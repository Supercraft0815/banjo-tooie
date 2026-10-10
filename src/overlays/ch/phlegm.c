#include "common.h"

OSThread *chphlegm_entrypoint_0(void)
{
    extern u8 D_80800B58_chphlegm[];

    return (OSThread *) D_80800B58_chphlegm;
}

OSThread *chphlegm_entrypoint_1(void)
{
    extern u8 D_80800BA0_chphlegm[];

    return (OSThread *) D_80800BA0_chphlegm;
}

OSThread *chphlegm_entrypoint_2(void)
{
    extern u8 D_80800BE8_chphlegm[];

    return (OSThread *) D_80800BE8_chphlegm;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800024_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808000C4_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_8080026C_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800354_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808003B4_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808005E4_chphlegm.s")

/* extern */

void func_80800704_chphlegm(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800748_chphlegm.s")

void func_808007EC_chphlegm(u8 *arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800C98_chphlegm;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(2);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, arg1);
    func_800BABB8(sp24, arg0 + 4, NULL, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_80800C98_chphlegm);
}

void func_80800848_chphlegm(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800850_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808009DC_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800A58_chphlegm.s")
