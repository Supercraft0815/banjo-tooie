#include "common.h"

void *func_80800000_dbmorph(s16 *arg0, s32 arg1) {
    u8 *entry = (u8 *)arg0 + 4;
    s32 i = 0;
    s32 count = *arg0;
    if (count <= 0) goto done;
    do {
        i++;
        if (arg1 == entry[2]) return entry;
        entry += *(s32 *)(entry + 8);
    } while (i < count);
done:
    return NULL;
}

s32 dbmorph_entrypoint_0(s16 *arg0) {
    return arg0[1];
}

s32 dbmorph_entrypoint_1(s16 *arg0) {
    return arg0[0];
}

/* extern */

u8 dbmorph_entrypoint_2(void) {
    void *func_80800000_dbmorph();
    return (*(u8 *)((s8 *)(func_80800000_dbmorph()) + (3)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/morph/dbmorph_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/morph/dbmorph_entrypoint_4.s")
