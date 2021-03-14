#include <system/io/screen.hpp>

#include <boot/boot.hpp>
#include <memory/memory.hpp>

system::io::Screen::Screen() : graphicMemory((uint32_t *)system::memory::phyicalToVirtualAddr((void *)system::boot::getBootInfo()->graphicInfo.FrameBufferBase)),
                               height(system::boot::getBootInfo()->graphicInfo.VerticalResolution),
                               width(system::boot::getBootInfo()->graphicInfo.HorizontalResolution),
                               pixelsPerScanLine(system::boot::getBootInfo()->graphicInfo.PixelsPerScanLine) {}
system::io::Screen::~Screen() = default;