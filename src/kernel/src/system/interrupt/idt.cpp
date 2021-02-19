#include <std/type.hpp>
#include <system/interrupt/idt.hpp>
#include <system/interrupt/irq.hpp>

namespace system::interrupt::idt
{
    InterruptDescriptor interruptDescriptorTable[MAX_INTERRUPT_TABLE_SIZE] = {0};
    const InterruptDescriptorTableDescriptor idtDescriptor = {
        sizeof(interruptDescriptorTable) * 8 - 1, (uint64_t)interruptDescriptorTable};

    void initIdt()
    {
        for (int i = 0x00; i < 0x2f; i++)
        {
            interruptDescriptorTable[i].setHandler((uint64_t)irq::irqs[i], 0x08, InterruptDescriptorAttribute::InterruptGate32, 0);
        }
    }

    void InterruptDescriptor::setHandler(uint64_t handler, uint16_t gdtSelector, InterruptDescriptorAttribute type, uint8_t privilege)
    {
        uint64_t address = handler;
        selector = gdtSelector;
        typeAttribute = (0b1 << 7 & 0b10000000) | (privilege << 5 & 0b01100000) | (0b0 << 4 & 0b00010000) | (type & 0b00001111);
        handlerOffset1 = address & 0xffff;
        handlerOffset2 = (address >> 16) & 0xffff;
        handlerOffset3 = (address >> 32) & 0xffffffff;

        ist = 0;
        reserved = 0;
    }
} // namespace system::interrupt::idt
