#include "common.h"

OSThread *chbadjinjo_entrypoint_0(void)
{
    extern u8 D_80801288_chbadjinjo[];

    return (OSThread *) D_80801288_chbadjinjo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_8080000C_chbadjinjo.s")

/* extern */

void func_8080010C_chbadjinjo(s32 arg0, f32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA994(s32, s32, s16, s32, s32, s32, s32);
    s32 func_8080000C_chbadjinjo(s32, s32, s32);
    s32 sp2C;
    s32 temp_v0;

    temp_v0 = func_800B53A4(0xA);
    sp2C = temp_v0;
    func_8080000C_chbadjinjo(temp_v0, arg0, arg2);
    func_800BA994(sp2C, -0xF, (s16) (s32) (-60.0f + arg1), 0x15E, -5, (s32) (60.0f + arg1), 0x1C2);
    func_800BA22C(sp2C, 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_808001B0_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800278_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800358_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_808003EC_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_8080059C_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800C90_chbadjinjo.s")

void func_80800DF0_chbadjinjo(s32 arg0) 
{
}
s16 func_80800DF8_chbadjinjo(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    extern s16 D_80801384_chbadjinjo[];
    return D_80801384_chbadjinjo[*((u8 *)func_80100094(arg0, 0U) + 0x24)];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800E28_chbadjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80800F7C_chbadjinjo.s")

/* extern */

void func_80801054_chbadjinjo(Actor *arg0, s32 arg1, f32 arg2) {
    s32 func_80101E14(Actor*, f32);
    s32 func_80801090_chbadjinjo(Actor *, s32);
    if (func_80101E14(arg0, arg2) != 0) {
        func_80801090_chbadjinjo(arg0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/jinjo/func_80801090_chbadjinjo.s")

/* extern */

void func_80801118_chbadjinjo(void *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800C3D78(s32, u8);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x5F)));
    if ((temp_a1 != 0) && (func_800C3D78(temp_a1 & 0xFF, temp_a1) == 0)) {
        func_800C2FDC((*(u8 *)((s8 *)(arg0) + (0x5F))));
        (*(u8 *)((s8 *)(arg0) + (0x5F))) = 0U;
    }
}
