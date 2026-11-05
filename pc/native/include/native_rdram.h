#ifndef NATIVE_RDRAM_H
#define NATIVE_RDRAM_H

#include <stddef.h>
#include <ultra64.h>

// Game heap: an arena inside the executable, so every block has a 32-bit physical address.
void *bt_alloc(size_t n);
void *bt_realloc(void *p, size_t n);
void bt_free(void *p);
size_t bt_alloc_size(const void *p);

// 32-bit physical address of game memory (static or arena) and back:
// 0x80000000 + offset from the executable's start.
u32 bt_phys(const void *p);
int bt_is_phys(u32 phys);
void *bt_host(u32 phys);

#endif
