#include "common.h"

struct player_state_s;

/* extern */

void bsbee_entrypoint_0(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void _babee_entrypoint_3(PlayerState *);
    void baflag_clear(PlayerState *, s32);
    void baroll_setIdeal(PlayerState *, f32);
    void bastick_popZone(PlayerState *);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_80095A40(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    void func_8009E474(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A0CE8(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    if (func_8009E74C(arg0, 1) == 0) {
        func_800947EC(arg0, 1, 0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        bastick_popZone(arg0);
        func_800A0CF4(arg0, 0);
        func_800A0CE8(arg0, 0);
        baflag_clear(arg0, 3);
        baflag_clear(arg0, 4);
        func_8009E474(arg0);
        func_80095A40(arg0);
        _babee_entrypoint_3(arg0);
        func_80092864(arg0, 1.0f);
    }
}

/* extern */

void bsbee_entrypoint_1(struct player_state_s *arg0) {
    typedef struct player_state_s PlayerState;
    void _babee_entrypoint_4(PlayerState *);
    void baflag_set(PlayerState *, s32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009590C(PlayerState *, f32);
    void func_800959C8(PlayerState *, f32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    void func_8009E4AC(PlayerState *);
    void func_8009E55C(PlayerState *, s32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 1) == 0) {
        _babee_entrypoint_4(arg0);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        func_800959C8(arg0, 50.0f, 25.0f);
        baflag_set(arg0, 3);
        baflag_set(arg0, 4);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.03f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_8009E4AC(arg0);
        func_8009E55C(arg0, 0, 30.0f);
        func_8009E55C(arg0, 1, 40.0f);
        func_800959C8(arg0, 75.0f, 43.0f);
        func_8009590C(arg0, 75.0f);
        func_800947EC(arg0, 1, 1);
        func_80092864(arg0, 1.0999908447265625f);
    }
}

/* extern */

void bsbee_entrypoint_2(void) {
    s32 _babee_entrypoint_8();
    _babee_entrypoint_8();
}
