#include "ch/burgerstand.h"
#include "core2/switch_animations.h"
OSThread *chburgerstand_entrypoint_0(void)
{
    extern ActorData D_80800C28_chburgerstand[];

    return (OSThread *) D_80800C28_chburgerstand;
}

OSThread *chburgerstand_entrypoint_1(void)
{
    extern ActorData D_80800C70_chburgerstand[];

    return (OSThread *) D_80800C70_chburgerstand;
}

OSThread *chburgerstand_entrypoint_2(void)
{
    extern ActorData D_80800CB8_chburgerstand[];

    return (OSThread *) D_80800CB8_chburgerstand;
}

OSThread *chburgerstand_entrypoint_3(void)
{
    extern ActorData D_80800D00_chburgerstand[];

    return (OSThread *) D_80800D00_chburgerstand;
}

void func_80800030_chburgerstand(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    Actor *other;

    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 4);
    } else {
        arg0->unk64_16 = func_800DA298(FLAG_09F_UNK);
    }
    func_80103110(arg0, arg0->unk64_16);
    other = _subaddiefind_entrypoint_2(0x32F, 0);
    if (other != NULL) {
        func_800EE7F8((f32 *)arg0->actorData, other->position);
        ((f32 *)arg0->actorData)[1] = arg0->position[1];
    }
}

void *func_80100094(Actor *, u32);

void func_808000C4_chburgerstand(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    BT_IDO_ONLY(void func_800D175C(s32, s32);) BT_NATIVE_ONLY(s32 func_800D175C(s32, s32);)
    s32 func_800D1A04(s32);
    s32 func_800F4EC8(BtUIntPtr, BtIntPtr, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800FC660(u32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    void func_80102424(Actor *, s32);
    void func_808004DC_chburgerstand(Actor *);
    void func_808005AC_chburgerstand(Actor *);
    void func_80800754_chburgerstand(Actor *);
    extern u32 D_80800D48_chburgerstand;

    if (func_80100094(arg0, 1) != NULL) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
        if (func_801022E4(arg0) != 0xDC || !func_80102320(arg0, 0.32f, 0.95f)) {
            _suexpression_entrypoint_18(func_80100094(arg0, 1), 1);
        }
    }
    func_800F4EC8(func_800F54E4(), (BtIntPtr)arg0->actorData, 300.0f, -10.0f, 260.0f);
    switch (arg0->unk70_10) {
        case 1:
            func_808004DC_chburgerstand(arg0);
            func_808005AC_chburgerstand(arg0);
            func_80800754_chburgerstand(arg0);
            break;
        case 2:
            func_808004DC_chburgerstand(arg0);
            func_808005AC_chburgerstand(arg0);
            break;
        case 3:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800D48_chburgerstand, 0.7f);
            if (func_80101DDC(arg0)) {
                func_800D175C(0x4B, 5 - func_800D1A04(0x4B));
                func_800FC660(0xE);
                func_80102424(arg0, 1);
                func_800FFA88(arg0->unk3C);
                arg0->unk3C = NULL;
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x10FE, 6, arg0->position, 0x51);
            }
            break;
        case 4:
            func_808004DC_chburgerstand(arg0);
            func_808005AC_chburgerstand(arg0);
            break;
    }
}

void func_80800284_chburgerstand(Actor* arg0)
{
    func_80800720_chburgerstand(arg0);
}

s32 func_808002A4_chburgerstand(Actor *arg0, s32 arg1, s32 arg2) {
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
    s32 func_808006B4_chburgerstand(Actor *);
    void func_808007A0_chburgerstand(Actor *, s32, s16);
    void func_8080087C_chburgerstand(Actor *, s32, s16);
    s32 func_80800940_chburgerstand(Actor *);
    extern s32 D_80800D50_chburgerstand[4];
    Unk80132ED0 *temp_a0;
    s32 temp_t7;
    s32 result;
    Actor *temp_v0;

    switch (arg1) {
        default:                                    /* switch 2 */
            return 0;
        case 0x2E:                                  /* switch 2 */
            func_808007A0_chburgerstand(arg0, (*(s16 *)((s8 *)(&arg2) + (0))), (*(s16 *)((s8 *)(&arg2) + (2))));
            break;
        case 0x2F:                                  /* switch 2 */
            func_8080087C_chburgerstand(arg0, (*(s16 *)((s8 *)(&arg2) + (0))), (*(s16 *)((s8 *)(&arg2) + (2))));
            break;
        case 0x32:                                  /* switch 2 */
            func_80090734(2, arg0->position);
            break;
        case 0x3D:                                  /* switch 2 */
            func_80800940_chburgerstand(arg0);
            break;
        case 0x52:                                  /* switch 2 */
            _gcdialogcamera_entrypoint_3(D_80800D50_chburgerstand, arg0->scale);
            break;
        case 0xA:                                   /* switch 2 */
            arg0->unk64_16 = 1;
            func_80102424(arg0, 2);
            func_80101EE4(arg0, 0.0f);
            func_80103110(arg0, 1);
            temp_a0 = arg0->unk3C;
            if (temp_a0 != NULL) {
                temp_v0 = func_80106790(temp_a0);
                temp_v0->unk64_16 = arg0->unk64_16;
            }
            _capod_entrypoint_13(arg0->unk0, 0, 0x11, 0x30);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x10DF, 4, arg0->position, 0x50);
            break;
        case 0x29:                                  /* switch 2 */
            func_808006B4_chburgerstand(arg0);
            break;
        case 0x2A:                                  /* switch 2 */
            func_80800720_chburgerstand(arg0);
            break;
        case 0x95:
            if (func_800D1A04(0x4B) == 0) {
                func_80108B04(arg0, 0);
            }
            break;
        case 0xB8:
            temp_t7 = arg2 & 0xFFFF;
            switch (temp_t7) {
            default:
                return 0;
            case 1:
                return arg0->unk3C != NULL ? 0x10AB : 0x10AC;
            case 2:
                return arg0->unk3C != NULL ? 0x1106 : 0x1107;
            }
    }
    return 1;
}

void func_808004DC_chburgerstand(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    extern u32 D_80800D60_chburgerstand[3];
    extern u32 D_80800D6C_chburgerstand[4];
    extern u32 D_80800D7C_chburgerstand[3];
    extern u32 D_80800D88_chburgerstand[3];
    extern u32 D_80800D94_chburgerstand[3];
    extern u32 D_80800DA0_chburgerstand[3];
    extern u32 D_80800DAC_chburgerstand[3];
    extern u32 D_80800DB8_chburgerstand[5];
    extern u32 D_80800DCC_chburgerstand[4];
    f32 *temp_s1;

    temp_s1 = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800D7C_chburgerstand, 0.02f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800D88_chburgerstand, 0.04f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800D94_chburgerstand, 0.11f);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80800D60_chburgerstand, D_80800DAC_chburgerstand);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80800D6C_chburgerstand, D_80800DB8_chburgerstand);
    _subaddieaudioquick_entrypoint_4(arg0, temp_s1, D_80800DA0_chburgerstand, D_80800DCC_chburgerstand);
}

void func_808005AC_chburgerstand(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_3(BtIntPtr, s32, s32 *);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA994(void *emitter, s16 yaw_min, s16 pitch_min, s16 speed_min, s16 yaw_max, s16 pitch_max, s16 speed_max);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_80101E4C(Actor *, f32 *);
    extern f32 D_80800DDC_chburgerstand[];
    extern s32 D_80800DEC_chburgerstand[];
    f32 position[3];
    BtIntPtr emitter;

    if (func_80101E4C(arg0, D_80800DDC_chburgerstand) &&
        _subaddieskeleton_entrypoint_3(arg0->unk0, 4, position)) {
        position[1] -= 30.0f;
        emitter = func_800BABB8(0, position, NULL, arg0->scale, D_80800DEC_chburgerstand);
        func_800BA994(emitter, 0x2D, (s16)(s32)(arg0->rotation[1] - 50.0f),
            (s16)(s32)(arg0->scale * 10.0f), 0x3C, (s32)(arg0->rotation[1] + 50.0f), (s32)(arg0->scale * 20.0f));
        func_800BA22C(emitter, 3);
    }
}

s32 func_808006B4_chburgerstand(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BT_IDO_ONLY(BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);) BT_NATIVE_ONLY(void *_suexpression_entrypoint_7(Actor *, s32, s16);)
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x50);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    } BT_NATIVE_ONLY(return 0;)
}

void func_80800720_chburgerstand(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80800754_chburgerstand(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 func_80090734(s32, f32 *);
    extern s32 D_80800E14_chburgerstand[7];
    extern s32 D_80800BC0_chburgerstand[10];
    f32 *position[2];

    position[1] = arg0->position;
    if (_subaddiedialog_entrypoint_8((BtIntPtr)arg0, position[1], D_80800E14_chburgerstand, D_80800BC0_chburgerstand, 5) != 0) {
        func_80090734(1, position[1]);
    }
}

void func_808007A0_chburgerstand(Actor *arg0, s32 arg1, s16 arg2) {
    void func_80102424(Actor *, s32);
    void _capod_entrypoint_14(void);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);) BT_NATIVE_ONLY(u8 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);)
    void func_8008FC9C(s32);
    void func_80090708(s32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800BC0_chburgerstand[10];
    switch (arg1) {
        case 0x10DF:
            _capod_entrypoint_14();
            func_80102424(arg0, 1);
            break;
        case 0x10FE:
            func_8008FC9C(0);
            func_80102424(arg0, 1);
            break;
        default:
            if (arg0->unk3C != NULL && _subaddiedialog_entrypoint_9(arg0, arg1, D_80800BC0_chburgerstand, 5) == 2) {
                func_80102424(arg0, 3);
                func_80102424(func_80106790(arg0->unk3C), 2);
            } else {
                func_80102424(arg0, 1);
                func_80090708(0);
            }
            break;
    }
}

void func_8080087C_chburgerstand(Actor *arg0, s32 arg1, s16 arg2) {
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_9(Actor *, s32, s32 *, s32);) BT_NATIVE_ONLY(u8 _subaddiedialog_entrypoint_9(Actor *, s32, void *, s32);)
    void func_8010D254(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_80090708(s32);
    void func_8008F8B0(void);
    void func_8008F904(void *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    extern s32 D_80800BC0_chburgerstand[10];
    extern s32 func_8010D5DC;
    f32 sp34[3];
    f32 sp28[3];
    s32 pad[2];

    if (arg0->unk3C != NULL && _subaddiedialog_entrypoint_9(arg0, arg1, D_80800BC0_chburgerstand, 5) == 2) {
        func_8010D254(sp28);
        func_800EE7F8(sp34, arg0->position);
        func_800EF1B8(sp34, arg0->rotation[1], 340.0f);
        if (func_800EEAD4(sp28, sp34) > 50.0f) {
            func_80090708(0);
            func_8008F8B0();
            func_8008F904(&func_8010D5DC, arg0->unk0);
            func_8008F990(sp34, 170.0f);
        }
    }
}

s32 func_80800940_chburgerstand(Actor *arg0) {
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_80102FDC(void *, f32);
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    Actor *temp_v0;
    s32 sp20[3];

    temp_v0 = func_801084B0(0x32C, &arg0);
    func_80102FDC(temp_v0, arg0->scale);
    _subaddiefade_entrypoint_9(arg0, sp20);
    _subaddiefade_entrypoint_11(temp_v0, sp20);
    arg0->unk3C = temp_v0->unk0;
    temp_v0->unk64_16 = arg0->unk64_16; BT_NATIVE_ONLY(return (s32)(BtIntPtr)temp_v0;)
}

void func_808009C4_chburgerstand(s32 arg0) 
{
}    typedef struct { u8 pad0[0x8]; f32 unk8; } Objburgerstand_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
/* extern */

void func_808009CC_chburgerstand(void *arg0) {
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
    (((Objburgerstand_arg0 *)arg0)->unk8) = (f32) ((((Objburgerstand_arg0 *)arg0)->unk8) - 225.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        var_v0 = -1;
        func_80101FDC(arg0, 4);
    } else {
        var_v0 = 0x9F;
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 225.0f, 0x20, var_v0) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_8(arg0, 3);
    }
}

void func_80800A8C_chburgerstand(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_09F_UNK);
    _chswitch_entrypoint_9(arg0);
}

s32 func_80800AB8_chburgerstand(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 ret;

    if (arg1 == 7) {
        func_80101180(0x32F, 7, 0);
        func_80101180(0x32B, 0xA, 0);
        ret = 1;
    } else {
        return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return ret;
}
/* data_to_c.py: from asm/data/overlays/ch/burgerstand.data.s */
extern u8 D_80800BE8_chburgerstand[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_80800C10_chburgerstand[];
void func_80102EC0();
void _chdoor_entrypoint_0();
void _chdoor_entrypoint_1();

void _chswitch_entrypoint_6();
s32 D_80800BC0_chburgerstand[10] BT_DATA(4, overlays_ch_burgerstand, 0x0) = { 1, 279576832, 1, -65024, 512, 285540608, 512, -130560, -73729, 303039232 };
u8 D_80800BE8_chburgerstand[40] BT_DATA(4, overlays_ch_burgerstand, 0x28) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x94, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x01, 0x41, 0x94, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x01, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0xDD, 0x00, 0x02, 0x41, 0x94, 0x00, 0x00, 0x00, 0xDC, 0x00, 0x01 };
u8 D_80800C10_chburgerstand[24] BT_DATA(4, overlays_ch_burgerstand, 0x50) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x44, 0x3F, 0xE0, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x02 };
ActorData D_80800C28_chburgerstand [1] BT_DATA(4, overlays_ch_burgerstand, 0x68) = { { 439, 811, 1710, 1, (void *)D_80800BE8_chburgerstand, (void (*)(struct Actor *))func_808000C4_chburgerstand, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 131072000, 0, 0, 0, 16384, 352, (void (*)(struct Actor *))func_80800284_chburgerstand, 0, 0, 0, (void (*)(struct Actor *))func_80800030_chburgerstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 25618, (void (*)(struct Actor *, long, long))func_808002A4_chburgerstand, 0 } };
ActorData D_80800C70_chburgerstand [1] BT_DATA(4, overlays_ch_burgerstand, 0xB0) = { { 440, 812, 1711, 1, (void *)D_80800C10_chburgerstand, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_808009C4_chburgerstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32752, 10258, 0, 0 } };
ActorData D_80800CB8_chburgerstand [1] BT_DATA(4, overlays_ch_burgerstand, 0xF8) = { { 172, 815, 1908, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_808009CC_chburgerstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_80800D00_chburgerstand [1] BT_DATA(4, overlays_ch_burgerstand, 0x140) = { { 835, 816, 1888, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800A8C_chburgerstand, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11282, (void (*)(struct Actor *, long, long))func_80800AB8_chburgerstand, 0 } };
u32 D_80800D48_chburgerstand BT_DATA(4, overlays_ch_burgerstand, 0x188) = 0x1303FF;
u8 D_80800D48_chburgerstand__gap[4] BT_DATA(4, overlays_ch_burgerstand, 0x18C) = { 0 };
s32 D_80800D50_chburgerstand[4] BT_DATA(4, overlays_ch_burgerstand, 0x190) = { 1131085824, 1126825984, 1120403456, 1121714176 };
u32 D_80800D60_chburgerstand[3] BT_DATA(4, overlays_ch_burgerstand, 0x1A0) = { 0x130430, 0xD0099, 0xB30000 };
u32 D_80800D6C_chburgerstand[4] BT_DATA(4, overlays_ch_burgerstand, 0x1AC) = { 0x130449, 0xD00B3, 0xCC0016, 0x2EE00000 };
u32 D_80800D7C_chburgerstand[3] BT_DATA(4, overlays_ch_burgerstand, 0x1BC) = { 0x130500, 0xD00F3, 0x10C0000 };
u32 D_80800D88_chburgerstand[3] BT_DATA(4, overlays_ch_burgerstand, 0x1C8) = { 0x130502, 0xD00C0, 0xD90000 };
u32 D_80800D94_chburgerstand[3] BT_DATA(4, overlays_ch_burgerstand, 0x1D4) = { 0x130503, 0xD00D9, 0xF30000 };
u32 D_80800DA0_chburgerstand[3] BT_DATA(4, overlays_ch_burgerstand, 0x1E0) = { 0x130501, 0xD00F3, 0x10C0000 };
u32 D_80800DAC_chburgerstand[3] BT_DATA(4, overlays_ch_burgerstand, 0x1EC) = { 0x3F1EB852, 0x3F266666, 0xBF800000 };
u32 D_80800DB8_chburgerstand[5] BT_DATA(4, overlays_ch_burgerstand, 0x1F8) = { 0x3F051EB8, 0x3F0CCCCD, 0x3F3851EC, 0x3F400000, 0xBF800000 };
u32 D_80800DCC_chburgerstand[4] BT_DATA(4, overlays_ch_burgerstand, 0x20C) = { 0x3E4CCCCD, 0x3E77CED9, 0x3E99999A, 0xBF800000 };
f32 D_80800DDC_chburgerstand [4] BT_DATA(4, overlays_ch_burgerstand, 0x21C) = { 0.12f, 0.62f, 0.65f, -1.0f };
s32 D_80800DEC_chburgerstand [10] BT_DATA(4, overlays_ch_burgerstand, 0x22C) = { 51380253, 165478422, 34078751, 1354780672, 2228275, 4980940, 16777237, 153, 2818304, 20119552 };
s32 D_80800E14_chburgerstand[7] BT_DATA(4, overlays_ch_burgerstand, 0x254) = { 10289152, 26214480, 6, 120717824, 0, 0, 0 };
