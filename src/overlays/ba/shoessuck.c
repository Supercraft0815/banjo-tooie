#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoessuck/bashoessuck_entrypoint_0.s")

void bashoessuck_entrypoint_1(s32 arg0, f32 arg1[3]) {
    s32 _gccubesearch_entrypoint_1(s32, f32[3]);
    void _gspropctrl_entrypoint_11(s32, f32[3]);
    void func_8009C128(s32, f32[3]);
    s32 temp_v0;

    func_8009C128(arg0, arg1);
    temp_v0 = _gccubesearch_entrypoint_1(0x16D, arg1);
    if (temp_v0 != 0) {
        _gspropctrl_entrypoint_11(temp_v0, arg1);
    }
}

void bashoessuck_entrypoint_2(struct player_state_s *arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    func_800932CC(arg0, 0);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800961AC(arg0, 1);
}

void bashoessuck_entrypoint_3(s32 arg0)
{
    func_800961AC(arg0,0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoessuck/bashoessuck_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/shoessuck/bashoessuck_entrypoint_5.s")
