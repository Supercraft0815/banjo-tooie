// Diagnostics for code and data that is not ported yet. gen_traps.py generates a
// function per missing symbol that calls bt_unported(), and places missing data in
// a page-protected area, so the first access reports the symbol instead of using zeros.
#include <execinfo.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include "native_traps.h"

static void print_backtrace(void) {
    void *frames[16];
    int n = backtrace(frames, 16);
    backtrace_symbols_fd(frames, n, 2);
}

void bt_unported(const char *name) {
    fprintf(stderr, "bt_native: unported function %s called\n", name);
    print_backtrace();
    abort();
}

static void on_fault(int sig, siginfo_t *info, void *ctx) {
    uintptr_t addr = (uintptr_t)info->si_addr;
    const BtTrapData *hit = NULL;
    (void)ctx;
    for (const BtTrapData *d = bt_trap_data; d->name; d++) {
        if (addr >= (uintptr_t)d->addr && addr < (uintptr_t)d->addr + d->size) hit = d;
    }
    if (hit) {
        // fprintf is not async-signal-safe, but the process aborts right after.
        fprintf(stderr, "bt_native: unmigrated data %s accessed (+0x%lx)\n", hit->name,
                (unsigned long)(addr - (uintptr_t)hit->addr));
    } else {
        fprintf(stderr, "bt_native: signal %d at address %p\n", sig, info->si_addr);
    }
    print_backtrace();
    signal(SIGABRT, SIG_DFL);
    abort();
}

void bt_traps_install(void) {
    struct sigaction sa;
    long page = sysconf(_SC_PAGESIZE);
    uintptr_t start = (uintptr_t)bt_trap_area_start;
    uintptr_t end = (uintptr_t)bt_trap_area_end;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = on_fault;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);
    sigaction(SIGBUS, &sa, NULL);
    start = (start + page - 1) & ~(uintptr_t)(page - 1);
    end &= ~(uintptr_t)(page - 1);
    if (end > start && mprotect((void *)start, end - start, PROT_NONE) != 0) {
        perror("bt_native: mprotect of the unmigrated data area");
        exit(1);
    }
}
