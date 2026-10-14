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

void bashake_entrypoint_1(void *self, s32 arg1, s32 arg2) {
    void func_8009C128(struct player_state_s *, f32[3]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern f32 D_80800100_bashake[][3];
    extern f32 D_8080013C_bashake[][2];
    f32 sp1C[3];

    func_8009C128(self, sp1C);
    func_800E1610(0, D_80800100_bashake[arg1][0], D_8080013C_bashake[arg2][0], sp1C);
}
