#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800EFE50.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800EFED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800EFFB4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0008.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0064.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F00A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F018C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0274.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F03AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0410.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0524.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F059C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F05F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0734.s")

s32 func_800F0AA4(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    f32 a, b, c;
    f32 d, e;

    a = arg1[2] - arg0[2];
    b = arg0[0] - arg1[0];
    c = arg1[0] * arg0[2] - arg0[0] * arg1[2];
    d = a * arg2[0] + b * arg2[2] + c;
    e = a * arg3[0] + b * arg3[2] + c;
    if (d * e > 0.0f) {
        return 0;
    }
    a = arg3[2] - arg2[2];
    b = arg2[0] - arg3[0];
    c = arg3[0] * arg2[2] - arg2[0] * arg3[2];
    d = a * arg0[0] + b * arg0[2] + c;
    e = a * arg1[0] + b * arg1[2] + c;
    if (d * e > 0.0f) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0BD0.s")

/* extern */

f32 func_800F0C68(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 func_800EF2A0(s32);
    func_800EF2A0(arg1);
    return arg2 / sqrtf((arg2 * arg2) + (arg3 * arg3));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC9740/func_800F0CB4.s")
