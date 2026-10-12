#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/palette/subaddiepalette_entrypoint_3.s")

void subaddiepalette_entrypoint_4(void *arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (6))) = 1;
    if ((((*(s16 *)((s8 *)(arg0) + (0x60))) == 0) || ((((u32) (*(u8 *)((s8 *)(arg0) + (0x7B)))) >> 6) == 0)) && ((*(u8 *)((s8 *)(arg0) + (0x70))) & 1)) {
        (*(s16 *)((s8 *)(arg1) + (6))) = (s16) ((*(s16 *)((s8 *)(arg1) + (6))) + 1);
    }
}
