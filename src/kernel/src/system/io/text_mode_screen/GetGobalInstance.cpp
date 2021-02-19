#include <system/io/text_mode_screen.hpp>

system::io::TextModeScreen &system::io::TextModeScreen::getGobalInstance()
{
    static TextModeScreen gobalInstance;

    return gobalInstance;
}
