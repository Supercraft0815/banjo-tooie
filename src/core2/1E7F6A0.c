#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A5DB0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A69F0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A6B24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A6DAC.s")

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
