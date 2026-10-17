#include "common.h"

void bsdronefired_entrypoint_0()
{
    _babounce_entrypoint_3();
}

void bsdronefired_entrypoint_1(struct player_state_s *self) {
    void _badata_entrypoint_7();
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void yaw_applyIdeal(struct player_state_s *);
    f32 _badata_entrypoint_18(struct player_state_s *);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    f32 duration;
    s32 anim_id;
    s32 sfx_id;

    _badata_entrypoint_7(self, &anim_id, &duration);
    baanim_playForDuration_loopSmooth(self, anim_id, duration);
    _babounce_entrypoint_4(self, 2);
    yaw_setIdeal(self, yaw_getIdeal(self) + 180.0f);
    yaw_applyIdeal(self);
    switch (func_800A3274(self)) {
        case 1:
        case 10:
            sfx_id = 0x420;
            break;
        case 11:
            sfx_id = 0x598;
            break;
        case 13:
            sfx_id = 0x5A3;
            break;
        default:
            return;
    }
    func_8009DF18(self, sfx_id, _badata_entrypoint_18(self) + 1.0f, 0x6D60);
}

void bsdronefired_entrypoint_2()
{
    func_80099AA8();
}

/* extern */

void bsdronefired_entrypoint_3(s32 arg0) {
    s32 _babounce_entrypoint_10();
    s32 _badata_entrypoint_24(s32);
    s32 bs_setState(s32, s32);
    if (_babounce_entrypoint_10() != 0) {
        bs_setState(arg0, _badata_entrypoint_24(arg0));
    }
}
