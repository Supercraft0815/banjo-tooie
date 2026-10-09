#include "common.h"

OSThread *chamazonstadiumguard_entrypoint_0(void)
{
    extern u8 D_80800700_chamazonstadiumguard[];

    return (OSThread *) D_80800700_chamazonstadiumguard;
}

void func_8080000C_chamazonstadiumguard(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((s8 *)(arg0) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800028_chamazonstadiumguard.s")

void func_808002F4_chamazonstadiumguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800328_chamazonstadiumguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800488_chamazonstadiumguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800530_chamazonstadiumguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_808005CC_chamazonstadiumguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800620_chamazonstadiumguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazonstadiumguard/func_80800648_chamazonstadiumguard.s")
