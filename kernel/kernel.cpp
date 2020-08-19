#include "system/io/Screen.hpp"

extern "C" void kernel_main(void)
{
    // 1360 * 768
    // so, red : x:[595, 674] y:[299, 378]  green:  x:[685, 764] y:[299, 378]
    //     blue: x:[595, 674] y:[389, 468]  yellow: x:[685, 764] y:[389, 468]
    int ms_red = 0xff4325;
    int ms_blue = 0x06a4eb;
    int ms_green = 0x77b921;
    int ms_yellow = 0xf8b619;

    for (int x = 0; x < system::io::screen::width; x++)
    {
        for (int y = 0; y < system::io::screen::height; y++)
        {
            system::io::screen::drawPixel(x, y, 0);
        }
    }

    for (int x = 595; x <= 674; x++)
    {
        for (int y = 299; y <= 378; y++)
        {
            system::io::screen::drawPixel(x, y, ms_red);
        }
    }

    for (int x = 685; x <= 764; x++)
    {
        for (int y = 299; y <= 378; y++)
        {
            system::io::screen::drawPixel(x, y, ms_green);
        }
    }

    for (int x = 595; x <= 674; x++)
    {
        for (int y = 389; y <= 468; y++)
        {
            system::io::screen::drawPixel(x, y, ms_blue);
        }
    }

    for (int x = 685; x <= 764; x++)
    {
        for (int y = 389; y <= 468; y++)
        {
            system::io::screen::drawPixel(x, y, ms_yellow);
        }
    }

    while (true)
    {
    }
}
