#include "common.h"

/* extern */

void func_80800000_chpiranha(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    void func_800DA3B8(s32, s32);
    func_80100074(arg0, 0U, 0U);
    arg0->unk3C = NULL;
    func_800DA3B8(0x6A8, 0);
}

void func_8080003C_chpiranha(Actor *arg0, u32 arg1) {
    typedef struct {
        u8 pad[0x8];
        s16 unk8;
        s16 unkA;
    } ImageStruct;
    ImageStruct *func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    s32 func_800DF350(void);
    void func_800DF410(s32);
    void func_800DF830(s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    s32 func_800EFA4C(s32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    u8 *func_801039E4(Unk80132ED0 *);
    struct PiranhaFish {
        f32 position[3];
        f32 unkC[7];
        f32 yaw;
        f32 unk2C;
    };
    struct PiranhaState {
        u8 unk0;
        u8 unk1;
        u8 previousState;
        u8 unk3;
        f32 position[3];
        f32 unk10[2];
        s32 unk18;
        struct PiranhaFish fish[1];
    };
    u8 *model;
    ImageStruct *image;
    s32 i;
    f32 position[3];
    f32 rotationStorage[3];
    f32 *rotation;
    struct PiranhaState *state;
    struct PiranhaFish *fish;

    state = func_80100094(arg0, 0);
    model = func_801039E4(arg0->unk0);
    rotation = rotationStorage;
    for (i = 0, fish = state->fish; i < arg0->unk6C_0; i++, fish++) {
        func_800EFA4C(rotation, 0, fish->yaw - 90.0f, 0.0f);
        func_800EE780(position, arg0->position, fish->position);
        func_800DF830(2);
        func_800DF410(0xFF);
        func_800DE448(position, rotation, 0.075f, NULL, (s32)model);
        state->unk1 |= func_800DF350();
        if (i < 10) {
            image = func_800D674C(0x637);
            if (image != NULL) {
                position[1] = state->unk10[0] + 6.0f;
                func_800DF410(0xC0);
                func_800DF830(2);
                func_800DE448(position, rotation, 0.1f, NULL, (s32)image);
                state->unk1 |= func_800DF350();
            }
        }
    }
}

void func_80800218_chpiranha(Actor *arg0, u32 arg1) { if (arg0->unk70_10 == 7) { arg0->unk64_16 = 1; } func_80101FDC(arg0, arg1); if (arg1 == 7) { arg0->unk64_16 = 0; } }

void func_80800280_chpiranha(void *arg0) {
    *(u16 *)((u8 *)arg0 + 0x6E) = (*(u16 *)((u8 *)arg0 + 0x6E) & 0xFE00) | (((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) & 0x1FF);
}

void func_808002A0_chpiranha(Actor *arg0) {
    void func_8008FE94(s32, f32 *);
    f32 func_80090010(void);
    void func_80090434(s32);
    s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, s32);
    s32 func_800C2FDC(u8);
    f32 func_800D8FF8(void);
    void func_800DA3B8(s32, s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 func_800EFC7C(void *, void *);
    void func_800EFCD8(f32 *, f32, f32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010C9B0(f32 *, s32);
    s32 func_8010D284(void);
    f32 func_80800CAC_chpiranha(void);
    void func_80800EFC_chpiranha(Actor *, void *, f32);
    void func_80801250_chpiranha(u8 *, u8 *, u8 *, f32, f32, u8 *, f32 *);
    void func_80801420_chpiranha(Actor *);
    void func_80801508_chpiranha(s32);
    void func_8080154C_chpiranha(Actor *);
    s32 func_80801638_chpiranha(Actor *);
    void func_80801690_chpiranha(s32, s32);
    struct PiranhaState {
        u8 unk0;
        u8 unk1;
        u8 previousState;
        u8 unk3;
        f32 position[3];
        f32 unk10[2];
        s32 unk18;
        struct {
            f32 position[3];
            f32 unkC[9];
        } fish[1];
    };
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    f32 sp80[3];
    struct PiranhaState *sp7C;
    f32 sp70[3];
    f32 sp6C;
    f32 sp68;
    s32 pad60[2];
    Actor *sp5C;
    f32 sp50[3];
    f32 sp44[3];

    sp7C = func_80100094(arg0, 0);
    sp6C = func_800D8FF8();
    if (!func_8010C9B0(arg0->position, 1500)) {
        if (arg0->unk5F != 0) {
            func_800C2FDC(arg0->unk5F);
            arg0->unk5F = 0;
            func_800DA3B8(0x6A8, 0);
        }
    }
    if (arg0->unk3C != NULL && (arg0->unk3C->unk24 >> 22) == 0x22F) {
        func_800EE7F8(sp7C->position, func_80106790(arg0->unk3C)->position);
        sp7C->position[1] += 250.0f;
    }
    func_800EE7F8(sp98, arg0->position);
    func_800EFA20(sp8C, &arg0->actorData[4], sp6C);
    func_800EF04C(sp8C, arg0->position);
    if (func_800BF0E0(sp98, sp8C, 75.0f, sp80, 3, 0)) {
        func_800EF2A0(sp80);
        func_800EFA20(&arg0->actorData[4], sp80,
                      func_800EEAA4((f32 *)&arg0->actorData[4], sp80) * -1.5f);
        func_800EFA20(arg0->actorData, sp80, 37.5f);
        func_800EF04C((f32 *)arg0->actorData, arg0->position);
        if (arg0->unk70_10 != 6) {
            sp7C->previousState = arg0->unk70_10;
            func_80800218_chpiranha(arg0, 6);
        }
    }
    func_80801250_chpiranha((u8 *)arg0->actorData, (u8 *)arg0->position,
                          (u8 *)&arg0->actorData[4], *(f32 *)&arg0->actorData[3],
                          100.0f, NULL, spA4);
    func_8008FE94(5, sp70);
    sp68 = func_800EFC7C(arg0->position, arg0->actorData);
    switch (arg0->unk70_10) {
        case 7:
            if (arg0->unk3C != NULL) {
                sp5C = func_80106790(arg0->unk3C);
                if ((arg0->unk3C->unk24 >> 22) == 0x22F) {
                    func_800EE7F8((f32 *)arg0->actorData, sp7C->position);
                    func_800EE7F8(arg0->position, sp7C->position);
                }
                if (sp5C->unk70_10 == 2) {
                    sp7C->position[1] += 150.0f;
                    func_80800EFC_chpiranha(arg0, sp7C->position, 100.0f);
                    func_80800218_chpiranha(arg0, 2);
                    arg0->unk3C = NULL;
                    arg0->unk58 = 0.0f;
                }
            } else {
                sp7C->position[1] += 150.0f;
                func_80800218_chpiranha(arg0, 3);
            }
            break;
        case 1:
            if (func_80801638_chpiranha(arg0)) {
                func_80800218_chpiranha(arg0, 2);
            }
            if (arg0->unk3C != NULL) {
                if ((arg0->unk3C->unk24 >> 22) == 0x22F) {
                    func_800EE7F8((f32 *)arg0->actorData, sp7C->position);
                    func_800EE7F8(arg0->position, sp7C->position);
                }
            }
            if (sp68 < 2500.0f) {
                func_80800EFC_chpiranha(arg0, sp7C->position, 100.0f);
            }
            break;
        case 2:
            if (sp68 < 2500.0f) {
                func_80800EFC_chpiranha(arg0, sp7C->position, 100.0f);
            }
            func_80801508_chpiranha((s32)arg0);
            break;
        case 3:
            func_800EE7F8((f32 *)arg0->actorData, sp70);
            ((f32 *)arg0->actorData)[1] += 50.0f;
            if ((arg0->unk0->unk24 >> 22) == 0x2C2) {
                arg0->unk58 += sp6C;
                if (sp68 < 2500.0f && arg0->unk58 > 0.5f &&
                    (f32)arg0->unk6C_0 > 0.0f && func_8010D284() != 3 &&
                    func_80800CAC_chpiranha() > 5000.0f) {
                    func_80090434(13);
                    arg0->unk58 -= 0.5f;
                }
                if (sp68 > 2500.0f) {
                    sp50[1] = 0.0f;
                    func_800EFCD8(sp50, func_80090010(), 100.0f);
                    func_800EF04C((f32 *)arg0->actorData, sp50);
                    if (((f32 *)arg0->actorData)[3] < 250.0f) {
                        ((f32 *)arg0->actorData)[3] *= 1.1f;
                    }
                }
                if (sp68 > 7500.0f) {
                    if (((f32 *)arg0->actorData)[3] < 250.0f) {
                        ((f32 *)arg0->actorData)[3] *= 1.1f;
                    } else if (((f32 *)arg0->actorData)[3] > 100.0f) {
                        ((f32 *)arg0->actorData)[3] *= 0.9f;
                    }
                }
                if (sp68 < 2750.0f) {
                    func_80800EFC_chpiranha(arg0, sp70, 50.0f);
                    func_80800218_chpiranha(arg0, 4);
                }
            } else {
                if (((f32 *)arg0->actorData)[3] < 100.0f) {
                    ((f32 *)arg0->actorData)[3] += 5.0f;
                } else if (((f32 *)arg0->actorData)[3] > 100.0f) {
                    ((f32 *)arg0->actorData)[3] -= 5.0f;
                }
                if (sp68 < 2500.0f) {
                    func_80800EFC_chpiranha(arg0, sp70, 50.0f);
                    func_80800218_chpiranha(arg0, 4);
                }
            }
            func_8080154C_chpiranha(arg0);
            break;
        case 4:
            sp70[1] += 50.0f;
            arg0->unk58 += sp6C;
            if ((arg0->unk0->unk24 >> 22) == 0x2C2) {
                if (arg0->unk58 > 0.5f && (f32)arg0->unk6C_0 > 0.0f &&
                    func_8010D284() != 3 && func_80800CAC_chpiranha() > 5000.0f) {
                    func_80090434(13);
                    arg0->unk58 -= 0.5f;
                }
            } else {
                if (arg0->unk58 > 0.5f && (f32)arg0->unk6C_0 > 0.0f &&
                    func_8010D284() != 3) {
                    func_80090434(13);
                    arg0->unk58 -= 0.5f;
                }
            }
            if (arg0->unk58 > 0.2f && func_8010D284() == 3) {
                if (arg0->unk6C_0-- > 0) {
                    func_800EE780(sp44, sp7C->fish[arg0->unk6C_0].position, arg0->position);
                    func_80801690_chpiranha((s32)arg0, (s32)sp44);
                    arg0->unk58 -= 0.2f;
                }
            }
            if (arg0->unk6C_0 == 0) {
                func_800FFA88(arg0->unk0);
            }
            if (sp68 < 2500.0f) {
                func_80800EFC_chpiranha(arg0, sp70, 50.0f);
            }
            if (sp68 > 2500.0f || func_80800CAC_chpiranha() > 0.0f) {
                func_80800218_chpiranha(arg0, 3);
            } else {
                func_8080154C_chpiranha(arg0);
            }
            break;
        case 5:
            func_800EE7F8((f32 *)arg0->actorData, sp7C->position);
            if ((arg0->unk0->unk24 >> 22) != 0x2C2) {
                if (sp68 < 2500.0f) {
                    func_80800218_chpiranha(arg0, 2);
                }
                func_80801508_chpiranha((s32)arg0);
            } else {
                if (func_80800CAC_chpiranha() > 7500.0f && sp68 < 2500.0f) {
                    func_80800218_chpiranha(arg0, 2);
                }
            }
            break;
        case 6:
            if (sp68 < 2500.0f) {
                func_80800218_chpiranha(arg0, sp7C->previousState);
            }
            break;
    }
    if (sp7C->unk1 && arg0->unk70_10 != 7) {
        func_80801420_chpiranha(arg0);
    }
    sp7C->unk1 = 0;
}

f32 func_80800CAC_chpiranha(void) {
    void func_8008FFBC(s32);
    f32 sp1C[3];
    f32 result;

    func_8008FFBC((s32)sp1C);
    result = sp1C[1];
    result = sp1C[0] * sp1C[0] + result * result + sp1C[2] * sp1C[2];
    return result;
}

/* extern */

void func_80800CEC_chpiranha(void *arg0, void *arg1, f32 arg2, f32 *arg3, f32 arg4, f32 arg5) {
    f32 func_800DC178(f32, f32);
    s32 func_800EFA4C(s32, f32, f32, f32);
    f32 func_800EFC7C(void *, void *);
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    s32 var_s0;

    var_s0 = 0;
    temp_f22 = -arg2;
loop_1:
    temp_f24 = func_800DC178(temp_f22, arg2);
    temp_f26 = func_800DC178(temp_f22, arg2);
    func_800EFA4C(arg1, temp_f24, temp_f26, func_800DC178(temp_f22, arg2));
    var_s0 += 1;
    if (var_s0 < 0xA) {
        if (func_800EFC7C(arg0, arg1) < (arg2 * arg2)) {
            goto loop_1;
        }
    }
    *arg3 = func_800DC178(arg4, arg5);
}

s32 func_80800DD0_chpiranha(Actor *arg0, u8 *arg1) {
    if (arg0->unk70_10 != 7) {
        func_80800CEC_chpiranha((s32)arg1, (s32)(arg1 + 0x18),
            arg0->unk70_10 == 4 ? (arg0->unk0->unk24 >> 22 == 0x2C2 ? 150.0f : 50.0f) : (arg0->unk70_10 == 3 ? 100.0f : 150.0f),
            (f32 *)(arg1 + 0x2C), arg0->unk70_10 == 1 ? 20.0f : 40.0f,
            arg0->unk70_10 == 1 ? 40.0f : 80.0f);
    } else {
        func_80800CEC_chpiranha((s32)arg1, (s32)(arg1 + 0x18), 5.0f,
            (f32 *)(arg1 + 0x2C), 5.0f, 5.0f);
    }
}

void func_80800EFC_chpiranha(Actor *arg0, void *arg1, f32 arg2) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp3C[3];
    f32 min, max;
    u32 state;
    const u32 five = 5;
    void *sp28;

    func_800EFB24(sp3C, arg0->position, arg1);
    state = arg0->unk70_10;
    if (state != 7) {
        if (arg0->unk0->unk24 >> 22 != 0x2C2) {
            min = five == state ? 20.0f : 25.0f;
            max = five == state ? 20.0f : 30.0f;
            func_80800CEC_chpiranha(sp3C, sp28 = arg0->actorData, arg2, (f32 *)&arg0->actorData[3], min, max);
        } else {
            min = five == state ? 20.0f : 25.0f;
            max = five == state ? 20.0f : 30.0f;
            func_80800CEC_chpiranha(sp3C, sp28 = arg0->actorData, arg2, (f32 *)&arg0->actorData[3], min, max);
        }
    } else {
        func_80800CEC_chpiranha(sp3C, sp28 = arg0->actorData, 5.0f, (f32 *)&arg0->actorData[3], 5.0f, 5.0f);
    }
    func_800EF04C(*(void **)&sp28, arg1);
}

void func_8080106C_chpiranha(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    s32 func_800EFA4C(s32, f32, f32, f32);
    void func_800EFD24(f32 *);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    s32 pad;
    u8 *sp58;
    f32 temp_f20;
    f32 temp_f22;
    u8 *temp_v0;
    u32 var_s1;
    u8 *var_s0;

    func_80100074(arg0, 0, arg0->unk6C_0 * 0x30 + 0x1C);
    temp_v0 = func_80100094(arg0, 0);
    sp58 = temp_v0;
    var_s1 = 0;
    var_s0 = temp_v0 + 0x1C;
    if (arg0->unk6C_0) {
        do {
            if (arg0->unk0->unk24 >> 22 == 0x2C1) {
                temp_f20 = func_800DC178(-150.0f, 150.0f);
                temp_f22 = func_800DC178(-150.0f, 150.0f);
                func_800EFA4C((f32 *)var_s0, temp_f20, temp_f22, func_800DC178(-150.0f, 150.0f));
            } else {
                func_800EFA4C((f32 *)var_s0, 0.0f, -50.0f, 0.0f);
            }
            func_800EFD24((f32 *)(var_s0 + 0xC));
            func_800EFD24((f32 *)(var_s0 + 0x24));
            func_80800DD0_chpiranha(arg0, var_s0);
            var_s1++;
            var_s0 += 0x30;
        } while (var_s1 < arg0->unk6C_0);
    }
    func_800EFA4C((f32 *)&arg0->actorData[4], 0.0f, 1.0f, 0.0f);
    func_80800EFC_chpiranha(arg0, sp58 + 4, 100.0f);
}

void func_80801210_chpiranha(f32 *arg0, f32 arg1, f32 arg2) {
    void func_800EF334(f32 vec[3], f32 scale);
    if (arg1 != 0.0f) {
        func_800EF334(arg0, arg2 / arg1);
    }
}

void func_80801250_chpiranha(u8 *arg0, u8 *arg1, u8 *arg2, f32 arg3, f32 arg4, u8 *arg5, f32 *arg6) {
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 speed = arg3;
    f32 length;
    f32 zero[3];
    f32 dt;

    dt = func_800D8FF8();
    func_800EFB24(arg6, arg0, arg1);
    length = func_800EEF94(arg6);
    if (length < 2.0f * arg4) {
        func_80801210_chpiranha(arg6, length, 8.0f * speed);
    } else {
        func_80801210_chpiranha(arg6, length, 2.0f * speed);
    }
    ((f32 *)arg1)[0] += ((f32 *)arg2)[0] * dt + arg6[0] * dt * dt;
    ((f32 *)arg1)[1] += ((f32 *)arg2)[1] * dt + arg6[1] * dt * dt;
    ((f32 *)arg1)[2] += ((f32 *)arg2)[2] * dt + arg6[2] * dt * dt;
    ((f32 *)arg2)[0] += arg6[0] * dt;
    ((f32 *)arg2)[1] += arg6[1] * dt;
    ((f32 *)arg2)[2] += arg6[2] * dt;
    length = func_800EEF94((f32 *)arg2);
    if (speed < length) {
        func_80801210_chpiranha((f32 *)arg2, length, speed);
    }
    if (arg5 != NULL) {
        func_800EFD24(zero);
        func_800F18FC((f32 *)arg2, zero, (f32 *)arg5);
    }
}

/* extern */

void func_80801420_chpiranha(Actor *arg0) {
    f32 func_800EFC7C(void *, void *);
    void *func_80100094(Actor *, u32);
    s32 func_80800DD0_chpiranha(Actor *, u8 *);
    void func_80801250_chpiranha(u8 *, u8 *, u8 *, f32, f32, u8 *, f32 *);
    u32 var_s2;
    u8 *temp_s1;
    u8 *var_s0;
    f32 sp58[3];

    var_s0 = func_80100094(arg0, 0);
    var_s2 = 0;
    var_s0 += 0x1C;
    for (; var_s2 < arg0->unk6C_0; var_s2++) {
            temp_s1 = var_s0 + 0x18;
            func_80801250_chpiranha(temp_s1, var_s0, var_s0 + 0xC, (*(f32 *)((s8 *)(var_s0) + (0x2C))), 150.0f, var_s0 + 0x24, sp58);
            if (func_800EFC7C(var_s0, temp_s1) < 2500.0f) {
                func_80800DD0_chpiranha(arg0, var_s0);
            }
            var_s0 += 0x30;
    }
}

/* extern */

void func_80801508_chpiranha(s32 arg0) {
    s32 func_8010C500();
    s32 func_8010C9B0(f32 *, s32);
    void func_80800218_chpiranha(Actor *, u32);
    if ((func_8010C500() != 0) && (func_8010C9B0(arg0 + 4, 0x384) != 0)) {
        func_80800218_chpiranha(arg0, 3);
    }
}

void func_8080154C_chpiranha(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    void func_80800EFC_chpiranha(Actor *, void *, f32);
    s32 var_s1;

    var_s1 = 0;
    if (func_8010C500(arg0) == 0) {
        var_s1 = 1;
    }
    if ((arg0->unk0->unk24 >> 22) != 0x2C2) {
        if (func_8010C9B0(arg0->position, 0x384) == 0) {
            var_s1 = 1;
        }
    } else if ((func_80800CAC_chpiranha() < 2500.0f) &&
               ((f32)func_800DC128(0x19, 0x4B) < arg0->unk58)) {
        var_s1 = 1;
        arg0->unk58 = 0.0f;
    }
    if (var_s1 != 0) {
        func_80800218_chpiranha(arg0, 5U);
        func_80800EFC_chpiranha(arg0, (u8 *)func_80100094(arg0, 0) + 4, 100.0f);
    }
}

s32 func_80801638_chpiranha(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    return arg0->unk3C != NULL ?
        ((u32)*(u16 *)((s8 *)arg0->unk3C + 0x12) >> 1) != *(s32 *)((s8 *)func_80100094(arg0, 0U) + 0x18) : 1;
}

void func_80801690_chpiranha(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80801B10_chpiranha;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80801B10_chpiranha);
}

/* extern */

s32 *func_808016D0_chpiranha(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, f32 *);
    s32 pad;
    s32 *sp28;
    f32 sp24;
    f32 sp20;
    s32 *temp_v0;

    sp28 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), 0x211, -1, &sp24);
    temp_v0 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), 0x199, -1, &sp20);
    if ((temp_v0 != NULL) && (sp28 == NULL)) {
        sp28 = temp_v0;
    }
    if ((temp_v0 != NULL) && (sp28 != NULL) && ((sp20 < sp24) || (sp24 > 500.0f))) {
        sp28 = temp_v0;
        sp24 = sp20;
    }
    temp_v0 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), 0x19A, -1, &sp20);
    if ((temp_v0 != NULL) && (sp28 == NULL)) {
        sp28 = temp_v0;
    }
    if ((temp_v0 != NULL) && (sp28 != NULL) && ((sp20 < sp24) || (sp24 > 500.0f))) {
        sp28 = temp_v0;
        sp24 = sp20;
    }
    if (sp28 != NULL) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) *sp28;
    } else {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = 0;
    }
    if (sp24 > 500.0f) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = 0;
    }
    return sp28;
}

s32 func_8080182C_chpiranha(Actor *arg0, s32 arg1, s32 arg2) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    s32 func_800DA298(s32 index);
    void func_800DA3B8(s32 index, s32 set);
    s32 func_800DB9B0(void);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void *func_80100094(Actor *, u32);
    struct PiranhaState {
        u8 unk0;
        u8 unk1;
        u8 previousState;
        u8 unk3;
        f32 position[3];
        f32 floorY;
        f32 unk14;
        s32 unk18;
    };
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    struct PiranhaState *state;
    void *scratch;

    if (arg1 == 0x95) {
        func_8080106C_chpiranha(arg0);
        state = func_80100094(arg0, 0);
        scratch = func_808016D0_chpiranha((u8 *)arg0);
        state->floorY = arg0->position[1];
        if (arg0->unk3C != NULL) {
            scratch = ((Actor *)scratch)->position;
        } else {
            scratch = arg0->position;
        }
        func_800EE7F8(state->position, scratch);
        if ((arg0->unk0->unk24 >> 22) == 0x2C1) {
            state->position[1] += 250.0f;
        } else {
            state->position[1] += 100.0f;
        }
        func_800EE7F8(arg0->position, state->position);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        func_800EE7F8(start, arg0->position);
        func_800EE7F8(end, arg0->position);
        start[1] += 50.0f;
        end[1] -= 500.0f;
        if (func_800BEF00(start, end, normal, arg0->unk14)) {
            state->floorY = end[1];
        }
        if (arg0->unk3C != NULL) {
            state->unk18 = (u32)*(u16 *)((s8 *)arg0->unk3C + 0x12) >> 1;
        } else {
            state->unk18 = 0;
        }
        state->unk1 = 1;
        if (arg0->unk3C != NULL) {
            func_800DA3B8(0x34, 1);
        }
        if ((arg0->unk0->unk24 >> 22) == 0x2C1) {
            func_80800218_chpiranha(arg0, arg0->unk3C != NULL ? 1 : 2);
        } else {
            func_80800218_chpiranha(arg0, arg0->unk3C != NULL ? 7 : 2);
        }
        arg0->unk58 = 0.0f;
        arg0->unk64_20 = func_800DB9B0() | func_800DA298(0x650);
    } else {
        return 0;
    }
    return 1;
}

OSThread *chpiranha_entrypoint_0(void)
{
    extern u8 D_80801B60_chpiranha[];

    return (OSThread *) D_80801B60_chpiranha;
}

OSThread *chpiranha_entrypoint_1(void)
{
    extern u8 D_80801BA8_chpiranha[];

    return (OSThread *) D_80801BA8_chpiranha;
}

OSThread *chpiranha_entrypoint_2(void)
{
    extern u8 D_80801BF0_chpiranha[];

    return (OSThread *) D_80801BF0_chpiranha;
}
