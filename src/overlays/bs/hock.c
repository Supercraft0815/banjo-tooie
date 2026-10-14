#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_2.s")

s32 bsbshock_entrypoint_3(s32 arg0) {
    extern s32 D_80800870_bsbshock[];
    return ((s32 *)&D_80800870_bsbshock)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/hock/bsbshock_entrypoint_5.s")

/* extern */

struct player_state_s;

void bsbshock_entrypoint_6(struct player_state_s *arg0) {
    void baphysics_reset_gravity(struct player_state_s *);
    s32 bs_getNextState(void *);
    void func_80093300(void *, f32);
    void func_8009C1B4(void *, f32);
    void func_800A0CE8(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    if (bs_getNextState(arg0) != 0x11) {
        baphysics_reset_gravity(arg0);
    }
    func_800A0CE8(arg0, 0);
    func_800A0CF4(arg0, 0);
    func_80093300(arg0, 0.0f);
    func_8009C1B4(arg0, 87.0f);
}

s32 bsbshock_entrypoint_7(s32 arg0) {
    extern s32 D_80800880_bsbshock[];
    return ((s32 *)&D_80800880_bsbshock)[arg0];
}
