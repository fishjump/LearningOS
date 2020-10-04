#pragma once

#include <type_traits>

#include <system/media.hpp>

#include "../TextModeScreen.hpp"

template <typename T, typename std::enable_if_t<std::is_same_v<std::decay_t<T>, const char *> || std::is_convertible_v<std::decay_t<T>, const char *>> *>
system::io::TextModeScreen *system::io::TextModeScreen::print(T content)
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

template <typename T, typename std::enable_if_t<std::is_integral_v<std::decay_t<T>>> *>
system::io::TextModeScreen *system::io::TextModeScreen::print(T content)
{
    char arr[64] = {}; // length is long enought now

    if (content == 0)
    {
        arr[0] = '0';
        return print(arr);
    }

    T tmp = content, length = 0;
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