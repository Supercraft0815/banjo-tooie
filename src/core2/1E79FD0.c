#include "core2/1E79FD0.h"

s32 func_800A06E0() 
{
    return 0x18;
}

/* extern */

void func_800A06E8(s32 arg0) {
    s32 func_80092B80();
    s32 func_800A0714(s32, s32);
    func_800A0714(arg0, func_80092B80());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E79FD0/func_800A0714.s")

s32 func_800A0C20(PlayerState *self)
{
    return (*(u8 **)((u8 *)self + 0x138))[0x10];
}

f32 func_800A0C2C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 0);
}

f32 func_800A0C38(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E79FD0/func_800A0C44.s")

void func_800A0CD0(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 18) = arg1;
}

void func_800A0CDC(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 13) = arg1;
}

void func_800A0CE8(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 14) = arg1;
}

void func_800A0CF4(PlayerState* arg0, s32 arg1) 
{
    func_800A0D14(arg0, arg1, 0.0f);
}

void func_800A0D14(PlayerState *arg0, s32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (8))) = arg2;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0xC))) = (s8) arg1;
    if (arg2 == 0.0f) {
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (0x10))) = (s8) arg1;
    }
}

void func_800A0D44(PlayerState *arg0, s32 arg1) {
    func_800A0D14(arg0, arg1, 0.2f);
}

void func_800A0D68(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 23) = arg1;
}

void func_800A0D74(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 0) = arg1;
}

void func_800A0D84(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 4) = arg1;
}

void func_800A0D94(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 22) = arg1;
}

s32 func_800A0DA0(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 20) = arg1;
}

void func_800A0DAC(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 19) = arg1;
}

void func_800A0DB8(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 15) = arg1;
}

void func_800A0DC4(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 21) = arg1;
}

void func_800A0DD0(PlayerState *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 312) + 17) = arg1;
}

/* extern */

void func_800A0DDC(void *arg0) {
    f32 func_800D8FF8(void);
    f32 delta;
    void *temp_v0;

    if ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x138)))) + (8))) != 0.0f) {
        delta = func_800D8FF8();
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x138)));
        (*(f32 *)((s8 *)(temp_v0) + (8))) -= delta;
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x138)));
        if ((*(f32 *)((s8 *)(temp_v0) + (8))) <= 0.0f) {
            (*(u8 *)((s8 *)(temp_v0) + (0x10))) = (u8) (*(u8 *)((s8 *)(temp_v0) + (0xC)));
        }
    }
}

s32 func_800A0E50() 
{
    return 0x14;
}

f32 func_800A0E58(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E79FD0/func_800A0E64.s")

u32 func_800A0FCC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 2);
}

u32 func_800A0FD8(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 0);
}

u32 func_800A0FE4(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 336) + 1);
}

void func_800A0FF0(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (2))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (0))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (1))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (4))) = 50.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (8))) = 70.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (0xC))) = -1.0f;
}

void func_800A1040(PlayerState *arg0) {
    u8 *temp_v0;
    u8 *temp_v0_2;
    f32 *temp_f0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x150)));
    (*(f32 *)((s8 *)(temp_v0) + (4))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    temp_v0 = (u8 *)(*(u8 **)((s8 *)(arg0) + (0x150)));
    temp_f0 = (f32 *)temp_v0;
    temp_f0[2] = temp_f0[4];
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x150)))) + (0xC))) = -1.0f;
}

void func_800A106C(PlayerState *arg0, f32 arg1, f32 arg2) {
    void *temp_v0;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x150)));
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (4)));
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x150)));
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (8)));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (4))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x150)))) + (8))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E79FD0/func_800A10A0.s")
