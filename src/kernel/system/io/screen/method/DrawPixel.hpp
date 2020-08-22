#pragma once

#include <system/media/Color.hpp>

#include "../Screen.hpp"

void system::io::Screen::drawPixel(unsigned x, unsigned y, system::media::Color color)
{
    if (0 <= x && x < screenWidth && 0 <= y && y < screenHeight)
    {
        int *addr = (int *)graphicMemory + y * screenWidth + x;
        *addr = color.getColor();
    }
}