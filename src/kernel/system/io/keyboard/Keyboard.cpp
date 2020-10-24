#include "Keyboard.hpp"

system::io::Keyboard::Keyboard() : bufferBegin(0), bufferEnd(1), bufferCount(0) {}
system::io::Keyboard::~Keyboard() = default;

void system::io::Keyboard::enqueue(uint8_t keyCode)
{
    if (bufferCount < MAX_BUFFER_SIZE)
    {
        buffer[bufferEnd] = keyCode;
        bufferEnd = (bufferEnd + 1) % MAX_BUFFER_SIZE;
        bufferCount++;
    }
}

uint8_t system::io::Keyboard::dequeue()
{
    if (!empty())
    {
        bufferCount--;
        uint8_t frontKeyCode = front();
        bufferBegin = (bufferBegin + 1) % MAX_BUFFER_SIZE;
        return frontKeyCode;
    }

    return 0;
}

uint8_t system::io::Keyboard::front() const
{
    return buffer[bufferBegin];
}

uint8_t system::io::Keyboard::end() const
{
    return buffer[(bufferEnd - 1) % MAX_BUFFER_SIZE];
}

bool system::io::Keyboard::empty() const
{
    return 0 == bufferCount;
}

size_t system::io::Keyboard::count() const
{
    return bufferCount;
}

void system::io::Keyboard::initGobalInstance()
{
    Keyboard &gobalInstance = getGobalInstance();
    gobalInstance = Keyboard();
}

system::io::Keyboard &system::io::Keyboard::getGobalInstance()
{
    static Keyboard gobalInstance;
    return gobalInstance;
}
