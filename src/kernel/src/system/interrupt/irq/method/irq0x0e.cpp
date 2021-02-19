#include <system/interrupt/irq.hpp>

#include <system/io.hpp>

void system::interrupt::irq::irq0x0e(interrupt_frame *frame)
{
    system::io::TextModeScreen &tm = system::io::TextModeScreen::getGobalInstance();
    tm.print("irq0x0e triggered\n");
    system::io::port::writeBtye(0x20, 0x20);
}