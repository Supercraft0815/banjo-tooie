#include "common.h"

void susubgame_entrypoint_12(void *, void *);
void susubgame_entrypoint_0(s32 arg0, u8 *arg1, s32 arg2) {
    extern s32 D_80800970_susubgame;
    (*(s8 *)(arg1 + 0)) = 0;
    (*(s16 *)(arg1 + 2)) = arg2;
    (*(s8 *)(arg1 + 1)) = 0;
    (*(s16 *)(arg1 + 4)) = 0x15;
    susubgame_entrypoint_12(arg1, &D_80800970_susubgame);
}

void susubgame_entrypoint_1(s32 arg0, u8 *arg1, s32 arg2) {
    (*(s16 *)((s8 *)(arg1) + (4))) = arg2;
}

u8 susubgame_entrypoint_2(s32 arg0, u8 *arg1) {
    return *arg1;
}

/* extern */

s32 susubgame_entrypoint_3(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 susubgame_entrypoint_5(s32, u8 *, s32, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg2, arg3) != 0) {
        if (*arg1 != 2) {
            susubgame_entrypoint_5(arg0, arg1, 5, 1, 0);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_7.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_8.s")

/* extern */

s32 susubgame_entrypoint_9(void) {
    s32 func_800F6F00(s32);
    s32 func_808008DC_susubgame(s32);
    s32 var_s0;

    var_s0 = 0;
loop_1:
    if ((func_808008DC_susubgame(var_s0) != 0) && (func_800F6F00(var_s0) == 0)) {
        return 0;
    }
    var_s0 += 1;
    if (var_s0 == 8) {
        return 1;
    }
    goto loop_1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/susubgame_entrypoint_10.s")

/* extern */

void susubgame_entrypoint_11(s32 arg0) {
    s32 func_800CE88C(s32, s32);
    s32 func_800CEAA8();
    if (func_800CEAA8() != 0) {
        func_800CE88C(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/func_8080078C_susubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/func_80800814_susubgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/bgame/func_808008DC_susubgame.s")

void susubgame_entrypoint_12(void *arg0, void *arg1) {
    (*(f32 *)((s8 *)(arg0) + (8))) = (f32) (*(f32 *)((s8 *)(arg1) + (0)));
    (*(f32 *)((s8 *)(arg0) + (0xC))) = (f32) (*(f32 *)((s8 *)(arg1) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0x10))) = (f32) (*(f32 *)((s8 *)(arg1) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x14))) = (f32) (*(f32 *)((s8 *)(arg1) + (0xC)));
}
