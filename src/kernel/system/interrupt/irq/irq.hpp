#pragma once

#include <system/interrupt/interrupt_frame.hpp>

namespace system::interrupt::irq
{
    using IrqCall = void(interrupt_frame *frame);

    IrqCall irq0x00;
    IrqCall irq0x01;
    IrqCall irq0x02;
    IrqCall irq0x03;
    IrqCall irq0x04;
    IrqCall irq0x05;
    IrqCall irq0x06;
    IrqCall irq0x07;
    IrqCall irq0x08;
    IrqCall irq0x09;
    IrqCall irq0x0a;
    IrqCall irq0x0b;
    IrqCall irq0x0c;
    IrqCall irq0x0d;
    IrqCall irq0x0e;
    IrqCall irq0x0f;
    IrqCall irq0x10;
    IrqCall irq0x11;
    IrqCall irq0x12;
    IrqCall irq0x13;
    IrqCall irq0x14;
    IrqCall irq0x15;
    IrqCall irq0x16;
    IrqCall irq0x17;
    IrqCall irq0x18;
    IrqCall irq0x19;
    IrqCall irq0x1a;
    IrqCall irq0x1b;
    IrqCall irq0x1c;
    IrqCall irq0x1d;
    IrqCall irq0x1e;
    IrqCall irq0x1f;
    IrqCall irq0x20;
    IrqCall irq0x21;
    IrqCall irq0x22;
    IrqCall irq0x23;
    IrqCall irq0x24;
    IrqCall irq0x25;
    IrqCall irq0x26;
    IrqCall irq0x27;
    IrqCall irq0x28;
    IrqCall irq0x29;
    IrqCall irq0x2a;
    IrqCall irq0x2b;
    IrqCall irq0x2c;
    IrqCall irq0x2d;
    IrqCall irq0x2e;
    IrqCall irq0x2f;

    extern const IrqCall *irqs[0x30];
} // namespace system::interrupt::irq
