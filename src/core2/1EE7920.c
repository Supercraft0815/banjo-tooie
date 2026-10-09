#include "common.h"

void func_8010E030(void) {
    s32 defrag(s32);
    extern s32 D_80127614;
    if (D_80127614 != 0) {
        D_80127614 = defrag(D_80127614);
    }
}
