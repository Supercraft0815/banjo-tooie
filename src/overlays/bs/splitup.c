#include "common.h"

typedef struct player_state_s PlayerState;

/* extern */

void bssplitup_entrypoint_0(void *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009FFD8();
    void func_800A3410(PlayerState *, s32);
    func_800A3410(arg0, 0xA);
    _bapackctrl_entrypoint_5(arg0, 3);
    baanim_playForDuration_onceSmooth(arg0, 0xA2, 2.2f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    func_8009BA9C(arg0, 0);
}

/* extern */

void bssplitup_entrypoint_1(void *arg0) {
    s32 baanim_isStopped();
    s32 bs_setState(void *, s32);
    s32 func_800F457C(void *, s32);
    s32 func_800F54E4();
    s32 sp1C;

    sp1C = 0;
    if (baanim_isStopped() != 0) {
        sp1C = 1;
        if (func_800F54E4() != (*(s32 *)((s8 *)(arg0) + (0x184)))) {
            func_800F457C(arg0, 2);
        }
    }
    bs_setState(arg0, sp1C);
}

/* extern */

void bssplitup_entrypoint_2(s32 arg0) {
    void _sudialog_entrypoint_0(s32, s32);
    s32 _baduo_entrypoint_7(void *, s32);
    s32 bs_getNextState(void *);
    _baduo_entrypoint_7(arg0, 3);
    if (bs_getNextState(arg0) != 0x5A) {
        _sudialog_entrypoint_0(0x4F5, 0xC);
    }
}

s32 bssplitup_entrypoint_3(s32 arg0) {
    extern s32 D_80800700_bssplitup[];
    return ((s32 *)&D_80800700_bssplitup)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/splitup/func_8080012C_bssplitup.s")

/* extern */

void bssplitup_entrypoint_4(PlayerState *arg0) {
    void bastick_func_8009F258(PlayerState *);
    void func_80092778(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    s32 func_8080012C_bssplitup(PlayerState *, s32);
    func_800A3410(arg0, 0xB);
    func_800A38F0(arg0, 0, 0);
    func_80092778(arg0);
    bastick_func_8009F258(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_8080012C_bssplitup(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/splitup/bssplitup_entrypoint_5.s")

/* extern */

void bssplitup_entrypoint_6(void *arg0) {
    s32 _baduo_entrypoint_7(void *, s32);
    s32 func_800F8EE4(s32);
    _baduo_entrypoint_7(arg0, 3);
    func_800F8EE4((*(s32 *)((s8 *)(arg0) + (0x184))));
}

s32 bssplitup_entrypoint_7(s32 arg0) {
    extern s32 D_80800710_bssplitup[];
    return ((s32 *)&D_80800710_bssplitup)[arg0];
}

/* extern */

void bssplitup_entrypoint_8(void *arg0) {
    s32 _batimer_set(s32, s32, s32);
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009FFD8();
    baanim_playForDuration_loopSmooth(arg0, 0x6F, 5.5f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    func_8009BA9C(arg0, 0);
    _batimer_set(arg0, 0, 0x3DCCCCCD);
}

/* extern */

void bssplitup_entrypoint_9(u8 *arg0) {
    s32 _batimer_decrement(void *, s32);
    s32 bs_setState(void *, s32);
    s32 _baduo_entrypoint_16(u8 *);
    s32 var_a2;

    var_a2 = 0;
    arg0 = arg0;
    if (_batimer_decrement(arg0, 0) != 0) {
        _baduo_entrypoint_16(arg0);
        var_a2 = 0xB9;
    }
    bs_setState(arg0, var_a2);
}

void bssplitup_entrypoint_10(s32 arg0) 
{
}
s32 bssplitup_entrypoint_11(s32 arg0) {
    extern s32 D_80800720_bssplitup[];
    return ((s32 *)&D_80800720_bssplitup)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/splitup/bssplitup_entrypoint_12.s")

/* extern */

void bssplitup_entrypoint_13(s32 arg0) {
    s32 baanim_isStopped();
    s32 bs_setState(void *, s32);
    s32 sp1C;

    sp1C = 0;
    if (baanim_isStopped() != 0) {
        sp1C = 1;
    }
    bs_setState(arg0, sp1C);
}

void func_800A0CF4(PlayerState *, s32);
void bssplitup_entrypoint_14(s32 arg0)
{
    func_800A0CF4(arg0,0);
}

s32 bssplitup_entrypoint_15(s32 arg0) {
    extern s32 D_80800730_bssplitup[];
    return ((s32 *)&D_80800730_bssplitup)[arg0];
}

void bssplitup_entrypoint_16(void *arg0) {
    s32 baanim_playForDuration_once(void *, s32, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009FFD8();
    void func_800A0CF4(PlayerState *, s32);
    f32 yaw_get(PlayerState *);
    baanim_playForDuration_once(arg0, 0x292, 0.8f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    baphysics_set_horizontal_velocity(arg0, yaw_get(arg0), 800.0f);
    func_800A0CF4(arg0, 1);
    func_8009DF18(arg0, 0x3EA, 1.0f, 0x6D60);
}

void bssplitup_entrypoint_17(void *arg0) {
    s32 baanim_isStopped();
    s32 bs_setState(void *, s32);
    s32 next_state;
    s32 unused;

    next_state = 0;
    if (baanim_isStopped() != 0) {
        next_state = 1;
    }
    bs_setState(arg0, next_state);
}

void bssplitup_entrypoint_18(s32 arg0)
{
    func_800A0CF4(arg0,0);
}

s32 bssplitup_entrypoint_19(s32 arg0) {
    extern s32 D_80800740_bssplitup[];
    return ((s32 *)&D_80800740_bssplitup)[arg0];
}
