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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_8080052C_chboggyfatboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_808005AC_chboggyfatboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800808_chboggyfatboy.s")

void func_80800978_chboggyfatboy(Actor* arg0)
{
    func_80800FAC_chboggyfatboy(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800998_chboggyfatboy.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/fatboy/func_80800E80_chboggyfatboy.s")

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
