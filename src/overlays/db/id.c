#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/id/dbid_entrypoint_0.s")

s32 dbid_entrypoint_1(s16 *arg0) {
    s32 sum = 0;
    s16 *p = arg0 + 1;
    s32 i;
    for (i = 0; i < arg0[0]; i++) {
        s32 value = p[1];
        p += value;
        p += 2;
        sum += value;
    }
    return sum;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/id/dbid_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/id/dbid_entrypoint_3.s")
