#include "core2/1E831D0.h"

void func_800A98E0(void) {
    s32 _gsattract_entrypoint_3();
    extern u8 D_80127760;
    extern s8 D_80127763;
    if ((D_80127760 != 1) && (D_80127760 == 2)) {
        _gsattract_entrypoint_3();
    }
    D_80127763 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9924.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9998.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9A14.s")

void func_800A9AA4(void) {
    extern u8 D_80127760;
    void func_800E817C(void);
    void _gsattract_entrypoint_2(void);
    switch (D_80127760) {
        case 1: func_800E817C(); break;
        case 2: _gsattract_entrypoint_2(); break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9AF8.s")

void func_800A9B84(void) {
}

void func_800A9B8C(s32 arg0, s32 arg1) {
    extern u8 D_80127760;
    (*(s16 *)((s8 *)(&D_80127760) + (0xA))) = (s16) arg0;
    (*(s16 *)((s8 *)(&D_80127760) + (0xC))) = (s16) arg1;
}

void func_800A9BA0(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 D_80127760;
    void func_800A79D4(s32, s32);
    void func_800A7A90(s32);
    void func_800A7B18(u32);
    (*(s8 *)((s8 *)(&D_80127760) + (1))) = (s8) arg0;
    if ((*(u8 *)((s8 *)(&D_80127760) + (0))) != 0) {
        (*(s8 *)((s8 *)(&D_80127760) + (4))) = 1;
    }
    (*(s16 *)((s8 *)(&D_80127760) + (6))) = (s16) arg1;
    (*(s16 *)((s8 *)(&D_80127760) + (8))) = (s16) arg2;
    func_800A79D4(arg1, arg2);
    func_800A7A90(1);
    func_800A7B18(3U);
}

/* extern */

void func_800A9BFC(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800EA090(void);
    s32 func_800EA05C();
    struct { s32 map; s32 entrance; } saved;
    s32 entrance;

    func_800A9B84();
    saved.map = func_800EA05C();
    entrance = func_800EA090();
    func_800A9B8C(saved.map, entrance);
    func_800A9BA0(arg0, arg1, arg2);
}

/* extern */

void func_800A9C50(void) {
    extern u8 D_80127760;
    void func_800A79D4(s32, s32);
    void func_800A7A90(s32);
    void func_800A7B18(u32);
    s32 func_800A8264();
    if (func_800A8264() == 0) {
        func_800A79D4((s32) (*(s16 *)((s8 *)(&D_80127760) + (0xA))), (s32) (*(s16 *)((s8 *)(&D_80127760) + (0xC))));
        func_800A7A90(1);
        func_800A7B18(1U);
    }
}

s32 func_800A9C98(void) {
    extern u8 D_80127760;
    return D_80127760 != 0;
}

s32 func_800A9CAC(void) {
    extern u8 D_80127760;
    s32 result;
    result = 0;
    return D_80127760 ? 1 : result;
}

u32 func_800A9CD0(void) {
    extern u8 D_80127760;
    return *(u8 *)((u8 *)&D_80127760 + 0);
}

void func_800A9CDC(void) {
    extern u8 D_80127760;
    if ((*(u8 *)((s8 *)(&D_80127760) + (2))) == 0) {
        (*(u8 *)((s8 *)(&D_80127760) + (2))) = 1U;
    }
}

void func_800A9D00(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9D08.s")
