#include "common.h"

void chbaddieDll_entrypoint_0(void *arg0) {
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
    (*(s8 *)((s8 *)(arg0) + (5))) = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/dieDll/chbaddieDll_entrypoint_1.s")

/* extern */

void chbaddieDll_entrypoint_2(void *arg0) {
    s32 func_800CB9D8();
    s32 func_800FF564();
    s32 heap_free(s32);
    func_800FF564();
    func_800CB9D8();
    heap_free((*(s32 *)((s8 *)(arg0) + (0))));
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(s8 *)((s8 *)(arg0) + (4))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/dieDll/chbaddieDll_entrypoint_3.s")
