# Harness maintenance

Keep the runtime stdlib-only and inference exclusively in `codex exec`.
Never weaken the ChatGPT credential guard or add a provider/API fallback.
Workers edit independent copies; only the trusted parent compiles and publishes.
A normalized score is guidance. `make check` plus the original full-ROM hash is
required before committing a match. Keep original ROMs and build/diff tools intact.
Exercise failure/resume paths with fake CLI processes before spending real usage.
Tests: `PYTHONPATH=tools/decomp_harness/src python3 -m unittest discover -s tools/decomp_harness/tests -v`.
