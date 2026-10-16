#include "common.h"

s16 D_8012B260[23];

s16 *func_800D1FC0(s32 arg0) {
    s32 func_800D395C(void);
    extern s16 D_8012B260[];
    extern s32 D_8012B290;
    s16 *result;

    arg0 -= 0x80;
    if (func_800D395C() != 0) {
        result = (s16 *) &D_8012B290 + arg0;
    } else {
        result = (s16 *) D_8012B260 + arg0;
    }
    return result;
}

void func_800D2014(void) {
    s32 i;

    for (i = 0; i < 23; i++) {
        D_8012B260[i] = 0;
    }
}

s32 func_800D2054(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D395C(void);
    s32 func_800DA544(s32);
    s32 result;
    s16 *value;
    s32 difference;

    value = func_800D1FC0(arg1);
    if (*value == 0) {
        result = 1;
    } else {
        switch (arg0) {
            case 0:
                difference = arg2 - *value;
                break;
            case 1:
                difference = *value - arg2;
                break;
        }
        result = difference <= 0 ? (difference != 0 ? -1 : 0) : 1;
    }
    if (result == 1) {
        if (func_800D395C() != 0) {
            func_800DA544(0xD54);
        }
        *value = arg2;
    }
    return result;
}

/* extern */

s16 func_800D211C(s32 arg0) {
    s16 *func_800D1FC0(s32);
    return *func_800D1FC0(arg0);
}

s32 func_800D2140() 
{
    return 0x2E;
}

void func_800D2148(u8 *arg0, u32 arg1) {
    void rare_memcpy(void* dst, void* src, int length);
    extern s16 D_8012B260[];
    u32 var_v1;

    var_v1 = arg1 >> 1;
    if ((s32) var_v1 >= 0x18) {
        var_v1 = 0x17;
    }
    rare_memcpy(D_8012B260, arg0, var_v1 * 2);
}

void func_800D2188(u8 *arg0) {
    void rare_memcpy(void* dst, void* src, int length);
    extern s16 D_8012B260[];
    rare_memcpy(arg0, D_8012B260, 0x2E);
}

void func_800D21B0(s32 *arg0, s32 **arg1) {
    extern s32 D_8012B290;
    *arg0 = 0x2E;
    *arg1 = &D_8012B290;
}
