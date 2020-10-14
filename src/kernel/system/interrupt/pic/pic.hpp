#pragma once

#include <std/type.hpp>

#include <system/interrupt/idt.hpp>

namespace system::interrupt::pic
{
    const uint16_t MAX_INT_NUMBER = 256;

    void initPic();

    extern "C" system::interrupt::idt::IdtDescriptor idtTable[MAX_INT_NUMBER];
    extern "C" const system::interrupt::idt::IdtTableDescriptor idtTableDescriptor;

} // namespace system::interrupt::pic
