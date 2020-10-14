#include "IdtDescriptor.hpp"

#include <std/type.hpp>

void system::interrupt::idt::IdtDescriptor::setHandler(uint64_t handler)
{
    uint64_t address = (uint64_t)handler;
    selector = 0x08;
    ist = 0;
    typeAttribute = (0b1 << 7 & 0b10000000) | (0b00 << 5 & 0b01100000) | (0b0 << 4 & 0b00010000) | (0xe & 0b00001111);
    handlerOffset1 = address & 0xffff;
    handlerOffset2 = (address >> 16) & 0xffff;
    handlerOffset3 = (address >> 32) & 0xffffffff;
    reserved = 0;
}