#include "common.h"

s32 func_800F5EF8(s32);

void plcamera_entrypoint_0(s32 *arg0) { s32 func_80110014(s32 *); int sp1C = func_800F5EF8(arg0); func_801108A0(func_80110014(sp1C)); func_8010FD88(sp1C); }

/* extern */

s32 plcamera_entrypoint_1(s32 arg0) {
    struct player_state_s;
    void _bsfirstp_entrypoint_2(struct player_state_s *);
    u32 func_800A3404(void *);
    s32 func_800EA068(s32);
    struct player_state_s *func_800F53E4(s32);
    s32 func_800F693C(s32);
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

void plcamera_entrypoint_2(s32 *arg0, s32 arg1) { s32 func_80110014(s32 *); func_801106A8(func_80110014(func_800F5EF8(arg0)), arg1); }

void plcamera_entrypoint_3(s32 *arg0, s32 arg1) { s32 func_80110014(s32 *); func_80110720(func_80110014(func_800F5EF8(arg0)), arg1); }

void plcamera_entrypoint_4(s32 *arg0, s32 arg1) { s32 func_80110014(s32 *); func_80110770(func_80110014(func_800F5EF8(arg0)), arg1); }

void plcamera_entrypoint_5(s32 *arg0, s32 arg1) { s32 func_80110014(s32 *); func_80110790(func_80110014(func_800F5EF8(arg0)), arg1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/pl/camera/plcamera_entrypoint_6.s")

void plcamera_entrypoint_7(s32 arg0, f32 *arg1, f32 arg2, f32 arg3) {
    s32 func_80110014(s32 *);
    void _ncbadeflect_entrypoint_1(s32, f32 *, f32, f32, f32);
    s32 *camera;
    s32 deflect;

    camera = func_800F5EF8(arg0);
    if (camera != NULL) {
        deflect = func_80110014(camera);
        if (deflect != 0) {
            _ncbadeflect_entrypoint_1(deflect, arg1, arg2, arg3, 1000.0f);
        }
    }
}

void plcamera_entrypoint_8(s32 *arg0) { s32 func_80110014(s32 *); int sp1C = func_800F5EF8(arg0); func_80110928(func_80110014(sp1C)); func_8010FD88(sp1C); }

void plcamera_entrypoint_9(s32 *arg0, s32 arg1, s32 arg2) { s32 func_80110014(s32 *); func_801110EC(func_80110014(func_800F5EF8(arg0)), arg1, arg2); }

/* extern */

void plcamera_entrypoint_10(s32 *arg0) {
    s32 func_801106A0(s32);
    s32 func_80110014(s32 *);
    func_801106A0(func_80110014(func_800F5EF8(arg0)));
}

int func_80800300_plcamera(f32 *arg0, f32 *arg1) {
    Prop *_gccubesearch_entrypoint_6(s32 *, f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    f32 func_800EEB40(f32 *, f32 *);
    extern s32 D_80800510_plcamera;
    Prop *temp_v0;

    temp_v0 = _gccubesearch_entrypoint_6(&D_80800510_plcamera, arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    _gspropctrl_entrypoint_11(temp_v0, arg1);
    return func_800EEB40(arg0, arg1) < 4000000.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/pl/camera/plcamera_entrypoint_11.s")

s32 plcamera_entrypoint_12(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8010FDA8();
    return func_8010FDA8(func_800F5EF8(arg0), arg1, arg2);
}

void plcamera_entrypoint_13(s32 arg0, f32 arg1) {
    void func_8010FDEC(void *, f32);
    func_8010FDEC(func_800F5EF8(arg0), arg1);
}

void plcamera_entrypoint_14(s32 *arg0, s32 arg1, s32 arg2) { s32 func_80110014(s32 *); func_80110848(func_80110014(func_800F5EF8(arg0)), arg1, arg2); }
