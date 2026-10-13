#include "common.h"

u32 func_8001E7E0(void) {
    return 0x80400000;
}

void func_8001E7E8(void) {
    extern s32 D_8007E990;
    extern s32 D_8007E994;
    extern u32 D_8007E998;
    u32 func_8001E830(void);
    D_8007E998 = func_8001E7E0();
    D_8007E990 = D_8007E998 - func_8001E830();
    D_8007E994 = D_8007E990;
}

u32 func_8001E830(void) {
    return 0x002C8800;
}
