#include "common.h"

/* extern */

void chanim_entrypoint_0(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790();
    (*(s32 *)((s8 *)(((s8 *)func_80100094(func_80106790(), 0) + (arg1 * 4))) + (4))) = 0;
}

/* extern */

void chanim_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790();
    (*(s32 *)((s8 *)(((s8 *)func_80100094(func_80106790(), 0) + (arg1 * 4))) + (4))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anim/chanim_entrypoint_2.s")

void chanim_entrypoint_3(s16 *arg0, f32 arg1, volatile s32 arg2, s32 arg3) {
    void _anseq_entrypoint_2(s16 *, f32, void *, s32, s32);
    extern s32 _chanim_entrypoint_0;
    _anseq_entrypoint_2(arg0, arg1, &_chanim_entrypoint_0, arg2, arg3);
}

void chanim_entrypoint_4(s16 *arg0, f32 arg1, volatile s32 arg2, s32 arg3, s32 arg4) {
    void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
    extern s32 _chanim_entrypoint_1;
    _anseq_entrypoint_3(arg0, arg1, &_chanim_entrypoint_1, arg2, arg3, arg4);
}

void chanim_entrypoint_5(s16 *arg0, f32 arg1, volatile s32 arg2, s32 arg3, s32 arg4) {
    void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
    extern s32 _chanim_entrypoint_2;
    _anseq_entrypoint_3(arg0, arg1, &_chanim_entrypoint_2, arg2, arg3, arg4);
}

/* extern */

void chanim_entrypoint_6(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _anseq_entrypoint_5(s32);
    s16 *data;

    data = func_80100094(arg0, 0);
    if (*data != 0) {
        _anseq_entrypoint_5(*data);
    }
    *data = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anim/chanim_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anim/chanim_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anim/chanim_entrypoint_9.s")
