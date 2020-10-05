#pragma once

#include <system/memory/Memory.hpp>

#include "../MemoryDescriptor.hpp"

unsigned int system::memory::MemoryDescriptor::pages() const
{
    void *start, *end;
    start = system::memory::PageCurrentAlign(this->address);
    end = (void *)(((unsigned long)this->address + this->length) & system::memory::PAGE_CURRENT_MASK);

    return start > end ? 0 : ((unsigned long)end - (unsigned long)start) >> system::memory::PAGE_CURRENT_SHIFT;
}