#!/usr/bin/env python3
"""Play the native build step by step (BT_CONTROL, host/control.c).

  play.py start [--save EEPROM] [--scale N] [-- ENV=VALUE ...]   start a paused headless game
  play.py "run 60 8000; run 30 0; shot a"                         send commands, print the reply
  play.py stop

`shot NAME` without a path writes build/play/NAME.png (converted with sips for viewing).
Masks: A 8000, B 4000, Z 2000, Start 1000, stick x << 16 and stick y << 24 (signed bytes),
e.g. 50000000 = stick up, B0000000 = down, 500000 = right, B00000 = left.
"""
import os
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
DIR = ROOT / 'build' / 'play'
CTL = DIR / 'ctl'


def start(args):
    DIR.mkdir(parents=True, exist_ok=True)
    for p in (Path(str(CTL) + '.in'), Path(str(CTL) + '.out')):
        if p.exists():
            p.unlink()
        os.mkfifo(p)
    env = dict(os.environ, BT_VCLOCK='1', BT_HEADLESS='1', BT_MUTE='1', BT_CONTROL=str(CTL),
               BT_SAVE=str(DIR / 'eeprom.bin'))
    rest = []
    while args:
        a = args.pop(0)
        if a == '--save':
            src = Path(args.pop(0))
            (DIR / 'eeprom.bin').write_bytes(src.read_bytes())
        elif a == '--scale':
            env['BT_SCALE'] = args.pop(0)
        elif a == '--':
            rest = args
            break
    for kv in rest:
        k, v = kv.split('=', 1)
        env[k] = v
    log = open(DIR / 'log.txt', 'w')
    proc = subprocess.Popen([str(ROOT / 'build/ilp32/bt_game'), str(ROOT / 'baserom.us.z64')],
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
                sys.exit('game exited; see build/play/log.txt')
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
            sys.exit(data.decode() + 'game exited; tail of build/play/log.txt:\n' + ''.join(open(DIR / 'log.txt').readlines()[-30:]))
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
    if a and a[0] == 'start':
        start(a[1:])
    elif a and a[0] == 'stop':
        if alive():
            send('quit')
    elif a:
        if not alive():
            sys.exit('game is not running; tail of build/play/log.txt:\n' + ''.join(open(DIR / 'log.txt').readlines()[-30:]))
        print(send(' '.join(a)), end='')
    else:
        print(__doc__)
