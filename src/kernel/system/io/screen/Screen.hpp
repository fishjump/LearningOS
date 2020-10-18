#pragma once

#include <system/media/color.hpp>

namespace system::io
{
    class Screen
    {
    public:
        Screen();
        ~Screen();

        int *graphicMemory;
        unsigned height;
        unsigned width;

        void drawPixel(unsigned x, unsigned y, system::media::Color color);
        void drawChar(unsigned x, unsigned y, system::media::Color color, char ch);
        void clear();
        
        static void initGobalInstance();
        static Screen& getGobalInstance();
    }; // class screen

} // namespace system::io