#include "core2/1EAF950.h"
typedef struct {
    s16 id;
    u8 size;
    u8 pad;
    s16 *font;
} FontCacheEntry;

FontCacheEntry D_8011B560[4] = {
    {0x0C21, 8, 0, 0},
    {0x0C22, 16, 0, 0},
    {0x0C20, 16, 0, 0},
    {0x0C23, 6, 0, 0}
};
u8 D_8011B580[] BT_DATA(1, code_entry_alphabet, 0) = "0123456789:ABCDEFGHIJKLMNOPQRSTUVWXYZ@%?()<>\".;-!/'";

void func_800D34A0(void) {
    s32 func_800E7188(u8 *);
    extern u8 D_8011B580[];
    extern s8 D_8012B370[];
    s32 temp_v0;
    s32 var_a1;
    int var_a0;

    temp_v0 = func_800E7188(D_8011B580);
    for (var_a1 = 0; var_a1 < 0x80; var_a1++) {
        for (var_a0 = 0; var_a0 < temp_v0; var_a0++) {
            if (var_a1 == D_8011B580[var_a0]) {
                D_8012B370[var_a1] = var_a0;
                break;
            }
        }
        if (var_a0 == temp_v0) {
            D_8012B370[var_a1] = -1;
        }
    }
}

s16 *func_800D3524(s32 arg0) {


    if (D_8011B560[arg0].font == 0) {
        D_8011B560[arg0].font = (s16 *)func_800D674C(D_8011B560[arg0].id);
    }
    return D_8011B560[arg0].font;
}

int func_800D3574(s32 arg0) {

    return (s32) ((f32) (u32) D_8011B560[arg0].size * 0.8f);
}

u8 func_800D35BC(s32 arg0) {
    return D_8011B560[arg0].size;
}

s32 func_800D35D0(s32 arg0, s32 arg1) {
    extern s8 D_8012B370[];
    s32 temp;

    if ((arg0 != 2) && (arg0 != 0) && (arg1 >= 0x61) && (arg1 < 0x7B)) {
        arg1 -= 0x20;
    }
    switch (arg0) {
        case 0:
            if ((arg1 >= 0x21) && (arg1 < 0x7B)) {
                return arg1 - 0x21;
            }
            break;
        case 1:
            if (arg1 < 0x80) {
                temp = D_8012B370[arg1];
                if (temp >= 0) {
                    return temp;
                }
            }
            break;
        case 2:
            if ((arg1 > 0) && (arg1 < 0xFD)) {
                return arg1;
            }
            break;
        case 3:
            if ((arg1 >= 0x30) && (arg1 < 0x3B)) {
                return arg1 - 0x30;
            }
            return 0xB;
    }
    return -1;
}

void func_800D36A8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8011B560[i].font = 0;
    }
}

/* extern */

int func_800D36C4(s32 arg0, s32 arg1) {
    void *func_800B0D6C(void *, s32);
    s16 *func_800D3524(s32);
    s32 func_800D35D0(s32, s32);
    s32 pad;
    s32 sp18;
    s16 *temp_v0;

    sp18 = func_800D35D0(arg0, arg1);
    temp_v0 = func_800D3524(arg0);
    if ((sp18 < 0) || (temp_v0 == 0)) {
        return func_800D3574(arg0);
    }
    return (*(u8 *)((s8 *)(func_800B0D6C(temp_v0, sp18)) + (2)));
}

s32 func_800D3724(s32 arg0) {
    s32 func_800D6C34(s32 arg0);
    s32 var_v1;
    FontCacheEntry *temp_v0;

    temp_v0 = &D_8011B560[arg0];
    if (temp_v0->font != 0) {
        var_v1 = func_800D6C34(temp_v0->id);
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s8 D_8012B370 [ 128 ] BT_DATA(4, bss_core2bss1_2, 0xE0);
#endif
