#include <system/io/text_mode_screen.hpp>

void system::io::TextModeScreen::initGobalInstance()
{
    TextModeScreen &gobalInstance = getGobalInstance();
    gobalInstance = TextModeScreen();
}