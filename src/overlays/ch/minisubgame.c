#include "common.h"

OSThread *chminisubgame_entrypoint_0(void)
{
    extern u8 D_80801424_chminisubgame[];

    return (OSThread *) D_80801424_chminisubgame;
}

OSThread *chminisubgame_entrypoint_1(void)
{
    extern u8 D_8080146C_chminisubgame[];

    return (OSThread *) D_8080146C_chminisubgame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800018_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_808000C8_chminisubgame.s")

void func_80800430_chminisubgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(arg0, (s32) (sp1C + 0x30C)) != 0) {
        _susubgame_entrypoint_4(arg0, (s32) (sp1C + 0x30C));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800484_chminisubgame.s")

void func_80800A64_chminisubgame(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    arg0->actorData[5] -= 1;
    (*(s8 *)((s8 *)((temp_v0 + arg1)) + (0x2D0))) = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800AAC_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800BA8_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800EC8_chminisubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80801058_chminisubgame.s")

void func_808011DC_chminisubgame(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808014B4_chminisubgame;
    s32 sp24;
    f32 *temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 4;
    func_800BABB8(sp24, temp_a1, temp_a1, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_808014B4_chminisubgame);
    func_800BA22C(sp24, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80801248_chminisubgame.s")
