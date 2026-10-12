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

/* extern */

void func_80800374_chstarspinnerctrl(Actor *arg0) {
    void func_8010A570(Actor*);
    s32 func_800DA298(s32);
    if (func_800DA298(0x679) != 0) {
        func_8010A570(arg0);
        arg0->unk64_20 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_808003B8_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080044C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_808004CC_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_80800554_chstarspinnerctrl.s")

s32 chstarspinnerctrl_entrypoint_3(s32 arg0, s32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8D4C(s32, s32 *);
    s32 func_800C8E84(s32, s32 *);
    s32 func_800C8F64(s32, s32);
    s32 func_800DA298(s32);
    extern s32 D_808008E0_chstarspinnerctrl;
    extern s32 D_808008F4_chstarspinnerctrl;
    s32 temp_v0;

    if ((func_800DA298(0xEA) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        return 0;
    }
    temp_v0 = func_800C8A98();
    func_800C8D4C(temp_v0, &D_808008E0_chstarspinnerctrl);
    func_800C8E84(temp_v0, &D_808008F4_chstarspinnerctrl);
    func_800C8CB8(temp_v0, arg1);
    func_800C8F64(temp_v0, 9);
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080069C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/chstarspinnerctrl_entrypoint_4.s")
