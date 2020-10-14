#pragma once

#include <system/media/color.hpp>

namespace system::io
{
    class Screen
    {
    public:
        Screen();
        ~Screen();

        const int *graphicMemory;
        const unsigned height;
        const unsigned width;

        static Screen *getInstance();

        void drawPixel(unsigned x, unsigned y, system::media::Color color);
        void drawChar(unsigned x, unsigned y, system::media::Color color, char ch);
    }; // class screen

} // namespace system::io