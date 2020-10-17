#include "TextModeScreen.hpp"

#include "method/Print.cpp"
#include "method/TextModeScreen.cpp"

void system::io::TextModeScreen::initGobalInstance()
{
    Screen &gobalInstance = getGobalInstance();
    gobalInstance = Screen();
}

system::io::TextModeScreen &system::io::TextModeScreen::getGobalInstance()
{
    static TextModeScreen gobalInstance;

    return gobalInstance;
}