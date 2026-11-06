#include "common.h"
struct anctrl_s;
struct player_state_s;

s32 bsjig_entrypoint_0(s32 arg0) {
    return arg0 == 0x44;
}

void bsjig_entrypoint_1(void *arg0) {
    s32 _chjigsawdance_entrypoint_1(s32, s32);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setIndex();
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 baflag_clear(s32, s32);
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_8008E944(struct player_state_s *);
    void func_8009DE38(struct player_state_s *, s32, f32);
    f32 func_8009F308(struct player_state_s *);
    void func_8009FFD8();
    void func_800A0CF4(struct player_state_s *, s32);
    s32 func_800A32F8(s32);
    int func_800A4C68(void *);
    void func_800A4DFC(struct player_state_s *, s32);
    s32 func_800C52F4(s32, s32);
    s32 func_800D0018(s16, s32);
    void func_800FC660(u32);
    s32 func_80106790(s32);
    void yaw_setIdeal(struct player_state_s *, f32);
    extern u8 D_8012762C;
    struct anctrl_s *control;
    s32 flag;

    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setSmoothTransition(control, 0);
    anctrl_setIndex(control, 0x2E);
    anctrl_setDuration(control, 4.3f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    yaw_setIdeal(arg0, func_8009F308(arg0));
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    flag = func_800D0018(1, D_8012762C) != 0;
    if (flag == 0) {
        flag = 0;
    }
    *(s32 *)((u8 *)arg0 + 0x160) = flag;
    func_800FC660(5);
    func_800A4DFC(arg0, 9);
    func_800C52F4(func_800A4C68(arg0), 2);
    func_800A0CF4(arg0, 1);
    func_8009DE38(arg0, 0x422, 1.0f);
    baflag_clear(arg0, 7);
    baflag_clear(arg0, 0xF);
    func_8008E944(arg0);
    _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(arg0)), 1);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

/* extern */

void bsjig_entrypoint_2(void) {
    s32 _chjigsawdance_entrypoint_1(s32, s32);
    s32 func_800A32F8(s32);
    s32 func_800F53D0();
    s32 func_80106790(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F53D0();
    sp1C = temp_v0;
    if (func_800A32F8(temp_v0) != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(sp1C)), 4);
    }
}

void bsjig_entrypoint_3(void *arg0) {
    int anctrl_isAt(struct anctrl_s *, f32);
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 bs_setState(void *, s32);
    s32 func_8009919C(void *, s32 *, s32);
    s32 func_8009D874(void *);
    void func_8009DE38(struct player_state_s *, s32, f32);
    f32 func_8009F308(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
#ifndef BT_NATIVE
    extern s32 _bsjig_entrypoint_2;
#endif
    s32 sp24;
    struct anctrl_s *sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    yaw_setIdeal(arg0, func_8009F308(arg0));
    if (anctrl_isAt(sp20, 0.6502f) != 0) {
        func_8009D874(arg0);
    }
    if (anctrl_isAt(sp20, 0.835f) != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x15C))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x15C))) + 1);
        func_8009DE38(arg0, 0x434, 1.3f);
    }
    if (anctrl_isAt(sp20, 0.94f) != 0) {
        func_8009DE38(arg0, 0x3EA, 1.0f);
    }
    if (anctrl_isStopped(sp20) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x160))) != 0) {
            sp24 = 0x34;
        } else {
            sp24 = 1;
        }
    }
    func_8009919C(arg0, &_bsjig_entrypoint_2, (*(s32 *)((s8 *)(arg0) + (0x184))));
    bs_setState(arg0, sp24);
}

/* extern */

void bsjig_entrypoint_4(s32 arg0) {
    s32 _chjigsawdance_entrypoint_1(s32, s32);
    s32 func_800A32F8();
    s32 func_800A34D8(s32, s32);
    s32 func_80106790(s32);
    s32 temp_v0;

    temp_v0 = func_800A32F8();
    if (temp_v0 != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(temp_v0), 5);
        func_800A34D8(arg0, 0);
    }
}

/* extern */

void bsjig_entrypoint_5(s32 arg0) {
    s32 func_8008E95C(s32);
    s32 func_8009CEE8(s32);
    void func_800A0CF4(struct player_state_s *, s32);
    int func_800A4C68(void *);
    s32 func_800A4E30(s32);
    s32 func_800C53EC(s32, s32);
    bsjig_entrypoint_4(arg0);
    func_800A0CF4(arg0, 0);
    func_800A4E30(arg0);
    func_800C53EC(func_800A4C68(arg0), 2);
    func_8008E95C(arg0);
    func_8009CEE8(arg0);
}

s32 bsjig_entrypoint_6(s32 arg0) {
    extern s32 D_808005B0_bsjig[];
    return ((s32 *)&D_808005B0_bsjig)[arg0];
}

/* extern */

void bsjig_entrypoint_7(s32 arg0) {
    s32 func_80099AA8(s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    if (func_8009E6EC() == 0x26) {
        func_80099B94(arg0);
        return;
    }
    func_80099AA8(arg0);
}

void bsjig_entrypoint_8(s32 arg0) {
    s32 func_8008E95C(s32);
    s32 func_8009CEE8(s32);
    void func_800A0CF4(struct player_state_s *, s32);
    int func_800A4C68(void *);
    s32 func_800A4E30(s32);
    s32 func_800C53EC(s32, s32);
    func_8008E95C(arg0);
    func_800A0CF4(arg0, 0);
    func_800A4E30(arg0);
    func_800C53EC(func_800A4C68(arg0), 2);
    func_8009CEE8(arg0);
}

void bsjig_entrypoint_9(struct player_state_s *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    s32 bs_getPreviousState(struct player_state_s *);
    s32 baflag_clear(s32, s32);
    f32 func_8009F308(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    void func_8009FFD8();
    void baphysics_set_target_horizontal_velocity(struct player_state_s *, f32);
    void func_800FC660(u32);
    void func_800A4DFC(struct player_state_s *, s32);
    int func_800A4C68(void *);
    s32 func_800C52F4(s32, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    void func_8009DE38(struct player_state_s *, s32, f32);
    void func_8008E944(struct player_state_s *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex();
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    (*(s32 *)((u8 *)arg0 + 0x164)) = bs_getPreviousState(arg0) == 0x44;
    baflag_clear(arg0, 0x1A);
    anctrl_reset(control);
    anctrl_setIndex(control, 0x282);
    anctrl_setDuration(control, 3.6f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    yaw_setIdeal(arg0, func_8009F308(arg0));
    func_8009FFD8(arg0, 1, 1, 3, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800FC660(0x1B);
    func_800A4DFC(arg0, 9);
    func_800C52F4(func_800A4C68(arg0), 2);
    func_800A0CF4(arg0, 1);
    func_8009DE38(arg0, 0x422, 1.0f);
    func_8008E944(arg0);
}

typedef struct player_state_s PlayerState;

void bsjig_entrypoint_10(PlayerState *arg0) {
    int baanim_isAt(PlayerState *, f32);
    int baanim_isStopped(PlayerState *);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    s32 bs_setState(void *, s32);
    s32 sp24;

    sp24 = 0;
    if ((baanim_isAt(arg0, 0.59f) != 0) || (baanim_isAt(arg0, 0.84f) != 0)) {
        func_8009DF18(arg0, 0x3EA, 1.0f, 0x7530);
    }
    if (baanim_isStopped(arg0) != 0) {
        sp24 = 1;
    }
    bs_setState(arg0, sp24);
}

s32 bsjig_entrypoint_11(s32 arg0) {
    extern s32 D_808005C0_bsjig[];
    return ((s32 *)&D_808005C0_bsjig)[arg0];
}
