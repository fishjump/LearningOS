#pragma once

#include <std/type.hpp>

namespace system::interrupt::idt
{
    enum IdtDescriptorType : uint8_t
    {
        TaskGate32 = 0x5,
        InterruptGate16 = 0x6,
        TrapGate16 = 0x7,
        InterruptGate32 = 0xe,
        TrapGate32 = 0xf
    };
} // namespace system::interrupt::idt
