#ifndef NATIVE_RDRAM_H
#define NATIVE_RDRAM_H

#include <stddef.h>
#include <ultra64.h>

// Game heap: an arena inside the executable, so every block has a 32-bit physical address.
void *bt_alloc(size_t n);
void *bt_realloc(void *p, size_t n);
void bt_free(void *p);
size_t bt_alloc_size(const void *p);
// Statistics for the game's memory checks: free bytes, largest free block, free block count.
void bt_heap_stats(size_t *free_bytes, size_t *largest, size_t *blocks);
// The n-th free block (1 = topmost) counted down from the arena's end, with its usable size.
void *bt_free_block_from_top(int n, size_t *size);
size_t bt_heap_size(void);

// 32-bit physical address of game memory (static or arena) and back:
// 0x80000000 + offset from the executable's start.
u32 bt_phys(const void *p);
int bt_is_phys(u32 phys);
void *bt_host(u32 phys);

#endif
