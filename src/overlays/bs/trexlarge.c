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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808002E0_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808003C4_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808004B4_bstrexlarge.s")

void func_80800560_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800580_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808005D4_bstrexlarge.s")

s32 bstrexlarge_entrypoint_0(s32 arg0) {
    extern s32 D_80801990_bstrexlarge[];
    return ((s32 *)&D_80801990_bstrexlarge)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/bstrexlarge_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/bstrexlarge_entrypoint_2.s")

void bstrexlarge_entrypoint_3(s32 arg0) {
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x15D)));
    if (temp_v0 != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x15D))) = (u8) (temp_v0 - 1);
    }
}

void func_80800834_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
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
    bstrexlarge_entrypoint_1();
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800934_bstrexlarge.s")

void func_80800A00_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/bstrexlarge_entrypoint_7.s")

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

void func_80800F2C_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80800FC8_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80801008_bstrexlarge.s")

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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808010B0_bstrexlarge.s")

s32 bstrexlarge_entrypoint_11(s32 arg0) {
    extern s32 D_80801A00_bstrexlarge[];
    return ((s32 *)&D_80801A00_bstrexlarge)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80801110_bstrexlarge.s")

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
    bstrexlarge_entrypoint_1();
    func_80801208_bstrexlarge(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_8080126C_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808012EC_bstrexlarge.s")

s32 bstrexlarge_entrypoint_12(s32 arg0) {
    extern s32 D_80801A10_bstrexlarge[];
    return ((s32 *)&D_80801A10_bstrexlarge)[arg0];
}

void func_808014A4_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808014C4_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_80801574_bstrexlarge.s")

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

void func_808017DC_bstrexlarge(void)
{
    bstrexlarge_entrypoint_1();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808017FC_bstrexlarge.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexlarge/func_808018AC_bstrexlarge.s")

s32 bstrexlarge_entrypoint_15(s32 arg0) {
    extern s32 D_80801A40_bstrexlarge[];
    return ((s32 *)&D_80801A40_bstrexlarge)[arg0];
}
