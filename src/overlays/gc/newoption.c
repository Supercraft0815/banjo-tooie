#include "gc/newoption.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80800000_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80800038_gcnewoption.s")

s32 func_80800070_gcnewoption(void *arg0, s32 arg1) {
    return (*(s16 *)((s8 *)(arg0) + (8))) + arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_1.s")

int gcnewoption_entrypoint_2(void)
{
	return 0x260;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_7.s")

void gcnewoption_entrypoint_8(s16 *arg0, s32 arg1) {
    arg0[1] = arg1;
}

void gcnewoption_entrypoint_9(s16 *arg0, s32 arg1) {
    arg0[2] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_10.s")

void gcnewoption_entrypoint_11(s16 *arg0) {
    *arg0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80800D28_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_8080103C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808010E0_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801114_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801190_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_13.s")

void gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    (*(s16 *)((s8 *)(arg0) + (0x26))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg2;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg3;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg4;
    (*(f32 *)((s8 *)(arg0) + (0x30))) = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808012C8_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_20.s")

void gcnewoption_entrypoint_21(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = 0;
}

void gcnewoption_entrypoint_22(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = 1;
}

void gcnewoption_entrypoint_23(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_26.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_27.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_29.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_30.s")

void gcnewoption_entrypoint_31(s32 arg0, s32 arg1, s16 arg2) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0x1DC))) = arg2;
}

/* extern */

void gcnewoption_entrypoint_32(void *arg0, s16 arg1) {
    s32 _gczoombox_entrypoint_37(s32, s16);
    (*(s16 *)((s8 *)(arg0) + (0x236))) = arg1;
    _gczoombox_entrypoint_37((*(s32 *)((s8 *)(arg0) + (0x20))), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_33.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808019D0_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801B5C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801E68_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808020C4_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808022E0_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_8080241C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802534_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802674_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808027DC_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802998_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802A9C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_35.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_36.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802B24_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_37.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_39.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_41.s")

void gcnewoption_entrypoint_42(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_43.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_44.s")

s32 gcnewoption_entrypoint_45(s16 *arg0) {
    return arg0[3];
}

void gcnewoption_entrypoint_46(s8 *arg0, s32 arg1) {
    arg0[592] = arg1;
}

s32 gcnewoption_entrypoint_47(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x24))) == 3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_49.s")
