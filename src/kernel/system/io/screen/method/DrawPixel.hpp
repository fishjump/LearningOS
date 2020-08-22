#ifndef SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP
#define SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP

#include <system/media/Color.hpp>

#include "../Screen.hpp"

void system::io::screen::drawPixel(unsigned x, unsigned y, system::media::Color color)
{
    if (0 <= x && x < screenWidth && 0 <= y && y < screenHeight)
    {
        int *addr = (int *)graphicMemory + y * screenWidth + x;
        *addr = color.getColor();
    }
}

#endif // SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP