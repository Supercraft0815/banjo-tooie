#include "ch/factory/roofbits.h"

/* extern */

void func_80800000_chfactoryroofbits(BtIntPtr arg0) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    func_800EFA4C((f32 *)(arg0 + 4), -1124.0f, 9002.0f, 1596.0f);
}

/* extern */

int func_8080003C_chfactoryroofbits(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_808000D4_chfactoryroofbits(Actor *);
    f32 position[3];
    int result;

    if (arg1 == 0x40) {
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, arg0->rotation[1], -150.0f);
        position[1] -= 50.0f;
        _chexploder_entrypoint_3(arg0, position, 0xC);
        return 1;
    }
    result = 0;
    if (arg1 == 0x90) {
        func_808000D4_chfactoryroofbits(arg0);
        return 1;
    }
    return result;
}

void func_808000D4_chfactoryroofbits(Actor *arg0) {
    s32 _chexploder_entrypoint_6(BtIntPtr, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(BtIntPtr, s32, s32 *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    Unk80132ED0 *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800920_chfactoryroofbits[18];
    extern s32 D_80800968_chfactoryroofbits[3];
    Actor *actor = func_80106790(func_80101080());
    _chexploder_entrypoint_6(actor, 0x44160000, 0x44480000);
    func_800DA544(FLAG_196_UNK);
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800920_chfactoryroofbits);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800968_chfactoryroofbits);
}

OSThread *chfactoryroofbits_entrypoint_0(void)
{
    extern ActorData D_80800974_chfactoryroofbits[];

    return (OSThread *) D_80800974_chfactoryroofbits;
}

s32 func_8080015C_chfactoryroofbits(s32 arg0) { switch (arg0) { case 0x4B: return 0x197; case 0x4C: return 0x198; case 0x4D: return 0x199; case 0x4E: return 0x19A; case 0xE: return 0x19B; default: return 0; } }

/* extern */

s32 func_808001C0_chfactoryroofbits(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    switch (arg0) {
    case 0x4B:
        func_800EFA4C(arg1, -1397.0f, 8063.0f, -632.0f);
        func_800EFA4C(arg2, 0.94f, 0.73f, 1.0f);
        *arg3 = 312.0f;
        break;
    case 0x4C:
        func_800EFA4C(arg1, 174.0f, 8066.0f, -1017.0f);
        func_800EFA4C(arg2, 0.94f, 0.73f, 1.0f);
        *arg3 = 312.0f;
        break;
    case 0x4D:
        func_800EFA4C(arg1, -1138.0f, 2148.0f, 2300.0f);
        func_800EFA4C(arg2, 1.8f, 1.8f, 1.8f);
        *arg3 = 0.0f;
        break;
    case 0x4E:
        func_800EFA4C(arg1, 2303.0f, 2143.0f, -376.0f);
        func_800EFA4C(arg2, 1.8f, 1.8f, 1.8f);
        *arg3 = 0.0f;
        break;
    case 0xE:
        func_800EFA4C(arg1, 2645.0f, 1494.0f, 2645.0f);
        func_800EFA4C(arg2, 1.14f, 1.0f, 1.0f);
        *arg3 = 0.0f;
        break;
    default:
        return 1;
    }
    return func_800DA298(func_8080015C_chfactoryroofbits(arg0));
}                typedef struct { s32 unk0; u8 pad4[0x24]; f32 unk28; f32 unk2C; s32 unk30; u8 pad34[0x38]; u32 unk6C; } Objroofbits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_808003C4_chfactoryroofbits(u8 *arg0) {
    s32 func_800FFA88(BtIntPtr);
    s32 func_808001C0_chfactoryroofbits(s32, f32 *, f32 *, f32 *);
    if (func_808001C0_chfactoryroofbits((u32) (((Objroofbits_arg0 *)arg0)->unk6C) >> 0x15, (f32 *)(arg0 + 4), (f32 *)(arg0 + 0x28), (f32 *)(arg0 + 0x44)) != 0) {
        func_800FFA88((((Objroofbits_arg0 *)arg0)->unk0));
    }
}

s32 func_80800414_chfactoryroofbits(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    s32 _subaddieaudioquick_entrypoint_2();
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800FFAB0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_808009BC_chfactoryroofbits[16];
    extern s32 D_808009FC_chfactoryroofbits[3];
    BtIntPtr emitter;
    f32 *position;
    Unk80132ED0 *marker;

    if (arg1 == 0x40) {
        marker = *(Unk80132ED0 **)&arg2;
        if (((u16 *)&marker->unk18)[0] & 1) { if (func_80106790(marker)->unk6C_9 == 0x15D) {
                emitter = func_800B53A4(0x20);
                position = arg0->position;
                func_800BABB8(emitter, position, 0, ((f32 *)arg0->actorData)[6] * 0.5f, D_808009BC_chfactoryroofbits);
                func_800BA930(emitter, -200, 400, -200, 200, 800, 200);
                func_800BA22C(emitter, 0x20);
            } else {
                emitter = func_800B53A4(0x10);
                position = arg0->position;
                func_800BABB8(emitter, position, 0, ((f32 *)arg0->actorData)[6], D_808009BC_chfactoryroofbits);
                func_800BA22C(emitter, 0x10);
            }
        } else {
            emitter = func_800B53A4(8);
            position = arg0->position;
            func_800BABB8(emitter, position, 0, ((f32 *)arg0->actorData)[6] * 1.25f, D_808009BC_chfactoryroofbits);
            func_800BA22C(emitter, 8);
        }
        _subaddieaudioquick_entrypoint_2(arg0, position, D_808009FC_chfactoryroofbits);
        func_800DA544(func_8080015C_chfactoryroofbits(arg0->pad6C_21));
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

/* extern */

void func_808005DC_chfactoryroofbits(void *arg0, s32 arg1) {
    s32 func_800DF500(f32, f32, s32);
    s32 func_80101870(void *, BtIntPtr);
    func_800DF500((((Objroofbits_arg0 *)arg0)->unk28), (((Objroofbits_arg0 *)arg0)->unk2C), (((Objroofbits_arg0 *)arg0)->unk30));
    func_80101870(arg0, arg1);
}

OSThread *chfactoryroofbits_entrypoint_1(void)
{
    extern ActorData D_80800A08_chfactoryroofbits[];

    return (OSThread *) D_80800A08_chfactoryroofbits;
}

void func_80800624_chfactoryroofbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _chdoormake_entrypoint_10(void *, s32, s32);
    f32 func_80103EF4(Actor *);

    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], 90.0f, func_80103EF4(arg0), 0x20AE, 0xA08);
    _chdoormake_entrypoint_5(arg0, 3.0f);
    _chdoormake_entrypoint_6(arg0, 0x40E00000);
    _chdoormake_entrypoint_8(arg0, 4);
    _chdoormake_entrypoint_9(arg0, 0, 1, 0x10);
    _chdoormake_entrypoint_10(arg0, 0, 0x19C);
    _chdoormake_entrypoint_9(arg0, 1, 0xB, 0x10);
    _chdoormake_entrypoint_10(arg0, 1, 0x19D);
}

OSThread *chfactoryroofbits_entrypoint_2(void)
{
    extern ActorData D_80800A50_chfactoryroofbits[];

    return (OSThread *) D_80800A50_chfactoryroofbits;
}

void func_808006E8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A08_UNK);
}
struct RoofPosition { f32 position[3]; };
void func_80800708_chfactoryroofbits(Actor *arg0, s32 arg1, s32 arg2) {

    extern struct RoofPosition D_80800A98_chfactoryroofbits;
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void func_80108B04(Actor *, u32);
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    struct RoofPosition sp1C;

    switch (arg1) {
        case 0x3D:
            sp1C = D_80800A98_chfactoryroofbits;
            func_80108528(0x3F3, sp1C.position, 0x10E, &arg0);
            break;
        case 0x95:
            if (_subaddiefind_entrypoint_2(0x3F3, 0) == NULL) {
                func_80108B04(arg0, 0);
            }
            break;
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chfactoryroofbits_entrypoint_3(void)
{
    extern ActorData D_80800AA4_chfactoryroofbits[];

    return (OSThread *) D_80800AA4_chfactoryroofbits;
}

void func_808007B8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_163_STATION_UNLOCKED_GI);
    _chswitch_entrypoint_9(arg0);
}

void func_808007E4_chfactoryroofbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x102U, 0x44U);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chfactoryroofbits_entrypoint_4(void)
{
    extern ActorData D_80800AEC_chfactoryroofbits[];

    return (OSThread *) D_80800AEC_chfactoryroofbits;
}

void func_80800840_chfactoryroofbits(Actor *arg0) {
    void _chdoormake_entrypoint_0(void*, f32, u32, s32);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_6(Actor*, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    _chdoormake_entrypoint_0(arg0, 90.0f, 0x80U, 0x355);
    _chdoormake_entrypoint_5(arg0, 3.0f);
    _chdoormake_entrypoint_6(arg0, 0x3F800000);
    _chdoormake_entrypoint_8(arg0, 4U);
}

s32 func_80800890_chfactoryroofbits(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);
    if (arg1 == 0x49) {
        if (arg2 == 0x86) {
            _capod_entrypoint_13(arg0->unk0, 0, 0x12, 0x910);
            return _chdoor_entrypoint_1(arg0, 7, 0);
        }
        return 0;
    }
    return _chdoor_entrypoint_1(arg0, arg1, arg2);
}

OSThread *chfactoryroofbits_entrypoint_5(void)
{
    extern ActorData D_80800B34_chfactoryroofbits[];

    return (OSThread *) D_80800B34_chfactoryroofbits;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/roofbits.data.s */
void func_80102EC0();
void func_80105834(Actor*);
s32 func_80101870 ( void * , BtIntPtr );
void func_80108ED0();
void func_80107C2C();
void _chdoor_entrypoint_0();
s32 _chdoor_entrypoint_1 ( Actor * , s32 , BtIntPtr );
extern u8 D_8011A1BC[];
void _chswitch_entrypoint_6();
extern u8 D_8011A248[];
s32 D_80800920_chfactoryroofbits[18] BT_DATA(4, overlays_ch_factory_roofbits, 0x0) = { 84934685, 165478443, 100665344, 2228736, 41944576, 134217749, 38, 1638400, 458796, -1310700, -1310700, 2621460, 2121824, 1619001354, -1245234, -1310700, 3276820, 85590016 };
s32 D_80800968_chfactoryroofbits[3] BT_DATA(4, overlays_ch_factory_roofbits, 0x48) = { 1246368, 1469792, 0 };
ActorData D_80800974_chfactoryroofbits [1] BT_DATA(4, overlays_ch_factory_roofbits, 0x54) = { { 291, 651, 1808, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 406, 0, 0, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chfactoryroofbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_8080003C_chfactoryroofbits, 0 } };
s32 D_808009BC_chfactoryroofbits[16] BT_DATA(4, overlays_ch_factory_roofbits, 0x9C) = { 1902351, 1445888, 2819072, 100663323, -26149264, 2228326, 8388710, 8388647, -26149264, 26214800, 720821, 1048501, 4915250, 4915221, 204, 0 };
s32 D_808009FC_chfactoryroofbits[3] BT_DATA(4, overlays_ch_factory_roofbits, 0xDC) = { 1246349, 1469792, 0 };
ActorData D_80800A08_chfactoryroofbits [1] BT_DATA(4, overlays_ch_factory_roofbits, 0xE8) = { { 309, 1010, 1806, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808005DC_chfactoryroofbits, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808003C4_chfactoryroofbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800414_chfactoryroofbits, 0 } };
ActorData D_80800A50_chfactoryroofbits [1] BT_DATA(4, overlays_ch_factory_roofbits, 0x130) = { { 172, 1011, 1805, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3076, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800624_chfactoryroofbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
struct RoofPosition D_80800A98_chfactoryroofbits BT_DATA(4, overlays_ch_factory_roofbits, 0x178) = { { -2260.0f, 5500.0f, -1139.0f } };
ActorData D_80800AA4_chfactoryroofbits [1] BT_DATA(4, overlays_ch_factory_roofbits, 0x184) = { { 835, 1012, 2185, 1, (void *)((u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808006E8_chfactoryroofbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800708_chfactoryroofbits, 0 } };
ActorData D_80800AEC_chfactoryroofbits [1] BT_DATA(4, overlays_ch_factory_roofbits, 0x1CC) = { { 835, 1140, 2157, 1, (void *)D_8011A248, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_808007B8_chfactoryroofbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11282, (void (*)(struct Actor *, long, long))func_808007E4_chfactoryroofbits, 0 } };
ActorData D_80800B34_chfactoryroofbits [1] BT_DATA(4, overlays_ch_factory_roofbits, 0x214) = { { 172, 1241, 2253, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800840_chfactoryroofbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11282, (void (*)(struct Actor *, long, long))func_80800890_chfactoryroofbits, 0 } };
