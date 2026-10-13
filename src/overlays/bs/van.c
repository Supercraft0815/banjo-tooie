#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80800000_bsvan.s")

/* extern */

struct player_state_s;

s32 func_80800064_bsvan(struct player_state_s *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(struct player_state_s *);
    int bainput_should_enter_first_person(struct player_state_s *);
    int bakey_pressed();
    if (bainput_should_enter_first_person(arg0) != 0) {
        arg1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x115;
    }
    return arg1;
}

void func_808000BC_bsvan(u8 *arg0) {
    int bakey_pressed(void *, s32);
    if (bakey_pressed(arg0, 9) != 0) {
        _bavan_entrypoint_1(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/bsvan_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/bsvan_entrypoint_1.s")

void bsvan_entrypoint_2(s32 arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_8009C128(s32, f32 *);
    extern s32 D_80801B90_bsvan;
    f32 sp24[3];
    s32 sp20;

    sp20 = func_800B5BE4(8);
    func_8009C128(arg0, sp24);
    func_800BABB8(sp20, sp24, NULL, 1.0f, &D_80801B90_bsvan);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_8080032C_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/bsvan_entrypoint_3.s")

void func_808004F8_bsvan(s32 arg0)
{
    _basudie_entrypoint_6();
    bsvan_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80800520_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_808005E4_bsvan.s")

s32 bsvan_entrypoint_4(s32 arg0) {
    extern s32 D_80801C8C_bsvan[];
    return ((s32 *)&D_80801C8C_bsvan)[arg0];
}

void func_80800760_bsvan(s32 arg0)
{
    _bsdrone_entrypoint_2();
    bsvan_entrypoint_0(arg0);
}
void func_80800788_bsvan(s32 arg0)
{
    bsvan_entrypoint_1();
    _bsdrone_entrypoint_0(arg0);
}
void func_808007B0_bsvan(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bsvan_entrypoint_3(arg0);
}
s32 bsvan_entrypoint_5(s32 arg0) {
    extern s32 D_80801C9C_bsvan[];
    return ((s32 *)&D_80801C9C_bsvan)[arg0];
}

/* extern */

void func_808007EC_bsvan(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bsvan_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80800824_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_808008D4_bsvan.s")

s32 bsvan_entrypoint_6(s32 arg0) {
    extern s32 D_80801CAC_bsvan[];
    return ((s32 *)&D_80801CAC_bsvan)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80800A5C_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80800BDC_bsvan.s")

void func_80800E0C_bsvan(s32 arg0) {
    void func_8009BF5C(s32, f32);
    void baroll_setIdeal(s32, f32);
    baphysics_reset_gravity();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    bsvan_entrypoint_0(arg0);
}

s32 bsvan_entrypoint_7(s32 arg0) {
    extern s32 D_80801CBC_bsvan[];
    return ((s32 *)&D_80801CBC_bsvan)[arg0];
}

/* extern */

void func_80800E60_bsvan(u8 *arg0, s32 (*arg1)(u8 *)) {
    s32 _chfaircoinbox_entrypoint_0(s32, u8 *);
    s32 bs_setState(u8 *, s32);
    s32 func_80099A4C(u8 *);
    s32 func_8009E6EC();
    s32 func_8009E830(u8 *, s32);
    s32 temp_v0;
    u8 *temp_v1;

    temp_v0 = func_8009E6EC(arg0);
    switch (temp_v0) {
    case 0x46:
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x188)))) + (0))) = func_80099A4C(arg0);
        temp_v1 = (*(u8 **)((s8 *)(arg0) + (0x188)));
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x188)))) + (0x10))) = _chfaircoinbox_entrypoint_0((*(s32 *)((s8 *)(temp_v1) + (0))), temp_v1 + 4);
        func_8009E830(arg0, 2);
        bs_setState(arg0, 0x121);
        return;
    default:
        arg1(arg0);
        /* fallthrough */
    case 0x1F:
    case 0x20:
    case 0x21:
    case 0x2E:
    case 0x4E:
    case 0x51:
    case 0x52:
        return;
    }
}

void bsvan_entrypoint_8(s32 *arg0) {
    extern s32 func_80099B94;
    func_80800E60_bsvan(arg0, &func_80099B94);
}

void bsvan_entrypoint_9(s32 *arg0) {
    extern s32 _bsdrone_entrypoint_3;
    func_80800E60_bsvan(arg0, &_bsdrone_entrypoint_3);
}

void func_80800F50_bsvan()
{
    bsvan_entrypoint_0();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80800F70_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80801034_bsvan.s")

s32 bsvan_entrypoint_10(s32 arg0) {
    extern s32 D_80801CCC_bsvan[];
    return ((s32 *)&D_80801CCC_bsvan)[arg0];
}

void func_80801118_bsvan(s32 arg0)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(arg0);
}
/* extern */

struct anctrl_s;

void func_80801140_bsvan(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bsvan_entrypoint_1();
    _babounce_entrypoint_4(arg0, 1);
    _babounce_entrypoint_5(arg0, 0xEF, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80801198_bsvan.s")

s32 bsvan_entrypoint_11(s32 arg0) {
    extern s32 D_80801CDC_bsvan[];
    return ((s32 *)&D_80801CDC_bsvan)[arg0];
}

void func_80801224_bsvan(s32 arg0)
{
    _babounce_entrypoint_3();
    bsvan_entrypoint_0(arg0);
}
void func_8080124C_bsvan(struct player_state_s *arg0) {
    void _babounce_entrypoint_4(struct player_state_s *, s32);
    void _babounce_entrypoint_5(struct player_state_s *, s32, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    bsvan_entrypoint_1();
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0xEF, 0.5128f);
    func_8008B10C(baanim_getAnimCtrlPtr(arg0), 0.1026f);
}

/* extern */

void func_808012A4_bsvan(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(u8 *, s32);
    s32 func_80800000_bsvan(s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_80800000_bsvan(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x11A;
    }
    bs_setState(arg0, sp1C);
}

s32 bsvan_entrypoint_12(s32 arg0) {
    extern s32 D_80801CEC_bsvan[];
    return ((s32 *)&D_80801CEC_bsvan)[arg0];
}

void func_8080130C_bsvan(s32 arg0)
{
    _bsrest_entrypoint_14();
    bsvan_entrypoint_0(arg0);
}
void func_80801334_bsvan(s32 arg0)
{
    bsvan_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
void func_8080135C_bsvan(u8 *arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(u8 *, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bsvan_entrypoint_3(arg0);
    bs_setState(arg0, sp1C);
}

s32 bsvan_entrypoint_13(s32 arg0) {
    extern s32 D_80801CFC_bsvan[];
    return ((s32 *)&D_80801CFC_bsvan)[arg0];
}

void func_808013BC_bsvan(s32 arg0)
{
    bsvan_entrypoint_0();
    func_80090A2C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_808013E4_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_8080145C_bsvan.s")

s32 bsvan_entrypoint_14(s32 arg0) {
    extern s32 D_80801D70_bsvan[];
    return ((s32 *)&D_80801D70_bsvan)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_8080164C_bsvan.s")

void func_80801770_bsvan(void *arg0) { s32 _chfaircoinbox_entrypoint_1(s32); _chfaircoinbox_entrypoint_1(*(*(s32 **)((s8 *)(arg0) + 0x188))); bsvan_entrypoint_0(arg0); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_808017A0_bsvan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/bsvan_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/van/func_80801890_bsvan.s")

s32 bsvan_entrypoint_16(s32 arg0) {
    extern s32 D_80801D80_bsvan[];
    return ((s32 *)&D_80801D80_bsvan)[arg0];
}
