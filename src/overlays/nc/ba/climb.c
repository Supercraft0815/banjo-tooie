#include "nc/ba/climb.h"

s32 ncbaclimb_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbaclimb(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbaclimb(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbaclimb_entrypoint_1(BtIntPtr arg0) {
    void func_80111B8C(s32 *, f32, f32);
    void func_801124D0(BtIntPtr arg0, s32 arg1);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C((s32 *) arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 2);
    func_80115858((void *) arg0, 0);
    func_80115870((void *) arg0, 0.0f);
}

void ncbaclimb_entrypoint_2(s32 arg0) 
{
}
/* extern */

void ncbaclimb_entrypoint_3(PlayerState *arg0) {
    u32 func_8009861C(void *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    PlayerState *func_800F53D0(BtIntPtr);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    s32 func_80110840(s32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80110F44(void *);
    f32 func_801112B0(void *);
    s32 func_80111CC8(void *, f32 *);
    f32 func_80112C3C(PlayerState *, f32);
    void func_80112D08(void *, s32, f32, f32);
    s32 func_801138A0(PlayerState *);
    s32 func_801138F4(PlayerState *);
    f32 func_80113978(PlayerState *, s32, s32);
    f32 func_80115358(PlayerState *, f32);
    int func_80115580(void *, f32 *);
    f32 func_80115750(PlayerState *, f32);
    void func_80115828(void *arg0, f32 arg1, f32 arg2);
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp3C[2];
    f32 temp_f0;
    s32 sp34;
    s32 temp_v1;

    temp_v1 = func_8009861C(func_800F53D0(func_80110840(arg0))) == 2;
    sp34 = temp_v1;
    if (temp_v1 == 0) {
        func_80113978(arg0, 1, 0);
    }
    func_80800028_ncbaclimb(arg0, sp6C);
    func_801107F0(arg0, sp54);
    func_800EFB24(sp60, sp54, sp6C);
    sp44 = func_800EEF94(sp60);
    func_800F1A88(sp60, sp3C);
    sp44 = func_80115358(arg0, sp44);
    sp3C[0] = func_80115750(arg0, sp3C[0]);
    sp3C[1] = func_80112C3C(arg0, sp3C[1]);
    func_80115828(arg0, -60.0f, 60.0f);
    sp3C[0] = func_80115750(arg0, sp3C[0]);
    if (sp34 != 0) {
        temp_f0 = func_800F1DCC(func_801112B0(arg0), 180.0f);
        func_80112D08(arg0, 5, temp_f0 - 45.0f, temp_f0 + 45.0f);
        sp3C[1] = func_80112C3C(arg0, sp3C[1]);
    }
    func_800EEBF0(sp60, sp3C, sp44);
    func_800EE780(sp54, sp6C, sp60);
    if ((func_80111CC8(arg0, sp54) != 0) && ((func_801138A0(arg0) != 0) || (func_80115580(arg0, sp6C) != 0)) && (func_801138F4(arg0) != 0)) {
        func_80110F44(arg0);
    }
    func_80800008_ncbaclimb(arg0, sp6C);
    func_80110A68(arg0, sp48, sp6C);
    func_80110790(arg0, sp48);
}
