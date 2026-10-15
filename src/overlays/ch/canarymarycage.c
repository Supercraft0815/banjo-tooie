#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800000_chcanarymarycage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_8080018C_chcanarymarycage.s")

/* extern */

void func_80800284_chcanarymarycage(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80800000_chcanarymarycage(Actor *, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    if ((func_800DA298(0x66) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80800000_chcanarymarycage(arg0, 4);
    }
    _subaddielink_entrypoint_0(sp1C);
}

/* extern */

void func_808002E0_chcanarymarycage(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DB9B0();
    if ((func_800DB9B0() == 0) && (func_800DA298(1) != 0) && (func_800DA298(0x507) == 0)) {
        func_800DA544(0x66);
        func_800DA544(0x507);
    }
}

void func_80800338_chcanarymarycage(Actor *arg0, s32 *arg1) {
    s32 _chexploder_entrypoint_4(void *, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DA544(s32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_80800000_chcanarymarycage(Actor *, s32);
    extern s32 D_80800628_chcanarymarycage;
    extern s32 D_80800668_chcanarymarycage;
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800668_chcanarymarycage);
    func_800EEB9C((f32 *)arg0->actorData, arg0->rotation[1] - 100.0f, 300.0f);
    ((f32 *)arg0->actorData)[1] = 180.0f;
    func_800EF04C((f32 *)arg0->actorData, arg0->position);
    func_800BBCB8((f32 *)arg0->actorData, NULL, 1.0f, 0xA, &D_80800628_chcanarymarycage);
    _chexploder_entrypoint_4(arg0, *arg1 + 4, 0x44);
    arg0->unk64_16 = 1;
    func_800DA544(1);
    func_80800000_chcanarymarycage(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/canarymarycage/func_80800410_chcanarymarycage.s")

OSThread *chcanarymarycage_entrypoint_0(void)
{
    extern u8 D_80800674_chcanarymarycage[];

    return (OSThread *) D_80800674_chcanarymarycage;
}
