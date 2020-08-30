#pragma once

#include <system/media.hpp>

#include "../TextModeScreen.hpp"

system::io::TextModeScreen *system::io::TextModeScreen::print(const char *content)
{
    int i = 0;
    while (content[i] != '\0')
    {
        if (cursor >= height * width)
        {
            break;
        }
        int x = (cursor % width) * system::media::Font::fontWidth;
        int y = (cursor / width) * system::media::Font::fontHeight;
        switch (content[i])
        {
        case '\n':
            cursor += width - cursor % width;
            break;

        default:
            drawChar(x, y, system::media::common_color::white, content[i]);
            cursor++;
            break;
        }

        i++;
    }

    return this;
}

system::io::TextModeScreen *system::io::TextModeScreen::print(int content)
{
    // Cannot implement now, because we don't have 'stack' data structure.
    // If we wanna have a stack, we need to implement 'malloc' first

    // if (content < 0)
    // {
    //     int x = cursor % width, y = cursor / width;
    //     drawChar(x * system::media::Font::fontWidth, y * system::media::Font::fontHeight, system::media::common_color::white, '-');
    // }

    // while (content != 0)
    // {
    //     char ch = content % 10;
    // }
    // int i = 0;
    // while (content[i] != '\0')
    // {
    //     i++;
    // }

    return this;
}