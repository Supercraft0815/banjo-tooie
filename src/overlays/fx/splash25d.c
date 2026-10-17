#include "common.h"

/* extern */

void fxsplash25d_entrypoint_0(void) {
    s32 func_800BA22C(s32, s32);
    s32 func_8080002C_fxsplash25d();
    func_800BA22C(func_8080002C_fxsplash25d(), 1);
}

s32 func_8080002C_fxsplash25d(f32 *arg0) {
    s32 func_800B5BE4(s32);
    void func_800BA660(void *, s32, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    s32 func_800FB350(f32[3], s32 *, f32 *);
    extern s32 D_80800110_fxsplash25d[];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp28;
    s32 emitter;
    s32 sp20;

    func_800EE7F8(sp2C, arg0);
    func_800FB350(sp2C, &sp20, &sp28);
    sp2C[1] = sp28 + 14.0f;
    func_800E3980(sp38);
    func_800EFB24(sp44, sp38, sp2C);
    sp44[1] = 0.0f;
    func_800EF368(sp44, 20.0f);
    func_800EF04C(sp2C, sp44);
    emitter = func_800B5BE4(4);
    if (sp20 != 0) {
        func_800BA660(emitter, sp20, (s16)(s32)sp2C[1]);
    }
    return func_800BABB8(emitter, sp2C, 0, 1.0f, D_80800110_fxsplash25d);
}
