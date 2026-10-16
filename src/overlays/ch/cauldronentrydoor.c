#include "ch/cauldronentrydoor.h"

/* extern */

void func_80800000_chcauldronentrydoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_4(Actor *, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _glcutDll_entrypoint_19(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80104004(Actor *, f32 *, f32 *);
    void func_8010A800(Actor *, s32);
    f32 *temp_s1;

    temp_s1 = func_80100094(arg0, 1);
    if (_chdoormake_entrypoint_4(arg0, 1, 0x58E) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.0f);
        _chdoormake_entrypoint_6(arg0, 0x40000000);
        _chdoormake_entrypoint_8(arg0, 0xB);
        _chdoormake_entrypoint_9(arg0, 0, 0x56, 0x14);
    }
    func_8010A800(arg0, 0);
    func_80104004(arg0, temp_s1, temp_s1 + 3);
    temp_s1[5] = temp_s1[2] + 40.0f;
    if (_glcutDll_entrypoint_19(0x5B) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_808000C8_chcauldronentrydoor(Actor *arg0) {
    s32 _chdoor_entrypoint_0();
    s32 _chelectricfence_entrypoint_2(Actor *, u8 *, u8 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    void func_8010A590(Actor *);
    extern u32 D_80800520_chcauldronentrydoor[];
    u8 *temp_v0;

    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800520_chcauldronentrydoor);
    if (func_800D9078((f32 *)&arg0->actorData[4]) != 0) {
        func_8010A590(arg0);
    }
    if (arg0->unk7C_12 && func_800DA298(0x436) != 0 && func_800DC298(0.2f) != 0) {
        temp_v0 = func_80100094(arg0, 1);
        _chelectricfence_entrypoint_2(arg0, temp_v0, temp_v0 + 0xC);
    }
    _chdoor_entrypoint_0(arg0);
}

s32 func_80800168_chcauldronentrydoor(Actor *arg0, s32 arg1, void *arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    f32 func_800EC75C(void *, f32 *);
    void func_800FC6B0(u32);
    void func_8010A570(Actor *);
    f32 sp20[4];
    void **marker = &arg2;

    switch (arg1) {
        case 7:
            func_800FC6B0(0xE);
            return _chdoor_entrypoint_1(arg0, arg1, *marker);
        case 0x3F:
            func_800EC75C(*marker, sp20);
            _chelectricfence_entrypoint_1(arg0, sp20);
            func_8010A570(arg0);
            *(f32 *)&arg0->actorData[4] = 0.2f;
            return 1;
        default:
            return 0;
    }
}

/* extern */

void func_808001FC_chcauldronentrydoor(void *arg0) {
    s32 func_800DA298(s32);
    (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 0.0f;
    if (func_800DA298(0x436) != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x1C))) = 360.0f;
    } else {
        (*(f32 *)((s8 *)(arg0) + (0x1C))) = 270.0f;
    }
    (*(f32 *)((s8 *)(arg0) + (0x20))) = 0.5f;
    (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x1C)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_80800274_chcauldronentrydoor.s")

void func_80800370_chcauldronentrydoor(s32 arg0) 
{
}
void chcauldronentrydoor_entrypoint_0()
{
    func_800E1720();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cauldronentrydoor/func_80800398_chcauldronentrydoor.s")

OSThread *chcauldronentrydoor_entrypoint_1(void)
{
    extern u8 D_80800550_chcauldronentrydoor[];

    return (OSThread *) D_80800550_chcauldronentrydoor;
}

OSThread *chcauldronentrydoor_entrypoint_2(void)
{
    extern u8 D_80800598_chcauldronentrydoor[];

    return (OSThread *) D_80800598_chcauldronentrydoor;
}
