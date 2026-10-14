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

void func_800EE670(void) {
    u32 vector_begin(s32);
    s32 vector_defrag(s32);
    u32 vector_end(s32);
    extern s32 (*D_80123590[])(s32);
    extern s32 D_80127EF8;
    s32 (*temp_v0_2)(s32);
    u32 temp_s2;
    u32 temp_v0;
    u32 var_s0;

    if (D_80127EF8 != 0) {
        temp_s2 = vector_end(D_80127EF8);
        temp_v0 = vector_begin(D_80127EF8);
        var_s0 = temp_v0;
        if (temp_v0 < temp_s2) {
            do {
                temp_v0_2 = D_80123590[*(u8 *)(var_s0 + 6)];
                if (temp_v0_2 != NULL) {
                    temp_v0_2(var_s0 + 8);
                }
                var_s0 += 0xA8;
            } while (var_s0 < temp_s2);
        }
        D_80127EF8 = vector_defrag(D_80127EF8);
    }
}

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
