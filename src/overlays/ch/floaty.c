#include "common.h"

OSThread *chfloaty_entrypoint_0(void)
{
    extern u8 D_80800E00_chfloaty[];

    return (OSThread *) D_80800E00_chfloaty;
}

s32 func_8080000C_chfloaty(s32 arg0, s32 arg1, s32 arg2) {
    return 1;
}

void func_80800020_chfloaty(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, *((s32 *) (((s8 *) arg1) + 0)), *((s32 *) (((s8 *) arg1) + 4)), *((s32 *) (((s8 *) arg1) + 8)), arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_8080007C_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800118_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_808006AC_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_8080090C_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800B68_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800BD8_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800C4C_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800CA0_chfloaty.s")

OSThread *chfloaty_entrypoint_1(void)
{
    extern u8 D_80800EF0_chfloaty[];

    return (OSThread *) D_80800EF0_chfloaty;
}
