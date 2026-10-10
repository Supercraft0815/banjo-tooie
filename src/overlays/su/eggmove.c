#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/func_80800000_sueggmove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_0.s")

/* extern */

s32 sueggmove_entrypoint_1(void) {
    void *func_80106790();
    return (*(s32 *)((s8 *)(func_80106790()) + (0x3C)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_2.s")

void func_80800108_sueggmove(void *arg0) {
    if ((*(u8 *)((s8 *)(arg0) + (0xD))) == 0) {
        (*(s8 *)((s8 *)(arg0) + (0xC))) = 1;
        (*(u8 *)((s8 *)(arg0) + (0xD))) = 8U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/func_8080012C_sueggmove.s")

u8 sueggmove_entrypoint_3(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_5.s")

void sueggmove_entrypoint_6(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)(arg0) + (0x34))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = arg2;
}

/* extern */

void sueggmove_entrypoint_7(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x28);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/eggmove/sueggmove_entrypoint_10.s")
