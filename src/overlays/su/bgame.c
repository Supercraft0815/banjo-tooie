#include "common.h"

void susubgame_entrypoint_12(void *, void *);
void susubgame_entrypoint_0(s32 arg0, u8 *arg1, s32 arg2) {
    extern s32 D_80800970_susubgame;
    (*(s8 *)(arg1 + 0)) = 0;
    (*(s16 *)(arg1 + 2)) = arg2;
    (*(s8 *)(arg1 + 1)) = 0;
    (*(s16 *)(arg1 + 4)) = 0x15;
    susubgame_entrypoint_12(arg1, &D_80800970_susubgame);
}

void susubgame_entrypoint_1(s32 arg0, u8 *arg1, s32 arg2) {
    (*(s16 *)((s8 *)(arg1) + (4))) = arg2;
}

u8 susubgame_entrypoint_2(s32 arg0, u8 *arg1) {
    return *arg1;
}

/* extern */

s32 susubgame_entrypoint_3(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 susubgame_entrypoint_5(s32, u8 *, s32, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg2, arg3) != 0) {
        if (*arg1 != 2) {
            susubgame_entrypoint_5(arg0, arg1, 5, 1, 0);
        }
        return 2;
    }
    return 1;
}

/* extern */

int susubgame_entrypoint_4(s32 arg0, u8 *arg1) {
    void _glcutDll_entrypoint_17();
    s32 _ncpod_entrypoint_17(s32, s32);
    s32 func_800A93E4(s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
    if (arg1[0] != 0) {
        do {
            if (func_808008DC_susubgame(var_s0) != 0) {
                _ncpod_entrypoint_17(func_800A93E4(var_s0), 0);
            }
            var_s0 += 1;
        } while (var_s0 != 8);
        arg1[0] = 0;
        if (arg1[1] != 0) {
            arg1[1] = 0;
            _glcutDll_entrypoint_17();
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_5.s")

void susubgame_entrypoint_6(s32 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _ncpod_entrypoint_20(s32, s32, s32, s32);
    s32 func_800A93E4(s32);
    u32 func_800F54E4(void);
    void func_80800814_susubgame(s32 *, void *, s32);

    if (arg4 == 0) {
        arg4 = *arg0;
    }
    switch (*arg1) {
    case 0:
        func_80800814_susubgame(arg0, arg1, arg3);
    case 2:
    case 3:
        *arg1 = 1;
    case 1:
        _ncpod_entrypoint_20(func_800A93E4(func_800F54E4()), arg4, arg2, arg3 | 0x800);
        return;
    }
}

void susubgame_entrypoint_7(s32 *arg0, u8 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 _ncpod_entrypoint_20(s32, s32, s32, s32);
    s32 func_800A93E4(s32);
    void func_80800814_susubgame(s32 *, void *, s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    if (arg4 == 0) {
        arg4 = *arg0;
    }
    switch (*arg1) {
    case 0:
        func_80800814_susubgame(arg0, arg1, arg3);
    case 2:
    case 3:
        *arg1 = 1;
    case 1:
        var_s0 = 0;
        do {
            if (func_808008DC_susubgame(var_s0) != 0) {
                _ncpod_entrypoint_20(func_800A93E4(var_s0), arg4, arg2[var_s0], arg3 | 0x800);
            }
            var_s0 += 1;
        } while (var_s0 != 8);
        return;
    }
}

void susubgame_entrypoint_8(s32 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 _ncpod_entrypoint_32(s32, s32, s32, s32);
    s32 func_800A93E4(s32);
    void func_80800814_susubgame(s32 *, void *, s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    if (arg4 == 0) {
        arg4 = *arg0;
    }
    switch (*arg1) {
    case 0:
        func_80800814_susubgame(arg0, arg1, arg3);
    case 1:
    case 2:
        *arg1 = 3;
    case 3:
        var_s0 = 0;
        do {
            if (func_808008DC_susubgame(var_s0) != 0) {
                _ncpod_entrypoint_32(func_800A93E4(var_s0), arg4, arg2, arg3 | 0x800);
            }
            var_s0 += 1;
        } while (var_s0 != 8);
        return;
    }
}

/* extern */

s32 susubgame_entrypoint_9(void) {
    s32 func_800F6F00(s32);
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if ((func_808008DC_susubgame(var_s0) != 0) && (func_800F6F00(var_s0) == 0)) {
        return 0;
    }
    var_s0 += 1;
    if (var_s0 == 8) {
        return 1;
    }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_10.s")

/* extern */

void susubgame_entrypoint_11(s32 arg0) {
    s32 func_800CE88C(s32, s32);
    s32 func_800CEAA8();
    if (func_800CEAA8() != 0) {
        func_800CE88C(arg0, 0);
    }
}

/* extern */

void func_8080078C_susubgame(s32 arg0, s32 arg1) {
    s32 _gcdialogcamera_entrypoint_7(s32, s32 *);
    s32 _ncpod_entrypoint_22(s32, s32, s32);
    s32 _ncpod_entrypoint_23(s32, s32, s32);
    s32 _ncpod_entrypoint_24(s32, s32, s32);
    s32 func_800A93E4(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5DC8(u32, s32 *);
    void *func_80110024(s16 *);
    f32 sp3C[3];
    s32 sp30[3];
    s32 sp20[4];
    void *sp1C;

    sp1C = func_80110024(func_800A93E4(arg1));
    func_800F5A00(arg1, sp3C);
    func_800F5DC8(arg1, sp30);
    _ncpod_entrypoint_23(sp1C, 1, sp3C);
    _ncpod_entrypoint_24(sp1C, 1, sp30);
    _gcdialogcamera_entrypoint_7(arg1, sp20);
    _ncpod_entrypoint_22(sp1C, 1, sp20);
}

/* extern */

void func_80800814_susubgame(s32 *arg0, void *arg1, s32 arg2) {
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _ncpod_entrypoint_16(s32, s32, s32, s32);
    s32 func_800A93E4(s32);
    s32 func_800EA05C();
    int func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_808008DC_susubgame(var_s0) != 0) {
            _ncpod_entrypoint_16(func_800A93E4(var_s0), *arg0, (*(s16 *)((s8 *)(arg1) + (4))), arg2 | 0x800);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
    if (arg2 & 0x800) {
        (*(u8 *)((s8 *)(arg1) + (1))) = 0U;
    } else {
        (*(u8 *)((s8 *)(arg1) + (1))) = 1U;
    }
    if ((*(u8 *)((s8 *)(arg1) + (1))) != 0) {
        _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
    }
}

/* extern */

int func_808008DC_susubgame(s32 arg0) {
    s32 func_800A9420(s32);
    s32 func_800D3948(void);
    u32 func_800F54E4(void);
    s32 func_800F6438(u32);
    if (func_800D3948() != 0) {
        return func_800F6438(arg0) != 0 && func_800A9420(arg0) != 0;
    } else {
        return func_800F54E4() == arg0;
    }
}

void susubgame_entrypoint_12(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x14))) = (f32) (*(f32 *)((s8 *)(arg1) + (0xC)));
}
