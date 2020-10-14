#pragma once

#include "../memory.hpp"

#include <system/memory/global_memory.hpp>

void *system::memory::allocatePages(unsigned count)
{
    unsigned memoryDescriptorsCount = globalMemoryDescriptor.memoryDescriptorsCount;
    if (memoryDescriptorsCount >= GlobalMemoryDescriptor::MEMORY_DESCRIPTORS_COUNT_MAX)
    {
        // Cannot hold more descriptors
        return nullptr;
    }

    for (int i = 0; i < memoryDescriptorsCount; i++)
    {
        if (globalMemoryDescriptor.memoryDescriptors[i].type == MemoryDescriptorType::RAM &&
            globalMemoryDescriptor.memoryDescriptors[i].pages() >= count)
        {
            void *addr = (void *)globalMemoryDescriptor.memoryDescriptors[i].address;
            MemoryDescriptor newNode;
            newNode.address = addr;
            newNode.length = count * PAGE_SIZE;
            newNode.type = globalMemoryDescriptor.memoryDescriptors[i].type;
            newNode.free = false;

            globalMemoryDescriptor.memoryDescriptors[i].address = (void *)((unsigned long)globalMemoryDescriptor.memoryDescriptors[i].address + newNode.length);
            globalMemoryDescriptor.memoryDescriptors[i].length -= newNode.length;

            for (int j = memoryDescriptorsCount - 1; j >= i; j--)
            {
                globalMemoryDescriptor.memoryDescriptors[j] = globalMemoryDescriptor.memoryDescriptors[j + 1];
            }

            globalMemoryDescriptor.memoryDescriptors[i] = newNode;

            return addr;
        }
    }
    return nullptr;
}