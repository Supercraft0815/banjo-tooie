#include "common.h"

void fxdialog_entrypoint_0(void) {
    extern s32 B_80800290_fxdialog;
    (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (0x10))) = 1.0f;
    (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (4))) = 0.0f;
    (*(s32 *)((s8 *)(&B_80800290_fxdialog) + (0xC))) = 0;
    (*(s32 *)((s8 *)(&B_80800290_fxdialog) + (8))) = 0;
    (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (0))) = (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (4)));
}

void fxdialog_entrypoint_1(s32 arg0, s32 arg1) {
    extern s32 B_80800290_fxdialog;
    (*(s32 *)((s8 *)(&B_80800290_fxdialog) + (8))) = (s32) (arg0 * 4);
    (*(s32 *)((s8 *)(&B_80800290_fxdialog) + (0xC))) = (s32) (arg1 * 4);
    (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (0))) = (f32) arg0;
    (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (4))) = (f32) arg1;
}

void fxdialog_entrypoint_2(f32 arg0) {
    extern s32 B_80800290_fxdialog;
    if (arg0 > 0.0f) {
        (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (0x10))) = arg0;
        (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (0x14))) = (f32) (1.0f / arg0);
    }
}

void fxdialog_entrypoint_3(s32 arg0, f32 arg1, s32 arg2, s32 arg3) {
    s32 func_800D674C(s32);
    void func_800DF410(s32);
    void func_800DF41C(s32);
    void func_800DF944(u32, f32 *, f32, f32, f32 *, u8, s32);
    void func_800DFFA0(s32 *, s32, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_801040D0(void);
    extern s32 B_80800290_fxdialog;
    extern f32 B_808002A4_fxdialog;
    f32 sp40[2];
    f32 sp34[3];
    s32 sp30;
    s32 temp_v0;

    temp_v0 = func_801040D0();
    sp40[1] = -24.0f;
    sp30 = temp_v0;
    sp40[0] = 0.0f;
    func_800EFA4C(sp34, (arg1 * 0.041666668f * B_808002A4_fxdialog) - 2.0f, 0.0f, 0.0f);
    func_800DFFA0(sp30, 0x2A, sp34);
    func_800DF41C(sp30);
    func_800DF410(arg3);
    func_800DF944(arg0, &B_80800290_fxdialog, (f32) arg2 * 90.0f, (*(f32 *)((s8 *)(&B_80800290_fxdialog) + (0x10))), sp40, 0, func_800D674C(0x9F1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/dialog/fxdialog_entrypoint_4.s")
