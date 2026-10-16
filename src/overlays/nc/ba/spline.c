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

void func_8080002C_ncbaspline(void *arg0) {
    void func_800EFD24(f32 *);
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x44)) = -1;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 4) = 0.0f;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 8) = 0.0f;
    *(s32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x28) = 0;
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2C) = 0;
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2F) = 0;
    *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2E) = *(u8 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x2F);
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0xC));
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x1C));
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x44) + 0x18) = 0.0f;
}

void ncbaspline_entrypoint_1(void *arg0)
{
    func_8080002C_ncbaspline(arg0);
}

/* extern */

void ncbaspline_entrypoint_2(s32 arg0) {
    s32 func_801124D0(s32, s32);
    s32 func_80111B8C(s32, s32, s32);
    func_801124D0(arg0, 1);
    func_80111B8C(arg0, 0x40400000, 0x41000000);
}

void ncbaspline_entrypoint_3(void *arg0)
{
    func_8080002C_ncbaspline(arg0);
}

/* extern */

void func_80800130_ncbaspline(s32 arg0, s32 arg1) {
    s32 func_80112518();
    s32 func_801124D0(s32, s32);
    s32 func_80112524(s32, s32);
    s32 sp1C;

    sp1C = func_80112518();
    func_801124D0(arg0, 0x1);
    func_80112524(arg0, arg1);
    func_801124D0(arg0, sp1C);
}

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
