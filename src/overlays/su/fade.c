#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/fade/sufade_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/fade/sufade_entrypoint_1.s")

void sufade_entrypoint_2(void) {
    s32 vector_free(s32);
    extern s32 D_80127EF4;
    if (D_80127EF4 != 0) {
        vector_free(D_80127EF4);
        D_80127EF4 = 0;
    }
}
