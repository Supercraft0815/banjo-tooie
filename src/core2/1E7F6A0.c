#include "common.h"

void func_800A5DB0(Actor *arg0) {
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF830(s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F1988(f32 *, f32 *, f32 *);
    f32 func_800F554C(s32);
    void func_800F5680(s32, f32 *);
    extern f32 D_801255D0;
    f32 pad;
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp48;
    f32 sp44;
    f32 sp38[3];
    f32 sp34;

    func_800EE7F8(sp58, arg0->position);
    sp44 = ((f32 *)arg0->actorData)[3];
    sp34 = func_800F10B4(sp58[1] - sp44, 0.0f, 300.0f, 0.43f, D_801255D0);
    sp48 = func_800F554C(arg0->unk74_7) * (sp34 * arg0->unk58);
    sp58[1] = sp44;
    func_800F5680(arg0->unk74_7, sp38);
    func_800F1988(sp38, &arg0->rotation[0], &arg0->rotation[1]);
    sp4C[0] = arg0->rotation[0];
    sp4C[1] = arg0->rotation[1];
    sp4C[2] = 0.0;
    func_800EF334(sp38, 0.0f);
    func_800EE780(arg0->position, sp58, sp38);
    func_800DF830(3);
    func_800DE448(arg0->position, sp4C, sp48, NULL, func_800D674C(0x637));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A5EC4.s")

void func_800A61D4(void) {
    typedef struct { s32 color[4]; } Color;
    void func_800DF580(void *arg0, void *arg1);
    void func_800DF830(s32 arg0);
    extern Color D_8011A380;
    extern Color D_8011A390;
    Color sp28 = D_8011A380;
    Color sp18 = D_8011A390;
    func_800DF580(&sp28, &sp18);
    func_800DF830(3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A6250.s")

s32 func_800A69F0(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    s32 func_800A6250(Actor *, f32 *, f32 *, f32 *, s32);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF174(f32 *, f32 *, f32);
    void func_800F5680(s32, f32 *);
    f32 mlAbsF(f32);
    extern f32 D_801255DC;
    extern f32 D_801255E0;
    f32 sp3C[3];
    f32 sp38;
    f32 sp2C[3];

    func_800EE7F8(arg1, arg0->position);
    sp38 = *(f32 *)&arg0->actorData[3];
    if ((mlAbsF(arg1[1] - sp38) < D_801255DC) || (D_801255E0 < arg2[1])) {
        func_800F5680(arg0->unk74_7, sp3C);
        arg1[1] = sp38;
        func_800A6250(arg0, arg1, sp3C, arg2, arg3);
        goto block_6;
    }
    func_800EE7F8(sp2C, arg1);
    func_800EF174(arg1, arg2, -2000.0f);
    if (func_800C6A7C(sp2C, arg1, sp3C, 0x20020) == 0) {
        return 1;
    }
    func_800A6250(arg0, arg1, sp3C, arg2, arg3);
block_6:
    arg0->unk7C_12 = 1;
    return 1;
}

void func_800A6B24(Actor *arg0) {
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    void func_800C8800(s32, f32 *);
    void func_800C8898(s32, f32 *);
    u8 func_800C89A8(s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFD24(f32 *);
    f32 func_800F5BC4(s32, f32 *);
    f32 sqrtf(f32);
    s32 light;
    f32 radius;
    f32 spBC[3];
    f32 distance;
    f32 scale;
    f32 fade;
    f32 spA4[3];
    f32 sp98[3];
    f32 sp8C[3];
    s32 alpha;
    s32 count;

    if (!(arg0->position[1] - *(f32 *)&arg0->actorData[3] > 2000.0f)) {
    radius = func_800F5BC4(arg0->unk74_7, spBC);
    func_800EF04C(spBC, arg0->position);
    count = 0;
    for (light = func_800C8760(0, 1); light != 0 && count < 2; light = func_800C878C(light, 0, 1)) {
            alpha = 255;
            if (!(func_800C89A8(light) & 8)) {
                func_800C8800(light, sp98);
                func_800C8898(light, sp8C);
                func_800EFB24(spA4, sp98, spBC);
                distance = sqrtf(spA4[0] * spA4[0] + spA4[1] * spA4[1] + spA4[2] * spA4[2]);
                if (distance == 0.0f) {
                    continue;
                }
                if (sp8C[1] + radius <= distance) {
                    continue;
                }
                {
                    scale = -1.0f / distance;
                    distance -= radius;
                    spA4[0] = -(spA4[0] * scale);
                    spA4[2] = -(spA4[2] * scale);
                    spA4[1] *= -scale;
                    if (sp8C[0] < distance) {
                        fade = 1.0f - (distance - sp8C[0]) * sp8C[2];
                        alpha = (s32)(255.0f * fade);
                    }
                    func_800A69F0(arg0, sp98, spA4, alpha);
                    count++;
                }
            }

    }
    if (count == 0) {
        f32 sp78[3];
        f32 sp6C[3];
        func_800EFD24(sp78);
        func_800EFA4C(sp6C, 0, 1.0f, 0);
        func_800A69F0(arg0, sp78, sp6C, 255);
    }
    }
}

void func_800A6DAC(Actor *arg0, s32 arg1) {
    s32 _plsu_entrypoint_1(s32);
    s32 func_800F5410(s32);
    s32 func_800F55FC(s32);
    f32 func_800F5628(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    s32 func_800F65D0(s32);
    int func_800F6640(s32);
    s32 func_800F6E80(s32);
    s32 func_800F8B88(void);

    if (func_800F6438(arg0->unk74_7) &&
        func_800F6640(arg0->unk74_7) &&
        func_800F6E80(arg0->unk74_7) &&
        !(func_800F55FC(arg0->unk74_7) & 0x80000000) &&
        (func_800F65D0(arg0->unk74_7) ||
         (arg0->unk74_30 &&
          (func_800F8B88() < 2 ||
           (func_800F5410(arg0->unk74_7) == 0xB &&
            _plsu_entrypoint_1(0x11) != -1))))) {
        func_800F5A00(arg0->unk74_7, arg0->position);
        *(f32 *)&arg0->actorData[3] = func_800F5628(arg0->unk74_7);
        if (arg0->unk64_20) {
            func_800A5DB0(arg0);
            return;
        }
        func_800A6B24(arg0);
    }
}

void func_800A6EF4(Actor *arg0) {
    s32 func_800A946C(void);
    s32 func_800A9C98(void);
    u32 func_800A9CD0(void);
    u32 func_800BCC84(void);
    s32 func_800D3948(void);
    s32 func_800EA05C();
    void func_8010A800(Actor *, s32);
    extern s16 D_8011A2E0[];
    s32 i;
    s32 sp20;

    sp20 = func_800EA05C();
    func_8010A800(arg0, 5);
    arg0->unk74_29 = 0;
    arg0->unk58 = 1.0f;
    for (i = 0; D_8011A2E0[i] != -1; i++) {
        if (sp20 == D_8011A2E0[i]) {
            arg0->unk74_29 = 1;
            break;
        }
    }
    if (((func_800A9C98() != 0) && (func_800A9CD0() != 2)) || (func_800BCC84() != 0) || (func_800D3948() != 0) || (func_800A946C() >= 2)) {
        arg0->unk74_29 = 1;
    }
}

/* extern */

void func_800A6FF0(Actor *arg0) {
    f32 func_800F5628(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F8874(s32);
    func_800F5A00(arg0->unk74_7, arg0->position);
    *(f32 *)&arg0->actorData[3] = func_800F5628(arg0->unk74_7);
    arg0->unk64_20 = arg0->unk74_29;
    arg0->unk74_30 = func_800F8874(arg0->unk74_7);
}

/* extern */

void func_800A7088(void *arg0) {
    s32 func_800F7364(u32);
    func_800F7364((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7);
}

void func_800A70B0()
{
    func_800FFA88();
}

void func_800A70D0(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    struct Fields {
        u8 pad[0x76];
        u16 value : 9;
        u16 low : 7;
    };
    struct Fields *actor;

    actor = (struct Fields *)func_80106790(arg0);
    actor->value = arg1;
}

void func_800A7108(Unk80132ED0 *arg0, f32 arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    func_80106790(arg0)->unk58 = arg1;
}

void func_800A7130(Unk80132ED0 *arg0, s32 arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    struct Fields { u8 pad[0x65]; u8 other : 7; u8 bit : 1; } *actor;
    actor = (struct Fields *)func_80106790(arg0);
    actor->bit = arg1;
}

void * func_800A7168(void) {
    extern u8 D_8011A3A0;
    return &D_8011A3A0;
}
