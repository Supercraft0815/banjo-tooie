#include "nc/ba/pan.h"

s32 ncbapan_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbapan(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbapan(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void func_80800048_ncbapan(PlayerState *arg0) {
    void func_800EFB24(void *, void *, void *);
    s32 func_800F1EA4(f32[3], f32 *);
    void func_801107F0(void *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_801107F0(arg0, sp34);
    func_80800028_ncbapan(arg0, sp1C);
    func_800EFB24(sp28, sp34, sp1C);
    func_800F1EA4(sp28, *(f32 **)((s8 *)arg0 + 0x38));
}

/* extern */

void ncbapan_entrypoint_1(PlayerState *arg0) {
    void func_80111B8C(s32 *, f32, f32);
    void func_801120CC(s32 *, f32, f32, f32);
    void func_801124D0(BtIntPtr, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0((BtIntPtr) arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_80800048_ncbapan(arg0);
}

void ncbapan_entrypoint_2(s32 arg0) 
{
}
void ncbapan_entrypoint_3(PlayerState *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    void func_80110790(BtIntPtr, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_80110F44(void *);
    s32 func_80111FD4(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80113978(PlayerState *, s32, s32);
    f32 func_80115358(void *, f32);
    int func_80115580(void *, f32 *);
    f32 func_80115750(Actor *, f32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp24[2];
    f32 temp_f0;

    func_80800028_ncbapan(arg0, sp54);
    func_801107F0(arg0, sp3C);
    func_800EFB24(sp48, sp3C, sp54);
    sp2C = func_800EEF94(sp48);
    func_800F1A88(sp48, sp24);
    func_80113978(arg0, 1, 0);
    sp2C = func_80115358(arg0, sp2C);
    sp24[0] = func_80115750(arg0, sp24[0]);
    temp_f0 = func_80112C3C(arg0, sp24[1]);
    if (temp_f0 != sp24[1]) {
        **(f32 **)((s8 *)arg0 + 0x38) = temp_f0;
    }
    sp24[1] = **(f32 **)((s8 *)arg0 + 0x38);
    func_800EEBF0(sp48, sp24, sp2C);
    func_800EE780(sp3C, sp54, sp48);
    if (func_80111FD4(arg0, sp3C) != 0) {
        if (((func_801138A0(arg0) != 0) || (func_80115580(arg0, sp54) != 0)) &&
            (func_801138F4(arg0) != 0)) {
            func_80110F44(arg0);
        }
        func_80800048_ncbapan(arg0);
    }
    func_80800008_ncbapan(arg0, sp54);
    func_80110A68((BtIntPtr)arg0, (BtIntPtr)sp30, (BtIntPtr)sp54);
    func_80110790((BtIntPtr)arg0, sp30);
}
