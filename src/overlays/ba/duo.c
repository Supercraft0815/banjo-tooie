#include "common.h"

typedef struct player_state_s PlayerState;

s32 baduo_entrypoint_0() 
{
    return 0x14;
}

/* extern */

void func_80800008_baduo(s32 arg0, s32 arg1) {
    s32 func_800A4C88(s32);
    s32 func_801100E4(s32, s32);
    s32 sp18;
    volatile s32 sp1c;

    sp18 = func_800A4C88(arg1);
    sp1c = sp18;
    func_801100E4(sp1c, func_800A4C88(arg0));
}

u32 baduo_entrypoint_1(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_2.s")

u32 baduo_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 1);
}

u32 baduo_entrypoint_4(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 2);
}

void baduo_entrypoint_5(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_7.s")

/* extern */

void baduo_entrypoint_8(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x58))) + 8);
}

void baduo_entrypoint_9(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 4) = arg1;
}

void baduo_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 1) = arg1;
}

void baduo_entrypoint_11(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 2) = arg1;
}

/* extern */

void baduo_entrypoint_12(s32 arg0) {
    s32 _bashoes_entrypoint_6(s32, s32);
    s32 func_8008E39C();
    s32 func_800F9A6C();
    if (func_8008E39C() != 0) {
        _bashoes_entrypoint_6(arg0, 2);
    }
    func_800F9A6C();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_13.s")

/* extern */

void baduo_entrypoint_14(void *arg0, s32 arg1) {
    s32 _bababykaz_entrypoint_10(s32, s32);
    s32 _bababykaz_entrypoint_8(s32);
    s32 _bsfirstp_entrypoint_28(void *, s32);
    s32 bs_setState(s32, s32);
    void func_80092778(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A38F0(PlayerState *, s32, s32);
    void func_800A91A8(s32);
    s32 func_800F452C(s32, s32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F6224(s32);
    void func_80800008_baduo(s32, s32);
    f32 yaw_get(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    s32 yaw_set(s32, f32);
    void yaw_setIdeal(PlayerState *, f32);
    s32 sp24;
    s32 temp_v0;
    PlayerState *temp_v0_2;

    temp_v0 = func_800F6224((*(s32 *)((s8 *)(arg0) + (0x184))));
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
    _bababykaz_entrypoint_10(temp_v0_2, (*(s32 *)((s8 *)(arg0) + (0x184))));
    _bsfirstp_entrypoint_28(arg0, temp_v0_2);
    func_800A91A8(sp24);
    func_800A38F0(arg0, 0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_16.s")

/* extern */

void baduo_entrypoint_17(void *arg0, s32 arg1) {
    s32 bs_setState(s32, s32);
    void func_8009C128(void *, f32[3]);
    s32 func_800F452C(s32, s32);
    s32 func_800F45B0(s32, s32, s32);
    PlayerState *func_800F53D0(s32);
    s32 func_800F6224(s32);
    void *temp_v0;
    void *sp28;
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    temp_v0 = func_800F53D0(func_800F6224((*(s32 *)((s8 *)(arg0) + (0x184)))));
    sp28 = temp_v0;
    func_800F452C((s32) temp_v0, arg1);
    bs_setState((s32) sp28, 1);
    func_800F45B0((s32) sp28, 2, (s32) sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/duo/baduo_entrypoint_21.s")

/* extern */

void func_80800C78_baduo(s32 arg0, s32 arg1) {
    s32 _surestart_entrypoint_0(s32);
    s32 func_800A1658(s32);
    _surestart_entrypoint_0(arg1);
    func_800A1658(arg1);
}

void func_80800CA8_baduo(s32 arg0, s32 arg1) {
    s32 sp18[2];

    sp18[0] = func_800A3274(arg0);
    func_800D5034(sp18[0], func_800A3274(arg1));
}
