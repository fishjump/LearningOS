#pragma once

#include <system/boot.hpp>
#include <system/memory.hpp>

#include "../Screen.hpp"

system::io::Screen::Screen() : graphicMemory((const int *)system::memory::phyicalToVirtualAddr((void *)system::boot::bootInfo->graphicInfo.FrameBufferBase)),
                               height(system::boot::bootInfo->graphicInfo.VerticalResolution),
                               width(system::boot::bootInfo->graphicInfo.HorizontalResolution) {}

system::io::Screen::~Screen() = default;