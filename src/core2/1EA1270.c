#include "core2/1EA1270.h"

typedef void (*SplineDerivativeFunc)(f32, u8, s32 *, f32 *);

SplineDerivativeFunc func_800C7980(u8 *arg0) {
    void _mlspline_entrypoint_6(f32, u8, s32 *, f32 *);
    void _mlspline_entrypoint_7(f32, u8, s32 *, f32 *);
    void _mlspline_entrypoint_8(f32, u8, s32 *, f32 *);
    void _mlspline_entrypoint_10(f32, u8, s32 *, f32 *);
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

void (*func_800C79EC(Unk800C7A68 *arg0))(f32, u8, s32 *, f32 *) {
    void _mlspline_entrypoint_0(f32, u8, s32 *, f32 *);
    void _mlspline_entrypoint_2(f32, u8, s32 *, f32 *);
    void _mlspline_entrypoint_4(f32, u8, s32 *, f32 *);
    void _mlspline_entrypoint_5(f32, u8, s32 *, f32 *);
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
}

/* extern */

void func_800C7AE4(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _mlspline_entrypoint_11(u8, u8 *, s32, s32, void (*)(f32, u8, s32 *, f32 *));
    SplineDerivativeFunc func_800C7980();
    _mlspline_entrypoint_11((*(u8 *)((s8 *)(arg0) + (2))), arg0 + 0x14, arg1, arg2, func_800C7980());
}

/* extern */

void func_800C7B28(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _mlspline_entrypoint_12(u8, u8 *, s32, s32, s32, void (*)(f32, u8, s32 *, f32 *));
    SplineDerivativeFunc func_800C7980();
    _mlspline_entrypoint_12((*(u8 *)((s8 *)(arg0) + (2))), arg0 + 0x14, arg1, arg2, arg3 * 2, func_800C7980());
}

f32 func_800C7B7C(Unk800C7A68 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, void (*)(f32, u8, s32 *, f32 *));
    SplineDerivativeFunc func_800C7980();
    return _mlspline_entrypoint_13((s16) arg0->unk2, (u8 *) &arg0->unk14, arg1, arg2, 0.0f, func_800C7980());
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

    point = (f32 *) ((u8 *) arg0 + 0x14);
    end = (f32 *) (count * 12 + (u8 *) arg0 + 8);
    for (i = 0; point != end; point += 3, i++) {
        if (point[0] == end[0] && point[1] == end[1] && point[2] == end[2]) {
            return *(f32 *) ((u8 *) arg0 + 0xC) = (f32) i / (count - 1);
        }
    }
    return *(f32 *) ((u8 *) arg0 + 0xC) = 1.0f;
}

/* extern */

f32 func_800C7FD4(u8 *arg0, f32 arg1, f32 arg2) {
    f32 _glintrosyncDll_entrypoint_5(void);
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, void (*)(f32, u8, s32 *, f32 *));
    SplineDerivativeFunc func_800C7980();
    f32 func_800C7E28(void *);
    f32 func_800D8FF8(void);
    f32 sp2C;
    f32 sp30;
    f32 var_f0;

    if ((*(u8 *)((s8 *)(arg0) + (4))) != 0) {
        var_f0 = _glintrosyncDll_entrypoint_5();
    } else {
        var_f0 = func_800D8FF8();
    }
    sp2C = var_f0;
    sp30 = func_800C7E28(arg0);
    return _mlspline_entrypoint_13((*(u8 *)((s8 *)(arg0) + (2))), arg0 + 0x14, arg1, var_f0 * arg2, sp30, func_800C7980(arg0));
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C82CC.s")

void func_800C84A4(s8 *arg0, s32 arg1) {
    arg0[3] = arg1;
}
