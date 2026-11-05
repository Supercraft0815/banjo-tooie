#ifdef BT_NATIVE
#include "native_reflection.h"
s16 D_80127F1A;
u8 D_80127F1D;
#endif
void func_800B5680(s32 arg0) {
    extern s16 D_80127F1A;
    extern u8 D_80127F1D;
    D_80127F1D = 1;
    D_80127F1A = arg0;
}

s32 func_800B5698(s16 *arg0) {
    extern s16 D_80127F1A;
    extern u8 D_80127F1D;
    if (D_80127F1D != 0) {
        *arg0 = D_80127F1A;
        return 1;
    }
    return 0;
}
