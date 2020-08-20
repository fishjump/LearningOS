#ifndef SYSTEM_IO_SCREEN_METHOD_DRAW_CHAR_HPP
#define SYSTEM_IO_SCREEN_METHOD_DRAW_CHAR_HPP

#include "../Screen.hpp"

void system::io::screen::drawChar(unsigned x, unsigned y, Color color, char ch)
{
    const unsigned char *font = asciiFonts[ch];

    unsigned xBoundary = x + fontWidth, yBoundary = y + fontHeight;
    for (unsigned _y = y, fontRowIndex = 0; _y < yBoundary; _y++, fontRowIndex++)
    {
        char fontRow = font[fontRowIndex];
        for (unsigned _x = x; _x < xBoundary; _x++)
        {
            if (fontRow & 0b10000000)
            {
                drawPixel(_x, _y, color);
            }
            else
            {
                drawPixel(_x, _y, common_color::black);
            }

            fontRow = fontRow << 1;
        }
    }
}

#endif // SYSTEM_IO_SCREEN_METHOD_DRAW_CHAR_HPP