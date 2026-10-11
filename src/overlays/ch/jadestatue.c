#include "common.h"

OSThread *chjadestatue_entrypoint_0(void)
{
    extern u8 D_80800310_chjadestatue[];

    return (OSThread *) D_80800310_chjadestatue;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_8080000C_chjadestatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_80800098_chjadestatue.s")

void func_80800104_chjadestatue(Actor *arg0, u8 *arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_80101870(Actor* arg0, void* arg1);
    s32 func_80103110(s32, s32);
    func_80101870(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_80103110((s32) arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_80800140_chjadestatue.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jadestatue/func_808001C0_chjadestatue.s")

/* extern */

void func_8080026C_chjadestatue(s32 arg0) {
    s32 func_800D035C(s32);
    s32 func_800FFAB0(s32);
    if (func_800D035C(5) >= 0x14) {
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_808002A4_chjadestatue(s32 arg0) {
    s32 func_800D035C(s32);
    s32 func_800D24E8(s32, s32, s32);
    s32 func_800FFAB0(s32);
    s32 func_80101180(s32, s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800D035C(5);
    sp1C = temp_v0;
    func_800D24E8(0xEE, temp_v0, 0);
    if (sp1C >= 0x14) {
        func_80101180(0x2B3, 0x2C, 0);
        func_800FFAB0(arg0);
    }
}

OSThread *chjadestatue_entrypoint_1(void)
{
    extern u8 D_80800358_chjadestatue[];

    return (OSThread *) D_80800358_chjadestatue;
}
