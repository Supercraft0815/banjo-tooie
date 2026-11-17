#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "native_rdram.h"

/* Host allocations do not move during defragmentation. Handle zero is reserved.
   Blocks come from the rdram arena so they have 32-bit physical addresses. */
static void *handles[250];
static s32 handle_sizes[250];

static void memory_error(const char *message) {
    fprintf(stderr, "Banjo-Tooie native memory: %s\n", message);
    abort();
}

// Like heap_alloc_sided (func_8001BD30): at least 1 byte, rounded up to 16. Game code writes a few
// bytes past some tables (subaddierouteDll route slots); on the N64 that lands in this padding.
static size_t n64_size(s32 size) { return ((size_t)(size > 0 ? size : 1) + 15) & ~(size_t)15; }

void *heap_alloc(s32 size) {
    void *result;
    if (size < 0) memory_error("negative allocation size");
    result = bt_alloc(n64_size(size));
    if (!result) memory_error("allocation failed");
    return result;
}

/* The arena needs no setup; the N64 version carves the heap out of RDRAM. */
void heap_setup(s32 zero_contents) {
    (void)zero_contents;
}

/* The N64 heap allocates from both ends to limit fragmentation; the arena has one. */
void *heap_alloc_sided(s32 size, s32 alloc_side) {
    (void)alloc_side;
    return heap_alloc(size);
}

void *heap_realloc(void *memory, BtIntPtr size) {
    void *result;
    if (size < 0) memory_error("negative allocation size");
    result = bt_realloc(memory, n64_size(size));
    if (!result) memory_error("allocation failed");
    return result;
}

void heap_free(void *memory) {
    bt_free(memory);
}

/* Heap statistics (src/core1/heap.c, 1E33860.c) answered from the rdram arena. */
s32 heap_bytes_allocated(void) {return (s32)bt_heap_size();} /* N64: the heap's total size */
s32 heap_bytes_free(void) {size_t free_bytes,largest,blocks;bt_heap_stats(&free_bytes,&largest,&blocks);return (s32)free_bytes;}
s32 heap_largest_free(s32 *size_out) {
    size_t free_bytes,largest,blocks;bt_heap_stats(&free_bytes,&largest,&blocks);
    *size_out=(s32)largest;return (s32)blocks;
}
s32 has_free_block_after(s32 size) {s32 largest;heap_largest_free(&largest);return largest>=size;}
/* Fragmented: the largest free block is below the given share of all free memory. */
int func_8001BD50(f32 share) {s32 largest;heap_largest_free(&largest);return (f32)largest<(f32)heap_bytes_free()*share;}
/* The n-th free block from the top of the heap and its size. */
void *func_8001BDAC(s32 *size, s32 n) {size_t bytes=0;void *block=bt_free_block_from_top(n,&bytes);*size=(s32)bytes;return block;}

void *defrag(void *memory) {
    return memory;
}

s16 func_8001B668(s32 type, s32 size) {
    s16 index;
    (void)type; /* Type only selects pointer repair after N64 heap compaction. */
    for (index = 1; index < 250; index++) {
        if (!handles[index]) {
            handles[index] = heap_alloc(size);
            handle_sizes[index] = size;
            return index;
        }
    }
    return 0;
}

void *func_8001B798(s16 handle) {
    if (handle <= 0 || handle >= 250 || !handles[handle]) {
        fprintf(stderr, "Banjo-Tooie native memory: handle %d\n", handle);
        memory_error("invalid allocation handle");
    }
    return handles[handle];
}

void *func_8001B710(s16 handle, s32 size) {
    void *memory = func_8001B798(handle);
    handles[handle] = heap_realloc(memory, size);
    handle_sizes[handle] = size;
    return handles[handle];
}

void func_8001B754(s16 handle) {
    /* N64 handle zero contains NULL; cache purges also release empty slots. */
    if (handle == 0) return;
    heap_free(func_8001B798(handle));
    handles[handle] = NULL;
    handle_sizes[handle] = 0;
}

void func_8001B7F0(s16 handle, u8 value, int size) {
    rare_memset(func_8001B798(handle), value, size);
}

s32 func_8001B7B8(s16 handle) {
    func_8001B798(handle);
    return handle_sizes[handle];
}
