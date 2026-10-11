#include "common.h"

extern s32 D_8012AAC4;

f32 func_800C6920(s32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    s32 func_800C696C(s32, f32, f32, s32, f32 *);
    f32 result;
    if (func_800C696C(arg0, arg1, arg2, arg3, &result) == 0) {
        result = 100.0f;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA0210/func_800C696C.s")

s32 func_800C69FC()
{
    return D_8012AAC4;
}

void func_800C6A08(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C6A28(s32, s32, s32, s32);
    func_800C6A28(arg0, arg1, arg2, 0);
}

void func_800C6A28(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern s32 D_8012AA40;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (0))) = arg0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (4))) = arg1;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (8))) = arg2;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(&D_8012AA40) + (0x80)))) + (0xC))) = arg3;
    (*(u8 **)((s8 *)(&D_8012AA40) + (0x80))) = (u8 *) ((*(u8 **)((s8 *)(&D_8012AA40) + (0x80))) + 0x10);
}

void func_800C6A60(void) {
}

void func_800C6A68(void) {
    extern s32 D_8012AA40;
    (*(s32 **)((s8 *)(&D_8012AA40) + (0x80))) = &D_8012AA40;
    (*(s32 *)((s8 *)(&D_8012AA40) + (0x84))) = 0;
}

extern s32 D_8012AA40;
typedef void * (*Method_1EA0210_0)(f32[3], f32[3], f32[3], u32);
typedef void * (*Method_1EA0210_1)(f32[3], f32[3], f32, f32[3], s32, u32);
typedef void * (*Method_1EA0210_2)(f32[3], f32, f32[3], u32);
typedef void * (*Method_1EA0210_3)(void);

typedef struct {
    Method_1EA0210_0 unk0;
    Method_1EA0210_1 unk4;
    Method_1EA0210_2 unk8;
    Method_1EA0210_3 unkC;
} Struct_1EA0210_0;

typedef struct {
    Struct_1EA0210_0 unk0[0x8];
    Struct_1EA0210_0 *unk80;
    void *unk84;
} Struct_1EA0210_1;

#define D_8012AA40_TABLE (*(Struct_1EA0210_1 *)&D_8012AA40)

void *func_800C6A7C(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 flags) {
    Struct_1EA0210_0 *var_s0;
    void *temp_v0_2;
    void *var_s7;

    var_s7 = NULL;
    D_8012AA40_TABLE.unk84 = NULL;
    for(var_s0 = &D_8012AA40_TABLE.unk0[0]; var_s0 < D_8012AA40_TABLE.unk80; var_s0++){
        if (var_s0->unk0 != NULL) {
            temp_v0_2 = var_s0->unk0(arg0, arg1, arg2, flags);
            if (temp_v0_2 != NULL) {
                if (var_s0->unkC != NULL) {
                    D_8012AA40_TABLE.unk84 = var_s0->unkC();
                } else {
                    D_8012AA40_TABLE.unk84 = NULL;
                }
            }
            var_s7 = (temp_v0_2 != NULL) ? temp_v0_2 : var_s7;
        }
    }
    return var_s7;
}

void *func_800C6B78(f32 arg0[3], f32 arg1[3], f32 arg2, f32 arg3[3], s32 arg4, u32 arg5) {
    Struct_1EA0210_0 *var_s0;
    void *temp_v0_2;
    void *var_s7;

    var_s7 = NULL;
    D_8012AA40_TABLE.unk84 = NULL;
    for(var_s0 = &D_8012AA40_TABLE.unk0[0]; var_s0 < D_8012AA40_TABLE.unk80; var_s0++){
        if (var_s0->unk4 != NULL) {
            temp_v0_2 = var_s0->unk4(arg0, arg1, arg2, arg3, arg4, arg5);
            if (temp_v0_2 != 0) {
                if (var_s0->unkC != NULL) {
                    D_8012AA40_TABLE.unk84 = var_s0->unkC();
                } else {
                    D_8012AA40_TABLE.unk84 = 0;
                }
            }
            var_s7 = (temp_v0_2 != 0) ? temp_v0_2 : var_s7;
        }
    }
    return var_s7;
}

void *func_800C6C94(f32 arg0[3], f32 arg1, f32 arg2[3], u32 arg3) {
    Struct_1EA0210_0 *var_s0;
    void *temp_v0_2;
    void *var_s7;

    var_s7 = NULL;
    D_8012AA40_TABLE.unk84 = NULL;
    for(var_s0 = &D_8012AA40_TABLE.unk0[0]; var_s0 < D_8012AA40_TABLE.unk80; var_s0++){
        if (var_s0->unk8 != NULL) {
            temp_v0_2 = var_s0->unk8(arg0, arg1, arg2, arg3);
            if (temp_v0_2 != NULL) {
                if (var_s0->unkC != NULL) {
                    D_8012AA40_TABLE.unk84 = var_s0->unkC();
                } else {
                    D_8012AA40_TABLE.unk84 = NULL;
                }
            }
            var_s7 = (temp_v0_2 != NULL) ? temp_v0_2 : var_s7;
        }
    }
    return var_s7;
}
