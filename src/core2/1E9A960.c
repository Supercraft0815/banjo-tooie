#include "core2/1E9A960.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1104.s")

void func_800C11F8(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7A];
        unsigned char value : 3;
        unsigned char rest : 5;
    };
    ((struct Flags *)arg0)->value = arg1;
}

void func_800C1210(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x7A];
        unsigned char first : 3;
        unsigned char value : 3;
        unsigned char last : 2;
    };
    ((struct Flags *)arg0)->value = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C122C.s")

void func_800C13A0(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7C))) | arg1);
}

void func_800C13B0(void *arg0, s32 arg1) {
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7C))) & ~arg1);
}

u32 func_800C13C4(u16 *arg0, u32 arg1)
{
    return (u32) arg0[0x3E] & arg1;
}

s32 func_800C13D0(void *arg0, s32 arg1) {
    return ((*(u16 *)((s8 *)(arg0) + (0x7C))) & arg1) == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C13E4.s")

void *func_800C1414(u8 arg0) {
    extern s32 D_80128B90;
    s32 index = arg0;
    s32 *base = &D_80128B90;
    return (void *)((u8 *)base + (index << 7));
}

u8 *func_800C1430(s32 arg0) {
    extern s32 D_80128B10;
    return (u8 *) &D_80128B10 + ((arg0 << 3) - 8);
}

s32 func_800C1448(s32 arg0) {
    extern s64 D_80128B08;
    return *(s32 *)((u8 *)&D_80128B08 + (arg0 << 3));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C145C.s")

void func_800C1568(s32 arg0) {
    extern s32 D_80128B0C;
    *((s32 *)((u8 *)&D_80128B0C + (arg0 << 3))) = 0;
}

void func_800C157C(void) {
    extern s32 D_80128B10;
    extern s32 D_80128B90;
    u32 end;
    s32 *var_v1;

    end = (u32)&D_80128B90;
    for (var_v1 = &D_80128B10; ; ) {
    var_v1 += 8;
    ((s32 *)var_v1)[-6] = 0;
    ((s32 *)var_v1)[-5] = 0;
    ((s32 *)var_v1)[-4] = 0;
    ((s32 *)var_v1)[-3] = 0;
    ((s32 *)var_v1)[-2] = 0;
    ((s32 *)var_v1)[-1] = 0;
    ((s32 *)var_v1)[-8] = 0;
    ((s32 *)var_v1)[-7] = 0;
        if ((u32)var_v1 == end) {
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C15BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C16A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C16F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1860.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C18C8.s")

/* extern */

void func_800C191C(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    s32 func_800DC4B0(s32, s32);
    if (arg0 != 0) {
        func_800DC4B0(func_800C1448(), arg1);
    }
}

/* extern */

void func_800C1950(s32 arg0, s32 arg1) {
    s32 func_800C1448();
    s32 func_800DC42C(s32, s32);
    if (arg0 != 0) {
        func_800DC42C(func_800C1448(), arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1984.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C19E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1CCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C1D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2000.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C269C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2718.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2840.s")

void func_800C28D8()
{
    func_800C157C();
    func_800C13E4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2900.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2A08.s")

void func_800C2A5C(s32 arg0, s32 arg1) {
}
void func_800C2A68()
{
    func_80017244();
    func_80016E7C();
}

void func_800C2A90()
{
    func_800C2900();
    func_800C2A68();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2AB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2B80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2C4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2E04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2E40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C2FDC.s")

void func_800C301C(u8 id, s32 arg1) {
    if (id != 0) {
        (*(s16 *)((s8 *)(func_800C1414(id)) + (0x58))) = (s16) arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3058.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C30B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C316C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C31DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3224.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C32C4.s")

void func_800C330C(u8 id, s32 arg1) {
    extern void func_800C11F8(void *, s32);
    extern void *func_800C1414(u8);

    if (id != 0) {
        func_800C11F8(func_800C1414(id), arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C334C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3394.s")

void func_800C33DC(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x1B))) = (s8) arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3418.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C34CC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3528.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3584.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C35E8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C368C.s")

void func_800C36F4(u8 arg0, s32 arg1) {
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x62))) = (s8) arg1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3798.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C37E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3868.s")

s16 func_800C38E4(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s16 *)((s8 *)(func_800C1414(arg0)) + (0x58)));
}

s16 func_800C3920(u8 arg0) {
    if (arg0 == 0) {
        return 0;
    }
    return (*(s16 *)((s8 *)(func_800C1414(arg0)) + (0x5A)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C395C.s")

s32 func_800C39A0(u8 id) {
    u16 *p = (u16 *) ((u8 *) func_800C1414(id) + 0x7A);
    return ((u32) *p) >> 13;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C39D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3A40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3AE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3B8C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3BDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3CE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3D78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3E00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3E88.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3EB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3EE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3F14.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3F48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3FC0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C3FF0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C401C.s")

void func_800C4104(s32 arg0, f32 arg1, s32 arg2, s32 arg3, f32 arg4, f32 arg5) {
    s32 func_800C401C(s32, f32, s32, s32, f32, f32, s32);
    func_800C401C(arg0, arg1, arg2, arg3, arg4, arg5, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4140.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4208.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4244.s")

void func_800C427C()
{
    func_800C2718();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C429C.s")

/* extern */

void func_800C42E0(s32 arg0) {
    s32 func_800DC548(s32, s32, s32);
    func_800DC548(0, arg0 - 0x3E9, arg0);
}

void func_800C4308(f32 arg0, f32 arg1) {
    extern f32 D_8011A870;
    extern f32 D_8011A874;
    D_8011A870 = arg0;
    D_8011A874 = arg1;
}

void func_800C431C(u8 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800C1414(arg0)) + (0x63))) = (s8) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9A960/func_800C4AF0.s")

void func_800C4B64(f32 arg0) {
    extern f32 D_8012A990;
    *(f32 *)((u8 *)&D_8012A990 + 0) = arg0;
}

void func_800C4B70(s32 arg0) {
    extern s16 D_8012A994;
    *(s16 *)((u8 *)&D_8012A994 + 0) = arg0;
}

void func_800C4B7C(s32 arg0) {
    extern s16 D_8012A996;
    *(s16 *)((u8 *)&D_8012A996 + 0) = arg0;
}
