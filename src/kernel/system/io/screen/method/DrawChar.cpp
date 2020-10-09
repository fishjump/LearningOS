#pragma once

#include <system/media.hpp>

#include "../Screen.hpp"

void system::io::Screen::drawChar(unsigned x, unsigned y, system::media::Color color, char ch)
{
    system::media::Font font(ch);
    system::media::Font::FontRows fontRows = font.getFontRows();

    unsigned xBoundary = x + system::media::Font::fontWidth, yBoundary = y + system::media::Font::fontHeight;
    for (unsigned _y = y, fontRowIndex = 0; _y < yBoundary; _y++, fontRowIndex++)
    {
        char fontRow = fontRows[fontRowIndex];
        for (unsigned _x = x; _x < xBoundary; _x++)
        {
            if (fontRow & 0b10000000)
            {
                drawPixel(_x, _y, color);
            }
            else
            {
                drawPixel(_x, _y, system::media::common_color::black);
            }

            fontRow = fontRow << 1;
        }
    }
}