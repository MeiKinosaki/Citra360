#pragma once

#include <array>
#include <cstdint>

namespace citra360 {

// Deliberately small ARM-state instruction-execution prototype.
// It is NOT a complete ARM11/ARMv6K CPU and is not suitable for running Citra.
class Arm11Core {
public:
    std::array<std::uint32_t, 16> r{};
    bool n = false;
    bool z = false;
    bool c = false;
    bool v = false;

    // Executes a small ARM data-processing-immediate subset.
    // Returns false for unsupported encodings. PC advances only on success.
    bool step(std::uint32_t instruction) noexcept;

private:
    static std::uint32_t ror(std::uint32_t value, unsigned amount) noexcept;
    void set_nz(std::uint32_t value) noexcept;
};

}  // namespace citra360
