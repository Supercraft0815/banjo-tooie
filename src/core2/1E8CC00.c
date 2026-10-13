#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B3310.s")

void func_800B3370(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B3390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B3494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B36C0.s")

/* extern */

void func_800B3748(s32 arg0) {
    s32 func_800B36C0(s32, f32 *, s32 *, f32);
    s32 func_800C8960(s32 *, f32 *);
    f32 sp24[3];
    s32 pad[2];
    s32 sp18;

    func_800C8960(&sp18, sp24);
    func_800B36C0(arg0, sp24, &sp18, 500.0f);
}

s32 func_800B3784(u8 *arg0) { return ((*(s32 *)((s8 *)arg0 + 0x10) - (s32)arg0) - 0x18) / 28; }

void func_800B37A4(u8 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0 + 0x18;
    *arg2 = (*(s32 *)((s8 *)(arg0) + (0x10)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B37B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B37E4.s")

void func_800B388C(u8 *arg0, s32 arg1) {
    (*(s32 *)((s8 *)(arg0) + (0x14))) = (s32) ((arg0 + 0x18) + (arg1 * 0x1C));
}

void func_800B38A8()
{
    func_800EE830();
}

void func_800B38C8()
{
    func_800C87B8();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B38E8.s")
