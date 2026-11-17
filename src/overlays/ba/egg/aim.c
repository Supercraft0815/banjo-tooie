#include "common.h"

s32 baeggaim_entrypoint_0() 
{
    return 0x4;
}

f32 func_80800008_baeggaim(f32 arg0, f32 arg1, f32 arg2) { s32 func_800D8FEC(); f32 func_800F0DC0(f32, f32); f32 temp_f0; f32 var_f20; s32 var_s0; var_f20 = arg0;
    var_s0 = 0;
    if ((func_800D8FEC() * 5) > 0) {
        do {
            temp_f0 = func_800F0DC0((arg1 - var_f20) * 0.04f, arg2);
            var_s0 += 1;
            var_f20 += temp_f0;
        } while (var_s0 < (func_800D8FEC() * 5));
    }
    return var_f20;
}

void func_808000B4_baeggaim(struct player_state_s *arg0, f32 *arg1) { void _baeggcursor_entrypoint_10(void *arg0, f32 arg1, f32 arg2); void _baeggcursor_entrypoint_3(void *arg0, f32 *arg1, f32 *arg2); f32 bastick_getX(struct player_state_s *); f32 bastick_getY(struct player_state_s *); f32 func_80800008_baeggaim(f32, f32, f32); f32 sp24; f32 sp20; f32 temp_f0;
    _baeggcursor_entrypoint_3(arg0, arg1, arg1 + 1);
    sp24 = (bastick_getX(arg0) * 114.0f) + 114.0f + 38.0f;
    sp20 = (bastick_getY(arg0) * 85.5f) + 85.5f + 28.5f;
    arg1[0] = func_80800008_baeggaim(arg1[0], sp24, 7.4f);
    temp_f0 = func_80800008_baeggaim(arg1[1], sp20, 5.5f);
    arg1[1] = temp_f0;
    _baeggcursor_entrypoint_10(arg0, arg1[0], temp_f0);
}

void func_80800170_baeggaim(BtIntPtr arg0, f32 *arg1, f32 arg2) {
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 unused;
    f32 temp;
    f32 y;
    f32 x;
    f32 zero;

    zero = 0.0;
    y = 0.0f;
    x = 0.0f;
    temp = 78.0f - ((f32 *)arg0)[0];
    if (temp > zero) {
        x = temp;
    }
    temp = 226.0f - ((f32 *)arg0)[0];
    if (temp < zero) {
        x = temp;
    }
    temp = 61.0f - ((f32 *)arg0)[1];
    if (temp > zero) {
        y = temp;
    }
    temp = 167.0f - ((f32 *)arg0)[1];
    if (temp < zero) {
        y = temp;
    }
    arg1[0] = func_800F1344(x, 0.0f, 40.0f, zero, arg2);
    arg1[1] = func_800F1344(y, 0.0f, 32.5f, zero, arg2);
}

void func_80800264_baeggaim(struct player_state_s *arg0, BtIntPtr arg1) {
    f32 _bafpctrl_entrypoint_3(struct player_state_s *);
    f32 _bsdronelook_entrypoint_2(f32);
    void _ncba1p_entrypoint_7(struct player_state_s *, f32[3]);
    void _ncba1p_entrypoint_8(struct player_state_s *, f32[3]);
    int baflag_isTrue(struct player_state_s *, s32);
    struct player_state_s *func_800A4CA8(struct player_state_s *);
    f32 func_800D8FF8(void);
    void func_80800170_baeggaim(BtIntPtr, f32 *, f32);
    f32 speed;
    f32 dt;
    struct {
        f32 delta[2];
        f32 rotation[3];
    } vectors;
    struct player_state_s *player;

    player = func_800A4CA8(arg0);
    _ncba1p_entrypoint_8(player, vectors.rotation);
    speed = _bafpctrl_entrypoint_3(arg0) * 70.0f;
    func_80800170_baeggaim(arg1, vectors.delta, speed);
    dt = func_800D8FF8();
    vectors.rotation[1] += vectors.delta[0] * dt;
    if (!baflag_isTrue(arg0, 0x3A)) {
        vectors.rotation[0] += vectors.delta[1] * dt;
        vectors.rotation[0] = _bsdronelook_entrypoint_2(vectors.rotation[0]);
    }
    vectors.rotation[2] = 0.0f;
    _ncba1p_entrypoint_7(player, vectors.rotation);
}

void baeggaim_entrypoint_1(BtIntPtr arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x4);
    _baeggfire_entrypoint_4(arg0);
}

void baeggaim_entrypoint_2(BtIntPtr arg0)
{
    _baeggcursor_entrypoint_7(arg0,0x3);
    _baeggfire_entrypoint_5(arg0);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) baeggaim_entrypoint_3(struct player_state_s *arg0) {
    int bakey_held(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, int);
    s32 func_80094510(struct player_state_s *);
    void func_80094AB4(void *);
    s32 func_80094B14(struct player_state_s *);
    f32 sp28[2];
    s32 sp24;

    if (_bafpctrl_entrypoint_2(arg0) == 0) {
        func_80094AB4(arg0);
    }
    func_808000B4_baeggaim(arg0, sp28);
    if ((baflag_isTrue(arg0, 0x2E) == 0) && (_bafpctrl_entrypoint_1(arg0) == 0)) {
        func_80800264_baeggaim(arg0, (BtIntPtr)sp28);
    }
    sp24 = 0;
    if (func_80094510(arg0) == 7) {
        if (bakey_held(arg0, 1) != 0) {
            sp24 = 1;
        }
    } else if (bakey_pressed(arg0, 1) != 0) {
        sp24 = 1;
    }
    if ((sp24 != 0) && (_bafpctrl_entrypoint_2(arg0) == 0) && (func_80094B14(arg0) != 0)) {
        _baeggfire_entrypoint_7(arg0);
    }
    BT_NATIVE_ONLY(return) _baeggfire_entrypoint_6(arg0);
}
