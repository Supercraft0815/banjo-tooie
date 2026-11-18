#!/usr/bin/env python3
"""Save fixtures checked against the original gl/crc.c, without ROM data."""
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE.parent))
import build
import save_editor as save


class SaveTest(unittest.TestCase):
    def test_original_crc(self):
        with tempfile.TemporaryDirectory(prefix='bt-save-test-') as tmp:
            directory = Path(tmp)
            source = directory / 'crc.c'
            # Independently spell the MIPS shifts in 1EF0140.s, then call the real C CRC loop.
            source.write_text('''#include <stdint.h>
#include <stdio.h>
typedef uint8_t u8; typedef uint32_t u32; typedef uint64_t u64; typedef int32_t s32;
typedef intptr_t BtIntPtr; typedef uintptr_t BtUIntPtr;
static s32 func_801168AC(u64 *s) {
    u64 a = ((*s << 63) >> 31) | ((*s << 31) >> 32);
    a ^= (*s << 44) >> 32;
    *s = a ^ ((a >> 20) & 0xfff);
    return (s32)*s;
}
#define __COMMON_H__
#include "''' + (save.ROOT / 'src/overlays/gl/crc.c').as_posix() + '''"
int main(int argc, char **argv) {
    u8 data[440]; u32 result[2]; FILE *f = fopen(argv[1], "rb");
    if (!f || fread(data, 1, sizeof data, f) != sizeof data) return 2;
    fclose(f); func_80800000_glcrc(data, data + sizeof data, result);
    printf("%08x%08x", result[0], result[1]); return 0;
}
''')
            exe = directory / 'crc'
            subprocess.run([build.CLANG, '-O2', '-Wno-int-to-void-pointer-cast', '-Wno-void-pointer-to-int-cast',
                            '-Wno-pointer-to-int-cast', '-Wno-int-to-pointer-cast', '-I', str(save.ROOT / 'include'),
                            str(source), '-o', str(exe)], check=True)
            for payload in (bytes(440), bytes(i % 256 for i in range(440)), save.new_record(2)[:-8]):
                file = directory / 'data'; file.write_bytes(payload)
                self.assertEqual(subprocess.check_output([str(exe), str(file)]).decode(), save.checksum(payload).hex())

    def test_editing(self):
        image = save.edit(bytes(2048), 1, [(0x392, True), (0xED, True)], create=True)
        block = image[256:704]; fields = save.records(block); flags, _ = fields[6]
        self.assertEqual(block[fields[2][0]], 2)
        bit = 0x392 - 0x28
        self.assertTrue(block[flags + bit // 8] & (1 << (bit & 7)))
        changed = save.edit(image, 1, [(0x392, False)])
        self.assertEqual(changed[:256], image[:256])
        self.assertEqual(changed[704:], image[704:])
        changed_block = changed[256:704]
        self.assertFalse(changed_block[flags + bit // 8] & (1 << (bit & 7)))
        save.records(changed_block)
        with self.assertRaisesRegex(ValueError, 'already exists'): save.edit(image, 1, [], True)
        with self.assertRaisesRegex(ValueError, 'permanent'): save.edit(image, 1, [(0x640, True)])
        with self.assertRaises(ValueError): save.edit(bytes(512), 0, [], True)
        bad = bytearray(image); bad[300] ^= 1
        with self.assertRaisesRegex(ValueError, 'checksum'): save.edit(bad, 1, [])
        duplicate = bytearray(image); duplicate[704:1152] = image[256:704]
        with self.assertRaisesRegex(ValueError, 'one valid'): save.edit(duplicate, 1, [])

    def test_cli_preserves_input(self):
        with tempfile.TemporaryDirectory(prefix='bt-save-cli-') as tmp:
            output = Path(tmp) / 'save.bin'
            command = [sys.executable, str(HERE.parent / 'save_editor.py'), str(output), '--create',
                       '--set-flag', 'FLAG_392_PROGRESS_OPENED_WORLD_MT']
            subprocess.run(command, check=True)
            before = output.read_bytes()
            self.assertEqual(subprocess.run(command, capture_output=True).returncode, 2)
            self.assertEqual(output.read_bytes(), before)


if __name__ == '__main__':
    unittest.main()
