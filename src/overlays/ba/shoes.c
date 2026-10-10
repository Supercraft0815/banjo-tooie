#include "common.h"

s32 bashoes_entrypoint_0() 
{
    return 0x18;
}

u32 bashoes_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 4);
}

u32 bashoes_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 16);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/func_80800020_bashoes.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/func_808000D4_bashoes.s")

/* extern */

void func_80800128_bashoes(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _baalarm_new();
    s32 baflag_clear(s32, s32);
    s32 func_800A0DB8(s32, s32);
    s32 func_80800020_bashoes(s32);
    _baalarm_new();
    baflag_clear(arg0, arg1);
    func_800A0DB8(arg0, arg2);
    if (arg3 != 0) {
        func_80800020_bashoes(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/func_80800180_bashoes.s")

void bashoes_entrypoint_3(s32 arg0)
{
    bashoes_entrypoint_6(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_4.s")

void bashoes_entrypoint_5(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 5) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_6.s")

void bashoes_entrypoint_7(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 8) = arg1;
}

void bashoes_entrypoint_8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 12) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_9.s")

void bashoes_entrypoint_10(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 20) = arg1;
}

void bashoes_entrypoint_11(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 16) = arg1;
}

void bashoes_entrypoint_12(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 268) + 0) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_20.s")
