#include <system/media/color.hpp>

system::media::Color::Color(const int &color) : color(color) {}

system::media::Color::Color(const char &b, const char &g, const char &r)
{
    *((char *)&color + 0) = b;
    *((char *)&color + 1) = g;
    *((char *)&color + 2) = r;
}

system::media::Color::~Color() = default;

int system::media::Color::getColor() const { return color; }