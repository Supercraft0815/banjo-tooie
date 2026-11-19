// Native entry point: loads the ROM, instantiates the guest and runs its boot code.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guest.h"
#include "crash.h"
#include "plat.h"
#include "crash_build.h"
#include "mod_texture.h"

w2c_bt bt_inst;
u8 *bt_mem;
static struct w2c_env { int unused; } env;

void bt_call_guest(u32 fn, u32 arg, u32 thread) {
    wasm_rt_funcref_table_t *table = w2c_bt_0x5F_indirect_function_table(&bt_inst);
    if (fn >= table->size || !table->data[fn].func) bt_fatal("call to guest function %u outside the table", fn);
    wasm_rt_funcref_t entry = table->data[fn];
    if (entry.func_type == wasm2c_bt_get_func_type(1, 0, WASM_RT_I32)) {
        ((void (*)(void *, u32))entry.func)(entry.module_instance, arg);
    } else if (entry.func_type == wasm2c_bt_get_func_type(3, 0, WASM_RT_I32, WASM_RT_I32, WASM_RT_I32)) {
        // BT_PASS2 thread entries receive the low words of OSThread.context.a1/a2.
        ((void (*)(void *, u32, u32, u32))entry.func)(entry.module_instance, arg, gr32(thread + 0x44), gr32(thread + 0x4c));
    } else {
        bt_fatal("unexpected signature for guest thread entry %u", fn);
    }
}

#ifdef BT_CRASH_TEST
void w2c_bt_func_800D5D70(w2c_bt *instance);
#endif

int main(int argc, char **argv) {
    bt_settings_load();
    bt_mod_texture_init(getenv("BT_MOD_ORDER"));
    const char *version = getenv("BT_VERSION");
    const char *map_path = bt_path_env("BT_GAME_MAP");
    const char *native_map = bt_path_env("BT_NATIVE_MAP");
    bt_crash_init(version ? version : BT_BUILD_VERSION, map_path ? map_path : "game.map",
                  native_map ? native_map : BT_NATIVE_MAP_PATH);
    bt_video_init();
    const char *rom = argc > 1 ? argv[1] : bt_rom_find();
    if (argc > 1) bt_rom_open(rom);
    wasm_rt_init();
    wasm2c_bt_instantiate(&bt_inst, &env);
    bt_crash_install();
#ifdef BT_CRASH_TEST
    const char *crash_test = getenv("BT_CRASH_TEST");
    if (crash_test && !strcmp(crash_test, "fatal")) bt_fatal("A11 injected fatal test");
    if (crash_test && !strcmp(crash_test, "trap")) bt_trap(WASM_RT_TRAP_OOB);
#ifdef _WIN32
    if (crash_test && !strcmp(crash_test, "seh")) RaiseException(0xE0424242, 0, 0, NULL);
#endif
#endif
    bt_mem = bt_inst.w2c_memory.data;
    // Guest pointers start at 0x80000000; anything lower is a stray pointer.
    if (!bt_guard_low_memory(bt_mem)) bt_fatal("cannot protect low guest memory");
#ifdef BT_CRASH_TEST
    if (crash_test && (!strcmp(crash_test, "guesttrap") || !strcmp(crash_test, "guestsegv"))) {
        w2c_bt_func_800D5D70(&bt_inst);
    }
    if (crash_test && !strcmp(crash_test, "segv")) *(volatile int *)0 = 1;
#endif
    BT_SP = w2c_bt_bt_guest_boot_stack_top(&bt_inst);
    w2c_bt_bt_be_fixup(&bt_inst); // relocated words in the data, into big-endian order
    bt_trace_init(rom);
    bt_video_window();  // before any game thread: the GPU renderer shares the window's context
    w2c_bt_bt_guest_start(&bt_inst); // never returns: the boot context ends in osStartThread
    return 0;
}
