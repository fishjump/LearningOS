#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <efi.h>
#include <efilib.h>

EFI_STATUS closeProtocol(EFI_HANDLE handle, EFI_GUID *protocol, EFI_HANDLE agentHandle, EFI_HANDLE controllerHandle);
EFI_STATUS locateProtocol(EFI_GUID *protocol, VOID *registration, VOID **interface);
EFI_STATUS handleProtocol(EFI_HANDLE handle, EFI_GUID *protocol, VOID **interface);

//  uefi_call_wrapper(BS->HandleProtocol, 3, ImageHandle, &LoadedImageProtocol, (void *)&LoadedImage);

EFI_STATUS closeProtocol(EFI_HANDLE handle, EFI_GUID *protocol, EFI_HANDLE agentHandle, EFI_HANDLE controllerHandle)
{
    return uefi_call_wrapper(BS->CloseProtocol, 4, handle, protocol, agentHandle, controllerHandle);
}

EFI_STATUS locateProtocol(EFI_GUID *protocol, VOID *registration, VOID **interface)
{
    return uefi_call_wrapper(BS->LocateProtocol, 3, protocol, registration, interface);
}

EFI_STATUS handleProtocol(EFI_HANDLE handle, EFI_GUID *protocol, VOID **interface)
{
    uefi_call_wrapper(BS->HandleProtocol, 3, handle, protocol, interface);
}

#endif // PROTOCOL_H