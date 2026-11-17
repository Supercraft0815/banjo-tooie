#include "common.h"

struct player_state_s;

void bashake_entrypoint_0(struct player_state_s *arg0, s32 arg1, s32 arg2) {
    void _bamotor_entrypoint_1(struct player_state_s *, f32, f32, f32);
    void func_8009C128(struct player_state_s *, f32[3]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern f32 D_80800100_bashake[][3];
    extern f32 D_8080013C_bashake[][2];
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    func_800E1610(0, D_80800100_bashake[arg1][0], D_8080013C_bashake[arg2][0], sp24);
    _bamotor_entrypoint_1(arg0, D_80800100_bashake[arg1][1], D_80800100_bashake[arg1][2], D_8080013C_bashake[arg2][1]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) bashake_entrypoint_1(void *self, s32 arg1, s32 arg2) {
    void func_8009C128(struct player_state_s *, f32[3]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern f32 D_80800100_bashake[][3];
    extern f32 D_8080013C_bashake[][2];
    f32 sp1C[3];

    func_8009C128(self, sp1C);
    BT_NATIVE_ONLY(return) func_800E1610(0, D_80800100_bashake[arg1][0], D_8080013C_bashake[arg2][0], sp1C);
}
/* data_to_c.py: from asm/data/overlays/ba/shake.data.s */
f32 D_80800100_bashake [5] [ 3 ] BT_DATA(4, overlays_ba_shake, 0x0) = { { 5.0f, 0.4f, 0.3f }, { 15.0f, 0.65f, 0.35f }, { 25.0f, 0.85f, 0.45f }, { 45.0f, 1.0f, 0.7f }, { 60.0f, 1.0f, 0.8f } };
f32 D_8080013C_bashake [6] [ 2 ] BT_DATA(4, overlays_ba_shake, 0x3C) = { { 0.5f, 0.25f }, { 0.6f, 0.4f }, { 0.7f, 0.6f }, { 0.85f, 0.9f }, { 0.95f, 1.2f }, { 0.0f, 0.0f } };
