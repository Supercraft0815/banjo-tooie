#include "common.h"

typedef struct {
    void *asset_base_ptr;
    void *asset_current_ptr;
    void *base_ptr;
    void *current_ptr;
    void *end_ptr;
    s32 mode;
    s32 last_expected;
    s32 unk1C;
    s16 asset_id;
    s16 pad22;
} GsFile;

void gsmaker_entrypoint_13(GsFile *, void *, s32);

// void stuff() {
    
// }

/* extern */

void gsmaker_entrypoint_0(void *arg0) {
    s32 func_800D6CEC(s16);
    s32 func_800D70F8(s16, s32);
    s32 func_800D721C(s16, s32);
    s32 heap_free(void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x14))) == 2) {
        func_800D721C((*(s16 *)((s8 *)(arg0) + (0x20))), 0);
        func_800D70F8((*(s16 *)((s8 *)(arg0) + (0x20))), 0);
        func_800D6CEC((*(s16 *)((s8 *)(arg0) + (0x20))));
    }
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/maker/gsmaker_entrypoint_1.s")

/* extern */

void gsmaker_entrypoint_2(s32 arg0) {
    s32 gsmaker_entrypoint_1(s32);
    gsmaker_entrypoint_1(arg0 + 0x955);
}

/* extern */

void gsmaker_entrypoint_3(s32 arg0, s32 arg1) {
    s32 gsmaker_entrypoint_1(s32);
    gsmaker_entrypoint_1(arg0 + arg1);
}

void gsmaker_entrypoint_4(s32 arg0, s32 arg1) {
    void* heap_alloc(s32 size);
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x24);
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 3;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0xC))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0x10))) = (s32) (arg0 + arg1);
}

u8 *gsmaker_entrypoint_5(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;
    u8 *temp_v0_2;

    temp_v0 = heap_alloc(0x24);
    (*(s32 *)((s8 *)(temp_v0) + (0x14))) = 4;
    (*(s32 *)((s8 *)(temp_v0) + (0x18))) = -1;
    (*(s32 *)((s8 *)(temp_v0) + (0x1C))) = -1;
    sp1C = temp_v0;
    temp_v0_2 = heap_alloc(0x20);
    (*(u8 **)((s8 *)(sp1C) + (8))) = temp_v0_2;
    (*(u8 **)((s8 *)(sp1C) + (0xC))) = temp_v0_2;
    (*(s32 *)((s8 *)(sp1C) + (0x10))) = (s32) (temp_v0_2 + 0x20);
    return sp1C;
}

void gsmaker_entrypoint_6(GsFile *file, void **dst, s32 *size) {
    void *heap_realloc(void *, s32);
    *size = (u32)file->current_ptr - (u32)file->base_ptr;
    *dst = heap_realloc(file->base_ptr, *size);
    file->base_ptr = NULL;
    gsmaker_entrypoint_0(file);
}

void gsmaker_entrypoint_7(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x1);
}

void gsmaker_entrypoint_8(s32 file, s32 dst, s32 count) {
    while (count > 0) {
        gsmaker_entrypoint_7(file, dst);
        count--;
        dst += 1;
    }
}

void gsmaker_entrypoint_9(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x4);
}

void gsmaker_entrypoint_10(s32 arg0, s32 arg1, s32 arg2) {
    while (arg2 > 0) {
        gsmaker_entrypoint_9(arg0, arg1);
        arg2--;
        arg1 += 4;
    }
}

void gsmaker_entrypoint_11(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x4);
}

void gsmaker_entrypoint_12(s32 file, s32 dst, s32 count) {
    while (count > 0) {
        gsmaker_entrypoint_11(file, dst);
        count--;
        dst += 4;
    }
}

void gsmaker_entrypoint_13(GsFile *file, void *dst, s32 len) {
    void *heap_realloc(void *, s32);
    void rare_memcpy(void *, void *, s32);
    u32 curr_offset;
    u32 capacity;
    void *new_base_ptr;

    if (file->mode == 2) {
        rare_memcpy(dst, file->asset_current_ptr, len);
        file->asset_current_ptr = (void *) ((u32)file->asset_current_ptr + len);
    }
    else if (file->mode == 3) {
        rare_memcpy(dst, file->current_ptr, len);
        file->current_ptr = (void *) ((u32)file->current_ptr + len);
    }
    else if (file->mode == 4) {
        if ((u8 *) file->end_ptr < (u8 *) file->current_ptr + len) {
            curr_offset = (u8 *) file->current_ptr - (u8 *) file->base_ptr;
            capacity = ((u8 *) file->end_ptr - (u8 *) file->base_ptr) * 2;

            while (((u8 *) file->base_ptr + capacity) < ((u8*) file->current_ptr + len)) {
                capacity *= 2;
            }

            new_base_ptr = heap_realloc(file->base_ptr, capacity);
            file->base_ptr = new_base_ptr;
            file->current_ptr = (u8 *) new_base_ptr + curr_offset;
            file->end_ptr = (u8 *) new_base_ptr + capacity;
        }

        rare_memcpy(file->current_ptr, dst, len);
        file->current_ptr = (u8 *) file->current_ptr + len;
    }
}

void gsmaker_entrypoint_14(s32 arg0,s32 arg1)
{
    gsmaker_entrypoint_13((GsFile *)arg0, (void *)arg1, 0x2);
}

void gsmaker_entrypoint_15(s32 file, s32 dst, s32 count) {
    while (count > 0) {
        gsmaker_entrypoint_14(file, dst);
        count--;
        dst += 2;
    }
}

s32 gsmaker_entrypoint_16(GsFile *file, s32 expected) {
    u8 saved_expected;

    saved_expected = expected;

    if ((file->mode == 1) || (file->mode == 4)) {
        gsmaker_entrypoint_7((s32)file, (s32)&saved_expected);
        return 1;
    }

    if (file->last_expected == -1) {
        gsmaker_entrypoint_7((s32)file, (s32)&saved_expected);

        if (expected == saved_expected) {
            return 1;
        }

        file->last_expected = saved_expected;
        return 0;
    }

    if (expected == file->last_expected) {
        file->last_expected = -1;
        return 1;
    }

    return 0;
}

/* extern */

s32 gsmaker_entrypoint_17(s32 arg0, s32 arg1, s32 arg2) {
    s32 gsmaker_entrypoint_16();
    if (gsmaker_entrypoint_16((GsFile *)arg0, arg1) == 0) {
        return 0;
    }
    gsmaker_entrypoint_7(arg0, arg2);
    return 1;
}

/* extern */

s32 gsmaker_entrypoint_18(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    void gsmaker_entrypoint_8(s32, s32, s32);
    if (gsmaker_entrypoint_16((GsFile *)file, expected) == 0) {
        return 0;
    }
    gsmaker_entrypoint_8(file, dst, count);
    return 1;
}

s32 gsmaker_entrypoint_19(s32 file, s32 expected, s32 dst) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_9(file, dst);
        return 1;
    }
}

s32 gsmaker_entrypoint_20(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_10(file, dst, count);
        return 1;
    }
}

s32 gsmaker_entrypoint_21(s32 file, s32 expected, s32 dst) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_11(file, dst);
        return 1;
    }
}

s32 gsmaker_entrypoint_22(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_12(file, dst, count);
        return 1;
    }
}

s32 gsmaker_entrypoint_23(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_13((GsFile *)file, (void *)dst, count);
        return 1;
    }
}

s32 gsmaker_entrypoint_24(s32 file, s32 expected, s32 dst) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_14(file, dst);
        return 1;
    }
}

s32 gsmaker_entrypoint_25(s32 file, s32 expected, s32 dst, s32 count) {
    s32 gsmaker_entrypoint_16(GsFile *, s32);
    if (!gsmaker_entrypoint_16((GsFile *)file, expected)) {
        return 0;
    } else {
        gsmaker_entrypoint_15(file, dst, count);
        return 1;
    }
}
