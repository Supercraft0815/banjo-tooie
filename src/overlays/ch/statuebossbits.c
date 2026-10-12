#include "common.h"

OSThread *chstatuebossbits_entrypoint_0(void)
{
    extern u8 D_808006F0_chstatuebossbits[];

    return (OSThread *) D_808006F0_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_1(void)
{
    extern u8 D_80800738_chstatuebossbits[];

    return (OSThread *) D_80800738_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_2(void)
{
    extern u8 D_80800780_chstatuebossbits[];

    return (OSThread *) D_80800780_chstatuebossbits;
}

OSThread *chstatuebossbits_entrypoint_3(void)
{
    extern u8 D_808007C8_chstatuebossbits[];

    return (OSThread *) D_808007C8_chstatuebossbits;
}

void func_80800030_chstatuebossbits(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800038_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800224_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800270_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_808002CC_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_80800360_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_8080040C_chstatuebossbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_808004D8_chstatuebossbits.s")

void func_80800604_chstatuebossbits(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32 *, s32 *, s32, s32, s32 *);
    s32 func_800EC398(s32, s32 *);
    extern s32 D_80800864_chstatuebossbits;
    s32 sp24[3];

    func_800EC398(arg1, sp24);
    func_800BBCB8(sp24, sp24, 0x3F800000, 4, &D_80800864_chstatuebossbits);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statuebossbits/func_8080064C_chstatuebossbits.s")
