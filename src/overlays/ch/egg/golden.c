#include "common.h"

void func_80800000_chegggolden(Actor *arg0) {
    void _fxegg_entrypoint_6(f32 *, f32, f32 *);
    s32 func_800A946C(void);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *temp_s0;
    f32 *temp_s1;
    f32 sp64[3];
    f32 sp58[3];
    f32 temp_f20;

    temp_s1 = func_80100094(arg0, 0);
    if (func_800A946C() < 3) {
        func_800EFA20(sp64, &arg0->actorData[4], 0.5f);
        temp_s1[10] -= func_800D8FF8();
        temp_f20 = func_800F10B4(temp_s1[12], 0, 1.8f, 0.0333f, 0.1f);
        temp_s0 = arg0->position;
        if (temp_s1[10] <= 0.0f) {
            do {
                temp_s1[10] += temp_f20;
                func_800EE7F8(sp58, temp_s0);
                _fxegg_entrypoint_6(temp_s0, arg0->scale, sp64);
            } while (temp_s1[10] <= 0.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/golden/func_80800110_chegggolden.s")

OSThread *chegggolden_entrypoint_0(void)
{
    extern u8 D_808003F0_chegggolden[];

    return (OSThread *) D_808003F0_chegggolden;
}

/* extern */

void *chegggolden_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15F, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

/* extern */

void *chegggolden_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15F, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
