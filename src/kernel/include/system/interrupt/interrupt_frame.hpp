#pragma once

#include <std/type.hpp>

class interrupt_frame
{
    uint32_t eip;
    uint32_t cs;
    uint32_t eflags;
};