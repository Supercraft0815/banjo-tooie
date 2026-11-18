#include "common.h"

s32 func_80800000_chminelight(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    BtIntPtr _idworld_entrypoint_3(s32);
    void _idworldmake_entrypoint_1(BtIntPtr arg0, s32 arg1, volatile unsigned int arg2, s32 arg3);
    void *func_800BEA88(s32 i);
    s32 func_800DA298(s32);
    void func_800EDDDC(BtIntPtr, f32 *, f32 *, f32);
    BtIntPtr world;
    f32 rgba[4];
    BtIntPtr player;

    if (arg1 == 0x95) {
        world = _idworld_entrypoint_3(0x1AA);
        if (world != 0) {
            rgba[0] = ((f32 *)arg0->actorData)[6];
            rgba[1] = ((f32 *)arg0->actorData)[6];
            rgba[2] = ((f32 *)arg0->actorData)[6];
            rgba[3] = ((f32 *)arg0->actorData)[6];
            player = func_800BEA88(0);
            if (player != 0) {
                _idworldmake_entrypoint_1(player, 0x69, 0x1AA, 1);
            }
            player = func_800BEA88(1);
            if (player != 0) {
                _idworldmake_entrypoint_1(player, 0x69, 0x1AA, 1);
            }
            func_800EDDDC(world, rgba, rgba, 0.0f);
        }
        if (_glcutDll_entrypoint_19(0x15) != 0) {
            if (func_800DA298(0x9E0) != 0) {
                _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x6910);
            } else {
                _capod_entrypoint_13(arg0->unk0, NULL, 2, 0x6910);
            }
            arg0->unk64_20 = 1;
        }
    } else {
        return 0;
    }
    return 1;
}

void func_8080011C_chminelight(Actor *arg0) {
    BtIntPtr _idworld_entrypoint_3(s32);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 func_8001210C(s32);
    void func_800C8800(BtIntPtr, f32 *);
    void func_800C8E84(s32, s32 *);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EDDDC(BtIntPtr, f32 *, f32 *, f32);
    void *func_80100094(Actor *, u32);
    extern s16 D_80800660_chminelight[9];
    extern s16 D_80800674_chminelight[9];
    extern s32 D_80800688_chminelight[9];
    u8 (*colors)[3];
    BtIntPtr world;
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
                    _subaddieaudioquick_entrypoint_2((BtIntPtr)arg0, (BtIntPtr)arg0->position, D_80800660_chminelight);
                }
            } else if (func_800DC0C0() < 0.15f) {
                _subaddieaudioquick_entrypoint_2((BtIntPtr)arg0, (BtIntPtr)arg0->position, D_80800674_chminelight);
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
void func_808004D4_chminelight(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    void func_800C8900(s32, s32 *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800688_chminelight[9];
    extern ActorData D_808006AC_chminelight[1];
    s32 rgb[5];
    s32 *id;
    u8 *color;

    color = func_80100094(arg0, 0); id = D_80800688_chminelight; do {
        func_800C8900(*id, rgb);
        id++;
        color += 3;
        color[-3] = rgb[0];
        color[-2] = rgb[1];
        color[-1] = rgb[2];
    } while ((void *)id != D_808006AC_chminelight);
    if (func_800DA298(0x9E0)) {
        if (arg0->unk70_10 != 3) {
            arg0->unk70_10 = 2;
            arg0->unk54 = -1.0f;
            if (_glcutDll_entrypoint_19(0x15) == 0) {
                ((f32 *)arg0->actorData)[6] = 1.0f;
            } else {
                ((f32 *)arg0->actorData)[6] = 0.0f;
            }
        }
    } else if (arg0->unk70_10 != 1) {
        arg0->unk70_10 = 4;
        arg0->unk54 = -1.0f;
        if (_glcutDll_entrypoint_19(0x15) == 0) {
            ((f32 *)arg0->actorData)[6] = 0.0f;
        } else {
            ((f32 *)arg0->actorData)[6] = 1.0f;
        }
    }
    func_8080011C_chminelight(arg0);
}

OSThread *chminelight_entrypoint_0(void)
{
    extern ActorData D_808006AC_chminelight[1];
    return (OSThread *) D_808006AC_chminelight;
}
#include "light_data.inc"
