#pragma once

#include <system/boot.hpp>

namespace system
{
    namespace memory
    {

        class GlobalMemoryDescriptor
        {
        public:
            system::boot::MemoryDescriptor memoryDescriptors[1024];
            unsigned long descriptorsSize;
        };

        GlobalMemoryDescriptor globalMemoryDescriptor;

    } // namespace memory

} // namespace system
