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
