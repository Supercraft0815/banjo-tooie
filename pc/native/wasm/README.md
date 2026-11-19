# Playable ILP32 port

The current game build compiles the decompiled C to wasm32, applies the LLVM
passes, translates it with wasm2c and links it with the SDL3 host. The software
renderer and game logic passed the same 29 recorded scenarios on Apple Silicon,
Debian arm64 and the x86-64 Windows executable under Wine. The macOS GPU passes
the intro image comparison. Mesa llvmpipe and the Wine OpenGL path still exceed
its tolerance. Physical Windows hardware has yet to be checked.

Run commands from the repository root. The guest stage requires the existing N64
build/extracted assets and your local ROM, clang >= 19, the LLVM tools/libraries
for the pass plugin, WABT, and Python 3. The host stage requires clang and clang++ >= 19,
WABT's C runtime, SDL3, zlib and platform graphics libraries.

OpenGL uses SDL3 contexts and the vendored glad 2 loader on every platform.
Headless GPU tests create a hidden SDL window. Exact 1x GPU rendering requires
OpenGL 4.5, `GL_ARB_texture_barrier`, or `GL_NV_texture_barrier`; without a usable
barrier it reports the reason once and falls back to the software renderer.
Loader generation and licensing are recorded in `host/glad/README.md`.

```sh
python3 pc/native/wasm/build.py
python3 pc/native/wasm/build.py --run -- baserom.us.z64
```

Tools are selected from the following overrides, then `PATH`, then Homebrew
locations on macOS. An explicit override is never silently replaced by a tool
from somewhere else.

| Variable | Meaning |
|---|---|
| `BT_LLVM_BIN` | Directory containing `clang`, `clang++`, `opt`, `llvm-config`, `llvm-nm`, `llvm-dis`, `llvm-link`, `wasm-ld` |
| `BT_WABT` | Installation prefix containing `bin/wasm2c`, `include/wasm-rt.h`, `share/wabt/wasm2c/` |
| `BT_SDL3` | Installation prefix containing `include/SDL3/` and `lib/`; otherwise `pkg-config sdl3`, Homebrew or the system search paths |
| `BT_OUT` | Output directory, default `build/ilp32` |
| `BT_AUDIO_DEBUG` | Set to `1` to include the RSP interpreter and command-by-command audio checks |
| `BT_HOST_FLAGS` | Additional compiler/linker flags, e.g. `-fsanitize=address,undefined` |

Use a matching LLVM installation for `opt` and the plugin's headers/libraries.
Compiler/version/flag changes select new guest and host object caches; plugin
toolchain changes invalidate its stamp. Dependencies with spaces are supported.

## Separate guest and host builds

```sh
python3 pc/native/wasm/build.py guest
mkdir -p build/host-only
cp -R build/ilp32/gen build/host-only/gen
BT_OUT="$PWD/build/host-only" python3 pc/native/wasm/build.py host
```

Transfer the generated C sources and headers in `gen/`. The host uses these with WABT's C runtime.
The game reads the audio coefficients from the player's US ROM at startup. A debug audio build
also reads the original RSP instructions from the ROM. Generated guest sources contain
ROM-derived data and remain private pending the A4 distribution review.

Windows pass plugins are toolchain-dependent: LLVM's build supports explicit
symbol exports for plugins when using MSVC, and plugins must link to the tool.
This does not establish whether any particular Windows binary distribution
enables that configuration. No Windows plugin execution was tested locally;
the separate host stage avoids requiring it for the Windows port. See the
[LLVM configuration source](https://github.com/llvm/llvm-project/blob/llvmorg-21.1.0/llvm/cmake/modules/HandleLLVMOptions.cmake#L1223).

## Checks

```sh
python3 pc/native/wasm/tests/build_test.py
python3 pc/native/wasm/port.py gate --full
python3 pc/native/wasm/port.py gate --case intro --exe build/host-only/bt_game
```

The gate uses isolated saves and frozen executable copies. Do not accept new
reference traces to hide a build regression. See `../PROGRESS.md` for evidence
and remaining gameplay issues.

## Audio verification

The native n_audio mixer is the default (`BT_AUDIO=mixer`). A host built with `BT_AUDIO_DEBUG=1` also
accepts `BT_AUDIO=rsp` and `BT_AUDIO_CHECK=1`. The check compares all 4 KiB of DMEM and each
RDRAM DMA write after every command. `BT_PCM=/path/to/file` writes the submitted stereo s16le
samples. The settings menu's **Audiopuffer** controls the device queue reserve in stereo frames
(512, 1024, 2048 or 4096, default 1024).

```sh
BT_AUDIO_DEBUG=1 python3 pc/native/wasm/build.py host
BT_AUDIO_CHECK=1 python3 pc/native/wasm/port.py gate --full --exe build/ilp32/bt_game
python3 pc/native/wasm/tests/audio_mixer_test.py
```


## Settings and controls

F2 or the controller’s Back button opens the settings menu. Use the D-pad to choose a page.
Right enters its settings. A selects an item, B returns to the page list and Back closes the menu.
Graphics, audio, controls, enhancements and debug settings use the same values as `settings.ini`.
The renderer and language take effect after the next launch.

Choose a controller port and an N64 button under **Steuerung**, then press the new key or gamepad
button. Existing port-one keyboard aliases such as `key.A=Space,G` work as before. Examples of
per-port bindings are `pad2.A=a` and `pad3.B=key:H`. Use `default` to restore a pad binding.
Stick dead zone and sensitivity are percentages, for example `pad2.deadzone=20` and
`pad2.sensitivity=100`. The menu captures input from all four ports while it is open.

The game loads and saves `settings.ini` in the existing SDL preferences directory. `BT_SETTINGS`
selects another INI file for isolated windowed runs. Headless runs skip the settings file and
ImGui. Host-only source bundles must include `pc/native/third_party/imgui` alongside the host.
The included core and SDL3/OpenGL3 backends come from [Dear ImGui v1.93.0](https://github.com/ocornut/imgui/releases/tag/v1.93.0)
under the [MIT license](../third_party/imgui/LICENSE.txt).

## Mod packages

Put packages in the game's working directory. Under **Mods**, enter their names
in priority order, separated by commas, and restart the game. The first package
with a matching file wins. An empty list uses the original resources.
`BT_MOD_ORDER=first,second` selects the same order for a scripted run.

- For GPU textures, select a render scale of 2× or higher and set `BT_TEX_DUMP`
  to an output directory. Put an enlarged
  PNG in `mods/first/textures/` with the exact filename from the dump. The
  dimensions in the filename describe the original tile. Enlarge both axes by
  the same integer factor of at least two.
- For models and other assets, set `BT_ASSET_DUMP` to an output directory.
  Put the replacement's uncompressed bytes under the same eight-digit
  hexadecimal filename, for example `mods/first/assets/000006ea.bin`.
