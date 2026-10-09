#include "common.h"

u32 gspropctrl_entrypoint_0(u8 *arg0) {
    return arg0[10];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propctrl/gspropctrl_entrypoint_1.s")

u32 gspropctrl_entrypoint_2(void *arg0) {
    return (u32) ((*(s32 *)((s8 *)(arg0) + (4))) << 0x19) >> 0x1A;
}

s32 gspropctrl_entrypoint_3(s32 *arg0) {
    return arg0[3];
}

u32 gspropctrl_entrypoint_4(u16 *arg0) {
    return arg0[4];
}

void gspropctrl_entrypoint_5(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propctrl/gspropctrl_entrypoint_6.s")

s32 gspropctrl_entrypoint_7(s32 arg0) {
    extern s16 D_80800140_gspropctrl[];
    return ((s16 *)&D_80800140_gspropctrl)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propctrl/gspropctrl_entrypoint_8.s")

void gspropctrl_entrypoint_9(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
}

void gspropctrl_entrypoint_10(void *arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (0))) = (s16) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(s16 *)((s8 *)(arg1) + (2))) = (s16) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(s16 *)((s8 *)(arg1) + (4))) = (s16) (*(s16 *)((s8 *)(arg0) + (4)));
}

void gspropctrl_entrypoint_11(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(s16 *)((s8 *)(arg0) + (0)));
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) (*(s16 *)((s8 *)(arg0) + (2)));
    (*(f32 *)((s8 *)(arg1) + (8))) = (f32) (*(s16 *)((s8 *)(arg0) + (4)));
}

u32 gspropctrl_entrypoint_12(void *arg0) {
    return (u32) (*(u32 *)((s8 *)(arg0) + (0xC))) >> 0x17;
}

s32 gspropctrl_entrypoint_13(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0xC))) & 0x7FFFFF;
}
