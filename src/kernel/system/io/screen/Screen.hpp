#pragma once

#include <system/media/Color.hpp>

namespace system
{
    namespace io
    {
        class Screen
        {
        public:
            static const unsigned screenHeight = 768;
            static const unsigned screenWidth = 1360;
            static const int *graphicMemory;

            void drawPixel(unsigned x, unsigned y, system::media::Color color);
            void drawChar(unsigned x, unsigned y, system::media::Color color, char ch);

        }; // class screen

        const int *Screen::graphicMemory = (const int *)0xffff800080000000;

    } // namespace io

} // namespace system