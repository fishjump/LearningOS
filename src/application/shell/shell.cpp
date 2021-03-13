#include "shell.hpp"

#include <std/stdcxx.hpp>
#include <system/io.hpp>

void application::Shell::getInput()
{
    auto &keyboard = system::io::Keyboard::getGobalInstance();
    auto &textModeScreen = system::io::TextModeScreen::getGobalInstance();
    while (!keyboard.empty())
    {
        uint8_t code = keyboard.dequeue();
        if (code <= 0x3b)
        {
            char str[2];
            str[0] = system::io::keyboardScanCodeTable[code];
            str[1] = '\0';
            textModeScreen.print(str);
        }
        // textModeScreen.print(" ");
    }
}