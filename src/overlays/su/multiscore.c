#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_80800140_sumultiscore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_80800BFC_sumultiscore.s")

/* extern */

void func_80800D24_sumultiscore(s32 arg0, s32 arg1, void *arg2) {
    s16 func_800F5578(s32);
    (*(s16 *)((s8 *)(arg2) + (8))) = func_800F5578(arg1);
}

void func_80800D54_sumultiscore(s32 arg0, s32 arg1, s32 arg2) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_80800D64_sumultiscore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_80800DD0_sumultiscore.s")

void func_80800E84_sumultiscore(s32 arg0, s32 arg1, s32 arg2) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_7.s")

s16 sumultiscore_entrypoint_8(s32 arg0, s32 arg1, s32 arg2) {
    s8 *table = (s8 *)arg0 + (arg2 << 2);
    s32 index = *(s32 *)(table + 4);
    s32 offset = arg1 * 0x13C;
    return *(s16 *)((s8 *)(arg0 + offset + (index << 5)) + 0x48);
}

void sumultiscore_entrypoint_9(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 base;
    s32 index;
    s32 offset;
    offset = arg1 * 0x13C;
    base = arg0 + offset;
    index = *(s32 *)((s8 *)arg0 + (arg2 << 2) + 4);
    *(s16 *)((s8 *)base + (index << 5) + 0x48) = arg3;
    if (arg2 == 4) {
        *(f32 *)((s8 *)base + (index << 5) + 0x54) = 1.0f;
    }
}

void sumultiscore_entrypoint_10(u8 *arg0, s32 arg1) {
    s32 value = *(s32 *)(arg0 + 0x18);
    arg0[arg1 * 0x13C + (value << 5) + 0x47] = 1;
}

void sumultiscore_entrypoint_11(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    s32 index = arg0[arg2 + 1];
    s32 offset = arg1 * 0x13C;
    *(f32 *)((s8 *)arg0 + offset + (index << 5) + 0x58) = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/sumultiscore_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_80801160_sumultiscore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_808011E0_sumultiscore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/multiscore/func_80801340_sumultiscore.s")
