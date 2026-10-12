#include "common.h"

void subaddielink_entrypoint_0(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
}

void subaddielink_entrypoint_1(u8 *arg0, u8 *arg1) {
    if (arg1 != NULL) {
        (*(u32 *)((s8 *)(arg0) + (4))) = (u32)*(u16 *)(arg1 + 0x12) >> 1;
        (*(u8 **)((s8 *)(arg0) + (0))) = arg1;
        return;
    }
    subaddielink_entrypoint_0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/link/subaddielink_entrypoint_2.s")

/* extern */

s32 subaddielink_entrypoint_3(s32 *arg0) {
    s32 *_subaddiefind_entrypoint_8(s32, s32 *);
    s32 *temp_v0;
    s32 temp_a2;
    temp_a2 = arg0[1];
    arg0[0] = 0;
    if (temp_a2 != 0) {
        temp_v0 = _subaddiefind_entrypoint_8(temp_a2, arg0);
        if (temp_v0 != NULL) {
            arg0[0] = *temp_v0;
        }
    }
    return arg0[0] != 0;
}

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
