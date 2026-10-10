#include "nc/ba/pivot.h"

s32 ncbapivot_entrypoint_0() 
{
    return 0x4;
}

void func_80800008_ncbapivot(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbapivot_entrypoint_1(u8 *arg0) {
    s32 func_801120CC(void *, s32, s32, s32);
    s32 func_801124D0(s32, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    s32 func_80111B8C(u8 *, s32, s32);
    func_801120CC(arg0, 0x44FA0000, 0x457A0000, -0x3A860000);
    func_80111B8C(arg0, 0x40800000, 0x41000000);
    func_801124D0((s32) arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
}

void ncbapivot_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/pivot/ncbapivot_entrypoint_3.s")
