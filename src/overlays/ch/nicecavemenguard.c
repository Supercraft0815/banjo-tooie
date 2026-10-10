#include "ch/nicecavemenguard.h"

OSThread *chnicecavemenguard_entrypoint_0(void)
{
    extern u8 D_80800920_chnicecavemenguard[];

    return (OSThread *) D_80800920_chnicecavemenguard;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_8080000C_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808000D4_chnicecavemenguard.s")

void func_80800388_chnicecavemenguard(Actor* arg0)
{
    func_8080080C_chnicecavemenguard(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808003A8_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808004FC_chnicecavemenguard.s")

void func_808005D4_chnicecavemenguard(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if (arg1 != 0x17E8) {
        func_80102424(arg0, 1);
    }
}

void func_80800600_chnicecavemenguard(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_80800608_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_80800730_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_8080075C_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808007A8_chnicecavemenguard.s")

void func_8080080C_chnicecavemenguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
