#pragma once

#include <std/type.hpp>

namespace system::interrupt::idt
{
    enum InterruptDescriptorAttribute : uint8_t
    {
        TaskGate32 = 0x5,
        InterruptGate16 = 0x6,
        TrapGate16 = 0x7,
        InterruptGate32 = 0xe,
        TrapGate32 = 0xf
    };

    class InterruptDescriptor
    {
    public:
        uint16_t handlerOffset1; // offset bits 0..15
        uint16_t selector;       // a code segment selector in GDT or LDT
        uint8_t ist;             // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
        uint8_t typeAttribute;   // type and attributes
        uint16_t handlerOffset2; // offset bits 16..31
        uint32_t handlerOffset3; // offset bits 32..63
        uint32_t reserved;       // reserved
        void setHandler(uint64_t handler, uint16_t gdtSelector, InterruptDescriptorAttribute type, uint8_t privilege = 0b11);
    } __attribute__((packed));

    class InterruptDescriptorTableDescriptor
    {
    public:
        uint16_t length;
        uint64_t addr;
    } __attribute__((packed));

    const size_t MAX_INTERRUPT_TABLE_SIZE = 256;
    extern "C" InterruptDescriptor interruptDescriptorTable[MAX_INTERRUPT_TABLE_SIZE];
    extern "C" const InterruptDescriptorTableDescriptor idtDescriptor;

    void initIdt();
} // namespace system::interrupt::idt
