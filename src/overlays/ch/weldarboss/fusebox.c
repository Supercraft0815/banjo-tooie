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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800024_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800098_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800140_chweldarbossfusebox.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800384_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_808003F8_chweldarbossfusebox.s")

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
