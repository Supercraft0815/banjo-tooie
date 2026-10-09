#include "common.h"

s32 bafly_entrypoint_0() 
{
    return 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_2.s")

u32 bafly_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 140) + 8);
}

/* extern */

void bafly_entrypoint_4(void *arg0) {
    s32 func_800C2FDC(s32, u8, void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9)));
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1 & 0xFF, temp_a1, arg0);
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x8C)))) + (9))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_5.s")

void bafly_entrypoint_6(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 140) + 0) = arg1;
}

void bafly_entrypoint_7(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 140) + 8) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_11.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_17.s")

void bafly_entrypoint_18(s32 arg0)
{
    baphysics_reset_gravity();
    func_8008E95C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/fly/bafly_entrypoint_21.s")
