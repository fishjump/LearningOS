#include "Screen.hpp"

#include "method/DrawChar.cpp"
#include "method/DrawPixel.cpp"
#include "method/Screen.cpp"

void system::io::Screen::initGobalInstance()
{
    Screen &gobalInstance = getGobalInstance();
    gobalInstance = Screen();
}

system::io::Screen &system::io::Screen::getGobalInstance()
{
    static Screen gobalInstance;

    return gobalInstance;
}