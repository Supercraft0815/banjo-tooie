#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_0.s")

int func_80800074_suspline(u8 *array, s32 index) {
    return ((array + 0x7E)[index / 8] & (1 << (index & 7))) ? 1 : 0;
}

int func_808000B4_suspline(u8 *array, s32 index) {
    return ((array + 0x87)[index / 8] & (1 << (index & 7))) ? 1 : 0;
}

s32 suspline_entrypoint_1(void *arg0) {
    return *(f32 *)((s8 *)arg0 + 0x58) >= 0.99f;
}

s32 suspline_entrypoint_2(void *arg0, f32 arg1) {
    if (((*(f32 *)((s8 *)(arg0) + (0x5C))) <= arg1) && (arg1 < (*(f32 *)((s8 *)(arg0) + (0x58))))) {
        return 1;
    }
    return 0;
}

void suspline_entrypoint_3(f32 arg0[][3], s32 arg1, f32 *arg2) {
    s32 func_800EE7F8();
    func_800EE7F8(arg2, arg0[arg1]);
}

f32 suspline_entrypoint_4(s32 arg0, s32 arg1) {
    return ((f32 *)arg0)[arg1 + 12];
}

/* extern */

void suspline_entrypoint_5(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x3C);
}

f32 suspline_entrypoint_6(f32 *arg0) {
    return arg0[22];
}

u32 suspline_entrypoint_7(u8 *arg0) {
    return arg0[139];
}

void suspline_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 88) = arg1;
}

void suspline_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 92) = arg1;
}

s32 suspline_entrypoint_10(s32 arg0, s32 arg1) {
    return ((s16 *)arg0)[arg1 + 0x34] + arg0;
}

s32 suspline_entrypoint_11(s32 arg0, s32 arg1) {
    return arg0 + *(s16 *)((s8 *)arg0 + (arg1 * 2) + 0x70);
}

void suspline_entrypoint_12(void *arg0, s8 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x8A))) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/func_80800224_suspline.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_13.s")

void suspline_entrypoint_14(u8 *arg0) {
    struct SplineOffsets {
        u8 pad[0x68];
        s16 offsets[8];
    };
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, s32 *);
    extern s32 _mlspline_entrypoint_6;
    extern s32 _mlspline_entrypoint_7;
    extern s32 _mlspline_entrypoint_8;
    f32 temp_f0;
    f32 var_f0;
    s16 temp_a0;
    u8 *temp_a1;

    if (((temp_f0 = *(f32 *)(arg0 + 0x58)) < 0.9999f) && !((*(u8 *)((s8 *)(arg0) + (0x8A))) & 1)) {
        temp_a1 = ((struct SplineOffsets *)arg0)->offsets[*(s16 *)(arg0 + 0x7A)] + arg0;
        temp_a0 = (*(s16 *)((s8 *)(arg0) + (0x78)));
        if (temp_a0 >= 4) {
            var_f0 = _mlspline_entrypoint_13(temp_a0, temp_a1, temp_f0, (*(f32 *)((s8 *)(arg0) + (0x54))) * (*(f32 *)((s8 *)(arg0) + (0x64))), 1.0f, &_mlspline_entrypoint_8);
        } else if (temp_a0 >= 3) {
            var_f0 = _mlspline_entrypoint_13(temp_a0, temp_a1, temp_f0, (*(f32 *)((s8 *)(arg0) + (0x54))) * (*(f32 *)((s8 *)(arg0) + (0x64))), 1.0f, &_mlspline_entrypoint_7);
        } else {
            var_f0 = _mlspline_entrypoint_13(temp_a0, temp_a1, temp_f0, (*(f32 *)((s8 *)(arg0) + (0x54))) * (*(f32 *)((s8 *)(arg0) + (0x64))), 1.0f, &_mlspline_entrypoint_6);
        }
        (*(f32 *)((s8 *)(arg0) + (0x58))) = var_f0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_16.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_17.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/func_80800C8C_suspline.s")

s32 suspline_entrypoint_18(s32 arg0, s32 arg1, s32 arg2) {
    return (s32)((u32)arg0 * (u32)((arg1 * 0xC) + (arg2 * 4))) + 0x8C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/spline/suspline_entrypoint_19.s")

/* extern */

void suspline_entrypoint_20(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_80100074(s32, s32, s32);
    s32 func_80100094(s32, s32);
    s32 suspline_entrypoint_18(s32, s32, s32);
    s32 suspline_entrypoint_19(s32, s32, s32, s32, s32, s32);
    func_80100074(arg0, 1, suspline_entrypoint_18(arg1, arg2, arg3));
    suspline_entrypoint_19(func_80100094(arg0, 1), arg1, arg2, arg3, arg4, arg5);
}
