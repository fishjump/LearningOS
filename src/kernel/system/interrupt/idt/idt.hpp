#pragma once

#include <std/type.hpp>
#include <system/interrupt/idt/idt_descriptor.hpp>
#include <system/interrupt/idt/idt_table_descriptor.hpp>

namespace system::interrupt::idt
{
    const size_t MAX_INTERRUPT_NUMBER = 256;

    extern "C" IdtDescriptor idtTable[MAX_INTERRUPT_NUMBER];
    extern "C" const IdtTableDescriptor idtTableDescriptor;

    void initIdt();

} // namespace system::interrupt::idt
