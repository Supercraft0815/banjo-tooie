#include "common.h"

s32 baspin_entrypoint_0() 
{
    return 0x8;
}

/* extern */

void baspin_entrypoint_1(void *arg0) {
    s32 _bafpctrl_entrypoint_4();
    s32 _ncba1p_entrypoint_4(s32, s32);
    s32 func_8008E95C(void *);
    f32 func_80092BE8(void *);
    s32 func_800931AC(void *, s32);
    s32 func_800951B4(void *);
    s32 func_8009BD88(void *);
    s32 func_800A4CA8(void *);
    s32 yaw_applyIdeal(void *);
    s32 yaw_setIdeal(void *, f32);
    if (((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x118)))) + (1))) == 1) && (_bafpctrl_entrypoint_4() == 3)) {
        _ncba1p_entrypoint_4(func_800A4CA8(arg0), 1);
    }
    func_8009BD88(arg0);
    func_8008E95C(arg0);
    func_800951B4(arg0);
    yaw_setIdeal(arg0, func_80092BE8(arg0));
    yaw_applyIdeal(arg0);
    func_800931AC(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/spin/baspin_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/spin/baspin_entrypoint_3.s")
