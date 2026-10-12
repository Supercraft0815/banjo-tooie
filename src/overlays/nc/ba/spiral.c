#include "nc/ba/spiral.h"

s32 ncbaspiral_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbaspiral_entrypoint_1(void *arg0) {
    s32 func_800EFD24(s32);
    void func_80111B8C(s32 *, f32, f32);
    void func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_800EFD24((s32 *)((s8 *)(*(s32 **)((s8 *)(arg0) + (0x48))) + 4));
    *(*(s32 **)((s8 *)(arg0) + (0x48))) = -1;
}

void ncbaspiral_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spiral/ncbaspiral_entrypoint_3.s")

/* extern */

void ncbaspiral_entrypoint_4(void *arg0) {
    s32 func_800EE7F8(s32 *);
    func_800EE7F8(*(s32 **)((s8 *)arg0 + 0x48) + 1);
    *(*(s32 **)((s8 *)(arg0) + (0x48))) = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spiral/ncbaspiral_entrypoint_5.s")
