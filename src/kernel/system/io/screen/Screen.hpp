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
            Screen() : graphicMemory((const int *)system::boot::bootInfo->graphicInfo.FrameBufferBase),
                       height(system::boot::bootInfo->graphicInfo.VerticalResolution),
                       width(system::boot::bootInfo->graphicInfo.HorizontalResolution) {}
            ~Screen() = default;

            const int *graphicMemory;
            const unsigned height;
            const unsigned width;

            static void initScreen();
            static Screen *getInstance();

            void drawPixel(unsigned x, unsigned y, system::media::Color color);
            void drawChar(unsigned x, unsigned y, system::media::Color color, char ch);

        private:
            static Screen *instance;
        }; // class screen

        Screen *Screen::instance = nullptr;

    } // namespace io

} // namespace system