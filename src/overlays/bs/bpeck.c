#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_0.s")

typedef struct player_state_s PlayerState;

void func_80800168_bsbpeck(PlayerState *self) {
    s32 baflag_set(PlayerState *, s32);
    void func_8009DE38(PlayerState *, s32, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 rate = 1.0f;

    switch (((s32 *)self)[0x58]) {
        case 0:
            rate = 1.13f;
            break;
        case 1:
            rate = 1.1f;
            break;
        case 2:
            rate = 1.32f;
            break;
    }
    baflag_set(self, 5);
    func_8009DE38(self, 0x442C, rate);
    baphysics_set_vertical_velocity(self, 120.0f);
    ((s32 *)self)[0x58]++;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bpeck/bsbpeck_entrypoint_1.s")

/* extern */

void bsbpeck_entrypoint_2(s32 arg0) {
    s32 baflag_clear(s32, s32);
    void func_800C6DA0(s32);
    s32 baphysics_reset_gravity(s32);
    s32 func_8009E474(s32);
    s32 func_800A0CF4(s32, s32);
    baflag_clear(arg0, 0x2A);
    func_800C6DA0(0x46);
    func_8009E474(arg0);
    func_800A0CF4(arg0, 0);
    baphysics_reset_gravity(arg0);
}

s32 bsbpeck_entrypoint_3(s32 arg0) {
    extern s32 D_808004A0_bsbpeck[];
    return ((s32 *)&D_808004A0_bsbpeck)[arg0];
}
