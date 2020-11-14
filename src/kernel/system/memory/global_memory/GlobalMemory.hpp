#pragma once

#include <system/boot.hpp>
#include <system/memory/memory_descriptor.hpp>

namespace system::memory
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

    extern GlobalMemoryDescriptor globalMemoryDescriptor;

} // namespace system::memory
