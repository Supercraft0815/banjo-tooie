#include "core2/1EA1270.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C7980.s")

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
    s32 _mlspline_entrypoint_11(u8, u8 *, s32, s32, s32);
    s32 func_800C7980();
    _mlspline_entrypoint_11((*(u8 *)((s8 *)(arg0) + (2))), arg0 + 0x14, arg1, arg2, func_800C7980());
}

/* extern */

void func_800C7B28(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _mlspline_entrypoint_12(u8, u8 *, s32, s32, s32, s32);
    s32 func_800C7980();
    _mlspline_entrypoint_12((*(u8 *)((s8 *)(arg0) + (2))), arg0 + 0x14, arg1, arg2, arg3 * 2, func_800C7980());
}

f32 func_800C7B7C(Unk800C7A68 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, s32 *);
    s32 func_800C7980();
    return _mlspline_entrypoint_13((s16) arg0->unk2, (u8 *) &arg0->unk14, arg1, arg2, 0.0f, func_800C7980());
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C7BCC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C7E28.s")

/* extern */

f32 func_800C7FD4(u8 *arg0, f32 arg1, f32 arg2) {
    f32 _glintrosyncDll_entrypoint_5(void);
    f32 _mlspline_entrypoint_13(s16, u8 *, f32, f32, f32, s32 *);
    s32 func_800C7980();
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C810C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C8198.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA1270/func_800C82CC.s")

void func_800C84A4(s8 *arg0, s32 arg1) {
    arg0[3] = arg1;
}
