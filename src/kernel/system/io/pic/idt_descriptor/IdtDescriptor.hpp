#pragma once

#include <std/type.hpp>

namespace system
{
    namespace io
    {
        namespace pic
        {
            class IdtDescriptor
            {
            public:
                uint16_t handlerOffset1; // offset bits 0..15
                uint16_t selector;       // a code segment selector in GDT or LDT
                uint8_t ist;             // bits 0..2 holds Interrupt Stack Table offset, rest of bits zero.
                uint8_t typeAttribute;   // type and attributes
                uint16_t handlerOffset2; // offset bits 16..31
                uint32_t handlerOffset3; // offset bits 32..63
                uint32_t reserved;       // reserved
                void setHandler(uint64_t handler);
            } __attribute__((packed));
        } // namespace pic

    } // namespace io

} // namespace system
