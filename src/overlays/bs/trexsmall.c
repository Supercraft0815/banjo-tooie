#include "bs/trexsmall.h"

int func_80800000_bstrexsmall(PlayerState *arg0) {
    s32 func_800C6E38(s32);
    return bakey_pressed(arg0, BUTTON_B) && func_800C6E38(0x20);
}

int func_8080003C_bstrexsmall(PlayerState* arg0)
{
    return bakey_pressed(arg0, BUTTON_A);
}

void func_8080005C_bstrexsmall()
{
    func_80099B94();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_8080007C_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_808000C8_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800154_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_8080020C_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_808002B8_bstrexsmall.s")

void func_80800364_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800384_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_808003D0_bstrexsmall.s")

s32 bstrexsmall_entrypoint_0(s32 arg0) {
    extern s32 D_80801B08_bstrexsmall[];
    return ((s32 *)&D_80801B08_bstrexsmall)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/bstrexsmall_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/bstrexsmall_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/bstrexsmall_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800680_bstrexsmall.s")

/* extern */

void func_8080070C_bstrexsmall(PlayerState *arg0) {
    s32 baroll_setIdeal(s32, f32);
    void func_8009BF5C(PlayerState *, f32);
    s32 _basudie_entrypoint_6();
    _basudie_entrypoint_6();
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal((s32) arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800744_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800818_bstrexsmall.s")

s32 bstrexsmall_entrypoint_4(s32 arg0) {
    extern s32 D_80801B18_bstrexsmall[];
    return ((s32 *)&D_80801B18_bstrexsmall)[arg0];
}

void func_80800998_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_1();
    _bsdrone_entrypoint_2(arg0);
}
void func_808009C0_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_2();
    _bsdrone_entrypoint_0(arg0);
}
void func_808009E8_bstrexsmall(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstrexsmall_entrypoint_3(arg0);
}
s32 bstrexsmall_entrypoint_5(s32 arg0) {
    extern s32 D_80801B28_bstrexsmall[];
    return ((s32 *)&D_80801B28_bstrexsmall)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800A24_bstrexsmall.s")

void func_80800AF0_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800B10_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800B40_bstrexsmall.s")

s32 bstrexsmall_entrypoint_6(s32 arg0) {
    extern s32 D_80801B38_bstrexsmall[];
    return ((s32 *)&D_80801B38_bstrexsmall)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/bstrexsmall_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800CA4_bstrexsmall.s")

void func_80800E94_bstrexsmall(s32 arg0)
{
    func_80800CA4_bstrexsmall(arg0,0);
    bstrexsmall_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800EC0_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80800EF0_bstrexsmall.s")

s32 bstrexsmall_entrypoint_8(s32 arg0) {
    extern s32 D_80801B48_bstrexsmall[];
    return ((s32 *)&D_80801B48_bstrexsmall)[arg0];
}

void func_80801004_bstrexsmall(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexsmall_entrypoint_1(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_8080102C_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_8080106C_bstrexsmall.s")

s32 bstrexsmall_entrypoint_9(s32 arg0) {
    extern s32 D_80801B58_bstrexsmall[];
    return ((s32 *)&D_80801B58_bstrexsmall)[arg0];
}

void func_808010E8_bstrexsmall(s32 arg0)
{
    _babounce_entrypoint_3();
    bstrexsmall_entrypoint_1(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801110_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801150_bstrexsmall.s")

s32 bstrexsmall_entrypoint_10(s32 arg0) {
    extern s32 D_80801B68_bstrexsmall[];
    return ((s32 *)&D_80801B68_bstrexsmall)[arg0];
}

void func_808011A8_bstrexsmall(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstrexsmall_entrypoint_1(arg0);
}
void func_808011D0_bstrexsmall(s32 arg0)
{
    bstrexsmall_entrypoint_2();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_808011F8_bstrexsmall.s")

s32 bstrexsmall_entrypoint_11(s32 arg0) {
    extern s32 D_80801B78_bstrexsmall[];
    return ((s32 *)&D_80801B78_bstrexsmall)[arg0];
}

/* extern */

void func_80801258_bstrexsmall(PlayerState *arg0, s32 arg1) {
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_801013A8(f32 *, s32, s32);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_801013A8(sp1C, arg1, arg0->unk184);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801294_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_808013E8_bstrexsmall.s")

/* extern */

void func_80801414_bstrexsmall(void *arg0) {
    s32 func_80801294_bstrexsmall(void *, s32);
    (*(s8 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_80801294_bstrexsmall(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801438_bstrexsmall.s")

s32 bstrexsmall_entrypoint_12(s32 arg0) {
    extern s32 D_80801B88_bstrexsmall[];
    return ((s32 *)&D_80801B88_bstrexsmall)[arg0];
}

void func_808015BC_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_808015DC_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801688_bstrexsmall.s")

s32 bstrexsmall_entrypoint_13(s32 arg0) {
    extern s32 D_80801B98_bstrexsmall[];
    return ((s32 *)&D_80801B98_bstrexsmall)[arg0];
}

void func_80801718_bstrexsmall(s32 arg0)
{
    func_80090A2C();
    func_800951B4(arg0);
    bstrexsmall_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801748_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801844_bstrexsmall.s")

s32 bstrexsmall_entrypoint_14(s32 arg0) {
    extern s32 D_80801BA8_bstrexsmall[];
    return ((s32 *)&D_80801BA8_bstrexsmall)[arg0];
}

void func_80801970_bstrexsmall()
{
    bstrexsmall_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801990_bstrexsmall.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/trexsmall/func_80801A3C_bstrexsmall.s")

s32 bstrexsmall_entrypoint_15(s32 arg0) {
    extern s32 D_80801BB8_bstrexsmall[];
    return ((s32 *)&D_80801BB8_bstrexsmall)[arg0];
}
