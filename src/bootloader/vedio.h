#ifndef VEDIO_H
#define VEDIO_H

#include <efi.h>
#include <efilib.h>

#include "protocol.h"

EFI_STATUS locateGraphicOutputProtocol(EFI_GRAPHICS_OUTPUT_PROTOCOL **graphicsOutputProtocol);
EFI_STATUS closeGraphicOutputProtocol(EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol, EFI_HANDLE agentHandle);
EFI_STATUS queryMode(EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol, UINT32 modeNumber, UINTN *sizeOfInfo, EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **info);
EFI_STATUS setMode(EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol, UINT32 modeNumber);
void printGraphicsInfo(EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *mode);

EFI_STATUS locateGraphicOutputProtocol(EFI_GRAPHICS_OUTPUT_PROTOCOL **graphicsOutputProtocol)
{
    return locateProtocol(&gEfiGraphicsOutputProtocolGuid, NULL, (VOID **)graphicsOutputProtocol);
}

EFI_STATUS closeGraphicOutputProtocol(EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol, EFI_HANDLE agentHandle)
{
    return closeProtocol(graphicsOutputProtocol, &gEfiGraphicsOutputProtocolGuid, agentHandle, NULL);
}

EFI_STATUS queryMode(EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol, UINT32 modeNumber, UINTN *sizeOfInfo, EFI_GRAPHICS_OUTPUT_MODE_INFORMATION **info)
{
    return uefi_call_wrapper(graphicsOutputProtocol->QueryMode, 4, graphicsOutputProtocol, modeNumber, sizeOfInfo, info);
}

EFI_STATUS setMode(EFI_GRAPHICS_OUTPUT_PROTOCOL *graphicsOutputProtocol, UINT32 modeNumber)
{
    return uefi_call_wrapper(graphicsOutputProtocol->SetMode, 2, graphicsOutputProtocol, modeNumber);
}

void printGraphicsInfo(EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE *mode)
{
    Print(L"Current Mode:   %02d\n", mode->Mode);
    Print(L"Version:        %x\n", mode->Info->Version);
    Print(L"Format:         %d\n", mode->Info->PixelFormat);
    Print(L"Horizontal:     %d\n", mode->Info->HorizontalResolution);
    Print(L"Vertical:       %d\n", mode->Info->VerticalResolution);
    Print(L"ScanLine:       %d\n", mode->Info->PixelsPerScanLine);
    Print(L"Buffer Base:    %x\n", mode->FrameBufferBase);
    Print(L"Buffer Size:    %x\n", mode->FrameBufferSize);
}

#endif // VEDIO_H