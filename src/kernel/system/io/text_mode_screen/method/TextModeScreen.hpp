#pragma once

#include <system/media/Font.hpp>

#include "../TextModeScreen.hpp"

system::io::TextModeScreen::TextModeScreen() : row(height / system::media::Font::fontHeight),
                                               column(width / system::media::Font::fontWidth) {}