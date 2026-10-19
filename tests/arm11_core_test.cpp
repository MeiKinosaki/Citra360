#include "citra360/arm11_core.hpp"

#include <cassert>
#include <cstdint>
#include <iostream>

int main() {
    citra360::Arm11Core cpu;

    // MOV r0, #5; ADD r1, r0, #3; SUB r2, r1, #2; CMP r2, #6
    assert(cpu.step(0xE3A00005U));
    assert(cpu.r[0] == 5U && cpu.r[15] == 4U);

    assert(cpu.step(0xE2801003U));
    assert(cpu.r[1] == 8U && cpu.r[15] == 8U);

    assert(cpu.step(0xE2412002U));
    assert(cpu.r[2] == 6U && cpu.r[15] == 12U);

    assert(cpu.step(0xE3520006U));
    assert(cpu.z && cpu.c && !cpu.n && !cpu.v && cpu.r[15] == 16U);

    // Conditional instructions and unsupported opcodes must be rejected without advancing PC.
    const auto pc = cpu.r[15];
    assert(!cpu.step(0x03A00001U)); // EQ MOV: condition != AL
    assert(!cpu.step(0xE1A00000U)); // register MOV, not in this immediate subset
    assert(cpu.r[15] == pc);

    std::cout << "ARM11 prototype tests: PASS (limited ARM-state subset only)\n";
    return 0;
}
