#include "gdt.hpp"

const system::memory::gdt::GdtDescriptor system::memory::gdt::gdtTable[system::memory::gdt::MAX_DESCRIPTOR_NUMBER] = {
    // base, limit, access, flags
    SET_GDT_DESCRIPTOR(0, 0, 0, 0),                     // 0 NULL descriptor 0x00
    SET_GDT_DESCRIPTOR(0, 0, 0b10011000, 0b0010),       // 1 Kernel Code 64-bit Segment 0x08
    SET_GDT_DESCRIPTOR(0, 0, 0b10010010, 0b0000),       // 2 Kernel Data 64-bit Segment 0x10
    SET_GDT_DESCRIPTOR(0, 0, 0b11111000, 0b0010),       // 3 User Code 64-bit Segment 0x18
    SET_GDT_DESCRIPTOR(0, 0, 0b11110010, 0b0000),       // 4 User Data 64-bit Segment 0x20
    SET_GDT_DESCRIPTOR(0, 0xfffff, 0b10011010, 0b1100), // 5 Kernel Code 32-bit Segment 0x28
    SET_GDT_DESCRIPTOR(0, 0xfffff, 0b10010010, 0b1100), // 6 Kernel Data 32-bit Segment 0x30
};

const system::memory::gdt::GdtTableDescriptor system::memory::gdt::gdtTableDescriptor = {
    sizeof(system::memory::gdt::gdtTable) * 8 - 1, (uint64_t)(system::memory::gdt::gdtTable)};