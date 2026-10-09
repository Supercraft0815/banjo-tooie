#include "nc/ba/fly.h"

s32 ncbafly_entrypoint_0() 
{
    return 0x4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fly/ncbafly_entrypoint_1.s")

void ncbafly_entrypoint_2(s32 arg0) 
{
}
void func_808000A4_ncbafly(PlayerState* arg0, f32* arg1)
{
    func_80112550(arg0,arg1);
}

void ncbafly_entrypoint_3(PlayerState *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F1A88(f32 *, f32 *);
    f32 func_800F5AE0(s32);
    void func_80110790(PlayerState *, f32 *);
    void func_801107F0(PlayerState *, f32 *);
    s32 func_80110840(PlayerState *);
    void func_80110A68(PlayerState *, f32 *, f32 *);
    f32 func_801112B0(PlayerState *);
    s32 func_80111CC8(PlayerState *, f32 *);
    void func_801138F4(PlayerState *);
    void func_80115444(void *, f32 *, f32 *);
    f32 func_80115750(PlayerState *, f32);
    void func_80115828(void *, f32, f32);
    void func_8011607C(void *, s32);
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp50;
    f32 sp44[3];
    f32 sp40;
    f32 sp34[3];
    s32 sp30;
    f32 angle;

    sp30 = func_80110840(arg0);
    func_8011607C(arg0, 1);
    func_801107F0(arg0, sp60);
    func_808000A4_ncbafly(arg0, sp6C);
    func_80115444(arg0, &sp50, &sp40);
    angle = func_80013728(func_800F5AE0(sp30));
    if (angle < 0.0f) {
        angle = func_800F10B4(angle, -30.0f, -60.0f, 0.0f, 84.0f);
        func_80115828(arg0, angle, angle);
    } else {
        func_80115828(arg0, angle, angle);
    }
    func_800EFB24(sp34, sp60, sp6C);
    func_800F1A88(sp34, sp44);
    sp44[0] = func_80115750(arg0, sp44[0]);
    sp44[1] = func_800136E4(func_801112B0(arg0) + 180.0f);
    func_800EEBF0(sp34, sp44, sp50);
    func_800EE780(sp60, sp6C, sp34);
    if (func_80111CC8(arg0, sp60) != 0) {
        func_801138F4(arg0);
    }
    func_80112524(arg0, sp6C);
    func_80110A68(arg0, sp54, sp6C);
    func_80110790(arg0, sp54);
}

void ncbafly_entrypoint_4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {

}

void ncbafly_entrypoint_5(s32 arg0)
{
}
