# Native PC port – progress log

Goal: Banjo-Tooie compiled from the decomp C sources (`BT_NATIVE`) as a native
PC executable that boots and is playable. No N64Recomp, no emulation of MIPS code
(decision 2026-11-05). The N64 build in `src/` must stay byte-identical
(`make check` in the Docker image `banjo-tooie-decomp:local`).

Technical details of finished modules: [README.md](README.md).

## Milestones

| # | Milestone | Status |
|---|-----------|--------|
| M0 | Native core library + 53 module tests (Codex, up to 2026-11-05) | done |
| M1 | Every game C file compiles natively (strict pointer flags) | 352 / 1,114 (2026-11-05) |
| M2 | Game executable links: all code + data, missing pieces trap with their name | links with traps (2026-11-05) |
| M3 | Platform layer: main, threads/messages/timers (libultra on host), ROM/asset I/O, boot runs to the game loop | in progress |
| M4 | Renderer: F3DEX2 display-list interpreter + SDL window → first visible frame | – |
| M5 | Input (SDL controller), saves (EEPROM), audio (n_audio command lists) | – |
| M6 | Gameplay verification: title, file select, Spiral Mountain, level transitions | – |

## Working method

- Demand-driven: the game executable links everything that compiles; every
  still-missing function becomes a generated trap that prints its name and
  aborts. Run, port the function that trapped, repeat. Traps are diagnostics,
  never fake behaviour.
- Full-source audit: `pc/native/audit.py` (one log per file) gives the M1 count.
- N64 match check after every source change in `src/` or `include/`.

## Log

### 2026-11-05
- Baseline: native core builds, 53/53 tests pass; N64 `make check` OK.
- Full-source audit: 762 of 1,114 files fail. Largest error classes: pointer↔s32
  casts (~2,700), undeclared functions (1,026), pointer/int argument mismatches
  (~1,100). 3,048 raw-offset struct accesses (`(u8 *)p + 0x74`) in 308 files need
  typed fields for 64-bit hosts.
- Data: 1,710 splat-generated `asm/data` files (808 data segments) still hold
  game data; these need conversion to typed C for the native link.
- `bt_native_game` (target, built by `pc/native/link_game.py`): all files that
  compile plus generated traps: 975 functions, 94 zeroed .bss symbols, 528
  page-protected data symbols. Run: `build/native/native/bt_native_game baserom.us.z64`.
- Platform layer in `pc/native/platform/`: `ultra_os.c` (threads on pthreads with a
  single-CPU token, priorities, message queues, events, timers, interrupt mask),
  `ultra_vi.c` (60 Hz retrace thread, framebuffer swap), `ultra_pi.c` (ROM DMA
  from the .z64), `rdram.c` (game heap arena inside the executable; physical
  address = 0x80000000 + image offset, shared with the graphics registry),
  `traps.c`, `handwritten.c` (C versions of handwritten asm).
- `native_prototypes.h` is force-included: host signatures that differ from the
  N64 (pointer returns) make stale caller declarations fail to compile.
- Boot ported: core1 entry (no BSS clear, no core2 load), CIC thread (pure C
  CIC-6105), CRC tamper check (disabled: it hashes N64 machine code), ROM DMA
  helpers, VI/framebuffer module. Audio synthesizer and audio thread are not
  started yet (queues only).
- Boot reaches `func_8001D1E0` (next unported function).
