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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800A88_chnutsnbolts.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800B80_chnutsnbolts.s")

void func_80800BD4_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800CC0_chnutsnbolts, 0x3F266666);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_80800C04_chnutsnbolts.s")
