#include "common.h"

/* extern */

void chfantasylakebits_entrypoint_0(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    Vtx *end;

    actor = func_80106790(arg4);
    end = arg2 + arg3;
    if (arg2 < end) {
        do {
            arg2->v.cn[0] = 255;
            arg2->v.cn[1] = 255;
            arg2->v.cn[2] = 0;
            arg2++;
            arg1++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + actor->actorData[3];
        } while (arg2 < end);
    }
}

void func_8080007C_chfantasylakebits(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800D90A4(f32 *);
    int func_800D91EC(f32 *, f32);
    int func_800DB9B0(void);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800F8418(BtIntPtr, f32 *);
    void func_80800300_chfantasylakebits(BtIntPtr, s16);
    extern u32 D_80800920_chfantasylakebits[];
    extern u32 D_80800928_chfantasylakebits[];
    extern f32 D_80800934_chfantasylakebits[];
    extern s32 D_80800940_chfantasylakebits[];
    extern s32 D_80800980_chfantasylakebits[];
    extern f32 D_808009B8_chfantasylakebits[];
    extern f32 D_808009C4_chfantasylakebits[];
    extern f32 D_808009D0_chfantasylakebits[];
    extern s32 D_808009DC_chfantasylakebits[];
    s16 sp2E;

    switch (arg0->unk70_10) {
    case 2:
        if (func_800DB9B0() == 0) {
            _capod_entrypoint_13(arg0->unk0, NULL, 0x23, 0x30);
        }
        func_800D91EC(&arg0->unk58, 12.0f);
        func_80800300_chfantasylakebits((BtIntPtr)arg0, (s16)(s32)func_800F10B4(arg0->unk58, 0.0f, 12.0f, 0, -3200.0f));
        _subaddieaudioloop_entrypoint_4(arg0, D_80800934_chfantasylakebits, 1, D_80800920_chfantasylakebits);
        break;
    case 3:
        if (arg0->unk58 < 6.0f) {
            func_800BBCB8(D_80800934_chfantasylakebits, D_80800934_chfantasylakebits, 1.0f, 2, D_80800940_chfantasylakebits);
        }
        func_800D91EC(&arg0->unk58, 12.0f);
        sp2E = (s16)(s32)func_800F10B4(arg0->unk58, 0.0f, 12.0f, 0, -3200.0f);
        _subaddieaudioloop_entrypoint_4(arg0, D_80800934_chfantasylakebits, 1, D_80800920_chfantasylakebits);
        func_80800300_chfantasylakebits((BtIntPtr)arg0, sp2E);
        break;
    case 4:
        func_800BBCB8(D_808009B8_chfantasylakebits, NULL, 1.0f, 2, D_80800980_chfantasylakebits);
        func_800D90A4(&((f32 *)arg0->actorData)[7]);
        func_800EFE50(arg0->position, D_808009C4_chfantasylakebits, D_808009D0_chfantasylakebits, func_800F10B4(((f32 *)arg0->actorData)[7], 5.0f, 0.0f, 0.0f, 1.0f));
        arg0->unk54 = func_800F10B4(((f32 *)arg0->actorData)[7], 5.0f, 0.0f, 1.0f, 2.0f);
        _subaddieaudioloop_entrypoint_4(arg0, D_80800934_chfantasylakebits, 1, D_80800928_chfantasylakebits);
        _subaddieaudioloop_entrypoint_0(arg0, 1.0f);
        if (((f32 *)arg0->actorData)[7] > 2.0f) {
            func_800BBCB8(D_808009B8_chfantasylakebits, NULL, 1.0f, 1, D_808009DC_chfantasylakebits);
        }
        func_800F8418(func_800F54E4(), &((f32 *)arg0->actorData)[4]);
        break;
    }
}

/* extern */

void func_80800300_chfantasylakebits(BtIntPtr arg0, s16 arg1) {
    void _idwibble_entrypoint_5(void *arg0, s16 arg1);
    BtIntPtr _idworld_entrypoint_4(BtIntPtr, s32);
    void *func_800BEA88(s32 i);
    BtIntPtr temp_v0;

    temp_v0 = _idworld_entrypoint_4(func_800BEA88(1), 1);
    if (temp_v0 != 0) {
        _idwibble_entrypoint_5(temp_v0, arg1);
    }
}

void func_80800344_chfantasylakebits(Actor *arg0, s32 arg1) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void _idworldmake_entrypoint_1(BtIntPtr arg0, s32 arg1, volatile unsigned int arg2, s32 arg3);
    void _subaddieDll_entrypoint_0(void *arg0);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    void *func_800BEA88(s32 i);
    void func_800BF744(s32, s32);
    void func_800DA524(s32 index);
    void func_800DA544(s32);
    s32 func_800EA05C();
    u32 func_800F54E4(void);
    BT_IDO_ONLY(f32) BT_NATIVE_ONLY(s32) func_800F5628(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800F9C38(void);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A800(Actor *, s32);
#ifndef BT_NATIVE
    extern s32 _chfantasylakebits_entrypoint_0;
#endif
    BtIntPtr sp2C;
    BtIntPtr temp_v0;
    BtIntPtr sp24;
    s32 pad;

    switch (arg1) {
    case 1:
        sp2C = func_800BEA88(1);
        arg0->unk58 = 0.0f;
        func_800BF744(1, 1);
        arg0->actorData[3] = 0;
        _idworldmake_entrypoint_1(sp2C, 0x654, 1, 1);
        _glid_entrypoint_0(sp2C, 1, &_chfantasylakebits_entrypoint_0, arg0->unk0);
        if (func_800EA05C() == 0x13A) {
            temp_v0 = func_800BEA88(0);
            arg0->actorData[3] = 0;
            _idworldmake_entrypoint_1(temp_v0, 0x59B, 2, 1);
        }
        arg0->unk64_16 = 0;
        func_80103110(arg0, 0);
        break;
    case 2:
        func_800F9C38();
        func_80103110(arg0, 1);
        arg0->unk58 = 0.0f;
        _subaddieDll_entrypoint_0(arg0);
        arg0->unk54 = 1.0f;
        func_80103140(arg0, 0x8DE, arg0->unk0->unk16);
        break;
    case 3:
        func_8010A800(arg0, 2);
        func_800F5A00(func_800F54E4(), &((f32 *)arg0->actorData)[4]);
        BT_IDO_ONLY(((f32 *)arg0->actorData)[5] = func_800F5628(func_800F54E4());) BT_NATIVE_ONLY(((s32 *)arg0->actorData)[5] = func_800F5628(func_800F54E4());)
        break;
    case 4:
        func_800BF744(1, 0);
        arg0->unk64_16 = 1;
        ((f32 *)arg0->actorData)[7] = 5.0f;
        _subaddieaudioloop_entrypoint_2(arg0);
        break;
    case 5:
        sp24 = func_800BEA88(1);
        func_800BF744(1, 0);
        arg0->actorData[3] = -0xC80;
        _glid_entrypoint_0(sp24, 1, &_chfantasylakebits_entrypoint_0, arg0->unk0);
        _idworldmake_entrypoint_1(sp24, 0x654, 1, 1);
        func_800DA544(0x327);
        func_800DA524(0x9FC);
        arg0->unk64_16 = 0;
        _subaddieaudioloop_entrypoint_2(arg0);
        func_800FFAB0(arg0);
        break;
    }
    func_80101FDC(arg0, arg1);
}

s32 func_80800570_chfantasylakebits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 func_800DA298(s32);
    void func_800DF500(f32, f32, f32);
    void func_800E3980(f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_801015D0(Actor *);
    f32 sp24[3];

    switch (arg1) {
    case 0xB:
        if (arg2 == 0x23) {
            _capod_entrypoint_14();
            func_80800344_chfantasylakebits(arg0, 5);
            _glcutDll_entrypoint_6(0x112, 0x36);
            return 4;
        }
        return 3;
    case 0xC:
        if (arg0->unk70_10 == 2) {
            func_80800344_chfantasylakebits(arg0, 3);
            return 3;
        }
        if (arg0->unk70_10 == 3) {
            func_80800344_chfantasylakebits(arg0, 4);
        }
        return 3;
    case 0x36:
        func_80800344_chfantasylakebits(arg0, 2);
        return 1;
    case 0x1F:
        if (arg0->unk64_16) {
            func_801015D0(arg0);
            func_800E3980(sp24);
            arg0->rotation[1] = func_800F1DF4(arg0->position, sp24);
            func_800DF500(arg0->unk54, 4.0f, arg0->unk54);
        }
        return 1;
    case 0x95:
        if (func_800DA298(0x327)) {
            func_80800344_chfantasylakebits(arg0, 5);
            return 1;
        }
        func_80800344_chfantasylakebits(arg0, 1);
        return 1;
    default:
        return 0;
    }
}

OSThread *chfantasylakebits_entrypoint_1(void)
{
    extern ActorData D_80800A30_chfantasylakebits[];

    return (OSThread *) D_80800A30_chfantasylakebits;
}

/* extern */

void func_808006F4_chfantasylakebits(s32 *arg0) {
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0 *);
    if ((func_800DA298(0x327) != 0) || (func_800DA298(0x9FC) != 0)) {
        func_800FFA88((Unk80132ED0 *)*arg0);
    }
}

BtIntPtr func_8080073C_chfantasylakebits(Actor *arg0, s32 arg1, s32 arg2) {
    void _chskeletonexplode_entrypoint_3(Actor *arg0, s32 arg1, s32 arg2);
    void _chskeletonexplode_entrypoint_4(Actor *arg0, s32 arg1);
    void _chskeletonexplode_entrypoint_7(Actor *arg0, f32 *arg1);
    BtIntPtr _fxairbub_entrypoint_1(f32 arg0[3], f32 arg1, f32 arg2, f32 arg3);
    s32 func_8008FCC8(Unk80132ED0 *arg0);
    void func_800BA22C(BtIntPtr arg0, s32 n);
    void func_800BA930(BtIntPtr arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
    BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4);
    void func_800C4AF0(f32 *arg0, void *arg1);
    void func_800DA544(s32 index);
    void func_800DF744(s32 arg0, s32 arg1);
    void func_800FFA88(Unk80132ED0* a0);
    void *func_80101080(void);
    s32 func_80101180(s32 arg0, s32 arg1, BtIntPtr arg2);
    s32 func_801015D0(Actor *arg0);
    Actor *func_80106790(Unk80132ED0 *arg0);
    extern s32 D_80800A78_chfantasylakebits[];
    extern s32 D_80800AB4_chfantasylakebits[];
    extern s32 D_80800ADC_chfantasylakebits[];
    BtIntPtr result;
    Actor *actor;

    switch (arg1) {
    case 0x40:
        if (func_8008FCC8(arg0->unk0) == 0x14) {
            result = _fxairbub_entrypoint_1(arg0->position, 200.0f, arg0->position[1] + 500.0f, 3.0f);
            func_800BA930(result, -60, -250, -60, 60, 0, 60);
            func_800BA22C(result, 10);
            func_800BBCB8(arg0->position, arg0->position, arg0->scale, 3, D_80800A78_chfantasylakebits);
            func_800BBCB8(arg0->position, arg0->position, arg0->scale, 8, D_80800AB4_chfantasylakebits);
            func_800C4AF0(arg0->position, D_80800ADC_chfantasylakebits);
            func_80101180(0x415, 0x36, 0);
            _chskeletonexplode_entrypoint_7(arg0, arg0->position);
            func_800DA544(0x9FC);
            return 1;
        }
        return 0;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(1, 1);
        func_800DF744(2, 1);
        return 1;
    case 0xF:
        actor = func_80106790(func_80101080());
        _chskeletonexplode_entrypoint_3(actor, 1, 2);
        _chskeletonexplode_entrypoint_3(actor, 2, 1);
        _chskeletonexplode_entrypoint_4(actor, 1);
        func_800FFA88(arg0->unk0);
        return 1;
    default:
        result = 0;
        break;
    }
    return result;
}

OSThread *chfantasylakebits_entrypoint_2(void)
{
    extern ActorData D_80800AF0_chfantasylakebits[];

    return (OSThread *) D_80800AF0_chfantasylakebits;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/lakebits.data.s */
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
u32 D_80800920_chfantasylakebits [2] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x0) = { 0x20013, 0x56A0000 };
u32 D_80800928_chfantasylakebits [3] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x8) = { 0x20013, 0x3EC0016, 0x7D000000 };
f32 D_80800934_chfantasylakebits [3] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x14) = { -12500.0f, -4000.0f, 6000.0f };
s32 D_80800940_chfantasylakebits [16] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x20) = { 1903051, 1446416, 1769772, 39321644, -9830400, -9830250, 150, 917604, 6553634, 1638451, 2490444, 1376435, 15073323, 3342438, 458753, 0 };
s32 D_80800980_chfantasylakebits [14] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x60) = { 1903091, 2162687, -21757918, 6684800, 3342412, 1831508, -229375993, 65579, 167774720, 1442304, 917579, 4915230, 13107400, 0 };
f32 D_808009B8_chfantasylakebits [3] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x98) = { -12520.0f, -4500.0f, 6080.0f };
f32 D_808009C4_chfantasylakebits [3] BT_DATA(4, overlays_ch_fantasy_lakebits, 0xA4) = { -12520.0f, -3000.0f, 6080.0f };
f32 D_808009D0_chfantasylakebits [3] BT_DATA(4, overlays_ch_fantasy_lakebits, 0xB0) = { -12520.0f, -5000.0f, 6080.0f };
s32 D_808009DC_chfantasylakebits [21] BT_DATA(4, overlays_ch_fantasy_lakebits, 0xBC) = { 1903069, 1446416, 1572864, 462592, 503316507, -39256464, 2948970, 65386, 9830400, 9830414, 6553700, 2228352, 8388992, 50331669, 3342464, 2818252, 20119599, 3473510, 3473408, 0, 13369344 };
ActorData D_80800A30_chfantasylakebits [1] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x110) = { { 344, 1045, 0, 1, 0, (void (*)(struct Actor *))func_8080007C_chfantasylakebits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 15000, 0, 0, 0, 0, 4096, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80800570_chfantasylakebits, 0 } };
s32 D_80800A78_chfantasylakebits [15] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x158) = { 1903069, 2820096, 167772194, 25166336, 75499008, 1376256, 2490393, 7, 2949170, 6553632, -559451712, 720796, 1703836, 6553675, 6553600 };
s32 D_80800AB4_chfantasylakebits [10] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x194) = { 1902895, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4915200 };
s32 D_80800ADC_chfantasylakebits [5] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x1BC) = { 1246227, 655590, 1469792, 131099, 0 };
ActorData D_80800AF0_chfantasylakebits [1] BT_DATA(4, overlays_ch_fantasy_lakebits, 0x1D0) = { { 267, 1044, 2346, 1, 0, 0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808006F4_chfantasylakebits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_8080073C_chfantasylakebits, 0 } };
