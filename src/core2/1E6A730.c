#include "core2/1E6A730.h"

s32 func_80090E40(void)
{
	return 0x18;
}

void func_80090E48(void *arg0) {
    s32 func_8008FD48();
    void func_80092DE4(PlayerState *, f32 *);
    void func_80092E5C(PlayerState *, f32 *);
    void func_8009DF94(PlayerState *, s32, f32, s32);
    s32 func_8009FBB0(PlayerState *, f32[3], f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    extern s32 D_80117DB0;
    extern f32 D_80124D00;
    extern f32 D_80124D04;
    f32 sp34[3];
    void *temp_v1;

    if (((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0xD))) == 0) || (func_8008FD48() != 1)) {
        func_80092E5C(arg0, sp34);
    } else {
        func_80092DE4(arg0, sp34);
    }
    func_800BABB8(func_8009FBB0(arg0, sp34, 0.0f), 0, 0, 1.0f, &D_80117DB0);
    temp_v1 = (*(void **)((s8 *)(arg0) + (0x30)));
    if (((*(u8 *)((s8 *)(temp_v1) + (0xF))) != 0) && ((*(f32 *)((s8 *)(temp_v1) + (0))) == 0.0f)) {
        (*(f32 *)((s8 *)(temp_v1) + (0))) = (f32) D_80124D00;
        func_8009DF94(arg0, 0x3ED, func_800DC178(0.5f, D_80124D04), 0x1770);
    }
}

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
