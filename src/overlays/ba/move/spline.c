#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_80800000_bamovespline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_808000F4_bamovespline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/bamovespline_entrypoint_0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/bamovespline_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_80800374_bamovespline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/func_8080057C_bamovespline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/spline/bamovespline_entrypoint_10.s")
