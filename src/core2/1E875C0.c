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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800ADE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800ADEC4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800ADFE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE020.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE0E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE124.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E875C0/func_800AE598.s")

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
