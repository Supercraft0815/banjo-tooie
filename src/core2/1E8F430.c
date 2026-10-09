#include "core2/1E8F430.h"

extern s32 D_801282B4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5B40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5B88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5C7C.s")

void func_800B5DD4()
{
    func_800B5C7C(0x8);
}

void func_800B5DF4(void) {
}

void func_800B5DFC(void) {
}

void func_800B5E04(void) {
    s32 vector_free(s32);
    extern s32 D_80128180;
    if (D_80128180 != 0) {
        vector_free(D_80128180);
        D_80128180 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5E3C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B60C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B62CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7174.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B71F4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B798C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7A98.s")

void func_800B7ADC(s32 arg0) {
    extern s8 D_8012818F;
    *(s8 *)((u8 *)&D_8012818F + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7AE8.s")

void func_800B7B2C(s32 arg0) {
    extern s16 D_80128194;
    *(s16 *)((u8 *)&D_80128194 + 0) = arg0;
}

void func_800B7B38(s32 arg0) {
    extern s8 D_80128191;
    *(s8 *)((u8 *)&D_80128191 + 0) = arg0;
}

void func_800B7B44(s32 arg0) {
    extern s8 D_80128193;
    if (arg0 != 0) {
        D_80128193 = 1;
        return;
    }
    D_80128193 = 0;
}

void func_800B7B68(s32 arg0) {
    extern s8 D_80128192;
    if (arg0 != 0) {
        D_80128192 = 1;
        return;
    }
    D_80128192 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7B8C.s")

void func_800B7BA4(f32 arg0) {
    extern f32 D_80128198;
    *(f32 *)((u8 *)&D_80128198 + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7BB0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7C54.s")

s32 func_800B7C98()
{
    return D_801282B4;
}

void func_800B7CA4()
{
    func_800B9038();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7CC4.s")

void func_800B7D14(void) {
    extern s32 D_801282B0;
    (*(s32 *)((s8 *)(&D_801282B0) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_801282B0) + (4))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7D28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7DC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7E38.s")
