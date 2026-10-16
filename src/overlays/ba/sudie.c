#include "common.h"

void basudie_entrypoint_0()
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/sudie/basudie_entrypoint_4.s")

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
