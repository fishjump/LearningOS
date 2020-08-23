#include <efi/efi.h>
#include <efi/efilib.h>

#include "file.h"
#include "memory.h"
#include "protocol.h"
#include "vedio.h"

EFI_STATUS exitBootServices(IN EFI_HANDLE imageHandle, IN UINTN mapKey);

EFI_STATUS exitBootServices(IN EFI_HANDLE imageHandle, IN UINTN mapKey)
{
	return uefi_call_wrapper(BS->ExitBootServices, 2, imageHandle, mapKey);
}

EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
	InitializeLib(ImageHandle, SystemTable);
	EFI_STATUS status = 0;

	EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol = 0;
	status = locateGraphicOutputProtocol(&graphicsOutputProtocol);

	setMode(graphicsOutputProtocol, 15);

	UINTN sizeOfInfo = 0;
	EFI_GRAPHICS_OUTPUT_MODE_INFORMATION *info = 0;
	for (int i = 0; i < graphicsOutputProtocol->Mode->MaxMode; i++)
	{
		status = queryMode(graphicsOutputProtocol, i, &sizeOfInfo, &info);
		if (i % 2 == 0)
		{
			Print(L"[%02d]%4d * %4d", i, info->HorizontalResolution, info->VerticalResolution);
		}
		else
		{
			Print(L"     [%02d]%4d * %4d\n", i, info->HorizontalResolution, info->VerticalResolution);
		}
	}
	closeGraphicOutputProtocol(graphicsOutputProtocol, ImageHandle);

	loadKernel(ImageHandle, SystemTable);
	
	UINTN memoryMapSize = 0;
	EFI_MEMORY_DESCRIPTOR *memoryMap = 0;
	UINTN mapKey = 0;
	UINTN descriptorSize = 0;
	UINT32 desVersion = 0;
	status = getMemoryMap(&memoryMapSize, memoryMap, &mapKey, &descriptorSize, &desVersion);
	status = exitBootServices(ImageHandle, mapKey);

	void (*kernelMain)(void);
	kernelMain = (void *)0x100000;
	kernelMain();

	return EFI_SUCCESS;
}