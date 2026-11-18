#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif

void func_80800000_bsbbilldrill(void *arg0) {
    *(u32 *)((u8 *)arg0 + 0x168) = 0;
}

void func_80800008_bsbbilldrill(void *arg0) {
    s32 func_8001210C(s32);
    void func_8009C128(void *, f32[3]);
    s8 func_800BF8E4(void);
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32 id,u32 *color);
    void func_800C8F64(s32, s32);
    extern s32 D_80800AB0_bsbbilldrill[][3];
    f32 sp24[3];

    if (func_800BF8E4() > 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x168))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (0x168))) = func_800C8A98();
            func_800C8E54((*(s32 *)((s8 *)(arg0) + (0x168))), 80.0f, 350.0f);
            func_800C8F64((*(s32 *)((s8 *)(arg0) + (0x168))), 0xB);
        }
        func_8009C128(arg0, sp24);
        sp24[1] -= 10.0f;
        func_800C8CB8((*(s32 *)((s8 *)(arg0) + (0x168))), sp24);
        func_800C8E84((*(s32 *)((s8 *)(arg0) + (0x168))), D_80800AB0_bsbbilldrill[func_8001210C(1)]);
    }
}    typedef struct { u8 pad0[0x168]; s32 unk168; } Objbbilldrill_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_808000C0_bsbbilldrill(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (((Objbbilldrill_arg0 *)arg0)->unk168);
    if (temp_a3 != 0) {
        (((Objbbilldrill_arg0 *)arg0)->unk168) = _chlightfader_entrypoint_1(temp_a3, 0.6f, 2);
    }
}

/* extern */

void func_80800100_bsbbilldrill(void *arg0) {
    f32 func_80092BF4(void *);
    void func_80093300(void *, f32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_80092BF4(arg0);
    var_f2 = temp_f0;
    if (temp_f0 == 0.0f) {
        var_f2 = 8.0f;
    }
    var_f2 = -var_f2;
    func_80093300(arg0, var_f2);
}

BtIntPtr func_80800158_bsbbilldrill(f32 arg0[3]) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800AC8_bsbbilldrill[18];
    return func_800BABB8(func_800B5BE4(9), arg0, NULL, 1.0f, D_80800AC8_bsbbilldrill);
}

void func_8080019C_bsbbilldrill(void *arg0) {
    void func_8009C128(void *, f32[3]);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    f32 func_800DC0C0(void);
    f32 position[3];
    f32 scale;
    BtIntPtr emitter;

    if (func_800DC0C0() <= 0.2f) {
        scale = 0.15f;
    } else {
        scale = 0.09f;
    }
    func_8009C128(arg0, position);
    position[1] -= 80.0f;
    emitter = func_80800158_bsbbilldrill(position);
    func_800BA7C4((void *)emitter, scale, scale);
    func_800BA7FC((void *)emitter, scale, scale);
    func_800BA22C(emitter, 2);
}

/* extern */

void func_80800250_bsbbilldrill(void *arg0) {
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr _fxdlsmoke_entrypoint_0(f32 *);
    void func_8009C128(void *, f32[3]);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    sp1C[1] -= 80.0f;
    func_800BA22C(_fxdlsmoke_entrypoint_0(sp1C), 1);
}

/* extern */

struct player_state_s;

void func_80800298_bsbbilldrill(struct player_state_s *arg0) {
    s32 _bswalk_entrypoint_1();
    f32 baphysics_get_target_horizontal_velocity(struct player_state_s *);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    _bswalk_entrypoint_1();
    baphysics_set_target_horizontal_velocity(arg0, baphysics_get_target_horizontal_velocity(arg0) * 0.1f);
}

void func_808002DC_bsbbilldrill(void *arg0, s32 arg1) {
    typedef struct player_state_s PlayerState;
    void _badust_entrypoint_10(PlayerState *, f32);
    void _bamotor_entrypoint_3(PlayerState *, f32, f32, f32, f32, f32, f32);
    void _bashake_entrypoint_1(PlayerState *, s32, s32);
    void _batimer_set(PlayerState *, s32, f32);
    void baanim_setEndAndDuration(PlayerState *, f32, f32);
    void baflag_clear(PlayerState *, int);
    void baflag_set(PlayerState *, s32);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_terminal_velocity(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    s32 func_8009328C(u8 *, f32);
    f32 func_800962D4(void *);
    void func_80098520(void *, f32);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009C1F8(void *, f32 *);
    s32 func_8009D454(PlayerState *, volatile u8, s32 *);
    void func_8009DE38(PlayerState *, s32, f32);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009E53C(PlayerState *, s32, f32);
    s32 func_8009EA2C(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 yaw_get(PlayerState *);
    extern s32 D_80800B10_bsbbilldrill[];
    extern s32 D_80800B30_bsbbilldrill[];
    extern s32 D_80800B50_bsbbilldrill[];
    f32 sp34[3];

    *((s8 *)arg0 + 0x15C) = arg1;
    switch (arg1) {
    case 1:
        *(f32 *)((u8 *)arg0 + 0x16C) = yaw_get(arg0);
        *(f32 *)((u8 *)arg0 + 0x170) = 0;
        func_80098520(arg0, 0);
        _batimer_set(arg0, 0, 0.3f);
        if (func_8009EA2C()) {
            *((s8 *)arg0 + 0x164) = func_8009D454(arg0, 0, D_80800B30_bsbbilldrill);
        } else {
            *((s8 *)arg0 + 0x164) = func_8009D454(arg0, 0, D_80800B10_bsbbilldrill);
        }
        *((s8 *)arg0 + 0x15D) = 0;
        break;
    case 2:
        *(f32 *)((u8 *)arg0 + 0x170) = 1500.0f;
        func_80098520(arg0, 1.0f);
        _batimer_set(arg0, 0, 0.15f);
        break;
    case 3:
        func_8009DF18(arg0, 0x442F, 1.2f, 30000);
        baphysics_set_terminal_velocity(arg0, -5000.0f);
        baphysics_set_gravity(arg0, -20000.0f);
        baphysics_set_vertical_velocity(arg0, 2300.0f);
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        func_8009E53C(arg0, 1, -100.0f);
        break;
    case 4:
        func_800EFA4C(sp34, 0.0f, 80.0f - func_800962D4(arg0), 0.0f);
        func_8009C1F8(arg0, sp34);
        _badust_entrypoint_10(arg0, -func_800962D4(arg0));
        baflag_set(arg0, 0x26);
        baphysics_set_gravity(arg0, 0.0f);
        func_8009BA9C(arg0, 0);
        _batimer_set(arg0, 0, 0.8f);
        _bamotor_entrypoint_3(arg0, 1.0f, 0.7, 0.01f, 0.1f, 0.7f, 0.4f);
        _bashake_entrypoint_1(arg0, 3, 2);
        *((s8 *)arg0 + 0x160) = func_8009D454(arg0, 0, D_80800B50_bsbbilldrill);
        func_8009DE38(arg0, 0x40D, 1.0f);
        break;
    case 5:
        func_8009E53C(arg0, 1, 0.0f);
        baflag_clear(arg0, 0x22);
        func_8009328C(arg0, yaw_get(arg0));
        baphysics_set_vertical_velocity(arg0, 730.0f);
        baphysics_set_gravity(arg0, -2400.0f);
        baanim_setEndAndDuration(arg0, 0.7299f, 2.1f);
        func_808000C0_bsbbilldrill(arg0);
        break;
    }
}

/* extern */

void func_808005C0_bsbbilldrill(u8 *arg0) {
    f32 func_800D8FF8(void);
    s32 func_8009328C(u8 *, f32);
    f32 delta = func_800D8FF8();
    f32 *velocity = (f32 *) (arg0 + 0x170);
    f32 *position = (f32 *) (arg0 + 0x16C);
    *position += *velocity * delta;
    func_8009328C(arg0, *position);
}

/* extern */

void bsbbilldrill_entrypoint_0(void *arg0) {
    typedef struct player_state_s PlayerState;
    void baflag_clear(PlayerState *, int);
    void baphysics_reset_gravity(PlayerState *);
    void baphysics_reset_terminal_velocity(PlayerState *);
    void func_800931AC(PlayerState *, s32);
    void func_80093300(void *, f32);
    void func_80098520(void *, f32);
    void func_8009E474(PlayerState *);
    void func_800A0CF4(PlayerState *, s32);
    func_800931AC(arg0, 1);
    func_80093300(arg0, 0.0f);
    func_80098520(arg0, 1.0f);
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
    func_800A0CF4(arg0, 0);
    baflag_clear(arg0, 0x22);
    baflag_clear(arg0, 0x26);
    func_8009E474(arg0);
    func_808000C0_bsbbilldrill(arg0);
}

void bsbbilldrill_entrypoint_1(void *arg0) {
    struct anctrl_s;
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baflag_clear(struct player_state_s *, int);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_800931AC(struct player_state_s *, s32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    void func_808002DC_bsbbilldrill(void *, s32);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0x61);
    anctrl_setDuration(control, 1.02f);
    anctrl_setStart(control, 0.3637f);
    anctrl_setSubrange(control, 0.0f, 0.4546f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    baphysics_set_gravity(arg0, 0.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A0CF4(arg0, 1);
    baflag_clear(arg0, 0x22);
    baflag_clear(arg0, 0x26);
    func_800931AC(arg0, 3);
    func_8009E4AC(arg0);
    ((u8 *)arg0)[0x164] = 0;
    ((u8 *)arg0)[0x160] = 0;
    ((u8 *)arg0)[0x15C] = 0;
    func_808002DC_bsbbilldrill(arg0, 1);
    func_80800000_bsbbilldrill(arg0);
}

void bsbbilldrill_entrypoint_2(struct player_state_s *arg0) {
    s32 _batimer_decrement(void *, s32);
    f32 _batimer_get(void *, s32);
    s32 _bswalk_entrypoint_1();
    void baanim_setEndAndDuration(struct player_state_s *, f32, f32);
    void baflag_clear(struct player_state_s *, int);
    void baflag_set(struct player_state_s *, s32);
    f32 baphysics_get_vertical_velocity(struct player_state_s *);
    s32 bs_setState(struct player_state_s *, s32);
    int func_8008DF8C(struct player_state_s *, s32);
    s32 func_800954E8(void *, s32 *);
    void func_80096394(struct player_state_s *, f32 *);
    void func_80098520(void *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    s32 player_inWater(struct player_state_s *);
    s32 player_isStable(struct player_state_s *);
    s32 nextState;
    f32 timer;
    f32 velocity[3];
    s32 surface;

    nextState = 0;
    switch (((u8 *)arg0)[0x15C]) {
    case 1:
        func_80800298_bsbbilldrill(arg0);
        timer = _batimer_get(arg0, 0);
        *(f32 *)((u8 *)arg0 + 0x170) = func_800F10B4(timer, 0.0f, 0.3f, 1500.0f, 50.0f);
        func_808005C0_bsbbilldrill((u8 *)arg0);
        func_80098520(arg0, func_800F10B4(timer, 0.0f, 0.3f, 1.0f, 0.0f));
        if (_batimer_decrement(arg0, 0)) {
            func_808002DC_bsbbilldrill(arg0, 2);
        }
        break;
    case 2:
        func_80800298_bsbbilldrill(arg0);
        func_808005C0_bsbbilldrill((u8 *)arg0);
        if (_batimer_decrement(arg0, 0)) {
            func_808002DC_bsbbilldrill(arg0, 3);
        }
        break;
    case 3:
        func_80096394(arg0, velocity);
        if (mlAbsF(velocity[1]) < 1.0f) {
            ((u8 *)arg0)[0x15D]++;
        } else {
            ((u8 *)arg0)[0x15D] = 0;
        }
        func_808005C0_bsbbilldrill((u8 *)arg0);
        if (baphysics_get_vertical_velocity(arg0) < 0.0f) {
            baflag_set(arg0, 0x22);
        }
        if (player_inWater(arg0)) {
            nextState = 0x4C;
        } else if (func_8008DF8C(arg0, 0x50) || ((u8 *)arg0)[0x15D] >= 4) {
            if (func_800954E8(arg0, &surface)) {
                nextState = 0x72;
            } else {
                func_808002DC_bsbbilldrill(arg0, 4);
            }
        }
        break;
    case 4:
        baflag_clear(arg0, 0x26);
        func_808005C0_bsbbilldrill((u8 *)arg0);
        func_80800250_bsbbilldrill(arg0);
        func_80800100_bsbbilldrill(arg0);
        func_8080019C_bsbbilldrill(arg0);
        func_80800008_bsbbilldrill(arg0);
        if (_batimer_decrement(arg0, 0)) {
            func_808002DC_bsbbilldrill(arg0, 5);
        }
        break;
    case 5:
        _bswalk_entrypoint_1(arg0);
        if (player_inWater(arg0)) {
            nextState = 0x4C;
        }
        if (player_isStable(arg0)) {
            baanim_setEndAndDuration(arg0, 1.0f, 1.9f);
            nextState = 0x20;
        }
        break;
    }
    bs_setState(arg0, nextState);
}

s32 bsbbilldrill_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_80800B68_bsbbilldrill[];
    return ((s32 *)&D_80800B68_bsbbilldrill)[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/bbilldrill.data.s */
void _bsbbilldrill_entrypoint_0();
void _bsbbilldrill_entrypoint_1();
void _bsbbilldrill_entrypoint_2();
void func_80099B94();
s32 D_80800AB0_bsbbilldrill [2] [ 3 ] BT_DATA(4, overlays_bs_bbilldrill, 0x0) = { { 224, 224, 170 }, { 224, 224, 224 } };
s32 D_80800AC8_bsbbilldrill[18] BT_DATA(4, overlays_bs_bbilldrill, 0x18) = { 1903074, 2228262, 2490393, 1638439, 200, 240, 1445888, 262297, 458754, 1376256, 13369387, 21758387, 2948870, 26279686, 16384800, 16384027, -131007664, 0 };
s32 D_80800B10_bsbbilldrill [8] BT_DATA(4, overlays_bs_bbilldrill, 0x60) = { 50724883, 70713365, 115, 3342358, 1441792012, 76, 15925516, 1114112 };
s32 D_80800B30_bsbbilldrill [8] BT_DATA(4, overlays_bs_bbilldrill, 0x80) = { 50724883, 70713365, 115, 3342358, 1441792012, 76, 14221555, 1114112 };
s32 D_80800B50_bsbbilldrill [6] BT_DATA(4, overlays_bs_bbilldrill, 0xA0) = { 50724883, 80281621, 204, 3342358, 1441792017, 0 };
BtIntPtr D_80800B68_bsbbilldrill [6] BT_DATA(4, overlays_bs_bbilldrill, 0xB8) = { (BtIntPtr)_bsbbilldrill_entrypoint_0, (BtIntPtr)_bsbbilldrill_entrypoint_1, (BtIntPtr)_bsbbilldrill_entrypoint_2, (BtIntPtr)func_80099B94, 0, 0 };
