#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4534.s")

void func_800D4564()
{
    func_800AAD28();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4584.s")

/* extern */

void func_800D4D5C(s32 arg0, void *arg1) {
    s32 func_800C65E0(s32);
    s32 func_800C68AC(s32, s32);
    s32 func_800C68CC(s32, s32);
    s32 func_800EA600(s32);
    s32 func_800EA614();
    func_800EA600((*(s32 *)((s8 *)(arg1) + (0xC))));
    (*(s32 (**)(void *))((s8 *)(arg1) + (0x10)))(arg1);
    func_800C68AC((*(s32 *)((s8 *)(arg1) + (0))), arg0);
    func_800C68CC((*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (0x14))));
    func_800C65E0((*(s32 *)((s8 *)(arg1) + (0))));
    func_800EA614();
}
