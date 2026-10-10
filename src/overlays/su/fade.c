#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/fade/sufade_entrypoint_0.s")

void sufade_entrypoint_1(s32 arg0) {
    s32 func_800B99CC(s32, u8, s32 *);
    u32 vector_begin(s32);
    s32 vector_clear(s32);
    u32 vector_end(s32);
    extern s32 B_80800160_sufade;
    extern s32 D_80127EF4;
    u32 temp_v0;
    u32 var_s0;

    var_s0 = vector_begin(D_80127EF4);
    temp_v0 = vector_end(D_80127EF4);
    if (var_s0 < temp_v0) {
        do {
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (0))) = (s32) (*(u8 *)((s8 *)(var_s0) + (0)));
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (4))) = (s32) (*(u8 *)((s8 *)(var_s0) + (1)));
            (*(s32 *)((s8 *)(&B_80800160_sufade) + (8))) = (s32) (*(u8 *)((s8 *)(var_s0) + (2)));
            func_800B99CC(arg0, (*(u8 *)((s8 *)(var_s0) + (3))), &B_80800160_sufade);
            var_s0 += 4;
        } while (var_s0 < temp_v0);
    }
    vector_clear(D_80127EF4);
}

void sufade_entrypoint_2(void) {
    s32 vector_free(s32);
    extern s32 D_80127EF4;
    if (D_80127EF4 != 0) {
        vector_free(D_80127EF4);
        D_80127EF4 = 0;
    }
}
