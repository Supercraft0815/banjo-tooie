#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80800000_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_808000B4_cheel.s")

void func_80800128_cheel(Actor *arg0) {
    void func_800C8B84(s32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(s32 *)((s8 *)(temp_v0) + (0xDC))) != 0) {
        sp1C = temp_v0;
        func_800C8B84((*(s32 *)((s8 *)(temp_v0) + (0xDC))));
        (*(s32 *)((s8 *)(sp1C) + (0xDC))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80800168_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_8080020C_cheel.s")

/* extern */

s32 func_808002A0_cheel(u8 *arg0) {
    s32 func_800EFFB4(u8 *, s32, u8 *, u8 *);
    f32 func_800F1DCC(f32, f32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x48))), (*(f32 *)((s8 *)(arg0) + (0x54))));
    var_f2 = temp_f0;
    if (temp_f0 < 0.0f) {
        var_f2 = -temp_f0;
    }
    if ((var_f2 < 30.0f) || (func_800EFFB4(arg0 + 0x18, 0x43480000, arg0 + 4, arg0) != 0)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_8080031C_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80800D60_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80801120_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80801200_cheel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eel/func_80801330_cheel.s")

OSThread *cheel_entrypoint_0(void)
{
    extern u8 D_80801644_cheel[];

    return (OSThread *) D_80801644_cheel;
}
