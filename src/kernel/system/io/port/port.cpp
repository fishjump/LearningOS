#include "port.hpp"

void system::io::port::writeBtye(uint16_t port, uint8_t data)
{
    asm volatile("movw %0, %%dx;\
                  movb %1, %%al;\
                  outb %%al, %%dx;"
                 :
                 : "r"(port), "r"(data)
                 : "%al", "%dx");
}
void system::io::port::writeWord(uint16_t port, uint16_t data)
{
    asm volatile("movw %0, %%dx;\
                  movw %1, %%ax;\
                  outw %%ax, %%dx;"
                 :
                 : "r"(port), "r"(data)
                 : "%ax", "%dx");
}
void system::io::port::writeDWord(uint16_t port, uint32_t data)
{
    asm volatile("movw %0, %%dx;\
                  movl %1, %%eax;\
                  outl %%eax, %%dx;"
                 :
                 : "r"(port), "r"(data)
                 : "%eax", "%dx");
}

uint8_t system::io::port::readBtye(uint16_t port)
{
    uint8_t data;

    asm volatile("movw %1, %%dx;\
                  inb %%dx, %%al;\
                  movb %%al, %0;"
                 : "=r"(data)
                 : "r"(port)
                 : "%al", "%dx");

    return data;
}

uint16_t system::io::port::readWord(uint16_t port)
{
    uint16_t data;

    asm volatile("movw %1, %%dx;\
                  inw %%dx, %%ax;\
                  movw %%ax, %0;"
                 : "=r"(data)
                 : "r"(port)
                 : "%ax", "%dx");

    return data;
}

uint32_t system::io::port::readDWord(uint16_t port)
{
    uint32_t data;

    asm volatile("movw %1, %%dx;\
                  inl %%dx, %%eax;\
                  movl %%eax, %0;"
                 : "=r"(data)
                 : "r"(port)
                 : "%eax", "%dx");

    return data;
}