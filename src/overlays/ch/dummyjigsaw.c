#include "common.h"

void func_80800000_chdummyjigsaw(Actor *arg0) {
    void _fxtwinkle_entrypoint_2(f32 *, s32);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_80103DFC(Actor *, f32 *);
    f32 sp5C[3];
    f32 temp_f20;
    s32 var_s1;

    var_s1 = 0;
    if (arg0->unk7C_12) {
        do {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(arg0, sp5C);
                temp_f20 = func_800DC178(0.0f, 360.0f);
                func_800EF214(sp5C, temp_f20, func_800DC178(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_2(sp5C, 0x9E2);
            }
            var_s1 += 1;
        } while (var_s1 != 4);
    }
    arg0->rotation[1] += func_800D8FF8() * 230.0f;
    arg0->rotation[1] = func_800136E4(arg0->rotation[1]);
}

s32 func_80800128_chdummyjigsaw(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFA88(Unk80132ED0 *);
    if ((arg1 == 0x3E) && arg0->unk64_20) {
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

OSThread *chdummyjigsaw_entrypoint_0(void)
{
    extern u8 D_80800190_chdummyjigsaw[];

    return (OSThread *) D_80800190_chdummyjigsaw;
}
