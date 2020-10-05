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
        const unsigned PAGE_CURRENT_SHIFT = PAGE_2M_SHIFT;

        // size pre page
        const unsigned long PAGE_1G_SIZE = 1ul << PAGE_1G_SHIFT;
        const unsigned long PAGE_2M_SIZE = 1ul << PAGE_2M_SHIFT;
        const unsigned long PAGE_4K_SIZE = 1ul << PAGE_4K_SHIFT;
        const unsigned long PAGE_CURRENT_SIZE = PAGE_2M_SIZE;

        // page mask
        const unsigned long PAGE_1G_MASK = ~(PAGE_1G_SIZE - 1);
        const unsigned long PAGE_2M_MASK = ~(PAGE_2M_SIZE - 1);
        const unsigned long PAGE_4K_MASK = ~(PAGE_4K_SIZE - 1);
        const unsigned long PAGE_CURRENT_MASK = PAGE_2M_MASK;

        inline void *VirtualToPhyicalAddr(void *addr)
        {
            return (void *)((unsigned long)addr - KERNEL_ADDR_BASE);
        }

        inline void *PhyicalToVirtualAddr(void *addr)
        {
            return (void *)((unsigned long)addr + KERNEL_ADDR_BASE);
        }

        inline void *Page1gAlign(void *addr)
        {
            // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
            // we cannot use (addr & PAGE_1G_MASK) because the result may be lower than addr which is illegal.
            // this method may waste some space but it's necessary.
            return (void *)(((unsigned long)addr + PAGE_1G_SIZE - 1) & PAGE_1G_MASK);
        }

        inline void *Page2mAlign(void *addr)
        {
            // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
            // we cannot use (addr & PAGE_2M_MASK) because the result may be lower than addr which is illegal.
            // this method may waste some space but it's necessary.
            return (void *)(((unsigned long)addr + PAGE_2M_SIZE - 1) & PAGE_2M_MASK);
        }

        inline void *Page4kAlign(void *addr)
        {
            // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
            // we cannot use (addr & PAGE_4K_MASK) because the result may be lower than addr which is illegal.
            // this method may waste some space but it's necessary.
            return (void *)(((unsigned long)addr + PAGE_4K_SIZE - 1) & PAGE_4K_MASK);
        }

        inline void *PageCurrentAlign(void *addr)
        {
            return Page2mAlign(addr);
        }

        void initMemory();
        void *allocatePages(unsigned count);
        void freePages(void *addr);

    } // namespace memory

} // namespace system
