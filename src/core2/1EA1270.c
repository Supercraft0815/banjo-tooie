#include "core2/1EA1270.h"

#ifdef BT_NATIVE
#include "ml/spline.h"
f32 D_80125920 = 100000000.0f;
f32 D_80125924 = 0.009999999776f;
#else
typedef void (*SplineDerivativeFunc)(f32, u8, s32 *, f32 *);
#endif

SplineDerivativeFunc func_800C7980(u8 *arg0) {
#ifndef BT_NATIVE
    void _mlspline_entrypoint_6(f32, u8, s32 *, f32 *);
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_7(f32, u8, s32 *, f32 *);
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_8(f32, u8, s32 *, f32 *);
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_10(f32, u8, s32 *, f32 *);
#endif
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = arg0[2];
    temp_v1 = arg0[3];
    if (temp_v0 < 2) {
        return NULL;
    }
    if (temp_v0 == 2) {
        return &_mlspline_entrypoint_6;
    }
    if (temp_v0 == 3) {
        return &_mlspline_entrypoint_7;
    }
    if (temp_v1 == 1) {
        return &_mlspline_entrypoint_10;
    }
    return &_mlspline_entrypoint_8;
}   

/* extern */

#ifdef BT_NATIVE
SplineDerivativeFunc func_800C79EC(Unk800C7A68 *arg0) {
#else
void (*func_800C79EC(Unk800C7A68 *arg0))(f32, u8, s32 *, f32 *) {
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_0(f32, u8, s32 *, f32 *);
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_2(f32, u8, s32 *, f32 *);
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_4(f32, u8, s32 *, f32 *);
#endif
#ifndef BT_NATIVE
    void _mlspline_entrypoint_5(f32, u8, s32 *, f32 *);
#endif
    s32 temp_v0;
    s32 temp_v1;

    temp_v0 = arg0->unk2;
    temp_v1 = arg0->pad3[0];
    if (temp_v0 < 2) {
        return NULL;
    }
    if (temp_v0 == 2) {
        return _mlspline_entrypoint_0;
    }
    if (temp_v0 == 3) {
        return _mlspline_entrypoint_2;
    }
    if (temp_v1 == 1) {
        return _mlspline_entrypoint_5;
    }
    return _mlspline_entrypoint_4;
}

void func_800C7A58(void) {
}

void func_800C7A60(void) {
}

void func_800C7A68(Unk800C7A68* arg0, f32 arg1, f32 *arg2) {
    if (arg1 < 0.0f) {
        arg1 = 0.0f;
    } else if (arg1 > 1.0f) {
        arg1 = 1.0f;
    }

    func_800C79EC(arg0)(arg1, arg0->unk2, &arg0->unk14, arg2);
}          typedef struct { u8 pad0[0x2]; u8 unk2; u8 pad3[0x1]; u8 unk4; u8 pad5[0x7]; f32 unkC; u8 pad10[0x4]; f32 unk14; } Obj1EA1270_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

#ifdef BT_NATIVE
f32 func_800C7AE4(u8 *arg0, f32 arg1, f32 arg2) {
#else
void func_800C7AE4(u8 *arg0, s32 arg1, s32 arg2) {
#endif
#ifndef BT_NATIVE
    s32 _mlspline_entrypoint_11(u8, u8 *, s32, s32, void (*)(f32, u8, s32 *, f32 *));
#endif
    SplineDerivativeFunc func_800C7980(u8 *);
#ifdef BT_NATIVE
    return
#endif
    _mlspline_entrypoint_11((((Obj1EA1270_arg0 *)arg0)->unk2), arg0 + 0x14, arg1, arg2, func_800C7980((u8 *)arg0));
}

/* extern */

#ifdef BT_NATIVE
f32 func_800C7B28(u8 *arg0, f32 arg1, f32 arg2, s32 arg3) {
#else
void func_800C7B28(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
#endif
#ifndef BT_NATIVE
    s32 _mlspline_entrypoint_12(u8, u8 *, s32, s32, s32, void (*)(f32, u8, s32 *, f32 *));
#endif
    SplineDerivativeFunc func_800C7980(u8 *);
#ifdef BT_NATIVE
    return
#endif
    _mlspline_entrypoint_12((((Obj1EA1270_arg0 *)arg0)->unk2), arg0 + 0x14, arg1, arg2, arg3 * 2, func_800C7980((u8 *)arg0));
}

f32 func_800C7B7C(Unk800C7A68 *arg0, f32 arg1, f32 arg2, f32 arg3) {
#ifndef BT_NATIVE
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, void (*)(f32, u8, s32 *, f32 *));
#endif
    SplineDerivativeFunc func_800C7980(u8 *);
    return _mlspline_entrypoint_13((s16) arg0->unk2, (u8 *) &arg0->unk14, arg1, arg2, 0.0f, func_800C7980((u8 *)arg0));
}

f32 func_800C7BCC(u8 *arg0, u8 *arg1) {
    s32 count = arg0[2];
    f32 *point;
    f32 *end;
    s32 i;

    point = (f32 *) (arg0 + 0x14);
    end = (f32 *) (count * 12 + arg0 + 0x14);
    for (i = 0; point != end; point += 3, i++) {
        if (point[0] == ((f32 *) arg1)[0] && point[1] == ((f32 *) arg1)[1] && point[2] == ((f32 *) arg1)[2]) {
            return (f32) i / (count - 1);
        }
    }
    return -1.0f;
}

f32 func_800C7E28(void *arg0) {
    s32 count = ((Unk800C7A68 *) arg0)->unk2;
    f32 *point;
    f32 *end;
    s32 i;

    point = &((Obj1EA1270_arg0 *)arg0)->unk14;
    end = (f32 *) (count * 12 + (u8 *) arg0 + 8);
    for (i = 0; point != end; point += 3, i++) {
        if (point[0] == end[0] && point[1] == end[1] && point[2] == end[2]) {
            return *&((Obj1EA1270_arg0 *)arg0)->unkC = (f32) i / (count - 1);
        }
    }
    return *&((Obj1EA1270_arg0 *)arg0)->unkC = 1.0f;
}

/* extern */

f32 func_800C7FD4(u8 *arg0, f32 arg1, f32 arg2) {
    f32 _glintrosyncDll_entrypoint_5(void);
#ifndef BT_NATIVE
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, void (*)(f32, u8, s32 *, f32 *));
#endif
    SplineDerivativeFunc func_800C7980(u8 *);
    f32 func_800C7E28(void *);
    f32 func_800D8FF8(void);
    f32 sp2C;
    f32 sp30;
    f32 var_f0;

    if ((((Obj1EA1270_arg0 *)arg0)->unk4) != 0) {
        var_f0 = _glintrosyncDll_entrypoint_5();
    } else {
        var_f0 = func_800D8FF8();
    }
    sp2C = var_f0;
    sp30 = func_800C7E28(arg0);
    return _mlspline_entrypoint_13((((Obj1EA1270_arg0 *)arg0)->unk2), arg0 + 0x14, arg1, var_f0 * arg2, sp30, func_800C7980(arg0));
}

/* extern */

f32 func_800C8070(u8 *arg0, f32 arg1, f32 arg2, s32 *arg3) {
    f32 func_800C7FD4(u8 *, f32, f32);
    f32 temp_f0;
    f32 temp_f2;

    temp_f0 = func_800C7FD4(arg0, arg1, arg2);
    temp_f2 = temp_f0;
    *arg3 = 0;
    if (arg2 > 0.0f) {
        if (temp_f0 < arg1) {
            *arg3 = 1;
        }
    } else if ((arg2 < 0.0f) && (arg1 < temp_f0)) {
        *arg3 = 1;
    }
    return temp_f2;
}

void func_800C810C(u8 *arg0, f32 arg1, f32 *arg2, f32 *arg3) {
    f32 func_800136E4(f32);
    void func_800EF2A0(f32 *);
    void func_800F1A88(f32 *, f32 *);

    func_800C7980(arg0)(arg1, arg0[2], (s32 *)(arg0 + 0x14), arg2);
    func_800F1A88(arg2, arg3);
    arg3[0] = func_800136E4(arg3[0]);
    arg3[1] = func_800136E4(arg3[1] + 180.0f);
    arg3[2] = 0.0f;
    func_800EF2A0(arg2);
}

f32 func_800C8198(Unk800C7A68 *arg0, f32 arg1[3], f32 min, f32 max, f32 step) {
    extern f32 D_80125920;
    void func_800EFB24(void *, void *, void *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 sp74[3];
    f32 sp68[3];
    f32 f22;
    f32 f28;
    f32 f20;
    f32 f24;
    f32 f2;

    min = func_800F0E00(0.0f, min);
    max = func_800F13F0(1.0f, max);
    f24 = D_80125920;
    f28 = min;
    f20 = min;
    do {
        func_800C7A68(arg0, f20, sp68);
        func_800EFB24(sp74, arg1, sp68);
        f2 = sp74[0]*sp74[0] + sp74[1]*sp74[1] + sp74[2]*sp74[2];
        if (f2 < f24) {
            f24 = f2;
            f28 = f20;
        }
        if (f20 == max)
            break;
        else {
            f20 += step;
            if (f20 > max)
                f20 = max;
        }
    } while (1);
    return f28;
}

f32 func_800C82CC(void *arg0, f32 *arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    extern f32 D_80125924;
    f32 result;
    f32 step;
    f32 min;
    f32 max;
    f32 sp5C[3];
    f32 sp50[3];
    f32 initial;
    result = func_800C7BCC(arg0, (u8 *)arg1);
    if (result >= 0) {
    return result;

} initial = D_80125924;
    step = initial;
    result = func_800C8198(arg0, arg1, 0.0f, 1.0f, initial);
    min = result - step;
    max = result + step;
    step = 2.0f * (step / 10.0f);
    result = func_800C8198(arg0, arg1, min, max, step);
    min = result - step;
    max = result + step;
    initial = step / 10.0f;
    step = 2.0f * initial;
    result = func_800C8198(arg0, arg1, min, max, step);
    min = result - step;
    max = result + step;
    initial = step / 10.0f;
    step = 2.0f * initial;
    result = func_800C8198(arg0, arg1, min, max, step);
    min = result - step;
    max = result + step;
    initial = step / 10.0f;
    step = 2.0f * initial;
    result = func_800C8198(arg0, arg1, min, max, step);
    min = result - step;
    max = result + step;
    initial = step / 10.0f;
    step = 2.0f * initial;
    result = func_800C8198(arg0, arg1, min, max, step);
    func_800C7A68(arg0, result, sp5C);
    func_800C7A68(arg0, 1.0f, sp50);
    initial = func_800EEB40(arg1, sp5C);
    if (initial < func_800EEB40(arg1, sp50)) {
    return result;

} return 1.0f;

}

void func_800C84A4(s8 *arg0, s32 arg1) {
    arg0[3] = arg1;
}
