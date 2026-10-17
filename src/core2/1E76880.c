#include "core2/1E76880.h"

s32 func_8009CF90() 
{
    return 0x8;
}

/* extern */

void func_8009CF98(PlayerState *arg0) {
    s32 yaw_init();
    yaw_init();
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xFC)))) + (4))) = 0.0f;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xFC)))) + (0))) = 0;
    func_8009D2D8(arg0, 1);
}

void func_8009CFD8(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xFC)))) + (4))) = arg1;
}

void func_8009CFE8(PlayerState *self) {
    f32 bastick_getX(PlayerState *);
    f32 mlAbsF(f32);
    f32 func_800F1344(f32, f32, f32, f32, f32);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    extern f32 D_80125350;
    f32 stick = bastick_getX(self);
    f32 change;

    if (mlAbsF(stick) > D_80125350) {
        change = func_800F1344(stick, 0.0f, 1.0f, 1.0f, 6.0f);
    } else {
        change = 0.0f;
    }
    yaw_setIdeal(self, yaw_getIdeal(self) + change);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E76880/func_8009D088.s")

void func_8009D2D8(PlayerState *arg0, s32 arg1) {
    **(s32 **)((u8 *)arg0 + 0xFC) = arg1;
}

s32 func_8009D2E4(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 252) + 0);
}

void func_8009D2F0(PlayerState *arg0, s32 arg1, f32 arg2) {
    void baroll_setIdeal(PlayerState *, f32);
    f32 func_800136E4(f32);
    void func_800963C0(PlayerState *, f32 *);
    s32 func_80096628(PlayerState *);
    void func_8009BF5C(PlayerState *, f32);
    s32 func_800F1B78(f32 *, f32 *, f32, f32);
    f32 yaw_get(PlayerState *);
    f32 sp34[3];
    f32 sp28[3];

    if (!(func_80096628(arg0) & 2)) {
        func_800963C0(arg0, sp34);
        if (arg1 != 0) {
            func_800F1B78(sp28, sp34, func_800136E4(yaw_get(arg0) + 180.0f), arg2);
        } else {
            func_800F1B78(sp28, sp34, yaw_get(arg0), arg2);
        }
        func_8009BF5C(arg0, sp28[0]);
        baroll_setIdeal(arg0, sp28[2]);
    }
}

void func_8009D3A8(PlayerState *arg0, s32 arg1) {
    func_8009D2F0(arg0, arg1, 1.0f);
}
