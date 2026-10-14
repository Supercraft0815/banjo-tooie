#include "common.h"

s32 baflamethrower_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void func_80800008_baflamethrower(void *arg0) {
    s32 _baflameline_entrypoint_4(void *, s32 *);
    s32 _baflameline_entrypoint_5(void *, s32 *);
    s32 _baflameline_entrypoint_6(void *, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 sp2C[3];
    s32 sp20[3];

    (*(s32 (**)(void *, s32 *, s32 *))((s8 *)((*(void **)((s8 *)(arg0) + (0x88)))) + (0)))(arg0, sp2C, sp20);
    _baflameline_entrypoint_4(arg0, sp2C);
    _baflameline_entrypoint_5(arg0, sp20);
    _baflameline_entrypoint_6(arg0, (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x88)))) + (4))));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x88)))) + (4))) = func_800F15F8((*(f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x88)) + 4)), (*(f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x88)) + 8)), 20.0f);
}

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
