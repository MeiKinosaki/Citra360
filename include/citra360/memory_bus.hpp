#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

namespace citra360 {

// Generic bounded little-endian RAM buffer for host-side prototypes.
// This is not the Nintendo 3DS memory map or MMU.
class MemoryBus {
public:
    explicit MemoryBus(std::size_t size);

    std::size_t size() const noexcept;
    bool read8(std::uint32_t address, std::uint8_t& value) const noexcept;
    bool read16(std::uint32_t address, std::uint16_t& value) const noexcept;
    bool read32(std::uint32_t address, std::uint32_t& value) const noexcept;
    bool write8(std::uint32_t address, std::uint8_t value) noexcept;
    bool write16(std::uint32_t address, std::uint16_t value) noexcept;
    bool write32(std::uint32_t address, std::uint32_t value) noexcept;

private:
    bool valid(std::uint32_t address, std::size_t width) const noexcept;
    std::vector<std::uint8_t> ram_;
};

}  // namespace citra360
