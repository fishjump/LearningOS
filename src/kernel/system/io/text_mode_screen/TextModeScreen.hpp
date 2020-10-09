#pragma once

#include <system/io/screen.hpp>

namespace system
{
    namespace io
    {
        class TextModeScreen : public Screen
        {
        public:
            TextModeScreen();
            ~TextModeScreen();

            const int row;
            const int column;

            TextModeScreen *print(const char *content);
            TextModeScreen *print(long long content);

        private:
            int cursor = 0;
        };

    } // namespace io

} // namespace system
