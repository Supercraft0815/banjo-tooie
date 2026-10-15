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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BDAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BF80.s")

/* extern */

s32 func_8001C070(void) {
    s32 func_8001BF80();
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
