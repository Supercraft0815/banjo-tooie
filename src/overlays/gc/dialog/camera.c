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
} typedef struct { u8 pad0[0x12]; u16 unk12; u8 pad14[0x153]; u8 unk167; union { s32 unk168; void * unk168_voidp; }; s32 unk16C; } Objcamera_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_8080003C_gcdialogcamera(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*&((Objcamera_arg0 *)arg0)->unk12 >> 1));
}

/* extern */

s32 gcdialogcamera_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _ncpoddialog_entrypoint_11(s32, s32, s32);
    return 1 - _ncpoddialog_entrypoint_11(arg0, arg1, 0);
}

/* extern */

s32 gcdialogcamera_entrypoint_1(s32 arg0, s32 arg1, BtIntPtr arg2) {
    s32 _capod_entrypoint_3(s32 arg0);
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
    void _capod_entrypoint_7(s32 arg0, s32 arg1);
    s32 temp_v0;

    temp_v0 = _capod_entrypoint_4();
    if ((temp_v0 != -1) && (temp_v0 != 1)) {
        if (temp_v0 == 6) {
            _capod_entrypoint_7(0, 0x64);
            return;
        }
        _capod_entrypoint_0(0x57, 0x10000, (((Objcamera_arg0 *)arg0)->unk168));
    }
}

void func_8080015C_gcdialogcamera(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    void _capod_entrypoint_9(s32 arg0, BtIntPtr arg1);
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
    void _capod_entrypoint_9(s32 arg0, BtIntPtr arg1);
    f32 sp18[4];

    sp18[0] = arg0[0] * arg1;
    sp18[1] = arg0[1] * arg1;
    sp18[2] = arg0[2] * arg1;
    sp18[3] = arg0[3] * arg1;
    _capod_entrypoint_9(0, sp18);
}

/* extern */

void gcdialogcamera_entrypoint_4(BtIntPtr arg0) {
    void _capod_entrypoint_10(s32 arg0, BtIntPtr arg1);
    _capod_entrypoint_10(0, arg0);
}

/* extern */

void gcdialogcamera_entrypoint_5(BtIntPtr arg0) {
    void _capod_entrypoint_11(s32 arg0, BtIntPtr arg1);
    _capod_entrypoint_11(0, arg0);
}

/* extern */

void func_8080026C_gcdialogcamera(BtIntPtr arg0) {
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_8080015C_gcdialogcamera(Unk80132ED0 *);
    if (func_8010114C(arg0, 0x52, 0) <= 0) {
        func_8080015C_gcdialogcamera(arg0);
    }
}

/* extern */

void func_808002A4_gcdialogcamera(Unk80132ED0 *arg0) {
    void _capod_entrypoint_10(s32 arg0, BtIntPtr arg1);
    void _capod_entrypoint_11(s32 arg0, BtIntPtr arg1);
    Actor *func_80106790(Unk80132ED0 *);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    temp_v0 = func_80106790(arg0);
    sp1C = temp_v0;
    _capod_entrypoint_10(0, temp_v0 + 4);
    _capod_entrypoint_11(0, sp1C + 0x44);
}

void gcdialogcamera_entrypoint_6(BtIntPtr arg0)
{
    func_808002A4_gcdialogcamera(arg0);
    func_8080026C_gcdialogcamera(arg0);
}
/* extern */

void func_8080030C_gcdialogcamera(void) {
    void _capod_entrypoint_10(s32 arg0, BtIntPtr arg1);
    void _capod_entrypoint_11(s32 arg0, BtIntPtr arg1);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32[3]);
    void func_800F5DC8(BtIntPtr player, f32 rotation[3]);
    f32 position[3];
    f32 rotation[3];
    BtUIntPtr sp1C;
    BtUIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    func_800F5A00((s32) temp_v0, position);
    func_800F5DC8(sp1C, rotation);
    _capod_entrypoint_10(1, (BtIntPtr)position);
    _capod_entrypoint_11(1, (BtIntPtr)rotation);
}

void gcdialogcamera_entrypoint_7(BtUIntPtr arg0, f32 *arg1) {
    s32 func_800F543C(BtIntPtr);
    f32 func_800F5C44(BtIntPtr);
    s32 func_800F5D18(BtIntPtr);
    int func_800F6720(BtIntPtr);
    s32 func_800F67EC(BtIntPtr);
    s32 func_800F7058(BtIntPtr);
    extern f32 D_808007C0_gcdialogcamera[][4];
    s32 index;
    f32 *entry;
    f32 scale;
    s32 i;
    s32 state;

    scale = 1.0f;
    state = func_800F543C(arg0);
    switch (state) {
        case 1:
            if (func_800F7058(arg0)) {
                index = 16;
            } else {
        case 0x200:
            state = func_800F5D18(arg0);
            switch (state) {
                case 0:
                                    if (func_800F6720(arg0)) index = 12;
                    else index = 1;
                    break;
                case 1: index = 7; break;
                case 2: index = 8; break;
            }
            }
            break;
        case 0x80: index = 2; break;
        case 0x8000: index = 3; break;
        case 0x4000: index = 4; break;
        case 0x400:
            if (func_800F67EC(arg0)) index = 17;
            else index = 5;
            break;
        case 0x1000: index = 6; break;
        case 0x40: index = 9; break;
        case 0x20: index = 10; break;
        case 0x100: index = 11; break;
        case 0x20000: index = 13; break;
        case 0x800: index = 14; break;
        case 0x10000: index = 15; break;
        case 2:
            index = 18;
            scale = func_800F5C44(arg0);
            break;
        case 0x2000: index = 19; break;
        case 0x40000: index = 20; break;
        default: index = 0; break;
    }
    entry = D_808007C0_gcdialogcamera[index];
    for (i = 0; i < 4; i++) {
        arg1[i] = entry[i] * scale;
    }
}

/* extern */

void func_808005C0_gcdialogcamera(void) {
    void _capod_entrypoint_9(s32 arg0, BtIntPtr arg1);
    BtUIntPtr func_800F54E4(void);
    void gcdialogcamera_entrypoint_7(BtUIntPtr, f32 *);
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
    s32 _capod_entrypoint_2(BtIntPtr, s32, s32);
    void _capod_entrypoint_8(s32 arg0);
    if (_capod_entrypoint_2(0, 6, arg0) != 0) {
        _capod_entrypoint_8(1);
        return 1;
    }
    return 0;
}

/* extern */

void gcdialogcamera_entrypoint_9(s32 arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_5(s32 arg0);
    void _capod_entrypoint_7(s32 arg0, s32 arg1);
    gcdialogcamera_entrypoint_6(arg0);
    gcdialogcamera_entrypoint_8();
    if (arg1 == 7) {
        _capod_entrypoint_5(0x200);
    }
    _capod_entrypoint_7(arg1, arg2);
}

void gcdialogcamera_entrypoint_10(void *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_0(s32, s32, s32);
    s32 _capod_entrypoint_4();
    s32 sp24;
    s32 sp20;

    func_80800000_gcdialogcamera(arg1, &sp24, &sp20);
    if (((Objcamera_arg0 *)arg0)->unk167 != 0) {
        if (func_8080003C_gcdialogcamera(((Objcamera_arg0 *)arg0)->unk168_voidp, ((Objcamera_arg0 *)arg0)->unk16C) != 0) {
            switch (_capod_entrypoint_4()) {
                case -1:
                    func_80800620_gcdialogcamera(arg2);
                case 6:
                    gcdialogcamera_entrypoint_9(((Objcamera_arg0 *)arg0)->unk168, sp24, sp20);
                    return;
                default:
                    switch (_capod_entrypoint_0(0x57, (sp20 << 16) | sp24, ((Objcamera_arg0 *)arg0)->unk168)) {
                        case 0:
                        case 1:
                            break;
                        case 2:
                            gcdialogcamera_entrypoint_9(((Objcamera_arg0 *)arg0)->unk168, sp24, sp20);
                            return;
                    }
                    break;
            }
        } else if (_capod_entrypoint_4() == 6) {
            gcdialogcamera_entrypoint_9(((Objcamera_arg0 *)arg0)->unk168, sp24, sp20);
        }
    }
}
/* data_to_c.py: from asm/data/overlays/gc/dialog/camera.data.s */
f32 D_808007C0_gcdialogcamera [21] [ 4 ] BT_DATA(4, overlays_gc_dialog_camera, 0x0) = { { 130.0f, 70.0f, 100.0f, 75.0f }, { 130.0f, 70.0f, 100.0f, 75.0f }, { 90.0f, 60.0f, 180.0f, 20.0f }, { 190.0f, 150.0f, 180.0f, 80.0f }, { 120.0f, 60.0f, 60.0f, 40.0f }, { 90.0f, 60.0f, 70.0f, 40.0f }, { 165.0f, 80.0f, 100.0f, 50.0f }, { 100.0f, 70.0f, 100.0f, 45.0f }, { 150.0f, 150.0f, 150.0f, 0.0f }, { 165.0f, 165.0f, 165.0f, 25.0f }, { 90.0f, 90.0f, 90.0f, 0.0f }, { 120.0f, 120.0f, 160.0f, 50.0f }, { 150.0f, 150.0f, 150.0f, 0.0f }, { 180.0f, 220.0f, 240.0f, 0.0f }, { 180.0f, 150.0f, 150.0f, 0.0f }, { 45.0f, 40.0f, 40.0f, 10.0f }, { 115.0f, 100.0f, 120.0f, 50.0f }, { 120.0f, 100.0f, 70.0f, 60.0f }, { 90.0f, 90.0f, 90.0f, 20.0f }, { 725.0f, 300.0f, 300.0f, 350.0f }, { 650.0f, 600.0f, 800.0f, 150.0f } };
