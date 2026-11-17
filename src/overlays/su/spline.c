#include "common.h"

void suspline_entrypoint_0(u8 *array, s32 index, s32 value) {
    u8 *ptr;
    if (value) {
        ptr = array + 0x7E;
        *(ptr += index / 8) |= (1 << (index & 7));
    } else {
        ptr = array + 0x7E;
        *(ptr += index / 8) &= ~(1 << (index & 7));
    }
}

int func_80800074_suspline(u8 *array, s32 index) {
    return ((array + 0x7E)[index / 8] & (1 << (index & 7))) ? 1 : 0;
}

int func_808000B4_suspline(u8 *array, s32 index) {
    return ((array + 0x87)[index / 8] & (1 << (index & 7))) ? 1 : 0;
}    typedef struct { u8 pad0[0x54]; f32 unk54; f32 unk58; f32 unk5C; u8 pad60[0x4]; f32 unk64; u8 pad68[0x10]; s16 unk78; u8 pad7A[0xE]; u8 unk88; u8 unk89; u8 unk8A; s8 unk8B; } Objspline_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 suspline_entrypoint_1(void *arg0) {
    return *&((Objspline_arg0 *)arg0)->unk58 >= 0.99f;
}

s32 suspline_entrypoint_2(void *arg0, f32 arg1) {
    if (((((Objspline_arg0 *)arg0)->unk5C) <= arg1) && (arg1 < (((Objspline_arg0 *)arg0)->unk58))) {
        return 1;
    }
    return 0;
}

void suspline_entrypoint_3(f32 arg0[][3], s32 arg1, f32 *arg2) {
    s32 func_800EE7F8();
    func_800EE7F8(arg2, arg0[arg1]);
}

f32 suspline_entrypoint_4(BtIntPtr arg0, s32 arg1) {
    return ((f32 *)arg0)[arg1 + 12];
}

/* extern */

void suspline_entrypoint_5(BtIntPtr arg0 BT_PASS2(, s32 arg1)) {
    s32 func_800EE7F8(s32 BT_PASS2(, s32));
    func_800EE7F8(arg0 + 0x3C BT_PASS2(, arg1));
}

f32 suspline_entrypoint_6(f32 *arg0) {
    return arg0[22];
}

u32 suspline_entrypoint_7(u8 *arg0) {
    return arg0[139];
}

void suspline_entrypoint_8(void *arg0, f32 arg1) {
    ((Objspline_arg0 *)arg0)->unk58 = arg1;
}

void suspline_entrypoint_9(void *arg0, f32 arg1) {
    ((Objspline_arg0 *)arg0)->unk5C = arg1;
}

BtIntPtr suspline_entrypoint_10(BtIntPtr arg0, s32 arg1) {
    return ((s16 *)arg0)[arg1 + 0x34] + arg0;
}

BtIntPtr suspline_entrypoint_11(BtIntPtr arg0, s32 arg1) {
    return arg0 + *(s16 *)((s8 *)arg0 + (arg1 * 2) + 0x70);
}

void suspline_entrypoint_12(void *arg0, s8 arg1) {
    (*(s8 *)((s8 *)(arg0) + (0x8A))) = arg1;
}                      typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Objspline_arg2; /* offsets.py genstruct: fields from raw offsets on arg2; rename once understood */

/* extern */

f32 func_80800224_suspline(u8 *arg0, f32 *arg1, void *arg2) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    int func_80800074_suspline(u8 *, s32);
    f32 temp_f0;
    f32 temp_f0_2;
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = (((Objspline_arg0 *)arg0)->unk78);
    if (temp_v1 >= 4) {
        if ((((Objspline_arg0 *)arg0)->unk8A) & 2) {
            (((Objspline_arg2 *)arg2)->unk2) = (s16) (s32) (*arg1 * (f32) temp_v1);
        } else {
            (((Objspline_arg2 *)arg2)->unk2) = (s16) (s32) (*arg1 * (f32) (temp_v1 - 1));
        }
        temp_v0 = (((Objspline_arg2 *)arg2)->unk2);
        (((Objspline_arg2 *)arg2)->unk0) = (s16) (temp_v0 - 1);
        (((Objspline_arg2 *)arg2)->unk4) = (s16) (temp_v0 + 1);
        temp_v1 = (((Objspline_arg0 *)arg0)->unk78);
        if ((((Objspline_arg2 *)arg2)->unk4) >= temp_v1) {
            if ((((Objspline_arg0 *)arg0)->unk8A) & 2) {
                (((Objspline_arg2 *)arg2)->unk4) = (s16) ((((Objspline_arg2 *)arg2)->unk4) - temp_v1);
            } else {
                (((Objspline_arg2 *)arg2)->unk4) = (s16) (temp_v1 - 1);
            }
        }
        (((Objspline_arg2 *)arg2)->unk6) = (s16) ((((Objspline_arg2 *)arg2)->unk4) + 1);
        temp_v1 = (((Objspline_arg0 *)arg0)->unk78);
        temp_v0 = (((Objspline_arg2 *)arg2)->unk6);
        if (temp_v0 >= temp_v1) {
            if ((((Objspline_arg0 *)arg0)->unk8A) & 2) {
                (((Objspline_arg2 *)arg2)->unk6) = (s16) (temp_v0 - temp_v1);
            } else {
                (((Objspline_arg2 *)arg2)->unk6) = (s16) (temp_v1 - 1);
            }
        }
        if ((((Objspline_arg2 *)arg2)->unk0) < 0) {
            if ((((Objspline_arg0 *)arg0)->unk8A) & 2) {
                (((Objspline_arg2 *)arg2)->unk0) += (((Objspline_arg0 *)arg0)->unk78);
            } else {
                (((Objspline_arg2 *)arg2)->unk0) = 0;
            }
        }
        if (func_80800074_suspline(arg0, (s32) (((Objspline_arg2 *)arg2)->unk2)) != 0) {
            if ((((Objspline_arg0 *)arg0)->unk8A) & 2) {
                *arg1 = (f32) ((((Objspline_arg2 *)arg2)->unk2) + 1) / (f32) (((Objspline_arg0 *)arg0)->unk78);
            } else {
                *arg1 = (f32) ((((Objspline_arg2 *)arg2)->unk2) + 1) / (f32) ((((Objspline_arg0 *)arg0)->unk78) - 1);
            }
            (((Objspline_arg0 *)arg0)->unk8B) = 1;
        } else {
            (((Objspline_arg0 *)arg0)->unk8B) = 0;
        }
        if (func_80800074_suspline(arg0, (s32) (((Objspline_arg2 *)arg2)->unk4)) != 0) {
            (((Objspline_arg2 *)arg2)->unk6) = (s16) (((Objspline_arg2 *)arg2)->unk4);
        }
        if (func_80800074_suspline(arg0, (s32) (((Objspline_arg2 *)arg2)->unk0)) != 0) {
            (((Objspline_arg2 *)arg2)->unk0) = (s16) (((Objspline_arg2 *)arg2)->unk2);
        }
        temp_v0 = (((Objspline_arg2 *)arg2)->unk2);
        if ((((Objspline_arg0 *)arg0)->unk8A) & 2) {
            temp_f0_2 = (f32) (((Objspline_arg0 *)arg0)->unk78);
            return func_800F10B4(*arg1, (f32) temp_v0 / temp_f0_2, (f32) (temp_v0 + 1) / temp_f0_2, 0.333f, 0.666f);
        }
        temp_f0 = (f32) ((((Objspline_arg0 *)arg0)->unk78) - 1);
        return func_800F10B4(*arg1, (f32) temp_v0 / temp_f0, (f32) (((Objspline_arg2 *)arg2)->unk4) / temp_f0, 0.333f, 0.666f);
    }
    return 0.0f;
}

void suspline_entrypoint_13(u8 *arg0) {
    struct SplineOffsets {
        u8 pad[0x70];
        s16 offsets[8];
    };
    void _mlspline_entrypoint_1(f32 arg0, s32 arg1, u8 *arg2, f32 *arg3);
    void _mlspline_entrypoint_3(f32 arg0, s32 arg1, void *arg2, f32 *arg3);
    void _mlspline_entrypoint_9(f32, s32, f32 *, f32 *);
    f32 func_800D8FF8(void);
    f32 pad;
    s16 indices[4];
    f32 values[4];
    f32 t;
    s16 count;
    f32 *points;

    if (!(arg0[0x8A] & 1)) {
        count = *(s16 *)(arg0 + 0x78);
        points = (f32 *)(((struct SplineOffsets *)arg0)->offsets[*(s16 *)(arg0 + 0x7C)] + arg0);
        if (count >= 4) {
            t = func_80800224_suspline(arg0, (f32 *)(arg0 + 0x58), indices);
            values[0] = points[indices[0]];
            values[1] = points[indices[1]];
            values[2] = points[indices[2]];
            values[3] = points[indices[3]];
            _mlspline_entrypoint_9(t, 4, values, (f32 *)(arg0 + 0x60));
        } else if (count == 3) {
            _mlspline_entrypoint_3(*(f32 *)(arg0 + 0x58), count, points, (f32 *)(arg0 + 0x60));
        } else {
            _mlspline_entrypoint_1(*(f32 *)(arg0 + 0x58), count, points, (f32 *)(arg0 + 0x60));
        }
        if (*(f32 *)(arg0 + 0x54) < 0.05f) {
            *(f32 *)(arg0 + 0x54) = 0.05f;
        }
        *(f32 *)(arg0 + 0x64) = *(f32 *)(arg0 + 0x60) * func_800D8FF8();
    }
}

void suspline_entrypoint_14(u8 *arg0) {
    struct SplineOffsets {
        u8 pad[0x68];
        s16 offsets[8];
    };
    f32 _mlspline_entrypoint_13(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, void *arg5);
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

void suspline_entrypoint_15(u8 *arg0, f32 arg1) {
    struct SplineOffsets {
        u8 pad[0x68];
        s16 offsets[8];
    };
    f32 _mlspline_entrypoint_13(s32 arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, void *arg5);
    extern s32 _mlspline_entrypoint_6;
    extern s32 _mlspline_entrypoint_7;
    extern s32 _mlspline_entrypoint_8;
    f32 temp_f0;
    f32 var_f0;
    s16 temp_a0;
    u8 *temp_a1;
    if (((temp_f0 = *(f32 *)(arg0 + 0x58)) < 0.9999f) && !(*(u8 *)(arg0 + 0x8A) & 1)) {
        temp_a1 = ((struct SplineOffsets *)arg0)->offsets[*(s16 *)(arg0 + 0x7A)] + arg0;
        temp_a0 = *(s16 *)(arg0 + 0x78);
        if (temp_a0 >= 4) {
            var_f0 = _mlspline_entrypoint_13(temp_a0, temp_a1, temp_f0, arg1, 1.0f, &_mlspline_entrypoint_8);
        } else if (temp_a0 >= 3) {
            var_f0 = _mlspline_entrypoint_13(temp_a0, temp_a1, temp_f0, arg1, 1.0f, &_mlspline_entrypoint_7);
        } else {
            var_f0 = _mlspline_entrypoint_13(temp_a0, temp_a1, temp_f0, arg1, 1.0f, &_mlspline_entrypoint_6);
        }
        *(f32 *)(arg0 + 0x58) = var_f0;
    }
}

/* extern */

void suspline_entrypoint_16(u8 *arg0) {
    struct SplineSpeed {
        u8 pad[0x54];
        f32 speed;
        u8 pad58[0xC];
        f32 scale;
    };
    f32 func_800EEAD4(f32 *, f32 *);
    int func_800EECE0(f32 a[3], f32 b[3]);

    if (suspline_entrypoint_1(arg0) == 0) {
        if ((((Objspline_arg0 *)arg0)->unk64) != 0.0f) {
            if (func_800EECE0((f32 *)(arg0 + 0x48), (f32 *)(arg0 + 0x3C)) == 0) {
                ((struct SplineSpeed *)arg0)->speed *= ((struct SplineSpeed *)arg0)->scale / func_800EEAD4((f32 *)(arg0 + 0x48), (f32 *)(arg0 + 0x3C));
            }
        }
    }
}

void suspline_entrypoint_17(u8 *arg0) {
    void _mlspline_entrypoint_0(f32 t, s32 arg1, void *input, f32 *dst);
    void _mlspline_entrypoint_1(f32 arg0, s32 arg1, u8 *arg2, f32 *arg3);
    void _mlspline_entrypoint_2(f32 arg0, s32 arg1, void *input, f32 *output);
    void _mlspline_entrypoint_3(f32 arg0, s32 arg1, void *arg2, f32 *arg3);
    void _mlspline_entrypoint_4(f32, s32, f32 *, f32 *);
    void _mlspline_entrypoint_9(f32, s32, f32 *, f32 *);
    s32 func_800EE7F8();
    void func_800F0EF0(s32, f32 *);
    struct SplineOffsets17 {
        u8 pad[0x68];
        s16 vectors[4];
        s16 scalars[4];
    };
    f32 progress;
    f32 *vectors[4];
    f32 *scalars[4];
    f32 t;
    s32 i;
    s16 indices[4];
    f32 values[4];
    BT_IDO_ONLY(f32 point3[3];) BT_NATIVE_ONLY(f32 points[4][3]; f32 *point3 = points[3];)  // mlspline reads the four points as one array; IDO lays the locals out that way
    BT_IDO_ONLY(f32 point2[3];) BT_NATIVE_ONLY(f32 *point2 = points[2];)
    BT_IDO_ONLY(f32 point1[3];) BT_NATIVE_ONLY(f32 *point1 = points[1];)
    BT_IDO_ONLY(f32 point0[3];) BT_NATIVE_ONLY(f32 *point0 = points[0];)

    progress = *(f32 *)(arg0 + 0x58);
    func_800EE7F8((f32 *)(arg0 + 0x48), (f32 *)(arg0 + 0x3C));
    for (i = 0; i < arg0[0x88]; i++) {
        vectors[i] = (f32 *)(((struct SplineOffsets17 *)arg0)->vectors[i] + arg0);
    }
    for (i = 0; i < arg0[0x89]; i++) {
        scalars[i] = (f32 *)(((struct SplineOffsets17 *)arg0)->scalars[i] + arg0);
    }
    if (*(s16 *)(arg0 + 0x78) >= 4) {
        t = func_80800224_suspline(arg0, &progress, indices);
        for (i = 0; i < arg0[0x88]; i++) {
            func_800EE7F8(point0, vectors[i] + indices[0] * 3);
            func_800EE7F8(point1, vectors[i] + indices[1] * 3);
            func_800EE7F8(point2, vectors[i] + indices[2] * 3);
            func_800EE7F8(point3, vectors[i] + indices[3] * 3);
            if (func_808000B4_suspline(arg0, i)) {
                func_800F0EF0(4, point0);
            }
            _mlspline_entrypoint_4(t, 4, point0, (f32 *)(arg0 + i * 12));
        }
        for (i = 0; i < arg0[0x89]; i++) {
            values[0] = scalars[i][indices[0]];
            values[1] = scalars[i][indices[1]];
            values[2] = scalars[i][indices[2]];
            values[3] = scalars[i][indices[3]];
            _mlspline_entrypoint_9(t, 4, values, (f32 *)(arg0 + 0x30 + i * 4));
        }
    } else if (*(s16 *)(arg0 + 0x78) == 3) {
        for (i = 0; i < arg0[0x88]; i++) {
            _mlspline_entrypoint_2(progress, *(s16 *)(arg0 + 0x78), vectors[i], (f32 *)(arg0 + i * 12));
        }
        for (i = 0; i < arg0[0x89]; i++) {
            _mlspline_entrypoint_3(progress, *(s16 *)(arg0 + 0x78), scalars[i], (f32 *)(arg0 + 0x30 + i * 4));
        }
    } else {
        for (i = 0; i < arg0[0x88]; i++) {
            _mlspline_entrypoint_0(progress, *(s16 *)(arg0 + 0x78), vectors[i], (f32 *)(arg0 + i * 12));
        }
        for (i = 0; i < arg0[0x89]; i++) {
            _mlspline_entrypoint_1(progress, *(s16 *)(arg0 + 0x78), scalars[i], (f32 *)(arg0 + 0x30 + i * 4));
        }
    }
    if (progress > 0.9999f) {
        progress = 0.9999f;
    }
    *(f32 *)(arg0 + 0x58) = progress;
}    typedef struct { u8 pad0[0x68]; s16 unk68; } Objspline_func_80800C8C_suspline_var_a1; /* offsets.py genstruct: fields from raw offsets on var_a1; rename once understood */ typedef struct { u8 pad0[0x70]; s16 unk70; } Objspline_func_80800C8C_suspline_var_a1_2; /* offsets.py genstruct: fields from raw offsets on var_a1_2; rename once understood */

void func_80800C8C_suspline(u8 *arg0) {
    s32 var_v0;
    s32 var_v1;
    u8 *var_a1;
    u8 *var_a1_2;

    var_v0 = 0x8C;
    var_v1 = 0;
    var_a1 = arg0;
    if ((s32) (((Objspline_arg0 *)arg0)->unk88) > 0) {
        do {
            (((Objspline_func_80800C8C_suspline_var_a1 *)var_a1)->unk68) = var_v0;
            var_v1 += 1;
            var_a1 += 2;
            var_v0 += (((Objspline_arg0 *)arg0)->unk78) * 0xC;
        } while (var_v1 < (s32) (((Objspline_arg0 *)arg0)->unk88));
        var_v1 = 0;
    }
    var_a1_2 = arg0;
    if ((s32) (((Objspline_arg0 *)arg0)->unk89) > 0) {
        do {
            (((Objspline_func_80800C8C_suspline_var_a1_2 *)var_a1_2)->unk70) = var_v0;
            var_v1 += 1;
            var_a1_2 += 2;
            var_v0 += (((Objspline_arg0 *)arg0)->unk78) * 4;
        } while (var_v1 < (s32) (((Objspline_arg0 *)arg0)->unk89));
    }
}

s32 suspline_entrypoint_18(s32 arg0, s32 arg1, s32 arg2) {
    return (s32)((u32)arg0 * (u32)((arg1 * 0xC) + (arg2 * 4))) + 0x8C;
}

void suspline_entrypoint_19(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void func_800EFD24(f32 *);
    s32 i;
    func_800EFD24((f32 *)(arg0 + 0x3C));
    func_800EFD24((f32 *)(arg0 + 0x48));
    *(f32 *)(arg0 + 0x60) = 0.0f;
    *(f32 *)(arg0 + 0x64) = 0.0f;
    for (i = 0; i < 9; i++) {
        arg0[0x7E + i] = 0;
    }
    *(s16 *)(arg0 + 0x7A) = arg4;
    *(s16 *)(arg0 + 0x7C) = arg5;
    *(s16 *)(arg0 + 0x78) = arg1;
    *(u8 *)(arg0 + 0x88) = arg2;
    *(u8 *)(arg0 + 0x89) = arg3;
    *(u8 *)(arg0 + 0x87) = 0;
    *(f32 *)(arg0 + 0x54) = 1.0f;
    func_800EFD24((f32 *)(arg0 + 0x48));
    *(f32 *)(arg0 + 0x58) = 0.0f;
    *(f32 *)(arg0 + 0x5C) = -0.01f;
    *(u8 *)(arg0 + 0x8B) = 0;
    *(u8 *)(arg0 + 0x8A) = 0;
    func_80800C8C_suspline(arg0);
    }

/* extern */

void suspline_entrypoint_20(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u32 *func_80100074(Actor *actor,u32 slot,u32 size);
    BtIntPtr func_80100094(BtIntPtr, s32);
    s32 suspline_entrypoint_18(s32, s32, s32);
    void suspline_entrypoint_19(u8 *, s32, s32, s32, s32, s32);
    func_80100074(arg0, 1, suspline_entrypoint_18(arg1, arg2, arg3));
    suspline_entrypoint_19(func_80100094(arg0, 1), arg1, arg2, arg3, arg4, arg5);
}
