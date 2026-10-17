#include "bs/trexlarge.h"

void func_80800000_bstrexlarge(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x168))) = 5;
}

void func_8080000C_bstrexlarge(void *arg0) {
    s32 temp_v0;

    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x168)));
    if (temp_v0 > 0) {
        (*(s32 *)((s8 *)(arg0) + (0x168))) = (s32) (temp_v0 - 1);
    }
}

s32 func_80800024_bstrexlarge(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x168))) == 0;
}

s32 func_80800034_bstrexlarge(void *arg0) {
    return (*(s32 *)((s8 *)(arg0) + (0x164))) >= 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800044_bstrexlarge.s")

int func_80800140_bstrexlarge(s32 arg0)
{
    return bakey_pressed(arg0,BUTTON_B);
}

int func_80800160_bstrexlarge(s32 arg0)
{
    return bakey_pressed(arg0,BUTTON_A);
}

void func_80800180_bstrexlarge(PlayerState *arg0, void (*arg1)(PlayerState *)) {
    s32 func_8009E6EC();
    void func_8009E830(PlayerState *, s32);

    switch (func_8009E6EC(arg0)) {
        case 0x20:
        case 0x21:
        case 0x2E:
        case 0x4E:
        case 0x51:
        case 0x52:
        case 0x59:
        case 0x5A:
        case 0x5B:
        case 0x5C:
        case 0x91:
            func_8009E830(arg0, 1);
            break;
        case 0x7E:
            *((s8 *)arg0 + 0x15D) = 2;
            break;
        default:
            arg1(arg0);
            break;
    }
}

s32 func_8080024C_bstrexlarge(s32 arg0) {
    void func_80099B94(PlayerState *);
    func_80800180_bstrexlarge((PlayerState *) arg0, func_80099B94);
}

void func_80800270_bstrexlarge(s32 *arg0) {
    extern s32 _bsdrone_entrypoint_3;
    func_80800180_bstrexlarge(arg0, &_bsdrone_entrypoint_3);
}

/* extern */

void func_80800294_bstrexlarge(s32 arg0) {
    s32 func_8009E6EC();
    s32 func_8080024C_bstrexlarge(s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    if ((temp_v0 != 0x1C) && (temp_v0 != 0x1D) && (temp_v0 != 0x1E) && (temp_v0 != 0x25)) {
        func_8080024C_bstrexlarge(arg0);
    }
}

s32 func_808002E0_bstrexlarge(PlayerState *arg0, s32 arg1, s32 arg2) {
    s32 bastick_getZone(PlayerState *);
    s32 bs_getCurrentState(PlayerState *);
    int func_8008DD04(PlayerState *);
    s32 state;
    s32 can_fall;

    if (arg2 != 0) {
        can_fall = func_80800024_bstrexlarge(arg0);
    } else {
        can_fall = 1;
    }
    switch (bastick_getZone(arg0)) {
        case 0:
            state = 0x151;
            break;
        case 1:
            state = 0x152;
            break;
        case 2:
            state = 0x150;
            break;
    }
    if (bs_getCurrentState(arg0) != state) {
        arg1 = state;
    }
    if (func_80800140_bstrexlarge((s32) arg0) != 0) {
        arg1 = 0x14F;
    }
    if ((can_fall != 0) && (func_8008DD04(arg0) != 0)) {
        arg1 = 0x14A;
    }
    if (func_80800160_bstrexlarge((s32) arg0) != 0) {
        arg1 = 0x14B;
    }
    return arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808003C4_bstrexlarge.s")

void func_808004B4_bstrexlarge(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp24;

    sp24 = bastick_getZonePosition(arg0);
    switch (bastick_getZone(arg0)) {
        case 0:
            baphysics_set_target_horizontal_velocity(arg0, 0.0f);
            break;
        case 1:
            baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 100.0f, 400.0f));
            break;
        case 2:
            baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp24, 400.0f, 1000.0f));
            break;
    }
}

void bstrexlarge_entrypoint_1(PlayerState *);

void func_80800560_bstrexlarge(PlayerState *arg0)
{
    bstrexlarge_entrypoint_1(arg0);
}
void func_80800580_bstrexlarge(PlayerState *arg0) { bstrexlarge_entrypoint_2(); func_8009FFD8(arg0, 1, 3, 3, 2); yaw_setVelocityBounded((s32)arg0, 0x43960000, 0x40600000); func_80800000_bstrexlarge(arg0); }

void func_808005D4_bstrexlarge(PlayerState *arg0) {
    int baanim_isStopped(PlayerState *);
    s32 bs_setState(s32, s32);
    void bstrexlarge_entrypoint_3(s32);
    s32 func_808003C4_bstrexlarge(s32, s32, s32);
    s32 sp24;

    sp24 = 0;
    func_8080000C_bstrexlarge(arg0);
    bstrexlarge_entrypoint_3((s32)arg0);
    if (baanim_isStopped(arg0) != 0) {
        sp24 = 0x151;
    }
    bs_setState((s32)arg0, func_808003C4_bstrexlarge((s32)arg0, sp24, 1));
}

s32 bstrexlarge_entrypoint_0(s32 arg0) {
    extern s32 D_80801990_bstrexlarge[];
    return ((s32 *)&D_80801990_bstrexlarge)[arg0];
}

void bstrexlarge_entrypoint_1(PlayerState *arg0) {
    void baphysics_reset_gravity(PlayerState *);
    void bastick_popZone(PlayerState *);
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_8009590C(PlayerState *, f32);
    void func_80095964(void *, s32);
    void func_80095A40(PlayerState *);
    void func_8009E474(PlayerState *);
    s32 func_8009E74C(PlayerState *, s32);
    void func_800A4D6C(u8 *, f32, f32);

    if (func_8009E74C(arg0, 0x11) == 0) {
        bastick_popZone(arg0);
        func_800A4D6C(arg0, 1.0f, 1.0f);
        func_80092864(arg0, 1.0f);
        func_8009E474(arg0);
        func_80095A40(arg0);
        func_8009590C(arg0, 0.0f);
        baphysics_reset_gravity(arg0);
        func_80095964(arg0, 0);
        func_800947EC(arg0, 1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/bstrexlarge_entrypoint_2.s")

void bstrexlarge_entrypoint_3(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x15D)));
    if (temp_v0 != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x15D))) = (u8) (temp_v0 - 1);
    }
}

void func_80800834_bstrexlarge(PlayerState *arg0)
{
    bstrexlarge_entrypoint_1(arg0);
}
void func_80800854_bstrexlarge()
{
    bstrexlarge_entrypoint_2();
}

void func_80800874_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_3(arg0);
}

s32 bstrexlarge_entrypoint_4(s32 arg0) {
    extern s32 D_808019A0_bstrexlarge[];
    return ((s32 *)&D_808019A0_bstrexlarge)[arg0];
}

void func_808008A8_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_1(arg0);
    _bsdrone_entrypoint_2(arg0);
}
void func_808008D0_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_2();
    _bsdrone_entrypoint_0(arg0);
}
void func_808008F8_bstrexlarge(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstrexlarge_entrypoint_3(arg0);
}
s32 bstrexlarge_entrypoint_5(s32 arg0) {
    extern s32 D_808019B0_bstrexlarge[];
    return ((s32 *)&D_808019B0_bstrexlarge)[arg0];
}

void func_80800934_bstrexlarge(void *arg0, s32 arg1) {
    struct anctrl_s;
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex();
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    void baanim_setEndAndDuration(PlayerState *, f32, f32);
    struct anctrl_s *control;

    control = baanim_getAnimCtrlPtr(arg0);
    switch (arg1) {
        case 1:
            anctrl_reset(control);
            anctrl_setIndex(control, 0x1D1);
            anctrl_setDuration(control, 4.0f);
            anctrl_setSubrange(control, 0.0f, 0.715f);
            anctrl_setPlaybackType(control, 1);
            anctrl_setStart(control, 0.45f);
            anctrl_start(control);
            break;
        case 2:
            baanim_setEndAndDuration(arg0, 1.0f, 0.8f);
            break;
    }
    *(s8 *)((u8 *)arg0 + 0x15C) = arg1;
}

void func_80800A00_bstrexlarge(PlayerState *arg0)
{
    bstrexlarge_entrypoint_1(arg0);
}
void func_80800A20_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_2();
    *(u8 *)((u8 *)arg0 + 0x15C) = 0;
    func_80800934_bstrexlarge(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800A50_bstrexlarge.s")

s32 bstrexlarge_entrypoint_6(s32 arg0) {
    extern s32 D_808019C0_bstrexlarge[];
    return ((s32 *)&D_808019C0_bstrexlarge)[arg0];
}

/* extern */

s32 bstrexlarge_entrypoint_7(PlayerState *arg0, f32 *arg1) {
    s32 func_8008DAE8(PlayerState *, f32 *, f32);
    void func_8009C128(PlayerState *, f32[3]);
    f32 func_800EFC7C(f32 *, f32 *);
    f32 temp_f0;
    f32 sp18[3];

    func_8009C128(arg0, sp18);
    temp_f0 = func_800EFC7C(sp18, arg1);
    if (temp_f0 < 160000.0f) {
        return 1;
    }
    if (temp_f0 > 2250000.0f) {
        return 0;
    }
    if (func_8008DAE8(arg0, arg1, 90.0f) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800BC4_bstrexlarge.s")

void func_80800DAC_bstrexlarge(s32 arg0)
{
    func_80800BC4_bstrexlarge(arg0,0);
    bstrexlarge_entrypoint_1(arg0);
}

void func_80800DD8_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_2();
    *(u8 *)((u8 *)arg0 + 0x15C) = 0;
    func_80800BC4_bstrexlarge(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800E08_bstrexlarge.s")

s32 bstrexlarge_entrypoint_8(s32 arg0) {
    extern s32 D_808019D0_bstrexlarge[];
    return ((s32 *)&D_808019D0_bstrexlarge)[arg0];
}

void func_80800F2C_bstrexlarge(PlayerState *arg0)
{
    bstrexlarge_entrypoint_1(arg0);
}
void func_80800F4C_bstrexlarge()
{
    bstrexlarge_entrypoint_2();
}

void func_80800F6C_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_3(arg0);
}

s32 bstrexlarge_entrypoint_9(s32 arg0) {
    extern s32 D_808019E0_bstrexlarge[];
    return ((s32 *)&D_808019E0_bstrexlarge)[arg0];
}

void func_80800FA0_bstrexlarge(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexlarge_entrypoint_1(arg0);
}
void func_80800FC8_bstrexlarge(s32 arg0) { bstrexlarge_entrypoint_2(); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0x147, (s32) 0x3F30A3D7); }

/* extern */

void func_80801008_bstrexlarge(s32 arg0) {
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    bstrexlarge_entrypoint_3(arg0);
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x151;
    }
    bs_setState(arg0, sp1C);
}

s32 bstrexlarge_entrypoint_10(s32 arg0) {
    extern s32 D_808019F0_bstrexlarge[];
    return ((s32 *)&D_808019F0_bstrexlarge)[arg0];
}

void func_80801060_bstrexlarge(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstrexlarge_entrypoint_1(arg0);
}
void func_80801088_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_2();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808010B0_bstrexlarge(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bstrexlarge_entrypoint_3(arg0);
    bs_setState(arg0, sp1C);
}

s32 bstrexlarge_entrypoint_11(s32 arg0) {
    extern s32 D_80801A00_bstrexlarge[];
    return ((s32 *)&D_80801A00_bstrexlarge)[arg0];
}

/* extern */

void func_80801110_bstrexlarge(PlayerState *arg0) {
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DF18(PlayerState *, s32, f32, s32);
    void func_8009E55C(PlayerState *, s32, f32);
    void func_8009E5A4(PlayerState *, s32, s32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    f32 sp24[3];

    func_8009C128(arg0, sp24);
    arg0->unk160.word = func_800E1610(0, 30.0f, 1.0f, sp24);
    func_8009DF18(arg0, 0x56C, 1.0f, 0x7FFF);
    func_8009E5A4(arg0, 2, 1);
    func_8009E55C(arg0, 2, 600.0f);
    _bamotor_entrypoint_1(arg0, 1.0f, 1.0f, 5.0f);
}

s32 func_808011A8_bstrexlarge(PlayerState *arg0) {
    void func_8009E55C(PlayerState *, s32, f32);
    s32 _bamotor_entrypoint_2(PlayerState *, s32, s32, s32);
    s32 func_800E144C(s32, s32);
    s32 temp_a2;

    temp_a2 = arg0->unk160.word;
    if (temp_a2 != -1) {
        func_800E144C(temp_a2, 0x3F5C28F6);
    }
    func_8009E55C(arg0, 2, 0.0f);
    return _bamotor_entrypoint_2(arg0, 0x3F800000, 0x3DCCCCCD, 0x3F000000);
}

/* extern */

void func_80801208_bstrexlarge(void *arg0) {
    s32 func_808011A8_bstrexlarge();
    func_808011A8_bstrexlarge();
    (*(s8 *)((s8 *)(arg0) + (0x15E))) = 0;
}

void func_80801230_bstrexlarge(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0x160))) = -1;
    (*(u8 *)((s8 *)(arg0) + (0x15E))) = (u8) (*(u8 *)((s8 *)(arg0) + (0x15D)));
}

void func_80801244_bstrexlarge(s32 arg0)
{
    bstrexlarge_entrypoint_1(arg0);
    func_80801208_bstrexlarge(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_8080126C_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808012EC_bstrexlarge.s")

s32 bstrexlarge_entrypoint_12(s32 arg0) {
    extern s32 D_80801A10_bstrexlarge[];
    return ((s32 *)&D_80801A10_bstrexlarge)[arg0];
}

void func_808014A4_bstrexlarge(PlayerState *arg0)
{
    bstrexlarge_entrypoint_1(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808014C4_bstrexlarge.s")

void func_80801574_bstrexlarge(PlayerState *arg0) {
    s32 bs_setState(s32, s32);
    void func_800A2D2C(PlayerState *, f32, s32);
    s32 func_808002E0_bstrexlarge(PlayerState *, s32, s32);

    func_8080000C_bstrexlarge(arg0);
    bstrexlarge_entrypoint_3((s32)arg0);
    func_808004B4_bstrexlarge(arg0);
    func_800A2D2C(arg0, 0.5702f, 3);
    func_800A2D2C(arg0, 0.0702f, 4);
    bs_setState((s32)arg0, func_808002E0_bstrexlarge(arg0, 0, 1));
}

s32 bstrexlarge_entrypoint_13(s32 arg0) {
    extern s32 D_80801A20_bstrexlarge[];
    return ((s32 *)&D_80801A20_bstrexlarge)[arg0];
}

void func_80801604_bstrexlarge(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bstrexlarge_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80801634_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808016B4_bstrexlarge.s")

s32 bstrexlarge_entrypoint_14(s32 arg0) {
    extern s32 D_80801A30_bstrexlarge[];
    return ((s32 *)&D_80801A30_bstrexlarge)[arg0];
}

void func_808017DC_bstrexlarge(PlayerState *arg0)
{
    bstrexlarge_entrypoint_1(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808017FC_bstrexlarge.s")

void func_808018AC_bstrexlarge(PlayerState *arg0) {
    s32 bs_setState(s32, s32);
    void func_800A2D2C(PlayerState *, f32, s32);
    s32 func_808002E0_bstrexlarge(PlayerState *, s32, s32);

    func_8080000C_bstrexlarge(arg0);
    bstrexlarge_entrypoint_3((s32)arg0);
    func_808004B4_bstrexlarge(arg0);
    func_800A2D2C(arg0, 0.8977f, 3);
    func_800A2D2C(arg0, 0.3977f, 4);
    bs_setState((s32)arg0, func_808002E0_bstrexlarge(arg0, 0, 1));
}

s32 bstrexlarge_entrypoint_15(s32 arg0) {
    extern s32 D_80801A40_bstrexlarge[];
    return ((s32 *)&D_80801A40_bstrexlarge)[arg0];
}
