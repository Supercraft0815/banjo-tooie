#include "common.h"

void subaddiecustomhits_entrypoint_0(void **arg0, s32 arg1) {
    void func_800EC358(void *, s32);

    func_800EC358(*arg0, arg1);
    (*(u8 *)((s8 *)(arg0) + (0x74))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x74))) & 0xFF7F) | 0x80);
}

OSThread *subaddiecustomhits_entrypoint_1(void)
{
    extern u8 D_80800350_subaddiecustomhits[];

    return (OSThread *) D_80800350_subaddiecustomhits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/customhits/subaddiecustomhits_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/customhits/subaddiecustomhits_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/customhits/subaddiecustomhits_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/customhits/subaddiecustomhits_entrypoint_5.s")
