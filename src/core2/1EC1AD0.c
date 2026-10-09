#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E81E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E829C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E82EC.s")

void func_800E86DC(void) {
    s32 freelist_free(s32);
    extern s32 D_8012D600;
    if (D_8012D600 != 0) {
        freelist_free(D_8012D600);
        D_8012D600 = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8714.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E87E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8830.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8870.s")

/* extern */

void func_800E88AC(u8 arg0, s32 arg1) {
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, s32, s32);
    func_800E8918(arg0, func_800A89F8(), 0, arg1);
}

/* extern */

void func_800E88E4(u8 arg0) {
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, s32, s32);
    func_800E8918(arg0, func_800A89F8(), 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC1AD0/func_800E8918.s")

void func_800E8A20(void) {
    s32 freelist_defrag(s32);
    extern s32 D_8012D600;
    if (D_8012D600 != 0) {
        D_8012D600 = freelist_defrag(D_8012D600);
    }
}
