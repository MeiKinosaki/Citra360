#include "citra360/memory_bus.hpp"

namespace citra360 {

MemoryBus::MemoryBus(std::size_t size) : ram_(size, 0U) {}

std::size_t MemoryBus::size() const noexcept { return ram_.size(); }

bool MemoryBus::valid(std::uint32_t address, std::size_t width) const noexcept {
    const auto start = static_cast<std::size_t>(address);
    return start <= ram_.size() && width <= ram_.size() - start;
}

bool MemoryBus::read8(std::uint32_t address, std::uint8_t& value) const noexcept {
    if (!valid(address, 1U)) return false;
    value = ram_[address];
    return true;
}

bool MemoryBus::read16(std::uint32_t address, std::uint16_t& value) const noexcept {
    if (!valid(address, 2U)) return false;
    value = static_cast<std::uint16_t>(ram_[address]) |
            static_cast<std::uint16_t>(static_cast<std::uint16_t>(ram_[address + 1U]) << 8U);
    return true;
}

bool MemoryBus::read32(std::uint32_t address, std::uint32_t& value) const noexcept {
    if (!valid(address, 4U)) return false;
    value = static_cast<std::uint32_t>(ram_[address]) |
            (static_cast<std::uint32_t>(ram_[address + 1U]) << 8U) |
            (static_cast<std::uint32_t>(ram_[address + 2U]) << 16U) |
            (static_cast<std::uint32_t>(ram_[address + 3U]) << 24U);
    return true;
}

bool MemoryBus::write8(std::uint32_t address, std::uint8_t value) noexcept {
    if (!valid(address, 1U)) return false;
    ram_[address] = value;
    return true;
}

bool MemoryBus::write16(std::uint32_t address, std::uint16_t value) noexcept {
    if (!valid(address, 2U)) return false;
    ram_[address] = static_cast<std::uint8_t>(value);
    ram_[address + 1U] = static_cast<std::uint8_t>(value >> 8U);
    return true;
}

bool MemoryBus::write32(std::uint32_t address, std::uint32_t value) noexcept {
    if (!valid(address, 4U)) return false;
    ram_[address] = static_cast<std::uint8_t>(value);
    ram_[address + 1U] = static_cast<std::uint8_t>(value >> 8U);
    ram_[address + 2U] = static_cast<std::uint8_t>(value >> 16U);
    ram_[address + 3U] = static_cast<std::uint8_t>(value >> 24U);
    return true;
}

}  // namespace citra360
