#include "ch/hellterskelter.h"

OSThread *chhellterskelter_entrypoint_0(void)
{
    extern u8 D_808007C8_chhellterskelter[];

    return (OSThread *) D_808007C8_chhellterskelter;
}

OSThread *chhellterskelter_entrypoint_1(void)
{
    extern u8 D_80800810_chhellterskelter[];

    return (OSThread *) D_80800810_chhellterskelter;
}

OSThread *chhellterskelter_entrypoint_2(void)
{
    extern u8 D_80800858_chhellterskelter[];

    return (OSThread *) D_80800858_chhellterskelter;
}

/* extern */

void func_80800024_chhellterskelter(u8 *arg0) {
    s32 _gccubesearch_entrypoint_0(s32, u8 *);
    s32 func_800EE88C(u8 *, s32);
    s32 func_80108B04(u8 *, s32);
    s32 sp24;
    s32 sp20;

    sp24 = _gccubesearch_entrypoint_0(0x154, arg0);
    sp20 = _gccubesearch_entrypoint_0(0x320, arg0);
    func_800EE88C(arg0 + 0x18, sp24);
    func_800EE88C(arg0 + 0x28, sp20);
    if (func_800DA298(FLAG3_A4B_UNK) != 0) {
        (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
        func_80108B04(arg0, 0x210);
    }
}

/* extern */

void func_808000A8_chhellterskelter(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chshockjump_entrypoint_2(Unk80132ED0 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    s32 func_80108B04();
    if (arg0->unk64_19 && (func_800DA298(FLAG3_A4B_UNK) == 0)) {
        if (func_800DA9E4(FLAG2_6A2_UNK, 1) == 0) {
            _capod_entrypoint_13(arg0->unk0, 0, 5, 0x10);
        }
        _chshockjump_entrypoint_2(arg0->unk3C);
        arg0->unk3C = 0;
        arg0->unk64_19 = 0;
    }
    if (func_800D90A4(&arg0->unk58) != 0) {
        func_80108B04(arg0, 0x33A);
        arg0->unk58 = func_800DC178(6.0f, 8.0f);
    }
}

s32 func_80800158_chhellterskelter(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _capod_entrypoint_17(f32);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    s32 func_80108B04();
    void func_80800680_chhellterskelter(Actor *, s32);

    switch (arg1) {
        case 0x3D:
            func_80800680_chhellterskelter(arg0, arg2);
            break;
        case 0xE:
            if (arg2 == 1 && _capod_entrypoint_17(0.9f)) {
                arg0->unk64_20 = 1;
                func_80108B04(arg0, 0x210);
            }
            return 3;
        case 0xA:
            if (func_800DA9E4(FLAG2_6A1_UNK, 1) == 0) {
                _capod_entrypoint_13(arg0->unk0, 0, 1, 0x10);
            } else {
                arg0->unk64_20 = 0;
                func_80108B04(arg0, 0x210);
            }
            break;
        case 0x95:
            if (arg0->unk3C == NULL) {
                _subaddiefind_entrypoint_10(arg0, 0x210, 0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800274_chhellterskelter(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG3_A4B_UNK);
}

void func_80800294_chhellterskelter(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x339, 0xA, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

void func_808002E8_chhellterskelter(s32 arg0) 
{
}
void func_808002F0_chhellterskelter(Actor *arg0) {
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    s32 func_800F6478(s32);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    void func_80105834(Actor *);
    void func_808004D0_chhellterskelter(Actor *);
    s32 func_8010CAC0(f32 *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioloop_entrypoint_5(Actor *, f32 *, s32, s32, s32 *);
    void *func_80105494(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80800540_chhellterskelter(Actor *volatile);
    void func_808005E0_chhellterskelter(Actor *);
    s32 func_80105998(Actor *, f32);
    s32 func_80105A5C(Actor *);
    void func_800FFAB0(Actor *);
    extern s32 D_808008A0_chhellterskelter;
    extern s32 D_808008AC_chhellterskelter;
    f32 sp3C;
    u32 sp38;
    s32 sp34;
    f32 *sp30;

    sp3C = arg0->position[1];
    sp38 = func_800F54E4();
    if (func_800F64A4(sp38, 0x8000) || !func_800F6478(sp38)) {
        func_800F4F34(sp38, arg0->position, 50.0f, 80.0f);
    }
    func_80105834(arg0);
    func_808004D0_chhellterskelter(arg0);
    if (!arg0->unk64_20) {
        if (func_8010CAC0(arg0->position, 400)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808008A0_chhellterskelter);
            arg0->unk64_20 = 1;
        }
    }
    switch (arg0->unk70_10) {
        case 1:
            sp34 = func_8010CAC0(arg0->position, 1500);
            sp30 = func_80105494(arg0);
            if (sp34 || (!sp34 && arg0->unk5F)) {
                _subaddieaudioloop_entrypoint_5(arg0, arg0->position, sp34, 1200, &D_808008AC_chhellterskelter);
            }
            if (sp30[3] > 0.94f) {
                func_80101FDC(arg0, 2);
            }
            break;
        case 2:
            if (sp3C > -110.0f && arg0->position[1] <= -110.0f) {
                func_80800540_chhellterskelter(arg0);
            }
            if (func_80105998(arg0, 0.985f)) {
                func_808005E0_chhellterskelter(arg0);
            }
            if (func_80105A5C(arg0)) {
                func_800FFAB0(arg0);
            }
            break;
    }
}

void func_808004D0_chhellterskelter(Actor *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DC298(f32);
    void *func_80105494();
    extern s32 D_808008C0_chhellterskelter;
    if (!((*(f32 *)((s8 *)(func_80105494()) + (0xC))) > 0.9f) && (func_800DC298(0.1f) != 0)) {
        func_800BBCB8(arg0->position, 0, 1.0f, 1, &D_808008C0_chhellterskelter);
    }
}

void func_80800540_chhellterskelter(Actor *volatile arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808008F4_chhellterskelter;
    extern s32 D_80800924_chhellterskelter;
    f32 sp24[3];
    f32 *sp20;

    sp20 = arg0->position;
    func_800EE7F8(sp24, sp20);
    sp24[1] -= 100.0f;
    func_800EF1B8(sp24, arg0->rotation[1] + 180.0f, 50.0f);
    func_800BBCB8(sp20, sp24, 1.0f, 0xA, &D_808008F4_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(arg0, sp20, &D_80800924_chhellterskelter);
}

void func_808005E0_chhellterskelter(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800938_chhellterskelter[];
    extern s32 D_80800974_chhellterskelter;
    f32 sp24[3];

    func_800EE7F8(sp24, arg0->position);
    sp24[1] -= 100.0f;
    func_800EF1B8(sp24, arg0->rotation[1] + 180.0f, 50.0f);
    func_800BABB8(0, arg0->position, sp24, 1.0f, D_80800938_chhellterskelter);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800974_chhellterskelter);
}

void func_80800680_chhellterskelter(Actor *arg0, s32 arg1)
{
  void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
  s32 _subaddiefade_entrypoint_2();
  void func_80102FDC(Actor *, f32);
  void func_80105A9C(Actor *, f32);
  Actor *func_80106790(Unk80132ED0 *);
  Actor *func_80108528(s32, f32 [3], s32, Actor **);
  Actor *func_8010856C(s32, f32 *, f32 *);
  f32 sp28[2];
  Actor *sp24;
  Unk80132ED0 *sp20;
  Actor *sp1C;
  if (arg1 != 0x210)
  {
    if (arg1 == 0x33A)
    {
 do { sp20 = arg0->unk0; sp28[0] = 0.0f; sp28[1] = arg0->rotation[1]; sp24 = func_8010856C(arg1, (f32 *) arg0->actorData, sp28); arg0 = func_80106790(sp20); func_80102FDC(sp24, arg0->scale); } while (0);
      func_80105A9C(sp24, 700.0f);
    }
  }
  else
  {
    sp1C = func_80108528(arg1, (f32 *) (&arg0->actorData[4]), 0, &arg0);
    func_80102FDC(sp1C, 0.7f);
    if (arg0->unk64_20 != 0)
    {
      _subaddiefade_entrypoint_2(sp1C);
      _chappearfx_entrypoint_1(sp1C, 0x22, 1, 1.0f);
    }
    arg0->unk64_20 = 0;
    arg0->unk64_19 = 1;
    arg0->unk3C = sp1C->unk0;
  }
}
