#pragma once

#include <type_traits>

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

            template <typename T, typename std::enable_if_t<std::is_same_v<std::decay_t<T>, const char *> || std::is_convertible_v<std::decay_t<T>, const char *>> * = nullptr>
            TextModeScreen *print(T content);

            template <typename T, typename std::enable_if_t<std::is_integral_v<std::decay_t<T>>> * = nullptr>
            TextModeScreen *print(T content);

        private:
            int cursor = 0;
        };

    } // namespace io

} // namespace system
