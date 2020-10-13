#include "pic.hpp"

void system::io::pic::initPic()
{
    // disable all interrupts
    writeBtye(PIC0_IMR, 0b11111111);
    writeBtye(PIC1_IMR, 0b11111111);

    // init master pic
    writeBtye(PIC0_ICW1, 0x11);
    writeBtye(PIC0_ICW2, 0x20);       // handle IRQ0 - IRQ7 by interrupt 0x20 - 0x27
    writeBtye(PIC0_ICW3, 0b00000100); // the 3rd port is connected to slave pic
    writeBtye(PIC0_ICW4, 0x01);

    // init slave pic
    writeBtye(PIC1_ICW1, 0x11);
    writeBtye(PIC1_ICW2, 0x28);       // handle IRQ0 - IRQ7 by interrupt 0x28 - 0x2f
    writeBtye(PIC1_ICW3, 0b00000010); // the 2nd port is connected to master pic
    writeBtye(PIC1_ICW4, 0x01);

    // enable all interrupts
    writeBtye(PIC0_IMR, 0b11111101);
    writeBtye(PIC1_IMR, 0b11111111);
}

void system::io::pic::initIdt()
{
    // IDT_Table[1].setHandler();
}

void system::io::pic::writeBtye(uint16_t port, uint8_t data)
{
    asm("movw %0, %%dx;\
         movb %1, %%al;\
         outb %%al, %%dx;"
        :
        : "r"(port), "r"(data)
        : "%al", "%dx");
}
void system::io::pic::writeWord(uint16_t port, uint16_t data)
{
    asm("movw %0, %%dx;\
         movw %1, %%ax;\
         outw %%ax, %%dx;"
        :
        : "r"(port), "r"(data)
        : "%ax", "%dx");
}
void system::io::pic::writeDWord(uint16_t port, uint32_t data)
{
    asm("movw %0, %%dx;\
         movl %1, %%eax;\
         outl %%eax, %%dx;"
        :
        : "r"(port), "r"(data)
        : "%eax", "%dx");
}

uint8_t system::io::pic::readBtye(uint16_t port)
{
    uint8_t data;

    asm("movw %1, %%dx;\
         inb %%dx, %%al;\
         movb %%al, %0;"
        : "=r"(data)
        : "r"(port)
        : "%al", "%dx");

    return data;
}

uint16_t system::io::pic::readWord(uint16_t port)
{
    uint16_t data;

    asm("movw %1, %%dx;\
         inw %%dx, %%ax;\
         movw %%ax, %0;"
        : "=r"(data)
        : "r"(port)
        : "%ax", "%dx");

    return data;
}

uint32_t system::io::pic::readDWord(uint16_t port)
{
    uint32_t data;

    asm("movw %1, %%dx;\
         inl %%dx, %%eax;\
         movl %%eax, %0;"
        : "=r"(data)
        : "r"(port)
        : "%eax", "%dx");

    return data;
}