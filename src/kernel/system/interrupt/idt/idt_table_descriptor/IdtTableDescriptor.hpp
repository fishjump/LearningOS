#pragma once

#include <std/type.hpp>

namespace system::interrupt::idt
{
    class IdtTableDescriptor
    {
    public:
        uint16_t length;
        uint64_t addr;
    } __attribute__((packed));

} // namespace system::interrupt::idt
