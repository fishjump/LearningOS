#include "../irq.hpp"

#include <system/io.hpp>

void system::interrupt::irq::irq0x21(interrupt_frame *frame)
{
    system::io::TextModeScreen &tm = system::io::TextModeScreen::getGobalInstance();
    system::io::Keyboard &keyboard = system::io::Keyboard::getGobalInstance();

    unsigned char scan_code = system::io::port::readBtye(0x60);

    keyboard.enqueue(scan_code);

    system::io::port::writeBtye(0x20, 0x20);
}