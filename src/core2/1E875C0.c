#include "common.h"

void func_800ADCD0(u8 **list_ptr, u8 *animation) {
    void *heap_realloc(void *, s32);
    s32 func_80019CD4(void);
    void mlMtxGet(void *);
    u8 *list;
    u8 *start, *end, *matrix;
    list = *list_ptr;
    if (*(s32 *)(list + 4) < *(s16 *)(animation + 4)) {
        list = heap_realloc(list, *(s16 *)(animation + 4) * 64 + 0x50);
        *(s32 *)(list + 4) = *(s16 *)(animation + 4);
        *list_ptr = list;
    }
    *(s32 *)list = *(s16 *)(animation + 4);
    start = list + 0x50;
    end = start + *(s32 *)list * 64;
    func_80019CD4();
    for (matrix = start; matrix < end; matrix += 64) mlMtxGet(matrix);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800ADD80.s")

s32 func_800ADE2C(s32 arg0, s32 arg1) {
    if (arg1 == -1) {
        return arg0 + 0x10;
    }
    return (arg0 + 0x50) + (arg1 << 6);
}

u32 func_800ADE50(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 temp_v1;
    u8 *var_a1;
    u8 *var_v0;

    var_v0 = arg1 + 8;
    if (*(s16 *)(arg1 + 4) != (temp_v1 = *(s32 *)arg0)) {
        return 0;
    }
    var_a1 = arg0 + 0x50;
    while (var_a1 < (temp_v1 << 6) + arg0 + 0x50) {
        if (arg2 == *(s16 *)(var_v0 + 0xC)) {
            return (u32) var_a1;
        }
        var_a1 += 0x40;
        var_v0 += 0x10;
    }
    return 0U;
}

/* extern */

void func_800ADEC4(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3[4][4]) {
    void func_800F293C(f32 arg0[4][4], f32 arg1[4][4]);
    s32 temp_v1;
    u8 *var_s0;
    u8 *var_s1;

    var_s1 = arg1 + 8;
    if (*(s16 *)(arg1 + 4) == (temp_v1 = *(s32 *)arg0)) {
        var_s0 = arg0 + 0x50;
        while (var_s0 < (temp_v1 << 6) + arg0 + 0x50) {
            if (arg2 == (*(s16 *)((s8 *)(var_s1) + (0xC)))) {
                func_800F293C((f32 (*)[4])var_s0, arg3);
            }
            var_s0 += 0x40;
            var_s1 += 0x10;
        }
    }
}

/* extern */

void func_800ADF5C(void *arg0) {
    s32 func_800E0A50(s32, s32, void *);
    s32 heap_free(void *);
    s32 value;

    value = *(s32 *)((s8 *)arg0 + 8);
    if (value != 0) {
        func_800E0A50(value, *(s32 *)((s8 *)arg0 + 8), arg0);
    }
    heap_free(arg0);
}

/* extern */

u8 *func_800ADF98(void) {
    s32 func_80019CD4(void);
    void *heap_alloc(s32);
    void mlMtxGet(void *);
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x50);
    (*(s32 *)((s8 *)(temp_v0) + (0))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0xC))) = 0;
    func_80019CD4();
    mlMtxGet(temp_v0 + 0x10);
    return temp_v0;
}

void func_800ADFE0(s16 arg0) { s32 func_800AE080(s16); s32 func_8001B754(s16); s32 func_800E0A70(s16); s32 temp_v0; temp_v0 = func_800AE080(arg0); if ((*(s16 *)((s8 *)temp_v0 + 0xC)) != 0) { func_800E0A70(*(s16 *)((s8 *)temp_v0 + 0xC)); } func_8001B754(arg0); }

s16 func_800AE020(void) {
    s32 func_80019CD4(void);
    s16 func_8001B668(s32, s32);
    s32 func_800AE080(s16);
    void mlMtxGet(void *);
    s16 result;
    s32 ptr;

    result = func_8001B668(0, 0x50);
    ptr = func_800AE080(result);
    *(s32 *)ptr = 0;
    *(s32 *)(ptr + 4) = 0;
    *(s32 *)(ptr + 8) = 0;
    *(s16 *)(ptr + 0xC) = 0;
    func_80019CD4();
    mlMtxGet((void *)(ptr + 0x10));
    return result;
}

/* extern */

s32 func_800AE080(s16 arg0) {
    s32 func_8001B798(s16);
    if (arg0 == 0) {
        return 0;
    }
    return func_8001B798(arg0);
}

s32 func_800AE0B8(s32 *arg0) {
    if (arg0 != NULL) {
        return *arg0;
    }
    return 1;
}

s32 func_800AE0D0(s32 *arg0) {
    if (arg0 != NULL) {
        return *arg0;
    }
    return 0;
}

s32 func_800AE0E8(s16 arg0) { if (arg0 != 0) { return *(s32 *)func_800AE080(arg0); } return 1; }

s32 func_800AE124(s16 arg0) { if (arg0 != 0) { return *(s32 *)func_800AE080(arg0); } return 0; }

/* extern */

void func_800AE160(u8 **arg0, u8 *arg1, s32 arg2) {
    void* heap_realloc(void* mem, s32 size);
    s32 func_800AE820(s32, u8 *, u8 *, s32);
    s16 var_v1;
    u8 *temp_v0;
    u8 *var_s0;

    var_s0 = *arg0;
    var_v1 = (*(s16 *)((s8 *)(arg1) + (4)));
    if ((*(s32 *)((s8 *)(var_s0) + (4))) < var_v1) {
        temp_v0 = heap_realloc(var_s0, (var_v1 << 6) + 0x50);
        var_s0 = temp_v0;
        (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) (*(s16 *)((s8 *)(arg1) + (4)));
        *arg0 = temp_v0;
        var_v1 = (*(s16 *)((s8 *)(arg1) + (4)));
    }
    (*(s32 *)((s8 *)(var_s0) + (0))) = (s32) var_v1;
    func_800AE820(arg2, arg1, var_s0 + 0x50, (*(s32 *)((s8 *)(var_s0) + (8))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE1E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE40C.s")

/* extern */

void func_800AE598(s32 *arg0, s32 *arg1) {
    s32 func_80116684(void *, s32, s32, s32 *);
    func_80116684((u8 *) arg0 + 0x10, *arg1, *arg0 + 1, arg0);
    *arg1 += (*arg0 + 1) << 6;
}

/* extern */

void func_800AE5F0(u8 *arg0) {
    void *defrag(void *);
    s32 func_800E0A98(s32, u8 *);
    s32 temp_a2;

    temp_a2 = ((s32 *) arg0)[2];
    if (temp_a2 != 0) {
        ((s32 *) arg0)[2] = func_800E0A98(temp_a2, arg0);
    }
    defrag(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE630.s")

/* extern */

s32 func_800AE6BC(s32 *arg0) {
    s32 func_800E0A28(s16);
    s16 temp_a1;

    temp_a1 = ((s16 *) arg0)[6];
    if (temp_a1 != 0) {
        return func_800E0A28(temp_a1);
    }
    return arg0[2];
}

void func_800AE6FC(s16 *arg0, s16 arg1) {
    arg0[6] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE708.s")
