#pragma once

#include "../Screen.hpp"

system::io::Screen::Screen() : graphicMemory((const int *)system::boot::bootInfo->graphicInfo.FrameBufferBase),
                               height(system::boot::bootInfo->graphicInfo.VerticalResolution),
                               width(system::boot::bootInfo->graphicInfo.HorizontalResolution) {}