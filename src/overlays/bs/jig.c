#include "common.h"

s32 bsjig_entrypoint_0(s32 arg0) {
    return arg0 == 0x44;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_1.s")

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
    s32 anctrl_isAt(s32, s32);
    s32 anctrl_isStopped(s32);
    s32 baanim_getAnimCtrlPtr();
    s32 bs_setState(void *, s32);
    s32 func_8009919C(void *, s32 *, s32);
    s32 func_8009D874(void *);
    s32 func_8009DE38(void *, s32, s32);
    f32 func_8009F308(void *);
    s32 yaw_setIdeal(void *, f32);
    extern s32 _bsjig_entrypoint_2;
    s32 sp24;
    s32 sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr();
    yaw_setIdeal(arg0, func_8009F308(arg0));
    if (anctrl_isAt(sp20, 0x3F267382) != 0) {
        func_8009D874(arg0);
    }
    if (anctrl_isAt(sp20, 0x3F55C28F) != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x15C))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x15C))) + 1);
        func_8009DE38(arg0, 0x434, 0x3FA66666);
    }
    if (anctrl_isAt(sp20, 0x3F70A3D7) != 0) {
        func_8009DE38(arg0, 0x3EA, 0x3F800000);
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
    s32 func_800A0CF4(s32, s32);
    s32 func_800A4C68(s32);
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
    s32 func_800A0CF4(s32, s32);
    s32 func_800A4C68(s32);
    s32 func_800A4E30(s32);
    s32 func_800C53EC(s32, s32);
    func_8008E95C(arg0);
    func_800A0CF4(arg0, 0);
    func_800A4E30(arg0);
    func_800C53EC(func_800A4C68(arg0), 2);
    func_8009CEE8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_9.s")

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
