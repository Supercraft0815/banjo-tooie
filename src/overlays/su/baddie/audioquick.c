#include "common.h"

/* extern */

void subaddieaudioquick_entrypoint_0(u8 arg0, s32 arg1) { void func_800C32C4(u8, s32); void func_800C3418(u8, s32); if (arg1 != 0) { func_800C3418(arg0, 1); func_800C32C4(arg0, 0x40); } else { func_800C3418(arg0, 2); } }

u8 subaddieaudioquick_entrypoint_1(Actor *arg0, f32 *arg1) {
    typedef struct { u8 pad[0x70]; u32 unused : 31; u32 active : 1; } Flags;
    u8 func_800C4350(s32, f32 *, s32 *);
    extern s32 D_808001D0_subaddieaudioquick;
    u8 saved;
    s32 result;
    result = func_800C4350(0, arg1, &D_808001D0_subaddieaudioquick);
    saved = result;
    subaddieaudioquick_entrypoint_0(result, ((Flags *)arg0)->active);
    return saved;
}

/* extern */

void subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2) { void func_800C3BDC(u8); u8 func_800C4350(s32, f32[3], s32 *); u8 subaddieaudioquick_entrypoint_1(Actor *, f32 *); u8 sp1F; sp1F = subaddieaudioquick_entrypoint_1(arg0, arg1); func_800C4350(sp1F & 0xFF, arg1, arg2); func_800C3BDC(sp1F); }

/* extern */

s32 subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3) {
    s32 func_80101E14(Actor*, f32);
    void subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    if (func_80101E14(arg0, arg3) != 0) {
        subaddieaudioquick_entrypoint_2(arg0, arg1, arg2);
        return 1;
    }
    return 0;
}

/* extern */

s32 subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3) { s32 func_80101E14(Actor *, f32); f32 *var_s0 = arg3; f32 var_f0 = *arg3; f32 sentinel = -1.0f; goto check; loop: if (func_80101E14(arg0, var_f0) != 0) { subaddieaudioquick_entrypoint_2(arg0, arg1, arg2); return 1; } var_f0 = var_s0[1]; var_s0++; check: if (sentinel != var_f0) { goto loop; } return 0; }
