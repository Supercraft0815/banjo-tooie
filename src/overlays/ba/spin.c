#include "common.h"

s32 baspin_entrypoint_0() 
{
    return 0x8;
} typedef struct { u8 pad0[0x118]; union { u8 * unk118; void * unk118_voidp; }; } Objspin_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void baspin_entrypoint_1(void *arg0) {
    s32 _bafpctrl_entrypoint_4();
    void _ncba1p_entrypoint_4(void *arg0, s32 arg1);
    void func_8008E95C(void *arg0);
    f32 func_80092BE8(void *);
    void func_800931AC(void *arg0, s32 arg1);
    void func_800951B4(void *player);
    void func_8009BD88(void *arg0);
    BtIntPtr func_800A4CA8(void *);
    void yaw_applyIdeal(void *self);
    void yaw_setIdeal(void *self, f32 arg1);
    if (((*(u8 *)((s8 *)((((Objspin_arg0 *)arg0)->unk118_voidp)) + (1))) == 1) && (_bafpctrl_entrypoint_4() == 3)) {
        _ncba1p_entrypoint_4(func_800A4CA8(arg0), 1);
    }
    func_8009BD88(arg0);
    func_8008E95C(arg0);
    func_800951B4(arg0);
    yaw_setIdeal(arg0, func_80092BE8(arg0));
    yaw_applyIdeal(arg0);
    func_800931AC(arg0, 1);
}

void baspin_entrypoint_2(void *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    s32 _bafpctrl_entrypoint_4(void *);
    void _bareact_entrypoint_1(void *arg0, s32 arg1);
    f32 _bareact_entrypoint_4(void *);
    void _batimer_set(void *, s32, f32);
    void _ncba1p_entrypoint_4(void *arg0, s32 arg1);
    void baanim_playForDuration_once(void *self, s32 anim_id, f32 duration);
    f32 baphysics_get_target_horizontal_velocity(void *);
    void baphysics_set_horizontal_velocity(void *, f32, f32);
    void baphysics_set_target_horizontal_velocity(void *, f32);
    void baphysics_set_target_yaw(void *, f32);
    void baroll_setIdeal(void *, f32);
    void func_8008E944(void *);
    void func_800931AC(void *arg0, s32 arg1);
    void func_8009328C(void *, f32);
    void func_8009514C(void *);
    s32 func_80099A58(void *);
    void func_8009BF5C(void *, f32);
    void func_8009C128(void *, f32[3]);
    void func_8009D9D4(void *);
    void func_8009FFD8(void *, s32, s32, s32, s32);
    void func_800A32C4(void *, f32[3]);
    s32 func_800A32EC(void *);
    BtIntPtr func_800A4CA8(void *);
    s32 func_800F1E6C(f32 *arg0, f32 *arg1, f32 *target_yaw);
    void yaw_applyIdeal(void *self);
    f32 yaw_get(void *);
    void yaw_setIdeal(void *self, f32 arg1);
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];

    (((Objspin_arg0 *)arg0)->unk118)[1] = arg4;
    (((Objspin_arg0 *)arg0)->unk118)[0] = arg3;
    _bareact_entrypoint_1(arg0, func_80099A58(arg0));
    baanim_playForDuration_once(arg0, arg1, arg2);
    if (func_800A32EC(arg0) != 3) {
        func_8009D9D4(arg0);
    }
    func_8009C128(arg0, sp40);
    func_800A32C4(arg0, sp34);
    func_800F1E6C(sp34, sp40, &sp4C);
    yaw_setIdeal(arg0, sp4C);
    yaw_applyIdeal(arg0);
    baroll_setIdeal(arg0, 0.0f);
    func_8009BF5C(arg0, 0.0f);
    *(f32 *)(((Objspin_arg0 *)arg0)->unk118 + 4) = yaw_get(arg0);
    func_800931AC(arg0, 3);
    func_8009328C(arg0, *(f32 *)(((Objspin_arg0 *)arg0)->unk118 + 4));
    baphysics_set_target_horizontal_velocity(arg0, _bareact_entrypoint_4(arg0));
    baphysics_set_target_yaw(arg0, sp4C);
    baphysics_set_horizontal_velocity(arg0, sp4C, baphysics_get_target_horizontal_velocity(arg0));
    func_8009FFD8(arg0, 1, 1, 2, 3);
    func_8008E944(arg0);
    func_8009514C(arg0);
    _batimer_set(arg0, 0xB, 1.5f);
    if (((((Objspin_arg0 *)arg0)->unk118)[1] == 1) && (_bafpctrl_entrypoint_4(arg0) == 3)) {
        _ncba1p_entrypoint_4(func_800A4CA8(arg0), 0);
    }
} 

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
    void func_800951B4(void *player);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void yaw_applyIdeal(void *self);
    void yaw_setIdeal(void *self, f32 arg1);
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
