#include "common.h"

void func_80800000_rtlight(void *arg0, s32 arg1, void *arg2) {
    (*(s32 *)((s8 *)(arg2) + (8))) = (s32) (arg1 / (s32) (*(u16 *)((s8 *)(arg0) + (0xE))));
    (*(s32 *)((s8 *)(arg2) + (4))) = (s32) ((s32) (arg1 % (s32) (*(u16 *)((s8 *)(arg0) + (0xE)))) / (s32) (*(u16 *)((s8 *)(arg0) + (0xC))));
    (*(s32 *)((s8 *)(arg2) + (0))) = (s32) (arg1 % (s32) (*(u16 *)((s8 *)(arg0) + (0xE)))) % (s32) (*(u16 *)((s8 *)(arg0) + (0xC)));
    (*(s32 *)((s8 *)(arg2) + (0))) += (*(s16 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(arg2) + (4))) += (*(s16 *)((s8 *)(arg0) + (2)));
    (*(s32 *)((s8 *)(arg2) + (8))) += (*(s16 *)((s8 *)(arg0) + (4)));
}

void rtlight_entrypoint_0(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/rtlight_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/func_8080036C_rtlight.s")

void func_80800544_rtlight(void *arg0, s32 position[3]) {
    void func_800C8800(void *, f32 *);
    f32 pos[3];
    func_800C8800(arg0, pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/func_808005AC_rtlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/rt/light/rtlight_entrypoint_2.s")
