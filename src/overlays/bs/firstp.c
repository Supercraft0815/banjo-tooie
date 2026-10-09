#include "bs/firstp.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800000_bsfirstp.s")

void func_80800040_bsfirstp()
{
    _bastatemem_entrypoint_1();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800190_bsfirstp.s")

/* extern */

void func_808001D0_bsfirstp(s32 arg0) {
    s32 func_80800858_bsfirstp(s32, s32);
    s32 func_80808C48_bsfirstp();
    func_80808C48_bsfirstp();
    func_80800858_bsfirstp(arg0, 0);
}

/* extern */

void func_808001FC_bsfirstp(void) {
    s32 anctrl_setPlaybackType(s32, s32);
    s32 func_8008D04C();
    anctrl_setPlaybackType(func_8008D04C(), 3);
}

/* extern */

s32 func_80800228_bsfirstp(void) {
    s32 anctrl_getPlaybackType(s32);
    s32 func_8008D04C();
    s32 var_v1;

    if (anctrl_getPlaybackType(func_8008D04C()) == 3) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800264_bsfirstp.s")

/* extern */

void func_80800290_bsfirstp(s32 arg0, s32 arg1, s32 arg2) {
    f32 baanim_getTimer();
    s32 baanim_playForDuration_loopStartingAt(s32, s32, s32, f32);
    baanim_playForDuration_loopStartingAt(arg0, arg1, arg2, baanim_getTimer());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808002CC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800340_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808003B4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800424_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800488_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808004F8_bsfirstp.s")

/* extern */

void func_8080053C_bsfirstp(void *arg0) {
    s32 func_800EFD24(s32);
    s32 func_808004F8_bsfirstp();
    s32 sp1C;

    sp1C = (*(s32 *)((s8 *)(arg0) + (0x188)));
    func_808004F8_bsfirstp();
    func_800EFD24(sp1C + 0x38);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080056C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808006DC_bsfirstp.s")

void func_80800830_bsfirstp(s32 arg0)
{
    func_8080056C_bsfirstp();
    func_808006DC_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800858_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800864_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800888_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808008B0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800900_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800978_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800A18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800B44_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800C88_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800D18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80800F14_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801000_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808015C0_bsfirstp.s")

void func_80801640_bsfirstp()
{
    func_800C517C(func_800A4C68());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801668_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808016A0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080175C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080187C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808018E0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801928_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808019B0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808019EC_bsfirstp.s")

void func_80801A34_bsfirstp(s32 arg0)
{
    func_8080187C_bsfirstp();
    bsfirstp_entrypoint_2(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801A5C_bsfirstp.s")

/* extern */

s32 func_80801A98_bsfirstp(void) {
    s32 _ncba1p_entrypoint_10(s32);
    s32 func_800A4CA8();
    return _ncba1p_entrypoint_10(func_800A4CA8()) == 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801AC4_bsfirstp.s")

void func_80801AEC_bsfirstp(s32 arg0)
{
    func_80801B64_bsfirstp(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801B0C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801B64_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801BDC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801C18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801C74_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801D30_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801D70_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801DC0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801E18_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80801FD0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080222C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802304_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808023A0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802438_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802444_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802458_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802484_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808024B0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808024DC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802508_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802534_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802560_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802594_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808025C8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080261C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802670_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808026AC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802700_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802754_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808027A8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802A40_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802AA8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_7.s")

void func_80802BD8_bsfirstp(s32 arg0) 
{
}
void func_80802BE0_bsfirstp(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802BE8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802C30_bsfirstp.s")

void func_80802C6C_bsfirstp(s32 arg0)
{
    func_800FC660(0xF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802C90_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802CD8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802D14_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802D50_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802E7C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802ED4_bsfirstp.s")

void func_80802F00_bsfirstp()
{
    func_80802ED4_bsfirstp();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80802F20_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808030E0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803124_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803134_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808031D0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803204_bsfirstp.s")

s32 bsfirstp_entrypoint_8(s32 arg0) {
    extern s32 D_8080B474_bsfirstp[];
    return ((s32 *)&D_8080B474_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808032C0_bsfirstp.s")

void func_80803320_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803340_bsfirstp.s")

s32 bsfirstp_entrypoint_9(s32 arg0) {
    extern s32 D_8080B484_bsfirstp[];
    return ((s32 *)&D_8080B484_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808035EC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808036F0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803760_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803784_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808037E4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803828_bsfirstp.s")

s32 bsfirstp_entrypoint_11(s32 arg0) {
    extern s32 D_8080B494_bsfirstp[];
    return ((s32 *)&D_8080B494_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803A84_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803B04_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803B58_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803B68_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803CD4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803E84_bsfirstp.s")

void func_80803F6C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80803F94_bsfirstp.s")

s32 bsfirstp_entrypoint_15(s32 arg0) {
    extern s32 D_8080B4D0_bsfirstp[];
    return ((s32 *)&D_8080B4D0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804104_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808041D0_bsfirstp.s")

void func_80804210_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804238_bsfirstp.s")

s32 bsfirstp_entrypoint_16(s32 arg0) {
    extern s32 D_8080B4E0_bsfirstp[];
    return ((s32 *)&D_8080B4E0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080432C_bsfirstp.s")

void func_8080436C_bsfirstp(s32 arg0)
{
    func_808090D8_bsfirstp();
    func_80807C8C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804394_bsfirstp.s")

s32 bsfirstp_entrypoint_17(s32 arg0) {
    extern s32 D_8080B4F0_bsfirstp[];
    return ((s32 *)&D_8080B4F0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804488_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808045FC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808047EC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080483C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804848_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_18.s")

void func_80804A34_bsfirstp(s32 arg0) 
{
}
/* extern */

void func_80804A3C_bsfirstp(void *arg0) {
    s32 func_80101238(s32, s32, void *);
    func_80101238(0x77, (*(s32 *)((s8 *)(arg0) + (0x184))), arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804A64_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804B10_bsfirstp.s")

void func_80804B84_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804BA4_bsfirstp.s")

s32 bsfirstp_entrypoint_19(s32 arg0) {
    extern s32 D_8080B500_bsfirstp[];
    return ((s32 *)&D_8080B500_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804D18_bsfirstp.s")

void func_80804D80_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804DA0_bsfirstp.s")

s32 bsfirstp_entrypoint_20(s32 arg0) {
    extern s32 D_8080B510_bsfirstp[];
    return ((s32 *)&D_8080B510_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804E1C_bsfirstp.s")

void func_80804EB4_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804ED4_bsfirstp.s")

s32 bsfirstp_entrypoint_21(s32 arg0) {
    extern s32 D_8080B520_bsfirstp[];
    return ((s32 *)&D_8080B520_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804F28_bsfirstp.s")

void func_80804FB4_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80804FD4_bsfirstp.s")

s32 bsfirstp_entrypoint_22(s32 arg0) {
    extern s32 D_8080B530_bsfirstp[];
    return ((s32 *)&D_8080B530_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80805058_bsfirstp.s")

void func_808050B0_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(arg0);
}
void func_808050D8_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
}

s32 bsfirstp_entrypoint_23(s32 arg0) {
    extern s32 D_8080B540_bsfirstp[];
    return ((s32 *)&D_8080B540_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080511C_bsfirstp.s")

void func_8080519C_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_2();
    func_80807C8C_bsfirstp(arg0);
}
void func_808051C4_bsfirstp(s32 arg0)
{
    _bsdrone_entrypoint_1();
    func_80807D48_bsfirstp(arg0);
    func_80809D24_bsfirstp(arg0);
}

s32 bsfirstp_entrypoint_24(s32 arg0) {
    extern s32 D_8080B550_bsfirstp[];
    return ((s32 *)&D_8080B550_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808052A4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808052C8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80805380_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080549C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80805644_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808057C8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808058F0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_26.s")

void func_80805F48_bsfirstp(s32 arg0)
{
    func_808061AC_bsfirstp(arg0,0);
}

void func_80805F68_bsfirstp()
{
    func_8009B4FC();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_27.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806000_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806130_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080613C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806148_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806170_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808061AC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080633C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080649C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806588_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806774_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808067B0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808067E8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080682C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808068E8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806928_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808069BC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808069FC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806AD0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806BA0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806C58_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806CC0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806D64_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806D90_bsfirstp.s")

s32 bsfirstp_entrypoint_29(s32 arg0) {
    extern s32 D_8080B560_bsfirstp[];
    return ((s32 *)&D_8080B560_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806E0C_bsfirstp.s")

void func_80806E9C_bsfirstp(s32 arg0)
{
    _bsbabykaz_entrypoint_3();
    func_80807C8C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80806EC4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807024_bsfirstp.s")

s32 bsfirstp_entrypoint_30(s32 arg0) {
    extern s32 D_8080B570_bsfirstp[];
    return ((s32 *)&D_8080B570_bsfirstp)[arg0];
}

void func_808071D8_bsfirstp(s32 arg0)
{
    func_80091E6C();
    _bsbabykaz_entrypoint_3(arg0);
    func_80807C8C_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807208_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807264_bsfirstp.s")

s32 bsfirstp_entrypoint_31(s32 arg0) {
    extern s32 D_8080B580_bsfirstp[];
    return ((s32 *)&D_8080B580_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808072C8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807328_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807394_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808074D0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807504_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080762C_bsfirstp.s")

s32 bsfirstp_entrypoint_32(s32 arg0) {
    extern s32 D_8080B590_bsfirstp[];
    return ((s32 *)&D_8080B590_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808077AC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808077E0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807864_bsfirstp.s")

s32 bsfirstp_entrypoint_33(s32 arg0) {
    extern s32 D_8080B5A0_bsfirstp[];
    return ((s32 *)&D_8080B5A0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808078F4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807A70_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807AF8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807BB8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807C8C_bsfirstp.s")

void func_80807D48_bsfirstp(s32 arg0)
{
    func_80802BE0_bsfirstp(arg0);
    func_8080800C_bsfirstp(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807D70_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807DD4_bsfirstp.s")

/* extern */

void func_80807EEC_bsfirstp(s32 arg0) {
    s32 func_800A3404();
    s32 func_800A3544(s32, s32);
    s32 func_80807DD4_bsfirstp(s32);
    if (func_800A3404() == 0) {
        func_800A3544(arg0, 1);
        func_80807DD4_bsfirstp(arg0);
    }
}

/* extern */

void func_80807F24_bsfirstp(s32 arg0) {
    s32 func_800A3404();
    s32 func_800A3544(s32, s32);
    s32 func_80807DD4_bsfirstp(s32);
    if (func_800A3404() != 0) {
        func_800A3544(arg0, 0);
        func_80807DD4_bsfirstp(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807F5C_bsfirstp.s")

void func_80807F9C_bsfirstp()
{
    func_80807FBC_bsfirstp();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80807FBC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080800C_bsfirstp.s")

void func_80808084_bsfirstp(s32 arg0)
{
    func_80092744(arg0,0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808080A4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808080B4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808100_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808148_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808084AC_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080853C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808085A8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808630_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808678_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808086B0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808848_bsfirstp.s")

void func_808088A4_bsfirstp(s32 arg0)
{
    func_808086B0_bsfirstp(arg0,0x3);
    func_80807C8C_bsfirstp(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808088D0_bsfirstp.s")

s32 bsfirstp_entrypoint_34(s32 arg0) {
    extern s32 D_8080B5B0_bsfirstp[];
    return ((s32 *)&D_8080B5B0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808A24_bsfirstp.s")

void func_80808A8C_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808AAC_bsfirstp.s")

s32 bsfirstp_entrypoint_35(s32 arg0) {
    extern s32 D_8080B5C0_bsfirstp[];
    return ((s32 *)&D_8080B5C0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808B24_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808B8C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808C48_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808CAC_bsfirstp.s")

/* extern */

void func_80808D80_bsfirstp(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s16, s32);
    void *func_80802508_bsfirstp();
    void *temp_v0;

    temp_v0 = func_80802508_bsfirstp();
    baanim_playForDuration_loopSmooth(arg0, (*(s16 *)((s8 *)(temp_v0) + (0))), (*(s32 *)((s8 *)(temp_v0) + (4))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808DB0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808E78_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808EF0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80808F38_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808090D8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080911C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809198_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809250_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809334_bsfirstp.s")

void func_80809384_bsfirstp(void)
{
    func_80807C8C_bsfirstp();
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808093A4_bsfirstp.s")

s32 bsfirstp_entrypoint_36(s32 arg0) {
    extern s32 D_8080B5D0_bsfirstp[];
    return ((s32 *)&D_8080B5D0_bsfirstp)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808094A4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808094F4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809540_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809684_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809740_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809900_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809938_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080995C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808099A8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_808099B4_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809A10_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809A7C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809AF8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/bsfirstp_entrypoint_37.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809C30_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809C90_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809CB4_bsfirstp.s")

void func_80809CD8_bsfirstp()
{
    func_80809CF8_bsfirstp();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809CF8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809D24_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809D6C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809D94_bsfirstp.s")

void func_80809DA0_bsfirstp(void *arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x188)));
    if (arg1 == 0) {
        if ((*(s32 *)((s8 *)(temp_v0) + (0x254))) < 0) {
            (*(s32 *)((s8 *)(temp_v0) + (0x254))) = arg1;
            (*(s32 *)((s8 *)(temp_v0) + (0x258))) = 0;
        }
    } else {
        (*(s32 *)((s8 *)(temp_v0) + (0x254))) = arg1;
        (*(s32 *)((s8 *)(temp_v0) + (0x258))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809DD0_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809EF8_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_80809F74_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080A03C_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080A194_bsfirstp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/firstp/func_8080A250_bsfirstp.s")
