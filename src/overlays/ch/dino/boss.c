#include "common.h"

OSThread *chdinoboss_entrypoint_0(void)
{
    extern u8 D_80802B40_chdinoboss[];

    return (OSThread *) D_80802B40_chdinoboss;
}

OSThread *chdinoboss_entrypoint_1(void)
{
    extern u8 D_80802B88_chdinoboss[];

    return (OSThread *) D_80802B88_chdinoboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800018_chdinoboss.s")

void func_80800220_chdinoboss(Actor* arg0) {
    typedef struct {
        u8 pad0[0x110];
        f32 unk110[3];
        s16 unk11C;
        s16 unk11E;
        s32 unk120;
        f32 unk124;
        u8 pad128[8];
        f32 unk130;
    } DinoBossData;
    typedef struct {
        u8 pad0[0xAE];
        u16 flags;
    } DinoBossDefinition;
    extern f32 D_80802A20_chdinoboss[3];
    extern u32 D_80802A2C_chdinoboss[];
    extern u32 D_80802A34_chdinoboss[];
    extern u32 D_80802A58_chdinoboss[];
    extern DinoBossDefinition D_80802A68_chdinoboss;
    extern u8 D_80802BD0_chdinoboss[];
    void* func_80100094(Actor*, u32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    void _subaddieskeleton_entrypoint_2(Unk80132ED0*, s32, f32*);
    void func_800EFD24(f32*);
    s32 func_8010C9B0(f32*, u32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    void func_8010D254(f32*);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    s32 func_80101180(s32, s32, s32);
    u8 func_800D9078(f32*);
    s32 func_800D90A4(f32*);
    u32 func_800FDC28(u32);
    s32 func_80101DDC(Actor*);
    s32 func_80101E14(Actor*, f32);
    void func_80108B04(Actor*, u32);
    void _gcfrontend_entrypoint_9(s32);
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    Actor* _subaddiefind_entrypoint_2(s32, s32);
    f32 func_800D8FF8(void);
    f32 func_800136E4(f32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1F38(f32, f32, f32);
    f32 func_800F2094(f32, f32);
    s32 func_80102CF4(Actor*, f32);
    void func_800E15CC(s32, f32, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800D395C(void);
    s32 func_800C9510(void);
    f32 func_800F1DF4(f32*, f32*);
    void func_800907C0(f32*);
    void func_800906DC(f32*);
    void func_800C964C(s32);
    s32 _subaddiedialog_entrypoint_7(Actor*, f32*, void*);
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    s32 func_801022E4(Actor*);
    void _subaddiemulti_entrypoint_6(f32*, f32);
    void func_80800F70_chdinoboss(Actor*, s32);
    void func_80801660_chdinoboss(Actor*, f32, f32);
    void func_808016C0_chdinoboss(Actor*);
    void func_808017A0_chdinoboss(Actor*);
    void func_808017D0_chdinoboss(Actor*);
    void func_80801800_chdinoboss(Actor*);
    void func_80801830_chdinoboss(Actor*);
    void func_80801860_chdinoboss(Actor*);
    void func_808018D0_chdinoboss(Actor*);
    s32 func_80801C28_chdinoboss(Actor*);
    f32 func_80801C84_chdinoboss(Actor*);
    void func_80801CDC_chdinoboss(Actor*);
    void func_80801D08_chdinoboss(Actor*, s32);
    void func_80801DC8_chdinoboss(Actor*);
    void func_8080248C_chdinoboss(Actor*, s32, s32);
    void func_80802500_chdinoboss(Actor*);
    void func_80802540_chdinoboss(Actor*);
    DinoBossData* sp84;

    sp84 = func_80100094(arg0, 0);
    if (func_800DA298(1)) {
        func_80801CDC_chdinoboss(arg0);
    }

    switch (arg0->unk70_10) {
        case 1: {
            f32 sp78[3];
            f32 sp6C[3];

            _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp84->unk110);
            func_800EFD24(sp78);
            sp78[1] = arg0->position[1];
            if (func_8010C9B0(sp78, 0x6D6) && func_800F64A4(func_800F54E4(), 1)) {
                func_8010D254(sp6C);
                if (sp6C[2] < 1000.0f) {
                    if (func_800DA298(0x172)) {
                        func_8080248C_chdinoboss(arg0, 0xD, 0x30);
                        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1801, 6, arg0->position, 0x57);
                        func_80800F70_chdinoboss(arg0, 3);
                    } else {
                        func_8080248C_chdinoboss(arg0, 0x28, 0x30);
                        func_80800F70_chdinoboss(arg0, 2);
                    }
                    func_80101180(0x461, 8, 0);
                }
            }
            func_808016C0_chdinoboss(arg0);
            break;
        }
        case 2:
        case 3:
            _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp84->unk110);
            func_808016C0_chdinoboss(arg0);
            break;
        case 4:
            func_808016C0_chdinoboss(arg0);
            if (func_800D9078(&arg0->unk58)) {
                func_800FDC28(6);
                func_80800F70_chdinoboss(arg0, 5);
            }
            break;
        case 5:
            func_808017A0_chdinoboss(arg0);
            if (func_80101DDC(arg0)) {
                func_80800F70_chdinoboss(arg0, 6);
            }
            break;
        case 6:
            if (!func_800DA298(0x6AD)) {
                func_80802500_chdinoboss(arg0);
                func_80800F70_chdinoboss(arg0, 7);
                sp84->unk120 = func_80801C28_chdinoboss(arg0);
                func_800DA544(0x172);
                _gcfrontend_entrypoint_9(0x27);
            }
            func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
            func_80801D08_chdinoboss(arg0, 2);
            func_808017D0_chdinoboss(arg0);
            break;
        case 7:
            func_80801D08_chdinoboss(arg0, 2);
            func_808017D0_chdinoboss(arg0);
            if (func_800D9078(&arg0->unk58)) {
                func_80800F70_chdinoboss(arg0, 8);
            }
            break;
        case 8:
            func_80801D08_chdinoboss(arg0, 2);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A34_chdinoboss, 0.65f);
            if (func_80101E14(arg0, 0.7f)) {
                func_80108B04(arg0, 1);
            }
            if (func_80101DDC(arg0)) {
                if (sp84->unk120 > 0) {
                    func_80800F70_chdinoboss(arg0, 7);
                    arg0->unk58 = func_80801C84_chdinoboss(arg0);
                } else {
                    func_80800F70_chdinoboss(arg0, 9);
                }
            }
            break;
        case 9:
            func_80801D08_chdinoboss(arg0, 2);
            func_808017D0_chdinoboss(arg0);
            if (!_subaddiefind_entrypoint_2(0x398, 0) && func_800D9078(&arg0->unk58)) {
                func_80800F70_chdinoboss(arg0, 10);
                arg0->unk58 = 12.0f;
            }
            break;
        case 10: {
            f32 sp68 = func_800D8FF8();

            sp84->unk130 = func_800136E4(sp84->unk130 + sp68 * 16.0f);
            func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
            func_80801D08_chdinoboss(arg0, 1);
            func_80801800_chdinoboss(arg0);
            if (func_800D9078(&arg0->unk58)) {
                if (sp84->unk11E == 0) {
                    func_80800F70_chdinoboss(arg0, 7);
                    sp84->unk120 = func_80801C28_chdinoboss(arg0);
                } else {
                    func_80800F70_chdinoboss(arg0, 11);
                }
            }
            break;
        }
        case 11:
            func_80801D08_chdinoboss(arg0, 0);
            func_808017D0_chdinoboss(arg0);
            if (func_800D9078(&arg0->unk58)) {
                func_80800F70_chdinoboss(arg0, 12);
            }
            break;
        case 12:
            func_80801D08_chdinoboss(arg0, 0);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A34_chdinoboss, 0.65f);
            if (func_80101E14(arg0, 0.7f)) {
                func_80108B04(arg0, 1);
            }
            if (func_80101DDC(arg0)) {
                if (sp84->unk120 > 0) {
                    func_80800F70_chdinoboss(arg0, 12);
                    arg0->unk58 = func_800DC178(0.5f, 1.0f);
                } else {
                    func_80800F70_chdinoboss(arg0, 13);
                }
            }
            break;
        case 13: {
            f32 sp64;
            f32 sp60;
            s32 sp5C;

            sp5C = func_800D9078(&arg0->unk58);
            sp64 = func_800F10B4(arg0->unk58, 0.0f, 4.0f, -70.0f, 0.0f);
            sp60 = func_800F10B4(arg0->unk58, 0.0f, 4.0f, 6500.0f, 0.0f);
            func_80801660_chdinoboss(arg0, sp64, sp60);
            func_80801D08_chdinoboss(arg0, 0);
            func_808017D0_chdinoboss(arg0);
            if (sp5C) {
                func_80800F70_chdinoboss(arg0, 14);
                func_800DA544(0);
            }
            break;
        }
        case 14:
            func_80801D08_chdinoboss(arg0, 0);
            if (!_subaddiefind_entrypoint_2(0x399, 0) && func_800D90A4(&arg0->unk58)) {
                func_80800F70_chdinoboss(arg0, 15);
                func_800DA524(0);
            }
            break;
        case 15: {
            f32 sp58;
            f32 sp54;
            s32 sp50;

            sp50 = func_800D9078(&arg0->unk58);
            sp58 = func_800F10B4(arg0->unk58, 0.0f, 4.0f, 0.0f, -70.0f);
            sp54 = func_800F10B4(arg0->unk58, 0.0f, 4.0f, 0.0f, 6500.0f);
            func_80801660_chdinoboss(arg0, sp58, sp54);
            func_80801D08_chdinoboss(arg0, 0);
            func_808017D0_chdinoboss(arg0);
            if (sp50) {
                func_80800F70_chdinoboss(arg0, 7);
                sp84->unk120 = func_80801C28_chdinoboss(arg0);
            }
            break;
        }
        case 16: {
            f32 sp4C = func_800D8FF8();

            sp84->unk130 = func_800F1F38(sp84->unk130, sp84->unk124, 25.0f * sp4C);
            func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
            func_80801D08_chdinoboss(arg0, 0);
            func_80801830_chdinoboss(arg0);
            if (func_800F2094(sp84->unk130, sp84->unk124) < 1.5f && func_80102CF4(arg0, 4.0f)) {
                arg0->rotation[1] = arg0->unk54;
                func_80800F70_chdinoboss(arg0, 17);
                func_8080248C_chdinoboss(arg0, 10, 0x30);
            }
            break;
        }
        case 17:
            if (_subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A2C_chdinoboss, 0.35f)) {
                func_800E15CC(0, 30.0f, 0.9f);
                func_80018820(0, 2.0f, 0.45f);
            }
            if (func_80101DDC(arg0)) {
                func_80800F70_chdinoboss(arg0, 18);
            }
            break;
        case 18:
            if (func_800D9078(&arg0->unk58)) {
                if (func_800D395C()) {
                    func_80802500_chdinoboss(arg0);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_80800F70_chdinoboss(arg0, 19);
                }
            }
            func_80801860_chdinoboss(arg0);
            break;
        case 19: {
            f32 sp40[3];

            func_80801860_chdinoboss(arg0);
            if (!func_800C9510()) {
                D_80802A68_chdinoboss.flags |= 0x200;
                func_80800F70_chdinoboss(arg0, 21);
                D_80802A68_chdinoboss.flags &= ~0x200;
                func_8080248C_chdinoboss(arg0, 0x13, 0x20);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17B6, 0xE, arg0->position, 0x57);
                func_800EFD24(sp40);
                sp40[1] = func_800F1DF4(D_80802A20_chdinoboss, arg0->position);
                func_800907C0(D_80802A20_chdinoboss);
                func_800906DC(sp40);
                func_800C964C(4);
            }
            break;
        }
        case 20:
            if (_subaddiedialog_entrypoint_7(arg0, arg0->position, D_80802BD0_chdinoboss)) {
                _capod_entrypoint_13(arg0->unk0, NULL, 0x27, 0x20);
            }
            func_808018D0_chdinoboss(arg0);
            func_80802540_chdinoboss(arg0);
            break;
        case 21:
            func_808018D0_chdinoboss(arg0);
            func_80802540_chdinoboss(arg0);
            break;
        case 22:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A58_chdinoboss, 0.45f);
            if (func_80101DDC(arg0)) {
                if (sp84->unk11E == 3) {
                    func_80800F70_chdinoboss(arg0, 11);
                } else {
                    func_80800F70_chdinoboss(arg0, 10);
                }
            }
            break;
        case 23:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A58_chdinoboss, 0.45f);
            if (func_80101DDC(arg0)) {
                func_80800F70_chdinoboss(arg0, 16);
            }
            break;
        case 24:
            func_80802540_chdinoboss(arg0);
            func_808016C0_chdinoboss(arg0);
            break;
        case 25:
            func_80801D08_chdinoboss(arg0, 0);
            func_808017D0_chdinoboss(arg0);
            break;
        case 26:
            func_808016C0_chdinoboss(arg0);
            break;
    }

    func_80801DC8_chdinoboss(arg0);
    switch (func_801022E4(arg0)) {
        case 0x163:
        case 0x1C1:
        case 0x1F7:
            if (!func_800D395C()) {
                break;
            }
        default: {
            f32 sp34[3];

            func_800EFD24(sp34);
            _subaddiemulti_entrypoint_6(sp34, 3062500.0f);
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800C50_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800E2C_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800E88_chdinoboss.s")

void func_80800F28_chdinoboss(Actor *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_80800F70_chdinoboss(Actor*, s32);
    void func_8080248C_chdinoboss(Actor*, s32, s32);
    if (func_800DA298(0xE5) == 0) {
        func_80800F70_chdinoboss(arg0, 0x17);
        func_8080248C_chdinoboss(arg0, 0x2A, 0x438);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80800F70_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801408_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808015AC_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801660_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808016C0_chdinoboss.s")

void func_808017A0_chdinoboss(Actor *arg0) {
    extern u32 D_80802A48_chdinoboss;
    extern u32 D_80802C40_chdinoboss;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802A48_chdinoboss, &D_80802C40_chdinoboss);
}

void func_808017D0_chdinoboss(Actor *arg0) {
    extern u32 D_80802A48_chdinoboss;
    extern u32 D_80802C4C_chdinoboss;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80802A48_chdinoboss, &D_80802C4C_chdinoboss);
}

void func_80801800_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    extern u32 D_80802A48_chdinoboss;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802A48_chdinoboss, 0.23f);
}

void func_80801830_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    extern u32 D_80802A48_chdinoboss;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802A48_chdinoboss, 0.28f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801860_chdinoboss.s")

void func_808018D0_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    extern u32 D_80802C98_chdinoboss;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802C98_chdinoboss, 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801900_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801A44_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801AE4_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801C28_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801C84_chdinoboss.s")

void func_80801CDC_chdinoboss(Actor *arg0) {
    void func_800D2498(u32 itemDisplayUI, u32 value,u32 a2);
    func_800D2498(0xC8U, (u32) arg0->pad5E, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801D08_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801DC8_chdinoboss.s")

void func_80801E90_chdinoboss(s32 arg0, s32 arg1) {
    u32 func_800F54E4(void);
    s32 func_800F5EF8(s32);
    void func_8010FFB0(s32, s32, s32);

    func_8010FFB0(func_800F5EF8(func_800F54E4()), arg0, arg1);
}

/* extern */

void func_80801ECC_chdinoboss(s32 arg0, s32 arg1) {
    s32 func_800F5EF8(s32);
    s32 func_800F6438(s32);
    s32 func_8010FE14(s32, s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_8010FE14(func_800F5EF8(var_s0), arg0, arg1);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

/* extern */

void func_80801F44_chdinoboss(s32 arg0) {
    s32 func_800F5EF8(s32);
    s32 func_800F6438(s32);
    s32 func_8010F9C0(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_8010F9C0(func_800F5EF8(var_s0), arg0);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80801FAC_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_8080232C_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_8080248C_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802500_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802540_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808025E8_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_80802684_chdinoboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/boss/func_808026D0_chdinoboss.s")

void func_80802864_chdinoboss(s32 arg0, s32 arg1) {
    s32 _chappearfx_entrypoint_1(s32, s32, s32, s32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800FFAB0(s32);
    s32 func_80102FDC(s32, s32);
    s32 func_80108528(s32, s32 *, s32, s32 *);
    extern s32 D_80802CA8_chdinoboss;
    s32 sp1C;
    s32 temp_v0;

    if (arg1 == 0) {
        temp_v0 = func_80108528(0x234, &D_80802CA8_chdinoboss, 0x5A, &arg0);
        sp1C = temp_v0;
        func_80102FDC(temp_v0, 0x3F4CCCCD);
        if (_glcutDll_entrypoint_19(0x33) != 0) {
            _chappearfx_entrypoint_1(sp1C, 0x22, 2, 0x3F800000);
            return;
        }
        func_800FFAB0(arg0);
    }
}
