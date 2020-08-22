#ifndef FILE_H
#define FILE_H

#include <efi/efi.h>
#include <efi/efilib.h>

#include "memory.h"
#include "protocol.h"

EFI_STATUS openVolume(IN EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *volume, OUT EFI_FILE_HANDLE *root);
EFI_STATUS openFile(IN EFI_FILE_HANDLE root, OUT EFI_FILE_HANDLE *file, IN CHAR16 *fileName, IN UINT64 mode, IN UINT64 attribute);
EFI_STATUS closeFile(IN EFI_FILE_PROTOCOL *file);
EFI_STATUS readFile(IN EFI_FILE_HANDLE file, IN OUT UINTN *bufferSize, OUT VOID *buffer);
EFI_STATUS getFileInfo(IN EFI_FILE_HANDLE file, IN EFI_GUID *informationType, IN OUT UINTN *bufferSize, OUT VOID *buffer);

EFI_STATUS openVolume(IN EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *volume, OUT EFI_FILE_HANDLE *root)
{
    return uefi_call_wrapper(volume->OpenVolume, 2, volume, root);
}

EFI_STATUS openFile(IN EFI_FILE_HANDLE root, OUT EFI_FILE_HANDLE *file, IN CHAR16 *fileName, IN UINT64 mode, IN UINT64 attribute)
{
    return uefi_call_wrapper(root->Open, 5, root, file, fileName, mode, attribute);
}

EFI_STATUS closeFile(IN EFI_FILE_PROTOCOL *file)
{
    return uefi_call_wrapper(file->Close, 1, file);
}

EFI_STATUS readFile(IN EFI_FILE_HANDLE file, IN OUT UINTN *bufferSize, OUT VOID *buffer)
{
    return uefi_call_wrapper(file->Read, 3, file, bufferSize, buffer);
}

EFI_STATUS getFileInfo(IN EFI_FILE_HANDLE file, IN EFI_GUID *informationType, IN OUT UINTN *bufferSize, OUT VOID *buffer)
{
    return uefi_call_wrapper(file->GetInfo, 4, file, informationType, bufferSize, buffer);
}

void loadKernel(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
    EFI_STATUS status = 0;

    EFI_LOADED_IMAGE *loadedImage;
    EFI_FILE_IO_INTERFACE *volume;
    EFI_FILE_HANDLE root;
    EFI_FILE_HANDLE file;

    status = handleProtocol(ImageHandle, &gEfiLoadedImageProtocolGuid, (VOID **)&loadedImage);
    status = handleProtocol(loadedImage->DeviceHandle, &gEfiSimpleFileSystemProtocolGuid, (VOID **)&volume);
    status = openVolume(volume, &root);
    status = openFile(root, &file, (CHAR16 *)L"kernel.bin", EFI_FILE_MODE_READ, 0);

    EFI_FILE_INFO *fileInfo;
    UINTN bufferSize = 0;
    EFI_PHYSICAL_ADDRESS addr = 0x100000;

    bufferSize = sizeof(EFI_FILE_INFO) + sizeof(CHAR16) * 100;
    status = allocatePool(EfiRuntimeServicesData, bufferSize, (VOID **)&fileInfo);
    status = getFileInfo(file, &gEfiFileInfoGuid, &bufferSize, (VOID *)fileInfo);

    Print(L"\tFileName:%s\t FileInfoSize:%d\t FileSize:%d\t Physical Size:%d\n", fileInfo->FileName, fileInfo->Size, fileInfo->FileSize, fileInfo->PhysicalSize);

    status = allocatePages(AllocateAddress, EfiConventionalMemory, (fileInfo->FileSize + 0x1000 - 1) / 0x1000, &addr);
    Print(L"Read Kernel File to Memory Address:%018lx\n", addr);

    bufferSize = fileInfo->FileSize;
    readFile(file, &bufferSize, (VOID *)addr);
    freePool(fileInfo);
    closeFile(file);
    closeFile(root);

    closeProtocol(volume, &gEfiSimpleFileSystemProtocolGuid, loadedImage->DeviceHandle, NULL);
    closeProtocol(loadedImage, &gEfiGraphicsOutputProtocolGuid, ImageHandle, NULL);
}

#endif //FILE_H