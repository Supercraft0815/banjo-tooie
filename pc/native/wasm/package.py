#!/usr/bin/env python3
"""Assemble platform packages from an already built host executable only."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import tempfile
import zipfile


WINDOWS_SYSTEM_DLLS = {'kernel32.dll', 'user32.dll', 'advapi32.dll', 'gdi32.dll', 'imm32.dll',
                       'oleaut32.dll', 'ole32.dll', 'setupapi.dll', 'shell32.dll', 'version.dll',
                       'winmm.dll', 'msvcrt.dll', 'ws2_32.dll', 'comdlg32.dll', 'comctl32.dll',
                       'shlwapi.dll', 'bcrypt.dll', 'secur32.dll', 'ntdll.dll', 'rpcrt4.dll',
                       'uxtheme.dll', 'dwmapi.dll', 'winspool.drv', 'dbghelp.dll'}


def pe_imports(binary, objdump):
    proc = subprocess.run([str(objdump), '-p', str(binary)], capture_output=True, text=True, check=True)
    return [line.split('DLL Name:', 1)[1].strip() for line in proc.stdout.splitlines() if 'DLL Name:' in line]


def copy_runtime(exe, runtime_dirs, destination, objdump):
    copied, checked = {}, set()
    pending = [Path(exe)]
    while pending:
        binary = pending.pop()
        if binary in checked:
            continue
        checked.add(binary)
        for name in pe_imports(binary, objdump):
            key = name.lower()
            if key in copied or key in WINDOWS_SYSTEM_DLLS or key.startswith(('api-ms-win-', 'ext-ms-win-')):
                continue
            source = next((p / name for p in runtime_dirs or [] if (p / name).is_file()), None)
            if source is None:
                raise ValueError(f'Windows runtime dependency {name} not found in --runtime-dir')
            target = destination / name
            shutil.copy2(source, target)
            copied[key] = target
            pending.append(target)
    if 'sdl3.dll' not in copied:
        raise ValueError('Windows package requires SDL3.dll as an executable dependency')
    return [path.name for path in copied.values()]


def copy_linux_dependencies(exe, runtime_dirs, destination):
    """Bundle SDL and its user-space libraries. The system supplies GPU drivers."""
    search = os.pathsep.join([*(str(path) for path in runtime_dirs or []), os.environ.get('LD_LIBRARY_PATH', '')]).rstrip(os.pathsep)
    proc = subprocess.run(['ldd', str(exe)], env=dict(os.environ, LD_LIBRARY_PATH=search),
                          capture_output=True, text=True, check=True)
    system = ('libc.so', 'libm.so', 'libdl.so', 'libpthread.so', 'librt.so', 'libgcc_s.so',
              'libstdc++.so', 'ld-linux', 'linux-vdso',
              'libdrm.so', 'libgbm.so', 'libvulkan.so')
    for line in proc.stdout.splitlines():
        left, arrow, right = line.partition('=>')
        if not arrow:
            continue
        name = left.strip()
        resolved = right.strip().rsplit(' (', 1)[0]
        if right.strip() == 'not found':
            raise ValueError(f'unresolved Linux runtime dependency: {name}')
        if not resolved.startswith('/'):
            continue
        if name.startswith(system) or name.startswith('libGLX_') or name.startswith('libvulkan_'):
            continue
        source = Path(resolved)
        if not source.is_file():
            raise ValueError(f'ldd dependency disappeared: {source}')
        target = destination / name
        if not target.exists():
            shutil.copy2(source, target)
    if not any(path.name.startswith('libSDL3.so') for path in destination.iterdir()):
        raise ValueError('Linux AppImage requires the SDL3 shared library')


def write_manifest(root):
    files = []
    for path in sorted(p for p in root.rglob('*') if p.is_file() and p != root / 'PACKAGE-MANIFEST.json'):
        digest = hashlib.sha256()
        with path.open('rb') as stream:
            for chunk in iter(lambda: stream.read(1024 * 1024), b''):
                digest.update(chunk)
        files.append({'path': path.relative_to(root).as_posix(), 'bytes': path.stat().st_size,
                      'sha256': digest.hexdigest()})
    (root / 'PACKAGE-MANIFEST.json').write_text(json.dumps({'format': 'bt-package-1', 'files': files},
                                                            indent=2) + '\n')


def copy_map_assets(game_map, native_map, destination, *, windows=False):
    game_map = Path(game_map).resolve() if game_map else None
    native_map = Path(native_map).resolve() if native_map else None
    if not game_map or not game_map.is_file():
        raise ValueError('package requires the linked wasm game.map')
    shutil.copy2(game_map, destination / 'game.map')
    if windows:
        if not native_map or not native_map.is_file():
            raise ValueError('Windows package requires bt_game.native.map')
        shutil.copy2(native_map, destination / 'bt_game.native.map')
    elif native_map:
        if not native_map.is_file():
            raise ValueError(f'native map not found: {native_map}')
        shutil.copy2(native_map, destination / 'bt_game.native.map')


def package(platform, exe, output, runtime_dir=None, appimagetool=None, objdump=None,
            game_map=None, native_map=None):
    exe, output = Path(exe).resolve(), Path(output).resolve()
    if not exe.is_file() or exe.suffix.lower() not in ('.exe', ''):
        raise ValueError(f'not a native host executable: {exe}')
    output.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix='bt-package-', dir=output.parent) as temp:
        work = Path(temp)
        if platform == 'windows':
            tree = work / 'BanjoTooie'
            tree.mkdir()
            shutil.copy2(exe, tree / 'BanjoTooie.exe')
            copy_map_assets(game_map, native_map, tree, windows=True)
            if not objdump:
                raise ValueError('Windows package requires llvm-objdump for dependency closure')
            copy_runtime(exe, runtime_dir, tree, objdump)
            write_manifest(tree)
            packed = work / output.name
            with zipfile.ZipFile(packed, 'w', compression=zipfile.ZIP_DEFLATED) as archive:
                for item in sorted(tree.iterdir()):
                    archive.write(item, f'BanjoTooie/{item.name}')
            packed.replace(output)
        elif platform == 'macos':
            otool = shutil.which('otool')
            if otool:
                linked = subprocess.run([otool, '-L', str(exe)], capture_output=True, text=True, check=True).stdout
                if any(('libSDL3' in line and '.dylib' in line) or 'SDL3.framework/' in line for line in linked.splitlines()):
                    raise ValueError('macOS release app requires statically linked SDL3 (BT_SDL3_STATIC=1)')
            app = work / output.name
            contents = app / 'Contents'
            binary = contents / 'MacOS'
            resources = contents / 'Resources'
            binary.mkdir(parents=True)
            resources.mkdir()
            shutil.copy2(exe, binary / 'BanjoTooie')
            copy_map_assets(game_map, native_map, resources)
            (contents / 'Info.plist').write_text('''<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0"><dict><key>CFBundleExecutable</key><string>BanjoTooie</string>
<key>CFBundleIdentifier</key><string>org.banjotooie.native</string><key>CFBundleName</key><string>Banjo-Tooie</string>
<key>CFBundlePackageType</key><string>APPL</string><key>CFBundleVersion</key><string>1</string></dict></plist>
''')
            write_manifest(app)
            app.rename(output)
        elif platform == 'linux':
            appdir = work / 'BanjoTooie.AppDir'
            binary = appdir / 'usr' / 'bin'
            binary.mkdir(parents=True)
            (appdir / 'usr' / 'share' / 'applications').mkdir(parents=True)
            icons = appdir / 'usr/share/icons/hicolor/512x512/apps'
            icons.mkdir(parents=True)
            shutil.copy2(Path(__file__).resolve().parents[2] / 'icons/app.png', icons / 'bt_game.png')
            (appdir / 'bt_game.png').symlink_to('usr/share/icons/hicolor/512x512/apps/bt_game.png')
            shutil.copy2(exe, binary / 'bt_game')
            copy_map_assets(game_map, native_map, binary)
            libdir = appdir / 'usr' / 'lib'
            libdir.mkdir(parents=True)
            copy_linux_dependencies(exe, runtime_dir, libdir)
            (appdir / 'AppRun').write_text('#!/bin/sh\nHERE="$(dirname "$(readlink -f "$0")")"\n'
                                           'export LD_LIBRARY_PATH="$HERE/usr/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"\n'
                                           'exec "$HERE/usr/bin/bt_game" "$@"\n')
            os.chmod(appdir / 'AppRun', 0o755)
            (appdir / 'bt_game.desktop').write_text('[Desktop Entry]\nType=Application\nName=Banjo-Tooie\nExec=bt_game\nIcon=bt_game\nCategories=Game;\n')
            shutil.copy2(appdir / 'bt_game.desktop', appdir / 'usr/share/applications/bt_game.desktop')
            write_manifest(appdir)
            tool = appimagetool or shutil.which('appimagetool')
            if not tool:
                raise ValueError('Linux package requires AppImageKit appimagetool')
            image = work / output.name
            proc = subprocess.run([str(tool), str(appdir), str(image)], check=False)
            if proc.returncode:
                raise RuntimeError(f'appimagetool failed with exit {proc.returncode}')
            image.replace(output)
        else:
            raise ValueError(f'unsupported platform {platform}')
    return output


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--platform', choices=('macos', 'windows', 'linux'), required=True)
    parser.add_argument('--exe', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--runtime-dir', type=Path, action='append', default=[])
    parser.add_argument('--appimagetool')
    parser.add_argument('--objdump')
    parser.add_argument('--game-map', type=Path, required=True,
                        help='linked wasm game.map, packaged beside the executable')
    parser.add_argument('--native-map', type=Path,
                        help='optional native linker map; required for Windows diagnostics')
    args = parser.parse_args()
    try:
        print(package(args.platform, args.exe, args.output, args.runtime_dir, args.appimagetool,
                      args.objdump, args.game_map, args.native_map))
    except (OSError, ValueError, RuntimeError, zipfile.BadZipFile) as exc:
        parser.exit(1, f'package failed: {exc}\n')


if __name__ == '__main__':
    main()
