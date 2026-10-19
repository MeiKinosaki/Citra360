#include "citra360/arm11_core.hpp"

#include <cstring>
#include <iostream>
#include <string_view>

namespace {
constexpr std::string_view kProject = "Citra360";
constexpr std::string_view kVersion = "0.1b";

bool self_test() {
    citra360::Arm11Core cpu;
    return cpu.step(0xE3A00005U) && cpu.r[0] == 5U && cpu.r[15] == 4U;
}
}  // namespace

int main(int argc, char** argv) {
    if (argc > 1 && std::strcmp(argv[1], "--self-test") == 0) {
        if (!self_test()) {
            std::cerr << "Citra360 bootstrap self-test: FAIL\n";
            return 1;
        }
        std::cout << "Citra360 bootstrap self-test: PASS\n";
        return 0;
    }

    std::cout << kProject << " v" << kVersion << "\n";
    std::cout << "ARM-state prototype included: limited data-processing-immediate subset.\n";
    std::cout << "Not a complete ARM11/ARMv6K implementation; no game execution claimed.\n";
    std::cout << "Target: Xbox 360 RGH (PowerPC Xenon) — toolchain not verified.\n";
    return 0;
}
