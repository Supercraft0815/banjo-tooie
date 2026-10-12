#include "common.h"

s32 basetup_entrypoint_0() 
{
    return 0x4;
}

/* extern */

void func_80800008_basetup(s32 arg0) {
    s32 func_800A0FF0(s32);
    s32 func_800DA298(s32);
    s32 func_800DB9B0();
    s32 func_800EA05C();
    s32 func_800EA090();
    s32 sp1C;
    s32 sp18;

    sp1C = func_800EA05C();
    sp18 = func_800EA090();
    if ((func_800DB9B0() == 0) && (((sp1C == 0x13A) && (sp18 == 0xE)) || ((sp1C == 0x136) && (sp18 == 0x1B))) && (func_800DA298(0x327) != 0)) {
        func_800A0FF0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800080_basetup.s")

/* extern */

void func_80800140_basetup(void *arg0) {
    s32 func_800C6A7C(s32 *, void *, s32 *, s32);
    s32 func_800EE7F8(s32 *, void *);
    s32 sp24[3];
    s32 sp18[3];

    func_800EE7F8(sp18, arg0);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg0) + (4))) - 1000.0f);
    func_800C6A7C(sp18, arg0, sp24, 0x420025);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800194_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/basetup_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_808002D4_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800394_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800534_basetup.s")

/* extern */

void func_808006F0_basetup(void) {
    s32 _gccubesearch_entrypoint_14(s32, s32);
    s32 _gemarkersDll_entrypoint_1();
    _gccubesearch_entrypoint_14(_gemarkersDll_entrypoint_1(), 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_8080071C_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/func_80800778_basetup.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/setup/basetup_entrypoint_2.s")

void basetup_entrypoint_3(s32 arg0) 
{
}
void basetup_entrypoint_4(s32 arg0) 
{
}
