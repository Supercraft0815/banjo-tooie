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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_8080032C_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_80800384_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_808003F8_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_8080049C_chweldarbossfusebox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/fusebox/func_808005C0_chweldarbossfusebox.s")

void func_808005F8_chweldarbossfusebox(s32 arg0) {
    s32 func_8001210C(s32);
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808007BC_chweldarbossfusebox;
    if (func_8001210C(3) != 0) {
        func_800BBCB8(arg0 + 4, 0, 0x3F800000, 2, &D_808007BC_chweldarbossfusebox);
    }
}
