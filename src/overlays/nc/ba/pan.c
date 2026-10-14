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
    void func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_801120CC(arg0, 2000.0f, 4000.0f, -4000.0f);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0((s32) arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_80800048_ncbapan(arg0);
}

void ncbapan_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/pan/ncbapan_entrypoint_3.s")
