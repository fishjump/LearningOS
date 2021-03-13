#include <system/memory.hpp>

void *system::memory::virtualToPhyicalAddr(void *addr)
{
    return (void *)((unsigned long)addr - KERNEL_ADDR_BASE);
}

void *system::memory::phyicalToVirtualAddr(void *addr)
{
    return (void *)((unsigned long)addr + KERNEL_ADDR_BASE);
}

void *system::memory::page1gAlign(void *addr)
{
    // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
    // we cannot use (addr & PAGE_1G_MASK) because the result may be lower than addr which is illegal.
    // this method may waste some space but it's necessary.
    return (void *)(((unsigned long)addr + PAGE_1G_SIZE - 1) & PAGE_1G_MASK);
}

void *system::memory::page2mAlign(void *addr)
{
    // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
    // we cannot use (addr & PAGE_2M_MASK) because the result may be lower than addr which is illegal.
    // this method may waste some space but it's necessary.
    return (void *)(((unsigned long)addr + PAGE_2M_SIZE - 1) & PAGE_2M_MASK);
}

void *system::memory::page4kAlign(void *addr)
{
    // find out an addr with is equal or higher than addr, and it's lower bits are all 0s.
    // we cannot use (addr & PAGE_4K_MASK) because the result may be lower than addr which is illegal.
    // this method may waste some space but it's necessary.
    return (void *)(((unsigned long)addr + PAGE_4K_SIZE - 1) & PAGE_4K_MASK);
}

void *system::memory::pageAlign(void *addr)
{
    return page2mAlign(addr);
}