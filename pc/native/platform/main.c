// Native entry point of the game executable.
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "native_traps.h"

// core1 entrypoint (src/core1/1E29B60.c); the boot segment only decompresses core1.
void func_80012030(void *unused);
void bt_rom_open(const char *path);

static void check_trap_layout(void) {
    for (const BtTrapData *d = bt_trap_data; d->name; d++) {
        if ((char *)d->addr < bt_trap_area_start || (char *)d->addr >= bt_trap_area_end) {
            fprintf(stderr, "bt_native: trap data %s outside the protected area\n", d->name);
            exit(1);
        }
    }
}

int main(int argc, char **argv) {
    bt_rom_open(argc > 1 ? argv[1] : "baserom.us.z64");
    check_trap_layout();
    bt_traps_install();
    // Starts the idle thread, which boots the game on its own threads.
    func_80012030(NULL);
    for (;;) pause();
}
