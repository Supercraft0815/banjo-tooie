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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_3.s")

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

void baswim_entrypoint_6(Actor *arg0, u32 arg1) {
    u32* baswim_entrypoint_7(Actor*, u32, u32);
    baswim_entrypoint_7(arg0, arg1, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_7.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/swim/baswim_entrypoint_13.s")

f32 baswim_entrypoint_14(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 308) + 0);
}
