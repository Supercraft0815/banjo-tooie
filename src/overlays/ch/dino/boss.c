#include "common.h"

void func_80800220_chdinoboss(Actor* arg0);
void func_80105834(Actor *);
void func_80101870(Actor *, void *);
OSThread *func_80108ED0(void);
void func_80800018_chdinoboss(Actor *arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80800C50_chdinoboss(Actor *arg0, s32 arg1, s32 arg2);
void func_80802684_chdinoboss(Actor *arg0);
void func_8010A730(s32, s32);
void func_808025E8_chdinoboss(Actor *arg0);
s32 func_808026D0_chdinoboss(Actor *arg0, s32 arg1, s32 arg2);

f32 D_80802A20_chdinoboss[] = {
    300.0f, 10.0f, -150.0f
};

u32 D_80802A2C_chdinoboss[] = {
    0x00130417, 0x00020000
};

u32 D_80802A34_chdinoboss[] = {
    0x00130538, 0x00020016, 0x7530000D, 0x00F3010C,
    0x00000000
};

u32 D_80802A48_chdinoboss[] = {
    0x001303FF, 0x000D0073, 0x008C0002, 0x00000000
};

u32 D_80802A58_chdinoboss[] = {
    0x00130539, 0x00020018, 0x000D00F3, 0x010C0000
};

u32 D_80802A68_chdinoboss[] = {
    0x00000000, 0x00000000, 0x411CCCCD, 0x01630001,
    0x411CCCCD, 0x01630001, 0x411CCCCD, 0x01630001,
    0x411CCCCD, 0x01630001, 0x40000000, 0x01620002,
    0x408CCCCD, 0x01610301, 0x4099999A, 0x01610001,
    0x3F800000, 0x015F0042, 0x408CCCCD, 0x01610001,
    0x3EE66666, 0x01600001, 0x408CCCCD, 0x01610001,
    0x3F800000, 0x015F0042, 0x408CCCCD, 0x01610001,
    0x408CCCCD, 0x01610001, 0x408CCCCD, 0x01610001,
    0x3F666666, 0x015E0001, 0x3F800000, 0x015D0302,
    0x413BAE14, 0x01C10001, 0x413BAE14, 0x01C10001,
    0x40E75C29, 0x01F70001, 0x40E75C29, 0x01F70001,
    0x3F000000, 0x015C0002, 0x3F000000, 0x015C0002,
    0x411CCCCD, 0x01630001, 0x408CCCCD, 0x01610001,
    0x411CCCCD, 0x01630001
};

BtFnWord D_80802B40_chdinoboss[] = {
    0x02FA036F, 0x06DA0001, (BtFnWord)D_80802A68_chdinoboss, (BtFnWord)func_80800220_chdinoboss,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00010568, 0x00000000, (BtFnWord)func_80108ED0,
    0x01780000, (BtFnWord)func_80800018_chdinoboss, (BtFnWord)func_80107C2C, 0x80210420,
    (BtFnWord)func_80800C50_chdinoboss, 0x00000000
};

BtFnWord D_80802B88_chdinoboss[] = {
    0x009F03D8, 0x00000001, 0x00000000, (BtFnWord)func_80802684_chdinoboss,
    (BtFnWord)func_80105834, (BtFnWord)func_8010A730, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, (BtFnWord)func_808025E8_chdinoboss, (BtFnWord)func_80107C2C, 0x80000602,
    (BtFnWord)func_808026D0_chdinoboss, 0x00000000
};

u8 D_80802BD0_chdinoboss[] = {
    0, 0, 9, 196,
    0, 0, 23, 183,
    0, 0, 6, 1,
    18, 11, 0, 0,
    0, 87, 0, 0,
    0, 14, 34, 40,
    21, 0, 0, 0
};

u32 D_80802BEC_chdinoboss[] = {
    0x001304AA, 0x00020000
};

u32 D_80802BF4_chdinoboss[] = {
    0x00130535, 0x0002000D, 0x00F3010C, 0x00000000
};

u32 D_80802C04_chdinoboss[] = {
    0x00130534, 0x00020018, 0x000D00F3, 0x010C0000
};

u32 D_80802C14_chdinoboss[] = {
    0x3D3851EC, 0x3DB43958, 0x3E0D4FDF, 0x3E3D70A4,
    0xBF800000
};

u32 D_80802C28_chdinoboss[] = {
    0x3E99999A, 0x3EBD70A4, 0xBF800000
};

u32 D_80802C34_chdinoboss[] = {
    0x3F400000, 0x3F6B851F, 0xBF800000
};

u32 D_80802C40_chdinoboss[] = {
    0x3E99999A, 0x3F266666, 0xBF800000
};

u32 D_80802C4C_chdinoboss[] = {
    0x3C23D70A, 0x3E3851EC, 0x3EB33333, 0x3F051EB8,
    0x3F2E147B, 0x3F570A3D, 0xBF800000
};

u32 D_80802C68_chdinoboss[] = {
    0x00130512, 0x0002000D, 0x00C000D9, 0x00000000
};

u32 D_80802C78_chdinoboss[] = {
    0x00130551, 0x0002000D, 0x00F3010C, 0x00000000
};

u32 D_80802C88_chdinoboss[] = {
    0x3EE147AE, 0x3F000000, 0x3F0F5C29, 0xBF800000
};

u32 D_80802C98_chdinoboss[] = {
    0x00130535, 0x0002000D, 0x009900B3, 0x00000000
};

f32 D_80802CA8_chdinoboss[] = {
    -6700.0f, 1300.0f, -4400.0f, 0.0f,
    0.0f, 0.0f
};

void _glcutDll_entrypoint_6(u32, u32);

s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
void _glcutDll_entrypoint_17(void);
s32 func_800EA05C();

OSThread *chdinoboss_entrypoint_0(void)
{
    return (OSThread *) D_80802B40_chdinoboss;
}

OSThread *chdinoboss_entrypoint_1(void)
{
    return (OSThread *) D_80802B88_chdinoboss;
}

void func_80800018_chdinoboss(Actor *arg0) {
    typedef struct {
        s16 count;
        f32 positions[20][3];
        u8 padF4[0x10];
        f32 position[3];
        f32 unk110[3];
        s16 unk11C;
        u8 pad11E[0x1A];
        s16 unk138;
        u8 pad13A[0x2A];
        s16 unk164;
    } DinoBossData;
    s32 _chintrotext_entrypoint_2(s32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _glcutDll_entrypoint_20(void);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE88C(f32 *, s16 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    void func_80109EEC(s16 *, s32);
    void func_80109FE8(void **, s32);
    s32 func_80800E2C_chdinoboss(void);
    void func_80800F70_chdinoboss(Actor *, s32);
    void func_8080248C_chdinoboss(Actor *, s32, s32);
    Prop *props[20];
    DinoBossData *data;
    s32 i;

    data = func_80100094(arg0, 0);
    func_80102FDC(arg0, arg0->scale * 1.25f);
    func_800EE7F8(data->position, arg0->position);
    data->unk138 = 0;
    data->unk164 = 1;
    func_800DA524(1);
    arg0->pad5E = 0x1E;
    data->unk11C = arg0->pad5E;
    data->unk138 = 0;
    func_80109EEC(arg0, 0x40);
    func_80109FE8(arg0, 0);
    if (_glcutDll_entrypoint_20()) {
        func_80102424(arg0, 0x1A);
    } else if (func_800D395C()) {
        if (func_800DA298(0x172)) {
            func_8080248C_chdinoboss(arg0, 0xD, 0x30);
            func_80800F70_chdinoboss(arg0, 3);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1801, 6, arg0->position, 0x57);
        } else {
            func_8080248C_chdinoboss(arg0, 0x28, 0x30);
            func_80800F70_chdinoboss(arg0, 2);
        }
    } else if (func_800DA298(0xE5)) {
        func_80101FDC(arg0, 0x14);
        func_80109EEC(arg0, 1);
        if (func_80800E2C_chdinoboss() == 4) {
            func_80101FDC(arg0, 0x18);
        }
    }
    if (!func_800D395C() && !_glcutDll_entrypoint_20()) {
        _chintrotext_entrypoint_2(1);
    }
    data->count = _gccubesearch_entrypoint_9(0x154, props, 20);
    for (i = 0; i < data->count; i++) {
        func_800EE88C(data->positions[i], props[i]->position);
    }
}

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

    void* func_80100094(Actor*, u32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 *arg2);
    void func_800EFD24(f32*);
    s32 func_8010C9B0(f32*, u32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_8010D254(f32*);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 func_80101180(s32, s32, BtIntPtr);
    u8 func_800D9078(f32*);
    s32 func_800D90A4(f32*);
    u32 func_800FDC28(u32);
    s32 func_80101DDC(Actor*);
    s32 func_80101E14(Actor*, f32);
    void func_80108B04(Actor*, u32);
    void _gcfrontend_entrypoint_9(s32);
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);
    Actor* _subaddiefind_entrypoint_2(s32, BtIntPtr);
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
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
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
                ((DinoBossDefinition *)D_80802A68_chdinoboss)->flags |= 0x200;
                func_80800F70_chdinoboss(arg0, 21);
                ((DinoBossDefinition *)D_80802A68_chdinoboss)->flags &= ~0x200;
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

s32 func_80800C50_chdinoboss(Actor *arg0, s32 arg1, s32 arg2) {
    void _glcutDll_entrypoint_6(u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 func_800D395C(void);
    u32 func_800FDC28(u32 arg0);
    void func_80800E88_chdinoboss(void *arg0, s32 arg1);
    void func_80800F28_chdinoboss(Actor *arg0, s32 arg1);
    void func_80800F70_chdinoboss(Actor *arg0, s32 arg1);
    void func_80801408_chdinoboss(Actor *arg0, s32 arg1, s32 arg2);
    void func_80801900_chdinoboss(Actor *arg0);
    void func_8080248C_chdinoboss(Actor *arg0, s32 arg1, s32 arg2);
    void func_80802500_chdinoboss(Actor *arg0);
    switch ((int)arg1) {
    default:
        return 0;
    case 0x3F:
        func_80800E88_chdinoboss(arg0, arg2);
        break;
    case 0x40:
        func_80800F28_chdinoboss(arg0, arg2);
        break;
    case 0xB:
        switch ((int)arg2) {
        case 11:
            func_80802500_chdinoboss(arg0);
            _glcutDll_entrypoint_6(0x112, 0x33);
            return 4;
        case 40:
            func_8080248C_chdinoboss(arg0, 1, 0x30);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17B3, 6, arg0->position, 0x57);
            func_80800F70_chdinoboss(arg0, 3);
            return 4;
        default:
            return 3;
        }
    case 0x2E:
        func_80801408_chdinoboss(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x31:
        func_8080248C_chdinoboss(arg0, 0x1B, 0x30);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17DF, 6, arg0->position, 0x57);
        break;
    case 0x3D:
        func_80801900_chdinoboss(arg0);
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x4E, arg0->position, 0x57);
        break;
    case 0x9F:
        func_800FDC28(0);
        func_80800F70_chdinoboss(arg0, 0x19);
        break;
    }
    return 1;
}

/* extern */

s32 func_80800E2C_chdinoboss(void) {
    s32 func_800DA564(s32, s32);
    volatile s32 sp1C;
    s32 temp_v0;
    s32 var_v1;

    sp1C = 0;
    temp_v0 = func_800DA564(0x175, 4);
    var_v1 = sp1C;
    if (temp_v0 & 1) {
        var_v1 = 1;
    }
    if (temp_v0 & 2) {
        var_v1 += 1;
    }
    if (temp_v0 & 4) {
        var_v1 += 1;
    }
    if (temp_v0 & 8) {
        var_v1 += 1;
    }
    return var_v1;
}

void func_80800E88_chdinoboss(void *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x11E];
        s16 hitCount;
    } DinoBossData;
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    void func_80109FE8(void **, s32);
    void func_80800F70_chdinoboss(Actor *, s32);
    DinoBossData *sp24;
    Actor *actor = arg0;

    sp24 = func_80100094(actor, 0);
    if (func_800DA298(0xE5) == 0 && actor->unk70_10 == 0xA) {
        sp24->hitCount++;
        if (sp24->hitCount == 3) {
            func_80109FE8(arg0, 0);
        }
        if (actor->unk70_10 != 0x16) {
            func_80800F70_chdinoboss(actor, 0x16);
        }
    }
}

void func_80800F28_chdinoboss(Actor *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_80800F70_chdinoboss(Actor*, s32);
    void func_8080248C_chdinoboss(Actor*, s32, s32);
    if (func_800DA298(0xE5) == 0) {
        func_80800F70_chdinoboss(arg0, 0x17);
        func_8080248C_chdinoboss(arg0, 0x2A, 0x438);
    }
}

void func_80800F70_chdinoboss(Actor *arg0, s32 arg1) {
    typedef struct {
        s16 unk0;
        s16 unk2;
        u8 pad4[0x100];
        f32 unk104[3];
        f32 unk110[3];
        s16 unk11C;
        s16 unk11E;
        s32 unk120;
        f32 unk124;
        BT_BITFIELD_ORDER(u32 initialized : 1, u32 pad128_16 : 11);
        BT_BITFIELD_ORDER(u32 dialog12 : 1, u32 dialog15 : 1);
        u32 pad128_28 : 2;
        BT_BITFIELD_ORDER(u32 dialog15 : 1, u32 dialog12 : 1);
        BT_BITFIELD_ORDER(u32 pad128_16 : 11, u32 initialized : 1);
        u8 unk12A;
        u8 pad12B;
        f32 unk12C;
        f32 unk130;
        f32 unk134;
    } DinoBossData;
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    s32 func_800C064C(void);
    s32 func_800C067C(s32);
    void func_800C964C(s32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EFD24(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80109EEC(s16 *, s32);
    void func_80109FE8(void **, s32);
    void func_808015AC_chdinoboss(Actor *);
    void func_80801660_chdinoboss(Actor *, f32, f32);
    void func_80801AE4_chdinoboss(Actor *);
    s32 func_80801C28_chdinoboss(Actor *);
    void func_80801CDC_chdinoboss(Actor *);
    void func_80801FAC_chdinoboss(Actor *, s32, s32);
    void func_8080248C_chdinoboss(Actor *, s32, s32);
    DinoBossData *data;
    s32 sp48;
    s32 sp44;
    f32 sp3C[2];
    f32 sp30[3];

    data = func_80100094(arg0, 0);
    sp48 = 0;
    sp44 = 0;
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 3:
        func_800FDC28(1);
        break;
    case 4:
        func_8080248C_chdinoboss(arg0, 4, 0x30);
        break;
    case 5:
        func_800DA544(1);
        break;
    case 6:
        if (func_800DA298(0x172) == 0) {
            _chintrotext_entrypoint_1(0x18B9, 1, 1, 0);
        }
        func_808015AC_chdinoboss(arg0);
        break;
    case 7:
        data->unk12C = 30.0f;
        data->unk134 = 2500.0f;
        func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
        arg0->unk58 = func_800DC178(2.0f, 4.0f);
        sp48 = 1;
        break;
    case 8:
        data->unk120--;
        sp48 = 1;
        break;
    case 9:
        arg0->unk58 = 0.7f;
        data->unk11E = 0;
        sp48 = 1;
        break;
    case 10:
        data->unk12C = 40.0f;
        data->unk134 = 3500.0f;
        func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
        if (data->unk12A == 0) {
            data->unk12A = 1;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17FC, 0x44, arg0->position, 0x57);
        }
        func_80109FE8(arg0, 1);
        data->unk11C = arg0->pad5E;
        break;
    case 11:
        data->unk12C = 30.0f;
        data->unk134 = 2500.0f;
        func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
        func_80109FE8(arg0, 0);
        arg0->unk58 = func_800DC178(1.0f, 2.0f);
        data->unk2 = func_80801C28_chdinoboss(arg0);
        data->unk120 = data->unk2;
        func_80801AE4_chdinoboss(arg0);
        sp48 = 1;
        sp44 = 1;
        break;
    case 12:
        if (!data->dialog12) {
            data->dialog12 = 1;
            if (func_800C064C() == 0x17FC) {
                func_800C067C(0x17FC);
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17B4, 0x44, arg0->position, 0x57);
        }
        data->unk120--;
        sp48 = 1;
        sp44 = 1;
        break;
    case 13:
        data->unk12C = 40.0f;
        data->unk134 = 3500.0f;
        func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
        arg0->unk58 = 4.0f;
        sp48 = 2;
        sp44 = 1;
        break;
    case 14:
        arg0->unk64_16 = 0;
        arg0->unk58 = 2.0f;
        break;
    case 15:
        if (!data->dialog15) {
            data->dialog15 = 1;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1802, 0x44, arg0->position, 0x57);
        }
        arg0->unk64_16 = 1;
        arg0->unk58 = 4.0f;
        sp48 = 3;
        sp44 = 1;
        break;
    case 23:
        func_800EFD24(sp30);
        func_800F18FC(data->unk110, sp30, sp3C);
        data->unk12C = func_800136E4(-sp3C[0]);
        data->unk134 = func_800EEF94(data->unk110);
        data->unk124 = func_80013728(data->unk124);
        func_80801660_chdinoboss(arg0, 0.0f, 0.0f);
        func_80109EEC(arg0, 1);
        func_80109FE8(arg0, 0);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17B5, 0x44, arg0->position, 0x57);
        func_800DA544(0xE5);
        func_800DA524(1);
        func_800FDC28(0);
        arg0->pad5E = 0;
        func_80801CDC_chdinoboss(arg0);
        break;
    case 16:
        sp44 = 1;
        break;
    case 17:
        func_800EE7F8(arg0->position, data->unk104);
        break;
    case 18:
        arg0->unk58 = 10.0f;
        break;
    case 19:
        func_800C964C(3);
        break;
    }
    func_80801FAC_chdinoboss(arg0, sp48, sp44);
}

void func_80801408_chdinoboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    s32 func_800DA298(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_8080248C_chdinoboss(Actor *, s32, s32);

    switch (arg1) {
    case 0x17B3:
    case 0x1801:
        func_80800F70_chdinoboss(arg0, 4);
        arg0->unk58 = 0.75f;
        break;
    case 0x17B6:
        func_800D1000(0x2C, 1, NULL, 1, 0);
        func_8080248C_chdinoboss(arg0, 0xB, 0x10);
        func_80800F70_chdinoboss(arg0, 0x14);
        func_80101180(0x461, 7, 0);
        func_80101180(0x469, 7, 0);
        break;
    case 0x120B:
    case 0x17B7:
        func_80800F70_chdinoboss(arg0, 0x14);
        _capod_entrypoint_14();
        break;
    case 0x17DF:
        func_800D1000(0x2F, 1, NULL, 1, 0);
        func_8080248C_chdinoboss(arg0, 0x22, 0x10);
        func_80102424(arg0, 0x18);
        break;
    case 0xCEB:
        if (arg2 > 0) {
            _gcfrontend_entrypoint_11();
        } else {
            _gcfrontend_entrypoint_10();
        }
        break;
    case 0x17B4:
    case 0x17B5:
    case 0x17FC:
        break;
    default:
        if (func_800DA298(0xE5) != 0) {
            func_80800F70_chdinoboss(arg0, 0x14);
        }
        break;
    }
}

void func_808015AC_chdinoboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x110];
        f32 position[3];
        u8 pad11C[8];
        f32 unk124;
        BT_BITFIELD_ORDER(u32 initialized : 1, u32 pad128 : 31);
        BT_BITFIELD_ORDER(u32 pad128 : 31, u32 initialized : 1);
        f32 unk12C;
        f32 unk130;
        f32 unk134;
    } DinoBossData;
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    f32 func_800EEF94(f32 *);
    DinoBossData *data;
    f32 sp38;
    f32 sp2C[3];
    f32 *sp20;

    data = func_80100094(arg0, 0);
    if (!data->initialized) {
        data->initialized = 1;
        sp20 = arg0->position;
        func_800EE7F8(sp20, data->position);
        func_800EFD24(sp2C);
        func_800F18FC(sp20, sp2C, &sp38);
        data->unk124 = data->unk130 = func_800136E4(arg0->rotation[1] + 180.0f);
        data->unk12C = func_80013728(-sp38);
        data->unk134 = func_800EEF94(sp20);
    }
}

void func_80801660_chdinoboss(Actor *arg0, f32 arg1, f32 arg2) {
    void func_800EEC30(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 *data;

    data = func_80100094(arg0, 0);
    func_800EEC30(arg0->position, data[0x12C / 4] + arg1, data[0x130 / 4], data[0x134 / 4] + arg2);
}

void func_808016C0_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_800E15CC(s32, f32, f32);
    void func_80018820(s32, f32, f32);

    f32 *temp_s1;

    temp_s1 = arg0->position;
    if (_subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80802A2C_chdinoboss, 0.94f) != 0) {
        func_800E15CC(0, 30.0f, 0.9f);
        func_80018820(0, 1.0f, 0.3f);
    }
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80802BEC_chdinoboss, D_80802C28_chdinoboss);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80802A48_chdinoboss, D_80802C14_chdinoboss);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80802BF4_chdinoboss, D_80802C34_chdinoboss);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80802C04_chdinoboss, 0.07f);
}

void func_808017A0_chdinoboss(Actor *arg0) {

    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80802A48_chdinoboss, D_80802C40_chdinoboss);
}

void func_808017D0_chdinoboss(Actor *arg0) {

    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80802A48_chdinoboss, D_80802C4C_chdinoboss);
}

void func_80801800_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);

    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A48_chdinoboss, 0.23f);
}

void func_80801830_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);

    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802A48_chdinoboss, 0.28f);
}

void func_80801860_chdinoboss(Actor *arg0) {
    f32 *sp1C[1];
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);

    sp1C[0] = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[0], D_80802A2C_chdinoboss, 0.8f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[0], D_80802C68_chdinoboss, 0.65f);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[0], D_80802C78_chdinoboss, D_80802C88_chdinoboss);
}

void func_808018D0_chdinoboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor*, f32*, u32*, f32);

    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802C98_chdinoboss, 0.1f);
}

void func_80801900_chdinoboss(Actor *arg0) {
    typedef struct {
        u32 unk0;
        f32 positions[20][3];
        s16 indices[22];
        s32 index;
    } DinoBossData;
    typedef struct {
        u8 pad18[0x10];
        f32 velocity[3];
    } ProjectileData;
    void *func_80100094(Actor *, u32);
    void func_80801A44_chdinoboss(Actor *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void _subaddieskeleton_entrypoint_1(Actor *, s32, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    f32 func_800DC178(f32, f32);
    void func_80102FDC(Actor *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EF368(f32 *, f32);
    Actor *projectile;
    DinoBossData *data;
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp28[2];

    data = func_80100094(arg0, 0);
    if (arg0->unk70_10 == 8) {
        func_80801A44_chdinoboss(arg0, sp30);
    } else {
        func_800EE7F8(sp30, data->positions[data->indices[data->index]]);
    }
    _subaddieskeleton_entrypoint_1(arg0, 5, sp3C);
    func_800F18FC(sp3C, sp30, sp28);
    projectile = func_80108528(0x398, sp3C, (s32)sp28[1], &arg0);
    func_80102FDC(projectile, func_800DC178(2.0f, 4.0f));
    func_800EFB24(((ProjectileData *)projectile->actorData)->velocity, sp30, sp3C);
    func_800EF368(((ProjectileData *)projectile->actorData)->velocity, 3500.0f);
    if (arg0->unk70_10 == 8) {
        projectile->unk64_20 = 0;
    } else {
        projectile->unk64_20 = 1;
    }
}

void func_80801A44_chdinoboss(Actor *arg0, f32 *arg1) {
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    void func_800EE7F8(f32 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    void func_8010D09C(BtIntPtr, f32 *, f32);
    void func_8010D254(f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_8010D09C(func_800F54E4(), sp28, 1.0f);
    func_800EE7F8(sp34, sp28);
    sp34[1] += 400.0f;
    sp28[1] -= 350.0f;
    if (func_800C6A7C(sp34, sp28, sp1C, arg0->unk14) != NULL) {
        func_800EE7F8(arg1, sp28);
        return;
    }
    func_8010D254(arg1);
}

void func_80801AE4_chdinoboss(Actor *arg0) {
    typedef struct {
        s16 count;
        s16 selectedCount;
        f32 positions[20][3];
        s16 selected[14];
    } DinoBossPoints;
    void *func_80100094(Actor *, u32);
    void func_8010D254(f32 *);
    s32 func_800DC128(s32, s32);
    f32 func_800EEB40(f32 *, f32 *);
    DinoBossPoints *data;
    s32 i;
    s32 j;
    s32 valid;
    s32 index;
    f32 position[3];

    data = func_80100094(arg0, 0);
    func_8010D254(position);
    for (i = 0; i < data->selectedCount; i++) {
        data->selected[i] = -1;
        do {
            index = func_800DC128(0, data->count);
            valid = 1;
            for (j = i - 1; j >= 0; j--) {
                if (index == data->selected[j]) {
                    valid = 0;
                    break;
                }
            }
            if (valid) {
                if (func_800EEB40(position, data->positions[index]) > 160000.0f) {
                    data->selected[i] = index;
                } else {
                    valid = 0;
                }
            }
        } while (!valid);
    }
}

s32 func_80801C28_chdinoboss(Actor *arg0) {
    if (arg0->pad5E < 7) {
        return 6;
    }
    if (arg0->pad5E < 0xD) {
        return 5;
    }
    if (arg0->pad5E < 0x13) {
        return 4;
    }
    if (arg0->pad5E < 0x19) {
        return 3;
    }
    return 2;
}

f32 func_80801C84_chdinoboss(Actor *arg0) { f32 func_800F10B4(f32, f32, f32, f32, f32); f32 result; result = func_800F10B4((f32)arg0->pad5E, 0.0f, 30.0f, 0.3f, 1.8f); return result; }

void func_80801CDC_chdinoboss(Actor *arg0) {
    s32 func_800D2498(u32 itemDisplayUI, s32 value, u32 a2);
    func_800D2498(0xC8U, (u32) arg0->pad5E, 0U);
}

void func_80801D08_chdinoboss(Actor *arg0, s32 arg1) {
    void func_800EFD24(f32 *);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_8010D254(f32 *);
    f32 sp24[3];

    switch (arg1) {
        case 0:
            func_800EFD24(sp24);
            arg0->unk54 = func_80102D78(arg0, sp24);
            break;
        case 1:
            func_800EFD24(sp24);
            arg0->unk54 = func_80102D78(arg0, sp24) - 90.0f;
            break;
        case 2:
            func_8010D254(sp24);
            arg0->unk54 = func_80102D78(arg0, sp24);
            break;
    }
    func_80102BF8(arg0, 0.1f, 0.05f, 120.0f);
}

void func_80801DC8_chdinoboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x138];
        s16 state;
        u8 pad13A[0x26];
        f32 unk160;
        u8 pad164[8];
        f32 position[3];
    } DinoBossData;
    void *func_80100094(Actor *, u32);
    void func_8008FE68(f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_8080232C_chdinoboss(Actor *, f32 *, f32 *);
    DinoBossData *data;
    f32 sp30[3];
    f32 sp24[3];

    data = func_80100094(arg0, 0);
    switch (data->state) {
        case 0:
            break;
        case 1:
            func_8008FE68(sp30);
            func_800EEC30(sp24, 60.0f, data->unk160, 2800.0f);
            func_800EF934(sp24, sp24, arg0->rotation[1]);
            func_800EF04C(sp24, arg0->position);
            func_8080232C_chdinoboss(arg0, sp24, sp30);
            break;
        case 2:
        case 3:
            func_8080232C_chdinoboss(arg0, data->position, arg0->position);
            break;
    }
}

void func_80801E90_chdinoboss(BtIntPtr arg0, BtIntPtr arg1) {
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5EF8(BtIntPtr);
    void func_8010FFB0(s32, BtIntPtr, BtIntPtr);

    func_8010FFB0(func_800F5EF8(func_800F54E4()), arg0, arg1);
}

/* extern */

void func_80801ECC_chdinoboss(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_800F5EF8(BtIntPtr);
    s32 func_800F6438(BtIntPtr);
    s32 func_8010FE14(BtIntPtr, BtIntPtr, BtIntPtr);
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
    s32 func_800F5EF8(BtIntPtr);
    s32 func_800F6438(BtIntPtr);
    void func_8010F9C0(BtIntPtr, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        if (func_800F6438(var_s0) != 0) {
            func_8010F9C0(func_800F5EF8(var_s0), arg0);
        }
        var_s0 += 1;
    } while (var_s0 != 8);
}

void func_80801FAC_chdinoboss(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad[0x138];
        s16 state;
        s16 playerMode;
        s16 cutscene;
        s16 blend;
        f32 blendTime;
        f32 blendDuration;
        f32 position[3];
        f32 rotation[3];
        f32 turn;
        s16 reset;
        s16 pad166;
        f32 timer;
        f32 target[3];
    } DinoData;
    void *func_80100094(Actor *, u32);
    BtUIntPtr func_800F54E4(void);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_800136E4(f32);
    void func_8008FE68(f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1EA4(BtIntPtr, f32 *);
    s32 func_800DC298(f32);
    s32 func_800C52F4(s32, s32);
    s32 func_800C53EC(s32, s32);
    void func_80801E90_chdinoboss();
    void func_80801ECC_chdinoboss();
    f32 playerPos[3];
    DinoData *data;
    s32 cutscene;
    s32 blend;
    f32 position[3];
    f32 delta[3];
    f32 rotation[3];
    f32 heading;
    f32 *vec;

    data = func_80100094(arg0, 0);
    cutscene = 0;
    blend = 1;
    if (data->playerMode != 0 && arg2 == 0) {
        func_80090708(0);
        data->playerMode = 0;
    }
    if (data->playerMode == 0 && arg2 != 0) {
        func_80090708(2);
        data->playerMode = 1;
    }
    if (arg1 != data->state) {
        vec = data->position;
        func_80801E90_chdinoboss(vec, data->rotation);
        switch (data->state) {
            case 1:
            case 2:
            case 3:
                break;
            case 0:
                func_800F7B9C(func_800F54E4(), 0x93);
                break;
        }
        switch (arg1) {
            case 0:
                func_8008FE68(playerPos);
                func_80801E90_chdinoboss(position, rotation);
                func_800EFB24(delta, position, playerPos);
                func_800EF368(delta, 600.0f);
                func_800EF04C(playerPos, delta);
                func_80801ECC_chdinoboss(playerPos, rotation);
                func_80801F44_chdinoboss(2);
                blend = 0;
                break;
            case 1: {
                f32 angle;
                func_80801F44_chdinoboss(6);
                angle = func_80102D78(arg0, vec);
                if (func_800F1EA4((BtIntPtr)((u8 *)arg0 + 4), &heading) == 0) {
                    heading = arg0->rotation[1];
                }
                if (func_800F1DCC(angle, heading) > 0.0f) {
                    data->turn = -100.0f;
                } else {
                    data->turn = 100.0f;
                }
                if (data->reset != 0) {
                    blend = 0;
                    data->reset = 0;
                }
                if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) == 0xB ||
                    ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) == 0xC) {
                    cutscene = 1;
                }
                break;
            }
            case 2: {
                f32 offset;
                func_80801F44_chdinoboss(6);
                data->timer = 0.0f;
                offset = func_800DC298(0.5f) ? -35.0f : 35.0f;
                offset = func_800136E4(arg0->rotation[1] + offset);
                vec = data->target;
                func_800EEB9C(vec, offset, 6000.0f);
                func_800EF04C(vec, &arg0->position[0]);
                cutscene = 1;
                blend = 0;
                break;
            }
            case 3:
                func_80801F44_chdinoboss(6);
                cutscene = 1;
                blend = 0;
                break;
        }
        if (cutscene != 0 && data->cutscene == 0) {
            _glcutDll_entrypoint_6(func_800EA05C(), 0x79);
            func_800C52F4(0, 2);
            data->cutscene = 1;
        }
        if (cutscene == 0 && data->cutscene != 0) {
            _glcutDll_entrypoint_17();
            func_800C53EC(0, 2);
            data->cutscene = 0;
        }
        data->state = arg1;
        if (blend != 0) {
            data->blend = 1;
            data->blendDuration = 1.0f;
            data->blendTime = 1.0f;
        } else {
            data->blend = 0;
        }
    }
}

void func_8080232C_chdinoboss(Actor *arg0, f32 *arg1, f32 *arg2) {
    typedef struct {
        u8 pad[0x13E];
        s16 blend;
        f32 blendTime;
        f32 blendDuration;
        f32 position[3];
    } DinoData;
    void *func_80100094(Actor *, u32);
    u8 func_800D9078(f32 *);
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800F1A88(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    s32 pad;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp64[2];
    f32 sp5C[2];
    f32 sp58;
    f32 sp54;
    DinoData *data;
    f32 blend;
    s32 i;
    s32 done;

    data = func_80100094(arg0, 0);
    if (data->blend != 0) {
        done = func_800D9078(&data->blendTime);
        blend = func_800F12D4(data->blendTime, 0.0f, data->blendDuration, 1.0f, 0.0f);
        func_800F1A88(data->position, sp64);
        func_800F1A88(arg1, sp5C);
        sp58 = func_800EEF94(data->position);
        sp54 = (func_800EEF94(arg1) - sp58) * blend + sp58;
        for (i = 0; i < 2; i++) {
            sp5C[i] = func_800F1DCC(sp5C[i], sp64[i]) * blend;
            sp5C[i] += sp64[i];
        }
        func_800EEBF0(sp6C, sp5C, sp54);
        func_800A516C(sp78, arg2, sp6C);
        func_80801ECC_chdinoboss((BtIntPtr)sp6C, (BtIntPtr)sp78);
        if (done != 0) {
            data->blend = 0;
        }
    } else {
        func_800A516C(sp78, arg2, arg1);
        func_80801ECC_chdinoboss((BtIntPtr)arg1, (BtIntPtr)sp78);
    }
}    typedef struct { u8 pad0[0x12B]; s8 unk12B; } Objboss_func_8080248C_chdinoboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x12B]; u8 unk12B; } Objboss_func_8080248C_chdinoboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8080248C_chdinoboss(Actor *arg0, s32 arg1, s32 arg2)
{
  s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
  s32 _capod_entrypoint_14(void);
  void *func_80100094(Actor *, u32);
  u8 *sp1C;
  u8 *temp_v0;
 temp_v0 = func_80100094(arg0, 0U); sp1C = temp_v0;
  arg2 = arg2;
  if ((((Objboss_func_8080248C_chdinoboss_temp_v0 *)temp_v0)->unk12B) != 0)
  {
    _capod_entrypoint_14();
    arg2 = arg2 | 0x2000;
  }
  _capod_entrypoint_13(arg0->unk0, NULL, (u32) arg1, (u32) arg2);
  ((Objboss_func_8080248C_chdinoboss_sp1C *)sp1C)->unk12B = 1;
}    typedef struct { u8 pad0[0x12B]; u8 unk12B; } Objboss_func_80802500_chdinoboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x12B]; s8 unk12B; } Objboss_func_80802500_chdinoboss_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

void func_80802500_chdinoboss(Actor *arg0) {
    s32 _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C[1];
    u8 *temp_v0;
    u8 *var_v1;

    temp_v0 = func_80100094(arg0, 0U);
    var_v1 = temp_v0;
    if ((((Objboss_func_80802500_chdinoboss_temp_v0 *)temp_v0)->unk12B) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        var_v1 = sp1C[0];
    }
    (((Objboss_func_80802500_chdinoboss_var_v1 *)var_v1)->unk12B) = 0;
}

void func_80802540_chdinoboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    s32 func_800F4F34(BtUIntPtr, f32 *, f32, f32);
    BtUIntPtr func_800F54E4(void);
    f32 sp1C[3];

    func_800F4F34(func_800F54E4(), arg0->position, 500.0f, 500.0f);
    if (_subaddieskeleton_entrypoint_0(arg0, 6, sp1C) != 0) {
        func_800F4F34(func_800F54E4(), sp1C, 0.0f, 300.0f);
    }
    if (_subaddieskeleton_entrypoint_0(arg0, 0x14, sp1C) != 0) {
        func_800F4F34(func_800F54E4(), sp1C, 0.0f, 300.0f);
    }
}

void func_808025E8_chdinoboss(Actor *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80108B04(Actor *, u32);
    s32 sp1C;
    s32 sp18;

    sp1C = func_800EA05C();
    sp18 = 1;
    arg0->actorData[4] = -1;
    if (_glcutDll_entrypoint_19(0x33) == 0) {
        if ((func_800DA298(0xE5) != 0) && (sp1C == 0x112) && (_subaddiefind_entrypoint_2(0x234, 0) == NULL)) {
            func_80108B04(arg0, 0);
            sp18 = 0;
        }
    } else {
        sp18 = 0;
    }
    if (sp18 != 0) {
        func_800FFAB0(arg0);
    }
}

void func_80802684_chdinoboss(Actor *arg0) {
    u8 func_800D9078(f32*);
    void func_80108B04(Actor*, u32);
    if ((func_800D9078(&arg0->unk58) != 0) && (arg0->actorData[4] == 0x1DU)) {
        func_80108B04(arg0, 0U);
    }
}

s32 func_808026D0_chdinoboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    void func_80802864_chdinoboss(Actor *, s32);
    s32 map;

    switch (arg1) {
    case 0xB:
        switch (arg2) {
        case 29:
            _capod_entrypoint_14();
            _capod_entrypoint_13(arg0->unk0, NULL, 0x25, 0x2820);
            arg0->actorData[4] = 0x25;
            return 4;
        case 37:
            _glcutDll_entrypoint_24(0x115, 0x113, 0x33);
            arg0->actorData[4] = -1;
            break;
        case 4:
            _glcutDll_entrypoint_17();
            arg0->actorData[4] = -1;
            break;
        }
        return 2;
    case 0x3D:
        func_80802864_chdinoboss(arg0, arg2);
        break;
    case 0x49:
        map = func_800EA05C();
        if (arg2 != 0x33) {
            return 0;
        }
        switch (map) {
        case 0x112:
            arg0->unk58 = 0.8f;
            arg0->actorData[4] = 0x1D;
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17FB, 0x44, NULL, 0x57);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x1D, 0x2820);
            break;
        case 0x115:
            arg0->actorData[4] = 4;
            _capod_entrypoint_13(arg0->unk0, NULL, 4, 0x2820);
            break;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80802864_chdinoboss(Actor *arg0, s32 arg1) {
    void _chappearfx_entrypoint_1(s32 *arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 _glcutDll_entrypoint_19(s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);

    Actor *sp1C;
    Actor *temp_v0;

    if (arg1 == 0) {
        temp_v0 = func_80108528(0x234, D_80802CA8_chdinoboss, 0x5A, &arg0);
        sp1C = temp_v0;
        func_80102FDC(temp_v0, 0.8f);
        if (_glcutDll_entrypoint_19(0x33) != 0) {
            _chappearfx_entrypoint_1(sp1C, 0x22, 2, 0x3F800000);
            return;
        }
        func_800FFAB0(arg0);
    }
}
