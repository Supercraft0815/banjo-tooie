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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/jig/ncbajig_entrypoint_3.s")
