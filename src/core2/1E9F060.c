#include "common.h"

void func_800C5770(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5778.s")

void func_800C57C0(void) {
    s32 func_800BF48C(u8, u8, u8);
    extern s32 D_8012AA20;
    func_800BF48C((*(u8 *)((s8 *)(&D_8012AA20) + (8))), (*(u8 *)((s8 *)(&D_8012AA20) + (9))), (*(u8 *)((s8 *)(&D_8012AA20) + (0xA))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C57F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5968.s")

/* extern */

void func_800C59F0(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800C5968(s32, s32, s32, f32);
    func_800C5968(arg0, arg1, arg2, 0.0f);
}

void func_800C5A10(u8 *arg0, s32 arg1) {
    if (arg1 == 1) {
        arg0[0x93] = 5;
    }
    if (arg1 == 4) {
        arg0[0x92] = 1;
    }
    arg0[0x94] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5A38.s")

void func_800C5B84(s32 arg0)
{
    func_800C5A10(arg0,1);
}

void func_800C5BA4(void* arg0) 
{
    heap_free(arg0);
}
void* func_800C5BC4(void* arg0) 
{
    return defrag(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5BE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5CC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5E14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5F40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5F8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5FCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6038.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C65E0.s")

u32 func_800C6704(u8 *arg0) {
    return arg0[142];
}

u8 func_800C670C(void *arg0) {
    extern f32 D_801258AC;
    if (D_801258AC == (*(f32 *)((s8 *)(arg0) + (0x74)))) {
        return 0U;
    }
    return (*(u8 *)((s8 *)(arg0) + (0x8F)));
}

f32 func_800C673C(f32 *arg0) {
    return arg0[30];
}

s32 func_800C6744(s32 *arg0) {
    return arg0[31];
}

s32 func_800C674C(s16 *arg0) {
    return arg0[70];
}

u32 func_800C6754(u8 *arg0) {
    return arg0[149];
}

void func_800C675C(void *arg0, f32 *arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x64);
}

f32 func_800C6784(void *arg0) {
    f32 temp_f2;

    if ((*(u8 *)((s8 *)(arg0) + (0x95))) != 0) {
        temp_f2 = (*(f32 *)((s8 *)(arg0) + (0x74))) - 15.0f;
        if ((*(f32 *)((s8 *)(arg0) + (0x70))) < temp_f2) {
            return temp_f2;
        }
    }
    return (*(f32 *)((s8 *)(arg0) + (0x70)));
}

s32 func_800C67C8(s32 *arg0) {
    return arg0[0];
}

u32 func_800C67D0(u8 *arg0) {
    return arg0[156];
}

f32 func_800C67D8(f32 *arg0) {
    return arg0[29];
}

s32 func_800C67E0(s32 *arg0) {
    return arg0[32];
}

void *func_800C67E8(void *arg0) {
    return (u8 *) arg0 + 0x10;
}

void *func_800C67F0(void *arg0) {
    return (u8 *) arg0 + 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C67F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6840.s")

void func_800C68A0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 120) = arg1;
}

/* extern */

void func_800C68AC(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x4C);
}

void func_800C68CC(s32 *arg0, s32 arg1) {
    arg0[33] = arg1;
}

void func_800C68D4(s8 *arg0, s32 arg1) {
    arg0[149] = arg1;
}

void func_800C68DC(s8 *arg0) {
    arg0[147] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C68E8.s")
