#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_0.s")

s32 func_80800048_susplinet(s16 *arg0, s32 arg1) {
    s8 *base = (s8 *)arg0;
    s16 *ptr;
    base += arg0[0x19];
    ptr = (s16 *)base;
    return ptr[arg1] & 4;
}

s32 func_80800068_susplinet(s16 *arg0, s32 arg1) {
    s8 *base = (s8 *)arg0;
    s16 *ptr;
    base += arg0[0x19];
    ptr = (s16 *)base;
    return ptr[arg1] & 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_1.s")

int func_808000FC_susplinet(u8 *array, s32 index) {
    return ((array + 0x50)[index / 8] & (1 << (index & 7))) ? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_2.s")

s16 susplinet_entrypoint_3(s8 *arg0) {
    s32 base = (s32)arg0;
    base += *(s16 *)(arg0 + 0x30);
    return ((s16 *)base)[*(s16 *)(arg0 + 0x4E) - 1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_4.s")

s32 susplinet_entrypoint_5(void *arg0, f32 arg1) {
    if (((*(f32 *)((s8 *)(arg0) + (0x48))) <= arg1) && (arg1 < (*(f32 *)((s8 *)(arg0) + (0x44))))) {
        return 1;
    }
    return 0;
}

u32 susplinet_entrypoint_6(u8 *arg0) {
    return arg0[83];
}

void susplinet_entrypoint_7(f32 arg0[][3], s32 arg1, f32 *arg2) {
    s32 func_800EE7F8();
    func_800EE7F8(arg2, arg0[arg1]);
}

f32 susplinet_entrypoint_8(f32 *arg0, s32 arg1) {
    return (arg0 + arg1)[9];
}

f32 susplinet_entrypoint_9(f32 *arg0) {
    return arg0[17];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_10.s")

void susplinet_entrypoint_11(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 72) = arg1;
}

u8 *susplinet_entrypoint_12(u8 *arg0) {
    arg0 += *(s16 *)(arg0 + 0x30);
    return arg0;
}

u8 *susplinet_entrypoint_13(u8 *arg0) {
    arg0 += *(s16 *)(arg0 + 0x34);
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_14.s")

s32 susplinet_entrypoint_15(s32 arg0, s32 arg1) {
    s16 *ptr = (s16 *)((s8 *)arg0 + (arg1 * 2) + 0x3E);
    return arg0 + *ptr;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_80800384_susplinet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_80800620_susplinet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_808007D0_susplinet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_80800D3C_susplinet.s")

void susplinet_entrypoint_17(u8 *spline) {
    s32 func_80800D3C_susplinet(u8 *, s32);
    spline[0x58] = 1;
    func_80800D3C_susplinet(spline, *(s32 *)(spline + 0x44));
    spline[0x58] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/func_8080111C_susplinet.s")

s32 func_808011B8_susplinet(s32 arg0, s32 arg1) {
    return (arg0 * 0xC) + (arg1 * 4) + 6;
}

s32 susplinet_entrypoint_18(s32 arg0, s32 arg1, s32 arg2) {
    register s32 result;
    result = arg0;
    result *= func_808011B8_susplinet(arg1, arg2);
    return result + 0x5C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/splinet/susplinet_entrypoint_19.s")
