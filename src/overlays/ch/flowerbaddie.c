#include "common.h"

OSThread *chflowerbaddie_entrypoint_0(void)
{
    extern ActorData D_80800C14_chflowerbaddie[];

    return (OSThread *) D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(BtIntPtr arg0, void *arg1, f32 *arg2);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 600.0f;
    arg0->unk64_20 = 0;
}

void func_8080005C_chflowerbaddie(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800F3780(f32, u8 *, s16);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102B2C(Actor *, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_8010D254(f32 *);
    s32 func_808007F0_chflowerbaddie(Actor *);
    void func_80800980_chflowerbaddie(Actor *, f32 *);
    s32 func_808009F0_chflowerbaddie(Actor *, void *, f32);
    extern u32 D_80800C5C_chflowerbaddie[];
    extern u8 D_80800C68_chflowerbaddie[];
    extern f32 D_80800C80_chflowerbaddie[];
    extern f32 D_80800C94_chflowerbaddie[];
    extern u8 D_80800CA8_chflowerbaddie[];
    union FlowerBaddieUpdateActor {
        Actor actor;
        struct {
            u32 reserved[30];
            u32 : 29;
            u32 inactive : 1;
            u32 : 2;
        } flags;
    };
    void *sp34;

    sp34 = func_80100094(arg0, 0);
    if (((union FlowerBaddieUpdateActor *)arg0)->flags.inactive) {
        return;
    }
    func_8010D254((f32 *)arg0->actorData);
    func_800D9078(&arg0->unk58);
    switch (arg0->unk70_10) {
    case 1:
        if (func_808007F0_chflowerbaddie(arg0)) {
            func_80102424(arg0, 2);
        }
        break;
    case 2:
        if (func_80101F24(arg0) > 0.1f) {
            arg0->unk64_20 = 1;
        } else {
            arg0->unk64_20 = 0;
        }
        func_80800980_chflowerbaddie(arg0, D_80800C80_chflowerbaddie);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800C5C_chflowerbaddie, 0.15f);
        if (func_80101F24(arg0) > 0.5f) {
            if (!func_808009F0_chflowerbaddie(arg0, sp34,
                    func_800F3780(func_80101F24(arg0), D_80800C68_chflowerbaddie, 3))) {
                return;
            }
        } else {
            if (arg0->unk64_29) {
                _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
            } else {
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
            }
            func_80102B2C(arg0, func_800D8FF8() * 120.0f);
        }
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 3);
        }
        break;
    case 3:
        func_80800980_chflowerbaddie(arg0, D_80800C94_chflowerbaddie);
        if (!(arg0->unk58 > 0.0f)) {
            func_808009F0_chflowerbaddie(arg0, sp34,
                func_800F3780(func_80101F24(arg0), D_80800CA8_chflowerbaddie, 3));
        }
        break;
    case 4:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800C5C_chflowerbaddie, 0.08f);
        if (func_80101F24(arg0) > 0.7f) {
            arg0->unk64_20 = 0;
        } else {
            arg0->unk64_20 = 1;
        }
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 1);
        }
        break;
    case 5:
        if (func_80101DDC(arg0)) {
            if (!func_808007F0_chflowerbaddie(arg0)) {
                func_80102424(arg0, arg0->unk64_20 ? 4 : 1);
            } else {
                func_80102424(arg0, arg0->unk64_20 ? 3 : 2);
            }
        }
        break;
    }
}

s32 func_80800380_chflowerbaddie(Actor *arg0, s32 arg1, s32 *arg2) {
    void _chexploder_entrypoint_4(Actor *arg0, s16 *arg1, s32 arg2);
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    void _chexploder_entrypoint_7(Actor *arg0, f32 arg1, f32 arg2);
    void _chexploder_entrypoint_8(Actor *, f32, f32);
    void _chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2);
    void _chexploder_entrypoint_10(Actor *, s16 *);
    s32 _subaddieDll_entrypoint_3(Actor *);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800FFAB0(Actor *);
    void func_80101010(f32 *);
    void func_80101074(void *);
    void *func_80101080(void);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, u32);
    void func_808006A0_chflowerbaddie(Actor *);
    extern u8 D_80800BCC_chflowerbaddie[];
    extern u8 D_80800CC0_chflowerbaddie[];
    s16 parts[20];
    Actor *exploder;
    s32 i;
    f32 position[3];
    union {
        s32 **args;
        s32 *event;
        u32 flags;
        struct {
            u32 upper : 29;
            u32 active : 1;
            u32 lower : 2;
        } bits;
    } data;

    data.args = &arg2;

    switch (arg1) {
    case 0x3E:
        arg0->unk58 = 1.0f;
        break;
    case 0x3F:
        if (arg0->unk70_10 != 5 && (data.flags = arg0->pad7A_0, !data.bits.active)) {
            _subaddieaudioloop_entrypoint_2(arg0);
            func_80102424(arg0, 5);
            arg0->unk58 = 1.0f;
        }
        break;
    case 0x40: {
        data.event = *data.args;
        _chexploder_entrypoint_4(arg0, *data.event + 4, 4);
        _subaddieaudioloop_entrypoint_2(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800CC0_chflowerbaddie);
        break;
    }
    case 0x90: {
        exploder = func_80106790(func_80101080());
        for (i = 0x44; i < 0x53; i++) {
            parts[i - 0x44] = i;
        }
        parts[i++ - 0x44] = 0x5B;
        parts[i++ - 0x44] = 0x5C;
        parts[i - 0x44] = -1;
        _chexploder_entrypoint_9(exploder, 2, 0);
        _chexploder_entrypoint_9(exploder, 3, 0);
        _chexploder_entrypoint_9(exploder, 4, 1);
        _chexploder_entrypoint_9(exploder, 5, 2);
        _chexploder_entrypoint_9(exploder, 6, 1);
        _chexploder_entrypoint_10(exploder, parts);
        _chexploder_entrypoint_6(exploder, 600.0f, 800.0f);
        _chexploder_entrypoint_7(exploder, -800.0f, -600.0f);
        _chexploder_entrypoint_8(exploder, 80.0f, 160.0f);
        func_808006A0_chflowerbaddie(arg0);
        if (!func_80107070(arg0, 3)) {
            func_800FFAB0(arg0);
        }
        break;
    }
    case 0x95:
        _subaddierouteDll_entrypoint_1(arg0);
        break;
    case 0x38:
        func_80101074(D_80800BCC_chflowerbaddie);
        return 6;
    case 0x97:
        func_800EFA4C(position, 0.0f, 300.0f, 0.0f);
        func_80101010(position);
        break;
    case 2:
        if (!_subaddieDll_entrypoint_3(arg0)) {
            func_80107070(arg0, 1);
            arg0->unk64_20 = 0;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800610_chflowerbaddie(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);

    func_800DF744(3, arg0->unk64_20 ? 1 : 0);
    func_800DF744(4, arg0->unk64_20 ? 2 : 1);
    func_800DF744(5, 1);
    func_800DF744(6, 0);
    func_80101870(arg0, arg1);
}

void func_808006A0_chflowerbaddie(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_80103DFC(Actor *, f32 *);
    extern s32 D_80800CCC_chflowerbaddie[9];
    extern s32 D_80800CF0_chflowerbaddie[5];
    extern s32 D_80800D04_chflowerbaddie[5];
    extern s32 D_80800D18_chflowerbaddie[4];
    f32 sp34[3];
    BtIntPtr emitter;

    func_80103DFC(arg0, sp34);
    emitter = func_800B53A4(1);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, D_80800D18_chflowerbaddie);
    func_800BA22C(emitter, 1);
    emitter = func_800B53A4(2);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, D_80800CF0_chflowerbaddie);
    func_800BA22C(emitter, 2);
    emitter = func_800B53A4(4);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, D_80800D04_chflowerbaddie);
    func_800BA22C(emitter, 4);
    arg0->unk64_20 = 0;
}

/* extern */

s32 func_808007F0_chflowerbaddie(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_801072A8(Actor *);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (arg0->unk58 > 0.0f) {
        return 0;
    }
    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 1;
    }
    if (func_801072A8(arg0) != 0) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 0;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 0;
    }
    return _suchase_entrypoint_0() == arg0->unk0;
}

/* extern */

s32 func_808008D4_chflowerbaddie(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 1;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 1;
    }
    return _suchase_entrypoint_0() != arg0->unk0;
}

void func_80800980_chflowerbaddie(Actor *arg0, f32 *arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_80800D28_chflowerbaddie[6];

    if (func_80101E4C(arg0, arg1) != 0) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
            func_800C4350(arg0->unk5F, arg0->position, D_80800D28_chflowerbaddie);
        }
        func_800C3BDC(arg0->unk5F);
    }
}

s32 func_808009F0_chflowerbaddie(Actor *arg0, void *arg1, f32 arg2) {
    void _subaddieaudioloop_entrypoint_2(Actor *);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddierouteDll_entrypoint_7(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5);
    f32 func_800D8FF8(void);
    void func_80102424(Actor *, s32);
    void func_80102B2C(Actor *, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010C3A8(Actor *, u32, f32);
    struct FlowerRoute {
        u16 unk0[3];
        u16 unk6;
        s32 unk8;
        s32 unkC;
    };
    f32 sp2C;
    f32 sp28;

    sp2C = func_800D8FF8();
    if (arg0->unk64_29) {
        sp28 = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
        func_80102B2C(arg0, sp2C * 120.0f);
        func_8010C3A8(arg0, 0x205025, sp28 * arg2);
    } else {
        if (_subaddierouteDll_entrypoint_4(arg0) != 0) {
            arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
            _subaddierouteDll_entrypoint_7(arg0, arg1, arg0->rotation[1], arg0->unk54, 350.0f, 0x5000);
            ((struct FlowerRoute *)arg1)->unkC = ((struct FlowerRoute *)arg1)->unk6;
        }
        func_80102B2C(arg0, sp2C * 120.0f);
        func_8010C3A8(arg0, 0x5325, arg2);
    }
    if (func_808008D4_chflowerbaddie(arg0) != 0) {
        _subaddieaudioloop_entrypoint_2(arg0);
        func_80102424(arg0, 4);
        return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/flowerbaddie.data.s */
extern u8 D_80800B70_chflowerbaddie[];
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80800BB8_chflowerbaddie[];
u8 D_80800B70_chflowerbaddie[72] BT_DATA(4, overlays_ch_flowerbaddie, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF3, 0x33, 0x33, 0x03, 0x9D, 0x00, 0x01, 0x3F, 0xF3, 0x33, 0x33, 0x03, 0x9E, 0x00, 0x02, 0x3F, 0x54, 0x7A, 0xE1, 0x03, 0x9F, 0x03, 0x01, 0x3F, 0x40, 0x00, 0x00, 0x03, 0xA0, 0x00, 0x02, 0x3F, 0x75, 0xC2, 0x8F, 0x03, 0xA1, 0x00, 0x02, 0x3F, 0xF3, 0x33, 0x33, 0x03, 0x9D, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xF3, 0x33, 0x33, 0x03, 0x9D, 0x00, 0x01 };
u8 D_80800BB8_chflowerbaddie[20] BT_DATA(4, overlays_ch_flowerbaddie, 0x48) = { 0x00, 0x01, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00 };
u8 D_80800BCC_chflowerbaddie [72] BT_DATA(4, overlays_ch_flowerbaddie, 0x5C) = { 0, 0, 0, 0x12, 0x3F, 0xC0, 0, 0, 0, 0xFD, 0, 0, 0, 0, 0, 1, 0x3F, 0xB3, 0x33, 0x33, 2, 3, 0, 0, 0, 0, 0, 0x45, 0x3F, 0xE6, 0x66, 0x66, 0, 0x46, 0, 0, 0, 0, 0, 0x51, 0x3F, 0xE6, 0x66, 0x66, 0, 0x52, 0, 0, 0, 0, 0, 0x4D, 0x3F, 0xE6, 0x66, 0x66, 0, 0x4E, 0, 0, 0, 0, 0, 0x49, 0x3F, 0xE6, 0x66, 0x66, 0, 0x4A, 0, 0 };
ActorData D_80800C14_chflowerbaddie [1] BT_DATA(4, overlays_ch_flowerbaddie, 0xA4) = { { 425, 1131, 2197, 1, (void *)D_80800B70_chflowerbaddie, (void (*)(struct Actor *))func_8080005C_chflowerbaddie, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800610_chflowerbaddie, 131072000, 1058642330, 0, 0, 773, 545, 0, (BtIntPtr)func_80108ED0, 16, 0, (void (*)(struct Actor *))func_8080000C_chflowerbaddie, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32734, 21533, (void (*)(struct Actor *, long, long))func_80800380_chflowerbaddie, (BtIntPtr)D_80800BB8_chflowerbaddie } };
u32 D_80800C5C_chflowerbaddie [3] BT_DATA(4, overlays_ch_flowerbaddie, 0xEC) = { 0x1304D5, 0xD00F3, 0x10C0000 };
u8 D_80800C68_chflowerbaddie [24] BT_DATA(4, overlays_ch_flowerbaddie, 0xF8) = { 0x3F, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x40, 0, 0, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0 };
f32 D_80800C80_chflowerbaddie [5] BT_DATA(4, overlays_ch_flowerbaddie, 0x110) = { 0.56f, 0.68f, 0.79f, 0.89f, -1.0f };
f32 D_80800C94_chflowerbaddie [5] BT_DATA(4, overlays_ch_flowerbaddie, 0x124) = { 0.0f, 0.25f, 0.5f, 0.75f, -1.0f };
u8 D_80800CA8_chflowerbaddie [24] BT_DATA(4, overlays_ch_flowerbaddie, 0x138) = { 0, 0, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0, 0, 0, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0 };
u8 D_80800CC0_chflowerbaddie [12] BT_DATA(4, overlays_ch_flowerbaddie, 0x150) = { 0, 0x13, 4, 0x84, 0, 0xD, 0, 0xF3, 1, 0xC, 0, 0 };
s32 D_80800CCC_chflowerbaddie[9] BT_DATA(4, overlays_ch_flowerbaddie, 0x15C) = { 1903069, 2228608, 33554944, 41943061, 153, 1638400, 458797, 3276900, 0 };
s32 D_80800CF0_chflowerbaddie[5] BT_DATA(4, overlays_ch_flowerbaddie, 0x180) = { 2818406, 26804238, 1966140, 2162560, -4325376 };
s32 D_80800D04_chflowerbaddie[5] BT_DATA(4, overlays_ch_flowerbaddie, 0x194) = { 2818457, 30146574, 3932260, 2130112, -4325376 };
s32 D_80800D18_chflowerbaddie[4] BT_DATA(4, overlays_ch_flowerbaddie, 0x1A8) = { 2818355, 23461920, -48928, 0 };
s32 D_80800D28_chflowerbaddie[6] BT_DATA(4, overlays_ch_flowerbaddie, 0x1B8) = { 50724883, 67043341, 19267904, 1456792, 196608, 0 };
