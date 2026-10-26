#include "nc/ba/suck.h"

void func_80800000_ncbasuck(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800020_ncbasuck(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbasuck_entrypoint_0(s32 arg0) {
    void func_80111B8C(s32 *, f32, f32);
    s32 func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C((s32 *) arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 1);
    func_80115858((void *) arg0, 0);
    func_80115870((void *) arg0, 0.0f);
}

void ncbasuck_entrypoint_1(s32 arg0) 
{
}
/* extern */

s32 func_80800094_ncbasuck(s32 *arg0) {
    s32 func_80092BC4(s32);
    s32 func_800F53D0(s32);
    return func_80092BC4(func_800F53D0(func_80110840(arg0)));
}

/* extern */

f32 func_808000C4_ncbasuck(s32 *arg0) {
    f32 func_80092BD0(s32);
    s32 func_800F53D0(s32);
    return func_80092BD0(func_800F53D0(func_80110840(arg0)));
}

void ncbasuck_entrypoint_2(PlayerState *arg0) {
    s32 func_80800094_ncbasuck(s32 *);
    f32 func_808000C4_ncbasuck(s32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_80110790(s32, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(s32, s32, s32);
    void func_80110F44(void *);
    s32 func_80111CC8(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    void func_80112D08(void *, s32, f32, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80113978(PlayerState *, s32, s32);
    f32 func_80115358(void *, f32);
    int func_80115580(void *, f32 *);
    f32 func_80115750(Actor *, f32);
    void func_80115828(void *, f32, f32);
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp2C[2];
    f32 sp28;
    s32 sp24;

    sp24 = func_80800094_ncbasuck(arg0);
    func_80800020_ncbasuck(arg0, sp5C);
    func_801107F0(arg0, sp44);
    func_800EFB24(sp50, sp44, sp5C);
    sp34 = func_800EEF94(sp50);
    func_800F1A88(sp50, sp2C);
    if (sp24 == 0) {
        func_80113978(arg0, 1, 0);
    }
    sp34 = func_80115358(arg0, sp34);
    sp2C[0] = func_80115750(arg0, sp2C[0]);
    sp2C[1] = func_80112C3C(arg0, sp2C[1]);
    func_80115828(arg0, -60.0f, 60.0f);
    sp2C[0] = func_80115750(arg0, sp2C[0]);
    if (sp24 != 0) {
        sp28 = func_808000C4_ncbasuck(arg0);
        func_80112D08(arg0, 5, sp28 - 45.0f, sp28 + 45.0f);
        sp2C[1] = func_80112C3C(arg0, sp2C[1]);
    }
    func_800EEBF0(sp50, sp2C, sp34);
    func_800EE780(sp44, sp5C, sp50);
    if (func_80111CC8(arg0, sp44) != 0 &&
        (func_801138A0(arg0) != 0 || func_80115580(arg0, sp5C) != 0) &&
        func_801138F4(arg0) != 0) {
        func_80110F44(arg0);
    }
    func_80800000_ncbasuck(arg0, sp5C);
    func_80110A68(arg0, sp38, sp5C);
    func_80110790(arg0, sp38);
}
