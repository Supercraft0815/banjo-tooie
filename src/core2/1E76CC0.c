#include "core2/1E76CC0.h"

s32 func_8009D3D0() 
{
    return 0x20;
}

void func_8009D3D8(s32 arg0)
{
    func_8009E674(arg0,0x2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D3F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D454.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D4A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D4D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D7A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D820.s")

void func_8009D874(PlayerState *arg0) {
    func_8009DE38(arg0, 0x442E, 1.117f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D9D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DA40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DB04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DBB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DBF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DC98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DCCC.s")

u32 func_8009DDD0(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 260) + 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DDDC.s")

/* extern */

void func_8009DE14(void *arg0) {
    s32 func_800C3D78(u8);
    func_800C3D78((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))));
}

/* extern */

void func_8009DE38(PlayerState *arg0, s32 arg1, f32 arg2) {
    s32 func_8009DCCC(f32, u8, s32, f32, s32);
    func_8009DCCC(arg2, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), arg1, arg2, 0x55F0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DE74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DEC0.s")

/* extern */

void func_8009DF18(PlayerState *arg0, s32 arg1, f32 arg2, s32 arg3) {
    s32 func_8009DCCC(f32, u8, s32, f32, s32);
    func_8009DCCC(arg2, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), arg1, arg2, arg3);
}

/* extern */

void func_8009DF58(PlayerState *arg0, s32 arg1, f32 arg2) {
    s32 func_8009DCCC(f32, u8, s32, f32, s32);
    func_8009DCCC(arg2, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), arg1, arg2, 0x55F0);
}

/* extern */

void func_8009DF94(PlayerState *arg0, s32 arg1, f32 arg2, s32 arg3) {
    s32 func_8009DCCC(f32, u8, s32, f32, s32);
    func_8009DCCC(arg2, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), arg1, arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DFD4.s")

void func_8009E02C(PlayerState *arg0) {
    func_8009DF18(arg0, 0x417, 0.8f, 0x7FFF);
}

void func_8009E058(PlayerState *arg0) {
    func_8009DF18(arg0, 0x417, 0.8f, 0x4650);
}

void func_8009E084(PlayerState *arg0) {
    func_8009DF18(arg0, 0x417, 1.0f, 0x36B0);
}

void func_8009E0AC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 260) + 28) = arg1;
}

/* extern */

void func_8009E0B8(void *arg0) {
    s32 func_800C3CE8(u8);
    func_800C3CE8(*(*(u8 **)((s8 *)(arg0) + (0x104))));
}

/* extern */

void func_8009E0DC(PlayerState *arg0) {
    s32 func_800C3CE8(u8);
    func_800C3CE8((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))));
}

/* extern */

void func_8009E100(PlayerState *arg0) {
    s32 func_800C3CE8(u8);
    func_800C3CE8((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))));
}
