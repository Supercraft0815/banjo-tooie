# Playable ILP32 port

The current game build compiles the decompiled C to wasm32, applies the LLVM
passes, translates it with wasm2c and links it with the SDL3 host. The supported
runtime is currently macOS; Linux/Windows runtime work is tracked as A2/A3 in
`../FAHRPLAN_SOH.md`. Platform link flags alone do not complete those ports.

Run commands from the repository root. The guest stage requires the existing N64
build/extracted assets and your local ROM, clang >= 19, the LLVM tools/libraries
for the pass plugin, WABT, and Python 3. The host stage requires clang >= 19,
WABT's C runtime, SDL3, zlib and platform graphics libraries.

```sh
python3 pc/native/wasm/build.py
python3 pc/native/wasm/build.py --run -- baserom.us.z64
```

Tools are selected from the following overrides, then `PATH`, then Homebrew
locations on macOS. An explicit override is never silently replaced by a tool
from somewhere else.

| Variable | Meaning |
|---|---|
| `BT_LLVM_BIN` | Directory containing `clang`, `clang++`, `opt`, `llvm-config`, `llvm-nm`, `llvm-dis`, `llvm-link`, `wasm-ld` |
| `BT_WABT` | Installation prefix containing `bin/wasm2c`, `include/wasm-rt.h`, `share/wabt/wasm2c/` |
| `BT_SDL3` | Installation prefix containing `include/SDL3/` and `lib/`; otherwise `pkg-config sdl3`, Homebrew or the system search paths |
| `BT_OUT` | Output directory, default `build/ilp32` |
| `BT_HOST_FLAGS` | Additional compiler/linker flags, e.g. `-fsanitize=address,undefined` |

Use a matching LLVM installation for `opt` and the plugin's headers/libraries.
Compiler/version/flag changes select new guest and host object caches; plugin
toolchain changes invalidate its stamp. Dependencies with spaces are supported.

## Separate guest and host builds

```sh
python3 pc/native/wasm/build.py guest
mkdir -p build/host-only
cp -R build/ilp32/gen build/host-only/gen
BT_OUT="$PWD/build/host-only" python3 pc/native/wasm/build.py host
```

Transfer the complete `gen/` directory, including headers and the two audio
microcode `.bin` files. The host stage does not invoke guest compilers, `opt`,
`wasm-ld` or `wasm2c`, and needs neither `game.map` nor `game.wasm`. Its trace build
ID includes the generated inputs, host sources and compiler/flags. Clang's
`--embed-dir` resolves the audio files within `gen/`.

Generated files contain ROM-derived data and microcode. Keep these private; A4
requires a separate review before public release artifacts are produced.

Windows pass plugins are toolchain-dependent: LLVM's build supports explicit
symbol exports for plugins when using MSVC, and plugins must link to the tool.
This does not establish whether any particular Windows binary distribution
enables that configuration. No Windows plugin execution was tested locally;
the separate host stage avoids requiring it for the Windows port. See the
[LLVM configuration source](https://github.com/llvm/llvm-project/blob/llvmorg-21.1.0/llvm/cmake/modules/HandleLLVMOptions.cmake#L1223).

## Checks

```sh
python3 pc/native/wasm/tests/build_test.py
python3 pc/native/wasm/port.py gate --full
python3 pc/native/wasm/port.py gate --case intro --exe build/host-only/bt_game
```

The gate uses isolated saves and frozen executable copies. Do not accept new
reference traces to hide a build regression. See `../PROGRESS.md` for evidence
and remaining gameplay issues.
