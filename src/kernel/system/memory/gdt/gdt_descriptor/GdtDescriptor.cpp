#include "GdtDescriptor.hpp"

#include <std/type.hpp>

void system::memory::gdt::GdtDescriptor::setDescriptor(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags)
{
    limit1 = (uint16_t)limit;
    limit2 = (uint8_t)(limit >> 16);
    base1 = (uint16_t)base;
    base2 = (uint8_t)(base >> 16);
    base3 = (uint8_t)(base >> 24);
    this->access = access;
    this->flags = flags;
}