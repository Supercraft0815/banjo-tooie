#include "common.h"

OSThread *chattract_entrypoint_0(void)
{
    extern u8 D_808004F4_chattract[];

    return (OSThread *) D_808004F4_chattract;
}

void func_8080000C_chattract(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_80800014_chattract.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_80800204_chattract.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/func_808002AC_chattract.s")

void chattract_entrypoint_1(s32 arg0) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, s32);
    extern s32 _chattract_entrypoint_2;
    _chbaddiesetup_entrypoint_1(&_chattract_entrypoint_2, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/attract/chattract_entrypoint_2.s")
