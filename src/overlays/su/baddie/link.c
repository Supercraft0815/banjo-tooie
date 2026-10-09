#include "common.h"

void subaddielink_entrypoint_0(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/link/subaddielink_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/link/subaddielink_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/link/subaddielink_entrypoint_3.s")

/* extern */

s32 subaddielink_entrypoint_4(s32 *arg0) {
    s32 func_80106790(s32);
    s32 subaddielink_entrypoint_2();
    if (subaddielink_entrypoint_2() == 0) {
        return 0;
    }
    return func_80106790(*arg0);
}

void subaddielink_entrypoint_5(void *arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s32 *)((s8 *)(arg0) + (0)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s32 *)((s8 *)(arg0) + (4)));
}
