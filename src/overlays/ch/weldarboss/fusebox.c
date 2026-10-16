#include "common.h"

OSThread *chweldarbossfusebox_entrypoint_0(void)
{
    extern u8 D_80800670_chweldarbossfusebox[];

    return (OSThread *) D_80800670_chweldarbossfusebox;
}

OSThread *chweldarbossfusebox_entrypoint_1(void)
{
    extern u8 D_808006B8_chweldarbossfusebox[];

    return (OSThread *) D_808006B8_chweldarbossfusebox;
}

OSThread *chweldarbossfusebox_entrypoint_2(void)
{
    extern u8 D_80800700_chweldarbossfusebox[];

    return (OSThread *) D_80800700_chweldarbossfusebox;
}

/* extern */

void func_80800024_chweldarbossfusebox(s32 arg0) {
    s32 _subaddiefade_entrypoint_14(s32);
    s32 func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EFA4C(s32, s32, s32, s32);
    s32 func_800FFAB0(s32);
    s32 func_80103014(s32);
    func_800BF744(2, func_800DA298(0x18C));
    func_800EFA4C(arg0 + 4, 0xC4E10000, 0x44960000, 0xC5098000);
    func_80103014(arg0);
    _subaddiefade_entrypoint_14(arg0);
    if (func_800DA298(0x18C) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800098_chweldarbossfusebox.s")

void func_80800140_chweldarbossfusebox(s32 arg0) {
    s32 _chexploder_entrypoint_15(s32, s32, s32);
    s32 _chexploder_entrypoint_6(s32, s32, s32);
    s32 _chexploder_entrypoint_7(s32, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_800BF744(s32, s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    extern s32 D_80800660_chweldarbossfusebox;
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp1C = temp_v0;
    _chexploder_entrypoint_6(temp_v0, 0x44E10000, 0x44FA0000);
    _chexploder_entrypoint_7(sp1C, 0xC4AF0000, 0xC4960000);
    _chexploder_entrypoint_15(sp1C, 2, 0x3FC00000);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800660_chweldarbossfusebox);
    func_800BF744(2, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_808001BC_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800268_chweldarbossfusebox.s")

void func_8080032C_chweldarbossfusebox(s32 arg0) {
    s32 _chexploder_entrypoint_15(s32, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_800BF744(s32, s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    extern s32 D_80800660_chweldarbossfusebox;
    _chexploder_entrypoint_15(func_80106790(func_80101080()), 2, 0x3FC00000);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800660_chweldarbossfusebox);
    func_800BF744(4, 1);
}

void func_80800384_chweldarbossfusebox(f32 *arg0) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800748_chweldarbossfusebox;
    f32 sp24[3];

    func_800EE7F8(sp24, arg0 + 6);
    sp24[1] += 400.0f;
    sp24[2] -= 100.0f;
    func_800BABB8(0, arg0 + 6, sp24, 1.0f, &D_80800748_chweldarbossfusebox);
}

void func_808003F8_chweldarbossfusebox(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    void func_80105A9C(Actor *arg0, f32 arg1);
    f32 height;

    if (func_800DA298(0x18C) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (arg0->unk74_7 == 0x32) {
        arg0->unk58 = 0.0f;
    } else {
        arg0->unk58 = 0.5f;
    }
    if (arg0->unk74_7 == 0x32) {
        height = 750.0f;
    } else {
        height = 700.0f;
    }
    func_80105A9C(arg0, height);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_8080049C_chweldarbossfusebox.s")

s32 func_808005C0_chweldarbossfusebox(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80103110(Actor*, u32);
    if (arg1 == 0xA) {
        func_80103110(arg0, 1U);
        return 1;
    }
    return 0;
}

void func_808005F8_chweldarbossfusebox(s32 arg0) {
    s32 func_8001210C(s32);
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808007BC_chweldarbossfusebox;
    if (func_8001210C(3) != 0) {
        func_800BBCB8(arg0 + 4, 0, 0x3F800000, 2, &D_808007BC_chweldarbossfusebox);
    }
}
