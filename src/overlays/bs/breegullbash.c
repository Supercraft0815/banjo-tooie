#include "bs_script.h"
#include "common.h"
struct player_state_s;

/* extern */

void func_80800000_bsbreegullbash(struct player_state_s *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void _babackpack_entrypoint_5(void *self, BtIntPtr arg1, s32 arg2);
    void _badust_entrypoint_2(struct player_state_s *, f32 *, f32 *, f32, f32, f32);
    void func_800EFCD8(f32 *, f32, f32);
    f32 sp2C[3];
    f32 sp20[3];

    arg2 *= 0.51f;
    _babackpack_entrypoint_5(arg0, sp20, 2);
    sp20[1] -= 20.0f;
    func_800EFCD8(sp2C, arg1, arg2);
    sp2C[1] = arg3;
    _badust_entrypoint_2(arg0, sp20, sp2C, 0.1f, 0.8f, 0.7f);
}

/* extern */

void func_808000A4_bsbreegullbash(struct player_state_s *arg0) {
    f32 func_800136E4(f32);
    f32 var_f20;

    for (var_f20 = 0.0f; var_f20 < 359.0f; var_f20 += 60.0f) {
        func_80800000_bsbreegullbash(arg0, var_f20, 730.0f, 100.0f);
    }
    for (var_f20 = 0.0f; var_f20 < 359.0f; var_f20 += 60.0f) {
        func_80800000_bsbreegullbash(arg0, func_800136E4(var_f20 + 30.0f), 430.0f, 40.0f);
    }
}

void func_808001B4_bsbreegullbash(BtIntPtr arg0)
{
    _babackpack_set_state(arg0,0x7);
}

s32 func_808001D4_bsbreegullbash(BtIntPtr arg0) {
    void func_8009E4E0(void *, s32, BtIntPtr);
    void func_8009E55C(struct player_state_s *, s32, f32);
    if (_babackpack_get_state() != 1) {
        _babackpack_set_state(arg0, 1);
        func_8009E4E0(arg0, 2, 0);
        func_8009E55C(arg0, 2, 0.0f);
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void bsbreegullbash_entrypoint_0(BtIntPtr arg0) {
    void baflag_clear(void *self, s32 id);
    s32 func_8009E474();
    s32 func_808001D4_bsbreegullbash(BtIntPtr);
    func_8009E474();
    func_808001D4_bsbreegullbash(arg0);
    baflag_clear(arg0, 0x3E);
}

/* extern */

void bsbreegullbash_entrypoint_1(struct player_state_s *arg0) {
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E4E0(void *, s32, BtIntPtr);
    void func_8009E55C(struct player_state_s *, s32, f32);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    f32 yaw_getIdeal(struct player_state_s *);
    baanim_playForDuration_onceSmooth(arg0, 0x20, 1.75f);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_8009E4AC(arg0);
    func_8009E4E0(arg0, 2, 0);
    func_8009E55C(arg0, 2, 0.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
}

void bsbreegullbash_entrypoint_2(struct player_state_s *arg0) {
    void _babackpack_entrypoint_5(void *self, BtIntPtr arg1, s32 arg2);
    int _babackpack_get_state();
    void _bashake_entrypoint_0(struct player_state_s *arg0, s32 arg1, s32 arg2);
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    void baflag_clear(void *self, s32 id);
    void baflag_set(struct player_state_s *, s32);
    void bs_setState(void *self, s32 nextState);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009DFD4(struct player_state_s *, s32, f32, f32, s32, s32);
    void func_8009E4E0(void *, s32, BtIntPtr);
    void func_8009E55C(struct player_state_s *, s32, f32);
    void func_8009E5A4(struct player_state_s *, s32, s32);
    s32 player_inWater(struct player_state_s *);
    s32 next_state = 0;

    if (baanim_isAt(arg0, 0.22f) && _babackpack_get_state(arg0) == 7) {
        baflag_set(arg0, 0x3E);
        func_8009E55C(arg0, 2, 60.0f);
        func_8009E4E0(arg0, 2, _babackpack_entrypoint_5);
        func_8009E5A4(arg0, 2, 2);
    }
    if (baanim_isAt(arg0, 0.1188f)) {
        func_808001B4_bsbreegullbash(arg0);
    }
    if (baanim_isAt(arg0, 0.21f)) {
        func_8009DFD4(arg0, 0x4595, 1.0f, 1.1f, 0x55F0, 0x55F0);
    }
    if (baanim_isAt(arg0, 0.36f)) {
        func_8009DB04(arg0, 0x416, 1.0f, 0x55F0);
    }
    if (baanim_isAt(arg0, 0.37f)) {
        func_8009DFD4(arg0, 0x4596, 1.0f, 1.1f, 0x7FFF, 0x7FFF);
    }
    if (baanim_isAt(arg0, 0.6714f)) {
        func_8009DF18(arg0, 0x3EA, 1.0f, 0x55F0);
    }
    if (baanim_isAt(arg0, 0.335f)) {
        _bashake_entrypoint_0(arg0, 3, 2);
        func_8009E55C(arg0, 2, 180.0f);
        func_808000A4_bsbreegullbash(arg0);
    }
    if (baanim_isAt(arg0, 0.38f)) {
        func_8009E55C(arg0, 2, 0.0f);
        baflag_clear(arg0, 0x3E);
    }
    if (baanim_isAt(arg0, 0.8911f)) {
        func_808001D4_bsbreegullbash(arg0);
    }
    if (baanim_isStopped(arg0)) {
        next_state = 1;
    }
    if (player_inWater(arg0)) {
        next_state = 0x4C;
    }
    bs_setState(arg0, next_state);
}

BsScript bsbreegullbash_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80800560_bsbreegullbash[];
    return (BsScript)D_80800560_bsbreegullbash[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/breegullbash.data.s */
void _bsbreegullbash_entrypoint_0();
void _bsbreegullbash_entrypoint_1();
void _bsbreegullbash_entrypoint_2();
void func_80099B94();
BtIntPtr D_80800560_bsbreegullbash [4] BT_DATA(4, overlays_bs_breegullbash, 0x0) = { (BtIntPtr)_bsbreegullbash_entrypoint_0, (BtIntPtr)_bsbreegullbash_entrypoint_1, (BtIntPtr)_bsbreegullbash_entrypoint_2, (BtIntPtr)func_80099B94 };
