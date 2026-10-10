#include "common.h"

void suflamefx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3) {
    u32* func_80100074(Actor*, u32, u32);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    func_80100074(arg0, arg1, (arg2 * 0x30) + 0x20);
    temp_v0 = func_80100094(arg0, arg1);
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = arg3;
    (*(s8 *)((s8 *)(temp_v0) + (0x1B))) = (s8) arg2;
}

void suflamefx_entrypoint_1(Actor *arg0, u32 arg1) {
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, arg1, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/flamefx/suflamefx_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/flamefx/suflamefx_entrypoint_3.s")

void suflamefx_entrypoint_4(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (0x1C))) = 1;
}

void suflamefx_entrypoint_5(void *arg0, f32 arg1, f32 arg2) {
    (*(s16 *)((s8 *)(arg0) + (0xC))) = (s16) (s32) arg1;
    (*(s16 *)((s8 *)(arg0) + (0xE))) = (s16) (s32) arg2;
}

void suflamefx_entrypoint_6(f32 *arg0, f32 arg1) {
    arg0[5] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/flamefx/suflamefx_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/flamefx/func_80800428_suflamefx.s")
