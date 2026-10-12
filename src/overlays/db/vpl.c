#include "common.h"

s32 *dbvpl_entrypoint_0(u8 *arg0, s32 arg1) {
    s32 i = 0;
    register s32 count = *(s32 *)(arg0 + 0x2C);
    u8 *entry = arg0;
    s32 *p;
    if (count > 0) {
loop:
        i++;
        p = (s32 *)(arg0 + *(s32 *)(entry + 0x30));
        if (arg1 == *p) return p;
        entry += 4;
        count = *(s32 *)(arg0 + 0x2C);
        if (i < count) goto loop;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/vpl/dbvpl_entrypoint_1.s")
