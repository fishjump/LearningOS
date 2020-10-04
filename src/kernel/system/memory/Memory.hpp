#pragma once

#define VIRTUAL_TO_PHYICAL_ADDR(addr) ((unsigned long)(addr) - system::memory::KERNEL_ADDR_OFFSET)
#define PHYICAL_TO_VIRTUAL_ADDR(addr) ((unsigned long)(addr) + system::memory::KERNEL_ADDR_OFFSET)

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
        constexpr unsigned long KERNEL_ADDR_OFFSET = 0xffff800000000000;
        constexpr unsigned long USER_ADDR_OFFSET =   0x0000000000000000;

        // internal page bits' length
        constexpr unsigned PAGE_1G_SHIFT = 30;
        constexpr unsigned PAGE_2M_SHIFT = 21;
        constexpr unsigned PAGE_4K_SHIFT = 12;

        // size pre page
        constexpr unsigned long PAGE_1G_SIZE = 1ul << PAGE_1G_SHIFT;
        constexpr unsigned long PAGE_2M_SIZE = 1ul << PAGE_2M_SHIFT;
        constexpr unsigned long PAGE_4K_SIZE = 1ul << PAGE_4K_SHIFT;

        // page mask
        constexpr unsigned long PAGE_1G_MASK = ~(PAGE_1G_SIZE - 1);
        constexpr unsigned long PAGE_2M_MASK = ~(PAGE_2M_SIZE - 1);
        constexpr unsigned long PAGE_4K_MASK = ~(PAGE_4K_SIZE - 1);

        inline unsigned long VirtualToPhyicalAddr(unsigned long addr)
        {
            return addr - KERNEL_ADDR_OFFSET;
        }

        inline unsigned long PhyicalToVirtualAddr(unsigned long addr)
        {
            return addr + KERNEL_ADDR_OFFSET;
        }

        inline unsigned long Page1gAlign(unsigned long addr)
        {
            // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
            // we cannot use (addr & PAGE_1G_MASK) because the result may be lower than addr which is illegal.
            // this method may waste some space but it's necessary.
            return (addr + PAGE_1G_SIZE - 1) & PAGE_1G_MASK;
        }

        inline unsigned long Page2mAlign(unsigned long addr)
        {
            // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
            // we cannot use (addr & PAGE_2M_MASK) because the result may be lower than addr which is illegal.
            // this method may waste some space but it's necessary.
            return (addr + PAGE_2M_SIZE - 1) & PAGE_2M_MASK;
        }

        inline unsigned long Page4kAlign(unsigned long addr)
        {
            // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
            // we cannot use (addr & PAGE_4K_MASK) because the result may be lower than addr which is illegal.
            // this method may waste some space but it's necessary.
            return (addr + PAGE_4K_SIZE - 1) & PAGE_4K_MASK;
        }
        
    } // namespace memory

} // namespace system
