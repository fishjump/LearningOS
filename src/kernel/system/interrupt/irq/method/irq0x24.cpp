#include "../irq.hpp"

#include <system/io.hpp>

void system::interrupt::irq::irq0x24(interrupt_frame *frame)
{
    system::io::TextModeScreen &tm = system::io::TextModeScreen::getGobalInstance();
    tm.print("irq0x24 triggered\n");
    system::io::port::writeBtye(0x20, 0x20);
}