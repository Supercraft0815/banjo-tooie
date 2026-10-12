#include "common.h"

s32 glrecord_entrypoint_0(OSContPad *arg0, s32 *arg1) {
    extern s32 D_8012D5B0;
    struct Record { u8 x; u8 y; u16 button; u8 lag; u8 pad; } *record;
    s32 count;
    int valid;

    count = *(s32 *)((s8 *)&D_8012D5B0 + 8);
    record = (struct Record *)*(s32 *)((s8 *)&D_8012D5B0) + (*(s32 *)((s8 *)&D_8012D5B0 + 8))++;
    valid = *(s32 *)((s8 *)&D_8012D5B0 + 8) < *(s32 *)((s8 *)&D_8012D5B0 + 0xC);
    if (!valid) {
        record = (struct Record *)((s8 *)&D_8012D5B0 + 0x10);
    }
    arg0->stick_x = record->x;
    arg0->stick_y = record->y;
    arg0->button = record->button;
    *arg1 = record->lag;
    return valid;
}

void glrecord_entrypoint_1(s32 arg0, u32 arg1, s32 arg2) {
    extern s32 D_8012D5B0;
    (*(s32 *)((s8 *)(&D_8012D5B0) + (0))) = arg0;
    (*(u32 *)((s8 *)(&D_8012D5B0) + (0xC))) = (u32) (arg1 / 6U);
    (*(s32 *)((s8 *)(&D_8012D5B0) + (8))) = 0;
}

s32 glrecord_entrypoint_2(void) {
    extern s32 D_8012D5B0;
    return (*(s32 *)((s8 *)(&D_8012D5B0) + (8))) * 6;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/record/glrecord_entrypoint_3.s")

void glrecord_entrypoint_4(void) {
    s32 func_800D56C4(s32);
    extern s32 D_8012D5B0;
    if ((*(s32 *)((s8 *)(&D_8012D5B0) + (4))) != 0) {
        func_800D56C4((*(s32 *)((s8 *)(&D_8012D5B0) + (4))));
        (*(s32 *)((s8 *)(&D_8012D5B0) + (4))) = 0;
    }
}
