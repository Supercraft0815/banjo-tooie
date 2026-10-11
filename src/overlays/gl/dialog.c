#include "common.h"

s32 gldialog_entrypoint_0(void) {
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dialog/gldialog_entrypoint_1.s")

void gldialog_entrypoint_2(void) {
    extern u32 D_801275E0[];
    u32 *p = D_801275E0;
    p += 8;
    p[0] = 0;
    p[1] = -1;
}

void gldialog_entrypoint_3(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dialog/gldialog_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dialog/gldialog_entrypoint_5.s")
