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
    // TextModeScreen tmscreen;
    // tmscreen.print((uint64_t)system::interrupt::idt::idtTable);
    // tmscreen.print("\n");
    // tmscreen.print((uint64_t)system::interrupt::idt::idtTableDescriptor.addr);
    // tmscreen.print("\n");
    // tmscreen.print((uint64_t)system::interrupt::idt::idtTableDescriptor.length);
    // tmscreen.print("\n");
    // tmscreen.print("Hello LearningOS!\nThis is a print test =w=\n");

    // tmscreen.print("Usable pages: ");
    // tmscreen.print((unsigned long long)globalMemoryDescriptor.usablePages);
    // tmscreen.print("\n");

    // for (int i = 0; i < globalMemoryDescriptor.memoryDescriptorsCount; i++)
    // {
    //     tmscreen.print("Start: ");
    //     tmscreen.print((unsigned long long)globalMemoryDescriptor.memoryDescriptors[i].address);
    //     tmscreen.print(" Length: ");
    //     tmscreen.print((long long)globalMemoryDescriptor.memoryDescriptors[i].length);
    //     tmscreen.print("\n");
    // }

    // int *onePage = (int *)system::memory::allocatePages(1);
    // for (int i = 0; i < 100; i++)
    // {
    //     onePage[i] = i;
    // }

    // tmscreen.print("Allocate a page at: ");
    // tmscreen.print((unsigned long long)onePage);
    // tmscreen.print("\n");

    // for (int i = 0; i < 100; i++)
    // {
    //     tmscreen.print((long long)onePage[i]);
    //     tmscreen.print(" ");
    // }
    // tmscreen.print("\n");

    // freePages(onePage);

    // int a = 2333, b;
    // asm volatile("movl %2, %1;\
    //      movl $6665, %0;\
    //      inc %0;"
    //              : "=r"(b), "=r"(a)
    //              : "r"(a));
    // tmscreen.print((long long)a);
    // tmscreen.print("\n");
    // tmscreen.print((long long)b);
    // tmscreen.print("\n");

    while (true)
    {
    }
}
