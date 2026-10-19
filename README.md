# Citra360

**Status: v0.1b — bootstrap / feasibility stage**

Citra360 is an experimental research project exploring whether parts of the Nintendo 3DS emulator Citra can be adapted for the Xbox 360 (RGH/JTAG). This repository is currently a project scaffold, not a working 3DS emulator.

## Current scope

- Establish a small, testable C++ bootstrap.
- Keep platform-independent code separate from Xbox 360-specific code.
- Audit CPU, memory, graphics, audio, and system-service dependencies before attempting a port.
- Investigate a Xenon/PowerPC toolchain and XEX packaging only after the target environment is verified.

## Honest status

| Area | Status |
|---|---|
| Project documentation and scaffold | In progress |
| Citra source/dependency audit | Not started |
| Xenon cross-compiler verified | Not verified |
| ARM11 emulation integrated | Not implemented |
| 3DS memory and services | Not implemented |
| Xenos graphics backend | Not implemented |
| Audio and controller integration | Not implemented |
| Xbox 360 ELF/XEX artifact | Not built or tested |
| Commercial-game compatibility | Not tested |

Percentages should only be raised when backed by code, reproducible builds, or tests. A host-side smoke test does **not** prove Xbox 360 compatibility.

## Build the bootstrap on a host

A normal CMake compiler can build the initial bootstrap for development and CI. This is only a host-side check:

```sh
cmake -S . -B build
cmake --build build
./build/citra360_bootstrap
```

## Planned milestones

1. **v0.1b:** establish the repository scaffold and a host-side smoke test.
2. Audit the chosen Citra source revision, license obligations, dependencies, and platform assumptions.
3. Validate the Xbox 360 toolchain and a minimal Xenon executable independently.
4. Design platform abstraction layers for logging, memory, input, timing, and graphics.
5. Port and test emulator subsystems incrementally; do not claim a subsystem complete until tested.

## Legal and attribution

Citra360 is an independent experimental porting effort. Review and preserve the licenses and notices of any upstream code and dependencies before copying or distributing them. Do not include copyrighted game files, console firmware, or encryption keys in this repository.
