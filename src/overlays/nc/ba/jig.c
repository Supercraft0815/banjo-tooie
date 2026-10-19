#include "nc/ba/jig.h"

s32 ncbajig_entrypoint_0() 
{
    return 0xC;
}

void func_80800008_ncbajig(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbajig(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbajig_entrypoint_1(void *arg0) {
    void func_80111B8C(s32 *, f32, f32);
    void func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C(arg0, 1.8f, 14.0f);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x2C)))) + (0))) = 290.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x2C)))) + (4))) = 12.0f;
    func_80115858(arg0, 0);
    func_80115870(arg0, 5.0f);
    func_801124D0((s32)arg0, 5);
}

void ncbajig_entrypoint_2(s32 arg0) 
{
}
/* extern */

void ncbajig_entrypoint_3(PlayerState *arg0) {
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
    f32 sp5C[3];
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp2C[2];
    f32 *temp_v0;
    f32 temp_f0_2;
    f32 temp_f2;

    func_80800028_ncbajig(arg0, sp5C);
    func_801107F0(arg0, sp44);
    func_800EFB24(sp50, sp44, sp5C);
    sp34 = func_800EEF94(sp50);
    func_800F1A88(sp50, sp2C);
    sp34 = func_80115358(arg0, sp34);
    temp_v0 = (void *)arg0->unk2C;
    temp_f2 = temp_v0[0];
    if (temp_f2 < sp34) {
        sp34 = temp_f2;
    }
    temp_f0_2 = temp_v0[1];
    func_80115828(arg0, temp_f0_2, temp_f0_2);
    sp2C[0] = func_80115750((Actor *)arg0, sp2C[0]);
    sp2C[1] = func_80112C3C(arg0, sp2C[1]);
    func_800EEBF0(sp50, sp2C, sp34);
    func_800EE780(sp44, sp5C, sp50);
    if ((func_80111CC8(arg0, sp44) != 0) && (func_801138A0(arg0) != 0) && (func_801138F4(arg0) != 0)) {
        func_80110F44(arg0);
    }
    func_80800008_ncbajig(arg0, sp5C);
    func_80110A68((s32)arg0, (s32)sp38, (s32)sp5C);
    func_80110790((s32)arg0, sp38);
}
