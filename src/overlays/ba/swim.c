#include "common.h"
struct player_state_s;

s32 baswim_entrypoint_0() 
{
    return 0x8;
}

/* extern */

int baswim_entrypoint_1(struct player_state_s *arg0) {
    f32 func_800964DC(struct player_state_s *);
    f32 func_8009C150(struct player_state_s *);
    return (func_800964DC(arg0) - func_8009C150(arg0)) < 100.0f;
}

/* extern */

int baswim_entrypoint_2(struct player_state_s *arg0) {
    f32 func_800964DC(struct player_state_s *);
    s32 func_80096544(struct player_state_s *);
    f32 func_8009C150(struct player_state_s *);
    s32 pad;
    return func_80096544(arg0) &&
        func_8009C150(arg0) > func_800964DC(arg0) - 130.0f;
}

int baswim_entrypoint_3(struct player_state_s *arg0) {
    int bakey_held(struct player_state_s *, s32);
    int func_800C6E38(s32);
    int sp1C;
    int sp18;

    sp1C = bakey_held(arg0, 8);
    sp18 = bakey_held(arg0, 9);
    if (func_800C6E38(0x30) && sp1C && sp18) {
        return 3;
    }
    if (sp18) {
        return 2;
    }
    if (sp1C) {
        return 1;
    }
    return 0;
}

void baswim_entrypoint_4()
{
    bastick_resetZones();
}

void baswim_entrypoint_5(struct player_state_s *arg0) {
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    void baswim_entrypoint_9(void *, f32);
    void baswim_entrypoint_8(void *, f32);
    bastick_setZoneMax(arg0, 0, 0.03f);
    bastick_setZoneMax(arg0, 1, 1.0f);
    baswim_entrypoint_9(arg0, 0.0f);
    baswim_entrypoint_8(arg0, 0.0f);
}

void baswim_entrypoint_6(struct player_state_s *arg0, u32 arg1) {
    void baswim_entrypoint_7(struct player_state_s *, u32, u32);
    baswim_entrypoint_7(arg0, arg1, 0U);
}

void baswim_entrypoint_7(struct player_state_s *arg0, u32 arg1, u32 arg2) {
    s32 _bafpctrl_entrypoint_4(struct player_state_s *);
    void _bafpctrl_entrypoint_9(struct player_state_s *, s32);
    void _bafpctrl_entrypoint_11(struct player_state_s *, s32, s32);
    void _bafpctrl_entrypoint_16(struct player_state_s *, s32);
    void _bafpctrl_entrypoint_17(struct player_state_s *);
    int func_800A3274(struct player_state_s *);
    int func_800C6E38(s32);
    s32 sp24;

    if (arg1 != 0) {
        sp24 = 0;
        _bafpctrl_entrypoint_9(arg0, 1);
        if (_bafpctrl_entrypoint_4(arg0) != 3) {
            _bafpctrl_entrypoint_16(arg0, 2);
            if (func_800C6E38(0x1F) == 0) {
                sp24 = 1;
            }
            if ((arg2 == 0) && (func_800A3274(arg0) == 0xA)) {
                sp24 += 1;
            }
            if (sp24 != 0) {
                _bafpctrl_entrypoint_11(arg0, 4, 1);
            }
        }
    } else {
        _bafpctrl_entrypoint_17(arg0);
        _bafpctrl_entrypoint_9(arg0, 0);
    }
}

void baswim_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 4) = arg1;
}

void baswim_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 0) = arg1;
}

void baswim_entrypoint_10(void *arg0, f32 arg1) {
    f32 *temp_v0;

    temp_v0 = (*(f32 **)((s8 *)(arg0) + (0x134)));
    if (*temp_v0 < arg1) {
        *temp_v0 = arg1;
    }
}

/* extern */

struct player_state_s;
void baswim_entrypoint_11(struct player_state_s *arg0) {
    f32 _bafpctrl_entrypoint_3(struct player_state_s *);
    void baroll_setIdeal(struct player_state_s *, f32);
    f32 bastick_getX(struct player_state_s *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    f32 sp34;
    f32 sp30 = 4.3f;
    f32 sp2C = 45.0f;
    f32 sp28;

    sp28 = bastick_getX(arg0);
    yaw_setVelocityBounded(arg0, 250.0f, 20.0f);
    baroll_setIdeal(arg0, func_800F10B4(sp28, -1.0f, 1.0f, -sp2C, sp2C));
    sp34 = func_800F10B4(sp28, -1.0f, 1.0f, sp30, -sp30);
    sp34 *= _bafpctrl_entrypoint_3(arg0);
    yaw_setIdeal(arg0, yaw_getIdeal(arg0) + sp34);
}

/* extern */

f32 func_808003B8_baswim(void *self) {
    f32 func_800EEF94(f32*);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    void func_8009BB24(void *, f32 *);
    f32 sp24[3];

    func_8009BB24(self, sp24);
    return func_800F10B4(func_800EEF94(sp24), 50.0f, 200.0f, 0.0f, 1.0f);
}

/* extern */

void baswim_entrypoint_12(struct player_state_s *arg0) {
    f32 _bafpctrl_entrypoint_3(struct player_state_s *);
    f32 bastick_getY(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 sp2C;
    f32 temp_f0;
    f32 temp_f0_2;

    sp2C = func_800F1214(func_808003B8_baswim(arg0), 140.0f, 90.0f);
    temp_f0 = _bafpctrl_entrypoint_3(arg0);
    sp2C *= func_800F10B4(temp_f0, 0.1f, 1.0f, temp_f0 * temp_f0, 1.0f);
    func_8009BFE4(arg0, sp2C, 1.6f);
    temp_f0_2 = bastick_getY(arg0);
    if (temp_f0_2 < 0.0f) {
        func_8009BF5C(arg0, func_800F10B4(temp_f0_2, -1.0f, 0.0f, 275.0f, 360.0f));
        return;
    }
    func_8009BF5C(arg0, func_800F10B4(temp_f0_2, 0.0f, 1.0f, 0.0f, 85.0f));
}

/* extern */

void baswim_entrypoint_13(void *arg0) {
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(struct player_state_s *, f32 *);
    f32 func_8009BFCC(struct player_state_s *);
    f32 func_800D8FF8(void);
    void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
    f32 func_800F0E00(f32, f32);
    f32 yaw_get(struct player_state_s *);
    f32 sp44;
    f32 sp34[4];

    sp44 = func_8009BFCC(arg0);
    func_800EF4E4(sp34, sp44, yaw_get(arg0), 0.0f, 0.0f, *(f32 *)*(void **)((u8 *)arg0 + 0x134));
    *(f32 *)*(void **)((u8 *)arg0 + 0x134) = func_800F0E00(*(f32 *)*(void **)((u8 *)arg0 + 0x134) - ((f32 *)*(void **)((u8 *)arg0 + 0x134))[1] * func_800D8FF8(), 0.0f);
    func_8009B94C(arg0, sp34);
    func_8009BA9C(arg0, sp34);
}

f32 baswim_entrypoint_14(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 0);
}
