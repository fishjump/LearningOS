#ifndef SYSTEM_IO_SCREEN_COLOR_HPP
#define SYSTEM_IO_SCREEN_COLOR_HPP

namespace system
{
    namespace media
    {

        class Color
        {
        public:
            Color(const char &b, const char &g, const char &r)
            {
                *((char *)&color + 0) = b;
                *((char *)&color + 1) = g;
                *((char *)&color + 2) = r;
            }

            Color(const int &color) : color(color) {}

            int getColor() const { return color; }

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

#endif // SYSTEM_IO_SCREEN_COLOR_HPP