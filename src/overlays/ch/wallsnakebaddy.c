#include "common.h"

void func_80800000_chwallsnakebaddy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    f32 func_800D8FF8(void);
    u32 func_800F54E4(void);
    f32 func_800F5F7C(u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80107070(Actor *, u32);
    s32 func_8010CA74(f32 *, s32);
    extern s32 D_808006F4_chwallsnakebaddy;
    extern s32 D_80800700_chwallsnakebaddy;
    extern s32 D_80800710_chwallsnakebaddy;
    f32 y;

    switch (arg0->unk70_10) {
    case 1:
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= func_800D8FF8();
            break;
        }
        y = func_800F5F7C(func_800F54E4());
        if ((arg0->unk64_29 && _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) ||
            (!arg0->unk64_29 && func_8010CA74(arg0->position, arg0->unk74_7))) {
            if (y <= arg0->position[1]
                ? arg0->position[1] - 500.0f <= y
                : y <= arg0->position[1] + 360.0f) {
                func_80102424(arg0, y <= arg0->position[1] ? 2 : 3);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808006F4_chwallsnakebaddy);
            }
        }
        break;
    case 2:
    case 3:
        if (func_80101E14(arg0, 0.18f) || func_80101E14(arg0, 0.31f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800700_chwallsnakebaddy);
        }
        if (func_80101E14(arg0, 0.6f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800710_chwallsnakebaddy);
        }
        if (func_80101E14(arg0, 0.999f)) {
            func_80102424(arg0, 1);
            arg0->unk58 = 0.4f;
        }
        break;
    case 4:
    case 5:
        if (func_80101DDC(arg0)) {
            func_80107070(arg0, 3);
        }
        if (func_80101F24(arg0) > 0.7f) {
            arg0->unk64_19 = 0;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_8080027C_chwallsnakebaddy.s")

void func_808004FC_chwallsnakebaddy(Actor *arg0, s32 arg1) {
    extern void _chbaddiesetup_entrypoint_10(void);
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80102424(Actor *, s32);
    s32 func_8010A430(void *);
    void func_8010A570(Actor *);
    extern s32 D_8080079C_chwallsnakebaddy;
    extern s32 D_808007A8_chwallsnakebaddy;
    f32 position[3];

    arg0->unk64_20 = 1;
    func_8010A570(arg0);
    func_80102424(arg0, arg0->unk70_10 == 2 ? 4 : 5);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080079C_chwallsnakebaddy);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808007A8_chwallsnakebaddy);
    if (func_8010A430(arg0)) {
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, arg0->rotation[1], 60.0f);
        _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3,
            ((s32 *)position)[0], ((s32 *)position)[1], ((s32 *)position)[2], ((s32 *)arg0->rotation)[1]);
    }
}

s32 func_808005D8_chwallsnakebaddy(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808004FC_chwallsnakebaddy(Actor *, s32);
    void func_800EEB9C(f32[3], f32, f32);
    void func_80101010(f32 *);
    f32 sp1C[3];
    switch (arg1) {
        case 0x40:
            func_808004FC_chwallsnakebaddy(arg0, arg2);
            break;
        case 0x97:
            func_800EEB9C(sp1C, arg0->rotation[1], 150.0f);
            func_80101010(sp1C);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800650_chwallsnakebaddy()
{
    func_80105010();
}

OSThread *chwallsnakebaddy_entrypoint_0(void)
{
    extern u8 D_808007B4_chwallsnakebaddy[];

    return (OSThread *) D_808007B4_chwallsnakebaddy;
}
