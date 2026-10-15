#include "common.h"

typedef struct {
    s16 id;
    u8 size;
    u8 pad;
    s32 value;
} EntryData;

EntryData D_8011B560[4] = {
    {0x0C21, 8, 0, 0},
    {0x0C22, 16, 0, 0},
    {0x0C20, 16, 0, 0},
    {0x0C23, 6, 0, 0}
};

/* extern */

s32 func_800D2F20(void) {
    s32 func_800BDC5C();
    return func_800BDC5C() * 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D2F44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D3104.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D3524.s")

int func_800D3574(s32 arg0) {
    extern f32 D_80125B10;
    return (s32) ((f32) (u32) D_8011B560[arg0].size * D_80125B10);
}

u8 func_800D35BC(s32 arg0) {
    return D_8011B560[arg0].size;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAC810/func_800D35D0.s")

void func_800D36A8(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_8011B560[i].value = 0;
    }
}

/* extern */

int func_800D36C4(s32 arg0) {
    void *func_800B0D6C(void *, s32);
    s16 *func_800D3524(s32);
    s32 func_800D35D0();
    s32 pad;
    s32 sp18;
    s16 *temp_v0;

    sp18 = func_800D35D0();
    temp_v0 = func_800D3524(arg0);
    if ((sp18 < 0) || (temp_v0 == 0)) {
        return func_800D3574(arg0);
    }
    return (*(u8 *)((s8 *)(func_800B0D6C(temp_v0, sp18)) + (2)));
}

s32 func_800D3724(s32 arg0) {
    s32 func_800D6C34(s16);
    s32 var_v1;
    u8 *temp_v0;

    temp_v0 = (u8 *)D_8011B560 + arg0 * 8;
    if ((*(s32 *)((s8 *)temp_v0 + 4)) != 0) {
        var_v1 = func_800D6C34(*(s16 *)(temp_v0 + 0));
    } else {
        var_v1 = 1;
    }
    return var_v1;
}
