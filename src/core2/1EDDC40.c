#include "common.h"

void func_80104350(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_80136E80;
    D_80136E80 = freelist_new(0x2C, 8);
}

void func_80104378(void) {
    s32 freelist_free(s32);
    extern s32 D_80136E80;
    freelist_free(D_80136E80);
    D_80136E80 = 0;
}

void func_801043A0(void) {
    s32 freelist_defrag(s32);
    extern s32 D_80136E80;
    if (D_80136E80 != 0) {
        D_80136E80 = freelist_defrag(D_80136E80);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801043D8.s")

s32 *func_80104410(void *arg0) {
    s32 *freelist_at(s32, s16);
    extern s32 D_80136E80;
    extern s32 D_80136E88;
    extern s8 D_80136E8B;
    extern s32 D_80136EAC;
    extern s8 D_80136EB0;
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(arg0) + (0x8E)));
    if (temp_a1 == 0) {
        D_80136E8B = 0;
        D_80136EAC = 0;
        D_80136EB0 = 0;
        return &D_80136E88;
    }
    return freelist_at(D_80136E80, temp_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104460.s")

void func_80104504(void *arg0) {
    s32 freelist_erase(s32, s16, void *);
    extern s32 D_80136E80;
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(arg0) + (0x8E)));
    if (temp_a1 != 0) {
        freelist_erase(D_80136E80, temp_a1, arg0);
        (*(s16 *)((s8 *)(arg0) + (0x8E))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104544.s")

/* extern */

void func_80104580(void) {
    void *func_801043D8();
    void *temp_v0;

    temp_v0 = func_801043D8();
    if (temp_v0 != NULL) {
        (*(s8 *)((s8 *)(temp_v0) + (3))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801045AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104668.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_8010473C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104780.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_8010486C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801048E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104958.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801049B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104D80.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104E24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104E78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80104F2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80105010.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80105138.s")

/* extern */

s32 func_8010518C(s32 arg0) {
    void *func_801043D8(s32);
    s32 func_80104544();
    if (func_80104544() == 0) {
        return 0;
    }
    return (*(s32 *)((s8 *)(func_801043D8(arg0)) + (0x24)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_801051C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80105230.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDDC40/func_80105390.s")

/* extern */

s32 func_801053D4(void) {
    s32 func_800C84B0(s32);
    s32 func_8010518C();
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800C84B0(func_8010518C());
    var_v1 = temp_v0;
    if (temp_v0 == 0) {
        var_v1 = 1;
    }
    return var_v1;
}
