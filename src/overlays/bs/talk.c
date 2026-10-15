#include "common.h"

/* extern */

void bstalk_entrypoint_0(void *arg0) {
    typedef struct anctrl_s AnimCtrl;
    typedef struct player_state_s PlayerState;
    void anctrl_reset(AnimCtrl *);
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_start(AnimCtrl *);
    AnimCtrl *baanim_getAnimCtrlPtr(PlayerState *);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 baphysics_set_type(void *, s32);
    s32 func_8008CA4C(void *, s32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009D2D8(PlayerState *, s32);
    void func_800A0110(AnimCtrl *, AnimCtrl *);
    s32 func_800A33A0(void *, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 yaw_setUpdateType(void *, s32);
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
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
}

void bstalk_entrypoint_1(u8 *arg0) {
    s32 bs_setState(s32, s32);
    s32 var_a1;

    var_a1 = 0;
    if ((*(s32 *)((s8 *)(arg0) + (0x15C))) == 0) {
        var_a1 = 1;
    }
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    bs_setState((s32) arg0, var_a1);
}

void bstalk_entrypoint_2(s32 arg0) 
{
}
s32 bstalk_entrypoint_3(s32 arg0) {
    extern s32 D_80800170_bstalk[];
    return ((s32 *)&D_80800170_bstalk)[arg0];
}

/* extern */

void bstalk_entrypoint_4(void *arg0) {
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    if (func_8009E6EC() == 8) {
        (*(s32 *)((s8 *)(arg0) + (0x15C))) = 1;
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}
