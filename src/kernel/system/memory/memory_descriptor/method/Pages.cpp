#pragma once

#include <system/memory.hpp>

#include "../MemoryDescriptor.hpp"

unsigned int system::memory::MemoryDescriptor::pages() const
{
    void *start, *end;
    start = system::memory::PageAlign(this->address);
    end = (void *)(((unsigned long)this->address + this->length) & system::memory::PAGE_MASK);

    return start > end ? 0 : ((unsigned long)end - (unsigned long)start) >> system::memory::PAGE_SHIFT;
}