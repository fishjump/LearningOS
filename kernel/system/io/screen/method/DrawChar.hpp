#ifndef SYSTEM_IO_SCREEN_METHOD_DRAW_CHAR_HPP
#define SYSTEM_IO_SCREEN_METHOD_DRAW_CHAR_HPP

#include "../Screen.hpp"

void system::io::screen::drawChar(unsigned x, unsigned y, int color, char ch)
{
    const unsigned char *font = asciiFont[ch];
    
    unsigned xBoundary = x + fontWidth, yBoundary = y + fontHeight;
    for (unsigned _y = y; _y < yBoundary; _y++)
    {
        char fontRow = font[_y];
        for (unsigned _x = x; _x < xBoundary; _x++)
        {
            if (fontRow & 0b10000000)
            {
                drawPixel(_x, _y, color);
            }

            fontRow = fontRow << 1;
        }
    }
}

#endif // SYSTEM_IO_SCREEN_METHOD_DRAW_CHAR_HPP