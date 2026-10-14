#include "common.h"

s32 func_80114E80(s32 arg0) { extern u8 D_80124A50; u8 *base = &D_80124A50; u8 *p = &D_80124A50; if (D_80124A50 != 0) { do { if (arg0 == *p) { return (p - base) / 5; } p += 5; } while (*p != 0); } return (p - base) / 5; }

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
void *func_80115118(s32 arg0) {
    s32 func_800EA05C();
    s32 func_80114E80(s32);
    extern s16 D_80124A58;
    s16 *ptr;
    s16 map;
    void *result;

    result = heap_alloc(0x14);
    (*(s32 *)((s8 *)result + 0)) = arg0;
    (*(s32 *)((s8 *)result + 4)) = func_80114E80(func_800EA05C());
    (*(s8 *)((s8 *)result + 0xC)) = 0;
    (*(s8 *)((s8 *)result + 0xD)) = 0;
    (*(s8 *)((s8 *)result + 0xE)) = 1;
    (*(f32 *)((s8 *)result + 0x10)) = 0.0f;
    map = func_800EA05C();
    ptr = &D_80124A58;
    while (*ptr != 0) {
        if (map == *ptr) {
            (*(s8 *)((s8 *)result + 0xE)) = 0;
            break;
        }
        ptr++;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEE770/func_801151C4.s")

/* extern */

void func_80115324(s32 *arg0, s32 arg1) {
    s32 defrag();
    *arg0 = arg1;
    defrag();
}
