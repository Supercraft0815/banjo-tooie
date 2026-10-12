#include "core2/1EEEC40.h"

s32 func_80115350() 
{
    return 0x1C;
}

f32 func_80115358(void *arg0, f32 arg1) {
    void *temp_v0;
    f32 bound;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x14)));
    bound = *(f32 *)((s8 *)temp_v0 + 0xC);
    if (arg1 < bound) {
        arg1 = bound;
    } else {
        bound = *(f32 *)((s8 *)temp_v0 + 0x10);
        if (bound < arg1) {
            arg1 = bound;
        }
    }
    return arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEC40/func_8011539C.s")

void func_80115428(void *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0x14))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0x18))) = arg2;
}

void func_80115444(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0xC)));
    *arg2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0x10)));
}

f32 func_80115460(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 20) + 8);
}

f32 func_8011546C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 20) + 0);
}

f32 func_80115478(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 20) + 4);
}

void func_80115484(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEC40/func_801154A4.s")

void func_80115564(u8 *arg0) {
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x14)));
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x14)));
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x14)));
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x18)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEEC40/func_80115580.s")

f32 func_801155E8(void *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x14)))) + (0x10))) * 1.5f;
}
