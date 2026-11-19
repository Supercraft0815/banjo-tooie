#include "common.h"

OSThread *chnutsnbolts_entrypoint_0(void)
{
    extern ActorData D_80800E28_chnutsnbolts[];

    return (OSThread *) D_80800E28_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_1(void)
{
    extern ActorData D_80800E70_chnutsnbolts[];

    return (OSThread *) D_80800E70_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_2(void)
{
    extern ActorData D_80800EB8_chnutsnbolts[];

    return (OSThread *) D_80800EB8_chnutsnbolts;
}    typedef struct { u8 pad0[0x1C]; f32 unk1C; } Objnutsnbolts_func_80800024_chnutsnbolts_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

/* extern */

void func_80800024_chnutsnbolts(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    void* func_80100094(Actor*, u32);
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    _subaddierouteDll_entrypoint_3(arg0, temp_v0 + 8, arg0->position);
    func_8080092C_chnutsnbolts(arg0, 2);
    (((Objnutsnbolts_func_80800024_chnutsnbolts_sp24 *)sp24)->unk1C) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
}

void func_80800080_chnutsnbolts(Actor *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefx_entrypoint_0(Actor *, s32, void *);
    void _subaddiefx_entrypoint_1(BtIntPtr arg0, void *arg1);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    s32 func_800BFA1C(f32 *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    f32 func_800EEFFC(void *);
    void func_800EFDE8(f32 *, u8 *, f32 *);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6478(BtIntPtr);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    f32 func_80101F24(Actor *);
    void func_80102BF8(Actor *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_801072A8(Actor *);
    s32 func_801072E4(Actor *);
    void func_8010AA54(f32[3]);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010C3A8(Actor *, u32, f32);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    void func_8010D254(f32 *);
    void func_8010D690(Actor *);
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    s32 func_80800A88_chnutsnbolts(Actor *, s32, s32);
    void func_80800B80_chnutsnbolts(Actor *);
    void func_80800BD4_chnutsnbolts(Actor *);
    void func_80800C04_chnutsnbolts(Actor *);
    extern u8 D_80800F00_chnutsnbolts[];
    extern u8 D_80800F14_chnutsnbolts[];
    struct NutsFlags {
        BT_BITFIELD_ORDER(u32 pad : 29, u32 tail : 2);
        u32 disabled : 1;
        BT_BITFIELD_ORDER(u32 tail : 2, u32 pad : 29);
    };
    struct NutsData {
        u8 effects[8];
        u8 route[6];
        u16 routeEnd;
        u8 pad10[4];
        s16 routeTarget;
        u8 active;
        u8 pad17;
        f32 timer;
        f32 speed;
    } *sp54;
    s32 sp50;
    s32 sp4C;
    f32 sp40[3];
    f32 sp3C;

    sp54 = func_80100094(arg0, 0U);
    if (!((struct NutsFlags *)&arg0->unk78)->disabled) {
        func_8010D254((f32 *)arg0->actorData);
        if (!func_801072A8(arg0) || func_801072E4(arg0)) {
            func_8010D690(arg0);
        }
        sp50 = func_800D90A4(&arg0->unk58);
        switch (arg0->unk70_10) {
        case 1:
            ((f32 *)arg0->actorData)[5] -= func_800D8FF8() * 1000.0f;
            sp4C = func_8010B990(arg0, 0x400027);
            if (!func_800BFA1C(arg0->position)) {
                func_800FFAB0(arg0);
                return;
            }
            if (sp4C & 0x20) {
                func_8010AA54(sp40);
                func_800EFDE8((f32 *)&arg0->actorData[4], (u8 *)&arg0->actorData[4], sp40);
                ((f32 *)arg0->actorData)[4] *= 0.8f;
                ((f32 *)arg0->actorData)[5] *= 0.4f;
                ((f32 *)arg0->actorData)[6] *= 0.8f;
                if (func_800EEFFC(&arg0->actorData[4]) < 50.0f) {
                    func_8010B990(arg0, 0x1000);
                    func_8080092C_chnutsnbolts(arg0, 3);
                } else if (sp50) {
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F00_chnutsnbolts);
                    arg0->unk58 = 0.6f;
                }
            }
            break;
        case 2:
            func_80800A88_chnutsnbolts(arg0, 0, 3);
            break;
        case 3:
            func_80800B80_chnutsnbolts(arg0);
            if (func_80101DDC(arg0)) {
                func_8080092C_chnutsnbolts(arg0, 4);
            }
            break;
        case 4:
            if (arg0->unk64_29) {
                sp3C = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
                ((f32 *)arg0->actorData)[3] = sp54->speed;
                func_80102BF8(arg0, 0.2f, 8.0f, 500.0f);
                func_8010C3A8(arg0, 0x205025, func_800F3780(func_80101F24(arg0), D_80800F14_chnutsnbolts, 3) * sp3C);
            } else {
                if (!sp54->active) {
                    if (_subaddierouteDll_entrypoint_4(arg0)) {
                        arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                        _subaddierouteDll_entrypoint_7(arg0, sp54->route, arg0->rotation[1], arg0->unk54, 200.0f, 0x5800);
                        sp54->routeTarget = sp54->routeEnd;
                    }
                    _subaddierouteDll_entrypoint_5(arg0, sp54->route, sp54->routeTarget, 0.15f, 8.0f, 200.0f);
                } else {
                    arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
                    func_80102BF8(arg0, 0.15f, 8.0f, 200.0f);
                }
                ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], sp54->speed, func_800D8FF8() * 400.0f);
                func_8010C3A8(arg0, 0x305425, func_800F3780(func_80101F24(arg0), D_80800F14_chnutsnbolts, 3));
                if (!sp54->active) {
                    if (_subaddierouteDll_entrypoint_4(arg0) && func_800DC298(0.2f) &&
                        (!func_8010C9B0(arg0->position, 1500) || !func_8010C500(arg0))) {
                        func_8080092C_chnutsnbolts(arg0, 6);
                    }
                } else if (!func_800F6478(func_800F54E4())) {
                    func_8080092C_chnutsnbolts(arg0, 5);
                }
            }
            func_80800BD4_chnutsnbolts(arg0);
            break;
        case 5:
            func_80800BD4_chnutsnbolts(arg0);
            if (func_800F6478(func_800F54E4()) && !func_80800A88_chnutsnbolts(arg0, 1, 4)) {
                func_8080092C_chnutsnbolts(arg0, 6);
            }
            break;
        case 6:
            func_80800C04_chnutsnbolts(arg0);
            if (func_80101DDC(arg0)) {
                func_8080092C_chnutsnbolts(arg0, 2);
                arg0->unk58 = func_800DC178(1.5f, 2.0f);
            }
            break;
        case 7:
            if (!sp54->active) {
                _subaddiefx_entrypoint_0(arg0, 4, sp54);
            }
            if (func_800D9078(&sp54->timer)) {
                _subaddiefx_entrypoint_1(arg0, (u8 *)sp54);
                if (!func_80800A88_chnutsnbolts(arg0, 1, 4)) {
                    func_8080092C_chnutsnbolts(arg0, 6);
                }
            }
            break;
        case 8:
            if (!sp54->active) {
                _subaddiefx_entrypoint_0(arg0, 4, sp54);
            }
            break;
        }
    }
}

s32 func_808005D0_chnutsnbolts(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80103DFC(Actor *, f32 *);
    s32 func_8010A430(void *);
    Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void _subaddiefade_entrypoint_3(Actor *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 func_80107070(Actor *, u32);
    void func_80101038(f32 *);
    void func_80101074(void *);
    void func_800EFB24(void *, void *, void *);
    void func_800EF368(f32 *, f32);
    f32 func_800DC178(f32, f32);
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    extern u8 D_80800E04_chnutsnbolts[];
    extern u8 D_80800E10_chnutsnbolts[];
    struct NutsFlags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 enabled : 1, u32 pad64_0 : 24);
        BT_BITFIELD_ORDER(u32 pad64_25 : 6, u32 visible : 1);
        BT_BITFIELD_ORDER(u32 visible : 1, u32 pad64_25 : 6);
        BT_BITFIELD_ORDER(u32 pad64_0 : 24, u32 enabled : 1);
        u32 pad68;
        u32 pad6C;
        BT_BITFIELD_ORDER(u32 pad70_17 : 15, u32 pad70_0 : 16);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 pad70_0 : 16, u32 pad70_17 : 15);
        u32 pad74;
        BT_BITFIELD_ORDER(u32 pad78_3 : 29, u32 pad78_0 : 2);
        u32 blocked : 1;
        BT_BITFIELD_ORDER(u32 pad78_0 : 2, u32 pad78_3 : 29);
    };
    struct NutsData {
        u8 effects[8];
        u8 route[6];
        u16 routeEnd;
        u8 pad10[4];
        s16 routeTarget;
        u8 active;
        u8 pad17;
        f32 timer;
        f32 speed;
    } *data;
    f32 pos[3];
    s32 iterator;
    Actor *other;
    s32 last;
    s32 id;
    f32 point[3];
    f32 *velocity;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x3E:
        if (!arg0->unk64_29 && arg0->unk70_10 == 4) {
            func_8080092C_chnutsnbolts(arg0, 5);
        }
        break;
    case 0x3F:
        if (((struct NutsFlags *)arg0)->blocked) {
            return 0;
        }
        if (arg0->unk70_10 != 7) {
            func_8080092C_chnutsnbolts(arg0, 7);
        }
        break;
    case 0x40:
        func_80103DFC(arg0, pos);
        if (!data->active) {
            if (func_8010A430(arg0)) {
                _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, *(s32 *)&pos[0], *(s32 *)&pos[1], *(s32 *)&pos[2], *(s32 *)&arg0->rotation[1]);
            }
        } else {
            last = 1;
            for (id = 0x43E; id < 0x441; id++) {
                for (other = _subaddiefind_entrypoint_2(id, &iterator); other != NULL; other = _subaddiefind_entrypoint_3(id, &iterator)) {
                    if (other != arg0 && (s32)other->unk70_10 < 8) {
                        last = 0;
                        goto found;
                    }
                }
            }
        found:
            if (last) {
                _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, *(s32 *)&pos[0], *(s32 *)&pos[1], *(s32 *)&pos[2], *(s32 *)&arg0->rotation[1]);
            }
        }
        func_8080092C_chnutsnbolts(arg0, 8);
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(arg0) && !func_80107070(arg0, 1)) {
            func_8080092C_chnutsnbolts(arg0, 10);
            _subaddiefade_entrypoint_3(arg0);
            ((struct NutsFlags *)arg0)->active = 0;
            ((struct NutsFlags *)arg0)->enabled = arg0->pad70_16; ((struct NutsFlags *)arg0)->visible = arg0->pad70_16;
        }
        break;
    case 0x8E:
        func_80101038(point);
        velocity = (f32 *)&arg0->actorData[4];
        func_800EFB24(velocity, point, arg0->position);
        func_800EF368(velocity, func_800DC178(1800.0f, 2000.0f));
        func_8080092C_chnutsnbolts(arg0, 1);
        _subaddieDll_entrypoint_4(arg0, 1);
        data->active = 1;
        arg0->unk58 = 0.0f;
        break;
    case 0x95:
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x38:
        if (arg0->unk6C_9 == 0x440) {
            func_80101074(D_80800E10_chnutsnbolts);
            return 2;
        }
        func_80101074(D_80800E04_chnutsnbolts);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_808008FC_chnutsnbolts(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void _subaddiefx_entrypoint_1(BtIntPtr arg0, void *arg1);
    _subaddiefx_entrypoint_1(arg0, func_80100094(arg0, 0U));
}

s32 func_8080092C_chnutsnbolts(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    f32 func_800DC178(f32, f32);
    s32 func_80107070(Actor *, u32);
    void func_8010A570(Actor *);
    void _subaddiefade_entrypoint_3(Actor *);
    struct NutsData {
        u8 effects[8];
        u8 route[6];
        u16 routeEnd;
        u8 pad10[4];
        s16 routeTarget;
        u8 active;
        u8 pad17;
        f32 timer;
        f32 speed;
    } *data;
    struct NutsActorFlags {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 flag31 : 1, u32 tail64 : 24);
        BT_BITFIELD_ORDER(u32 pad64 : 6, u32 flag24 : 1);
        BT_BITFIELD_ORDER(u32 flag24 : 1, u32 pad64 : 6);
        BT_BITFIELD_ORDER(u32 tail64 : 24, u32 flag31 : 1);
        u32 pad68;
        u32 pad6C;
        BT_BITFIELD_ORDER(u32 savedState : 7, u32 pad73 : 4);
        BT_BITFIELD_ORDER(u32 pad70 : 8, u32 state : 6);
        BT_BITFIELD_ORDER(u32 flag16 : 1, u32 pad72 : 6);
        BT_BITFIELD_ORDER(u32 pad72 : 6, u32 flag16 : 1);
        BT_BITFIELD_ORDER(u32 state : 6, u32 pad70 : 8);
        BT_BITFIELD_ORDER(u32 pad73 : 4, u32 savedState : 7);
    };

    data = func_80100094(arg0, 0U);
    func_80102424(arg0, arg1);
    switch (arg1) {
    case 1:
        arg0->unk64_24 = 0;
        break;
    case 2:
        arg0->unk64_24 = 1;
        break;
    case 4:
        data->speed = func_800DC178(700.0f, 800.0f);
        ((f32 *)arg0->actorData)[3] = 0.0f;
        break;
    case 7:
        data->timer = func_800DC178(3.0f, 4.0f);
        break;
    case 8:
        ((struct NutsActorFlags *)arg0)->state = 0;
        ((struct NutsActorFlags *)arg0)->savedState = ((struct NutsActorFlags *)arg0)->state;
        ((struct NutsActorFlags *)arg0)->flag16 = 0;
        ((struct NutsActorFlags *)arg0)->flag31 = (u8)((struct NutsActorFlags *)arg0)->flag16; ((struct NutsActorFlags *)arg0)->flag24 = ((struct NutsActorFlags *)arg0)->flag16;
        if (!func_80107070(arg0, 2)) {
            func_8010A570(arg0);
            _subaddiefade_entrypoint_3(arg0);
        }
        break;
    } BT_NATIVE_ONLY(return 0;)
}

s32 func_80800A88_chnutsnbolts(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010C500(void *);
    s32 func_8010C9B0(f32 *, s32);
    u8 *data;

    data = func_80100094(arg0, 0U);
    if (arg0->unk64_29) {
        func_8080092C_chnutsnbolts(arg0, arg2);
        return 1;
    }
    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if (data[0x16] != 0) {
        func_8080092C_chnutsnbolts(arg0, arg2);
        return 1;
    }
    if (((arg1 != 0) || ((_subaddierouteDll_entrypoint_4(arg0) != 0) && (func_800DC298(0.2f) != 0))) &&
        (func_8010C9B0(arg0->position, 1500) != 0) && (func_8010C500(arg0) != 0)) {
        func_8080092C_chnutsnbolts(arg0, arg2);
        return 1;
    }
    return 0;
}

s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
void func_80800B80_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts[4];
    extern u32 D_80800F2C_chnutsnbolts[4];
    extern u32 D_80800F3C_chnutsnbolts[3];
    f32 *sp1C[2];

    sp1C[1] = &arg0->position[0];
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[1], D_80800CC0_chnutsnbolts, D_80800F3C_chnutsnbolts);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], D_80800F2C_chnutsnbolts, 0.2f);
}

void func_80800BD4_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts[4];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800CC0_chnutsnbolts, 0.65f);
}

void func_80800C04_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts[4];
    extern u32 D_80800F48_chnutsnbolts[4];
    extern u32 D_80800F58_chnutsnbolts[6];
    f32 *sp1C[2];

    sp1C[1] = &arg0->position[0];
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], D_80800F48_chnutsnbolts, 0.7f);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[1], D_80800CC0_chnutsnbolts, D_80800F58_chnutsnbolts);
}
/* data_to_c.py: from asm/data/overlays/ch/nutsnbolts.data.s */
extern u8 D_80800CD0_chnutsnbolts[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80800DF0_chnutsnbolts[];
extern u8 D_80800D30_chnutsnbolts[];
extern u8 D_80800D90_chnutsnbolts[];
u32 D_80800CC0_chnutsnbolts[4] BT_DATA(4, overlays_ch_nutsnbolts, 0x0) = { 0x13045A, 0xD0140, 0x1590016, 0x36B00000 };
u8 D_80800CD0_chnutsnbolts[96] BT_DATA(4, overlays_ch_nutsnbolts, 0x10) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE3, 0x00, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE3, 0x00, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE3, 0x00, 0x02, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xE4, 0x00, 0x01, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xE4, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x02, 0xE3, 0x00, 0x92, 0x3F, 0x8F, 0x5C, 0x29, 0x02, 0xE5, 0x00, 0x01, 0x3F, 0x8F, 0x5C, 0x29, 0x02, 0xE5, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xE4, 0x04, 0x01, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE3, 0x00, 0x4C };
u8 D_80800D30_chnutsnbolts[96] BT_DATA(4, overlays_ch_nutsnbolts, 0x70) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE9, 0x00, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE9, 0x00, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE9, 0x00, 0x02, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xEA, 0x00, 0x01, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xEA, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x02, 0xE9, 0x00, 0x92, 0x3F, 0x8F, 0x5C, 0x29, 0x02, 0xEB, 0x00, 0x01, 0x3F, 0xAF, 0x5C, 0x29, 0x02, 0xEB, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xEA, 0x04, 0x01, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE9, 0x00, 0x4C };
u8 D_80800D90_chnutsnbolts[96] BT_DATA(4, overlays_ch_nutsnbolts, 0xD0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE6, 0x00, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE6, 0x00, 0x4C, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE6, 0x00, 0x02, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xE7, 0x00, 0x01, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xE7, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x02, 0xE6, 0x00, 0x92, 0x3F, 0x8F, 0x5C, 0x29, 0x02, 0xE8, 0x00, 0x01, 0x3F, 0x8F, 0x5C, 0x29, 0x02, 0xE8, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xE7, 0x04, 0x01, 0x3F, 0xCC, 0xCC, 0xCD, 0x02, 0xE6, 0x00, 0x4C };
u8 D_80800DF0_chnutsnbolts[20] BT_DATA(4, overlays_ch_nutsnbolts, 0x130) = { 0x00, 0x02, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00 };
u8 D_80800E04_chnutsnbolts [12] BT_DATA(4, overlays_ch_nutsnbolts, 0x144) = { 0, 0, 0, 1, 0x3F, 0xE6, 0x66, 0x66, 0, 0x12, 0, 0 };
u8 D_80800E10_chnutsnbolts [24] BT_DATA(4, overlays_ch_nutsnbolts, 0x150) = { 0, 0, 0, 3, 0x3F, 0xC0, 0, 0, 0, 0x12, 0, 0, 0, 0, 0, 1, 0x40, 0, 0, 0, 0, 0x12, 0, 0 };
ActorData D_80800E28_chnutsnbolts [1] BT_DATA(4, overlays_ch_nutsnbolts, 0x168) = { { 413, 1086, 2026, 2, (void *)D_80800CD0_chnutsnbolts, (void (*)(struct Actor *))func_80800080_chnutsnbolts, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 1065353216, 0, 0, 901, 609, (void (*)(struct Actor *))func_808008FC_chnutsnbolts, (BtIntPtr)func_80108ED0, 32, 0, (void (*)(struct Actor *))func_80800024_chnutsnbolts, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32734, 21533, (void (*)(struct Actor *, long, long))func_808005D0_chnutsnbolts, (BtIntPtr)D_80800DF0_chnutsnbolts } };
ActorData D_80800E70_chnutsnbolts [1] BT_DATA(4, overlays_ch_nutsnbolts, 0x1B0) = { { 413, 1087, 2027, 2, (void *)D_80800D30_chnutsnbolts, (void (*)(struct Actor *))func_80800080_chnutsnbolts, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 1061997773, 0, 0, 901, 609, (void (*)(struct Actor *))func_808008FC_chnutsnbolts, (BtIntPtr)func_80108ED0, 32, 0, (void (*)(struct Actor *))func_80800024_chnutsnbolts, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32734, 21533, (void (*)(struct Actor *, long, long))func_808005D0_chnutsnbolts, (BtIntPtr)D_80800DF0_chnutsnbolts } };
ActorData D_80800EB8_chnutsnbolts [1] BT_DATA(4, overlays_ch_nutsnbolts, 0x1F8) = { { 413, 1088, 2028, 2, (void *)D_80800D90_chnutsnbolts, (void (*)(struct Actor *))func_80800080_chnutsnbolts, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 1067030938, 0, 0, 901, 609, (void (*)(struct Actor *))func_808008FC_chnutsnbolts, (BtIntPtr)func_80108ED0, 32, 0, (void (*)(struct Actor *))func_80800024_chnutsnbolts, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32734, 21533, (void (*)(struct Actor *, long, long))func_808005D0_chnutsnbolts, (BtIntPtr)D_80800DF0_chnutsnbolts } };
u8 D_80800F00_chnutsnbolts [20] BT_DATA(4, overlays_ch_nutsnbolts, 0x240) = { 0, 0x13, 5, 0xC1, 0, 0xD, 0, 0xB3, 0, 0xCC, 0, 1, 5, 0xDC, 0x13, 0x88, 0, 0, 0, 0 };
u8 D_80800F14_chnutsnbolts [24] BT_DATA(4, overlays_ch_nutsnbolts, 0x254) = { 0, 0, 0, 0, 0x3D, 0xCC, 0xCC, 0xCD, 0x3F, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0x3D, 0xCC, 0xCC, 0xCD };
u32 D_80800F2C_chnutsnbolts[4] BT_DATA(4, overlays_ch_nutsnbolts, 0x26C) = { 0x1304B2, 0xD00D9, 0xF30016, 0x36B00000 };
u32 D_80800F3C_chnutsnbolts[3] BT_DATA(4, overlays_ch_nutsnbolts, 0x27C) = { 0x3F19999A, 0x3F666666, 0xBF800000 };
u32 D_80800F48_chnutsnbolts[4] BT_DATA(4, overlays_ch_nutsnbolts, 0x288) = { 0x1304B2, 0xD00C0, 0xD90016, 0x36B00000 };
u32 D_80800F58_chnutsnbolts[6] BT_DATA(4, overlays_ch_nutsnbolts, 0x298) = { 0x3E4CCCCD, 0x3F000000, 0xBF800000, 0, 0, 0 };
