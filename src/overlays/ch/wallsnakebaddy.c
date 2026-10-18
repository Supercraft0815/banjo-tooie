#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wallsnakebaddy/func_80800000_chwallsnakebaddy.s")

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
