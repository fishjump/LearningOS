#pragma once

#include <std/stdcxx.hpp>

#define SET_GDT_DESCRIPTOR(base, limit, access, flags) \
    {                                                  \
        (uint16_t)(limit),                             \
            (uint16_t)(base),                          \
            (uint8_t)((base) >> 16),                   \
            (access),                                  \
            (uint8_t)((limit) >> 16),                  \
            (uint8_t)(flags),                          \
            (uint8_t)((base) >> 24),                   \
    }

namespace system::memory::gdt
{
    class GdtTableDescriptor
    {
    public:
        uint16_t length;
        uint64_t addr;
    } __attribute__((packed));

    class GdtDescriptor
    {
    public:
        uint16_t limit1;
        uint16_t base1;
        uint8_t base2;
        uint8_t access;
        uint8_t limit2 : 4;
        uint8_t flags : 4;
        uint8_t base3;

        void setDescriptor(uint32_t base, uint32_t limit, uint8_t access, uint8_t flags);
    } __attribute__((packed));

    const size_t MAX_DESCRIPTOR_NUMBER = 10;
    extern "C" const GdtDescriptor gdtTable[MAX_DESCRIPTOR_NUMBER];
    extern "C" const GdtTableDescriptor gdtTableDescriptor;
} // namespace system::memory::gdt
