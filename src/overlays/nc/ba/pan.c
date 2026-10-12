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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/pan/ncbapan_entrypoint_1.s")

void ncbapan_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/pan/ncbapan_entrypoint_3.s")
