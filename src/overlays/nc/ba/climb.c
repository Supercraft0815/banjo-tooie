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

void ncbaclimb_entrypoint_1(s32 arg0) {
    void func_80111B8C(s32 *, f32, f32);
    s32 func_801124D0(s32, s32);
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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/climb/ncbaclimb_entrypoint_3.s")
