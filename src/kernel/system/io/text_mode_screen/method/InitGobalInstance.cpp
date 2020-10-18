#include "../TextModeScreen.hpp"

void system::io::TextModeScreen::initGobalInstance()
{
    TextModeScreen &gobalInstance = getGobalInstance();
    gobalInstance = TextModeScreen();
}