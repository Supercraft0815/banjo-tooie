#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/invisible/func_80800000_bainvisible.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/invisible/func_808001BC_bainvisible.s")

/* extern */

int func_808003AC_bainvisible(void *arg0) {
    f32 func_800F214C(f32, f32);
    f32 temp_f0;
    f32 temp_f12;
    f32 step;

    temp_f0 = (*(f32 *)((s8 *)(arg0) + (0xC)));
    temp_f12 = (*(f32 *)((s8 *)(arg0) + (8))) - temp_f0;
    step = temp_f12 * 0.25f;
    (*(f32 *)((s8 *)(arg0) + (0xC))) = temp_f0 + step;
    return func_800F214C(temp_f12, 0.01f) == 0.0f;
}

s32 bainvisible_entrypoint_0() 
{
    return 0x7C;
}

void bainvisible_entrypoint_1(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA8)))) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA8)))) + (0x18))) = arg2;
}

f32 bainvisible_entrypoint_2(void *arg0, s32 arg1) {
    return (*(f32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0xA8))) + (arg1 * 0x30))) + (0x28)));
}

void bainvisible_entrypoint_3(s32 arg0) {
    s32 bastatetimer_clear(void *, s32);
    void func_80800000_bainvisible(s32, void *, s32);
    s8 *sp1C;

    sp1C = *(s8 **)((s8 *)arg0 + 0xA8) + 0x1C;
    func_80800000_bainvisible(arg0, sp1C, 1);
    sp1C += 0x30;
    func_80800000_bainvisible(arg0, sp1C, 1);
    bastatetimer_clear((void *)arg0, 9);
}

void bainvisible_entrypoint_4(s32 arg0) {
    s32 bastatetimer_clear(void *, s32);
    void func_80800000_bainvisible(s32, void *, s32);
    s8 *sp1C;

    sp1C = *(s8 **)((s8 *)arg0 + 0xA8) + 0x1C;
    func_80800000_bainvisible(arg0, sp1C, 0);
    sp1C += 0x30;
    func_80800000_bainvisible(arg0, sp1C, 0);
    bastatetimer_clear((void *)arg0, 9);
}

void bainvisible_entrypoint_5(s32 arg0, f32 arg1) {
    void bastatetimer_set(void *, s32, f32);
    void func_80800000_bainvisible(s32, void *, s32);
    s8 *sp1C;

    sp1C = *(s8 **)((s8 *)arg0 + 0xA8) + 0x1C;
    func_80800000_bainvisible(arg0, sp1C, 2);
    sp1C += 0x30;
    func_80800000_bainvisible(arg0, sp1C, 2);
    bastatetimer_set((void *)arg0, 9, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/invisible/bainvisible_entrypoint_6.s")

void bainvisible_entrypoint_7(u8 *arg0, s32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    s8 var_v0;
    u8 *temp_v1;
    u8 *temp_v1_2;

    var_v0 = arg4 != 0.0f ? 1 : 0;
    if (arg1 & 1) {
        temp_v1 = (*(u8 **)((s8 *)(arg0) + (0xA8)));
        (*(s8 *)((s8 *)(temp_v1) + (0x38))) = var_v0;
        (*(f32 *)((s8 *)(temp_v1) + (0x34))) = arg4;
        (*(f32 *)((s8 *)(temp_v1) + (0x2C))) = arg2;
        temp_v1 += 0x1C;
        (*(f32 *)((s8 *)(temp_v1) + 0x14)) = arg3;
    }
    if (arg1 & 2) {
        temp_v1_2 = (*(u8 **)((s8 *)(arg0) + (0xA8)));
        (*(s8 *)((s8 *)(temp_v1_2) + (0x68))) = var_v0;
        (*(f32 *)((s8 *)(temp_v1_2) + (0x64))) = arg4;
        (*(f32 *)((s8 *)(temp_v1_2) + (0x5C))) = arg2;
        temp_v1_2 += 0x4C;
        (*(f32 *)((s8 *)(temp_v1_2) + 0x14)) = arg3;
    }
}

/* extern */

void func_808007CC_bainvisible(s32 arg0, void *arg1, f32 arg2, f32 arg3) {
    void func_80800000_bainvisible(s32, void *, s32);
    func_80800000_bainvisible(arg0, arg1, 4);
    (*(f32 *)((s8 *)(arg1) + (0x20))) = arg2;
    (*(f32 *)((s8 *)(arg1) + (0x2C))) = arg3;
}

void bainvisible_entrypoint_8(void *arg0, s32 arg1, f32 arg2, f32 arg3) {
    if (arg1 & 1) {
        func_808007CC_bainvisible((s32) arg0, (*(s32 *)((s8 *)(arg0) + (0xA8))) + 0x1C, arg2, arg3);
    }
    if (arg1 & 2) {
        func_808007CC_bainvisible((s32) arg0, (*(s32 *)((s8 *)(arg0) + (0xA8))) + 0x4C, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/invisible/bainvisible_entrypoint_9.s")
