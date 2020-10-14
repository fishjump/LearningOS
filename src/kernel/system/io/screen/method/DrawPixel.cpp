#pragma once

#include "../Screen.hpp"

#include <system/media.hpp>

void system::io::Screen::drawPixel(unsigned x, unsigned y, system::media::Color color)
{
    if (0 <= x && x < width && 0 <= y && y < height)
    {
        int *addr = (int *)graphicMemory + y * width + x;
        *addr = color.getColor();
    }
}