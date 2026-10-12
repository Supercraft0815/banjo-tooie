#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/func_80800000_fxegg.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/fxegg_entrypoint_0.s")

void func_8080009C_fxegg(s32 arg0, s32 arg1, f32 arg2[3], f32 arg3) {
    s32 func_800B5BE4(s32);
    s32 func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800574_fxegg;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B5BE4(arg1);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg0);
    func_800BABB8(sp24, arg2, arg2, arg3, &D_80800574_fxegg);
}

void func_808000F8_fxegg(s32 arg0, f32 arg1[3], s32 arg2, f32 arg3) {
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808005B0_fxegg;
    func_800BA3FC(arg0, arg2);
    func_800BABB8(arg0, arg1, 0, arg3, &D_808005B0_fxegg);
}

/* extern */

s32 fxegg_entrypoint_1(f32 arg0[3], f32 arg1) {
    s32 func_800B5BE4(s32);
    s32 sp1C;

    sp1C = func_800B5BE4(0xC);
    func_808000F8_fxegg(sp1C, arg0, 0x9E5, arg1);
    return sp1C;
}

/* extern */

s32 fxegg_entrypoint_2(f32 arg0[3], f32 arg1) {
    s32 func_800B5BE4(s32);
    s32 sp1C;

    sp1C = func_800B5BE4(0xB);
    func_808000F8_fxegg(sp1C, arg0, 0x9E0, arg1);
    return sp1C;
}

void func_808001CC_fxegg(s32 arg0, f32 arg1[3], f32 arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808005D8_fxegg;
    func_800BABB8(arg0, arg1, 0, arg2, &D_808005D8_fxegg);
}

/* extern */

s32 fxegg_entrypoint_3(s32 arg0, s32 arg1) {
    s32 func_800B5BE4(s32);
    void func_808001CC_fxegg(s32, f32[3], f32);
    s32 sp1C[2];
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0x13);
    sp1C[1] = temp_v0;
    func_808001CC_fxegg(temp_v0, (f32 *) arg0, *(f32 *) &arg1);
    return sp1C[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/fxegg_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/fxegg_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/fxegg_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/egg/func_80800410_fxegg.s")

/* extern */

void fxegg_entrypoint_7(s32 arg0, s32 arg1, f32 arg2) {
    s32 func_800B5BE4(s32);
    s32 func_80800410_fxegg(s32, s32, s32, s32, f32);
    func_80800410_fxegg(func_800B5BE4(0xB), arg0, arg1, 0x9E0, arg2);
}

/* extern */

void fxegg_entrypoint_8(s32 arg0, s32 arg1, f32 arg2) {
    s32 func_800B5BE4(s32);
    s32 func_80800410_fxegg(s32, s32, s32, s32, f32);
    func_80800410_fxegg(func_800B5BE4(0xC), arg0, arg1, 0x9E5, arg2);
}
