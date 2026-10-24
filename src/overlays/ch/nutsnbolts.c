#include "common.h"

OSThread *chnutsnbolts_entrypoint_0(void)
{
    extern u8 D_80800E28_chnutsnbolts[];

    return (OSThread *) D_80800E28_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_1(void)
{
    extern u8 D_80800E70_chnutsnbolts[];

    return (OSThread *) D_80800E70_chnutsnbolts;
}

OSThread *chnutsnbolts_entrypoint_2(void)
{
    extern u8 D_80800EB8_chnutsnbolts[];

    return (OSThread *) D_80800EB8_chnutsnbolts;
}

/* extern */

void func_80800024_chnutsnbolts(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    s32 func_8080092C_chnutsnbolts(Actor *, s32);
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    _subaddierouteDll_entrypoint_3(arg0, temp_v0 + 8, arg0->position);
    func_8080092C_chnutsnbolts(arg0, 2);
    (*(f32 *)((s8 *)(sp24) + (0x1C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
}

void func_80800080_chnutsnbolts(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefx_entrypoint_0(Actor *, s32, void *);
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
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
    u32 func_800F54E4(void);
    s32 func_800F6478(s32);
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
        u32 pad : 29;
        u32 disabled : 1;
        u32 tail : 2;
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nutsnbolts/func_808005D0_chnutsnbolts.s")

/* extern */

void func_808008FC_chnutsnbolts(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
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
        u32 flag31 : 1;
        u32 pad64 : 6;
        u32 flag24 : 1;
        u32 tail64 : 24;
        u32 pad68;
        u32 pad6C;
        u32 savedState : 7;
        u32 pad70 : 8;
        u32 flag16 : 1;
        u32 pad72 : 6;
        u32 state : 6;
        u32 pad73 : 4;
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
    }
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

void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
void func_80800B80_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    extern u32 D_80800F2C_chnutsnbolts;
    extern u32 D_80800F3C_chnutsnbolts;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 4);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[1], &D_80800CC0_chnutsnbolts, &D_80800F3C_chnutsnbolts);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800F2C_chnutsnbolts, 0.2f);
}

void func_80800BD4_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800CC0_chnutsnbolts, 0.65f);
}

void func_80800C04_chnutsnbolts(Actor *arg0) {
    extern u32 D_80800CC0_chnutsnbolts;
    extern u32 D_80800F48_chnutsnbolts;
    extern u32 D_80800F58_chnutsnbolts;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 4);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_80800F48_chnutsnbolts, 0.7f);
    _subaddieaudioquick_entrypoint_4(arg0, sp1C[1], &D_80800CC0_chnutsnbolts, &D_80800F58_chnutsnbolts);
}
