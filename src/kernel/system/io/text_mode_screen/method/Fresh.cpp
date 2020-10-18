#include "../TextModeScreen.hpp"

#include <system/media.hpp>

void system::io::TextModeScreen::fresh()
{
    int cursor = 0;
    for (int i = 0; i < bufferCount; i++)
    {
        if (cursor >= row * column)
        {
            clear();
            cursor = 0;
        }
        int x = (cursor % column) * system::media::Font::fontWidth;
        int y = (cursor / column) * system::media::Font::fontHeight;
        switch (buffer[i])
        {
        case '\n':
            cursor += column - cursor % column;
            break;

        default:
            drawChar(x, y, system::media::common_color::white, buffer[i]);
            cursor++;
            break;
        }
    }
}
