#include "common.h"

OSThread *chseaweedbaddy_entrypoint_0(void)
{
    extern u8 D_80800EB4_chseaweedbaddy[];

    return (OSThread *) D_80800EB4_chseaweedbaddy;
}

OSThread *chseaweedbaddy_entrypoint_1(void)
{
    extern u8 D_80800EFC_chseaweedbaddy[];

    return (OSThread *) D_80800EFC_chseaweedbaddy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800018_chseaweedbaddy.s")

void func_8080043C_chseaweedbaddy(Actor *arg0) {
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    _sudeflect_entrypoint_1(arg0->position, arg0->scale * 120.0f, arg0->scale * 100.0f, 0.0f, 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800498_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800554_chseaweedbaddy.s")

void func_8080065C_chseaweedbaddy(Actor *arg0) {
    f32 func_800DC0C0(void);
    s32 func_80101EE4(Actor *, f32);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.7f);
    func_80101EE4(arg0, func_800DC0C0());
}

/* extern */

void func_808006A8_chseaweedbaddy(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_800DF744(5, 1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800710_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_808007E4_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_8080082C_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800910_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_808009BC_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800BCC_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800CE0_chseaweedbaddy.s")
