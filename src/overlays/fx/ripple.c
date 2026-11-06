#include "common.h"

/* extern */

s32 func_80800000_fxripple(f32 arg0[3], s32 *arg1, void *arg2) {
    void *func_800FB2AC(f32 arg0[3], f32 arg1);
    s32 func_800FB338(void *, void *, s32 *, f32 *);
    f32 sp1C;

    *arg1 = 0;
    if (arg2 != 0) {
        arg0[1] += 1.0f;
    } else {
        arg2 = func_800FB2AC(arg0, 50.0f);
        if (arg2 == 0) {
            return 0;
        }
    }
    if (func_800FB338(arg0, arg2, arg1, &sp1C) != 0) {
        arg0[1] = sp1C;
    }
    return 1;
}

s32 func_80800094_fxripple(s32 arg0, f32 *arg1, void *arg2) {
    s32 func_800B5BE4(s32);
    void func_800BA660(void *, s32, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 *D_80800320_fxripple[];
    extern s32 D_80800334_fxripple[];
    s32 sp3C;
    f32 sp30[3];
    s32 emitter;

    func_800EE7F8(sp30, arg1);
    if (func_80800000_fxripple(sp30, &sp3C, arg2) == 0) {
        return 0;
    }
    sp30[1] += 3.0f;
    emitter = func_800B5BE4(3);
    if (sp3C != 0) {
        func_800BA660(emitter, sp3C, (s16)(s32)sp30[1]);
    } else {
        func_800BA660(emitter, 0, 0);
    }
    func_800BABB8(emitter, sp30, NULL, 1.0f, D_80800334_fxripple);
    func_800BABB8(emitter, NULL, NULL, 1.0f, D_80800320_fxripple[arg0]);
    return emitter;
}

void fxripple_entrypoint_0(s32 arg0, s32 arg1) {
    s32 temp_v0;
    temp_v0 = func_80800094_fxripple(arg0, arg1, 0);
    if (temp_v0 != 0) {
        func_800BA22C(temp_v0, 1);
    }
}

void fxripple_entrypoint_1(void) {
    s32 func_80800094_fxripple();
    s32 temp_v0;
#ifdef BT_NATIVE
    temp_v0 = ((s32 (*)())func_80800094_fxripple)();
#else
    temp_v0 = func_80800094_fxripple();
#endif
    if (temp_v0 != 0) {
        func_800BA22C(temp_v0, 1);
    }
}

void fxripple_entrypoint_2(s32 arg0, s32 arg1) {
    func_80800094_fxripple(arg0, arg1, 0);
}

void fxripple_entrypoint_3()
{
    s32 func_80800094_fxripple();
#ifdef BT_NATIVE
    ((s32 (*)())func_80800094_fxripple)();
#else
    func_80800094_fxripple();
#endif
}

/* extern */

void fxripple_entrypoint_4(f32 arg0) {
    s32 func_800B5BE4(s32);
    s32 func_800BA5D0(s32, s16);
    func_800BA5D0(func_800B5BE4(3), (s16) (s32) arg0);
}
