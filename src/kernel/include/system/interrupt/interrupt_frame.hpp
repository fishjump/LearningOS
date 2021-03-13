#pragma once

#include <std/stdcxx.hpp>

class interrupt_frame
{
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
};