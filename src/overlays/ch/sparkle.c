#include "common.h"

void func_80800000_chsparkle(f32 *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern s16 D_80800120_chsparkle[];
    extern s32 D_8080012C_chsparkle[];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp34[2];
    s32 sp30;
    s32 sp2C;

    sp30 = func_800DC128(0, 5);
    sp2C = func_800B53A4(1);
    func_800BA3FC(sp2C, D_80800120_chsparkle[sp30]);
    func_800E3980(sp54);
    func_800EE7F8(sp48, arg0 + 1);
    sp48[1] -= 200.0f;
    func_800F18FC(arg0 + 1, sp54, sp34);
    func_800EEB9C(sp3C, sp34[1] + func_800DC178(-90.0f, 90.0f), 40.0f);
    func_800EF04C(sp3C, arg0 + 1);
    sp3C[1] += func_800DC178(0.0f, 120.0f);
    func_800BABB8(sp2C, sp3C, sp48, 1.0f, D_8080012C_chsparkle);
}

OSThread *chsparkle_entrypoint_0(void)
{
    extern u8 D_80800164_chsparkle[];

    return (OSThread *) D_80800164_chsparkle;
}
