#include "core2/1E6A730.h"

s32 func_80090E40(void)
{
	return 0x18;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6A730/func_80090E48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6A730/func_80090F38.s")

void func_80091030(void *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (4))) = 0.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xC))) = 1;
}

void func_80091054(s32 arg0) 
{

}

void func_8009105C(PlayerState *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xC))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (4))) = 2.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xE))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x14))) = 0.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xF))) = 1;
    func_800910BC(arg0, 1);
}

void func_800910BC(PlayerState *arg0, s32 arg1) {
    void *p;

    p = *(void **)((s8 *)arg0 + 0x30);
    if (*(u8 *)((s8 *)p + 0xE) == 4) {
        *(f32 *)((s8 *)p + 4) = 0.0f;
        *(s8 *)((s8 *)*(void **)((s8 *)arg0 + 0x30) + 0xC) = 0;
        *(f32 *)((s8 *)*(void **)((s8 *)arg0 + 0x30) + 0x14) = 0.0f;
        p = *(void **)((s8 *)arg0 + 0x30);
        *(f32 *)((s8 *)p + 0x10) = *(f32 *)((s8 *)p + 0x14);
    }
    p = *(void **)((s8 *)arg0 + 0x30);
    *(s8 *)((s8 *)p + 0xE) = arg1;
}

void func_80091104(s32 *arg0, s32 arg1)
{
    *(u8 *) (arg0[12] + 0xF) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6A730/func_80091110.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E6A730/func_80091290.s")

void func_800914FC(PlayerState *arg0, f32 arg1, s32 arg2) {
    func_80091290(arg0, arg1, arg2, 4);
}
