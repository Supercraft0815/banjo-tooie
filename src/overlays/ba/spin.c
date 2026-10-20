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

/* extern */

s32 baspin_entrypoint_3(void *arg0) {
    s32 pad;
    s32 _bafpctrl_entrypoint_4(void *);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    int baanim_isAt(void *, f32);
    int baanim_isStopped(void *);
    f32 func_80013970(f32);
    void func_8009328C(void *, f32);
    s32 func_800951B4(void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 yaw_applyIdeal(void *);
    s32 yaw_setIdeal(void *, f32);
    f32 sp30;
    f32 sp2C;
    f32 temp_f2;
    void *temp_v0;
    f32 scale;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x118)));
    scale = 360.0f;
    sp30 = (scale * (*(u8 *)((s8 *)(temp_v0) + (0)))) + (*(f32 *)((s8 *)(temp_v0) + (4))) + 180.0f;
    temp_f2 = func_80013970(func_800F10B4(_batimer_get(arg0, 0xB), 0, 1.5f, 1.0f, 0.0f) * 90.0f) * sp30;
    sp2C = temp_f2;
    func_8009328C(arg0, temp_f2);
    if (((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x118)))) + (1))) == 1) && (_bafpctrl_entrypoint_4(arg0) == 3)) {
        yaw_setIdeal(arg0, sp2C);
        yaw_applyIdeal(arg0);
    }
    _batimer_decrement(arg0, 0xB);
    if (baanim_isAt(arg0, 0.5f) != 0) {
        func_800951B4(arg0);
    }
    if ((_batimer_get(arg0, 0xB) == 0.0f) && (baanim_isStopped(arg0) != 0)) {
        return 2;
    }
    return 1;
}
