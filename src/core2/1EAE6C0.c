#include "core2/1EAE6C0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D4DD0.s")

/* extern */

void func_800D4E18(s32 arg0, s32 arg1) { u8 func_800D4E7C(s32); s32 func_800D4FB8(s32, s32); if (arg0 == 9) { arg0 = 1; } if (arg1 < 0) { func_800FC660(0x74U); } func_800D4FB8(arg0, func_800D4E7C(arg0) + arg1); }

u8 func_800D4E7C(s32 arg0) {
    s32 func_800D4DD0(s32);
    extern u8 D_8011B641[];
    s32 index;

    if (arg0 == 9) {
        arg0 = 1;
    }
    index = func_800D4DD0(arg0);
    return D_8011B641[index * 3];
}

u8 func_800D4EB8(s32 arg0) {
    s32 func_800D4DD0(s32);
    extern u8 D_8011B642[];
    s32 index;

    if (arg0 == 9) {
        arg0 = 1;
    }
    index = func_800D4DD0(arg0);
    return D_8011B642[index * 3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D4EF4.s")

s32 func_800D4F9C(s32 arg0) {
    if (arg0 == 2) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D4FB8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D5034.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D517C.s")

u8 func_800D5210(s32 arg0) {
    extern u8 D_8011B640[];

    if (arg0 == 9) {
        arg0 = 1;
    }
    return D_8011B640[arg0 * 3];
}

void func_800D5234(s32 arg0) {
    extern s32 D_8012B420;
    *(s32 *)((u8 *)&D_8012B420 + 0) = arg0;
}

s32 func_800D5240(void) {
    extern s32 D_8012B420;
    return *(s32 *)((u8 *)&D_8012B420 + 0);
}
