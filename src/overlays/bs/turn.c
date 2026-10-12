#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/turn/bsturn_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/turn/bsturn_entrypoint_1.s")

/* extern */

void bsturn_entrypoint_2(s32 arg0) {
    s32 baroll_setIdeal(s32, f32);
    f32 func_800136E4(f32);
    void func_8009BF5C(s32, f32);
    f32 yaw_get();
    s32 yaw_set(s32, f32);
    yaw_set(arg0, func_800136E4(yaw_get() - 180.0f));
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
}

s32 bsturn_entrypoint_3(s32 arg0) {
    extern s32 D_80800360_bsturn[];
    return ((s32 *)&D_80800360_bsturn)[arg0];
}
