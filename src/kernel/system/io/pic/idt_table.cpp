#include <system/io/pic.hpp>

system::io::pic::IdtDescriptor system::io::pic::idtTable[system::io::pic::MAX_INT_NUMBER] = {0};
const system::io::pic::IdtTableDescriptor system::io::pic::idtTableDescriptor = {sizeof(system::io::pic::idtTable) * 8 - 1, (uint64_t)system::io::pic::idtTable};