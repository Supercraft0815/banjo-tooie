#include "core2/1E7D460.h"

s32 func_800A3B70() 
{
    return 0x40;
}

/* extern */

void func_800A3B78(PlayerState *arg0, s32 arg1) {
    s32 func_801106A8(PlayerState *, s32);
    PlayerState *temp_v0;

    temp_v0 = func_800A4CA8(arg0);
    if (temp_v0 != NULL) {
        func_801106A8(temp_v0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A3BA8.s")

/* extern */

void func_800A3D78(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800A3BA8(s32, s32);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
    if (arg1 != (*(u8 *)((s8 *)(temp_v0) + (2)))) {
        (*(u8 *)((s8 *)(temp_v0) + (2))) = arg1;
        func_800A3BA8((s32)arg0, arg2);
    }
}

u32 func_800A3DAC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 56) + 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A3DB8.s")

/* extern */

void func_800A3EC8(PlayerState *arg0, s32 arg1) {
    s32 func_80110D08(PlayerState *, u8, PlayerState *);
    if (arg1 != (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7)))) {
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))) = arg1;
        func_80110D08(func_800A4CA8(arg0), (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))), arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A3F14.s")

/* extern */

void func_800A4030(void *arg0) {
    s32 func_800A4074(u8 *, s32);
    if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (6))) == 9) {
        func_800A4074(arg0, 9);
        return;
    }
    func_800A4074(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4074.s")

void func_800A4160(s32 arg0) 
{
}
/* extern */

void func_800A4168(u8 *arg0) {
    s32 func_800A4074(u8 *, s32);
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))) = 0;
    func_800A4074(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4A14.s")

void func_800A4A4C(s32 arg0)
{
    func_800A4190();
    func_800A4878(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4AD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4B08.s")

/* extern */

f32 *func_800A4C48(PlayerState *arg0) {
    f32 *func_800A93F8(s32);
    return func_800A93F8(arg0->unk184);
}

/* extern */

void func_800A4C68(void *arg0) {
    s32 func_800A940C(s32);
    func_800A940C((*(s32 *)((s8 *)(arg0) + (0x184))));
}

/* extern */

void func_800A4C88(void *arg0) {
    s32 func_800A93E4(s32);
    func_800A93E4((*(s32 *)((s8 *)(arg0) + (0x184))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4CA8.s")

/* extern */

void func_800A4CE8(PlayerState *arg0, s32 arg1) {
    s32 func_800CA7E4(f32 *, s32);
    func_800CA7E4(func_800A4C48(arg0), arg1);
}

/* extern */

void func_800A4D14(PlayerState *arg0, s32 arg1) {
    s32 func_800CA9D8(f32 *, s32);
    func_800CA9D8(func_800A4C48(arg0), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4D40.s")

/* extern */

void func_800A4D6C(u8 *arg0, f32 arg1, f32 arg2) {
    s32 func_800A3BA8(s32, s32);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x2C))) = arg1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x30))) = arg2;
    func_800A3BA8((s32)arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4DA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4E30.s")

void func_800A4E74(s32 arg0)
{
    func_800A3F14(arg0,0x5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4E94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4EC8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4EFC.s")

/* extern */

void func_800A5004(void *arg0) {
    s32 func_800A4E94(void *);
    s32 func_800CA334();
    if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3C))) == 0) {
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3C))) = func_800CA334();
        func_800A4E94(arg0);
    }
}

/* extern */

void func_800A5044(u8 *arg0) {
    s32 func_800A4EC8(void *);
    s32 func_800CA364(s32);
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))) != 0) {
        func_800A4EC8(arg0);
        func_800CA364((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))));
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))) = 0;
    }
}

s32 func_800A5090(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 56) + 60);
}

void func_800A509C(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3B))) = 1;
}
