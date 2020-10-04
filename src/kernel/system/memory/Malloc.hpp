#pragma once

#include <system/boot.hpp>

namespace system
{
    namespace memory
    {
        void* malloc(unsigned size) {
            // int count = system::boot::bootInfo->memoryInfo.count;
            // const system::boot::MemoryDescriptor *descriptor = system::boot::bootInfo->memoryInfo.descriptors;

            // for(int i = 0; i < count; i++) {
            //     if(descriptor[i].type == 1)
            // }
        }
    } // namespace memory
    
} // namespace system
