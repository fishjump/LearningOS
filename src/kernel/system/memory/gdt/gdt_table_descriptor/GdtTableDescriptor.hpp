#pragma once

#include <std/type.hpp>

namespace system::memory::gdt
{
    class GdtTableDescriptor
    {
    public:
        uint16_t length;
        uint64_t addr;
    } __attribute__((packed));
} // namespace system::memory::gdt
