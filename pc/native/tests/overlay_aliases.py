"""Link a syscall-name consumer to ordinary C definitions, including a callback."""
import importlib.util
import pathlib
import subprocess
import sys
import tempfile
import unittest

COMPILER, HEADER = sys.argv[1:]
sys.argv = sys.argv[:1]
spec = importlib.util.spec_from_file_location(
    "aliases", pathlib.Path(__file__).resolve().parents[1] / "generate_overlay_aliases.py")
aliases = importlib.util.module_from_spec(spec)
spec.loader.exec_module(aliases)


class NativeOverlayAliases(unittest.TestCase):
    def test_invalid_manifest_is_rejected(self):
        for names in [["foo", "foo"], ["foo", "_foo"], ["foo;bar"], [123]]:
            with self.subTest(names=names), self.assertRaises(ValueError):
                aliases.generate({"overlay": [{"entrypoints": names}]})

    def test_native_calls_preserve_float_and_pointer_arguments(self):
        # Separate translation units ensure the linker sees native symbols, not syscall stubs.
        with tempfile.TemporaryDirectory() as directory:
            root = pathlib.Path(directory)
            producer = root / "producer.c"
            producer.write_text("""
void batimer_incrementBy(void *state, int id, float step) {
    ((float *)state)[id] += step;
}
float batimer_get(void *state, int id) { return ((float *)state)[id]; }
""")
            consumer = root / "consumer.c"
            consumer.write_text("""
void _batimer_incrementBy(void *, int, float);
float _batimer_get(void *, int);
int main(void) {
    float state[2] = {1.0f, 2.0f};
    void (*callback)(void *, int, float) = _batimer_incrementBy;
    callback(state, 1, 0.25f);
    _batimer_incrementBy(state, 0, 0.5f);
    return _batimer_get(state, 0) != 1.5f || _batimer_get(state, 1) != 2.25f;
}
""")
            executable = root / "overlay-test"
            subprocess.run([COMPILER, "-DBT_NATIVE=1", "-include", HEADER,
                            str(producer), str(consumer), "-o", str(executable)], check=True)
            subprocess.run([str(executable)], check=True)


if __name__ == "__main__":
    unittest.main()
