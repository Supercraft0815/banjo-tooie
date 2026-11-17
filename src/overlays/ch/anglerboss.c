#include "common.h"

void func_808002E0_changlerboss(Actor *);
void func_80105834(Actor *);
void func_80800FEC_changlerboss(Actor *, BtIntPtr);
OSThread *func_80108ED0(void);
void func_80800018_changlerboss(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80800B7C_changlerboss(Actor *, s32, s32);
void func_80802888_changlerboss(Actor *);
void func_80101870(Actor *, void *);
void func_80802844_changlerboss(void *);
s32 func_80802A90_changlerboss(Actor *, s32, s32);

u32 D_80802DA0_changlerboss[] = {
    0x001305E2, 0x00180002, 0x00000000,
};

u32 D_80802DAC_changlerboss[] = {
    0x001305E2, 0x0018000D, 0x00CC00E6, 0x00020000,
};

u32 D_80802DBC_changlerboss[] = {
    0x00000000, 0x00000000, 0x402CCCCD, 0x03EB0001,
    0x40000000, 0x03EC0002, 0x40000000, 0x03300001,
    0x40000000, 0x03300001, 0x40000000, 0x03300001,
    0x40000000, 0x03300001, 0x40000000, 0x03300001,
    0x40000000, 0x033E0001, 0x3FC00000, 0x033F0002,
    0x40000000, 0x03300001, 0x40000000, 0x03300001,
    0x40000000, 0x03300001, 0x40000000, 0x03300001,
    0x40000000, 0x03300001, 0x40000000, 0x03300001,
    0x40000000, 0x033E0002, 0x40000000, 0x03300001,
    0x40000000, 0x033E0042, 0x40000000, 0x033E0001,
    0x40000000, 0x03300001, 0x40000000, 0x033E0001,
    0x3FC00000, 0x033F0002, 0x40000000, 0x03300001,
    0x41133333, 0x03400002, 0x40000000, 0x03410001,
    0x40000000, 0x03410001, 0x40000000, 0x03410001,
    0x40000000, 0x03300001, 0x40000000, 0x03EC0002,
    0x40000000, 0x03300001,
};

BtFnWord D_80802EB4_changlerboss[] = {
    0x0002045D, 0x07F90001, (BtFnWord)D_80802DBC_changlerboss, (BtFnWord)func_808002E0_changlerboss,
    (BtFnWord)func_80105834, (BtFnWord)func_80800FEC_changlerboss, 0x0000752F, 0x00000000,
    0x00000000, 0x00000468, 0x00000000, (BtFnWord)func_80108ED0,
    0x01300000, (BtFnWord)func_80800018_changlerboss, (BtFnWord)func_80107C2C, 0x80E10402,
    (BtFnWord)func_80800B7C_changlerboss, 0x00000000,
};

BtFnWord D_80802EFC_changlerboss[] = {
    0x0158045E, 0x07FB0001, 0x00000000, (BtFnWord)func_80802888_changlerboss,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00021404, 0x00000000, 0x00000000,
    0x00000000, (BtFnWord)func_80802844_changlerboss, (BtFnWord)func_80107C2C, 0x80000002,
    (BtFnWord)func_80802A90_changlerboss, 0x00000000,
};

u32 D_80802F44_changlerboss[] = {
    0x00130692, 0x00180002, 0x00000000,
};

OSThread *changlerboss_entrypoint_0(void)
{


    return (OSThread *) D_80802EB4_changlerboss;
}

OSThread *changlerboss_entrypoint_1(void)
{


    return (OSThread *) D_80802EFC_changlerboss;
}

void func_80800018_changlerboss(Actor *arg0) {
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_20(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F497C(BtIntPtr);
    void func_800F49D4(BtIntPtr, void *, Unk80132ED0 *);
    void func_800F4AC0(BtIntPtr, f32 *, f32);
    BtIntPtr func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80109F08(void *, s32);
    void func_8010A590(Actor *);
    void func_8010A85C(Actor *, s32);
    void func_808012E0_changlerboss(Actor *, s32);
    void func_808015F4_changlerboss(Actor *, BtIntPtr, s32);
    void func_808021E4_changlerboss(Actor *, u32, u32);
    extern s32 func_8010D5DC;
    struct AnglerBossInitData {
        u8 pad0[0x90];
        s16 unk90;
        s16 unk92;
        s16 unk94;
        s16 unk96;
        f32 unk98;
        Unk80132ED0 *unk9C;
        Unk80132ED0 *unkA0;
        f32 unkA4[6];
        f32 unkBC[6];
        f32 unkD4[6];
        f32 unkEC[6];
        f32 unk104[6];
        f32 unk11C[3];
        s16 unk128;
        s8 unk12A;
    } *data;
    s32 i;
    BtIntPtr player;

    data = func_80100094(arg0, 0);
    arg0->unk70_0 = 1;
    arg0->pad7A_7 = 3;
    func_800EE7F8(data->unk11C, arg0->position);
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x32, data->unkA4, 1);
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x33, data->unkBC, 1);
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x34, data->unkD4, 1);
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x35, data->unkEC, 1);
    _subaddiemarker_entrypoint_1(arg0, 0x154, 0x36, data->unk104, 1);
    data->unk90 = 1;
    data->unk9C = NULL;
    data->unkA0 = NULL;
    data->unk92 = 0;
    data->unk96 = 6;
    for (i = 0; i != 6; i++) {
        func_808015F4_changlerboss(arg0, i, 1);
    }
    func_80109F08(arg0, 0x40);
    player = func_800F54E4();
    if (_glcutDll_entrypoint_20()) {
        func_800EE7F8(arg0->position, data->unk104);
        func_80102424(arg0, 0x1D);
        func_8010A85C(arg0, 1);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802DA0_changlerboss);
        return;
    }
    if (func_800DA298(0x377)) {
        func_8010A85C(arg0, 1);
        func_8010A590(arg0);
        func_808012E0_changlerboss(arg0, 0x1A);
        func_800EE7F8(arg0->position, data->unkEC);
        arg0->rotation[1] = data->unkEC[4];
        _chintrotext_entrypoint_2(1);
        return;
    }
    func_8010A85C(arg0, 2);
    arg0->unk58 = 2.0f;
    if (func_800DA298(0x1AF)) {
        func_800EE7F8(arg0->position, data->unk104);
        func_808012E0_changlerboss(arg0, 4);
        func_800F608C(player, 1);
        func_800F8294(player, data->unkD4);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1028, 0x106, arg0->position, 0xB4);
        func_808021E4_changlerboss(arg0, 0x12, 0x30);
        data->unk12A = 1;
    } else {
        func_800F608C(player, 1);
        func_800F497C(player);
        func_800F49D4(player, &func_8010D5DC, arg0->unk0);
        func_800F4AC0(player, data->unkD4, 300.0f);
        func_808021E4_changlerboss(arg0, 0x22, 0x20);
        _chintrotext_entrypoint_2(1);
    }
}

void func_808002E0_changlerboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DC128(s32, s32);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EFE50(f32 *, void *, void *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    BtIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80108B04(Actor *arg0, u32 arg1);
    void func_80109FE8(Actor *, s32);
    u32 func_8010A5B0(Actor *arg0, s32 arg1);
    void func_8010A85C(Actor *, s32);
    void func_8010D640(f32 *);
    void func_808012E0_changlerboss(Actor *, s32);
    void func_808016A8_changlerboss(Actor *);
    int func_80801948_changlerboss(Actor *);
    void func_80801A10_changlerboss(Actor *);
    s32 func_80801AF0_changlerboss(Actor *);
    void func_80801BC8_changlerboss(Actor *);
    s32 func_80801C50_changlerboss(Actor *);
    void func_80801CD8_changlerboss(BtIntPtr);
    void func_808021E4_changlerboss(Actor *, u32, u32);
    void func_808022C4_changlerboss(Actor *);
    void func_80802340_changlerboss(Actor *);
    BtIntPtr func_808025AC_changlerboss(BtIntPtr);
    void func_808025EC_changlerboss(Actor *);
    void func_80802680_changlerboss(Actor *);

    extern u32 D_80802F50_changlerboss[];
    extern u32 D_80802F60_changlerboss[];
    struct AnglerBossActorFlags {
        u8 pad0[0x7A];
        u8 pad7A_15 : 2;
        u8 unk7A_13 : 2;
        u8 unk7A_11 : 3;
        u8 unk7A_8 : 1;
    };
    struct AnglerBossUpdateData {
        u8 pad0[0x94];
        s16 unk94;
        s16 unk96;
        u8 pad98[8];
        Unk80132ED0 *unkA0;
        u8 padA4[0x60];
        f32 unk104[3];
        u8 pad110[0xC];
        f32 unk11C[3];
        s16 unk128;
        u8 unk12A;
        u8 unk12B;
        u8 unk12C;
        u8 unk12D;
        u8 unk12E;
        u8 unk12F;
    } *data;
    f32 position[3];
    s32 pad44;
    s32 expired;
    s32 pad3C;
    f32 progress;

    data = func_80100094(arg0, 0);
    data->unk128 = func_808025AC_changlerboss(arg0);
    if (func_800F6438(data->unk128)) {
        func_800F5A00(data->unk128, position);
    } else {
        func_8010D640(position);
    }
    func_808025EC_changlerboss(arg0);
    func_80802680_changlerboss(arg0);
    func_808022C4_changlerboss(arg0);
    func_80802340_changlerboss(arg0);
    if (arg0->unk7C_12 && data->unkA0) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, func_80106790(data->unkA0)->position);
    }
    switch (arg0->unk70_10) {
        case 1:
            func_8010A5B0(arg0, arg0->unk7C_12);
            if (func_800D9078(&arg0->unk58)) {
                func_80101180(0x46C, 8, 0);
            }
            if (!func_800DA298(0x6AD) && !data->unk12E) {
                data->unk12E = 1;
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x103E, 0x144, arg0->position, 0xB4);
            }
            if (data->unk12C && data->unk12D) {
                func_800F82D4(func_800F54E4(), 0);
                func_808012E0_changlerboss(arg0, 2);
            }
            break;
        case 2:
            if (func_80101DDC(arg0)) {
                func_808012E0_changlerboss(arg0, 3);
            }
            break;
        case 3:
            expired = func_800D9078(&arg0->unk58);
            func_800EFE50(arg0->position, data->unk11C, data->unk104,
                         func_800F12D4(arg0->unk58, 0.0f, 4.0f, 1.0f, 0.0f));
            if (expired) {
                func_808012E0_changlerboss(arg0, 4);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1027, 0x106, arg0->position, 0xB4);
                func_808021E4_changlerboss(arg0, 0xA, 0x30);
            }
            break;
        case 4:
            func_8010A5B0(arg0, arg0->unk7C_12);
            break;
        case 5:
            func_80801A10_changlerboss(arg0);
            if (func_800D9078(&arg0->unk58)) {
                func_808012E0_changlerboss(arg0, 6);
            }
            break;
        case 6:
            func_80801A10_changlerboss(arg0);
            if (func_80801948_changlerboss(arg0)) {
                func_808012E0_changlerboss(arg0, 7);
            }
            break;
        case 7:
            func_80801948_changlerboss(arg0);
            if (func_80801AF0_changlerboss(arg0)) {
                func_808012E0_changlerboss(arg0, 8);
            }
            break;
        case 8:
            func_80801AF0_changlerboss(arg0);
            if (func_80101E14(arg0, 0.7f)) {
                func_80108B04(arg0, 1);
            }
            if (func_80101E14(arg0, 0.999f) && --data->unk94 == 0) {
                func_808012E0_changlerboss(arg0, 5);
            }
            break;
        case 9:
            if (func_80101DDC(arg0)) {
                switch (func_80801C50_changlerboss(arg0)) {
                    case 0:
                        func_808012E0_changlerboss(arg0, 0xB);
                        break;
                    case 5:
                        _subaddiedialog_entrypoint_11(arg0->unk0, 0x102A, 0x106, arg0->position, 0xB4);
                        func_808012E0_changlerboss(arg0, 0xA);
                        break;
                    default:
                        func_808016A8_changlerboss(arg0);
                        func_808012E0_changlerboss(arg0, 6);
                        break;
                }
            }
            break;
        case 11:
            if (func_800D9078(&arg0->unk58)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802F44_changlerboss);
                func_8010A85C(arg0, 1);
                ((struct AnglerBossActorFlags *)arg0)->unk7A_13 = 1;
                arg0->unk7A_11 = 3;
                func_808012E0_changlerboss(arg0, 0xC);
            }
            break;
        case 13:
            if (func_800D9078(&arg0->unk58)) {
                func_808012E0_changlerboss(arg0, 0xE);
            }
            break;
        case 14:
            func_80801A10_changlerboss(arg0);
            if (func_80801948_changlerboss(arg0)) {
                func_808012E0_changlerboss(arg0, 0xF);
            }
            break;
        case 15:
            func_80801948_changlerboss(arg0);
            if (func_80801AF0_changlerboss(arg0)) {
                func_808012E0_changlerboss(arg0, 0x10);
            }
            break;
        case 16:
            progress = func_80101F24(arg0);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802F60_changlerboss, 0.4f);
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802F50_changlerboss, 0.75f);
            if (progress > 0.0f && progress >= 0.4f && progress <= 0.75f) {
                func_80801CD8_changlerboss(arg0);
            }
            func_80801AF0_changlerboss(arg0);
            if (func_80101DDC(arg0)) {
                func_808012E0_changlerboss(arg0, 0x12);
                data->unk94 = 2;
            }
            break;
        case 17:
            func_80801AF0_changlerboss(arg0);
            if (data->unk94 == 0 && !_subaddiefind_entrypoint_2(0x460, 0)) {
                func_808012E0_changlerboss(arg0, 0xD);
            }
            if (func_800D9078(&arg0->unk58) && data->unk94 > 0) {
                func_808012E0_changlerboss(arg0, 0x12);
            }
            break;
        case 18:
            func_80801AF0_changlerboss(arg0);
            if (func_80101E14(arg0, 0.7f)) {
                func_80108B04(arg0, 1);
            }
            if (func_80101DDC(arg0)) {
                if (--data->unk94 == 0 && !_subaddiefind_entrypoint_2(0x460, 0)) {
                    func_808012E0_changlerboss(arg0, 0xD);
                } else {
                    func_808012E0_changlerboss(arg0, 0x11);
                }
            }
            break;
        case 19:
            func_80801AF0_changlerboss(arg0);
            if (func_80101E14(arg0, 0.7f)) {
                func_80108B04(arg0, 1);
            }
            if (func_80101E14(arg0, 0.999f)) {
                data->unk94--;
                if (data->unk94 == 0) {
                    func_808012E0_changlerboss(arg0, 0xD);
                }
            }
            break;
        case 20:
            func_80801AF0_changlerboss(arg0);
            if (func_800D9078(&arg0->unk58)) {
                func_808012E0_changlerboss(arg0, 0x15);
            }
            break;
        case 21:
            func_80801AF0_changlerboss(arg0);
            if (func_80101E14(arg0, 0.7f)) {
                func_80108B04(arg0, 1);
            }
            if (func_80101E14(arg0, 0.999f)) {
                data->unk94--;
                if (data->unk94 == 0) {
                    func_808012E0_changlerboss(arg0, 0xD);
                }
            }
            break;
        case 22:
            if (func_80101DDC(arg0)) {
                data->unk12F = 1;
                if (data->unk96 == 5) {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1036, 0x106, arg0->position, 0xB4);
                    func_808012E0_changlerboss(arg0, 0x17);
                } else {
                    func_80109FE8(arg0, 0);
                    func_808012E0_changlerboss(arg0, 0x13);
                }
            }
            break;
        case 24:
            if (func_80101DDC(arg0)) {
                func_808012E0_changlerboss(arg0, 0x19);
            }
            break;
        case 25:
            func_80801BC8_changlerboss(arg0);
            break;
        case 26:
            func_80801BC8_changlerboss(arg0);
            if (!data->unk12B && func_800D90A4(&arg0->unk58) &&
                func_800EEB40(arg0->position, position) < 1960000.0f) {
                _subaddiedialog_entrypoint_11(arg0->unk0, func_800DC128(0, 4) + 0x1037,
                                            0x144, arg0->position, 0xB4);
                func_808012E0_changlerboss(arg0, 0x1B);
            }
            break;
        case 29:
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 0x1E);
            }
            break;
    }
}

s32 func_80800B7C_changlerboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_20(void);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    BtIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80101074(void *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80108B04(Actor *arg0, u32 arg1);
    void func_80800F14_changlerboss(Actor *, s32);
    void func_80801070_changlerboss(Actor *, s32);
    void func_808012E0_changlerboss(Actor *, s32);
    void func_8080170C_changlerboss(Actor *, s32, s32);
    void func_80801D0C_changlerboss(Actor *);
    Actor *func_80801DA0_changlerboss(Actor *);
    void func_80801E3C_changlerboss(Actor *);
    void func_80801F54_changlerboss(Actor *);
    void func_80802108_changlerboss(Actor *);
    void func_808021E4_changlerboss(Actor *, u32, u32);
    extern f32 B_808030B0_changlerboss[3];
    struct AnglerBossMessageData {
        u8 pad0[0x1B];
        u8 occupied[6];
        u8 pad21[0x1B];
        f32 positions[6][3];
        f32 position[3];
        s16 pad90;
        s16 unk92;
        u8 pad94[0x96];
        u8 unk12A;
        u8 unk12B;
        u8 unk12C;
    } *data;
    union AnglerBossMessage {
        s32 word;
        s16 half[2];
    };
    s32 i;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x3D:
            switch (arg2) {
                case 0: func_80801D0C_changlerboss(arg0); break;
                case 1: func_80801E3C_changlerboss(arg0); break;
                case 2: func_80801F54_changlerboss(arg0); break;
                case 3: func_80802108_changlerboss(arg0); break;
            }
            break;
        case 0x2E:
            func_8080170C_changlerboss(arg0, ((union AnglerBossMessage *)&arg2)->half[0],
                                      ((union AnglerBossMessage *)&arg2)->half[1]);
            break;
        case 0xB:
            switch (arg2) {
                case 0x19:
                    func_80101180(0x46C, 7, 0);
                    func_808021E4_changlerboss(arg0, 0xE, 0x10);
                    return 4;
                case 0xE:
                    data->unk12B = 0;
                    break;
            }
            return 3;
        case 0x40:
            func_80801070_changlerboss(arg0, ((union AnglerBossMessage *)&arg2)->word);
            break;
        case 0xA:
            if (arg0->unk70_10 == 0x11) {
                func_808012E0_changlerboss(arg0, 0x13);
            }
            break;
        case 0x49:
            if (!func_800DA298(0x377) || _glcutDll_entrypoint_20()) {
                func_80801DA0_changlerboss(arg0);
            }
            break;
        case 0x32:
            data->unk12C = 1;
            func_800F82D4(func_800F54E4(), 2);
            break;
        case 0x95:
            if (!func_800DA298(0x377)) {
                func_80108B04(arg0, 0);
            }
            if (data->unk12A) {
                func_800FDC28(1);
                data->unk12A = 0;
            }
            break;
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x146, arg0->position, 0xB4);
            break;
        case 0x9F:
            func_800FDC28(0);
            func_808012E0_changlerboss(arg0, 0x1C);
            break;
        case 0xA2:
            if (!arg0->unk7C_12 || func_800DA298(0x377)) {
                return 0;
            }
            if (data->unk92 == 0) {
                for (i = 0; i < 6; i++) {
                    if (data->occupied[i] == 0) {
                        func_800EE7F8(B_808030B0_changlerboss, data->positions[i]);
                        func_80101074(B_808030B0_changlerboss);
                        return 1;
                    }
                }
                return 0;
            } else {
                func_800EE7F8(B_808030B0_changlerboss, data->position);
                func_80101074(B_808030B0_changlerboss);
            }
            break;
        case 0x1F:
            func_80800F14_changlerboss(arg0, ((union AnglerBossMessage *)&arg2)->word);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800F14_changlerboss(Actor *arg0, s32 arg1) {
    void func_800DF660(s32 type,uintptr_t a,uintptr_t b,s32 alpha);
    void func_800DF720(BtIntPtr);
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80100AC4(s16);
    s32 func_801015D0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    struct AnglerBossRenderData {
        u8 visibility[0x9C];
        Unk80132ED0 *unk9C;
    } *temp_v0, *sp30;
    s32 sp2C;
    Unk80132ED0 *temp_a0;
    s32 var_s0;
    u8 *var_s1;
    Actor *child;

    temp_v0 = func_80100094(arg0, 0);
    sp2C = 0;
    var_s0 = 1;
    var_s1 = temp_v0->visibility + 1;
    sp30 = temp_v0;
    do {
        func_800DF744(var_s0, *var_s1);
        var_s0 += 1;
        var_s1 += 1;
    } while (var_s0 != 0x1B);
    func_801015D0(arg0);
    temp_a0 = sp30->unk9C;
    if (temp_a0 != NULL) {
        child = func_80106790(temp_a0);
        if (child->unk64_16) {
            sp2C = *(s32 *)&child->unk54;
        }
    }
    func_800DF660(4, (sp2C & 0xFFFF) | 0x30000, 0, arg0->alpha);
    func_800DF720(func_80100AC4(*(s16 *)&arg0->pad60));
}

/* extern */

void func_80800FEC_changlerboss(Actor *arg0, BtIntPtr arg1) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101870(Actor *, void *);
    void func_801018A4(Actor *, BtIntPtr);
    Actor *func_80106790(Unk80132ED0 *);
    struct AnglerBossData {
        u8 pad0[0x9C];
        Unk80132ED0 *unk9C;
        Unk80132ED0 *unkA0;
    } *sp1C, *temp_v0;
    Unk80132ED0 *temp_a0;
    Actor *child;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if (sp1C->unkA0 != NULL) {
        child = func_80106790(sp1C->unkA0);
        func_80101870(child, arg1);
    }
    func_801018A4(arg0, arg1);
    temp_a0 = sp1C->unk9C;
    if (temp_a0 != NULL) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, func_80106790(temp_a0)->position);
    }
}

void func_80801070_changlerboss(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80109FE8(Actor *, s32);
    void func_808012E0_changlerboss(Actor *, s32);
    void func_808015F4_changlerboss(Actor *, BtIntPtr, s32);
    s32 func_80801C50_changlerboss(Actor *);
    void func_808021E4_changlerboss(Actor *, u32, u32);
    void func_808027F8_changlerboss(void *);
    extern u32 D_80802F70_changlerboss;
    struct {
        u8 pad0[0x1B];
        u8 unk1B[6];
        u8 pad21[3];
        f32 unk24[6];
        f32 unk3C[6][3];
        u8 pad84[0xE];
        s16 unk92;
        s16 unk94;
        s16 unk96;
    } *sp3C;
    u32 sp38;
    s32 index;

    sp3C = func_80100094(arg0, 0);
    sp38 = (arg0->unk0->unk18 << 11) >> 28;
    if (func_800DA298(0x377)) {
        if (arg0->unk70_10 == 0x1A) {
            _subaddiedialog_entrypoint_11(arg0->unk0, func_800DC128(0, 3) + 0x103B, 0x144, arg0->position, 0xB4);
            func_808012E0_changlerboss(arg0, 0x1B);
        }
    } else {
        index = sp38 - 1;
        if (sp3C->unk92 == 0) {
            if (index >= 0 && index < 6 && sp3C->unk1B[index] == 0) {
                func_808015F4_changlerboss(arg0, index, 2);
                func_808012E0_changlerboss(arg0, 9);
                sp3C->unk24[index] = 2.0f;
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802DAC_changlerboss);
                _subaddieaudioquick_entrypoint_2(arg0, sp3C->unk3C[index], &D_80802F70_changlerboss);
                if (func_80801C50_changlerboss(arg0) == 5) {
                    func_80109FE8(arg0, 0);
                    func_808027F8_changlerboss(arg0);
                    func_808021E4_changlerboss(arg0, 0x1E, 0x30);
                }
            }
        } else if (sp38 == 8) {
            sp3C->unk96--;
            if (sp3C->unk96 == 0) {
                func_80109FE8(arg0, 0);
                func_808012E0_changlerboss(arg0, 0x18);
            } else if (sp3C->unk96 == 5) {
                func_80109FE8(arg0, 0);
                func_808027F8_changlerboss(arg0);
                func_808021E4_changlerboss(arg0, 0x1E, 0x30);
                func_808012E0_changlerboss(arg0, 0x16);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802DAC_changlerboss);
            } else if (sp3C->unk96 == 3) {
                func_808012E0_changlerboss(arg0, 0x14);
                sp3C->unk94 = 3;
            } else {
                func_808012E0_changlerboss(arg0, 0x16);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802DAC_changlerboss);
            }
        }
    }
}

void func_808012E0_changlerboss(Actor *arg0, s32 arg1) {
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_800D2770(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 func_800EEB40(f32 *, f32 *);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80109FE8(Actor *, s32);
    void func_808018E8_changlerboss(Actor *);
    s32 func_80801C50_changlerboss(Actor *);
    void func_808021E4_changlerboss(Actor *, u32, u32);
    void func_808027F8_changlerboss(void *);
    extern u32 D_80802F80_changlerboss;
    struct {
        u8 pad0[0x90];
        s16 unk90;
        s16 unk92;
        s16 unk94;
        s16 unk96;
        f32 unk98;
        Unk80132ED0 *unk9C;
        Unk80132ED0 *unkA0;
        f32 unkA4[2][6];
    } *sp2C;

    sp2C = func_80100094(arg0, 0U);
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 2:
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80802DA0_changlerboss);
        func_800FDC28(1);
        func_808021E4_changlerboss(arg0, 0U, 0x30U);
        func_80102424(func_80106790(sp2C->unk9C), 2);
        break;
    case 3:
        _chintrotext_entrypoint_1(0x18B9, 5, 1, 0);
        arg0->unk58 = 4.0f;
        break;
    case 5:
        arg0->unk58 = func_800DC178(4.0f, 6.0f);
        break;
    case 6:
    case 14:
        if (func_800EEB40(arg0->position, sp2C->unkA4[sp2C->unk90]) < 640000.0f) {
            sp2C->unk90 ^= 1;
        }
        func_80109FE8(arg0, 1);
        func_808018E8_changlerboss(arg0);
        break;
    case 7:
    case 15:
        sp2C->unk90 ^= 1;
        sp2C->unk98 = 0.0f;
        break;
    case 13:
        arg0->unk58 = func_800DC178(2.0f, 3.0f);
        break;
    case 8:
        if (func_80801C50_changlerboss(arg0) < 4) {
            sp2C->unk94 = 2;
        } else {
            sp2C->unk94 = 1;
        }
        break;
    case 11:
        arg0->unk58 = 2.0f;
        func_808027F8_changlerboss(arg0);
        func_808021E4_changlerboss(arg0, 0x1CU, 0x30U);
        func_800D2770(0xFE, 0);
        break;
    case 12:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x102B, 0x106, arg0->position, 0xB4);
        break;
    case 17:
        arg0->unk58 = 2.0f;
        break;
    case 19:
        sp2C->unk94 = 1;
        break;
    case 22:
        func_80109FE8(arg0, 0);
        break;
    case 20:
        arg0->unk58 = func_800DC178(1.5f, 2.5f);
        break;
    case 24:
        func_800FDC28(0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802F80_changlerboss);
        func_808027F8_changlerboss(arg0);
        func_808021E4_changlerboss(arg0, 0x16U, 0x38U);
        break;
    case 25:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1029, 0x106, arg0->position, 0xB4);
        break;
    case 26:
        func_80109FE8(arg0, 1);
        arg0->unk58 = func_800DC178(5.0f, 8.0f);
        break;
    case 27:
    case 28:
        func_80109FE8(arg0, 0);
        break;
    }
}

void func_808015F4_changlerboss(Actor *arg0, BtIntPtr arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    extern s16 D_80802F8C_changlerboss[][3][3];
    struct {
        u8 pad0[0x1B];
        s8 state[6];
    } *data;
    s32 offset;
    s32 i;
    s32 j;
    s8 enabled;

    data = func_80100094(arg0, 0U);
    data->state[arg1] = arg2;
    for (i = 0; i != 3; i++) {
        j = 0;
        if (i == arg2) {
            enabled = 1;
        } else {
            enabled = 0;
        }
        for (; D_80802F8C_changlerboss[arg1][i][j] != -1; j++) {
            offset = D_80802F8C_changlerboss[arg1][i][j];
            ((s8 *)data)[offset] = enabled;
        }
    }
}

/* extern */

void func_808016A8_changlerboss(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_808015F4_changlerboss(Actor *, BtIntPtr, s32);
    u8 *temp_s0;
    BtIntPtr temp_v0;

    temp_s0 = func_80100094(arg0, 0U);
    do {
        temp_v0 = func_800DC128(0, 6);
    } while (*(u8 *)((BtIntPtr)temp_s0 + temp_v0 + 0x1B) != 1);
    func_808015F4_changlerboss(arg0, temp_v0, 0);
}

void func_8080170C_changlerboss(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _gcfrontend_entrypoint_9(s32 arg0);
    void _plcamera_entrypoint_8(s32 *arg0);
    s32 func_800D395C(void);
    void func_800DA544(s32 index);
    BtIntPtr func_800F54E4(void);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *arg0, u32 arg1);
    void func_80109FE8(Actor *, s32);
    void func_80802288_changlerboss(Actor *);
    struct {
        u8 pad0[0x92];
        s16 unk92;
        u8 pad94[0x99];
        s8 unk12D;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x1027:
        case 0x1028:
            func_800FDC28(5);
            func_80802288_changlerboss(arg0);
            _plcamera_entrypoint_8(func_800F54E4());
            func_800DA544(0x1AF);
            _gcfrontend_entrypoint_9(0x26);
            func_808016A8_changlerboss(arg0);
            func_808012E0_changlerboss(arg0, 6);
            break;
        case 0x1029:
            func_808012E0_changlerboss(arg0, 0x1A);
            if (func_800D395C() != 0) {
                func_80802288_changlerboss(arg0);
                _gcfrontend_entrypoint_10();
            } else {
                func_80108B04(arg0, 3);
                func_800DA544(0x377);
            }
            break;
        case 0x102B:
            func_80802288_changlerboss(arg0);
            data->unk92 = 1;
            func_808012E0_changlerboss(arg0, 0xE);
            break;
        case 0x102A:
            func_80802288_changlerboss(arg0);
            func_808016A8_changlerboss(arg0);
            func_808012E0_changlerboss(arg0, 6);
            func_80109FE8(arg0, 1);
            break;
        case 0x1036:
            func_80802288_changlerboss(arg0);
            func_808012E0_changlerboss(arg0, 0x13);
            func_80109FE8(arg0, 1);
            break;
        case 0x1037:
        case 0x1038:
        case 0x1039:
        case 0x103A:
        case 0x103B:
        case 0x103C:
        case 0x103D:
            func_808012E0_changlerboss(arg0, 0x1A);
            break;
        case 0x103E:
            data->unk12D = 1;
            break;
        case 0xCEB:
            if (arg2 > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
    }
}

/* extern */

void func_808018E8_changlerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[0x98];
        f32 unk98;
        u8 pad9C[0x93];
        u8 unk12F;
    } *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    *(f32 *)&arg0->actorData[3] = 10.0f;
    if (temp_v0->unk12F != 0) {
        temp_v0->unk98 = 900.0f;
        return;
    }
    temp_v0->unk98 = 400.0f;
}

/* extern */

int func_80801948_changlerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800F15F8(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010B990(Actor *, s32);
    struct {
        u8 pad0[0x90];
        s16 index;
        u8 pad92[6];
        f32 speed;
        u8 pad9C[8];
        struct {
            f32 position[3];
            f32 padC[3];
        } points[5];
        u8 pad11C[0x13];
        u8 active;
    } *temp_s1;

    temp_s1 = func_80100094(arg0, 0);
    *(f32 *)&arg0->actorData[3] = func_800F15F8(*(f32 *)&arg0->actorData[3], temp_s1->speed, func_800D8FF8() * 600.0f);
    func_8010B990(arg0, 6);
    if (func_800EEB40(arg0->position, temp_s1->points[temp_s1->index].position) < 160000.0f) {
        if (temp_s1->active != 0) {
            temp_s1->active = 0;
            temp_s1->speed = 400.0f;
        }
        return 1;
    }
    return 0;
}

void func_80801A10_changlerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80102CF4(Actor *, s32);
    struct {
        u8 pad0[0x90];
        s16 index;
        u8 pad92[0x12];
        struct {
            f32 position[3];
            f32 padC[3];
        } points[5];
    } *data;
    f32 angles[2];
    f32 delta;

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    func_800F18FC(arg0->position, data->points[data->index].position, angles);
    arg0->unk50 = angles[0];
    arg0->unk54 = angles[1];
    arg0->rotation[1] = func_800F1FF0(arg0->rotation[1], arg0->unk54, 0.1f, 2.0f * delta, delta * 60.0f);
    arg0->rotation[0] = func_800F1FF0(arg0->rotation[0], arg0->unk50, 0.1f, 2.0f * delta, delta * 60.0f);
    BT_NATIVE_ONLY(return) func_80102CF4(arg0, 0x41000000);
}

s32 func_80801AF0_changlerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80102CF4(Actor *, s32);
    struct {
        u8 pad0[0x128];
        s16 index;
    } *data;
    f32 angles[2];
    f32 delta;
    f32 position[3];

    data = func_80100094(arg0, 0);
    delta = func_800D8FF8();
    func_800F5A00(data->index, position);
    func_800F18FC(arg0->position, position, angles);
    arg0->unk50 = angles[0];
    arg0->unk54 = angles[1];
    arg0->rotation[1] = func_800F1FF0(arg0->rotation[1], arg0->unk54, 0.1f, 2.0f * delta, delta * 60.0f);
    arg0->rotation[0] = func_800F1FF0(arg0->rotation[0], arg0->unk50, 0.1f, 2.0f * delta, delta * 60.0f);
    BT_NATIVE_ONLY(return) func_80102CF4(arg0, 0x41000000);
}    typedef struct { u8 pad0[0xF0]; f32 unkF0; } Objanglerboss_func_80801BC8_changlerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80801BC8_changlerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    void *temp_v0;
    f32 temp_f2;

    temp_v0 = func_80100094(arg0, 0U);
    if ((arg0->position[1]) < (((Objanglerboss_func_80801BC8_changlerboss_temp_v0 *)temp_v0)->unkF0)) {
        (arg0->position[1]) += func_800D8FF8() * 120.0f;
        temp_f2 = (((Objanglerboss_func_80801BC8_changlerboss_temp_v0 *)temp_v0)->unkF0);
        if (temp_f2 < (arg0->position[1])) {
            (arg0->position[1]) = temp_f2;
        }
    }
}

/* extern */

s32 func_80801C50_changlerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 var_v1;
    s32 i;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_v1 = 0;
    for (i = 0; i < 6; i++) {
        if ((temp_v0 + i)[0x1B] != 2) {
            var_v1 += 1;
        }
    }
    return var_v1;
}

/* extern */

void func_80801CD8_changlerboss(BtIntPtr arg0) {
    s32 func_8001210C(s32);
    void func_80108B04(Actor *arg0, u32 arg1);
    if (func_8001210C(3) == 0) {
        func_80108B04(arg0, 2);
    }
}

/* extern */

void func_80801D0C_changlerboss(Actor *arg0) {
    void _subaddieDll_entrypoint_0(void *arg0);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_8010A570(Actor *);
    void func_8010A800(Actor *, s32);
    struct AnglerBossData {
        u8 pad0[0x9C];
        Unk80132ED0 *unk9C;
        Unk80132ED0 *unkA0;
    } *sp24;
    Actor *temp_v0;

    sp24 = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x298, &arg0);
    temp_v0->unk3C = arg0->unk0;
    sp24->unkA0 = temp_v0->unk0;
    _subaddieDll_entrypoint_0(temp_v0);
    func_8010A800(temp_v0, 2);
    func_8010A570(temp_v0);
    temp_v0->unk64_16 = 0;
    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, temp_v0->position);
}

/* extern */

Actor *func_80801DA0_changlerboss(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    Actor *func_801084B0(BtIntPtr, Actor **);
    struct AnglerBossData {
        u8 pad0[0x9C];
        Unk80132ED0 *unk9C;
    } *sp24;
    Actor *temp_v0;

    sp24 = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x45E, &arg0);
    func_80102FDC(temp_v0, arg0->scale);
    temp_v0->unk3C = arg0->unk0;
    sp24->unk9C = temp_v0->unk0;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(temp_v0, 2);
    } else if (func_800DA298(0x1AF) != 0) {
        func_80102424(temp_v0, 3);
    }
    return arg0;
}

void func_80801E3C_changlerboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F5A00(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    f32 sp4C[3];
    f32 sp40[3];
    s32 pad3C;
    struct AnglerBossShotData {
        u8 pad0[0x92];
        s16 unk92;
        s16 pad94;
        s16 unk96;
        u8 pad98[0x90];
        s16 unk128;
    } *sp38;
    f32 speed;
    Actor *shot;
    s32 pad28[2];

    sp38 = func_80100094(arg0, 0);
    func_800F5A00(sp38->unk128, sp4C);
    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, sp40) != 0) {
        sp38 = func_80100094(arg0, 0);
        shot = func_80108528(0x45F, sp40, 0, &arg0);
        func_800EFB24(&shot->actorData[4], sp4C, shot->position);
        shot->unk6C_0 = sp38->unk128;
        if (sp38->unk92 == 0) {
            speed = 1000.0f;
        } else {
            speed = func_800F10B4(sp38->unk96, 1.0f, 3.0f, 2000.0f, 1500.0f);
            shot->unk64_20 = 1;
        }
        func_800EF368((f32 *)&shot->actorData[4], speed);
        shot->unk3C = arg0->unk0;
    }
}

void func_80801F54_changlerboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 *arg2);
    f32 func_800DC178(f32 arg0, f32 arg1);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void func_800EF214(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    void func_800EF368(f32 vec[3], f32 target_length);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    void func_80102FDC(Actor *arg0, f32 arg1);
    Actor* func_80108528(s32 arg0, f32 arg1[3], s32 arg2, Actor **arg3);
    f32 sp8C[3];
    f32 sp80[3];
    int i;
    Actor *shot;

    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xA, sp80);
    i = 0;
    do {
        func_800EE7F8(sp8C, sp80);
        func_800EF214(sp8C, arg0->rotation[0] + func_800DC178(-10.0f, 10.0f), arg0->rotation[1] + func_800DC178(-10.0f, 10.0f), func_800DC178(200.0f, 300.0f));
        shot = func_80108528(0x460, sp8C, 0, &arg0);
        if (shot != NULL) {
            func_800EFB24(&shot->actorData[4], shot->position, sp80);
            func_800EF368((f32 *)&shot->actorData[4], func_800DC178(1000.0f, 1400.0f));
            shot->unk3C = arg0->unk0;
            func_80102FDC(shot, func_800DC178(0.8f, 1.2f));
        }
        i++;
    } while (i != 3);
}

/* extern */

void func_80802108_changlerboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    Unk80132ED0 *func_800D10D4(s32, s32, f32 *, s32, BtIntPtr);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80802210_changlerboss(Actor *, Unk80132ED0 *, u32, u32);
    struct AnglerBossCleanupData {
        u8 pad0[0x9C];
        s32 unk9C;
        Unk80132ED0 *unkA0;
    } *sp44;
    Unk80132ED0 *sp40;
    Unk80132ED0 *sp3C;
    f32 sp30[3];
    f32 *sp2C;
    struct AnglerBossFlagData {
        u8 pad0[0x73];
        u8 pad73_1 : 7;
        u8 flag : 1;
    };
    Actor *temp_v0;

    sp44 = func_80100094(arg0, 0);
    sp3C = arg0->unk0;
    sp2C = NULL;
    func_800FFA88(sp44->unkA0);
    sp44->unkA0 = NULL;
    func_8010114C(sp44->unk9C, 0x2C, 0);
    sp44->unk9C = 0;
    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, sp30) != 0) {
        sp2C = sp30;
    }
    sp40 = func_800D10D4(0x25, 1, sp2C, 0, 0);
    arg0 = func_80106790(sp3C);
    if (sp40 != NULL) {
        temp_v0 = func_80106790(sp40);
        ((struct AnglerBossFlagData *)temp_v0)->flag = 1;
        func_80802210_changlerboss(arg0, sp40, 0x19, 0x438);
    }
}

void func_808021E4_changlerboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802210_changlerboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802210_changlerboss(arg0, arg0->unk0, arg1, arg2);
}    typedef struct { u8 pad0[0x12B]; s8 unk12B; } Objanglerboss_func_80802210_changlerboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x12B]; u8 unk12B; } Objanglerboss_func_80802210_changlerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80802210_changlerboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3)
{
  s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
  s32 _capod_entrypoint_14(void);
  void *func_80100094(Actor *, u32);
  u8 *sp1C;
  u8 *temp_v0;
  temp_v0 = func_80100094(arg0, 0U);
  sp1C = temp_v0;
  arg3 = arg3;
  if ((((Objanglerboss_func_80802210_changlerboss_temp_v0 *)temp_v0)->unk12B) != 0)
  {
    _capod_entrypoint_14();
    arg3 = arg3 | 0x2000;
  }
  _capod_entrypoint_13(arg1, arg0->unk0, arg2, arg3);
  ((Objanglerboss_func_80802210_changlerboss_sp1C *)sp1C)->unk12B = 1;
}    typedef struct { u8 pad0[0x12B]; u8 unk12B; } Objanglerboss_func_80802288_changlerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80802288_changlerboss(Actor *arg0) {
    s32 _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objanglerboss_func_80802288_changlerboss_temp_v0 *)temp_v0)->unk12B) != 0) {
        _capod_entrypoint_14();
        (*(s8 *)((s8 *)(temp_v0) + (0x12B))) = 0;
    }
}    typedef struct { u8 pad0[0x92]; s16 unk92; u8 pad94[0x2]; s16 unk96; } Objanglerboss_func_808022C4_changlerboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_808022C4_changlerboss(Actor *arg0) {
    s32 func_800D2498(u32 itemDisplayUI, s32 value, u32 a2);
    void *func_80100094(Actor *, u32);
    s32 var_a1;
    s32 temp_t6;
    void *temp_v0;

    temp_t6 = arg0->unk70_10;
    if ((temp_t6 != 0xB) && (temp_t6 != 0xC) && (temp_t6 >= 5) && (temp_t6 < 0x19)) {
        temp_v0 = func_80100094(arg0, 0U);
        if ((((Objanglerboss_func_808022C4_changlerboss_temp_v0 *)temp_v0)->unk92) == 0) {
            var_a1 = func_80801C50_changlerboss(arg0);
        } else {
            var_a1 = (((Objanglerboss_func_808022C4_changlerboss_temp_v0 *)temp_v0)->unk96);
        }
        func_800D2498(0xFE, var_a1, 0);
    }
}

void func_80802340_changlerboss(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    int func_800DC298(f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    s32 func_80802430_changlerboss(Actor *);
    extern u32 D_80802FF8_changlerboss;

    switch (func_801022E4(arg0)) {
    case 0x3EC:
        if ((func_80102320(arg0, 0.25f, 0.8f) != 0) && (func_800DC298(0.15f) != 0)) {
            func_80802430_changlerboss(arg0);
        }
        break;
    case 0x330:
        if ((func_80102320(arg0, 0.25f, 0.75f) != 0) && (func_800DC298(0.1f) != 0)) {
            func_80802430_changlerboss(arg0);
        }
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80802FF8_changlerboss, 0.4f);
        break;
    case 0x33F:
        if (func_80101E14(arg0, 0.85f) != 0) {
            func_80802430_changlerboss(arg0);
        }
        break;
    }
}

s32 func_80802430_changlerboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA568(s16 *, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    extern s32 D_80803008_changlerboss;
    f32 sp44[3];
    s32 sp40;
    f32 temp_f20;
    BtIntPtr temp_v0_2;

    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 0xA, sp44);
        sp40 = func_800DC128(1, 3);
        temp_v0_2 = func_800B53A4(sp40);
        temp_f20 = arg0->scale * 1.3f;
        func_800BABB8(temp_v0_2, sp44, 0, 1.0f, &D_80803008_changlerboss);
        func_800BA568(temp_v0_2, (s16) (s32) (sp44[1] + 1000.0f));
        func_800BA7C4(temp_v0_2, 0.16f * temp_f20, 0.3f * temp_f20);
        func_800BA7FC(temp_v0_2, 0.45f * temp_f20, 0.6f * temp_f20);
        func_800BA994(temp_v0_2, -75, (s16) (s32) (arg0->rotation[1] - 75.0f), 800, -35, (s32) (arg0->rotation[1] + 75.0f), 1000);
        func_800BA22C(temp_v0_2, sp40);
    }
    BT_NATIVE_ONLY(return 0;) }

/* extern */

BtIntPtr func_808025AC_changlerboss(BtIntPtr arg0) {
    BtIntPtr func_800F54E4();
    BtIntPtr func_8010D290(s32);
    BtIntPtr temp_v0;
    BtIntPtr var_v1;

    temp_v0 = func_8010D290(0x400);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800F54E4();
    }
    return var_v1;
}

void func_808025EC_changlerboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    extern s16 D_80803054_changlerboss;
    s32 i;
    struct {
        f32 pad0[15];
        f32 unk3C[6][3];
        f32 unk84[3];
    } *sp30;

    sp30 = func_80100094(arg0, 0);
    for (i = 0; i < 6; i++) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, (&D_80803054_changlerboss)[i], sp30->unk3C[i]);
    }
    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xC, sp30->unk84);
}

void func_80802680_changlerboss(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80103DFC(Actor *, f32 *);
    extern s32 D_80803060_changlerboss[];
    f32 position[3];
    f32 delta;
    f32 scale;
    BtIntPtr emitter;
    s32 i;
    struct {
        f32 pad0[9];
        f32 timers[6];
        f32 points[6][3];
    } *data;

    delta = func_800D8FF8();
    data = func_80100094(arg0, 0);
    func_80103DFC(arg0, position);
    position[1] -= 600.0f;
    for (i = 0; i != 6; i++) {
        if (data->timers[i] > 0.0f) {
            scale = func_800F10B4(data->timers[i], 0.0f, 2.0f, 0.75f, 1.0f);
            data->timers[i] -= delta;
            emitter = func_800B53A4(1);
            func_800BABB8(emitter, data->points[i], position, scale, D_80803060_changlerboss);
            func_800BA22C(emitter, 1);
        }
    }
}

/* extern */

void func_808027F8_changlerboss(void *arg0) {
    void func_800EFD24(f32 *);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];
    f32 temp_f0;

    func_800EFD24((f32 *)sp1C);
    temp_f0 = func_80102D78(arg0, sp1C);
    (((Actor *)arg0)->unk54) = temp_f0;
    (((Actor *)arg0)->rotation[1]) = temp_f0;
    (((Actor *)arg0)->unk50) = 0.0f;
    (((Actor *)arg0)->rotation[0]) = 0.0f;
}

/* extern */

void func_80802844_changlerboss(void *arg0) {
    s32 func_800C8A98();
    struct {
        u8 pad0[0x54];
        s32 unk54;
        f32 unk58;
        u8 pad5C[0x1E];
        u8 unk7A_7 : 2;
        u8 pad7A_5 : 6;
    } *self = arg0;
    self->unk58 = 0.4f;
    self->unk7A_7 = 2;
    self->unk54 = func_800C8A98();
}

void func_80802888_changlerboss(Actor *arg0) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    s32 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800F2F60(void *, void *, f32);
    void func_80101FDC(Actor *, u32);
    extern u32 D_80803098_changlerboss[3];
    u32 sp54[3];
    f32 sp50;
    u32 sp44[3];
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 scale;
    struct {
        u8 pad0[0x54];
        s32 unk54;
    } *self = (void *)arg0;

    switch (arg0->unk70_10) {
    case 1:
        arg0->unk64_16 = 0;
        sp50 = arg0->scale * 0.3f;
        func_800F2F60(sp54, D_80803098_changlerboss, 0.3f);
        func_800C8E54(self->unk54, sp50 * 400.0f, sp50 * 1000.0f);
        func_800C8E84(self->unk54, sp54);
        break;
    case 2:
        sp40 = func_800D9078(&arg0->unk58);
        sp3C = func_800F12D4(arg0->unk58, 0.0f, 0.4f, 1.0f, 0.3f);
        arg0->unk64_16 = 1;
        sp38 = arg0->scale * sp3C;
        func_800F2F60(sp44, D_80803098_changlerboss, sp3C);
        func_800C8E54(self->unk54, sp38 * 400.0f, sp38 * 1000.0f);
        func_800C8E84(self->unk54, sp44);
        _subaddiefade_entrypoint_1((BtIntPtr)arg0, (s32)(sp3C * 255.0f));
        if (sp40 != 0) {
            func_80101FDC(arg0, 3);
        }
        break;
    case 3:
        scale = arg0->scale;
        arg0->unk64_16 = 1;
        func_800C8E54(self->unk54, scale * 400.0f, scale * 1000.0f);
        func_800C8E84(self->unk54, D_80803098_changlerboss);
        break;
    }
    if (self->unk54 != 0) {
        func_800C8CB8(self->unk54, arg0->position);
    }
}

/* extern */

s32 func_80802A90_changlerboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddiefade_entrypoint_3(Actor *);
    void func_80101FDC(Actor *, u32);
    struct {
        u8 pad0[0x54];
        s32 unk54;
    } *self = (void *)arg0;
    s32 temp_a0;
    s32 result;

    if (arg1 == 0x2C) {
        temp_a0 = self->unk54;
        if (temp_a0 != 0) {
            self->unk54 = _chlightfader_entrypoint_1(temp_a0, 1.0f, 3);
        }
        _subaddiefade_entrypoint_3(arg0);
        func_80101FDC(arg0, 4);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 B_808030B0_changlerboss [ 3 ] BT_DATA(16, bss_ch_anglerboss, 0x0);
#endif
