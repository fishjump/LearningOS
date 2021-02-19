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
        static const int MAX_BUFFER_SIZE = 4096;
        char buffer[MAX_BUFFER_SIZE];

        TextModeScreen *print(const char *content);
        TextModeScreen *print(long long content);
        TextModeScreen *print(unsigned long long content);
        void fresh();

        static void initGobalInstance();
        static TextModeScreen &getGobalInstance();

    private:
        int bufferCount = 0;
    };

} // namespace system::io
