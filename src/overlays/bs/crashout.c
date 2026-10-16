#include "common.h"

struct player_state_s;

void func_80800000_bscrashout(struct player_state_s *self) {
    int baanim_isAt(struct player_state_s *, f32);
    f32 baanim_getTimer(struct player_state_s *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void _badust_entrypoint_9(struct player_state_s *);

    if (baanim_isAt(self, 0.3659f) != 0) {
        func_8009DB04(self, 0x417, 1.0f, 0x36B0);
    }
    if (baanim_isAt(self, 0.6862f) != 0) {
        func_8009DB04(self, 0x417, 0.8f, 0x4650);
        func_8009DB04(self, 0x427, 1.0f, 0x55F0);
    }
    if (baanim_getTimer(self) < 0.8f) {
        _badust_entrypoint_9(self);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crashout/func_808000B0_bscrashout.s")

void bscrashout_entrypoint_0(s32 arg0)
{
    func_8009BD88();
    func_8008E95C(arg0);
    func_800951B4(arg0);
}

/* extern */

void bscrashout_entrypoint_1(void *arg0) {
    s32 _bamotor_entrypoint_1(void *, f32, f32, f32);
    s32 func_8008E944(void *);
    s32 func_8009514C(void *);
    f32 func_80099A34();
    s32 func_8009D89C(void *, f32);
    s32 func_808000B0_bscrashout(void *, s32);
    s32 yaw_applyIdeal(void *);
    s32 yaw_setIdeal(void *, f32);
    yaw_setIdeal(arg0, func_80099A34());
    yaw_applyIdeal(arg0);
    func_8009D89C(arg0, 1.0f);
    _bamotor_entrypoint_1(arg0, 1.0f, 0.5f, 0.5f);
    func_8008E944(arg0);
    func_8009514C(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = 600.0f;
    func_808000B0_bscrashout(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/crashout/bscrashout_entrypoint_2.s")

s32 bscrashout_entrypoint_3(s32 arg0) {
    extern s32 D_808003D0_bscrashout[];
    return ((s32 *)&D_808003D0_bscrashout)[arg0];
}
