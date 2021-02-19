#pragma once

#include <std/type.hpp>
#include <system/media/color.hpp>

namespace system::io
{
    class Screen
    {
    public:
        Screen();
        ~Screen();

        uint32_t *graphicMemory;
        size_t height;
        size_t width;
        size_t pixelsPerScanLine;

        void drawPixel(uint32_t x, uint32_t y, system::media::Color color);
        void drawChar(uint32_t x, uint32_t y, system::media::Color color, char ch);
        void clear();

        static void initGobalInstance();
        static Screen &getGobalInstance();
    }; // class screen

} // namespace system::io