#include "common.h"

s32 baflamethrower_entrypoint_0() 
{
    return 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/func_80800008_baflamethrower.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/func_80800088_baflamethrower.s")

void baflamethrower_entrypoint_1(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0);
    _baflameline_entrypoint_2(arg0);
}

void baflamethrower_entrypoint_2(s32 arg0, s32 arg1) { _baflameline_entrypoint_3(); (*(s32 *)((s8 *)(*(u8 **)((s8 *)(arg0) + 0x88)) + 0)) = arg1; (*(s8 *)((s8 *)(*(u8 **)((s8 *)(arg0) + 0x88)) + 0xC)) = 0; func_80800088_baflamethrower(arg0, 1); }

void baflamethrower_entrypoint_3(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0x2);
}

void baflamethrower_entrypoint_4(s32 arg0)
{
    func_80800088_baflamethrower(arg0,0x3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/flamethrower/baflamethrower_entrypoint_5.s")
