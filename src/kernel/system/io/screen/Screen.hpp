#ifndef SYSTEM_IO_SCREEN_SCREEN_HPP
#define SYSTEM_IO_SCREEN_SCREEN_HPP

#include "../../media/Color.hpp"
#include "../../media/Font.hpp"

namespace system
{
    namespace io
    {
        namespace screen
        {
            constexpr unsigned screenHeight = 768;
            constexpr unsigned screenWidth = 1360;
            const int *graphicMemory = (int *)0xffff800080000000;

            void drawPixel(unsigned x, unsigned y, system::media::Color color);
            void drawChar(unsigned x, unsigned y, system::media::Color color, char ch);

        } // namespace screen

    } // namespace io

} // namespace system

#endif // SYSTEM_IO_SCREEN_SCREEN_HPP