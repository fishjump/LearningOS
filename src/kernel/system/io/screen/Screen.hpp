#pragma once

#include <system/boot.hpp>
#include <system/media/Color.hpp>

namespace system
{
    namespace io
    {
        class Screen
        {
        public:
            Screen();
            ~Screen() = default;

            const int *graphicMemory;
            const unsigned height;
            const unsigned width;

            static Screen *getInstance();

            void drawPixel(unsigned x, unsigned y, system::media::Color color);
            void drawChar(unsigned x, unsigned y, system::media::Color color, char ch);
        }; // class screen
        
    } // namespace io

} // namespace system