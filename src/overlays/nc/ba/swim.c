#include "common.h"

s32 ncbaswim_entrypoint_0() 
{
    return 0x4;
}

void ncbaswim_entrypoint_1(s32 arg0) 
{
}
void ncbaswim_entrypoint_2(s32 arg0) {
    s32 func_801124D0(s32, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    func_801124D0(arg0, 1);
    func_80115858((u8 *) arg0, 2);
    func_80115870((u8 *) arg0, 0.0f);
}

void ncbaswim_entrypoint_3(void *arg0) {
    f32 _baswim_entrypoint_14(void *);
    f32 _ncbawaypoint_entrypoint_3(void *, f32 *, f32 *);
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
    void func_80110F44(void *);
    s32 func_80111CC8(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(void *);
    f32 func_80113978(void *, s32, s32);
    f32 func_80115358(void *, f32);
    s32 func_80115580(void *, f32 *);
    f32 func_801155E8(void *);
    f32 func_80115750(void *, f32);
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp68[3];
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    f32 sp54[2];
    void *sp50;
    f32 sp44[3];
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp;
    f32 scale;

    func_80112524(arg0, sp8C);
    func_801107F0(arg0, sp74);
    if (**(s32 **)((u8 *)arg0 + 0x5C) != 0) {
        sp60 = _ncbawaypoint_entrypoint_3(arg0, sp8C, sp74);
    } else {
        sp60 = 0.0f;
    }
    func_800EFB24(sp80, sp74, sp8C);
    sp5C = func_800EEF94(sp80) + sp60;
    func_800F1A88(sp80, sp54);
    sp54[0] += func_80113978(arg0, 1, 1);
    sp64 = func_80115358(arg0, sp5C);
    sp50 = func_800F53D0(func_80110840((s32 *)arg0));
    func_80110818(arg0, sp44);
    sp38 = _baswim_entrypoint_14(sp50);
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
    scale = (sp38 / 900.0f) * 0.2f;
    sp54[0] -= scale * sp40;
    sp54[1] -= scale * sp3C;
    sp54[0] = func_80115750(arg0, sp54[0]);
    sp54[1] = func_80112C3C(arg0, sp54[1]);
    sp64 -= sp60;
    func_800EEBF0(sp80, sp54, sp64);
    func_800EE780(sp74, sp8C, sp80);
    if (func_80111CC8(arg0, sp74) != 0) {
        if (func_801138A0(arg0) != 0) {
            if (func_801138F4(arg0) != 0) {
                func_80110F44(arg0);
            }
        } else if (func_80115580(arg0, sp8C) != 0 && func_801155E8(arg0) < sp5C) {
            func_801138F4(arg0);
        }
    }
    func_80112524(arg0, sp8C);
    func_80110A68(arg0, sp68, sp8C);
    func_80110790(arg0, sp68);
}
