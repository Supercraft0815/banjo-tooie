#include "common.h"

void idtwinklea_entrypoint_0(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
}

void idtwinklea_entrypoint_1(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/twinklea/idtwinklea_entrypoint_2.s")

void idtwinklea_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, u8 *arg4) {
    f32 var_f0;
    u8 *temp_a2;
    Vtx *temp_v0;
    u8 *var_v1;

    temp_v0 = arg1 + arg3;
    for (; arg1 < temp_v0; arg1++, arg2++) {
            var_v1 = (*(u8 **)((s8 *)(arg4) + (0)));
            temp_a2 = (*(u8 **)((s8 *)(arg4) + (4)));
            if (var_v1 < temp_a2) {
loop_4:
                if (((*(s16 *)((s8 *)(arg1) + (0))) != (*(s16 *)((s8 *)(var_v1) + (8)))) || ((*(s16 *)((s8 *)(arg1) + (2))) != (*(s16 *)((s8 *)(var_v1) + (0xA)))) || ((*(s16 *)((s8 *)(arg1) + (4))) != (*(s16 *)((s8 *)(var_v1) + (0xC))))) {
                    var_v1 += 0x10;
                    if (var_v1 < temp_a2) {
                        goto loop_4;
                    }
                }
            }
            if (var_v1 == temp_a2) {
                var_f0 = 0.0f;
            } else {
                var_f0 = 1.0f;
            }
            if (var_f0 > 1.0f) {
                var_f0 = 1.0f;
            }
            arg2->v.cn[3] = var_f0 * 255.0f;
    }
}
