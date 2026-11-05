#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

/* Host allocations do not move during defragmentation. Handle zero is reserved. */
static void *handles[250];
static s32 handle_sizes[250];

static void memory_error(const char *message) {
    fprintf(stderr, "Banjo-Tooie native memory: %s\n", message);
    abort();
}

void *heap_alloc(s32 size) {
    void *result;
    if (size < 0) memory_error("negative allocation size");
    result = malloc(size ? (size_t)size : 1);
    if (!result) memory_error("allocation failed");
    return result;
}

void *heap_realloc(void *memory, s32 size) {
    void *result;
    if (size < 0) memory_error("negative allocation size");
    result = realloc(memory, size ? (size_t)size : 1);
    if (!result) memory_error("allocation failed");
    return result;
}

void heap_free(void *memory) {
    free(memory);
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
