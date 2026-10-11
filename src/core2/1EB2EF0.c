#include "common.h"

void func_800D9600(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg1) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9624.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D965C.s")

int func_800D97E8(f32 a[4], f32 b[4]) {
    return a[0] == b[0] && a[1] == b[1] && a[2] == b[2] && a[3] == b[3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9888.s")

void func_800D9AD4(f32 arg0[4], f32 arg1[4], f32 arg2[4], f32 arg3) {
    void func_800D9888(f32 *, f32 *, f32 *, f32);
    f32 var_f0;
    f32 var_f2;
    f32 sp20[4];

    sp20[0] = arg1[0]-arg2[0];
    sp20[1] = arg1[1]-arg2[1];
    sp20[2] = arg1[2]-arg2[2];
    sp20[3] = arg1[3]-arg2[3];
    var_f0 = (sp20[0]*sp20[0] + sp20[1]*sp20[1] + sp20[2]*sp20[2] + sp20[3]*sp20[3]);

    sp20[0] = arg1[0]+arg2[0];
    sp20[1] = arg1[1]+arg2[1];
    sp20[2] = arg1[2]+arg2[2];
    sp20[3] = arg1[3]+arg2[3];
    var_f2 = (sp20[0]*sp20[0] + sp20[1]*sp20[1] + sp20[2]*sp20[2] + sp20[3]*sp20[3]);

    if (var_f0 <= var_f2) {
        func_800D9888(arg0, arg1, arg2, arg3);
        return;
    }
    sp20[0] = -arg2[0];
    sp20[1] = -arg2[1];
    sp20[2] = -arg2[2];
    sp20[3] = -arg2[3];
    func_800D9888(arg0, arg1, sp20, arg3);

}

void func_800D9C34(void *arg0) {
    (*(s32 *)((s8 *)(arg0) + (0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (8))) = 0;
    (*(s32 *)((s8 *)(arg0) + (0xC))) = 0x3F800000;
}

int func_800D9C4C(f32 arg0[4]){
    return ((arg0[0] == 0.0f)
        && (arg0[1] == 0.0f)
        && (arg0[2] == 0.0f)
        && (arg0[3] == 1.0f));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB2EF0/func_800D9CE8.s")
