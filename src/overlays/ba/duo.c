#include "common.h"

typedef struct player_state_s PlayerState;

s32 baduo_entrypoint_0() 
{
    return 0x14;
}

/* extern */

void func_80800008_baduo(BtIntPtr arg0, BtIntPtr arg1) {
    s16 *func_800A4C88(void *arg0);
    void func_801100E4(s32 *arg0, s32 *arg1);
    BtIntPtr sp18;
    volatile BtIntPtr sp1c;

    sp18 = func_800A4C88(arg1);
    sp1c = sp18;
    func_801100E4(sp1c, func_800A4C88(arg0));
}    typedef struct { u8 pad0[0x58]; void * unk58; u8 pad5C[0x128]; s32 unk184; } Objduo_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

u32 baduo_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*&((Objduo_arg0 *)arg0)->unk58 + 0);
}

s32 baduo_entrypoint_2(PlayerState *self) {
    int func_800A3274(PlayerState *);
    s32 _plsu_entrypoint_1(s32);
    s32 temp_v0;

    temp_v0 = func_800A3274(self);
    switch (temp_v0) {
        case 10:
            return _plsu_entrypoint_1(0xB);
        case 11:
            return _plsu_entrypoint_1(0xA);
        default:
            return 0;
    }
}

u32 baduo_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*&((Objduo_arg0 *)arg0)->unk58 + 1);
}

u32 baduo_entrypoint_4(void *arg0) {
    return *(u8 *)((u8 *)*&((Objduo_arg0 *)arg0)->unk58 + 2);
}

void baduo_entrypoint_5(BtIntPtr arg0) 
{
}
void baduo_entrypoint_6(PlayerState *arg0) {
    void baduo_entrypoint_11(void *, s32);
    void baduo_entrypoint_7(PlayerState *, s32);
    int func_800A3274(PlayerState *);
    void func_800EFD24(f32 *);
    u8 func_800F8B88(void);
    s32 temp_v0;

    *((u8 *)*(void **)((u8 *)arg0 + 0x58) + 1) = 0;
    baduo_entrypoint_11(arg0, 0);
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x58) + 4) = 0.0f;
    func_800EFD24((f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x58) + 8));
    *(u8 *)*(void **)((u8 *)arg0 + 0x58) = 0;
    temp_v0 = func_800A3274(arg0);
    if ((temp_v0 == 0xA) || (temp_v0 == 0xB)) {
        if (func_800F8B88() == 2) {
            baduo_entrypoint_7(arg0, 3);
            return;
        }
        baduo_entrypoint_7(arg0, 1);
        return;
    }
    baduo_entrypoint_7(arg0, 1);
}

void baduo_entrypoint_7(PlayerState *arg0, s32 arg1) {
    void baduo_entrypoint_10(void *, s32);
    void baduo_entrypoint_11(void *, s32);
    s32 func_8008DAA8(void *);
    void func_8009ADF0(void *, s32, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    int _bashoes_entrypoint_6(void *arg0, s32 arg1);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    *(u8 *)*(void **)((u8 *)arg0 + 0x58) = arg1;
    switch (*(u8 *)*(void **)((u8 *)arg0 + 0x58)) {
        case 1:
            baduo_entrypoint_11(arg0, 0);
            func_8009ADF0(arg0, 2, 0);
            return;
        case 2:
            baduo_entrypoint_10(arg0, 0);
            baduo_entrypoint_11(arg0, 1);
            return;
        case 3:
            if (func_8008DAA8(arg0) != 0) {
                func_800A38F0(arg0, 1, 1);
            } else {
                func_800A38F0(arg0, 0, 1);
            }
            func_8009ADF0(arg0, 2, 1);
            return;
        case 4:
            _bashoes_entrypoint_6(arg0, 1);
            func_800F82D4(func_800F54E4(), 2);
            return;
    }
}

/* extern */

void baduo_entrypoint_8(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x58))) + 8);
}

void baduo_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objduo_arg0 *)arg0)->unk58 + 4) = arg1;
}

void baduo_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 1) = arg1;
}

void baduo_entrypoint_11(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 2) = arg1;
}

/* extern */

void baduo_entrypoint_12(BtIntPtr arg0) {
    int _bashoes_entrypoint_6(void *arg0, s32 arg1);
    s32 func_8008E39C();
    void func_800F9A6C(void);
    if (func_8008E39C() != 0) {
        _bashoes_entrypoint_6(arg0, 2);
    }
    func_800F9A6C();
}

void baduo_entrypoint_13(PlayerState *arg0) {
    void _bapackctrl_entrypoint_5(PlayerState *, s32);
    s32 _plsu_entrypoint_1(s32);
    void bs_setState(void *self, s32 nextState);
    s32 func_8008D40C(PlayerState *);
    void func_8009C128(PlayerState *, f32 *);
    int func_800A3274(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    void func_800A91A8(s32);
    int func_800D5034(s32, s32);
    f32 func_800F1F0C(f32 *, f32 *, f32);
    PlayerState *func_800F53D0(BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F5B0C(BtIntPtr);
    void func_800F759C(s32);
    void func_800F80D8(u32 arg0);
    void func_800F8268(s32, s32, s32);
    void func_800F82D4(BtIntPtr, s32);
    void func_800F8EBC(s32);
    void func_800F911C(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    f32 mlAbsF(f32);
    f32 yaw_get(PlayerState *);
    BtIntPtr sp54;
    s32 pad50;
    f32 sp4C;
    f32 sp40[3];
    f32 sp34[3];
    s32 sp30;

    sp54 = func_800F54E4();
    switch (**(u8 **)((u8 *)arg0 + 0x58)) {
    case 3:
        if ((func_800A3274(arg0) == 0xA) && (func_8008D40C(arg0) != 0)) {
            baduo_entrypoint_7(arg0, 4);
        }
        break;
    case 4:
        if (func_800F5B0C(sp54) == 2) {
            sp30 = baduo_entrypoint_2(arg0);
            if (sp54 == *(s32 *)((u8 *)arg0 + 0x184)) {
                func_800F8EBC(_plsu_entrypoint_1(0xB));
            } else {
                func_800F8EBC(*(s32 *)((u8 *)arg0 + 0x184));
            }
            if (sp54 == *(s32 *)((u8 *)arg0 + 0x184)) {
                func_800F82D4(sp54, 0);
            } else {
                func_800F82D4(sp54, 0);
                func_800F82D4(*(s32 *)((u8 *)arg0 + 0x184), 0);
            }
            _bapackctrl_entrypoint_5(arg0, 1);
            func_800F911C(1);
            func_800F80D8(*(s32 *)((u8 *)arg0 + 0x184));
            func_800D5034(func_800A3274(arg0), 1);
            func_800A3410(arg0, 1);
            func_800F8268(*(s32 *)((u8 *)arg0 + 0x184), 0, 1);
            if (sp54 != *(s32 *)((u8 *)arg0 + 0x184)) {
                func_80800008_baduo(func_800F53D0(sp30), func_800F53D0(*(s32 *)((u8 *)arg0 + 0x184)));
            }
            sp4C = yaw_get(arg0);
            func_800F5A00(sp30, sp34);
            func_8009C128(arg0, sp40);
            func_800F759C(sp30);
            func_800A38F0(arg0, 1, 1);
            func_800A91A8(*(s32 *)((u8 *)arg0 + 0x184));
            baduo_entrypoint_7(arg0, 1);
            if (mlAbsF(func_800F1F0C(sp40, sp34, sp4C)) > 90.0f) {
                bs_setState(arg0, 0x69);
            } else {
                bs_setState(arg0, 0x6A);
            }
            func_80101180(0x158, 0x17, 0);
        }
        break;
    }
}

/* extern */

void baduo_entrypoint_14(void *arg0, s32 arg1) {
    void _bababykaz_entrypoint_10(PlayerState *self, s32 arg1);
    void _bababykaz_entrypoint_8(PlayerState *self);
    void _bsfirstp_entrypoint_28(void *arg0, void *arg1);
    void bs_setState(void *self, s32 nextState);
    void func_80092778(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    void func_800A91A8(s32);
    s32 func_800F452C(BtIntPtr, BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void func_80800008_baduo(BtIntPtr, BtIntPtr);
    f32 yaw_get(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_set(PlayerState *self, f32 arg1);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp24;
    s32 temp_v0;
    PlayerState *temp_v0_2;

    temp_v0 = func_800F6224((((Objduo_arg0 *)arg0)->unk184));
    sp24 = temp_v0;
    temp_v0_2 = func_800F53D0(temp_v0);
    func_800F452C(temp_v0_2, arg1);
    func_800A3410(temp_v0_2, 0x11);
    func_80092778(temp_v0_2);
    func_80800008_baduo(arg0, temp_v0_2);
    _bababykaz_entrypoint_8(temp_v0_2);
    bs_setState(temp_v0_2, 0x139);
    yaw_set(temp_v0_2, yaw_get(arg0));
    yaw_setIdeal(temp_v0_2, yaw_getIdeal(arg0));
    _bababykaz_entrypoint_10(temp_v0_2, (((Objduo_arg0 *)arg0)->unk184));
    _bsfirstp_entrypoint_28(arg0, temp_v0_2);
    func_800A91A8(sp24);
    func_800A38F0(arg0, 0, 1);
}

void baduo_entrypoint_15(PlayerState *arg0, f32 *arg1) {
    void _bababykaz_entrypoint_8(PlayerState *self);
    s32 _badrone_entrypoint_29(PlayerState *);
    s32 _sudialog_entrypoint_0(s32 arg0, s32 arg1);
    void bs_setState(void *self, s32 nextState);
    void func_80092778(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    PlayerState *func_800A4CA8(PlayerState *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F3BB0(PlayerState *, f32[3]);
    s32 func_800F452C(BtIntPtr, BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void func_800F8128(s32);
    void func_800F86C4(s32, s32);
    s32 func_800F8EE4(s32);
    void func_80110588(PlayerState *);
    void func_80800008_baduo(BtIntPtr, BtIntPtr);
    void func_80800C78_baduo(BtIntPtr, s32);
    void func_80800CA8_baduo(BtIntPtr, BtIntPtr);
    s32 sp4C;
    PlayerState *temp_s2;
    PlayerState *temp_v0_2;
    s32 var_s0;
    f32 sp34[3];

    sp4C = func_800F6224(*(s32 *)((s8 *)arg0 + 0x184));
    temp_v0_2 = func_800F53D0(sp4C);
    func_800F452C(temp_v0_2, arg1);
    func_800A3410(temp_v0_2, 0x11);
    func_80092778(temp_v0_2);
    _bababykaz_entrypoint_8(temp_v0_2);
    func_80800008_baduo(arg0, temp_v0_2);
    temp_s2 = func_800A4CA8(temp_v0_2);
    func_800F3BB0(arg0, sp34);
    if (func_800EEB40(arg1, sp34) > 1000000.0f) {
        for (var_s0 = 0; var_s0 != 0x3C; var_s0++) {
            func_80110588(temp_s2);
        }
    }
    bs_setState(temp_v0_2, 0x136);
    func_800F8128(sp4C);
    func_800A38F0(arg0, 0, 1);
    func_800F8EE4(*(s32 *)((s8 *)arg0 + 0x184));
    bs_setState(arg0, _badrone_entrypoint_29(arg0));
    _sudialog_entrypoint_0(0xE8, 0xC);
    func_80800C78_baduo(temp_v0_2, 0x11);
    func_80800CA8_baduo(arg0, temp_v0_2);
    func_800F86C4(*(s32 *)((s8 *)temp_v0_2 + 0x184), 0x11);
}

/* extern */

void baduo_entrypoint_16(PlayerState *arg0) {
    void baduo_entrypoint_7(PlayerState *, s32);
    void bs_setState(void *self, s32 nextState);
    int func_800D5034(s32, s32);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void func_800F8128(s32);
    s32 func_800F8EE4(s32);
    void func_800F9098(s32, f32 *);
    void func_800F90EC(f32);
    void func_800F911C(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800008_baduo(BtIntPtr, BtIntPtr);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp24;
    s32 temp_v0;
    PlayerState *temp_s0;

    temp_v0 = func_800F6224((*(s32 *)((s8 *)(arg0) + (0x184))));
    sp24 = temp_v0;
    temp_s0 = func_800F53D0(temp_v0);
    yaw_setIdeal(arg0, yaw_get(arg0));
    yaw_setIdeal(temp_s0, yaw_get(arg0));
    yaw_applyIdeal(temp_s0);
    bs_setState(temp_s0, 0xBA);
    func_80800008_baduo(arg0, temp_s0);
    baduo_entrypoint_7(temp_s0, 2);
    baduo_entrypoint_7(arg0, 2);
    func_800F911C(2);
    func_800F9098(0xA, (f32 *)((*(u8 **)((s8 *)(arg0) + (0x58))) + 8));
    func_800F90EC((*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x58)))) + (4))));
    func_800D5034(1, 0xA);
    func_800D5034(1, 0xB);
    func_800F8EE4(sp24);
    func_800F8128((*(s32 *)((s8 *)(arg0) + (0x184))));
    func_80101180(0x158, 0x16, 0);
}

/* extern */

void baduo_entrypoint_17(void *arg0, BtIntPtr arg1) {
    void bs_setState(void *self, s32 nextState);
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_800F452C(BtIntPtr, BtIntPtr);
    s32 func_800F45B0(BtIntPtr, s32, BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void *temp_v0;
    void *sp28;
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    temp_v0 = func_800F53D0(func_800F6224((((Objduo_arg0 *)arg0)->unk184)));
    sp28 = temp_v0;
    func_800F452C((BtIntPtr) temp_v0, arg1);
    bs_setState((BtIntPtr) sp28, 1);
    func_800F45B0((BtIntPtr) sp28, 2, (BtIntPtr) sp1C);
}

void baduo_entrypoint_18(PlayerState *arg0, BtIntPtr arg1) {
    void bs_setState(void *self, s32 nextState);
    void func_80092778(PlayerState *);
    void func_8009DB04(PlayerState *, s32, f32, s32);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    s32 func_800F452C(BtIntPtr, BtIntPtr);
    s32 func_800F45B0(BtIntPtr, s32, BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void func_800F8128(s32);
    s32 func_800F8EE4(s32);
    void func_80800008_baduo(BtIntPtr, BtIntPtr);
    void func_80800C78_baduo(BtIntPtr, s32);
    void func_80800CA8_baduo(BtIntPtr, BtIntPtr);
    void yaw_applyIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp24;
    s32 temp_v0;
    PlayerState *temp_v0_2;

    temp_v0 = func_800F6224(*(s32 *)((s8 *)arg0 + 0x184));
    sp24 = temp_v0;
    temp_v0_2 = func_800F53D0(temp_v0);
    func_800F452C((BtIntPtr)temp_v0_2, arg1);
    func_800A3410(temp_v0_2, 0xD);
    func_80092778(temp_v0_2);
    bs_setState((BtIntPtr)temp_v0_2, 0xE5);
    func_80800008_baduo((BtIntPtr)arg0, (BtIntPtr)temp_v0_2);
    func_800A38F0(arg0, 0, 1);
    func_800F8128(sp24);
    func_800F8EE4(*(s32 *)((s8 *)arg0 + 0x184));
    func_800F45B0((BtIntPtr)arg0, 2, arg1);
    yaw_setIdeal(temp_v0_2, 0.0f);
    yaw_applyIdeal(temp_v0_2);
    func_80800C78_baduo((BtIntPtr)temp_v0_2, 0xD);
    func_80800CA8_baduo((BtIntPtr)arg0, (BtIntPtr)temp_v0_2);
    func_8009DB04(arg0, 0x5A2, 0.9f, 0x6D60);
}

void baduo_entrypoint_19(PlayerState *arg0) {
    s32 _plsu_entrypoint_1(s32);
    void func_8009DB04(PlayerState *, s32, f32, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    void func_800F457C(void *, s32);
    PlayerState *func_800F53D0(BtIntPtr);
    void func_800F759C(s32);
    void func_800F8128(s32);
    void func_800F8EBC(s32);
    void func_80800C78_baduo(BtIntPtr, s32);
    void func_80800CA8_baduo(BtIntPtr, BtIntPtr);
    s32 sp24;

    sp24 = _plsu_entrypoint_1(0xD);
    func_800F457C(arg0, 0);
    func_800A38F0(arg0, 1, 1);
    func_800F8EBC(*(s32 *)((s8 *)arg0 + 0x184));
    func_80800008_baduo((BtIntPtr)func_800F53D0(sp24), (BtIntPtr)arg0);
    func_800F8128(*(s32 *)((s8 *)arg0 + 0x184));
    func_80800CA8_baduo((BtIntPtr)func_800F53D0(sp24), (BtIntPtr)arg0);
    func_800F759C(sp24);
    func_80800C78_baduo((BtIntPtr)arg0, 1);
    func_8009DB04(arg0, 0x5A4, 0.9f, 0x6D60);
}

void baduo_entrypoint_20(PlayerState *arg0, BtIntPtr arg1, f32 arg2) {
    void _bsstatue_entrypoint_1(BtIntPtr arg0);
    s32 _sudialog_entrypoint_0(s32 arg0, s32 arg1);
    void bs_setState(void *self, s32 nextState);
    void func_80092778(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    s32 func_800F452C(BtIntPtr, BtIntPtr);
    s32 func_800F45B0(BtIntPtr, s32, BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void func_800F8128(s32);
    s32 func_800F8EE4(s32);
    void func_80800008_baduo(BtIntPtr, BtIntPtr);
    void func_80800C78_baduo(BtIntPtr, s32);
    void func_80800CA8_baduo(BtIntPtr, BtIntPtr);
    void yaw_applyIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp24;
    PlayerState *temp_s0;

    sp24 = func_800F6224(*(s32 *)((s8 *)arg0 + 0x184));
    temp_s0 = func_800F53D0(sp24);
    func_800F452C((BtIntPtr)temp_s0, arg1);
    func_80800008_baduo((BtIntPtr)arg0, (BtIntPtr)temp_s0);
    func_800A3410(temp_s0, 0xE);
    func_80092778(temp_s0);
    yaw_setIdeal(temp_s0, arg2);
    yaw_applyIdeal(temp_s0);
    _bsstatue_entrypoint_1(arg0);
    bs_setState((BtIntPtr)temp_s0, 0xF9);
    func_800F8128(sp24);
    func_800F8EE4(*(s32 *)((s8 *)arg0 + 0x184));
    func_800F45B0((BtIntPtr)arg0, 2, arg1);
    func_800A38F0(arg0, 0, 1);
    _sudialog_entrypoint_0(0x50, 0xE);
    func_80800C78_baduo((BtIntPtr)temp_s0, 0xE);
    func_80800CA8_baduo((BtIntPtr)arg0, (BtIntPtr)temp_s0);
}

/* extern */

void baduo_entrypoint_21(PlayerState *arg0) {
    void _bakaztorpedo_entrypoint_3(void *arg0);
    void bs_setState(void *self, s32 nextState);
    void func_80092778(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800A1694(void);
    void func_800A16BC(s32);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    void func_800A91A8(s32);
    void func_800D5234(s32);
    s32 func_800F452C(BtIntPtr, BtIntPtr);
    PlayerState *func_800F53D0(BtIntPtr);
    s32 func_800F6224(s32);
    void func_800F80D8(u32 arg0);
    s32 func_800F8EE4(s32);
    void func_800F911C(s32);
    void func_80800008_baduo(BtIntPtr, BtIntPtr);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp34;
    PlayerState *temp_s1;
    f32 sp24[3];

    func_800F911C(3);
    sp34 = func_800F6224((*(s32 *)((s8 *)(arg0) + (0x184))));
    temp_s1 = func_800F53D0(sp34);
    func_8009C128(arg0, sp24);
    func_800F452C((BtIntPtr)temp_s1, (BtIntPtr)sp24);
    func_800A3410(arg0, 0xA);
    func_800A3410(temp_s1, 0xB);
    func_80092778(temp_s1);
    yaw_setIdeal(arg0, yaw_get(arg0));
    yaw_setIdeal(temp_s1, yaw_get(arg0));
    yaw_applyIdeal(temp_s1);
    func_800F80D8(sp34);
    bs_setState((BtIntPtr)temp_s1, 0x153);
    func_800A91A8(sp34);
    func_80800008_baduo((BtIntPtr)arg0, (BtIntPtr)temp_s1);
    func_800F8EE4((*(s32 *)((s8 *)(arg0) + (0x184))));
    func_800A38F0(arg0, 0, 1);
    func_800D5234(1);
    func_800A16BC(1);
    func_800A1694();
    _bakaztorpedo_entrypoint_3(temp_s1);
}

/* extern */

void func_80800C78_baduo(BtIntPtr arg0, s32 arg1) {
    void _surestart_entrypoint_0(s32 arg0);
    void func_800A1658(s32 arg0);
    _surestart_entrypoint_0(arg1);
    func_800A1658(arg1);
}

void func_80800CA8_baduo(BtIntPtr arg0, BtIntPtr arg1) {
    s32 sp18[2];

    sp18[0] = func_800A3274(arg0);
    func_800D5034(sp18[0], func_800A3274(arg1));
}
