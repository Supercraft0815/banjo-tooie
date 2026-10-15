#include "common.h"

void func_8010EF70(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800192FC(s32 *, s32 *);
    u8 func_800DF8D4();
    s32 func_800DF8F8(s32);
    s32 func_800EE97C(s32 *, s32 *, s32 *);
    s32 func_800EF2A0(s32 *);
    s32 func_800EF368(s32 *, f32);
    s32 func_800EFA4C(s32 *, f32, f32, f32);
    s32 func_800EFB24(s32 *, s32, s32);
    extern s32 D_80137210;
    extern s32 D_80137214;
    extern s32 D_80137220;
    extern s32 D_8013722C;
    extern u8 D_80137238;
    D_80137210 = arg0;
    D_80137238 = func_800DF8D4();
    func_800EFB24(&D_80137214, func_800DF8F8(arg0), arg3);
    func_800EF368(&D_80137214, -1.0f);
    func_800EFA4C(&D_8013722C, 0.0f, 1.0f, 0.0f);
    func_800EE97C(&D_80137220, &D_8013722C, &D_80137214);
    func_800EF2A0(&D_80137220);
    func_800EE97C(&D_8013722C, &D_80137214, &D_80137220);
    func_800EF2A0(&D_8013722C);
    if (D_80137238 == 0) {
        func_800192FC(&D_8013722C, &D_8013722C);
        func_800192FC(&D_80137220, &D_80137220);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8860/func_8010F070.s")

void func_8010F270(void)
{
    extern s32 D_80137210;

    D_80137210 = 0;
}
