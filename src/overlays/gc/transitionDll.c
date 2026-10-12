#include "common.h"

void *func_80800000_gctransitionDll(s32 arg0) {
    extern u8 D_80800CB0_gctransitionDll[];
    u8 *p = D_80800CB0_gctransitionDll;
    while (*p != 0) {
        if (arg0 == *p) return p;
        p += 0x14;
    }
    return NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/func_8080004C_gctransitionDll.s")

/* extern */

void func_80800098_gctransitionDll(s32 *arg0, f32 *arg1) {
    f32 func_800A8AF0(s32);
    *arg1 *= func_800A8AF0(*arg0) * 0.75f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/func_808000D8_gctransitionDll.s")

void gctransitionDll_entrypoint_0(s32 *arg0, Gfx **arg1) {
    struct TransitionScale {
        u8 pad[0x18];
        f32 scale;
    };
    void func_8008B304(s32);
    s32 func_8008B4D4(void *);
    void func_800B99CC(Gfx **, s32, s32 *);
    s32 func_800D674C(s32);
    void func_800DE318(void);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF41C(s32);
    void func_800DF830(s32);
    void func_800E3BAC(f32 *);
    void func_800E3C30(f32 *);
    void func_800E3C8C(f32, f32);
    void func_800E3CE8(void);
    void func_800E41CC(void);
    void func_800E4208(void);
    void func_800E44FC(Gfx **);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    f32 func_800F1480(f32);
    extern s32 D_808010CC_gctransitionDll[];
    extern s32 D_808010D8_gctransitionDll[];
    extern f32 D_808010E4_gctransitionDll;
    extern f32 D_808010E8_gctransitionDll;
    f32 camera[3];
    f32 rotation[3];
    f32 fraction;
    f32 position[3];
    f32 scale;

    arg0[1]++;
    if (((u8 *)arg0)[0x1C] != 1) {
        func_800E41CC();
        if (arg0[0x2C / 4] != 0) {
            func_800EFA4C(camera, 0, 0, 350.0f);
        } else {
            func_800EFA4C(camera, 0, 0, 300.0f);
        }
        func_800EFD24(rotation);
        func_800E3C8C(D_808010E4_gctransitionDll, D_808010E8_gctransitionDll);
        func_800E3BAC(camera);
        func_800E3C30(rotation);
        func_800E3CE8();
        func_800E44FC(arg1);
        func_800EFD24(position);
        if (arg0[0x2C / 4] != 0) {
            gDPSetTextureFilter((*arg1)++, G_TF_POINT);
            gDPSetColorDither((*arg1)++, G_CD_DISABLE);
            func_8008B304(arg0[0x2C / 4]);
            func_800DF41C(func_8008B4D4((void *)arg0[0x2C / 4]));
        }
        func_800DF830(0);
        if (((u8 *)arg0)[0x1C] == 2 || ((u8 *)arg0)[0x1C] == 7) {
            func_800DE448(position, rotation, 1.0f, NULL, func_800D674C(arg0[0x20 / 4]));
            if (arg0[0x2C / 4] != 0) {
                gDPSetTextureFilter((*arg1)++, G_TF_BILERP);
                gDPSetColorDither((*arg1)++, G_CD_MAGICSQ);
            }
            func_800E4208();
            return;
        }
        fraction = ((f32 *)arg0)[0x28 / 4] / ((f32 *)arg0)[0xC / 4];
        if (((u8 *)arg0)[0x1C] == 5) {
            switch (((u8 *)arg0)[8]) {
                default:
                    rotation[2] = ((f32 *)arg0)[0x24 / 4] - 90.0f * fraction;
                    scale = ((f32 *)arg0)[0x18 / 4] * fraction + 0.1f;
                    break;
                case 16:
                    scale = ((f32 *)arg0)[0x18 / 4];
                    break;
                case 22:
                case 24:
                    rotation[2] = 0.0f;
                    scale = ((f32 *)arg0)[0x18 / 4] * fraction + 0.1f;
                    break;
            }
            func_80800098_gctransitionDll(arg0, &scale);
            func_800DE448(position, rotation, scale, NULL, func_800D674C(arg0[0x20 / 4]));
        } else if (((u8 *)arg0)[0x1C] == 6) {
            switch (((u8 *)arg0)[8]) {
                default:
                    rotation[2] = ((f32 *)arg0)[0x24 / 4] - 90.0f * fraction;
                    scale = (1.0f - fraction) * ((struct TransitionScale *)arg0)->scale + 0.1f;
                    break;
                case 17:
                    scale = ((f32 *)arg0)[0x18 / 4];
                    break;
                case 10:
                    rotation[2] = 0.0f;
                    scale = ((f32 *)arg0)[0x18 / 4] * (1.0f - func_800F1480(fraction)) + 0.1f;
                    break;
                case 23:
                case 25:
                    rotation[2] = 0.0f;
                    scale = (1.0f - fraction) * ((struct TransitionScale *)arg0)->scale + 0.1f;
                    break;
            }
            if (arg0[0x30 / 4] >= 3 || ((u8 *)arg0)[8] != 17) {
                func_80800098_gctransitionDll(arg0, &scale);
                func_800DE448(position, rotation, scale, NULL, func_800D674C(arg0[0x20 / 4]));
            } else {
                func_800DE318();
            }
        } else if (((u8 *)arg0)[0x1C] == 3) {
            func_800B99CC(arg1, (s32)((1.0f - fraction) * 255.0f + 0.5f), D_808010D8_gctransitionDll);
        } else if (((u8 *)arg0)[0x1C] == 4) {
            func_800B99CC(arg1, (s32)(fraction * 255.0f + 0.5f), D_808010D8_gctransitionDll);
        } else if (((u8 *)arg0)[0x1C] == 8) {
            if (fraction <= 0.5f) {
                fraction = 1.0f;
            } else {
                fraction = 1.0f - (fraction - 0.5f) / 0.5f;
            }
            func_800B99CC(arg1, (s32)(fraction * 255.0f + 0.5f), D_808010CC_gctransitionDll);
        } else if (((u8 *)arg0)[0x1C] == 9) {
            func_800B99CC(arg1, (s32)(fraction * 255.0f + 0.5f), D_808010CC_gctransitionDll);
        }
        if (arg0[0x2C / 4] != 0) {
            gDPSetTextureFilter((*arg1)++, G_TF_BILERP);
        }
        func_800E4208();
    }
}

/* extern */

void gctransitionDll_entrypoint_1(s32 arg0) {
    s32 func_800EA05C();
    void *func_80800000_gctransitionDll(s32);
    void *func_8080004C_gctransitionDll(s32);
    s32 func_808000D8_gctransitionDll(s32, u8, void *);
    void *temp_v0;

    temp_v0 = func_80800000_gctransitionDll((*(u8 *)((s8 *)(func_8080004C_gctransitionDll(func_800EA05C())) + (2))));
    func_808000D8_gctransitionDll(arg0, (*(u8 *)((s8 *)(temp_v0) + (1))), temp_v0);
}

s32 gctransitionDll_entrypoint_2(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x1C))) == 1;
}

s32 gctransitionDll_entrypoint_3(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x1C))) != 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_4.s")

void gctransitionDll_entrypoint_5(u8 *arg0) {
    s32 func_808000D8_gctransitionDll(s32, u8, void *);
    func_808000D8_gctransitionDll(arg0, 0x1, 0);
}

/* extern */

void gctransitionDll_entrypoint_6(s32 arg0) {
    s32 func_800EA05C();
    void *func_80800000_gctransitionDll(s32);
    void *func_8080004C_gctransitionDll(s32);
    s32 func_808000D8_gctransitionDll(s32, u8, void *);
    void *temp_v0;

    temp_v0 = func_80800000_gctransitionDll((*(u8 *)((s8 *)(func_8080004C_gctransitionDll(func_800EA05C())) + (3))));
    func_808000D8_gctransitionDll(arg0, (*(u8 *)((s8 *)(temp_v0) + (1))), temp_v0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_7.s")

void gctransitionDll_entrypoint_8(u8 *arg0, s32 arg1) {
    u32 func_800E6A00(void);
    s32 func_808000D8_gctransitionDll(s32, u8, void *);
    (*(s8 *)((s8 *)(arg0) + (8))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
    (*(s8 *)((s8 *)(arg0) + (0x1D))) = func_800E6A00();
    func_808000D8_gctransitionDll((s32) arg0, 1U, NULL);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/transitionDll/gctransitionDll_entrypoint_9.s")
