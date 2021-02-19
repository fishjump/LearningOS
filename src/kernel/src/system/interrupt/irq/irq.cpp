#include <system/interrupt/irq.hpp>

#define X(name) system::interrupt::irq::name,
const system::interrupt::irq::IrqCall *system::interrupt::irq::irqs[0x30] = {
    IrqList};
#undef X