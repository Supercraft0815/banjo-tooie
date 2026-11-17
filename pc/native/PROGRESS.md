# Native PC port – progress log

Goal: Banjo-Tooie compiled from the decomp C sources (`BT_NATIVE`) as a native
PC executable that boots and is playable. No N64Recomp, no emulation of MIPS code
(decision 2026-11-05). The N64 build in `src/` must stay byte-identical
(`make check` in the Docker image `banjo-tooie-decomp:local`).

Technical details of finished modules: [README.md](README.md).

## Build and run (ILP32 model, since 2026-11-06)

```
python3 pc/native/wasm/build.py          # incremental; needs Apple clang, Homebrew llvm, lld, wabt
build/ilp32/bt_game baserom.us.z64      # no argument: ./baserom.us.z64, the copy in the user
                                        # data folder, or a file dialog on first start
```

Playing (2026-11-12): first start without argument asks for the ROM (US `.z64`/`.v64`/`.n64`,
checksum verified) and keeps a `.z64` copy, the save (`bt_eeprom.bin`, same bytes as an `.eep`
dump) and `settings.ini` in the user data folder (macOS `~/Library/Application Support/BanjoTooie/`).
F1 key help, F2 settings (internal resolution 1x-4x, 16:9, fullscreen, filter, rumble, volume,
60 FPS experimental, renderer GPU/software: GPU by default since 2026-11-15, applies after a restart;
`BT_RENDERER` wins, headless runs stay on software; FPS display top right = game pictures/s, `BT_SHOW_FPS=1`), F11 fullscreen, F12 screenshot. Keyboard: WASD stick (Ctrl slow), Space A,
Shift/X B, Q/Z Z, Return Start, Tab L, E R, arrows C, IJKL D-pad; `key.A=Space,X` lines in
`settings.ini` rebind buttons. Up to four gamepads (ports 1-4), Rumble Pak on the gamepad.

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
   name and abort. Missing data now fails the build instead of receiving zero placeholders.

Run options (`host/video.c`, `host/input.c`): `BT_HEADLESS=1`, `BT_DUMP=prefix`
(BMP frames, `BT_DUMP_EVERY=N`, from `BT_DUMP_FROM=secs` on), `BT_EXIT_AFTER=secs` (game time), `BT_SPEED=x` (game
clock multiplier, e.g. 4 to fast-forward cutscenes), `BT_PRESS=secs:mask,...` (scripted
controller, up to 2048 entries; mask bits 0-15 buttons (A 8000, B 4000, Z 2000, Start
1000), 16-23 stick x, 24-31 stick y, e.g. `15:1000,15.3:0` = Start at 15 s,
`965:50000000` = stick up). Keyboard: F1 shows all controls (see below).
Saves: 16 Kbit EEPROM in `bt_eeprom.bin`.

### Virtual clock: repeatable scripted runs (2026-11-08)

`BT_VCLOCK=1` replaces the wall clock (`host/os.c`). Time stands still while guest code
runs and jumps to the next VI retrace or timer once every thread waits; the thread that
went idle delivers those events itself, so no host thread touches the guest. `osGetTime`
advances it by 1 µs, and 100,000 loop latches without an OS call (a busy wait) jump it to
the next event. `BT_PRESS`, `BT_EXIT_AFTER`, `BT_DUMP_FROM` and the dump numbering
(`prefix_<retrace>.bmp`, guest framebuffer only) follow virtual time, and so does the AI
queue length. Windowed runs are paced to `BT_SPEED` × real time; headless runs go as fast
as the host can (about 6× real time in gameplay on this Mac). Start every run from the
same `bt_eeprom.bin` (it lives in the working directory).

```
P="0:0"; for t in $(seq 10 4 98); do P="$P,$t:1000,$t.2:0"; done
for t in $(seq 100 2 940); do P="$P,$t:8000,$t.2:0"; done
BT_VCLOCK=1 BT_HEADLESS=1 BT_EXIT_AFTER=950 BT_PRESS="$P" BT_DUMP=f BT_DUMP_EVERY=1800 \
  build/ilp32/bt_game baserom.us.z64
```

This script reaches Spiral Mountain at about 750 s of game time. Verified 2026-11-08:
two runs of a 1,010-second script (201 dumps each) and two runs of the script above
gave byte-identical dumps, with audio tasks enabled. Keyboard and gamepad input still
work under the virtual clock, but they are not repeatable.
Audio (`host/ai.c`): plays in windowed runs; `BT_MUTE=1` skips audio tasks,
`BT_PCM=path` also writes raw s16le stereo at the AI rate (22047 Hz).

### Retrace traces (2026-11-08)

`BT_TRACE=/absolute/path/run.jsonl` records one JSON line per virtual VI retrace,
before the VI message reaches the game. Use `BT_VCLOCK=1 BT_HEADLESS=1`; other
clock/window combinations fail explicitly. Live keyboard/gamepad input is ignored
in trace mode; only `BT_PRESS` controls the game. The output must not already exist,
so a baseline cannot be silently overwritten. Read/write errors fail the run.

Each record contains:

- Retrace number, virtual CPU ticks, width/height and a 64-bit FNV-1a hash of the
  visible **guest** RGBA5551 framebuffer (black VI is a distinct absent buffer).
- Current map ID from `D_80132DC2` (`func_800EA05C`), all eight player slots with
  position and previous/current/next behaviour states. Float values are stored as
  their exact IEEE-754 word bits, without decimal rounding.
- Actor vector order, marker IDs, position, scale, rotation, state word at `0x14`
  and health/flag words at `0x5C..0x7F`. Heap addresses and pointer fields are omitted.
- Six flag-bank hashes: `D_8011B990`, the three pointed-to arrays in `D_8012C770`
  (176/22/32 bytes), `D_8012C780` (12 bytes), `D_8012C78C` (6 bytes), followed by
  an aggregate state hash. These selected fields are an oracle, not a complete
  serialization of every actor component, timer or game variable.

`build.py` generates `build/ilp32/gen/trace_symbols.h` from the current linker map,
including LLVM-split flag-pointer arrays. No N64 address is assumed to equal a
guest address. Range checks reject invalid pointers; actor stride is checked at
runtime, and the test suite compiles layout assertions against the real ILP32
game types. Recording reads guest memory on its owning thread and never invokes
game functions or writes to the guest.

The header identifies the guest Wasm and host sources/build flags by SHA-256 and
hashes the input ROM, starting EEPROM, `BT_PRESS`, `BT_SCALE` and `BT_MUTE`.
The comparator rejects incompatible headers, missing/out-of-order retraces,
empty or malformed traces, and reports the first differing field, for example
`Retrace 123, players[0].position[0]`. Exit codes: 0 identical, 1 divergence or an
early end, 2 invalid/incompatible input. The aggregate state hash is checked after
the individual fields so it does not hide a more precise diagnosis.

```
# Run from two fresh, separate working directories; copy the SAME initial
# bt_eeprom.bin into each, or leave it absent in both for a new save.
BT_VCLOCK=1 BT_HEADLESS=1 BT_EXIT_AFTER=45 BT_TRACE="$PWD/run.jsonl" \
  /absolute/path/to/build/ilp32/bt_game /absolute/path/to/baserom.us.z64
python3 pc/native/wasm/trace_tools.py /path/to/A/run.jsonl /path/to/B/run.jsonl
python3 pc/native/wasm/tests/trace_test.py
```

**Build-local comparison is deliberate.** The virtual clock still counts loop
latches and therefore depends on optimization/inlining. Different `BT_NOINLINE`
builds are rejected rather than declared equivalent. This completes the
build-local alternative in Phase 0; it does not yet provide an oracle for
cross-build changes in Phases 1–5. Those need a build-independent clock or a
separately validated synchronization point. Keep other game-affecting settings,
including debug options such as `BT_NO_GFX`, identical as well. High-resolution
host render targets and audio PCM are outside this trace; use `BT_PCM` separately.

Validation and local replay artifacts are under `build/ilp32/trace-validation/`.
No ROM bytes or EEPROM dumps were added to the source tree for these tests.
Two 950-second runs of the script in the virtual-clock section, both starting
without an EEPROM file, produced **56,943 byte-identical retrace records** and
31 byte-identical BMPs (`spiral-final-a/`, `spiral-final-b/`). Current map `0xAF`
(Spiral Mountain) first appears at retrace 46,317 (about 772.7 seconds), and both
runs end there with one player and 72 actors. All 31 BMPs also match the
executable saved before adding tracing (`spiral-before/`). An earlier 45-second
smoke test matched 2,698 retraces and eight BMPs against that executable.
`summary.json` records the build identity, map counts and trace SHA-256;
`spiral.press` stores the exact input script. The last image was inspected and
shows Banjo in Spiral Mountain. This is repeatability and a sampled behaviour
comparison, not emulator or human acceptance of every frame in that scene.

The ROM-free suite covers state/field decoding, address relocation, read-only
capture, framebuffer/flag changes, map-symbol resolution, invalid inputs,
exclusive output creation and comparator diagnostics. The keyboard test also
checks that trace mode ignores live input while applying the scripted stick and
buttons. Existing renderer, sampling/cache and keyboard regressions pass at
scales 1/2/4. `make check` passed in `banjo-tooie-decomp:local`; SHA-1 of both
complete decompressed ROMs is `af479771ff5e91ce3732f3d84146614ab71d8d79`.

The static Ripwire gate also covers earlier uncommitted renderer/clock changes:
its quality result is not green (complexity/duplication in that working tree,
plus the new recursive JSON comparator's complexity and fixture-only helpers).
Its named renderer and trace tests are exercised; its remaining untested OS,
audio and I/O paths are not a full-game acceptance claim.

### Phase 0/1 implementation and remaining gates (2026-11-08)

This is continued work on both phases, **not completion of either phase**. The
complete reference playthrough, emulator screenshots and broad scene corpus are
still missing. No N64 emulator was found in `/Applications` or as `mupen64plus`
on PATH during this pass. A matching intro/Spiral Mountain replay is insufficient
to approve every world, boss, minigame, transformation and multiplayer mode.

New tools:

```
python3 pc/native/wasm/corpus.py build/ilp32/my-new-corpus
python3 pc/native/wasm/save_editor.py /tmp/open-worlds.eeprom --create \
  --set-flag FLAG_392_PROGRESS_OPENED_WORLD_MT
python3 pc/native/wasm/save_editor.py /tmp/edited.eeprom --input /path/to/original.eeprom \
  --slot 0 --set-flag FLAG_393_PROGRESS_OPENED_WORLD_GGM
python3 pc/native/wasm/data_inventory.py /tmp/data-inventory.json
```

The corpus runner freezes a copy of the executable and runs each selected case
twice in fresh working directories. It checks ordered traces, exact state/image
equality, final map and elapsed virtual time. Cases are `intro` (45 seconds),
`new-game` (950 seconds) and `edited-save` (180 seconds, nine world-open flags).
Use repeated `--case` arguments to select a subset. It writes actual named-map
coverage and leaves all human/emulator/boss/minigame/transformation/multiplayer
acceptance flags false. It does not turn a map load into a scene acceptance.

The save editor uses the game's KHJC tagged records, four physical 448-byte
records at EEPROM offset `0x100`, logical slots 0–2 and both original CRC words.
It edits only the permanent flag bank (`0x29..0x5A4`), validates bounds, version,
section lengths, unique logical-slot ownership and CRC, and updates the selected
record's checksum. Input files are untouched and outputs must be new files.
Minimal new records and opened-world flags are fixtures; they do not encode every
quest's prerequisite state or replace saves from actual completed scenarios.
The CRC tests call the original `gl/crc.c` and independently implement the MIPS
shift-register steps. The reference build accepted an edited slot and reached
Spiral Mountain within 180 seconds; the player ended in idle state 1.

Platform/trap work:

- `_Printf` now uses the existing libultra `xprintf.c`, `xlitob.c`, `xldtob.c` and
  `ldiv.c`. Its dedicated test compiles those real sources through the big-endian
  wasm/wasm2c path and checks integer, 64-bit, exponent/general-float formatting,
  padding and callback failure.
- `__osMotorAccess` returns libultra's uninitialized-Pak error. `osMotorInit`
  continues to report no pak; this does not implement physical gamepad rumble.
- `__osContLastCmd`, `__osFaultedThread`, `__osRunningThread` and `osClockRate`
  have typed definitions. `osInitialize` sets the counter rate to 46,875,000 Hz;
  the scheduler writes the current guest thread into `__osRunningThread` on
  dispatch and boot. Normal execution has no faulted thread. Host fatal faults
  still terminate the process; no native fault-recovery UI is claimed.
- This fixes a real timer problem: the old zero-filled `osClockRate` placeholder
  made the controller timer interval zero. Consequently the old corpus is not an
  equality baseline for this platform correction. Capture a new reference after
  that fix; do not hide differences by stripping header checks in normal use.
- Generated missing data no longer gets silent 4-KiB zero buffers. The builder
  now fails on symbols classified as unresolved guest data. There are **10
  function diagnostics and zero generated data placeholders**. This build-stage
  classification also puts linker-boundary/legacy names among the function
  diagnostics; it does not prove those addresses have correct implementations.
  Remaining names are in `build/ilp32/traps.txt`; link-time removal of an untested
  path is not an implemented function.

Phase-1 data work:

- Two real C migrations were implemented: seven typed save callback records
  with array bounds, and nine typed HUD draw/update/scale records replacing
  three overlapping symbols and hardcoded strides. A dedicated test confirmed
  every HUD function symbol and float bit pattern against the assembly table.
- **Both migrations were rejected and removed from the active sources.** The
  isolated HUD comparison matched every sampled image but first differed at
  retrace 46,310, `actors[0].health_flags[2]` (`0x01040000` vs `0x00040000`), as
  Spiral Mountain actors were being loaded. The save-table experiment also
  differed at retrace 46,318, `actors[0].health_flags[7]` (`16418` vs `16416`).
  These fields have not been proved to be irrelevant padding. No masking or
  tolerance was added to conceal them. Possible layout/uninitialized-state
  causes remain hypotheses, not a validated explanation.
- `typed-data-rejected.patch` preserves the complete experiment and its HUD
  test for review. `hud-migration-comparison.json` records the first mismatch;
  `corpus-typed-experiment/` contains the repeatability runs of that rejected
  build. Both modified game source files were restored byte-for-byte to HEAD.
  A cross-build diagnostic explicitly excluded only the header's build identity;
  the normal comparator's strict build checks remain unchanged.
- Original-IDO `make check` passed even with these changes: it is necessary but
  does not prove native runtime equality. Complete decompressed-ROM SHA-1 remains
  `af479771ff5e91ce3732f3d84146614ab71d8d79`.
- The inventory reports 1,715 input assembly files, 718 sections with labels,
  5,782 labels; remaining-definition/declaration counts are in the JSON report.
  Declarations are not proof of full types.
  There are 146 C-defined `R_*` symbols and no unresolved `R_*` reference: the
  checklist's former count of 151 open symbols was stale. One original assembly
  section contains raw syscall-pointer words (`sc/infobar.data.s`). The active
  native build still depends on `data.py`, including that original table.
- A read-only three-way preview of `3810562de` (the Rodata branch) is preserved
  in `build/ilp32/phase01-validation/rodata-preview/`: 41 paths merge cleanly,
  11 conflict and six are new split files. Those splits must move the current
  matched/native function bodies, retaining function inventory and compiler
  behaviour. The old branch bodies include obsolete assembly placeholders.
  No partial Rodata merge or unverified source overwrite was applied.

Validation artifacts are in `build/ilp32/phase01-validation/`. The final corpus
uses `corpus-accepted/`; earlier intermediate runs are not acceptance evidence
(one run correctly failed when a rebuild changed its executable between replays,
which is why the runner now freezes its executable).

The final active build passed all three replay pairs with one build identity
(`9b182a711e68e3b352f7aea08e963a6b41d25a83b60e6481563362d05f62a408`):
intro 2,698 retraces/one BMP, new game 56,943 retraces/31 BMPs, edited save
10,790 retraces/five BMPs. Every trace and BMP matches its paired replay. Both
gameplay scenarios end in Spiral Mountain. The inventory still lists **214
unvisited named maps** and all broad acceptance flags remain false. The frozen
executable is byte-identical to the current `build/ilp32/bt_game`.

The final data inventory has 5,728 remaining assembly labels and 4,569 known
declarations without C definitions. Static Ripwire quality is still not green:
the working tree includes previous renderer/clock changes and new validation
scripts, with complexity/duplication and fixture-helper findings. Its runtime
test suggestions do not establish complete OS/audio/gameplay coverage.

Test commands:

```
python3 pc/native/wasm/tests/trace_test.py
python3 pc/native/wasm/tests/save_test.py
python3 pc/native/wasm/tests/inventory_test.py
python3 pc/native/wasm/tests/printf_test.py
clang -O2 -Wall -Wextra -Werror -Wno-unused-function \
  pc/native/wasm/tests/os_globals.c -o /tmp/bt-os-globals-test -lpthread
/tmp/bt-os-globals-test
python3 pc/native/wasm/tests/render_test.py
```

Neither `data.py` removal nor full `.data/.rodata/.bss` C conversion, the Rodata
merge, universal cross-build trace equivalence or full Phase-0 acceptance is
claimed. Those unchecked checklist items remain required work.

### Higher internal resolution (2026-11-08)

`BT_SCALE=1` (default), `2` or `4` controls software raster resolution. For BT's
304×228 scanout, the larger images are 608×456 and 1216×912. For example:

```
BT_SCALE=2 build/ilp32/bt_game baserom.us.z64
BT_SCALE=2 BT_DUMP=build/ilp32/frame BT_DUMP_HIRES=1 build/ilp32/bt_game baserom.us.z64
BT_SCALE=2 BT_RENDER_STATS=1 build/ilp32/bt_game baserom.us.z64
python3 pc/native/wasm/tests/render_test.py
```

- Only addresses registered by `osViSwapBuffer` receive larger color buffers.
  First use of a newly seen address imports its native image; following tasks
  rasterize at the requested resolution. Render-to-texture targets stay native.
- Depth storage follows the Z-image address, since BT shares it between scanout
  buffers. The normal `0xFFFC` depth clear is enlarged. Color copies into borrowed
  Z memory retain their original RGBA16 bytes.
- Color is averaged back into RGBA5551; depth is averaged in decoded 18-bit depth
  units and compressed again. Resolves happen at task completion, target changes
  and framebuffer texture loads. CPU-written pixels are imported on the next task
  or swap without discarding detail in unchanged pixels.
- The SDL thread copies a completed scanout under a separate mutex; it does not
  wait for the full raster pass. Line quads are scaled once by the triangle rasterizer.
- Dumps remain at the native resolution unless `BT_DUMP_HIRES=1` is present.
  The window stays 4:3. No widescreen change is included.

Validation: the ROM-free fixture checks S=1 against the original renderer's exact
16-KiB output (SHA-256 pinned to `02629d9d1`), S=2/4 fill patterns, texture copies,
color/depth separation, borrowed-Z copies, CPU writes, fractional scissors, bounds,
and concurrent presentation. AddressSanitizer/UndefinedBehaviorSanitizer passed.
A temporary differential game build compared the original and changed renderers
on the same live display lists: at least 600 complete intro tasks had identical
color/depth rows with S=1. The optimized game builds and boots at all three scales.

Initial, pre-optimization 20-second headless intro samples on this Mac (normal game clock, audio
tasks enabled; these are observed framebuffer changes, not VSync counts):

| Scale | New game images/s | Mean raster task time across 5-second windows |
| --- | --- | --- |
| 1 | about 20 | 9.3–10.4 ms |
| 2 | about 20 | 17.4–22.1 ms |
| 4 | 9–13 | 68.5–100.8 ms |

These initial samples do not establish gameplay performance or 60 FPS; the later
optimization measurements below supersede their timings.

A five-minute S=2 scripted run at `BT_SPEED=4` reached a new game, the opening
cutscene, Spiral Mountain, the pause overlay and return from pause. Dumps were
visually inspected at those points. Inspection exposed an alpha-loss bug: merely
drawing a color/HUD row marked borrowed Z memory dirty, so a later resolve could
recompress RGBA data as depth. Only actual Z_UPD writes now mark depth dirty. The
new regression fails on the pre-fix renderer and passes after the fix, including
under sanitizers; the full new-game/pause sequence was not repeated after that fix.
Input scripts depend on wall-clock timing:
an earlier attempt pressed Start too early and only covered attract scenes and
file select. The SDL window/texture path also completed a dummy-video-driver run;
this is not a physical-window or controller acceptance test.
S=4 additionally passed title/file-select/new-game transition runs, but Spiral
Mountain and pause at S=4 are not verified: the attempted reload restarted the
opening story instead of skipping to gameplay.

### Faster rendering and keyboard controls (2026-11-08)

The renderer caches decoded texels, invalidating them on texture/palette loads,
tile changes and TLUT mode changes. Hidden fragments fail depth testing before
texture filtering; unused combiner textures are skipped. LOD remains available
even when a combiner uses no texture color. The cache lookup and pixel/blend
pipeline are inlined, with decoding kept out of the fast path. Unchanged native
framebuffer snapshots bypass the per-pixel import scan. Build flags remain `-O2`;
the game clock and simulation cadence are unchanged.

The deterministic 120-frame benchmark draws textured, occluded and blended
304x228 geometry, including high-resolution presentation and color/depth readback.
Sequential measurements on this Mac, before/after these optimizations:

| Scale | Before (ms/frame) | After (ms/frame) | Speedup |
| --- | ---: | ---: | ---: |
| 1 | 7.133 | 3.559 | 2.0x |
| 2 | 29.221 | 14.361 | 2.0x |
| 4 | 117.219 | 56.621 | 2.1x |

All scanout/readback hashes match the pre-optimization renderer at all three scales.
Separate 20-second headless intro runs at S=4 and normal clock improved from
10.2-14.2 to 16.6-20.0 observed framebuffer changes/s. Mean raster task times across
the three reporting windows fell from 62.54-88.82 ms to 37.56-49.42 ms (about 39%
less time on average). These are scene-specific measurements, not a 60-FPS claim.
The intro's own cadence is about 20 FPS.

Click the game window to give it keyboard focus; F1 toggles the controls overlay.

| Key | N64 input / action |
| --- | --- |
| WASD | Analog stick; Ctrl + WASD moves at half stick strength |
| Space | A |
| Either Shift / X | B |
| Q / Z | Z |
| Enter / keypad Enter / Escape | Start / pause |
| E / Tab | R / L |
| Arrow keys | C buttons / camera (free camera: turn and tilt) |
| C | C-Up (first person) |
| IJKL | D-pad |
| F1 / F11 | Controls overlay / fullscreen |

Button presses are retained until the guest reads them once, so short taps between
video polls are not lost. Focus loss clears held keys. Gamepad and scripted input
remain supported. The SDL event-queue test checks every binding, combinations,
held keys, short taps, slow walking and focus loss. The help overlay was rendered
with SDL's dummy driver and visually checked.

`python3 pc/native/wasm/tests/render_test.py` runs the renderer, texture/cache,
benchmark image-hash and keyboard tests. The LOD-only combiner regression failed
before its fix and passes afterward. Renderer, sampling and keyboard fixtures also
pass AddressSanitizer/UndefinedBehaviorSanitizer. A temporary live differential
build checked at least 500 complete intro tasks after the optimization: native
color/depth rows remained byte-identical to the original S=1 renderer.
Physical keyboard/gamepad play and a full gameplay performance sweep remain unchecked.
Ripwire's static gates are not green: they report complexity growth in input,
video and renderer dispatch, fixture/VI boilerplate clones and untested OS/audio
callers. The event handler was flattened; the remaining dispatch/inner-loop logic
is kept together deliberately. All four tests named by the test gate passed;
that does not establish coverage of the entire host runtime.

### 60-Hz interpolation investigation (not implemented)

The active clock is `wasm/host/vi.c` (59.94 Hz), not `platform/ultra_vi.c`.
`src/core1/1E2C940.c:func_800151BC` waits on `D_80079138` against
`func_80015184()` minus the previous swap wait. `func_80015178(2)` sets the usual
interval; overlays also request 3 and 4, and `func_800C73A4` can select 1–5.
Thus alternating one original and one intermediate frame is insufficient in all
scenes. Presentation must use the actual interval between game frames.

`func_800A7D30` passes the elapsed retrace count from `func_80014F4C` into
`func_800D8FA0`, which updates the game's delta time. This establishes one
time-dependent path, not that every animation/timer/audio path tolerates a shorter
wait. A temporary executable forced this variable to 1 before each graphics task
(using its address in this build's `game.map`, without changing the regular game
binary). Its initial value in the intro was 3. A 20-second S=1 intro run then
produced 59.9–60.0 tasks/s and about 60 framebuffer changes/s, with 5.5–6.7-ms mean
render time. Ten-second dumps showed approximately the same intro progress as
the normal interval; this is a limited observation, not a gameplay/timer/audio
speed audit. No forced-tick option was added to the regular host.

The camera owner `src/core2/1EBCFC0.c:func_800E44FC` combines view and projection
into the G_MTX_PROJECTION matrix. Interpolating that matrix element-wise would not
implement position/target/FOV interpolation. Capture the camera parameters before
this composition. The model owner `src/core2/1EB5E70.c:func_800DE498` builds object
transforms, but also calls `_dbanim_entrypoint_0/1` to skin vertex data on the CPU.
Correct object interpolation therefore needs stable instance/lifetime IDs and
retained vertex data as well as matrix samples. Scratch matrix addresses and draw
order alone do not identify objects across culling/spawn/despawn changes.

Further implementation belongs in native replacement sources plus host recording,
replay and presentation code: immutable display-list inputs, explicit camera and
instance IDs, quaternion rotation interpolation, history resets at discontinuities,
and intermediate frames that cannot modify guest color/depth readback. No such
interpolation is enabled or claimed by the resolution work above.

Debug helpers: guest data starts at `0x80001000` (`--global-base`), but addresses do
not equal N64 ones; `build/ilp32/game.map` (wasm-ld map) names every guest address.
The low 2 GB of the instance are protected, so NULL accesses fault at once.
`BT_NOINLINE=1 python3 pc/native/wasm/build.py` keeps every function separate, for
exact backtraces under lldb.

Source fixers (repeat each with `build.py` until it reports 0; edits are `BT_NATIVE`-guarded):
`fix_decls.py` (declaration conflicts, K&R argument counts) and `fix_passthrough.py`
(adds pass-through parameters to definitions, because clang drops the extra arguments
of calls in the same file as the definition).

### Script-first tooling (2026-11-09)

`pc/native/wasm/port.py` is the single entry point; every command prints a few lines so
agents never read logs. Work lists are generated, never hand-edited (details and the agent
runbook: `VARIANTE_A_CHECKLISTE.md`, section "Werkzeuge").

- `port.py status`: counts of all work lists and checklist progress (< 1 s).
- `port.py gate [--full] [--accept] [--exe PATH]`: build, unit tests, replay corpus cases and
  compare each trace with `build/reference/<case>.jsonl` (cross-build: only the build
  identity is ignored). This is the oracle for every later phase.
- `port.py worklist traps|xsym|calls|lp64 [--file F]`: open items by source file.
- `xsym_report.py`: diagnostic build (`BT_XSYM=1`, `BT_OUT=build/ilp32-xsym`) with the
  `bt-xsym` pass: every load/store whose address derives from a data label is range-checked
  against the label's extent (up to the next asm label, or the C variable's size); the host
  logs the first miss per site (`env.xsym`). Report: function, label used, symbol hit, and
  union-find groups of labels that must become one C object.
- `hazards64.py`: all game files with `-fsyntax-only` for arm64 LP64 and the pointer/int
  warnings, 3 s. `lp64_fnwords.py`: codemod for function-address tables (`BtFnWord`).
- `offsets.py scan|pad|apply|verify` + `n64_objdiff.py`: raw byte-offset accesses become
  struct fields where the base is a known struct and a field of exactly that type sits at the
  offset (`pad` first splits header byte padding into typed fields). `verify` builds HEAD and
  the working tree in a Docker clone, reverts functions whose object code changed and records
  them in `offsets_ido_keep.txt` until make check is OK. 2026-11-09: 545 rewrites in 135
  files, 17 functions kept raw; clean make check OK (SHA-1 af479771...), gate --full PASS.
  Pitfall fixed: rsync keeps old mtimes, so `sync` touches changed files before make.
- `offsets.py infer|genstruct` + `place_decls.py`: parameter types from direct callers, and
  one-line `Obj<file>_<argN>` structs built from all offsets on a parameter; `apply` writes
  `((Obj *)argN)->unkXX`. 2026-11-09: 2,102 rewrites in 313 files, 27 functions kept raw,
  make check OK. Lessons: (1) as1 schedules by `.loc` line, so no file may gain a line, and
  a declaration on a function's first line changes that function: append it to an earlier
  `;`/`}` line in the same `#if` branch; (2) `revert` restores HEAD's line wherever it equals
  the current one after applying the logged edits (own function's edits first); undoing
  by text search hit identical original text; (3) count braces on comment/string-free text,
  per `#if` branch. Open: 8,756 raw accesses (1,366 move on 64-bit).
- 2026-11-10 `genstruct` also for named parameters, locals (one struct per function and
  variable) and globals `&D_...` (per file), with function-pointer fields: 3,981 more rewrites
  (6,083 logged), open 8,756 -> 4,774, 64-bit-critical 1,366 -> 173, 86 functions kept raw;
  make check OK, gate --full PASS. Fixes: `((T *)(p + 0x17C))[i]` becomes `(&field)[i]`;
  `revert` restores every definition of a function (a `#ifdef BT_NATIVE` variant comes first
  in many files); `syntax_new.py` reports only clang errors HEAD does not have; `sync` copies
  untracked files too (a new header); `offsets.py check` = make check + per-function diff
  against HEAD for any codemod.
- 2026-11-10 `lp64_words.py`: integers that carry pointers become `BtIntPtr`/`BtUIntPtr`
  (`include/PR/ultratypes.h` shadows the submodule's copy: long/unsigned long under IDO like
  s32/u32; `pc/native/include/PR/ultratypes.h`: intptr_t). libclang reads each LP64
  diagnostic, finds the declaration the pointer passes through (cast, destination/source
  variable, parameter or return type in every declaration of the function, fields of
  generated structs) and replaces only its `s32`/`u32` token. hazards64 6,539 -> 908, all
  files compile LP64, make check OK with 0 functions changed, gate --full PASS. Lesson:
  `int` -> long changes IDO's code (gcskyDll), so only s32/u32 tokens are retyped. Left:
  fields of real structs, globals, array elements, raw memory reads, calls through pointers
  (`build/lp64_words_left.tsv`).
- 2026-11-10 `data_to_c.py`: asm `.data` modules become typed C definitions appended to their
  C file (no line moves), the yaml entry becomes `.data`. 182 modules moved (430 left,
  `port.py worklist data`). `ActorData` is now the 0x48 actor descriptor the overlays hold
  (`ActorDataX` adds the two 0x50 words), `unk2C` is `BtIntPtr` (a marker callback).
  Lessons: a C file with its own `.data` (as1 lever tables like `D_lever`) puts it first and
  moves the appended data, so such modules are refused; `T x[];` reads as `[1]` in libclang;
  the second declarator of `T a[], b[];` has no type tokens; block-scope declarations are not
  visible at the end of the file, so the appended block redeclares them.
- 2026-11-10 root cause of the actor-flag mismatches (retrace 46,310/46,311, also behind the
  rejected HUD/save patches): actor descriptor flag words (`ActorData` 0x24/0x3C, tested by
  `func_80102FA0`) whose value equals a stub or core address (`0x80082C10`,
  `0x80104410`) were emitted as native pointers, so the flags changed with the native
  layout. `data_to_c.py constants` lists the 17 words (`stub_constants.txt`), data.py keeps
  them raw. With it the build with the 155 new modules in C and the one with them in asm
  run identically (56,943 retraces). References re-accepted on purpose; old and new differ
  first at that flag (`0x01040000` -> `0x00050000`, bit 24 now off as on the N64).
- 2026-11-10 evening `data_to_c.py` 182 -> 415 modules (make check OK, gate --full PASS against
  the unchanged references). New: address-only scalar labels become arrays of the declared type
  (`&lab` -> `lab`); labels reached only from the module's own data become `u8[n]`; flag words
  with addend (`boot_thread_stack+0x1F32`, 13 more in `stub_constants.txt`, now 30) and raw core
  addresses in pointer fields (`D_8011A1BC + 0x64`, switch descriptors) are written as the ROM
  has them: overlay_processor keeps only relocations into the overlay itself; IDO puts every
  variable on >= 4 bytes; `ActorData` 0x44 is `BtIntPtr unk44`; `apply` also checks the native
  view; `verify` copies the regenerated `banjotooie.ld` back (a stale one fed both asm and C data
  to the native build). New pass `bt-datagroup`: `BT_DATA(align, module, offset)` sections
  become one packed block per module, as data.py builds asm modules. Without it clang orders
  globals by first mention and wasm-ld spreads them, so `su/coaster/data.c` (which reaches
  `D_8080041C` through `D_808003C0 + i * 0x5C`) read other tables (bisected: retrace 46,435).
  data.py dropped `.asciz "\x8C"` continuation lines: floats 70.0/280.0 read as 32.0/128.0 in
  boggy kidshome/boy/girl and captainblubber; fixed.
- `build.py` honours `BT_OUT` (separate tree for diagnostic builds); `data.py` honours
  `BT_DATA_ALIGN=N` (moves every asm data block without changing content: layout test).

## Milestones

| # | Milestone | Status |
|---|-----------|--------|
| M0 | Native core library + 53 module tests (Codex, up to 2026-11-05) | done |
| M1 | Selected game C files compile natively | 1,109 / 1,109 in the current ILP32 source selection (2026-11-08) |
| M2 | Game executable links; missing functions trap with their name | linked; 10 function diagnostics, zero generated data placeholders (2026-11-08) |
| M3 | Platform layer, boot runs to the game loop | done 2026-11-06 |
| M4 | Renderer: F3DEX2 HLE + software RDP + SDL window | done 2026-11-06: intro, title, attract demos, file select, new-game cutscene render; no AA/dither |
| M5 | Input (SDL controller), saves (EEPROM), audio (n_audio command lists) | done 2026-11-06: SDL gamepad/keyboard, EEPROM file, audio (n_aspMain on an RSP interpreter, SDL stream) |
| M6 | Gameplay verification: title, file select, Spiral Mountain, level transitions | in progress: new game plays into Spiral Mountain; warp sweep 2026-11-12: 225 of 229 maps load and run 25 s without crash (135 stay, 90 walk on through a door), 4 not in the section table |

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
   `bt-stackslots` only covers accesses in the same function; a callee that reads
   neighbouring locals as one array (2026-11-14, `su/spline.c`) needs a source fix.
2. **Audio details.** The microcode's MP3 overlay (command 7) is not supported (the
   interpreter stops with a message; Banjo-Tooie has not used it so far). Output
   latency is 35-110 ms (`LATENCY_BYTES` in `ai.c` plus the game's own rate control).
3. **Gameplay (M6).** 2026-11-14: map sweeps with scripted input find no crash any more
   (all 229 maps, 180 s through exit 1 and 120 s through exit 2). What is left are maps
   whose picture stands still after a debug warp: cutscene maps, quizzes and stills, and
   minigame or interior maps entered through an exit they may not have (kickball shows the
   arena without Banjo). Real play-throughs (`play.py`) are the next check, not more sweeps.
   Seen once (2026-11-07, optimized build): after a jump, frames alternated between a
   sky view and an above-ground view with a solid green (RGBA5551 0x0781) rectangle;
   only the two framebuffers and the Z buffer were drawn, and no display list ended
   early. Not reproduced in two reruns.
4. **Scripted runs are deterministic only with `BT_VCLOCK=1`.** Under the wall clock, the
   same `BT_PRESS` script still takes different paths.
5. **Cross-symbol data access.** Code that reaches data through another symbol's
   address only works when both lie in one asm block (`data.py` joins touching files of a
   module). Since 2026-11-11 zero-initialized C variables in a gap between two core asm files
   move into the joined block (`placeCData`); C variables with an initializer, and C-only
   neighbours without asm on both sides, are still placed by clang.
6. Codex's 64-bit `*_native.inc` replacements stay active under ILP32 unless they
   mismatch; then the module switches back to the original code with
   `#if defined(BT_NATIVE) && !defined(BT_ILP32)`. Their little-endian assumptions are
   a risk under the big-endian guest: plain members that share a word now follow
   `BT_NATIVE_LE_MEMORY` (unset under ILP32), bitfields `BT_NATIVE_LITTLE_ENDIAN`.
7. 10 function diagnostics left (`build/ilp32/traps.txt`), including unresolved linker/legacy names. The four old data placeholders have real OS definitions; new missing data fails the build.
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


## 2026-11-09 — Phase 1 / xsym: HUD-Einzeldatensatz, nach zwei Ansätzen gestoppt

- Ausgangs-/Endstand laut `port.py status`: xsym 286 → 286, calls 825 → 825,
  lp64 6539 → 6539. Keine dieser Reduktionen wurde in diesem Durchgang akzeptiert.
- Sonderauftrag: `build/ilp32/phase01-validation/typed-data-rejected.patch` auf
  Datensatz 0 der HUD-Tabelle verkleinert. Draw: `_sccustom_entrypoint_0`
  (N64-Wort 0x8008A648, Tabellenadresse 0x80800D54), Update:
  `_sccustom_entrypoint_3` (0x8008A660), Scale: 0.65f (Bits 0x3F266666).
  Statische Prüfung aller neun Callback-Paare und Scale-Bitmuster gegen die
  Assemblerdaten: identisch. Ein falscher Initialwert wurde nicht nachgewiesen.
- Ansatz 1: ein kompletter typisierter Datensatz, nur unter `BT_NATIVE`.
  Ansatz 2: feldweise Varianten desselben Datensatzes (nur draw / update / scale).
  Alle Varianten ausschließlich als generierte Diagnosequellen unter
  `build/phase01-hud-probe/`; keine Diagnosevariante in `src/` übernommen.
- Unveränderter Kontroll-Build: `port.py gate --case new-game --exe .../control.exe`
  PASS über 56943 Retraces. Alle vier Varianten melden FAIL bei Retrace 46311,
  Map 175, `actors[45].health_flags[2]`: Referenz 3238330368 (0xC1050000),
  Variante 17104896 (0x01050000). Kein einzelner Tabellenwert als Ursache isoliert.
- Wesentliche Einschränkung: Die Abschlussprüfung fand 251 parallel veränderte
  Eingabedateien seit dem Hash-Snapshot, einschließlich Build-/Host-Code und
  `src/overlays/sc/infobar.c`. Die letzte Variante hat auch andere Guest-IR-
  Änderungen. Die Messreihe ist daher kein vollständig isolierter Vergleich und
  erlaubt keine belastbare Ursachenzuordnung. Keine parallelen Änderungen
  zurückgesetzt, keine fremden Jobs beendet. Ein Layout-Effekt wurde nicht erneut
  untersucht; gemäß Auftrag ist er ausgeschlossen.
- Nach den zwei gescheiterten Ansätzen gestoppt. Kein Implementierungs-Commit,
  kein `--accept`. SHA-256 aller drei Referenzen vor/nachher unverändert.
  Kein `make check`, da keine Diagnoseänderung an `src/`/`include/` übernommen wurde.
- Artefakte: `build/phase01-hud-probe/report.json`, `record0-draw.patch`,
  `probe.py`, `matrix.py`, pro Variante `.c`, `.exe`, `.bc`, `.linked.bc` und
  Gate-Ergebnisse. Wiederholung einer einzelnen Probe:
  `python3 build/phase01-hud-probe/probe.py 0 --fields draw`.
  Vor weiteren Versuchen sind alle Eingaben inklusive Build-/Host-Code als
  unveränderlicher Snapshot zu sichern; ein separates BT_OUT allein genügt nicht.


## 2026-11-10 (spät) — Phase 2/5: Deklarationen an Definitionen angeglichen (`protos.py fix`)

- Neu: `protos.py fix` schreibt jede Deklaration, die ihrer Definition widerspricht, auf
  deren Signatur um (gleiche Zeilenzahl), `protos.py n64` prüft im Docker-Klon
  `build/n64verify` gegen `build.pre` (Objekte vor dem Codemod). Drei Durchgänge:
  exakte Signatur; portable Form (`void *`, `s32`, …), wo die Typen der Definition an
  der Deklarationsstelle fehlen; Stub-Namen `_x_entrypoint_N` der Overlays.
- Zurückgenommen wird automatisch: was clang in N64- oder nativer Sicht neu ablehnt
  (Ergebnis einer `void`-Funktion wird benutzt, durchgereichte Argumente, Typ-Konflikte),
  und jede Deklaration, die eine Funktion mit geändertem IDO-Code benutzt
  (`protos_ido_keep.txt`, 1.356 Datei/Funktion-Paare; dort wandelt IDO mit der echten
  Signatur Argumente um oder die Aufrufer übergeben rohe Float-Bits).
- Ergebnis laut `port.py status`: protos 8.809 → 4.217 (size 2.801 → 1.125, ret 5.207 →
  2.309, arity 380 → 362, float 421 → 421), calls 825 → 698 (RET 339 → 212).
  4.499 Deklarationen in 700+ Dateien umgeschrieben.
- lp64: 908 → 2.017 direkt nach dem Codemod (die Mischungen waren vorher hinter falschen
  Deklarationen unsichtbar), nach `lp64_words.py` 1.041; alle Spieldateien kompilieren
  als LP64. Dafür gilt `BT_DATA` (Section-Attribut für `bt-datagroup`) nur noch unter
  `BT_ILP32`: Mach-O lehnte den Section-Namen ab, 415 Dateien scheiterten seit der
  Datenumstellung im LP64-Check und acht davon brachen vor der Zählung ab.
- Prüfung: `make check` OK nach jedem Durchgang und am Ende (ROM bytegleich);
  `port.py gate --full` PASS (2.698 / 56.943 / 10.790 identische Retraces), Referenzen
  unverändert.
- Klon für N64-Prüfungen: `offsets.sync` kopiert jetzt auch, was git nicht listet
  (Submodule, `tools/ido*`, Tool-Binaries, `decompressed.us.z64`, `assets/overlays`).
  Falle: Bricht `overlay_processor` ab (fehlende `relocs.bin`), bleibt eine leere
  `build/us/assets/overlay_table.s` liegen und die ROM ist 0xDE0 Bytes zu kurz; Datei löschen.
- Offen: 4.217 Abweichungen. 884 lehnt clang ab (meist benutztes Ergebnis einer
  `void`-Funktion = RET/UNDEFRET der `calls`-Liste), 387 haben native Sondertypen in der
  Definition (`NativeSpawn…`), der Rest steht in `protos_ido_keep.txt`.

## 2026-11-10 (Nacht) — Phase 1: `.bss` nach C, noch NICHT aktiv (Gate FAIL, zurückgenommen)

- Neu: `bss_to_c.py scan|apply|revert`. 772 asm-`.bss`-Labels in 45 Dateien bekommen unter
  `BT_NATIVE` typisierte Definitionen am Ende einer C-Datei, die sie deklariert (577 typisiert
  in 123 Dateien, 195 als Bytes in `pc/native/bss_untyped.c`); `BT_DATA` hält jede Asm-Datei als
  einen Block (Größe und Ausrichtung wie `data.py`). 23 Labels bleiben (Modul-`.data` noch Asm).
  `bt-datagroup` kann jetzt Labels, die im Typ des Vorgängers liegen, als Alias hineinlegen.
  `include/bt_data.h` liefert `BT_DATA` für Dateien ohne `common.h`. N64 `make check` OK.
- Gate: intro PASS, new-game FAIL bei Retrace 8049 (`actors[1].health_flags[7]` 20640 statt
  16544), edited-save FAIL bei Retrace 6150 (`flags[1]`). Halbierung
  (`BT_BSS_GROUPS=lo:hi`, `BT_BSS_SKIP=namen`): Gruppen 0–21 zusammen PASS; die Abweichung
  braucht `bss_core2bss1_sound_tail` UND `bss_core2bss2` gleichzeitig, jede allein ist PASS.
  Die beiden Dateien liegen nicht nebeneinander (0x80126CE0 und 0x8012C7F0), also kein
  Nachbarzugriff; Verdacht: ein Zugriff über Blockgrenzen, dessen Ergebnis vom Layout abhängt.
  Nächster Schritt: `xsym_report.py` mit beiden Gruppen in C, Zugriffe suchen, deren Treffer
  den Block verlassen; Gruppen 27–44 sind allein noch ungetestet.
- Stand im Baum: per `bss_to_c.py revert` zurückgenommen (keine Definition aktiv). Vor dem
  nächsten `apply` einmal `build.py` laufen lassen (die Objekte definieren die Labels noch),
  danach `port.py gate --full`; das Gate wurde nach dem Revert nicht erneut gefahren.
- `data_to_c.py`: neuer nativer Modus (`scan-native`, `apply --native`: Definitionen nur unter
  `BT_NATIVE`, yaml bleibt) und `fields` (Struct-Felder, deren Daten Adressen halten, werden
  `BtIntPtr`). Geschrieben, `scan-native` zählt 18 von 197 Modulen als ok (92 scheitern an
  „pointer in an integer“, dafür ist `fields` gedacht); `fields` und `apply --native` sind
  noch nicht ausgeführt und ungeprüft.

## 2026-11-11 — M6: Karten-Sweep, drei generische Absturzursachen, Schatten/HUD-Matrix

Neue Werkzeuge (alle ohne Änderung an `src/` oder `include/`, daher kein N64-`make check` nötig):

- `BT_WARP=secs:map_hex:exit,...` (`host/input.c`, Hook im Guest-`osViSwapBuffer`): ruft zur
  Spielzeit `_gcgoto_entrypoint_1(map, exit)` auf dem Spiel-Thread auf. Zählt in die
  `BT_PRESS`-Identität des Trace-Headers. Ohne die Variable ändert sich kein Trace.
- `python3 pc/native/wasm/sweep.py OUTDIR [--map HEX ...] [--exe PATH]`: lädt je Karte aus
  `include/maps.h` einen Spielstand mit offenen Welten (Spiral Mountain bei 29 s), warpt bei 34 s
  und läuft 25 s mit Stick-Kreisen und A/B. Ergebnis `summary.json`; Status `ok`, `other-map`
  (durch eine Tür in die Nachbarkarte gelaufen), `expected`, `crash`, `trap`, `hang`. Abstürze
  werden über `atos` nach innerster Spielfunktion gruppiert (auch inline-optimierte).
  229 Karten brauchen etwa 10 Minuten. Warp vom Titelbild ist ungeeignet: der Attract-Modus
  läuft weiter und wechselt selbst die Karte.
- Absturzdiagnose im Host: `WASM_RT_TRAP_HANDLER=bt_trap`, eigener SIGSEGV/SIGBUS-Handler mit
  Fehleradresse und PC, `bt_backtrace()` (auch in `bt_fatal`). Falle: `build.py` baut
  `wasm-rt-impl.c.o` bei geänderten Host-Flags nicht neu (Objekt löschen).
- `BT_GFX_TRACE=N@K` überspringt K Tasks; mit `BT_GFX_DUMP` stehen jetzt auch die
  Bildschirmkoordinaten jedes Polygons im Log.
- `BT_HEAPCHECK=1 BT_OUT=build/ilp32-heap build.py`: Arena prüft bei jedem alloc/free alle Köpfe.
- `pc/native/wasm/watch_lldb.py`: lldb-Skript, das Schreibzugriffe auf eine Guest-Adresse mit
  Backtrace protokolliert (Aufruf im Dateikopf); damit wurden Ursache 3 und der offene
  Heap-Fehler unten gefunden. lldb-Watchpoint-Kommandos im Batch-Modus hängen, das Skript nicht.

Behobene Ursachen (Sweep vorher: 41 Abstürze + 1 Trap; nachher: 1 Absturz):

1. **Structs per Wert** (`flattenByVal` in `FixCalls.cpp`): IDO übergibt die Worte in a0..a3/Stack,
   clang-wasm einen Zeiger auf eine Kopie. 8 Funktionen (`subaddietaxi_entrypoint_16`,
   `func_808003DC_chpoolkids`, `func_801026CC`, …) lasen ihr erstes Argument als Adresse. Jeder
   byval-Parameter wird ein i32 je Wort, jedes byval-Argument seine Worte. 14 Karten.
2. **Kurze indirekte Aufrufe** (`passThroughIndirect`): `(*(s32 (**)())(arg0 + 0x24))()` in
   chbanjoctrl verlässt sich auf a0 des Aufrufers. Indirekte Aufrufe mit < 4 Integer-Argumenten
   reichen jetzt die Parameter des Aufrufers der fehlenden Slots durch (nur im ersten Lauf, vor dem
   Inlining). Im `BT_NOINLINE`-Build lief es zufällig, weil x1 noch arg0 hielt.
3. **C-Variablen zwischen Asm-Datenblöcken** (`data.py` `merge_neighbours` + `placeCData`):
   `s32 D_80127050[4]` ist in `1E78170.c` definiert, liegt auf dem N64 aber zwischen
   `core2bss1_sound_tail.s` und `core2bss1_0_1.s`; `func_8009EC60` schreibt den Respawn-Punkt über
   `&D_80127040 + 0x10`. Nativ traf das `D_80127060`, dessen Byte-Reset die Karten-ID abschnitt
   (0x12B -> 0x2B, Absturz beim Respawn in jeder Karte >= 0x100, nur im optimierten Build). 20
   solche Lücken (13 in core2-bss, u. a. die Flag-Zeiger `D_8012C770`): die Lücke wird mit
   Nullbytes überbrückt, nullinitialisierte C-Variablen ziehen als Alias an ihren N64-Platz.
   Variablen mit Initialisierer bleiben, wo clang sie hinlegt (Meldung im opt-Log). Das erklärt
   auch den `.bss`-nach-C-Fehlschlag vom 2026-11-10 (Gruppen sound_tail + bss2).
4. **`nearbyintf` nicht deklariert** (`guest/include/math.h`): implizit `int`, FixCalls
   reinterpretierte die Float-Bits. `func_80116684` (`pc/native/skeleton.c`) schrieb so
   Knochenmatrizen mit Float-Bits statt Festkomma: dunkles Diagonalband vom HUD-Symbol unten rechts
   über den ganzen Bildschirm, fehlender Spielerschatten. FixCalls meldet jetzt `RETCLASS`
   (Ergebnis wechselt die Registerklasse); die 31 verbleibenden Fälle im Spielcode sind paarweise
   Durchreichungen (Bits bleiben erhalten), Phase-2-Material.

Prüfung: `port.py gate --full` nach 1–3 PASS gegen die unveränderten Referenzen. Fix 4 ändert
Bilder: 31.691 (new-game) und 7.172 (edited-save) Retraces unterscheiden sich **nur** im
Framebuffer-Hash, Zustand und alle anderen Felder sind über 56.943 bzw. 10.790 Retraces gleich.
Referenzen deshalb bewusst neu akzeptiert (`--accept`), danach erneut PASS.

Sweep-Endstand (optimierter Build): 143 ok, 80 other-map, 5 expected, 1 crash.

- expected: A0, F5, 149, 184 stehen nicht in der Sektionstabelle (`gcsectionDll`), D0 (Chuffys
  Führerstand) braucht eine Zugposition im Spielstand.
- **Offen, Karte 116** (TDL Inside the Mountain, drittes Betreten über 112): Actor 0x28C
  (`ch/factory/battery.c`) hat keine Route (`unk70_25 == 0`), `subaddierouteDll_entrypoint_1`
  schreibt mit `route == -1` vier Bytes vor seine Handle-Tabelle und zerstört `prev_size` des
  Arena-Blocks; `bt_free` stürzt beim Verlassen ab. Offen ist, warum die Routensuche
  (`_gccubesearch_entrypoint_12(…, 0x28C, …)`) dort nichts findet.
- "ok" heißt: lädt und läuft 25 s ohne Trap. Bilder wurden nur als Kontaktbogen überflogen; DE, DF,
  E0 und CC waren schwarz (nicht untersucht). Der grüne Himmel aus dem ersten Versuch war ein
  Artefakt des Titelbild-Warps; im echten Spiel zeichnen 113, 136 und 13F ihren Himmel.
- Mehrspieler, Bosse und Minispiele wurden nur betreten, nicht gespielt.

## 2026-11-12 — Spielerkomfort (SoH-Richtung): Breitbild, Einstellungen, Controller, ROM-Erststart

Ziel: wer nur die ROM hat, startet `bt_game` ohne Terminal und ohne Umgebungsvariablen.

- **Breitbild ohne Verzerrung:** Das Spiel hat einen eigenen anamorphen 16:9-Modus
  (`widescreen_enabled`, Option im Spielstand-Menü). `vi.c` meldet ihn mit jedem Framebuffer an
  `rdp_register_framebuffer(address, width, widescreen)`; der Rasterizer rendert dann 4/3 so viele
  Spalten (`render_sx = (render_scale*4+1)/3`, getrennte Skalen `kx/ky`), das Fenster wechselt
  auf 1280x720 logisch. Einstellung „immer 16:9“ (`BT_WIDESCREEN=1`) setzt den Modus über den
  Host-Import `widescreen_forced` in jedem `osViSwapBuffer`. `widescreen_enabled` steht im
  Trace-Kopf (`trace_tools.py`, Fixture in `trace_test.py`).
- **Einstellungsmenü** (`host/settings.c`, F2 oder Back am Gamepad): interne Auflösung 1x-4x
  (`rdp_request_scale`, wirkt ab dem nächsten Framebuffer ohne Neustart), Bildformat, Vollbild
  (auch F11), Bildfilter scharf/weich, Vibration, Lautstärke (`SDL_SetAudioStreamGain`). Gespeichert
  in `settings.ini` im SDL-Benutzerordner (`SDL_GetPrefPath`, macOS
  `~/Library/Application Support/BanjoTooie/`). Umgebungsvariablen haben Vorrang; mit
  `BT_HEADLESS` wird die Datei nicht gelesen, Skriptläufe hängen also nie von Spielereinstellungen
  ab. F12 legt ein BMP-Bildschirmfoto im Benutzerordner ab.
- **Vier Controller, Rumble Pak:** `osContInit`/`osContGetReadData` für 4 Ports
  (`pad_read(port)`, `pad_mask`), `osPfsInit`/`osMotorInit`/`__osMotorAccess` auf
  `SDL_RumbleGamepad` (aus, wenn Vibration aus). Bei offenem Menü sieht Port 1 keine Eingaben.
- **Spielstand im Benutzerordner** (`io.c host_path`): `bt_eeprom.bin` kommt aus `BT_SAVE`, sonst
  aus dem Arbeitsverzeichnis bei `BT_HEADLESS`/`BT_VCLOCK` oder wenn dort schon eine Datei liegt,
  sonst aus dem Benutzerordner. Der Pfad wird einmal ausgegeben.
- **ROM-Erststart** (`io.c bt_rom_find`): ohne Argument `baserom.us.z64` im Arbeitsverzeichnis,
  dann die Kopie im Benutzerordner, sonst Hinweis + `SDL_ShowOpenFileDialog`; die gewählte ROM
  wird als `.z64` in den Benutzerordner kopiert. `.v64` (byte-getauscht) und `.n64`
  (little-endian) werden beim Laden gewandelt (Trace nach 300 s identisch zu `.z64`); andere
  Dateien und andere Versionen als US (`NB7E` an 0x3B) werden mit Meldung (Fenster + stderr)
  abgelehnt. Der Dialog selbst wurde nur bis zum Öffnen geprüft (Prozess wartet, kein Fehler),
  nicht durchgeklickt.
- **Karte 116 (offen seit 2026-11-11):** `subaddierouteDll` ohne Route schreibt auf dem N64 vor
  seine Tabelle. Nativ jetzt `BT_NATIVE_ONLY(if (route < 0) return;)` an beiden Stellen, auf
  einer bestehenden Zeile (`include/common.h`: `BT_NATIVE_ONLY(code)`, für Code, der nur nativ
  laufen soll, ohne dass eine `src`-Datei Zeilen gewinnt). `make check` OK. Der Absturz war im
  aktuellen Stand auch ohne Wache nicht mehr reproduzierbar (Ausgänge 0-4); die Wache bleibt.
- **Befund: Spielverhalten hängt vom Heap-Layout ab.** Versuche, Arena-Blöcke zu polstern
  (auch nullgefüllt), änderten Traces ab Retrace 18 (Markerfelder von Actor 7 im Intro). Jede
  Änderung an `memory.c`/Blockgrößen ist also eine Verhaltensänderung für das Gate.
- `build/reference/edited-save.jsonl` neu akzeptiert: Referenz war seit der `corpus.py`/
  `save_editor.py`-Änderung vom 2026-11-11 veraltet („incompatible traces: eeprom“).

Prüfung: `port.py gate` intro 2698, new-game 56.943, edited-save 10.790 Retraces identisch;
`make check` nach den `include/common.h`-/`routeDll.c`-Änderungen OK.

Sweep (`sweep.py`, neu: Status `static`, Bild 5 s unverändert): 115 ok, 20 static, 90 other-map,
4 expected, 0 crash (2026-11-11: 143 ok, 80 other-map, 5 expected, 1 crash). static sind die
Zwischensequenz-Karten A2-AC und 159 (ohne Skript schwarz bis auf einen 29-Pixel-Strich, nicht
geprüft, ob der N64 ihn auch zeigt), DE/DF/E0 (dunkle Dodgem-Arenen), 15F/189 (Quiz) und die
Standbilder 167-169. Dass 10 Karten mehr durch eine Tür laufen, ist nicht zugeordnet (Kandidaten:
Rumble Pak jetzt vorhanden, routeDll-Wache).

Leistung (Software-Rasterizer, Apple Silicon, Spiral Mountain): bei 4x 28-52 ms je Task, also
19-35 Bilder/s; 4x ist für schwere Szenen zu langsam. 2x/3x in diesem Durchgang nicht gemessen.

### 2026-11-12 (Abend) — 60 FPS, ROM-Prüfsumme, Stick, Tastenbelegung

- **60 FPS (Einstellung „Bildrate“, `BT_FPS60=1`, experimentell):** Das Spiel wartet je Bild
  mindestens `func_80015184()` Retraces (meist 2, Minispiele 3-5) und rechnet mit den wirklich
  vergangenen (`D_80078F64` → Delta-Zeit). `BT_FRAME_INTERVAL(...)` (`include/types.h`, auf dem
  N64 `(n)`) um beide Abfragen in `func_800151BC`; nativ fragt `bt_frame_interval` den Host
  (`frame_interval`-Import), der bei aktivierter Option 1 liefert. Gespeicherte Intervalle der
  Minispiele bleiben unverändert. `make check` OK.
  Prüfung mit dem new-game-Korpus: alle 15 Kartenwechsel zur selben Spielzeit (Abweichung
  ≤ 0,4 s über 772 s), 54-60 statt 18-20 Bildwechsel/s in den Zwischensequenzen. Bewegungstest
  (Spiral Mountain, gleiches Skript): Sprunghöhe 175 → 181 (+3 %), Anlaufsprung 135 → 144, Laufweg
  in 3 s 1413 → 1315 (−7 %), Endposition nach allen Bewegungen fast gleich. Die Physik ist also
  nicht bitgleich; deshalb „experimentell“ und standardmäßig aus. `BT_FPS60` und
  `BT_WIDESCREEN` zählen (nur wenn gesetzt) in die `BT_PRESS`-Identität des Trace-Kopfs.
- **ROM-Prüfsumme:** neben dem Spielcode FNV-1a-64 über die ganze `.z64` (`e04fb9f40c35687f`,
  derselbe Wert wie im Trace-Kopf). Ein einzelnes gekipptes Bit wird abgelehnt.
- **Stick:** runde Deadzone (20 %) und das achteckige N64-Gate (80 auf den Achsen, 65 auf den
  Diagonalen) wie bei libultraship, statt quadratischer Deadzone je Achse.
- **Tastenbelegung:** `settings.ini` nimmt `key.A=Space,X` (SDL-Tastennamen) für A B Z Start L R
  CUp CDown CLeft CRight DUp DDown DLeft DRight; ersetzt die Vorgabe des Knopfs, bleibt beim
  Speichern erhalten. Bewegen bleibt WASD. Kein Menü dafür; die F1-Hilfe zeigt die Vorgaben.
- **Spielstand-Import/Export:** `bt_eeprom.bin` ist das rohe 2-KB-EEPROM in N64-Byte-Reihenfolge,
  dasselbe Format wie `.eep` von Project64/mupen64plus; Kopieren genügt.
- Getestet: `keyboard.c` (Belegung, Stick-Gate), ROM-Varianten von Hand.

### 2026-11-12 (Nacht) — Software-Raster schneller, Korpus „worlds“, Dauerlauf-Werkzeug

- **Raster-Threads besser ausgelastet** (`host/rdp.c`, nur `BT_SCALE` > 1; Skala 1 bleibt die
  bitgenaue Referenz): Profil (`sample`, Spiral Mountain, 4x) zeigte ~70 % der RCP-Zeit in
  Dreiecken bei nur ~35 % Auslastung der 7 Raster-Threads, dazu ~17 % `frame_resolve`
  (Herunterrechnen ins Gast-Bild, auch des Z-Puffers) und ~5 % `fill_rect` einzeln. Der Pool führt
  jetzt beliebige Band-Aufträge aus (`pool_for`); Herunterrechnen und Füllrechtecke laufen in
  8-Zeilen-Bändern, `rdp_end` rechnet noch bei laufendem Pool herunter, und Dreiecke gehen ab 2048
  statt 8192 Pixeln Hüllrechteck (8 statt 16 Zeilen) auf den Pool (gemessen: 8192 → 20,0 ms,
  2048 → 16,5 ms, 512/1024 nicht besser). Ergebnis Spiral Mountain 4x: im Mittel 33 → 16,5 ms je
  Bild; Benchmark 4x 12,1 → 9,0 ms. Benchmark-Hashes (`render_test.py`) unverändert,
  heruntergerechnete Gast-Bilder bei 2x bitgleich zum alten Build (19 Stichproben).
  Ausprobiert und zurückgenommen: Dreiecke mit Zustands-Schnappschuss in eine Warteschlange und
  in 8-Zeilen-Streifen über alle Dreiecke rastern (Bild dann unabhängig von der Thread-Zahl). Im
  Spielabschnitt nur 16,5 → 16,1 ms; auch 10 oder 12 statt 8 Threads bringen nichts. Der Engpass
  ist jetzt die Arbeit je Pixel (grob 35 ns je Fragment bei 8 Threads: generischer Combiner,
  4 Texel je bilinearem Sample); schneller wird es nur dort, und an Skala 1 hängt das Gate.
- **Korpus-Fall `worlds`** (`corpus.py`, `port.py gate --case worlds`, Teil von `--full`): Spielstand
  mit offenen Welten, dann per `BT_WARP`-Fahrplan je 20 s in die Hubs von Mayahem Temple, Glitter
  Gulch Mine, Witchyworld, Jolly Roger's Lagoon, Terrydactyland, Grunty Industries, Hailfire Peaks
  (Lava- und Eisseite), Cloud Cuckooland, Cauldron Keep, Jinjo Village und Wooded Hollow, mit
  Stick-Kreisen und A/B. 276 s Spielzeit, 16.544 Retraces, 20 Karten (einige Hubs laufen durch eine
  Tür weiter). Zweimal abgespielt identisch (`corpus.py --case worlds`). `corpus.run_env(case)`
  liefert `BT_PRESS` und `BT_WARP` für alle Werkzeuge, die Korpus-Fälle abspielen.
- **Breitbild geprüft:** Hi-Res-Dumps im 16:9-Modus (2x) zeigen HUD, Schrift und Ränder korrekt
  proportioniert; das Spiel staucht seine 2D-Elemente selbst für die anamorphe Ausgabe.
- **`soak.py OUTDIR [--seconds-per-map 15] [--rounds N] [--exe PATH]`:** ein Prozess warpt
  nacheinander durch 194 Karten (alle ladbaren ohne `sweep.EXPECTED`, ohne Zwischensequenz-Karten
  `_CS_`/`_STILL`: die tauschen keine Bilder, also kommt der nächste Warp dort nie an), Speicher
  (RSS) alle 10 s. `BT_PRESS` nimmt dafür jetzt bis zu 65.536 Einträge (vorher 2048).
  Ergebnis mit dem Heap-Prüf-Build (`BT_HEAPCHECK=1`, `BT_OUT=build/ilp32-heap`), 3 Runden à 15 s:
  582 Warps, 8.769 s Spielzeit (~2,4 h) in 18 min, kein Absturz, keine Heap-Meldung, RSS höchstens
  86 MB und am Ende 49 MB. Ein Leck im Host gibt es damit nicht.

### 2026-11-12 (spät) — Phase 1: `.data`-Module 415 → 497 in C

- **`data_to_c.py`, neue Regeln** (alle mit `verify` im Docker-Klon geprüft: `.data`-Bytes und
  Relocations jedes Moduls gleich dem Asm-Objekt, `make check` OK):
  - Array mit Nullbytes nach dem letzten ganzen Element: Ausrichtungslücke zum nächsten Label oder,
    nach dem letzten Label, die 16-Byte-Sektionsauffüllung (vorher „no multiple of the element“).
  - **Funktionslokale Typen** (`struct`/`union`/`typedef` in einer Funktion, mit denen ein Label
    deklariert ist) werden zeilenneutral auf Dateiebene gehoben: die Definition einzeilig auf die
    Leerzeile vor der Funktion (sonst vor deren erste Zeile), die alten Zeilen bleiben leer; aus
    `struct X {...} var;` wird `struct X var;`; derselbe Typ in mehreren Funktionen nur einmal.
    Im Log als `hoisted`, `revert` stellt die Zeilen wieder her. 45 Module.
  - Eine Funktion, die die C-Datei ohne Deklaration aufruft, wird im angehängten Block `int f();`
    (wie die implizite Deklaration) statt `void f();`.
  - Funktionszeiger-Arrays mit Parameterliste (`void (*D[])(u32, s32, s32)`) sind keine
    Mehrfachdeklaration; `extern struct Tag {...} D[]` wird als `struct Tag D[n]` definiert.
  - Null-Wörter zwischen zwei Labels, die die Ausrichtung des nächsten nicht erzeugt, und am
    Modulende, wenn das Objekt sonst eine 16-Byte-Zeile früher endete: Füllvariable
    `u8 <label>__gap[n] = { 0 }`. Der zweite Fall war ein echter Fehler: madamegrunty kam mit
    0x10 Bytes zu kurzem `.data` durch die alte Regel, `verify` fand es (`make check` FAIL).
  - Ein Label im ersten Element des vorigen, das keine Quelle, kein Header und keine andere
    Asm-Datei nennt (`asm/nonmatchings` zählt nicht), wird Teil der Tabelle.
  - Cross-Symbol-Gruppen (`xsym_groups.tsv`) sperren ein Modul nur noch, wenn nach dem Plan mehr
    als ein Label der Gruppe ein eigenes C-Objekt bleibt oder die Gruppe in ein anderes Modul reicht.
- **Quellen, zeilenneutral:** madamegrunty `FortuneEntry.unk4` ist `s16 unk4; s16 unk6;` (Daten
  und einziger Zugriff sind `s16`, als `f32` war es ein NaN) und das Tabellenende ein `(u8 *)`;
  Mehrfach-`extern` in armouredcaveman, boggy und dippy auf derselben Zeile getrennt (dann nur
  per `&` benutzt, also Arrays); worldmakes Struct heißt `IdWorldmakeEntry`. Zugriffe über ein
  Label mitten in einer Tabelle als Feld oder Spalte der Tabelle: chbounce
  (`D_80800FE0[i].actorId`, `.unk20`), chchompaslunch und chfootwear (Spalten 1–4), cothemedll
  (Spalten 1 und 2), chmrsicecube, gcnewpause (`[i].unk3`), chchuffy (`[i].pad[1]`).
- Rest 114 Module (`port.py worklist data`): 18 C-Dateien mit eigenem `.data` (as1-Hebel-Tabellen), Tabellen
  mit mehreren benannten inneren Labels (dinoswitches, gcegg, jigsawbitcont …), Labels mitten in
  einem Element eines anderen Typs (Klasse „misaligned“), Byte-Blobs mit Adressen anderer
  Struct-Typen (Schalter-Deskriptoren u. a.), halbe Tabellenzeilen (`u16 x[][4]` mit 0x3C Bytes).

### 2026-11-12 (Nacht) — Phase 1: `.bss` nach C, diesmal aktiv (Gate PASS)

- `bss_to_c.py apply` (wie am 10.11.): 582 asm-`.bss`-Labels typisiert in 125 C-Dateien (unter
  `BT_NATIVE` am Dateiende), 195 als Bytes in `pc/native/bss_untyped.c`, 18 bleiben (Modul-`.data`
  noch asm). Erster Gate-Lauf scheiterte genau wie am 10.11. (new-game Retrace 8049,
  edited-save 6150, worlds 1713): `placeCData` erklärte es also nicht allein.
- **Ursache:** Die einzige Cross-Symbol-Gruppe dieser Dateien ist der Respawn-Punkt:
  `D_80127040…4C` (bss, nach C verschoben) und `D_80127050` (C-Variable in `1E78170.c`), die der
  Code über `&D_80127040 + 0x10` erreicht. Als Asm-Label lagen beide in einem Block, mit
  `bt-datagroup` bekam die bss-Datei einen eigenen Block und `D_80127050` blieb im Asm-Brückenblock.
- **Lösung (`data.py`):** Ein bss-Label, das C definiert, wird nicht mehr übersprungen, sondern
  bekommt im Asm-Block den Platzhalter `__bt_place_<label>`; `placeCData` zieht die
  nullinitialisierte C-Definition dorthin. Nativ bleibt das Layout damit exakt das der Asm-Blöcke
  (Nachbarzugriffe wie oben funktionieren weiter), die Definitionen sind trotzdem typisiert.
  833 Platzhalter; außerhalb bleiben die 10 Lückenvariablen mit Initialisierer (wie bisher) und
  `D_8007E938` (`__OSThreadOddFpStorage`, nativ größer als sein Platz; liegt wie vorher in seinem
  `bt-datagroup`-Block).
- Gate `--full` PASS gegen die unveränderten Referenzen (intro, new-game, edited-save, worlds).
  `bss_to_c.py scan` hatte einen Tupel-Fehler in der Ausgabe (behoben).

## 2026-11-13 — Bildinterpolation: 60 FPS ohne Eingriff in die Spiellogik (SoH-Art)

Einstellung „Bildinterpolation“ (F2, `settings.ini` `interp=1`, Umgebung `BT_INTERP=1`; Standard aus).
Das Spiel rechnet unverändert mit 30 (20/15) Bildern/s; der Host zeigt zwischen zwei Spielbildern
Zwischenbilder, die aus der Displayliste des neuen Bildes mit gemischten Matrizen gerastert werden.

- **Aufzeichnung (`gsp.c`):** Jeder Task, der in ein VI-Bild zeichnet, protokolliert jedes `G_MTX`
  mit einem Schlüssel aus der Geometrie, die danach gezeichnet wird (erstes `G_DL`/`G_VTX`, wie
  geschrieben, also segmentrelativ und damit bildübergreifend gleich). Matrizen mit direkter
  Adresse (Kamera-Projektion, Objektwurzeln aus dem Matrixpuffer) werden der nächstgelegenen
  vorherigen mit gleichem Schlüssel zugeordnet (Translation), segmentrelative (Knochen über
  Segment 5 in statischen Modell-Listen) innerhalb ihrer Wurzel nach Reihenfolge. Projektions-Loads
  ohne Treffer fallen auf den gleichnamigen Load des Vorbilds zurück (Kamera bleibt flüssig, auch
  wenn ihre Liste pro Bild neu gebaut wird). Gemischt wird elementweise; ein Paar mit großer
  Drehung (> halbe Matrixgröße) oder > 500 Einheiten Sprung gilt als Schnitt und bleibt aktuell.
  `G_CULLDL`/`G_BRANCH_Z`-Entscheidungen werden aus dem echten Durchlauf wiederholt, damit beide
  Durchläufe dieselben Befehle lesen; jede gelesene Matrix wird gegen die Aufzeichnung geprüft
  (sonst Abbruch der Mischung für den Rest des Bildes, Zähler `desyncs`).
- **Rastern (`rdp.c`):** Zwischenbilder gehen in Host-Puffer (`ip.color`, `ip.z`) in der aktuellen
  Auflösung, vorbelegt mit dem Inhalt des Ziel-Bildes vor dem Task. Andere Ziele (Render-to-Texture,
  geliehener Z-Speicher) werden im Zwischenlauf nicht beschrieben; ihre Texturen liest er so, wie
  der echte Lauf sie hinterließ. RDP-Zustand, TMEM und Rauschfolge werden gesichert und
  wiederhergestellt.
- **Asynchron:** Die Zwischenläufe laufen auf einem eigenen Thread mit einem Schnappschuss der
  ersten 16 MB Gast-Speicher (Spieldaten, Heap-Arena, Stacks; ~1 ms memcpy), damit das Spiel
  weiterrechnen kann. Der nächste echte Task (und eine Skalierungsänderung) wartet, bis der Thread
  fertig ist. Synchron kostete die Option bei 3x Echtzeit 27,6 → 22,9 Spielbilder/s, asynchron
  25,6 (der Software-Raster ist bei 3x schon ohne Interpolation am Limit; 2x ist die Empfehlung).
- **Anzeige (`vi.c`, `video.c`):** `bt_vi_frame` liefert das Alter des gezeigten Bildes in
  Retraces. Alter 0..k-2 zeigt Zwischenbild i (t = (i+1)/k, k = letztes VI-Intervall, höchstens
  3 Zwischenbilder), danach das echte Bild: eine Retrace Latenz bei Intervall 2.
  Fehlt ein Zwischenbild noch, wird das echte gezeigt. Dumps unter `BT_VCLOCK` warten auf den Thread
  (wiederholbar). `BT_RENDER_STATS=1` meldet `interp: frames matrices/frame matched desyncs`.

Prüfung:
- Spielzustand unberührt: `worlds` (16.544 Retraces) und `new-game` (56.943) mit `BT_INTERP=1`
  identisch zu den Referenzen; `edited-save` bei 2x mit/ohne Interpolation identisch (10.790).
- Echte Bilder im Interpolationslauf bitgleich zum Lauf ohne, um eine Retrace versetzt (60/60);
  synchrone und asynchrone Variante liefern dieselben 60 Bilder.
- Über alle Welt-Hubs: 97,6–99,4 % der Matrizen zugeordnet, 0 desyncs. Drei Kartenwechsel
  (Warp B8→C7, C7→D6, Tür D6→E1; ~600 Bilder) ohne Mischbild (kein gezeigtes Bild weiter von beiden
  Nachbarn entfernt als diese voneinander). Sichtprüfung: Kamera, Banjo-Pose, NPC flüssig.
- Nicht geprüft: Fenster mit echtem Display (nur Dumps), Bosse, Minispiele mit Intervall 3-5,
  Zwischensequenzen mit Kameraschnitten im Detail, Mehrspieler (geteilter Bildschirm).

Raster-Threads (`rdp.c` Pool): spinnen nach einem Dreieck höchstens 200 µs auf das nächste und
schlafen dann (vorher spinnten sie den ganzen Task lang; bei 4x so viel Wartezeit, 21.800 Samples,
wie Dreieckszeit). Eine feste Grenze von 4000 `yield` (~1–2 µs auf M4) war zu kurz: die Threads
schliefen zwischen zwei Dreiecken ein, mit Interpolation 25,8 → 23,3 Spielbilder/s. Mit 200 µs,
3x, 130 s Echtzeit: ohne Interpolation 27,8 Spielbilder/s (user 335 s, sys 2,7 s), mit 25,6
(user 593 s, sys 3,2 s); Systemzeit vorher 20–39 s. Render-Test-Hashes und Gate unverändert.

## 2026-11-13 — Animationen: Keyframe-Skala und Knochen-Quaternion falsch portiert (Gate-Referenzen erneuert)

Meldung: Banjo steht breitbeinig mit abgespreizten Armen, Kazooies Kopf ist beim Hacken um 90° verdreht.
Unabhängig von der Bildinterpolation (auch mit `interp=0` im Dump sichtbar).

Ursache in `animation_resource.c`, der C-Portierung des handgeschriebenen `src/core2/1EB9DB0.s`:
1. `func_800E04C0` (Kanal-Sampler) teilte Keyframes durch 128 (linear, Einzelwert) bzw. 256 (Hermite).
   Das Assembly multipliziert mit `0x3C800000` = 1/64 bzw. `0x3C000000` = 1/128 (BK `animationfile.c`:
   `unk2 / 64`). Alle Gelenkwinkel, Skalierungen und Verschiebungen waren halbiert.
2. `func_800E084C` rief `func_800D93A0` auf; das Assembly rechnet die Variante von `func_800D952C`
   (andere Rotationsreihenfolge, vertauschte Vorzeichen in x/y).

Dabei mit erledigt: `func_800137AC/F4` und die Getter `func_80013788/C4` liefen über libm mit einer
gemeinsamen Zwischenzelle (Getter lieferte je nach letzter Funktion den falschen Wert); jetzt die
bitgenaue Tabellenroutine aus `platform/handwritten.c` mit `D_8003CC90[0]` = cos, `[1]` = sin wie
`1E2B200.s`. `func_800D93A0/952C` (`quaternion.c`) nutzen sie wie `1EB2C90_asm.s`.
Gegen Assembly geprüft und unverändert korrekt: `func_800AE820` (Skelett, 3 Durchläufe), Quaternion-
Produkt `func_800D9470`, Skinning `func_80116568`, Normalen `func_801163B0`, `func_80116684`.

Prüfung: Dumps worlds (Mayahem Temple, 2x) vorher/nachher: Pose normal, Kazooie hackt mit gestrecktem
Hals. Sampler-Selbsttest (`tests/animation_resource.c`, Erwartungen an das Assembly angepasst; der
alte CMake-Test lief nicht im Gate). Alte Referenzen weichen ab Retrace 97 ab (erste animierte Figur
im Intro) — das ist der Fix, keine Regression. Alte Referenzen gesichert unter
`build/reference-pre-animfix-20261113`; neue mit `port.py gate --full --accept` aufgenommen, zweiter
Lauf PASS (2.698 / 56.943 / 10.790 / 16.544 identische Retraces), alle Fälle erreichen ihre Zielkarte.
Offen: übrige libm-Winkelhilfen in `quaternion.c` (`func_800136E4`, `80013728`, `80013970`,
`800139F8`, `80013A7C`, `80013B70/7C`) sind nicht bitgenau zur Tabelle; die anderen 11 handgeschriebenen
Asm-Module und 26 `_native.inc`-Ersatzteile sind nicht systematisch gegen das Original geprüft.

## 2026-11-14 — Absturz Karte 0x116, Asm-Audit, Original-Code statt nativer Ersatzteile

**Absturz (Map-Sweep, `bt_free`)**: `subaddierouteDll_entrypoint_1` (aus `chbadbeehive`) schreibt
Routen-Slot 11 hinter eine 10er-Tabelle. Auf dem N64 landet das in der Rundung von
`heap_alloc_sided` (`func_8001BD30`: mindestens 1 Byte, auf 16 aufgerundet). `memory.c` rundet jetzt
genauso (`n64_size`) in `heap_alloc`/`heap_realloc`; der Heap-Check-Sweep über alle Karten hat danach
0 Abstürze.

**Asm-Audit** (alle `hasm`-Module gegen ihre `.s` gelesen):
- `1E2B200`: die libm-Winkelhilfen (`func_800136E4`, `80013728`, `80013970`, `800139F8`, `80013A7C`,
  `80013B70/7C`, `80013C48`) laufen jetzt über dieselben Tabellen wie das Assembly
  (`platform/handwritten.c`), libm-Fassungen aus `quaternion.c` entfernt.
- `1E88110`/mtx: zwei fehlende Ports ergänzt (`func_80019BB8`, `func_80019D78`, `matrix.c`).
- `1EEFCA0`: zwei fehlende Ports ergänzt (`func_8011649C`, `func_801164E0`, `skinning.c`).
- Geprüft und korrekt: `inflate`, `memory`, `1EF0140` (RNG), `1ECB9F0`. `1E358F0`/`1E357D0` sind
  unbenutzt bzw. OS-Stubs; Boot und `1E5B6F0` ersetzt der native Start/das statische Linken.

**Original-Code statt nativer Ersatzteile** (Nutzerwunsch: so viel Originalcode wie möglich): rund
70 Module laufen im ILP32-Build jetzt mit dem dekompilierten Original statt mit der nativen
Neuschreibung (Kartensystem, Kollision, Gitter, Kamera, Skelett, Loader, gs-Dateien, Licht,
Splines, Props, Spielstand-Auswahl …). Mechanik: Wächter `#if defined(BT_NATIVE) && !defined(BT_ILP32)`
(native Fassung nur noch für LP64), Zeilenzahl der `src`-Dateien unverändert, N64-Build per
`make check` weiterhin byte-identisch. Werkzeuge (Scratchpad, nicht eingecheckt): `flipall.py` dreht
alle Schalter einer Datei außer `BT_DATA`, `autorevert.py` dreht Schalter zurück, deren Block einen
Compilerfehler enthält.

Neue Ein-Zeilen-Makros in `include/common.h` (IDO sieht nichts davon):
- `BT_PASS2(a, b)`, `BT_PARAM_OR_VOID(decl)`, `BT_NATIVE_ONLY(...)`: K&R-Durchreichungen. Clang
  verwirft überzählige Argumente beim Aufruf einer K&R-Definition `f()` im selben TU, FixCalls füllt
  dann die Parameter des *Aufrufers* ein (Absturz an NULL+4 in `func_800B3310`). Fix: Parameter
  explizit machen (`void func_800B38C8(BT_NATIVE_ONLY(s32 bt_a0))`).
- `BT_IDO_ONLY(...)`: Deklarationen, die nur IDO braucht (z. B. `s32 heap_realloc` lokal).
- `BT_LP64_ONLY(...)`, `BT_LP64_HEADER(h)`: native Header/Static nur im LP64-Modell.

Fehlerklassen, die erst zur Laufzeit auffallen (Kompilieren ist sauber):
1. Gemischte Grenzen: der native `ca/dbio` las `GsFile.failed`, das der Original-`gsmaker` nie
   initialisiert → Lesestrom verrutscht → Endlosschleife in `gsworldDll_entrypoint_0`. Lösung:
   `ca/dbio` und `gc/lightsDll` ebenfalls auf Original.
2. K&R-Durchreichung nach Inlining: Wächter, deren nativer Zweig nur `bt_aN`-Parameter oder einen
   Cast-Aufruf `((T (*)())f)()` ausschreibt, bleiben nativ (11 Stellen in `ch/gameselect`, `1ECE0B0`;
   sonst NULL-Spieler in `func_800F8914`, Jinjo-Häuser und Abspann stürzten ab).
3. IDO-Stacklayout: `func_801085CC` (1EE1510) kopiert bis `var_v0 == &arg0` (IDO legt den
   Heimslot direkt hinter `sp24[3]`), `func_8080021C_sulights` bis `&sp4C`. Unter clang überschreibt
   die Schleife den Rahmen → Abstürze in fremdem Code (Thread-Queue, `osSendMesg`), alle
   Ego-Schießspiele (DC, 162, 164–166). Fix auf derselben Zeile: `BT_NATIVE_ONLY(sp40 + 3)
   BT_IDO_ONLY(&sp4C)`. Gefunden per Bisektion (Datei, dann Wächter).
4. Rein additive native Blöcke (kein `#else`) ersetzen keinen Originalcode, sondern sichern UB ab.
   `flipall` hatte auch sie abgeschaltet; wieder aktiv (`#ifdef BT_NATIVE // ILP32 too: …`) sind die
   Initialisierungen und NULL-/Grenzprüfungen auf Originaldaten (`1EAF950` uninitialisiertes
   `result`, `gl/spline/Dll` Knoten nullen, `ch/bad/diesetup`, `1EE1510`, `1EDFED0`, `1EDED00`).
   Blöcke mit `native_*`-Bezug (z. B. `native_spline_context.count`) bleiben aus: der native Zustand
   wird bei Original-Code nicht mehr gepflegt.
5. Keine Fehlerklasse: Bitfelder. `bitfields.py` spiegelt sie auch in Original-Zweigen von
   `BT_ILP32`-Wächtern korrekt (am IR geprüft: Zugriff als i32, richtige Bits).

Sweep über alle Karten (Warp, 25 s Skript-Eingabe), vorher (nur Heap-Fix) → jetzt:
0 → 0 Abstürze, ok 115 → 123, statisch 19 → 17. Vier Karten enden in einem Nachbarraum statt am
Startort bzw. umgekehrt (0x102, 0x107, 0x136, 0x13A: Ladezonen am Ende der Skript-Eingabe, durch
die Original-Kamera/-Kollision leicht andere Wege). Karten 0x145–0x14E fallen nicht mehr auf 0x142
zurück, 0xDE–0xE0 sind nicht mehr statisch.

Gate: gegen die alten Referenzen weichen fast alle Bilder ab Retrace 4 ab (bitgenaue Winkeltabellen,
Original-Kamera/-Licht). Geprüft: gleiche Kartenfolge in allen Fällen, Wechsel um −63…+26 Retraces
verschoben, Kontaktbögen alt/neu (worlds, new-game) ohne Artefakte. Alte Referenzen gesichert unter
`build/reference-pre-original-20261114`, neue mit `--accept` aufgenommen, zweiter Lauf PASS
(2.698 / 56.943 / 10.790 / 16.544 identische Retraces); Selbsttests grün; `make check` OK.

Was nativ bleibt (bewusst): Plattform (`core1/1E31B40` Scheduler, `1E2C940` Framebuffer, `1E2A0E0`
DMA, `1E2B840`, `1E35920`, `1E2D890`, `1E29B60`), `core2/overlays.c` (statisches Overlay-Linken),
`gc/newoption` (Einstellungsmenü), Rest von `1EAED30` (Asset-Cache), `BT_DATA`-Blöcke, sowie kleine
ABI-Anpassungen (durchgereichte Register-Argumente, Union als Registerwert in `su/mole`) und
Hardware-Emulation (`func_800EE940`: MIPS `cvt.w.s` mit Halbwort-Speicher; `1EAAD80`: XOR mit den
MIPS-Codebytes von `func_800D1A04`). Zusammen ~630 Zeilen native Logik in `src`.

## 2026-11-14 (Nachmittag) — Schrittweises Spielen (`play.py`), Kopierschutz-Zustand, lange Sweeps

**Werkzeug `wasm/play.py` + `host/control.c` (`BT_CONTROL`, nur mit `BT_VCLOCK`):** Ein Agent spielt
Schritt für Schritt. Das Spiel hält an einer Retrace an (hält dabei die Gast-Sperre, bleibt also
deterministisch) und liest eine Befehlszeile aus dem FIFO `build/play/ctl.in`: `run N [Maske]`
(Maske wie `BT_PRESS`), `shot NAME [hi]` (PNG über sips), `peek ADDR [N]`, `poke ADDR HEX`,
`warp MAP [EXIT]`, `quit`, mehrere Befehle mit `;`. Antwort: `ready <retrace> map <hex> pos x y z`.
`play.py start --save EEP [-- BT_PRESS=... BT_WARP=...]` startet headless; ein laufendes `BT_PRESS`
gilt weiter, solange keine Befehlsmaske gesetzt ist (so lässt sich ein Sweep-Lauf bis kurz vor einen
Absturz nachspielen). 15 s Spielzeit dauern < 1 s. `bt_video_save` (video.c) ist der gemeinsame
BMP-Pfad von Dumps und `shot`.

**Kopierschutz (behoben):** Banjo-Tooie prüft Reste zweier Thread-Rahmen, die auf dem N64 nie
zurückkehren und deshalb liegen bleiben (am N64-Objekt nachgerechnet, libultra-sp = Stackende − 16):
- CIC-Thread `func_8001DE64`, Rahmen ab `D_8007DA60+0xD8`: `second` (+0xF0) = 0xAD170014 und
  `first` (+0xF4, = `D_8007DB54`) = 0xAD090010, die IPL3-Wörter aus RDRAM 0x2FE1C0/0x2FB1F4.
- Joy-Thread `func_800166DC`, Rahmen ab `D_80079D70+0x1D0`: `eeprom_type` (+0x1EC) = 2 (16K).
Leser: `gleeprom_entrypoint_0` (+0xF0 ^ 0xBD1F0416, Nester belohnen nur bei `>>24 == 0x10`),
`glreflight_entrypoint_0` (`D_8007DB54 ^ 0xACC903EE`, `gccollectDll` erwartet `& 0xFF == 0xFE`,
`sujiggy`), `gldbDll` (Flags 0x648–0x687 aus allen dreien), `func_80015D60` (Stick-Skala
`0xE955CCDD − D_8007DB54` = 1/80 nur mit dem echten Wert), `func_8001E204` (Gegner nur bei 0).
Der Port hatte alle drei Stellen auf 0. Folgen: Ei-/Feder-Nester gaben nichts, „Speichern und
Beenden“ endete mit „GAME OVER“ und leerer Datei („GAME 1: EMPTY“), der Menü-Stick war umgedreht
und übersteuert (Pausemenü: „View Totals“ nie anwählbar), Jiggywiggy-Cursor kaputt, Flags der
Raubkopie-Erkennung gesetzt. Fix (zeilenneutral, `make check` OK, beide Objekte unverändert): der
native CIC-Thread schreibt die IPL3-Wörter in seinen N64-Rahmen und startet mit `sp = D_8007DA60 +
0xD8`, der Joy-Thread legt `eeprom_type` auf +0x1EC und startet mit `sp = D_80079D70 + 0x1D0`;
native Rahmen liegen so unter den N64-Rahmen. Geprüft mit `play.py`: Pausemenü navigiert normal,
Speichern und Beenden schreibt den neuen Datensatz in den freien physischen Platz (Rotation) und die
Dateiauswahl zeigt „GAME 1: TIME 0:01:12“.

**Lange Sweeps:** 180 s je Karte statt 25 s fanden 5 Abstürze, die der kurze Sweep nicht sah:
Ego-Modus (`bsfirstp`, Karten 123/164/165/166, Zugriff weit außerhalb des Gastspeichers in `func_80809AF8`)
und Lord Woo Fak Fak (FC). Nach dem Kopierschutz-Fix laufen 123/164–166 durch. Gegenprobe: im neuen
Build die drei Kopierschutz-Wörter per `poke` auf 0 gesetzt, dann stürzt 123 wieder an derselben
Stelle ab; der Ego-Modus-Absturz ist also eine Sabotage des Kopierschutzes. FC: nach Banjos Tod (Jiggy-Übergang)
steht Licht 7 des Köders bei (7168, 0, 53), `func_8010E924` liefert für das außer Reichweite liegende
Pflichtlicht NULL, `trangler_entrypoint_0` schreibt `->value` auf 0x24. Native NULL-Prüfung auf
derselben Zeile (`tr/angler.c`); ob der N64 hier ebenso fehlschlagen würde, ist offen (Verdacht: der
gespeicherte Licht-Handle zeigt nach dem Neuladen auf ein anderes Licht).

**GPU-Prototyp neu gemessen:** ganzes Intro (2.694 Retraces) mit `BT_RENDERER=gl`: 18 Bilder über
der Toleranz, schlimmstes 0,63 % (erlaubt 0,5 %). 2.319 Bilder haben > 0,1 % abweichende Pixel; die
Abweichung sind vereinzelte Texel im Himmel (Filter-Rundung), mit bloßem Auge nicht sichtbar
(`build/gpu-intro-attempt3`). Für Spieler bringt GL erst mit höherer Auflösung etwas; das fehlt.

**Spline-Kamerafahrten schwarz (behoben):** Stomping Plains (11A) wurde schwarz, sobald der Dino-Fuß
seine Zwischensequenz startet; Jingalings Thronsaal (144) blieb im ersten Teil des Dialogs schwarz.
Projektion überall −32768, Sichtfeld `D_8012A9F0[0]` = 0xFFFFFF8E statt 40,0. Ursache:
`suspline_entrypoint_17` (`su/spline.c`) kopiert vier Kontrollpunkte in die Locals `point0..point3`
und übergibt nur `point0`; `mlspline_entrypoint_4` und `func_800F0EF0` lesen vier Punkte am Stück.
IDO legt die Locals nebeneinander, clang nicht, also las die Kamera fremde Stack-Wörter.
`bt-stackslots` sieht das nicht, weil der Zugriff in einer anderen Funktion liegt. Fix zeilenneutral:
nativ ein `f32 points[4][3]` mit Zeigern `point0..point3`. Beide Szenen spielen jetzt mit Kamerafahrt
und Letterbox (`play.py`). Ein grober Quelltext-Scan (Gruppen gleichartiger lokaler Arrays, nur eines
weitergegeben) fand sonst nur Strukturfelder. Auf dem Weg dorthin fiel ein Fehlalarm auf: Ein
Wächter auf der zuerst gefundenen Kameraadresse zeigte `inflate` beim Schreiben, das war aber die
korrekt freigegebene Kamera der vorherigen Karte (erst die Rücksprungkette prüfen, dann den Heap
verdächtigen).

**Sweep-Stand danach:** 180 s je Karte über Ausgang 1: 0 Abstürze (vorher 5), 115 ok, 91 auf anderer
Karte, 18 stehendes Bild (Zwischensequenz-, Quiz- und Standbild-Karten, dazu 11A und 144, die der
Spline-Fix behebt). 120 s über Ausgang 2: 0 Abstürze, 38 stehende Bilder, meist Minispiel-, Laden-
und Innenraum-Karten ohne diesen Eingang (Kickball zeigt die Arena ohne Banjo). Mit dem Spline-Fix
laufen D1, 10A und 11A über Ausgang 2 normal; die übrigen 10 zeigen Räume aus einer Standardkamera ohne
Banjo oder wartende Minispiele.

**Gate-Referenzen erneuert (alte in `build/reference-pre-antipiracy-20261114`):** Kopierschutz- und
Spline-Fix ändern das Verhalten absichtlich. `intro`, `new-game` und `edited-save` unterscheiden sich
nur in `flags`/`state` (Kopierschutz-Flags ab Retrace 1); Kartenfolge und alle Bildpuffer-Hashes sind
gleich. `worlds` weicht 67 Retraces nach dem Warp nach Mayahem Temple ab (Banjos Position, kamera-
relativer Stick und Spline-Einstiegskamera), danach laufen die Zufallswege anders; alle geplanten
Welten bis 0x14F werden erreicht, zwei Warps (0x128, 0x142) fielen in einen Kartenübergang und
griffen nicht. Unit-Tests 5/5, `make check` OK (nur die bekannten 511 `<data>`-Unterschiede).
`maps.h` benennt 0xCA–0xCE als `MT_KICKBALL_3`; das sind Platzhalter (0xCD liegt in Glitter Gulch Mine).

## 2026-11-14 (Abend) — GPU-Renderer `BT_RENDERER=gpu` (Fast3D-Art): 4x mit Interpolation, Orakel PASS

**Benutzung:** `BT_RENDERER=gpu BT_SCALE=4 BT_INTERP=1 build/ilp32/bt_game baserom.us.z64`. Software
bleibt Standard und Referenz (`BT_RENDERER=soft` oder ungesetzt); andere Namen brechen ab. Der alte
Prototyp (`gl`, `--probe`, `gpu_state`) ist ersetzt.

**Aufbau (`host/rdp_gl.h`, `host/rdp_glsl.h`, OpenGL 4.1 core über CGL):** Gleiche F3DEX2-HLE
(gsp.c: Transformation, Clipping, Licht, Interpolations-Matrizen) und gleicher RDP-Befehls-/TMEM-Zustand
wie die Software. An `rdp_triangle`/`rdp_texrect`/`fill_rect` übernimmt die GPU alles, was in einem
registrierten VI-Bildpuffer (RGBA16) landet; der Rest bleibt auf dem Software-Pfad in RDRAM.
- Batching: alle Ecken eines Tasks in einem VBO, Materialien (Othermode, Combiner, Farben,
  Kachel-Deskriptoren) als Datensätze in einem Texture-Buffer, Index pro Ecke. Neue Batches nur bei
  anderem Ziel, Tiefenzustand, Decal, Scissor oder rmw (s. u.): Spiral Mountain ~2.100 Dreiecke/Rechtecke
  in ~26 Draw-Calls pro Task.
- Fragment-Shader = Pixel-Pipeline aus rdp.c in Ganzzahl-Arithmetik (Texel aus dem Atlas,
  wrap/mirror/clamp, bilinear mit 8-Bit-Gewichten, LOD, 1/2-Zyklus-Combiner, Alpha-Compare/Coverage);
  der speicherlesende Teil des Blenders über Dual-Source-Blending.
- Texturcache: TMEM-Kacheln werden einmal mit `decode_texel` in einen 4096²-RGBA8UI-Atlas dekodiert,
  Schlüssel = TMEM-Inhalt (Hash je `tmem_gen`) + Deskriptor + TLUT; Regal-Allokator, Reset wenn voll.
  1–9 Uploads pro Task.
- Ziele: je VI-Puffer ein RGBA8-Bild in Skala (Breitbild: 4/3 mehr Spalten), gemeinsame Depth32F,
  Depth-Clamp, Polygon-Offset für Decals. Darstellung: `glReadPixels` des hochaufgelösten Bilds in den
  Scanout-Slot; video.c ist unverändert.
- Exakter Modus bei 1x (Orakel): jede Ausgabe rastet auf RGBA5551; Blends, die Speicher lesen (rmw),
  laufen pro Dreieck mit `glTextureBarrierNV` im Shader gegen das Ziel selbst, so runden alle
  Blend-Schritte wie in rdp.c (ohne das wichen mehrlagige Glows im Intro um 2–3 Stufen ab, 0,64 %).
- Bildinterpolation: das Zwischenbild ist ein eigenes GPU-Ziel (Startbild + eigene Tiefe); die Passes
  laufen bei der GPU im Task selbst (der GL-Kontext gehört dem Spielthread), nicht im Worker.

**Wo das Spiel Bildpuffer selbst liest oder schreibt (alle explizit, kein Sync pro Draw):**
- Ende jedes Tasks: gezeichnete Bilder werden auf N64-Auflösung gemittelt und als RGBA5551 ins RDRAM
  geschrieben (CPU-Leser, Bildschirmfotos, Pausenmenü-Hintergrund).
- Texturladen aus einem GPU-Bild (Blase `bubble.c`, Pausenmenü-Kopie `func_800C0BC0` Bildpuffer →
  Z-Speicher → Bildpuffer) löst mitten im Task einen Resolve aus.
- CPU-Schreibzugriffe in Bildpuffer (Debug-Text, `gamenew.c`) unterscheiden sich vom letzten Resolve
  und werden beim nächsten Task importiert (nur geänderte Pixel, übrige Subpixel bleiben).
- Software-Pfad zeichnet ins RDRAM (Spielerschatten als CI8-Bild im dritten Bildpuffer `0x800C26C0`,
  Pausen-Kopie in den Z-Speicher): vorher wird dort Liegendes zurückgeschrieben, überlappte GPU-Bilder
  gelten als veraltet und werden vor dem nächsten GPU-Draw importiert.
- **Tiefe:** Das Spiel liest den Z-Speicher mit der CPU (`func_8001A0C0`, Sichtbarkeitsproben in
  `core2/1EC1AD0.c`). Die GPU-Tiefe wird deshalb am Ende jedes Tasks, der Tiefe gezeichnet hat, in den
  Z-Speicher geschrieben (Subpixel wie die RDP komprimiert, gemittelt, neu komprimiert), außerdem bevor
  der Software-Pfad über den Z-Speicher zeichnet, ihn als Textur lädt oder gegen ihn testet. Letzteres
  fehlte zuerst: der Spielerschatten wird als Decal (`0x0C192E10`) gegen die Szenentiefe ins CI8-Bild
  gezeichnet und verschwand. Das Löschen der Tiefe (Fill 0xFFFC ins Z-Bild) läuft auf beiden Seiten.

**Orakel** (`frame_compare.py replay`, jede Retrace, max. 0,5 % Pixel je Bild über der Toleranz):
Standardtoleranz jetzt 9 statt 8 = eine RGBA5551-Stufe (5-Bit-Stufen werden 8 oder 9 in 8 Bit); bei 8
zählte jede 5-Bit-Stufe mit 9 als Fehler und jede mit 8 nicht. Alle Restabweichungen sind einzelne
Stufen aus float- statt Festkomma-Interpolation von Texturkoordinaten/Schattierung (verstreute Texel),
dazu einzelne Kantenpixel.
- `intro` (2.694 Retraces): PASS, schlechtestes Bild 0,056 % (bei Toleranz 8: 33 Bilder ≤ 0,74 %).
- `edited-save` bis Spiral Mountain (10.786 Retraces): PASS, schlechtestes Bild 0,088 % (vor dem
  Schatten-Fix 0,39 %: Banjos Schatten fehlte).
- Pausenmenü (worlds-Spielstand, Warp nach 0xB8, Start bei 46 s, 1x, jedes 5. Bild 45,5–49 s): GPU =
  Software bis 0,016 %. Bei 4x ist der Hintergrund N64-aufgelöst (Kopie über den Z-Speicher), HUD scharf.
- Interpolation 1x, Intro 25 s, beide mit `BT_INTERP=1` (1.495 Retraces): PASS, 0,074 %.
- Gate `port.py gate --full --exe build/ilp32-gpu/bt_game` (Software, alle vier Fälle identisch);
  Tests `render_test`, `gpu_render_test` (FB/FB2 jetzt als VI-Puffer registriert, 65.536 gleiche Bytes
  inkl. Z-Speicher), `frame_compare_test`, `trace/save/inventory/printf_test` grün. Keine Änderung unter
  `src/`/`include/`.

**Messung** (Apple M4 Pro, headless, virtuelle Uhr ungebremst, `edited-save` 180 s = 10.790 Retraces,
Intro → Dateiauswahl → Spiral Mountain; ms = Mittel je Grafik-Task inkl. Zwischenbild):

| Renderer | Wandzeit | × Echtzeit | ms/Task |
|---|---|---|---|
| gpu 4x + Interpolation | 30,6 s | 5,9 | 3,8 |
| gpu 4x | 14,1 s | 12,8 | 3,6 |
| gpu 1x (exakt, rmw pro Dreieck) | 38,8 s | 4,6 | 11,7 |
| soft 1x | 30,8 s | 5,8 | 9,3 |
| soft 4x + Interpolation | 201,8 s | 0,89 | 26,3 |

Die GPU hält 4x mit Interpolation also mit fast sechsfachem Vorrat; die Software schafft dabei keine Echtzeit.

**Lücken / nächste Schritte:**
- Kontext nur über CGL (macOS); Linux/Windows brauchen Loader + SDL/EGL-Kontext, der Rest ist reines GL.
  `build.py` linkt OpenGL immer mit.
- `RDP_MAX_SCALE` = 4 begrenzt auf 1216×912 (Breitbild 1520×912); 1440p/4K braucht eine höhere Grenze
  (statische Puffer in video.c/rdp.c sind danach bemessen).
- Bilder außerhalb der VI-Puffer (Spielerschatten-CI8, Pausen-Hintergrund) bleiben N64-aufgelöst auf dem
  Software-Pfad: der Schatten ist bei 4x blockig.
- Rauschen ist ein Pixel-Hash statt des Software-LCG; über 1x wird ein speicherlesender erster
  Blender-Zyklus übersprungen; keine Coverage/AA und kein Dithering (wie die Software).
- Tiefe, die der Software-Pfad oder die CPU schreibt, kommt nicht in die GPU-Tiefe (das Spiel löscht
  vorher); Import ergänzen, falls eine Szene dagegen zeichnet.
- 1x ist langsamer als 4x (Barriere pro rmw-Dreieck); als Orakelmodus gedacht.
- Echtzeit im Fenster nicht gemessen (nur der Vorrat headless); Übergänge und Blase nicht einzeln im
  Bild abgenommen, nur über die Korpusläufe.

## 2026-11-15 — Freie Kamera (Einstellung), Intro-Skip geprüft

- **Intro überspringen:** schon im Spiel (`ch/intro/ticker.c func_808005AC`): im Neues-Spiel-Intro
  (Karten A1–AC) springt ein B-Druck ans Ende der Kette nach Spiral Mountain (AF); getestet mit
  `play.py` (A1 → AF). Logos/Startintro (18B): Start. Tastatur B = Shift/X, Gamepad B/X.
- **Kamera „frei (rechter Stick)“** (F2-Menü, `settings.ini camera=1`, `BT_FREECAM=1`): Host-Import
  `camera_stick` = (u8)x | (u8)y << 8 (Gamepad rechter Stick analog; ohne Stick C-Links/Rechts als
  volle Drehung). Rechter Stick gibt dann keine C-Tasten mehr, Stick-Klick = C-Oben (Ego-Sicht).
  Gast (`1EE9AB0.c`, nur `BT_NATIVE`), am Ende von `func_80110588`:
  - Gierung `bt_free_camera_yaw`: dreht die Spielkamera (0x74) sofort um den Blickpunkt
    (`unk30+4`), bis 150°/s, Wandprüfung wie beim C-Dreh (`func_8011349C`), Drehfeder (`unk60+0x10`)
    auf den neuen Winkel. Die Steuerung folgt dem Bild (geprüft: Stick hoch nach Drehung läuft
    bildschirmaufwärts). `func_800A4878` überspringt die 45°-Schritte, solange gedreht wird.
  - Neigung `bt_free_camera_pitch`: nur das Bild (Kopie für `func_8010FE14`), Höhe -20°..80°, bis
    100°/s, bleibt nach Loslassen stehen. Der Versatz selbst wird auf den Höhenbereich geklemmt (kein
    Totweg beim Zurückdrücken). Linie Blickpunkt→Kamera blockiert: Bisektion auf den größten freien
    Versatz, die Kamera bleibt am Hindernis stehen statt aufs Spielbild zurückzuspringen.
    Stick hoch = Kamera tiefer (nach oben schauen). Einstellung „Kamera invertieren“
    (`camera_invert` 0..3: aus/horizontal/vertikal/beide) dreht die Achsen in `camera_stick` um.
  - Kameramodi ohne C-Dreh (fest, Zwischensequenz) bleiben unverändert, der Neigungsversatz wird dort
    zurückgesetzt. Tastatur: Pfeile links/rechts drehen, Pfeile hoch/runter neigen (geben dann kein
    C-Oben/C-Unten mehr), Ego-Sicht (C-Oben) zusätzlich immer auf Taste C.
  - Geprüft headless (vorübergehender Env-Haken für den Stick, wieder entfernt): Spiral Mountain,
    hoch → Kamera tief mit Himmel, runter → fast Draufsicht, Übergang gleichmäßig, kein Rücksprung.
  - Aus = unverändertes Spiel (Import liefert 0). Gate/Orakel nicht gelaufen.

## 2026-11-15 — GPU-Renderer: Kachelnähte über 1x (`gpu_seams`, `host/rdp_gl.h`)

Das Titellogo ist ein Raster aus Quads mit je einer geklemmten 32x32-RGBA32-Kachel (st -0,5 .. 31,5).
Der bilineare Filter erreicht an der Kante die Nachbarkachel nicht (Clamp wie auf der Hardware), das gab bei 4x
sichtbare Linien. Fix: Atlas-Einträge haben 1 Texel Rand; gefilterte Dreiecke, die eine geklemmte Kachel
von Kante zu Kante abbilden, werden pro Flush gesammelt, Kanten mit gleicher Bildschirmposition und
fortlaufender Texturkoordinate verknüpft und die Randtexel (Kanten + Ecken) per Blit aus dem Nachbarn
kopiert (unverknüpft = Kantentexel, also genau Clamp). Nur diese Draws lesen den Rand (Material-Flag),
1x bleibt exakt: Orakel `intro` PASS unverändert (0,056 %). 4x-Lauf bis Spiral Mountain, mit/ohne Fix:
einziger Unterschied das Logo. Texrects (z. B. aus Streifen gebaute 2D-Bilder) sind nicht abgedeckt.
`BT_GFX_DUMP` gibt bei `poly` jetzt auch st (Texel) aus.

## 2026-11-15 — Textglättung (GPU, ab 2x)

Schrift und HUD werden ohne Filter abgetastet; bei 4x wurde jedes Font-Texel ein harter 4×4-Block. Neue
Einstellung „Textglaettung“ (`smooth`, `BT_SMOOTH`, Standard an): Nur im GPU-Renderer und nur ab Skala 2
interpoliert `sample_tile` ungefilterte Texel mit Catmull-Rom über alpha-gewichtete Farbe
(`host/rdp_glsl.h`). Glyphen bekommen runde Striche, 3D (gefiltert) bleibt unverändert, 1x bleibt exakt.
Eine Scale2x-Eckenregel wurde zuerst probiert und verworfen: Der Font ist schattiert und kantengeglättet,
gleiche Nachbarn sind selten, die Regel änderte kaum Pixel. Geprüft am Dateiauswahl-Bildschirm bei 4x;
der Software-Renderer hat die Glättung nicht.

## 2026-11-16 — Bild direkt ins Fenster, Retrace am VSync des Displays

**Vorher:** Der GPU-Renderer las jedes fertige Bild zurück (`glReadPixels`, bei 4x Breitbild 5,5 MB), und
`video.c` lud es bei jedem Schleifendurchlauf mit `SDL_UpdateTexture` in einen zweiten Renderer (SDL/Metal)
wieder hoch. Dazu liefen zwei Uhren frei: der VI-Thread (`nanosleep`, 59,94 Hz) und der VSync des Fensters.

**Jetzt:**
- Das Fenster hat einen OpenGL-Kontext (`bt_video_window`, vor dem Spielstart auf dem Hauptthread). Die
  Kontexte des GPU-Renderers liegen in dessen Share-Group (`rdp_gpu_share`, gleiches Pixelformat).
- `gpu_publish`/`gpu_interp_end` kopieren das fertige Bild auf der GPU in eine eigene Textur (`gpu_show`,
  je VI-Puffer und je Zwischenbild eine); `rdp_frame_texture` gibt sie dem Fenster, das sie als ein Dreieck
  zeichnet. Kein Readback, kein Upload. CPU-Bilder macht der GPU-Renderer nur noch ohne Fenster und mit
  `BT_VCLOCK` (Dumps schreiben dort die Spielthreads); F12 und `BT_DUMP` mit echter Uhr lesen die Textur.
- Software-Renderer und Skala 1 aus dem RDRAM: ein Upload je Retrace statt je Schleifendurchlauf.
- Menü, Tastenhilfe und FPS zeichnet SDLs Software-Renderer in eine Surface, die nur bei Änderung
  hochgeladen und als Textur über das Bild gelegt wird. `settings.c` ist unverändert.
- **Takt** (`host/retrace.h`, `video.c retrace_clock`): Ist die Bildwiederholrate ein Vielfaches von
  59,94 Hz (±1 %: 60, 120, 240 Hz), feuert der Hauptthread die Retrace nach dem Buffer-Swap
  (`bt_vi_tick`), der Timer in `vi.c` ruht (`bt_vi_display`). Verpasste Refreshes werden nachgeholt (höchstens
  4). Andere Raten, `BT_SPEED`, `BT_VCLOCK` und Swaps, die nicht warten, bleiben beim Timer. Das Spiel läuft an
  60,00 Hz damit 0,1 % schneller; sein Audio regelt über die AI-Länge nach (`1E2A0E0.c`).
- `BT_RENDER_STATS=1` meldet zusätzlich `presents repeated` (Swaps ohne neue Retrace) und
  `retraces skipped` (Retraces, die nie ein eigenes Bild bekamen).

**Messung** (M4 Pro, internes Display 120 Hz, Fenster, GPU 4x Breitbild, `fps60=1`, worlds-Spielstand,
Warp nach Spiral Mountain 0xAF bei 36 s, 75 s, bis 2.700 Dreiecke je Task; alte Version aus denselben
Objekten mit den alten `video.c`/`vi.c`/`rdp.c`/`main.c` gelinkt):

| | Bildwechsel/s (5-s-Fenster) | übersprungene Retraces in 75 s |
|---|---|---|
| alt | 55,8–60,0 | 41 |
| neu | 58,8–60,0, meist 60,0 | 1 (im ersten Fenster) |

**Prüfung:** `render_test` (neu: `tests/retrace.c`, Takt bei 60/120 Hz, verpasste Refreshes, andere Raten),
`gpu_render_test` (65.536 gleiche Bytes), `port.py gate` intro 2.698 Retraces identisch. Fensterfotos:
GPU 4x, GPU 4x mit Interpolation, Software 2x; Dump aus der Textur (echte Uhr) und mit `BT_VCLOCK`.
Die Test-Stubs in `tests/renderer.c` und `tests/keyboard.c` waren seit dem 15.11. veraltet (freie Kamera,
Textglättung, Completion-Thread) und sind ergänzt.

**Offen:**
- Nicht gemessen: externes 4K-Display mit 60 Hz und Vollbild (dort war der alte Weg am langsamsten),
  Menü per F2 im neuen Overlay (nur die FPS-Anzeige gesehen, gleicher Zeichenweg), `gate --full`.
- Das Fenster wartet nicht auf einen Fence der Kopie (Kommentar bei `gpu_publish`).
- `video.c` nutzt wie `rdp_gl.h` die macOS-GL-Header und CGL; Linux/Windows brauchen einen Loader und
  geteilte SDL-Kontexte.
- Die Resolves je Task (Farbe, Tiefe ins RDRAM) und der Uber-Shader sind unverändert: nächster Hebel.

## 2026-11-17 — SoH-Fahrplan P0: Ausgangsstand und Abnahme

Start auf `native-port`, HEAD `69c622e01`: 1.222 Status-Einträge (1.164 Änderungen,
58 untracked Einträge). Dateiprüfsummen und Status vor der Arbeit liegen in
`build/acceptance/p0-2026-11-17/initial-*`; der Nutzerspielstand wurde nicht verwendet.
`bt_eeprom.bin` wird jetzt ignoriert. Der untracked Gradle-Cache in `tools/fmt` ist lokales
Build-Material und gehört nicht zum Checkpoint.

Arbeitslisten unverändert: traps 9, xsym 348, data 114, calls 0, offsets 4.774,
offsets64 208, protos 4.217, lp64 1.041. Noch keine N1–N3-Migration dieser Sitzung.

**Port-Abnahme:** `port.py gate --full` PASS, alle Referenzen unverändert:
intro 2.698, new-game 56.943, edited-save 10.790, worlds 16.544 identische Retraces.
Alle vier Fälle erreichen ihre erwartete Endkarte. Fünf Testgruppen grün;
zusätzlich `gpu_render_test.py` 65.536 identische Bytes, `frame_compare_test.py` grün
und 204 Harness-Tests grün. Details/Hashes: `build/acceptance/p0-2026-11-17/validation.json`.

**N64:** Original-IDO mit unveränderten Makefile-Flags, `make check` OK.
Alle 35.098.224 Bytes des dekomprimierten ROMs stimmen überein
(SHA-256 `8c9d316b2edca686ec8393ddf95d480a7dfd9879ef434dbcfc4ea3000f2ffe89`).
Das komprimierte ROM stimmt bis zu seinem Ende byteweise; mit 112.032 abschließenden
`0xFF`-Padding-Bytes ist es identisch zum vollständigen 32-MiB-Original.

Der bisherige `offsets.py check` meldete irreführend „511 Funktionen“: tatsächlich
498 geänderte Objekt-Datensektionen und 13 Funktionen mit Daten-Relocations auf
zusammengefasste Labels (z. B. `D_80801000_chbounce` → `D_80800FE0_chbounce + 0x20`).
`n64_objdiff.py --linked` prüft diese gegen Adressen und Instruktionsbytes im gelinkten
ELF; fehlende/neue Funktionen bleiben Fehler. `offsets.py check` verwendet diesen Modus,
bewahrt die vollständige Differenzliste neben dem Build-Log und bricht bei Fehlern des
Vergleichswerkzeugs ab. Objekt-Datenzuordnung wird separat gezählt; nur ein bytegleiches
ROM kann trotzdem bestehen. Sechs Regressionstests in `tests/n64_check_test.py` prüfen
u. a. echte Codeänderungen, fehlende Funktionen und Werkzeugfehler.

`ripwire --quality-delta` meldet 34 ältere größere Verschlechterungen gegenüber HEAD;
die vorhandenen Quelländerungen enthalten auch Whitespace-Warnungen. Sie werden beim
Sichern nicht kosmetisch umgeschrieben. Das Port-Gate ist kein Emulatorvergleich.

## 2026-11-17 — A1: Werkzeugsuche und getrennte Build-Stufen

`build.py [all|guest|host]` sucht Werkzeuge über `BT_LLVM_BIN`/`BT_WABT`, `PATH`
und macOS-Homebrew-Fallbacks. SDL3 kommt aus `BT_SDL3`, `pkg-config` oder den
Systempfaden. Plattformabhängige Link-Flags und Plugin-Endungen sind getrennt;
clang < 19 wird vor dem Build wegen `#embed` abgewiesen. Anleitung:
`pc/native/wasm/README.md` (die alte native README ist als historischer Versuch markiert).

Die Host-Stufe benötigt nur die vollständige `gen/`-Übergabe und Host-Abhängigkeiten.
Auch die zwei bisher aus `assets/` eingebetteten Audio-Dateien werden im Gast-Schritt
nach `gen/` kopiert und via `--embed-dir` gefunden. Sie bleiben private Build-Artefakte.
Trace-Build-IDs berücksichtigen auch bei reinem Host-Build die generierten Dateien,
Host-Quellen und Compiler/Flags, ohne einen Gast-Linkerplan vorauszusetzen.

Gast-/Host-Objekte werden nach Compiler, Version und Flags getrennt; der Plugin-Stamp
berücksichtigt die LLVM-Konfiguration. `BT_HOST_FLAGS` erlaubt z. B. Sanitizer ohne
alte Host-Objekte wiederzuverwenden. Der Dependency-Parser versteht jetzt die
escaped Leerzeichen dieses Projektpfads und Windows-Laufwerkspräfixe.

**Abnahme:** Gast-Stufe: 1.109/1.109 Spieldateien, 45 native/Runtime-Dateien, 9 Traps,
0 fehlende Datensymbole. Ein frisches `host-only/` enthielt ausschließlich `gen/`;
Toolpfad nur Clang, WABT-Präfix nur C-Runtime (kein `bin/wasm2c`), kein `game.map`,
`game.wasm`, Pass-Plugin oder Gast-Objektbaum. Host-Build und Intro-Gate PASS
(2.698 identische Retraces). Endgültiger Standard-Build: `gate --full` PASS,
sechs Testgruppen und alle 86.975 Retraces identisch. `build_test.py`: sechs Tests,
zusätzlich drei Trace-Tests. `ripwire --quality-delta` ohne größere Verschlechterung,
`git diff --check` sauber. Artefakte: `build/acceptance/a1-2026-11-17/`, maßgeblicher
voller Lauf `gate-acceptance.log`.

Keine Spielquellen/Headers geändert; N64-Abnahme bleibt der bytegleiche P0-Stand.
Windows-Plugin-Ausführung wurde hier nicht getestet: LLVM unterstützt konfigurierbare
Plugin-Symbolexporte, die konkrete Windows-Distribution muss A3 prüfen. Der getrennte
Host-Schritt ist unabhängig davon benutzbar. CGL im Host bleibt bis A2 bestehen.

## 2026-11-17 — Dialogsprachen aus der EU-ROM (Deutsch, Französisch, Spanisch)

- Einstellung „Sprache“ (`settings.ini language=`, `BT_LANG=0..3`: Englisch, Französisch,
  Deutsch, Spanisch; wirkt nach Neustart). Bei Sprache ≠ 0 lädt `io.c rom_add_language` die
  europäische ROM (`NB7P`, En/Fr/De/Es): `BT_PAL_ROM`, sonst `baserom.eu.z64` im
  Arbeitsverzeichnis oder im Benutzerordner, sonst Dateidialog (Kopie in den Benutzerordner).
  Ohne EU-ROM bleibt es Englisch.
- Die EU-Asset-Tabelle (ROM 0x5140) hat dieselben 0x3667 Einträge wie US (0x5180). Nur
  Dialog-Assets (Typ 3, komprimiert, entpackt `01 03 00` in US, `04 …` in EU; 2251 Stück) tragen
  Text. Der Host baut eine Kopie der US-Asset-Region mit diesen EU-Dialogen hinter das 32-MB-Image.
  `func_800D5D70` verschiebt `D_8011B900`/`D_8012B448` nativ um `bt_asset_shift()`, und
  `gldialog_entrypoint_0` (US: immer 0) gibt `bt_language()` zurück. Andere EU-Unterschiede
  (Texturen, Level-Setups, Modelle) bleiben US.
- Die US-Schrift kann die Umlaute schon (geprüft: „DRÜCKE“, „KÖRPER“ in Dateiauswahl und Intro).
  Nicht geprüft: Menütexte außerhalb der Dialog-Assets, Texturen mit Schrift, Französisch und
  Spanisch.
- `BT_LANG` zählt in die `BT_PRESS`-Identität des Trace-Kopfs. Ohne `BT_LANG` gibt es keine
  Verschiebung: Gate intro 2698 und edited-save 10.790 Retraces identisch. IDO-Objekte von
  `1EAED30.c` und `gl/dialog.c` sind vorher/nachher gleich (Docker, objdump mit Relokationen).

## Bekannte Fehler (P0.2, frische Nachweise vom 2026-11-17)

Alle folgenden Repros verwenden ein frisch erzeugtes EEPROM (2.048 Bytes), Flags
`0x392..0x39A` plus `save_editor.START_ABILITIES`, `BT_VCLOCK=1`, Software-Renderer,
`sweep.press(34, Dauer)` und Warp bei Sekunde 34. Dauer ist die **gesamte** virtuelle
Laufzeit einschließlich Boot. Befehle, Binary-/Save-Hashes, Trace und Bilder je Fall:
`build/acceptance/p0-2026-11-17/repro/<Fall>/`; Skript `run_repros.py` im selben Ordner.
Alle zehn Prozesse wurden beendet, Exit-Code jeweils 0. Kein Nutzersave wurde angefasst.

| Befund | Karte / Eingang / Dauer | Nachweis und verbleibende Arbeit |
|---|---|---|
| Lord Woo Fak Fak: NULL-Licht nach Tod/Jiggy-Übergang | FC / 1 / 180 s | `fc-exit1/at40.png`, `end.png`: Bossraum läuft. Historischer Absturz in `build/sweep-crash5/summary.json`; der relevante Todes-/Neuladeübergang wurde diesmal nicht erreicht. NULL-Schutz vorhanden, Ursache/N64-Vergleich offen. |
| Grünes Rechteck nach Sprung | Historische Karte unbekannt; Probe AF / 1 / 60 s | `af-jumps-exit1/end.png`: kein Rechteck. Zwischenbild bei 40 s schwarz während Kartenwechsel AF/AE. Zwei Bilder können den seltenen Fehler nicht ausschließen; historischer Save/Input fehlt. |
| 18 statische Karten nach Warp | Ausgang 1 | Alte Liste: A2, A3, A4, A5, A6, A7, A9, AA, AB, AC, 11A, 144, 159, 15F, 167, 168, 169, 189 (`build/sweep-long-20261114/summary.json`). Frische 60-s-Proben `11a-exit1` und `144-exit1` zeigen bewegte Szene/Dialog und bestätigen den Spline-Fix. Andere Fälle brauchen natürliche Einstiege; der Warp allein belegt keinen Spielfehler. |
| Kickball-Arena ohne Banjo | C6 / 2 / 120 s | `c6-exit2/at40.png` und `end.png`: gleiche Arena auf schwarzem Hintergrund, kein Banjo. Nach Debug-Warp reproduziert; natürlicher Spieleinstieg noch zu prüfen. |
| Falsche Platzhalternamen in `maps.h` | CA–CE / 1 / je 50 s | `ca-exit1` bis `ce-exit1`: fünf verschiedene Innen-/Wasserräume, keine Kickball-Arena. CA blendet „FUEL DEPOT“ ein, CD „WATER STORAGE“. Namen erst nach Abgleich mit Karten-/Abschnittsdaten ändern. |

Zusätzlicher Werkzeugbefund: Der Trace-Header meldet bei `BT_SAVE=<Kopie>` noch
EEPROM-Hash `0000000000000000`, obwohl Engine-Log und kopierte Save-Datei stimmen.
Für Q2 die Trace-Metadaten auf den tatsächlich geladenen Save beziehen; aktuelle
Repro-Logs enthalten daher zusätzlich den SHA-256 des synthetischen Ausgangsstands.

## 2026-11-17 — Q1: Bildbögen und isolierte Spielsteuerung

Agententeil fertig, menschliche Abnahme ausdrücklich vorläufig offen gelassen.
`build/acceptance/q1-2026-11-17/summary-ego60.json` verzeichnet 14 Karten:
AF, 152, B8, C7, D6, 1A7, 112, 100, 127, 128, 136, 15D, 142 und 14F.
Jeder Bogen zeigt den Startpunkt nach zehn Spielsekunden, das Pause-Menü und
die Ego-Sicht. Alle drei Ansichten wurden visuell geprüft. Die vier zunächst
fehlenden Pause-Menüs auf D6, 112, 127 und 128 wurden mit länger gehaltenem Start
in frischen Läufen nachgeholt; das Manifest zeigt auf `sheet-corrected.png` und
die zugehörigen `*-pausefix`-Aufnahmen. Alte Belege sind erhalten.

Alle Läufe verwenden dasselbe eingefrorene P0-Programm und einen synthetischen
2048-Byte-Spielstand aus `save_editor.py`/den `worlds`-Flags. Karten-IDs,
Eingaben, Zeiten und SHA-256-Werte stehen im Manifest; alle referenzierten
Bild-, Blatt- und Tracepfade sowie Prüfsummen wurden maschinell verifiziert.
Alle Spielprozesse sind beendet. Das belegt die Port-Aufnahmen, keinen
Vergleich mit ares oder N64-Hardware und kein Durchspielen.

`play.py start --exe FILE --dir NEW_DIR` hält Programm und Laufverzeichnis
fest. `play.py --dir DIR COMMAND` richtet Folgebefehle einschließlich `stop`
an dieselbe Session. Bestehende Zielordner und ungültige Optionen werden
abgewiesen; bisherige Aufrufe bleiben gültig. Neun ROM-freie Tests prüfen
Argumente, Pfade, Save-Kopie und Prozessstart; `play_test.py` gehört nun zum Gate.

## 2026-11-17 — Q2, Referenzen und Spielstände

Spiel und Trace lösen den EEPROM-Pfad über dieselbe Funktion auf. Eine
Spielprobe mit zwei unterschiedlichen synthetischen EEPROMs meldet im
Trace-Kopf den FNV-Hash `a5b850efc0f5877c` des mit `BT_SAVE` gewählten
Spielstands. Sie schließt den unter P0.2 protokollierten Werkzeugfehler.
Nachweis unter `build/acceptance/q2-gate-2026-11-17/selected-save/`.

`port.py gate --full` liest die Fälle aus `corpus.CASES`. Fehlende
Referenzen führen zum Fehler. Mit ausdrücklichem `--accept` prüft das Gate
alle angeforderten Läufe auf Traceschema, Endkarte und Spieldauer, bevor es
die jeweilige Referenz atomar ersetzt. Korpus und Gate benutzen denselben
Recorder mit eigenem Laufverzeichnis und explizitem Spielstandpfad.
Der Regressionstest prüft fehlende Referenz, Annahme, falsche Karte und
vorzeitiges Ende. Das volle Gate bestand mit acht Testprogrammen und 86.975
identischen Retraces. Alle vier Referenzen haben weiterhin die P0-Prüfsummen.
Laufprotokoll unter `build/acceptance/q2-gate-2026-11-17/gate-final.log`.

## 2026-11-17 — A2, SDL-OpenGL auf macOS

Fenster-, Spiel- und Completion-Kontexte werden vor den Spielthreads über
SDL3 angelegt. Jeder Renderer-Thread aktiviert seinen geteilten Kontext
selbst. Headless-GPU-Läufe erhalten ein verborgenes Fenster. Der eingecheckte
glad-2-Lader unterstützt OpenGL 4.1 core und beide Texture-Barrier-Erweiterungen.
Fehlt die Barriere, verwendet der exakte 1×-Modus den Software-Renderer.

Auf dem M4 Pro lief der GPU-Fixturetest mit 65.536 identischen Bytes durch,
einschließlich eigener Prüfungen des Fallbacks und unbekannter Backends.
Der vollständige Intro-Bildvergleich am endgültigen Releaseprogramm ergab
2.694 Bilder ohne fehlgeschlagenes Bild, schlechtestes Bild 0,056267 %
bei 0,5 % erlaubter Abweichung. Belege in
`build/acceptance/a2-2026-11-17/intro-release/summary.json` und
`gpu-render-test-final.log` im übergeordneten Ordner.

**Die Leistungsabnahme bleibt offen.** In der 75-s-Messung am internen
120-Hz-Display (GPU 4×, 16:9, 60 FPS, Warp nach AF bei 36 s) lagen die
anfänglichen Auslassungen bei 5–6, auch der alte CGL-Build zeigte 6.
Die Audioöffnung dauerte in einer Zeitmessung 66 ms. Ein Vorziehen allein
ergab im normalen Release noch 2 Auslassungen beim Start. Zusätzlich benötigte
die erste SDL-Ereignisabfrage 25–36 ms. Beide Schritte laufen nun vor dem
VI-Timer. Vier abschließende Messungen meldeten jeweils 2 ausgelassene
Retraces. Die letzte ergab 0 beim Start, 2 zwischen 35 und 40 s und 0 im
Restfenster. Der Grenzwert liegt bei 1. Alle neun Messungen mit Binärhash
und getrennten Fensterwerten stehen in
`build/acceptance/a2-2026-11-17/startup/results.tsv`.

## 2026-11-17 — Q2, zwanzig Kartenaufnahmen im regulären Korpus

Je ein Eingang und ein Innenraum der acht Hauptwelten sowie der Isle o' Hags
und von Cauldron Keep haben einen eigenen Fall mit synthetischem EEPROM,
Eingabe, Warp bei 34 s, erwarteter Endkarte und Ende bei 44 s. Die ersten
40 interaktiven Läufe endeten auf der Sollkarte. Alle 20 Bildpaare wurden
gesichtet. Sie belegen die Szenen nach einem Warp. Natürliche Übergänge von
der Nachbarkarte, Bosskämpfe und Verwandlungen erfordern eigene Eingaben.

Im regulären Korpus lief jede Szene nochmals zweimal. Beide Läufe hatten
jeweils identische 2.638 Retraces und zwei identische Bilddateien. Die
letzten Bilder bei Retrace 2.636 wurden gesichtet. Nach Sicherung der vier
P0-Referenzen entstanden ausschließlich die 20 neuen Referenzen. Jede
stimmt byteweise mit dem gesichteten Wiederholungslauf überein. Das
anschließende volle Gate mit dem eingefrorenen Programm bestand alle
24 Fälle (139.735 Retraces). Die ursprünglichen vier Referenzen blieben
bytegleich. Läufe, Bilder, Sicherung und Prüfprotokolle liegen unter
`build/acceptance/q2-worlds-2026-11-17/`. Die Liste der 206 unbesuchten
benannten Karten im dortigen Teilkorpus bezieht sich nur auf die 20 neuen
Fälle. Die übrigen Q2-Szenarien sind offen.

## 2026-11-17 — Q3, zwei Fehler im instrumentierten Host

Der ASan-/UBSan-Host stoppte zuerst beim Start von `func_800124EC`.
Die wasm2c-Funktion erwartet neben der Instanz drei Registerwerte. Der Host
rief sie über einen Zeiger für ein Argument auf. Der Threadstart wählt jetzt
die tatsächliche Wasm-Signatur. Für die beiden mit `BT_PASS2` erweiterten
Einstiege liest er die unteren Wörter von `OSThread.context.a1` und `.a2`.
Zwei statische Prüfungen sichern die Offsets 0x44 und 0x4c im ILP32-Layout.

Beim nächsten Lauf meldete UBSan einen Links-Shift des negativen
RSP-Branch-Offsets −320. Der Interpreter berechnet den Versatz jetzt mit
vorzeichenloser Arithmetik. Die Ausgabe von `new-game` war vor und nach
dieser Änderung über 83.772.256 PCM-Bytes identisch (SHA-256
`a2afd2121432f0d92701cc49f654a378b0d1efac3a0dfa133602a3d886ad08ac`).
Der isolierte Build mit genau diesen beiden Korrekturen bestand das volle
Gate mit 24 Fällen und 139.735 identischen Retraces. Nachweise unter
`build/acceptance/q3-2026-11-17/` in den ersten beiden
`sanitizer-corpus*`-Laufprotokollen und `staged-gate-24.log`.

## 2026-11-17 — A8, nativer C-Mixer und Audiovergleich

Der Release-Host mischt n_audio in C. Er lädt die Koeffizienten aus der US-ROM
des Spielers. Der Debug-Build (`BT_AUDIO_DEBUG=1`) lädt zusätzlich die
RSP-Instruktionen aus der ROM und unterstützt `BT_AUDIO=rsp` sowie
`BT_AUDIO_CHECK=1`. Nach jedem Befehl prüft das Orakel alle 4.096 Bytes DMEM
und Adresse, Länge und Inhalt des Schreibzugriffs ins RDRAM. Der Release-Build
enthält den Interpreter und die eingebetteten Audio-Binärdateien nicht mehr.

Der Vergleich bestand alle 24 registrierten Fälle mit 69.820 Audio-Tasks und
27.429.644 Befehlen. Mit fünf separat geprüften Bossbegegnungen waren es
81.083 Tasks und 31.825.785 Befehle. MP3-Opcode 7 trat dabei keinmal auf und
bleibt ausdrücklich unimplementiert. Synthetische Eingaben prüfen auch die
Pole- und IIR-Filter. Bei `new-game` lieferten Release-Mixer und Debug-RSP
je 83.772.256 bytegleiche PCM-Bytes (SHA-256
`a2afd2121432f0d92701cc49f654a378b0d1efac3a0dfa133602a3d886ad08ac`).

Der Audiopuffer im Einstellungsmenü unterstützt 512, 1.024, 2.048 und 4.096
Stereo-Samples. Die gemessene sichtbare Warteschlange passte bei jeder
Einstellung zur gewählten Reserve. Unter `build/acceptance/a8-2026-11-17/`
liegen die Gates der beiden Binärdateien, der Opcode-Zensus, der PCM-Vergleich
und die Messung mit SDL.

## 2026-11-17 — Q2, fünf wiederholbare Bossbegegnungen

Targitzan (0x17A), Old King Coal (0xD1), Mr. Patch (0xF9) und Terry (0x113)
laufen jeweils 64 Spielsekunden. Lord Woo Fak Fak (0xFC) braucht 120 Sekunden,
damit nach seinem Dialog auch der Kampf im Bild ist. In jedem Fall zeigen
zwei unabhängige Starts denselben vollständigen Trace und identische Bilder.
Die fünf neuen Referenzen entsprechen den gesichteten regulären Läufen. Die
24 bisherigen Referenzen wurden vorher gesichert und bleiben bytegleich.
Das volle Gate bestand neun Testprogramme und 29 Fälle mit insgesamt
162.276 identischen Retraces. Das Debug-Audio bestand alle fünf zusätzlichen
Fälle. Bildbogen, Einzelfälle,
Sicherung und Prüfprotokolle stehen unter `build/acceptance/q2-bosses-2026-11-17/`.

Weldar blieb bei zwei Einstiegen hinter Wand bzw. Decke. Bei den beiden
Hailfire-Drachen löste der Warp in den Stationsraum den Kampf nicht aus.
Bei Mingy Jongo fehlt die sichere Identifikation des sichtbaren Actors. Für
Hag 1 fehlt eine geprüfte Eingabefolge. Diese Begegnungen sind offen.

Kickball, Saucer of Peril und das Rennen in Cloud Cuckooland zeigten jeweils
die Karte, aber keinen bestätigten Spielstart. In der Ordnance Range erschien
das Ego-HUD mit null Eiern. Die Bilder mit und ohne Feuertaste waren
pixelgleich. Zwei Versuche mit Wumbas Bezahlflag zeigten Banjo bzw. den
Dialog in ihrer Hütte. Eine steuerbare verwandelte Figur ist offen. Die
Belege liegen unter `build/acceptance/q2-minigames-2026-11-17/` und
`build/acceptance/q2-transform-mp-2026-11-17/`.

## 2026-11-17 — Q5, Originalcode für Zonen unter ILP32

Die Präprozessorprüfung aller 1.109 Spielquellen zeigt, dass keiner der 27
`*_native.inc`-Ersatztexte unter ILP32 ausgewählt wird. In
`glzone_entrypoint_2` läuft jetzt auch die originale Löschschleife. Der
IR-Vergleich fand ausschließlich die in `wasm/reference-ir/accepted.txt`
beschriebene Adressrechnung. Original-IDO, Funktionsvergleich und das
vollständige Cartridge-ROM stimmen. Alle 29 Referenzen passen.

Der Sweep lief mit 180 Spielsekunden pro Warp über 229 benannte Karten.
123 blieben in der Zielkarte, 87 wechselten die Karte, 14 blieben zuletzt
im selben Bild. Fünf bekannte ungültige Warps endeten wie erwartet.
Kein neuer Absturz, Hänger oder Aufruf einer unportierten Funktion.
Protokolle und Zuordnung der Guards liegen in
`build/acceptance/q5-inventory-2026-11-17/`. Weitere aktive
`BT_NATIVE`-Zweige und die ABI-Sonderfälle werden einzeln geprüft.

Die menschlichen Abnahmen Q1 und Q4, die externe 4K/60-Hz-Messung für
A7 und die Wunschliste A10 sind auf Nutzerwunsch vorläufig offen.

## 2026-11-17 — N1, zwei Datenmodule und ein strikter Build

Der Distanzvektor von `ca/dbmgrDll` sowie die vier Kletterparameter und
zwei Actor-Deskriptoren von `ch/climbbase` liegen jetzt in C. Beide
Spielquelldateien behalten ihre ursprüngliche Zeilenzahl. Die IDO-Prüfung
bestätigt alle Funktionen sowie Daten und Relokationen beider Module.
Das dekomprimierte ROM stimmt in allen 35.098.224 Bytes. Mit den 112.032
originalen Füllbytes stimmt auch das vollständige Cartridge-ROM.
Der Port verwendet jetzt 1.216 Assemblerdateien und 2.425 Symbole
(vorher 1.218 und 2.430). Die neun Testprogramme und 29 Referenzen
mit 162.276 Retraces bestehen.

`BT_NO_ASMDATA=1 python3 pc/native/wasm/build.py guest` meldet die
2.375 noch aus Assembler stammenden Dateneinträge einzeln in
`remaining_asm_data.tsv` im Build-Verzeichnis. Der aktuelle Scanner
führt 113 weitere `.data`-Module auf. Die Diagnose über alle 29 Fälle
beobachtete erstmals 1.711 von 6.100 instrumentierten Zugriffsstellen
in 413 Funktionen. Fünf Stellen trafen je nach Fall verschiedene
Zielsymbole. Der Bericht erfasst alle 1.716 beobachteten Kombinationen.
Prüfprotokolle liegen unter `build/acceptance/n1-2026-11-17/` und
`build/acceptance/q2-xsym-2026-11-17/`.

## 2026-11-17 — A5, Menü und Eingabe

F2 oder Back am Controller öffnet das Dear-ImGui-Menü. Grafik, Audio,
Eingabe, Spiel und Entwicklerwerkzeuge sind im GPU- und im Softwarefenster
bedienbar. Ein Fenstertest auf Controllerport 2 band Y an A und H an B.
Während der Eingabe im Menü erhielt der Gast keine Tastendrücke. Nach dem
Schließen lieferte Y die erwartete A-Maske 0x8000. Lautstärke und
Tastenbelegung überstanden den Neustart. Der separate Einstellungs-Test
prüfte alle 17 Werte, ältere Tastaturnamen und unbekannte Einträge.

Die fünf Menüseiten wurden in beiden Renderern mit 1.920 × 1.440 Pixeln
aufgenommen. Die ursprünglichen 29 Spieltraces bestehen auch im integrierten
Build. Belege und Aufnahmen stehen in `build/acceptance/a5-2026-11-17/`.

## 2026-11-17 — N2, Aufrufsignaturen und abschaltbare LLVM-Pässe

`BT_PASS_OFF` schaltet einzelne Pässe im separaten `BT_OUT` ab. Auch
ohne `bt-fixcalls` löst der Linker die Cartridge-Symbole und positioniert
die C-Daten. Der reguläre Build schreibt die zwölf von `bt-stackslots`
vergrößerten Stackbereiche mit Funktion und Bytebereich nach
`build/ilp32/stackslots.txt`. Ohne diesen Pass scheitern die 29 bisherigen
Fälle bereits beim Start.

Die beiden Audio-Weiterleitungen für `func_80021A00` und `func_80021AD0`
sowie die Aufrufer von `chnests_entrypoint_13` und
`gcsectionDll_entrypoint_4` verwenden unter ILP32 die tatsächliche Signatur.
Beim Übergang zu einem vorzeichenbehafteten 32-Bit-Ergebnis bleibt die
bisherige Erweiterung des unteren Bytes erhalten. Der vollständige
IR-Vergleich mit dem Stand vor diesen Änderungen ergab null abweichende
Funktionen. Im Diagnose-Binary ohne Signaturreparatur sank die Zahl der
ungültigen Aufrufvarianten von 163 auf 150 (143 bzw. 130 verschiedene
Ziele). Der Intro-Lauf erreicht jetzt den Hänger eines Gastthreads auf
Priorität 20. Die Aufrufreparatur bleibt im regulären Build aktiv.

Das reguläre Gate bestand neun Testprogramme und alle 162.276 Retraces.
Ein frisch aus HEAD gebauter Original-IDO-Vergleich ergab null Unterschiede
bei Funktionen und Objektdaten. Die dekomprimierte ROM und das vollständige
Cartridge-Abbild stimmen byteweise. Belege liegen in
`build/acceptance/n2-2026-11-17/`, darunter `sections-validation.json`,
`sections-ir.log` und `sections-full-gate.log`.
