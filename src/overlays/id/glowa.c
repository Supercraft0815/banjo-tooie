#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/glowa/idglowa_entrypoint_0.s")

f32 idglowa_entrypoint_1(f32 *arg0) {
    return arg0[1];
}

void func_808000E8_idglowa(void *arg0, s32 arg1) {
    if (arg1 == 2) {
        (*(f32 *)((s8 *)(arg0) + (0xC))) = 1.0f;
    }
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
}

void idglowa_entrypoint_2(s32 arg0) 
{
}
void idglowa_entrypoint_3(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(f32 *)((s8 *)(arg0) + (4))) = 0.5f;
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((f32) (arg1 + 1) * 0.01f);
    func_808000E8_idglowa(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/glowa/idglowa_entrypoint_4.s")
