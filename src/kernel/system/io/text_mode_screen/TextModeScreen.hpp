#pragma once

#include <system/io/screen.hpp>

namespace system::io
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
        TextModeScreen *print(unsigned long long content);

    private:
        int cursor = 0;
    };

} // namespace system::io
