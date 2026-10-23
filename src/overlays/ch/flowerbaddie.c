#include "common.h"

OSThread *chflowerbaddie_entrypoint_0(void)
{
    extern u8 D_80800C14_chflowerbaddie[];

    return (OSThread *) D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800380_chflowerbaddie.s")

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
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_80103DFC(Actor *, f32 *);
    extern s32 D_80800CCC_chflowerbaddie;
    extern s32 D_80800CF0_chflowerbaddie;
    extern s32 D_80800D04_chflowerbaddie;
    extern s32 D_80800D18_chflowerbaddie;
    f32 sp34[3];
    s32 emitter;

    func_80103DFC(arg0, sp34);
    emitter = func_800B53A4(1);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800D18_chflowerbaddie);
    func_800BA22C(emitter, 1);
    emitter = func_800B53A4(2);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CF0_chflowerbaddie);
    func_800BA22C(emitter, 2);
    emitter = func_800B53A4(4);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800CCC_chflowerbaddie);
    func_800BABB8(emitter, sp34, sp34, arg0->scale, &D_80800D04_chflowerbaddie);
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
    u8 func_800C4350(s32, f32[3], s32 *);
    s32 func_80101E4C(Actor *, f32 *);
    extern s32 D_80800D28_chflowerbaddie;

    if (func_80101E4C(arg0, arg1) != 0) {
        if (arg0->unk5F == 0) {
            arg0->unk5F = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
            func_800C4350(arg0->unk5F, arg0->position, &D_80800D28_chflowerbaddie);
        }
        func_800C3BDC(arg0->unk5F);
    }
}

s32 func_808009F0_chflowerbaddie(Actor *arg0, void *arg1, f32 arg2) {
    void _subaddieaudioloop_entrypoint_2(Actor *);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    void _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
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
