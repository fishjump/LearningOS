#include <system/interrupt/pic.hpp>
#include <system/interrupt/idt.hpp>
#include <system/io.hpp>

void system::interrupt::pic::initPic()
{
    // disable all interrupts
    system::io::port::writeBtye(system::io::port::pic::PIC0_IMR, 0b11111111);
    system::io::port::writeBtye(system::io::port::pic::PIC1_IMR, 0b11111111);

    // init master pic
    system::io::port::writeBtye(system::io::port::pic::PIC0_ICW1, 0x11);
    system::io::port::writeBtye(system::io::port::pic::PIC0_ICW2, 0x20);       // handle IRQ0 - IRQ7 by interrupt 0x20 - 0x27
    system::io::port::writeBtye(system::io::port::pic::PIC0_ICW3, 0b00000100); // the 3rd port is connected to slave pic
    system::io::port::writeBtye(system::io::port::pic::PIC0_ICW4, 0x01);

    // init slave pic
    system::io::port::writeBtye(system::io::port::pic::PIC1_ICW1, 0x11);
    system::io::port::writeBtye(system::io::port::pic::PIC1_ICW2, 0x28);       // handle IRQ0 - IRQ7 by interrupt 0x28 - 0x2f
    system::io::port::writeBtye(system::io::port::pic::PIC1_ICW3, 0b00000010); // the 2nd port is connected to master pic
    system::io::port::writeBtye(system::io::port::pic::PIC1_ICW4, 0x01);

    // enable all interrupts
    system::io::port::writeBtye(system::io::port::pic::PIC0_IMR, 0b11111101);
    system::io::port::writeBtye(system::io::port::pic::PIC1_IMR, 0b11111111);
}