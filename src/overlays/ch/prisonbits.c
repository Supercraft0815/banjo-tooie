#include "common.h"

struct PrisonBitsChoices { u8 values[15]; };

extern u8 D_8011A270[];
extern u32 D_80800F20_chprisonbits[];
void _chdoor_entrypoint_0();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
void _chswitch_entrypoint_6();
void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_808000C0_chprisonbits(Actor *arg0);
void func_808001E0_chprisonbits(s32 arg0);
void func_80800200_chprisonbits(BtIntPtr arg0);
void func_80800224_chprisonbits(Actor *arg0);
s32 func_808002A0_chprisonbits(s32 arg0, s32 arg1, s32 arg2);
void func_8080044C_chprisonbits(Actor *arg0);
void func_80800518_chprisonbits(Actor *arg0);
void func_8080090C_chprisonbits(Actor *arg0);
void func_80800970_chprisonbits(Actor *arg0);
s32 func_808009C4_chprisonbits(Actor *arg0, s32 arg1, s32 arg2);

u32 D_80800F20_chprisonbits[] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x3ECCCCCD, 0x01DA0001, 0x40A66666, 0x01D90001,
    0x40066666, 0x01DB0001, 0x3E99999A, 0x01DA0001,
    0x40A66666, 0x01D90001, 0x3E99999A, 0x01DA0001,
    0x3E99999A, 0x01DA0001, 0x40A66666, 0x01D90001,
    0x40A66666, 0x01D90001,
};

BtFnWord D_80800F78_chprisonbits[] = {
    0x000E011E, 0x06470001, 0x00000000, (BtFnWord)_chdoor_entrypoint_0,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000800, 0x00000000, 0x00000000,
    0x00000000, (BtFnWord)func_80800224_chprisonbits, (BtFnWord)func_80107C2C, 0x80002C02,
    (BtFnWord)_chdoor_entrypoint_1, 0x00000000,
};

BtFnWord D_80800FC0_chprisonbits[] = {
    0x000F011F, 0x06440001, (BtFnWord)D_8011A270, (BtFnWord)_chswitch_entrypoint_6,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000808, 0x00000000, 0x00000000,
    0x00000007, (BtFnWord)func_808000C0_chprisonbits, (BtFnWord)func_80107C2C, 0x80002C02,
    (BtFnWord)func_808002A0_chprisonbits, 0x00000000,
};

BtFnWord D_80801008_chprisonbits[] = {
    0x00130120, 0x06450001, (BtFnWord)D_8011A270, (BtFnWord)_chswitch_entrypoint_6,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000808, 0x00000000, 0x00000000,
    0x00000000, (BtFnWord)func_808001E0_chprisonbits, (BtFnWord)func_80107C2C, 0x80002C02,
    (BtFnWord)func_808002A0_chprisonbits, 0x00000000,
};

BtFnWord D_80801050_chprisonbits[] = {
    0x00150121, 0x06460001, (BtFnWord)D_8011A270, (BtFnWord)_chswitch_entrypoint_6,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000808, 0x00000000, 0x00000000,
    0x00000000, (BtFnWord)func_80800200_chprisonbits, (BtFnWord)func_80107C2C, 0x80002C02,
    (BtFnWord)func_808002A0_chprisonbits, 0x00000000,
};

u32 D_80801098_chprisonbits[] = {
    0x42A00000, 0x42A00000, 0x42A00000, 0x41200000,
};

BtFnWord D_808010A8_chprisonbits[] = {
    0x00360117, 0x066D0003, (BtFnWord)D_80800F20_chprisonbits, (BtFnWord)func_80800518_chprisonbits,
    (BtFnWord)func_8080090C_chprisonbits, (BtFnWord)func_80101870, 0x09C40000, 0x3F800000,
    0x00000000, 0x00000121, (BtFnWord)func_80800970_chprisonbits, 0x00000000,
    0x00340000, (BtFnWord)func_8080044C_chprisonbits, (BtFnWord)func_80107C2C, 0x80004482,
    (BtFnWord)func_808009C4_chprisonbits, 0x00000000,
};

struct PrisonBitsChoices D_808010F0_chprisonbits = {
    {3, 2, 1, 2, 3, 1, 3, 1, 2, 2, 2, 1, 3, 1, 1}
};

u32 D_80801100_chprisonbits[] = {
    0x005B015E, 0x0F160F17, 0x00000281, 0x12080000,
    0x00320000, 0x000C0000, 0x06000000,
};

u32 D_8080111C_chprisonbits[] = {
    0x00130402, 0x001636B0, 0x000A0119, 0x00000000,
};

u32 D_8080112C_chprisonbits[] = {
    0x0013044C, 0x00163A98, 0x00000000,
};

u32 D_80801138_chprisonbits[] = {
    0x0013043A, 0x000D01CC, 0x01FD0000,
};

u32 D_80801144_chprisonbits[] = {
    0x3E8A3D71, 0x3F000000, 0xBF800000,
};

OSThread *chprisonbits_entrypoint_0(void)
{
    return (OSThread *) ((u8 *)D_80800F78_chprisonbits);
}

OSThread *chprisonbits_entrypoint_1(void)
{
    return (OSThread *) ((u8 *)D_80800FC0_chprisonbits);
}

OSThread *chprisonbits_entrypoint_2(void)
{
    return (OSThread *) ((u8 *)D_80801008_chprisonbits);
}

OSThread *chprisonbits_entrypoint_3(void)
{
    return (OSThread *) ((u8 *)D_80801050_chprisonbits);
}

OSThread *chprisonbits_entrypoint_4(void)
{
    return (OSThread *) ((u8 *)D_808010A8_chprisonbits);
}

#ifdef BT_NATIVE
void func_8080003C_chprisonbits(BtIntPtr bt_a0, s32 bt_a1)
#else
void func_8080003C_chprisonbits()
#endif
{
    _chswitch_entrypoint_7();
}

Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);

void func_8080005C_chprisonbits(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *temp_v0;

    temp_v0 = (Actor *) _subaddiefind_entrypoint_2(0x120, 0);
    arg0->position[0] = temp_v0->position[0] + (f32) arg2;
    arg0->position[2] = temp_v0->position[2];
    func_8080003C_chprisonbits(arg0, arg1);
}

void func_808000C0_chprisonbits(Actor *arg0) {
    s32 func_800DA298();
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    struct PrisonBitsChoices choices = D_808010F0_chprisonbits;
    u8 *data;
    u8 *choice;
    s32 i;

    data = func_80100094(arg0, 1);
    data[6] = 0;
    data[0] = 0;
    if (func_800DA564(0x32B, 2) == 0) {
        func_800DA7A8(0x32B, func_800DC128(0, 3) + 1, 2);
    }
    choice = &choices.values[func_800DA564(0x32B, 2) * 5 - 5];
    for (i = 0; i < 5; i++) {
        data[i] = choice[i];
    }
    data[5] = 0;
    func_8080005C_chprisonbits(arg0, 0, -175);
    arg0->unk64_19 = func_800DA298(0xD5);
}

void func_808001E0_chprisonbits(s32 arg0)
{
    func_8080003C_chprisonbits(arg0,1);
}

void func_80800200_chprisonbits(BtIntPtr arg0) {
    func_8080005C_chprisonbits(arg0, 0x2, 175);
}

/* extern */

void func_80800224_chprisonbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(void*, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    void _chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3);
    if (_chdoormake_entrypoint_0(arg0, 90.0f, 0x60U, 0xD5) != 0) {
        _chdoormake_entrypoint_8(arg0, 5);
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_9(arg0, 0, 0, 0x10);
    }
}

s32 func_800DA298();

s32 func_80800280_chprisonbits(s32 arg0)
{
    return func_800DA298(arg0);
}

s32 func_808002A0_chprisonbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800344_chprisonbits(BtIntPtr);

    switch (arg1) {
        case 7:
            func_80101180(0x11F, 0xA, 0);
            break;
        case 0xA:
            func_80800344_chprisonbits(arg0);
            break;
        case 0x91:
            if (func_800DA298(0xD5) != 0) {
                return 0;
            }
        default:
            return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}

void func_80800344_chprisonbits(BtIntPtr arg0) {
    void *func_80100094(Actor *, u32);
    void func_800DA544(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    struct {
        u8 flags[6];
        u8 index;
    } *data;
    u32 result;

    data = func_80100094(arg0, 1);
    if (data->flags[(u32)data->index] != 0) {
        result = func_80800280_chprisonbits(data->flags[(u32)data->index] - 1);
        if (result == 0) {
            result = func_80800280_chprisonbits(data->flags[0] - 1);
            if (result != 0) {
                data->index = 0;
            }
        }
        if (result != 0) {
            if (func_800DA298(0xD5) != 0) {
                data->index = 0;
            } else {
                result = data->index;
                result++;
                result &= 0xFF;
                data->index = result;
                if (data->flags[result] == 0) {
                    func_800DA544(0xD5);
                    func_80101180(0x11E, 7, 0);
                }
            }
        } else {
            if (func_80800280_chprisonbits(0) ||
                func_80800280_chprisonbits(1) ||
                func_80800280_chprisonbits(2)) {
                data->index = 0;
            }
        }
    }
}

void func_8080044C_chprisonbits(Actor *arg0) {
    Prop *_gccubesearch_entrypoint_0(u32, Actor *);
    s32 _glcutDll_entrypoint_20();
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void _susubgame_entrypoint_12(void *arg0, void *arg1);
    s32 func_800EA05C();
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80800DAC_chprisonbits(Actor *);
    struct {
        u8 unk0[0x10];
        f32 position[3];
        u32 subgame;
    } *sp24;

    sp24 = func_80100094(arg0, 0);
    _susubgame_entrypoint_0(arg0, &sp24->subgame, 1);
    _susubgame_entrypoint_12(&sp24->subgame, &(*(s32 *)D_80801098_chprisonbits));
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 0xA);
        return;
    }
    if ((func_800DA298(0x5C) != 0) && (func_800EA05C() == 0xB9)) {
        func_800FFAB0(arg0);
        return;
    }
    func_80800DAC_chprisonbits(arg0);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_0(0x127, arg0), sp24->position);
}

void func_80800518_chprisonbits(Actor *arg0) {
    s32 _capod_entrypoint_22(void);
    s32 _glsplinefind_entrypoint_1(s32);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    f32 func_800D8FF8(void);
    int func_800F0064(f32 *, f32, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80102128(Actor *, s32, s32, f32, s32);
    void func_80102424(Actor *, s32);
    s32 func_80102844(Actor *, f32, s32, f32 *);
    s32 func_80102CF4(Actor *, f32);
    void func_801058C4(Actor *, s32, f32, u32);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010BF4C(Actor *, f32 *, f32, s32, s32);
    void func_8010C820(Actor *, s32, s32);
    s32 func_8010CE70(Actor *, s32, s32);
    int func_80800BB4_chprisonbits(Actor *);
    void func_80800C18_chprisonbits(Actor *);
    s32 func_80800C84_chprisonbits(Actor *);
    void func_80800DAC_chprisonbits(Actor *);
    int func_80800DFC_chprisonbits(Actor *);
    struct {
        f32 origin[3];
        u32 unkC;
        f32 position[3];
        u32 subgame;
    } *sp4C;
    s32 pad;
    f32 sp3C[3];

    sp4C = func_80100094(arg0, 0);
    func_8010C820(arg0, 0x28, 0x1E);
    if (func_80100094(arg0, 1) != NULL) { _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0); }
    switch (arg0->unk70_10) {
        case 3:
            if (!func_80800BB4_chprisonbits(arg0) && !func_80800C84_chprisonbits(arg0)) {
                func_80102128(arg0, 0x1F, 0x11, func_80800DFC_chprisonbits(arg0) ? 1.0f : 0.4f, 2);
            }
            break;
        case 2:
            if (func_80800DFC_chprisonbits(arg0)) {
                ((f32 *)arg0->actorData)[3] = 450.0f;
                func_8010CE70(arg0, (s32)(func_800D8FF8() * 350.0f), -1);
                func_8010B990(arg0, 0x300105);
                func_80800BB4_chprisonbits(arg0);
                break;
            }
            if (!func_80800BB4_chprisonbits(arg0) && !func_80800C84_chprisonbits(arg0)) {
                func_80102128(arg0, 0x1F, 7, 0.3f, 3);
            }
            if ((func_8010BF4C(arg0, sp4C->origin, 420.0f, (s32)(func_800D8FF8() * 350.0f), 0x300105) & 0x24) && func_80102CF4(arg0, 20.0f)) {
                func_80800DAC_chprisonbits(arg0);
            }
            if (func_800F0064(arg0->position, 100.0f, sp4C->origin)) {
                func_80800DAC_chprisonbits(arg0);
            }
            break;
        case 5:
            func_80800C84_chprisonbits(arg0);
            func_8010CE70(arg0, 5, 6);
            break;
        case 6:
            func_8010CE70(arg0, 6, -1);
            break;
        case 7:
            ((f32 *)arg0->actorData)[3] = 350.0f;
            func_80102844(arg0, func_800D8FF8() * 350.0f, -1, sp4C->position);
            func_8010B990(arg0, 5);
            if (func_800F0064(sp4C->position, 120.0f, arg0->position)) {
                _capod_entrypoint_22();
                func_800F7F98(func_800F54E4(), 0);
                _susubgame_entrypoint_5(arg0, &sp4C->subgame, 3, 1, 0x2000);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xF18, 0xE, arg0->position, 0x32);
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            func_80800C18_chprisonbits(arg0);
            func_8010CE70(arg0, 9, -1);
            break;
        case 8:
            func_80102844(arg0, 8.0f, -1, sp4C->position);
            if (func_80102CF4(arg0, 60.0f)) {
                sp3C[0] = sp4C->position[0];
                sp3C[1] = arg0->position[1];
                sp3C[2] = sp4C->position[2];
                ((f32 *)arg0->actorData)[3] = 300.0f;
                func_8010BF4C(arg0, sp4C->position, 300.0f, 6, 0x1005);
                if (func_800F0064(arg0->position, 100.0f, sp3C)) {
                    func_801058C4(arg0, _glsplinefind_entrypoint_1(0x127), ((f32 *)arg0->actorData)[3], 1);
                }
            }
            break;
        case 9:
        case 10:
            break;
    }
}

/* extern */

void func_8080090C_chprisonbits(Actor *arg0) {
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
#ifndef BT_NATIVE
    void func_800DA544(GameFlag);
#endif
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    u8 *sp24;

    func_80105834(arg0);
    if (func_80105A5C(arg0) != 0) {
        sp24 = func_80100094(arg0, 0);
        func_800DA544(0x5C);
        _susubgame_entrypoint_4(arg0, (BtIntPtr)(sp24 + 0x1C));
        func_800FFAB0(arg0);
    }
}

void func_80800970_chprisonbits(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor*, u32);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1U);
    }
    _susubgame_entrypoint_4(arg0, (BtIntPtr) (sp1C + 0x1C));
}

s32 func_808009C4_chprisonbits(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80800CC4_chprisonbits(Actor *, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    void func_80102424(Actor *, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    void _suexpression_entrypoint_14(void *, f32, f32);
    void _suexpression_entrypoint_8(Actor *, u32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    f32 func_8010CD28(Actor *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_5(f32 *);
    f32 sp34[5];
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x2E:
            func_80800CC4_chprisonbits(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x49:
            if (arg2 == 0xC) {
                _susubgame_entrypoint_6(arg0, (u8 *)func_80100094(arg0, 0) + 0x1C, 0x11, 0x2820, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xF42, 0x44, arg0->position, 0x32);
                func_80102424(arg0, 9);
                break;
            }
            return 0;
        case 0x29:
            _suexpression_entrypoint_7(arg0, 1, 0x32);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 0x42340000, 0x41700000);
            _suexpression_entrypoint_14(func_80100094(arg0, 1), 1.0f, 1.0f);
            break;
        case 0x2A:
            _suexpression_entrypoint_8(arg0, 1);
            break;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, data + 0x1C, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x52:
            func_800EFA4C(sp34, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(&(*(s32 *)D_80801098_chprisonbits), arg0->scale);
            _gcdialogcamera_entrypoint_5(sp34);
            break;
        default:
            return 0;
    }
    return 1;
}

int func_80800BB4_chprisonbits(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void *func_80100094(Actor *, u32);
    s32 result;

    result = _subaddiedialog_entrypoint_7((BtIntPtr)arg0, (BtIntPtr)arg0 + 4, &(*(s32 *)D_80801100_chprisonbits));
    if ((result != 0) && (result != 0x1208)) {
        _susubgame_entrypoint_5(arg0, (u8 *)func_80100094(arg0, 0U) + 0x1C, 4, 0, 0);
    }
    return result;
}

void func_80800C18_chprisonbits(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = &arg0->position[0], &(*(u32 *)D_8080111C_chprisonbits), &(*(u32 *)D_80801144_chprisonbits));
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &(*(u32 *)D_8080112C_chprisonbits), 0.75f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &(*(u32 *)D_80801138_chprisonbits), 0.6f);
}

/* extern */

s32 func_80800C84_chprisonbits(Actor *arg0) {
    void func_80102424(Actor *, s32);
    if (func_800DA298(0x514) != 0) {
        func_80102424(arg0, 7);
        return 1;
    }
    return 0;
}

void func_80800CC4_chprisonbits(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void _glcutDll_entrypoint_17(void);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0xF18:
            func_80102424(arg0, 8);
            _susubgame_entrypoint_6(arg0, data + 0x1C, 0xE, 0x2030, 0);
            break;
        case 0xF42:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x1C));
            _glcutDll_entrypoint_17();
            break;
        case 0xF4F:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x1C));
            func_80102424(arg0, 3);
            break;
        default:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)(data + 0x1C));
            func_80102424(arg0, 3);
            break;
    }
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Objprisonbits_func_80800DAC_chprisonbits_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_80800DAC_chprisonbits(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_800CD08C(s32 arg0, f32 *arg1);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_800CD08C(((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1, temp_v0);
    (((Objprisonbits_func_80800DAC_chprisonbits_sp1C *)sp1C)->unk4) = (f32) arg0->position[1];
}

int func_80800DFC_chprisonbits(Actor *arg0) {
    return !func_800DA298(0x5B) && func_80090128() && func_8010C500(arg0);
}

void chprisonbits_entrypoint_5(s32 arg0, s32 arg1) {
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    Actor *actor;

    actor = _subaddiefind_entrypoint_2(0x117, 0);
    if (actor != NULL && func_800DA298(0x6A4) == 0) {
        _susubgame_entrypoint_6(actor, (u8 *)func_80100094(actor, 0) + 0x1C, 2, 0x430, 0);
        _subaddiedialog_entrypoint_11(actor->unk0, 0xF4F, 0x44, actor->position, 0x32);
        func_80102424(actor, 9);
        func_800DA544(0x6A4);
    }
}
