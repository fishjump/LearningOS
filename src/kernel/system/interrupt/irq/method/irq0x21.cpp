#include "../irq.hpp"

#include <system/io.hpp>

__attribute__((interrupt)) void system::interrupt::irq::irq0x21(interrupt_frame *frame)
{
    system::io::TextModeScreen &tm = system::io::TextModeScreen::getGobalInstance();
    tm.print("irq0x21 triggered\n");

    unsigned char scan_code = system::io::port::readBtye(0x60);

    system::io::port::writeBtye(0x20, 0x20);
}