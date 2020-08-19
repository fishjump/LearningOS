#ifndef SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP
#define SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP

#include "../Screen.hpp"

void system::io::screen::drawPixel(unsigned x, unsigned y, int color)
{
    if (0 <= x && x < screenWidth && 0 <= y && y < screenHeight)
    {
        int *addr = (int *)graphicMemory + y * screenWidth + x;
        *((char *)addr + 0) = (char)(color >> 0);  // B
        *((char *)addr + 1) = (char)(color >> 8);  // G
        *((char *)addr + 2) = (char)(color >> 16); // R
    }
}

#endif // SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP