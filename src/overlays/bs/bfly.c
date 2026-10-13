#include "common.h"
#include "overlays/ba/playerstate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800000_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808000AC_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800128_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800188_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800248_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800320_bsbfly.s")

/* extern */

void func_808003E0_bsbfly(s32 arg0) {
    s32 func_800A0CF4(s32, s32);
    s32 func_800A4E30(s32);
    s32 func_800C6DA0(s32);
    func_800C6DA0(0x44);
    func_800A0CF4(arg0, 0);
    func_800A4E30(arg0);
}

s32 bsbfly_entrypoint_0(s32 arg0) {
    extern s32 D_80801D48_bsbfly[];
    return ((s32 *)&D_80801D48_bsbfly)[arg0];
}

void func_8080042C_bsbfly(s32 arg0)
{
    func_8009E6EC();
    func_80801BB4_bsbfly(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800454_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080050C_bsbfly.s")

void func_80800624_bsbfly(PlayerState *arg0) {
    s32 _baboost_entrypoint_1(void *);
    s32 _baboost_entrypoint_2(s32, s32);
    void _baboost_entrypoint_5(void *);
    void _bafly_entrypoint_10(void *, f32, f32);
    void _bafly_entrypoint_11(void *);
    s32 _bafly_entrypoint_12(void *);
    s32 _bafly_entrypoint_2(void *);
    void _bafly_entrypoint_20(void *);
    void _bafly_entrypoint_21(void *);
    void _bafly_entrypoint_7(void *, s32);
    void _bafly_entrypoint_8(void *, f32, f32, f32, f32, f32, f32, f32);
    void _bafly_entrypoint_9(void *);
    s32 _bafpctrl_entrypoint_4();
    s32 _chusefeather_entrypoint_1(s32, s32);
    s32 anctrl_isAt(s32, f32);
    void anctrl_setDuration(s32, f32);
    s32 baanim_getAnimCtrlPtr();
    s32 bainput_should_beak_bust(void *);
    s32 bakey_pressed(s32, s32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    s32 bs_setState(s32, s32);
    s32 func_8008D0E0(void *);
    f32 func_800136E4(f32);
    void func_8009BF5C(PlayerState *, f32);
    f32 func_8009BFD8(PlayerState *);
    void func_8009DFD4(void *, s32, f32, f32, s32, s32);
    f32 func_800D8FF8();
    f32 func_800F0E00(f32, f32);
    s32 player_inWater(void *);
    s32 next_state;
    s32 anim;
    f32 pitch;
    s32 boost;
    s32 flap;

    next_state = 0;
    anim = baanim_getAnimCtrlPtr(arg0);
    _bafly_entrypoint_20(arg0);
    _bafly_entrypoint_9(arg0);
    _bafly_entrypoint_10(arg0, 300.0f, 80.0f);
    _bafly_entrypoint_11(arg0);
    flap = 0;
    if (bakey_pressed((s32)arg0, 8)) {
        ((u8 *)arg0->kazfly)[0x1C] = 1;
    }
    if (((u8 *)arg0->kazfly)[0x1C] && func_8001211C() % 3 == 0) {
        ((u8 *)arg0->kazfly)[0x1C] = 0;
        flap = _bafly_entrypoint_12(arg0);
    }
    if (flap || arg0->unk15C.word) {
        if (flap) {
            anctrl_setDuration(anim, 0.3f);
            _chusefeather_entrypoint_1(arg0->unk184, 0);
        }
        if (arg0->unk15C.word) {
            arg0->unk15C.word = 0;
            _baboost_entrypoint_2((s32)arg0, 0x3EB33333);
        } else {
            _baboost_entrypoint_2((s32)arg0, 0x3F800000);
        }
    }
    boost = _baboost_entrypoint_1(arg0);
    _bafly_entrypoint_7(arg0, 0);
    switch (arg0->unk160.word) {
        case 0:
            if (boost) {
                arg0->unk160.word = 1;
            }
            break;
        case 1:
            _bafly_entrypoint_7(arg0, 1);
            pitch = func_800136E4(func_8009BFD8(arg0) - 30.0f);
            if (pitch > 80.0f && pitch < 300.0f) {
                pitch = 300.0f;
            }
            func_8009BF5C(arg0, pitch);
            _bafly_entrypoint_21(arg0);
            if (boost) {
                baphysics_set_vertical_velocity(arg0, boost * 400.0f);
            }
            if (!boost) {
                anctrl_setDuration(anim, 0.62f);
                _bafly_entrypoint_20(arg0);
                arg0->unk160.word = 0;
            }
            break;
    }
    if (anctrl_isAt(anim, 0.1358f)) {
        func_8009DFD4(arg0, 0x3FF, 0.6f, 0.7f, 10000, 12000);
    }
    _bafly_entrypoint_8(arg0, 300.0f, 80.0f, 600.0f, -300.0f, -99.9f, -700.0f, -1000.0f);
    if (_bafpctrl_entrypoint_4(arg0) != 3 && bainput_should_beak_bust(arg0)) {
        next_state = 0xF;
    }
    *(f32 *)arg0->kazfly = func_800F0E00(*(f32 *)arg0->kazfly - func_800D8FF8(), 0.0f);
    if (*(f32 *)arg0->kazfly == 0.0f && bakey_pressed((s32)arg0, 9) && func_8008D0E0(arg0) && _bafly_entrypoint_12(arg0)) {
        next_state = 0x2A;
    }
    if (player_inWater(arg0)) {
        next_state = 0x2D;
    }
    if (_bafly_entrypoint_2(arg0)) {
        next_state = 1;
    }
    _baboost_entrypoint_5(arg0);
    bs_setState((s32)arg0, next_state);
}

s32 bsbfly_entrypoint_1(s32 arg0) {
    extern s32 D_80801D58_bsbfly[];
    return ((s32 *)&D_80801D58_bsbfly)[arg0];
}

/* extern */

void func_808009D0_bsbfly(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EF04C(f32 *, f32 *);
    void func_800A34AC(PlayerState *, f32[3]);
    void func_8009DF58(PlayerState *, s32, f32);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_800EF04C(sp1C, (f32 *)(*(s32 *)((s8 *)arg0 + 0x188) + 0x10));
    func_800A34AC(arg0, sp1C);
    func_8009DF58(arg0, 0x40D, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800A24_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800C38_bsbfly.s")

void func_80800D50_bsbfly(s32 arg0) { s32 func_80800128_bsbfly(void); func_80800128_bsbfly(); (*(s32 *)((s8 *)(arg0) + 0x160)) = 0; func_80800A24_bsbfly(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800D80_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800F10_bsbfly.s")

void func_80801138_bsbfly(s32 arg0)
{
    func_80800A24_bsbfly(arg0,0);
    func_80800188_bsbfly(arg0);
}

s32 bsbfly_entrypoint_2(s32 arg0) {
    extern s32 D_80801D68_bsbfly[];
    return ((s32 *)&D_80801D68_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801178_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801208_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801334_bsbfly.s")

s32 bsbfly_entrypoint_3(s32 arg0) {
    extern s32 D_80801D78_bsbfly[];
    return ((s32 *)&D_80801D78_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080145C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808014E8_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808015C4_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808016B4_bsbfly.s")

/* extern */

void func_8080183C_bsbfly(s32 arg0) {
    s32 func_8008E95C(s32);
    s32 func_800A042C(s32);
    s32 func_800A0CF4(s32, s32);
    s32 func_800A4E30();
    func_800A4E30();
    func_800A042C(arg0);
    func_800A0CF4(arg0, 0);
    func_8008E95C(arg0);
}

s32 bsbfly_entrypoint_4(s32 arg0) {
    extern s32 D_80801D88_bsbfly[];
    return ((s32 *)&D_80801D88_bsbfly)[arg0];
}

/* extern */

void func_8080188C_bsbfly(s32 arg0) {
    s32 _bafly_entrypoint_13(s32, s32, s32, s32);
    s32 func_800A0CF4(s32, s32);
    s32 func_80800128_bsbfly();
    func_80800128_bsbfly();
    _bafly_entrypoint_13(arg0, 0, 0xD3, 0x3F99999A);
    func_800A0CF4(arg0, 1);
}

void func_808018D0_bsbfly(s32 arg0) {
    s32 _bafly_entrypoint_14(s32, s32, s32);
    _bafly_entrypoint_14(arg0, 0x24, 2);
}

void func_808018F4_bsbfly(s32 arg0) { s32 func_800A0CF4(s32, s32); func_800A0CF4(arg0, 0); _bafly_entrypoint_15(arg0); func_80800188_bsbfly(arg0); }

s32 bsbfly_entrypoint_5(s32 arg0) {
    extern s32 D_80801D98_bsbfly[];
    return ((s32 *)&D_80801D98_bsbfly)[arg0];
}

/* extern */

void func_8080193C_bsbfly(s32 arg0) {
    s32 _bafly_entrypoint_13(s32, s32, s32, s32);
    s32 func_800A0CF4(s32, s32);
    s32 func_80800128_bsbfly();
    func_80800128_bsbfly();
    _bafly_entrypoint_13(arg0, 1, 0xD3, 0x3F99999A);
    func_800A0CF4(arg0, 1);
}

void func_80801980_bsbfly(s32 arg0) {
    s32 _bafly_entrypoint_14(s32, s32, s32);
    _bafly_entrypoint_14(arg0, 0x24, 2);
}

void func_808019A4_bsbfly(s32 arg0) { s32 func_800A0CF4(s32, s32); func_800A0CF4(arg0, 0); _bafly_entrypoint_15(arg0); func_80800188_bsbfly(arg0); }

s32 bsbfly_entrypoint_6(s32 arg0) {
    extern s32 D_80801DA8_bsbfly[];
    return ((s32 *)&D_80801DA8_bsbfly)[arg0];
}

/* extern */

void func_808019EC_bsbfly(s32 arg0) {
    s32 _bafly_entrypoint_16(s32, s32, s32);
    s32 func_80800128_bsbfly();
    func_80800128_bsbfly();
    _bafly_entrypoint_16(arg0, 0x10D, 0x3F800000);
}

void func_80801A1C_bsbfly(s32 arg0) {
    s32 _bafly_entrypoint_17(s32, s32, s32, s32 *);
    _bafly_entrypoint_17(arg0, 0x24, 0x20, arg0 + 0x15C);
}

void func_80801A44_bsbfly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_80800188_bsbfly(arg0);
}
s32 bsbfly_entrypoint_7(s32 arg0) {
    extern s32 D_80801DB8_bsbfly[];
    return ((s32 *)&D_80801DB8_bsbfly)[arg0];
}

void func_80801A80_bsbfly(s32 arg0) {
    s32 func_80800128_bsbfly();
    s32 baanim_playForDuration_loopSmooth(s32, s32, f32);
    s32 func_8009FFD8(s32, s32, s32, s32, s32);
    s32 func_800A0CF4(s32, s32);
    s32 func_800A0024(s32);

    func_80800128_bsbfly(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x38, 0.62f);
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_800A0CF4(arg0, 1);
    func_800A0024(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801AEC_bsbfly.s")

void func_80801B80_bsbfly()
{
    func_80800188_bsbfly();
}

s32 bsbfly_entrypoint_8(s32 arg0) {
    extern s32 D_80801DC8_bsbfly[];
    return ((s32 *)&D_80801DC8_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801BB4_bsbfly.s")

/* extern */

void func_80801C58_bsbfly(s32 arg0) {
    s32 _badrone_entrypoint_3(s32);
    s32 _bsdrone_entrypoint_0(s32);
    s32 baphysics_set_type(s32, s32);
    s32 func_80800128_bsbfly();
    func_80800128_bsbfly();
    _bsdrone_entrypoint_0(arg0);
    if (_badrone_entrypoint_3(arg0) == 0xE) {
        baphysics_set_type(arg0, 7);
    }
}

void func_80801C9C_bsbfly(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void func_80801CBC_bsbfly(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80800188_bsbfly(arg0);
}
s32 bsbfly_entrypoint_9(s32 arg0) {
    extern s32 D_80801DD8_bsbfly[];
    return ((s32 *)&D_80801DD8_bsbfly)[arg0];
}
