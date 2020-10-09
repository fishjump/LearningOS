#pragma once

#include <system/boot.hpp>
#include <system/memory.hpp>

#include "../memory.hpp"

void system::memory::initMemory()
{
    int count = system::boot::bootInfo->memoryInfo.count;

    unsigned long usableMemory = 0;
    const system::boot::MemoryDescriptor *descriptors = system::boot::bootInfo->memoryInfo.descriptors;
    int i = 0;
    for (; i < count && i < GlobalMemoryDescriptor::MEMORY_DESCRIPTORS_COUNT_MAX; i++)
    {
        if (descriptors[i].type == MemoryDescriptorType::RAM)
        {
            usableMemory += descriptors[i].length;
            globalMemoryDescriptor.memoryDescriptors[i].free = true;
        }

        globalMemoryDescriptor.memoryDescriptors[i].address = descriptors[i].address;
        globalMemoryDescriptor.memoryDescriptors[i].length = descriptors[i].length;
        globalMemoryDescriptor.memoryDescriptors[i].type = (MemoryDescriptorType)descriptors[i].type;

        // must be dirty data
        if (descriptors[i].length == 0 || descriptors[i].type < MemoryDescriptorType::RAM || descriptors[i].type > MemoryDescriptorType::UNUSABLE)
        {
            break;
        }
    }

    globalMemoryDescriptor.memoryDescriptorsCount = i;
    globalMemoryDescriptor.usableMemory = usableMemory;

    unsigned long usablePages = 0;
    for (int i = 0; i < globalMemoryDescriptor.memoryDescriptorsCount; i++)
    {
        if (globalMemoryDescriptor.memoryDescriptors[i].type != MemoryDescriptorType::RAM)
        {
            continue;
        }

        usablePages += globalMemoryDescriptor.memoryDescriptors[i].pages();
    }
    globalMemoryDescriptor.usablePages = usablePages;
}
