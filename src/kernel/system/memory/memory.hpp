#pragma once

#define VIRTUAL_TO_PHYICAL_ADDR(addr) ((addr)-system::memory::KERNEL_ADDR_BASE)
#define PHYICAL_TO_VIRTUAL_ADDR(addr) ((addr) + system::memory::KERNEL_ADDR_BASE)

namespace system
{
    namespace memory
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

        void *VirtualToPhyicalAddr(void *addr);

        void *PhyicalToVirtualAddr(void *addr);

        void *Page1gAlign(void *addr);

        void *Page2mAlign(void *addr);
        void *Page4kAlign(void *addr);

        void *PageAlign(void *addr);

        void initMemory();
        void *allocatePages(unsigned count);
        void freePages(void *addr);

    } // namespace memory

} // namespace system
