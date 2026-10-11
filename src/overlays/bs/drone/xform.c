#include "common.h"

void func_80800000_bsdronexform(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808011F0_bsdronexform;
    func_800BABB8(arg1, 0, 0, 0x3F800000, &D_808011F0_bsdronexform);
    func_800BA3FC(arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_80800050_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_808000E4_bsdronexform.s")

/* extern */

void func_808002CC_bsdronexform(void *arg0) {
    s32 func_800B5450(s32);
    func_800B5450((*(s32 *)((s8 *)((*(s32 **)((s8 *)(arg0) + (0x18C)))) + (4))));
    func_800B5450(*(*(s32 **)((s8 *)(arg0) + (0x18C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_80800304_bsdronexform.s")

void func_808003BC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 12) = arg1;
}

void func_808003CC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 24) = arg1;
}

void func_808003DC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 20) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_808003EC_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_8080051C_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/bsdronexform_entrypoint_0.s")

void func_8080069C_bsdronexform(s32 arg0)
{
    func_8008C9D8(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_808006BC_bsdronexform.s")

void func_80800704_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 40) = arg1;
}

void func_80800714_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 396) + 36) = arg1;
}

void func_80800724_bsdronexform(void *arg0) {
    f32 func_800D8FF8();
    void *arg0_copy;
    f32 temp_f0;

    arg0_copy = arg0;
    temp_f0 = func_800D8FF8();
    (*(f32 *)((s8 *)(*(void **)((s8 *)arg0_copy + 0x18C)) + 0x20)) = temp_f0 + (*(f32 *)((s8 *)(*(void **)((s8 *)arg0_copy + 0x18C)) + 0x20));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_80800758_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/bsdronexform_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/bsdronexform_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/func_80800B5C_bsdronexform.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/xform/bsdronexform_entrypoint_3.s")
