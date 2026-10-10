#include "common.h"

s32 bamum_entrypoint_0() 
{
    return 0x8;
}

void func_80800008_bamum(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xD0)))) + (4))) = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/mum/func_80800018_bamum.s")

void bamum_entrypoint_1(s32 arg0) 
{
}
/* extern */

void bamum_entrypoint_2(void *arg0) {
    s32 func_8009ADF0(void *, s32, s32);
    func_80800008_bamum(arg0);
    func_8009ADF0(arg0, 5, 0);
}

void bamum_entrypoint_3()
{
    func_80800018_bamum();
}

void bamum_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 func_8009ADF0(void *, s32, s32);
    if (arg1 != 0) {
        func_8009ADF0(arg0, 5, 1);
        func_80800008_bamum(arg0);
        return;
    }
    func_8009ADF0(arg0, 5, 0);
}

void bamum_entrypoint_5(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 208) + 4) = arg1;
}
