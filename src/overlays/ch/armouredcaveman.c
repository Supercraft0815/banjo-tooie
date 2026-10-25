#include "common.h"

OSThread *charmouredcaveman_entrypoint_0(void)
{
    extern u8 D_80800B20_charmouredcaveman[];

    return (OSThread *) D_80800B20_charmouredcaveman;
}

/* extern */

void func_8080000C_charmouredcaveman(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_8010B990(Actor *, s32);
    s32 temp_v0;

    temp_v0 = arg0->unk74_7 - 0x32;
    arg0->actorData[5] = temp_v0;
    arg0->actorData[4] = temp_v0 + 0x17A;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 7);
        goto block_9;
    }
    if (func_800DA298(0x5D) != 0) {
        if ((func_800DA564(0x17A, 5) == arg0->actorData[5]) && (func_800D0B68(0x31, 1) == 0)) {
            func_800D1000(0x31, 1, arg0->position, 3, NULL);
        }
        func_800FFAB0(arg0);
        return;
    }
    if (func_800DA298(arg0->actorData[4]) != 0) {
        func_800FFAB0(arg0);
        return;
    }
block_9:
    func_8010B990(arg0, 0x1000);
}

void func_808000EC_charmouredcaveman(Actor *arg0) {
    typedef struct {
        u8 prefix[0x74];
        u32 pad74_21 : 11;
        u32 unk74_20 : 1;
        u32 pad74_0 : 20;
    } ArmouredCavemanFlags;
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 _subaddiefade_entrypoint_5();
    s32 _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_8010C9B0(f32 *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_8010D23C(void);
    s32 func_8010D278();
    void func_80800640_charmouredcaveman(Actor *);
    void func_8080072C_charmouredcaveman(Actor *);
    void func_808008B0_charmouredcaveman(Actor *);
    void func_8080092C_charmouredcaveman(Actor *);
    void func_8080095C_charmouredcaveman(Actor *);
    void func_808009D4_charmouredcaveman(Actor *);
    s32 sp34;
    s32 sp30;
    s32 deflected;
    s32 state;

    sp34 = 1;
    sp30 = func_8010D23C();
    deflected = 0;
    if (arg0->unk70_10 != 6) {
        deflected = _sudeflect_entrypoint_1(arg0->position, 250.0f, -10.0f, 140.0f, 10) & 8;
    }
    switch (arg0->unk70_10) {
    case 1:
        func_80800640_charmouredcaveman(arg0);
        if (deflected) {
            func_808009D4_charmouredcaveman(arg0);
        }
        if (sp30 && func_8010D278() != 0x11 && func_8010C9B0(arg0->position, 400)) {
            arg0->unk64_19 = 0;
            func_80102424(arg0, 4);
        }
        break;
    case 2:
        func_80800640_charmouredcaveman(arg0);
        sp34 = 0;
        break;
    case 3:
        func_8080072C_charmouredcaveman(arg0);
        if (func_80101DDC(arg0)) {
            state = arg0->unk64_20 ? 2 : 1;
            func_80102424(arg0, state);
        }
        break;
    case 4:
        func_808008B0_charmouredcaveman(arg0);
        if (func_80101DDC(arg0)) {
            if (arg0->unk64_19) {
                func_8080095C_charmouredcaveman(arg0);
            } else {
                func_80102424(arg0, 1);
            }
        }
        break;
    case 5:
        sp34 = 0;
        func_8080092C_charmouredcaveman(arg0);
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 6);
            _subaddiefade_entrypoint_5(arg0);
        }
        break;
    case 6:
        sp34 = 0;
        state = _subaddiefade_entrypoint_0(arg0) == 0 ? 0 : 1;
        arg0->unk64_16 = state; ((ArmouredCavemanFlags *)arg0)->unk74_20 = state;
        break;
    case 7:
        func_8080072C_charmouredcaveman(arg0);
        break;
    }
    if (sp34 && sp30) {
        if (func_8010D278() != 0x11) {
            arg0->unk54 = func_8010CD28(arg0);
        }
        func_80102BF8(arg0, 0.3f, 3.0f, 300.0f);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_80800370_charmouredcaveman.s")

void func_80800640_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800B78_charmouredcaveman;
    extern u32 D_80800BA4_charmouredcaveman, D_80800BB0_charmouredcaveman, D_80800BBC_charmouredcaveman;
    s32 sp44;
    f32 sp38[3];
    f32 sp2C[3];
    sp44 = _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_80800BA4_charmouredcaveman, &D_80800BBC_charmouredcaveman);
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800BB0_charmouredcaveman, 0.83f);
    if (sp44 && arg0->unk7C_12) {
    func_800EE7F8(sp38, arg0->position);
    sp38[1] += arg0->scale * 180.0f;
    func_800EE7F8(sp2C, sp38);
    sp2C[1] -= arg0->scale * 10.0f;
    func_800BBCB8(sp38, sp2C, 1.0f, 8, &D_80800B78_charmouredcaveman);
    }
}

void func_8080072C_charmouredcaveman(Actor *arg0) {
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    typedef struct { f32 values[4]; } FloatTable;
    typedef struct { s16 values[4]; } ShortTable;
    extern FloatTable D_80800BCC_charmouredcaveman;
    extern FloatTable D_80800BDC_charmouredcaveman;
    extern ShortTable D_80800BEC_charmouredcaveman;
    extern ShortTable D_80800BF4_charmouredcaveman;
    extern s32 D_80800BFC_charmouredcaveman;
    FloatTable times = D_80800BCC_charmouredcaveman;
    FloatTable volumes = D_80800BDC_charmouredcaveman;
    ShortTable sounds = D_80800BEC_charmouredcaveman;
    ShortTable rates = D_80800BF4_charmouredcaveman;
    s32 i;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &D_80800BFC_charmouredcaveman);
    }
    for (i = 0; i < 4; i++) {
        if (func_80101E14(arg0, times.values[i])) {
            func_800C301C(arg0->unk5F, sounds.values[i]);
            func_800C31DC(arg0->unk5F, volumes.values[i] + func_800DC178(-0.02f, 0.02f));
            func_800C3058(arg0->unk5F, rates.values[i]);
            func_800C3BDC(arg0->unk5F);
            return;
        }
    }
}

void func_808008B0_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_80800C08_charmouredcaveman, D_80800C14_charmouredcaveman;
    f32 *position[1];

    position[0] = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, position[0], &D_80800C08_charmouredcaveman, 0.3f);
    if (_subaddieaudioquick_entrypoint_3(arg0, position[0], &D_80800C14_charmouredcaveman, 0.5f)) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 20.0f, 0.85f);
    }
}

void func_8080092C_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800C20_charmouredcaveman;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800C20_charmouredcaveman, 0.1f);
}

/* extern */

void func_8080095C_charmouredcaveman(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    arg0->unk64_19 = 0;
    if (func_800DA298(0x66C) == 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E2, 0xE, arg0->position, 0xA6);
        arg0->unk64_20 = 1;
        func_8010A570(arg0);
    }
    func_80102424(arg0, 3);
}

/* extern */

void func_808009D4_charmouredcaveman(Actor *arg0) {
    void func_8080095C_charmouredcaveman(Actor *);
    if (arg0->unk70_10 != 3) {
        if (arg0->unk70_10 == 4) {
            arg0->unk64_19 = 1;
            return;
        }
        func_8080095C_charmouredcaveman(arg0);
    }
}
