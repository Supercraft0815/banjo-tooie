#include "common.h"

/* extern */

s32 func_80800000_bsswim(void) {
    s32 func_8008E23C();
    s32 var_v1;

    if (func_8008E23C() != 0) {
        var_v1 = 0x6D;
    } else {
        var_v1 = 0x30;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800030_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808000E0_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800178_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808001DC_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_80800270_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808002E0_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808004C4_bsswim.s")

void func_80800688_bsswim(s32 arg0)
{
    func_80800270_bsswim();
    func_800A4E30(arg0);
}
s32 bsswim_entrypoint_0(s32 arg0) {
    extern s32 D_80800BA4_bsswim[];
    return ((s32 *)&D_80800BA4_bsswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808006C4_bsswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/swim/func_808007F8_bsswim.s")

void func_808009F0_bsswim()
{
    func_80800270_bsswim();
}

s32 bsswim_entrypoint_1(s32 arg0) {
    extern s32 D_80800BB4_bsswim[];
    return ((s32 *)&D_80800BB4_bsswim)[arg0];
}

void func_80800A24_bsswim(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_80800270_bsswim(arg0);
}
void func_80800A4C_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800A74_bsswim(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 bs_setState(s32, s32);
    s32 _bsrest_entrypoint_20();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20() != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

s32 bsswim_entrypoint_2(s32 arg0) {
    extern s32 D_80800BC4_bsswim[];
    return ((s32 *)&D_80800BC4_bsswim)[arg0];
}

void func_80800AC8_bsswim(s32 arg0)
{
    func_808001DC_bsswim();
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void func_80800AF0_bsswim(s32 arg0) {
    s32 _badrone_entrypoint_30();
    s32 _bsdrone_entrypoint_1(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_badrone_entrypoint_30() != 0) {
        sp1C = 1;
    }
    _bsdrone_entrypoint_1(arg0);
    bs_setState(arg0, sp1C);
}

void func_80800B34_bsswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800270_bsswim(arg0);
}
s32 bsswim_entrypoint_3(s32 arg0) {
    extern s32 D_80800BD4_bsswim[];
    return ((s32 *)&D_80800BD4_bsswim)[arg0];
}
