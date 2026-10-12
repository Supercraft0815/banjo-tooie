#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BBD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BBED8.s")

void func_800BBFDC(void *arg0, s32 arg1) {
    s32 func_800BBED8(void *, s32, f32 *);
    s32 func_800D674C(s32);
    void func_800E2440(s32, s32, s32);
    void func_800E24B4(s32);
    void func_800E24D8(s32);
    void func_800E24F8(s32, s32, s32);
    void func_800E2530(f32);
    void func_800E2588(u32);
    s32 func_800E2594(s32, s32);
    s32 func_800E2720(s32, s32, s32, f32 *, f32 *, s32);
    s32 func_800E28A4(s32, s32, s32, f32 *, f32 *, f32 *, s32);
    s32 func_800E2A14(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    struct DrawFlags { u8 drawn : 1; u8 rest : 7; };
    s32 temp_s0;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    s32 var_s4;
    u8 *var_s0;

    temp_s0 = func_800D674C((*(u16 *)((s8 *)(arg0) + (2))));
    var_s4 = ((*(u16 *)arg0) & 0x800) ? 1 : 0;
    if (!((*(u16 *)arg0) & 0x20) && (((*(u8 *)((s8 *)(arg0) + (0x80))) != 0xFF) || ((*(u8 *)((s8 *)(arg0) + (0x81))) != 0xFF) || ((*(u8 *)((s8 *)(arg0) + (0x82))) != 0xFF) || ((*(u8 *)((s8 *)(arg0) + (0x83))) != 0xFF))) {
        func_800E2588((*(u8 *)((s8 *)(arg0) + (0x53))));
        func_800E24F8((*(u8 *)((s8 *)(arg0) + (0x80))), (*(u8 *)((s8 *)(arg0) + (0x81))), (*(u8 *)((s8 *)(arg0) + (0x82))));
        func_800E2440(
            (*(u8 *)((u8 *)arg0 + 0x80)) < 8 ? 0 : (*(u8 *)((u8 *)arg0 + 0x80)) - 8,
            (*(u8 *)((u8 *)arg0 + 0x81)) < 8 ? 0 : (*(u8 *)((u8 *)arg0 + 0x81)) - 8,
            (*(u8 *)((u8 *)arg0 + 0x82)) < 8 ? 0 : (*(u8 *)((u8 *)arg0 + 0x82)) - 8);
        func_800E24B4(0);
    } else {
        func_800E2588((*(u8 *)((s8 *)arg0 + 0x53)) ? 2 : 0);
    }
    func_800E24D8((*(u16 *)arg0) & 0x200 ? 1 : 0);
    func_800E2594(arg1, temp_s0);
    if ((*(u16 *)((s8 *)(arg0) + (0))) & 1) {
        func_800EFA4C(sp6C, 90.0f, 0.0f, 0.0f);
    }
    var_s0 = (*(u8 **)((s8 *)(arg0) + (0x8C)));
    if (var_s0 < (*(u8 **)((s8 *)(arg0) + (0x90)))) {
        do {
            sp78[0] = (f32) ((*(s16 *)((s8 *)(var_s0) + (6))) + (*(s16 *)((s8 *)(arg0) + (0xC))));
            sp78[1] = (f32) ((*(s16 *)((s8 *)(var_s0) + (8))) + (*(s16 *)((s8 *)(arg0) + (0xE))));
            sp78[2] = (f32) ((*(s16 *)((s8 *)(var_s0) + (0xA))) + (*(s16 *)((s8 *)(arg0) + (0x10))));
            sp60[0] = sp60[1] = sp60[2] = (f32) (*(s16 *)((s8 *)(var_s0) + (0x30))) * 0.00390625f;
            if ((*(f32 *)((s8 *)(arg0) + (0x5C))) != 0.0f) {
                func_800BBED8(arg0, (*(s32 *)((s8 *)(var_s0) + (0x1C))), sp60);
            }
            if ((*(u16 *)((s8 *)(arg0) + (0))) & 1) {
                ((struct DrawFlags *)((u8 *)var_s0 + 0x39))->drawn |= func_800E28A4(arg1, (s16) (*(s16 *)((s8 *)(var_s0) + (0x2C))) >> 8, var_s4, sp78, sp6C, sp60, (s32) ((*(f32 *)((s8 *)(var_s0) + (0xC))) * (f32) (u32) (*(u8 *)((s8 *)(arg0) + (0x83)))));
            } else {
                func_800E2530((*(f32 *)((s8 *)(var_s0) + (0x18))));
                ((struct DrawFlags *)((u8 *)var_s0 + 0x39))->drawn |= func_800E2720(arg1, (s16) (*(s16 *)((s8 *)(var_s0) + (0x2C))) >> 8, var_s4, sp78, sp60, (s32) ((*(f32 *)((s8 *)(var_s0) + (0xC))) * (f32) (u32) (*(u8 *)((s8 *)(arg0) + (0x83)))));
            }
            var_s0 += 0x3C;
        } while (var_s0 < (*(u8 **)((s8 *)(arg0) + (0x90))));
    }
    func_800E2A14(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BC358.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BC3B8.s")

void* func_800BC3F0(void* arg0) 
{
    return defrag(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BC410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BC474.s")

/* extern */

void func_800BC580(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_800BC474(s32, s32, s32, s32, s32, s32, s32, s32);
    func_800BC474(arg0, arg1, arg2, arg3, arg4, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E95650/func_800BC5B0.s")
