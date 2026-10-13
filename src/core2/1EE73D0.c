#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE73D0/func_8010DAE0.s")

/* extern */

void func_8010DC50(s32 arg0) {
    void *func_80104148(s32);
    s32 func_80104268(s32);
    s16 func_800AE020();
    s32 func_8010DAE0(s32, s32);
    s16 *ptr;
    ptr = func_80104148(arg0);
    if (*((u8 *)ptr + 4) == 0) {
        func_8010DAE0(func_80104268((s32)((u8 *)ptr + 2)), arg0);
        *ptr = func_800AE020();
    }
    *((u8 *)ptr + 4) = *((u8 *)ptr + 4) + 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE73D0/func_8010DCB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE73D0/func_8010DD20.s")

/* extern */

void func_8010DEFC(void) {
    void *func_80104148(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        var_s0 += 1;
        (*(s8 *)((s8 *)(temp_v0) + (5))) = 0;
    } while (var_s0 != 0xB);
}

/* extern */

void func_8010DF3C(void) {
    s32 func_8008ADE4(s32);
    void *func_80104148(s32);
    s32 func_80104200(s16);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        if ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) {
            func_8008ADE4(func_80104200((*(s16 *)((s8 *)(temp_v0) + (2)))));
        }
        var_s0 += 1;
    } while (var_s0 != 0xB);
}

/* extern */

void func_8010DF98(void) {
    s32 func_800ADFE0(s16);
    void *func_80104148(s32);
    s32 var_s0;
    void *temp_v0;

    var_s0 = 0;
    do {
        temp_v0 = func_80104148(var_s0);
        if (((*(u8 *)((s8 *)(temp_v0) + (4))) != 0) || ((*(s16 *)((s8 *)(temp_v0) + (2))) != 0) || ((*(s16 *)((s8 *)(temp_v0) + (8))) != 0)) {
            (*(u8 *)((s8 *)(temp_v0) + (4))) = 0U;
            (*(s16 *)((s8 *)(temp_v0) + (2))) = 0;
            (*(s16 *)((s8 *)(temp_v0) + (8))) = 0;
        }
        if ((*(s16 *)((s8 *)(temp_v0) + (0))) != 0) {
            func_800ADFE0((*(s16 *)((s8 *)(temp_v0) + (0))));
            (*(s16 *)((s8 *)(temp_v0) + (0))) = 0;
        }
        var_s0 += 1;
    } while (var_s0 != 0xB);
}
