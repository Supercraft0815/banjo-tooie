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

void *heap_alloc(s32 size) {
    void *result;
    if (size < 0) memory_error("negative allocation size");
    result = bt_alloc(size ? (size_t)size : 1);
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

void *heap_realloc(void *memory, s32 size) {
    void *result;
    if (size < 0) memory_error("negative allocation size");
    result = bt_realloc(memory, size ? (size_t)size : 1);
    if (!result) memory_error("allocation failed");
    return result;
}

void heap_free(void *memory) {
    bt_free(memory);
}

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
    if (handle <= 0 || handle >= 250 || !handles[handle])
        memory_error("invalid allocation handle");
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

s32 func_8001B7B8(s16 handle) {
    func_8001B798(handle);
    return handle_sizes[handle];
}
