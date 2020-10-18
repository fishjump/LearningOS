#include <system.hpp>

using namespace system::io;
using namespace system::media;
using namespace system::memory;

void clear()
{
    Screen screen;

    for (int x = 0; x < screen.width; x++)
    {
        for (int y = 0; y < screen.height; y++)
        {
            screen.drawPixel(x, y, system::media::common_color::black);
        }
    }
}

void printLogo()
{
    // 1360 * 768
    // so, red : x:[595, 674] y:[299, 378]  green:  x:[685, 764] y:[299, 378]
    //     blue: x:[595, 674] y:[389, 468]  yellow: x:[685, 764] y:[389, 468]
    Color ms_red = 0xff4325;
    Color ms_blue = 0x06a4eb;
    Color ms_green = 0x77b921;
    Color ms_yellow = 0xf8b619;

    Screen screen;

    for (int x = 595; x <= 674; x++)
    {
        for (int y = 299; y <= 378; y++)
        {
            screen.drawPixel(x, y, ms_red);
        }
    }

    for (int x = 685; x <= 764; x++)
    {
        for (int y = 299; y <= 378; y++)
        {
            screen.drawPixel(x, y, ms_green);
        }
    }

    for (int x = 595; x <= 674; x++)
    {
        for (int y = 389; y <= 468; y++)
        {
            screen.drawPixel(x, y, ms_blue);
        }
    }

    for (int x = 685; x <= 764; x++)
    {
        for (int y = 389; y <= 468; y++)
        {
            screen.drawPixel(x, y, ms_yellow);
        }
    }
}

extern "C" void kernelMain(void)
{
    system::interrupt::idt::initIdt();
    system::interrupt::pic::initPic();
    system::memory::initMemory();
    system::io::Screen::initGobalInstance();
    system::io::TextModeScreen::initGobalInstance();

    printLogo();

    while (true)
    {
        system::io::TextModeScreen::getGobalInstance().fresh();
    }
}
