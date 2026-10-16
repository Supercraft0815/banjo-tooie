#include "core2/1EAE6C0.h"

extern s32 D_8012B420;
s32 func_800D4DD0(s32 arg0) {
    if (D_8012B420 != 0) {
        switch (arg0) {
        case 10:
            arg0 = 1;
            break;
        case 4:
        case 11:
            arg0 = 0;
            break;
        }
    }
    return arg0;
}

/* extern */

void func_800D4E18(s32 arg0, s32 arg1) { s32 func_800D4E7C(s32); void func_800D4FB8(s32, s32); if (arg0 == 9) { arg0 = 1; } if (arg1 < 0) { func_800FC660(0x74U); } func_800D4FB8(arg0, func_800D4E7C(arg0) + arg1); }

s32 func_800D4E7C(s32 arg0) {
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

void func_800D4FB8(s32 arg0, s32 arg1) {
    s32 func_800D4DD0(s32);
    extern u8 D_8011B640[];
    s32 index;
    u8 *entry;
    if (arg0 == 9) {
        arg0 = 1;
    }
    index = func_800D4DD0(arg0);
    if (arg1 < 0) {
        entry = &D_8011B640[index * 3];
        arg1 = 0;
    } else {
        entry = &D_8011B640[index * 3];
        arg0 = entry[2];
        if (arg0 < arg1) {
            arg1 = arg0;
        }
    }
    entry[1] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAE6C0/func_800D5034.s")

void func_800D517C(void) {
    s32 _gcextra_entrypoint_0();
    s32 func_800D4EF4(s32);
    extern u8 D_8011B640[];
    u8 *entry;
    s32 extra;
    s32 i;
    s32 value;

    extra = _gcextra_entrypoint_0();
    D_8012B420 = 0;
    entry = D_8011B640;
    i = 0;
    do {
        value = func_800D4EF4(i);
        if (value != 0 && func_800D4F9C(i) != 0) {
            value += extra;
        }
        i++;
        entry += 3;
        entry[-1] = value;
        entry[-2] = value;
    } while (i != 0x14);
}

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
