#include "common.h"

void ncbasub_entrypoint_0(s32 arg0) 
{
}
void ncbasub_entrypoint_1(s32 arg0) {
    s32 func_801124D0(s32, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    func_801124D0(arg0, 1);
    func_80115858((u8 *) arg0, 2);
    func_80115870((u8 *) arg0, 0.0f);
}

void ncbasub_entrypoint_2(void *arg0) {
    typedef struct player_state_s PlayerState;
    f32 func_8009BFCC(PlayerState *);
    f32 yaw_get(PlayerState *);
    PlayerState *func_800F53D0(s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 _bamovethrust_entrypoint_6(PlayerState *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    f32 func_80013728(f32);
    f32 func_800F5E7C(s32);
    f32 func_800F5F7C(u32);
    void func_80110790(void *, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110818(void *, f32 *);
    s32 func_80110840(s32 *);
    void func_80110A68(void *, f32 *, f32 *);
    s32 func_80111CC8(void *, f32 *);
    void func_80112524(PlayerState *, f32 *);
    f32 func_80112C3C(void *, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80113978(PlayerState *, s32, s32);
    f32 func_80115358(void *, f32);
    s32 func_80115580(void *, f32 *);
    f32 func_80115750(void *, f32);
    void func_80115858(void *, s32);
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp64;
    f32 sp5C[2];
    s32 sp58;
    s32 sp54;
    PlayerState *sp50;
    f32 sp44[3];
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 scale;
    f32 angle;

    sp58 = func_80110840(arg0);
    sp54 = (func_800F5E7C(sp58) - func_800F5F7C(sp58)) < 200.0f;
    func_80112524(arg0, sp8C);
    func_801107F0(arg0, sp74);
    func_800EFB24(sp80, sp74, sp8C);
    sp64 = func_800EEF94(sp80);
    func_800F1A88(sp80, sp5C);
    func_80113978(arg0, 1, 1);
    sp64 = func_80115358(arg0, sp64);
    sp50 = func_800F53D0(func_80110840(arg0));
    func_80110818(arg0, sp44);
    sp38 = _bamovethrust_entrypoint_6(sp50);
    sp40 = func_800F1DCC(180.0f, func_8009BFCC(sp50));
    sp3C = func_80013728(sp44[1] - yaw_get(sp50) - 180.0f);
    if (sp3C > 90.0f) {
        sp3C = 180.0f - sp3C;
    } else if (sp3C < -90.0f) {
        sp3C = -180.0f - sp3C;
    }
    sp40 = func_80013728(sp44[0] - sp40);
    if (sp40 > 90.0f) {
        sp40 = 180.0f - sp40;
    } else if (sp40 < -90.0f) {
        sp40 = -180.0f - sp40;
    }
    scale = (sp38 / 90.0f) * 0.3f;
    sp5C[0] -= scale * sp40;
    if (!sp54) {
        sp5C[1] -= scale * sp3C;
    }
    sp5C[0] = func_80115750(arg0, sp5C[0]);
    sp5C[1] = func_80112C3C(arg0, sp5C[1]);
    func_800EEBF0(sp80, sp5C, sp64);
    func_800EE780(sp74, sp8C, sp80);
    if (func_80111CC8(arg0, sp74) && (func_801138A0(arg0) || func_80115580(arg0, sp8C))) {
        func_801138F4(arg0);
    }
    func_80110A68(arg0, sp68, sp8C);
    func_80110790(arg0, sp68);
    func_80115858(arg0, sp54 ? 1 : 2);
}
