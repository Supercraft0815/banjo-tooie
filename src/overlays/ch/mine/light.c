#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/light/func_80800000_chminelight.s")

void func_8080011C_chminelight(Actor *arg0) {
    s32 _idworld_entrypoint_3(s32);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_8001210C(s32);
    void func_800C8800(s32, f32 *);
    void func_800C8E84(s32, s32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EDDDC(s32, f32 *, f32 *, f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800660_chminelight[];
    extern s32 D_80800674_chminelight[];
    extern s32 D_80800688_chminelight[];
    u8 (*colors)[3];
    s32 world;
    s32 rgb[3];
    s32 i;
    f32 intensity;
    f32 rgba[4];

    colors = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 2:
            if (((f32 *)arg0->actorData)[6] <= 0.975f) {
                if (func_8001210C(3)) {
                    ((f32 *)arg0->actorData)[6] += 0.025f;
                }
            } else {
                arg0->unk70_10 = 3;
            }
            break;
        case 4:
            if (((f32 *)arg0->actorData)[6] >= 0.02f) {
                if (func_8001210C(3)) {
                    ((f32 *)arg0->actorData)[6] -= 0.02f;
                }
            } else {
                arg0->unk70_10 = 1;
            }
            break;
    }
    if (arg0->unk54 != ((f32 *)arg0->actorData)[6]) {
        intensity = ((f32 *)arg0->actorData)[6];
        if (intensity < 0.9f && func_800DC0C0() < 0.8f) {
            intensity *= func_800DC178(0.25f, 0.5f);
            func_800C8800(D_80800688_chminelight[arg0->unk6C_0], (f32 *)arg0->actorData);
            if ((s32)arg0->unk70_10 == 2) {
                if (func_800DC0C0() < 0.3f) {
                    _subaddieaudioquick_entrypoint_2((s32)arg0, (s32)arg0->position, D_80800660_chminelight);
                }
            } else if (func_800DC0C0() < 0.15f) {
                _subaddieaudioquick_entrypoint_2((s32)arg0, (s32)arg0->position, D_80800674_chminelight);
            }
        }
        for (i = 0; i < 2; i++) {
            rgb[0] = colors[arg0->unk6C_0][0] * intensity;
            rgb[1] = colors[arg0->unk6C_0][1] * intensity;
            rgb[2] = colors[arg0->unk6C_0][2] * intensity;
            func_800C8E84(D_80800688_chminelight[arg0->unk6C_0], rgb);
            if (arg0->unk6C_0 >= 8) {
                arg0->unk6C_0 = 0;
                arg0->unk54 = ((f32 *)arg0->actorData)[6];
            } else {
                arg0->unk6C_0++;
            }
        }
    }
    world = _idworld_entrypoint_3(0x1AA);
    if (world) {
        rgba[0] = ((f32 *)arg0->actorData)[6];
        rgba[1] = ((f32 *)arg0->actorData)[6];
        rgba[2] = ((f32 *)arg0->actorData)[6];
        rgba[3] = ((f32 *)arg0->actorData)[6];
        func_800EDDDC(world, rgba, rgba, 0.0f);
    }
}

void func_808004CC_chminelight(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/light/func_808004D4_chminelight.s")

OSThread *chminelight_entrypoint_0(void)
{
    extern u8 D_808006AC_chminelight[];

    return (OSThread *) D_808006AC_chminelight;
}
