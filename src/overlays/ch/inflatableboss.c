#include "common.h"

OSThread *chinflatableboss_entrypoint_0(void)
{
    extern u8 D_80802E50_chinflatableboss[];

    return (OSThread *) D_80802E50_chinflatableboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080000C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800408_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808004A0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800A98_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800F84_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808010BC_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801164_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808012EC_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801418_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801554_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080183C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801904_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801958_chinflatableboss.s")

void func_80801AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor*, u32);
    if (arg1 == 0x1085) {
        func_80108B04(arg0, 0U);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801B04_chinflatableboss.s")

/* extern */

s32 func_80801C7C_chinflatableboss(void) {
    s32 func_80801CB4_chinflatableboss();
    return (s32) (0xC - func_80801CB4_chinflatableboss()) / 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801CB4_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801D38_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801DE0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801EA0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801F4C_chinflatableboss.s")

void func_80801FC0_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802F90_chinflatableboss;
    func_800BABB8(0, arg1, arg2, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f, &D_80802F90_chinflatableboss);
}

void func_8080200C_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802FC4_chinflatableboss;
    func_800BABB8(0, arg1, arg2, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f, &D_80802FC4_chinflatableboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802058_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802264_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808023B0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802450_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808024BC_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802590_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080267C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080272C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802910_chinflatableboss.s")

/* extern */

void func_808029AC_chinflatableboss(s32 arg0) {
    s32 func_800D2498(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80801CB4_chinflatableboss(s32);
    if ((func_800DA298(1) != 0) && (func_800DA298(3) == 0)) {
        func_800D2498(0xEC, func_80801CB4_chinflatableboss(arg0), 0);
    }
}

void func_80802A00_chinflatableboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802A2C_chinflatableboss(arg0, arg0->unk0, arg1, arg2);
}

void func_80802A2C_chinflatableboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    void _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x49D))) != 0) {
        arg3 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg1, arg0->unk0, arg2, arg3);
    (*(s8 *)((s8 *)(sp1C) + (0x49D))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802A9C_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802AD8_chinflatableboss.s")
