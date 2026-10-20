#include "nc/ba/die.h"

s32 ncbadie_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbadie(PlayerState *arg0, f32 *arg1) { func_80112524(arg0, arg1); arg1[1] = *(f32 *)*(void **)((s8 *)arg0 + 0x10) + arg1[1]; }

void func_80800048_ncbadie(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbadie_entrypoint_1(void *arg0) {
    void ncbadie_entrypoint_3(void *, f32);
    void func_80111B8C(s32 *, f32, f32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    void func_801124D0(s32, s32);
    ncbadie_entrypoint_3(arg0, 30.0f);
    func_80111B8C(arg0, 1.4f, 14.0f);
    func_80115858(arg0, 0);
    func_80115870(arg0, 5.0f);
    func_801124D0((s32) arg0, 4);
}

void ncbadie_entrypoint_2(s32 arg0) 
{
}
void ncbadie_entrypoint_3(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 16) + 0) = arg1;
}

void ncbadie_entrypoint_4(PlayerState *arg0) {
    f32 func_80013AAC(f32, f32);
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
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80115358(void *, f32);
    f32 func_80115750(Actor *, f32);
    void func_80115828(void *, f32, f32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp24[2];
    f32 temp;

    func_80800048_ncbadie(arg0, sp54);
    func_801107F0(arg0, sp3C);
    func_800EFB24(sp48, sp3C, sp54);
    sp2C = func_800EEF94(sp48);
    func_800F1A88(sp48, sp24);
    sp2C = func_80115358(arg0, sp2C);
    if (sp2C > 220.0f) {
        sp2C = 220.0f;
    }
    temp = func_80013AAC((120.0f - *(f32 *)arg0->babykaz) / 220.0f, sp2C);
    func_80115828(arg0, temp, temp);
    sp24[0] = func_80115750(arg0, sp24[0]);
    sp24[1] = func_80112C3C(arg0, sp24[1]);
    func_800EEBF0(sp48, sp24, sp2C);
    func_800EE780(sp3C, sp54, sp48);
    if (func_80111CC8(arg0, sp3C) && func_801138A0(arg0) && func_801138F4(arg0)) {
        func_80110F44(arg0);
    }
    func_80800008_ncbadie(arg0, sp54);
    func_80110A68(arg0, sp30, sp54);
    func_80110790(arg0, sp30);
}
