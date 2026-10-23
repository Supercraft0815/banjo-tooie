#include "common.h"

void ncbakaztorp_entrypoint_0(s32 arg0) 
{
}
/* extern */

void ncbakaztorp_entrypoint_1(u8 *arg0) {
    s32 func_801120CC(void *, s32, s32, s32);
    s32 func_801124D0(s32, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    s32 func_80111B8C(u8 *, s32, s32);
    func_801120CC(arg0, 0x44FA0000, 0x457A0000, -0x3A860000);
    func_80111B8C(arg0, 0x40800000, 0x41000000);
    func_801124D0((s32) arg0, 1);
    func_80115858(arg0, 2);
    func_80115870(arg0, 0.0f);
}

void ncbakaztorp_entrypoint_2(void *arg0) {
    f32 _bamovethrust_entrypoint_6(void *);
    f32 func_80013728(f32);
    f32 func_8009BFCC(void *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_800F53D0(s32);
    void func_80112524(void *, f32 *);
    f32 yaw_get(void *);
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_80110790(void *, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110818(void *, f32 *);
    s32 func_80110840(s32 *);
    void func_80110A68(void *, f32 *, f32 *);
    s32 func_80111FD4(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    s32 func_801138F4(void *);
    f32 func_80113978(void *, s32, s32);
    f32 func_80115358(void *, f32);
    f32 func_80115750(void *, f32);
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp5C;
    f32 sp54[2];
    void *sp50;
    f32 sp44[3];
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp;
    f32 scale;

    func_80112524(arg0, sp84);
    func_801107F0(arg0, sp6C);
    func_800EFB24(sp78, sp6C, sp84);
    sp5C = func_800EEF94(sp78);
    func_800F1A88(sp78, sp54);
    func_80113978(arg0, 1, 1);
    sp5C = func_80115358(arg0, sp5C);
    sp50 = func_800F53D0(func_80110840((s32 *)arg0));
    func_80110818(arg0, sp44);
    sp38 = _bamovethrust_entrypoint_6(sp50);
    sp40 = func_800F1DCC(180.0f, func_8009BFCC(sp50));
    temp = func_80013728((sp44[1] - yaw_get(sp50)) - 180.0f);
    sp3C = temp;
    if (temp > 90.0f) {
        sp3C = 180.0f - temp;
    } else if (temp < -90.0f) {
        sp3C = -180.0f - temp;
    }
    sp40 = func_80013728(sp44[0] - sp40);
    if (sp40 > 90.0f) {
        sp40 = 180.0f - sp40;
    } else if (sp40 < -90.0f) {
        sp40 = -180.0f - sp40;
    }
    scale = (sp38 / 225.0f) * 0.4f;
    sp54[0] -= scale * sp40;
    sp54[1] -= scale * sp3C;
    sp54[0] = func_80115750(arg0, sp54[0]);
    sp54[1] = func_80112C3C(arg0, sp54[1]);
    func_800EEBF0(sp78, sp54, sp5C);
    func_800EE780(sp6C, sp84, sp78);
    if (func_80111FD4(arg0, sp6C) != 0) {
        func_801138F4(arg0);
    }
    func_80110A68(arg0, sp60, sp84);
    func_80110790(arg0, sp60);
}
