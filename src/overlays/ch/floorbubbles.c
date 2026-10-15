#include "common.h"

void func_80800000_chfloorbubbles(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA568(s16 *, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800270_chfloorbubbles[];
    f32 (*sp34)[3];
    s32 sp30;
    s32 sp2C;
    s32 temp_v0;
    s32 temp_v0_2;

    sp34 = func_80100094(arg0, 0);
    if (func_800DC0C0() < 0.1f) {
        temp_v0 = func_800DC128(0, 5);
        sp30 = temp_v0;
        temp_v0_2 = func_800B53A4(temp_v0);
        sp2C = temp_v0_2;
        func_800BABB8(temp_v0_2, sp34[arg0->unk6C_0], NULL, 1.0f, D_80800270_chfloorbubbles);
        func_800BA568((s16 *)sp2C, (s16) (s32) (*(f32 *)&arg0->actorData[1]));
        func_800BA22C(sp2C, sp30);
        if (func_800DC0C0() < 0.75f) {
            arg0->unk6C_0 = func_800DC128(0, 0xA);
        }
    }
}

/* extern */

void func_8080010C_chfloorbubbles(Actor *arg0) {
    s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
    s32 _subaddie3d_entrypoint_1(f32 *, f32, f32, u32 *);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 temp_f20;
    f32 (*temp_v0)[3];
    s32 var_s1;

    temp_v0 = func_80100094(arg0, 0);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        temp_f20 = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(temp_v0[var_s1], temp_f20, func_800DC178(0.0f, (s32)arg0->unk74_7 * 10));
        func_800EF04C(temp_v0[var_s1], arg0->position);
        _subaddie3d_entrypoint_0(temp_v0[var_s1], 100.0f, -100.0f, &temp_v0[var_s1][1]);
    }
    _subaddie3d_entrypoint_1(arg0->position, 500.0f, 0.0f, &arg0->actorData[1]);
}

void func_80800244_chfloorbubbles(s32 arg0) 
{
}
OSThread *chfloorbubbles_entrypoint_0(void)
{
    extern u8 D_808002CC_chfloorbubbles[];

    return (OSThread *) D_808002CC_chfloorbubbles;
}
