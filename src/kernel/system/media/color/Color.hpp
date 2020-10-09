#pragma once

namespace system
{
    namespace media
    {

        class Color
        {
        public:
            Color(const int &color);
            Color(const char &b, const char &g, const char &r);
            ~Color();

            int getColor() const;

        private:
            int color;
        }; // class Color

        namespace common_color
        {
            const int black = 0x000000;
            const int white = 0xffffff;
            const int red = 0xff0000;
            const int green = 0x00ff00;
            const int blue = 0x0000ff;
        } // namespace common_color

    } // namespace media

} // namespace system