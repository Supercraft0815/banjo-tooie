#include "common.h"

/* extern */

void func_800EE530(void *arg0) {
    s32 defrag(s32);
    (*(s32 *)((s8 *)(arg0) + (0x2C))) = defrag((*(s32 *)((s8 *)(arg0) + (0x2C))));
}

void func_800EE55C(u8 *arg0) {
    s32 defrag(s32);
    s32 sp1C;

    sp1C = (s32) ((*(s32 *)((s8 *)(arg0) + (0x2C))) - (*(s32 *)((s8 *)(arg0) + (0x24)))) >> 2;
    (*(s32 *)((s8 *)(arg0) + (0x24))) = defrag((*(s32 *)((s8 *)(arg0) + (0x24))));
    (*(s32 *)((s8 *)(arg0) + (0x2C))) = (*(s32 *)((s8 *)(arg0) + (0x24))) + (sp1C * 4);
}

/* extern */

void func_800EE5AC(void *arg0) {
    s32 defrag(s32);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = defrag((*(s32 *)((s8 *)(arg0) + (0x24))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC7E20/func_800EE5D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC7E20/func_800EE670.s")

void func_800EE718(void) {
    s32 _idbounce_entrypoint_6();
    extern u8 D_80135483;
    if (D_80135483 != 0) {
        _idbounce_entrypoint_6();
    }
}

void func_800EE748(void) {
    s32 _idbounce_entrypoint_7();
    extern u8 D_80135483;
    if (D_80135483 != 0) {
        _idbounce_entrypoint_7();
    }
}
