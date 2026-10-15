#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_0.s")


void bsthrow_entrypoint_1(void *arg0) {
    struct anctrl_s;
    s32 baanim_getAnimCtrlPtr();
    int anctrl_isAt(s32, f32);
    s32 anctrl_isStopped(s32);
    void func_8009C128(void *, f32[3]);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void yaw_setIdeal(void *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 bs_setState(void *, s32);
    Unk80132ED0 *_bahold_entrypoint_5(void *);
    s32 _bahold_entrypoint_6(void *, Unk80132ED0 *);
    void func_800A33CC(void *, f32 *);
    s32 sp4C;
    s32 sp48;
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    Unk80132ED0 *sp28;

    sp4C = 0;
    sp48 = baanim_getAnimCtrlPtr(arg0);
    sp28 = _bahold_entrypoint_5(arg0);
    if ((*(s32 *)((s8 *)arg0 + 0x15C)) == 0 && sp28 != NULL) {
        _bahold_entrypoint_6(arg0, sp28);
    }
    func_8009C128(arg0, sp30);
    func_800A33CC(arg0, sp3C);
    func_800F1E6C(sp30, sp3C, &sp2C);
    yaw_setIdeal(arg0, sp2C);
    if (anctrl_isAt(sp48, 0.35f) && sp28 != NULL) {
        (*(s32 *)((s8 *)arg0 + 0x15C)) = 1;
        func_80106790(sp28)->unk64_22 = 1;
    }
    if (anctrl_isStopped(sp48)) {
        sp4C = 1;
    }
    bs_setState(arg0, sp4C);
}

/* extern */

void bsthrow_entrypoint_2(void *self) {
    s32 bastatetimer_set(void *, s32, f32);
    s32 bs_getNextState(void *);
    (*(s32 *)((s8 *)(self) + 0x15C)) = 0;
    if (bs_getNextState(self) == 1) {
        bastatetimer_set(self, 0, 0.14f);
        bastatetimer_set(self, 1, 0.28f);
    }
}

s32 bsthrow_entrypoint_3(s32 arg0) {
    extern s32 D_808002F0_bsthrow[];
    return ((s32 *)&D_808002F0_bsthrow)[arg0];
}

/* extern */

void bsthrow_entrypoint_4(void *arg0) {
    s32 func_8008E9AC(void *);
    s32 func_8008F6B8(void *, s32);
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
    case 18:
        if ((*(s32 *)((s8 *)(arg0) + (0x15C))) == 0) {
            func_8008F6B8(arg0, func_8008E9AC(arg0));
            return;
        }
        func_8009E830(arg0, 1);
        return;
    case 21:
    case 28:
    case 29:
    case 30:
    case 37:
        func_8009E830(arg0, 1);
        return;
    default:
        func_80099B94(arg0);
        return;
    }
}
