#pragma once

#include "../Screen.hpp"

#include <system/boot.hpp>
#include <system/memory.hpp>

system::io::Screen::Screen() : graphicMemory((uint32_t *)system::memory::phyicalToVirtualAddr((void *)system::boot::bootInfo->graphicInfo.FrameBufferBase)),
                               height(system::boot::bootInfo->graphicInfo.VerticalResolution),
                               width(system::boot::bootInfo->graphicInfo.HorizontalResolution),
                               pixelsPerScanLine(system::boot::bootInfo->graphicInfo.PixelsPerScanLine) {}
system::io::Screen::~Screen() = default;