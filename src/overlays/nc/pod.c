#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_80800000_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_80800038_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_8080006C_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_808000AC_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_1.s")

/* extern */

void ncpod_entrypoint_2(s16 arg0) {
    s32 func_8001B798(s16);
    func_8001B798(arg0);
}

void ncpod_entrypoint_3(s16 *arg0, s32 arg1) {
    arg0[30] = arg1;
}

s32 ncpod_entrypoint_4(s32 *arg0) {
    return arg0[14];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_808002E8_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_80800314_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_8.s")

void ncpod_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 48) = arg1;
}

f32 ncpod_entrypoint_10(f32 *arg0) {
    return arg0[12];
}

void ncpod_entrypoint_11(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 52) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_12.s")

u32 ncpod_entrypoint_13(u8 *arg0) {
    return arg0[65];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_808007D8_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_18.s")

/* extern */

void ncpod_entrypoint_19(void *arg0, s32 arg1) {
    s32 func_808007D8_ncpod();
    func_808007D8_ncpod();
    (*(s32 *)((s8 *)(arg0) + (0x10))) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_23.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_24.s")

/* extern */

void ncpod_entrypoint_25(s16 *arg0, s32 arg1) {
    s32 _ncpoddialog_entrypoint_0(s16);
    s32 _ncpoddialog_entrypoint_7(s32, s32);
    _ncpoddialog_entrypoint_7(_ncpoddialog_entrypoint_0(*arg0), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_26.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_27.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_29.s")

/* extern */

void ncpod_entrypoint_30(void) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_10(s32);
    void *func_80110024();
    _ncpoducam_entrypoint_10(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024()) + (2)))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_31.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_32.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_33.s")
