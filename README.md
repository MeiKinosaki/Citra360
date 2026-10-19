# Citra360

**Status: v0.1b — bootstrap / feasibility stage**

Citra360 is an experimental research project exploring whether parts of the Nintendo 3DS emulator Citra can be adapted for the Xbox 360 (RGH/JTAG). This is an early porting scaffold, **not a working 3DS emulator**.

## Implemented prototype code

- `CMakeLists.txt`: C++17 build and CTest test registration.
- `src/main.cpp`: startup banner and bootstrap self-test.
- `include/citra360/arm11_core.hpp`, `src/arm11_core.cpp`: a small ARM-state data-processing-immediate prototype covering AND, EOR, SUB, ADD, TST, CMP, ORR, and MOV with limited flag handling.
- `include/citra360/memory_bus.hpp`, `src/memory_bus.cpp`: bounded little-endian RAM buffer with 8-, 16-, and 32-bit reads/writes.
- `tests/arm11_core_test.cpp`: prototype instruction tests.
- `tests/memory_bus_test.cpp`: memory width and bounds tests.
- `.github/workflows/host-smoke-test.yml`: host build and automated test workflow.

The ARM core is a deliberately limited prototype, **not** a complete ARM11/ARMv6K CPU. The generic RAM buffer is **not** the 3DS memory map, MMU, or system services. Host tests do not establish Xbox 360 compatibility. Local isolated prototype checks passed during development; the complete GitHub Actions workflow result is not yet verified.

## Honest status

| Area | Status |
|---|---|
| C++ scaffold | Implemented |
| Limited ARM-state instruction subset | Prototype code added; isolated host checks passed |
| Generic bounded RAM access | Prototype code added; isolated host checks passed |
| Full CMake/CTest build | Pending CI confirmation |
| Citra source/dependency audit | Not started |
| Xenon cross-compiler verified | Not verified |
| Full ARM11/ARMv6K emulation | Not implemented |
| 3DS memory map, MMU, and services | Not implemented |
| Xenos graphics backend | Not implemented |
| Audio and controller integration | Not implemented |
| Xbox 360 ELF/XEX artifact | Not built or tested |
| Commercial-game compatibility | Not tested |

Percentages should only be raised when backed by code, reproducible builds, or tests. A host-side smoke test does **not** prove Xbox 360 compatibility.

## Host build and test

Requires CMake and a C++17 compiler:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel 2
ctest --test-dir build --output-on-failure
./build/citra360_bootstrap
```

## Next milestones

1. Confirm the full host build and CI test results.
2. Audit the selected Citra source revision, license obligations, dependencies, and platform assumptions.
3. Expand ARM instruction coverage with reference-based tests, exceptions, and precise CPU state.
4. Replace the generic RAM prototype with a documented 3DS address map, MMU/TLB model, and MMIO regions.
5. Validate an Xbox 360 Xenon/PowerPC toolchain independently and compile a minimal target executable.
6. Investigate platform abstraction, GPU command translation, audio, input, ELF/XEX packaging, and on-console tests only as each dependency becomes testable.

## Legal and attribution

Citra360 is an independent experimental porting effort. Review and preserve the licenses and notices of upstream code and dependencies before copying or distributing them. Do not include copyrighted game files, console firmware, or encryption keys in this repository.
