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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A6EF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F6A0/func_800A6FF0.s")

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
