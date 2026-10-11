#include "common.h"

void func_800EC890(s32 arg0) 
{
}
void func_800EC898(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    typedef struct { s16 map; s16 id; s16 scale; s16 offset; } Entry;
    void _glidmake_entrypoint_2(s32, s32, u8 *, u8 *);
    s32 func_800EA05C();
    extern Entry D_80123580[];
    Entry *var_t0;
    s16 temp_v0_2;
    s16 var_v1;
    s32 temp_lo;
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    for (var_t0 = D_80123580; var_t0->map != 0; var_t0++) {
        if (temp_v0 == var_t0->map && arg3 == var_t0->id) {
            break;
        }
    }
    (*(f32 *)((s8 *)(arg0) + (0x14))) = (f32) (2048.0f / (f32) (*(s16 *)((s8 *)(var_t0) + (4))));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) ((*(s16 *)((s8 *)(var_t0) + (6))) << 6);
    _glidmake_entrypoint_2(arg2, arg3, arg0, arg0 + 6);
    temp_v0 = arg1 / 10;
    if (temp_v0 & 1) {
        (*(s8 *)((s8 *)(arg0) + (0x1A))) = 0;
    } else {
        (*(s8 *)((s8 *)(arg0) + (0x1A))) = 1;
    }
    if (temp_v0 & 2) {
        (*(s8 *)((s8 *)(arg0) + (0x1B))) = 0;
    } else {
        (*(s8 *)((s8 *)(arg0) + (0x1B))) = 1;
    }
    if (temp_v0 & 4) {
        (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
    } else {
        (*(s8 *)((s8 *)(arg0) + (0x1C))) = 1;
    }
    temp_v0_2 = (*(s16 *)((s8 *)(arg0) + (0x18)));
    if (temp_v0_2 == 0) {
        (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) (50.0f / (f32) temp_v0_2);
}

void func_800EC9E0(s32 arg0, s32 arg1, s32 arg2) {
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EC9F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ECD60.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ECEEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED0D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED144.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED79C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED7F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED964.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800ED9B4.s")

s32 func_800EDA24(s16 *arg0) {
    return arg0[38];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDA2C.s")

/* extern */

void func_800EDAF4(u8 *arg0) {
    s32 func_800C2FDC(s32, u8);
    u8 temp_a1;

    temp_a1 = *arg0;
    if (temp_a1 != 0) {
        func_800C2FDC(temp_a1 & 0xFF, temp_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDB20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDBA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDC10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDC64.s")

void func_800EDCB8(void *arg0, f32 arg1) {
    void func_800EDC10(void *, f32, f32, f32, s32);
    func_800EDC10(arg0, arg1, arg1, 0.0f, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDCEC.s")

/* extern */

void func_800EDD20(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    void func_800EDC10(void *, f32, f32, f32, s32);
    s32 func_800EE010();
    func_800EE010();
    func_800EDC10(arg0, arg1, arg2, arg3, arg4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDD68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDDDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDE54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDF2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EDF98.s")

void func_800EDFBC(void *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4)
{
  s32 func_800ED964(f32, f32);
  *((s8 *) (((s8 *) arg0) + 0x29)) = 4;
  *((f32 *) (((s8 *) arg0) + 4)) = arg1;
  *((f32 *) (((s8 *) arg0) + 0x48)) = arg3;
  *((f32 *) (((s8 *) arg0) + 0x44)) = 0.0f;
  *((f32 *) (((s8 *) arg0) + 8)) = arg2;
  *((s16 *) (((s8 *) arg0) + 0x4C)) = 0;
  *((s16 *) (((s8 *) arg0) + 0x4E)) = (s16) arg4;
  func_800ED964(arg1, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EE010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EE040.s")

void func_800EE0F0(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}

void func_800EE0F8(s32 *arg0, s32 arg1) {
    arg0[4] = arg1;
}

void func_800EE100(s16 *arg0, s32 arg1) {
    arg0[38] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC6180/func_800EE108.s")
