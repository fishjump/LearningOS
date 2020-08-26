#pragma once

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
            const unsigned long address;
            const unsigned long length;
            const unsigned int type;
        } __attribute__((packed));

        class MemoryInfo
        {
        public:
            const unsigned int count;
            const MemoryDescriptor *descriptors;
        };

        class BootInfo
        {
        public:
            const GraphicInfo graphicInfo;
            const MemoryInfo memoryInfo;
        };

        const BootInfo *bootInfo = (BootInfo *)0xffff800000060000;

    } // namespace boot

} // namespace system
