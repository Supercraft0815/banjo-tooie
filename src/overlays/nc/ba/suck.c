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

void func_80800094_ncbasuck(s32 *arg0) {
    s32 func_80092BC4(s32);
    s32 func_800F53D0(s32);
    func_80092BC4(func_800F53D0(func_80110840(arg0)));
}

/* extern */

void func_808000C4_ncbasuck(s32 *arg0) {
    s32 func_80092BD0(s32);
    s32 func_800F53D0(s32);
    func_80092BD0(func_800F53D0(func_80110840(arg0)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/suck/ncbasuck_entrypoint_2.s")
