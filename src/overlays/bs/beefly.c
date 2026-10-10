#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800000_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_808000A4_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_8080010C_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_808001C4_bsbeefly.s")

void func_808002B0_bsbeefly()
{
    _bsbee_entrypoint_0();
}

s32 bsbeefly_entrypoint_0(s32 arg0) {
    extern s32 D_80800E18_bsbeefly[];
    return ((s32 *)&D_80800E18_bsbeefly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_808002E4_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_8080039C_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800480_bsbeefly.s")

/* extern */

void func_808005B0_bsbeefly(s32 arg0) {
    s32 _baboost_entrypoint_2(s32, s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    if (func_8009E6EC() == 0x18) {
        _baboost_entrypoint_2(arg0, 0x3F800000);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800600_bsbeefly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800708_bsbeefly.s")

void func_80800B18_bsbeefly(s32 arg0)
{
    func_808002E4_bsbeefly();
    _bsbee_entrypoint_0(arg0);
}
s32 bsbeefly_entrypoint_1(s32 arg0) {
    extern s32 D_80800E50_bsbeefly[];
    return ((s32 *)&D_80800E50_bsbeefly)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/beefly/func_80800B54_bsbeefly.s")

/* extern */

void func_80800BA4_bsbeefly(s32 arg0) {
    s32 _bsbee_entrypoint_2();
    s32 _bsrest_entrypoint_20(s32);
    s32 bs_setState(s32, s32);
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = 0x8C;
    }
    bs_setState(arg0, sp1C);
}

void func_80800BE8_bsbeefly(s32 arg0)
{
    _bsrest_entrypoint_14();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

s32 bsbeefly_entrypoint_2(s32 arg0) {
    extern s32 D_80800E60_bsbeefly[];
    return ((s32 *)&D_80800E60_bsbeefly)[arg0];
}

void func_80800C2C_bsbeefly(s32 arg0)
{
    _bafly_entrypoint_18();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

/* extern */

void func_80800C5C_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_16(s32, s32, s32);
    s32 _bsbee_entrypoint_1();
    s32 func_8080039C_bsbeefly(s32);
    _bsbee_entrypoint_1();
    func_8080039C_bsbeefly(arg0);
    _bafly_entrypoint_16(arg0, 0x1E0, 0x3F800000);
}

/* extern */

void func_80800C94_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_17(s32, s32, s32, s32 *);
    s32 _bsbee_entrypoint_2();
    s32 sp1C;

    sp1C = 0;
    _bsbee_entrypoint_2();
    _bafly_entrypoint_17(arg0, 0x8C, 0x85, &sp1C);
}

s32 bsbeefly_entrypoint_3(s32 arg0) {
    extern s32 D_80800E70_bsbeefly[];
    return ((s32 *)&D_80800E70_bsbeefly)[arg0];
}

void func_80800CE0_bsbeefly(s32 arg0)
{
    _bafly_entrypoint_15();
    func_808002E4_bsbeefly(arg0);
    _bsbee_entrypoint_0(arg0);
}

/* extern */

void func_80800D10_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_13(s32, s32, s32, s32);
    s32 _bsbee_entrypoint_1();
    s32 func_8080039C_bsbeefly(s32);
    _bsbee_entrypoint_1();
    func_8080039C_bsbeefly(arg0);
    _bafly_entrypoint_13(arg0, 1, 0xD3, 0x3F99999A);
}

/* extern */

void func_80800D50_bsbeefly(s32 arg0) {
    s32 _bafly_entrypoint_14(s32, s32, s32);
    s32 _bsbee_entrypoint_2();
    _bsbee_entrypoint_2();
    _bafly_entrypoint_14(arg0, 0x8C, 0x85);
}

s32 bsbeefly_entrypoint_4(s32 arg0) {
    extern s32 D_80800E80_bsbeefly[];
    return ((s32 *)&D_80800E80_bsbeefly)[arg0];
}
