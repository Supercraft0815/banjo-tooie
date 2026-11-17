#!/usr/bin/env python3
"""ILP32 build of the native port.

Game C (src/), the native modules (pc/native/*.c) and the guest runtime are
compiled for wasm32 (32-bit pointers, N64 struct layouts) as LTO bitcode, linked
with the converted asm data and generated traps, translated to C by wasm2c and
built with the host platform layer into one native executable:

    python3 pc/native/wasm/build.py [all|guest|host] [-j N] [--run] [-- ROM args]

BT_LLVM_BIN selects the LLVM bin directory; BT_WABT and BT_SDL3 select installation
prefixes. Otherwise tools come from PATH, with Homebrew as a macOS fallback.
The host stage needs gen/, clang >= 19, WABT's C runtime and SDL3.

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
import shlex
import shutil
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[3]
HERE = pathlib.Path(__file__).resolve().parent
NATIVE = HERE.parent
# BT_OUT: separate output tree for diagnostic builds (BT_XSYM=1), so the reference build stays.
OUT = pathlib.Path(os.environ.get('BT_OUT', ROOT / 'build' / 'ilp32')).resolve()
sys.path.insert(0, str(HERE))
import trace_tools  # noqa: E402

def tool(name):
    prefix = os.environ.get('BT_WABT') if name == 'wasm2c' else os.environ.get('BT_LLVM_BIN')
    if prefix:
        directory = pathlib.Path(prefix) / 'bin' if name == 'wasm2c' else pathlib.Path(prefix)
        return str(directory / (name + ('.exe' if sys.platform == 'win32' else '')))
    found = shutil.which(name)
    if found:
        return found
    if sys.platform == 'darwin':
        for directory in ('/opt/homebrew/opt/llvm/bin', '/opt/homebrew/bin',
                          '/usr/local/opt/llvm/bin', '/usr/local/bin'):
            candidate = pathlib.Path(directory) / name
            if candidate.is_file():
                return str(candidate)
    return name  # Only the selected stage validates its tools; host builds need no opt/wasm2c.


def sdl_flags():
    prefix = os.environ.get('BT_SDL3')
    if prefix:
        return ['-I', str(pathlib.Path(prefix) / 'include')], ['-L' + str(pathlib.Path(prefix) / 'lib'), '-lSDL3']
    pkg = shutil.which('pkg-config')
    if pkg:
        cflags = subprocess.run([pkg, '--cflags', 'sdl3'], capture_output=True, text=True)
        libs = subprocess.run([pkg, '--libs', 'sdl3'], capture_output=True, text=True)
        if cflags.returncode == libs.returncode == 0:
            return shlex.split(cflags.stdout), shlex.split(libs.stdout)
    if sys.platform == 'darwin':
        for prefix in ('/opt/homebrew', '/usr/local'):
            if (pathlib.Path(prefix) / 'include/SDL3/SDL.h').is_file():
                return ['-I', prefix + '/include'], ['-L' + prefix + '/lib', '-lSDL3']
    return [], ['-lSDL3']


CLANG = tool('clang')
WASM_LD = tool('wasm-ld')
LLVM_BIN = str(pathlib.Path(tool('llvm-config')).parent)
LLVM_NM = tool('llvm-nm')
WASM2C = tool('wasm2c')
WABT_PREFIX = pathlib.Path(os.environ.get('BT_WABT', pathlib.Path(WASM2C).parent.parent))
WASM2C_RT = WABT_PREFIX / 'share/wabt/wasm2c'
WASM2C_INC = WABT_PREFIX / 'include'
SDL_CFLAGS, SDL_LIBS = sdl_flags()
PLATFORM_LIBS = {'darwin': ['-framework', 'OpenGL'], 'linux': ['-lGL', '-ldl'],
                 'win32': ['-lopengl32', '-lws2_32']}
PLUGIN_NAME = 'FixCalls' + ('.dylib' if sys.platform == 'darwin' else '.dll' if sys.platform == 'win32' else '.so')

GLOBAL_BASE = 0x80001000      # guest pointers look like N64 KSEG0 addresses
MEMORY_END = 0x90000000       # 256 MB of game memory; physical addresses stay below the graphics tokens
GEN_OUTPUTS = 16              # wasm2c output files, compiled in parallel
EXPORTS = ['bt_guest_start', 'bt_guest_boot_stack_top', 'bt_be_fixup']
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
    # -fwrapv-pointer: IDO code adds unsigned "negative" offsets to pointers (p + 0xFFFFFFF1); with
    # inbounds GEPs the wasm backend folds them into the load offset, past the 4 GiB memory.
    '-fno-builtin', '-fno-strict-aliasing', '-fwrapv', '-fwrapv-pointer', '-w',
    '-Wno-implicit-function-declaration', '-Wno-int-conversion',
    '-Wno-incompatible-pointer-types', '-Wno-return-mismatch', '-Wno-implicit-int',
]
if os.environ.get('BT_HEAPCHECK'):  # diagnostic build: the arena checks every header on each alloc/free
    GUEST_FLAGS.append('-DBT_HEAP_CHECK=1')
HOST_FLAGS = ['-O2', '-g', '-I', str(WASM2C_INC), '-I', str(WASM2C_RT), '-I', str(OUT / 'gen'),
              '-I', str(HERE / 'host')] + SDL_CFLAGS + ['-DWASM_RT_MEMCHECK_GUARD_PAGES=1',
              '-DBT_GPU_OPENGL=1', '-DWASM_RT_TRAP_HANDLER=bt_trap'] + shlex.split(os.environ.get('BT_HOST_FLAGS', ''))

IMGUI = NATIVE / "third_party/imgui"
CXX = tool("clang++")

AUDIO_DEBUG = os.environ.get('BT_AUDIO_DEBUG') == '1'
if AUDIO_DEBUG:
    HOST_FLAGS.append('-DBT_AUDIO_DEBUG=1')


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
    # sinf/cosf come from the host: their constants are big-endian {hi, lo} double halves.
    gu = ['lib/ultralib/src/gu/%s.c' % n for n in (
        'coss', 'sins', 'lookat', 'lookathil', 'lookatref', 'perspective', 'rotate',
        'rotaterpy', 'scale', 'translate', 'mtxcatf', 'mtxcatl', 'normalize', 'position', 'poslight',
        'poslighthil', 'frustum', 'align', 'random')]
    # Keep libultra's callback formatter, including its float/exponent formatting.
    formatting = ['lib/ultralib/src/libc/%s.c' % name for name in ('xprintf', 'xlitob', 'xldtob', 'ldiv')]
    return game + native + guest + gu + formatting


def flags_hash(flags):
    return hashlib.sha1('\0'.join(flags).encode()).hexdigest()[:12]


def guest_object_tag(compiler_version=None):
    if compiler_version is None:
        compiler_version = run([CLANG, '--version'], check=True).stdout.strip()
    bitfields = hashlib.sha1((HERE / 'bitfields.py').read_bytes()).hexdigest()
    return flags_hash([CLANG, compiler_version, *GUEST_FLAGS, bitfields])


def guest_pipeline(disabled, xsym):
    passes = ['function(mem2reg)', 'bt-fixcalls']
    if xsym:
        passes.append('bt-xsym')
    passes += ['bt-bigendian', 'bt-datagroup', 'bt-stackslots', 'internalize',
               'bt-safepoints', 'default<O2>', 'bt-fixcalls']
    omit = {'bt-' + name.strip().removeprefix('bt-') for name in disabled.split(',') if name.strip()}
    unknown = omit - {p for p in passes if p.startswith('bt-')} - {'bt-xsym'}
    if unknown:
        raise ValueError('BT_PASS_OFF: unknown pass ' + ', '.join(sorted(unknown)))
    if 'bt-fixcalls' in omit:
        passes[1] = 'bt-linker-symbols'
    return ','.join(p for p in passes if p not in omit)


def up_to_date(obj, dep):
    if not obj.exists() or not dep.exists():
        return False
    t = obj.stat().st_mtime
    text = dep.read_text().replace('\\\n', ' ')
    for path in shlex.split(text.split(': ', 1)[1]):
        try:
            if os.stat(path).st_mtime > t:
                return False
        except FileNotFoundError:
            return False
    return True


def compile_one(src, tag):
    import bitfields

    obj = OUT / 'obj' / tag / (src.replace('/', '__') + '.o')
    dep, log = obj.with_suffix('.d'), obj.with_suffix('.log')
    if up_to_date(obj, dep):
        return src, obj, True
    obj.parent.mkdir(parents=True, exist_ok=True)
    extra = ['-I', str(ROOT / 'lib' / 'ultralib' / 'include' / 'PR')] if src.startswith('lib/ultralib/') else []
    cmd = [CLANG] + GUEST_FLAGS + extra
    if src.startswith('src/'):
        # Game code: bitfields get the N64 bit order (bitfields.py) between preprocessing and compiling.
        pre = obj.with_suffix('.i')
        r = run(cmd + ['-MMD', '-MF', str(dep), '-MT', str(obj), '-E', str(ROOT / src), '-o', str(pre)])
        if r.returncode == 0:
            text = pre.read_text()
            if re.search(r'\w\s*:\s*\d+\s*[;,]', text):
                def dump(t):
                    return run([CLANG, '--target=wasm32-unknown-unknown', '-w', '-fsyntax-only', '-x', 'cpp-output',
                                '-Xclang', '-fdump-record-layouts-complete', '-'], input=t).stdout
                text, notes = bitfields.rewrite(text, dump, (str(ROOT / 'src'), str(ROOT / 'include')))
                pre.write_text(text)
                obj.with_suffix('.bitfields').write_text(''.join(n + '\n' for n in notes))
            r = run(cmd + ['-x', 'cpp-output', '-c', str(pre), '-o', str(obj)])
    else:
        r = run(cmd + ['-MMD', '-MF', str(dep), '-c', str(ROOT / src), '-o', str(obj)])
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
    """Symbol -> 'text' or 'data' from the N64 link map, symbol -> address, and the segment
    ROM addresses (name_ROM_START = __romPos)."""
    kinds, addrs, roms, current = {}, {}, {}, None
    sec = re.compile(r'^ \.?(\w+)\s+0x[0-9a-f]+\s+0x[0-9a-f]+\s')
    sym = re.compile(r'^\s{16}0x([0-9a-f]+)\s+([A-Za-z_][\w.$]*)\s*$')
    rom = re.compile(r'^\s{16}0x([0-9a-f]+)\s+(\w+_ROM_(?:START|END))\s*=')
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
        m = rom.match(line)
        if m:
            roms.setdefault(m.group(2), int(m.group(1), 16))
    return kinds, addrs, roms


def c_types(objs):
    """C declarations of the asm data labels (irtypes.py), cached next to each object."""
    import irtypes
    def one(o):
        o = pathlib.Path(o)
        t = o.with_suffix('.types')
        if not t.exists() or t.stat().st_mtime < o.stat().st_mtime:
            r = run([tool('llvm-dis'), str(o), '-o', '-'])
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
# Loop latches call env.safepoint (bt-safepoints); only a pending preemption takes the call.
SAFEPOINT_CALL = 'w2c_env_safepoint(instance->w2c_env_instance);'
SAFEPOINT = '''
extern unsigned bt_preempt_flag;
#define BT_SAFEPOINT(env) \\
  do { if (UNLIKELY(__atomic_load_n(&bt_preempt_flag, __ATOMIC_RELAXED))) w2c_env_safepoint(env); } while (0)
'''
CALL_CHECK_N64 = '''#define CHECK_CALL_INDIRECT(table, ft, x) \\
  (LIKELY((x) < table.size && table.data[x].func) || (TRAP(CALL_INDIRECT), 0))'''


def write_if_changed(path, text):
    if path.exists() and path.read_text() == text:
        return False
    path.write_text(text)
    return True


def build_guest(jobs, compiler_version):
    import data
    import o32_thunks

    gen = OUT / 'gen'
    gen.mkdir(parents=True, exist_ok=True)
    aliases = run([sys.executable, str(NATIVE / 'generate_overlay_aliases.py'),
                   str(ROOT / 'overlays.us.toml'), str(gen / 'overlay_aliases.h.tmp')])
    if aliases.returncode != 0:
        sys.exit(aliases.stderr)
    write_if_changed(gen / 'overlay_aliases.h', (gen / 'overlay_aliases.h.tmp').read_text())

    # 1. Guest objects.
    tag = guest_object_tag(compiler_version)
    srcs = sources()
    with cf.ThreadPoolExecutor(jobs) as ex:
        results = list(ex.map(lambda s: compile_one(s, tag), srcs))
    objs = [o for _, o, ok in results if ok]
    failed = [s for s, _, ok in results if not ok]
    (OUT / 'compile_failures.txt').write_text(''.join(s + '\n' for s in failed))
    game_total = sum(1 for s in srcs if s.startswith('src/'))
    game_ok = sum(1 for s, _, ok in results if ok and s.startswith('src/'))
    print('guest: %d/%d game files compile, %d native/runtime files' % (game_ok, game_total, len(objs) - game_ok))
    for s in failed:
        if not s.startswith('src/'):
            sys.exit('runtime file failed: %s (%s)' % (s, OUT / 'obj' / tag / (s.replace('/', '__') + '.log')))

    # 2. Data and traps.
    defined, undef = nm(objs)
    n64, n64_addr, n64_rom = n64_sections()
    labels = set()
    files = data_files()
    c_data = {n for n, k in defined.items() if k.upper() in 'DBRCV'}
    if os.environ.get('BT_NO_ASMDATA') == '1':
        files = data.strict_inputs(files, c_data, ROOT, (ROOT / 'baserom.us.yaml').read_text(),
                                   OUT / 'remaining_asm_data.tsv')
    for f in files:
        for sec, lab, _ in data.parse_file(f):
            if sec.lstrip('.') != 'text':
                labels |= set(lab)

    def is_function(name):
        if name in labels or name in c_data:
            return False
        if name in defined:
            return defined[name].upper() == 'T'
        return n64.get(name, 'text') == 'text'

    alias = dict(re.findall(r'^#define (\w+) (\w+)$', (gen / 'overlay_aliases.h').read_text(), re.M))
    ddef, _, unresolved = data.generate(files, set(defined), is_function, gen / 'data.ll.tmp', alias, c_types(objs),
                                         {n: n64_addr[n] for n in c_data if n in n64_addr})
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
    named = {l.split()[0] for l in linker_syms}
    linker_syms += ['%s = %d' % (n, v) for n, v in sorted(n64_rom.items()) if n in undef and n not in defined and n not in named]
    write_if_changed(gen / 'linker_syms.txt', '\n'.join(linker_syms) + '\n')
    missing = sorted({alias.get(n, n) for n in undef | data_refs} - set(defined) - ddef - imports
                     - {l.split()[0] for l in linker_syms})
    funcs = [n for n in missing if is_function(n)]
    datas = [n for n in missing if not is_function(n)]
    if datas:
        sys.exit('unresolved guest data (zero placeholders are forbidden): ' + ', '.join(datas))
    stub = ['// Generated by pc/native/wasm/build.py: functions and data no compiled file defines.',
            'void bt_unported(const char *name);', '']
    stub += ['void %s() { bt_unported("%s"); }' % (n, n) for n in funcs]
    write_if_changed(gen / 'traps.c', '\n'.join(stub) + '\n')
    (OUT / 'traps.txt').write_text(''.join('function %s\n' % n for n in funcs) + ''.join('data %s\n' % n for n in datas))
    print('data: %d asm files, %d symbols; traps: %d functions, %d data' % (len(files), len(ddef), len(funcs), len(datas)))
    extra = []
    for src in (gen / 'data.ll', gen / 'traps.c'):
        obj = OUT / 'obj' / tag / (src.name + '.o')
        if not obj.exists() or obj.stat().st_mtime < src.stat().st_mtime:
            r = run([CLANG] + GUEST_FLAGS + ['-c', str(src), '-o', str(obj)])
            if r.returncode != 0:
                sys.exit('%s failed:\n%s' % (src, r.stderr[:4000]))
        extra.append(obj)

    # 3. Link, fix call signatures, optimize, translate.
    plugin = OUT / PLUGIN_NAME
    cpp = HERE / 'fixcalls' / 'FixCalls.cpp'
    llvm_version = run([tool('llvm-config'), '--version'])
    if llvm_version.returncode:
        sys.exit('llvm-config failed: ' + llvm_version.stderr)
    plugin_tag = flags_hash([tool('clang++'), tool('llvm-config'), llvm_version.stdout, compiler_version])
    stamp = plugin.with_suffix(plugin.suffix + '.flags')
    if (not plugin.exists() or not stamp.exists() or stamp.read_text() != plugin_tag or
            plugin.stat().st_mtime < max(cpp.stat().st_mtime, pathlib.Path(__file__).stat().st_mtime)):
        cxxflags = shlex.split(run([tool('llvm-config'), '--cxxflags']).stdout)
        libdir = run([tool('llvm-config'), '--libdir']).stdout.strip()
        tmp = plugin.with_suffix('.tmp')
        # lld: ld64's output fails to load in opt on newer macOS (mis-aligned LINKEDIT string pool)
        r = run([tool('clang++'), '-shared', '-fPIC', '-fuse-ld=lld'] + cxxflags + [str(cpp), '-o', str(tmp),
                 '-L' + libdir, '-lLLVM', '-Wl,-rpath,' + libdir])
        if r.returncode != 0:
            sys.exit('FixCalls plugin failed:\n' + r.stderr[:4000])
        if sys.platform == 'darwin':  # opt only loads signed libraries; this linker leaves it unsigned
            run(['codesign', '-s', '-', '-f', str(tmp)])
        os.replace(tmp, plugin)
        stamp.write_text(plugin_tag)
    linked, fixed = OUT / 'game.linked.bc', OUT / 'game.bc'
    r = run([tool('llvm-link'), '-o', str(linked)] + [str(o) for o in objs + extra])
    if r.returncode != 0:
        sys.exit('llvm-link failed:\n' + r.stderr[:8000])
    (OUT / 'widened.txt').unlink(missing_ok=True)
    r = run([tool('opt'), '--load-pass-plugin=%s' % plugin,
             # Inlining turns calls through function pointers into direct calls that may mismatch
             # again, so the fix runs before and after the optimization pipeline. Safepoints go in
             # before it: an opaque call per loop latch keeps loads of data other threads write
             # inside wait loops, as preemption anywhere on the N64 does.
             '-passes=' + guest_pipeline(os.environ.get('BT_PASS_OFF', ''), os.environ.get('BT_XSYM')),
             '-bt-abs-syms=%s' % (gen / 'linker_syms.txt'), '-bt-widened=%s' % (OUT / 'widened.txt'), '-bt-xsym-sites=%s' % (OUT / 'xsym_sites.txt'),
             '-internalize-public-api-list=' + ','.join(EXPORTS + LIBCALLS), str(linked), '-o', str(fixed)]
            # BT_NOINLINE=1: keeps every function separate, so crash backtraces name the real function.
            + (['-inline-threshold=-100000'] if os.environ.get('BT_NOINLINE') else []))
    (OUT / 'stackslots.txt').write_text(''.join(line + '\n' for line in r.stderr.splitlines()
                                                if line.startswith('bt-stackslots:') and ': slot reached at' in line))
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
            assert CALL_CHECK in text and o32_thunks.CALL_OLD in text, 'wasm2c changed its CALL_INDIRECT check'
            text = text.replace(CALL_CHECK, CALL_CHECK_N64).replace(o32_thunks.CALL_OLD, o32_thunks.CALL_NEW) + SAFEPOINT
        text = text.replace(SAFEPOINT_CALL, 'BT_SAFEPOINT(instance->w2c_env_instance);')
        write_if_changed(gen / p.name, text)

    header, thunks = o32_thunks.generate(wasm, gen)  # indirect calls with another signature
    write_if_changed(gen / 'o32_thunks.h', header)
    write_if_changed(gen / 'o32.c', thunks)

    write_if_changed(gen / 'trace_symbols.h', trace_tools.trace_header(OUT, HERE, HOST_FLAGS))
    # Display lists address memory as segment + 24-bit offset (see platform/rdram.c).
    top = max(int(l.split()[0], 16) + int(l.split()[2], 16) for l in (OUT / 'game.map').read_text().splitlines()
              if re.match(r'[0-9a-f]{8} +[0-9a-f]+ +[0-9a-f]+ ', l))
    if top > 0x81000000 and not os.environ.get('BT_BIG'):
        sys.exit('guest data ends at 0x%x, above the 16 MB the RSP can address' % top)
    return gen


def build_host(jobs, gen, compiler_version):
    # 4. Host executable.
    write_if_changed(gen / 'trace_symbols.h', trace_tools.trace_header(OUT, HERE, [CLANG, CXX, compiler_version] + HOST_FLAGS, from_gen=True))
    tag = flags_hash([CLANG, compiler_version] + HOST_FLAGS)
    host_srcs = sorted((HERE / 'host').glob('*.c')) + [HERE / 'host/glad/gl.c']
    if not AUDIO_DEBUG:
        host_srcs.remove(HERE / 'host/rsp.c')
    ui_srcs = [HERE / 'host/menu.cpp', *(IMGUI / f for f in (
        'imgui.cpp', 'imgui_draw.cpp', 'imgui_widgets.cpp', 'imgui_tables.cpp',
        'backends/imgui_impl_sdl3.cpp', 'backends/imgui_impl_opengl3.cpp'))]
    gen_srcs = (sorted(gen.glob('game_*.c')) or [gen / 'game.c']) + [gen / 'o32.c']
    rt_srcs = [WASM2C_RT / 'wasm-rt-impl.c', WASM2C_RT / 'wasm-rt-mem-impl.c']

    def host_obj(src):
        obj = OUT / 'host' / tag / (src.name + '.o')
        dep = obj.with_suffix('.d')
        if up_to_date(obj, dep):
            return obj, None
        obj.parent.mkdir(parents=True, exist_ok=True)
        compiler = [CXX, '-std=c++11', '-I', str(IMGUI)] if src.suffix == '.cpp' else [CLANG]
        r = run(compiler + HOST_FLAGS + ['-MMD', '-MF', str(dep), '-c', str(src), '-o', str(obj)])
        return obj, (r.stderr if r.returncode else None)

    with cf.ThreadPoolExecutor(jobs) as ex:
        built = list(ex.map(host_obj, host_srcs + ui_srcs + gen_srcs + rt_srcs))
    errors = [e for _, e in built if e]
    if errors:
        sys.exit('host compile failed:\n' + '\n'.join(errors)[:8000])
    exe = OUT / ('bt_game.exe' if sys.platform == 'win32' else 'bt_game')
    r = run([CXX, '-o', str(exe)] + [str(o) for o, _ in built] + ['-lz', '-lm', '-lpthread'] + SDL_LIBS + PLATFORM_LIBS[sys.platform] + shlex.split(os.environ.get('BT_HOST_FLAGS', '')))
    if r.returncode != 0:
        sys.exit('host link failed:\n' + r.stderr[:8000])
    print('built %s' % exe)
    return exe


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('-j', type=int, default=os.cpu_count())
    ap.add_argument('--run', action='store_true', help='run the game after building')
    ap.add_argument('rest', nargs='*', help='optional stage (all, guest, host), then ROM and game arguments')
    args = ap.parse_args()
    stage = args.rest.pop(0) if args.rest and args.rest[0] in ('all', 'guest', 'host') else 'all'
    if args.j < 1:
        ap.error('-j must be positive')
    if stage == 'guest' and args.run:
        ap.error('--run requires the host stage')
    if args.rest and not args.run:
        ap.error('unexpected arguments: ' + ' '.join(args.rest))
    if sys.platform not in PLATFORM_LIBS:
        ap.error('unsupported host platform: ' + sys.platform)
    required = [CLANG] + ([CXX] if stage != 'guest' else [])
    if stage != 'host':
        required += [tool(name) for name in ('clang++', 'llvm-config', 'llvm-nm', 'llvm-dis', 'llvm-link', 'opt')]
        required += [WASM_LD, WASM2C]
    for name in required:
        if not shutil.which(name):
            ap.error('tool not found: %s (set BT_LLVM_BIN or BT_WABT)' % name)
    version = run([CLANG, '--version'])
    match = re.search(r'clang version (\d+)', version.stdout)
    if version.returncode or not match or int(match[1]) < 19:
        ap.error('clang >= 19 is required; got ' + (version.stdout + version.stderr).strip())
    gen = build_guest(args.j, version.stdout.strip()) if stage != 'host' else OUT / 'gen'
    if stage == 'guest':
        print('generated %s (host stage ready)' % gen)
        return
    needed = [gen / name for name in ('game.h', 'game-impl.h', 'o32.c', 'trace_symbols.h')] + [
              WASM2C_INC / 'wasm-rt.h', WASM2C_RT / 'wasm-rt-impl.c', WASM2C_RT / 'wasm-rt-mem-impl.c']
    missing = [str(path) for path in needed if not path.is_file()]
    if missing:
        ap.error('host inputs missing (run guest or set BT_WABT): ' + ', '.join(missing))
    exe = build_host(args.j, gen, version.stdout.strip())
    if args.run:
        os.execv(str(exe), [str(exe)] + (args.rest or [str(ROOT / 'baserom.us.z64')]))


if __name__ == '__main__':
    main()
