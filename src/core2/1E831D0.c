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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9AA4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9AF8.s")

void func_800A9B84(void) {
}

void func_800A9B8C(s32 arg0, s32 arg1) {
    extern u8 D_80127760;
    (*(s16 *)((s8 *)(&D_80127760) + (0xA))) = (s16) arg0;
    (*(s16 *)((s8 *)(&D_80127760) + (0xC))) = (s16) arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9BFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9C50.s")

s32 func_800A9C98(void) {
    extern u8 D_80127760;
    return D_80127760 != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E831D0/func_800A9CAC.s")

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
