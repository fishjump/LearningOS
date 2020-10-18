#include "../Screen.hpp"

system::io::Screen &system::io::Screen::getGobalInstance()
{
    static Screen gobalInstance;

    return gobalInstance;
}
