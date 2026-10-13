#include "core2/1EEBA50.h"

s32 func_80112160() 
{
    return 0x34;
}

f32 func_80112168(s32 *arg0, f32 *arg1) {
    s32 func_80110840(s32 *);
    f32 func_800F5BC4(s32, f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800EF04C(f32 *, f32 *);
    f32 sp2C;
    f32 sp20[3];
    s32 sp1C;

    sp1C = func_80110840(arg0);
    sp2C = func_800F5BC4(sp1C, arg1);
    func_800F5A00(sp1C, sp20);
    func_800EF04C(arg1, sp20);
    return sp2C;
}

void func_801121B8(PlayerState* arg0, f32* arg1)
{
    func_80112168(arg0,arg1);
}

/* extern */

void func_801121D8(s32 *arg0, f32 *arg1) {
    s32 func_80110840(s32 *);
    void func_800F5A00(s32, f32 *);
    func_800F5A00(func_80110840(arg0), arg1);
}

void func_80112204(s32 *arg0, f32 *arg1) {
    s32 func_80110840(s32 *);
    void func_800F5470(s32, f32 *);
    f32 sp1C[3];

    func_80112168(arg0, arg1);
    func_800F5470(func_80110840(arg0), sp1C);
    arg1[0] = sp1C[0];
    arg1[2] = sp1C[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEBA50/func_80112250.s")

void func_80112354(PlayerState *arg0, s32 arg1) {
    func_80112168(arg0, arg1);
    (*(f32 *)((s8 *)(arg1) + (0))) = (f32) (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x28)));
    (*(f32 *)((s8 *)(arg1) + (8))) = (f32) (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x30)));
}

void func_80112398(u8 *arg0) {
    void func_800EFD24(f32 vec[3]);
    void func_801124D0(s32, s32);
    *(*(s32 **)((s8 *)(arg0) + (0x30))) = 0;
    func_801124D0((s32) arg0, 1);
    func_800EFD24((f32 *)(*(s32 **)((s8 *)(arg0) + (0x30))) + 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EEBA50/func_801123D4.s")

void func_801124D0(s32 arg0, s32 arg1) { s32 temp_a2; volatile s32 **temp_a1; temp_a2 = arg1; if (arg1 == 6) { temp_a1 = (volatile s32 **)((s8 *)(arg0) + 0x30); func_801121B8((PlayerState *) arg0, (f32 *)((s8 *)*temp_a1 + 0x28)); } **(s32 ***)((s8 *)(arg0) + 0x30) = temp_a2; }

s32 func_80112518(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 48) + 0);
}

/* extern */

void func_80112524(PlayerState *arg0, f32 *arg1) {
    s32 func_800EE7F8(f32 *, s32);
    func_800EE7F8(arg1, (*(s32 *)((s8 *)(arg0) + (0x30))) + 4);
}

void func_80112550(PlayerState* arg0, f32* arg1)
{
    func_80112168(arg0,arg1);
}

void func_80112570(u8 *arg0, s32 arg1, f32 arg2) {
    s32 func_800EE7F8(f32 *, s32);
    func_800EE7F8((*(u8 **)((s8 *)(arg0) + (0x30))) + 0x18, arg1);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x30)))) + (0x24))) = arg2;
}
