#include "common.h"
#include "overlays/ba/playerstate.h"

void func_80800000_bsstonehead(PlayerState *arg0) {
    void func_80092864(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_80095A40(PlayerState *);
    void func_80095A74(void *, s32);
    s32 func_8009E74C(PlayerState *, s32);
    if (func_8009E74C(arg0, 3) == 0) {
        func_800947EC(arg0, 1, 0);
        func_80095A40(arg0);
        func_80092864(arg0, 1.0f);
        func_80095A74(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_80800060_bsstonehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_808000CC_bsstonehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_80800194_bsstonehead.s")

int func_808003B8_bsstonehead(s32 arg0) {
    s32 bakey_pressed(s32, s32);
    s32 func_800DA298(s32);
    return bakey_pressed(arg0, 8) && !func_800DA298(0x65A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_808003F4_bsstonehead.s")

void bsstonehead_entrypoint_0(s32 arg0)
{
    func_80800194_bsstonehead(arg0,0);
}

void bsstonehead_entrypoint_1(s32 *arg0) { arg0[87] = 0; func_80800194_bsstonehead(arg0, 1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_2.s")

s32 bsstonehead_entrypoint_3(s32 arg0) {
    extern s32 D_80801630_bsstonehead[];
    return ((s32 *)&D_80801630_bsstonehead)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_808005F0_bsstonehead.s")

/* extern */

void bsstonehead_entrypoint_4(s32 arg0) {
    s32 func_808005F0_bsstonehead(s32, s32);
    func_80800060_bsstonehead(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_808005F0_bsstonehead(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_5.s")

void bsstonehead_entrypoint_6()
{
    _basudie_entrypoint_6();
}

s32 bsstonehead_entrypoint_7(s32 arg0) {
    extern s32 D_80801640_bsstonehead[];
    return ((s32 *)&D_80801640_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_8(s32 arg0)
{
    func_80800060_bsstonehead();
    _bsdrone_entrypoint_0(arg0);
}
void bsstonehead_entrypoint_9(PlayerState* self)
{
    _bsdrone_entrypoint_1(self);
}
void bsstonehead_entrypoint_10(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    _bsdrone_entrypoint_2(arg0);
}
s32 bsstonehead_entrypoint_11(s32 arg0) {
    extern s32 D_80801650_bsstonehead[];
    return ((s32 *)&D_80801650_bsstonehead)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_808008CC_bsstonehead.s")

void bsstonehead_entrypoint_12(PlayerState *arg0)
{
    func_808008CC_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_14.s")

s32 bsstonehead_entrypoint_15(s32 arg0) {
    extern s32 D_80801660_bsstonehead[];
    return ((s32 *)&D_80801660_bsstonehead)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/func_80800B38_bsstonehead.s")

void bsstonehead_entrypoint_16(PlayerState *arg0)
{
    func_80800B38_bsstonehead(arg0,0);
    func_80800000_bsstonehead(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_18.s")

s32 bsstonehead_entrypoint_19(s32 arg0) {
    extern s32 D_80801670_bsstonehead[];
    return ((s32 *)&D_80801670_bsstonehead)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_21.s")

void bsstonehead_entrypoint_22(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    func_80090A2C(arg0);
}
s32 bsstonehead_entrypoint_23(s32 arg0) {
    extern s32 D_80801680_bsstonehead[];
    return ((s32 *)&D_80801680_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_24(PlayerState *arg0)
{
    _baspin_entrypoint_1();
    func_80800000_bsstonehead(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_25.s")

void bsstonehead_entrypoint_26(s32 arg0) {
    s32 _baspin_entrypoint_3(s32);
    s32 bs_setState(s32, s32);
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_baspin_entrypoint_3(arg0) == 2) {
        var_a1 = 0xB3;
    }
    bs_setState(arg0, var_a1);
}

s32 bsstonehead_entrypoint_27(s32 arg0) {
    extern s32 D_80801690_bsstonehead[];
    return ((s32 *)&D_80801690_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_28(PlayerState *arg0)
{
    _babounce_entrypoint_3();
    func_80800000_bsstonehead(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_29.s")

/* extern */

void bsstonehead_entrypoint_30(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 func_808000CC_bsstonehead(s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_808000CC_bsstonehead(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0xB3;
    }
    bs_setState(arg0, sp1C);
}

s32 bsstonehead_entrypoint_31(s32 arg0) {
    extern s32 D_808016A0_bsstonehead[];
    return ((s32 *)&D_808016A0_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_32(PlayerState *arg0)
{
    _bsrest_entrypoint_14();
    func_80800000_bsstonehead(arg0);
}
void bsstonehead_entrypoint_33(s32 arg0)
{
    func_80800060_bsstonehead();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void bsstonehead_entrypoint_34(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 bs_setState(s32, s32);
    s32 _bsrest_entrypoint_20();
    s32 var_a1;
    s32 sp1C;

    sp1C = 0;
    var_a1 = sp1C;
    if (_bsrest_entrypoint_20() != 0) {
        var_a1 = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, var_a1);
}

s32 bsstonehead_entrypoint_35(s32 arg0) {
    extern s32 D_808016B0_bsstonehead[];
    return ((s32 *)&D_808016B0_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_36(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_37.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_38.s")

s32 bsstonehead_entrypoint_39(s32 arg0) {
    extern s32 D_808016C0_bsstonehead[];
    return ((s32 *)&D_808016C0_bsstonehead)[arg0];
}

void bsstonehead_entrypoint_40(PlayerState *arg0)
{
    func_80800000_bsstonehead(arg0);
    func_80090A2C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_41.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/stonehead/bsstonehead_entrypoint_42.s")

s32 bsstonehead_entrypoint_43(s32 arg0) {
    extern s32 D_808016D0_bsstonehead[];
    return ((s32 *)&D_808016D0_bsstonehead)[arg0];
}
