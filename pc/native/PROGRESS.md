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
2. `bitfields.py` rewrites the preprocessed files: IDO allocates bitfields from the most
   significant bit, clang from the least, so each field is mirrored inside its unit, and
   neighbouring units are fenced with `char : 0;` (clang would merge two `u8` units into
   one `i16` access, which the byte swap below breaks).
3. `data.py` turns the asm data (`asm/data`, bss files) into one LLVM IR module, one
   block per file with N64 offsets; data/rodata/bss files of one module that touch on
   the N64 become one block (code reaches a neighbour's table through another label).
   Raw words equal to an overlay syscall stub address become function pointers.
4. `llvm-link` → `opt` with the pass plugin (`fixcalls/FixCalls.cpp`):
   `mem2reg, bt-fixcalls, bt-bigendian, bt-stackslots, internalize, bt-safepoints,
   default<O2>, bt-fixcalls`.
   - `bt-fixcalls` emulates the IDO calling convention: calls adapted to the callee's
     real signature, pass-through arguments (missing = caller's own a0..a3) and
     results (a void call site reads v0/f0 of the last call), missing `return`s
     (the last call result of the same register class), O32 register mapping when the
     first two arguments switch FPR/GPR. Resolves `undefined_syms.us.txt`.
   - `bt-bigendian`: guest memory holds the N64 byte order; every load/store wider
     than a byte is swapped. ROM data, assets and display lists need no conversion.
   - `bt-stackslots`: IDO matches reach neighbouring stack slots through a local's
     address (`(&sp28) - 1`); such locals grow to cover the slot, because LLVM drops
     accesses outside an object once inlining exposes them.
   - `bt-safepoints`: every loop latch calls `env.safepoint`, which the build turns into
     a check of the host's preemption flag (the N64 preempts anywhere; e.g.
     `func_800C2AB8` spins until the audio thread has stopped a sound). It runs before
     the optimizer, so wait loops keep their loads of data other threads write.
5. `wasm-ld` → `wasm2c` → native clang build with the host layer (`host/`: threads with
   N64 priorities, message queues, timers, VI, PI/ROM, SI, files, F3DEX2 HLE `gsp.c`,
   software RDP `rdp.c`, SDL3 window `video.c`, controller `input.c`, RSP interpreter
   `rsp.c` running the game's own audio microcode, SDL audio output `ai.c`). Indirect calls
   skip wasm's signature check (the N64 does not have one either).
6. Missing functions become generated traps (`build/ilp32/traps.txt`) that print their
   name and abort.

Run options (`host/video.c`, `host/input.c`): `BT_HEADLESS=1`, `BT_DUMP=prefix`
(BMP frames, `BT_DUMP_EVERY=N`, from `BT_DUMP_FROM=secs` on), `BT_EXIT_AFTER=secs` (game time), `BT_SPEED=x` (game
clock multiplier, e.g. 4 to fast-forward cutscenes), `BT_PRESS=secs:mask,...` (scripted
controller, up to 2048 entries; mask bits 0-15 buttons (A 8000, B 4000, Z 2000, Start
1000), 16-23 stick x, 24-31 stick y, e.g. `15:1000,15.3:0` = Start at 15 s,
`965:50000000` = stick up). Keyboard: Return Start,
Space A, Left Shift B, WASD stick. Saves: 16 Kbit EEPROM in `bt_eeprom.bin`.
Audio (`host/ai.c`): plays in windowed runs; `BT_MUTE=1` skips audio tasks,
`BT_PCM=path` also writes raw s16le stereo at the AI rate (22047 Hz).

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
| M3 | Platform layer, boot runs to the game loop | done 2026-11-06 |
| M4 | Renderer: F3DEX2 HLE + software RDP + SDL window | done 2026-11-06: intro, title, attract demos, file select, new-game cutscene render; no AA/dither |
| M5 | Input (SDL controller), saves (EEPROM), audio (n_audio command lists) | done 2026-11-06: SDL gamepad/keyboard, EEPROM file, audio (n_aspMain on an RSP interpreter, SDL stream) |
| M6 | Gameplay verification: title, file select, Spiral Mountain, level transitions | in progress: new game plays through the opening cutscene into Spiral Mountain; Banjo walks and climbs by stick (2026-11-06) |

## Working method

- Demand-driven: run, port what trapped or crashed, repeat. Traps are diagnostics,
  never fake behaviour.
- `pc/native/wasm/fix_decls.py` fixes declaration conflicts and K&R argument counts
  from the compile logs (repeat until it reports 0); every edit is `BT_NATIVE`-guarded.
- N64 match check after source changes in `src/` or `include/`.

## Open problems (next steps)

1. **Undefined behaviour the optimizer exploits.** IDO matching hacks that are fine
   on the N64 can break once LTO inlines across files (out-of-object stack slots were
   one: `bt-stackslots`). When only the optimized build misbehaves, compare with a
   `BT_NOINLINE=1` build and read the optimized IR (`llvm-extract` on `game.bc`).
2. **Audio details.** The microcode's MP3 overlay (command 7) is not supported (the
   interpreter stops with a message; Banjo-Tooie has not used it so far). Output
   latency is 35-110 ms (`LATENCY_BYTES` in `ai.c` plus the game's own rate control).
3. **Gameplay (M6).** Spiral Mountain is reached at ~900 s game time (`BT_SPEED=4`,
   A every 2 s). Next: jumps, moves, level transitions; fix what traps or crashes.
   Seen once (2026-11-07, optimized build): after a jump, frames alternated between a
   sky view and an above-ground view with a solid green (RGBA5551 0x0781) rectangle;
   only the two framebuffers and the Z buffer were drawn, and no display list ended
   early. Not reproduced in two reruns.
4. **Scripted runs are not deterministic.** Threads, timers and the VI follow the wall
   clock, so the same `BT_PRESS` script takes different paths. A virtual-clock mode
   (time advanced by safepoints and idle waits) would make runs repeatable.
5. **Cross-symbol data access.** Code that reaches data through another symbol's
   address only works when both lie in one asm block (`data.py` joins touching files of a
   module). Data split between C files and asm cannot be joined this way.
6. Codex's 64-bit `*_native.inc` replacements stay active under ILP32 unless they
   mismatch; then the module switches back to the original code with
   `#if defined(BT_NATIVE) && !defined(BT_ILP32)`. Their little-endian assumptions are
   a risk under the big-endian guest: plain members that share a word now follow
   `BT_NATIVE_LE_MEMORY` (unset under ILP32), bitfields `BT_NATIVE_LITTLE_ENDIAN`.
7. 12 function traps left (`build/ilp32/traps.txt`).
8. The 64-bit target (`pc/native/link_game.py`, `platform/ultra_*.c`) is superseded
   by the ILP32 build and can go once nothing depends on it.

## Log

### 2026-11-06 (late night)
- Spiral Mountain: the new game plays through the opening cutscene; Banjo walks and
  climbs by stick input (`BT_SPEED`, stick axes in `BT_PRESS`).
- Optimized build runs (it hung on a black screen): `suautobaddies_entrypoint_1`
  passes `(&sp28) - 1` as the actor iterator's index slot; after inlining, SROA
  dropped the stores outside `sp28`, so the loop revisited the last actor forever.
  `bt-stackslots` widens such locals (10 in the game). Safepoints now go in before the
  optimizer. Intro: 7.7 s CPU per 40 s of play, audio included.
- F11 toggles fullscreen.
- Audio: `host/rsp.c` interprets the RSP (scalar unit, vector unit, DMA) and runs the
  audio microcode embedded from `assets/core1/n_aspMain.*.bin`, so every n_audio
  command, including the IIR mode of the pole filter, behaves as on hardware.
  `host/ai.c` feeds the AI buffers to SDL; `osAiGetLength` reports the queue beyond a
  latency reserve, which the game's own sample-count control keeps steady. Checked
  with `BT_PCM` dumps: harmonic music in the spectrogram, no clipping, no clicks at
  the 184-sample chunk boundaries.

### 2026-11-06 (night)
- Big-endian guest memory (`bt-bigendian`), renderer (`gsp.c`, `rdp.c`, `video.c`),
  controller input, EEPROM file. Intro, title, attract demos, file select and the
  new-game opening cutscene run in the `BT_NOINLINE` build.
- Fixes on the way:
  - `bitfields.py` mirrored native-port records twice (intro scripts never started);
    now also fences bitfield units (a `u8` flag pair was read as one `i16`, which
    toggled bit 31 of an actor's route number).
  - `Actor` handle pairs at 0x80–0x8C used the little-endian order under ILP32
    (`animation_handle` overwrote the prop freelist index): `BT_NATIVE_LE_MEMORY`.
  - IDO ABI: pass-through and missing returns, O32 FPR/GPR register mapping.
  - Overlay stub addresses in data tables (`scinfobar`), loads past 4 GB
    (`-fwrapv-pointer`), `1E2B200.s` trig routines and `nearbyintf` in C,
    `func_8001B7F0`, `func_800AE5F0` (defrag moves the bone list).
  - Loop safepoints for preemption (sound stop wait in `func_800C2AB8`).
  - `gczoombox` reads its button-image table before a `.bss` label: touching asm
    data files of one module form one block.
  - `gsp.c` ignores `G_VTX` with a negative buffer index instead of writing outside.

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

### Phase 8: frame oracle (2026-11-09)

`python3 pc/native/wasm/frame_compare.py compare SOFT_DIR GPU_DIR` compares
BT_DUMP BMPs by retrace, including dimensions and missing frames. Default tolerance:
8/255 per RGB channel, at most 0.5% failing pixels **in each frame**; both limits
are explicit CLI arguments and appear in the result. No reference is updated.
`frame_compare.py replay NEW_OUTPUT --renderer gl|metal [--case intro]` uses the
existing corpus inputs, isolated saves and a frozen executable, dumping every
retrace. `--seconds N` is a partial diagnostic, never corpus acceptance.
ROM-free checks: `python3 pc/native/wasm/tests/frame_compare_test.py`.
The tool is ready; GPU corpus and individual framebuffer-effect acceptance remain open.

### Phase 8: OpenGL prototype stopped after two attempts (2026-11-09)

`BT_RENDERER=gl` uses hardware OpenGL triangles through macOS CGL, sharing the
existing F3DEX2/L3DEX2 guest-memory decoder (big-endian reads) and RDP command/TMEM
state. `BT_RENDERER=soft` remains the default/reference. Unsupported backends fail
explicitly; Metal is not implemented. This is an unaccepted prototype, native
resolution only (`BT_SCALE=1`), with synchronous readback on texture loads, image
switches and DP completion. Its coordinate noise differs from the software LCG.

The 8-second intro comparison, every retrace, retained the same limits: 8/255 RGB
channel tolerance, at most 0.5% bad pixels **per frame**:

- Attempt 1: 93/470 failed frames; worst 74.332006%; first failure retrace 13.
- Attempt 2: 12/470 failed frames; worst 0.601627%; first failure retrace 367.
- Evidence: `build/gpu-intro-attempt1/summary.json` and
  `build/gpu-intro-attempt2/summary.json` (frozen executables, saves and dumps retained).
  Attempt 2 used a host-only diagnostic relink; this never substitutes for the gate.

The large intro-mask error is reproducible in the ROM-free fixture: a clipped,
untextured, two-cycle black triangle was discarded by the original GPU shader.
Replacing mutable global combiner inputs with explicit function arguments fixes
that regression. `tests/gpu_render_test.py` passes on Apple M4 Pro: 65,536 identical
fixture bytes, CPU writes/copies, RTT, borrowed RGBA16 depth and the clipped mask
assertion. These synthetic checks do **not** accept real pause, transition,
`gczoombox`, camera/photo or depth-read effects. All five remain separate unchecked
items. Full intro/full corpus, high-resolution GPU rendering and Metal remain open.

Stopped renderer implementation per the two-attempt rule. No tolerance or stored
reference changed; GPU is not the default. The GPU integration is left uncommitted
as an incomplete step, preserving the pre-existing working-tree changes. The
completed image-oracle tooling is committed separately. `frame_compare.py replay
... --probe` diagnoses the first draw outside the same color tolerance and writes
`probe.json`; it is a diagnostic, not frame acceptance. `build/gpu-relink.py` and
`build/gpu-shader-probe.py` retain the repeatable host-only/shader-stage diagnostics.
No `src/` or `include/` change was made for this GPU work, so no new N64 `make check`
was required. Normal `port.py gate`: PASS, 5 test groups and 2,698 identical intro
retraces (software default); a final rerun follows the checkpoint documentation.
