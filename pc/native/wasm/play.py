#!/usr/bin/env python3
"""Play the native build step by step (BT_CONTROL, host/control.c).

  play.py start [--exe FILE] [--dir NEW_DIR] [--save EEPROM] [--scale N] [-- ENV=VALUE ...]
                                                                start a paused headless game
  play.py "run 60 8000; run 30 0; shot a"                         send commands, print the reply
  play.py --dir DIR COMMAND                                  use another session for run/shot/stop

`shot NAME` without a path writes build/play/NAME.png (converted with sips for viewing).
Masks: A 8000, B 4000, Z 2000, Start 1000, stick x << 16 and stick y << 24 (signed bytes),
e.g. 50000000 = stick up, B0000000 = down, 500000 = right, B00000 = left.
"""
import argparse
import os
import re
import subprocess
import sys
import time
from pathlib import Path

import trace_tools

ROOT = Path(__file__).resolve().parents[3]
DIR = ROOT / 'build' / 'play'
CTL = DIR / 'ctl'


def parse_start_args(args):
    parser = argparse.ArgumentParser(add_help=False)
    parser.add_argument('--dir', type=Path)
    parser.add_argument('--exe', type=Path, default=ROOT / 'build/ilp32' / trace_tools.GAME_NAME)
    parser.add_argument('--save', type=Path)
    parser.add_argument('--scale')
    options, rest = parser.parse_known_args(args)
    if rest and rest[0] == '--':
        rest = rest[1:]
    elif rest:
        parser.error(f'unexpected start arguments {rest!r}; put ENV=VALUE arguments after --')
    directory = options.dir.expanduser().resolve() if options.dir else ROOT / 'build' / 'play'
    if options.dir and directory.exists():
        parser.error(f'play directory already exists: {directory}')
    exe = options.exe.expanduser().resolve()
    if not exe.is_file() or not os.access(exe, os.X_OK):
        parser.error(f'not an executable file: {exe}')
    for item in rest:
        name, sep, _ = item.partition('=')
        if not sep or not re.fullmatch(r'[A-Za-z_][A-Za-z0-9_]*', name):
            parser.error(f'invalid environment argument {item!r}; expected NAME=VALUE')
    return directory, exe, options, rest


def start(args):
    global DIR, CTL
    directory, exe, options, rest = parse_start_args(args)
    DIR = directory
    CTL = DIR / 'ctl'
    DIR.mkdir(parents=True, exist_ok=True)
    for p in (Path(str(CTL) + '.in'), Path(str(CTL) + '.out')):
        if p.exists():
            p.unlink()
        os.mkfifo(p)
    env = dict(os.environ, BT_VCLOCK='1', BT_HEADLESS='1', BT_MUTE='1', BT_CONTROL=str(CTL),
               BT_SAVE=str(DIR / 'eeprom.bin'))
    if options.save:
        (DIR / 'eeprom.bin').write_bytes(options.save.read_bytes())
    if options.scale:
        env['BT_SCALE'] = options.scale
    for kv in rest:
        k, v = kv.split('=', 1)
        env[k] = v
    log = open(DIR / 'log.txt', 'w')
    proc = subprocess.Popen([str(exe), str(ROOT / 'baserom.us.z64')],
                            cwd=DIR, env=env, stdout=log, stderr=subprocess.STDOUT, start_new_session=True)
    (DIR / 'pid').write_text(str(proc.pid))
    print(send('run 1'), end='')


def send(line):
    shots = []
    parts = []
    for cmd in line.split(';'):
        words = cmd.split()
        if words and words[0] == 'shot' and len(words) > 1 and '/' not in words[1]:
            bmp = DIR / (words[1] + '.bmp')
            shots.append(bmp)
            words[1] = str(bmp)
        parts.append(' '.join(words))
    # Non-blocking FIFO ends, so a crashed game ends the wait instead of hanging it.
    out = os.open(str(CTL) + '.out', os.O_RDONLY | os.O_NONBLOCK)
    while True:
        try:
            fd = os.open(str(CTL) + '.in', os.O_WRONLY | os.O_NONBLOCK)
            break
        except OSError:
            if not alive():
                sys.exit(f'game exited; see {DIR / "log.txt"}')
            time.sleep(0.01)
    os.set_blocking(fd, True)
    os.write(fd, ('; '.join(parts) + '\n').encode())
    os.close(fd)
    data = b''
    while True:
        try:
            chunk = os.read(out, 65536)
        except BlockingIOError:
            chunk = None
        if chunk:
            data += chunk
        elif chunk == b'' and data:
            break
        elif not alive():
            sys.exit(data.decode() + f'game exited; tail of {DIR / "log.txt"}:\n' + ''.join(open(DIR / 'log.txt').readlines()[-30:]))
        else:
            time.sleep(0.005)
    os.close(out)
    reply = data.decode()
    for bmp in shots:
        if bmp.exists():
            subprocess.run(['sips', '-s', 'format', 'png', str(bmp), '--out', str(bmp.with_suffix('.png'))],
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
            bmp.unlink()
            reply += 'shot %s\n' % bmp.with_suffix('.png')
    return reply


def alive():
    try:
        os.kill(int((DIR / 'pid').read_text()), 0)
        return True
    except (OSError, ValueError):
        return False


if __name__ == '__main__':
    a = sys.argv[1:]
    if a and a[0] == '--dir':
        if len(a) < 3:
            sys.exit('usage: play.py --dir DIR COMMAND')
        directory = Path(a[1]).expanduser().resolve()
        if not directory.is_dir():
            sys.exit(f'play directory is not a directory: {directory}')
        DIR, CTL = directory, directory / 'ctl'
        a = a[2:]
        if a[0] == 'start':
            sys.exit('for start, use play.py start --dir DIR')
    if a and a[0] == 'start':
        start(a[1:])
    elif a and a[0] == 'stop':
        if alive():
            send('quit')
    elif a:
        if not alive():
            sys.exit(f'game is not running; tail of {DIR / "log.txt"}:\n' + ''.join(open(DIR / 'log.txt').readlines()[-30:]))
        print(send(' '.join(a)), end='')
    else:
        print(__doc__)
