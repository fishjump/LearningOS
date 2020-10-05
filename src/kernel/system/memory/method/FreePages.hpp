#pragma once

#include <system/memory/GlobalMemory.hpp>
#include <system/memory/Memory.hpp>
#include <system/memory/MemoryDescriptor.hpp>
#include <system/memory/MemoryDescriptorType.hpp>

#include "../Memory.hpp"

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