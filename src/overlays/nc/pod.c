#include "common.h"

/* extern */

void func_80800000_ncpod(void *arg0) {
    s32 func_800F82D4(s32, s32);
    if ((*(u8 *)((s8 *)(arg0) + (0x42))) == 0) {
        (*(u8 *)((s8 *)(arg0) + (0x42))) = 1U;
        func_800F82D4((*(s32 *)((s8 *)(arg0) + (0x38))), 2);
    }
}

/* extern */

void func_80800038_ncpod(void *arg0) {
    s32 func_800F82D4(s32, s32);
    if ((*(u8 *)((s8 *)(arg0) + (0x42))) != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x42))) = 0U;
        func_800F82D4((*(s32 *)((s8 *)(arg0) + (0x38))), 0);
    }
}

/* extern */

void func_8080006C_ncpod(void *arg0) {
    s32 _glcutDll_entrypoint_6(s32, s32);
    s32 func_800EA05C();
    if (!((*(s32 *)((s8 *)(arg0) + (0x10))) & 0x800)) {
        (*(s8 *)((s8 *)(arg0) + (0x43))) = 1;
        _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
    }
}

/* extern */

void func_808000AC_ncpod(void *arg0) {
    s32 _glcutDll_entrypoint_17();
    if ((*(u8 *)((s8 *)(arg0) + (0x43))) != 0) {
        _glcutDll_entrypoint_17();
        (*(u8 *)((s8 *)(arg0) + (0x43))) = 0U;
    }
}

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

s32 func_808002E8_ncpod(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/func_80800314_ncpod.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_5.s")

/* extern */

s32 ncpod_entrypoint_6(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_80101074(s32);
    s32 func_8010114C(void *, s32, s32);
    s32 func_808002E8_ncpod(void *, s32);
    if ((func_808002E8_ncpod((*(void **)((s8 *)(arg1) + (8))), (*(s32 *)((s8 *)(arg1) + (0xC)))) != 0) && ((*(u16 *)((s8 *)((*(void **)((s8 *)(arg1) + (8)))) + (0x18))) & 1)) {
        func_80101074(arg4);
        return func_8010114C((*(void **)((s8 *)(arg1) + (8))), arg2, arg3);
    }
    return -1;
}

void ncpod_entrypoint_7(void *arg0, void *arg1) {
    (*(void **)((s8 *)(arg0) + (8))) = arg1;
    (*(u32 *)((s8 *)(arg0) + (0xC))) = (u32) (*(u16 *)((s8 *)(arg1) + (0x12))) >> 1;
}

void ncpod_entrypoint_8(u8 *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg0 + 0x18, arg1);
    func_800EE7F8(arg0 + 0x24, arg2);
    (*(s8 *)((s8 *)(arg0) + (0x40))) = 1;
}

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

/* extern */

void ncpod_entrypoint_15(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800A940C(s32);
    s32 func_800C52F4(s32, s32);
    s32 func_800C53EC(s32, s32);
    s32 index;

    if (arg1 == *(u8 *)((u8 *)arg0 + 0x3E)) {
        return;
    }
        if (arg1 != 0) {
            index = func_800A940C(*(s32 *)((u8 *)arg0 + 0x38));
            func_800C52F4(index, arg2 ? 2 : 0);
        } else {
            index = func_800A940C(*(s32 *)((u8 *)arg0 + 0x38));
            func_800C53EC(index, arg2 ? 2 : 0);
        }
        *(u8 *)((u8 *)arg0 + 0x3E) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ncpod_entrypoint_17.s")

/* extern */

s16 ncpod_entrypoint_18(void) {
    void *func_80110024();
    void *temp_v0;

    temp_v0 = func_80110024();
    if (temp_v0 == NULL) {
        return -1;
    }
    return (*(s16 *)((s8 *)(temp_v0) + (0x3C)));
}

/* extern */

void ncpod_entrypoint_19(void *arg0, s32 arg1) {
    s32 func_808007D8_ncpod();
    func_808007D8_ncpod();
    (*(s32 *)((s8 *)(arg0) + (0x10))) = arg1;
}

/* extern */

s32 ncpod_entrypoint_20(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_2(s32, s32, s32);
    s32 _ncpoducam_entrypoint_3(s32, s32);
    s32 _ncpoducam_entrypoint_4(s32, s32);
    void func_8010FD88(u8 *);
    void *func_80110024();
    s32 ncpod_entrypoint_12(void *, s32);
    void *sp1C;
    s32 sp18;
    s32 temp_v0_2;
    void *temp_v0;

    temp_v0 = func_80110024();
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 2);
    temp_v0_2 = _ncpoducam_entrypoint_1((*(s16 *)((s8 *)(sp1C) + (2))));
    sp18 = temp_v0_2;
    _ncpoducam_entrypoint_4(temp_v0_2, arg3);
    ncpod_entrypoint_19(sp1C, arg3);
    if (arg1 != 0) {
        _ncpoducam_entrypoint_3(sp18, arg1);
    }
    _ncpoducam_entrypoint_2(sp18, arg0, arg2);
    func_8010FD88(arg0);
    return 4;
}

void ncpod_entrypoint_21(s16 *arg0, s32 arg1, s32 arg2) {
    s32 _ncpoddialog_entrypoint_0(s16);
    void _ncpoddialog_entrypoint_9(s32, s16 *, s32, s32);
    void *func_80110024(s16 *);
    _ncpoddialog_entrypoint_9(_ncpoddialog_entrypoint_0(*(s16 *)func_80110024(arg0)), arg0, arg1, arg2);
}

/* extern */

void ncpod_entrypoint_22(s16 *arg0, s32 arg1, s32 arg2) {
    s32 _ncpoddialog_entrypoint_0(s16);
    s32 _ncpoddialog_entrypoint_4(s32, s32, s32);
    _ncpoddialog_entrypoint_4(_ncpoddialog_entrypoint_0(*arg0), arg1, arg2);
}

/* extern */

void ncpod_entrypoint_23(s16 *arg0, s32 arg1, s32 arg2) {
    s32 _ncpoddialog_entrypoint_0(s16);
    s32 _ncpoddialog_entrypoint_5(s32, s32, s32);
    _ncpoddialog_entrypoint_5(_ncpoddialog_entrypoint_0(*arg0), arg1, arg2);
}

/* extern */

void ncpod_entrypoint_24(s16 *arg0, s32 arg1, s32 arg2) {
    s32 _ncpoddialog_entrypoint_0(s16);
    s32 _ncpoddialog_entrypoint_6(s32, s32, s32);
    _ncpoddialog_entrypoint_6(_ncpoddialog_entrypoint_0(*arg0), arg1, arg2);
}

/* extern */

void ncpod_entrypoint_25(s16 *arg0, s32 arg1) {
    s32 _ncpoddialog_entrypoint_0(s16);
    s32 _ncpoddialog_entrypoint_7(s32, s32);
    _ncpoddialog_entrypoint_7(_ncpoddialog_entrypoint_0(*arg0), arg1);
}

/* extern */

s32 ncpod_entrypoint_26(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_2(s32, s32, s32);
    s32 _ncpoducam_entrypoint_3(s32, s32);
    s32 _ncpoducam_entrypoint_4(s32, s32);
    void func_8010FD88(u8 *);
    void *func_80110024(s16 *);
    s32 ncpod_entrypoint_12(void *, s32);
    s32 ncpod_entrypoint_16(void *, s32, s32, s32);
    void ncpod_entrypoint_7(void *, void *);
    void *sp1C;
    s32 sp18;
    s32 temp_v0_2;
    void *temp_v0;

    if (ncpod_entrypoint_16(arg0, 0, 1, arg4) == 0) {
        return 0;
    }
    temp_v0 = func_80110024(arg0);
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 2);
    if (arg2 != 0) {
        ncpod_entrypoint_7(sp1C, arg2);
    } else if (arg1 != 0) {
        ncpod_entrypoint_7(sp1C, arg1);
    }
    temp_v0_2 = _ncpoducam_entrypoint_1((*(s16 *)((s8 *)(sp1C) + (2))));
    sp18 = temp_v0_2;
    if (arg1 != 0) {
        _ncpoducam_entrypoint_3(sp18, arg1);
    }
    _ncpoducam_entrypoint_4(sp18, arg4);
    _ncpoducam_entrypoint_2(sp18, arg0, arg3);
    func_8010FD88(arg0);
    return 1;
}

/* extern */

s32 ncpod_entrypoint_27(s32 arg0, s32 arg1) {
    s32 func_8010F9C0(s32, s32);
    void *func_80110024();
    s32 ncpod_entrypoint_17(s32, s32);
    s32 sp18;
    s32 temp_v0;

    func_80110024();
    temp_v0 = ncpod_entrypoint_17(arg0, arg1);
    sp18 = temp_v0;
    func_8010F9C0(arg0, 2);
    return temp_v0;
}

/* extern */

void ncpod_entrypoint_28(s16 *arg0, s32 arg1) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_8(s32, s32);
    void *func_80110024(s16 *);
    _ncpoducam_entrypoint_8(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(arg0)) + (2)))), arg1);
}

/* extern */

void ncpod_entrypoint_29(s16 *arg0, s32 arg1) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_9(s32, s32);
    void *func_80110024(s16 *);
    _ncpoducam_entrypoint_9(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(arg0)) + (2)))), arg1);
}

/* extern */

void ncpod_entrypoint_30(void) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_10(s32);
    void *func_80110024();
    _ncpoducam_entrypoint_10(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024()) + (2)))));
}

/* extern */

void ncpod_entrypoint_31(s16 *arg0, s32 arg1) {
    s32 _ncpoducam_entrypoint_1(s16);
    s32 _ncpoducam_entrypoint_11(s32, s32);
    void *func_80110024(s16 *);
    _ncpoducam_entrypoint_11(_ncpoducam_entrypoint_1((*(s16 *)((s8 *)(func_80110024(arg0)) + (2)))), arg1);
}

/* extern */

s32 ncpod_entrypoint_32(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _ncpodfixpos_entrypoint_2(s16);
    s32 _ncpodfixpos_entrypoint_3(s32, s32, s32);
    s32 _ncpodfixpos_entrypoint_4(s32, s32);
    s32 _ncpodfixpos_entrypoint_5(s32, s32);
    void *func_80110024();
    s32 ncpod_entrypoint_12(void *, s32);
    void *sp1C;
    s32 sp18;
    s32 temp_v0_2;
    void *temp_v0;

    temp_v0 = func_80110024();
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 3);
    temp_v0_2 = _ncpodfixpos_entrypoint_2((*(s16 *)((s8 *)(sp1C) + (4))));
    sp18 = temp_v0_2;
    _ncpodfixpos_entrypoint_5(temp_v0_2, arg3);
    if (arg1 != 0) {
        _ncpodfixpos_entrypoint_4(sp18, arg1);
    }
    _ncpodfixpos_entrypoint_3(sp18, arg0, arg2);
    return 4;
}

/* extern */

s32 ncpod_entrypoint_33(void *arg0, void *arg1, void *arg2, s32 arg3, s32 arg4) {
    s32 _ncpodfixpos_entrypoint_2(s16);
    s32 _ncpodfixpos_entrypoint_3(s32, s32, s32);
    s32 _ncpodfixpos_entrypoint_4(s32, s32);
    s32 _ncpodfixpos_entrypoint_5(s32, s32);
    void func_8010FD88(u8 *);
    void *func_80110024(s16 *);
    s32 ncpod_entrypoint_12(void *, s32);
    s32 ncpod_entrypoint_16(void *, s32, s32, s32);
    void ncpod_entrypoint_7(void *, void *);
    void *sp1C;
    s32 sp18;
    s32 temp_v0_2;
    void *temp_v0;

    if (ncpod_entrypoint_16(arg0, 0, 0xB, arg4) == 0) {
        return 0;
    }
    temp_v0 = func_80110024(arg0);
    sp1C = temp_v0;
    ncpod_entrypoint_12(temp_v0, 3);
    if (arg2 != 0) {
        ncpod_entrypoint_7(sp1C, arg2);
    } else if (arg1 != 0) {
        ncpod_entrypoint_7(sp1C, arg1);
    }
    temp_v0_2 = _ncpodfixpos_entrypoint_2((*(s16 *)((s8 *)(sp1C) + (4))));
    sp18 = temp_v0_2;
    _ncpodfixpos_entrypoint_5(temp_v0_2, arg4);
    if (arg1 != 0) {
        _ncpodfixpos_entrypoint_4(sp18, arg1);
    }
    _ncpodfixpos_entrypoint_3(sp18, arg0, arg3);
    func_8010FD88(arg0);
    return 1;
}
