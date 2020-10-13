#pragma once

#include <std/type.hpp>

namespace system
{
    namespace io
    {
        namespace pic
        {
            class IdtTableDescriptor
            {
            public:
                uint16_t length;
                uint64_t addr;
            } __attribute__((packed));
        } // namespace pic

    } // namespace io

} // namespace system
