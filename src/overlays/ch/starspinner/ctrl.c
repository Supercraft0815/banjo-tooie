#include "common.h"

OSThread *chstarspinnerctrl_entrypoint_0(void)
{
    extern u8 D_8080092C_chstarspinnerctrl[];

    return (OSThread *) D_8080092C_chstarspinnerctrl;
}

OSThread *chstarspinnerctrl_entrypoint_1(void)
{
    extern u8 D_80800974_chstarspinnerctrl[];

    return (OSThread *) D_80800974_chstarspinnerctrl;
}

void func_80800018_chstarspinnerctrl(s32 *arg0) {
    s32 _chpowerhut_entrypoint_0();
    extern s32 D_80800918_chstarspinnerctrl;
    _chpowerhut_entrypoint_0(arg0, &D_80800918_chstarspinnerctrl);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080003C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_80800184_chstarspinnerctrl.s")

void func_808002B4_chstarspinnerctrl(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chstarspinnerctrl_entrypoint_2;
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chstarspinnerctrl_entrypoint_2, *arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/chstarspinnerctrl_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_80800374_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_808003B8_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080044C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_808004CC_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_80800554_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/chstarspinnerctrl_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080069C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/chstarspinnerctrl_entrypoint_4.s")
