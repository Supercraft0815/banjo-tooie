# Harness maintenance

Keep the runtime stdlib-only. Inference uses `codex exec` with ChatGPT, or the
explicitly enabled `claude -p` backend with confirmed Claude Pro/Max authentication.
Never weaken credential guards or add an API/provider fallback. Local generators
and learned patterns are candidates, never evidence of a match.
Parallel workers use private Git worktrees, file/dependency locks, and shared budgets.
Only the trusted, serialized parent validation/publication path touches the checkout.
A normalized score is guidance. `make check` plus the original full-ROM hash is
required before committing a match. Keep original ROMs and build/diff tools intact.
Exercise failure/resume paths with fake CLI processes before spending real usage.
Tests: `PYTHONPATH=tools/decomp_harness/src python3 -m unittest discover -s tools/decomp_harness/tests -v`.
