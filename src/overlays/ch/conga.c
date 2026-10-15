#include "ch/conga.h"

OSThread *chconga_entrypoint_0(void)
{
    extern u8 D_808006A0_chconga[];

    return (OSThread *) D_808006A0_chconga;
}

/* extern */

void func_8080000C_chconga(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddieitem_entrypoint_0(s32, s32, s32, s32);
    s32 _subaddieitem_entrypoint_1(s32, s32);
    s32 func_800D395C();
    s32 func_800DA298(s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_800FFAB0(s32);
    s32 func_80100094(s32, s32);
    s32 func_80102424(s32, s32);
    s32 func_80105A9C(s32, s32);
    s32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800DA298(0x17F);
    sp20 = func_800F64A4(func_800F54E4(), 1);
    sp1C = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
        goto block_10;
    }
    if (func_800DA298(0x9C) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if ((sp1C != 0) && (sp24 == 0)) {
        func_80102424(arg0, 4);
        func_80105A9C(arg0, 0x43C80000);
        goto block_10;
    }
    if ((sp24 != 0) && (sp20 != 0)) {
        func_800FFAB0(arg0);
        return;
    }
block_10:
    _subaddieitem_entrypoint_0(func_80100094(arg0, 0), 0x4E2, -1, 3);
    _subaddieitem_entrypoint_1(func_80100094(arg0, 0), 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800118_chconga.s")

void func_80800280_chconga(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_808002A0_chconga.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/conga/func_80800374_chconga.s")

s32 func_80800478_chconga(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D1A04(s32 a0);
    if ((arg1 == 0x10B0) || (arg1 == 0x10B1)) {
        return func_800D1A04(0x4D);
    }
    return 0;
}

/* extern */

s32 func_808004BC_chconga(s32 arg0, s32 arg1) {
    int func_800C6E38(s32);
    s32 var_v1;

    if ((func_800C6E38(0x1B) != 0) && (func_800C6E38(0x2D) != 0)) {
        var_v1 = arg1;
    } else if (func_800C6E38(0x1B) != 0) {
        var_v1 = 0x1112;
    } else if (func_800C6E38(0x2D) != 0) {
        var_v1 = 0x10FF;
    } else {
        var_v1 = 0x1113;
    }
    return var_v1;
}

void func_80800538_chconga(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800D1A04(s32);
    s32 func_800DA298(s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_80101180(s32, s32, s32);
    extern s32 D_808006F8_chconga;
    extern s16 D_808006FC_chconga;
    extern s16 D_808006FE_chconga;
    if ((func_800DA298(0x4A) != 0) && (func_800F64A4(func_800F54E4(), 1) != 0)) {
        D_808006FE_chconga = func_808004BC_chconga(arg0, 0x1101);
    } else {
        if (func_800D1A04(0x4D) >= 4) {
            D_808006FC_chconga = 0x10B1;
        } else {
            D_808006FC_chconga = 0x10B0;
        }
        if (func_800D1A04(0x4D) >= 4) {
            D_808006FE_chconga = 0x10B3;
        } else {
            D_808006FE_chconga = 0x10B2;
        }
    }
    if (_subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_808006F8_chconga) == 0x1101) {
        func_80101180(0x46E, 7, 0);
    }
}

void func_80800618_chconga(Actor *arg0) {
    extern u32 D_80800714_chconga;
    extern u32 D_80800724_chconga;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800714_chconga, &D_80800724_chconga);
}
