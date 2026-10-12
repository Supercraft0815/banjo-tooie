#include "core2/1EEF790.h"

s32 func_80115EA0() 
{
    return 0x5C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_80115EA8.s")

void func_80115F98(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (8))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_80115FB0.s")

/* extern */

void func_80116024(void *arg0) {
    s32 func_80116218();
    func_80116218();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x2C))) = 0;
}

void func_80116050(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (4))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x18))) = (f32) (arg1 * 0.5f);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (4)))) + (0x40))) = arg1;
}

void func_8011607C(void *arg0, s32 arg1) {
    *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 46) = arg1;
}

/* extern */

void func_80116088(u8 *arg0, s32 arg1) {
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_801107B0(void *, void *);
    f32 sp1C[3];

    func_801107B0(arg0, sp1C);
    if (func_800F1E6C(sp1C, (f32 *)arg1, (f32 *)(*(u8 **)((s8 *)(arg0) + (4)) + 0x28)) != 0) {
        (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (4)))) + (0x2C))) = 1;
    }
}

void func_801160DC(PlayerState *self, f32 arg1) {
    struct ba_anim_s *temp_v0;
    u8 flag = 1;

    (*(f32 *)((s8 *)(self->anim) + (0x20))) = arg1;
    temp_v0 = self->anim;
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x20)));
    (*(u8 *)((s8 *)(self->anim) + (0x24))) = flag;
    temp_v0 = self->anim;
    (*(u8 *)((s8 *)(temp_v0) + (0x10))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (0x24)));
    (*(f32 *)((s8 *)(self->anim) + (0x44))) = arg1;
    (*(u8 *)((s8 *)(self->anim) + (0x48))) = flag;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_80116120.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_80116218.s")

void func_801163A0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 4) + 88) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_801163B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_8011649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_801164E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_80116568.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEF790/func_80116684.s")
