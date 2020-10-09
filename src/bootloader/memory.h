#ifndef MEMORY_H
#define MEMORY_H

#include <efi.h>
#include <efilib.h>

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

#endif // MEMORY_H