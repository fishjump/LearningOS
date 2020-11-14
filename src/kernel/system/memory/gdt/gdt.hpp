#pragma once

#include <system/memory/gdt/gdt_descriptor.hpp>
#include <system/memory/gdt/gdt_table_descriptor.hpp>

namespace system::memory::gdt
{
    const size_t MAX_DESCRIPTOR_NUMBER = 10;
    extern "C" const GdtDescriptor gdtTable[MAX_DESCRIPTOR_NUMBER];
    extern "C" const GdtTableDescriptor gdtTableDescriptor;
} // namespace system::memory::gdt
