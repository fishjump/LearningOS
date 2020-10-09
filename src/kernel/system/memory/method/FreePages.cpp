#pragma once

#include <system/memory.hpp>

#include "../memory.hpp"

void system::memory::freePages(void *addr)
{
    MemoryDescriptor *descriptors = globalMemoryDescriptor.memoryDescriptors;
    unsigned int count = globalMemoryDescriptor.memoryDescriptorsCount;

    for (int i = 0; i < count; i++)
    {
        if (descriptors[i].address == addr)
        {
            descriptors[i].free = true;
            return;
        }
    }
}