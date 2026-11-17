#include "common.h"

typedef struct { f32 unk0; f32 unk4; f32 unk8; f32 unkC; f32 unk10; f32 unk14; f32 unk18; } Objwave_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void mlwave_entrypoint_0(void *arg0, f32 arg1, f32 arg2) {
    (((Objwave_arg0 *)arg0)->unkC) = arg2;
    (((Objwave_arg0 *)arg0)->unk10) = arg2;
    (((Objwave_arg0 *)arg0)->unk8) = arg1;
    (((Objwave_arg0 *)arg0)->unk0) = 0;
    (((Objwave_arg0 *)arg0)->unk14) = 100.0f;
    if (arg1 != 0.0f) {
        (((Objwave_arg0 *)arg0)->unk4) = (f32) (6.2831855f / arg1);
    } else {
        (((Objwave_arg0 *)arg0)->unk4) = 0;
    }
    (((Objwave_arg0 *)arg0)->unk18) = 0;
}

/* extern */

void mlwave_entrypoint_1(void *arg0) {
    f32 func_800D8FF8();
    f32 func_800F15F8(f32, f32, f32);
    f32 mlwave_entrypoint_6(void *);
    f32 sp24;
    f32 temp_f0;

    sp24 = func_800D8FF8();
    (((Objwave_arg0 *)arg0)->unk18) = mlwave_entrypoint_6(arg0);
    temp_f0 = func_800F15F8((((Objwave_arg0 *)arg0)->unkC), (((Objwave_arg0 *)arg0)->unk10), (((Objwave_arg0 *)arg0)->unk14) * sp24);
    (((Objwave_arg0 *)arg0)->unkC) = temp_f0;
    (((Objwave_arg0 *)arg0)->unk0) = (f32) ((((Objwave_arg0 *)arg0)->unk0) + (temp_f0 * sp24));
}

/* extern */

void mlwave_entrypoint_2(void *arg0, f32 arg1, f32 arg2) {
    f32 func_800DC178(f32, f32);
    f32 mlwave_entrypoint_6(void *);
    f32 temp_f0;
    temp_f0 = func_800DC178(arg1, arg2);
    (((Objwave_arg0 *)arg0)->unk0) = (f32) ((((Objwave_arg0 *)arg0)->unk8) * temp_f0);
    (((Objwave_arg0 *)arg0)->unk18) = mlwave_entrypoint_6(arg0);
}

void mlwave_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (((Objwave_arg0 *)arg0)->unk10) = arg1;
    (((Objwave_arg0 *)arg0)->unk14) = arg2;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) mlwave_entrypoint_4(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_8001395C(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    BT_NATIVE_ONLY(return) func_800F10B4(func_8001395C((arg1 - *(f32 *)arg0) * *(f32 *)((s8 *)arg0 + 4)), -1.0f, 1.0f, arg2, arg3);
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) mlwave_entrypoint_5(void *arg0, f32 arg1, f32 arg2) { BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) mlwave_entrypoint_4(void *, f32, f32, f32); BT_NATIVE_ONLY(return) mlwave_entrypoint_4(arg0, 0.0f, arg1, arg2); }

f32 mlwave_entrypoint_6(void *arg0) {
    f32 func_800F13C4(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 value;

    value = func_800F13C4(*(f32 *)arg0, ((Objwave_arg0 *)arg0)->unk8);
    return func_800F10B4(value, 0, *(f32 *)arg0 < 0.0f ? -((Objwave_arg0 *)arg0)->unk8 : ((Objwave_arg0 *)arg0)->unk8, 0, 1.0f);
}

void mlwave_entrypoint_7(void *arg0, f32 arg1) {
    (((Objwave_arg0 *)arg0)->unk18) = arg1;
    (((Objwave_arg0 *)arg0)->unk0) = (f32) ((((Objwave_arg0 *)arg0)->unk8) * arg1);
}

s32 mlwave_entrypoint_8(BtIntPtr arg0, f32 arg1) {
    f32 current;
    f32 previous;

    previous = *(f32 *)(arg0 + 0x18);
    current = mlwave_entrypoint_6((void *)arg0);
    if (*(f32 *)(arg0 + 0xC) > 0.0f) {
        return previous < current ?
            (previous <= arg1 && arg1 < current) :
            (previous <= arg1 || arg1 < current);
    } else {
        return current < previous ?
            (arg1 <= previous && current < arg1) :
            (arg1 <= previous || current < arg1);
    }
}

/* extern */

s32 mlwave_entrypoint_9(s32 arg0, f32 *arg1) { s32 mlwave_entrypoint_8(BtIntPtr, f32); f32 *var_s0 = arg1; f32 var_f0 = *arg1; f32 sentinel = -1.0f; goto check; loop: if (mlwave_entrypoint_8(arg0, var_f0) != 0) { return 1; } var_f0 = var_s0[1]; var_s0++; check: if (sentinel != var_f0) { goto loop; } return 0; }
