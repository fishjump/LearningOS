#include <system/io/screen.hpp>

void system::io::Screen::initGobalInstance()
{
    Screen &gobalInstance = getGobalInstance();
    gobalInstance = Screen();
}