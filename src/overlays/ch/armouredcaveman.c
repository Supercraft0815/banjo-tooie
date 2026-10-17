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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_808000EC_charmouredcaveman.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_8080072C_charmouredcaveman.s")

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
