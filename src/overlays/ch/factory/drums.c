#include "common.h"

extern u32 D_80800FE0_chfactorydrums[];
extern u32 D_80800FF4_chfactorydrums[];
void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_808003A8_chfactorydrums(Actor *arg0);
void func_808003DC_chfactorydrums(Actor *arg0);
s32 func_80800D90_chfactorydrums(Actor *arg0, s32 arg1, s32 arg2);

u32 D_80800FE0_chfactorydrums[] = {
    0x00010000, 0x00080000, 0x00080000, 0x00070000,
    0x00090000,
};

u32 D_80800FF4_chfactorydrums[] = {
    0x00000000, 0x00000000, 0x3EEF1AA0, 0x02AC0044,
    0x3EEF1AA0, 0x02AC0042, 0x3E92F1AA, 0x02A70001,
    0x3EEF1AA0, 0x02AC0092, 0x3F28F5C3, 0x02AB0042,
    0x3F28F5C3, 0x02AB0042, 0x3F28F5C3, 0x02AB0062,
    0x3EEF1AA0, 0x02AC0044, 0x3EEF1AA0, 0x02AC0044,
};

u32 D_80801044_chfactorydrums[] = {
    0x00000003, 0x4019999A, 0x01010000, 0x00000001,
    0x4019999A, 0x01120000, 0x0000000A, 0x3FC00000,
    0x02030000, 0x00000018, 0x3FC00000, 0x02030000,
    0x0000002A, 0x3F99999A, 0x026C0000,
};

u32 D_80801080_chfactorydrums[] = {
    0x001304DC, 0x001636B0, 0x00000000,
};

u32 D_8080108C_chfactorydrums[] = {
    0x00000000, 0x3F000000, 0xBF800000,
};

u32 D_80801098_chfactorydrums[] = {
    0x001304D5, 0x00163E80, 0x000D00CC, 0x00E60001,
    0x00C81770, 0x00000000,
};

u32 D_808010B0_chfactorydrums[] = {
    0x00000000, 0x3E4CCCCD, 0x3E19999A, 0x3F800000,
    0x3EB33333, 0x3F4CCCCD, 0x3F000000, 0x3E4CCCCD,
    0x3F266666, 0x3F800000, 0x3F59999A, 0x3F4CCCCD,
};

u32 D_808010E0_chfactorydrums[] = {
    0x3F8CCCCD, 0xBAB78034, 0x3EB33333,
};

u32 D_808010EC_chfactorydrums[] = {
    0x001D09C9, 0x00161000, 0x002B0180, 0x03000022,
    0x00800100, 0x05000A00, 0x00150033, 0x004C0019,
    0x00000007, 0x002CFFD8, 0x0032FFD8, 0x00280096,
    0x00280020, 0xFFFFFF50, 0x000AFFD8, 0x0000FFD8,
    0x002800C8, 0x00280000,
};

u32 D_80801134_chfactorydrums[] = {
    0x001D09D0, 0x00161000, 0x002B0180, 0x03000022,
    0x00800100, 0x05000A00, 0x00150033, 0x004C0019,
    0x00000007, 0x002CFFD8, 0x0032FFD8, 0x00280096,
    0x00280020, 0x00F00350, 0x000AFFD8, 0x0000FFD8,
    0x002800C8, 0x00280000,
};

u32 D_8080117C_chfactorydrums[] = {
    0x00140016, 0x1406002B, 0x02000300, 0x002D0258,
    0x0320001B, 0xF448F63C, 0x00230100, 0x0031FFEC,
    0xFFFB000B, 0x00190019, 0x00320000, 0x00150000,
    0x00B30004, 0x008C0007, 0x00040000,
};

u32 D_808011B8_chfactorydrums[] = {
    0x001304C8, 0x00165DC0, 0x000100C8, 0x1770000A,
    0x014C0000,
};

u32 D_808011CC_chfactorydrums[] = {
    0x001D09D0, 0x00161000, 0x002B0180, 0x02000022,
    0x00800100, 0x05000A00, 0x00150000, 0x004C0019,
    0x00000007, 0x002CFFD8, 0x0032FFD8, 0x00280096,
    0x00280020, 0x00F00350, 0x00000000,
};

u32 D_80801208_chfactorydrums[] = {
    0x001D09C9, 0x00161000, 0x002B0180, 0x03000022,
    0x00800100, 0x05000A00, 0x00150033, 0x004C0019,
    0x00000007, 0x002CFFD8, 0x0032FFD8, 0x00280096,
    0x00280020, 0xFFFFFF50, 0x000AFFD8, 0x0000FFD8,
    0x002800C8, 0x00280000,
};

u32 D_80801250_chfactorydrums[] = {
    0x00000000, 0x437A0000, 0x00000000,
};

BtFnWord D_8080125C_chfactorydrums[] = {
    0x011503F0, 0x07CF0001, (BtFnWord)D_80800FF4_chfactorydrums, (BtFnWord)func_808003DC_chfactorydrums,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x0BB80000, 0x3FC00000,
    0x00000000, 0x43850221, 0x00000000, (BtFnWord)func_80108ED0,
    0x000C0000, (BtFnWord)func_808003A8_chfactorydrums, (BtFnWord)func_80107C2C, 0x8002541D,
    (BtFnWord)func_80800D90_chfactorydrums, (BtFnWord)D_80800FE0_chfactorydrums, 0x00000000, 0x00000000,
    0x00000000,
};

s32 func_80800000_chfactorydrums(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    s32 func_800CC338(s32 *, s32, s32);
    union DrumActor {
        Actor actor;
        struct {
            u8 pad[0x70];
            BT_BITFIELD_ORDER(u32 group : 7, u32 rest : 4);
            BT_BITFIELD_ORDER(u32 unused : 15, u32 point : 6);
            BT_BITFIELD_ORDER(u32 point : 6, u32 unused : 15);
            BT_BITFIELD_ORDER(u32 rest : 4, u32 group : 7);
        } path;
        struct {
            Unk80132ED0 *unk0;
            s32 position[3];
        } coordinates;
    };
    u8 *actors[10];
    s32 count;
    s32 total = 0;
    s32 i;

    count = _subaddiefind_entrypoint_4(0x3FF, actors, 10);
    for (i = 0; i < count; i++) {
        if (func_800CC338(((union DrumActor *)actors[i])->coordinates.position,
                ((union DrumActor *)arg0)->path.group - 1,
                ((union DrumActor *)arg0)->path.point - 1) != 0) {
            total++;
        }
    }
    count = _subaddiefind_entrypoint_4(0x3F0, actors, 10);
    for (i = 0; i < count; i++) {
        if (((union DrumActor *)actors[i])->actor.unk70_10 == 5) {
            if (func_800CC338(((union DrumActor *)actors[i])->coordinates.position,
                    ((union DrumActor *)arg0)->path.group - 1,
                    ((union DrumActor *)arg0)->path.point - 1) != 0) {
                total++;
            }
        }
    }
    return total < ((s32)arg0->unk74_7 - 50);
}

s32 func_80800130_chfactorydrums(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EF3DC(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    u8 *actors[10];
    s32 count;
    s32 i;
    s32 result = 1;
    f32 origin[3];
    f32 self[3];
    f32 other[3];

    count = _subaddiefind_entrypoint_4(0x3F0, actors, 10);
    for (i = 0; i < count; i++) {
        if ((((Actor *)actors[i])->unk70_10 == 3 ||
             ((Actor *)actors[i])->unk70_10 == 5) &&
            arg0 != (Actor *)actors[i]) {
            func_800F5A00(func_800F54E4(), origin);
            func_800EE7F8(other, ((Actor *)actors[i])->position);
            func_800EE7F8(self, arg0->position);
            func_800EF3DC(other, origin);
            func_800EF3DC(self, origin);
            func_800EF2A0(other);
            func_800EF2A0(self);
            result &= (other[0] * self[0] + other[1] * self[1] +
                       other[2] * self[2]) <= 0.0f;
            if (result == 0) {
                return 0;
            }
        }
    }
    return result;
}

/* extern */

void func_808002B8_chfactorydrums(Actor *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 func_8001210C(s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_80102424(Actor *, s32);
    s32 func_80800000_chfactorydrums(Actor *);
    union FactoryDrumsActor {
        Actor actor;
        struct {
            u8 pad[0x64];
            BT_BITFIELD_ORDER(u32 pad64_30 : 2, u32 : 29);
            BT_BITFIELD_ORDER(u32 unk64_29 : 1, u32 unk64_29 : 1; u32 pad64_30 : 2);
        } flags;
    };
    union FactoryDrumsActor *drum = (union FactoryDrumsActor *)arg0;
    if (drum->flags.unk64_29) {
        if ((func_8001210C(7) != 0) && (arg0->unk74_7 != 0x32) && (func_80800000_chfactorydrums(arg0) != 0) && (_subaddiejoy_entrypoint_6((u8 *)arg0, 1) != 0)) {
            func_80102424(arg0, 5);
        }
    } else if ((func_800D90A4(&arg0->unk58) != 0) && (func_8001210C(7) != 0)) {
        if ((arg0->unk74_7 != 0x32) && (func_80800000_chfactorydrums(arg0) != 0)) {
            func_80102424(arg0, 5);
        }
        arg0->unk58 = func_800DC178(3.0f, 5.0f);
    }
}

void func_808003A8_chfactorydrums(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
}

void func_808003DC_chfactorydrums(Actor *arg0) {
    typedef struct Vec3s32 {
        f32 x, y, z;
    } Vec3s32;
    void func_80101CDC(Actor *, f32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    void func_801026CC(Actor *, Vec3s32, f32);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    f32 _subaddiejoy_entrypoint_3();
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA4D0(s16 *, s16);
    void func_800BA544(s32 *, BtIntPtr);
    void func_800BA670(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4140(u32, f32 *, u32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1198(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    void func_80102BAC(Actor *, f32, f32, f32);
    void func_80108B04(Actor *, s32);
    s32 func_8010BA80(Actor *volatile arg0, volatile s32 arg1, s32 arg2);
    s32 func_8010C3A8(Actor *arg0, u32 arg1, f32 arg2);
    s32 func_8010C500(Actor *);
    void func_8010C93C(Actor *, f32 *, f32);
    f32 func_8010CD50(Actor *, BtIntPtr);
    void func_80800CD0_chfactorydrums(Actor *, s32);
    void _chfactorydrums_entrypoint_0(s32, BtIntPtr);
    void _chfactorydrums_entrypoint_1(s32, BtIntPtr);
    union DrumUpdateActor {
        Actor actor;
        struct {
            u8 pad[0x38];
            s32 scale;
        } particles;
        struct {
            u8 pad[0x78];
            BT_BITFIELD_ORDER(u32 unused : 29, u32 rest : 2);
            u32 inactive : 1;
            BT_BITFIELD_ORDER(u32 rest : 2, u32 unused : 29);
        } flags;
    };
    struct DrumRoute {
        u8 pad[6];
        u16 point;
    };
    Vec3s32 sp54;
    f32 sp50;
    struct DrumRoute *sp4C;
    BtIntPtr sp48;
    BtIntPtr sp44;
    BtIntPtr sp40;

    if (arg0->unk70_10 != 7) {
        func_8010C93C(arg0, arg0->position, 0.5f);
    }
    if (!((union DrumUpdateActor *)arg0)->flags.inactive) {
        switch (arg0->unk70_10) {
            case 1:
                if (arg0->unk64_29) {
                    if (_subaddiejoy_entrypoint_3(arg0) >= 0.1f) {
                        func_80800CD0_chfactorydrums(arg0, 2);
                    }
                    func_808002B8_chfactorydrums(arg0);
                } else if (func_800D90A4(&arg0->unk58) && func_8010C500(arg0) && func_80800130_chfactorydrums(arg0)) {
                    func_80800CD0_chfactorydrums(arg0, 2);
                }
                break;
            case 2:
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, ((u32 *)D_80801098_chfactorydrums), 0.5f);
                if (func_80101DDC(arg0)) {
                    func_80800CD0_chfactorydrums(arg0, 3);
                    arg0->unk58 = func_800DC178(3.0f, 5.0f);
                }
                if (arg0->unk64_29) {
                    _subaddiejoy_entrypoint_3(arg0);
                    func_80102BAC(arg0, 1.5f, 1.0f, 20.0f);
                }
                break;
            case 3:
                sp54 = (*(Vec3s32 *)D_8080108C_chfactorydrums);
                if (func_80101E4C(arg0, &sp54.x)) {
                    func_800C4140(((u16)(func_800DC178(1.0f, 1.1f) * 1023.0f) << 21) + 0xFA45A, arg0->position, 0x4B000FA);
                }
                if (arg0->unk64_29) {
                    sp50 = _subaddiejoy_entrypoint_3(arg0);
                    func_80102BAC(arg0, 1.5f, 1.0f, 20.0f);
                    ((f32 *)arg0->actorData)[3] = sp50 * 600.0f;
                    func_8010BA80(arg0, 0x201015, 0x20);
                    func_80101CDC(arg0, func_800F1198(((f32 *)arg0->actorData)[3], 500.0f, 600.0f, 0.467f, 0.35025f));
                    func_808002B8_chfactorydrums(arg0);
                } else {
                    sp4C = func_80100094(arg0, 0);
                    if (_subaddierouteDll_entrypoint_4(arg0)) {
                        if (func_8010C500(arg0) && func_80800130_chfactorydrums(arg0)) {
                            arg0->unk54 = func_8010CD50(arg0, func_800F54E4());
                        } else {
                            func_80800CD0_chfactorydrums(arg0, 4);
                        }
                        _subaddierouteDll_entrypoint_7(arg0, sp4C, arg0->rotation[1], arg0->unk54, 200.0f, 0x4802);
                        arg0->unk6C_0 = sp4C->point;
                    }
                    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], arg0->unk50, func_800D8FF8() * 500.0f);
                    _subaddierouteDll_entrypoint_5(arg0, sp4C, arg0->unk6C_0, 0.3f, 1.0f, 200.0f);
                    func_8010C3A8(arg0, 0x305425, func_800F3780(func_80101F24(arg0), ((u8 *)D_808010B0_chfactorydrums), 6));
                    func_801026CC(arg0, (*(Vec3s32 *)D_808010E0_chfactorydrums), ((f32 *)arg0->actorData)[3]);
                    func_808002B8_chfactorydrums(arg0);
                }
                break;
            case 4:
                _subaddieaudioquick_entrypoint_3(arg0, arg0->position, ((u32 *)D_80801098_chfactorydrums), 0.5f);
                if (func_80101DDC(arg0) && !((union DrumUpdateActor *)arg0)->flags.inactive) {
                    arg0->unk58 = 1.5f;
                    func_80800CD0_chfactorydrums(arg0, 1);
                }
                break;
            case 5:
                _subaddieaudioloop_entrypoint_4(arg0, arg0->position, func_80101F24(arg0) > 0.3f && func_80101F24(arg0) < 1.0f, ((u32 *)D_80801080_chfactorydrums));
                _subaddieaudioloop_entrypoint_0(arg0, func_800F1214(func_800F10B4(func_80101F24(arg0), 0.3f, 1.0f, 0.0f, 1.0f), 1.2f, 0.9f));
                if (func_80101E14(arg0, 0.5f)) {
                    func_80108B04(arg0, 0);
                } else if (func_80101DDC(arg0)) {
                    _subaddieaudioloop_entrypoint_2(arg0);
                    if (arg0->unk64_29) {
                        func_80800CD0_chfactorydrums(arg0, 3);
                    } else {
                        switch (func_8010C500(arg0)) {
                            default:
                                func_80800CD0_chfactorydrums(arg0, 3);
                                break;
                            case 0:
                                func_80800CD0_chfactorydrums(arg0, 4);
                                break;
                        }
                    }
                }
                break;
            case 6:
                sp48 = func_800B53A4(2);
                sp44 = func_800B53A4(2);
                sp40 = func_800B53A4(6);
                func_800BABB8(sp48, arg0->position, arg0->position, 1.0f, ((s32 *)D_8080117C_chfactorydrums));
                func_800BA670(sp48, 0x88C);
                func_800BA4D0(sp48, arg0->position[1] + 35.0f);
                func_800BA22C(sp48, 2);
                func_800BABB8(sp44, arg0->position, arg0->position, 1.0f, ((s32 *)D_8080117C_chfactorydrums));
                func_800BA670(sp44, 0x88D);
                func_800BA4D0(sp44, arg0->position[1] + 35.0f);
                func_800BA22C(sp44, 2);
                func_800BABB8(sp40, arg0->position, arg0->position, 1.0f, ((s32 *)D_8080117C_chfactorydrums));
                func_800BA670(sp40, 0x88B);
                func_800BA544(sp40, arg0->unk74_7 != 0x32 ? _chfactorydrums_entrypoint_0 : _chfactorydrums_entrypoint_1);
                func_800BA4D0(sp40, arg0->position[1] + 35.0f);
                func_800BA22C(sp40, 6);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u32 *)D_808011B8_chfactorydrums));
                if (arg0->unk74_7 != 0x32) {
                    if (func_80800000_chfactorydrums(arg0)) {
                        func_80108B04(arg0, 0);
                    }
                    func_800BBCB8(arg0->position, 0, arg0->scale, 3, ((s32 *)D_80801134_chfactorydrums));
                } else {
                    func_800BBCB8(arg0->position, 0, arg0->scale, 3, ((s32 *)D_808010EC_chfactorydrums));
                }
                func_80800CD0_chfactorydrums(arg0, 7);
                break;
            case 7:
            case 8:
            case 9:
                break;
        }
    }
}

void chfactorydrums_entrypoint_0(s32 arg0, BtIntPtr arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    func_800BBCB8((f32 *)arg1, NULL, 1.0f, 1, &(*(s32 *)D_808011CC_chfactorydrums));
}

void chfactorydrums_entrypoint_1(s32 arg0, BtIntPtr arg1) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    func_800BBCB8((f32 *)arg1, NULL, 1.0f, 1, &(*(s32 *)D_80801208_chfactorydrums));
}

void func_80800CD0_chfactorydrums(Actor *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    void func_80101CDC(Actor *, f32);
    void func_80102424(Actor *, s32);
    s32 func_80107070(Actor *, s32);
    void func_8010A590(Actor *);

    switch (arg1) {
        case 1:
            func_8010A590(arg0);
            arg0->unk64_16 = 1;
            arg0->unk58 = func_800DC178(0.5f, 2.0f);
            ((f32 *)arg0->actorData)[3] = 0.0f;
            break;
        case 3:
            func_80101CDC(arg0, 0.467f);
            ((f32 *)arg0->actorData)[3] = 0.0f;
            arg0->unk50 = 500.0f;
            break;
        case 7:
            func_80107070(arg0, 3);
            break;
    }
    func_80102424(arg0, arg1);
}

s32 func_80800D90_chfactorydrums(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800C4140(u32, f32 *, u32);
    void func_80101010(f32 *);
    void func_80101074(void *);
    s32 func_80103140(Actor *, u32, u16);
    f32 func_80103EF4(Actor *);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    union DrumFlags {
        Actor actor;
        struct {
            u8 pad[0x78];
            BT_BITFIELD_ORDER(u32 unused : 29, u32 rest : 2);
            u32 flag : 1;
            BT_BITFIELD_ORDER(u32 rest : 2, u32 unused : 29);
        } flags;
    };
    Actor *sp1C;

    switch (arg1) {
        case 0x3E:
        case 0x3F:
            if (!arg0->unk64_29 && !((union DrumFlags *)arg0)->flags.flag) {
                func_80800CD0_chfactorydrums(arg0, 4);
            }
            if (arg0->unk70_10 != 4) {
                func_800C4140(0x7FEFA417, arg0->position, 0x04B000FA);
            }
            return 1;
        case 0x40:
            func_80800CD0_chfactorydrums(arg0, 6);
            return 1;
        case 1:
            func_80800CD0_chfactorydrums(arg0, 2);
            return 1;
        case 2:
            func_80800CD0_chfactorydrums(arg0, 8);
            return 1;
        case 0x3D:
            sp1C = func_80108528(0x3FF, arg0->position, 0, &arg0);
            sp1C->position[1] += func_80103EF4(arg0);
            return 1;
        case 0x38:
            func_80101074(((u8 *)D_80801044_chfactorydrums));
            return 5;
        case 0x95:
            _subaddierouteDll_entrypoint_1(arg0);
            if (arg0->unk74_7 == 0x32) {
                func_80103140(arg0, 0x7D0, arg0->unk0->unk16);
            }
            func_80800CD0_chfactorydrums(arg0, 1);
            return 1;
        case 0x97:
            func_80101010(((f32 *)D_80801250_chfactorydrums));
            return 1;
        default:
            return 0;
    }
}

OSThread *chfactorydrums_entrypoint_2(void)
{
    return (OSThread *) ((u8 *)D_8080125C_chfactorydrums);
}
