// #include <application/shell.hpp>
#include <system.hpp>

void clear()
{
    system::io::entity::Screen screen;

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
    system::media::entity::Color ms_red = 0xff4325;
    system::media::entity::Color ms_blue = 0x06a4eb;
    system::media::entity::Color ms_green = 0x77b921;
    system::media::entity::Color ms_yellow = 0xf8b619;

    system::io::entity::Screen screen;
    for (int y = 299; y <= 378; y++)
    {
        for (int x = 595; x <= 674; x++)
        {
            screen.drawPixel(x, y, ms_red);
        }
    }
    for (int y = 299; y <= 378; y++)
    {
        for (int x = 685; x <= 764; x++)
        {
            screen.drawPixel(x, y, ms_green);
        }
    }
    for (int y = 389; y <= 468; y++)
    {
        for (int x = 595; x <= 674; x++)
        {
            screen.drawPixel(x, y, ms_blue);
        }
    }
    for (int y = 389; y <= 468; y++)
    {
        for (int x = 685; x <= 764; x++)
        {
            screen.drawPixel(x, y, ms_yellow);
        }
    }
}

extern "C" void kernelMain(void)
{
    system::global::init::initIdt();
    system::global::init::initPic();
    system::global::init::initMemory();
    system::global::init::initScreen();
    system::global::init::initDefaultFont();
    system::global::init::initTextScreen(
        *system::global::instance::getDefaultFont(),
        system::media::common_color::white);
    printLogo();
    auto tmScreen = system::global::instance::getTextScreen();
    tmScreen->print("VerticalResolution:")->print((uint64_t)system::boot::getBootInfo()->graphicInfo.VerticalResolution)->print("\n");
    tmScreen->print("HorizontalResolution:")->print((uint64_t)system::boot::getBootInfo()->graphicInfo.HorizontalResolution)->print("\n");
    tmScreen->print("PixelsPerScanLine:")->print((uint64_t)system::boot::getBootInfo()->graphicInfo.PixelsPerScanLine)->print("\n");
    tmScreen->print((uint64_t)tmScreen->width)->print("\n");
    tmScreen->fresh();

    uint8_t data;

    system::io::port::writeBtye(0x1f6, 0xf0);
    system::io::port::writeBtye(0x1f1, 0x00);
    system::io::port::writeBtye(0x1f2, 0x01);
    system::io::port::writeBtye(0x1f3, 0x00);
    system::io::port::writeBtye(0x1f4, 0x00);
    system::io::port::writeBtye(0x1f5, 0x00);
    system::io::port::writeBtye(0x1f7, 0x20);

    while (((data = system::io::port::readBtye(0x1f7)) & 0b10000000) != 0)
    {
        tmScreen->print((unsigned long long)data)->print("\n");
        tmScreen->fresh();
    }
    tmScreen->print("disk ready\n");
    if (data == 65)
    {
        data = system::io::port::readBtye(0x1f1);
        tmScreen->print((unsigned long long)data)->print("\n");
    }
    while (((data = system::io::port::readBtye(0x1f7)) & 0b00001000) == 0)
    {
        tmScreen->print((unsigned long long)data)->print("\n");
        tmScreen->fresh();
    }
    tmScreen->print("data ready\n");

    for (int i = 0; i < 255; i++)
    {
        uint16_t wdata = system::io::port::readWord(0x1f0);
        char str[3];
        str[0] = wdata;
        str[1] = wdata >> 8;
        str[2] = '\0';
        tmScreen->print(str)->print(" ");
    }

    // application::Shell shell;
    auto kb = system::global::instance::getKeyboard();
    kb->setHandler(handler::keyboardEventHandler);
    while (true)
    {
        // shell.getInput();
        kb->serve();
        tmScreen->fresh();
        asm("hlt");
    }
}
