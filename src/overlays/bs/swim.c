#include "bs_script.h"
#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif
BT_NATIVE_ONLY(struct player_state_s; void _bsrest_entrypoint_14(struct player_state_s *); s32 _bsrest_entrypoint_20(struct player_state_s *);) struct player_state_s;
struct anctrl_s;
enum asset_e;
/* extern */

#ifdef BT_NATIVE
s32 func_80800000_bsswim(BtIntPtr bt_a0) {
#else
s32 func_80800000_bsswim() {
#endif
    s32 func_8008E23C();
    s32 var_v1;

    if (func_8008E23C(BT_NATIVE_ONLY((void *)bt_a0)) != 0) {
        var_v1 = 0x6D;
    } else {
        var_v1 = 0x30;
    }
    return var_v1;
}

/* extern */

void func_80800030_bsswim(void *arg0) {
    void func_80092C00(void *, f32 *);
    void func_80092C24(void *, f32 *);
    s32 func_80096544(void *);
    BtIntPtr func_8009FBB0(void *, f32 *, f32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 func_800DC0C0(void);
    f32 sp2C[3];
    BtIntPtr sp28;

    if (func_80096544(arg0) != 0) {
        if (func_800DC0C0() > 0.5f) {
            func_80092C00(arg0, sp2C);
        } else {
            func_80092C24(arg0, sp2C);
        }
        sp28 = func_8009FBB0(arg0, sp2C, 0.0f);
        func_800BA930(sp28, -0x3C, -0x64, -0x3C, 0x3C, 0, 0x3C);
        func_800BA22C(sp28, 1);
    }
}

void func_808000E0_bsswim(u32 *arg0, struct anctrl_s *arg1) {
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    int anctrl_getIndex(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    extern s16 D_80800B90_bsswim[];
    s32 sp24;

    sp24 = D_80800B90_bsswim[arg0[0x57]];
    if (anctrl_getIndex(arg1) != sp24) {
        anctrl_setStart(arg1, anctrl_getAnimTimer(arg1));
        anctrl_setIndex(arg1, sp24);
        anctrl_start(arg1);
    }
    arg0[0x57]++;
    if (arg0[0x57] >= 0xAU) {
        arg0[0x57] = 0U;
    }
}

void func_80800178_bsswim(struct player_state_s *arg0) {
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
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 30.0f, 300.0f));
}

void func_808001DC_bsswim(struct player_state_s *arg0) {
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    int func_8008E0E8(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009E6C4(struct player_state_s *, s32);

    if (func_8009E6C4(arg0, 1) == 0) {
        baphysics_set_gravity(arg0, 100.0f);
        baphysics_set_terminal_velocity(arg0, 133.33f);
        bastick_setZoneMax(arg0, 0, 0.03f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800961AC(arg0, 3);
        if (func_8008E0E8(arg0) != 0) {
            _bapackctrl_entrypoint_5(arg0, 4);
        }
    }
}

void func_80800270_bsswim(struct player_state_s *arg0) {
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    void baphysics_reset_gravity(struct player_state_s *);
    void baphysics_reset_terminal_velocity(struct player_state_s *);
    void bastick_resetZones(struct player_state_s *);
    int func_8008E0E8(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    s32 func_8009E69C(struct player_state_s *, s32);

    if (func_8009E69C(arg0, 1) == 0) {
        baphysics_reset_terminal_velocity(arg0);
        baphysics_reset_gravity(arg0);
        bastick_resetZones(arg0);
        func_800961AC(arg0, 1);
        if (func_8008E0E8(arg0) != 0) {
            _bapackctrl_entrypoint_5(arg0, 3);
        }
    }
}

void func_808002E0_bsswim(struct player_state_s *arg0) {
    int anctrl_getIndex(struct anctrl_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void bainput_setDiveCooldown(struct player_state_s *, s32, f32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    s32 bs_getPreviousState(struct player_state_s *);
    void func_8008B1C8(struct anctrl_s *, f32);
    s32 func_8009CA70(struct player_state_s *, s32, s32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    void func_800A4DA4(struct player_state_s *, s32);
    f32 func_800CF67C(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    s32 pad;
    s32 previous;
    f32 transition;
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    func_808001DC_bsswim(arg0);
    previous = bs_getPreviousState(arg0);
    if (previous == 0x4C) {
        transition = 0.8f;
    } else {
        transition = 0.5f;
    }
    if (func_8009CA70(arg0, previous, 2) != 0) {
        if (previous == 0x54) {
            func_8009DF18(arg0, 0x461, 1.0f, 30000);
        } else if (previous != 0x4C) {
            func_8009DF18(arg0, 0x461, 1.0f, (s32)func_800F10B4(func_800CF67C(), 1.0f, 0.0f, 8000.0f, 30000.0f));
        }
        bainput_setDiveCooldown(arg0, 4, 0.7f);
    }
    if ((anctrl_getIndex(control) == 0x57) && (previous != 0x4C)) {
        anctrl_setDuration(control, 1.2f);
    } else {
        anctrl_reset(control);
        func_8008B1C8(control, transition);
        anctrl_setIndex(control, 0x57);
        anctrl_setPlaybackType(control, 2);
        anctrl_setStart(control, 0.3f);
        anctrl_setDuration(control, 1.2f);
        anctrl_start(control);
    }
    func_8009FFD8(arg0, 1, 3, 3, 2);
    yaw_setVelocityBounded(arg0, 500.0f, 5.0f);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
    func_800A4DA4(arg0, 8);
}

void func_808004C4_bsswim(struct player_state_s *arg0) {
    void bs_setState(void *self, s32 nextState);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    s32 bastick_getZone(struct player_state_s *);
    s32 func_8001210C(s32);
    s32 func_80096500(struct player_state_s *);
    void func_8009DEC0(struct player_state_s *, s32, f32, f32, s32, s32);
    void func_8009FC34(struct player_state_s *, s32);
    f32 func_800DC0C0(void);
    s32 next_state;
    struct anctrl_s *anim_ctrl;

    next_state = 0;
    anim_ctrl = baanim_getAnimCtrlPtr(arg0);
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_8009FC34(arg0, 1);
    }
    if ((func_8001210C(7) == 0) && (func_800DC0C0() < 0.5f)) {
        func_80800030_bsswim(arg0);
    }
    if (anctrl_isAt(anim_ctrl, 0.01f) != 0) {
        func_8009DEC0(arg0, 0x46F, 0.85f, 1.15f, 16000, 16000);
    }
    if (anctrl_isAt(anim_ctrl, 0.4348f) != 0) {
        func_808000E0_bsswim(arg0, anim_ctrl);
    }
    if (bastick_getZone(arg0) == 1) {
        next_state = 0x2E;
    }
    if (player_inWater(arg0) == 0) {
        next_state = 1;
    }
    if (bainput_should_enter_first_person(arg0) != 0) {
        next_state = _badrone_entrypoint_24(arg0);
    }
    if (bainput_should_dive(arg0) != 0) {
        next_state = func_80800000_bsswim(arg0);
    }
    if ((func_80096500(arg0) != 0) && (bakey_pressed(arg0, 8) != 0)) {
        next_state = 5;
    }
    if ((baflag_isTrue(arg0, 6) != 0) || (baflag_isTrue(arg0, 0x14) != 0)) {
        next_state = 0xD;
    }
    bs_setState(arg0, next_state);
}

void func_80800688_bsswim(struct player_state_s *arg0)
{
    func_80800270_bsswim(arg0);
    func_800A4E30(arg0);
}
BsScript bsswim_entrypoint_0(BsScriptType arg0) {
    extern BtIntPtr D_80800BA4_bsswim[];
    return (BsScript)D_80800BA4_bsswim[arg0];
}

void func_808006C4_bsswim(struct player_state_s *arg0) {
    int anctrl_getIndex(struct anctrl_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void baphysics_set_type(void *self, s32 type);
    s32 bs_getPreviousState(struct player_state_s *);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA4C(void *self, s32 arg1);
    void func_8009D2D8(struct player_state_s *, s32);
    void yaw_setUpdateType(void *self, s32 type);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    struct anctrl_s *control;
    f32 transition;

    control = baanim_getAnimCtrlPtr(arg0);
    func_808001DC_bsswim(arg0);
    if (bs_getPreviousState(arg0) == 0x4C) {
        transition = 0.8f;
    } else {
        transition = 0.4f;
    }
    if (anctrl_getIndex(control) != 0x39) {
        anctrl_reset(control);
        anctrl_setIndex(control, 0x39);
        func_8008B1C8(control, transition);
        anctrl_setStart(control, 0.8f);
        anctrl_setPlaybackType(control, 2);
        anctrl_start(control);
    }
    func_8008CA4C(arg0, 2);
    baanim_setDurationRange(arg0, 0.3f, 1.5f);
    func_8008C9F0(arg0, 30.0f, 300.0f, 1.2f, 0.7f);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 500.0f, 5.0f);
    func_8009D2D8(arg0, 1);
    baphysics_set_type(arg0, 2);
}

void func_808007F8_bsswim(struct player_state_s *arg0) {
    void bs_setState(void *self, s32 nextState);
    int baflag_isTrue(struct player_state_s *, s32);
    int bakey_pressed(struct player_state_s *, int);
    s32 bastick_getZone(struct player_state_s *);
    int func_8008D214(struct player_state_s *);
    s32 func_80096500(struct player_state_s *);
    s32 func_8009650C(struct player_state_s *);
    void func_8009DE74(struct player_state_s *, s32, f32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    int anctrl_isAt(struct anctrl_s *, f32);
    void func_80096440(struct player_state_s *, f32 *);
    f32 func_800964DC(struct player_state_s *);
    f32 func_8009C150(struct player_state_s *);
    void func_8009FD24(struct player_state_s *, s32);
    s32 sp34;
    struct anctrl_s *sp30;
    f32 sp24[3];
    f32 sp20;

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    if (anctrl_isAt(sp30, 0.38f)) {
        func_8009FD24(arg0, 1);
    }
    if (anctrl_isAt(sp30, 0.88f)) {
        func_8009FD24(arg0, 0);
    }
    if (anctrl_isAt(sp30, 0.2f)) {
        func_8009DE74(arg0, 0x40C, 0.9f, 1.1f);
    }
    if (anctrl_isAt(sp30, 0.7f)) {
        func_8009DE74(arg0, 0x40C, 0.9f, 1.1f);
    }
    func_80800178_bsswim(arg0);
    if (bastick_getZone(arg0) == 0) {
        sp34 = 0x2D;
    }
    if (player_inWater(arg0) == 0) {
        sp34 = 1;
    }
    if (func_8009650C(arg0) && func_8008D214(arg0)) {
        func_80096440(arg0, sp24);
        if (sp24[1] < -0.7f) {
            sp20 = func_800964DC(arg0);
            if (sp20 - func_8009C150(arg0) > 90.0f) {
                sp34 = func_80800000_bsswim(arg0);
            }
        }
    }
    if (bainput_should_dive(arg0)) {
        sp34 = func_80800000_bsswim(arg0);
    }
    if (func_80096500(arg0) && bakey_pressed(arg0, 8)) {
        sp34 = 5;
    }
    if (baflag_isTrue(arg0, 6) || baflag_isTrue(arg0, 0x14)) {
        sp34 = 0xD;
    }
    bs_setState(arg0, sp34);
}

void func_808009F0_bsswim(struct player_state_s *arg0)
{
    func_80800270_bsswim(arg0);
}

BsScript bsswim_entrypoint_1(BsScriptType arg0) {
    extern BtIntPtr D_80800BB4_bsswim[];
    return (BsScript)D_80800BB4_bsswim[arg0];
}

void func_80800A24_bsswim(struct player_state_s *arg0)
{
    _bsrest_entrypoint_14(BT_NATIVE_ONLY(arg0));
    func_80800270_bsswim(arg0);
}
void func_80800A4C_bsswim(struct player_state_s *arg0)
{
    func_808001DC_bsswim(arg0);
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_80800A74_bsswim(BtIntPtr arg0) {
    s32 _bsrest_entrypoint_13(BtIntPtr);
    void bs_setState(void *self, s32 nextState);
    BT_IDO_ONLY(s32 _bsrest_entrypoint_20();)
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20(BT_NATIVE_ONLY((struct player_state_s *)arg0)) != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

BsScript bsswim_entrypoint_2(BsScriptType arg0) {
    extern BtIntPtr D_80800BC4_bsswim[];
    return (BsScript)D_80800BC4_bsswim[arg0];
}

void func_80800AC8_bsswim(struct player_state_s *arg0)
{
    func_808001DC_bsswim(arg0);
    _bsdrone_entrypoint_0(arg0);
}
/* extern */

void func_80800AF0_bsswim(BtIntPtr arg0) {
    s32 _badrone_entrypoint_30();
    void _bsdrone_entrypoint_1(struct player_state_s *arg0);
    void bs_setState(void *self, s32 nextState);
    s32 sp1C;

    sp1C = 0;
    if (_badrone_entrypoint_30() != 0) {
        sp1C = 1;
    }
    _bsdrone_entrypoint_1(arg0);
    bs_setState(arg0, sp1C);
}

#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void func_80800B34_bsswim(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_80800270_bsswim(arg0);
}
BsScript bsswim_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80800BD4_bsswim[];
    return (BsScript)D_80800BD4_bsswim[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/swim.data.s */
void func_80099B94();
void _bsdrone_entrypoint_3();
s16 D_80800B90_bsswim [10] BT_DATA(4, overlays_bs_swim, 0x0) = { 87, 87, 87, 88, 87, 88, 87, 87, 88, 88 };
BtIntPtr D_80800BA4_bsswim [4] BT_DATA(4, overlays_bs_swim, 0x14) = { (BtIntPtr)func_80800688_bsswim, (BtIntPtr)func_808002E0_bsswim, (BtIntPtr)func_808004C4_bsswim, (BtIntPtr)func_80099B94 };
BtIntPtr D_80800BB4_bsswim [4] BT_DATA(4, overlays_bs_swim, 0x24) = { (BtIntPtr)func_808009F0_bsswim, (BtIntPtr)func_808006C4_bsswim, (BtIntPtr)func_808007F8_bsswim, (BtIntPtr)func_80099B94 };
BtIntPtr D_80800BC4_bsswim [4] BT_DATA(4, overlays_bs_swim, 0x34) = { (BtIntPtr)func_80800A24_bsswim, (BtIntPtr)func_80800A4C_bsswim, (BtIntPtr)func_80800A74_bsswim, (BtIntPtr)func_80099B94 };
BtIntPtr D_80800BD4_bsswim [7] BT_DATA(4, overlays_bs_swim, 0x44) = { (BtIntPtr)func_80800B34_bsswim, (BtIntPtr)func_80800AC8_bsswim, (BtIntPtr)func_80800AF0_bsswim, (BtIntPtr)_bsdrone_entrypoint_3, 0, 0, 0 };
