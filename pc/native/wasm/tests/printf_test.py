#!/usr/bin/env python3
"""Exercise the real libultra formatter through the guest's big-endian wasm pipeline."""
from pathlib import Path
import subprocess
import sys
import tempfile

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
import build


def main():
    with tempfile.TemporaryDirectory(prefix='bt-printf-test-') as tmp:
        directory = Path(tmp)
        source = directory / 'test.c'
        source.write_text('''#include <stdarg.h>
#include <stddef.h>
#include <string.h>
int _Printf(char *(*)(char *, const char *, size_t), char *, const char *, va_list);
static char buffer[2048];
static char *emit(char *p, const char *s, size_t n) { memcpy(p, s, n); p[n] = 0; return p + n; }
static int check(const char *expected, const char *fmt, ...) {
    va_list args; va_start(args, fmt);
    int n = _Printf(emit, buffer, fmt, args); va_end(args);
    return n == strlen(expected) && !strcmp(buffer, expected);
}
static char *reject(char *p, const char *s, size_t n) { return 0; }
static int rejected(const char *fmt, ...) {
    va_list args; va_start(args, fmt);
    int n = _Printf(reject, buffer, fmt, args); va_end(args); return n == 0;
}
int run_tests(void) {
    int bad = 0;
    if (!check("0000002a|-7|text", "%08x|%d|%s", 42, -7, "text")) bad |= 1;
    if (!check("1.25|1.25e+01|0.00125", "%.2f|%.2e|%.3g", 1.25, 12.5, .00125)) bad |= 2;
    if (!check("-9223372036854775807", "%lld", -9223372036854775807LL)) bad |= 4;
    if (!check("0x2a|  abc|A|%", "%#x|%5.3s|%c|%%", 42, "abcdef", 65)) bad |= 8;
    if (!rejected("failure: %d", 123)) bad |= 16;
    return bad;
}
''')
        files = [source, build.HERE / 'guest/libc.c'] + [build.ROOT / f'lib/ultralib/src/libc/{name}.c'
                                                            for name in ('xprintf', 'xlitob', 'xldtob', 'ldiv')]
        objects = []
        for i, file in enumerate(files):
            obj = directory / f'{i}.bc'
            subprocess.run([build.CLANG, *build.GUEST_FLAGS, '-I', str(build.ROOT / 'lib/ultralib/src/libc'),
                            '-I', str(build.ROOT / 'lib/ultralib/include/PR'),
                            '-c', str(file), '-o', str(obj)], check=True)
            objects.append(str(obj))
        linked, fixed = directory / 'linked.bc', directory / 'fixed.bc'
        subprocess.run([build.LLVM_BIN + '/llvm-link', *objects, '-o', str(linked)], check=True)
        subprocess.run([build.LLVM_BIN + '/opt', '--load-pass-plugin=' + str(build.OUT / 'FixCalls.dylib'),
                        '-passes=function(mem2reg),bt-bigendian,internalize,default<O2>',
                        '-internalize-public-api-list=run_tests,bt_be_fixup', str(linked), '-o', str(fixed)], check=True)
        wasm = directory / 'fmt.wasm'
        subprocess.run([build.WASM_LD, '--no-entry', '--lto-O0', '--export=run_tests', '--export=bt_be_fixup',
                        str(fixed), '-o', str(wasm)], check=True)
        subprocess.run([build.WASM2C, str(wasm), '-n', 'fmt', '-o', str(directory / 'fmt.c')], check=True)
        host = directory / 'host.c'
        host.write_text('''#include <stdio.h>
#include "fmt.h"
int main(void) {
    w2c_fmt instance; wasm_rt_init(); wasm2c_fmt_instantiate(&instance);
    w2c_fmt_bt_be_fixup(&instance);
    int result = w2c_fmt_run_tests(&instance);
    wasm2c_fmt_free(&instance); wasm_rt_free();
    if (result) fprintf(stderr, "libultra formatter failures: %d\\n", result);
    return result;
}
''')
        exe = directory / 'test'
        subprocess.run([build.CLANG, '-O2', '-I', str(build.WASM2C_INC), '-I', str(build.WASM2C_RT),
                        str(directory / 'fmt.c'), str(host), str(build.WASM2C_RT / 'wasm-rt-impl.c'),
                        str(build.WASM2C_RT / 'wasm-rt-mem-impl.c'), '-o', str(exe), '-lm', '-lpthread'], check=True)
        subprocess.run([str(exe)], check=True)
        print('libultra _Printf: integers, exponent/general floats, 64-bit values, padding and callback failure: PASS')


if __name__ == '__main__':
    main()
