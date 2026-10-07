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
