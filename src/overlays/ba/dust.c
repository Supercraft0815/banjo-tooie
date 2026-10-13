#include "common.h"

s32 badust_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_badust(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/func_80800010_badust.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_2.s")

/* extern */

typedef struct player_state_s PlayerState;

void badust_entrypoint_3(PlayerState *arg0, f32 arg1, f32 arg2) {
    void badust_entrypoint_2(PlayerState *, f32 *, f32 *, f32, f32, f32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    func_8009C128(arg0, sp20);
    sp20[1] += 12.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = 50.0f;
    badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_10.s")

/* extern */

void badust_entrypoint_11(void *arg0) {
    s32 badust_entrypoint_12(void *, s32);
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x5C)))) + (4))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x5C)))) + (8))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x5C)))) + (0))) = 0;
    badust_entrypoint_12(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/dust/badust_entrypoint_13.s")
