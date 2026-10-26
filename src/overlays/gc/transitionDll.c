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

void *func_8080004C_gctransitionDll(s32 arg0) {
    extern u16 D_8080105C_gctransitionDll[];
    u16 *p = D_8080105C_gctransitionDll;
    while (*p != 0) {
        if (arg0 == *p) return p;
        p += 2;
    }
    return p;
}

/* extern */

void func_80800098_gctransitionDll(s32 *arg0, f32 *arg1) {
    f32 func_800A8AF0(s32);
    *arg1 *= func_800A8AF0(*arg0) * 0.75f;
}

void func_808000D8_gctransitionDll(s32 address, s32 arg1, void *arg2) {
    typedef struct anctrl_s AnimCtrl;
    struct TransitionData {
        u8 kind;
        u8 pad[3];
        f32 duration;
        s32 asset;
        s32 animation;
        s32 unk10;
    };
    struct Transition {
        s32 unk0;
        s32 unk4;
        struct TransitionData data;
        u8 state;
        u8 pad1D[3];
        s32 asset;
        s32 unk24;
        f32 timer;
        AnimCtrl *control;
        s32 unk30;
    };
    int _gcaudiolist_entrypoint_0();
    AnimCtrl *func_8008AD80(s32);
    void anctrl_reset(AnimCtrl *);
    void anctrl_setIndex(AnimCtrl *, int);
    void anctrl_setDuration(AnimCtrl *, f32);
    void anctrl_setPlaybackType(AnimCtrl *, s32);
    void anctrl_start(AnimCtrl *);
    void func_8008B10C(AnimCtrl *, f32);
    void func_8008B188(AnimCtrl *, s32);
    void aligned4_memcpy(void *, void *, int);
    void func_8008ADBC(AnimCtrl *);
    void func_80090684(s32);
    void func_800C9214(void *);
    void func_800EA334(s32);
    void func_800FC6B0(u32);
    void func_800FCA90(u32);
    void func_800FC8EC();
    void func_800FCB54(s32, s32, s32, f32);
    u32 state = arg1;
    struct Transition *arg0 = (struct Transition *) address;

    if (arg0->control != NULL) {
        func_8008ADBC(arg0->control);
        arg0->control = NULL;
    }
    arg0->unk4 = 0;
    arg0->timer = 0.0f;
    if (arg2 != NULL) {
        aligned4_memcpy(&arg0->data, arg2, 0x14);
    } else {
        arg0->data.kind = 0;
    }
    if (state == 2) {
        arg0->asset = 0xB45;
    } else if (state == 7) {
        arg0->asset = 0xB46;
    } else if (arg2 != NULL) {
        if (((struct TransitionData *)arg2)->asset != 0) {
            arg0->asset = ((struct TransitionData *)arg2)->asset;
        }
    }
    if (arg2 != NULL && ((struct TransitionData *)arg2)->animation != 0) {
        arg0->control = func_8008AD80(0);
        anctrl_reset(arg0->control);
        anctrl_setIndex(arg0->control, ((struct TransitionData *)arg2)->animation);
        anctrl_setDuration(arg0->control, ((struct TransitionData *)arg2)->duration);
        anctrl_setPlaybackType(arg0->control, 1);
        if (state == 6) {
            func_8008B188(arg0->control, 0);
            func_80090684(1);
            func_800EA334(0);
        } else {
            osViBlack(1);
            func_8008B10C(arg0->control, 0.25f);
        }
        anctrl_start(arg0->control);
    }
    if (state == 5) {
        func_800FC6B0(0x1D);
        func_800FCB54(0x1D, 0, 1000, 0.4f);
        func_800FCA90(0x1D);
        func_800FC8EC(0x1D);
    } else if (state == 6) {
        if (arg0->data.kind == 10) {
            _gcaudiolist_entrypoint_0(1);
        } else {
            func_800FC6B0(0x1E);
            func_800FCB54(0x1E, 0, 1000, 0.2f);
            func_800FCA90(0x1E);
            func_800FC8EC(0x1E);
        }
    } else if (state == 1 && arg0->state != 0) {
        func_800C9214(arg0);
        return;
    }
    arg0->unk30 = 0;
    arg0->state = state;
}

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
    void func_808000D8_gctransitionDll(s32, s32, void *);
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

int gctransitionDll_entrypoint_4(void *arg0) {
    int state = *(u8 *)((s8 *)arg0 + 0x1C);

    return state == 4 ||
        (state == 2 && *(s32 *)((s8 *)arg0 + 4) < 2) ||
        state == 6 || state == 9 ||
        (state == 7 && *(s32 *)((s8 *)arg0 + 4) < 2);
}

void gctransitionDll_entrypoint_5(u8 *arg0) {
    void func_808000D8_gctransitionDll(s32, s32, void *);
    func_808000D8_gctransitionDll(arg0, 0x1, 0);
}

/* extern */

void gctransitionDll_entrypoint_6(s32 arg0) {
    s32 func_800EA05C();
    void *func_80800000_gctransitionDll(s32);
    void *func_8080004C_gctransitionDll(s32);
    void func_808000D8_gctransitionDll(s32, s32, void *);
    void *temp_v0;

    temp_v0 = func_80800000_gctransitionDll((*(u8 *)((s8 *)(func_8080004C_gctransitionDll(func_800EA05C())) + (3))));
    func_808000D8_gctransitionDll(arg0, (*(u8 *)((s8 *)(temp_v0) + (1))), temp_v0);
}

void gctransitionDll_entrypoint_7(s32 arg0, s32 arg1) {
    void func_808000D8_gctransitionDll(s32, s32, void *);
    extern s32 D_80800EA4_gctransitionDll;
    u8 *temp_a2;

    temp_a2 = (arg1 * 0x14) + (u8 *)&D_80800EA4_gctransitionDll;
    func_808000D8_gctransitionDll(arg0, (*(u8 *)((s8 *)(temp_a2) + (1))), temp_a2);
}

void gctransitionDll_entrypoint_8(u8 *arg0, s32 arg1) {
    u32 func_800E6A00(void);
    void func_808000D8_gctransitionDll(s32, s32, void *);
    (*(s8 *)((s8 *)(arg0) + (8))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0x20))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (0x1C))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
    (*(s8 *)((s8 *)(arg0) + (0x1D))) = func_800E6A00();
    func_808000D8_gctransitionDll((s32) arg0, 1U, NULL);
}

void gctransitionDll_entrypoint_9(u8 *arg0) {
    struct anctrl_s;
    f32 _glintrosyncDll_entrypoint_5(void);
    f32 func_800D8FF8(void);
    s32 func_8008ADE4(s32);
    void func_80090684(s32);
    s32 anctrl_isStopped(struct anctrl_s *);
    s32 func_800EA170(void);
    void func_800EA334(s32);
    void func_800EA34C(s32);
    void func_808000D8_gctransitionDll(s32, s32, void *);
    f32 delta;

    if (arg0[0x1D]) {
        delta = _glintrosyncDll_entrypoint_5();
    } else {
        delta = func_800D8FF8();
    }
    if (arg0[8]) {
        if (*(s32 *)(arg0 + 0x2C)) {
            func_8008ADE4(*(s32 *)(arg0 + 0x2C));
            if (arg0[0x1C] == 5) {
                switch (*(u32 *)(arg0 + 0x30)) {
                    case 0:
                    case 3:
                        break;
                    case 1:
                        func_80090684(1);
                        func_800EA334(0);
                        break;
                    case 2:
                        func_800EA34C(0);
                        break;
                    case 4:
                        osViBlack(0);
                        break;
                    default:
                        *(f32 *)(arg0 + 0x28) += delta;
                        break;
                }
            } else {
                switch (*(u32 *)(arg0 + 0x30)) {
                    case 0:
                    case 1:
                        break;
                    default:
                        *(f32 *)(arg0 + 0x28) += delta;
                        break;
                    case 2:
                        func_800EA34C(0);
                        break;
                }
            }
        } else {
            *(f32 *)(arg0 + 0x28) += delta;
        }
        if (*(f32 *)(arg0 + 0xC) < *(f32 *)(arg0 + 0x28) ||
            (*(struct anctrl_s **)(arg0 + 0x2C) && anctrl_isStopped(*(struct anctrl_s **)(arg0 + 0x2C)))) {
            *(f32 *)(arg0 + 0x28) = *(f32 *)(arg0 + 0xC);
            if (arg0[0x1C] == 5 || arg0[0x1C] == 6) {
                *(f32 *)(arg0 + 0x24) -= 90.0f;
                if (*(f32 *)(arg0 + 0x24) < -360.0f) {
                    *(f32 *)(arg0 + 0x24) += 360.0f;
                }
                if (*(f32 *)(arg0 + 0x24) > 360.0f) {
                    *(f32 *)(arg0 + 0x24) -= 360.0f;
                }
            }
            func_808000D8_gctransitionDll((s32)arg0, arg0[0xA], NULL);
            if (*(s32 *)(arg0 + 0x2C)) {
                func_800EA170();
            }
        }
        *(s32 *)(arg0 + 0x30) += 1;
    }
}
