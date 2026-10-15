#include "ch/boggy/fatboy.h"

OSThread *chboggyfatboy_entrypoint_0(void)
{
    extern u8 D_80801120_chboggyfatboy[];

    return (OSThread *) D_80801120_chboggyfatboy;
}

OSThread *chboggyfatboy_entrypoint_1(void)
{
    extern u8 D_808011DC_chboggyfatboy[];

    return (OSThread *) D_808011DC_chboggyfatboy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800018_chboggyfatboy.s")

void func_80800078_chboggyfatboy(Actor *arg0) {
    void *data = func_80100094(arg0, 0);
    _subaddieitem_entrypoint_0((s32)data + 0xC, 0x3CA, 0x190, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_808000AC_chboggyfatboy.s")

/* extern */

void func_8080052C_chboggyfatboy(Actor *arg0) {
    void _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_800DA980(s32, s32);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, s32);
    s32 func_80105230();
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    func_80105834(arg0);
    func_80105230(arg0, 0);
    _sudeflect_entrypoint_0(arg0->position, 100.0f, 50.0f, 0xA);
    if (func_80105A5C(arg0) != 0) {
        if (func_800DA980(0x8C, 3) != 3) {
            func_80101180(0x13F, 0x4F, 0);
        }
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_808005AC_chboggyfatboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800808_chboggyfatboy.s")

void func_80800978_chboggyfatboy(Actor* arg0)
{
    func_80800FAC_chboggyfatboy(arg0);
}

void func_80800998_chboggyfatboy(Actor *arg0) {
    s32 func_800EE940();
    Actor *func_80106790(Unk80132ED0 *);
    s32 sp1C;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = func_80106790(arg0->unk3C);
    ((s16 *)sp1C)[3] = *(s32 *)((u8 *)temp_v0 + 0x2C);
    func_800EE940((void *)sp1C, (u8 *)temp_v0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_808009E0_chboggyfatboy.s")

/* extern */

void func_80800AF0_chboggyfatboy(s32 arg0, s32 arg1) {
    s32 _subaddietaxi_entrypoint_2(s32, s32);
    s32 func_800DA298(s32);
    s32 func_80102424(s32, s32);
    if ((func_800DA298(0xBB) != 0) && (_subaddietaxi_entrypoint_2(arg0, 1) != 0)) {
        func_80102424(arg0, 9);
    }
}

void func_80800B38_chboggyfatboy(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA298(0x8E) == 0) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800BA0_chboggyfatboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800C5C_chboggyfatboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800D84_chboggyfatboy.s")

void func_80800E80_chboggyfatboy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_800C4B7C(s32);
    s32 func_800DC128(s32, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    s32 func_801022E4(Actor *);
    extern s16 D_808012A0_chboggyfatboy[];
    extern f32 D_808012AC_chboggyfatboy[];
    extern s32 D_808012BC_chboggyfatboy;
    extern s32 D_808012CC_chboggyfatboy;
    extern s32 D_808012E8_chboggyfatboy;
    if (func_801022E4(arg0) == 0x246) {
        if (func_80101E14(arg0, 0.0f) != 0) {
            func_800C4B7C(D_808012A0_chboggyfatboy[func_800DC128(0, 5)]);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012BC_chboggyfatboy);
        }
        if (func_80101E14(arg0, 0.5f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012CC_chboggyfatboy);
        }
        if (func_80101E4C(arg0, D_808012AC_chboggyfatboy) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808012E8_chboggyfatboy);
        }
    }
}

/* extern */

void func_80800F40_chboggyfatboy(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x3D);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

void func_80800FAC_chboggyfatboy(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
/* extern */

s32 func_80800FE0_chboggyfatboy(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F640C(s32, s32);
    s32 func_800F64A4(s32, s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F64A4(temp_v0, 0x201) == 0) {
        return 0;
    }
    return func_800F640C(sp1C, arg0) > 0;
}
