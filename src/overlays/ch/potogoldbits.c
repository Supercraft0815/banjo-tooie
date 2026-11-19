#include "common.h"
#include "core2/switch_animations.h"
/* extern */

void func_80800000_chpotogoldbits(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    _chswitch_entrypoint_7(arg0, 0xA2D);
    _chswitch_entrypoint_8(arg0, 0x601);
}

s32 func_80800030_chpotogoldbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x408, 7, 0);
        return 1;
    }
    return _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chpotogoldbits_entrypoint_0(void)
{
    extern ActorData D_80800920_chpotogoldbits[];

    return (OSThread *) D_80800920_chpotogoldbits;
}

void func_8080007C_chpotogoldbits(Actor *arg0) {
    void func_800CE88C(s32, s32);
    s32 func_800EA05C(void);
    s32 func_800EA090(void);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800FFA88();
    void func_80101FDC(Actor *, u32);
    f32 position[3];

    func_800EE7F8(((f32 *)arg0->actorData + 4), arg0->position);
    func_800EE7F8(((f32 *)arg0->actorData), arg0->position);
    if (func_800EA05C() == 0x136) {
        ((f32 *)arg0->actorData)[1] -= 500.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        arg0->unk54 = 3.0f;
        return;
    }
    func_800F5A00(func_800F54E4(), position);
        if (func_800EA090() == 1 && arg0->position[1] <= position[1]) {
            ((f32 *)arg0->actorData)[1] -= 2000.0f;
            ((f32 *)arg0->actorData)[3] = 0.0f;
            arg0->unk54 = 3.0f;
            func_80101FDC(arg0, 9);
            func_800CE88C(0, 0);
            return;
        }
    func_800FFA88(arg0->unk0);
}    typedef struct { s32 unk0; u8 pad4[0x20]; f32 unk24; u8 pad28[0x28]; f32 unk50; s32 unk54; f32 unk58; u8 pad5C[0x3F]; s8 unk9B; } Objpotogoldbits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800188_chpotogoldbits(u8 *arg0) {
    void _subaddieaudioloop_entrypoint_2(void *arg0);
    s32 _subaddieaudioloop_entrypoint_4(u8 *, u8 *, s32, s32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    f32 func_80013970(f32);
    s32 func_800D90A4(u8 *);
    s32 func_800D91EC(u8 *, s32);
    s32 func_800EFE50(u8 *, u8 *, u8 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 func_800FFA88(BtIntPtr);
    void func_80101FDC(Actor *, u32);
    s32 func_80103110(u8 *, s32);
    extern s32 D_80800968_chpotogoldbits[4];
    extern s32 D_80800978_chpotogoldbits[4];
    struct GoldFlags { BT_BITFIELD_ORDER(u32 other : 1, u32 : 30); BT_BITFIELD_ORDER(u32 played : 1, u32 played : 1; u32 other : 1); };
    f32 temp_f0;
    u8 *sp2C;

    switch ((u32) *(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        func_80103110(arg0, 0);
        break;
    case 2:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800978_chpotogoldbits);
        }
        sp2C = arg0 + 4;
        if (func_800D90A4(arg0 + 0x34) != 0) {
            func_80101FDC(arg0, 3);
        }
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, D_80800968_chpotogoldbits);
        break;
    case 3:
        sp2C = arg0 + 4;
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, D_80800968_chpotogoldbits);
        if (func_800D91EC(arg0 + 0x24, (((Objpotogoldbits_arg0 *)arg0)->unk54)) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, D_80800978_chpotogoldbits);
            func_80101FDC(arg0, 4);
        }
        break;
    case 4:
        func_80103110(arg0, 0);
        break;
    case 5:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800978_chpotogoldbits);
        }
        sp2C = arg0 + 4;
        if (func_800D90A4(arg0 + 0x34) != 0) {
            func_80101FDC(arg0, 6);
        }
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, D_80800968_chpotogoldbits);
        break;
    case 6:
        sp2C = arg0 + 4;
        _subaddieaudioloop_entrypoint_4(arg0, sp2C, 1, D_80800968_chpotogoldbits);
        if (func_800D90A4(arg0 + 0x24) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, D_80800978_chpotogoldbits);
            func_80101FDC(arg0, 1);
        }
        break;
    case 8:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(arg0 + 0x34) != 0) {
            func_80101FDC(arg0, 9);
        }
        break;
    case 9:
        if (func_800D91EC(arg0 + 0x24, (((Objpotogoldbits_arg0 *)arg0)->unk54)) != 0) {
            _subaddieaudioloop_entrypoint_2(arg0);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800978_chpotogoldbits);
            ((struct GoldFlags *)(arg0 + 0x74))->played = 0;
            func_80101FDC(arg0, 0xA);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, D_80800968_chpotogoldbits);
        break;
    case 10:
        if (!((struct GoldFlags *)(arg0 + 0x74))->played) {
            ((struct GoldFlags *)(arg0 + 0x74))->played = 1;
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_80800978_chpotogoldbits);
        }
        if (func_800D90A4(arg0 + 0x34) != 0) {
            (((Objpotogoldbits_arg0 *)arg0)->unk50) = 0.5f;
            func_80101FDC(arg0, 0xB);
        }
        break;
    case 11:
        if (func_800D90A4(arg0 + 0x50) != 0) {
            func_800FFA88((((Objpotogoldbits_arg0 *)arg0)->unk0));
        }
        (((Objpotogoldbits_arg0 *)arg0)->unk9B) = (s8) (u32) func_800F10B4((((Objpotogoldbits_arg0 *)arg0)->unk50), 0.5f, 0.0f, 255.0f, 0.0f);
        break;
    }
    sp2C = arg0 + 4;
    temp_f0 = func_800F12D4((((Objpotogoldbits_arg0 *)arg0)->unk24), 0.0f, (*(f32 *)((s8 *)(arg0) + (0x54))), 0.0f, 1.0f);
    (((Objpotogoldbits_arg0 *)arg0)->unk58) = temp_f0;
    func_800EFE50(sp2C, arg0 + 0x28, arg0 + 0x18, temp_f0);
    if (*(f32 *)(arg0 + 0x34)) {
        temp_f0 = func_800F10B4(*(f32 *)(arg0 + 0x34), 0.3f, 0.0f, 0.0f, 1.0f);
        temp_f0 = func_80013970(temp_f0 * 180.0f);
        (*(f32 *)(arg0 + 8)) += temp_f0 * 20.0f;
    }
}

s32 func_80800618_chpotogoldbits(Actor *arg0, u32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    s32 func_80103110(u8 *, s32);
    void func_80101FDC(Actor *, u32);
    void _chpotogoldbits_entrypoint_1(s32, s32);

    switch (arg1) {
    case 7:
        if (arg0->unk70_10 != 4) {
            arg0->unk74_30 = 0;
            _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x810);
            func_80103110(arg0, 1);
            ((f32 *)arg0->actorData)[7] = 0.3f;
            func_80101FDC(arg0, 2);
        }
        return 1;
    case 8:
        if (arg0->unk70_10 == 4) {
            arg0->unk74_30 = 0;
            _capod_entrypoint_13(arg0->unk0, NULL, 5, 0x810);
            func_80103110(arg0, 1);
            ((f32 *)arg0->actorData)[7] = 0.3f;
            func_80101FDC(arg0, 5);
        }
        return 1;
    case 0x91:
        if (7 == arg0->unk70_10) {
            func_80103110(arg0, 1);
            arg0->unk74_30 = 0;
            ((f32 *)arg0->actorData)[7] = 0.3f;
            func_80101FDC(arg0, 8);
        }
        return 1;
    case 11:
        if (arg2 == 3) {
            func_800CE8D8(0, arg0->unk74_7, arg0->unk74_7);
            func_800CE928(0, (BtIntPtr)_chpotogoldbits_entrypoint_1, 0);
            func_800CE88C(0, 1);
        }
        return 3;
    default:
        return 0;
    }
}

/* extern */

void chpotogoldbits_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_80101180(s32, s32, BtIntPtr);
    func_80101180(0x408, 8, 0);
}

OSThread *chpotogoldbits_entrypoint_2(void)
{
    extern ActorData D_80800988_chpotogoldbits[];

    return (OSThread *) D_80800988_chpotogoldbits;
}

/* extern */

void func_80800810_chpotogoldbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_7(Actor *arg0, f32 arg1);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 func_800EA090(void);
    s32 func_8010108C(void *, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    if (func_800EA090() == 0xD) {
        func_80101FDC(arg0, 4);
    }
    _chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 212.0f, 2, -1);
    _chdoormake_entrypoint_5(arg0, 1.0f);
    _chdoormake_entrypoint_7(arg0, 0.5f);
    _chdoormake_entrypoint_8(arg0, 2);
    if (arg0->unk70_10 == 4) {
        func_8010108C(arg0, 8, 0);
    }
}

OSThread *chpotogoldbits_entrypoint_3(void)
{
    extern ActorData D_808009D0_chpotogoldbits[];

    return (OSThread *) D_808009D0_chpotogoldbits;
}
/* data_to_c.py: from asm/data/overlays/ch/potogoldbits.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
void _chdoor_entrypoint_0();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
ActorData D_80800920_chpotogoldbits [1] BT_DATA(4, overlays_ch_potogoldbits, 0x0) = { { 835, 1031, 2093, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chpotogoldbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_80800030_chpotogoldbits, 0 } };
s32 D_80800968_chpotogoldbits[4] BT_DATA(4, overlays_ch_potogoldbits, 0x48) = { 1246649, 1466792, 655616, 131072 };
s32 D_80800978_chpotogoldbits[4] BT_DATA(4, overlays_ch_potogoldbits, 0x58) = { 1246695, 1474559, 655616, 131072 };
ActorData D_80800988_chpotogoldbits [1] BT_DATA(4, overlays_ch_potogoldbits, 0x68) = { { 172, 1032, 2095, 1, 0, (void (*)(struct Actor *))func_80800188_chpotogoldbits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1065353216, 0, 0, 2, 18432, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080007C_chpotogoldbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800618_chpotogoldbits, 0 } };
ActorData D_808009D0_chpotogoldbits [1] BT_DATA(4, overlays_ch_potogoldbits, 0xB0) = { { 172, 1033, 2094, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 131072000, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800810_chpotogoldbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
