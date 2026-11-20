#include "common.h"

BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800F5EF8(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u32));
void func_80110720(s8 *, s32); BT_NATIVE_ONLY(void func_80110928(void *); void func_8010FD88(u8 *);)

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) plcamera_entrypoint_0(s32 *arg0) { BtIntPtr func_80110014(s32 *); BtIntPtr sp1C = func_800F5EF8(arg0); func_801108A0(func_80110014(sp1C)); func_8010FD88(sp1C); BT_NATIVE_ONLY(return 0;) }

/* extern */

s32 plcamera_entrypoint_1(s32 arg0) {
    struct player_state_s;
    void _bsfirstp_entrypoint_2(struct player_state_s *);
    u32 func_800A3404(void *);
    s32 func_800EA068(s32);
    struct player_state_s *func_800F53E4(s32);
    s32 func_800F693C(BtIntPtr);
    struct player_state_s *self;

    self = func_800F53E4(arg0);
    if (self == NULL) {
        return 0;
    }
    if ((func_800A3404(self) != 0) && (func_800F693C(arg0) != 0) && (func_800EA068(8) != 0)) {
        _bsfirstp_entrypoint_2(self);
        return 1;
    }
    if (func_800A3404(self) != 0) {
        return 1;
    }
    return 0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) plcamera_entrypoint_2(s32 *arg0, s32 arg1) { BtIntPtr func_80110014(s32 *); BT_NATIVE_ONLY(return) func_801106A8(func_80110014(func_800F5EF8(arg0)), arg1); }

void plcamera_entrypoint_3(s32 *arg0, s32 arg1) { BtIntPtr func_80110014(s32 *); func_80110720(func_80110014(func_800F5EF8(arg0)), arg1); }

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) plcamera_entrypoint_4(s32 *arg0, s32 arg1) { BtIntPtr func_80110014(s32 *); BT_NATIVE_ONLY(return) func_80110770(func_80110014(func_800F5EF8(arg0)), arg1); }

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) plcamera_entrypoint_5(s32 *arg0, s32 arg1) { BtIntPtr func_80110014(s32 *); BT_NATIVE_ONLY(return) func_80110790(func_80110014(func_800F5EF8(arg0)), arg1); }

void plcamera_entrypoint_6(s32 arg0, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32) arg1, BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32) arg2, BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32) arg3, f32 arg4) {
    BtIntPtr func_80110014(s32 *);
    void _ncbadeflect_entrypoint_0(BtIntPtr, BT_NATIVE_ONLY(f32 *) BT_IDO_ONLY(s32), BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32), BT_NATIVE_ONLY(f32) BT_IDO_ONLY(s32), f32, f32);
    s32 *camera;
    BtIntPtr deflect;

    camera = BT_NATIVE_ONLY((s32 *))func_800F5EF8(arg0);
    if (camera != NULL) {
        deflect = func_80110014(camera);
        if (deflect != 0) {
            _ncbadeflect_entrypoint_0(deflect, arg1, arg2, arg3, arg4, 1000.0f);
        }
    }
}

void plcamera_entrypoint_7(s32 arg0, f32 *arg1, f32 arg2, f32 arg3) {
    BtIntPtr func_80110014(s32 *);
    void _ncbadeflect_entrypoint_1(BtIntPtr, f32 *, f32, f32, f32);
    s32 *camera;
    BtIntPtr deflect;

    camera = BT_NATIVE_ONLY((s32 *))func_800F5EF8(arg0);
    if (camera != NULL) {
        deflect = func_80110014(camera);
        if (deflect != 0) {
            _ncbadeflect_entrypoint_1(deflect, arg1, arg2, arg3, 1000.0f);
        }
    }
}

void plcamera_entrypoint_8(BT_IDO_ONLY(s32 *) BT_NATIVE_ONLY(u32) arg0) { BtIntPtr func_80110014(s32 *); BtIntPtr sp1C = func_800F5EF8(arg0); func_80110928(BT_NATIVE_ONLY((void *)) func_80110014(BT_NATIVE_ONLY((s32 *)) sp1C)); func_8010FD88(BT_NATIVE_ONLY((u8 *)) sp1C); }

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) plcamera_entrypoint_9(s32 *arg0, s32 arg1, s32 arg2) { BtIntPtr func_80110014(s32 *); BT_NATIVE_ONLY(return) func_801110EC(func_80110014(func_800F5EF8(arg0)), arg1, arg2); }

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) plcamera_entrypoint_10(s32 *arg0) {
    s32 func_801106A0(BtIntPtr);
    BtIntPtr func_80110014(s32 *);
    BT_NATIVE_ONLY(return) func_801106A0(func_80110014(func_800F5EF8(arg0)));
}

int func_80800300_plcamera(f32 *arg0, f32 *arg1) {
    Prop *_gccubesearch_entrypoint_6(s32 *, f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    f32 func_800EEB40(f32 *, f32 *);
    extern s32 D_80800510_plcamera[4];
    Prop *temp_v0;

    temp_v0 = _gccubesearch_entrypoint_6(D_80800510_plcamera, arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    _gspropctrl_entrypoint_11(temp_v0, arg1);
    return func_800EEB40(arg0, arg1) < 4000000.0f;
}

void plcamera_entrypoint_11(BtIntPtr arg0, f32 *arg1) {
    void func_800A516C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_8010FE14(s32 *, f32 *, f32 *);
    BtIntPtr func_80110014(s32 *);
    void func_80110720(s8 *, s32); BT_NATIVE_ONLY(void func_80110928(void *); void func_8010FD88(u8 *);)
    void func_801107F0(void *, f32 *);
    s32 *sp5C;
    s8 *sp58;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;
    f32 sp18[3];

    sp5C = func_800F5EF8(BT_NATIVE_ONLY((u32)) arg0);
    sp58 = func_80110014(sp5C);
    func_800F5A00(arg0, sp40);
    func_801107F0(sp58, sp4C);
    func_800EFB24(sp34, sp4C, sp40);
    func_800EFB24(sp28, arg1, sp40);
    sp24 = func_800EEAA4(sp34, sp28);
    func_80110720(sp58, 0);
    if ((sp24 > 0.0f) && func_80800300_plcamera(sp40, sp4C)) {
        func_800A516C(sp18, arg1, sp4C);
        sp18[0] += 10.0f;
        func_8010FE14(sp5C, sp4C, sp18);
    }
}

s32 plcamera_entrypoint_12(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8010FDA8();
    return func_8010FDA8(func_800F5EF8(arg0), arg1, arg2);
}

void plcamera_entrypoint_13(s32 arg0, f32 arg1) {
    void func_8010FDEC(void *, f32);
    func_8010FDEC(func_800F5EF8(arg0), arg1);
}

void plcamera_entrypoint_14(s32 *arg0, BtIntPtr arg1, BtIntPtr arg2) { BtIntPtr func_80110014(s32 *); func_80110848(func_80110014(func_800F5EF8(arg0)), arg1, arg2); }
/* data_to_c.py: from asm/data/overlays/pl/camera.data.s */
s32 D_80800510_plcamera[4] BT_DATA(4, overlays_pl_camera, 0x0) = { 1224, -1, 0, 0 };
