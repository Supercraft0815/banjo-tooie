// Native entry point: loads the ROM, instantiates the guest and runs its boot code.
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "guest.h"

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

// A stray guest pointer faults in the protected memory. Replaces the wasm2c handler, which
// drops the fault PC: the backtrace alone only names the caller of an inlined or leaf function.
static void on_fault(int sig, siginfo_t *si, void *uc) {
    (void)sig;
#if defined(__APPLE__) && defined(__arm64__)
    fprintf(stderr, "bt_native: guest fault at address %p, pc 0x%llx\n", si->si_addr,
            (unsigned long long)((ucontext_t *)uc)->uc_mcontext->__ss.__pc);
#else
    (void)uc;
    fprintf(stderr, "bt_native: guest fault at address %p\n", si->si_addr);
#endif
    bt_backtrace();
    abort();
}

int main(int argc, char **argv) {
    bt_settings_load();
    bt_video_init();  // SDL first: without a ROM argument a file dialog asks for it
    const char *rom = argc > 1 ? argv[1] : bt_rom_find();
    if (argc > 1) bt_rom_open(rom);
    wasm_rt_init();
    wasm2c_bt_instantiate(&bt_inst, &env);
    struct sigaction sa = {.sa_sigaction = on_fault, .sa_flags = SA_SIGINFO | SA_ONSTACK};
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGBUS, &sa, NULL);
    bt_mem = bt_inst.w2c_memory.data;
    // Guest pointers start at 0x80000000; anything lower is a stray pointer.
    if (mprotect(bt_mem, 0x80000000u, PROT_NONE) != 0) perror("bt_native: protecting low guest memory");
    BT_SP = w2c_bt_bt_guest_boot_stack_top(&bt_inst);
    w2c_bt_bt_be_fixup(&bt_inst); // relocated words in the data, into big-endian order
    bt_trace_init(rom);
    bt_video_window();  // before any game thread: the GPU renderer shares the window's context
    w2c_bt_bt_guest_start(&bt_inst); // never returns: the boot context ends in osStartThread
    return 0;
}
