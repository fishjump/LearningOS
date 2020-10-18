#include "../Screen.hpp"

#include <system/media.hpp>

void system::io::Screen::clear()
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            drawPixel(x, y, system::media::common_color::black);
        }
    }
}
