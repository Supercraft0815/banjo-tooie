#include "common.h"

/* extern */

void bschokedie_entrypoint_0(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void _basudie_entrypoint_1(PlayerState *);
    void _batimer_set(PlayerState *, s32, f32);
    void _ncbadie_entrypoint_3(PlayerState *, f32);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8008E944(PlayerState *);
    void func_80090A0C(PlayerState *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009FFD8(PlayerState *, s32, s32, s32, s32);
    void func_800A0180(PlayerState *);
    PlayerState *func_800A4CA8(PlayerState *);
    void func_800A4DFC(PlayerState *, s32);
    baanim_playForDuration_onceSmooth(arg0, 0xF0, 4.2f);
    func_8009FFD8(arg0, 1, 1, 2, 3);
    func_8009BA9C(arg0, 0);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A4DFC(arg0, 0xA);
    _ncbadie_entrypoint_3(func_800A4CA8(arg0), 30.0f);
    func_800A0180(arg0);
    _batimer_set(arg0, 0, 3.8f);
    func_8008E944(arg0);
    func_80090A0C(arg0);
    _basudie_entrypoint_1(arg0);
}

void bschokedie_entrypoint_1(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void _basudie_entrypoint_0(PlayerState *);
    s32 _batimer_decrement(void *, s32);
    int baanim_isAt(PlayerState *, f32);
    void func_80090A2C(PlayerState *);
    void func_8009514C(PlayerState *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009DF94(PlayerState *, s32, f32, s32);

    if (baanim_isAt(arg0, 0.4f) != 0) {
        func_80090A2C(arg0);
    }
    if (baanim_isAt(arg0, 0.58f) != 0) {
        func_8009514C(arg0);
    }
    if (baanim_isAt(arg0, 0.05f) != 0) {
        func_8009DF18(arg0, 0x574, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(arg0, 0.2f) != 0) {
        func_8009DF18(arg0, 0x575, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(arg0, 0.4f) != 0) {
        func_8009DF18(arg0, 0x576, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(arg0, 0.66f) != 0) {
        func_8009DF18(arg0, 0x577, 1.0f, 0x7FFF);
    }
    if (baanim_isAt(arg0, 0.5999f) != 0) {
        func_8009DF94(arg0, 0x417, 1.2f, 0x3E80);
    }
    if (baanim_isAt(arg0, 0.7891f) != 0) {
        func_8009DF94(arg0, 0x417, 0.9f, 0x4E20);
    }
    if (baanim_isAt(arg0, 0.9291f) != 0) {
        func_8009DF94(arg0, 0x417, 1.4f, 0x2328);
    }
    if (_batimer_decrement(arg0, 0) != 0) {
        _basudie_entrypoint_0(arg0);
    }
}

/* extern */

void bschokedie_entrypoint_2(BtIntPtr arg0) {
    void baroll_setIdeal(void *self, f32 arg1);
    s32 func_800951B4();
    void func_8009BF5C(void *arg0, f32 arg1);
    void func_800A4E30(void *arg0);
    func_800951B4();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800A4E30(arg0);
}

s32 bschokedie_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_808002B0_bschokedie[];
    return ((s32 *)&D_808002B0_bschokedie)[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/chokedie.data.s */
void _bschokedie_entrypoint_2();
void _bschokedie_entrypoint_0();
void _bschokedie_entrypoint_1();
void _basudie_entrypoint_11();
BtIntPtr D_808002B0_bschokedie [4] BT_DATA(4, overlays_bs_chokedie, 0x0) = { (BtIntPtr)_bschokedie_entrypoint_2, (BtIntPtr)_bschokedie_entrypoint_0, (BtIntPtr)_bschokedie_entrypoint_1, (BtIntPtr)_basudie_entrypoint_11 };
