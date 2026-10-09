#include "common.h"

void func_800AA2A0(s16 *arg0, s32 *arg1, f32 *arg2) {
    s32 i;

    if (arg0[9] == 0) {
        arg1[0] = arg1[1] = arg1[2] = 0;
        return;
    }
    for (i = 0; i < 3; i++) {
        if (arg2[i] >= 0.0f) {
            arg1[i] = (s32)arg2[i] / arg0[9];
        } else {
            arg1[i] = (s32)arg2[i] / arg0[9] - 1;
        }
        if (arg1[i] < arg0[i]) {
            arg1[i] = arg0[i];
        }
        if (arg0[i + 3] < arg1[i]) {
            arg1[i] = arg0[i + 3];
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA3B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA4D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AA7FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAAE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAD28.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAD80.s")

u32 func_800AADE4(u16 *arg0) {
    return arg0[10];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AADEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAEF4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AAFEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB0BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB868.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB980.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AB9D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABA20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABA9C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABB34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABC58.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800ABCE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC100.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC638.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AC978.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD1AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD2C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E83B90/func_800AD894.s")
