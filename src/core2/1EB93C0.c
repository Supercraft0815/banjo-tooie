#include "core2/1EB93C0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFAD0.s")

void func_800DFB40(s32 *arg0, s32 arg1, u8 *arg2) {
    void func_800D9600(void *arg0, void *arg1);
    func_800D9600(arg2, *arg0 + (arg1 * 0x28));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFB7C.s")

void func_800DFBE0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800EE7F8(s32, s32);
    func_800EE7F8(arg2, *arg0 + (arg1 * 0x28) + 0x10);
}

void func_800DFC20(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800EE7F8(s32, s32);
    func_800EE7F8(arg2, *arg0 + (arg1 * 0x28) + 0x1C);
}

void func_800DFC60(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFC80.s")

/* extern */

void func_800DFCC0(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

/* extern */

void func_800DFCE8(s16 arg0) {
    s32 func_8001B798(s16);
    func_8001B798(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFD10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFD64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFEA8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFF2C.s")

/* extern */

void func_800DFF64(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800EE7F8(s32, s32);
    func_800EE7F8(*arg0 + (arg1 * 0x28) + 0x10, arg2);
}

/* extern */

void func_800DFFA0(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800EE7F8(s32, s32);
    s32 **base = &arg0;
    func_800EE7F8(**base + (arg1 * 0x28) + 0x1C, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFFDC.s")

/* extern */

void func_800E0018(void) {
    s32 *defrag();
    s32 *temp_v0;

    temp_v0 = defrag();
    *temp_v0 = (s32) temp_v0 + 8;
}

void func_800E0040(u32 *arg0) {
    arg0[0] = (u32) arg0 + 8;
}
