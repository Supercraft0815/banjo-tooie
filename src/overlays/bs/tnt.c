#include "common.h"

struct anctrl_s;
enum asset_e;

void func_80800000_bstnt(void *arg0) {
    void func_8009DF94(void *, s32, f32, s32);
    func_8009DF94(arg0, 0x504, 1.0f, 0x7FFF);
}

void func_80800028_bstnt(s32 arg0) {
    s32 func_800C2FDC(u8 index);
    u8 index;

    index = *(u8 *)((s8 *)arg0 + 0x160);
    if (index != 0) {
        func_800C2FDC(index);
    }
    *(u8 *)((s8 *)arg0 + 0x160) = 0;
}

void func_80800060_bstnt(s32 arg0) 
{
}
void func_80800068_bstnt(void *arg0) {
    extern s32 D_80802230_bstnt;
    (*(s8 *)((s8 *)(arg0) + (0x160))) = func_8009D454(arg0, 0, &D_80802230_bstnt);
}

/* extern */

void func_8080009C_bstnt(void *arg0) {
    s32 func_800C2FDC(u8 index);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x160)));
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1);
    }
    (*(u8 *)((s8 *)(arg0) + (0x160))) = 0U;
}

/* extern */

void func_808000D4_bstnt(void *arg0, f32 arg1) {
    void _bapulse_entrypoint_3(void *, f32, f32);
    f32 _batimer_get(void *, s32);
    void _batimer_set(void *, s32, f32);
    void func_80092744(s32 *, s32);
    void func_80092750(void *, s32, s32, s32, s32);
    if (_batimer_get(arg0, 2) == 0.0f) {
        _bapulse_entrypoint_3(arg0, 0.0f, 0.15f);
        func_80092744(arg0, 1);
        func_80092750(arg0, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    _batimer_set(arg0, 2, arg1);
}

struct player_state_s;
void func_80800164_bstnt(struct player_state_s *arg0) {
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    f32 bastick_getZonePosition(struct player_state_s *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 600.0f));
}

/* extern */

struct player_state_s;

 s32 func_808001C8_bstnt(void *arg0, s32 arg1) {
    int bakey_pressed(struct player_state_s *, int);
    s32 bstnt_entrypoint_8(struct player_state_s *);

    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x107;
    }
    if (bstnt_entrypoint_8(arg0) != 0) {
        arg1 = 0x10E;
    }
    return arg1;
}

/* extern */

s32 func_80800218_bstnt(void *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(void *);
    s32 bainput_should_enter_first_person();
    int bakey_pressed(struct player_state_s *, int);
    s32 bstnt_entrypoint_8(struct player_state_s *);
    int player_isStable(void *);
    s32 var_s1;

    var_s1 = arg1;
    if (bainput_should_enter_first_person() != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x107;
    }
    if (bstnt_entrypoint_8(arg0) != 0) {
        var_s1 = 0x10E;
    }
    if (((*(u8 *)((s8 *)(arg0) + (0x168))) != 0) && (player_isStable(arg0) != 0)) {
        var_s1 = 0x10D;
    }
    return var_s1;
}

void func_808002AC_bstnt(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_8080223C_bstnt;
    extern s32 D_80802284_bstnt;
    func_800BBCB8((f32 *) arg1, NULL, 1.0f, 8, &D_8080223C_bstnt);
    func_800BBCB8((f32 *) arg1, NULL, 1.0f, 0xC, &D_80802284_bstnt);
}

void func_8080030C_bstnt(struct player_state_s *arg0, f32 *arg1) {
    s32 func_800B5BE4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA5BC(void *, f32, f32);
    void func_800BA8F8(void *, f32, f32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_808022CC_bstnt;
    f32 scale;
    f32 position[3];
    f32 rate;
    f32 angle;
    s32 emitter;
    s32 i;

    emitter = func_800B5BE4(8);
    func_800BABB8(emitter, arg1, NULL, 1.0f, &D_808022CC_bstnt);
    scale = 0.43f;
    func_800BA8F8((void *)emitter, scale, scale);
    rate = 19.0f / scale;
    func_800BA5BC((void *)emitter, rate, rate);
    for (i = 0; i != 360; i += 45) {
        angle = (f32)i;
        func_800EFA4C(position, 0.0f, angle, 480.0f);
        func_800BA994((u8 *)emitter, (s16)position[0], (s16)position[1], (s16)position[2],
                     (s16)position[0], (s16)position[1], (s16)position[2]);
        func_800BA22C(emitter, 1);
        func_800EFA4C(position, -45.0f, angle, 430.0f);
        func_800BA994((u8 *)emitter, (s16)position[0], (s16)position[1], (s16)position[2],
                     (s16)position[0], (s16)position[1], (s16)position[2]);
        func_800BA22C(emitter, 1);
    }
}

struct player_state_s;

void func_808004F8_bstnt(struct player_state_s *arg0, f32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 *func_800A4C48(struct player_state_s *);
    void func_800CA3F4(f32 *, f32 *, f32);
    extern s32 D_808022FC_bstnt;
    f32 sp24[3];

    func_800EE7F8(sp24, arg1);
    func_800CA3F4(func_800A4C48(arg0), sp24, 80.0f);
    func_800BBCB8(sp24, NULL, 1.0f, 1, &D_808022FC_bstnt);
}

void func_80800554_bstnt(struct player_state_s *arg0) {
    void func_8009C128(struct player_state_s *, f32[3]);
    f32 *func_800A4C48(struct player_state_s *);
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800CA3F4(f32 *, f32 *, f32);
    extern s32 D_80802328_bstnt;
    extern s32 D_808023C8_bstnt;
    f32 sp2C[3];
    s32 sp28;
    s32 temp_v0;

    func_8009C128(arg0, sp2C);
    func_800CA3F4(func_800A4C48(arg0), sp2C, 20.0f);
    temp_v0 = func_800B5BE4(8);
    sp28 = temp_v0;
    func_800BABB8(temp_v0, sp2C, NULL, 1.0f, &D_80802328_bstnt);
    func_800CA3F4(func_800A4C48(arg0), sp2C, 45.0f);
    func_800BABB8(sp28, sp2C, NULL, 1.0f, &D_808023C8_bstnt);
}

void func_808005F4_bstnt(struct player_state_s *arg0) {
    void func_8009C128(struct player_state_s *, f32[3]);
    s32 _bashake_entrypoint_0(struct player_state_s *, s32, s32);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    _bashake_entrypoint_0(arg0, 3, 2);
    func_8009DB04(arg0, 0x413, 1.0f, 0x7FFF);
    func_808004F8_bstnt(arg0, sp24);
    func_8080030C_bstnt(arg0, sp24);
    func_808002AC_bstnt((s32) arg0, (s32) sp24);
}

/* extern */

void func_80800668_bstnt(s32 arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_8009E474();
    func_8009E474();
    baflag_clear(arg0, 0x32);
}

void func_80800694_bstnt()
{
    func_8009E4AC();
}

/* extern */

void func_808006B4_bstnt(u8 *arg0, s32 arg1) {
    void baflag_set(void *, s32);
    void func_8009E55C(void *, s32, f32);
    (*(s8 *)((s8 *)(arg0) + (0x169))) = arg1;
    baflag_set(arg0, 0x32);
    func_8009E55C(arg0, 1, 200.0f);
}

/* extern */

void func_808006EC_bstnt(s32 arg0) {
    s32 baflag_clear(s32, s32);
    void func_8009E55C(void *, s32, f32);
    func_8009E55C(arg0, 1, 28.0f);
    baflag_clear(arg0, 0x32);
}

/* extern */

void func_80800720_bstnt(s32 arg0) {
    f32 func_800F0E00(f32, f32);
    (*(u8 *)((s8 *)(arg0) + (0x169))) = func_800F0E00((f32) ((*(u8 *)((s8 *)(arg0) + (0x169))) - 1), 0.0f);
    if (!(*(u8 *)((s8 *)(arg0) + (0x169)))) {
        func_808006EC_bstnt(arg0);
    }
}

s32 func_808007EC_bstnt(s32 arg0, s32 arg1) {
    void func_8009FFD8();
    void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baroll_setIdeal(s32, f32);
    f32 func_80092BE8(struct player_state_s *);
    void func_800931AC(struct player_state_s *, s32);
    void func_8009328C(struct player_state_s *, f32);
    void func_8009BC34(struct player_state_s *);
    void func_8009BF5C(s32, f32);
    void func_800A17A8(struct player_state_s *, s32);
    void yaw_applyIdeal(struct player_state_s *);
    f32 yaw_get(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    struct player_state_s *self = (struct player_state_s *)arg0;
    f32 yaw;

    *(s32 *)((s8 *)self + 0x15C) = arg1;
    switch (arg1) {
    case 1:
        baanim_playForDuration_onceSmooth(self, 0xE6, 1.5f);
        func_8009FFD8(self, 1, 1, 3, 2);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        func_808000D4_bstnt(self, 10.0f);
        break;
    case 2:
        func_808006B4_bstnt((void *)self, 10);
        func_808005F4_bstnt(self);
        func_800A17A8(self, -1);
        func_800931AC(self, 3);
        *(f32 *)((s8 *)self + 0x16C) = 800.0f;
        yaw = yaw_get(self);
        *(f32 *)((s8 *)self + 0x170) = yaw;
        func_8009328C(self, yaw);
        break;
    case 0:
        yaw_setIdeal(self, func_80092BE8(self));
        yaw_applyIdeal(self);
        func_800931AC(self, 1);
        func_808000D4_bstnt(self, 0.1f);
        func_8009BC34(self);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        break;
    }
}

/* extern */

void func_8080092C_bstnt(s32 arg0) {
    s32 func_808007EC_bstnt(s32, s32);
    func_80800668_bstnt(arg0);
    func_80800028_bstnt(arg0);
    func_808007EC_bstnt(arg0, 0);
}

/* extern */

void func_80800960_bstnt(s32 arg0) {
    s32 func_808007EC_bstnt(s32, s32);
    func_80800694_bstnt();
    func_80800060_bstnt(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_808007EC_bstnt(arg0, 1);
}

void func_80800998_bstnt(struct player_state_s *arg0) {
    f32 baanim_getTimer(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    s32 bs_setState(s32, s32);
    void bstnt_entrypoint_4(void *);
    f32 func_800136E4(f32);
    void func_8009328C(struct player_state_s *, f32);
    void func_8009D3A8(struct player_state_s *, s32);
    f32 func_800D8FF8(void);
    f32 func_800F0E00(f32, f32);
    s32 player_inWater(struct player_state_s *);
    s32 func_808007EC_bstnt(s32, s32);
    s32 next_state;
    f32 delta;
    f32 angle;

    next_state = 0;
    delta = func_800D8FF8();
    func_8009D3A8(arg0, 0);
    if (player_inWater(arg0)) {
        baphysics_set_gravity(arg0, -10.0f);
        baphysics_set_terminal_velocity(arg0, -20.0f);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 1:
        if (baanim_isAt(arg0, 0.15870000422000885f)) {
            func_80800068_bstnt(arg0);
        }
        if (baanim_isAt(arg0, 0.2770000100135803f)) {
            func_80800000_bstnt(arg0);
        }
        if (baanim_isAt(arg0, 0.4339999854564667f)) {
            func_808007EC_bstnt((s32)arg0, 2);
        }
        break;
    case 2:
        func_8080009C_bstnt(arg0);
        angle = func_800136E4(*(f32 *)((u8 *)arg0 + 0x16C) * delta +
                            *(f32 *)((u8 *)arg0 + 0x170));
        *(f32 *)((u8 *)arg0 + 0x170) = angle;
        func_8009328C(arg0, angle);
        if (baanim_getTimer(arg0) > 0.78f) {
            *(f32 *)((u8 *)arg0 + 0x16C) = func_800F0E00(0.0f,
                *(f32 *)((u8 *)arg0 + 0x16C) - 750.0f * delta);
        }
        if (baanim_isAt(arg0, 0.5f)) {
            func_80800554_bstnt(arg0);
        }
        if (*(f32 *)((u8 *)arg0 + 0x16C) == 0.0f) {
            next_state = 0x10C;
        }
        break;
    }
    func_80800720_bstnt((s32)arg0);
    bstnt_entrypoint_4(arg0);
    bs_setState((s32)arg0, next_state);
}

s32 bstnt_entrypoint_0(s32 arg0) {
    extern s32 D_808023F8_bstnt[];
    return ((s32 *)&D_808023F8_bstnt)[arg0];
}

void func_80800B60_bstnt(struct player_state_s *arg0, s32 arg1) {
    typedef struct player_state_s PlayerState;
    void _bamovegoto_entrypoint_0(void *);
    void _bamovegoto_entrypoint_12(void *, f32 *);
    void _bamovegoto_entrypoint_13(void *);
    void _bamovegoto_entrypoint_7(void *, f32);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8008F880(Unk80132ED0 *, f32 *);
    void func_8009C128(PlayerState *, f32 *);
    void func_8009FFD8();
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_80101038(f32 *);
    s32 func_8010114C(s32, s32, s32);
    void yaw_setIdeal(PlayerState *, f32);
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];

    *(s32 *)((u8 *)arg0 + 0x15C) = arg1;
    switch (arg1) {
        case 1:
            baanim_playForDuration_onceSmooth(arg0, 0xE2, 0.7f);
            func_8009FFD8(arg0, 1, 1, 3, 0);
            func_8010114C(*(s32 *)((u8 *)arg0 + 0x164), 6, 0);
            func_80101038(sp2C);
            func_8009C128(arg0, sp38);
            func_800F1E6C(sp38, sp2C, &sp44);
            yaw_setIdeal(arg0, sp44);
            _bamovegoto_entrypoint_0(arg0);
            _bamovegoto_entrypoint_12(arg0, sp2C);
            _bamovegoto_entrypoint_7(arg0, 0.7f);
            _bamovegoto_entrypoint_13(arg0);
            break;
        case 2:
            baanim_playForDuration_onceSmooth(arg0, 0xE3, 3.4f);
            func_8009FFD8(arg0, 1, 1, 3, 6);
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            func_8008F880(*(Unk80132ED0 **)((u8 *)arg0 + 0x164), sp2C);
            func_8009C128(arg0, sp38);
            func_800F1E6C(sp2C, sp38, &sp44);
            yaw_setIdeal(arg0, sp44);
            break;
    }
}

void func_800951B4(struct player_state_s *);

void func_80800CB0_bstnt(s32 arg0)
{
    func_80800028_bstnt(arg0);
    func_800951B4(arg0);
}
/* extern */

void func_80800CD8_bstnt(s32 arg0) {
    void func_80800B60_bstnt(struct player_state_s *, s32);
    func_80800060_bstnt(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_80800B60_bstnt(arg0, 1);
}

void func_80800D08_bstnt(struct player_state_s *arg0) {
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    s32 _bamovegoto_entrypoint_4();
    s32 bs_setState(s32, s32);
    void func_8009514C(struct player_state_s *);
    s32 func_8010114C(s32, s32, s32);
    void bstnt_entrypoint_4(void *);
    s32 next_state = 0;

    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
        case 1:
            if (_bamovegoto_entrypoint_4(arg0)) {
                func_80800B60_bstnt(arg0, 2);
            }
            break;
        case 2:
            if (baanim_isAt(arg0, 0.1183f)) {
                func_80800068_bstnt(arg0);
            }
            if (baanim_isAt(arg0, 0.592f)) {
                func_80800000_bstnt(arg0);
            }
            if (baanim_isAt(arg0, 0.65f)) {
                func_8009514C(arg0);
            }
            if (baanim_isAt(arg0, 0.665f)) {
                func_8010114C(*(s32 *)((u8 *)arg0 + 0x164), 5,
                    *(s32 *)((u8 *)arg0 + 0x184));
                func_8080009C_bstnt(arg0);
            }
            if (baanim_isAt(arg0, 0.85f)) {
                func_800951B4(arg0);
            }
            if (baanim_isStopped(arg0)) {
                next_state = 0x10C;
            }
            break;
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, next_state);
}

s32 bstnt_entrypoint_1(s32 arg0) {
    extern s32 D_80802408_bstnt[];
    return ((s32 *)&D_80802408_bstnt)[arg0];
}

void bstnt_entrypoint_2(void *arg0) {
    typedef struct player_state_s PlayerState;
    void baroll_resetAngularVelocity(PlayerState *);
    void bastick_popZone(PlayerState *);
    void func_80092744(s32 *, s32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_80095A40(PlayerState *);
    void func_8009C000(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 0xC) == 0) {
        func_800947EC(arg0, 1, 0);
        func_80092864(arg0, 1.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_popZone(arg0);
        func_80095A40(arg0);
        func_80092744(arg0, 0);
    }
}

void bstnt_entrypoint_3(void *arg0) {
    typedef struct player_state_s PlayerState;
    void _batimer_set(void *, s32, f32);
    void baroll_setAngularVelocity(PlayerState *, f32, f32);
    void bastick_pushZone(PlayerState *);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_800959C8(PlayerState *, f32, f32);
    void func_8009BFE4(PlayerState *, f32, f32);
    s32 func_8009E77C(PlayerState *, s32);
    if (func_8009E77C(arg0, 0xC) == 0) {
        *(s32 *)((u8 *)arg0 + 0x164) = 0;
        *(s8 *)((u8 *)arg0 + 0x168) = 0;
        *(s8 *)((u8 *)arg0 + 0x16A) = 0;
        _batimer_set(arg0, 2, 0.0f);
        func_80092864(arg0, 0.8999939f);
        func_8009BFE4(arg0, 1000.0f, 12.0f);
        baroll_setAngularVelocity(arg0, 1000.0f, 12.0f);
        bastick_pushZone(arg0);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800959C8(arg0, 85.0f, 38.0f);
        func_800947EC(arg0, 1, 1);
    }
}

/* extern */

void bstnt_entrypoint_4(void *arg0) {
    f32 _bapulse_entrypoint_1(void *);
    s32 _bapulse_entrypoint_2(void *);
    s32 _bapulse_entrypoint_4(void *);
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    void func_80092744(s32 *, s32);
    void func_80092750(void *, s32, s32, s32, s32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 temp_f8;

    if (_batimer_decrement(arg0, 2) != 0) {
        func_80092744(arg0, 0);
        _bapulse_entrypoint_2(arg0);
    } else if (_batimer_get(arg0, 2) > 0.0f) {
        _bapulse_entrypoint_4(arg0);
        temp_f8 = (s32) func_800F12D4(_bapulse_entrypoint_1(arg0), 0.0f, 1.0f, 0.0f, 255.0f);
        func_80092750(arg0, 0xFF, temp_f8, temp_f8, 0xFF);
    }
    (*(s8 *)((s8 *)(arg0) + (0x168))) = 0;
}

void func_80801058_bstnt(s32 arg0)
{
    _basudie_entrypoint_8();
    bstnt_entrypoint_2(arg0);
}
void func_80801080_bstnt(struct player_state_s *arg0) {
    s32 _basudie_entrypoint_9(struct player_state_s *, f32);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_8009D9D4(struct player_state_s *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802418_bstnt;
    extern s32 D_8080246C_bstnt;
    extern s32 D_808024B8_bstnt;
    extern s32 D_80802504_bstnt;
    f32 sp2C[3];

    bstnt_entrypoint_3(arg0);
    _basudie_entrypoint_9(arg0, 50.0f);
    func_80800554_bstnt(arg0);
    func_8009C128(arg0, sp2C);
    func_808004F8_bstnt(arg0, sp2C);
    func_8080030C_bstnt(arg0, sp2C);
    func_808002AC_bstnt((s32) arg0, (s32) sp2C);
    func_8009DB04(arg0, 0x693, 1.0f, 0x7FFF);
    func_8009D9D4(arg0);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_80802418_bstnt);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_8080246C_bstnt);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_808024B8_bstnt);
    func_800BBCB8(sp2C, NULL, 1.0f, 9, &D_80802504_bstnt);
}

void func_80801190_bstnt(s32 arg0)
{
    _basudie_entrypoint_10();
    bstnt_entrypoint_4(arg0);
}
s32 bstnt_entrypoint_5(s32 arg0) {
    extern s32 D_8080254C_bstnt[];
    return ((s32 *)&D_8080254C_bstnt)[arg0];
}

void func_808011CC_bstnt(s32 arg0)
{
    bstnt_entrypoint_3(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_808011F4_bstnt(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstnt_entrypoint_4(arg0);
}
void func_8080121C_bstnt(s32 arg0)
{
    bstnt_entrypoint_2(arg0);
    _bsdrone_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_6(s32 arg0) {
    extern s32 D_8080255C_bstnt[];
    return ((s32 *)&D_8080255C_bstnt)[arg0];
}

struct player_state_s;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);

void func_80801258_bstnt(void *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *control;

    bstnt_entrypoint_3(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setIndex(control, 0xE5);
    anctrl_setStart(control, 0.5036f);
    anctrl_setDuration(control, 0.7f);
    anctrl_setPlaybackType(control, 3);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

void func_808012F8_bstnt(struct player_state_s *arg0) {
    s32 _badrone_entrypoint_28(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setEnd(struct player_state_s *, f32);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int baflag_isTrue(struct player_state_s *, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009BB24(void *, f32 *);
    void func_8009D3A8(struct player_state_s *, s32);
    void func_800A2EAC(void *);
    s32 player_inWater(struct player_state_s *);
    int player_isStable(void *);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_8009D3A8(arg0, 0);
    func_80800164_bstnt(arg0);
    func_8009BB24(arg0, sp24);
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
        case 0:
            if (func_8008DF8C(arg0, 0x82) != 0) {
                baanim_setEnd(arg0, 0.6538f);
                *(s32 *)((u8 *)arg0 + 0x15C) = 1;
            }
            break;
        case 1:
            if (player_isStable(arg0) != 0) {
                func_800A2EAC(arg0);
                baphysics_set_target_horizontal_velocity(arg0, 0.0f);
                baanim_setEndAndDuration(arg0, 1, 1.0f);
                *(s32 *)((u8 *)arg0 + 0x15C) = 2;
            }
            break;
        case 2:
            break;
    }
    if (player_inWater(arg0) != 0) {
        sp34 = 0x111;
    }
    if ((player_isStable(arg0) != 0) &&
        ((bastick_getZone(arg0) > 0) ||
         ((*(s32 *)((u8 *)arg0 + 0x15C) == 2) && (anctrl_isStopped(sp30) != 0)))) {
        if (baflag_isTrue(arg0, 0x19) != 0) {
            sp34 = _badrone_entrypoint_28(arg0);
        } else {
            sp34 = 0x10C;
        }
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp34);
}

/* extern */

void func_80801464_bstnt(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_7(s32 arg0) {
    extern s32 D_8080256C_bstnt[];
    return ((s32 *)&D_8080256C_bstnt)[arg0];
}

/* extern */

s32 bstnt_entrypoint_8(struct player_state_s *arg0) {
    int bakey_pressed(struct player_state_s *, int);
    s32 func_800A1718(struct player_state_s *);
    void func_800FC660(u32);
    if (bakey_pressed(arg0, 9) == 0) {
        return 0;
    }
    if (func_800A1718(arg0) >= 2) {
        return 1;
    }
    func_800FC660(0xF);
    return 0;
}

void func_8080150C_bstnt(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void func_8009FFD8();
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 yaw_getIdeal(struct player_state_s *);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void func_8009D7A4(struct player_state_s *, f32, f32);
    struct anctrl_s *control;
    s32 pad;
    f32 yaw;

    bstnt_entrypoint_3(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0xE2);
    anctrl_setSubrange(control, 0.0f, 0.4008f);
    anctrl_setDuration(control, 1.0f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 3, 1, 6);
    yaw_setVelocityBounded(arg0, 1200.0f, 10.0f);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800164_bstnt(arg0);
    yaw = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, yaw, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 693.5f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_8009D7A4(arg0, 1.35f, 1.45f);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

void func_8080166C_bstnt(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 anctrl_isStopped(struct anctrl_s *);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    int bakey_pressed(struct player_state_s *, int);
    int bakey_released(struct player_state_s *, int);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_8009D3A8(struct player_state_s *, s32);
    int player_isStable(void *);
    s32 bs_setState(s32, s32);
    f32 func_8009BB5C(struct player_state_s *);
    void func_800A2EAC(void *);
    f32 baphysics_get_vertical_velocity(struct player_state_s *);
    s32 player_inWater(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    func_80800164_bstnt(arg0);
    if (bakey_released(arg0, 8) && baphysics_get_vertical_velocity(arg0) > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                0.7f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
        } else if (anctrl_isStopped(sp20)) {
            baanim_setEndAndDuration(arg0, 0.651f, 3.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (func_8008DF8C(arg0, 0x82)) {
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
        }
        break;
    case 2:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0)) {
            func_800A2EAC(arg0);
            baanim_setEndAndDuration(arg0,
                1.0f + 0.0f,
                1.0f);
            *(s32 *)((u8 *)arg0 + 0x15C) = 3;
        }
        break;
    case 3:
        baphysics_set_target_horizontal_velocity(arg0, func_8009BB5C(arg0) * 0.25f);
        func_8009D2D8(arg0, 3);
        func_8009D3A8(arg0, 0);
        if (anctrl_isStopped(sp20)) {
            if (func_8009BB5C(arg0) > 0.0f) {
                sp24 = 0x108;
            } else {
                sp24 = 0x10C;
            }
        }
        break;
    }
    if (baphysics_get_vertical_velocity(arg0) < 0.0f && player_inWater(arg0)) {
        sp24 = 0x111;
    }
    if (bstnt_entrypoint_8(arg0)) {
        sp24 = 0x10E;
    }
    if (player_isStable(arg0) && bakey_pressed(arg0, 8)) {
        sp24 = 0x107;
    }
    bstnt_entrypoint_4(arg0);
    bs_setState((s32)arg0, sp24);
}

void func_808018D0_bstnt(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_9(s32 arg0) {
    extern s32 D_8080257C_bstnt[];
    return ((s32 *)&D_8080257C_bstnt)[arg0];
}

/* extern */

void bstnt_entrypoint_10(void *arg0) {
    s32 func_80099A4C(void *);
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    if (func_8009E6EC() == 0x42) {
        (*(s32 *)((s8 *)(arg0) + (0x164))) = func_80099A4C(arg0);
        (*(s8 *)((s8 *)(arg0) + (0x168))) = 1;
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

void func_80801980_bstnt(struct player_state_s *arg0, u32 arg1) {
    void func_8009FFD8();
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_horizontal_velocity(struct player_state_s *, f32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    void baphysics_set_vertical_velocity(struct player_state_s *, f32);
    void baroll_setIdeal(s32, f32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    f32 func_8009BB5C(struct player_state_s *);
    void func_8009BF5C(s32, f32);
    void func_8009D2D8(struct player_state_s *, s32);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    struct anctrl_s *sp3C;
    f32 sp38;
    f32 sp34;
    f32 sp30;

    sp3C = baanim_getAnimCtrlPtr(arg0);
    *(u32 *)((u8 *)arg0 + 0x15C) = arg1;
    switch (arg1) {
    case 1:
        func_8009DB04(arg0, 0x3F0, func_800DC178(0.96f, 1.04f), 0x2710);
        func_800A2EEC(arg0, 4);
        func_8009FFD8(arg0, 1, 1, 1, 2);
        if (bastick_distance(arg0) != 0.0f) {
            yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
        }
        baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
        func_80800164_bstnt(arg0);
        baphysics_set_horizontal_velocity(arg0, yaw_getIdeal(arg0), baphysics_get_target_horizontal_velocity(arg0));
        sp38 = baphysics_get_target_horizontal_velocity(arg0);
        sp34 = func_800F10B4(sp38, 30.0f, 600.0f, 0.35f, 0.7f);
        sp30 = func_800F10B4(sp38, 30.0f, 600.0f, 346.75f, 693.5f);
        anctrl_reset(sp3C);
        anctrl_setIndex(sp3C, 0xE2);
        anctrl_setSubrange(sp3C, 0.0f, 0.4008f);
        anctrl_setDuration(sp3C, sp34);
        anctrl_setPlaybackType(sp3C, 1);
        anctrl_start(sp3C);
        baphysics_set_vertical_velocity(arg0, sp30);
        break;
    case 2:
        baanim_setEndAndDuration(arg0, 0.651f, 3.0f);
        break;
    case 3:
        baanim_setEndAndDuration(arg0, 0.93f, 0.7f);
        break;
    case 4:
        *(f32 *)((u8 *)arg0 + 0x16C) = func_8009BB5C(arg0) * 0.25f;
        func_8009D2D8(arg0, 3);
        baphysics_set_target_horizontal_velocity(arg0, *(f32 *)((u8 *)arg0 + 0x16C));
        func_800A2FCC(arg0, 0);
        baanim_setEndAndDuration(arg0, 0.93f, 0.7f);
        break;
    case 0:
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        break;
    }
}

void func_80801C0C_bstnt(s32 arg0) { bstnt_entrypoint_3(arg0); *(s32 *)((u8 *)arg0 + 0x15C) = 0; func_80801980_bstnt(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801C3C_bstnt.s")

void func_80801E20_bstnt(s32 arg0)
{
    func_80801980_bstnt(arg0,0);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_11(s32 arg0) {
    extern s32 D_8080258C_bstnt[];
    return ((s32 *)&D_8080258C_bstnt)[arg0];
}

void func_80801E60_bstnt(s32 arg0) { bstnt_entrypoint_3(arg0); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

void func_80801EA0_bstnt(struct player_state_s *arg0) {
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    s32 bs_setState(s32, s32);
    void func_800951B4(struct player_state_s *);
    s32 sp24;

    sp24 = 0;
    if (baanim_isAt(arg0, 0.5f) != 0) {
        func_800951B4(arg0);
    }
    if (_babounce_entrypoint_2(arg0) != 0) {
        func_80800164_bstnt(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp24 = 0x10C;
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp24);
}

void func_80801F20_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_12(s32 arg0) {
    extern s32 D_8080259C_bstnt[];
    return ((s32 *)&D_8080259C_bstnt)[arg0];
}

void func_80801F5C_bstnt(s32 arg0) { bstnt_entrypoint_3(arg0); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

void func_80801F9C_bstnt(struct player_state_s *arg0) {
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    s32 bs_setState(s32, s32);
    s32 sp24;
    struct player_state_s *self;

    self = arg0;
    sp24 = 0;
    if (_babounce_entrypoint_2(self) != 0) {
        func_80800164_bstnt(self);
    }
    if (_babounce_entrypoint_9(self) != 0) {
        sp24 = 0x10C;
    }
    bstnt_entrypoint_4(self);
    bs_setState(self, sp24);
}

void func_80802000_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_13(s32 arg0) {
    extern s32 D_808025AC_bstnt[];
    return ((s32 *)&D_808025AC_bstnt)[arg0];
}

void func_8080203C_bstnt(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstnt_entrypoint_2(arg0);
}
void func_80802064_bstnt(s32 arg0)
{
    bstnt_entrypoint_3(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_8080208C_bstnt(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp1C);
}

s32 bstnt_entrypoint_14(s32 arg0) {
    extern s32 D_808025BC_bstnt[];
    return ((s32 *)&D_808025BC_bstnt)[arg0];
}

void func_808020EC_bstnt(s32 arg0)
{
    bstnt_entrypoint_2(arg0);
    func_80090A2C(arg0);
}
void func_80802114_bstnt(void *arg0) {
    void *self;
    s32 baanim_playForDuration_loopSmooth(void *, s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    bstnt_entrypoint_3(self);
    baanim_playForDuration_loopSmooth(self, 0xE5, 0x40D00000);
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_8080217C_bstnt(struct player_state_s *arg0) {
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(s32, s32);
    s32 player_inWater(struct player_state_s *);
    s32 next_state;

    next_state = 0;
    if (bastick_getZone(arg0) > 0) {
        next_state = 0x108;
    }
    if (player_inWater(arg0) != 0) {
        next_state = 0x111;
    }
    next_state = func_80800218_bstnt(arg0, next_state);
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, next_state);
}

s32 bstnt_entrypoint_15(s32 arg0) {
    extern s32 D_808025CC_bstnt[];
    return ((s32 *)&D_808025CC_bstnt)[arg0];
}
