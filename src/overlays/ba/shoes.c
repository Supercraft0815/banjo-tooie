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

/* extern */

void func_808000D4_bashoes(void *arg0, s32 arg1) {
    void _baalarm_free();
    void bastatetimer_set(void *, s32, f32);
    void func_800A0DB8(void *, s32);
    void func_800C77DC(s32);
    _baalarm_free();
    func_800A0DB8(arg0, 1);
    if (arg1 != 0) {
        func_800C77DC(1);
        bastatetimer_set(arg0, 3, 0.0f);
    }
}

/* extern */

void func_80800128_bashoes(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _baalarm_new();
    s32 baflag_clear(s32, s32);
    void func_800A0DB8(void *, s32);
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

s32 bashoes_entrypoint_9(void *arg0) {
    return (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x10C) + 0x14)) > 0.0f ? 1 : 0;
}

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

void bashoes_entrypoint_16(s32 arg0) {
    s32 func_8009C128(s32, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, s32 *, s32 *, s32, s32 *);
    extern s32 D_80800AD0_bashoes;
    s32 sp24[3];
    s32 sp20;

    sp20 = func_800B53A4(6);
    func_8009C128(arg0, &sp24);
    func_800BABB8(sp20, &sp24, &sp24, 0x3F800000, &D_80800AD0_bashoes);
}

void bashoes_entrypoint_17(s32 arg0) {
    s32 func_8009C128(s32, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, s32 *, s32 *, s32, s32 *);
    extern s32 D_80800B4C_bashoes;
    s32 sp24[3];
    s32 sp20;

    sp20 = func_800B53A4(30);
    func_8009C128(arg0, &sp24);
    func_800BABB8(sp20, &sp24, &sp24, 0x3F800000, &D_80800B4C_bashoes);
}

void bashoes_entrypoint_18(s32 arg0) {
    s32 func_80092E08(s32, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, s32 *, s32 *, s32, s32 *);
    extern s32 D_80800B90_bashoes;
    f32 sp28;
    s32 sp24[2];
    s32 sp20;

    sp20 = func_800B53A4(0xA);
    func_80092E08(arg0, sp24);
    *(f32 *)((s8 *)sp24 + 4) -= 30.0f;
    func_800BABB8(sp20, sp24, sp24, 0x3F800000, &D_80800B90_bashoes);
}

void bashoes_entrypoint_19(s32 arg0) {
    s32 func_80092E2C(s32, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, s32 *, s32 *, s32, s32 *);
    extern s32 D_80800B90_bashoes;
    f32 sp28;
    s32 sp24[2];
    s32 sp20;

    sp20 = func_800B53A4(0xA);
    func_80092E2C(arg0, sp24);
    *(f32 *)((s8 *)sp24 + 4) -= 30.0f;
    func_800BABB8(sp20, sp24, sp24, 0x3F800000, &D_80800B90_bashoes);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoes/bashoes_entrypoint_20.s")
