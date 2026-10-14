#include "ch/hellterskelter.h"

OSThread *chhellterskelter_entrypoint_0(void)
{
    extern u8 D_808007C8_chhellterskelter[];

    return (OSThread *) D_808007C8_chhellterskelter;
}

OSThread *chhellterskelter_entrypoint_1(void)
{
    extern u8 D_80800810_chhellterskelter[];

    return (OSThread *) D_80800810_chhellterskelter;
}

OSThread *chhellterskelter_entrypoint_2(void)
{
    extern u8 D_80800858_chhellterskelter[];

    return (OSThread *) D_80800858_chhellterskelter;
}

/* extern */

void func_80800024_chhellterskelter(u8 *arg0) {
    s32 _gccubesearch_entrypoint_0(s32, u8 *);
    s32 func_800EE88C(u8 *, s32);
    s32 func_80108B04(u8 *, s32);
    s32 sp24;
    s32 sp20;

    sp24 = _gccubesearch_entrypoint_0(0x154, arg0);
    sp20 = _gccubesearch_entrypoint_0(0x320, arg0);
    func_800EE88C(arg0 + 0x18, sp24);
    func_800EE88C(arg0 + 0x28, sp20);
    if (func_800DA298(FLAG3_A4B_UNK) != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
        func_80108B04(arg0, 0x210);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_808000A8_chhellterskelter.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800158_chhellterskelter.s")

void func_80800274_chhellterskelter(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A4B_UNK);
}

void func_80800294_chhellterskelter(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x339, 0xA, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_808002E8_chhellterskelter(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_808002F0_chhellterskelter.s")

void func_808004D0_chhellterskelter(s32 arg0) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    s32 func_800DC298(f32);
    void *func_80105494();
    extern s32 D_808008C0_chhellterskelter;
    if (!((*(f32 *)((s8 *)(func_80105494()) + (0xC))) > 0.9f) && (func_800DC298(0.1f) != 0)) {
        func_800BBCB8(arg0 + 4, 0, 0x3F800000, 1, &D_808008C0_chhellterskelter);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800540_chhellterskelter.s")

void func_808005E0_chhellterskelter(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800938_chhellterskelter[];
    extern s32 D_80800974_chhellterskelter;
    f32 sp24[3];

    func_800EE7F8(sp24, arg0->position);
    sp24[1] -= 100.0f;
    func_800EF1B8(sp24, arg0->rotation[1] + 180.0f, 50.0f);
    func_800BABB8(0, arg0->position, sp24, 1.0f, D_80800938_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800974_chhellterskelter);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskelter/func_80800680_chhellterskelter.s")
