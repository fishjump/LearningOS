#ifndef MEMORY_H
#define MEMORY_H

#include <efi/efi.h>
#include <efi/efilib.h>

EFI_STATUS allocatePool(IN EFI_MEMORY_TYPE poolType, IN UINTN bufferSize, OUT VOID **buffer);
EFI_STATUS freePool(IN VOID *buffer);
EFI_STATUS allocatePages(IN EFI_ALLOCATE_TYPE type, IN EFI_MEMORY_TYPE memoryType, IN UINTN pages, IN OUT EFI_PHYSICAL_ADDRESS *addr);
EFI_STATUS getMemoryMap(IN OUT UINTN *memoryMapSize, IN OUT EFI_MEMORY_DESCRIPTOR *memoryMap, OUT UINTN *mapKey, OUT UINTN *descriptorSize, OUT UINT32 *descriptorVersion);

EFI_STATUS allocatePool(IN EFI_MEMORY_TYPE poolType, IN UINTN bufferSize, OUT VOID **buffer)
{
    return uefi_call_wrapper(gBS->AllocatePool, 3, poolType, bufferSize, buffer);
}

EFI_STATUS freePool(IN VOID *buffer)
{
    return uefi_call_wrapper(gBS->FreePool, 1, buffer);
}

EFI_STATUS allocatePages(IN EFI_ALLOCATE_TYPE type, IN EFI_MEMORY_TYPE memoryType, IN UINTN pages, IN OUT EFI_PHYSICAL_ADDRESS *addr)
{
    return uefi_call_wrapper(gBS->AllocatePages, 4, type, memoryType, pages, addr);
}

EFI_STATUS getMemoryMap(IN OUT UINTN *memoryMapSize, IN OUT EFI_MEMORY_DESCRIPTOR *memoryMap, OUT UINTN *mapKey, OUT UINTN *descriptorSize, OUT UINT32 *descriptorVersion)
{
    return uefi_call_wrapper(gBS->GetMemoryMap, 5, memoryMapSize, memoryMap, mapKey, descriptorSize, descriptorVersion);
}

// void PrintMemoryMapping(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
// {
// 	UINTN MemMapSize = 0;
// 	EFI_MEMORY_DESCRIPTOR *MemMap = 0;
// 	UINTN MapKey = 0;
// 	UINTN DescriptorSize = 0;
// 	UINT32 DesVersion = 0;

// 	EFI_STATUS status = 0;

// 	Print(L"Get EFI_MEMORY_DESCRIPTOR Structure\n");
// 	status = uefi_call_wrapper(BS->GetMemoryMap, 5, &MemMapSize, MemMap, &MapKey, &DescriptorSize, &DesVersion);
// 	MemMapSize += 2 * DescriptorSize;
// 	status = uefi_call_wrapper(BS->AllocatePool, 3, EfiRuntimeServicesData, MemMapSize, (void **)&MemMap);
// 	Print(L"Allocate Memory Size: %10d\n", MemMapSize);
// 	status = uefi_call_wrapper(BS->GetMemoryMap, 5, &MemMapSize, MemMap, &MapKey, &DescriptorSize, &DesVersion);
// 	Print(L"Memory Map Size:      %10d\n", MemMapSize);
// 	Print(L"Descriptor Size:      %10d\n", DescriptorSize);
// 	Print(L"Descriptor Version:   %10d\n", DesVersion);

// 	for (int i = 0; i < (MemMapSize / DescriptorSize); i++)
// 	{
// 		EFI_MEMORY_DESCRIPTOR *MMap = (EFI_MEMORY_DESCRIPTOR *)(((CHAR8 *)MemMap) + i * DescriptorSize);
// 		Print(L"Type: %4d Pages: %5d Addr: (%8lx~%8lx) Attr: %016lx\n", MMap->Type, MMap->NumberOfPages, MMap->PhysicalStart, MMap->PhysicalStart + (MMap->NumberOfPages << 12), MMap->Attribute);
// 	}

// 	uefi_call_wrapper(BS->FreePool, 1, MemMap);
// }

#endif // MEMORY_H