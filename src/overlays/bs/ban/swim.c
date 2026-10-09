#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_80800000_bsbanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_80800030_bsbanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_80800104_bsbanswim.s")

void func_808001A8_bsbanswim()
{
    func_80800104_bsbanswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808001C8_bsbanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_8080025C_bsbanswim.s")

s32 bsbanswim_entrypoint_0(s32 arg0) {
    extern s32 D_80800A30_bsbanswim[];
    return ((s32 *)&D_80800A30_bsbanswim)[arg0];
}

s32 func_80800390_bsbanswim(s32 arg0) {
    if ((arg0 == 0x81) || (arg0 == 0x82) || (arg0 == 0x90)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808003BC_bsbanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_8080040C_bsbanswim.s")

void func_8080049C_bsbanswim()
{
    func_808003BC_bsbanswim();
}

/* extern */

void func_808004BC_bsbanswim(s32 arg0) {
    s32 anctrl_setDuration(s32, s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8080040C_bsbanswim(s32);
    s32 sp1C;

    sp1C = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(arg0);
    anctrl_setDuration(sp1C, 0x3F800000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808004F4_bsbanswim.s")

s32 bsbanswim_entrypoint_1(s32 arg0) {
    extern s32 D_80800A40_bsbanswim[];
    return ((s32 *)&D_80800A40_bsbanswim)[arg0];
}

void func_80800670_bsbanswim()
{
    func_808003BC_bsbanswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_80800690_bsbanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808006CC_bsbanswim.s")

s32 bsbanswim_entrypoint_2(s32 arg0) {
    extern s32 D_80800A50_bsbanswim[];
    return ((s32 *)&D_80800A50_bsbanswim)[arg0];
}

void func_80800848_bsbanswim()
{
    func_808003BC_bsbanswim();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_80800868_bsbanswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808008A4_bsbanswim.s")

s32 bsbanswim_entrypoint_3(s32 arg0) {
    extern s32 D_80800A60_bsbanswim[];
    return ((s32 *)&D_80800A60_bsbanswim)[arg0];
}
