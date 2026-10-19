#include <cstring>
#include <iostream>
#include <string_view>

namespace {
constexpr std::string_view kProject = "Citra360";
constexpr std::string_view kVersion = "0.1b";

bool self_test() {
    // Bootstrap-only checks. These do not test 3DS emulation or Xbox 360 hardware.
    return !kProject.empty() && !kVersion.empty();
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
    std::cout << "Experimental port scaffold; no 3DS emulation is implemented yet.\n";
    std::cout << "Target: Xbox 360 RGH (PowerPC Xenon) — toolchain not verified.\n";
    return 0;
}
