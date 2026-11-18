# Native crash reports

The native host writes a report for `bt_fatal`, guest traps, and supported native faults. Interactive runs use the user's Banjo-Tooie preferences directory. Headless runs write only when `BT_CRASH_REPORT` names an explicit path. Reports contain the build version, last known guest map, fault details, host stack, up to 200 captured log lines, and matching wasm symbols from `game.map`.

The VI thread obtains the current map from the generated `TRACE_D_80132DC2` data address. The VI thread reads it after releasing the VI mutex and updates the last known valid map. The generated header may relocate the symbol; the current linked value is used in the read.

`game.map` is resolved with `SDL_GetBasePath`. macOS bundles place it in `Contents/Resources`. Linux and Windows place it beside the executable. Windows packages also include `bt_game.native.map` beside the executable to resolve wasm2c guest function names from PE instruction addresses. The map file records wasm addresses; Windows native frames use the native map first, then guest function names are matched against `game.map`.

On POSIX, the signal handler copies the signal context and thread identity to a pipe, then parks the faulting thread. A reporter thread writes the report, so it does not take the log-capture lock in the signal handler. x86-64 and arm64 frame chains are bounds checked against the faulting thread's stack. Linux builds use `-rdynamic` so `backtrace_symbols` includes generated wasm2c names. `bt_fatal` and guest traps capture their stack on the calling thread.

On Windows, the unhandled exception filter captures the exception context and uses `StackWalk64`/DbgHelp before writing the report. The log ring uses a try-lock so a report does not wait for a lock held by the crashed thread.

The stack is best effort: damaged stacks, leaf functions without a frame record, or faults inside the reporting/unwinding implementation can shorten or prevent the caller chain. Linux arm64 and macOS x86-64 POSIX fault chains were exercised in scratch. Windows x64 was exercised under Wine/llvmpipe. Native Windows hardware has not been tested by this report work.
