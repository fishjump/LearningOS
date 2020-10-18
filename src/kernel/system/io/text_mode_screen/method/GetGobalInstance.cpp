#include "../TextModeScreen.hpp"

system::io::TextModeScreen &system::io::TextModeScreen::getGobalInstance()
{
    static TextModeScreen gobalInstance;

    return gobalInstance;
}
