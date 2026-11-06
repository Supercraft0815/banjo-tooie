#!/usr/bin/env python3
"""ILP32 build of the native port.

Game C (src/), the native modules (pc/native/*.c) and the guest runtime are
compiled for wasm32 (32-bit pointers, N64 struct layouts) as LTO bitcode, linked
with the converted asm data and generated traps, translated to C by wasm2c and
built with the host platform layer into one native executable:

    python3 pc/native/wasm/build.py [-j N] [--run] [-- ROM args]

Files that do not compile are left out; their functions become traps that name
themselves (see build/ilp32/compile_failures.txt).
"""
import argparse
import bisect
import concurrent.futures as cf
import hashlib
import os
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
HERE = pathlib.Path(__file__).resolve().parent
NATIVE = HERE.parent
OUT = ROOT / 'build' / 'ilp32'
sys.path.insert(0, str(HERE))
import data  # noqa: E402
import irtypes  # noqa: E402

CLANG = 'clang'
WASM_LD = '/opt/homebrew/bin/wasm-ld'
LLVM_BIN = '/opt/homebrew/opt/llvm/bin'
LLVM_NM = LLVM_BIN + '/llvm-nm'
WASM2C = 'wasm2c'
WASM2C_RT = pathlib.Path('/opt/homebrew/share/wabt/wasm2c')
WASM2C_INC = pathlib.Path('/opt/homebrew/include')

GLOBAL_BASE = 0x80001000      # guest pointers look like N64 KSEG0 addresses
MEMORY_END = 0x90000000       # 256 MB of game memory; physical addresses stay below the graphics tokens
GEN_OUTPUTS = 16              # wasm2c output files, compiled in parallel
EXPORTS = ['bt_guest_start', 'bt_guest_boot_stack_top']
# Functions the wasm backend may call after optimization (libcalls); internalize must keep them.
LIBCALLS = ['memcpy', 'memmove', 'memset', 'memcmp', 'fminf', 'fmaxf', 'fmin', 'fmax']

GUEST_FLAGS = [
    # No LLVM passes per file: inlining before the FixCalls pass would move K&R calls that rely
    # on register pass-through into another function (with other a0..a3). opt optimizes later.
    '--target=wasm32-unknown-unknown', '-O2', '-Xclang', '-disable-llvm-passes', '-flto', '-g0',
    '-DBT_NATIVE=1', '-DBT_NATIVE_LITTLE_ENDIAN=1', '-DBT_ILP32=1',
    '-DBUILD_VERSION=VERSION_J', '-DF3DEX_GBI_2', '-D_FINALROM', '-D_LANGUAGE_C',
    '-isystem', str(HERE / 'guest' / 'include'),
    '-I', str(NATIVE / 'include'), '-I', str(ROOT / 'include'),
    '-I', str(ROOT / 'lib' / 'ultralib' / 'include'), '-I', str(ROOT / 'src'),
    '-include', str(OUT / 'gen' / 'overlay_aliases.h'),
    '-fno-builtin', '-fno-strict-aliasing', '-fwrapv', '-w',
    '-Wno-implicit-function-declaration', '-Wno-int-conversion',
    '-Wno-incompatible-pointer-types', '-Wno-return-mismatch', '-Wno-implicit-int',
]
HOST_FLAGS = ['-O2', '-g', '-I', str(WASM2C_INC), '-I', str(WASM2C_RT), '-I', str(OUT / 'gen'),
              '-I', str(HERE / 'host'), '-DWASM_RT_MEMCHECK_GUARD_PAGES=1']


def run(cmd, **kw):
    return subprocess.run(cmd, capture_output=True, text=True, **kw)


def sources():
    replaced = {l.strip() for l in open(NATIVE / 'replaced_sources.txt') if l.strip() and not l.startswith('#')}
    game = sorted(str(p.relative_to(ROOT)) for p in (ROOT / 'src').rglob('*.c'))
    game = [f for f in game if f not in replaced]
    # input.c replaces the controller module for host input; here the game's own SI code runs.
    native = sorted(str(p.relative_to(ROOT)) for p in NATIVE.glob('*.c') if p.name != 'input.c')
    native += ['pc/native/platform/rdram.c', 'pc/native/platform/handwritten.c']
    guest = sorted(str(p.relative_to(ROOT)) for p in (HERE / 'guest').glob('*.c'))
    # libultra's math, bit-exact with the N64 (fixed_matrix.c has the matrix conversions and guOrtho).
    gu = ['lib/ultralib/src/gu/%s.c' % n for n in (
        'cosf', 'sinf', 'coss', 'sins', 'lookat', 'lookathil', 'lookatref', 'perspective', 'rotate',
        'rotaterpy', 'scale', 'translate', 'mtxcatf', 'mtxcatl', 'normalize', 'position', 'poslight',
        'poslighthil', 'frustum', 'align', 'random')]
    return game + native + guest + gu


def flags_hash(flags):
    return hashlib.sha1('\0'.join(flags).encode()).hexdigest()[:12]


def up_to_date(obj, dep):
    if not obj.exists() or not dep.exists():
        return False
    t = obj.stat().st_mtime
    text = dep.read_text().replace('\\\n', ' ')
    for path in text.split(':', 1)[1].split():
        try:
            if os.stat(path).st_mtime > t:
                return False
        except FileNotFoundError:
            return False
    return True


def compile_one(src, tag):
    obj = OUT / 'obj' / tag / (src.replace('/', '__') + '.o')
    dep, log = obj.with_suffix('.d'), obj.with_suffix('.log')
    if up_to_date(obj, dep):
        return src, obj, True
    obj.parent.mkdir(parents=True, exist_ok=True)
    extra = ['-I', str(ROOT / 'lib' / 'ultralib' / 'include' / 'PR')] if src.startswith('lib/ultralib/') else []
    r = run([CLANG] + GUEST_FLAGS + extra + ['-MMD', '-MF', str(dep), '-c', str(ROOT / src), '-o', str(obj)])
    if r.returncode != 0:
        log.write_text(r.stderr)
        if obj.exists():
            obj.unlink()
        return src, obj, False
    if log.exists():
        log.unlink()
    return src, obj, True


def nm(objs):
    """Defined symbols (name -> kind letter) and undefined names of LTO objects."""
    defined, undef = {}, set()
    for i in range(0, len(objs), 200):
        r = run([LLVM_NM, '--no-sort'] + [str(o) for o in objs[i:i + 200]])
        for line in r.stdout.splitlines():
            parts = line.split()
            if len(parts) == 2 and parts[0] == 'U':
                undef.add(parts[1])
            elif len(parts) == 3 and parts[1].isupper():  # static symbols do not satisfy other files
                defined[parts[2]] = parts[1]
    return defined, undef - set(defined)


def n64_sections():
    """Symbol -> 'text' or 'data' from the N64 link map, and symbol -> address."""
    kinds, addrs, current = {}, {}, None
    sec = re.compile(r'^ \.?(\w+)\s+0x[0-9a-f]+\s+0x[0-9a-f]+\s')
    sym = re.compile(r'^\s{16}0x([0-9a-f]+)\s+([A-Za-z_][\w.$]*)\s*$')
    mp = ROOT / 'build' / 'us' / 'banjotooie_decompressed.map'
    for line in open(mp, errors='replace'):
        m = sec.match(line)
        if m:
            current = 'text' if m.group(1) == 'text' else 'data'
            continue
        m = sym.match(line)
        if m and current:
            kinds.setdefault(m.group(2), current)
            addrs.setdefault(m.group(2), int(m.group(1), 16) & 0xFFFFFFFF)
    return kinds, addrs


def c_types(objs):
    """C declarations of the asm data labels (irtypes.py), cached next to each object."""
    def one(o):
        o = pathlib.Path(o)
        t = o.with_suffix('.types')
        if not t.exists() or t.stat().st_mtime < o.stat().st_mtime:
            r = run([LLVM_BIN + '/llvm-dis', str(o), '-o', '-'])
            t.write_text('\n'.join(l for l in r.stdout.splitlines() if l[:1] in '@%'))
        return irtypes.declarations(t.read_text().splitlines())
    with cf.ThreadPoolExecutor(os.cpu_count()) as ex:
        return irtypes.merge(ex.map(one, objs))


def data_files():
    ld = (ROOT / 'banjotooie.ld').read_text()
    # asm/data from splat plus the bss files kept next to the C sources (src/**/core*bss*.s).
    return sorted({str(ROOT / m) for m in re.findall(r'build/us/((?:asm/data|src)/[^ )]+\.s)\.o', ld)})


def host_imports():
    """Names the guest runtime takes from the host (declared with BT_HOST)."""
    names = set()
    for p in (HERE / 'guest').glob('*.[ch]'):
        text = p.read_text()
        names |= {'host_' + n for n in re.findall(r'BT_HOST\((\w+)\)', text)}
        names |= {'host_' + n for n in re.findall(r'^LIBM[12]\((\w+)', text, re.M)}
        names |= {'host_' + n for n in re.findall(r'\) LIBM[12]\((\w+)', text)}
    return names


CALL_CHECK = '''#define CHECK_CALL_INDIRECT(table, ft, x)                       \\
  (LIKELY((x) < table.size && ft == table.data[x].func_type) || \\
   func_types_eq_slowpath(&(table), ft, x))'''
# The N64 calls through function pointers whatever their declared signature (the arguments are
# in registers); the callers here do the same, so only a missing function traps.
CALL_CHECK_N64 = '''#define CHECK_CALL_INDIRECT(table, ft, x) \\
  (LIKELY((x) < table.size && table.data[x].func) || (TRAP(CALL_INDIRECT), 0))'''


def write_if_changed(path, text):
    if path.exists() and path.read_text() == text:
        return False
    path.write_text(text)
    return True


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('-j', type=int, default=os.cpu_count())
    ap.add_argument('--run', action='store_true', help='run the game after building')
    ap.add_argument('rest', nargs='*')
    args = ap.parse_args()
    gen = OUT / 'gen'
    gen.mkdir(parents=True, exist_ok=True)
    aliases = run([sys.executable, str(NATIVE / 'generate_overlay_aliases.py'),
                   str(ROOT / 'overlays.us.toml'), str(gen / 'overlay_aliases.h.tmp')])
    if aliases.returncode != 0:
        sys.exit(aliases.stderr)
    write_if_changed(gen / 'overlay_aliases.h', (gen / 'overlay_aliases.h.tmp').read_text())

    # 1. Guest objects.
    tag = flags_hash(GUEST_FLAGS)
    srcs = sources()
    with cf.ThreadPoolExecutor(args.j) as ex:
        results = list(ex.map(lambda s: compile_one(s, tag), srcs))
    objs = [o for _, o, ok in results if ok]
    failed = [s for s, _, ok in results if not ok]
    (OUT / 'compile_failures.txt').write_text(''.join(s + '\n' for s in failed))
    game_total = sum(1 for s in srcs if s.startswith('src/'))
    game_ok = sum(1 for s, _, ok in results if ok and s.startswith('src/'))
    print('guest: %d/%d game files compile, %d native/runtime files' % (game_ok, game_total, len(objs) - game_ok))
    for s in failed:
        if not s.startswith('src/'):
            print('  runtime file failed: %s (%s)' % (s, OUT / 'obj' / tag / (s.replace('/', '__') + '.log')))

    # 2. Data and traps.
    defined, undef = nm(objs)
    n64, n64_addr = n64_sections()
    labels = set()
    files = data_files()
    for f in files:
        for sec, lab, _ in data.parse_file(f):
            if sec.lstrip('.') != 'text':
                labels |= set(lab)
    c_data = {n for n, k in defined.items() if k.upper() in 'DBRCV'}

    def is_function(name):
        if name in labels or name in c_data:
            return False
        if name in defined:
            return defined[name].upper() == 'T'
        return n64.get(name, 'text') == 'text'

    alias = dict(re.findall(r'^#define (\w+) (\w+)$', (gen / 'overlay_aliases.h').read_text(), re.M))
    ddef, _, unresolved = data.generate(files, set(defined), is_function, gen / 'data.ll.tmp', alias, c_types(objs))
    write_if_changed(gen / 'data.ll', (gen / 'data.ll.tmp').read_text())
    imports = host_imports()
    data_refs = set(re.findall(r'^declare void @"([^"]+)"', (gen / 'data.ll').read_text(), re.M))
    data_refs |= set(re.findall(r'^@"([^"]+)" = external global', (gen / 'data.ll').read_text(), re.M))
    # Symbols the N64 linker script defines (undefined_syms.us.txt: A = B; A = B + off; A = 0xaddr;).
    # The FixCalls pass points them into the object that holds them, or makes them plain numbers.
    have = sorted((a, n) for n, a in n64_addr.items() if n in defined or n in ddef)
    linker_syms = []
    for n, expr in re.findall(r'^\s*(\w+)\s*=\s*([^;]+);', (ROOT / 'undefined_syms.us.txt').read_text(), re.M):
        m = re.fullmatch(r'([A-Za-z_]\w*)(?:\s*\+\s*(0x[0-9A-Fa-f]+|\d+))?', expr.strip())
        if m:
            base, off = alias.get(m.group(1), m.group(1)), int(m.group(2) or '0', 0)
            if base not in ddef and base in n64_addr and off:
                # A table addressed as code + offset (ch/intro/char): natively the bytes are not
                # behind the code, so anchor it to the overlay's nearest data label instead.
                v, ovl = n64_addr[base] + off, base.rsplit('_', 1)[-1]
                near = [(abs(a - v), d, a) for d, a in n64_addr.items() if d in ddef and d.endswith('_' + ovl)]
                if near:
                    _, base, a = min(near)
                    off = v - a
            linker_syms.append('%s %s %d' % (n, base, off))
            continue
        v = int(expr.strip(), 0)
        i = bisect.bisect_right(have, (v, '\uffff')) - 1
        if 0x80000000 <= v < 0x80800000 and i >= 0 and v - have[i][0] < 0x10000:
            linker_syms.append('%s %s %d' % (n, have[i][1], v - have[i][0]))
        else:
            linker_syms.append('%s = %d' % (n, v))
    write_if_changed(gen / 'linker_syms.txt', '\n'.join(linker_syms) + '\n')
    missing = sorted({alias.get(n, n) for n in undef | data_refs} - set(defined) - ddef - imports
                     - {l.split()[0] for l in linker_syms})
    funcs = [n for n in missing if is_function(n)]
    datas = [n for n in missing if not is_function(n)]
    stub = ['// Generated by pc/native/wasm/build.py: functions and data no compiled file defines.',
            'void bt_unported(const char *name);', '']
    stub += ['void %s() { bt_unported("%s"); }' % (n, n) for n in funcs]
    # shortcut: unknown data gets 4 KB of zeros; it belongs to a file that does not compile yet.
    stub += ['__attribute__((aligned(16))) char %s[0x1000];' % n for n in datas]
    write_if_changed(gen / 'traps.c', '\n'.join(stub) + '\n')
    (OUT / 'traps.txt').write_text(''.join('function %s\n' % n for n in funcs) + ''.join('data %s\n' % n for n in datas))
    print('data: %d asm files, %d symbols; traps: %d functions, %d data' % (len(files), len(ddef), len(funcs), len(datas)))
    extra = []
    for src in (gen / 'data.ll', gen / 'traps.c'):
        obj = OUT / 'obj' / (src.name + '.o')
        if not obj.exists() or obj.stat().st_mtime < src.stat().st_mtime:
            r = run([CLANG] + GUEST_FLAGS + ['-c', str(src), '-o', str(obj)])
            if r.returncode != 0:
                sys.exit('%s failed:\n%s' % (src, r.stderr[:4000]))
        extra.append(obj)

    # 3. Link, fix call signatures, optimize, translate.
    plugin = OUT / 'FixCalls.dylib'
    cpp = HERE / 'fixcalls' / 'FixCalls.cpp'
    if not plugin.exists() or plugin.stat().st_mtime < cpp.stat().st_mtime:
        cxxflags = run([LLVM_BIN + '/llvm-config', '--cxxflags']).stdout.split()
        libdir = run([LLVM_BIN + '/llvm-config', '--libdir']).stdout.strip()
        tmp = plugin.with_suffix('.tmp')
        r = run([LLVM_BIN + '/clang++', '-shared', '-fPIC'] + cxxflags + [str(cpp), '-o', str(tmp),
                 '-L' + libdir, '-lLLVM', '-Wl,-rpath,' + libdir])
        if r.returncode != 0:
            sys.exit('FixCalls plugin failed:\n' + r.stderr[:4000])
        if sys.platform == 'darwin':  # opt only loads signed libraries; this linker leaves it unsigned
            run(['codesign', '-s', '-', '-f', str(tmp)])
        os.replace(tmp, plugin)
    linked, fixed = OUT / 'game.linked.bc', OUT / 'game.bc'
    r = run([LLVM_BIN + '/llvm-link', '-o', str(linked)] + [str(o) for o in objs + extra])
    if r.returncode != 0:
        sys.exit('llvm-link failed:\n' + r.stderr[:8000])
    (OUT / 'widened.txt').unlink(missing_ok=True)
    r = run([LLVM_BIN + '/opt', '--load-pass-plugin=%s' % plugin, 
             # Inlining turns calls through function pointers into direct calls that may mismatch
             # again, so the fix runs before and after the optimization pipeline.
             '-passes=bt-fixcalls,internalize,default<O2>,bt-fixcalls', '-bt-abs-syms=%s' % (gen / 'linker_syms.txt'), '-bt-widened=%s' % (OUT / 'widened.txt'),
             '-internalize-public-api-list=' + ','.join(EXPORTS + LIBCALLS), str(linked), '-o', str(fixed)]
            # BT_NOINLINE=1: keeps every function separate, so crash backtraces name the real function.
            + (['-inline-threshold=-100000'] if os.environ.get('BT_NOINLINE') else []))
    if r.returncode != 0:
        sys.exit('opt failed:\n' + r.stderr[:8000])
    wasm = OUT / 'game.wasm'
    link = [WASM_LD, '--no-entry', '--lto-O0', '--lto-CGO2', '-o', str(wasm), '-Map=%s' % (OUT / 'game.map'),
            '--global-base=%d' % GLOBAL_BASE, '--initial-memory=%d' % MEMORY_END,
            '--max-memory=%d' % (1 << 32), '--export-table', '--export=__stack_pointer',
            '--export=__heap_base'] + ['--export=' + e for e in EXPORTS] + [
            '--error-limit=0', str(fixed)]
    r = run(link)
    if r.returncode != 0:
        sys.exit('wasm-ld failed:\n' + r.stderr[:8000])
    warnings = [l for l in r.stderr.splitlines() if 'warning' in l]
    if warnings:
        (OUT / 'link_warnings.txt').write_text(r.stderr)
        print('link: %d warnings (%s)' % (len(warnings), OUT / 'link_warnings.txt'))
    tmp = OUT / 'w2c'
    tmp.mkdir(exist_ok=True)
    r = run([WASM2C, str(wasm), '-n', 'bt', '--num-outputs', str(GEN_OUTPUTS), '-o', str(tmp / 'game.c')])
    if r.returncode != 0:
        sys.exit('wasm2c failed:\n' + r.stderr[:8000])
    for p in sorted(tmp.iterdir()):
        text = p.read_text()
        if p.name == 'game-impl.h':
            assert CALL_CHECK in text, 'wasm2c changed its CALL_INDIRECT check'
            text = text.replace(CALL_CHECK, CALL_CHECK_N64)
        write_if_changed(gen / p.name, text)

    # 4. Host executable.
    host_srcs = sorted((HERE / 'host').glob('*.c'))
    gen_srcs = sorted(gen.glob('game_*.c')) or [gen / 'game.c']
    rt_srcs = [WASM2C_RT / 'wasm-rt-impl.c', WASM2C_RT / 'wasm-rt-mem-impl.c']

    def host_obj(src):
        obj = OUT / 'host' / (src.name + '.o')
        dep = obj.with_suffix('.d')
        if up_to_date(obj, dep):
            return obj, None
        obj.parent.mkdir(exist_ok=True)
        r = run([CLANG] + HOST_FLAGS + ['-MMD', '-MF', str(dep), '-c', str(src), '-o', str(obj)])
        return obj, (r.stderr if r.returncode else None)

    with cf.ThreadPoolExecutor(args.j) as ex:
        built = list(ex.map(host_obj, host_srcs + gen_srcs + rt_srcs))
    errors = [e for _, e in built if e]
    if errors:
        sys.exit('host compile failed:\n' + '\n'.join(errors)[:8000])
    exe = OUT / 'bt_game'
    r = run([CLANG, '-o', str(exe)] + [str(o) for o, _ in built] + ['-lz', '-lm', '-lpthread'])
    if r.returncode != 0:
        sys.exit('host link failed:\n' + r.stderr[:8000])
    print('built %s' % exe)
    if args.run:
        os.execv(str(exe), [str(exe)] + (args.rest or [str(ROOT / 'baserom.us.z64')]))


if __name__ == '__main__':
    main()
