#include "common.h"

OSThread *chweldarboss_entrypoint_0(void)
{
    extern u8 D_808047C4_chweldarboss[];

    return (OSThread *) D_808047C4_chweldarboss;
}

OSThread *chweldarboss_entrypoint_1(void)
{
    extern u8 D_8080480C_chweldarboss[];

    return (OSThread *) D_8080480C_chweldarboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80800018_chweldarboss.s")

void func_808002BC_chweldarboss(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(u8 *)((s8 *)(temp_v0) + (0xB0))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xB0))));
    (*(u8 *)((s8 *)(temp_v0) + (0xB1))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xB1))));
    (*(u8 *)((s8 *)(temp_v0) + (0xB2))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xB2))));
}

void func_8080030C_chweldarboss(Actor *arg0)
{
    typedef struct {
        f32 unk0[3];
        u8 padC[0x38];
        f32 unk44[3];
        u8 pad50[0xC];
        f32 unk5C;
        u8 pad60[2];
        u8 unk62;
        u8 unk63;
        u8 pad64[3];
        s8 unk67;
        u8 pad68[6];
        s8 unk6E;
        u8 pad6F;
        u8 unk70;
        u8 pad71[3];
        s16 unk74;
        s16 unk76;
        s16 unk78;
        u8 pad7A[2];
        u8 unk7C;
        u8 pad7D[0x37];
        f32 unkB4;
    } WeldarData;
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    void _chexploder_entrypoint_5(Actor *, s32, f32 *, f32, f32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor*, f32[3], void*);
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    s32 _subaddiefind_entrypoint_9(s32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void func_800BBCB8(f32 *, f32 *, s32, s32, s32 *);
    f32 func_800D8FF8(void);
    u8 func_800D9078(f32*);
    s32 func_800D90A4(f32*);
    s32 func_800DA298(s32 index);
    void func_800DA544(s32);
    void func_800EE7F8(f32[3], f32[3]);
    f32 func_800EF030(f32 *);
    void func_800EF1B8(f32*, f32, f32);
    f32 func_800EFC7C(f32 *, f32 *);
    s32 func_800F0064(f32 *, f32, f32 *);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F1DF4(f32[3], f32[3]);
    s32 func_800F54E4(void);
    void func_800F5A00(s32, f32[3]);
    s32 func_800F64A4(s32 characterIndex, s32 transformationType);
    void func_800F82D4(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80101DDC(Actor*);
    s32 func_80101E14(Actor*, f32);
    void func_80102B2C(Actor*, f32);
    s32 func_80102CF4(Actor *, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_80108B04(Actor*, u32);
    void func_8010A570(Actor*);
    void func_8010A590(Actor *);
    s32 func_8010CA74(f32 *, s32);
    f32 func_8010CD50(Actor*, u32);
    void func_80801AA0_chweldarboss(Actor *, s32);
    void func_80802214_chweldarboss(Actor *, s32, s32);
    void func_808023F8_chweldarboss(Actor *);
    void func_8080247C_chweldarboss(Actor *);
    void func_808026BC_chweldarboss(Actor *);
    void func_80802B1C_chweldarboss(Actor *);
    f32 func_80802C9C_chweldarboss(Actor *, s32);
    void func_80802D2C_chweldarboss(Actor *, s32, s32);
    void func_80802E80_chweldarboss(Actor *);
    void func_80802F14_chweldarboss(Actor *, s32);
    void func_80802FE4_chweldarboss(Actor *, s32);
    void func_808032A8_chweldarboss(Actor *);
    s32 func_808033D8_chweldarboss(Actor *);
    void func_808034A0_chweldarboss(Actor *);
    void func_80803528_chweldarboss(Actor *, f32 *);
    void func_808035D0_chweldarboss(Actor *);
    void func_80803624_chweldarboss(Actor *);
    void func_8080367C_chweldarboss(Actor *);
    void func_80803770_chweldarboss(Actor *);
    int func_80803B48_chweldarboss(s32);
    void func_80803C18_chweldarboss(Actor *);
    void func_80803CF0_chweldarboss(Actor *, s32, s32);
    void func_80803D64_chweldarboss(Actor *);
    s32 func_80803D98_chweldarboss(s32);
    extern f32 B_80804AE0_chweldarboss[3];
    extern s32 D_808047B8_chweldarboss[];
    extern s32 D_80804854_chweldarboss[];
    extern s32 D_80804864_chweldarboss[];
    extern s32 D_80804874_chweldarboss[];
    extern s32 D_80804880_chweldarboss[];
    extern s32 D_808048B4_chweldarboss[];
    extern void _chbaddiesetup_entrypoint_10(void);

    WeldarData *sp94;
    s32 sp90;
    f32 sp84[3];
    f32 sp80;
    s32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    f32 sp60;
    s32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp40[3];
    /* Keep these temporaries in order for the original IDO stack layout. */
    f32 deltaMovement;
    s32 count2;
    f32 value;
    s32 count1;
    f32 angle;

    sp94 = func_80100094(arg0, 0U);
    sp90 = 0;
    sp94->unk78 = func_80803D98_chweldarboss((s32)arg0);
    func_8080367C_chweldarboss(arg0);
    func_800F5A00((s32) sp94->unk78, sp84);
    switch (arg0->unk70_10) {
    case 1:
        if (func_8010CA74(arg0->position, 0x1B58) != 0) {
            sp5C = func_800F54E4();
            if (func_80803B48_chweldarboss(sp5C) != 0) {
                sp5C = func_800F54E4();
                if (func_800F64A4(sp5C, 1) != 0) {
                    func_80801AA0_chweldarboss(arg0, 2);
                }
            }
        }
        break;
    case 2:
        if (sp94->unk70 == 0) {
            sp94->unk70 = 1U;
            func_80101180(0x431, 8, 0);
        }
        break;
    case 3:
        value = func_80802C9C_chweldarboss(arg0, 0);
        sp80 = value * 500.0f;
        value = func_800D8FF8();
        deltaMovement = value * sp80;
        func_800EF1B8(arg0->position, arg0->rotation[1], deltaMovement);
        if (func_800D9078(&sp94->unkB4) != 0) {
            func_80802214_chweldarboss(arg0, 0x1366, 0x44);
        }
        if (func_800F0064(arg0->position, 200.0f, sp94->unk0) != 0) {
            func_80801AA0_chweldarboss(arg0, 4);
        }
        break;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 5);
        }
        break;
    case 5:
        if (func_800DA298(0x6AD) == 0) {
            func_80802214_chweldarboss(arg0, 0x1355, 6);
            func_80801AA0_chweldarboss(arg0, 6);
        }
        break;
    case 7:
        sp7C = func_800F0064(arg0->position, 200.0f, B_80804AE0_chweldarboss);
        func_80802F14_chweldarboss(arg0, 0);
        if (sp7C == 0) {
            sp78 = func_800D8FF8();
            value = func_80802C9C_chweldarboss(arg0, 1);
            sp74 = value * 700.0f;
            value = func_80802C9C_chweldarboss(arg0, 2);
            sp70 = value * 100.0f;
            arg0->unk54 = func_80102D78(arg0, B_80804AE0_chweldarboss);
            func_80102B2C(arg0, sp70 * sp78);
            func_800EF1B8(arg0->position, arg0->rotation[1], sp74 * sp78);
        } else if (func_80101E14(arg0, 0.999f) != 0) {
            func_80801AA0_chweldarboss(arg0, 8);
            sp94->unk63 = func_808033D8_chweldarboss(arg0);
        }
        break;
    case 8:
        sp6C = func_800D8FF8();
        value = func_80802C9C_chweldarboss(arg0, 2);
        sp68 = value * 100.0f;
        arg0->unk54 = func_8010CD50(arg0, (u32) sp94->unk78);
        func_80102B2C(arg0, sp68 * sp6C);
        func_80802F14_chweldarboss(arg0, 0);
        if ((func_80102CF4(arg0, 10.0f) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_80801AA0_chweldarboss(arg0, 9);
        }
        break;
    case 9:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101E14(arg0, 0.3f) != 0) {
            func_80108B04(arg0, 1U);
        }
        if (func_80101DDC(arg0) != 0) {
            sp94->unk63 -= 1;
            if (sp94->unk63 == 0) {
                func_80801AA0_chweldarboss(arg0, 0xA);
            } else {
                func_80801AA0_chweldarboss(arg0, 8);
            }
        }
        break;
    case 10:
        func_80802E80_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0xB);
        }
        break;
    case 11:
        func_80802D2C_chweldarboss(arg0, 0x10, 0xC);
        break;
    case 12:
        func_80802FE4_chweldarboss(arg0, 0xD);
        break;
    case 13:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 8);
            sp94->unk63 = func_808033D8_chweldarboss(arg0);
        }
        break;
    case 14:
        if (func_80101DDC(arg0) != 0) {
            if (sp94->unk7C == 0) {
                sp94->unk7C = 1U;
                func_80803CF0_chweldarboss(arg0, 0x22, 0x30);
                func_80802214_chweldarboss(arg0, 0x1359, 6);
                func_80801AA0_chweldarboss(arg0, 0xF);
            } else {
                func_80803D64_chweldarboss(arg0);
                func_80801AA0_chweldarboss(arg0, 0x12);
                sp94->unk63 = 3U;
            }
        }
        break;
    case 16:
        func_808032A8_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x11);
        }
        break;
    case 17:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4((s32) sp94->unk76, 0);
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 8);
            sp94->unk63 = func_808033D8_chweldarboss(arg0);
            sp94->unk76 = -1;
        }
        break;
    case 18:
        sp64 = func_800D8FF8();
        value = func_80802C9C_chweldarboss(arg0, 2);
        sp60 = value * 100.0f;
        arg0->unk54 = func_8010CD50(arg0, (u32) sp94->unk78);
        func_80102B2C(arg0, sp60 * sp64);
        func_80802F14_chweldarboss(arg0, 0);
        if ((func_80102CF4(arg0, 10.0f) != 0) && (func_80101E14(arg0, 0.999f) != 0)) {
            func_80801AA0_chweldarboss(arg0, 0x13);
        }
        break;
    case 19:
        if (func_80101E14(arg0, 0.3f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, sp94->unk44, D_80804854_chweldarboss);
            func_80108B04(arg0, 2U);
            sp94->unk63 = (u8) (sp94->unk63 - 1);
        }
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            if (sp94->unk63 == 0) {
                func_80801AA0_chweldarboss(arg0, 0x14);
            } else {
                func_80801AA0_chweldarboss(arg0, 0x12);
            }
        }
        break;
    case 20:
        count1 = _subaddiefind_entrypoint_9(0x43F);
        count2 = _subaddiefind_entrypoint_9(0x43E);
        sp5C = _subaddiefind_entrypoint_9(0x440) + count2 + count1;
        func_80802F14_chweldarboss(arg0, 0);
        if (sp5C == 0) {
            func_80801AA0_chweldarboss(arg0, 0x15);
        }
        break;
    case 21:
        func_80802E80_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x16);
        }
        break;
    case 22:
        func_80802D2C_chweldarboss(arg0, 0x1A, 0x17);
        break;
    case 23:
        func_80802FE4_chweldarboss(arg0, 0x18);
        break;
    case 24:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x12);
            sp94->unk63 = 3U;
        }
        break;
    case 25:
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1C);
        }
        break;
    case 26:
        func_808032A8_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1B);
        }
        break;
    case 27:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4((s32) sp94->unk76, 0);
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x12);
            sp94->unk63 = 3U;
            sp94->unk76 = -1;
        }
        break;
    case 28:
        func_80802F14_chweldarboss(arg0, 0);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, (u32 *) D_808047B8_chweldarboss, 0.15f);
        if (func_80101E14(arg0, 0.85f) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1D);
            sp94->unk5C = 3000.0f;
        }
        break;
    case 29:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if ((sp94->unk74 == 0) && (arg0->position[1] > 2750.0f)) {
            if (func_800EF030(sp84) > 360000.0f) {
                sp58 = func_800F1DF4(sp84, B_80804AE0_chweldarboss);
                arg0->position[0] = sp84[0];
                arg0->position[2] = sp84[2];
                func_800EF1B8(arg0->position, sp58, 600.0f);
            }
            sp94->unk74 = 1;
            func_80803D64_chweldarboss(arg0);
        }
        if (sp94->unk74 != 0) {
            if (func_800EFC7C(sp84, arg0->position) > 2500.0f) {
                angle = func_80102D78(arg0, sp84);
                value = func_800D8FF8();
                func_800EF1B8(arg0->position, angle, value * 600.0f);
            }
        }
        if (sp94->unk5C < 0.0f) {
            func_80801AA0_chweldarboss(arg0, 0x1E);
            func_8010A570(arg0);
        }
        break;
    case 30:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if (arg0->position[1] > 1500.0f) {
            if (func_800EFC7C(sp84, arg0->position) > 2500.0f) {
                angle = func_80102D78(arg0, sp84);
                value = func_800D8FF8();
                func_800EF1B8(arg0->position, angle, value * 600.0f);
            }
        }
        func_80803528_chweldarboss(arg0, sp84);
        if (arg0->position[1] < 0.0f) {
            arg0->position[1] = 0.0f;
            func_80802B1C_chweldarboss(arg0);
            func_808035D0_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x1F);
            func_8010A590(arg0);
        }
        break;
    case 31:
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x20);
            arg0->unk58 = 10.0f;
        }
        break;
    case 32:
        sp54 = func_800D8FF8();
        value = func_80802C9C_chweldarboss(arg0, 1);
        sp50 = value * 1400.0f;
        value = func_80802C9C_chweldarboss(arg0, 2);
        sp4C = value * 160.0f;
        arg0->unk54 = func_8010CD50(arg0, (u32) sp94->unk78);
        func_80102B2C(arg0, sp4C * sp54);
        func_800EF1B8(arg0->position, arg0->rotation[1], sp50 * sp54);
        arg0->position[0] = func_800F0D50(arg0->position[0], -2000.0f, 2000.0f);
        arg0->position[2] = func_800F0D50(arg0->position[2], -2000.0f, 2000.0f);
        sp90 = 1;
        func_80802F14_chweldarboss(arg0, 0);
        if (func_800D90A4(&arg0->unk58) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x21);
        }
        break;
    case 33:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, (u32 *) D_808047B8_chweldarboss, 0.15f);
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101E14(arg0, 0.85f) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x22);
            sp94->unk5C = 3000.0f;
        }
        break;
    case 34:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if (func_800EFC7C(B_80804AE0_chweldarboss, arg0->position) > 2500.0f) {
            angle = func_80102D78(arg0, B_80804AE0_chweldarboss);
            value = func_800D8FF8();
            func_800EF1B8(arg0->position, angle, value * 600.0f);
        }
        if (sp94->unk5C < 0.0f) {
            func_80801AA0_chweldarboss(arg0, 0x23);
            func_8010A570(arg0);
        }
        break;
    case 35:
        value = func_800D8FF8();
        sp94->unk5C = (f32) (sp94->unk5C - (value * 1000.0f));
        value = func_800D8FF8();
        arg0->position[1] += value * sp94->unk5C;
        if ((sp94->unk74 == 0) && (arg0->position[1] < 3000.0f)) {
            _subaddieaudioquick_entrypoint_2(arg0, sp94->unk44, D_80804864_chweldarboss);
            sp94->unk74 = 1;
            func_80803CF0_chweldarboss(arg0, 0x3C, 0x30);
        }
        if (arg0->position[1] > 1500.0f) {
            if (func_800EFC7C(B_80804AE0_chweldarboss, arg0->position) > 2500.0f) {
                angle = func_80102D78(arg0, B_80804AE0_chweldarboss);
                value = func_800D8FF8();
                func_800EF1B8(arg0->position, angle, value * 600.0f);
            }
        }
        func_80803528_chweldarboss(arg0, sp84);
        if (arg0->position[1] < 0.0f) {
            arg0->position[1] = 0.0f;
            func_80802B1C_chweldarboss(arg0);
            func_808035D0_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x24);
            func_8010A590(arg0);
        }
        break;
    case 36:
        if (func_80101DDC(arg0) != 0) {
            func_80803D64_chweldarboss(arg0);
            func_80801AA0_chweldarboss(arg0, 0x25);
        }
        break;
    case 37:
        func_80802E80_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x26);
        }
        break;
    case 38:
        func_80802D2C_chweldarboss(arg0, 0x2A, 0x27);
        break;
    case 39:
        func_80802FE4_chweldarboss(arg0, 0x28);
        break;
    case 40:
        func_80802F14_chweldarboss(arg0, 0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x1C);
        }
        break;
    case 41:
        if (func_80101DDC(arg0) != 0) {
            if (sp94->unk62 == 0) {
                func_80801AA0_chweldarboss(arg0, 0x2C);
            } else {
                sp94->unk67 = 1;
                func_80801AA0_chweldarboss(arg0, 0x2D);
            }
        }
        break;
    case 42:
        func_808032A8_chweldarboss(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x2B);
        }
        break;
    case 43:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4((s32) sp94->unk76, 0);
            func_80801AA0_chweldarboss(arg0, 0x1C);
            sp94->unk76 = -1;
        }
        break;
    case 45:
        func_80803624_chweldarboss(arg0);
        break;
    case 46:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800EE7F8(sp40, arg0->position);
            sp40[1] += 300.0f;
            sp94->unk6E = 0;
            _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 5, *(s32 *)&sp40[0], *(s32 *)&sp40[1], *(s32 *)&sp40[2], *(s32 *)&arg0->rotation[1]);
            func_800BBCB8(sp40, sp40, 0x40400000, 1, D_80804880_chweldarboss);
            func_800BBCB8(sp40, sp40, 0x3F800000, 6, D_808048B4_chweldarboss);
            _chexploder_entrypoint_5(arg0, 0x86F, arg0->position, arg0->rotation[1], arg0->scale, 3);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80804874_chweldarboss);
        }
        func_80803624_chweldarboss(arg0);
        break;
    case 47:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800DA544(0x18C);
            func_80101180(0x345, 5, 0);
        }
        break;
    case 48:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_80801AA0_chweldarboss(arg0, 0x31);
        }
        break;
    }
    func_808023F8_chweldarboss(arg0);
    func_8080247C_chweldarboss(arg0);
    func_808026BC_chweldarboss(arg0);
    func_80803770_chweldarboss(arg0);
    func_80803C18_chweldarboss(arg0);
    func_808034A0_chweldarboss(arg0);
    if (sp90 != 0) {
        _sudeflect_entrypoint_1(arg0->position, 600.0f, 0.0f, 600.0f, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_808014CC_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80801944_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80801AA0_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80801F30_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802100_chweldarboss.s")

void func_80802214_chweldarboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    s32 func_800C064C(void);
    s32 func_800C067C(s32 arg0);
    if ((arg1 == 0x1359) && (func_800C064C() == 0x1358)) {
        func_800C067C(0x1358);
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, (u32) arg1, (u32) arg2, arg0->position, 0xB5U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_8080227C_chweldarboss.s")

void func_808023BC_chweldarboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    s32 func_808041C4_chweldarboss(Actor *, s32);
    Actor *temp_v0;

    temp_v0 = _subaddielink_entrypoint_4((u8 *)func_80100094(arg0, 0U) + 0x30);
    if (temp_v0 != NULL) {
        func_808041C4_chweldarboss(temp_v0, arg1);
    }
}

void func_808023F8_chweldarboss(Actor *arg0) {
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 sp2C[3];
    f32 scale;

    if (arg0->unk64_16) {
        func_800EE7F8(sp2C, arg0->position);
        sp2C[1] = 0.0f;
        scale = func_800F10B4(arg0->position[1], 0.0f, 3000.0f, 5.0f, 1.4f) * arg0->scale;
        _chbadshad_entrypoint_1(arg0, sp2C, scale);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_8080247C_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_808026BC_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_808029D8_chweldarboss.s")

void func_80802ABC_chweldarboss(Actor *arg0, f32 arg1) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_808049EC_chweldarboss;
    if (_subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 4), &D_808049EC_chweldarboss, arg1) != 0) {
        func_800E15CC(0, 10.0f, 0.8f);
        func_80018820(0, 0.8f, 0.3f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802B1C_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802C9C_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802D2C_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802E80_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802F14_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80802FE4_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803080_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803184_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_808032A8_chweldarboss.s")

f32 func_80803378_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x6F];
        u8 unk6F;
    } WeldarData;
    void *func_80100094(Actor *, u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    WeldarData *data;

    data = func_80100094(arg0, 0);
    return func_800F10B4(data->unk6F, 1.0f, 6.0f, 0.0f, 3.0f);
}

s32 func_808033D8_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    return ((u8 *)func_80100094(arg0, 0))[0x62] == 0 ? 5 : 8;
}

/* extern */

void func_8080340C_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_808034A0_chweldarboss(Actor *);
    s32 func_800F4AF4(s16, s32);
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x64))) == 0) {
        sp1C = temp_v0;
        func_800F4AF4((*(s16 *)((s8 *)(temp_v0) + (0x78))), 0x14);
        (*(s8 *)((s8 *)(sp1C) + (0x64))) = 1;
    }
    func_808034A0_chweldarboss(arg0);
}

/* extern */

void func_80803460_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800F4B20(u32);
    u8 *temp_v0;
    u8 pad[1];

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x64))) != 0) {
        func_800F4B20((*(s16 *)((s8 *)(temp_v0) + (0x78))));
        (*(s8 *)((s8 *)(temp_v0) + (0x64))) = 0;
    }
}

void func_808034A0_chweldarboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x64];
        u8 unk64;
        u8 pad65[0x13];
        s16 unk78;
    } WeldarCameraData;
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void _plcamera_entrypoint_9(s32, f32 *, f32);
    s32 func_800F5EF8(s32);
    s32 func_80110014(s32 *);
    void func_80116088(u8 *, s32);
    WeldarCameraData *sp34;
    f32 sp28[3];
    s32 pad[2];

    sp34 = func_80100094(arg0, 0U);
    if (sp34->unk64 != 0) {
        func_800EE7F8(sp28, arg0->position);
        sp28[1] += 700.0f;
        _plcamera_entrypoint_9(sp34->unk78, sp28, 0.0f);
        func_80116088(func_80110014(func_800F5EF8(sp34->unk78)), sp28);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803528_chweldarboss.s")

void func_808035D0_chweldarboss(Actor *arg0) {
    void func_800F7B9C(s32, u32);
    void func_800F82D4(s32, s32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    s32 sp18;
    sp1C = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(sp1C) + (0x65))) != 0) {
        sp18 = (*(s16 *)((s8 *)(sp1C) + (0x78)));
        func_800F82D4(sp18, 0);
        func_800F7B9C(sp18, 0x5AU);
        (*(s8 *)((s8 *)(sp1C) + (0x65))) = 0;
    }
}

void func_80803624_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);
    extern s32 D_80804AB4_chweldarboss;
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    (*(s8 *)((s8 *)(sp24) + (0xB1))) = _subaddieaudioloop_entrypoint_7((*(u8 *)((s8 *)(temp_v0) + (0xB1))), arg0->position, (*(u8 *)((s8 *)(temp_v0) + (0x6E))), &D_80804AB4_chweldarboss, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1);
}

void func_8080367C_chweldarboss(Actor *arg0) {
    void func_800D2498(u32 itemDisplayUI, u32 value,u32 a2);
    void *func_80100094(Actor *, u32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if (((s32) temp_t6 >= 7) && ((s32) temp_t6 < 0x2D)) {
        func_800D2498(0xFDU, (u32) (*(u8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x6F))), 0U);
    }
}

void func_808036C8_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _mlwave_entrypoint_0(void *, f32, f32);
    void _mlwave_entrypoint_7(void *, f32);
    void func_800BF744(s32, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(s8 *)((s8 *)temp_v0 + 0x62)) = 1;
    (*(s16 *)((s8 *)temp_v0 + 0xAC)) = 2;
    (*(f32 *)((s8 *)temp_v0 + 0xA8)) = 10.0f;
    _mlwave_entrypoint_0(temp_v0 + 0x88, 300.0f, 300.0f);
    _mlwave_entrypoint_7(sp1C + 0x88, 0.25f);
    func_800BF744(3, 1);
}

void func_8080373C_chweldarboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (0xAC))) = 4;
    (*(f32 *)((s8 *)(temp_v0) + (0xA8))) = 2.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803770_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_808038F8_chweldarboss.s")

/* extern */

int func_80803B48_chweldarboss(s32 arg0) {
    f32 func_800F5628(s32);
    s32 func_800F6478(s32);
    s32 func_800F6C5C(s32);

    if ((func_800F6478(arg0) == 0) || (func_800F6C5C(arg0) == 0)) {
        return 0;
    }
    return func_800F5628(arg0) < 50.0f;
}

void chweldarboss_entrypoint_2(s32 arg0, s32 arg1, u32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor* func_80106790(Unk80132ED0 *);
    u32 temp_a0;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((s8 *)(func_80100094(func_80106790(arg4), 0U)) + (0xAF)));
    temp_a0 = (arg3 * 0x10) + arg2;
    if (arg2 < temp_a0) {
        do {
            arg2 += 0x10;
            (*(u8 *)((s8 *)(arg2) + (-1))) = temp_v1;
        } while (arg2 < temp_a0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803C18_chweldarboss.s")

void func_80803CF0_chweldarboss(Actor *arg0, s32 arg1, s32 arg2)
{
  void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
  void _capod_entrypoint_14(void);
  void *func_80100094(Actor *, u32);
  u8 *sp1C;
  u8 *temp_v0;
  temp_v0 = func_80100094(arg0, 0U);
  sp1C = temp_v0;
  arg2 = arg2;
  if ((*((s16 *) (((s8 *) temp_v0) + 0x72))) != 0)
  {
    _capod_entrypoint_14();
    arg2 = arg2 | 0x2000;
  }
  _capod_entrypoint_13(arg0->unk0, NULL, (u32) arg1, (u32) arg2);
  *((s16 *) (((s8 *) sp1C) + 0x72)) = 1;
}

void func_80803D64_chweldarboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(s16 *)((s8 *)(temp_v0) + (0x72))) != 0) {
        (*(s16 *)((s8 *)(temp_v0) + (0x72))) = 0;
        _capod_entrypoint_14();
    }
}

/* extern */

s32 func_80803D98_chweldarboss(s32 arg0) {
    s32 func_800F54E4();
    s32 func_8010D290(s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_8010D290(0x10000);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800F54E4();
    }
    return var_v1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803DD8_chweldarboss.s")

/* extern */

void func_80803E50_chweldarboss(Actor *arg0) {
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_808041C4_chweldarboss(Actor *, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(f32 *)((s8 *)(temp_v0) + (8))) = 0.0f;
    func_808041C4_chweldarboss(arg0, 1);
    _subaddielink_entrypoint_1(sp1C, arg0->unk3C);
    arg0->unk3C = NULL;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_80803EA4_chweldarboss.s")

u32 func_808040F4_chweldarboss(s32 unused, s32 arg1, s32 arg2) {
    void func_80804230_chweldarboss(Actor *);

    if (arg1 == 0x95) {
        func_80804230_chweldarboss((Actor *) unused);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_8080412C_chweldarboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/weldarboss/func_808041C4_chweldarboss.s")

/* extern */

void func_80804230_chweldarboss(Actor *arg0) {
    s32 func_800C8A98(void);
    s32 func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    u8 *sp1C;
    s32 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    _subaddielink_entrypoint_3(temp_v0);
    temp_v0_2 = func_800C8A98();
    (*(s32 *)((s8 *)(sp1C) + (0xC))) = temp_v0_2;
    func_800C8FE0(temp_v0_2, 0);
}
