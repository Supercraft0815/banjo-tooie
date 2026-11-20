#include "common.h"
#include "overlays/ba/playerstate.h"
struct player_state_s;
#include "bs_script.h"
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

void func_800951B4(struct player_state_s *);     
void func_808000B0_bscrashout(struct player_state_s *self, s32 state) {
    void _basudie_entrypoint_1(struct player_state_s *);
    void _batimer_set(struct player_state_s *, s32, f32);
    void _ncbadie_entrypoint_3(struct player_state_s *, f32);
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void func_800951B4(struct player_state_s *);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    void func_800A0180(struct player_state_s *);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    void func_800A4DFC(struct player_state_s *, s32);
    f32 yaw_getIdeal(struct player_state_s *);

    self->unk15C.word = state;
    switch (state) {
        case 1:
            baanim_playForDuration_onceSmooth(self, 0x3E, 1.4f);
            func_8009FFD8(self, 1, 3, 3, 3);
            baphysics_set_target_yaw(self, yaw_getIdeal(self));
            baphysics_set_target_horizontal_velocity(self, self->unk16C);
            baphysics_set_horizontal_velocity(self, 100.0f, self->unk16C);
            break;
        case 2:
            func_800951B4(self);
            baanim_playForDuration_onceSmooth(self, 0xD2, 2.25f);
            break;
        case 3:
            func_800A0180(self);
            func_800A4DFC(self, 0xA);
            _ncbadie_entrypoint_3(func_800A4CA8(self), 30.0f);
            _basudie_entrypoint_1(self);
            _batimer_set(self, 0, 3.2f);
            break;
    }
}

void bscrashout_entrypoint_0(BtIntPtr arg0)
{
    func_8009BD88(BT_NATIVE_ONLY((void *)arg0));
    func_8008E95C(arg0);
    func_800951B4(arg0);
}

/* extern */

void bscrashout_entrypoint_1(void *arg0) {
    void _bamotor_entrypoint_1(void *arg0, f32 arg1, f32 arg2, f32 arg3);
    void func_8008E944(void *arg0);
    void func_8009514C(void *player);
    f32 func_80099A34();
    void func_8009D89C(void *arg0, f32 arg1);
    void func_808000B0_bscrashout(struct player_state_s *, s32);
    void yaw_applyIdeal(void *self);
    void yaw_setIdeal(void *self, f32 arg1);
    yaw_setIdeal(arg0, func_80099A34(BT_NATIVE_ONLY(arg0)));
    yaw_applyIdeal(arg0);
    func_8009D89C(arg0, 1.0f);
    _bamotor_entrypoint_1(arg0, 1.0f, 0.5f, 0.5f);
    func_8008E944(arg0);
    func_8009514C(arg0);
    (((PlayerState *)arg0)->unk15C.word) = 0;
    (((PlayerState *)arg0)->unk16C) = 600.0f;
    func_808000B0_bscrashout(arg0, 1);
}

void bscrashout_entrypoint_2(struct player_state_s *arg0) {
    void _basudie_entrypoint_0(struct player_state_s *);
    s32 _batimer_decrement(void *, s32);
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void bs_setState(void *self, s32 nextState);
    s32 func_800A1718(struct player_state_s *);
    f32 func_800D8FF8(void);
    s32 func_800F1574(f32 *, f32);
    s32 next_state;

    next_state = 0;
    func_800F1574(&arg0->unk16C, func_800D8FF8() * 300.0f);
    baphysics_set_target_horizontal_velocity(arg0, arg0->unk16C);
    switch (arg0->unk15C.word) {
        case 1:
            func_80800000_bscrashout(arg0);
            if (baanim_isAt(arg0, 0.2f) && !func_800A1718(arg0)) {
                func_808000B0_bscrashout(arg0, 3);
            }
            if (baanim_isStopped(arg0)) {
                func_808000B0_bscrashout(arg0, 2);
            }
            break;
        case 2:
            if (baanim_isStopped(arg0)) {
                next_state = 1;
            }
            break;
        case 3:
            func_80800000_bscrashout(arg0);
            if (_batimer_decrement(arg0, 0)) {
                _basudie_entrypoint_0(arg0);
            }
            break;
    }
    bs_setState(arg0, next_state);
}

BsScript bscrashout_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_808003D0_bscrashout[];
    return (BsScript)D_808003D0_bscrashout[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/crashout.data.s */
void _bscrashout_entrypoint_0();
void _bscrashout_entrypoint_1();
void _bscrashout_entrypoint_2();
void func_80099AA8();
BtIntPtr D_808003D0_bscrashout [4] BT_DATA(4, overlays_bs_crashout, 0x0) = { (BtIntPtr)_bscrashout_entrypoint_0, (BtIntPtr)_bscrashout_entrypoint_1, (BtIntPtr)_bscrashout_entrypoint_2, (BtIntPtr)func_80099AA8 };
