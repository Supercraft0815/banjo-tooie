#include "common.h"

typedef struct {
    s16 current;
    u8 flag;
    u8 active;
    s16 values[8];
} ProgressData;
ProgressData D_80127780;

void func_800A9EC0(s32 arg0) {
    extern s32 D_80127770;
    extern s16 D_8011A480[][2];
    extern s16 D_8011A498[][2];
    s32 i;

    D_80127770 = 0x3E800;
    i = 0;
loop_1:
    if (arg0 == D_8011A480[i][0]) {
        D_80127770 = D_8011A480[i][1] << 10;
        return;
    }
    i++;
    if (D_8011A498 != &D_8011A480[i]) {
        goto loop_1;
    }
}

s32 func_800A9F14(s32 arg0) {
    if (arg0 == 2) {
        return 3;
    }
    return 0x12;
}

s32 func_800A9F30(void) {
    s32 func_8001BDAC(s32 *, s32);
    extern s32 D_80127770;
    s32 sp1C;

    func_8001BDAC(&sp1C, 1);
    return D_80127770 < sp1C;
}

void func_800A9F60(s32 arg0, s32 arg1) {
    void func_800DA3B8(s32, s32);
    func_800DA3B8(arg0 + 0xD1B, arg1);
}

/* extern */

s32 func_800A9F80(s32 arg0) {
    s32 func_800DA298(s32);
    return func_800DA298(arg0 + 0xD1B);
}

s32 func_800A9FA0(s32 arg0) {
    s32 var_s0;
    s32 var_s1;
    s32 difference;
    var_s0 = 0;
    var_s1 = 0x40;
    do {
        if (func_800A9F80(var_s1)) {
            difference = var_s0 ^ arg0;
            var_s0++;
            if (difference == 0) break;
        }
        var_s1++;
    } while (var_s1 != 0x4E);
    return var_s1;
}

void func_800AA00C(void) {
    s32 i;
    s32 j;

    D_80127780.current = -1;
    D_80127780.active = 0;
    D_80127780.flag = 0;
    for (i = 0; i < 4; i++) {
        D_80127780.values[i] = 0;
    }
    for (j = 4; j < 8; j++) { D_80127780.values[j] = 0; }
}

void func_800AA054(s32 arg0)
{
    func_800A9F60(arg0,1);
}

void func_800AA074(void) {
    s32 var_s0;

    var_s0 = 0x40;
    do {
        func_800A9F60(var_s0, 0);
        var_s0 += 1;
    } while (var_s0 != 0x4E);
}

u32 func_800AA0B8(void) {
    return *(u8 *)((u8 *)&D_80127780.active + 0);
}

s32 func_800AA0C4(void) {
    return *(s16 *)((u8 *)&D_80127780 + 0);
}

s32 func_800AA0D0(void) {
    int i;
    int sum = 0;
    for (i = 0x40; i < 0x4E; i++) {
        sum += func_800A9F80(i);
    }
    return sum;
}

s32 func_800AA120(void) { s32 func_800A9FA0(s32); return func_800A9FA0(D_80127780.current + 1); }

s32 func_800AA148(void) {
    s32 func_800A9FA0(s32);
    return func_800A9FA0(D_80127780.current);
}

s32 func_800AA16C(s32 arg0) {
    return ((s16 *)D_80127780.values)[arg0];
}

s32 func_800AA180(s32 arg0) {
    return ((s16 *)(D_80127780.values + 4))[arg0];
}

u32 func_800AA194(void) {
    return *(u8 *)((u8 *)&D_80127780.flag + 0);
}

void func_800AA1A0(void) {
    void _gcfrontend_entrypoint_7(s32, s32);
    s32 i;

    D_80127780.active = 1;
    D_80127780.current++;
    D_80127780.flag = 0;
    for (i = 4; i < 8; i++) {
        D_80127780.values[i] = 0;
    }
    _gcfrontend_entrypoint_7(func_800AA148(), 1);
}

void func_800AA200(s32 arg0) {
    D_80127780.flag = arg0;
}

void func_800AA20C(s32 arg0, s32 arg1) {
    D_80127780.values[arg0 + 4] = arg1;
}

void func_800AA220(s32 arg0, s32 arg1) {
    s16 *temp_v0;

    temp_v0 = (s16 *)&D_80127780 + arg0;
    (*(s16 *)((s8 *)(temp_v0) + (4))) = (s16) ((*(s16 *)((s8 *)(temp_v0) + (4))) + arg1);
}

/* extern */

s32 func_800AA240(void) {
    s32 func_800AA0D0();
    s32 sp1C;

    sp1C = func_800AA0C4();
    return sp1C >= (func_800AA0D0() - 1);
}

s32 func_800AA274(s32 arg0) {
    return func_800A9F80(arg0);
}
