#pragma once

#include <std/type.hpp>

namespace system::io
{
    class Keyboard
    {
    public:
        ~Keyboard();

        static const size_t MAX_BUFFER_SIZE = 4096;
        
        static void initGobalInstance();
        static Keyboard &getGobalInstance();

        void enqueue(uint8_t keyCode);
        uint8_t dequeue();

        uint8_t front() const;
        uint8_t end() const;

        bool empty() const;
        size_t count() const;

    private:
        Keyboard();
        uint8_t buffer[MAX_BUFFER_SIZE];
        uint32_t bufferBegin;
        uint32_t bufferEnd;
        size_t bufferCount;
    };
} // namespace system::io
