#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D790.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D7EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D930.s")

/* extern */

void func_8010DA30(u8 *arg0) {
    s32 func_800C2FDC(s32, u8 *, u8);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0)));
    if (temp_a2 != 0) {
        func_800C2FDC(temp_a2 & 0xFF, arg0, temp_a2);
        (*(u8 *)((s8 *)(arg0) + (0))) = 0;
    }
    (*(s32 *)((s8 *)(arg0) + (4))) = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010DA70.s")
