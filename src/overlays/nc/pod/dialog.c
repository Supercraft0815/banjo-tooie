#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800000_ncpoddialog.s")

/* extern */

void func_8080008C_ncpoddialog(u8 *arg0) {
    f32 func_800F1DCC(f32, f32, u8 *);
    f32 func_800F1DF4(s32, s32, u8 *);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800F1DCC(func_800F1DF4(arg0 + 0x28, arg0 + 0x34, arg0), (*(f32 *)((s8 *)(arg0) + (0x44))), arg0);
    var_f2 = temp_f0;
    if ((temp_f0 < -90.0f) || (temp_f0 > 90.0f)) {
        var_f2 = -temp_f0;
    }
    if (var_f2 > 0.0f) {
        (*(s8 *)((s8 *)(arg0) + (0x214))) = 1;
        return;
    }
    (*(s8 *)((s8 *)(arg0) + (0x214))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800128_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800338_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800584_ncpoddialog.s")

s32 func_80800698_ncpoddialog(void *arg0) {
    switch (*(s8 *)((s8 *)arg0 + 0x211)) {
    case 2:
    case 4:
    case 5:
    case 6:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
}

s32 func_808006D4_ncpoddialog(void *arg0) {
    switch (*(s8 *)((s8 *)arg0 + 0x211)) {
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    case 9:
        return 1;
    default:
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800710_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800A98_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800B28_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80800D10_ncpoddialog.s")

/* extern */

s32 func_80801058_ncpoddialog(void *arg0, s32 arg1) {
    s32 func_80800338_ncpoddialog(void *, s32, s32);

    if ((*(u8 *)((s8 *)arg0 + 0x212)) != 0) {
        (*(u8 *)((s8 *)arg0 + 0x212)) = 0;
        return func_80800338_ncpoddialog(arg0, arg1, 2);
    }
    return 3;
}

/* extern */

void ncpoddialog_entrypoint_0(s16 arg0) {
    s32 func_8001B798(s16);
    func_8001B798(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_2.s")

/* extern */

void func_808012A0_ncpoddialog(s32 arg0, s32 arg1, s32 arg2) {
    s32 _plcamera_entrypoint_14(s32, s32, s32);
    s32 func_800F5EF8(s32);
    s32 func_800F690C();
    s32 func_800F693C(s32);
    s32 func_8010FFB0(s32, s32, s32);
    if ((func_800F690C() != 0) || (func_800F693C(arg0) != 0)) {
        _plcamera_entrypoint_14(arg0, arg1, arg2);
        return;
    }
    func_8010FFB0(func_800F5EF8(arg0), arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801310_ncpoddialog.s")

/* extern */

void ncpoddialog_entrypoint_3(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808013C0_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801504_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808015CC_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808017F4_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_8080189C_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801A30_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801AC0_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801B98_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801DB8_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801E78_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801F88_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80802048_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_8080230C_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808023B4_ncpoddialog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_4.s")

/* extern */

void ncpoddialog_entrypoint_5(u8 *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EEDE8(u8 *, u8 *, f32);
    typedef struct { u8 pad[0x28]; f32 position[1][3]; } Pod;
    f32 *sp1C[1];
    sp1C[0] = ((Pod *)arg0)->position[arg1];
    if (func_800EEDE8((u8 *)sp1C[0], (u8 *)arg2, 10.0f) == 0) {
        func_800EE7F8(sp1C[0], arg2);
        arg0[0x216] = 1;
    }
}

/* extern */

void ncpoddialog_entrypoint_6(s32 arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    typedef struct { u8 pad[0x40]; f32 position[1][3]; } Pod;
    func_800EE7F8(((Pod *)arg0)->position[arg1], arg2);
}

void ncpoddialog_entrypoint_7(void *arg0, s32 arg1) {
    if (arg1 >= 0) {
        (*(s8 *)((s8 *)(arg0) + (0x215))) = 1;
        if (arg1 == 0) {
            (*(s8 *)((s8 *)(arg0) + (0x214))) = 0;
            return;
        }
        (*(s8 *)((s8 *)(arg0) + (0x214))) = 1;
        return;
    }
    (*(s8 *)((s8 *)(arg0) + (0x215))) = 0;
}

s32 ncpoddialog_entrypoint_8(void *arg0, s32 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x218))) = arg1;
    return 5;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_9.s")

/* extern */

void ncpoddialog_entrypoint_10(s32 arg0) {
    s32 ncpoddialog_entrypoint_11(s32, u32, s32, s32);
    ncpoddialog_entrypoint_11(arg0 & 0xFFFF, (u32) (arg0 & 0xFFFF0000) >> 0x10, 1, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/ncpoddialog_entrypoint_11.s")
