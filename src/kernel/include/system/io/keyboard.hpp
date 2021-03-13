#pragma once

#include <std/stdcxx.hpp>

namespace system::io
{
    enum KeyboardScanCode : uint8_t
    {
        EscapePressed = 0x01
    };

    const uint8_t keyboardScanCodeTable[] = {
        '\0', '\0', '1', '2',  // 0x0 <undefined>, 0x01 escape pressed, 0x02 1 pressed, 0x03 2 pressed
        '3', '4', '5', '6',    // 0x04 3 pressed, 0x05 4 pressed, 0x06 5 pressed, 0x07 6 pressed
        '7', '8', '9', '0',    // 0x08 7 pressed, 0x09 8 pressed, 0x0A 9 pressed, 0x0B 0 (zero) pressed
        '-', '=', '\b', '\t',  // 0x0C - pressed, 0x0D = pressed, 0x0E backspace pressed, 0x0F tab pressed
        'Q', 'W', 'E', 'R',    // 0x10 Q pressed, 0x11 W pressed, 0x12 E pressed, 0x13 R pressed
        'T', 'Y', 'U', 'I',    // 0x14 T pressed, 0x15 Y pressed, 0x16 U pressed, 0x17 I pressed
        'O', 'P', '[', ']',    // 0x18 O pressed, 0x19 P pressed 0x1A [ pressed, 0x1B ] pressed
        '\r', '\0', 'A', 'S',  // 0x1C enter pressed, 0x1D left control pressed, 0x1E A pressed, 0x1F S pressed
        'D', 'F', 'G', 'H',    // 0x20 D pressed, 0x21 F pressed, 0x22 G pressed, 0x23 H pressed
        'J', 'K', 'L', ';',    // 0x24 J pressed, 0x25 K pressed, 0x26 L pressed, 0x27  ; pressed
        '\'', '`', '\0', '\\', // 0x28 ' (single quote) pressed, 0x29 ` (back tick) pressed, 0x2A left shift pressed, 0x2B \ pressed
        'Z', 'X', 'C', 'V',    // 0x2C Z pressed, 0x2D X pressed, 0x2E C pressed, 0x2F V pressed
        'B', 'N', 'M', ',',    // 0x30 B pressed, 0x31 N pressed, 0x32 M pressed, 0x33 , pressed
        '.', '/', '\0', '*',   // 0x34 . pressed, 0x35 / pressed, 0x36 right shift pressed, 0x37 (keypad) * pressed
        '\0', ' ', '\0', '\0', // 0x38 left alt pressed, 0x39 space pressed, 0x3A CapsLock pressed, 0x3B F1 pressed
    };

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
