# Practical integration evidence — 2026-10-07

Environment: macOS arm64, Python 3.14.7, SQLite 3.53.4, Codex CLI 0.161.0,
Linux/amd64 Docker build with the repository's IDO 5.3 toolchain.

* The provided `Banjo-Tooie (USA).n64` is byte-swapped. Its normalized SHA-1 is
  `af1a89e12b638b8d82cc4c085c8e01d4cba03fb3`, matching the repository README.
  The source ROM and ZIP were preserved. `baserom.us.z64` was created locally.
* Original `make setup` and full `make -j4 check` succeeded. The decompressed
  reference SHA-1 is `af479771ff5e91ce3732f3d84146614ab71d8d79`, matching Splat.
* Initial scanner inventory: **13,398 functions and 151 data imports**. The latter
  are recorded as skipped, not sent to a function-decompilation worker.
* Both `gpt-6.1-sol` and `gpt-6-astra` returned `OK` in separate real, minimal
  `codex exec` probes using stored ChatGPT authentication. No API key was used.
* `doctor` passed Python, SQLite, Git, both ROM hashes, auth/version/help, build
  dependencies, compiler tools, diff tooling, full baseline build and both models.
  No local Banjo-Kazooie reference was configured; local BK lookup is fixture-tested.
* One real function was attempted: `src/core1/1E36310.c::func_8001E7E0` (8 bytes).
  Its Context Pack was 1,346 characters. One Sol/medium worker edited the file.
  The candidate compiled with the original Makefile and IDO flags.
* Objective outcome: **100.0**, **zero different instructions**, identical object
  disassembly, and **full ROM exact = true**. Original `make check` returned `OK`.
* The harness created atomic match commit `b83d1f1eb` (`decomp: match func_8001E7E0`).
  No other decompilation target was processed. Remaining inventory: **13,397**.
* Unit/process/transaction tests also simulate a score of 100 with a failing full
  ROM comparison: the harness escalates through all configured stages and blocks
  without publishing. Other tests exercise interrupted publication, recovery without
  another model call, technical retries, budgets, fake-process timeout/cancellation,
  credential rejection, source guards and preservation of unrelated staged changes.
* The final stdlib suite passed **39 tests**. A separate `decomp-agent verify
  func_8001E7E0` rebuilt the complete game and libultra in a fresh snapshot and
  confirmed the same exact ROM match without further inference.

Local reproducible evidence (ignored, not embedded in Git):

* `.decomp-agent/doctor.json`
* `.decomp-agent/logs/tests.log`
* `.decomp-agent/logs/integration-run.log`
* `.decomp-agent/runs/attempt-09be80b03197/` — prompt, JSONL, C patch, compiler logs,
  both disassemblies, `comparison.json`, regression output and commit SHA.

Codex's reported worker usage was 53,696 input tokens, including 38,528 cached input
tokens, and 461 output tokens. These are aggregate CLI turn metrics, including the
CLI's own system/tool context and multiple local tool turns; they are not the pack
size or a measurement of remaining subscription quota. In addition there were two
initial model probes plus a final live Sol startup probe. No large autonomous
batch was started during development.

## Optimization follow-up

The existing five matches and SQLite history were retained. Schema 2 adds learned
C patterns, persistent local-trial results, an easy-model stage and provider metadata.
The host still uses Codex CLI **0.161.0**, stored/forced ChatGPT authentication and
the same original ROM and IDO toolchain. No API key or custom inference API was used.

* The local pattern inventory initially found **130 candidates**, without inference.
  A standalone disposable build checked the generated `s32`-argument setter for
  `func_8008C1B8`: identical object instructions and full ROM, zero model runs.
  That preliminary check reused the just-verified doctor's build artifacts; the
  subsequent harness runs each performed their normal fresh isolated baseline build.
* Exactly **one additional target function** was used throughout this follow-up:
  `src/core2/1E64F00.c::func_8008C1B8` (8 bytes).
* A real `gpt-6-luna` / `low` worker ran with `--no-local`, concurrency 2 and a
  shared budget of one function/one worker attempt. It used one private Git worktree.
  The CLI completed in **7.805 seconds**, with **38,632 input tokens** (24,064 cached),
  **256 output tokens**, and one narrow source read before editing. These are CLI
  aggregate token metrics, not remaining subscription allowance or a cost benchmark.
* Luna chose `s16 arg1`. IDO emitted an extra `sw a1,4(sp)`: **66.6667 score, one
  different instruction, full ROM false**. The harness rejected publication and
  retained the attempt. No second model attempt was made.
* The same function then ran through `--local-only --concurrency 2 --max-functions 1`.
  The generated `s32 arg1` candidate achieved **100.0, zero different instructions,
  identical object code and full ROM exact**. The harness automatically created
  **`c09fdc81cf09e5c379c3051c471f682c74dcaef5`** (`decomp: match func_8008C1B8`).
  This complete local run used **zero CLI/model calls**. Its source pattern and the
  verified argument-width finding were persisted in the local knowledge base.
* Current inventory: **6 confirmed harness matches, 13,392 open functions, 151 data
  imports**; **129 remaining local candidates**, still requiring compilation.
* Final `doctor`: **ok=true, complete=true**, including original full-ROM validation.
  Luna was probed live; Sol 6.1 and Astra reused their still-valid successful real
  probe records for the same account and CLI version. In total this follow-up used
  two small Luna probes and one actual Luna worker, all through ChatGPT authentication.
* Claude Code **2.1.292** is installed and its actual flag surface was inspected.
  The cleaned subscription-auth check did **not** confirm a Pro/Max login. The optional
  Haiku backend therefore remains disabled; no Haiku inference or model availability
  claim is made. Its auth failures, restricted arguments and stream-JSON parser were
  tested with controlled fake CLI processes. In particular, `--bare` is prohibited
  because the installed CLI documents that it bypasses OAuth authentication.
* **61 stdlib tests passed**. Coverage includes migration from a real schema-1 column
  layout without losing history, pattern generation/reuse, Luna escalation, provider
  usage separation, interrupted and hard-crashed candidates, credential rejection,
  and two overlapping fake workers in real private Git worktrees. Those tests verify
  serialized builds/commits, dependency exclusion, shared budgets and stop/drain
  behavior. Two simultaneous real inference calls were deliberately not used for testing.
* Local configuration now enables **concurrency=2**, local patterns and one bounded
  Luna/low attempt before the existing Sol/Astra stages. New installations retain
  the conservative concurrency=1 default. No large batch or push was performed.

Ignored local evidence:

* `.decomp-agent/logs/local-pattern-integration/` — preliminary compiler and ROM check.
* `.decomp-agent/runs/attempt-d997537da85a/` — bounded Luna attempt, usage and rejected diff.
* `.decomp-agent/runs/local-a7e0b489eaf2/` — exact local match, original compiler output,
  full regression result and commit SHA.
* `.decomp-agent/logs/doctor-optimization-final.json` — final online doctor result.
* `.decomp-agent/logs/tests-optimizations.log` — all 61 unit/process tests.
* `.decomp-agent/report.json` and `.decomp-agent/knowledge.md` — current exported state.

The single Luna failure does not establish a model-wide success rate. The proven
quota saving here is the local path: it solved this target without inference.

## Project-wide local sweep — 2026-10-08

The earlier local recipes had already been exhausted in this checkout. At the start
of the following measurements, the existing user runs had reached 230 committed
matches, 13,163 pending functions, one blocked function and four needing human review.
Counts below are snapshots, not promises about future runs.

* The expanded local planner scanned all **13,163 pending functions in 6.49 seconds**
  and found **1,423 functions with untried candidates**. The installed CLI's unbounded
  `run --local-only --dry-run` independently produced a 1,423-entry plan with zero
  model runs. Unsupported functions no longer enter the build/objdump queue.
* A fresh isolated original `make check` took **251.52 seconds** on this machine and
  produced the exact original decompressed ROM. This explains the previous long
  startup even for a tiny local batch. The new cache retains verified artifacts,
  checks inputs, artifact contents and Docker image identity, and still runs the
  original full-ROM check after reuse. It never treats a cached success as a match.
* Seven disposable object-level checks produced **100.0 score and zero instruction
  differences** using the real IDO compiler: `func_800A5D60`, `func_800BDC44`,
  `func_8001E7A0`, `func_80092EBC`, `func_800932BC`, `func_8009E9D8`, and `func_800BA4C4`.
  They cover address returns with/without an existing declaration, indexed globals,
  nested pointer setters, global stores and direct/indirect float setters. These
  object-only experiments did not publish source changes or mark functions matched.
* `chbeehive_entrypoint_0` exposed a useful padding case: object symbol disassembly
  omitted two NOPs following the original `endlabel` (score 60), but **the full ROM
  was identical**. The compiler supplied equivalent section alignment outside the
  displayed symbol. This confirms why the original full-ROM test remains authoritative.
  This disposable test was restored and did not publish a match.
* Each generated target was restored after inspection; a final original `make check`
  confirmed the restored baseline. These checks used **zero inference/API calls**.
* Reusing the cache took **7.53 seconds** to copy and verify all artifacts, followed
  by **6.15 seconds** for the original `make check`; the full ROM was identical.
  A real installed-CLI run then matched **exactly one additional function**,
  `func_800A5D60`: score 100, zero instruction differences, full ROM exact, atomic
  commit **`da30285bbc938b25c4c6d1a65a05e63384936768`**. The complete invocation took
  **34.78 seconds**, including scan/startup, validation, publication and cache retention.
  SQLite recorded **zero new worker or probe calls**. Afterwards the planner reported
  **1,422 remaining eligible functions** and the harness had **231 confirmed matches**.
* The added stdlib tests cover symbolic relocations/register guards, typed declaration
  reuse, endlabel padding, project-wide preselection, persisted local failures,
  resumable candidates, stop before the first function, cache integrity/invalidation,
  symlink rejection and mandatory full-ROM checks even with a warm cache.
  Cache artifacts include generated Python bytecode and hidden files: adding or
  changing any such file invalidates reuse, even though the initial fresh source
  snapshot deliberately excludes user Git/agent configuration.

Ignored evidence: `.decomp-agent/logs/local-sweep-plan.json` and
`.decomp-agent/logs/local-sweep-integration/` (generated C, compiler logs, object dumps,
scores and original full-ROM checks). Only actual harness publications update the
matched count; 1,423 candidates does not mean 1,423 confirmed matches.
The full CLI output is in `.decomp-agent/logs/local-sweep-run.log`; timing and usage
counts are in the adjacent `local-sweep-run-timing.json`. The offline doctor passed
its requested checks (live model probes and its separate baseline build were skipped).

## Acceleration — 2026-10-08

Goal: fewer tokens per match, fewer blocked functions, shorter wall time. Snapshot at
the start: 398 matches, all but one ≤ 16 bytes (0.26 % of code bytes); every
nonmatching candidate paid a full `make check` plus a rebuild and second check
(≈ 20 s serialized), and Codex workers could not compile on macOS.

Measurements with the real Docker/IDO toolchain (no inference unless stated):

* **Score normalization.** The `func_80800220_chdinoboss` match (2,608 bytes) scored
  99.3865 with 4 "differences" that were only `jtbl_…`/`R_…` vs `.rodata` relocations.
  Rebuilt from the parent commit and compared with the new symbol-table rebasing:
  **100.0, 0 differences**. A wrong rodata offset remains a difference (unit-tested).
* **Compile service.** A scripted worker in a real `worker_copy` called
  `./decomp-compile`: ≈ 2 s per round trip, normalized diff or compiler error, workspace
  source and object restored byte-identically afterwards.
* **m2c** (`--valid-syntax`, macros expanded to plain C, `u8 *` variant for `void *`
  arithmetic), random samples of 30 pending functions each, object-level result:
  easy **12–14 / 30 identical**, medium 3 / 30 identical and 22 compiled, hard 15 compiled
  (median 40). ≈ 3 s per function including the IDO compile.
* **Permuter** on two m2c near misses for 120 s each: import, search and extraction work
  end to end; `func_800B59E0` improved from 94.29 to 97.14 (one instruction left).
* **Opcode shape groups:** 676 groups with 3,140 pending/matched functions; 37 groups
  already contain a match (812 pending members become transfer candidates).
* **Real worker run** (one function, one CLI launch): `./decomp-agent run --function
  func_80800394_chtorpedo --max-attempts 1 --model gpt-6-luna`. The m2c stage compiled a
  candidate at 94.44 (one instruction off; ROM check skipped). Luna started from it inside
  the normal Codex `workspace-write` sandbox, called `./decomp-compile` once, received
  `OBJECT MATCH` and stopped. The parent then verified **full ROM exact** and committed
  **`44a639b6dbc5805a43af92377e34567e3baa6dab`**. Worker: **17.0 s, 63,117 input tokens
  (29,184 cached), 919 output tokens**; no second attempt.
* **Local sweeps (zero inference).** `run --local-only --difficulty easy --max-functions 12`
  (concurrency 2) matched four functions via templates/transfers, then stopped with
  `database is locked`: candidate generation yielded while an SQLite cursor was still open,
  so a write after the other worker's commit hit a stale WAL snapshot. Cursors are now
  materialized; a regression test reproduces the error without the fix. State stayed
  consistent (no open publication, interrupted functions back to `pending`).
  The rerun `run --local-only --difficulty medium --max-functions 12` used m2c only:
  **3 / 12 ROM-exact matches** (`func_808000E8_chwandglow`, `func_8010A764`,
  `badrone_entrypoint_6`), 9 compiled near misses kept as model starting points,
  ≈ 87 s after the baseline, no lock errors.
* **Legacy matches seed their groups.** Matches made before shape grouping were never
  rescanned, so only 7 shape groups were solved. `remember` now derives the shape from the
  ASM file: **255 solved groups, 808 pending functions with a transfer candidate.**
* Stdlib tests: **105 passed**, including compile-service guard/symlink handling, batch
  publication, transfer, scheduler priorities, m2c macro expansion, permuter acceptance,
  local-only m2c planning, the SQLite snapshot regression and the new configuration checks.

Not yet measured: batch sessions with a real model and long unattended runs. The m2c
and permuter numbers are small random samples, not project-wide rates.

Ignored evidence: `.decomp-agent/logs/acceleration-real-run.log`,
`.decomp-agent/runs/attempt-670588bcda4a/` (prompt, `compile-1.txt`, usage, comparison,
regression output, commit SHA), `.decomp-agent/logs/acceleration-local-m2c*.log` and
`.decomp-agent/scratch/probe2-*.jsonl` (m2c samples).

### Follow-up: linker failure after host-side restore

A user sweep (`run --local-only --difficulty easy`) matched 15 functions, then every
ROM check failed with `mips-linux-gnu-ld: cannot open output file
build/us/banjotooie_decompressed_prelim.elf: No such file or directory`, although the
objects were identical (score 100). The new restore wrote the baseline object and
deleted linked outputs from the macOS host while the linker runs in the container
(Docker Desktop file sharing). The exact trigger could not be reproduced on a fresh copy,
so restore and baseline saving now run inside the build environment, like `make`.
31 affected runs on 16 functions were identified by their `regression.log`; their 44
non-matched local-trial records were removed (backup: `.decomp-agent/state-before-linker-cleanup.db`).
Verification `run --local-only --difficulty easy --max-functions 24`: 7 restores after
compile errors, every later ROM check passed, **22 / 24 matched**, including all 15
previously misreported functions. Stdlib tests: 105 passed.
