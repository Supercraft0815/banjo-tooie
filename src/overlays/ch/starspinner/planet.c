#include "common.h"

OSThread *chstarspinnerplanet_entrypoint_0(void)
{
    extern u8 D_80800260_chstarspinnerplanet[];

    return (OSThread *) D_80800260_chstarspinnerplanet;
}

OSThread *chstarspinnerplanet_entrypoint_1(void)
{
    extern u8 D_808002A8_chstarspinnerplanet[];

    return (OSThread *) D_808002A8_chstarspinnerplanet;
}

void func_80800018_chstarspinnerplanet(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    f32 func_800F15F8(f32, f32, f32);
    extern u32 D_808002F0_chstarspinnerplanet;
    f32 sp24;

    if (func_800DA298(0) != 0) {
        sp24 = func_800D8FF8();
        ((f32 *)arg0->actorData)[5] = func_800F15F8(((f32 *)arg0->actorData)[5], 20.0f, 0.5f);
        ((f32 *)arg0->actorData)[4] = func_800F15F8(((f32 *)arg0->actorData)[4], 40.0f, 0.8f);
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] + ((f32 *)arg0->actorData)[5] * sp24);
        arg0->rotation[0] = func_800136E4(arg0->rotation[0] + ((f32 *)arg0->actorData)[4] * sp24);
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, func_800DA298(0), &D_808002F0_chstarspinnerplanet);
}

/* extern */

void func_808000E4_chstarspinnerplanet(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiefade_entrypoint_12(s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800EA05C();
    void func_80108A30(s32, void *, f32, s32);
    s32 func_8010A624(s32);
    if ((func_800DA298(0xEA) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800DA544(0);
    }
    func_80108A30(0x335, (void *)(arg0 + 4), 0.0f, 0x32);
    if (func_800EA05C() != 0xE6) {
        func_8010A624(arg0);
    }
    _subaddiefade_entrypoint_12(arg0, 0xA0, 0xA0, 0xA0);
}

/* extern */

void func_80800170_chstarspinnerplanet(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8();
    s32 func_800DA298(s32);
    f32 func_800F15F8(f32, f32, f32);
    f32 sp1C;
    f32 temp_f0;

    if (func_800DA298(0) != 0) {
        sp1C = func_800D8FF8();
        temp_f0 = func_800F15F8((*(f32 *)((s8 *)(arg0) + (0x2C))), 25.0f, 0.6f);
        (*(f32 *)((s8 *)(arg0) + (0x2C))) = temp_f0;
        (*(f32 *)((s8 *)(arg0) + (0x48))) = func_800136E4((*(f32 *)((s8 *)(arg0) + (0x48))) - (temp_f0 * sp1C));
    }
}

/* extern */

void func_808001E8_chstarspinnerplanet(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiefade_entrypoint_12(s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800EA05C();
    s32 func_8010A624(s32);
    if ((func_800DA298(0xEA) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800DA544(0);
    }
    if (func_800EA05C() != 0xE6) {
        func_8010A624(arg0);
    }
    _subaddiefade_entrypoint_12(arg0, 0xA0, 0xA0, 0xA0);
}
