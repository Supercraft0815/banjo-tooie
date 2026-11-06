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
   Per-file LLVM passes are off (`-Xclang -disable-llvm-passes`), so FixCalls sees the
   calls as written before anything is inlined.
2. `data.py` turns the asm data (`asm/data`, bss files) into one LLVM IR module.
   Each element is stored with the width the C declarations give it (`irtypes.py`
   reads the external declarations from the bitcode), else the directive's width.
3. `llvm-link` → `opt` with the `FixCalls` pass plugin (`fixcalls/FixCalls.cpp`):
   adapts direct calls to the callee's real signature (IDO register semantics,
   missing arguments = caller's own a0..a3) and resolves `undefined_syms.us.txt`
   (fixed addresses, `A = B + off`; code-relative ones are re-anchored to the nearest
   data label of the same overlay). Functions whose short calls pass a0..a3 through
   get those parameters (`build/ilp32/widened.txt`). Runs before and after `default<O2>`.
4. `wasm-ld` → `wasm2c` → native clang build with the host layer (`host/`: threads,
   message queues, timers, VI, PI/ROM, SI, files). Indirect calls skip wasm's
   signature check (the N64 does not have one either).
5. Missing functions become generated traps (`build/ilp32/traps.txt`) that print their
   name and abort.

Debug helpers: guest data starts at `0x80001000` (`--global-base`), but addresses do
not equal N64 ones; `build/ilp32/game.map` (wasm-ld map) names every guest address.
The low 2 GB of the instance are protected, so NULL accesses fault at once.
`BT_NOINLINE=1 python3 pc/native/wasm/build.py` keeps every function separate, for
exact backtraces under lldb.

Source fixers (repeat each with `build.py` until it reports 0; edits are `BT_NATIVE`-guarded):
`fix_decls.py` (declaration conflicts, K&R argument counts) and `fix_passthrough.py`
(adds pass-through parameters to definitions, because clang drops the extra arguments
of calls in the same file as the definition).

## Milestones

| # | Milestone | Status |
|---|-----------|--------|
| M0 | Native core library + 53 module tests (Codex, up to 2026-11-05) | done |
| M1 | Every game C file compiles natively | 1,110 / 1,110 (ILP32, 2026-11-06) |
| M2 | Game executable links: all code + data, missing pieces trap with their name | done; 26 function + 4 data traps left |
| M3 | Platform layer, boot runs to the game loop | done 2026-11-06: frame loop runs (~30 gfx tasks/s, no crash) |
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

1. **Renderer (M4).** `host/rcp.c` completes tasks without running them. Next: an
   F3DEX2 display-list interpreter (HLE) plus an SDL window.
2. **Big-endian assets.** Guest memory is little-endian; ROM assets are big-endian.
   Converted on load in `native_asset_load` (`assets.c`, `model.c`): models (header,
   vertices, collision, skeleton, binding, VPL 0x34, mesh list 0x24, lights 0x30),
   animations, music sequence headers (type 9). Model fields 0x14, 0x2C, 0x38–0x40 and
   other asset types are still raw; convert each when its consumer shows up.
3. **Asm data widths.** Data without a matching C declaration keeps its directive
   widths, so a `.byte` table of records with `f32`/`s32` fields (or `.short` pairs read
   as bytes) reads wrong in little-endian memory. Type such tables in
   `guest/data_types.c` (done: `chintrochar` rows, `gctransitionDll` tables).
   Bitfields keep their N64 bit order only where all accesses share one declaration.
4. 26 function traps (`build/ilp32/traps.txt`): handwritten asm (`1E2B200.s`,
   `1EB2BF0.s` matrix code, `1EF0820.s`), `nearbyintf`, libultra SI/motor.
5. Codex's 64-bit `*_native.inc` replacements stay active under ILP32 unless they
   mismatch; then the module switches back to the original code with
   `#if defined(BT_NATIVE) && !defined(BT_ILP32)` (done for `1EB5E70` geometry,
   reset and state). Switching all of them at once cascades; do it per module.
6. Audio (no audio tasks yet), input, saves.
7. The 64-bit target (`pc/native/link_game.py`, `platform/ultra_*.c`) is superseded
   by the ILP32 build and can go once nothing depends on it.

## Log

### 2026-11-06 (evening)
- Boot reaches the game loop: map 395 load, camera and player init, actor spawn
  (`chintrochar`), frame loop with the original model interpreter (`1EB5E70`) and the
  scheduler. Fixes on the way:
  - Converters for world module VPL data, model mesh lists and lights, music sequence
    headers.
  - Per-file inlining before FixCalls lost pass-through arguments (NULL in
    `func_8011539C`): per-file passes off, whole-module `default<O2>` after FixCalls.
  - Pass-through parameters in FixCalls plus `fix_passthrough.py` (48 definitions).
  - `fminf`/`fmaxf` called themselves (LLVM lowers the builtins to libcalls on wasm).
  - Undefined-syms lines with leading spaces were skipped; code-relative symbols
    (`chintrochar` table) re-anchored; table types in `guest/data_types.c`.
  - Heap statistics (`heap_bytes_free`, `func_8001BD50`, ...) on the arena;
    `func_80100368` and the `1ECB9F0.s` float helpers ported in `handwritten.c`.
  - Original `1EB5E70` geometry/reset/state code under ILP32 (Codex's walker trapped).
  - `gctransitionDll` record tables typed (asset id was read from BE bytes).
  - `host/rcp.c` raised the RDP-done event as 5 (`OS_EVENT_SI`) instead of 9, so the
    scheduler never sent "frame done" and the game thread waited forever.
- Link map `build/ilp32/game.map`; `BT_NOINLINE=1` for debugging.

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
