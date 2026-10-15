#include "common.h"

/* extern */

void func_80800000_bamovespline(u8 *arg0) {
    f32 func_800D8840(s32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 dst[3], f32 angle, f32 distance);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 dst[3], f32 src[3]);
    void func_800EFA20(void *, void *, f32);
    s32 func_800F2168(u8 *, s32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    func_800EEB9C((f32 *)(temp_v0 + 0x1C), *(f32 *)(temp_v0 + 0x40), *(f32 *)(temp_v0 + 0x3C));
    sp34[0] = *(f32 *)(*(u8 **)(arg0 + 0xC8) + 0x10);
    sp34[1] = 0.0f;
    sp34[2] = *(f32 *)(*(u8 **)(arg0 + 0xC8) + 0x18);
    func_800EE7F8(sp28, (f32 *)(*(u8 **)(arg0 + 0xC8) + 0x1C));
    sp28[1] = 0.0f;
    func_800EFA20(sp4C, sp28, func_800D8840(2));
    func_800EFA20(sp40, sp34, func_800D8840(2));
    func_800EF3DC(sp4C, sp40);
    func_800EF334(sp4C, func_800D8FF8() * 30.0f);
    func_800EF04C((f32 *)(*(u8 **)(arg0 + 0xC8) + 0x10), sp4C);
    func_800F2168((*(u8 **)((s8 *)(arg0) + (0xC8))) + 0x10, 0x38D1B717);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_808000F4_bamovespline.s")

/* extern */

void bamovespline_entrypoint_0(void *arg0, f32 *arg1) {
    void func_800C810C(void *, f32, f32 *, f32 *);
    void *func_800D7520(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp20[4];
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x90))) == 4) {
        func_800C810C(func_800D7520((*(s16 *)((s8 *)(temp_v0) + (0x94)))), (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x98))), arg1, sp20);
        return;
    }
    func_800EFA4C(arg1, 0.0f, 1.0f, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/bamovespline_entrypoint_1.s")

u32 bamovespline_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 145);
}

u32 bamovespline_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 146);
}

s32 bamovespline_entrypoint_4(void *arg0) {
    return (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x90))) == 4;
}

void bamovespline_entrypoint_5(s32 arg0) 
{
}
void bamovespline_entrypoint_6(void *arg0) { (*(s8 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x90)) = 0; func_808000F4_bamovespline(arg0, 1); }

void bamovespline_entrypoint_7(void *arg0, s32 arg1) {
    *(s16 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 148) = arg1;
}

void bamovespline_entrypoint_8(s32 arg0)
{
    func_808000F4_bamovespline(arg0,0x2);
}

void bamovespline_entrypoint_9(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0xC8)) + 0x98)) = arg1;
    func_808000F4_bamovespline(arg0, 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_80800374_bamovespline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_8080057C_bamovespline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/bamovespline_entrypoint_10.s")
