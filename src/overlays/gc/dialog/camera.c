#include "common.h"

void func_80800000_gcdialogcamera(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_v0;
    s32 var_v1;

    var_v0 = arg0;
    if (arg0 < 0x32) {
        var_v1 = 0;
    } else {
        var_v0 = arg0 - 0x32;
        if (arg0 >= 0x64) {
            var_v0 = arg0 - 0x64;
            var_v1 = 1;
        } else {
            var_v1 = 0x32;
        }
    }
    *arg2 = var_v1;
    *arg1 = var_v0;
}

s32 func_8080003C_gcdialogcamera(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

/* extern */

s32 gcdialogcamera_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _ncpoddialog_entrypoint_11(s32, s32, s32);
    return 1 - _ncpoddialog_entrypoint_11(arg0, arg1, 0);
}

/* extern */

s32 gcdialogcamera_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_3(u32);
    s32 _ncpoddialog_entrypoint_11(s32, s32, s32);
    s32 sp1C;
    s32 sp18;

    func_80800000_gcdialogcamera(arg1, &sp1C, &sp18);
    if (arg0 == 0x58) {
        if (_ncpoddialog_entrypoint_11(sp1C, sp18, 0) != 0) {
            _capod_entrypoint_3(0);
            return 4;
        }
        return 3;
    }
    return 0;
}

/* extern */

void gcdialogcamera_entrypoint_2(void *arg0) {
    s32 _capod_entrypoint_0(s32, s32, s32);
    s32 _capod_entrypoint_4();
    s32 _capod_entrypoint_7(s32, s32);
    s32 temp_v0;

    temp_v0 = _capod_entrypoint_4();
    if ((temp_v0 != -1) && (temp_v0 != 1)) {
        if (temp_v0 == 6) {
            _capod_entrypoint_7(0, 0x64);
            return;
        }
        _capod_entrypoint_0(0x57, 0x10000, (*(s32 *)((s8 *)(arg0) + (0x168))));
    }
}

void func_8080015C_gcdialogcamera(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void _capod_entrypoint_9(u32, f32 *);
    Actor *actor;
    f32 size;
    f32 sp18[4];

    actor = func_80106790(arg0);
    size = (u32)*(u16 *)&actor->pad68 * actor->scale;
    sp18[0] = size;
    sp18[1] = size;
    sp18[2] = size;
    sp18[3] = size * 0.5f;
    _capod_entrypoint_9(0, sp18);
}

/* extern */

void gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1) {
    void _capod_entrypoint_9(u32, f32 *);
    f32 sp18[4];

    sp18[0] = arg0[0] * arg1;
    sp18[1] = arg0[1] * arg1;
    sp18[2] = arg0[2] * arg1;
    sp18[3] = arg0[3] * arg1;
    _capod_entrypoint_9(0, sp18);
}

/* extern */

void gcdialogcamera_entrypoint_4(s32 arg0) {
    s32 _capod_entrypoint_10(s32, s32);
    _capod_entrypoint_10(0, arg0);
}

/* extern */

void gcdialogcamera_entrypoint_5(s32 arg0) {
    s32 _capod_entrypoint_11(s32, s32);
    _capod_entrypoint_11(0, arg0);
}

/* extern */

void func_8080026C_gcdialogcamera(s32 arg0) {
    s32 func_8010114C(s32, s32, s32);
    void func_8080015C_gcdialogcamera(Unk80132ED0 *);
    if (func_8010114C(arg0, 0x52, 0) <= 0) {
        func_8080015C_gcdialogcamera(arg0);
    }
}

/* extern */

void func_808002A4_gcdialogcamera(Unk80132ED0 *arg0) {
    s32 _capod_entrypoint_10(s32, s32);
    s32 _capod_entrypoint_11(s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_80106790(arg0);
    sp1C = temp_v0;
    _capod_entrypoint_10(0, temp_v0 + 4);
    _capod_entrypoint_11(0, sp1C + 0x44);
}

void gcdialogcamera_entrypoint_6(s32 arg0)
{
    func_808002A4_gcdialogcamera(arg0);
    func_8080026C_gcdialogcamera(arg0);
}
/* extern */

void func_8080030C_gcdialogcamera(void) {
    s32 _capod_entrypoint_10(s32, s32);
    s32 _capod_entrypoint_11(s32, s32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32[3]);
    s32 func_800F5DC8(u32, s32 *);
    f32 sp2C[5];
    s32 sp20;
    u32 sp1C;
    u32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    func_800F5A00((s32) temp_v0, sp2C + 2);
    func_800F5DC8(sp1C, &sp20);
    _capod_entrypoint_10(1, (s32) (sp2C + 2));
    _capod_entrypoint_11(1, (s32) &sp20);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/camera/gcdialogcamera_entrypoint_7.s")

/* extern */

void func_808005C0_gcdialogcamera(void) {
    void _capod_entrypoint_9(u32, f32*);
    u32 func_800F54E4(void);
    s32 gcdialogcamera_entrypoint_7(u32, f32 *);
    f32 sp20[4];

    gcdialogcamera_entrypoint_7(func_800F54E4(), sp20);
    _capod_entrypoint_9(1U, sp20);
}

void gcdialogcamera_entrypoint_8()
{
    func_8080030C_gcdialogcamera();
    func_808005C0_gcdialogcamera();
}

/* extern */

s32 func_80800620_gcdialogcamera(s32 arg0) {
    s32 _capod_entrypoint_2(s32, s32, s32);
    s32 _capod_entrypoint_8(s32);
    if (_capod_entrypoint_2(0, 6, arg0) != 0) {
        _capod_entrypoint_8(1);
        return 1;
    }
    return 0;
}

/* extern */

void gcdialogcamera_entrypoint_9(s32 arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_5(s32);
    s32 _capod_entrypoint_7(s32, s32);
    gcdialogcamera_entrypoint_6(arg0);
    gcdialogcamera_entrypoint_8();
    if (arg1 == 7) {
        _capod_entrypoint_5(0x200);
    }
    _capod_entrypoint_7(arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/camera/gcdialogcamera_entrypoint_10.s")
