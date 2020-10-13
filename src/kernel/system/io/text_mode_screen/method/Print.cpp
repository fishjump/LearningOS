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

system::io::TextModeScreen *system::io::TextModeScreen::print(long long content)
{
    char arr[64] = {}; // length is long enought now

    if (content == 0)
    {
        arr[0] = '0';
        return print(arr);
    }

    long long tmp = content, length = 0;
    while (tmp != 0)
    {
        tmp /= 10;
        length++;
    }

    int index = length - 1, end = 0;
    if (content < 0)
    {
        arr[0] = '-';
        content = -content;
        index++;
        end++;
    }

    while (index >= end)
    {
        arr[index] = '0' + content % 10;
        content /= 10;
        index--;
    }

    return print(arr);
}

system::io::TextModeScreen *system::io::TextModeScreen::print(unsigned long long content)
{
    char arr[64] = {}; // length is long enought now

    if (content == 0)
    {
        arr[0] = '0';
        return print(arr);
    }

    unsigned long long tmp = content, length = 0;
    while (tmp != 0)
    {
        tmp /= 10;
        length++;
    }

    int index = length - 1, end = 0;
    if (content < 0)
    {
        arr[0] = '-';
        content = -content;
        index++;
        end++;
    }

    while (index >= end)
    {
        arr[index] = '0' + content % 10;
        content /= 10;
        index--;
    }

    return print(arr);
}