#pragma once

#include <system/memory/Memory.hpp>

namespace system
{
    namespace boot
    {
        class GraphicInfo
        {
        public:
            const unsigned int HorizontalResolution;
            const unsigned int VerticalResolution;
            const unsigned int PixelsPerScanLine;

            const unsigned long FrameBufferBase;
            const unsigned long FrameBufferSize;
        };

        class MemoryDescriptor
        {
        public:
            unsigned long address;
            unsigned long length;
            unsigned int type;
        } __attribute__((packed));

        class MemoryInfo
        {
        public:
            const unsigned int count;
            const MemoryDescriptor descriptors[0];
        };

        class BootInfo
        {
        public:
            const GraphicInfo graphicInfo;
            const MemoryInfo memoryInfo;
        };

        const BootInfo *bootInfo = (BootInfo *)(PHYICAL_TO_VIRTUAL_ADDR(0x60000));
        
    } // namespace boot

} // namespace system
