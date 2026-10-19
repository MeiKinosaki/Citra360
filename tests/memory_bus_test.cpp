#include "citra360/memory_bus.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>

int main() {
    citra360::MemoryBus memory(16U);
    std::uint8_t byte = 0;
    std::uint16_t half = 0;
    std::uint32_t word = 0;

    assert(memory.write8(0U, 0xA5U));
    assert(memory.read8(0U, byte) && byte == 0xA5U);
    assert(memory.write16(2U, 0x1234U));
    assert(memory.read16(2U, half) && half == 0x1234U);
    assert(memory.write32(4U, 0x89ABCDEFU));
    assert(memory.read32(4U, word) && word == 0x89ABCDEFU);

    assert(!memory.read16(15U, half));
    assert(!memory.write32(13U, 0U));
    assert(!memory.read8(16U, byte));
    assert(memory.size() == 16U);

    std::cout << "MemoryBus prototype tests: PASS\n";
    return 0;
}
