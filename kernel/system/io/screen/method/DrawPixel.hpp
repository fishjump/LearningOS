#ifndef SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP
#define SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP

#include "../screen.hpp"

void system::io::screen::drawPixel(int x, int y, int color)
{
    if (0 <= x && x < width && 0 <= y && y < height)
    {
        int *addr = (int *)graphicMemory + y * width + x;
        *((char *)addr + 0) = (char)(color >> 0);  // B
        *((char *)addr + 1) = (char)(color >> 8);  // G
        *((char *)addr + 2) = (char)(color >> 16); // R
    }
}

#endif // SYSTEM_IO_SCREEN_METHOD_DRAW_PIXEL_HPP