#include "common.h"

s32 func_801125B0() 
{
    return 0x10;
}

void func_801125B8(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (0))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (4))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (8))) = 0.0f;
}

void func_801125D8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 8) = arg1;
}

f32 func_801125E8(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 12);
}

int func_801125F4(s32 arg0) {
    struct player_state_s;
    struct player_state_s *func_800F53D0(s32);
    s32 func_8009BAF4(void *);
    s32 func_8009D2E4(void *);
    void *sp1C;
    int sp18;
    int temp_v0_2;
    int temp_v1;
    int var_v0;

    sp1C = func_800F53D0(arg0);
    sp18 = func_8009D2E4(sp1C);
    temp_v1 = func_8009BAF4(sp1C);
    return sp18 == 1 && temp_v1 == 2;
}

void func_80112648(void *arg0) {
    f32 func_80013728(f32);
    f32 func_800EEFFC(void *);
    s32 func_800F5B0C(s32);
    f32 func_800F5CC0(s32);
    f32 func_800F5CEC(s32);
    void func_800F5D70(s32, f32 *);
    s32 func_80110840(s32 *);
    extern f32 D_80126580;
    f32 temp_f2;
    f32 sp30[3];
    s32 temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0 = func_80110840(arg0);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (0))) = func_80013728(func_800F5CC0(temp_v0) + 90.0f);
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x4C)));
    temp_f2 = (*(f32 *)((s8 *)(temp_v0_2) + (0)));
    if (temp_f2 > 90.0f) {
        (*(f32 *)((s8 *)(temp_v0_2) + (0))) = (f32) (180.0f - temp_f2);
    } else if (temp_f2 < -90.0f) {
        (*(f32 *)((s8 *)(temp_v0_2) + (0))) = (f32) (-180.0f - temp_f2);
    }
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (4))) = func_800F5CEC(temp_v0);
    func_800F5D70(temp_v0, sp30);
    if ((func_800EEFFC(sp30) < D_80126580) || (func_800F5B0C(temp_v0) != 0) || (func_801125F4(temp_v0) == 0)) {
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x4C)))) + (4))) = 0.0f;
    }
    temp_v0_3 = (*(void **)((s8 *)(arg0) + (0x4C)));
    (*(f32 *)((s8 *)(temp_v0_3) + (0xC))) = (*(f32 *)((s8 *)(temp_v0_3) + (8))) * ((*(f32 *)((s8 *)(temp_v0_3) + (4))) * -(*(f32 *)((s8 *)(temp_v0_3) + (0))));
}

f32 func_80112788(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 76) + 8);
}
