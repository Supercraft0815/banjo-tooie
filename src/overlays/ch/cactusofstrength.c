#include "common.h"

OSThread *chcactusofstrength_entrypoint_0(void)
{
    extern u8 D_80800D00_chcactusofstrength[];

    return (OSThread *) D_80800D00_chcactusofstrength;
}

OSThread *chcactusofstrength_entrypoint_1(void)
{
    extern u8 D_80800D48_chcactusofstrength[];

    return (OSThread *) D_80800D48_chcactusofstrength;
}

OSThread *chcactusofstrength_entrypoint_2(void)
{
    extern u8 D_80800D90_chcactusofstrength[];

    return (OSThread *) D_80800D90_chcactusofstrength;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800024_chcactusofstrength.s")

void func_80800108_chcactusofstrength(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800110_chcactusofstrength.s")

/* extern */

s32 func_808001C4_chcactusofstrength(s32 arg0, s32 arg1, volatile s32 arg2) {
    s32 func_80800110_chcactusofstrength(s32, s32);
    s32 result;
    if (arg1 == 0x40) {
        func_80800110_chcactusofstrength(arg0, *(s32 *)&arg2);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800200_chcactusofstrength.s")

/* extern */

void func_808003EC_chcactusofstrength(void *arg0) {
    s32 func_800D0A9C(s32, s32, void *);
    s32 func_800FFAB0(void *);
    (*(s32 *)((s8 *)(arg0) + (0x50))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 1200.0f;
    if (func_800D0A9C(0x1E, 1, arg0) != 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800440_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_808004F8_chcactusofstrength.s")

/* extern */

void func_808006BC_chcactusofstrength(void *arg0) {
    s32 func_800CE88C(s32, s32);
    s32 func_800CEAA8(s32);
    s32 func_800CEAD0(s32);
    s32 func_80101FDC(void *, s32);
    if (((*(s32 *)((s8 *)(arg0) + (0x50))) != 0) && (func_800CEAD0(0) != 0)) {
        if (func_800CEAA8(0) != 0) {
            func_800CE88C(0, 0);
        }
        func_80101FDC(arg0, 3);
    }
}

/* extern */

void func_80800718_chcactusofstrength(void *arg0) {
    s32 _mlwave_entrypoint_0(s32, s32, s32);
    s32 func_80100074(void *, s32, s32);
    s32 func_80101FDC(void *, s32);
    s32 func_80103110(void *, s32);
    void *func_80106790(s32);
    void *sp1C;
    void *temp_v0;

    temp_v0 = func_80106790((*(s32 *)((s8 *)(arg0) + (0x3C))));
    sp1C = temp_v0;
    func_80101FDC(temp_v0, 2);
    func_80103110(sp1C, 1);
    (*(f32 *)((s8 *)(sp1C) + (0x58))) = 2.5f;
    _mlwave_entrypoint_0(func_80100074(sp1C, 1, 0x1C), 0x42C80000, 0x42A00000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800780_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800824_chcactusofstrength.s")

void func_8080094C_chcactusofstrength(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 mlAbsF(f32);
    extern s32 D_80800E08_chcactusofstrength;
    f32 *sp28;
    f32 sp30;
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if ((temp_t6 == 2) || (temp_t6 == 3)) {
        if (arg0->unk5F == 0) {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80800E08_chcactusofstrength);
        }
        if (arg0->unk5F != 0) {
            sp28 = arg0->position;
            sp30 = mlAbsF(((f32 *)arg0->actorData)[3]);
            sp30 = func_800F13F0(sp30, 20.0f);
            sp30 = func_800F0E00(5.0f, sp30);
            sp30 = func_800F10B4(sp30, 5.0f, 20.0f, 1.1f, 1.4f);
            func_800C4350(arg0->unk5F, sp28, 0);
            func_800C31DC(arg0->unk5F, sp30);
            func_800C3BDC(arg0->unk5F);
        }
    } else {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

void func_80800A44_chcactusofstrength(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    f32 _mlwave_entrypoint_5(u8 *, f32, f32);
    s32 _mlwave_entrypoint_8(u8 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u8 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800E18_chcactusofstrength;
    f32 sp28;
    u8 *sp30;
    f32 sp24[3];
    u8 *temp_v0;

    if (arg0->unk70_10 == 2) {
        temp_v0 = func_80100094(arg0, 1);
        sp30 = temp_v0;
        _mlwave_entrypoint_1(temp_v0);
        arg0->rotation[2] = _mlwave_entrypoint_5(sp30, -20.0f, 20.0f);
        if ((_mlwave_entrypoint_8(sp30, 0.75f) != 0) || (_mlwave_entrypoint_8(sp30, 0.25f) != 0)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800E18_chcactusofstrength);
        }
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800EE7F8(sp24, (f32 *)arg0->actorData);
            func_800EF1B8(sp24, arg0->rotation[1], -60.0f);
            sp24[1] -= 40.0f;
            _chexploder_entrypoint_3(arg0, sp24, 3);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800B24_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800B90_chcactusofstrength.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/cactusofstrength/func_80800C18_chcactusofstrength.s")
