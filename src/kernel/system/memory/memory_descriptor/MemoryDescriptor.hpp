#pragma once

#include <system/memory/memory_descriptor_type.hpp>

namespace system
{
    namespace memory
    {
        class MemoryDescriptor
        {
        public:
            void *address;
            unsigned long length;
            MemoryDescriptorType type;
            bool free = false;
            unsigned int pages() const;
        };

    } // namespace memory

} // namespace system
