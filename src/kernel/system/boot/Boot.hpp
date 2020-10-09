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

            const int *FrameBufferBase;
            const unsigned long FrameBufferSize;
        };

        class MemoryDescriptor
        {
        public:
            void *address;
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

        extern const BootInfo *bootInfo;

    } // namespace boot

} // namespace system
