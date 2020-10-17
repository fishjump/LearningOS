#include "irq.hpp"

#include "method/irq0x00.cpp"
#include "method/irq0x01.cpp"
#include "method/irq0x02.cpp"
#include "method/irq0x03.cpp"
#include "method/irq0x04.cpp"
#include "method/irq0x05.cpp"
#include "method/irq0x06.cpp"
#include "method/irq0x07.cpp"
#include "method/irq0x08.cpp"
#include "method/irq0x09.cpp"
#include "method/irq0x0a.cpp"
#include "method/irq0x0b.cpp"
#include "method/irq0x0c.cpp"
#include "method/irq0x0d.cpp"
#include "method/irq0x0e.cpp"
#include "method/irq0x0f.cpp"
#include "method/irq0x10.cpp"
#include "method/irq0x11.cpp"
#include "method/irq0x12.cpp"
#include "method/irq0x13.cpp"
#include "method/irq0x14.cpp"
#include "method/irq0x15.cpp"
#include "method/irq0x16.cpp"
#include "method/irq0x17.cpp"
#include "method/irq0x18.cpp"
#include "method/irq0x19.cpp"
#include "method/irq0x1a.cpp"
#include "method/irq0x1b.cpp"
#include "method/irq0x1c.cpp"
#include "method/irq0x1d.cpp"
#include "method/irq0x1e.cpp"
#include "method/irq0x1f.cpp"
#include "method/irq0x20.cpp"
#include "method/irq0x21.cpp"
#include "method/irq0x22.cpp"
#include "method/irq0x23.cpp"
#include "method/irq0x24.cpp"
#include "method/irq0x25.cpp"
#include "method/irq0x26.cpp"
#include "method/irq0x27.cpp"
#include "method/irq0x28.cpp"
#include "method/irq0x29.cpp"
#include "method/irq0x2a.cpp"
#include "method/irq0x2b.cpp"
#include "method/irq0x2c.cpp"
#include "method/irq0x2d.cpp"
#include "method/irq0x2e.cpp"
#include "method/irq0x2f.cpp"

const system::interrupt::irq::IrqCall *system::interrupt::irq::irqs[0x30] = {
    system::interrupt::irq::irq0x00,
    system::interrupt::irq::irq0x01,
    system::interrupt::irq::irq0x02,
    system::interrupt::irq::irq0x03,
    system::interrupt::irq::irq0x04,
    system::interrupt::irq::irq0x05,
    system::interrupt::irq::irq0x06,
    system::interrupt::irq::irq0x07,
    system::interrupt::irq::irq0x08,
    system::interrupt::irq::irq0x09,
    system::interrupt::irq::irq0x0a,
    system::interrupt::irq::irq0x0b,
    system::interrupt::irq::irq0x0c,
    system::interrupt::irq::irq0x0d,
    system::interrupt::irq::irq0x0e,
    system::interrupt::irq::irq0x0f,
    system::interrupt::irq::irq0x10,
    system::interrupt::irq::irq0x11,
    system::interrupt::irq::irq0x12,
    system::interrupt::irq::irq0x13,
    system::interrupt::irq::irq0x14,
    system::interrupt::irq::irq0x15,
    system::interrupt::irq::irq0x16,
    system::interrupt::irq::irq0x17,
    system::interrupt::irq::irq0x18,
    system::interrupt::irq::irq0x19,
    system::interrupt::irq::irq0x1a,
    system::interrupt::irq::irq0x1b,
    system::interrupt::irq::irq0x1c,
    system::interrupt::irq::irq0x1d,
    system::interrupt::irq::irq0x1e,
    system::interrupt::irq::irq0x1f,
    system::interrupt::irq::irq0x20,
    system::interrupt::irq::irq0x21,
    system::interrupt::irq::irq0x22,
    system::interrupt::irq::irq0x23,
    system::interrupt::irq::irq0x24,
    system::interrupt::irq::irq0x25,
    system::interrupt::irq::irq0x26,
    system::interrupt::irq::irq0x27,
    system::interrupt::irq::irq0x28,
    system::interrupt::irq::irq0x29,
    system::interrupt::irq::irq0x2a,
    system::interrupt::irq::irq0x2b,
    system::interrupt::irq::irq0x2c,
    system::interrupt::irq::irq0x2d,
    system::interrupt::irq::irq0x2e,
    system::interrupt::irq::irq0x2f,
};
