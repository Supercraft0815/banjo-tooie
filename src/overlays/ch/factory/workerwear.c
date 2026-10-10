#include "common.h"

OSThread *chfactoryworkerwear_entrypoint_0(void)
{
    extern u8 D_80800438_chfactoryworkerwear[];

    return (OSThread *) D_80800438_chfactoryworkerwear;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_8080000C_chfactoryworkerwear.s")

void func_80800100_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x24))) = 0;
}

void func_80800124_chfactoryworkerwear(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_8080012C_chfactoryworkerwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_80800260_chfactoryworkerwear.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_808002E4_chfactoryworkerwear.s")

void func_80800320_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 func_80101068(void);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    (*(f32 *)((s8 *)(sp1C) + (0x20))) = func_80101068();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerwear/func_80800350_chfactoryworkerwear.s")
