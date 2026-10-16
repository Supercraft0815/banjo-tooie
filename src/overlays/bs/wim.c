#include "common.h"

void func_80800000_bsbswim(s32 arg0) {
    func_8009FFD8(arg0, 0x1, 0x3, 0x3, 0x9);
}

struct player_state_s;
void func_80800030_bsbswim(struct player_state_s *arg0) {
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

struct player_state_s;
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

void func_80800104_bsbswim(struct player_state_s *arg0) {
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

void func_808001A8_bsbswim(struct player_state_s *arg0)
{
    func_80800104_bsbswim(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_808001C8_bsbswim.s")

void func_80800288_bsbswim(s32 self)
{
    void _baswim_entrypoint_11(void *);
    void _baswim_entrypoint_12(void *);
    void _baswim_entrypoint_13(void *);
    s32 _baswim_entrypoint_3(s32);
    s32 _baswim_entrypoint_2(s32);
    s32 bs_setState(s32, s32);
    s32 func_8008E23C();
    s32 player_inWater();
    s32 next_state = 0;

    _baswim_entrypoint_11((void *)self);
    _baswim_entrypoint_12((void *)self);
    _baswim_entrypoint_13((void *)self);
    if (func_8008E23C(self)) {
        if (bakey_held(self, 8) || bakey_held(self, 9)) {
            next_state = 0x81;
        }
    } else {
        switch (_baswim_entrypoint_3((s32)self)) {
            case 0:
                break;
            case 1:
                next_state = 0x39;
                break;
            case 2:
                next_state = 0x2C;
                break;
            case 3:
                next_state = 0x19;
                break;
        }
        if (bainput_func_8009803C(self)) {
            next_state = 0x157;
        }
    }
    if (_baswim_entrypoint_2((s32)self)) {
        next_state = 0x2D;
    }
    if (!player_inWater(self)) {
        next_state = 1;
    }
    bs_setState((s32)self, next_state);
}

s32 bsbswim_entrypoint_0(s32 arg0) {
    extern s32 D_80801E60_bsbswim[];
    return ((s32 *)&D_80801E60_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_8080039C_bsbswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80800440_bsbswim.s")

void func_800910BC(struct player_state_s *, s32);

void func_808005F4_bsbswim(s32 arg0)
{
    func_800910BC(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_1(s32 arg0) {
    extern s32 D_80801E70_bsbswim[];
    return ((s32 *)&D_80801E70_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80800634_bsbswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_808006DC_bsbswim.s")

void func_808008CC_bsbswim(s32 arg0)
{
    func_800910BC(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_2(s32 arg0) {
    extern s32 D_80801E80_bsbswim[];
    return ((s32 *)&D_80801E80_bsbswim)[arg0];
}

void func_8080090C_bsbswim(struct player_state_s *arg0) {
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void _baswim_entrypoint_10(void *, f32);
    void _baswim_entrypoint_8(void *, f32);
    void func_8009BC5C(struct player_state_s *, f32);
    baanim_playForDuration_loopSmooth(arg0, 0x71, 0.75f);
    func_80800000_bsbswim((s32)arg0);
    func_80800030_bsbswim(arg0);
    _baswim_entrypoint_10(arg0, 250.0f);
    _baswim_entrypoint_8(arg0, 600.0f);
    func_8009BC5C(arg0, 2.0f);
    func_800910BC(arg0, 2);
}

void func_8080097C_bsbswim(s32 arg0) {
    void _baswim_entrypoint_10(void *, f32);
    void _baswim_entrypoint_11(void *);
    void _baswim_entrypoint_12(void *);
    void _baswim_entrypoint_13(void *);
    s32 _baswim_entrypoint_2(s32);
    s32 _baswim_entrypoint_3(s32);
    void func_8009DF18(s32, s32, f32, s32);
    s32 baanim_getAnimCtrlPtr();
    s32 anctrl_isAt(s32, f32);
    s32 bs_setState(s32, s32);
    s32 player_inWater();
    s32 sp24;
    s32 sp20;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    _baswim_entrypoint_11((void *)arg0);
    _baswim_entrypoint_12((void *)arg0);
    _baswim_entrypoint_13((void *)arg0);
    _baswim_entrypoint_10((void *)arg0, 250.0f);
    if (anctrl_isAt(sp20, 0.17f)) {
        func_8009DF18(arg0, 0x3FD, 1.9f, 0x2710);
    }
    if (anctrl_isAt(sp20, 0.67f)) {
        func_8009DF18(arg0, 0x3FD, 1.7f, 0x2710);
    }
    switch (_baswim_entrypoint_3((s32)arg0)) {
    case 0:
        if (anctrl_isAt(sp20, 0.4791f)) {
            sp24 = 0x2B;
        }
        break;
    case 1:
        break;
    case 2:
        sp24 = 0x2C;
        break;
    case 3:
        sp24 = 0x19;
        break;
    }
    if (bainput_func_8009803C(arg0)) {
        sp24 = 0x157;
    }
    if (_baswim_entrypoint_2((s32)arg0)) {
        sp24 = 0x2D;
    }
    if (!player_inWater(arg0)) {
        sp24 = 1;
    }
    bs_setState(arg0, sp24);
}

void func_80800AD0_bsbswim(s32 arg0)
{
    func_800910BC(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_3(s32 arg0) {
    extern s32 D_80801E90_bsbswim[];
    return ((s32 *)&D_80801E90_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80800B10_bsbswim.s")

/* extern */

struct player_state_s;
struct anctrl_s;
void func_800951B4(struct player_state_s *);
void func_80800C0C_bsbswim(struct player_state_s *arg0) {
    s32 anctrl_isStopped(struct anctrl_s *);
    s32 baanim_getAnimCtrlPtr();
    s32 baanim_isAt(void *, f32);
    s32 bs_setState(s32, s32);
    void func_8009C128(struct player_state_s *, f32[3]);
    s32 func_8009FBB0(struct player_state_s *, f32 *, f32);
    void func_800BA22C(s32, s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    s32 sp44;
    f32 sp38[3];
    s32 sp34;

    sp44 = 0;
    func_8009C128(arg0, sp38);
    sp38[1] += 60.0f;
    sp34 = func_8009FBB0(arg0, sp38, 25.0f);
    func_800BA930(sp34, -60, -50, -60, 60, 100, 60);
    func_800BA22C(sp34, 1);
    if (baanim_isAt(arg0, 0.3f) != 0) {
        func_800951B4(arg0);
    }
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0)) != 0) {
        sp44 = 0x2B;
    }
    bs_setState(arg0, sp44);
}

void func_80800CE4_bsbswim(s32 arg0) { func_8009BD88(); func_8008E95C(arg0); func_800951B4(arg0); func_80800104_bsbswim(arg0); }

s32 bsbswim_entrypoint_4(s32 arg0) {
    extern s32 D_80801EA0_bsbswim[];
    return ((s32 *)&D_80801EA0_bsbswim)[arg0];
}

void func_80800D30_bsbswim(s32 arg0)
{
    _baspin_entrypoint_1();
    func_80800104_bsbswim(arg0);
}
/* extern */

void func_80800D58_bsbswim(s32 arg0) {
    s32 _baspin_entrypoint_2(s32, s32, s32, s32, s32);
    void func_80800030_bsbswim(struct player_state_s *);
    func_80800030_bsbswim(arg0);
    _baspin_entrypoint_2(arg0, 0xB9, 0x3F333333, 3, 1);
}

/* extern */

void func_80800D98_bsbswim(s32 arg0) {
    s32 _baspin_entrypoint_3(s32);
    s32 bs_setState(s32, s32);
    s32 func_800914FC(s32, f32, s32);
    s32 sp1C;

    sp1C = 0;
    func_800914FC(arg0, 40.0f, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x2B;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbswim_entrypoint_5(s32 arg0) {
    extern s32 D_80801EB0_bsbswim[];
    return ((s32 *)&D_80801EB0_bsbswim)[arg0];
}

void func_80800DFC_bsbswim(u8 *arg0) { _babounce_entrypoint_3(); func_800961AC((s32)arg0, 3); func_80800104_bsbswim(arg0); }

/* extern */

void func_80800E30_bsbswim(s32 arg0) {
    s32 _babounce_entrypoint_4(s32, s32);
    s32 _babounce_entrypoint_5(s32, s32, s32);
    void func_80800030_bsbswim(struct player_state_s *);
    func_80800030_bsbswim(arg0);
    func_800961AC(arg0, 1);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0xF, 0x3F15119D);
}

/* extern */

void func_80800E7C_bsbswim(s32 arg0) {
    s32 _babounce_entrypoint_9();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_9() != 0) {
        sp1C = 0x2B;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbswim_entrypoint_6(s32 arg0) {
    extern s32 D_80801EC0_bsbswim[];
    return ((s32 *)&D_80801EC0_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80800EC8_bsbswim.s")

void func_80800F64_bsbswim(void *arg0) {
    s32 _baswim_entrypoint_1(void *);
    void _baswim_entrypoint_10(void *, f32);
    void _baswim_entrypoint_8(void *, f32);
    void _baswim_entrypoint_11(void *);
    void _baswim_entrypoint_13(void *);
    void func_800A0E64(void *);
    s32 baanim_getAnimCtrlPtr();
    s32 anctrl_isAt(s32, f32);
    void func_8009DE38(void *, s32, f32);
    s32 player_inWater();
    s32 bs_setState(s32, s32);
    s32 sp24;
    s32 sp20;
    u8 temp_v1;

    sp24 = 0;
    sp20 = baanim_getAnimCtrlPtr(arg0);
    temp_v1 = *(u8 *)((s8 *)arg0 + 0x164);
    switch (temp_v1) {
        case 0:
            func_8009BF5C(arg0, 50.0f);
            if (anctrl_isAt(sp20, 0.2916f) != 0) {
                if (_baswim_entrypoint_1(arg0) != 0) {
                    func_800A0E64(arg0);
                }
                _baswim_entrypoint_10(arg0, 400.0f);
                _baswim_entrypoint_8(arg0, 300.0f);
                *(u8 *)((s8 *)arg0 + 0x164) = 1;
            }
            break;
        case 1:
            _baswim_entrypoint_11(arg0);
            _baswim_entrypoint_13(arg0);
            if (anctrl_isAt(sp20, 0.58f) != 0) {
                sp24 = 0x2B;
            }
            break;
    }
    if (anctrl_isAt(sp20, 0.6f) != 0) {
        func_8009DE38(arg0, 0x3FD, 1.0f);
    }
    if (player_inWater(arg0) == 0) {
        sp24 = 1;
    }
    bs_setState((s32)arg0, sp24);
}

void func_80801084_bsbswim(struct player_state_s *arg0)
{
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_7(s32 arg0) {
    extern s32 D_80801ED0_bsbswim[];
    return ((s32 *)&D_80801ED0_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_808010B8_bsbswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_808011C0_bsbswim.s")

void func_808013C4_bsbswim(s32 arg0) {
    _baswim_entrypoint_6(arg0, 1);
    func_800910BC(arg0, 1);
    func_800A4E30(arg0);
    func_8008E95C(arg0);
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_8(s32 arg0) {
    extern s32 D_80801EE0_bsbswim[];
    return ((s32 *)&D_80801EE0_bsbswim)[arg0];
}

void func_80801428_bsbswim(void *arg0) {
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_8009B94C(u8 *, f32 *);
    void _baswim_entrypoint_9(struct player_state_s *, f32);
    void func_8009BA9C(struct player_state_s *, f32 *);
    void func_800A0024(struct player_state_s *);
    baanim_playForDuration_loopSmooth(arg0, 0x70, 2.0f);
    func_80800000_bsbswim((s32)arg0);
    func_8009B94C(arg0, 0);
    _baswim_entrypoint_9(arg0, 0.0f);
    func_8009BA9C(arg0, 0);
    func_80800030_bsbswim(arg0);
    func_800A0024(arg0);
    _baswim_entrypoint_6(arg0, 0);
}

/* extern */

void func_808014A0_bsbswim(s32 arg0) {
    s32 bs_setState(s32, s32);
    s32 func_8009CC68(s32);
    void func_800A0024();
    s32 player_inWater(s32);
    s32 sp1C;

    sp1C = 0;
    func_800A0024();
    if (player_inWater(arg0) == 0) {
        sp1C = 0x74;
    }
    if (func_8009CC68(arg0) == 0) {
        sp1C = 0x2B;
    }
    bs_setState(arg0, sp1C);
}

void func_808014F8_bsbswim(s32 arg0)
{
    _baswim_entrypoint_6(arg0,0x1);
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_9(s32 arg0) {
    extern s32 D_80801EF0_bsbswim[];
    return ((s32 *)&D_80801EF0_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80801538_bsbswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_808016B8_bsbswim.s")

void func_808017F8_bsbswim(struct player_state_s *arg0)
{
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_10(s32 arg0) {
    extern s32 D_80801F00_bsbswim[];
    return ((s32 *)&D_80801F00_bsbswim)[arg0];
}

void func_8080182C_bsbswim(s32 arg0) {
    s32 _bsdrone_entrypoint_0(s32);
    void func_80800030_bsbswim(struct player_state_s *);
    func_80800030_bsbswim(arg0);
    _bsdrone_entrypoint_0(arg0);
    func_8009BF5C((u8 *) arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

/* extern */

void func_8080186C_bsbswim(s32 arg0) {
    s32 _badrone_entrypoint_30();
    s32 _bsdrone_entrypoint_1(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_badrone_entrypoint_30() != 0) {
        sp1C = 187;
    }
    _bsdrone_entrypoint_1(arg0);
    bs_setState(arg0, sp1C);
}

void func_808018B0_bsbswim(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800104_bsbswim(arg0);
}
s32 bsbswim_entrypoint_11(s32 arg0) {
    extern s32 D_80801F10_bsbswim[];
    return ((s32 *)&D_80801F10_bsbswim)[arg0];
}

/* extern */

void func_808018EC_bsbswim(s32 arg0) {
    s32 func_80099AA8(s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    if (func_8009E6EC() == 0x11) {
        func_80099B94(arg0);
        return;
    }
    func_80099AA8(arg0);
}

void func_80801930_bsbswim(u8 *arg0) { s32 _baduo_entrypoint_7(u8 *, s32); if (arg0[0x165] != 0) _baduo_entrypoint_7(arg0, 3); func_80800104_bsbswim(arg0); }

/* extern */

void func_8080196C_bsbswim(struct player_state_s *arg0) {
    s32 baanim_playForDuration_onceSmooth(struct player_state_s *, s32, s32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(struct player_state_s *, f32 *);
    func_80800030_bsbswim(arg0);
    baanim_playForDuration_onceSmooth(arg0, 0x131, 0x3FC00000);
    func_80800000_bsbswim((s32) arg0);
    func_8009B94C(arg0, 0);
    func_8009BA9C(arg0, 0);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    (*(s8 *)((s8 *)(arg0) + (0x165))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_808019E0_bsbswim.s")

s32 bsbswim_entrypoint_12(s32 arg0) {
    extern s32 D_80801F78_bsbswim[];
    return ((s32 *)&D_80801F78_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80801ACC_bsbswim.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80801B84_bsbswim.s")

void func_80801C04_bsbswim(s32 arg0) 
{
}
void func_80801C0C_bsbswim(s32 arg0) {
    void _baswim_entrypoint_7(s32, s32, s32);
    func_80091104((s32 *)arg0, 1);
    _baswim_entrypoint_7(arg0, 1, 1);
    func_8009679C((void *)arg0);
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_13(s32 arg0) {
    extern s32 D_80801F88_bsbswim[];
    return ((s32 *)&D_80801F88_bsbswim)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/wim/func_80801C64_bsbswim.s")

/* extern */

void func_80801CE4_bsbswim(s32 arg0) {
    s32 _baswim_entrypoint_3(s32);
    s32 baanim_isStopped();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if ((baanim_isStopped() != 0) || (_baswim_entrypoint_3(arg0) != 0)) {
        sp1C = 0x2B;
    }
    bs_setState(arg0, sp1C);
}

void func_80801D30_bsbswim(struct player_state_s *arg0)
{
    func_80800104_bsbswim(arg0);
}

s32 bsbswim_entrypoint_14(s32 arg0) {
    extern s32 D_80801F98_bsbswim[];
    return ((s32 *)&D_80801F98_bsbswim)[arg0];
}
