#include "common.h"

OSThread *chmineprospector_entrypoint_0(void)
{
    extern u8 D_8080102C_chmineprospector[];

    return (OSThread *) D_8080102C_chmineprospector;
}

OSThread *chmineprospector_entrypoint_1(void)
{
    extern u8 D_80801074_chmineprospector[];

    return (OSThread *) D_80801074_chmineprospector;
}

OSThread *chmineprospector_entrypoint_2(void)
{
    extern u8 D_808010BC_chmineprospector[];

    return (OSThread *) D_808010BC_chmineprospector;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800024_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_8080029C_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800340_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800398_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800540_chmineprospector.s")

void func_808005F0_chmineprospector(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_3(s32, s32, s32 *, s32);
    s32 func_800DC298(f32);
    extern s32 D_80800FB0_chmineprospector;
    if (func_800DC298(0.2f) != 0) {
        _subaddieaudioquick_entrypoint_3(arg0, arg0 + 0x28, &D_80800FB0_chmineprospector, 0x3F4CCCCD);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800638_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_8080068C_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808006EC_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_8080084C_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808008A4_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800910_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800970_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808009B0_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800A64_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800AF0_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800BF4_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800CD4_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800D34_chmineprospector.s")

void func_80800D8C_chmineprospector(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(s32, s32, s32 *, s32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    extern u32 D_80801184_chmineprospector;
    extern s32 D_80801194_chmineprospector;
    extern s32 D_808011A0_chmineprospector;
    extern u32 D_808011AC_chmineprospector;

    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_80801184_chmineprospector, &D_808011AC_chmineprospector);
    _subaddieaudioquick_entrypoint_3((s32) arg0, (s32) temp_a1, &D_80801194_chmineprospector, 0x3F400000);
    _subaddieaudioquick_entrypoint_3((s32) arg0, (s32) temp_a1, &D_808011A0_chmineprospector, 0x3F19999A);
}

void func_80800DF8_chmineprospector(s32 arg0) 
{
}
/* extern */

void func_80800E00_chmineprospector(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
