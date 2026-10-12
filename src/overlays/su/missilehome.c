#include "common.h"

/* extern */

void sumissilehome_entrypoint_0(s32 arg0, u8 *arg1) {
    s32 _subaddielink_entrypoint_0(u8 *);
    (*(s8 *)((s8 *)(arg1) + (8))) = 0;
    (*(s8 *)((s8 *)(arg1) + (9))) = 0;
    (*(s8 *)((s8 *)(arg1) + (0))) = -1;
    (*(s8 *)((s8 *)(arg1) + (1))) = -1;
    (*(f32 *)((s8 *)(arg1) + (4))) = 6000.0f;
    (*(s8 *)((s8 *)(arg1) + (0xA))) = 2;
    _subaddielink_entrypoint_0(arg1 + 0xC);
}

void sumissilehome_entrypoint_1(s32 arg0, void *arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg1) + (8))) = 1;
    (*(s16 *)((s8 *)(arg1) + (2))) = arg2;
}

void sumissilehome_entrypoint_2(s32 arg0, void *arg1, f32 arg2) {
    (*(s8 *)((s8 *)(arg1) + (0xA))) = 1;
    (*(f32 *)((s8 *)(arg1) + (4))) = arg2;
}

void sumissilehome_entrypoint_3(s32 arg0, s8 *arg1, s32 arg2) {
    *arg1 = arg2;
}

void sumissilehome_entrypoint_4(s32 arg0, s32 *arg1, s32 arg2) {
    (*(s8 *)((s8 *)(arg1) + (9))) = (s8)arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/missilehome/sumissilehome_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/missilehome/func_80800178_sumissilehome.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/missilehome/func_808001C8_sumissilehome.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/missilehome/sumissilehome_entrypoint_6.s")
