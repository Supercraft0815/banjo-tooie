#include "common.h"

s32 ncbafixpos_entrypoint_0() 
{
    return 0x1C;
}

void ncbafixpos_entrypoint_1(u8 *arg0) {
    s32 func_801124D0(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x1A))) = 1;
    func_801124D0((s32) arg0, 1);
}

void ncbafixpos_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fixpos/func_8080003C_ncbafixpos.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fixpos/ncbafixpos_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fixpos/ncbafixpos_entrypoint_4.s")
