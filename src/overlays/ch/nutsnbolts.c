#include "common.h"

OSThread *chnutsnbolts_entrypoint_0(void)
{
    extern u8 D_80800E28_chnutsnbolts[];

    return (OSThread *) D_80800E28_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_1(void)
{
    extern u8 D_80800E70_chnutsnbolts[];

    return (OSThread *) D_80800E70_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_2(void)
{
    extern u8 D_80800EB8_chnutsnbolts[];

    return (OSThread *) D_80800EB8_chnutsnbolts;
}

/* extern */

void func_80800024_chnutsnbolts(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    _subaddierouteDll_entrypoint_3(arg0, temp_v0 + 8, arg0->position);
    func_8080092C_chnutsnbolts(arg0, 2);
    (*(f32 *)((s8 *)(sp24) + (0x1C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800080_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_808005D0_chnutsnbolts.s")

/* extern */

void func_808008FC_chnutsnbolts(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
    _subaddiefx_entrypoint_1(arg0, func_80100094(arg0, 0U));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_8080092C_chnutsnbolts.s")

s32 func_80800A88_chnutsnbolts(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    u8 *data;

    data = func_80100094(arg0, 0U);
    if (arg0->unk64_29) {
        func_8080092C_chnutsnbolts(arg0, arg2);
        return 1;
    }
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if (data[0x16] != 0) {
        func_8080092C_chnutsnbolts(arg0, arg2);
        return 1;
    }
    if (((arg1 != 0) || ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_800DC298(0.2f) != 0))) &&
        (func_8010C9B0(arg0->position, 1500) != 0) && (func_8010C500(arg0) != 0)) {
        func_8080092C_chnutsnbolts(arg0, arg2);
        return 1;
    }
    return 0;
}

void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
void func_80800B80_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    extern u32 D_80800F2C_chnutsnbolts;
    extern u32 D_80800F3C_chnutsnbolts;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 4);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[1], &D_80800CC0_chnutsnbolts, &D_80800F3C_chnutsnbolts);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800F2C_chnutsnbolts, 0.2f);
}

void func_80800BD4_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800CC0_chnutsnbolts, 0.65f);
}

void func_80800C04_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    extern u32 D_80800F48_chnutsnbolts;
    extern u32 D_80800F58_chnutsnbolts;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800F48_chnutsnbolts, 0.7f);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[1], &D_80800CC0_chnutsnbolts, &D_80800F58_chnutsnbolts);
}
