#include "common.h"

void gzthread_entrypoint_0(s32 arg0, char *arg1) {
    extern u8 *D_80800380_gzthread[];
    u8 *temp_v0;
    u8 c;

    temp_v0 = D_80800380_gzthread[arg0];
    arg1++;
    c = *temp_v0++;
    arg1[-1] = c;
    while (c != 0) {
        c = *temp_v0;
        arg1++;
        temp_v0++;
        arg1[-1] = c;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002B0_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002B4_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002BC_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002C4_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002D0_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002D8_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002E4_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002EC_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002F0_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/R_808002F8_gzthread.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/thread/gzthread_entrypoint_1.s")
