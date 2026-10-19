#include "common.h"

/* extern */

void func_80800000_ncpoddialog(u8 *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    f32 *temp_v0;

    func_800EE7F8(arg2, ((f32 (*)[3])(arg0 + 0x28))[arg1]);
    temp_v0 = ((f32 (*)[4])arg0)[arg1];
    arg2[1] += temp_v0[3];
    arg2[1] += 0.5f * (temp_v0[0] - temp_v0[3]);
}

/* extern */

void func_8080008C_ncpoddialog(u8 *arg0) {
    f32 func_800F1DCC(f32, f32, u8 *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800F1DCC(func_800F1DF4((f32 *)(arg0 + 0x28), (f32 *)(arg0 + 0x34)), (*(f32 *)((s8 *)(arg0) + (0x44))), arg0);
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

/* extern */

void func_80800A98_ncpoddialog(f32 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF8BC(f32 *, f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EF9A8(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp24[3];

    func_800EFA4C(sp24, arg2, arg3, arg4);
    func_800EF9A8(sp24, sp24, arg1[2]);
    func_800EF8BC(sp24, sp24, arg1[0]);
    func_800EF934(sp24, sp24, arg1[1]);
    func_800EF04C(arg0, sp24);
}

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

void *ncpoddialog_entrypoint_0(s16 arg0) {
    void *func_8001B798(s16);
    return func_8001B798(arg0);
}

/* extern */

s32 ncpoddialog_entrypoint_1(s16 arg0, s32 arg1) {
    s32 func_808015CC_ncpoddialog(void *, s32);
    void *sp1C;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v1;
    u8 temp_v0_4;
    void *temp_v0_3;

    temp_v0_3 = ncpoddialog_entrypoint_0(arg0);
    sp1C = temp_v0_3;
    temp_v0_2 = func_80801058_ncpoddialog(temp_v0_3, arg1);
    var_v1 = temp_v0_2;
    if (temp_v0_2 == 4) {
        return temp_v0_2;
    }
    temp_v0_4 = (*(u8 *)((s8 *)(sp1C) + (0x210)));
    if ((temp_v0_4 != 1) && (temp_v0_4 == 2)) {
        temp_v0 = func_808015CC_ncpoddialog(sp1C, arg1);
        var_v1 = temp_v0;
        if (temp_v0 == 4) {
            return temp_v0;
        }
    }
    return var_v1;
}

s16 ncpoddialog_entrypoint_2(void) {
    s16 func_8001B668(s32, s32);
    void func_800EFD24(f32 *);
    s16 handle;
    s8 *data;
    s32 i;
    s32 j;
    f32 *scalar;

    handle = func_8001B668(0, 0x21C);
    data = ncpoddialog_entrypoint_0(handle);
    data[0x210] = 1;
    for (i = 0; i < 10; i++) {
        func_800EFD24((f32 *)(data + 0x58 + i * 12));
        func_800EFD24((f32 *)(data + 0xD0 + i * 12));
        func_800EFD24((f32 *)(data + 0x188 + i * 12));
    }
    *(f32 *)(data + 0x20C) = 0.0f;
    func_800EFD24((f32 *)(data + 0x148));
    *(f32 *)(data + 0x154) = 0.0f;
    data[0x211] = -1;
    data[0x212] = 0;
    data[0x213] = 0;
    data[0x214] = 0;
    data[0x215] = 0;
    data[0x217] = 0;
    func_800EFD24((f32 *)(data + 0x170));
    func_800EFD24((f32 *)(data + 0x17C));
    func_800EFD24((f32 *)(data + 0x200));
    for (j = 0; j < 2; j++) {
        func_800EFD24((f32 *)(data + 0x28 + j * 12));
        func_800EFD24((f32 *)(data + 0x40 + j * 12));
        scalar = (f32 *)(data + 0x20 + j * 4);
        *(f32 *)(data + j * 16 + 4) = 0.0f;
        *(f32 *)(data + j * 16 + 8) = 0.0f;
        *(f32 *)(data + j * 16 + 12) = 0.0f;
        *(f32 *)(data + j * 16) = 0.0f;
        *scalar = 0.0f;
    }
    return handle;
}

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

s32 func_808013C0_ncpoddialog(u8 *arg0) {
    s32 func_800BF340(f32 *, f32 *, f32 *, s32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    s32 var_s1;

    var_s1 = 1;
    if (func_808006D4_ncpoddialog(arg0) != 0) {
        func_80800000_ncpoddialog(arg0, 0, sp40);
        func_800EE7F8(sp34, (f32 *)(arg0 + 0xC4));
        if (func_800BF340(sp34, sp40, sp4C, 0x860020, 30.0f) != 0) {
            var_s1 = 0;
        } else if (func_800BF340(sp40, sp34, sp4C, 0x860020, 30.0f) != 0) {
            var_s1 = 0;
        }
    }
    if (func_80800698_ncpoddialog(arg0) != 0) {
        func_80800000_ncpoddialog(arg0, 1, sp40);
        func_800EE7F8(sp34, (f32 *)(arg0 + 0xC4));
        if (func_800BF340(sp34, sp40, sp4C, 0x860020, 30.0f) != 0) {
            var_s1 = 0;
        } else if (func_800BF340(sp40, sp34, sp4C, 0x860020, 30.0f) != 0) {
            var_s1 = 0;
        }
    }
    return var_s1;
}

/* extern */

s32 func_80801504_ncpoddialog(u8 *arg0) {
    s32 func_800BF340(f32 *, f32 *, f32 *, s32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp6C[3];
    f32 sp60[3];
    s32 var_s0;
    f32 *var_s1;
    f32 *var_s2;
    f32 *var_s3;
    f32 *var_s4;
    s32 var_s7;

    var_s7 = 1;
    var_s3 = sp60;
    var_s4 = sp6C;
    for (var_s0 = 0, var_s1 = (f32 *)(arg0 + 0x64), var_s2 = (f32 *)(arg0 + 0x58); var_s0 != 0x6C;) {
        func_800EE7F8(var_s3, var_s1);
        if (func_800BF340(var_s2, var_s3, var_s4, 0x860020, 30.0f) != 0) {
            var_s7 = 0;
        }
        var_s0 += 0xC;
        var_s1 += 3;
        var_s2 += 3;
    }
    return var_s7;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808015CC_ncpoddialog.s")

void func_808017F4_ncpoddialog(u8 *arg0, s16 *arg1) {
    f32 func_800136E4(f32);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80110024(s16 *);
    s32 sp34;

    sp34 = _ncpod_entrypoint_4(func_80110024(arg1));
    func_808023B4_ncpoddialog(arg0, arg1);
    func_808012A0_ncpoddialog(sp34, (s32)(arg0 + 0x58), (s32)(arg0 + 0xD0));
    *(f32 *)(arg0 + 0xD0) = func_800136E4(*(f32 *)(arg0 + 0xD0));
    *(f32 *)(arg0 + 0xD4) = func_800136E4(*(f32 *)(arg0 + 0xD4));
    *(f32 *)(arg0 + 0x140) = func_800136E4(func_800F1DF4((f32 *)(arg0 + 0x148), (f32 *)(arg0 + 0xC4)));
    *(f32 *)(arg0 + 0x13C) = func_800136E4(-func_800F1828((f32 *)(arg0 + 0x148), (f32 *)(arg0 + 0xC4)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_8080189C_ncpoddialog.s")

void func_80801A30_ncpoddialog(f32 *arg0) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp_f0;
    s32 var_s0;
    f32 *var_s1;

    var_s0 = 1;
    var_s1 = arg0 + 1;
    do {
        temp_f0 = func_800F10B4((f32)var_s0, 0.0f, 9.0f, arg0[0], arg0[9]);
        var_s0 += 1;
        var_s1 += 1;
        var_s1[-1] = temp_f0;
    } while (var_s0 != 9);
}

/* extern */

void func_80801AC0_ncpoddialog(u8 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp_f0;
    f32 *var_s2;
    f32 *var_s3;
    s32 var_s1;
    f32 *var_s0;

    var_s0 = (f32 *)(arg0 + 0xC);
    var_s1 = 1;
    var_s2 = arg1 + 1;
    var_s3 = arg2 + 1;
    do {
        func_800EEB9C(var_s0, *var_s2, *var_s3);
        func_800EF04C(var_s0, arg3);
        temp_f0 = func_800F10B4((f32) var_s1, 0.0f, 9.0f, *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 0x70));
        var_s1 += 1;
        var_s0 += 3;
        var_s2 += 1;
        var_s3 += 1;
        var_s0[-2] = temp_f0;
    } while (var_s1 != 9);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80801B98_ncpoddialog.s")

/* extern */

void func_80801DB8_ncpoddialog(u8 *arg0, s32 arg1, f32 arg2) {
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 distance;

    func_80800000_ncpoddialog(arg0, arg1, (f32 *)(arg0 + 0x148));
    arg2 += ((f32 (*)[3])(arg0 + 0x44))[arg1][0];
    distance = ((f32 (*)[4])arg0)[arg1][0] - ((f32 (*)[4])arg0)[arg1][3];
    if (distance < ((f32 (*)[4])arg0)[arg1][1]) {
        distance = ((f32 (*)[4])arg0)[arg1][1];
    }
    if (distance < ((f32 (*)[4])arg0)[arg1][2]) {
        distance = ((f32 (*)[4])arg0)[arg1][2];
    }
    func_800EEB9C((f32 *)(arg0 + 0xC4), arg2, distance);
    func_800EF04C((f32 *)(arg0 + 0xC4), (f32 *)(arg0 + 0x148));
    *(f32 *)(arg0 + 0xC8) = *(f32 *)(arg0 + 0x14C);
}

void func_80801E78_ncpoddialog(u8 *arg0, s32 arg1, s32 arg2) {
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 sp34[3];
    f32 var_f2;
    f32 *sp24;

    func_80800000_ncpoddialog(arg0, 1 - arg1, (f32 *)(arg0 + 0xC4));
    sp24 = (f32 *)(arg0 + 0x148);
    func_80800000_ncpoddialog(arg0, arg1, sp24);
    *(f32 *)(arg0 + 0xC8) += *(f32 *)(arg0 + 0x14C);
    *(f32 *)(arg0 + 0xC8) *= 0.5f;
    *(f32 *)(arg0 + 0x14C) = *(f32 *)(arg0 + 0xC8);
    var_f2 = func_800F1DF4(sp24, (f32 *)(arg0 + 0xC4));
    if (arg2 != 0) {
        var_f2 += 90.0f;
    } else {
        var_f2 -= 90.0f;
    }
    func_800EEB9C(sp34, var_f2, ((f32 *)arg0)[9 - (u32)arg1]);
    func_800EF04C((f32 *)(arg0 + 0xC4), sp34);
    func_800EFB24(sp34, (f32 *)(arg0 + 0xC4), sp24);
    func_800EF334(sp34, 0.5f);
    func_800EF04C((f32 *)(arg0 + 0xC4), sp34);
}

void func_80801F88_ncpoddialog(u8 *arg0, f32 arg1) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7B4(f32 *, f32 *, f32 *, f32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 distance;
    f32 unused;
    f32 position[3];
    f32 midpoint[3];
    f32 *volatile vector;

    func_80800000_ncpoddialog(arg0, 1, position);
    vector = (f32 *)(arg0 + 0x28);
    func_800EE780(midpoint, (f32 *)(arg0 + 0x28), position);
    func_800EF334(midpoint, 0.5f);
    distance = func_800F1DF4(vector, position);
    func_800F1828(vector, position);
    vector = (f32 *)(arg0 + 0xC4);
    distance += arg1;
    func_800EEC30((f32 *)(arg0 + 0xC4), 0.0f, distance, 500.0f);
    func_800EE7B4((f32 *)(arg0 + 0x148), midpoint, vector, -0.1f);
    func_800EF04C(vector, midpoint);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_80802048_ncpoddialog.s")

void func_8080230C_ncpoddialog(u8 *arg0, void *arg1, void *arg2) {
    void func_80802048_ncpoddialog(u8 *, void *, void *, f32 *, f32);
    s8 state;

    state = *(s8 *)(arg0 + 0x211);
    if (state == 4 || state == 5 || state == 6 || state == 8) {
        func_80802048_ncpoddialog(arg0, arg1, arg2, (f32 *)(arg0 + 0x28), *(f32 *)(arg0 + 0x20));
        state = *(s8 *)(arg0 + 0x211);
    }
    if (state == 2 || state == 3 || state == 4 || state == 8) {
        func_80802048_ncpoddialog(arg0, arg1, arg2, (f32 *)(arg0 + 0x34), *(f32 *)(arg0 + 0x24));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/dialog/func_808023B4_ncpoddialog.s")

void ncpoddialog_entrypoint_4(u8 *arg0, s32 arg1, f32 *arg2) {
    f32 first;
    f32 second;
    f32 *values;
    s32 i;
    s32 changed = 0;
    for (i = 0; i < 4; i++) {
        if (arg2[i] + 10.0f < ((f32 (*)[4])arg0)[arg1][i] ||
            ((f32 (*)[4])arg0)[arg1][i] < arg2[i] - 10.0f) {
            ((f32 (*)[4])arg0)[arg1][i] = arg2[i];
            changed = 1;
        }
    }
    if (changed) { values = ((f32 (*)[4])arg0)[arg1]; first = values[2]; second = values[1]; if (first < second) { *(f32 *)(arg0 + arg1 * 4 + 0x20) = second; } else { *(f32 *)(arg0 + arg1 * 4 + 0x20) = first; } arg0[0x216] = 1; }
}

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

/* extern */

void ncpoddialog_entrypoint_9(void *arg0, s16 *arg1, int arg2, s32 arg3) {
    s32 _ncpod_entrypoint_5(s16 *, void *, s32, s8, s32);
    void func_8009055C(s32, s32);
    void *func_80110024(s16 *);
    s32 func_80800338_ncpoddialog(void *, s32, s32);
    s32 func_80801310_ncpoddialog();
    s32 var_v1;

    var_v1 = (*(s8 *)((s8 *)(arg0) + (0x211)));
    if (var_v1 == -1) {
        func_80801310_ncpoddialog();
        var_v1 = (*(s8 *)((s8 *)(arg0) + (0x211)));
    }
    if ((var_v1 != arg2) || ((*(u8 *)((s8 *)(arg0) + (0x216))) != 0)) {
        (*(u8 *)((s8 *)(arg0) + (0x216))) = 0U;
        (*(s8 *)((s8 *)(arg0) + (0x211))) = (s8) arg2;
        (*(u8 *)((s8 *)(arg0) + (0x213))) = (u8) arg3;
        func_8009055C(0x64, (arg3 << 0x10) | arg2);
        var_v1 = (*(s8 *)((s8 *)(arg0) + (0x211)));
        if (((var_v1 == 0) && ((*(u8 *)((s8 *)(arg0) + (0x213))) == 1)) || (var_v1 == 7)) {
            if (_ncpod_entrypoint_5(arg1, func_80110024(arg1), 0x58, (*(s8 *)((s8 *)(arg0) + (0x211))), 0) != 4) {
                func_80800338_ncpoddialog(arg0, arg1, 1);
            }
        } else {
            (*(s8 *)((s8 *)(arg0) + (0x212))) = 1;
        }
    }
}

/* extern */

void ncpoddialog_entrypoint_10(s32 arg0) {
    s32 ncpoddialog_entrypoint_11();
    ncpoddialog_entrypoint_11(arg0 & 0xFFFF, (u32) (arg0 & 0xFFFF0000) >> 0x10, 1, arg0);
}

s32 ncpoddialog_entrypoint_11(s32 arg0, s32 arg1, s32 arg2) {
    switch (arg2) {
        case 0:
            if ((arg0 == 0) || (arg0 == 7)) {
                return 1;
            }
            break;
        case 1:
            if ((arg1 == 1) && ((arg0 == 0) || (arg0 == 1))) {
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 0;
}
