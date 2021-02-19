#include <system/boot.hpp>
#include <system/memory.hpp>

namespace system::boot
{
    const BootInfo *bootInfo = (BootInfo *)(PHYICAL_TO_VIRTUAL_ADDR(0x60000));
} // namespace system::boot
