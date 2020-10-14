#pragma once

#include <std/type.hpp>

namespace system::io::port
{
    void writeBtye(uint16_t port, uint8_t data);
    void writeWord(uint16_t port, uint16_t data);
    void writeDWord(uint16_t port, uint32_t data);

    uint8_t readBtye(uint16_t port);
    uint16_t readWord(uint16_t port);
    uint32_t readDWord(uint16_t port);

} // namespace system::io::port
