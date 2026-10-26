#include "ch/factory/roofbits.h"

/* extern */

void func_80800000_chfactoryroofbits(s32 arg0) {
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
    s32 _chexploder_entrypoint_6(s32, s32, s32);
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    Unk80132ED0 *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80800920_chfactoryroofbits;
    extern s32 D_80800968_chfactoryroofbits;
    Actor *actor = func_80106790(func_80101080());
    _chexploder_entrypoint_6(actor, 0x44160000, 0x44480000);
    func_800DA544(FLAG_196_UNK);
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800920_chfactoryroofbits);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800968_chfactoryroofbits);
}

OSThread *chfactoryroofbits_entrypoint_0(void)
{
    extern u8 D_80800974_chfactoryroofbits[];

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
}

/* extern */

void func_808003C4_chfactoryroofbits(u8 *arg0) {
    s32 func_800FFA88(s32);
    s32 func_808001C0_chfactoryroofbits(s32, f32 *, f32 *, f32 *);
    if (func_808001C0_chfactoryroofbits((u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15, (f32 *)(arg0 + 4), (f32 *)(arg0 + 0x28), (f32 *)(arg0 + 0x44)) != 0) {
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
    }
}

s32 func_80800414_chfactoryroofbits(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    s32 _subaddieaudioquick_entrypoint_2();
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800FFAB0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_808009BC_chfactoryroofbits;
    extern s32 D_808009FC_chfactoryroofbits;
    s32 emitter;
    f32 *position;
    Unk80132ED0 *marker;

    if (arg1 == 0x40) {
        marker = *(Unk80132ED0 **)&arg2;
        if (((u16 *)&marker->unk18)[0] & 1) { if (func_80106790(marker)->unk6C_9 == 0x15D) {
                emitter = func_800B53A4(0x20);
                position = arg0->position;
                func_800BABB8(emitter, position, 0, ((f32 *)arg0->actorData)[6] * 0.5f, &D_808009BC_chfactoryroofbits);
                func_800BA930(emitter, -200, 400, -200, 200, 800, 200);
                func_800BA22C(emitter, 0x20);
            } else {
                emitter = func_800B53A4(0x10);
                position = arg0->position;
                func_800BABB8(emitter, position, 0, ((f32 *)arg0->actorData)[6], &D_808009BC_chfactoryroofbits);
                func_800BA22C(emitter, 0x10);
            }
        } else {
            emitter = func_800B53A4(8);
            position = arg0->position;
            func_800BABB8(emitter, position, 0, ((f32 *)arg0->actorData)[6] * 1.25f, &D_808009BC_chfactoryroofbits);
            func_800BA22C(emitter, 8);
        }
        _subaddieaudioquick_entrypoint_2(arg0, position, &D_808009FC_chfactoryroofbits);
        func_800DA544(func_8080015C_chfactoryroofbits(arg0->pad6C_21));
        func_800FFAB0(arg0);
        return 1;
    }
    return 0;
}

/* extern */

void func_808005DC_chfactoryroofbits(void *arg0, s32 arg1) {
    s32 func_800DF500(f32, f32, s32);
    s32 func_80101870(void *, s32);
    func_800DF500((*(f32 *)((s8 *)(arg0) + (0x28))), (*(f32 *)((s8 *)(arg0) + (0x2C))), (*(s32 *)((s8 *)(arg0) + (0x30))));
    func_80101870(arg0, arg1);
}

OSThread *chfactoryroofbits_entrypoint_1(void)
{
    extern u8 D_80800A08_chfactoryroofbits[];

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
    extern u8 D_80800A50_chfactoryroofbits[];

    return (OSThread *) D_80800A50_chfactoryroofbits;
}

void func_808006E8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A08_UNK);
}

void func_80800708_chfactoryroofbits(Actor *arg0, s32 arg1, s32 arg2) {
    struct RoofPosition { f32 position[3]; };
    extern struct RoofPosition D_80800A98_chfactoryroofbits;
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void func_80108B04(Actor *, u32);
    s32 _chswitch_entrypoint_10(s32, s32, s32);
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
    extern u8 D_80800AA4_chfactoryroofbits[];

    return (OSThread *) D_80800AA4_chfactoryroofbits;
}

void func_808007B8_chfactoryroofbits(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_163_STATION_UNLOCKED_GI);
    _chswitch_entrypoint_9(arg0);
}

void func_808007E4_chfactoryroofbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    if (arg1 == 7) {
        _glcutDll_entrypoint_6(0x102U, 0x44U);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chfactoryroofbits_entrypoint_4(void)
{
    extern u8 D_80800AEC_chfactoryroofbits[];

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
    s32 _chdoor_entrypoint_1(Actor *, s32, s32);
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
    extern u8 D_80800B34_chfactoryroofbits[];

    return (OSThread *) D_80800B34_chfactoryroofbits;
}
