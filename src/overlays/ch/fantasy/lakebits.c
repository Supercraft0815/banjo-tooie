#include "common.h"

/* extern */

void chfantasylakebits_entrypoint_0(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    Vtx *end;

    actor = func_80106790(arg4);
    end = arg2 + arg3;
    if (arg2 < end) {
        do {
            arg2->v.cn[0] = 255;
            arg2->v.cn[1] = 255;
            arg2->v.cn[2] = 0;
            arg2++;
            arg1++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + actor->actorData[3];
        } while (arg2 < end);
    }
}

void func_8080007C_chfantasylakebits(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800D90A4(f32 *);
    int func_800D91EC(f32 *, f32);
    int func_800DB9B0(void);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F8418(s32, f32 *);
    void func_80800300_chfantasylakebits(s32, s16);
    extern u32 D_80800920_chfantasylakebits[];
    extern u32 D_80800928_chfantasylakebits[];
    extern f32 D_80800934_chfantasylakebits[];
    extern s32 D_80800940_chfantasylakebits[];
    extern s32 D_80800980_chfantasylakebits[];
    extern f32 D_808009B8_chfantasylakebits[];
    extern f32 D_808009C4_chfantasylakebits[];
    extern f32 D_808009D0_chfantasylakebits[];
    extern s32 D_808009DC_chfantasylakebits[];
    s16 sp2E;

    switch (arg0->unk70_10) {
    case 2:
        if (func_800DB9B0() == 0) {
            _capod_entrypoint_13(arg0->unk0, NULL, 0x23, 0x30);
        }
        func_800D91EC(&arg0->unk58, 12.0f);
        func_80800300_chfantasylakebits((s32)arg0, (s16)(s32)func_800F10B4(arg0->unk58, 0.0f, 12.0f, 0, -3200.0f));
        _subaddieaudioloop_entrypoint_4(arg0, D_80800934_chfantasylakebits, 1, D_80800920_chfantasylakebits);
        break;
    case 3:
        if (arg0->unk58 < 6.0f) {
            func_800BBCB8(D_80800934_chfantasylakebits, D_80800934_chfantasylakebits, 1.0f, 2, D_80800940_chfantasylakebits);
        }
        func_800D91EC(&arg0->unk58, 12.0f);
        sp2E = (s16)(s32)func_800F10B4(arg0->unk58, 0.0f, 12.0f, 0, -3200.0f);
        _subaddieaudioloop_entrypoint_4(arg0, D_80800934_chfantasylakebits, 1, D_80800920_chfantasylakebits);
        func_80800300_chfantasylakebits((s32)arg0, sp2E);
        break;
    case 4:
        func_800BBCB8(D_808009B8_chfantasylakebits, NULL, 1.0f, 2, D_80800980_chfantasylakebits);
        func_800D90A4(&((f32 *)arg0->actorData)[7]);
        func_800EFE50(arg0->position, D_808009C4_chfantasylakebits, D_808009D0_chfantasylakebits, func_800F10B4(((f32 *)arg0->actorData)[7], 5.0f, 0.0f, 0.0f, 1.0f));
        arg0->unk54 = func_800F10B4(((f32 *)arg0->actorData)[7], 5.0f, 0.0f, 1.0f, 2.0f);
        _subaddieaudioloop_entrypoint_4(arg0, D_80800934_chfantasylakebits, 1, D_80800928_chfantasylakebits);
        _subaddieaudioloop_entrypoint_0(arg0, 1.0f);
        if (((f32 *)arg0->actorData)[7] > 2.0f) {
            func_800BBCB8(D_808009B8_chfantasylakebits, NULL, 1.0f, 1, D_808009DC_chfantasylakebits);
        }
        func_800F8418(func_800F54E4(), &((f32 *)arg0->actorData)[4]);
        break;
    }
}

/* extern */

void func_80800300_chfantasylakebits(s32 arg0, s16 arg1) {
    s32 _idwibble_entrypoint_5(s32, s16);
    s32 _idworld_entrypoint_4(s32, s32);
    s32 func_800BEA88(s32);
    s32 temp_v0;

    temp_v0 = _idworld_entrypoint_4(func_800BEA88(1), 1);
    if (temp_v0 != 0) {
        _idwibble_entrypoint_5(temp_v0, arg1);
    }
}

void func_80800344_chfantasylakebits(Actor *arg0, s32 arg1) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, Unk80132ED0 *);
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 _subaddieDll_entrypoint_0(Actor *);
    void _subaddieaudioloop_entrypoint_2(Actor *);
    s32 func_800BEA88(s32);
    void func_800BF744(s32, s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800EA05C();
    u32 func_800F54E4(void);
    f32 func_800F5628(s32);
    void func_800F5A00(s32, f32 *);
    void func_800F9C38(void);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A800(Actor *, s32);
    extern s32 _chfantasylakebits_entrypoint_0;
    s32 sp2C;
    s32 temp_v0;
    s32 sp24;
    s32 pad;

    switch (arg1) {
    case 1:
        sp2C = func_800BEA88(1);
        arg0->unk58 = 0.0f;
        func_800BF744(1, 1);
        arg0->actorData[3] = 0;
        _idworldmake_entrypoint_1(sp2C, 0x654, 1, 1);
        _glid_entrypoint_0(sp2C, 1, &_chfantasylakebits_entrypoint_0, arg0->unk0);
        if (func_800EA05C() == 0x13A) {
            temp_v0 = func_800BEA88(0);
            arg0->actorData[3] = 0;
            _idworldmake_entrypoint_1(temp_v0, 0x59B, 2, 1);
        }
        arg0->unk64_16 = 0;
        func_80103110(arg0, 0);
        break;
    case 2:
        func_800F9C38();
        func_80103110(arg0, 1);
        arg0->unk58 = 0.0f;
        _subaddieDll_entrypoint_0(arg0);
        arg0->unk54 = 1.0f;
        func_80103140(arg0, 0x8DE, arg0->unk0->unk16);
        break;
    case 3:
        func_8010A800(arg0, 2);
        func_800F5A00(func_800F54E4(), &((f32 *)arg0->actorData)[4]);
        ((f32 *)arg0->actorData)[5] = func_800F5628(func_800F54E4());
        break;
    case 4:
        func_800BF744(1, 0);
        arg0->unk64_16 = 1;
        ((f32 *)arg0->actorData)[7] = 5.0f;
        _subaddieaudioloop_entrypoint_2(arg0);
        break;
    case 5:
        sp24 = func_800BEA88(1);
        func_800BF744(1, 0);
        arg0->actorData[3] = -0xC80;
        _glid_entrypoint_0(sp24, 1, &_chfantasylakebits_entrypoint_0, arg0->unk0);
        _idworldmake_entrypoint_1(sp24, 0x654, 1, 1);
        func_800DA544(0x327);
        func_800DA524(0x9FC);
        arg0->unk64_16 = 0;
        _subaddieaudioloop_entrypoint_2(arg0);
        func_800FFAB0(arg0);
        break;
    }
    func_80101FDC(arg0, arg1);
}

s32 func_80800570_chfantasylakebits(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 func_800DA298(s32);
    void func_800DF500(f32, f32, f32);
    void func_800E3980(f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_801015D0(Actor *);
    f32 sp24[3];

    switch (arg1) {
    case 0xB:
        if (arg2 == 0x23) {
            _capod_entrypoint_14();
            func_80800344_chfantasylakebits(arg0, 5);
            _glcutDll_entrypoint_6(0x112, 0x36);
            return 4;
        }
        return 3;
    case 0xC:
        if (arg0->unk70_10 == 2) {
            func_80800344_chfantasylakebits(arg0, 3);
            return 3;
        }
        if (arg0->unk70_10 == 3) {
            func_80800344_chfantasylakebits(arg0, 4);
        }
        return 3;
    case 0x36:
        func_80800344_chfantasylakebits(arg0, 2);
        return 1;
    case 0x1F:
        if (arg0->unk64_16) {
            func_801015D0(arg0);
            func_800E3980(sp24);
            arg0->rotation[1] = func_800F1DF4(arg0->position, sp24);
            func_800DF500(arg0->unk54, 4.0f, arg0->unk54);
        }
        return 1;
    case 0x95:
        if (func_800DA298(0x327)) {
            func_80800344_chfantasylakebits(arg0, 5);
            return 1;
        }
        func_80800344_chfantasylakebits(arg0, 1);
        return 1;
    default:
        return 0;
    }
}

OSThread *chfantasylakebits_entrypoint_1(void)
{
    extern u8 D_80800A30_chfantasylakebits[];

    return (OSThread *) D_80800A30_chfantasylakebits;
}

/* extern */

void func_808006F4_chfantasylakebits(s32 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    if ((func_800DA298(0x327) != 0) || (func_800DA298(0x9FC) != 0)) {
        func_800FFA88(*arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/lakebits/func_8080073C_chfantasylakebits.s")

OSThread *chfantasylakebits_entrypoint_2(void)
{
    extern u8 D_80800AF0_chfantasylakebits[];

    return (OSThread *) D_80800AF0_chfantasylakebits;
}
