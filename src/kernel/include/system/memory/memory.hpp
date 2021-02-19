#pragma once

#define VIRTUAL_TO_PHYICAL_ADDR(addr) ((addr) - (system::memory::KERNEL_ADDR_BASE))
#define PHYICAL_TO_VIRTUAL_ADDR(addr) ((addr) + (system::memory::KERNEL_ADDR_BASE))

namespace system::memory
{
    // virtual addr offset
    // x86_64 addr structure:
    // 64 bits length, but only 48 bits are valid.
    // the higher 16 bits must be all 0s or all 1s, and must be same as the 17th highest bit.
    // so, we can let the higher 17 bits all 1s to be kernel addr space
    // and let the higher 17 bits all 0s as user addr space
    const unsigned long KERNEL_ADDR_BASE = 0xffff800000000000ul;
    const unsigned long USER_ADDR_BASE = 0x0000000000000000ul;

    // internal page bits' length
    const unsigned PAGE_1G_SHIFT = 30;
    const unsigned PAGE_2M_SHIFT = 21;
    const unsigned PAGE_4K_SHIFT = 12;
    const unsigned PAGE_SHIFT = PAGE_2M_SHIFT;

    // size pre page
    const unsigned long PAGE_1G_SIZE = 1ul << PAGE_1G_SHIFT;
    const unsigned long PAGE_2M_SIZE = 1ul << PAGE_2M_SHIFT;
    const unsigned long PAGE_4K_SIZE = 1ul << PAGE_4K_SHIFT;
    const unsigned long PAGE_SIZE = PAGE_2M_SIZE;

    // page mask
    const unsigned long PAGE_1G_MASK = ~(PAGE_1G_SIZE - 1);
    const unsigned long PAGE_2M_MASK = ~(PAGE_2M_SIZE - 1);
    const unsigned long PAGE_4K_MASK = ~(PAGE_4K_SIZE - 1);
    const unsigned long PAGE_MASK = PAGE_2M_MASK;
    
    enum MemoryDescriptorType
    {
        RAM = 1,
        ROM = 2,
        ACPI_RECLAIM = 3,
        ACPI_NVS = 4,
        UNUSABLE = 5
    };
    
    class MemoryDescriptor
    {
    public:
        void *address;
        unsigned long length;
        MemoryDescriptorType type;
        bool free = false;
        unsigned int pages() const;
    };

    // Assume we only have 2 GB physical memory with 2MB page size
    class GlobalMemoryDescriptor
    {
    public:
        static const unsigned MEMORY_DESCRIPTORS_COUNT_MAX = 1024;

        MemoryDescriptor memoryDescriptors[MEMORY_DESCRIPTORS_COUNT_MAX];
        unsigned long memoryDescriptorsCount;

        unsigned long usableMemory;
        unsigned int usablePages;
    };

    extern GlobalMemoryDescriptor globalMemoryDescriptor;

    void *virtualToPhyicalAddr(void *addr);

    void *phyicalToVirtualAddr(void *addr);

    void *page1gAlign(void *addr);

    void *page2mAlign(void *addr);
    void *page4kAlign(void *addr);

    void *pageAlign(void *addr);

    void initMemory();
    void *allocatePages(unsigned count);
    void freePages(void *addr);

} // namespace system::memory
