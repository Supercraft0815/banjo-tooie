#include "common.h"
#ifdef BT_NATIVE
#include "overlays/ba/anim_smooth.h"
#endif
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif
#include "bs_script.h"
BT_NATIVE_ONLY(struct player_state_s; void _babounce_entrypoint_3(struct player_state_s *); void _bsrest_entrypoint_14(struct player_state_s *); s32 _bsrest_entrypoint_20(struct player_state_s *);) struct anctrl_s;
enum asset_e;     
BT_NATIVE_ONLY(struct player_state_s; void baphysics_reset_gravity(struct player_state_s *);)
void func_80800000_bstnt(void *arg0) {
    void func_8009DF94(void *, s32, f32, s32);
    func_8009DF94(arg0, 0x504, 1.0f, 0x7FFF);
}                typedef struct { u8 pad0[0x15C]; s32 unk15C; u8 unk160; u8 pad161[0x3]; BtIntPtr unk164; s8 unk168; } Objtnt_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800028_bstnt(BtIntPtr arg0) {
    s32 func_800C2FDC(u8 index);
    u8 index;

    index = ((Objtnt_arg0 *)arg0)->unk160;
    if (index != 0) {
        func_800C2FDC(index);
    }
    ((Objtnt_arg0 *)arg0)->unk160 = 0;
}

void func_80800060_bstnt(BtIntPtr arg0) 
{
}
void func_80800068_bstnt(void *arg0) {
    BT_NATIVE_ONLY(struct player_state_s; s32 func_8009D454(struct player_state_s *, volatile u8, s32 *);) extern s32 D_80802230_bstnt[3];
    (*(s8 *)((s8 *)(arg0) + (0x160))) = func_8009D454(arg0, 0, D_80802230_bstnt);
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
    BT_NATIVE_ONLY(int bainput_should_enter_first_person(struct player_state_s *);) BT_IDO_ONLY(s32 bainput_should_enter_first_person();)
    int bakey_pressed(struct player_state_s *, int);
    s32 bstnt_entrypoint_8(struct player_state_s *);
    int player_isStable(void *);
    s32 var_s1;

    var_s1 = arg1;
    if (bainput_should_enter_first_person(BT_NATIVE_ONLY(arg0)) != 0) {
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

void func_808002AC_bstnt(BtIntPtr arg0, BtIntPtr arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_8080223C_bstnt[18];
    extern s32 D_80802284_bstnt[18];
    func_800BBCB8((f32 *) arg1, NULL, 1.0f, 8, D_8080223C_bstnt);
    func_800BBCB8((f32 *) arg1, NULL, 1.0f, 0xC, D_80802284_bstnt);
}

void func_8080030C_bstnt(struct player_state_s *arg0, f32 *arg1) {
    BtIntPtr func_800B5BE4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA5BC(void *, f32, f32);
    void func_800BA8F8(void *, f32, f32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_808022CC_bstnt[12];
    f32 scale;
    f32 position[3];
    f32 rate;
    f32 angle;
    BtIntPtr emitter;
    s32 i;

    emitter = func_800B5BE4(8);
    func_800BABB8(emitter, arg1, NULL, 1.0f, D_808022CC_bstnt);
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
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    f32 *func_800A4C48(struct player_state_s *);
    void func_800CA3F4(f32 *, f32 *, f32);
    extern s32 D_808022FC_bstnt[11];
    f32 sp24[3];

    func_800EE7F8(sp24, arg1);
    func_800CA3F4(func_800A4C48(arg0), sp24, 80.0f);
    func_800BBCB8(sp24, NULL, 1.0f, 1, D_808022FC_bstnt);
}

void func_80800554_bstnt(struct player_state_s *arg0) {
    void func_8009C128(struct player_state_s *, f32[3]);
    f32 *func_800A4C48(struct player_state_s *);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800CA3F4(f32 *, f32 *, f32);
    extern s32 D_80802328_bstnt[40];
    extern s32 D_808023C8_bstnt[12];
    f32 sp2C[3];
    BtIntPtr sp28;
    BtIntPtr temp_v0;

    func_8009C128(arg0, sp2C);
    func_800CA3F4(func_800A4C48(arg0), sp2C, 20.0f);
    temp_v0 = func_800B5BE4(8);
    sp28 = temp_v0;
    func_800BABB8(temp_v0, sp2C, NULL, 1.0f, D_80802328_bstnt);
    func_800CA3F4(func_800A4C48(arg0), sp2C, 45.0f);
    func_800BABB8(sp28, sp2C, NULL, 1.0f, D_808023C8_bstnt);
}

void func_808005F4_bstnt(struct player_state_s *arg0) {
    void func_8009C128(struct player_state_s *, f32[3]);
    void _bashake_entrypoint_0(struct player_state_s *arg0, s32 arg1, s32 arg2);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    _bashake_entrypoint_0(arg0, 3, 2);
    func_8009DB04(arg0, 0x413, 1.0f, 0x7FFF);
    func_808004F8_bstnt(arg0, sp24);
    func_8080030C_bstnt(arg0, sp24);
    func_808002AC_bstnt((BtIntPtr) arg0, (BtIntPtr) sp24);
}

/* extern */

void func_80800668_bstnt(BtIntPtr arg0) {
    void baflag_clear(void *self, s32 id);
    s32 func_8009E474();
    func_8009E474(BT_NATIVE_ONLY((void *)arg0));
    baflag_clear(arg0, 0x32);
}

void func_80800694_bstnt(BT_NATIVE_ONLY(BtIntPtr bt_a0))
{
    func_8009E4AC(BT_NATIVE_ONLY(bt_a0));
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

void func_808006EC_bstnt(BtIntPtr arg0) {
    void baflag_clear(void *self, s32 id);
    void func_8009E55C(void *, s32, f32);
    func_8009E55C(arg0, 1, 28.0f);
    baflag_clear(arg0, 0x32);
}

/* extern */

void func_80800720_bstnt(BtIntPtr arg0) {
    f32 func_800F0E00(f32, f32);
    (*(u8 *)((s8 *)(arg0) + (0x169))) = func_800F0E00((f32) ((*(u8 *)((s8 *)(arg0) + (0x169))) - 1), 0.0f);
    if (!(*(u8 *)((s8 *)(arg0) + (0x169)))) {
        func_808006EC_bstnt(arg0);
    }
}

s32 func_808007EC_bstnt(BtIntPtr arg0, s32 arg1) {
    void func_8009FFD8();
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(struct player_state_s *, s32, f32);)
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void baroll_setIdeal(BtIntPtr, f32);
    f32 func_80092BE8(struct player_state_s *);
    void func_800931AC(struct player_state_s *, s32);
    void func_8009328C(struct player_state_s *, f32);
    void func_8009BC34(struct player_state_s *);
    void func_8009BF5C(BtIntPtr, f32);
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
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_8080092C_bstnt(s32 arg0) {
    s32 func_808007EC_bstnt(BtIntPtr, s32);
    func_80800668_bstnt(arg0);
    func_80800028_bstnt(arg0);
    func_808007EC_bstnt(arg0, 0);
}

/* extern */

void func_80800960_bstnt(BtIntPtr arg0) {
    s32 func_808007EC_bstnt(BtIntPtr, s32);
    func_80800694_bstnt(BT_NATIVE_ONLY(arg0));
    func_80800060_bstnt(arg0);
    (((Objtnt_arg0 *)arg0)->unk15C) = 0;
    func_808007EC_bstnt(arg0, 1);
}

void func_80800998_bstnt(struct player_state_s *arg0) {
    f32 baanim_getTimer(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    s32 bs_setState(BtIntPtr, s32);
    void bstnt_entrypoint_4(void *);
    f32 func_800136E4(f32);
    void func_8009328C(struct player_state_s *, f32);
    void func_8009D3A8(struct player_state_s *, s32);
    f32 func_800D8FF8(void);
    f32 func_800F0E00(f32, f32);
    s32 player_inWater(struct player_state_s *);
    s32 func_808007EC_bstnt(BtIntPtr, s32);
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
            func_808007EC_bstnt((BtIntPtr)arg0, 2);
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
    func_80800720_bstnt((BtIntPtr)arg0);
    bstnt_entrypoint_4(arg0);
    bs_setState((BtIntPtr)arg0, next_state);
}

BsScript bstnt_entrypoint_0(BsScriptType arg0) {
    extern BtIntPtr D_808023F8_bstnt[];
    return (BsScript)D_808023F8_bstnt[arg0];
}

void func_80800B60_bstnt(struct player_state_s *arg0, s32 arg1) {
    typedef struct player_state_s PlayerState;
    void _bamovegoto_entrypoint_0(void *);
    void _bamovegoto_entrypoint_12(void *, f32 *);
    void _bamovegoto_entrypoint_13(void *);
    void _bamovegoto_entrypoint_7(void *, f32);
    BT_IDO_ONLY(void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);)
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8008F880(Unk80132ED0 *, f32 *);
    void func_8009C128(PlayerState *, f32 *);
    void func_8009FFD8();
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_80101038(f32 *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
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

void func_80800CB0_bstnt(BtIntPtr arg0)
{
    func_80800028_bstnt(arg0);
    func_800951B4(arg0);
}
/* extern */

void func_80800CD8_bstnt(BtIntPtr arg0) {
    void func_80800B60_bstnt(struct player_state_s *, s32);
    func_80800060_bstnt(arg0);
    (((Objtnt_arg0 *)arg0)->unk15C) = 0;
    func_80800B60_bstnt(arg0, 1);
}

void func_80800D08_bstnt(struct player_state_s *arg0) {
    int baanim_isAt(struct player_state_s *, f32);
    int baanim_isStopped(struct player_state_s *);
    s32 _bamovegoto_entrypoint_4();
    s32 bs_setState(BtIntPtr, s32);
    void func_8009514C(struct player_state_s *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
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

BsScript bstnt_entrypoint_1(BsScriptType arg0) {
    extern BtIntPtr D_80802408_bstnt[];
    return (BsScript)D_80802408_bstnt[arg0];
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
    void _bapulse_entrypoint_2(BtIntPtr arg0);
    void _bapulse_entrypoint_4(void *arg0);
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

void func_80801058_bstnt(BtIntPtr arg0)
{
    _basudie_entrypoint_8();
    bstnt_entrypoint_2(arg0);
}
void func_80801080_bstnt(struct player_state_s *arg0) {
    void _basudie_entrypoint_9(struct player_state_s *arg0, f32 arg1);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_8009D9D4(struct player_state_s *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802418_bstnt[21];
    extern s32 D_8080246C_bstnt[19];
    extern s32 D_808024B8_bstnt[19];
    extern s32 D_80802504_bstnt[18];
    f32 sp2C[3];

    bstnt_entrypoint_3(arg0);
    _basudie_entrypoint_9(arg0, 50.0f);
    func_80800554_bstnt(arg0);
    func_8009C128(arg0, sp2C);
    func_808004F8_bstnt(arg0, sp2C);
    func_8080030C_bstnt(arg0, sp2C);
    func_808002AC_bstnt((BtIntPtr) arg0, (BtIntPtr) sp2C);
    func_8009DB04(arg0, 0x693, 1.0f, 0x7FFF);
    func_8009D9D4(arg0);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, D_80802418_bstnt);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, D_8080246C_bstnt);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, D_808024B8_bstnt);
    func_800BBCB8(sp2C, NULL, 1.0f, 9, D_80802504_bstnt);
}

void func_80801190_bstnt(BtIntPtr arg0)
{
    _basudie_entrypoint_10(BT_NATIVE_ONLY((void *)arg0));
    bstnt_entrypoint_4(arg0);
}
BsScript bstnt_entrypoint_5(BsScriptType arg0) {
    extern BtIntPtr D_8080254C_bstnt[];
    return (BsScript)D_8080254C_bstnt[arg0];
}

void func_808011CC_bstnt(BtIntPtr arg0)
{
    bstnt_entrypoint_3(arg0);
    _bsdrone_entrypoint_0(arg0);
} BT_NATIVE_ONLY(struct player_state_s; void _bsdrone_entrypoint_1(struct player_state_s *);)
void func_808011F4_bstnt(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_1(BT_NATIVE_ONLY(arg0));
    bstnt_entrypoint_4(arg0);
}
void func_8080121C_bstnt(BtIntPtr arg0)
{
    bstnt_entrypoint_2(arg0);
    _bsdrone_entrypoint_2(arg0);
}
BsScript bstnt_entrypoint_6(BsScriptType arg0) {
    extern BtIntPtr D_8080255C_bstnt[];
    return (BsScript)D_8080255C_bstnt[arg0];
}

struct player_state_s;
enum baanim_update_type_e;
enum yaw_type_e;
enum ba_physics_type_e;
#ifndef BT_NATIVE
void func_8009FFD8(struct player_state_s *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
#endif

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
    ((Objtnt_arg0 *)arg0)->unk15C = 0;
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
    s32 bs_setState(BtIntPtr, s32);
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

void func_80801464_bstnt(BtIntPtr arg0) {
    void func_8009BF5C(BtIntPtr, f32);
    void baroll_setIdeal(BtIntPtr, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstnt_entrypoint_2(arg0);
}

BsScript bstnt_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_8080256C_bstnt[];
    return (BsScript)D_8080256C_bstnt[arg0];
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
    s32 bs_setState(BtIntPtr, s32);
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
    bs_setState((BtIntPtr)arg0, sp24);
}

void func_808018D0_bstnt(BtIntPtr arg0) {
    void func_8009BF5C(BtIntPtr, f32);
    void baroll_setIdeal(BtIntPtr, f32);
    baphysics_reset_gravity(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bstnt_entrypoint_2(arg0);
}

BsScript bstnt_entrypoint_9(BsScriptType arg0) {
    extern BtIntPtr D_8080257C_bstnt[];
    return (BsScript)D_8080257C_bstnt[arg0];
}

/* extern */

void bstnt_entrypoint_10(void *arg0) {
    BtIntPtr func_80099A4C(void *);
    void func_80099B94(void *arg0);
    s32 func_8009E6EC(BT_NATIVE_ONLY(struct player_state_s *));
    void func_8009E830(void *arg0, s32 arg1);
    if (func_8009E6EC(BT_NATIVE_ONLY(arg0)) == 0x42) {
        (((Objtnt_arg0 *)arg0)->unk164) = func_80099A4C(arg0);
        (((Objtnt_arg0 *)arg0)->unk168) = 1;
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
    void baroll_setIdeal(BtIntPtr, f32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    f32 func_8009BB5C(struct player_state_s *);
    void func_8009BF5C(BtIntPtr, f32);
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

void func_80801C0C_bstnt(BtIntPtr arg0) { bstnt_entrypoint_3(arg0); ((Objtnt_arg0 *)arg0)->unk15C = 0; func_80801980_bstnt(arg0, 1); }

void func_80801C3C_bstnt(struct player_state_s *arg0) {
    s32 anctrl_isStopped(struct anctrl_s *);
    int func_8008DF8C(struct player_state_s *, s32);
    void func_8009D3A8(struct player_state_s *, s32);
    int player_isStable(void *);
    s32 player_inWater(struct player_state_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8009BB24(void *, f32 *);
    s32 bs_setState(BtIntPtr, s32);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_80800164_bstnt(arg0);
    func_8009BB24(arg0, sp24);
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 1:
        if (func_8008DF8C(arg0, 0x82) != 0) {
            func_80801980_bstnt(arg0, 3);
        } else if (anctrl_isStopped(sp30) != 0) {
            func_80801980_bstnt(arg0, 2);
        }
        sp34 = func_808001C8_bstnt(arg0, 0);
        break;
    case 2:
        if (func_8008DF8C(arg0, 0x82) != 0) {
            func_80801980_bstnt(arg0, 3);
        }
        sp34 = func_808001C8_bstnt(arg0, 0);
        break;
    case 3:
        func_8009D3A8(arg0, 0);
        if (player_isStable(arg0) != 0) {
            func_80801980_bstnt(arg0, 4);
        }
        sp34 = func_808001C8_bstnt(arg0, 0);
        break;
    case 4:
        if (*(u8 *)((u8 *)arg0 + 0x168) != 0 && player_isStable(arg0) != 0) {
            sp34 = 0x10D;
        }
        func_8009D3A8(arg0, 0);
        if (anctrl_isStopped(sp30) != 0) {
            if (baphysics_get_target_horizontal_velocity(arg0) > 0.0f) {
                func_80801980_bstnt(arg0, 1);
            } else {
                sp34 = 0x10C;
            }
        } else {
            baphysics_set_target_horizontal_velocity(arg0, *(f32 *)((u8 *)arg0 + 0x16C));
        }
        sp34 = func_80800218_bstnt(arg0, sp34);
        break;
    }
    if (player_inWater(arg0) != 0) {
        sp34 = 0x111;
    }
    bstnt_entrypoint_4(arg0);
    bs_setState((BtIntPtr)arg0, sp34);
}

void func_80801E20_bstnt(BtIntPtr arg0)
{
    func_80801980_bstnt(arg0,0);
    bstnt_entrypoint_2(arg0);
}

BsScript bstnt_entrypoint_11(BsScriptType arg0) {
    extern BtIntPtr D_8080258C_bstnt[];
    return (BsScript)D_8080258C_bstnt[arg0];
}

void func_80801E60_bstnt(BtIntPtr arg0) { bstnt_entrypoint_3(arg0); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

void func_80801EA0_bstnt(struct player_state_s *arg0) {
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    int baanim_isAt(struct player_state_s *, f32);
    s32 bs_setState(BtIntPtr, s32);
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

void func_80801F20_bstnt(BtIntPtr arg0)
{
    _babounce_entrypoint_3(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    bstnt_entrypoint_2(arg0);
}
BsScript bstnt_entrypoint_12(BsScriptType arg0) {
    extern BtIntPtr D_8080259C_bstnt[];
    return (BsScript)D_8080259C_bstnt[arg0];
}

void func_80801F5C_bstnt(BtIntPtr arg0) { bstnt_entrypoint_3(arg0); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

void func_80801F9C_bstnt(struct player_state_s *arg0) {
    int _babounce_entrypoint_2(struct player_state_s *);
    s32 _babounce_entrypoint_9(struct player_state_s *);
    s32 bs_setState(BtIntPtr, s32);
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

void func_80802000_bstnt(BtIntPtr arg0)
{
    _babounce_entrypoint_3(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    bstnt_entrypoint_2(arg0);
}
BsScript bstnt_entrypoint_13(BsScriptType arg0) {
    extern BtIntPtr D_808025AC_bstnt[];
    return (BsScript)D_808025AC_bstnt[arg0];
}

void func_8080203C_bstnt(BtIntPtr arg0)
{
    _bsrest_entrypoint_14(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    bstnt_entrypoint_2(arg0);
}
void func_80802064_bstnt(BtIntPtr arg0)
{
    bstnt_entrypoint_3(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_8080208C_bstnt(BtIntPtr arg0) {
    s32 _bsrest_entrypoint_13(BtIntPtr);
    BT_IDO_ONLY(s32 _bsrest_entrypoint_20();)
    s32 bs_setState(BtIntPtr, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bstnt_entrypoint_4(arg0);
    bs_setState(arg0, sp1C);
}

BsScript bstnt_entrypoint_14(BsScriptType arg0) {
    extern BtIntPtr D_808025BC_bstnt[];
    return (BsScript)D_808025BC_bstnt[arg0];
}

void func_808020EC_bstnt(BtIntPtr arg0)
{
    bstnt_entrypoint_2(arg0);
    func_80090A2C(arg0);
}
void func_80802114_bstnt(void *arg0) {
    void *self;
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(void *, s32, s32);)
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    self = arg0;
    bstnt_entrypoint_3(self);
    baanim_playForDuration_loopSmooth(self, 0xE5, BT_IDO_ONLY(0x40D00000) BT_NATIVE_ONLY(6.5f));
    func_8009FFD8(self, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(self, 0.0f);
    func_800909CC(self);
}

void func_8080217C_bstnt(struct player_state_s *arg0) {
    s32 bastick_getZone(struct player_state_s *);
    s32 bs_setState(BtIntPtr, s32);
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

BsScript bstnt_entrypoint_15(BsScriptType arg0) {
    extern BtIntPtr D_808025CC_bstnt[];
    return (BsScript)D_808025CC_bstnt[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/tnt.data.s */
void _bstnt_entrypoint_10();
void _basudie_entrypoint_11();
void _bsdrone_entrypoint_3();
void func_80099AA8();
s32 D_80802230_bstnt[3] BT_DATA(4, overlays_bs_tnt, 0x0) = { 50724883, 84344849, 0 };
s32 D_8080223C_bstnt[18] BT_DATA(4, overlays_bs_tnt, 0xC) = { 1903074, 1833008, -78643156, -13106750, -13107000, 52429000, 1445888, 2555904, 13107200, 15728674, 2490406, 1835036, 1376256, 13369387, 21758387, 262323, 458754, 0 };
s32 D_80802284_bstnt[18] BT_DATA(4, overlays_bs_tnt, 0x54) = { 1903074, 1833008, -78643156, -26214150, -26214000, 26214800, 1445888, 2555904, 13107200, 15728674, 2490406, 1835036, 1376256, 13369387, 21758387, 262297, 458754, 0 };
s32 D_808022CC_bstnt[12] BT_DATA(4, overlays_bs_tnt, 0x9C) = { 1903068, 1572864, 256, 16777237, 25, 2154151, 1910243358, 2621480, 2228352, 8388864, 16777238, 268435456 };
s32 D_808022FC_bstnt[11] BT_DATA(4, overlays_bs_tnt, 0xCC) = { 1903062, 1376281, 4980758, 268435486, 1966110, 1638400, 34, 16777472, 67109888, 2818304, 16777216 };
s32 D_80802328_bstnt[40] BT_DATA(4, overlays_bs_tnt, 0xF8) = { 1903068, 2949080, 3342296, 2621540, 2621461, 1310822, 2154151, 1901068322, 16777600, 33555200, 1445888, 1572864, 196608, 43, 46924748, 2162688, 0, 720796, 2621440, -6553560, 282, 2162688, 90, 655460, 2621440, 6553640, 282, 2162688, 180, 655360, 2686876, 40, -6553318, 2162688, 270, 655360, 2621540, 40, 6553882, 0 };
s32 D_808023C8_bstnt[12] BT_DATA(4, overlays_bs_tnt, 0x198) = { 2162688, 120, 2819200, 75497516, -2621410, -2621400, 3932200, 720886, 720886, 655385, 656154, 0 };
BtIntPtr D_808023F8_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x1C8) = { (BtIntPtr)func_8080092C_bstnt, (BtIntPtr)func_80800960_bstnt, (BtIntPtr)func_80800998_bstnt, (BtIntPtr)_bstnt_entrypoint_10 };
BtIntPtr D_80802408_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x1D8) = { (BtIntPtr)func_80800CB0_bstnt, (BtIntPtr)func_80800CD8_bstnt, (BtIntPtr)func_80800D08_bstnt, (BtIntPtr)_bstnt_entrypoint_10 };
s32 D_80802418_bstnt[21] BT_DATA(4, overlays_bs_tnt, 0x1E8) = { 1902946, 1441794, 1376256, 11730974, 1966110, 3080104, 700, -5766809, 45875227, -98239964, 197643, 917504008, 15073561, 262297, 458756, 2818662, 40239142, 58982600, 900, 13107200, 0 };
s32 D_8080246C_bstnt[19] BT_DATA(4, overlays_bs_tnt, 0x23C) = { 1902947, 1441794, 1376256, 11730974, 1966110, 3080107, 650, -5570201, 42598427, -98239964, 524518, 18415620, 10027015, 262187, 40239718, 2491268, 13107200, 58982600, 0 };
s32 D_808024B8_bstnt[19] BT_DATA(4, overlays_bs_tnt, 0x288) = { 1902948, 1441794, 1376256, 11730974, 1966110, 3080112, 600, -5242521, 39321627, -98239964, 524518, 18415620, 10027015, 262187, 40239718, 2491268, 13107200, 58982600, 0 };
s32 D_80802504_bstnt[18] BT_DATA(4, overlays_bs_tnt, 0x2D4) = { 1902945, 720926, 3276880, 1966101, 179, 3080132, 200, -2621081, 26214427, -98239964, 262297, 458755, 2818560, 41943078, -13041864, -13107000, 13107400, 0 };
BtIntPtr D_8080254C_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x31C) = { (BtIntPtr)func_80801058_bstnt, (BtIntPtr)func_80801080_bstnt, (BtIntPtr)func_80801190_bstnt, (BtIntPtr)_basudie_entrypoint_11 };
BtIntPtr D_8080255C_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x32C) = { (BtIntPtr)func_8080121C_bstnt, (BtIntPtr)func_808011CC_bstnt, (BtIntPtr)func_808011F4_bstnt, (BtIntPtr)_bsdrone_entrypoint_3 };
BtIntPtr D_8080256C_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x33C) = { (BtIntPtr)func_80801464_bstnt, (BtIntPtr)func_80801258_bstnt, (BtIntPtr)func_808012F8_bstnt, (BtIntPtr)_bstnt_entrypoint_10 };
BtIntPtr D_8080257C_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x34C) = { (BtIntPtr)func_808018D0_bstnt, (BtIntPtr)func_8080150C_bstnt, (BtIntPtr)func_8080166C_bstnt, (BtIntPtr)_bstnt_entrypoint_10 };
BtIntPtr D_8080258C_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x35C) = { (BtIntPtr)func_80801E20_bstnt, (BtIntPtr)func_80801C0C_bstnt, (BtIntPtr)func_80801C3C_bstnt, (BtIntPtr)_bstnt_entrypoint_10 };
BtIntPtr D_8080259C_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x36C) = { (BtIntPtr)func_80801F20_bstnt, (BtIntPtr)func_80801E60_bstnt, (BtIntPtr)func_80801EA0_bstnt, (BtIntPtr)func_80099AA8 };
BtIntPtr D_808025AC_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x37C) = { (BtIntPtr)func_80802000_bstnt, (BtIntPtr)func_80801F5C_bstnt, (BtIntPtr)func_80801F9C_bstnt, (BtIntPtr)func_80099AA8 };
BtIntPtr D_808025BC_bstnt [4] BT_DATA(4, overlays_bs_tnt, 0x38C) = { (BtIntPtr)func_8080203C_bstnt, (BtIntPtr)func_80802064_bstnt, (BtIntPtr)func_8080208C_bstnt, (BtIntPtr)_bstnt_entrypoint_10 };
BtIntPtr D_808025CC_bstnt [5] BT_DATA(4, overlays_bs_tnt, 0x39C) = { (BtIntPtr)func_808020EC_bstnt, (BtIntPtr)func_80802114_bstnt, (BtIntPtr)func_8080217C_bstnt, (BtIntPtr)_bstnt_entrypoint_10, 0 };
