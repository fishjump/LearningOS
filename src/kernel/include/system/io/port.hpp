#pragma once

#include <std/stdcxx.hpp>

namespace system::io::port
{
    namespace pic
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
    } // namespace pic

    void writeBtye(uint16_t port, uint8_t data);
    void writeWord(uint16_t port, uint16_t data);
    void writeDWord(uint16_t port, uint32_t data);

    uint8_t readBtye(uint16_t port);
    uint16_t readWord(uint16_t port);
    uint32_t readDWord(uint16_t port);

} // namespace system::io::port