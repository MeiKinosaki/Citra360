#include "citra360/arm11_core.hpp"

namespace citra360 {

std::uint32_t Arm11Core::ror(std::uint32_t value, unsigned amount) noexcept {
    amount &= 31U;
    if (amount == 0U) return value;
    return (value >> amount) | (value << (32U - amount));
}

void Arm11Core::set_nz(std::uint32_t value) noexcept {
    n = (value & 0x80000000U) != 0U;
    z = value == 0U;
}

bool Arm11Core::step(std::uint32_t instruction) noexcept {
    // ARM condition field: this prototype supports AL only.
    if ((instruction >> 28U) != 0xEU) return false;
    // Bits 27..26 = 00 and I = 1: data-processing immediate.
    if (((instruction >> 26U) & 0x3U) != 0U ||
        ((instruction >> 25U) & 0x1U) == 0U) return false;

    const unsigned opcode = (instruction >> 21U) & 0xFU;
    const bool set_flags = ((instruction >> 20U) & 1U) != 0U;
    const unsigned rn = (instruction >> 16U) & 0xFU;
    const unsigned rd = (instruction >> 12U) & 0xFU;
    const unsigned rotate = ((instruction >> 8U) & 0xFU) * 2U;
    const std::uint32_t imm = ror(instruction & 0xFFU, rotate);
    const std::uint32_t lhs = r[rn];
    std::uint32_t result = 0;
    bool writes_result = true;
    bool arithmetic = false;
    bool subtract = false;

    switch (opcode) {
        case 0x0: result = lhs & imm; break;                 // AND
        case 0x1: result = lhs ^ imm; break;                 // EOR
        case 0x2: result = lhs - imm; arithmetic = true; subtract = true; break; // SUB
        case 0x4: result = lhs + imm; arithmetic = true; break; // ADD
        case 0x8: result = lhs & imm; writes_result = false; break; // TST
        case 0xA: result = lhs - imm; writes_result = false; arithmetic = true; subtract = true; break; // CMP
        case 0xC: result = lhs | imm; break;                 // ORR
        case 0xD: result = imm; break;                       // MOV
        default: return false;
    }

    if (writes_result) r[rd] = result;
    if (set_flags || !writes_result) {
        set_nz(result);
        if (arithmetic) {
            if (subtract) {
                c = lhs >= imm;
                v = (((lhs ^ imm) & (lhs ^ result)) & 0x80000000U) != 0U;
            } else {
                const std::uint64_t wide = static_cast<std::uint64_t>(lhs) + imm;
                c = (wide >> 32U) != 0U;
                v = ((~(lhs ^ imm) & (lhs ^ result)) & 0x80000000U) != 0U;
            }
        } else if (rotate != 0U) {
            c = (imm & 0x80000000U) != 0U;
        }
    }

    r[15] += 4U;
    return true;
}

}  // namespace citra360
