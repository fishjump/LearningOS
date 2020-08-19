#ifndef SYSTEM_IO_SCREEN_SCREEN_HPP
#define SYSTEM_IO_SCREEN_SCREEN_HPP

namespace system
{
    namespace io
    {
        namespace screen
        {
            const int *graphicMemory = (int *)0xffff800080000000;
            constexpr unsigned height = 768;
            constexpr unsigned width = 1360;

            const unsigned char asciiFont[256][16];

            void drawPixel(unsigned x, unsigned y, int color);
            void drawChar(unsigned x, unsigned y, int color, char ch);

        } // namespace screen

    } // namespace io

} // namespace system
#endif // SYSTEM_IO_SCREEN_SCREEN_HPP