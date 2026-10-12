#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEE770/func_80114E80.s")

/* extern */

void func_80114EEC(void *arg0, s32 arg1) {
    s32 pad;
    f32 func_80013970(f32);
    s32 func_800A940C(s32);
    s32 func_800C4B90(s32, f32, f32);
    s32 func_800EA068(s32);
    s32 func_80110014(s32);
    s32 func_80110840(s32);
    f32 sp28;
    f32 sp24;

    sp24 = func_80013970((*(f32 *)((s8 *)(arg0) + (0x10)))) * 1.5f;
    sp28 = func_80013970((*(f32 *)((s8 *)(arg0) + (0x10))) * 1.5f) * 1.5f;
    if (func_800EA068(0x20) == 0) {
        func_800C4B90(func_800A940C(func_80110840(func_80110014((*(s32 *)((s8 *)(arg0) + (0)))))), sp24, sp28);
        (*(s8 *)((s8 *)(arg0) + (0xD))) = 1;
        (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x10))) + 2.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEE770/func_80114FA4.s")

u32 func_801150F0(u8 *arg0) {
    return arg0[12];
}

void func_801150F8(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEE770/func_80115118.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEE770/func_801151C4.s")

/* extern */

void func_80115324(s32 *arg0, s32 arg1) {
    s32 defrag();
    *arg0 = arg1;
    defrag();
}
