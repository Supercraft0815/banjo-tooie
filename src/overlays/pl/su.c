#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/pl/su/plsu_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/pl/su/plsu_entrypoint_1.s")

/* extern */

s32 plsu_entrypoint_2(void) {
    s32 plsu_entrypoint_1(s32);
    if (plsu_entrypoint_1(0xA) == -1) {
        return 0;
    }
    if (plsu_entrypoint_1(0xB) == -1) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/pl/su/plsu_entrypoint_3.s")
