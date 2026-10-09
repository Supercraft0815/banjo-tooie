#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/func_80800000_bamovegoto.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_1.s")

f32 bamovegoto_entrypoint_2(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 116);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_3.s")

s32 bamovegoto_entrypoint_4(void *arg0) {
    return (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x54))) == 6;
}

void bamovegoto_entrypoint_5(s32 arg0)
{
    func_80800000_bamovegoto(arg0,0);
}

void bamovegoto_entrypoint_6(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x54))) = 0;
}

void bamovegoto_entrypoint_7(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 112) = arg1;
}

void bamovegoto_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 120) = arg1;
}

void bamovegoto_entrypoint_9(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 85) = arg1;
}

void bamovegoto_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 86) = arg1;
}

void bamovegoto_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x80))) = arg1;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x7C))) = arg2;
}

/* extern */

void bamovegoto_entrypoint_12(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 100);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_13.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_14.s")
