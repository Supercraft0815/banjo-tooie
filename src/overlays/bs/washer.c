#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800000_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800064_bswasher.s")

/* extern */

void func_808000BC_bswasher(s32 arg0) {
    s32 yaw_setUpdateType(s32, s32);
    s32 yaw_setVelocityBounded(s32, s32, s32);
    yaw_setUpdateType(arg0, 3);
    yaw_setVelocityBounded(arg0, 0x43960000, 0x40C00000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808000F0_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808001A8_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/bswasher_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800300_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_8080042C_bswasher.s")

void func_80800590_bswasher(s32 arg0)
{
    _basudie_entrypoint_6();
    func_808000F0_bswasher(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808005B8_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800608_bswasher.s")

s32 bswasher_entrypoint_1(s32 arg0) {
    extern s32 D_80801E10_bswasher[];
    return ((s32 *)&D_80801E10_bswasher)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800714_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800770_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808007DC_bswasher.s")

s32 bswasher_entrypoint_2(s32 arg0) {
    extern s32 D_80801E20_bswasher[];
    return ((s32 *)&D_80801E20_bswasher)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808008BC_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808008F4_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_8080099C_bswasher.s")

s32 bswasher_entrypoint_3(s32 arg0) {
    extern s32 D_80801E30_bswasher[];
    return ((s32 *)&D_80801E30_bswasher)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800B08_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800C70_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800E74_bswasher.s")

s32 bswasher_entrypoint_4(s32 arg0) {
    extern s32 D_80801E40_bswasher[];
    return ((s32 *)&D_80801E40_bswasher)[arg0];
}

/* extern */

void func_80800EC8_bswasher(u8 *arg0) {
    s32 bs_setState(s32, s32);
    s32 func_80099A4C(void *);
    s32 func_80099B94(u8 *);
    s32 func_8009E6EC();
    if (func_8009E6EC(arg0) == 0x65) {
        (*(s32 *)((s8 *)(arg0) + (0x160))) = func_80099A4C(arg0);
        bs_setState((s32) arg0, 0x37);
    }
    func_80099B94(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800F1C_bswasher.s")

void func_80800F54_bswasher(void *arg0) {
    extern s32 D_80801E50_bswasher;
    (*(s8 *)((s8 *)(arg0) + (0x165))) = func_8009D454(arg0, 0, &D_80801E50_bswasher);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80800F88_bswasher.s")

void func_8080100C_bswasher(s32 arg0)
{
    func_80800F1C_bswasher();
    func_808000F0_bswasher(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801034_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808010DC_bswasher.s")

s32 bswasher_entrypoint_5(s32 arg0) {
    extern s32 D_80801E60_bswasher[];
    return ((s32 *)&D_80801E60_bswasher)[arg0];
}

void func_808011B4_bswasher(s32 arg0)
{
    _baspin_entrypoint_1();
    func_808000F0_bswasher(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808011DC_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801218_bswasher.s")

s32 bswasher_entrypoint_6(s32 arg0) {
    extern s32 D_80801E70_bswasher[];
    return ((s32 *)&D_80801E70_bswasher)[arg0];
}

void func_80801294_bswasher(s32 arg0)
{
    _babounce_entrypoint_3();
    func_808000F0_bswasher(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808012BC_bswasher.s")

/* extern */

void func_80801314_bswasher(s32 arg0) {
    s32 _babounce_entrypoint_2();
    s32 _babounce_entrypoint_9(s32);
    s32 bs_setState(s32, s32);
    s32 func_80800000_bswasher(s32);
    s32 sp1C;

    sp1C = 0;
    if (_babounce_entrypoint_2() != 0) {
        func_80800000_bswasher(arg0);
    }
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x32;
    }
    bs_setState(arg0, sp1C);
}

s32 bswasher_entrypoint_7(s32 arg0) {
    extern s32 D_80801E80_bswasher[];
    return ((s32 *)&D_80801E80_bswasher)[arg0];
}

void func_8080137C_bswasher(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808000F0_bswasher(arg0);
}
void func_808013A4_bswasher(s32 arg0)
{
    func_808001A8_bswasher();
    _bsrest_entrypoint_16(arg0);
}
/* extern */

void func_808013CC_bswasher(s32 arg0) {
    s32 _bsrest_entrypoint_13(s32);
    s32 _bsrest_entrypoint_20();
    s32 bs_setState(s32, s32);
    s32 func_80800300_bswasher(s32);
    s32 sp1C;

    sp1C = 0;
    if (_bsrest_entrypoint_20() != 0) {
        sp1C = _bsrest_entrypoint_13(arg0);
    }
    func_80800300_bswasher(arg0);
    bs_setState(arg0, sp1C);
}

s32 bswasher_entrypoint_8(s32 arg0) {
    extern s32 D_80801E90_bswasher[];
    return ((s32 *)&D_80801E90_bswasher)[arg0];
}

void func_8080142C_bswasher(s32 arg0)
{
    func_808000F0_bswasher();
    func_80090A2C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801454_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808014C8_bswasher.s")

s32 bswasher_entrypoint_9(s32 arg0) {
    extern s32 D_80801EA0_bswasher[];
    return ((s32 *)&D_80801EA0_bswasher)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808015EC_bswasher.s")

void func_80801744_bswasher(s32 arg0)
{
    func_808015EC_bswasher(arg0,0);
    func_808000F0_bswasher(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801770_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_808017A0_bswasher.s")

s32 bswasher_entrypoint_10(s32 arg0) {
    extern s32 D_80801EC4_bswasher[];
    return ((s32 *)&D_80801EC4_bswasher)[arg0];
}

void func_80801B10_bswasher()
{
    func_808000F0_bswasher();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801B30_bswasher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/washer/func_80801BA4_bswasher.s")

s32 bswasher_entrypoint_11(s32 arg0) {
    extern s32 D_80801ED4_bswasher[];
    return ((s32 *)&D_80801ED4_bswasher)[arg0];
}
