#include "common.h"

/* extern */

void func_80800000_chlighthalo(u8 *arg0) {
    s32 func_800E8830(s32, u8 *, u8, u8 *);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0x34)));
    if (temp_a2 != 0) {
        func_800E8830(temp_a2 & 0xFF, arg0 + 4, temp_a2, arg0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/halo/func_80800448_chlighthalo.s")

void func_80800630_chlighthalo(s32 arg0) 
{
}
OSThread *chlighthalo_entrypoint_0(void)
{
    extern u8 D_808006A8_chlighthalo[];

    return (OSThread *) D_808006A8_chlighthalo;
}
