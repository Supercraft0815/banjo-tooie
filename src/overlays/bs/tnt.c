#include "common.h"

void func_80800000_bstnt(void *arg0) {
    void func_8009DF94(void *, s32, f32, s32);
    func_8009DF94(arg0, 0x504, 1.0f, 0x7FFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800028_bstnt.s")

void func_80800060_bstnt(s32 arg0) 
{
}
void func_80800068_bstnt(void *arg0) {
    extern s32 D_80802230_bstnt;
    (*(s8 *)((s8 *)(arg0) + (0x160))) = func_8009D454(arg0, 0, &D_80802230_bstnt);
}

/* extern */

void func_8080009C_bstnt(void *arg0) {
    s32 func_800C2FDC(s32, u8, void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x160)));
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1 & 0xFF, temp_a1, arg0);
    }
    (*(u8 *)((s8 *)(arg0) + (0x160))) = 0U;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808000D4_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800164_bstnt.s")

/* extern */

 s32 func_808001C8_bstnt(void *arg0, s32 arg1) {
    s32 bakey_pressed(void *, s32);
    s32 bstnt_entrypoint_8(void *);

    if (bakey_pressed(arg0, 8) != 0) {
        arg1 = 0x107;
    }
    if (bstnt_entrypoint_8(arg0) != 0) {
        arg1 = 0x10E;
    }
    return arg1;
}

/* extern */

s32 func_80800218_bstnt(void *arg0, s32 arg1) {
    s32 _badrone_entrypoint_24(void *);
    s32 bainput_should_enter_first_person();
    s32 bakey_pressed(void *, s32);
    s32 bstnt_entrypoint_8(void *);
    int player_isStable(void *);
    s32 var_s1;

    var_s1 = arg1;
    if (bainput_should_enter_first_person() != 0) {
        var_s1 = _badrone_entrypoint_24(arg0);
    }
    if (bakey_pressed(arg0, 8) != 0) {
        var_s1 = 0x107;
    }
    if (bstnt_entrypoint_8(arg0) != 0) {
        var_s1 = 0x10E;
    }
    if (((*(u8 *)((s8 *)(arg0) + (0x168))) != 0) && (player_isStable(arg0) != 0)) {
        var_s1 = 0x10D;
    }
    return var_s1;
}

void func_808002AC_bstnt(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_8080223C_bstnt;
    extern s32 D_80802284_bstnt;
    func_800BBCB8(arg1, 0, 0x3F800000, 8, &D_8080223C_bstnt);
    func_800BBCB8(arg1, 0, 0x3F800000, 0xC, &D_80802284_bstnt);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080030C_bstnt.s")

void func_808004F8_bstnt(s32 arg0, f32 *arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800A4C48(s32);
    s32 func_800CA3F4(s32, f32 *, s32);
    extern s32 D_808022FC_bstnt;
    f32 sp24[3];

    func_800EE7F8(sp24, arg1);
    func_800CA3F4(func_800A4C48(arg0), sp24, 0x42A00000);
    func_800BBCB8((s32) sp24, 0, 0x3F800000, 1, &D_808022FC_bstnt);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800554_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808005F4_bstnt.s")

/* extern */

void func_80800668_bstnt(s32 arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_8009E474();
    func_8009E474();
    baflag_clear(arg0, 0x32);
}

void func_80800694_bstnt()
{
    func_8009E4AC();
}

/* extern */

void func_808006B4_bstnt(u8 *arg0, s32 arg1) {
    void baflag_set(void *, s32);
    void func_8009E55C(void *, s32, f32);
    (*(s8 *)((s8 *)(arg0) + (0x169))) = arg1;
    baflag_set(arg0, 0x32);
    func_8009E55C(arg0, 1, 200.0f);
}

/* extern */

void func_808006EC_bstnt(s32 arg0) {
    s32 baflag_clear(s32, s32);
    void func_8009E55C(void *, s32, f32);
    func_8009E55C(arg0, 1, 28.0f);
    baflag_clear(arg0, 0x32);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800720_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808007EC_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080092C_bstnt.s")

/* extern */

void func_80800960_bstnt(s32 arg0) {
    s32 func_808007EC_bstnt(s32, s32);
    func_80800694_bstnt();
    func_80800060_bstnt(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_808007EC_bstnt(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800998_bstnt.s")

s32 bstnt_entrypoint_0(s32 arg0) {
    extern s32 D_808023F8_bstnt[];
    return ((s32 *)&D_808023F8_bstnt)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800B60_bstnt.s")

void func_80800CB0_bstnt(s32 arg0)
{
    func_80800028_bstnt();
    func_800951B4(arg0);
}
/* extern */

void func_80800CD8_bstnt(s32 arg0) {
    s32 func_80800B60_bstnt(s32, s32);
    func_80800060_bstnt(arg0);
    (*(s32 *)((s8 *)(arg0) + (0x15C))) = 0;
    func_80800B60_bstnt(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80800D08_bstnt.s")

s32 bstnt_entrypoint_1(s32 arg0) {
    extern s32 D_80802408_bstnt[];
    return ((s32 *)&D_80802408_bstnt)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/bstnt_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/bstnt_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/bstnt_entrypoint_4.s")

void func_80801058_bstnt(s32 arg0)
{
    _basudie_entrypoint_8();
    bstnt_entrypoint_2(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801080_bstnt.s")

void func_80801190_bstnt(s32 arg0)
{
    _basudie_entrypoint_10();
    bstnt_entrypoint_4(arg0);
}
s32 bstnt_entrypoint_5(s32 arg0) {
    extern s32 D_8080254C_bstnt[];
    return ((s32 *)&D_8080254C_bstnt)[arg0];
}

void func_808011CC_bstnt(s32 arg0)
{
    bstnt_entrypoint_3();
    _bsdrone_entrypoint_0(arg0);
}
void func_808011F4_bstnt(s32 arg0)
{
    _bsdrone_entrypoint_1();
    bstnt_entrypoint_4(arg0);
}
void func_8080121C_bstnt(s32 arg0)
{
    bstnt_entrypoint_2();
    _bsdrone_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_6(s32 arg0) {
    extern s32 D_8080255C_bstnt[];
    return ((s32 *)&D_8080255C_bstnt)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801258_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808012F8_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801464_bstnt.s")

s32 bstnt_entrypoint_7(s32 arg0) {
    extern s32 D_8080256C_bstnt[];
    return ((s32 *)&D_8080256C_bstnt)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/bstnt_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080150C_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080166C_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_808018D0_bstnt.s")

s32 bstnt_entrypoint_9(s32 arg0) {
    extern s32 D_8080257C_bstnt[];
    return ((s32 *)&D_8080257C_bstnt)[arg0];
}

/* extern */

void bstnt_entrypoint_10(void *arg0) {
    s32 func_80099A4C(void *);
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    if (func_8009E6EC() == 0x42) {
        (*(s32 *)((s8 *)(arg0) + (0x164))) = func_80099A4C(arg0);
        (*(s8 *)((s8 *)(arg0) + (0x168))) = 1;
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801980_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801C0C_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801C3C_bstnt.s")

void func_80801E20_bstnt(s32 arg0)
{
    func_80801980_bstnt(arg0,0);
    bstnt_entrypoint_2(arg0);
}

s32 bstnt_entrypoint_11(s32 arg0) {
    extern s32 D_8080258C_bstnt[];
    return ((s32 *)&D_8080258C_bstnt)[arg0];
}

void func_80801E60_bstnt(s32 arg0) { bstnt_entrypoint_3(); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801EA0_bstnt.s")

void func_80801F20_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_12(s32 arg0) {
    extern s32 D_8080259C_bstnt[];
    return ((s32 *)&D_8080259C_bstnt)[arg0];
}

void func_80801F5C_bstnt(s32 arg0) { bstnt_entrypoint_3(); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0xE9, (s32) 0x3ED0FF97); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80801F9C_bstnt.s")

void func_80802000_bstnt(s32 arg0)
{
    _babounce_entrypoint_3();
    bstnt_entrypoint_2(arg0);
}
s32 bstnt_entrypoint_13(s32 arg0) {
    extern s32 D_808025AC_bstnt[];
    return ((s32 *)&D_808025AC_bstnt)[arg0];
}

void func_8080203C_bstnt(s32 arg0)
{
    _bsrest_entrypoint_14();
    bstnt_entrypoint_2(arg0);
}
void func_80802064_bstnt(s32 arg0)
{
    bstnt_entrypoint_3();
    _bsrest_entrypoint_16(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080208C_bstnt.s")

s32 bstnt_entrypoint_14(s32 arg0) {
    extern s32 D_808025BC_bstnt[];
    return ((s32 *)&D_808025BC_bstnt)[arg0];
}

void func_808020EC_bstnt(s32 arg0)
{
    bstnt_entrypoint_2();
    func_80090A2C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_80802114_bstnt.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/tnt/func_8080217C_bstnt.s")

s32 bstnt_entrypoint_15(s32 arg0) {
    extern s32 D_808025CC_bstnt[];
    return ((s32 *)&D_808025CC_bstnt)[arg0];
}
