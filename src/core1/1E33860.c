#include "memory.h"

// round_up_16
u32 func_8001BD30(u32 arg0) {
    s32 temp_v0;
    register s32 result;

    temp_v0 = arg0 & 0xF;
    result = arg0;
    return temp_v0 ? result - temp_v0 + 0x10 : result;
}

/* extern */

int func_8001BD50(f32 arg0) {
    s32 heap_bytes_free();
    s32 heap_largest_free(s32 *);
    s32 sp1C;

    heap_largest_free(&sp1C);
    return (f32) sp1C < ((f32) heap_bytes_free() * arg0);
}

void *func_8001BDAC(s32 *arg0, s32 arg1) {
    struct EmptyHeapBlock *block;

    block = LAST_BLOCK();
    for (; arg1 != 0; arg1--) {
        block = block->prev_free;
        if (block == FIRST_BLOCK()) {
            return NULL;
        }
    }
    *arg0 = GET_BLOCK_MEM_SIZE(&block->header);
    return GET_BLOCK_CONTENTS(block);
}

void *func_8001BE94(s32 arg0) {
    struct HeapHeader *block;
    struct HeapHeader *prev;
    struct HeapHeader *first;
    u32 size;
    u32 available;

    block = LAST_BLOCK()->header.prev;
    size = func_8001BD30(arg0 > 0 ? arg0 : 1);
    available = GET_BLOCK_MEM_SIZE(block);
    if (available < size || ((u32)((u8 *)block)[15] >> 6) != 0) {
        first = &FIRST_BLOCK()->header;
        prev = block->prev;
        if (first != prev) {
loop:
            block = prev;
            available = GET_BLOCK_MEM_SIZE(prev);
            if (available < size || ((u32)((u8 *)prev)[15] >> 6) != 0) {
                prev = block->prev;
                if (first != prev) {
                    goto loop;
                }
            }
        }
    }
    if (((u32)((u8 *)block)[15] >> 6) != 0) {
        return NULL;
    }
    if (available < size) {
        return NULL;
    }
    return block;
}

void *func_8001BF80(s32 arg0) {
    struct EmptyHeapBlock *block;
    struct EmptyHeapBlock *next;
    u32 size;

    block = FIRST_BLOCK()->next_free;
    size = func_8001BD30(arg0 > 0 ? arg0 : 1);
    if ((u32)GET_BLOCK_MEM_SIZE(&block->header) < size) {
        if ((heap_bytes_allocated() + D_8007E990) != (char *)(next = block->next_free) + sizeof(struct EmptyHeapBlock)) {
loop:
            block = next;
            if ((u32)GET_BLOCK_MEM_SIZE(&next->header) < size) {
                if ((heap_bytes_allocated() + D_8007E990) != (char *)(next = block->next_free) + sizeof(struct EmptyHeapBlock)) {
                    goto loop;
                }
            }
        }
    }
    return (u32)GET_BLOCK_MEM_SIZE(&block->header) < size ? NULL : block;
}

/* extern */

s32 func_8001C070(void) {
    void *func_8001BF80();
    s32 var_v1;

    if (func_8001BF80() != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void *func_8001C0A0(s32 arg0) {
    struct HeapHeader *block;
    struct HeapHeader *next;
    u32 size;

    block = FIRST_BLOCK()->header.next;
    size = func_8001BD30(arg0 > 0 ? arg0 : 1);
    next = block->next;
    if ((u32)((char *)next - (char *)block - sizeof(struct HeapHeader)) < size || ((u32)((u8 *)block)[15] >> 6) != 0) {
        if ((heap_bytes_allocated() + D_8007E990) != (char *)(next = block->next) + sizeof(struct EmptyHeapBlock)) {
loop:
            block = next;
            next = next->next;
            if ((u32)((char *)next - (char *)block - sizeof(struct HeapHeader)) < size || ((u32)((u8 *)block)[15] >> 6) != 0) {
                if ((heap_bytes_allocated() + D_8007E990) != (char *)(next = block->next) + sizeof(struct EmptyHeapBlock)) {
                    goto loop;
                }
            }
        }
    }
    if (((u32)((volatile u8 *)block)[15] >> 6) != 0) {
        return NULL;
    }
    if ((u32)((char *)next - (char *)block - sizeof(struct HeapHeader)) < size) {
        return NULL;
    }
    return block;
}
