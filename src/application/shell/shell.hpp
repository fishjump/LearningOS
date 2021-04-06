#pragma once

#include <std/stdcxx.hpp>

namespace application {
class Shell {
public:
    static const size_t MAX_BUFFER_SIZE = 1024;
    uint8_t             buffer[MAX_BUFFER_SIZE];

    void getInput();
};

} // namespace application
