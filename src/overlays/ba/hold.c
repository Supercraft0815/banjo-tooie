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

void bahold_entrypoint_1(u8 *arg0) { void bahold_entrypoint_7(void *, f32, f32); func_80800008_bahold(arg0, (s32)0); (*(u8 **)((s8 *)arg0 + 0x9C))[0xC] = 0; bahold_entrypoint_7(arg0, 0.0f, 0.0f); }

void bahold_entrypoint_2(s32 arg0) 
{
}
/* extern */

void func_80800088_bahold(Unk80132ED0 *arg0, f32 arg1[3], f32 arg2[3]) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;

    actor = func_80106790(arg0);
    if (actor->unk64_23) {
        actor->position[0] = arg1[0];
        actor->position[1] = arg1[1];
        actor->position[2] = arg1[2];
        actor->rotation[1] = arg2[1];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/hold/func_808000E0_bahold.s")

/* extern */

void bahold_entrypoint_3(u8 *arg0) {
    s32 func_808000E0_bahold();
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x9C)));
    if ((*(s32 *)((s8 *)(temp_v0) + (8))) != 0) {
        if ((*(u8 *)((s8 *)(temp_v0) + (0xC))) == 0) {
            func_80800008_bahold(arg0, 0);
            return;
        }
        func_808000E0_bahold();
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x9C)))) + (0xC))) = 0;
    }
}

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
