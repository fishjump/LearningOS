#include "Boot.hpp"

#include <system/memory.hpp>

const system::boot::BootInfo *system::boot::bootInfo = (system::boot::BootInfo *)(PHYICAL_TO_VIRTUAL_ADDR(0x60000));