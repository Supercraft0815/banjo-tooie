#include "common.h"

void func_80800000_chegggrenade(Actor *arg0) {
    void _fxegg_entrypoint_5(f32 *, f32 *, f32);
    void _suegg_entrypoint_20(Actor *, f32 *);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *temp_s0;
    f32 *temp_s1;
    f32 sp64[3];
    f32 sp58[3];
    f32 temp_f22;

    temp_s1 = func_80100094(arg0, 0);
    temp_s1[10] -= func_800D8FF8();
    temp_f22 = func_800F10B4(temp_s1[12], 0, 2.0f, 0.0333f, 0.1f);
    _suegg_entrypoint_20(arg0, sp58);
    temp_s0 = arg0->position;
    if (temp_s1[10] <= 0.0f) {
        do {
            temp_s1[10] += temp_f22;
            func_800EE7F8(sp64, temp_s0);
            _fxegg_entrypoint_5(temp_s0, sp58, arg0->scale);
        } while (temp_s1[10] <= 0.0f);
    }
}

/* extern */

void chegggrenade_entrypoint_0(void *arg0) {
    s32 _cheggsplode_entrypoint_1(s32 *, s32, s32);
    s32 _gcegg_entrypoint_0(u32);
    s32 _suegg_entrypoint_4(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80106790();
    s32 sp24;
    s32 temp_v0;
    s32 sp1C;

    temp_v0 = func_80106790();
    sp24 = temp_v0;
    sp1C = (s32) (*(s16 *)((s8 *)(func_80100094(temp_v0, 0)) + (0x3A)));
    _cheggsplode_entrypoint_1(&sp24, sp1C, _gcegg_entrypoint_0((u32) (*(u32 *)((s8 *)(arg0) + (0x24))) >> 0x16));
    _suegg_entrypoint_4(sp24, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/grenade/func_80800164_chegggrenade.s")

OSThread *chegggrenade_entrypoint_1(void)
{
    extern u8 D_80800450_chegggrenade[];

    return (OSThread *) D_80800450_chegggrenade;
}

/* extern */

void *chegggrenade_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15D, arg1, arg3);
    temp_v0->scale = 0.134f;
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_5(temp_v0, 1);
    _sueggmove_entrypoint_6(temp_v0, -2200.0f, -22000.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 2;
    return temp_v0;
}

/* extern */

void *chegggrenade_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _suegg_entrypoint_1(void *, f32);
    void *_suegg_entrypoint_11(s32, s32, s32);
    s32 _sueggmove_entrypoint_10(s32);
    s32 _sueggmove_entrypoint_5(void *, s32);
    s32 _sueggmove_entrypoint_6(void *, f32, f32);
    s32 _sueggmove_entrypoint_7(void *, s32);
    Actor *temp_v0;

    _sueggmove_entrypoint_10(arg0);
    temp_v0 = _suegg_entrypoint_11(0x15D, arg1, arg3);
    temp_v0->scale = 0.25f;
    _sueggmove_entrypoint_5(temp_v0, 0);
    _sueggmove_entrypoint_6(temp_v0, 0.0f, -100000.0f);
    _suegg_entrypoint_1(temp_v0, 30.0f);
    _sueggmove_entrypoint_7(temp_v0, arg2);
    temp_v0->unk70_10 = 1;
    return temp_v0;
}
