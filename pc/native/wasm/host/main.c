// Native entry point: loads the ROM, instantiates the guest and runs its boot code.
#include <stdio.h>
#include <sys/mman.h>
#include "guest.h"

w2c_bt bt_inst;
u8 *bt_mem;
static struct w2c_env { int unused; } env;

void bt_call_guest(u32 fn, u32 arg) {
    wasm_rt_funcref_table_t *table = w2c_bt_0x5F_indirect_function_table(&bt_inst);
    if (fn >= table->size || !table->data[fn].func) bt_fatal("call to guest function %u outside the table", fn);
    ((void (*)(void *, u32))table->data[fn].func)(table->data[fn].module_instance, arg);
}

int main(int argc, char **argv) {
    bt_rom_open(argc > 1 ? argv[1] : "baserom.us.z64");
    wasm_rt_init();
    wasm2c_bt_instantiate(&bt_inst, &env);
    bt_mem = bt_inst.w2c_memory.data;
    // Guest pointers start at 0x80000000; anything lower is a stray pointer.
    if (mprotect(bt_mem, 0x80000000u, PROT_NONE) != 0) perror("bt_native: protecting low guest memory");
    BT_SP = w2c_bt_bt_guest_boot_stack_top(&bt_inst);
    w2c_bt_bt_be_fixup(&bt_inst); // relocated words in the data, into big-endian order
    w2c_bt_bt_guest_start(&bt_inst); // never returns: the boot context ends in osStartThread
    return 0;
}
