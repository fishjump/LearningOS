#pragma once

#include <std/type.hpp>
#include <system/interrupt/idt/idt_descriptor.hpp>
#include <system/interrupt/idt/idt_table_descriptor.hpp>

namespace system::interrupt::idt
{
    const uint16_t MAX_INT_NUMBER = 256;

    extern "C" IdtDescriptor idtTable[MAX_INT_NUMBER];
    extern "C" const IdtTableDescriptor idtTableDescriptor;

    void initIdt();

} // namespace system::interrupt::idt
