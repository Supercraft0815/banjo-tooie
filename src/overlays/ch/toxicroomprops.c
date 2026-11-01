#include "common.h"

void func_80800000_chtoxicroomprops(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _chmrtannoy_entrypoint_0(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_6(Actor *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA450(s32, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 func_800DC0C0(void);
    f32 func_800F1214(f32, f32, f32);
    void func_80103110(Actor *, u32);
    void func_80800390_chtoxicroomprops(u8 *, f32);
    typedef struct { f32 values[3]; } Position;
    extern Position D_808009A0_chtoxicroomprops;
    extern s32 D_808009AC_chtoxicroomprops[];
    Actor *sp4C;
    Position sp40;
    s32 sp3C;
    s32 second;
    s32 first;

    switch (arg0->unk70_10) {
    case 1:
        func_80103110(arg0, 0);
        break;
    case 2:
        sp4C = _subaddiefind_entrypoint_2(0x178, 0);
        if (!arg0->unk74_30 && arg0->rotation[1] == 193.0f) {
            arg0->unk74_30 = 1;
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x133D, 7, arg0->position, 0xA3);
        }
        if (func_800DC0C0() < 0.1f && _subaddiefade_entrypoint_0(sp4C) >= 0x51) {
            sp40 = D_808009A0_chtoxicroomprops;
            sp3C = func_800B53A4(1);
            func_800BABB8(sp3C, sp40.values, 0, 10.0f, D_808009AC_chtoxicroomprops);
            first = arg0->rotation[1] == 193.0f ? (s32)func_800F1214(((f32 *)arg0->actorData)[3], 0.0f, 450.0f) * 10 : -((s32)func_800F1214(((f32 *)arg0->actorData)[3], 0.0f, 450.0f) * 10);
            second = arg0->rotation[1] == 193.0f ? (s32)func_800F1214(((f32 *)arg0->actorData)[3], 0.0f, 450.0f) * 10 : -((s32)func_800F1214(((f32 *)arg0->actorData)[3], 0.0f, 450.0f) * 10);
            func_800BA450(sp3C, 0, 0, first, 0, 0, second);
            func_800BA22C(sp3C, 1);
        }
        if (!func_800DA298(0x1BC) && arg0->rotation[1] == 193.0f) {
            func_800DA544(0x1BC);
            _capod_entrypoint_13(arg0->unk0, 0, 0, 0x800);
        }
        func_80800390_chtoxicroomprops((u8 *)arg0, 2.0f);
        if (((f32 *)arg0->actorData)[3] >= 450.0f && _subaddiefade_entrypoint_0(sp4C) && arg0->rotation[1] == 193.0f) {
            _subaddiefade_entrypoint_6(sp4C, -1);
        }
        break;
    }
}

s32 func_8080030C_chtoxicroomprops(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DA524(s32);
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    void _glcutDll_entrypoint_17(void);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0xB:
            func_800DA524(0xA04);
            func_800DA524(0x1BD);
            _subaddieaudioloop_entrypoint_2((u8 *)arg0);
            _glcutDll_entrypoint_17();
            return 3;
        case 0x49:
            if (arg2 == 0x41) {
                func_80101FDC(arg0, 2);
                return 1;
            }
            return 0;
        default:
            return 0;
    }
}

void func_80800390_chtoxicroomprops(u8 *arg0, f32 arg1) {
    void _subaddieaudioloop_entrypoint_0(u8 *arg0, f32 arg1);
    void _subaddieaudioloop_entrypoint_1(u8 *arg0, s32 sample_rate);
    s32 _subaddieaudioloop_entrypoint_4(Actor *arg0, f32 *arg1, u32 arg2, u32 *arg3);
    f32 func_800136E4(f32);
    void func_800C4140(u32 arg0, f32 *arg1, u32 arg2);
    f32 func_800D8FF8();
    f32 func_800DC178(f32 arg0, f32 arg1);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    f32 func_800F13C4(f32 arg0, f32 arg1);
    extern u32 D_808009E0_chtoxicroomprops;
    ((f32 *)((Actor *)arg0)->actorData)[3] += arg1;
    if (((f32 *)((Actor *)arg0)->actorData)[3] > 450.0f) {
        ((f32 *)((Actor *)arg0)->actorData)[3] = 450.0f;
    }
    ((Actor *)arg0)->unk54 = ((Actor *)arg0)->rotation[2];
    ((Actor *)arg0)->rotation[2] = func_800136E4(((Actor *)arg0)->rotation[2] + ((f32 *)((Actor *)arg0)->actorData)[3] * func_800D8FF8());
    if (((f32 *)((Actor *)arg0)->actorData)[3] > 45.0f) {
        if (func_800F13C4(((Actor *)arg0)->unk54, 90.0f) > func_800F13C4(((Actor *)arg0)->rotation[2], 90.0f)) {
            func_800C4140(((((s32)((f32)(s32)func_800F10B4(((f32 *)((Actor *)arg0)->actorData)[3], 45.0f, 450.0f, 18000.0f, 24000.0f) * 0.5f) >> 5) & 0x3FF) << 11) + (((u32)((func_800F10B4(((f32 *)((Actor *)arg0)->actorData)[3], 45.0f, 450.0f, 0.3f, 0.6f) + func_800DC178(-0.02f, 0.02f)) * 1023.0f) & 0x7FF) << 21) + 0x3FF, ((Actor *)arg0)->position, 0x0BB800C8);
        }
        _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4(((f32 *)((Actor *)arg0)->actorData)[3], 45.0f, 450.0f, 0.2f, 0.5f));
        _subaddieaudioloop_entrypoint_1(arg0, (s32)func_800F10B4(((f32 *)((Actor *)arg0)->actorData)[3], 45.0f, 450.0f, 18000.0f, 24000.0f));
        _subaddieaudioloop_entrypoint_4((Actor *)arg0, ((Actor *)arg0)->position, 1, &D_808009E0_chtoxicroomprops);
    }
}

OSThread *chtoxicroomprops_entrypoint_0(void)
{
    extern u8 D_808009E8_chtoxicroomprops[];

    return (OSThread *) D_808009E8_chtoxicroomprops;
}

void func_80800650_chtoxicroomprops(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x4C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 10.0f;
}

/* extern */

void func_80800670_chtoxicroomprops(u8 *arg0) {
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    s32 func_800D90A4(s32);
    s32 func_800FFA88(s32);
    void func_80800390_chtoxicroomprops(u8 *, f32);
    if (func_800D90A4(arg0 + 0x58) != 0) {
        func_80800390_chtoxicroomprops(arg0, -2.0f);
        if ((*(f32 *)((s8 *)(arg0) + (0x24))) < 45.0f) {
            _subaddieaudioloop_entrypoint_2(arg0);
            (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.0f;
            func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
        }
    } else {
        func_80800390_chtoxicroomprops(arg0, 4.0f);
    }
}

OSThread *chtoxicroomprops_entrypoint_1(void)
{
    extern u8 D_80800A30_chtoxicroomprops[];

    return (OSThread *) D_80800A30_chtoxicroomprops;
}

/* extern */

void func_80800700_chtoxicroomprops(void *arg0) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    if (func_800DA298(0x1BD) == 0) {
        func_80101FDC(arg0, 3);
        return;
    }
    func_80101FDC(arg0, 1);
}

void func_80800758_chtoxicroomprops(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D90A4();
    s32 func_800DA298(s32);
    void func_800E148C(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    f32 func_80103EF4(Actor *);
    extern u8 D_80800A78_chtoxicroomprops[];
    f32 *position;

    switch (arg0->unk70_10) {
        case 1:
            if (func_800DA298(0xA04) || !func_800DA298(0x1BD)) {
                func_80101FDC(arg0, 2);
                ((f32 *)arg0->actorData)[4] = 8.0f;
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6];
            break;
        case 2:
            if (func_800D90A4(&((f32 *)arg0->actorData)[4])) {
                func_80101FDC(arg0, 3);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_800F10B4(((f32 *)arg0->actorData)[4], 8.0f, 0.0f, 0.0f, func_80103EF4(arg0) * 0.9f);
            break;
        case 3:
            if (func_800DA298(0x1BD) && !func_800DA298(0xA04)) {
                func_80101FDC(arg0, 4);
                ((f32 *)arg0->actorData)[4] = 0.5f;
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800A78_chtoxicroomprops);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_80103EF4(arg0) * 0.9f;
            break;
        case 4:
            if (func_800D90A4(&((f32 *)arg0->actorData)[4])) {
                position = arg0->position;
                func_800E148C(func_800E1610(2, 200.0f, 0.85f, position), 1000.0f, 4000.0f);
                func_80101FDC(arg0, 1);
                _subaddieaudioquick_entrypoint_2(arg0, position, D_80800A78_chtoxicroomprops);
            }
            arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_800F10B4(((f32 *)arg0->actorData)[4], 0.5f, 0.0f, func_80103EF4(arg0) * 0.9f, 0.0f);
            break;
    }
}

OSThread *chtoxicroomprops_entrypoint_2(void)
{
    extern u8 D_80800A84_chtoxicroomprops[];

    return (OSThread *) D_80800A84_chtoxicroomprops;
}
