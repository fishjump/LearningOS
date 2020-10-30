#pragma once

#include "../Screen.hpp"

#include <std/type.hpp>
#include <system/media.hpp>

void system::io::Screen::drawPixel(uint32_t x, uint32_t y, system::media::Color color)
{
    if (0 <= x && x < width && 0 <= y && y < height)
    {
        size_t padding = (pixelsPerScanLine - width);
        size_t leftPadding = padding / 2;
        size_t rightPadding = padding - leftPadding;
        uint32_t *addr = (uint32_t *)graphicMemory + (y + padding) * width + x + leftPadding;
        *addr = color.getColor();
    }
}