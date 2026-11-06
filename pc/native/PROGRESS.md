# Native PC port – progress log

Goal: Banjo-Tooie compiled from the decomp C sources (`BT_NATIVE`) as a native
PC executable that boots and is playable. No N64Recomp, no emulation of MIPS code
(decision 2026-11-05). The N64 build in `src/` must stay byte-identical
(`make check` in the Docker image `banjo-tooie-decomp:local`).

Technical details of finished modules: [README.md](README.md).

## Build and run (ILP32 model, since 2026-11-06)

```
python3 pc/native/wasm/build.py          # incremental; needs Apple clang, Homebrew llvm, lld, wabt
build/ilp32/bt_game baserom.us.z64
```

Pipeline (`pc/native/wasm/`):

1. Game C (`src/**`), Codex's native modules (`pc/native/*.c`) and a small guest
   libc/libultra (`guest/`) compile with `clang --target=wasm32 -flto`: 32-bit
   pointers, so every struct keeps its N64 layout. `BT_NATIVE` and `BT_ILP32` are set.
2. `data.py` turns the asm data (`asm/data`, bss files) into one LLVM IR module.
   Each element is stored with the width the C declarations give it (`irtypes.py`
   reads the external declarations from the bitcode), else the directive's width.
3. `llvm-link` → `opt` with the `FixCalls` pass plugin (`fixcalls/FixCalls.cpp`):
   adapts direct calls to the callee's real signature (IDO register semantics,
   missing arguments = caller's own a0..a3) and resolves `undefined_syms.us.txt`
   (fixed addresses, `A = B + off`). Runs before and after `lto<O2>`.
4. `wasm-ld` → `wasm2c` → native clang build with the host layer (`host/`: threads,
   message queues, timers, VI, PI/ROM, SI, files). Indirect calls skip wasm's
   signature check (the N64 does not have one either).
5. Missing functions become generated traps (`build/ilp32/traps.txt`) that print their
   name and abort.

Debug helpers: guest addresses equal N64 KSEG0 addresses (`--global-base=0x80001000`);
the low 2 GB of the instance are protected, so NULL accesses fault at once.

## Milestones

| # | Milestone | Status |
|---|-----------|--------|
| M0 | Native core library + 53 module tests (Codex, up to 2026-11-05) | done |
| M1 | Every game C file compiles natively | 1,110 / 1,110 (ILP32, 2026-11-06) |
| M2 | Game executable links: all code + data, missing pieces trap with their name | done; 73 traps left |
| M3 | Platform layer, boot runs to the game loop | in progress: boot reaches map 395 setup |
| M4 | Renderer: F3DEX2 display-list interpreter + SDL window → first visible frame | – |
| M5 | Input (SDL controller), saves (EEPROM), audio (n_audio command lists) | – |
| M6 | Gameplay verification: title, file select, Spiral Mountain, level transitions | – |

## Working method

- Demand-driven: run, port what trapped or crashed, repeat. Traps are diagnostics,
  never fake behaviour.
- `pc/native/wasm/fix_decls.py` fixes declaration conflicts and K&R argument counts
  from the compile logs (repeat until it reports 0); every edit is `BT_NATIVE`-guarded.
- N64 match check after source changes in `src/` or `include/`.

## Open problems (next steps)

1. **Big-endian assets.** ROM assets stay big-endian in memory. Codex's loaders
   convert models and animations; every other consumer reads raw BE data
   (current stop: `vpmodule_entrypoint_0` reads `count2C` of a world module and
   allocates gigabytes). Each asset type needs a converter in `native_asset_load`
   (or typed swapping), driven by the consumer's struct layout.
2. Asm data without a C declaration keeps directive widths (`.word`), and bitfields
   keep their N64 bit order. Type such data in C where it matters.
3. 73 traps: handwritten asm (`1E2B200.s` float helpers, `1EB2BF0.s` matrix code,
   `1ECB9F0.s`, `1EF0820.s`), `heap_*` statistics, `nearbyintf`, libultra SI/motor.
4. Renderer (`host/rcp.c` only acknowledges tasks), audio, input.
5. The 64-bit target (`pc/native/link_game.py`, `platform/ultra_*.c`) is superseded
   by the ILP32 build and can go once nothing depends on it.

## Log

### 2026-11-06
- 64-bit native is a dead end for this code (pointer-sized fields in every struct,
  N64 addresses in data). Switched to ILP32 via wasm32 + wasm2c (approved).
- All 1,110 game files compile. Fixes: header prototypes take the definition's
  types natively; IDO-only forms (`T a[3] = other_array;`, `1 << (n + 0x1F)` shifts
  folded mod 32, block-scope `enum x;`) rewritten under `BT_NATIVE`.
- Boot runs through osInitialize, CIC, VI, heap, scheduler, controller/EEPROM
  probe, save-data CRC check, game setup (`gcgame`), section table and map load
  start for map 395. Fixed on the way: handwritten RNG (`1EF0140.s`) in C, code
  bytes of `func_800D1A04` used as an XOR key (copied as data), absolute linker
  symbols, asm text labels mis-classified as data, static symbols.
- Asset archive is read straight from the ROM (`rom:5180-1a14580`).

### 2026-11-05
- Baseline: native core builds, 53/53 tests pass; N64 `make check` OK.
- First (64-bit) game executable with traps and a libultra platform layer; boot
  reached `func_8001D1E0`. Details of that layer: `pc/native/platform/`.
