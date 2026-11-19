#include "common.h"
#ifdef BT_NATIVE
#include "overlays/ba/anim_smooth.h"
#endif

void func_80800000_bsclimb(void *arg0, s32 arg1) {
    u32 func_80098634(void *arg0);
    void func_8009DF94(void *, s32, f32, s32);
    extern s32 D_808008C0_bsclimb[15];
    u8 *temp_t0;
    u8 *temp_v1;
    u32 offset;

    offset = func_80098634(arg0) * 5;
    offset *= 4;
    temp_v1 = offset + (u8 *)D_808008C0_bsclimb;
    temp_t0 = (u8 *)temp_v1 + (arg1 * 8);
    func_8009DF94(arg0, *(s16 *)((u8 *)temp_v1 - 0x12), *(f32 *)(temp_t0 - 0x10), *(s32 *)(temp_t0 - 0xC));
}

/* extern */

void func_8080005C_bsclimb(void *arg0) {
    struct player_state_s;
    f32 bastick_getY(struct player_state_s *);
    void func_8009B94C(u8 *, f32 *);
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    f32 sp2C[3];
    f32 sp28;
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = bastick_getY(arg0);
    sp28 = temp_f0;
    if (mlAbsF(temp_f0) < 0.03f) {
        var_f2 = 0.0f;
    } else {
        var_f2 = func_800F1344(sp28, 0.03f, 1.0f, 100.0f, 300.0f);
    }
    sp2C[0] = 0.0f;
    sp2C[1] = var_f2;
    sp2C[2] = 0.0f;
    func_8009B94C(arg0, sp2C);
}

struct player_state_s;
s32 func_808000E8_bsclimb(BtIntPtr arg0) {
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    s32 baphysics_set_type(void *, s32);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    int func_8008E0E8(struct player_state_s *);
    void func_800959C8(struct player_state_s *, f32, f32);
    void func_800961AC(struct player_state_s *, s32);
    u32 func_8009861C(void *);
    void func_8009BC5C(struct player_state_s *, f32);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_800A4DA4(struct player_state_s *, s32);
    void yaw_setUpdateType(void *self, s32 type);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);

    if (func_8009861C(arg0) == 2) {
        func_8009D2D8(arg0, 3);
    } else {
        func_8009D2D8(arg0, 6);
    }
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 500.0f, 15.0f);
    bastick_setZoneMax(arg0, 0, 0.03f);
    bastick_setZoneMax(arg0, 1, 1.0f);
    baphysics_set_type(arg0, 10);
    func_8009BC5C(arg0, 10.0f);
    func_800961AC(arg0, 5);
    func_800959C8(arg0, 80.0f, 10.0f);
    func_800A4DA4(arg0, 12);
    if (func_8008E0E8(arg0) != 0) {
        _bapackctrl_entrypoint_5(arg0, 4);
    } BT_NATIVE_ONLY(return 0;)
}

struct player_state_s;
void func_808001D0_bsclimb(struct player_state_s *arg0) {
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    s32 baphysics_set_type(void *, s32);
    void bastick_resetZones(struct player_state_s *);
    s32 func_8008CA4C(void *, s32);
    int func_8008E0E8(struct player_state_s *);
    void func_80095A40(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009E74C(struct player_state_s *, s32);
    void func_800A4E30(struct player_state_s *);

    if (func_8009E74C(arg0, 0xA) == 0) {
        func_800A4E30(arg0);
        bastick_resetZones(arg0);
        func_8008CA4C(arg0, 1);
        baphysics_set_type(arg0, 2);
        func_800961AC(arg0, 1);
        func_80095A40(arg0);
        if (func_8008E0E8(arg0) != 0) {
            _bapackctrl_entrypoint_5(arg0, 3);
        }
    }
}

/* extern */

void func_80800258_bsclimb(void *arg0, f32 arg1, f32 arg2) {
    f32 func_800DC0C0();
    (*(f32 *)((s8 *)(arg0) + (0x16C))) = (f32) ((func_800DC0C0() * arg2) + arg1);
}

/* extern */

struct player_state_s;

int func_80800298_bsclimb(struct player_state_s *arg0) {
    f32 func_8009BB0C(void *);
    f32 mlAbsF(f32);
    f32 yaw_get(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);

    return mlAbsF(func_8009BB0C(arg0)) > 0.0f
        || yaw_get(arg0) != yaw_getIdeal(arg0);
}

void bsclimb_entrypoint_0(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    s32 func_8008CA4C(void *, s32);
    void func_8008FE68(f32 *);
    void func_80098590(f32 **, f32 *);
    s32 func_8009E77C(struct player_state_s *, s32);
    void func_800C6DA0(s32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_applyIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 sp3C;
    f32 sp30[3];
    f32 sp24[3];

    func_8008FE68(sp30);
    func_80098590(arg0, sp24);
    if (func_8009E77C(arg0, 0xA) == 0) {
        func_800F1E6C(sp30, sp24, &sp3C);
        yaw_setIdeal(arg0, sp3C);
        yaw_applyIdeal(arg0);
    }
    func_800C6DA0(0x40);
    baanim_playForDuration_loopSmooth(arg0, 0xB2, BT_IDO_ONLY(0x4028F5C3) BT_NATIVE_ONLY(2.64f));
    func_8008CA4C(arg0, 1);
    func_808000E8_bsclimb(arg0);
    *(s32 *)(arg0 + 0x160) = 1;
    func_80800258_bsclimb(arg0, 1.0f, 0.5f);
    *(s32 *)(arg0 + 0x15C) = 0;
}

void bsclimb_entrypoint_1(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    void func_800956B8(struct player_state_s *);
    f32 func_800D8FF8(void);
    int bakey_pressed(struct player_state_s *, int);
    void bs_setState();
    s32 nextState;
    struct anctrl_s *anim;

    nextState = 0;
    anim = baanim_getAnimCtrlPtr(arg0);
    func_800956B8(arg0);
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
        case 0:
            *(f32 *)((u8 *)arg0 + 0x16C) -= func_800D8FF8();
            if (*(f32 *)((u8 *)arg0 + 0x16C) <= 0.0f) {
                baanim_playForDuration_onceSmooth(arg0, 0xB1, 2.96f);
                *(s32 *)((u8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (anctrl_isStopped(anim)) {
                baanim_playForDuration_loopSmooth(arg0, 0xB2, BT_IDO_ONLY(0x4028F5C3) BT_NATIVE_ONLY(2.64f));
                func_80800258_bsclimb(arg0, 3.0f, 4.0f);
                *(s32 *)((u8 *)arg0 + 0x15C) = 0;
            }
            break;
    }
    func_8080005C_bsclimb(arg0);
    if (func_80800298_bsclimb(arg0)) {
        nextState = 0x50;
    }
    if (bakey_pressed(arg0, 8)) {
        nextState = 5;
    }
    if (*(s32 *)((u8 *)arg0 + 0x160) == 0) {
        nextState = 1;
    }
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
    bs_setState(arg0, nextState);
}

void bsclimb_entrypoint_2(struct player_state_s *arg0)
{
    func_808001D0_bsclimb(arg0);
}

s32 bsclimb_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_808008FC_bsclimb[];
    return ((s32 *)&D_808008FC_bsclimb)[arg0];
}

void bsclimb_entrypoint_4(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    s32 func_8008CA4C(void *, s32);

    baanim_playForDuration_loopSmooth(arg0, 0xA, BT_IDO_ONLY(0x3F666666) BT_NATIVE_ONLY(0.9f));
    func_8008CA4C(arg0, 3);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 100.0f, 300.0f, 0.6f, 0.4f);
    func_808000E8_bsclimb(arg0);
}

void bsclimb_entrypoint_5(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_23(struct player_state_s *, f32 *);
    int baanim_isAt(struct player_state_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    f32 baphysics_get_vertical_velocity(struct player_state_s *);
    void func_800956B8(struct player_state_s *);
    f32 func_800985B8(f32 **);
    s32 func_800985C4(void *, f32 *);
    u32 func_80098640(void *);
    f32 func_8009864C(void *);
    f32 func_8009BB0C(void *);
    void func_8009C128(struct player_state_s *, f32[3]);
    void bs_setState();
    s32 nextState;
    f32 position[3];
    f32 destination[3];

    nextState = 0;
    func_800956B8(arg0);
    func_8080005C_bsclimb(arg0);
    if (baanim_isAt(arg0, 0.25f)) {
        func_80800000_bsclimb(arg0, 0);
    }
    if (baanim_isAt(arg0, 0.75f)) {
        func_80800000_bsclimb(arg0, 1);
    }
    if (!func_80800298_bsclimb(arg0) && baphysics_get_vertical_velocity(arg0) < 30.0f) {
        nextState = 0x4F;
    }
    func_8009C128(arg0, position);
    if (func_8009BB0C(arg0) < 0.0f && func_800985B8(arg0) == position[1]) {
        nextState = 1;
    }
    if (func_80098640(arg0) == 2 && func_8009BB0C(arg0) > 0.0f && func_8009864C(arg0) == position[1]) {
        if (func_800985C4(arg0, destination)) {
            nextState = _badrone_entrypoint_23(arg0, destination);
        } else {
            nextState = 0x51;
        }
    }
    if (bakey_pressed(arg0, 8)) {
        nextState = 5;
    }
    if (*(s32 *)((u8 *)arg0 + 0x160) == 0) {
        nextState = 1;
    }
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
    bs_setState(arg0, nextState);
}

void bsclimb_entrypoint_6(struct player_state_s *arg0)
{
    func_808001D0_bsclimb(arg0);
}

s32 bsclimb_entrypoint_7(s32 arg0) {
    extern BtIntPtr D_8080090C_bsclimb[];
    return ((s32 *)&D_8080090C_bsclimb)[arg0];
}

/* extern */

void bsclimb_entrypoint_8(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    s32 baphysics_set_type(void *, s32);
    s32 func_8008CA4C(void *, s32);
    s32 func_808000E8_bsclimb(BtIntPtr);
    baanim_playForDuration_loopSmooth(arg0, 0xB2, BT_IDO_ONLY(0x4028F5C3) BT_NATIVE_ONLY(2.64f));
    func_8008CA4C(arg0, 1);
    func_808000E8_bsclimb(arg0);
    baphysics_set_type(arg0, 7);
}

/* extern */

struct player_state_s;
enum bs_state_e;
#ifndef BT_NATIVE
void bs_setState(struct player_state_s *, enum bs_state_e);
#endif

void bsclimb_entrypoint_9(struct player_state_s *arg0) {
    s32 func_8009CC68();
    s32 var_a1;

    var_a1 = 0;
    if (func_8009CC68() == 0) {
        var_a1 = 0x4F;
    }
    bs_setState(arg0, var_a1);
}

void bsclimb_entrypoint_10(struct player_state_s *arg0)
{
    func_808001D0_bsclimb(arg0);
}

s32 bsclimb_entrypoint_11(s32 arg0) {
    extern BtIntPtr D_8080091C_bsclimb[];
    return ((s32 *)&D_8080091C_bsclimb)[arg0];
}

/* extern */

void bsclimb_entrypoint_12(struct player_state_s *arg0) {
    void func_80099B94(struct player_state_s *);
    s32 func_8009E6EC(struct player_state_s *);
    void func_8009E830(struct player_state_s *, s32);
    if (func_8009E6EC(arg0) == 0xC) {
        *(s32 *)((s8 *)arg0 + 0x160) = 1;
    } else {
        func_80099B94(arg0);
        return;
    }
    func_8009E830(arg0, 1);
    bs_setState(arg0, 0);
}
/* data_to_c.py: from asm/data/overlays/bs/climb.data.s */
void _bsclimb_entrypoint_2();
void _bsclimb_entrypoint_0();
void _bsclimb_entrypoint_1();
void _bsclimb_entrypoint_12();
void _bsclimb_entrypoint_6();
void _bsclimb_entrypoint_4();
void _bsclimb_entrypoint_5();
void _bsclimb_entrypoint_10();
void _bsclimb_entrypoint_8();
void _bsclimb_entrypoint_9();
s32 D_808008C0_bsclimb[15] BT_DATA(4, overlays_bs_climb, 0x0) = { 16778350, 1061494456, 16000, 1063172178, 16000, 33555565, 1066192077, 32000, 1067030938, 32000, 50332699, 1065353216, 10000, 1066192077, 10000 };
BtIntPtr D_808008FC_bsclimb [4] BT_DATA(4, overlays_bs_climb, 0x3C) = { (BtIntPtr)_bsclimb_entrypoint_2, (BtIntPtr)_bsclimb_entrypoint_0, (BtIntPtr)_bsclimb_entrypoint_1, (BtIntPtr)_bsclimb_entrypoint_12 };
BtIntPtr D_8080090C_bsclimb [4] BT_DATA(4, overlays_bs_climb, 0x4C) = { (BtIntPtr)_bsclimb_entrypoint_6, (BtIntPtr)_bsclimb_entrypoint_4, (BtIntPtr)_bsclimb_entrypoint_5, (BtIntPtr)_bsclimb_entrypoint_12 };
BtIntPtr D_8080091C_bsclimb [5] BT_DATA(4, overlays_bs_climb, 0x5C) = { (BtIntPtr)_bsclimb_entrypoint_10, (BtIntPtr)_bsclimb_entrypoint_8, (BtIntPtr)_bsclimb_entrypoint_9, (BtIntPtr)_bsclimb_entrypoint_12, 0 };
