#include "common.h"
#include "overlays/ba/playerstate.h"
/* extern */
#include "bs_script.h"
#ifdef BT_NATIVE
#include "overlays/ba/anim.h"
#endif
void bsthrow_entrypoint_0(void *arg0) {

    #ifndef BT_NATIVE
    s32 anctrl_reset(BtIntPtr);
    s32 anctrl_setDuration(BtIntPtr, s32);
    s32 anctrl_setIndex(BtIntPtr, s32);
    s32 anctrl_setPlaybackType(BtIntPtr, s32);
    s32 anctrl_start(BtIntPtr);
    s32 baanim_getAnimCtrlPtr();
    #endif
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 baphysics_set_type(void *, s32);
    BT_IDO_ONLY(s32 func_8008CA4C(void *, s32);)
    s32 func_8009BA9C(void *, s32);
    s32 func_8009D2D8(void *, s32);
    s32 yaw_setUpdateType(void *, s32);
    BT_NATIVE_ONLY(AnimCtrl *) BT_IDO_ONLY(s32) temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(arg0));
    anctrl_reset(temp_v0);
    anctrl_setIndex(temp_v0, 0x11B);
    anctrl_setDuration(temp_v0, BT_DATA_FIELD(1.0f, 0x3F800000));
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8008CA4C(arg0, 1);
    yaw_setUpdateType(arg0, 1);
    func_8009D2D8(arg0, 3);
    baphysics_set_type(arg0, 3);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_8009BA9C(arg0, 0);
    (((PlayerState *)arg0)->unk15C.word) = 0;
}


void bsthrow_entrypoint_1(void *arg0) {
    #ifndef BT_NATIVE
    struct anctrl_s;
    s32 baanim_getAnimCtrlPtr();
    int anctrl_isAt(BtIntPtr, f32);
    s32 anctrl_isStopped(BtIntPtr);
    #endif
    void func_8009C128(void *, f32[3]);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_setIdeal(void *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    void bs_setState(void *self, s32 nextState);
    Unk80132ED0 *_bahold_entrypoint_5(void *);
    void _bahold_entrypoint_6(void *arg0, BtIntPtr arg1);
    void func_800A33CC(BT_IDO_ONLY(void *) BT_NATIVE_ONLY(PlayerState *), f32 *);
    s32 sp4C;
    BT_NATIVE_ONLY(AnimCtrl *) BT_IDO_ONLY(s32) sp48;
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    Unk80132ED0 *sp28;

    sp4C = 0;
    sp48 = baanim_getAnimCtrlPtr(arg0);
    sp28 = _bahold_entrypoint_5(arg0);
    if ((((PlayerState *)arg0)->unk15C.word) == 0 && sp28 != NULL) {
        _bahold_entrypoint_6(arg0, BT_NATIVE_ONLY((BtIntPtr))sp28);
    }
    func_8009C128(arg0, sp30);
    func_800A33CC(arg0, sp3C);
    func_800F1E6C(sp30, sp3C, &sp2C);
    yaw_setIdeal(arg0, sp2C);
    if (anctrl_isAt(sp48, 0.35f) && sp28 != NULL) {
        (((PlayerState *)arg0)->unk15C.word) = 1;
        func_80106790(sp28)->unk64_22 = 1;
    }
    if (anctrl_isStopped(sp48)) {
        sp4C = 1;
    }
    bs_setState(arg0, sp4C);
}    typedef struct { u8 pad0[0x15C]; s32 unk15C; } Objthrow_bsthrow_entrypoint_2_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

/* extern */

void bsthrow_entrypoint_2(void *self) {
    void bastatetimer_set(void *self, s32 id, f32 arg2);
    s32 bs_getNextState(void *);
    BT_DATA_FIELD(((PlayerState *)self)->unk15C.word, ((Objthrow_bsthrow_entrypoint_2_self *)self)->unk15C) = 0;
    if (bs_getNextState(self) == 1) {
        bastatetimer_set(self, 0, 0.14f);
        bastatetimer_set(self, 1, 0.28f);
    }
}

BsScript bsthrow_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_808002F0_bsthrow[];
    return (BsScript)D_808002F0_bsthrow[arg0];
}

/* extern */

void bsthrow_entrypoint_4(void *arg0) {
    s32 func_8008E9AC(void *);
    void func_8008F6B8(struct player_state_s *player, s32 actor_id);
    void func_80099B94(void *arg0);
    s32 func_8009E6EC(BT_NATIVE_ONLY(PlayerState *));
    void func_8009E830(void *arg0, s32 arg1);
    s32 temp_v0;

    temp_v0 = func_8009E6EC(BT_NATIVE_ONLY(arg0));
    switch (temp_v0) {
    case 18:
        if ((((PlayerState *)arg0)->unk15C.word) == 0) {
            func_8008F6B8(arg0, func_8008E9AC(arg0));
            return;
        }
        func_8009E830(arg0, 1);
        return;
    case 21:
    case 28:
    case 29:
    case 30:
    case 37:
        func_8009E830(arg0, 1);
        return;
    default:
        func_80099B94(arg0);
        return;
    }
}
/* data_to_c.py: from asm/data/overlays/bs/throw.data.s */
void _bsthrow_entrypoint_2();
void _bsthrow_entrypoint_0();
void _bsthrow_entrypoint_1();
void _bsthrow_entrypoint_4();
BtIntPtr D_808002F0_bsthrow [4] BT_DATA(4, overlays_bs_throw, 0x0) = { (BtIntPtr)_bsthrow_entrypoint_2, (BtIntPtr)_bsthrow_entrypoint_0, (BtIntPtr)_bsthrow_entrypoint_1, (BtIntPtr)_bsthrow_entrypoint_4 };
