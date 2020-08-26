#include <efi/efi.h>
#include <efi/efilib.h>

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
	struct MemoryDescriptor descriptors[0];
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
	SetMem((void *)bootInfo, 0x1000, 0);

	// init graphic
	EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol = 0;
	status = locateGraphicOutputProtocol(&graphicsOutputProtocol);
	setMode(graphicsOutputProtocol, 15);

	bootInfo->graphicInfo.frameBufferBase = graphicsOutputProtocol->Mode->FrameBufferBase;
	bootInfo->graphicInfo.frameBufferSize = graphicsOutputProtocol->Mode->FrameBufferSize;
	bootInfo->graphicInfo.horizontalResolution = graphicsOutputProtocol->Mode->Info->HorizontalResolution;
	bootInfo->graphicInfo.verticalResolution = graphicsOutputProtocol->Mode->Info->VerticalResolution;
	bootInfo->graphicInfo.pixelsPerScanLine = graphicsOutputProtocol->Mode->Info->PixelsPerScanLine;

	closeGraphicOutputProtocol(graphicsOutputProtocol, ImageHandle);

	// init memory map
	UINTN memoryMapSize = 0;
	EFI_MEMORY_DESCRIPTOR *memoryMap = 0;
	UINTN mapKey = 0;
	UINTN descriptorSize = 0;
	UINT32 desVersion = 0;
	status = getMemoryMap(&memoryMapSize, memoryMap, &mapKey, &descriptorSize, &desVersion);

	int descriptorCount = 0;
	struct MemoryDescriptor *currentNode = bootInfo->memoryInfo.descriptors, *lastNode = NULL;
	unsigned long lastEndAddr = 0;
	for (int i = 0; i < memoryMapSize / descriptorSize; i++)
	{
		int memoryType = 0;
		EFI_MEMORY_DESCRIPTOR *descriptor = (EFI_MEMORY_DESCRIPTOR *)((CHAR8 *)memoryMapSize + i * descriptorSize);
		if (descriptor->NumberOfPages == 0)
			continue;

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

		if ((lastNode != NULL) && (currentNode->type == memoryType) && (descriptor->PhysicalStart == lastEndAddr))
		{
			lastNode->length += descriptor->NumberOfPages << 12;
			lastEndAddr += descriptor->NumberOfPages << 12;
		}
		else
		{
			currentNode->address = descriptor->PhysicalStart;
			currentNode->length = descriptor->NumberOfPages << 12;
			currentNode->type = memoryType;
			lastEndAddr = descriptor->PhysicalStart + (descriptor->NumberOfPages << 12);
			lastNode = currentNode;
			currentNode++;
			descriptorCount++;
		}
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

	// exit boot services
	status = exitBootServices(ImageHandle, mapKey);

	// jump to kernel
	void (*kernelMain)(void);
	kernelMain = (void *)0x100000;
	kernelMain();

	return EFI_SUCCESS;
}