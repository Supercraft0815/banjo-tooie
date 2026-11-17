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
    f32 stick = bastick_getX(self);
    f32 change;

    if (mlAbsF(stick) > 0.03f) {
        change = func_800F1344(stick, 0.0f, 1.0f, 1.0f, 6.0f);
    } else {
        change = 0.0f;
    }
    yaw_setIdeal(self, yaw_getIdeal(self) + change);
}    typedef struct { u8 pad0[0xFC]; s32 * unkFC; } Obj1E76880_func_8009D088_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

s32 func_8009D088(void *self) {
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 func_800F1DCC(f32, f32);
    f32 mlAbsF(f32);
    f32 yaw_get(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_set(PlayerState *, f32);
    void yaw_setIdeal(PlayerState *, f32);
    void yaw_update(PlayerState *);
    f32 angle;

    switch (*((Obj1E76880_func_8009D088_self *)self)->unkFC) {
        case 0:
        case 2:
            break;
        case 1:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
            }
            yaw_update(self);
            break;
        case 5:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self) + 180.0f);
            }
            yaw_update(self);
            break;
        case 3:
            yaw_update(self);
            break;
        case 6:
            func_8009CFE8(self);
            yaw_update(self);
            break;
        case 4:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
                yaw_set(self, yaw_getIdeal(self));
            }
            yaw_update(self);
            break;
        case 7:
            if (bastick_distance(self) != 0.0f) {
                angle = bastick_getAngleRelativeToBanjo(self);
                if (mlAbsF(func_800F1DCC(yaw_getIdeal(self), angle)) >=
                    *(f32 *)((u8 *)*(void **)((u8 *)self + 0xFC) + 4)) {
                    yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
                }
            }
            yaw_update(self);
            break;
        case 8:
            if (bastick_distance(self) != 0.0f) {
                yaw_setIdeal(self, bastick_getAngleRelativeToBanjo(self));
            } else {
                yaw_setIdeal(self, yaw_get(self));
            }
            yaw_update(self);
            break;
        case 9:
            yaw_update(self);
            break;
    } BT_NATIVE_ONLY(return 0;)
}

void func_8009D2D8(PlayerState *arg0, s32 arg1) {
    *arg0->unkFC = arg1;
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
