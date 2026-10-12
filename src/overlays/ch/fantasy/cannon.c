#include "common.h"

/* extern */

void func_80800000_chfantasycannon(u8 *arg0) {
    s32 func_800DA298(s32);
    func_800DA298(((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x55D);
}

/* extern */

void func_80800028_chfantasycannon(u8 *arg0) {
    s32 func_800DA544(s32);
    func_800DA544(((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x55D);
}

/* extern */

s32 func_80800050_chfantasycannon(void) {
    s32 func_800F54E4();
    s32 func_800F64DC(s32);
    s32 func_8010C500();
    if (func_8010C500() == 0) {
        return 0;
    }
    if (func_800F64DC(func_800F54E4()) == 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/cannon/func_808000A4_chfantasycannon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/cannon/func_8080010C_chfantasycannon.s")

/* extern */

void func_80800228_chfantasycannon(Actor *arg0) {
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    f32 func_80013970(f32);
    void func_800C3F48(u32);
    s32 func_800D90A4(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F4CC0(s32);
    void func_800F4CEC(s32, u32);
    s32 func_800F54E4();
    s32 func_800F6C5C(s32);
    s32 func_800F7B9C(s32, s32);
    s32 func_800F8294(s32, f32 *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    s32 func_80800050_chfantasycannon();
    s32 func_808000A4_chfantasycannon();
    s32 func_80800544_chfantasycannon(Actor *, s32);
    s32 func_808008B0_chfantasycannon(Actor *);
    f32 temp_f0;
    f32 sp38[3];
    f32 sp34;
    f32 temp_f0_2;
    switch (arg0->unk70_10) {
    case 1:
        if (func_80800050_chfantasycannon(arg0) != 0) {
            func_80800544_chfantasycannon(arg0, 3);
            return;
        }
        temp_f0 = arg0->scale * 226.0f * 0.75f;
        _sudeflect_entrypoint_0(arg0->position, temp_f0, temp_f0, 0xE);
        return;
    case 2:
        if (func_800D90A4(&arg0->unk54) != 0) {
            func_80800544_chfantasycannon(arg0, 3);
            return;
        }
    default:
        return;
    case 3:
        if (func_80101E14(arg0, 0.47f) != 0) {
            func_800C3F48(0x7FFB5E0D);
            func_80800544_chfantasycannon(arg0, 4);
        }
        if (func_80101E14(arg0, 0.16f) != 0) {
            func_800F4CEC(func_800F54E4(), 0x2E);
            arg0->unk64_20 = 0;
        }
        if (func_80101E14(arg0, 0.01f) != 0) {
            func_800C3F48(0x665B5E0C);
        }
        if (func_80101F24(arg0) <= 0.3f) {
            temp_f0_2 = func_800F10B4(func_80101F24(arg0), 0.0f, 0.16f, 0.0f, 1.0f);
            sp34 = temp_f0_2;
            func_800EFE50(sp38, (f32 *)&arg0->actorData[4], arg0->position, temp_f0_2);
            sp38[1] += func_80013970(sp34 * 180.0f) * 300.0f;
            func_800F8294(func_800F54E4(), sp38);
            return;
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            func_80800544_chfantasycannon(arg0, 5);
        } else if (func_80101F24(arg0) >= 0.5f) {
            func_808000A4_chfantasycannon();
            if (!arg0->unk64_20 && (func_80101E14(arg0, 0.5f) != 0)) {
                arg0->unk64_20 = 1;
                func_800F4CC0(func_800F54E4());
            }
        }
        func_800F7B9C(func_800F54E4(), 0x8C);
        func_808008B0_chfantasycannon(arg0);
        return;
    case 5:
        func_808000A4_chfantasycannon();
        if (func_800F6C5C(func_800F54E4()) != 0) {
            func_80800544_chfantasycannon(arg0, 6);
        }
        func_800F7B9C(func_800F54E4(), 0x8C);
        func_808008B0_chfantasycannon(arg0);
        return;
    case 6:
        if (func_800D90A4(&arg0->unk54) != 0) {
            func_80800544_chfantasycannon(arg0, 1);
            return;
        }
        func_808008B0_chfantasycannon(arg0);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/cannon/func_80800544_chfantasycannon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/cannon/func_808008B0_chfantasycannon.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/cannon/func_808009B8_chfantasycannon.s")

OSThread *chfantasycannon_entrypoint_0(void)
{
    extern u8 D_80800D30_chfantasycannon[];

    return (OSThread *) D_80800D30_chfantasycannon;
}

void func_80800B84_chfantasycannon()
{
    func_80101870();
}

void func_80800BA4_chfantasycannon(Actor *arg0) { arg0->rotation[1] = 0.0f; if (arg0->unk74_7 == 0x38) { func_800FFAB0(arg0); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/cannon/func_80800BDC_chfantasycannon.s")

OSThread *chfantasycannon_entrypoint_1(void)
{
    extern u8 D_80800D78_chfantasycannon[];

    return (OSThread *) D_80800D78_chfantasycannon;
}
