#include "common.h"

struct player_state_s;

void func_80800000_bsbanswim(s32 arg0) {
    func_8009FFD8(arg0, 0x1, 0x3, 0x3, 0x9);
}

/* extern */

void func_80800030_bsbanswim(struct player_state_s *arg0) {
    s32 _baairbar_entrypoint_0(struct player_state_s *, s32);
    s32 _baswim_entrypoint_5(struct player_state_s *);
    s32 _baswim_entrypoint_6(struct player_state_s *, s32);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    void baroll_setAngularVelocity(struct player_state_s *, f32, f32);
    s32 bs_getCurrentState(struct player_state_s *);
    void func_80093360(struct player_state_s *, f32);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009BC5C(struct player_state_s *, f32);
    s32 func_8009E77C(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    s32 func_800F8B88();
    if (func_8009E77C(arg0, 0xB) == 0) {
        _baswim_entrypoint_5(arg0);
        baroll_setAngularVelocity(arg0, 130.0f, 0.9f);
        baphysics_set_gravity(arg0, 0.0f);
        baphysics_set_terminal_velocity(arg0, -399.99f);
        if (func_800F8B88() != 3) {
            func_800A0CF4(arg0, 1);
        }
        func_800961AC(arg0, 3);
        func_80093360(arg0, 60.0f);
        func_8009BC5C(arg0, 2.0f);
        _baswim_entrypoint_6(arg0, 1);
        if (bs_getCurrentState(arg0) != 0x4C) {
            _baairbar_entrypoint_0(arg0, 2);
        }
    }
}

void func_80800104_bsbanswim(struct player_state_s *arg0) {
    s32 _baairbar_entrypoint_0(struct player_state_s *, s32);
    s32 _baswim_entrypoint_4(struct player_state_s *);
    s32 _baswim_entrypoint_6(struct player_state_s *, s32);
    void baroll_setIdeal(struct player_state_s *, f32);
    s32 bs_getCurrentState(struct player_state_s *);
    void func_80093360(struct player_state_s *, f32);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009BC34(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    s32 func_8009E74C(struct player_state_s *, s32);
    void func_800A0CF4(struct player_state_s *, s32);
    if (func_8009E74C(arg0, 0xB) == 0) {
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009BC34(arg0);
        func_800A0CF4(arg0, 0);
        func_800961AC(arg0, 1);
        func_80093360(arg0, 0.0f);
        _baswim_entrypoint_6(arg0, 0);
        if (bs_getCurrentState(arg0) != 0x4C) {
            _baairbar_entrypoint_0(arg0, 1);
        }
        _baswim_entrypoint_4(arg0);
    }
}

void func_808001A8_bsbanswim(struct player_state_s *arg0)
{
    func_80800104_bsbanswim(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808001C8_bsbanswim.s")

void func_8080025C_bsbanswim(void *arg0) {
    s32 _baswim_entrypoint_1(void *);
    void _baswim_entrypoint_10(void *, f32);
    void _baswim_entrypoint_8(void *, f32);
    void _baswim_entrypoint_11(void *);
    void _baswim_entrypoint_13(void *);
    void func_800A0E64(void *);
    s32 baanim_getAnimCtrlPtr(void *);
    s32 anctrl_isAt(s32, f32);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009DE38(void *, s32, f32);
    s32 player_inWater(void *);
    s32 bs_setState(void *, s32);
    s32 sp24;
    s32 sp20;
    u8 temp_v1;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    temp_v1 = *(u8 *)((s8 *)arg0 + 0x164);
    switch (temp_v1) {
        case 0:
            func_8009BF5C(arg0, 50.0f);
            if (anctrl_isAt(sp20, 0.37f)) {
                if (_baswim_entrypoint_1(arg0)) {
                    func_800A0E64(arg0);
                }
                _baswim_entrypoint_10(arg0, 300.0f);
                _baswim_entrypoint_8(arg0, 200.0f);
                *(u8 *)((s8 *)arg0 + 0x164) = 1;
            }
            break;
        case 1:
            _baswim_entrypoint_11(arg0);
            _baswim_entrypoint_13(arg0);
            if (anctrl_isAt(sp20, 0.76f)) {
                sp24 = 0x2B;
            }
            break;
    }
    if (anctrl_isAt(sp20, 0.6f)) {
        func_8009DE38(arg0, 0x3FD, 1.0f);
    }
    if (!player_inWater(arg0)) {
        sp24 = 1;
    }
    bs_setState(arg0, sp24);
}

s32 bsbanswim_entrypoint_0(s32 arg0) {
    extern s32 D_80800A30_bsbanswim[];
    return ((s32 *)&D_80800A30_bsbanswim)[arg0];
}

s32 func_80800390_bsbanswim(s32 arg0) {
    if ((arg0 == 0x81) || (arg0 == 0x82) || (arg0 == 0x90)) {
        return 1;
    }
    return 0;
}

void func_808003BC_bsbanswim(struct player_state_s *arg0) {
    void func_80800104_bsbanswim(struct player_state_s *);
    s32 bs_getNextState(struct player_state_s *);
    int func_8008E0E8(struct player_state_s *);
    void _bapackctrl_entrypoint_5(struct player_state_s *, s32);
    if (!func_80800390_bsbanswim(bs_getNextState(arg0))) {
        if (func_8008E0E8(arg0)) _bapackctrl_entrypoint_5(arg0,3);
        func_80800104_bsbanswim(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_8080040C_bsbanswim.s")

void func_8080049C_bsbanswim(struct player_state_s *arg0)
{
    func_808003BC_bsbanswim(arg0);
}

/* extern */

void func_808004BC_bsbanswim(s32 arg0) {
    s32 anctrl_setDuration(s32, s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8080040C_bsbanswim(s32);
    s32 sp1C;

    sp1C = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(arg0);
    anctrl_setDuration(sp1C, 0x3F800000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808004F4_bsbanswim.s")

s32 bsbanswim_entrypoint_1(s32 arg0) {
    extern s32 D_80800A40_bsbanswim[];
    return ((s32 *)&D_80800A40_bsbanswim)[arg0];
}

void func_80800670_bsbanswim(struct player_state_s *arg0)
{
    func_808003BC_bsbanswim(arg0);
}

/* extern */

void func_80800690_bsbanswim(s32 arg0) {
    s32 anctrl_setDuration(s32, s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8080040C_bsbanswim(s32);
    s32 sp1C;

    sp1C = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(arg0);
    anctrl_setDuration(sp1C, 0x3F4CCCCD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808006CC_bsbanswim.s")

s32 bsbanswim_entrypoint_2(s32 arg0) {
    extern s32 D_80800A50_bsbanswim[];
    return ((s32 *)&D_80800A50_bsbanswim)[arg0];
}

void func_80800848_bsbanswim(struct player_state_s *arg0)
{
    func_808003BC_bsbanswim(arg0);
}

/* extern */

void func_80800868_bsbanswim(s32 arg0) {
    s32 anctrl_setDuration(s32, s32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_8080040C_bsbanswim(s32);
    s32 sp1C;

    sp1C = baanim_getAnimCtrlPtr();
    func_8080040C_bsbanswim(arg0);
    anctrl_setDuration(sp1C, 0x3F333333);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ban/swim/func_808008A4_bsbanswim.s")

s32 bsbanswim_entrypoint_3(s32 arg0) {
    extern s32 D_80800A60_bsbanswim[];
    return ((s32 *)&D_80800A60_bsbanswim)[arg0];
}
