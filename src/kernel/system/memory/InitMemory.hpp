#pragma once

#include <system/boot.hpp>

#include "GlobalMemory.hpp"
#include "Memory.hpp"

namespace system
{
    namespace memory
    {
        int initMemory()
        {
            int count = system::boot::bootInfo->memoryInfo.count;

            unsigned long totalUsableMemory = 0;
            const system::boot::MemoryDescriptor *descriptors = system::boot::bootInfo->memoryInfo.descriptors;
            for (int i = 0; i < count; i++)
            {
                if (descriptors[i].type == 1)
                {
                    totalUsableMemory += descriptors[i].length;
                }

                globalMemoryDescriptor.memoryDescriptors[i] = descriptors[i];
                globalMemoryDescriptor.descriptorsSize = i;

                // must be dirty data 
                if (descriptors[i].length == 0 || 1 > descriptors[i].type || descriptors[i].type > 4)
                {
                    break;
                }
            }

            unsigned long usablePagesCount = 0;
            for (int i = 0; i < globalMemoryDescriptor.descriptorsSize; i++)
            {
                if (globalMemoryDescriptor.memoryDescriptors[i].type != 1)
                {
                    continue;
                }

                unsigned long start, end;
                start = Page2mAlign(globalMemoryDescriptor.memoryDescriptors[i].address);
                end = (globalMemoryDescriptor.memoryDescriptors[i].address + descriptors[i].length) & PAGE_2M_MASK;

                if (start > end)
                {
                    continue;
                }

                usablePagesCount += (end - start) >> PAGE_2M_SHIFT;
            }

            return usablePagesCount;
        }
    } // namespace memory

} // namespace system
