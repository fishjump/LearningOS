#include <efi.h>
#include <efilib.h>

#include "file.h"
#include "memory.h"
#include "protocol.h"
#include "vedio.h"

struct GraphicInfo
{
	unsigned int horizontalResolution;
	unsigned int verticalResolution;
	unsigned int pixelsPerScanLine;

	unsigned long frameBufferBase;
	unsigned long frameBufferSize;
};

struct MemoryDescriptor
{
	unsigned long address;
	unsigned long length;
	unsigned int type;
} __attribute__((packed));

struct MemoryInfo
{
	unsigned int count;
	struct MemoryDescriptor descriptors[];
};

struct BootInfo
{
	struct GraphicInfo graphicInfo;
	struct MemoryInfo memoryInfo;
};

EFI_STATUS exitBootServices(IN EFI_HANDLE imageHandle, IN UINTN mapKey);

EFI_STATUS exitBootServices(IN EFI_HANDLE imageHandle, IN UINTN mapKey)
{
	return uefi_call_wrapper(BS->ExitBootServices, 2, imageHandle, mapKey);
}

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	InitializeLib(ImageHandle, SystemTable);
	EFI_STATUS status = 0;

	// load kernel image
	loadKernel(ImageHandle, SystemTable);

	// init boot info
	struct BootInfo *bootInfo = (struct BootInfo *)0x60000;
	allocatePages(AllocateAddress, EfiConventionalMemory, 1, (EFI_PHYSICAL_ADDRESS *)bootInfo);
	SetMem((void *)bootInfo, 0xffff, 0);

	// init graphic
	EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol = 0;
	status = locateGraphicOutputProtocol(&graphicsOutputProtocol);
	setMode(graphicsOutputProtocol, 15);

	bootInfo->graphicInfo.frameBufferBase = graphicsOutputProtocol->Mode->FrameBufferBase;
	bootInfo->graphicInfo.frameBufferSize = graphicsOutputProtocol->Mode->FrameBufferSize;
	bootInfo->graphicInfo.horizontalResolution = graphicsOutputProtocol->Mode->Info->HorizontalResolution;
	bootInfo->graphicInfo.verticalResolution = graphicsOutputProtocol->Mode->Info->VerticalResolution;
	bootInfo->graphicInfo.pixelsPerScanLine = graphicsOutputProtocol->Mode->Info->PixelsPerScanLine;

	Print(L"Graphic resolution: %d*%d\n", bootInfo->graphicInfo.horizontalResolution, bootInfo->graphicInfo.verticalResolution);
	Print(L"Graphic memory: %018lx\n", bootInfo->graphicInfo.frameBufferBase);
	closeGraphicOutputProtocol(graphicsOutputProtocol, ImageHandle);

	// init memory map
	UINTN memoryMapSize = 0;
	EFI_MEMORY_DESCRIPTOR *memoryMap = 0;
	UINTN mapKey = 0;
	UINTN descriptorSize = 0;
	UINT32 desVersion = 0;
	status = getMemoryMap(&memoryMapSize, memoryMap, &mapKey, &descriptorSize, &desVersion);
	memoryMapSize += descriptorSize * 5;
	status = allocatePool(EfiRuntimeServicesData, memoryMapSize, (VOID **)&memoryMap);
	SetMem((VOID *)memoryMap, memoryMapSize, 0);
	status = getMemoryMap(&memoryMapSize, memoryMap, &mapKey, &descriptorSize, &desVersion);

	int descriptorCount = 0;
	struct MemoryDescriptor *descriptors = bootInfo->memoryInfo.descriptors;
	Print(L"Get EFI_MEMORY_DESCRIPTOR Structure:%018lx\n", memoryMap);
	for (int i = 0; i < memoryMapSize / descriptorSize; i++)
	{
		int memoryType = 0;
		EFI_MEMORY_DESCRIPTOR *descriptor = (EFI_MEMORY_DESCRIPTOR *)((CHAR8 *)memoryMap + i * descriptorSize);

		Print(L"MemoryMap %4d %10d (%16lx<->%16lx)\n", descriptor->Type,
			  descriptor->NumberOfPages,
			  descriptor->PhysicalStart,
			  descriptor->PhysicalStart + (descriptor->NumberOfPages << 12));

		if (descriptor->NumberOfPages == 0 || descriptor->PhysicalStart < 0x100000)
		{
			continue;
		}

		switch (descriptor->Type)
		{
		case EfiLoaderCode:
		case EfiLoaderData:
		case EfiBootServicesCode:
		case EfiBootServicesData:
		case EfiRuntimeServicesCode:
		case EfiRuntimeServicesData:
		case EfiConventionalMemory:
			memoryType = 1; //1:RAM
			break;

		case EfiReservedMemoryType:
		case EfiMemoryMappedIO:
		case EfiMemoryMappedIOPortSpace:
		case EfiPalCode:
			memoryType = 2; //2:ROM or Reserved
			break;

		case EfiACPIReclaimMemory:
			memoryType = 3; //3:ACPI Reclaim Memory
			break;

		case EfiACPIMemoryNVS:
			memoryType = 4; //4:ACPI NVS Memory
			break;

		case EfiUnusableMemory:
			memoryType = 5; //5:Unusable
			break;

		default:
			Print(L"Invalid UEFI Memory Type:%4d\n", descriptor->Type);
			continue;
		}

		descriptors[descriptorCount].address = descriptor->PhysicalStart;
		descriptors[descriptorCount].length = descriptor->NumberOfPages << 12;
		descriptors[descriptorCount].type = memoryType;
		descriptorCount++;
	}
	bootInfo->memoryInfo.count = descriptorCount;

	// sort addr from low to high
	struct MemoryDescriptor *node = bootInfo->memoryInfo.descriptors;
	for (int i = 0; i < descriptorCount; i++)
	{
		struct MemoryDescriptor *nodeI = node + i;
		struct MemoryDescriptor tmp;
		for (int j = i + 1; j < descriptorCount; j++)
		{
			struct MemoryDescriptor *nodeJ = node + j;
			if (nodeI->address > nodeJ->address)
			{
				tmp = *nodeI;
				*nodeI = *nodeJ;
				*nodeJ = tmp;
			}
		}
	}
	Print(L"Jumping to kernel\n");
	// exit boot services
	status = exitBootServices(ImageHandle, mapKey);

	// jump to kernel
	void (*kernelMain)(void);
	kernelMain = (void *)0x100000;
	kernelMain();

	return EFI_SUCCESS;
}