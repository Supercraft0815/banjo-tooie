#include "ch/friesstand.h"
#include "core2/switch_animations.h"
void *func_80100094(Actor *, u32);

OSThread *chfriesstand_entrypoint_0(void)
{
    extern ActorData D_80800EC8_chfriesstand[];

    return (OSThread *) D_80800EC8_chfriesstand;
}

OSThread *chfriesstand_entrypoint_1(void)
{
    extern ActorData D_80800F10_chfriesstand[];

    return (OSThread *) D_80800F10_chfriesstand;
}

OSThread *chfriesstand_entrypoint_2(void)
{
    extern ActorData D_80800F58_chfriesstand[];

    return (OSThread *) D_80800F58_chfriesstand;
}

OSThread *chfriesstand_entrypoint_3(void)
{
    extern ActorData D_80800FA0_chfriesstand[];

    return (OSThread *) D_80800FA0_chfriesstand;
}

void func_80800030_chfriesstand(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    Actor *other;

    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
    } else {
        arg0->unk64_16 = func_800DA298(FLAG_0A0_UNK);
    }
    func_80103110(arg0, arg0->unk64_16);
    other = _subaddiefind_entrypoint_2(0x331, 0);
    if (other != NULL) {
        func_800EE7F8((f32 *)arg0->actorData, other->position);
        ((f32 *)arg0->actorData)[1] = arg0->position[1];
    }
}

void func_808000C4_chfriesstand(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    BT_IDO_ONLY(void func_800D175C(s32, s32);) BT_NATIVE_ONLY(s32 func_800D175C(s32, s32);)
    s32 func_800D1A04(s32);
    s32 func_800F4EC8(BtUIntPtr, BtIntPtr, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800FC660(u32);
    void func_800FFA88(Unk80132ED0 *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    void func_80102424(Actor *, s32);
    void func_808005F0_chfriesstand(Actor *);
    void func_80800620_chfriesstand(Actor *);
    void func_808006D4_chfriesstand(Actor *);
    void func_808009A4_chfriesstand(Actor *);
    extern u32 D_80800FE8_chfriesstand[];

    if (func_80100094(arg0, 1) != NULL) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
        if (func_801022E4(arg0) != 0xD0 || !func_80102320(arg0, 0.45f, 0.85f)) {
            _suexpression_entrypoint_18(func_80100094(arg0, 1), 1);
        }
    }
    func_800F4EC8(func_800F54E4(), (BtIntPtr)arg0->actorData, 300.0f, -10.0f, 200.0f);
    switch (arg0->unk70_10) {
        case 1:
            func_808005F0_chfriesstand(arg0);
            if (func_80101E14(arg0, 0.999f)) {
                if (arg0->unk6C_0 < 2) {
                    arg0->unk6C_0++;
                } else {
                    func_80102424(arg0, 2);
                }
            }
            func_808009A4_chfriesstand(arg0);
            break;
        case 2:
            func_80800620_chfriesstand(arg0);
            func_808006D4_chfriesstand(arg0);
            if (func_80101DDC(arg0)) {
                arg0->unk6C_0 = 0;
                func_80102424(arg0, 1);
            }
            func_808009A4_chfriesstand(arg0);
            break;
        case 3:
            func_808005F0_chfriesstand(arg0);
            break;
        case 4:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800FE8_chfriesstand, 0.7f);
            if (func_80101E14(arg0, 0.837f)) {
                if (arg0->unk3C != NULL) {
                    func_800FC660(0xE);
                    func_800D175C(0x4C, 5 - func_800D1A04(0x4C));
                    func_800FFA88(arg0->unk3C);
                    arg0->unk3C = NULL;
                }
                _subaddiedialog_entrypoint_11(arg0->unk0,
                    func_800F64A4(func_800F54E4(), 0x200) ? 0x110B : 0x10FD,
                    6, arg0->position, 0x51);
            }
            if (func_80101DDC(arg0)) {
                arg0->unk6C_0 = 0;
                func_80102424(arg0, 1);
            }
            break;
        case 5:
            func_808005F0_chfriesstand(arg0);
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 6);
            }
            break;
        case 6:
            func_80800620_chfriesstand(arg0);
            func_808006D4_chfriesstand(arg0);
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 5);
            }
            break;
    }
}

void func_80800398_chfriesstand(Actor* arg0)
{
    func_80800970_chfriesstand(arg0);
}

s32 func_808003B8_chfriesstand(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(Unk80132ED0 *, BtIntPtr, s32, s32);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_80090734(s32, f32 *);
    s32 func_800D1A04(s32);
    void func_80101EE4(Actor *actor,f32 time);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80108B04(Actor *arg0, u32 arg1);
    s32 func_80800904_chfriesstand(Actor *);
    void func_808009F0_chfriesstand(Actor *, s32, s16);
    void func_80800AEC_chfriesstand(Actor *, s32, s16);
    s32 func_80800BB0_chfriesstand(Actor *);
    extern s32 D_80800FF0_chfriesstand[4];
    Unk80132ED0 *temp_a0;
    s32 temp_t7;
    void *temp_v0;

    switch (arg1) {
    default:
        return 0;
    case 0x2E:
        func_808009F0_chfriesstand(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x2F:
        func_80800AEC_chfriesstand(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x32:
        func_80090734(2, arg0->position);
        break;
    case 0x3D:
        func_80800BB0_chfriesstand(arg0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800FF0_chfriesstand, arg0->scale);
        break;
    case 0xA:
        arg0->unk64_16 = 1;
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.0f);
        func_80103110(arg0, 1);
        temp_a0 = arg0->unk3C;
        if (temp_a0 != NULL) {
            temp_v0 = func_80106790(temp_a0);
            ((Actor *)temp_v0)->unk64_16 = arg0->unk64_16;
        }
        _capod_entrypoint_13(arg0->unk0, 0, 0x16, 0x30);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10E0, 4, arg0->position, 0x51);
        break;
    case 0x29:
        func_80800904_chfriesstand(arg0);
        break;
    case 0x2A:
        func_80800970_chfriesstand(arg0);
        break;
    case 0x95:
        if (func_800D1A04(0x4C) == 0) {
            func_80108B04(arg0, 0);
        }
        break;
    case 0xB8:
        temp_t7 = arg2 & 0xFFFF;
        switch (temp_t7) {
        default:
            return 0;
        case 1:
            return arg0->unk3C != NULL ? 0x10AE : 0x10AF;
        case 2:
            return arg0->unk3C != NULL ? 0x1109 : 0x110A;
        }
    }
    return 1;
}

void func_808005F0_chfriesstand(Actor *arg0) {
    extern u32 D_80801000_chfriesstand[3];
    extern u32 D_8080100C_chfriesstand[4];
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801000_chfriesstand, D_8080100C_chfriesstand);
}

void func_80800620_chfriesstand(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_8080101C_chfriesstand[4];
    extern u32 D_8080102C_chfriesstand[3];
    extern u32 D_80801038_chfriesstand[3];
    extern u32 D_80801044_chfriesstand[3];
    extern u32 D_80801050_chfriesstand[3];
    extern u32 D_8080105C_chfriesstand[4];
    f32 *temp_s1;

    temp_s1 = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_8080102C_chfriesstand, 0.08f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80801038_chfriesstand, 0.23f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80801044_chfriesstand, 0.34f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80801050_chfriesstand, 0.42f);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_8080101C_chfriesstand, D_8080105C_chfriesstand);
}

void func_808006D4_chfriesstand(Actor *arg0) {
    s32 func_80101E14(Actor *, f32);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA610(BtIntPtr, s16, s16);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_8080106C_chfriesstand[];
    f32 position[3];
    f32 angle;
    f32 scale;
    BtIntPtr emitter;

    if (func_80101E14(arg0, 0.345f)) {
        if (!_subaddieskeleton_entrypoint_3(arg0->unk0, 4, position)) {
            return;
        }
        func_800EF1B8(position, arg0->rotation[1], 20.0f);
        emitter = func_800B53A4(12); func_800BABB8(emitter, position, NULL, arg0->scale, D_8080106C_chfriesstand);
        func_800BA610(emitter, -100, -100);
        angle = arg0->rotation[1]; scale = arg0->scale; func_800BA994(emitter, 15, (s16)(s32)(angle - 50.0f), (s16)(s32)(scale * 300.0f), 20, (s32)(angle + 50.0f), (s32)(scale * 450.0f));
        func_800BA22C(emitter, 12);
    }
    if (func_80101E14(arg0, 0.43f) && _subaddieskeleton_entrypoint_3(arg0->unk0, 4, position)) {
        emitter = func_800B53A4(5); func_800BABB8(emitter, position, NULL, arg0->scale * 1.2f, D_8080106C_chfriesstand);
        func_800BA610(emitter, -800, -1000);
        angle = arg0->rotation[1] + 90.0f; scale = arg0->scale; func_800BA994(emitter, -25, (s16)(s32)(angle - 10.0f), (s16)(s32)(scale * 200.0f), -15, (s32)(angle + 10.0f), (s32)(scale * 400.0f));
        func_800BA22C(emitter, 5);
    }
}

s32 func_80800904_chfriesstand(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x51);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    } BT_NATIVE_ONLY(return 0;)
}

void func_80800970_chfriesstand(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808009A4_chfriesstand(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 func_80090734(s32, f32 *);
    extern s32 D_80801088_chfriesstand[6];
    extern s32 D_80800E50_chfriesstand[10];
    f32 *position[2];

    position[1] = arg0->position;
    if (_subaddiedialog_entrypoint_8((BtIntPtr)arg0, position[1], D_80801088_chfriesstand, D_80800E50_chfriesstand, 5) != 0) {
        func_80090734(1, position[1]);
    }
}

void func_808009F0_chfriesstand(Actor *arg0, s32 arg1, s16 arg2) {
    void _capod_entrypoint_14(void);
    s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);
    void func_8008FC9C(s32);
    void func_80090708(s32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800E50_chfriesstand[10];
    switch (arg1) {
        case 0x10E0:
            _capod_entrypoint_14();
            arg0->unk6C_0 = 0;
            func_80102424(arg0, 1);
            break;
        case 0x10FD:
        case 0x110B:
            func_8008FC9C(0);
            func_80102424(arg0, 1);
            break;
        default:
            if (arg0->unk3C != NULL && _subaddiedialog_entrypoint_9(arg0, arg1, D_80800E50_chfriesstand, 5) == 2) {
                func_80102424(arg0, 4);
                func_80102424(func_80106790(arg0->unk3C), 2);
            } else {
                arg0->unk6C_0 = 0;
                func_80102424(arg0, 1);
                func_80090708(0);
            }
            break;
    }
}

void func_80800AEC_chfriesstand(Actor *arg0, s32 arg1, s16 arg2) {
    s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);
    void func_8010D254(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_80090708(s32);
    void func_8008F8B0(void);
    void func_8008F904(void *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    extern s32 D_80800E50_chfriesstand[10];
    extern s32 func_8010D5DC;
    f32 sp34[3];
    f32 sp28[3];
    s32 pad[2];

    if (arg0->unk3C != NULL && _subaddiedialog_entrypoint_9(arg0, arg1, D_80800E50_chfriesstand, 5) == 2) {
        func_8010D254(sp28);
        func_800EE7F8(sp34, arg0->position);
        func_800EF1B8(sp34, arg0->rotation[1], 255.0f);
        if (func_800EEAD4(sp28, sp34) > 50.0f) {
            func_80090708(0);
            func_8008F8B0();
            func_8008F904(&func_8010D5DC, arg0->unk0);
            func_8008F990(sp34, 170.0f);
        }
    }
}

s32 func_80800BB0_chfriesstand(Actor *arg0) {
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_80102FDC(void *, f32);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    Actor *temp_v0;
    s32 sp20[3];

    temp_v0 = func_801084B0(0x32E, &arg0);
    func_80102FDC(temp_v0, arg0->scale);
    _subaddiefade_entrypoint_9(arg0, sp20);
    _subaddiefade_entrypoint_11(temp_v0, sp20);
    arg0->unk3C = temp_v0->unk0;
    temp_v0->unk64_16 = arg0->unk64_16; BT_NATIVE_ONLY(return (s32)temp_v0;)
}

void func_80800C34_chfriesstand(s32 arg0) 
{
}    typedef struct { u8 pad0[0x8]; f32 unk8; } Objfriesstand_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
/* extern */

void func_80800C3C_chfriesstand(void *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800EA05C();
    void func_80101FDC(Actor *, u32);
    void func_8010A624(void ***);
    s32 var_v0;

    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
    }
    (((Objfriesstand_arg0 *)arg0)->unk8) = (f32) ((((Objfriesstand_arg0 *)arg0)->unk8) - 225.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        var_v0 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_v0 = 0xA0;
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 225.0f, 0x20, var_v0) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_8(arg0, 3);
    }
}

void func_80800CF0_chfriesstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_0A0_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800D1C_chfriesstand(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    int result;
    if (arg1 == 7) {
        func_80101180(0x331, 7, 0);
        func_80101180(0x32D, 0xA, 0);
        result = 1;
    } else {
        return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return result;
}
/* data_to_c.py: from asm/data/overlays/ch/friesstand.data.s */
extern u8 D_80800E78_chfriesstand[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_80800EB0_chfriesstand[];
void func_80102EC0();
void _chdoor_entrypoint_0();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);

void _chswitch_entrypoint_6();
s32 D_80800E50_chfriesstand[10] BT_DATA(4, overlays_ch_friesstand, 0x0) = { 1, 279773440, 1, -65024, 512, 285737216, 512, -130560, -73729, 303039232 };
u8 D_80800E78_chfriesstand[56] BT_DATA(4, overlays_ch_friesstand, 0x28) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x20, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x01, 0x41, 0x20, 0x00, 0x00, 0x00, 0xD1, 0x00, 0x02, 0x41, 0x20, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x01, 0x40, 0x10, 0x00, 0x00, 0x00, 0xDA, 0x00, 0x02, 0x41, 0x20, 0x00, 0x00, 0x00, 0xD0, 0x00, 0x02, 0x41, 0x20, 0x00, 0x00, 0x00, 0xD1, 0x00, 0x02 };
u8 D_80800EB0_chfriesstand[24] BT_DATA(4, overlays_ch_friesstand, 0x60) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x10, 0x00, 0x00, 0x00, 0xDB, 0x00, 0x44, 0x40, 0x10, 0x00, 0x00, 0x00, 0xDB, 0x00, 0x02 };
ActorData D_80800EC8_chfriesstand [1] BT_DATA(4, overlays_ch_friesstand, 0x78) = { { 441, 813, 1709, 1, (void *)D_80800E78_chfriesstand, (void (*)(struct Actor *))func_808000C4_chfriesstand, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 131072000, 0, 0, 0, 16384, 352, (void (*)(struct Actor *))func_80800398_chfriesstand, 0, 0, 0, (void (*)(struct Actor *))func_80800030_chfriesstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 25618, (void (*)(struct Actor *, long, long))func_808003B8_chfriesstand, 0 } };
ActorData D_80800F10_chfriesstand [1] BT_DATA(4, overlays_ch_friesstand, 0xC0) = { { 442, 814, 1712, 1, (void *)D_80800EB0_chfriesstand, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800C34_chfriesstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32752, 10258, 0, 0 } };
ActorData D_80800F58_chfriesstand [1] BT_DATA(4, overlays_ch_friesstand, 0x108) = { { 172, 817, 1909, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800C3C_chfriesstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_80800FA0_chfriesstand [1] BT_DATA(4, overlays_ch_friesstand, 0x150) = { { 835, 818, 2365, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800CF0_chfriesstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11282, (void (*)(struct Actor *, long, long))func_80800D1C_chfriesstand, 0 } };
u32 D_80800FE8_chfriesstand [2] BT_DATA(4, overlays_ch_friesstand, 0x198) = { 0x1303FF, 0 };
s32 D_80800FF0_chfriesstand[4] BT_DATA(4, overlays_ch_friesstand, 0x1A0) = { 1131085824, 1125515264, 1120403456, 1120403456 };
u32 D_80801000_chfriesstand[3] BT_DATA(4, overlays_ch_friesstand, 0x1B0) = { 0x130419, 0xD01A6, 0x1C00000 };
u32 D_8080100C_chfriesstand[4] BT_DATA(4, overlays_ch_friesstand, 0x1BC) = { 0x3E6B851F, 0x3E9EB852, 0x3EB33333, 0xBF800000 };
u32 D_8080101C_chfriesstand[4] BT_DATA(4, overlays_ch_friesstand, 0x1CC) = { 0x130449, 0xD0166, 0x1800016, 0x27100000 };
u32 D_8080102C_chfriesstand[3] BT_DATA(4, overlays_ch_friesstand, 0x1DC) = { 0x130500, 0xD0140, 0x1590000 };
u32 D_80801038_chfriesstand[3] BT_DATA(4, overlays_ch_friesstand, 0x1E8) = { 0x130502, 0xD0126, 0x1400000 };
u32 D_80801044_chfriesstand[3] BT_DATA(4, overlays_ch_friesstand, 0x1F4) = { 0x130503, 0xD0126, 0x1400000 };
u32 D_80801050_chfriesstand[3] BT_DATA(4, overlays_ch_friesstand, 0x200) = { 0x130501, 0xD0126, 0x1400000 };
u32 D_8080105C_chfriesstand[4] BT_DATA(4, overlays_ch_friesstand, 0x20C) = { 0x3F4F5C29, 0x3F570A3D, 0x3F5D70A4, 0xBF800000 };
s32 D_8080106C_chfriesstand [7] BT_DATA(4, overlays_ch_friesstand, 0x21C) = { 1902940, 2228226, 327687, 786453, 153, 2818176, 13369344 };
s32 D_80801088_chfriesstand[6] BT_DATA(4, overlays_ch_friesstand, 0x238) = { 10354688, 19660881, 6, 120718080, 0, 0 };
