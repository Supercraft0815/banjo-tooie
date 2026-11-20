#include "common.h"
#include "overlays/ba/playerstate.h"
#include "bs_script.h"

/* extern */

void bssplitup_entrypoint_0(void *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009FFD8();
    void func_800A3410(PlayerState *, s32);
    func_800A3410(arg0, 0xA);
    _bapackctrl_entrypoint_5(arg0, 3);
    baanim_playForDuration_onceSmooth(arg0, 0xA2, 2.2f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    func_8009BA9C(arg0, 0);
}

/* extern */

void bssplitup_entrypoint_1(void *arg0) {
    s32 baanim_isStopped();
    void bs_setState(void *self, s32 nextState);
    void func_800F457C(void *arg0, s32 arg1);
    u32 func_800F54E4(void);
    s32 sp1C;

    sp1C = 0;
    if (baanim_isStopped(BT_NATIVE_ONLY(arg0)) != 0) {
        sp1C = 1;
        if (func_800F54E4() != (((PlayerState *)arg0)->unk184)) {
            func_800F457C(arg0, 2);
        }
    }
    bs_setState(arg0, sp1C);
}

/* extern */

void bssplitup_entrypoint_2(BtIntPtr arg0) {
    s32 _sudialog_entrypoint_0(s32 arg0, s32 arg1);
    void _baduo_entrypoint_7(PlayerState *arg0, s32 arg1);
    s32 bs_getNextState(void *);
    _baduo_entrypoint_7(arg0, 3);
    if (bs_getNextState(arg0) != 0x5A) {
        _sudialog_entrypoint_0(0x4F5, 0xC);
    }
}

BsScript bssplitup_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80800700_bssplitup[];
    return (BsScript)D_80800700_bssplitup[arg0];
}

s32 func_8080012C_bssplitup(PlayerState *arg0, s32 arg1) {
    void _bamovegoto_entrypoint_0(void *);
    void _bamovegoto_entrypoint_12(void *, f32 *);
    void _bamovegoto_entrypoint_13(void *);
    void _bamovegoto_entrypoint_7(void *, f32);
    s32 _subaddiefind_entrypoint_5(s32 arg0, Actor **arg1, s32 arg2, f32 *arg3, f32 arg4, f32 (*arg5)(f32 *, f32 *));
    f32 baanim_getTimer(PlayerState *);
    void baanim_playForDuration_onceSmooth(PlayerState *, s32, f32);
    void baphysics_set_type(void *self, s32 type);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009C128(PlayerState *, f32 *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
#ifndef BT_NATIVE
    void func_8009FFD8(PlayerState *, enum baanim_update_type_e, enum yaw_type_e, s32, enum ba_physics_type_e);
#endif
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F9098(s32, f32 *);
    f32 sp3C[3];
    f32 *sp34[2];

    (arg0->unk15C.word) = arg1;
    switch (arg1) {
    case 1:
        baanim_playForDuration_onceSmooth(arg0, 0xA3, 2.2f);
        func_8009FFD8(arg0, 1, 1, 3, 2);
        func_8009B94C((u8 *)arg0, NULL);
        func_8009BA9C(arg0, NULL);
        func_8009DF18(arg0, 0x4592, 1.0f, 0x6D60);
        break;
    case 2:
        func_8009C128(arg0, sp3C);
        _subaddiefind_entrypoint_5(0x156, sp34, 2, sp3C, 800.0f, func_800EEB40);
        func_800EE7F8(sp3C, sp34[0] + 1);
        _bamovegoto_entrypoint_0(arg0);
        _bamovegoto_entrypoint_12(arg0, sp3C);
        _bamovegoto_entrypoint_7(arg0, (0.51f - baanim_getTimer(arg0)) * 2.2f);
        _bamovegoto_entrypoint_13(arg0);
        func_800F9098(0xB, sp3C);
        break;
    case 3:
        baphysics_set_type(arg0, 2);
        break;
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void bssplitup_entrypoint_4(PlayerState *arg0) {
    void bastick_func_8009F258(PlayerState *);
    void func_80092778(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    s32 func_8080012C_bssplitup(PlayerState *, s32);
    func_800A3410(arg0, 0xB);
    func_800A38F0(arg0, 0, 0);
    func_80092778(arg0);
    bastick_func_8009F258(arg0);
    (arg0->unk15C.word) = 0;
    func_8080012C_bssplitup(arg0, 1);
}

void bssplitup_entrypoint_5(PlayerState *arg0) {
    int baanim_isAt(PlayerState *, f32);
    s32 baanim_isStopped();
    void bs_setState(void *self, s32 nextState);
    void func_800F457C(void *arg0, s32 arg1);
    u32 func_800F54E4(void);
    s32 func_8080012C_bssplitup(PlayerState *, s32);
    s32 sp24;

    sp24 = 0;
    switch (arg0->unk15C.word) {
        case 1:
            if (baanim_isAt(arg0, 0.05f)) {
                func_8080012C_bssplitup(arg0, 2);
            }
            break;
        case 2:
            if (baanim_isAt(arg0, 0.51f)) {
                func_8080012C_bssplitup(arg0, 3);
            }
            break;
        case 3:
            break;
    }
    if (baanim_isStopped(arg0)) {
        sp24 = 0xBB;
        if (func_800F54E4() != arg0->unk184) {
            func_800F457C(arg0, 2);
        }
    }
    bs_setState(arg0, sp24);
}

/* extern */

void bssplitup_entrypoint_6(void *arg0) {
    void _baduo_entrypoint_7(PlayerState *arg0, s32 arg1);
    s32 func_800F8EE4(s32);
    _baduo_entrypoint_7(arg0, 3);
    func_800F8EE4((((PlayerState *)arg0)->unk184));
}

BsScript bssplitup_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_80800710_bssplitup[];
    return (BsScript)D_80800710_bssplitup[arg0];
}

/* extern */

void bssplitup_entrypoint_8(void *arg0) {
    s32 _batimer_set(s32, s32, s32);
    void baanim_playForDuration_loopSmooth(PlayerState *, s32, f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(PlayerState *, f32 *);
    void func_8009FFD8();
    baanim_playForDuration_loopSmooth(arg0, 0x6F, 5.5f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    func_8009BA9C(arg0, 0);
    _batimer_set(arg0, 0, 0x3DCCCCCD);
}

/* extern */

void bssplitup_entrypoint_9(u8 *arg0) {
    s32 _batimer_decrement(void *, s32);
    void bs_setState(void *self, s32 nextState);
    void _baduo_entrypoint_16(PlayerState *arg0);
    s32 var_a2;

    var_a2 = 0;
    arg0 = arg0;
    if (_batimer_decrement(arg0, 0) != 0) {
        _baduo_entrypoint_16(arg0);
        var_a2 = 0xB9;
    }
    bs_setState(arg0, var_a2);
}

void bssplitup_entrypoint_10(s32 arg0) 
{
}
BsScript bssplitup_entrypoint_11(BsScriptType arg0) {
    extern BtIntPtr D_80800720_bssplitup[];
    return (BsScript)D_80800720_bssplitup[arg0];
}

void bssplitup_entrypoint_12(void *arg0) {
    void baanim_playForDuration_once(void *self, s32 anim_id, f32 duration);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    f32 func_800136E4(f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009FFD8();
    void func_800A0CF4(PlayerState *, s32);
    f32 yaw_get(PlayerState *);
    baanim_playForDuration_once(arg0, 0x296, 0.8f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    baphysics_set_horizontal_velocity(arg0, func_800136E4(yaw_get(arg0) + 180.0f), 800.0f);
    func_800A0CF4(arg0, 1);
    func_8009DF18(arg0, 0x3EA, 1.0f, 0x6D60);
}

/* extern */

void bssplitup_entrypoint_13(BtIntPtr arg0) {
    s32 baanim_isStopped();
    void bs_setState(void *self, s32 nextState);
    s32 sp1C;

    sp1C = 0;
    if (baanim_isStopped(BT_NATIVE_ONLY((void *)arg0)) != 0) {
        sp1C = 1;
    }
    bs_setState(arg0, sp1C);
}

void func_800A0CF4(PlayerState *, s32);
void bssplitup_entrypoint_14(BtIntPtr arg0)
{
    func_800A0CF4(arg0,0);
}

BsScript bssplitup_entrypoint_15(BsScriptType arg0) {
    extern BtIntPtr D_80800730_bssplitup[];
    return (BsScript)D_80800730_bssplitup[arg0];
}

void bssplitup_entrypoint_16(void *arg0) {
    void baanim_playForDuration_once(void *self, s32 anim_id, f32 duration);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009FFD8();
    void func_800A0CF4(PlayerState *, s32);
    f32 yaw_get(PlayerState *);
    baanim_playForDuration_once(arg0, 0x292, 0.8f);
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_8009B94C(arg0, 0);
    baphysics_set_horizontal_velocity(arg0, yaw_get(arg0), 800.0f);
    func_800A0CF4(arg0, 1);
    func_8009DF18(arg0, 0x3EA, 1.0f, 0x6D60);
}

void bssplitup_entrypoint_17(void *arg0) {
    s32 baanim_isStopped();
    void bs_setState(void *self, s32 nextState);
    s32 next_state;
    s32 unused;

    next_state = 0;
    if (baanim_isStopped(BT_NATIVE_ONLY(arg0)) != 0) {
        next_state = 1;
    }
    bs_setState(arg0, next_state);
}

void bssplitup_entrypoint_18(BtIntPtr arg0)
{
    func_800A0CF4(arg0,0);
}

BsScript bssplitup_entrypoint_19(BsScriptType arg0) {
    extern BtIntPtr D_80800740_bssplitup[];
    return (BsScript)D_80800740_bssplitup[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/splitup.data.s */
void _bssplitup_entrypoint_2();
void _bssplitup_entrypoint_0();
void _bssplitup_entrypoint_1();
void func_80099AA8();
void _bssplitup_entrypoint_6();
void _bssplitup_entrypoint_4();
void _bssplitup_entrypoint_5();
void _bssplitup_entrypoint_10();
void _bssplitup_entrypoint_8();
void _bssplitup_entrypoint_9();
void _bssplitup_entrypoint_14();
void _bssplitup_entrypoint_12();
void _bssplitup_entrypoint_13();
void func_80099B94(PlayerState *);
void _bssplitup_entrypoint_18();
void _bssplitup_entrypoint_16();
void _bssplitup_entrypoint_17();
BtIntPtr D_80800700_bssplitup [4] BT_DATA(4, overlays_bs_splitup, 0x0) = { (BtIntPtr)_bssplitup_entrypoint_2, (BtIntPtr)_bssplitup_entrypoint_0, (BtIntPtr)_bssplitup_entrypoint_1, (BtIntPtr)func_80099AA8 };
BtIntPtr D_80800710_bssplitup [4] BT_DATA(4, overlays_bs_splitup, 0x10) = { (BtIntPtr)_bssplitup_entrypoint_6, (BtIntPtr)_bssplitup_entrypoint_4, (BtIntPtr)_bssplitup_entrypoint_5, (BtIntPtr)func_80099AA8 };
BtIntPtr D_80800720_bssplitup [4] BT_DATA(4, overlays_bs_splitup, 0x20) = { (BtIntPtr)_bssplitup_entrypoint_10, (BtIntPtr)_bssplitup_entrypoint_8, (BtIntPtr)_bssplitup_entrypoint_9, (BtIntPtr)func_80099AA8 };
BtIntPtr D_80800730_bssplitup [4] BT_DATA(4, overlays_bs_splitup, 0x30) = { (BtIntPtr)_bssplitup_entrypoint_14, (BtIntPtr)_bssplitup_entrypoint_12, (BtIntPtr)_bssplitup_entrypoint_13, (BtIntPtr)func_80099B94 };
BtIntPtr D_80800740_bssplitup [4] BT_DATA(4, overlays_bs_splitup, 0x40) = { (BtIntPtr)_bssplitup_entrypoint_18, (BtIntPtr)_bssplitup_entrypoint_16, (BtIntPtr)_bssplitup_entrypoint_17, (BtIntPtr)func_80099B94 };
