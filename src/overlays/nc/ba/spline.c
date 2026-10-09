#include "common.h"

s32 ncbaspline_entrypoint_0() 
{
    return 0x30;
}

/* extern */

void func_80800008_ncbaspline(void *arg0) {
    s32 func_800D7520(s32);
    func_800D7520(*(*(s32 **)((s8 *)(arg0) + (0x44))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/func_8080002C_ncbaspline.s")

void ncbaspline_entrypoint_1()
{
    func_8080002C_ncbaspline();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/ncbaspline_entrypoint_2.s")

void ncbaspline_entrypoint_3()
{
    func_8080002C_ncbaspline();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/func_80800130_ncbaspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/func_8080017C_ncbaspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/func_80800318_ncbaspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/ncbaspline_entrypoint_4.s")

void ncbaspline_entrypoint_5(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x44)));
    if ((*(s32 *)((s8 *)(temp_v0) + (0x28))) != 0) {
        (*(s32 *)((s8 *)(temp_v0) + (0x28))) = -1;
    }
}

/* extern */

void ncbaspline_entrypoint_6(s32 arg0, void *arg1, s32 arg2) {
    s32 func_800D5424(u16);
    s32 ncbaspline_entrypoint_7(s32, s32);
    ncbaspline_entrypoint_7(arg0, func_800D5424((*(u16 *)((s8 *)(arg1) + (8)))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spline/ncbaspline_entrypoint_7.s")

s32 ncbaspline_entrypoint_8(void *arg0) {
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x44)))) + (0x28))) < 1;
}
