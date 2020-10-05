#pragma once

#include <system/boot.hpp>
#include <system/memory/MemoryDescriptor.hpp>

namespace system
{
    namespace memory
    {
        // Assume we only have 2 GB physical memory with 2MB page size
        class GlobalMemoryDescriptor
        {
        public:
            static const unsigned MEMORY_DESCRIPTORS_COUNT_MAX = 1024;

            MemoryDescriptor memoryDescriptors[MEMORY_DESCRIPTORS_COUNT_MAX];
            unsigned long memoryDescriptorsCount;

            unsigned long usableMemory;
            unsigned int usablePages;
        };

        GlobalMemoryDescriptor globalMemoryDescriptor;

    } // namespace memory

} // namespace system
