#pragma once

#include <std/type.hpp>

namespace system::io::port::pic
{
    const uint16_t PIC0_IMR = 0x21;
    const uint16_t PIC1_IMR = 0xa1;

    const uint16_t PIC0_ICW1 = 0x20;
    const uint16_t PIC0_ICW2 = 0x21;
    const uint16_t PIC0_ICW3 = 0x21;
    const uint16_t PIC0_ICW4 = 0x21;

    const uint16_t PIC1_ICW1 = 0xa0;
    const uint16_t PIC1_ICW2 = 0xa1;
    const uint16_t PIC1_ICW3 = 0xa1;
    const uint16_t PIC1_ICW4 = 0xa1;

} // namespace system::io::port::pic
