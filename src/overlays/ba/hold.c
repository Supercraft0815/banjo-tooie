#include "ba/hold.h"

s32 bahold_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_bahold(u8 *arg0, s32 arg1) {
    s32 func_8009ADF0(void *, s32, s32);
    s32 var_a2;

    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x9C)))) + (8))) = arg1;
    if (arg1 != 0) {
        var_a2 = 1;
    } else {
        var_a2 = 0;
    }
    func_8009ADF0(arg0, 0xE, var_a2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/hold/bahold_entrypoint_1.s")

void bahold_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/hold/func_80800088_bahold.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/hold/func_808000E0_bahold.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/hold/bahold_entrypoint_3.s")

void bahold_entrypoint_4(s32 arg0)
{
    func_80800008_bahold(arg0,0);
}

Unk80132ED0 *bahold_entrypoint_5(PlayerState *arg0) {
    return (*(Unk80132ED0 **)((s8 *)(arg0->unk9C) + (8)));
}

/* extern */

void bahold_entrypoint_6(u8 *arg0, s32 arg1) {
    s32 func_808000E0_bahold(u8 *);
    func_80800008_bahold(arg0, arg1);
    func_808000E0_bahold(arg0);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x9C)))) + (0xC))) = 1;
}

void bahold_entrypoint_7(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x9C)))) + (0))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x9C)))) + (4))) = arg2;
}
