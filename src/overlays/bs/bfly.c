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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800624_bsbfly.s")

s32 bsbfly_entrypoint_1(s32 arg0) {
    extern s32 D_80801D58_bsbfly[];
    return ((s32 *)&D_80801D58_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808009D0_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800A24_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800C38_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80800D50_bsbfly.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080183C_bsbfly.s")

s32 bsbfly_entrypoint_4(s32 arg0) {
    extern s32 D_80801D88_bsbfly[];
    return ((s32 *)&D_80801D88_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080188C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808018D0_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808018F4_bsbfly.s")

s32 bsbfly_entrypoint_5(s32 arg0) {
    extern s32 D_80801D98_bsbfly[];
    return ((s32 *)&D_80801D98_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_8080193C_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801980_bsbfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_808019A4_bsbfly.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801A1C_bsbfly.s")

void func_80801A44_bsbfly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_80800188_bsbfly(arg0);
}
s32 bsbfly_entrypoint_7(s32 arg0) {
    extern s32 D_80801DB8_bsbfly[];
    return ((s32 *)&D_80801DB8_bsbfly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801A80_bsbfly.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/bfly/func_80801C58_bsbfly.s")

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
