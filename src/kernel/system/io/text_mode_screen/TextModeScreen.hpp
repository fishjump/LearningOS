#pragma once

#include <system/io/screen.hpp>

namespace system::io
{
    class TextModeScreen : public Screen
    {
    public:
        TextModeScreen();
        ~TextModeScreen();

        int row;
        int column;

        TextModeScreen *print(const char *content);
        TextModeScreen *print(long long content);
        TextModeScreen *print(unsigned long long content);

        static void initGobalInstance();
        static TextModeScreen &getGobalInstance();

    private:
        int cursor = 0;
    };

} // namespace system::io
