#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/func_80800000_fxleaves.s")

void func_80800288_fxleaves(s8 *arg0, s32 arg1) {
    arg0[34] = arg1;
}

/* extern */

void fxleaves_entrypoint_0(void *arg0) {
    s32 vector_clear(s32);
    vector_clear((*(s32 *)((s8 *)(arg0) + (0x1C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_1.s")

/* extern */

int fxleaves_entrypoint_2(void *arg0) {
    s32 vector_size(s32);
    return *(u8 *)((s8 *)arg0 + 0x22) != 1 &&
        vector_size(*(s32 *)((s8 *)arg0 + 0x1C)) == 0;
}

/* extern */

void fxleaves_entrypoint_3(void *arg0) {
    s32 heap_free(void *);
    s32 vector_free(s32);
    vector_free((*(s32 *)((s8 *)(arg0) + (0x1C))));
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_4.s")

void fxleaves_entrypoint_5(s32 arg0)
{
    func_80800288_fxleaves(arg0,1);
}

void fxleaves_entrypoint_6(s32 arg0)
{
    func_80800288_fxleaves(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/leaves/fxleaves_entrypoint_7.s")
