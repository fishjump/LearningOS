#include "idt.hpp"

#include <std/type.hpp>
#include <system/interrupt/idt/idt_descriptor.hpp>
#include <system/interrupt/idt/idt_table_descriptor.hpp>
#include <system/interrupt/irq.hpp>

void system::interrupt::idt::initIdt()
{
    for (int i = 0x00; i < 0x2f; i++)
    {
        system::interrupt::idt::idtTable[i].setHandler((uint64_t)irq::irqs[i], 0x08, system::interrupt::idt::IdtDescriptorType::InterruptGate32, 0);
    }
}

system::interrupt::idt::IdtDescriptor system::interrupt::idt::idtTable[system::interrupt::idt::MAX_INTERRUPT_NUMBER] = {0};
const system::interrupt::idt::IdtTableDescriptor system::interrupt::idt::idtTableDescriptor = {
    sizeof(system::interrupt::idt::idtTable) * 8 - 1, (uint64_t)system::interrupt::idt::idtTable};
