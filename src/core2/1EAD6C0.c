#include "common.h"

s32 func_800D3DD0(s32 arg0) {
    s32 func_800DA298(s32);
    extern u16 D_8011B5B8[][4];
    u16 temp_v0;

    temp_v0 = D_8011B5B8[arg0][0];
    if (temp_v0 != 0) {
        return func_800DA298(temp_v0);
    }
    return 0;
}

s32 func_800D3E14(s32 arg0) {
    s32 func_800DA298(s32);
    extern u16 D_8011B5BA[][4];
    return func_800DA298(D_8011B5BA[arg0][0]);
}

s32 func_800D3E40(s32 arg0) {
    s32 func_800DA298(s32);
    extern u16 D_8011B5BC[][4];
    return func_800DA298(D_8011B5BC[arg0][0]);
}

s32 func_800D3E6C(s32 arg0) {
    s32 func_800DA298(s32);
    extern u16 D_8011B5B8[][4];
    u16 temp_v0;
    if (func_800D3E14(arg0) != 0) {
        return 0;
    }
    temp_v0 = D_8011B5B8[arg0][0];
    if (temp_v0 != 0) {
        return func_800DA298(temp_v0 & 0xFFFFFFFF);
    }
    return 1;
}

/* extern */

s32 func_800D3EC8(void) {
    s32 func_800D3E14();
    if (func_800D3E14() != 0) {
        return 0;
    }
    return 1;
}

void func_800D3EF4(s32 arg0) {
    s32 func_800DA544(s32);
    extern u16 D_8011B5B8[][4];
    u16 temp_v0;

    temp_v0 = D_8011B5B8[arg0][0];
    if (temp_v0 != 0) {
        func_800DA544(temp_v0);
    }
}

s32 func_800D3F2C(s32 arg0) {
    s32 func_800DA544(s32);
    extern u16 D_8011B5BA[][4];
    return func_800DA544(D_8011B5BA[arg0][0]);
}

void func_800D3F58(s32 arg0, s32 arg1) {
    void func_800DA3B8(GameFlag, s32);
    u32 func_800F54E4(void);
    void func_800F4924(s32, s32);
    extern u16 D_8011B5C0[][4];
    extern u16 D_8011B608[][4];
    u16 (*sp18)[4];

    sp18 = &D_8011B5C0[arg0];
    func_800DA3B8(sp18[-1][2], arg1);
    if ((sp18 == D_8011B608) && (arg1 != 0)) {
        arg0 = func_800F54E4();
        func_800F4924(arg0, 0x3E7);
    }
}

u32 func_800D3FC0(s32 arg0) {
    extern u16 D_8011B5BE[4][4];
    return D_8011B5BE[arg0][0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAD6C0/func_800D3FD4.s")

s32 func_800D41D8(s32 arg0) {
    extern s16 D_8011B620[][2];
    s32 i;

    for (i = 0; i < 7; i++) {
        if (arg0 == D_8011B620[i][0]) {
            return D_8011B620[i][1];
        }
    }
    return 0x3C;
}

/* extern */

void func_800D4298(s32 arg0, s32 arg1) {
    s32 func_800C6E38(s32);
    s32 func_800D192C(s32, s32);
    s32 func_800D41D8();
    s32 temp_v0;

    temp_v0 = func_800D41D8();
    if ((temp_v0 != 0x3C) && (func_800C6E38(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D192C(arg0, arg1);
}

/* extern */

void func_800D42E8(s32 arg0, s32 arg1) {
    s32 func_800C6E38(s32);
    s32 func_800D1960(s32, s32, s32);
    s32 func_800D41D8();
    s32 temp_v0;

    temp_v0 = func_800D41D8();
    if ((temp_v0 != 0x3C) && (func_800C6E38(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D1960(arg0, -2, arg1);
}

/* extern */

void func_800D433C(s32 arg0, s32 arg1) {
    s32 func_800C6E38(s32);
    s32 func_800D1960(s32, s32, s32);
    s32 func_800D1ACC(s32);
    s32 func_800D41D8();
    s32 temp_v0;

    temp_v0 = func_800D41D8();
    if ((temp_v0 != 0x3C) && (func_800C6E38(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D1960(arg0, func_800D1ACC(arg0), arg1);
}

/* extern */

void func_800D4398(s32 arg0, s32 arg1) {
    s32 func_800C6E38(s32);
    s32 func_800D1960(s32, s32, s32);
    s32 func_800D1ACC(s32);
    s32 func_800D41D8();
    s32 temp_v0;

    temp_v0 = func_800D41D8();
    if ((temp_v0 != 0x3C) && (func_800C6E38(temp_v0) == 0)) {
        arg1 = 0;
    }
    func_800D1960(arg0, func_800D1ACC(arg0) * 2, arg1);
}
