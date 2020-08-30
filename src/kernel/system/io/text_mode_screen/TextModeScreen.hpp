#pragma once

#include <system/io/Screen.hpp>

namespace system
{
    namespace io
    {
        class TextModeScreen : public Screen
        {
        public:
            TextModeScreen();
            ~TextModeScreen() = default;

            const int row;
            const int column;

            TextModeScreen *print(const char *content);
            TextModeScreen *print(int content);

        private:
            int cursor = 0;
        };

    } // namespace io

} // namespace system
