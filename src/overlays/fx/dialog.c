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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/dialog/fxdialog_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/dialog/fxdialog_entrypoint_4.s")
