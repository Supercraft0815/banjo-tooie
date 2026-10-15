#include "core2/1E76CC0.h"

s32 func_8009D3D0() 
{
    return 0x20;
}

void func_8009D3D8(s32 arg0)
{
    func_8009E674(arg0,0x2);
}

/* extern */

void func_8009D3F8(s32 arg0, s32 arg1) {
    s32 func_800C2FDC(u8);
    PlayerState *func_800F53D0(s32);
    PlayerState *sp1C;
    PlayerState *temp_v0;

    temp_v0 = func_800F53D0(arg1);
    sp1C = temp_v0;
    func_8009DB04(temp_v0, 0x411, (*(f32 *)((s8 *)((*(void **)((s8 *)(temp_v0) + (0x104)))) + (0x14))), 0x55F0);
    func_800C2FDC((*(u8 *)((s8 *)((*(void **)((s8 *)(sp1C) + (0x104)))) + (1))));
    (*(s8 *)((s8 *)((*(void **)((s8 *)(sp1C) + (0x104)))) + (1))) = 0;
}

s32 func_8009D454(PlayerState *arg0, volatile u8 arg1, s32 *arg2) {
    void func_8009C128(PlayerState *, f32[3]);
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_80119210;
    f32 sp1C[3];
    s32 var_a0;

    func_8009C128(arg0, sp1C);
    var_a0 = arg1;
    if (var_a0 == 0) {
        var_a0 = func_800C4350(var_a0, sp1C, &D_80119210) & 0xFF;
    }
    return func_800C4350(var_a0, sp1C, arg2);
}

void func_8009D4A8(PlayerState *arg0, u8 *arg1) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800C4AF0(f32 *, void*);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_800C4AF0(sp1C, arg1);
}

/* extern */

void func_8009D4D8(void *arg0) {
    u8 func_800C2E04();
    s32 func_800C330C(u8, s32);
    s32 func_800C3418(u8, s32);
    s32 func_800C431C(u8, s32);
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0x18))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0x1C))) = 1;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (8))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0xC))) = 0;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0x10))) = 0;
    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0))) = func_800C2E04();
    func_800C330C((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0))), 3);
    func_800C3418((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0))), 0);
    func_800C431C((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0))), 0);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (0x14))) = 1.0f;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (1))) = 0;
    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))) = func_800C2E04();
    func_800C3418((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), 0);
    func_800C431C((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), 0);
    (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))) = func_800C2E04();
    func_800C3418((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), 0);
    func_800C431C((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), 0);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (4))) = 0;
}

void func_8009D5E0(PlayerState *arg0) {
    s32 func_800C2FDC(u8);
    u8 *var_v0;
    u8 temp_a1;
    u8 temp_a0;

    var_v0 = *(u8 **)((s8 *)arg0 + 0x104);
    temp_a1 = var_v0[1];
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1);
        var_v0 = *(u8 **)((s8 *)arg0 + 0x104);
    }
    func_800C2FDC(var_v0[0]);
    func_800C2FDC((*(u8 **)((s8 *)arg0 + 0x104))[3]);
    func_800C2FDC((*(u8 **)((s8 *)arg0 + 0x104))[2]);
    temp_a0 = (*(u8 **)((s8 *)arg0 + 0x104))[4];
    if (temp_a0 != 0) {
        func_800C2FDC(temp_a0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D658.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D7A4.s")

void func_8009D820(PlayerState *arg0, f32 arg1) {
    f32 func_800DC0C0(void);
    s32 var_a1;
    if (func_800DC0C0() < 0.5f) {
        var_a1 = 0x585;
    } else {
        var_a1 = 0x586;
    }
    func_8009DE38(arg0, var_a1, arg1);
}

void func_8009D874(PlayerState *arg0) {
    func_8009DE38(arg0, 0x442E, 1.117f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009D89C.s")

/* extern */

void func_8009D940(PlayerState *arg0, s32 arg1, f32 arg2, s32 arg3) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DAAC(s32 *, f32 *);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    f32 sp24[3];

    func_8009DAAC(&arg1, &arg2);
    func_8009C128(arg0, sp24);
    func_800C35E8(*(*(u8 **)((s8 *)(arg0) + (0x104))), sp24);
    func_800C301C(*(*(u8 **)((s8 *)(arg0) + (0x104))), arg1);
    func_800C31DC(*(*(u8 **)((s8 *)(arg0) + (0x104))), arg2);
    func_800C3058(*(*(u8 **)((s8 *)(arg0) + (0x104))), arg3);
    func_800C3BDC(*(*(u8 **)((s8 *)(arg0) + (0x104))));
}

void func_8009D9D4(PlayerState *arg0) {
    s32 _badata_entrypoint_17(PlayerState *, s32, s32 *, f32 *, s32 *);
    void func_8009D940(PlayerState *, s32, f32, s32);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    if (_badata_entrypoint_17(arg0, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x104)))) + (0xC))), &sp28, (f32 *)&sp2C, &sp24) == 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x104)))) + (0xC))) = 0;
    } else {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x104)))) + (0xC))) += 1;
    }
    func_8009D940(arg0, sp28, *(f32 *)&sp2C, sp24);
}

void func_8009DA40(PlayerState *arg0) {
    s32 _badata_entrypoint_19(PlayerState *, s32, s32 *, f32 *, s32 *);
    void func_8009D940(PlayerState *, s32, f32, s32);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    if (_badata_entrypoint_19(arg0, (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x104)))) + (0xC))), &sp28, (f32 *)&sp2C, &sp24) == 0) {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x104)))) + (0xC))) = 0;
    } else {
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x104)))) + (0xC))) += 1;
    }
    func_8009D940(arg0, sp28, *(f32 *)&sp2C, sp24);
}

void func_8009DAAC(s32 *arg0, f32 *arg1) {
    s32 func_8009EA2C(void);
    extern f32 D_8012538C;
    s32 flags = *arg0 & ~0xFFF;

    *arg0 &= 0xFFF;
    if (flags == 0x4000 && func_8009EA2C() != 0) {
        *arg1 -= D_8012538C;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DB04.s")

void func_8009DBB0(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 func_800DC178(f32, f32);
    func_8009DB04(arg0, arg1, func_800DC178(arg2, arg3), arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DBF0.s")

void func_8009DC98(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3) {
    func_8009DBB0(arg0, arg1, arg2, arg3, 0x55F0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76CC0/func_8009DCCC.s")

u32 func_8009DDD0(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 260) + 2);
}

/* extern */

void func_8009DDDC(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800C35E8(u8, f32[3]);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_800C35E8(*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x104) + 3), sp1C);
}

/* extern */

void func_8009DE14(void *arg0) {
    s32 func_800C3D78(u8);
    func_800C3D78((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))));
}

/* extern */

void func_8009DE38(PlayerState *arg0, s32 arg1, f32 arg2) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), arg1, arg2, 0x55F0);
}

/* extern */
void func_8009DE74(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    f32 func_800DC178(f32, f32);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), arg1, func_800DC178(arg2, arg3), 0x55F0);
}

/* extern */

void func_8009DEC0(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 sp20[2];

    sp20[0] = func_800DC178(arg2, arg3);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), arg1, sp20[0], func_800DC128(arg4, arg5));
}

/* extern */

void func_8009DF18(PlayerState *arg0, s32 arg1, f32 arg2, s32 arg3) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (2))), arg1, arg2, arg3);
}

/* extern */

void func_8009DF58(PlayerState *arg0, s32 arg1, f32 arg2) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), arg1, arg2, 0x55F0);
}

/* extern */

void func_8009DF94(PlayerState *arg0, s32 arg1, f32 arg2, s32 arg3) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), arg1, arg2, arg3);
}

/* extern */

void func_8009DFD4(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5) {
    s32 func_8009DCCC(PlayerState *, u8, s32, f32, s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 sp20[2];

    sp20[0] = func_800DC178(arg2, arg3);
    func_8009DCCC(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x104)))) + (3))), arg1, sp20[0], func_800DC128(arg4, arg5));
}

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
