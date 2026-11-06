#include "common.h"

#ifdef BT_NATIVE
void basudie_entrypoint_0(s32 bt_a0)
#else
void basudie_entrypoint_0()
#endif
{
    func_80091EF0();
}

/* extern */

void basudie_entrypoint_1(void *arg0) {
    s32 func_800C0658();
    s32 func_800F8B64();
    s32 func_800F90F8(s32);
    s32 func_80101238(s32, s32);
    if (func_800F8B64() == 0) {
        func_80101238(0x9F, (*(s32 *)((s8 *)(arg0) + (0x184))));
        func_800F90F8(1);
        func_800C0658();
    }
}

/* extern */

void basudie_entrypoint_2(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void basudie_entrypoint_4(s32, f32, f32, f32, f32, f32);
    basudie_entrypoint_4(arg0, arg1, arg2, arg3, 30.0f, 3.5f);
}

/* extern */

void basudie_entrypoint_3(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    void basudie_entrypoint_4(s32, f32, f32, f32, f32, f32);
    basudie_entrypoint_4(arg0, arg1, arg2, arg3, arg4, 3.5f);
}

struct player_state_s;

void basudie_entrypoint_4(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    void _batimer_set(struct player_state_s *, s32, f32);
    void _ncbadie_entrypoint_3(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void func_8008E944(struct player_state_s *);
    void func_8009514C(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32 *);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    void func_800A0180(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_applyIdeal(struct player_state_s *);
    f32 func_800136E4(f32);
    void func_800A32C4(struct player_state_s *, f32[3]);
    int func_800A4C68(void *);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    void func_800A4DFC(struct player_state_s *, s32);
    s32 func_800C52F4(s32, s32);
    void func_800F1E6C(f32[3], f32[3], f32 *);
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    struct player_state_s *self = (struct player_state_s *)arg0;

    basudie_entrypoint_1(self);
    func_8009FFD8(self, 1, 1, 2, 3);
    func_8009C128(self, sp40);
    func_800A32C4(self, sp34);
    func_800F1E6C(sp34, sp40, &sp4C);
    yaw_setIdeal(self, func_800136E4(sp4C + 180.0f));
    yaw_applyIdeal(self);
    baphysics_set_target_horizontal_velocity(self, arg1);
    baphysics_set_target_yaw(self, sp4C);
    baphysics_set_horizontal_velocity(self, sp4C, baphysics_get_target_horizontal_velocity(self));
    baphysics_set_vertical_velocity(self, arg2);
    baphysics_set_gravity(self, arg3);
    func_8008E944(self);
    func_8009514C(self);
    func_800A4DFC(self, 0xA);
    func_800C52F4(func_800A4C68(self), 2);
    _ncbadie_entrypoint_3(func_800A4CA8(self), arg4);
    func_800A0180(self);
    _batimer_set(self, 9, arg5);
}

/* extern */

void basudie_entrypoint_5(u8 *arg0) {
    s32 _batimer_decrement(void *, s32);
    void func_8009D3A8(void *, s32);
    func_8009D3A8(arg0, 0);
    if (_batimer_decrement(arg0, 9) != 0) {
        basudie_entrypoint_0(arg0);
    }
}

/* extern */

void basudie_entrypoint_6(s32 arg0) {
    s32 baphysics_reset_gravity();
    s32 func_800951B4(s32);
    int func_800A4C68(void *);
    s32 func_800A4E30(s32);
    s32 func_800C53EC(s32, s32);
    baphysics_reset_gravity();
    func_800A4E30(arg0);
    func_800C53EC(func_800A4C68(arg0), 2);
    func_800951B4(arg0);
}

/* extern */

int basudie_entrypoint_7(struct player_state_s *arg0) {
    f32 _batimer_get(void *, s32);
    f32 func_80096364(struct player_state_s *);
    f32 func_800964DC(struct player_state_s *);
    s32 func_80096544(struct player_state_s *);
    f32 func_8009C150(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    f32 sp24;
    f32 sp20;

    sp24 = func_800964DC(arg0);
    sp20 = func_80096364(arg0);
    return _batimer_get(arg0, 9) != 0.0f
        && func_80096544(arg0) != 0
        && player_inWater(arg0) != 0
        && func_8009C150(arg0) < sp24 - 150.0f
        && sp24 - sp20 > 100.0f;
}

/* extern */

void basudie_entrypoint_8(s32 arg0) {
    s32 func_80091E6C();
    int func_800A4C68(void *);
    s32 func_800A4E30(s32);
    s32 func_800C53EC(s32, s32);
    func_80091E6C();
    func_800A4E30(arg0);
    func_800C53EC(func_800A4C68(arg0), 2);
}

void basudie_entrypoint_9(struct player_state_s *arg0, f32 arg1) {
    s32 _bashake_entrypoint_0(struct player_state_s *, s32, s32);
    void _batimer_set(struct player_state_s *, s32, f32);
    void _ncbadie_entrypoint_3(struct player_state_s *, f32);
    void func_8008E944(struct player_state_s *);
    s32 func_80091E48(s32, s32);
    void func_800A0180(struct player_state_s *);
    int func_800A4C68(void *);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    void func_800A4DFC(struct player_state_s *, s32);
    s32 func_800C52F4(s32, s32);
    func_80091E48(arg0, 0x20);
    basudie_entrypoint_1(arg0);
    func_8008E944(arg0);
    func_800A4DFC(arg0, 0xA);
    func_800C52F4(func_800A4C68(arg0), 2);
    _ncbadie_entrypoint_3(func_800A4CA8(arg0), arg1);
    func_800A0180(arg0);
    _batimer_set(arg0, 9, 3.6f);
    _bashake_entrypoint_0(arg0, 3, 2);
}

void basudie_entrypoint_10(u8 *arg0) {
    s32 _batimer_decrement(void *, s32);
    if (_batimer_decrement(arg0, 9) != 0) {
        basudie_entrypoint_0(arg0);
    }
}

void basudie_entrypoint_11(s32 arg0)
{
    func_8009E6EC();
    func_80099AA8(arg0);
}
/* extern */

void basudie_entrypoint_12(s32 arg0) {
    s32 baphysics_reset_terminal_velocity(s32);
    s32 baphysics_set_terminal_velocity(s32, s32);
    s32 player_inWater();
    if (player_inWater() != 0) {
        baphysics_set_terminal_velocity(arg0, 0xC37A0000);
        return;
    }
    baphysics_reset_terminal_velocity(arg0);
}
