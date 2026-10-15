#include "ch/lavaexplodbuild.h"

/* extern */

void func_80800000_chlavaexplodbuild(s32 arg0) {
    s32 func_800EFA4C(void *, s32, s32, s32);
    s32 func_80103014(s32);
    void *temp_a0;

    temp_a0 = arg0 + 4;
    (*(f32 *)((s8 *)(temp_a0) + (0x44))) = 45.0f;
    func_800EFA4C(temp_a0, 0xC6115000, 0x42480000, 0xC3FA0000);
    func_80103014(arg0);
}

/* extern */

void func_80800048_chlavaexplodbuild(s32 arg0) {
    s32 func_8010CB0C(s32, s32, s32, s32);
    func_800DA3B8(FLAG3_A24_UNK, func_8010CB0C(arg0 + 4, 0x708, 0x7D0, -0x1F4));
}

void func_80800084_chlavaexplodbuild(s32 arg0)
{
    func_800DA524(FLAG3_A24_UNK);
}

s32 func_808000A8_chlavaexplodbuild(void *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_80018820(s32, f32, f32);
    void func_800C4AF0(f32 *, void *);
    s32 func_800E15CC(s32, f32, f32);
    void func_80800138_chlavaexplodbuild(void *);
    extern s32 D_80800290_chlavaexplodbuild;
    void *sp1C[1];

    if (arg1 == 0x40) {
        sp1C[0] = (u8 *)arg0 + 4;
        _chexploder_entrypoint_3(arg0, sp1C[0], 0xC);
        func_80800138_chlavaexplodbuild(arg0); func_800C4AF0(sp1C[0], &D_80800290_chlavaexplodbuild);
        func_800E15CC(0, 80.0f, 0.95f);
        func_80018820(0, 4.0f, 0.45f);
        func_800DA544(FLAG_049_PHYSICAL_HFP_StoneBuildingBroken);
        arg1 = 1;
    } else {
        return 0;
    }
    return arg1;
}

void func_80800138_chlavaexplodbuild(void *arg0) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    extern s32 D_808002A4_chlavaexplodbuild;
    s32 temp_s3;
    f32 sp80[3];
    f32 sp74[3];
    s32 var_s0;

    func_800EE7F8(sp74, (f32 *)((u8 *)arg0 + 4));
    temp_s3 = func_800B53A4(0xA);
    for (var_s0 = 0; var_s0 != 0xA; var_s0++) {
        func_800EEB9C(sp80, (f32) var_s0 * 36.0f, func_800DC178(300.0f, 400.0f));
        func_800EF04C(sp80, (f32 *)((u8 *)arg0 + 4));
        sp80[1] += func_800DC178(400.0f, 600.0f);
        func_800BABB8(temp_s3, sp80, sp74, 2.25f, &D_808002A4_chlavaexplodbuild);
    }
}

OSThread *chlavaexplodbuild_entrypoint_0(void)
{
    extern u8 D_808002E0_chlavaexplodbuild[];

    return (OSThread *) D_808002E0_chlavaexplodbuild;
}
