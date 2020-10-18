#include "../Screen.hpp"

void system::io::Screen::initGobalInstance()
{
    Screen &gobalInstance = getGobalInstance();
    gobalInstance = Screen();
}