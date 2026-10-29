#include "common.h"

/* extern */

void func_80800000_chlighthalo(u8 *arg0) {
    void func_800E8830(u8, f32 *);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0x34)));
    if (temp_a2 != 0) {
        func_800E8830(temp_a2, (f32 *)(arg0 + 4));
    }
}

/* extern */

void func_80800030_chlighthalo(void *arg0) {
    s32 func_800E87E0(s32, u8, void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x34)));
    if (temp_a1 != 0) {
        func_800E87E0(temp_a1 & 0xFF, temp_a1, arg0);
        (*(u8 *)((s8 *)(arg0) + (0x34))) = 0U;
    }
}

void func_80800068_chlighthalo(u8 *arg0, s32 arg1) {
    s32 func_800A89F8(void);
    s32 func_800E8918(u8, s32, s32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void _subaddiedraw25d_entrypoint_0(void *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800E2588(u32);
    void func_800E24F8(s32, s32, s32);
    void func_800E257C(s32);
    s32 func_800D674C(s32);
    void func_800E2AA4(s32, s32, s32, s32, void *, f32 *);
    struct HaloFlags { u32 unused:11; u32 edge:1; u32 rest:20; };
    struct HaloScale { u8 unused[0x38]; f32 value; };
    f32 screen[2];
    s32 alpha = 0;
    s32 visible;
    f32 fadeX;
    f32 fadeY;
    f32 scale[3];

    visible = func_800E8918(arg0[0x34], func_800A89F8(), 0, screen);
    switch (visible) {
        case -1:
            if (((struct HaloFlags *)(arg0 + 0x64))->edge) {
                fadeX = fadeY = 1.0f;
                if (screen[0] < ((struct HaloScale *)arg0)->value * -30.0f ||
                    screen[0] > 304 + ((struct HaloScale *)arg0)->value * 30.0f) {
                    fadeX = -1.0f;
                } else if (screen[0] <= 0.0f && screen[0] >= ((struct HaloScale *)arg0)->value * -30.0f) {
                    fadeX = func_800F10B4(screen[0], 0.0f, ((struct HaloScale *)arg0)->value * -30.0f, 1.0f, 0.0f);
                } else if (screen[0] >= 304 && screen[0] <= 304 + ((struct HaloScale *)arg0)->value * 30.0f) {
                    fadeX = func_800F10B4(screen[0], 304, 304 + ((struct HaloScale *)arg0)->value * 30.0f, 1.0f, 0.0f);
                }
                if (screen[1] < ((struct HaloScale *)arg0)->value * -30.0f ||
                    screen[1] > 228 + ((struct HaloScale *)arg0)->value * 30.0f) {
                    fadeY = -1.0f;
                } else if (screen[1] <= 0.0f && screen[1] >= ((struct HaloScale *)arg0)->value * -30.0f) {
                    fadeY = func_800F10B4(screen[1], 0.0f, ((struct HaloScale *)arg0)->value * -30.0f, 1.0f, 0.0f);
                } else if (screen[1] >= 228 && screen[1] <= 228 + ((struct HaloScale *)arg0)->value * 30.0f) {
                    fadeY = func_800F10B4(screen[1], 228, 228 + ((struct HaloScale *)arg0)->value * 30.0f, 1.0f, 0.0f);
                }
                if (fadeY != -1.0f && fadeY != -1.0f) {
                    alpha = (fadeX + fadeY) * 0.5f * 255.0f;
                    visible = 1;
                    break;
                }
            }
        case 0:
            alpha = arg0[0x9B] * 0.3f;
            if (alpha != 0) {
                visible = 1;
            }
            break;
        case 1:
            alpha = 255;
            break;
    }
    arg0[0x9B] = (arg0[0x9B] + alpha) >> 1;
    if (visible == 1) {
        _subaddiedraw25d_entrypoint_0(arg0);
        func_800EFA4C(scale, ((struct HaloScale *)arg0)->value, ((struct HaloScale *)arg0)->value, ((struct HaloScale *)arg0)->value);
        func_800E2588(0);
        func_800E24F8(arg0[0x98], arg0[0x99], arg0[0x9A]);
        func_800E257C(arg0[0x9B]);
        func_800E2AA4(arg1, func_800D674C(*(u16 *)(*(u8 **)arg0 + 0x14)), 0, 0, arg0 + 4, scale);
        ((struct HaloFlags *)(arg0 + 0x64))->edge = 1;
    } else {
        ((struct HaloFlags *)(arg0 + 0x64))->edge = 0;
    }
}

s32 func_80800448_chlighthalo(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct { f32 value[2]; } HaloRadius;
    void _subaddiefade_entrypoint_11(u8 *, u8 *);
    s32 func_800BF8E4(void);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    void func_800C8FE0(s32, s32);
    u8 func_800E8714(s32);
    void func_800E8830(u8, f32 *);
    void func_800E8870(u8, f32);
    extern f32 D_808006A0_chlighthalo[];
    u32 color;
    u32 rgb[3];
    if (arg1 == 0x95) {
        switch (arg0->unk74_7) {
            case 0x32: case 0x3C: color = 0xFFFF2000; break;
            case 0x33: case 0x3D: color = 0x20FF0000; break;
            case 0x34: case 0x3E: color = 0xFF202000; break;
            case 0x35: case 0x36: case 0x3F: case 0x40: color = 0x20FFFF00; break;
            case 0x37: case 0x41: color = 0xFF802000; break;
            case 0x38: case 0x42: color = 0xFF60FF00; break;
            case 0x39: case 0x43: color = 0xFFFFFF00; break;
            default: color = 0xFFFFFF00; break;
        }
        /* Keep the packed-color expansion together for original IDO scheduling. */
        rgb[0] = (color & 0xFF000000) >> 24; rgb[1] = (color & 0x00FF0000) >> 16; rgb[2] = (color & 0x0000FF00) >> 8;
        _subaddiefade_entrypoint_11((u8 *)arg0, (u8 *)rgb);
        if ((s32)arg0->unk74_7 < 0x3C) {
            if (func_800BF8E4() > 0) {
                HaloRadius radius = *(HaloRadius *)D_808006A0_chlighthalo;
                radius.value[0] *= arg0->scale;
                radius.value[1] *= arg0->scale;
                arg0->actorData[3] = func_800C8A98();
                func_800C8FB0(arg0->actorData[3], rgb[0], rgb[1], rgb[2]);
                func_800C8CB8(arg0->actorData[3], arg0->position);
                func_800C8F64(arg0->actorData[3], 5);
                func_800C8D4C(arg0->actorData[3], radius.value);
                func_800C8FE0(arg0->actorData[3], 1);
            }
        }
        ((u8 *)arg0)[0x34] = func_800E8714(1);
        func_800E8830(((u8 *)arg0)[0x34], arg0->position);
        arg0->rotation[1] += 50.0f;
        func_800E8870(((u8 *)arg0)[0x34], 50.0f);
        ((u8 *)arg0)[0x9B] = 0;
        arg0->unk64_20 = 0;
        return 1;
    }
    return 0;
}

void func_80800630_chlighthalo(s32 arg0) 
{
}
OSThread *chlighthalo_entrypoint_0(void)
{
    extern u8 D_808006A8_chlighthalo[];

    return (OSThread *) D_808006A8_chlighthalo;
}
