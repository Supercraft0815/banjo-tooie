#include "common.h"

/* extern */

typedef struct { u8 pad0[0x15C]; s32 unk15C; } Objtalk_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void bstalk_entrypoint_0(void *arg0) {
    typedef struct anctrl_s AnimCtrl;
    typedef struct player_state_s PlayerState;
    void anctrl_reset(AnimCtrl *);
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_start(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void baphysics_set_type(void *self, s32 type);
    void func_8008CA4C(void *self, s32 arg1);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009D2D8(PlayerState *, s32);
    void func_800A0110(AnimCtrl *, AnimCtrl *);
    void func_800A33A0(PlayerState *arg0, f32 arg1[3]);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_setIdeal(PlayerState *, f32);
    void yaw_setUpdateType(void *self, s32 type);
    AnimCtrl *sp3C;
    f32 sp38;
    f32 sp2C[3];
    f32 sp20[3];

    sp3C = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(sp3C);
    func_800A0110(arg0, sp3C);
    anctrl_setPlaybackType(sp3C, 2);
    anctrl_start(sp3C);
    func_8009C128(arg0, sp2C);
    func_800A33A0(arg0, sp20);
    func_800F1E6C(sp2C, sp20, &sp38);
    yaw_setIdeal(arg0, sp38);
    func_8008CA4C(arg0, 1);
    yaw_setUpdateType(arg0, 1);
    func_8009D2D8(arg0, 3);
    baphysics_set_type(arg0, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    (((Objtalk_arg0 *)arg0)->unk15C) = 1;
}

void bstalk_entrypoint_1(u8 *arg0) {
    void bs_setState(void *self, s32 nextState);
    s32 var_a1;

    var_a1 = 0;
    if ((((Objtalk_arg0 *)arg0)->unk15C) == 0) {
        var_a1 = 1;
    }
    (((Objtalk_arg0 *)arg0)->unk15C) = 0;
    bs_setState((BtIntPtr) arg0, var_a1);
}

void bstalk_entrypoint_2(s32 arg0) 
{
}
s32 bstalk_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_80800170_bstalk[];
    return ((s32 *)&D_80800170_bstalk)[arg0];
}

/* extern */

void bstalk_entrypoint_4(void *arg0) {
    void func_80099B94(void *arg0);
    s32 func_8009E6EC();
    void func_8009E830(void *arg0, s32 arg1);
    if (func_8009E6EC() == 8) {
        (((Objtalk_arg0 *)arg0)->unk15C) = 1;
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}
/* data_to_c.py: from asm/data/overlays/bs/talk.data.s */
void _bstalk_entrypoint_2();
void _bstalk_entrypoint_0();
void _bstalk_entrypoint_1();
void _bstalk_entrypoint_4();
BtIntPtr D_80800170_bstalk [4] BT_DATA(4, overlays_bs_talk, 0x0) = { (BtIntPtr)_bstalk_entrypoint_2, (BtIntPtr)_bstalk_entrypoint_0, (BtIntPtr)_bstalk_entrypoint_1, (BtIntPtr)_bstalk_entrypoint_4 };
