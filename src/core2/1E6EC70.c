#include "core2/1E6EC70.h"

s32 func_80095380(void)
{
	return 0x18;
}

u8 func_80095388(s32 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    s32 threshold = arg3 + 0x3E8;
    s16 *entry = (s16 *)(arg2 + 0xC);
    s16 index;
    if (*entry >= 0) {
      do {
        index = *entry;
        if (index + threshold < arg1) {
            *arg0 = ((u8 *)entry)[2];
            return ((u8 *)entry)[3];
        }
        entry += 2;
        index = *entry;
      } while (index >= 0);
    }
    return 0;
}

s32 func_800953E0(PlayerState *arg0, void *arg1, s32 arg2) {
    enum transform_e {
        TRANSFORM_13_TREXLARGE = 0x13,
        TRANSFORM_12_TREXSMALL = 0x12,
        TRANSFORM_11_CLOCKWORK = 0x11,
        TRANSFORM_10_VAN = 0x10,
        TRANSFORM_F_DETONATOR = 0xF,
        TRANSFORM_E_GOLDENGOLIATH = 0xE,
        TRANSFORM_D_MUMBO = 0xD,
        TRANSFORM_C_SUB = 0xC,
        TRANSFORM_B_KAZOOIE = 0xB,
        TRANSFORM_A_BANJO = 0xA,
        TRANSFORM_9_FIRSTPERSON = 0x9,
        TRANSFORM_8_STONY = 0x8,
        TRANSFORM_7_WASHINGMACHINE = 0x7,
        TRANSFORM_6_BEE = 0x6,
        TRANSFORM_2_SNOWBALL = 0x2,
        TRANSFORM_1_BK = 0x1
    } func_800A3274(PlayerState *);
    s32 func_8009E71C(PlayerState *, s32);
    extern u8 D_80117E60[];

    *(s32 *)arg1 = 0;
    if (arg2 < 0) {
        return 0;
    }
    switch (func_800A3274(arg0)) {
        case TRANSFORM_A_BANJO:
            if (func_8009E71C(arg0, 0x13)) {
                return func_80095388(arg1, arg2, D_80117E60, 1000);
            }
            break;
        case TRANSFORM_2_SNOWBALL:
        case TRANSFORM_6_BEE:
        case TRANSFORM_7_WASHINGMACHINE:
        case TRANSFORM_8_STONY:
        case TRANSFORM_B_KAZOOIE:
        case TRANSFORM_C_SUB:
        case TRANSFORM_D_MUMBO:
        case TRANSFORM_E_GOLDENGOLIATH:
        case TRANSFORM_F_DETONATOR:
        case TRANSFORM_10_VAN:
        case TRANSFORM_11_CLOCKWORK:
        case TRANSFORM_12_TREXSMALL:
        case TRANSFORM_13_TREXLARGE:
            break;
    }
    return func_80095388(arg1, arg2, D_80117E60, 0);
}

void func_8009C128(PlayerState *, f32[3]);

void func_80095490(volatile PlayerState *arg0) {
    s32 func_800953E0(PlayerState *, void *, s32);
    f32 sp1C[3];
    func_8009C128(arg0, sp1C);
    *(s32 *) ((s8 *) *(void **)((s8 *) arg0 + 0x7C) + 0x14) = func_800953E0(arg0, (s8 *) *(void **)((s8 *) arg0 + 0x7C) + 0x10, (s32) (*(f32 *) ((s8 *) *(void **)((s8 *) arg0 + 0x7C) + 4) - sp1C[1]));
}

/* extern */

s32 func_800954E8(void *arg0, s32 *arg1) {
    s32 func_800D3E40(s32);
    if (func_800D3E40(3) != 0) {
        *arg1 = 0;
    } else {
        *arg1 = (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x7C)))) + (0x10)));
    }
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x7C)))) + (0x14)));
}

f32 func_80095534(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 position[3];
    s32 result;
    func_8009C128(arg0, position);
    result = (s32) ((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + 0x7C))) + 4)) - position[1]);
    return (f32) result;
}

s32 func_8009557C(PlayerState *arg0) {
    return ((u8 *) *(void **)((u8 *)arg0 + 0x7C))[0xC];
}

void func_80095588(PlayerState *arg0, s32 arg1) {
    u8 temp_v0;

    (*(u8 **)((s8 *)(arg0) + 0x7C))[0xC] = arg1;
    temp_v0 = (*(u8 **)((s8 *)(arg0) + 0x7C))[0xC];
    if ((temp_v0 == 2) || (temp_v0 == 3)) {
        func_800956B8(arg0);
    }
}    typedef struct { u8 pad0[0x10]; s32 unk10; s32 unk14; } Obj1E6EC70_func_800955CC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800955CC(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 *temp_v0;

    func_8009C128(arg0, (*(f32 **)((s8 *)(arg0) + (0x7C))));
    (*(s8 *)((s8 *)((*(f32 **)((s8 *)(arg0) + (0x7C)))) + (0xC))) = 0;
    func_80095588(arg0, 1);
    (*(s32 *)((s8 *)((*(f32 **)((s8 *)(arg0) + (0x7C)))) + (0x10))) = 0;
    temp_v0 = (*(f32 **)((s8 *)(arg0) + (0x7C)));
    (((Obj1E6EC70_func_800955CC_temp_v0 *)temp_v0)->unk14) = (s32) (((Obj1E6EC70_func_800955CC_temp_v0 *)temp_v0)->unk10);
}

/* extern */

void func_8009561C(PlayerState *arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s32 func_800F3ED0(void *);
    s32 func_800F40EC(PlayerState *);
    int player_isStable(PlayerState *);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = func_800F3ED0(arg0);
    sp28 = player_isStable(arg0);
    sp24 = bs_getCurrentState(arg0);
    if ((sp28 != 0) || (func_800F40EC(arg0) != 0) || (sp24 == 0xBE) || (sp24 == 0x15C) || (sp2C == 0xA)) {
        func_800956B8(arg0);
        func_80095588(arg0, 1);
    }
    func_80095490(arg0);
}

void func_800956B8(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    func_8009C128(arg0, (*(f32 **)((s8 *)(arg0) + (0x7C))));
}
