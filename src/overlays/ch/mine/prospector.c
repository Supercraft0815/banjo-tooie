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

void func_80800340_chmineprospector(Actor *arg0, u8 *arg1) {
    void func_800DBEFC(s32 *, s32, s32);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC((s32 *) func_80104130(), 4, (s32) &arg0->actorData[4]);
        *(f32 *) &arg0->actorData[5] = arg0->position[1];
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800398_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_80800540_chmineprospector.s")

void func_808005F0_chmineprospector(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 func_800DC298(f32);
    extern u32 D_80800FB0_chmineprospector;
    if (func_800DC298(0.2f) != 0) {
        _subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 0x28), &D_80800FB0_chmineprospector, 0.8f);
    }
}

void func_80800638_chmineprospector(Actor *arg0) {
    extern u32 D_80800FB0_chmineprospector;
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_8080111C_chmineprospector;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 0x28);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_8080111C_chmineprospector, 0.03f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800FB0_chmineprospector, 0.65f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_8080068C_chmineprospector.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/prospector/func_808006EC_chmineprospector.s")

void func_8080084C_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_10(s32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    s32 func_80108B04(s32, s32);
    s32 func_80800A64_chmineprospector(s32, s32, s32);
    extern s32 D_80800F58_chmineprospector;
    if (_subaddiedialog_entrypoint_10(_subaddiedialog_entrypoint_9((s32)arg0, arg1, &D_80800F58_chmineprospector, 7)) != 0) {
        func_80800A64_chmineprospector(arg0, 1, 0x30);
        func_80108B04(arg0, 0);
    }
}

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
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    extern u32 D_80801184_chmineprospector;
    extern u32 D_80801194_chmineprospector;
    extern u32 D_808011A0_chmineprospector;
    extern u32 D_808011AC_chmineprospector;

    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = (f32 *) ((s8 *) arg0 + 4), &D_80801184_chmineprospector, &D_808011AC_chmineprospector);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_80801194_chmineprospector, 0.75f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_808011A0_chmineprospector, 0.6f);
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
