# Citra360

**Status: v0.1b — bootstrap / feasibility stage**

Citra360 is an experimental research project exploring whether parts of the Nintendo 3DS emulator Citra can be adapted for the Xbox 360 (RGH/JTAG). This repository is an early scaffold, **not a working 3DS emulator**.

## Implemented scaffold

- `CMakeLists.txt`: C++17 host build and CTest registration.
- `src/main.cpp`: project/version banner and a minimal bootstrap self-test.
- `.github/workflows/host-smoke-test.yml`: GitHub Actions workflow to configure, build, and run the host-side smoke test.

These files have been committed, but the workflow result has not yet been verified. The self-test checks only the bootstrap; it does not test emulation or Xbox 360 compatibility.

## Honest status

| Area | Status |
|---|---|
| Initial C++ bootstrap | Implemented; build not yet verified here |
| Host CI workflow | Added; successful run not yet verified |
| Citra source/dependency audit | Not started |
| Xenon cross-compiler verified | Not verified |
| ARM11 emulation integrated | Not implemented |
| 3DS memory and services | Not implemented |
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

## Planned milestones

1. **v0.1b:** bootstrap and reproducible host smoke test.
2. Audit the selected Citra source revision, license obligations, dependencies, and platform assumptions.
3. Validate the Xbox 360 Xenon/PowerPC toolchain and a minimal target executable independently.
4. Design platform abstraction layers for logging, memory, input, timing, and graphics.
5. Port and test emulator subsystems incrementally.
6. Only after target compilation is proven, investigate ELF/XEX packaging and runtime testing.

## Legal and attribution

Citra360 is an independent experimental porting effort. Review and preserve the licenses and notices of any upstream code and dependencies before copying or distributing them. Do not include copyrighted game files, console firmware, or encryption keys in this repository.
