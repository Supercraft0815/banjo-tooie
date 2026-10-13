#include "common.h"

OSThread *chfpsgame_entrypoint_0(void)
{
    extern u8 D_808021A0_chfpsgame[];

    return (OSThread *) D_808021A0_chfpsgame;
}

void func_8080000C_chfpsgame(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (arg2 != 0) {
        (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (4))) | (1 << arg1));
        return;
    }
    (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (4))) & ~(1 << arg1));
}

s32 func_80800074_chfpsgame(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 var_v1;

    if ((*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))) & (1 << arg1)) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808000BC_chfpsgame.s")

/* extern */

void func_80800138_chfpsgame(u32 arg0) {
    s32 func_800F5898();
    s32 func_800F6BE4(s32);
    s32 func_800F7F98(s32, u32);
    s32 var_s0;

    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if (func_800F6BE4(var_s0) != 0) {
                func_800F7F98(var_s0, arg0);
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080019C_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808002FC_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808003D0_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808004E0_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808005B0_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808006A8_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080075C_chfpsgame.s")

/* extern */

void func_808008D4_chfpsgame(s32 arg0) {
    s32 func_80800FF4_chfpsgame(s32);
    s32 func_808015EC_chfpsgame();
    s32 func_80801758_chfpsgame(s32);
    s32 func_808018E0_chfpsgame(s32);
    func_808015EC_chfpsgame();
    func_80800FF4_chfpsgame(arg0);
    func_80801758_chfpsgame(arg0);
    func_808018E0_chfpsgame(arg0);
}

void func_8080090C_chfpsgame(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800914_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800BCC_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800CF8_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80800FF4_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080121C_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808012CC_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_8080135C_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808013DC_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808015EC_chfpsgame.s")

s32 func_80801758_chfpsgame(s32 arg0) {
    void *func_80100094(Actor *, u32);
    s32 _sumultiscore_entrypoint_6(u8 *);
    return _sumultiscore_entrypoint_6((u8 *)func_80100094((Actor *)arg0, 0U) + 0x14);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801780_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801814_chfpsgame.s")

void func_808018B0_chfpsgame(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (0x558))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x559))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (0x55C))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_808018E0_chfpsgame.s")

void func_80801A8C_chfpsgame(Actor *arg0, f32 arg1) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(f32 *)((s8 *)(temp_v0) + (0x564))) = arg1;
    if (arg1 != 0.0f) {
        (*(s8 *)((s8 *)(temp_v0) + (0x558))) = 1;
        return;
    }
    (*(s8 *)((s8 *)(temp_v0) + (0x558))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801ADC_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801B30_chfpsgame.s")

void func_80801C5C_chfpsgame(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s32 *)((s8 *)(temp_v0) + (0x5BC))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x5C0))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x610))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x614))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x664))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x668))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x568))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x56C))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801C9C_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801D40_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801DF0_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80801F34_chfpsgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fpsgame/func_80802020_chfpsgame.s")
