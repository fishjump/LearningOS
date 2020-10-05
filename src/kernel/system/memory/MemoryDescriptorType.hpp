#pragma once

namespace system
{
    namespace memory
    {
        enum MemoryDescriptorType
        {
            RAM = 1,
            ROM = 2,
            ACPI_RECLAIM = 3,
            ACPI_NVS = 4,
            UNUSABLE = 5
        };
    } // namespace memory

} // namespace system
