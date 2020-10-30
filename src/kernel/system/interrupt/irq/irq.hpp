#pragma once

#include <system/interrupt/interrupt_frame.hpp>

#define IrqList \
    X(irq0x00)  \
    X(irq0x01)  \
    X(irq0x02)  \
    X(irq0x03)  \
    X(irq0x04)  \
    X(irq0x05)  \
    X(irq0x06)  \
    X(irq0x07)  \
    X(irq0x08)  \
    X(irq0x09)  \
    X(irq0x0a)  \
    X(irq0x0b)  \
    X(irq0x0c)  \
    X(irq0x0d)  \
    X(irq0x0e)  \
    X(irq0x0f)  \
    X(irq0x10)  \
    X(irq0x11)  \
    X(irq0x12)  \
    X(irq0x13)  \
    X(irq0x14)  \
    X(irq0x15)  \
    X(irq0x16)  \
    X(irq0x17)  \
    X(irq0x18)  \
    X(irq0x19)  \
    X(irq0x1a)  \
    X(irq0x1b)  \
    X(irq0x1c)  \
    X(irq0x1d)  \
    X(irq0x1e)  \
    X(irq0x1f)  \
    X(irq0x20)  \
    X(irq0x21)  \
    X(irq0x22)  \
    X(irq0x23)  \
    X(irq0x24)  \
    X(irq0x25)  \
    X(irq0x26)  \
    X(irq0x27)  \
    X(irq0x28)  \
    X(irq0x29)  \
    X(irq0x2a)  \
    X(irq0x2b)  \
    X(irq0x2c)  \
    X(irq0x2d)  \
    X(irq0x2e)  \
    X(irq0x2f)

namespace system::interrupt::irq
{
    using IrqCall = __attribute__((interrupt)) void(interrupt_frame *frame);
    extern const IrqCall *irqs[0x30];

#define X(name) IrqCall name;
    IrqList
#undef X
} // namespace system::interrupt::irq
