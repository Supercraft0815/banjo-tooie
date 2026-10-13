#include "common.h"

void func_80800000_bsbeemain(s32 arg0) {
    s32 func_8009DF18(s32, s32, f32, s32);
    func_8009DF18(arg0, 0x41F, 1.4f, 0x1F40);
}

/* extern */

void func_8080002C_bsbeemain(s32 arg0) {
    s32 func_8009D7A4(s32, f32, f32);
    func_8009D7A4(arg0, 1.35f, 1.45f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800058_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808000C0_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800128_bsbeemain.s")

void func_808001FC_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_0(s32 arg0) {
    extern s32 D_80801260_bsbeemain[];
    return ((s32 *)&D_80801260_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800238_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808002C0_bsbeemain.s")

void func_808003B4_bsbeemain(s32 arg0)
{
    func_80090A2C();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_1(s32 arg0) {
    extern s32 D_80801270_bsbeemain[];
    return ((s32 *)&D_80801270_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808003F0_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800548_bsbeemain.s")

void func_80800788_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_0();
    baphysics_reset_gravity(arg0);
}
s32 bsbeemain_entrypoint_2(s32 arg0) {
    extern s32 D_80801280_bsbeemain[];
    return ((s32 *)&D_80801280_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808007C4_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800874_bsbeemain.s")

void func_80800A74_bsbeemain()
{
    _bsbee_entrypoint_0();
}

s32 bsbeemain_entrypoint_3(s32 arg0) {
    extern s32 D_80801290_bsbeemain[];
    return ((s32 *)&D_80801290_bsbeemain)[arg0];
}

void bsbeemain_entrypoint_4(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void _babounce_entrypoint_5(s32, s32, f32);
void bsbeemain_entrypoint_5(s32 arg0) { _bsbee_entrypoint_1(); _babounce_entrypoint_4(arg0, 1); _babounce_entrypoint_5(arg0, 0x1E0, 0.7518f); }

/* extern */

void bsbeemain_entrypoint_6(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x85;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbeemain_entrypoint_7(s32 arg0) {
    extern s32 D_808012A0_bsbeemain[];
    return ((s32 *)&D_808012A0_bsbeemain)[arg0];
}

void func_80800B68_bsbeemain(s32 arg0)
{
    _babounce_entrypoint_3();
    _bsbee_entrypoint_0(arg0);
}
void func_80800B90_bsbeemain(s32 arg0) { _bsbee_entrypoint_1(); _babounce_entrypoint_4(arg0, 2); _babounce_entrypoint_5(arg0, 0x1E0, 0.7518f); }

/* extern */

void func_80800BD0_bsbeemain(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x85;
    }
    bs_setState(arg0, sp1C);
}

s32 bsbeemain_entrypoint_8(s32 arg0) {
    extern s32 D_808012B0_bsbeemain[];
    return ((s32 *)&D_808012B0_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800C28_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800E0C_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80800FB8_bsbeemain.s")

/* extern */

void func_80800FF0_bsbeemain(s32 arg0) {
    s32 _basudie_entrypoint_11(s32);
    s32 bs_setState(s32, s32);
    s32 func_80093370(s32, s32);
    f32 func_80099A34(s32);
    s32 func_8009BDAC(s32, f32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x83) {
        func_8009BDAC(arg0, func_80099A34(arg0));
        func_80093370(arg0, 1);
        bs_setState(arg0, 0x85);
        func_8009E830(arg0, 2);
        return;
    }
    _basudie_entrypoint_11(arg0);
}

s32 bsbeemain_entrypoint_9(s32 arg0) {
    extern s32 D_808012C0_bsbeemain[];
    return ((s32 *)&D_808012C0_bsbeemain)[arg0];
}

void func_80801080_bsbeemain(s32 arg0)
{
    _bsbee_entrypoint_1();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808010A8_bsbeemain(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    bs_setState(arg0, sp1C);
}

void func_808010F4_bsbeemain(s32 arg0)
{
    _bsrest_entrypoint_14();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeemain_entrypoint_10(s32 arg0) {
    extern s32 D_808012D0_bsbeemain[];
    return ((s32 *)&D_808012D0_bsbeemain)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_80801130_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_8080118C_bsbeemain.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beemain/func_808011E8_bsbeemain.s")

s32 bsbeemain_entrypoint_11(s32 arg0) {
    extern s32 D_808012E0_bsbeemain[];
    return ((s32 *)&D_808012E0_bsbeemain)[arg0];
}
