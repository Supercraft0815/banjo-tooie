#include "memory.h"

// round_up_16
u32 func_8001BD30(u32 arg0) {
    s32 temp_v0;
    register s32 result;

    temp_v0 = arg0 & 0xF;
    result = arg0;
    return temp_v0 ? result - temp_v0 + 0x10 : result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BD50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BDAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BE94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001BF80.s")

/* extern */

s32 func_8001C070(void) {
    s32 func_8001BF80();
    s32 var_v1;

    if (func_8001BF80() != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E33860/func_8001C0A0.s")
