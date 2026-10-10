#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_80800000_chcaptainblubber.s")

void func_80800078_chcaptainblubber(Actor *arg0) {
    void _subaddieitem_entrypoint_0(s32, u32, s32, s32);
    void _subaddieitem_entrypoint_2(s32);
    s32 func_801000D8(Actor*, s32, s32);
    void func_80102424(Actor*, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_801000D8(arg0, 0, 0x14);
    sp1C = temp_v0;
    _subaddieitem_entrypoint_0(temp_v0, 0x4E4U, 0x3E8, 3);
    _subaddieitem_entrypoint_2(sp1C);
    func_80102424(arg0, 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_808000CC_chcaptainblubber.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_808001F0_chcaptainblubber.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_80800580_chcaptainblubber.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_80800A1C_chcaptainblubber.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/captainblubber/func_8080143C_chcaptainblubber.s")

void func_808014C8_chcaptainblubber(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
OSThread *chcaptainblubber_entrypoint_0(void)
{
    extern u8 D_8080176C_chcaptainblubber[];

    return (OSThread *) D_8080176C_chcaptainblubber;
}
