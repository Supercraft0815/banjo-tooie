#include "common.h"

f32 func_80027170(s32 arg0) {
    extern f32 D_80041CD0;
    extern f32 D_80041CD4;
    f32 x;
    f32 ratio = 1.0f;

    if (arg0 >= 0) {
        x = D_80041CD0;
    } else {
        x = D_80041CD4;
        arg0 = -arg0;
    }
    while (arg0 != 0) {
        if (arg0 & 1) {
            ratio *= x;
        }
        x *= x;
        arg0 >>= 1;
    }
    return ratio;
}

void func_80027200(void) {
    extern s32 *D_800411F4;
    *D_800411F4 = 0;
}
