#include "common.h"

OSThread *chaliendad_entrypoint_0(void)
{
    extern u8 D_80802674_chaliendad[];

    return (OSThread *) D_80802674_chaliendad;
}

OSThread *chaliendad_entrypoint_1(void)
{
    extern u8 D_808026BC_chaliendad[];

    return (OSThread *) D_808026BC_chaliendad;
}

OSThread *chaliendad_entrypoint_2(void)
{
    extern u8 D_80802704_chaliendad[];

    return (OSThread *) D_80802704_chaliendad;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80800024_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_808000AC_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_808008C8_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80800918_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80800A54_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80800F28_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801110_chaliendad.s")

void func_80801220_chaliendad(void *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieaudioquick_entrypoint_2(void *, void *, s32 *);
    extern s32 D_8080281C_chaliendad;
    if (arg1 == 0x12A0) {
        _subaddieaudioquick_entrypoint_2(arg0, (u8 *)arg0 + 4, &D_8080281C_chaliendad);
    }
}

/* extern */

s32 func_80801254_chaliendad(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80801C9C_chaliendad(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x1C))) != 2) {
            func_80801C9C_chaliendad(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_808012AC_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801324_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_8080142C_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_8080152C_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801868_chaliendad.s")

void func_80801B9C_chaliendad(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808025C0_chaliendad;
    extern s32 D_80802824_chaliendad;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_80802824_chaliendad, &D_808025C0_chaliendad, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801BD4_chaliendad.s")

/* extern */

void func_80801C60_chaliendad(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x1C))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x1C))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801C9C_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801D40_chaliendad.s")

s32 func_80801DD0_chaliendad(void) {
    s32 func_800DA298(s32);
    s32 i;
    s32 count = 0;
    for (i = 0; i < 3; i++) {
        if (func_800DA298(i + 0x372)) {
            count++;
        }
    }
    return count;
}

/* extern */

void func_80801E28_chaliendad(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0x62);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x3E8);
    }
}

void func_80801E80_chaliendad(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801EB4_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80801F98_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80802058_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80802188_chaliendad.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80802218_chaliendad.s")

void func_80802284_chaliendad(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    void func_80103DFC(Actor*, f32*);
    extern u32 D_80802834_chaliendad;
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    _subaddieaudioloop_entrypoint_4(arg0, sp1C, (arg0->unk70_10 ^ 1) != 0, &D_80802834_chaliendad);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_808022CC_chaliendad.s")

void func_80802330_chaliendad(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.85f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/aliendad/func_80802340_chaliendad.s")
