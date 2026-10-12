#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/func_80800000_fxrain.s")

void func_808001E8_fxrain(s32 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

/* extern */

void fxrain_entrypoint_0(void *arg0) {
    s32 vector_clear(s32);
    vector_clear((*(s32 *)((s8 *)(arg0) + (0x20))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_1.s")

int fxrain_entrypoint_2(void *arg0) {
    s32 vector_size(s32);
    return ((*(s32 *)((s8 *)(arg0) + (0x28))) != 1) && (vector_size((*(s32 *)((s8 *)(arg0) + (0x20)))) == 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_3.s")

/* extern */

void fxrain_entrypoint_4(u8 *arg0) {
    s32 func_800C2FDC(s32, u8 *, u8);
    s32 heap_free(u8 *);
    s32 vector_free(s32, u8 *);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0)));
    if (temp_a2 != 0) {
        func_800C2FDC(temp_a2 & 0xFF, arg0, temp_a2);
        (*(u8 *)((s8 *)(arg0) + (0))) = 0;
    }
    vector_free((*(s32 *)((s8 *)(arg0) + (0x20))), arg0);
    heap_free(arg0);
}

/* extern */

u8 *fxrain_entrypoint_5(s32 arg0) {
    s32 func_800EFD24(u8 *);
    u8 *heap_alloc(s32);
    s32 vector_new(s32, s32);
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x4C);
    func_800EFD24(temp_v0 + 4);
    func_800EFD24(temp_v0 + 0x10);
    (*(s8 *)((s8 *)(temp_v0) + (0))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x1C))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x30))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x20))) = vector_new(0x1C, arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x24))) = arg0;
    (*(s32 *)((s8 *)(temp_v0) + (0x28))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (0x2C))) = 0.1f;
    return temp_v0;
}

void fxrain_entrypoint_6(void *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    typedef struct {
        u8 pad0[0x30];
        u8 enabled;
        f32 elapsed;
        f32 rate;
        f32 values[4];
    } RainFade;
    RainFade *this = arg0;
    this->enabled = 1;
    this->elapsed = 0.0f;
    this->rate = 0.1f;
    this->values[0] = arg1;
    this->values[1] = arg2;
    this->values[2] = arg3;
    this->values[3] = arg4;
}

void fxrain_entrypoint_7(s32 arg0)
{
    func_808001E8_fxrain(arg0,1);
}

/* extern */

void fxrain_entrypoint_8(u8 *arg0) {
    s32 func_800C3A40(u8, f32, f32, f32);
    u8 temp_a0;

    func_808001E8_fxrain(arg0, 2);
    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        func_800C3A40(temp_a0, 0.0f, 0.0f, 3.0f);
        *arg0 = 0U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/fx/rain/fxrain_entrypoint_9.s")
