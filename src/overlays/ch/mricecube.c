#include "common.h"

OSThread *chmricecube_entrypoint_0(void)
{
    extern u8 D_80800928_chmricecube[];

    return (OSThread *) D_80800928_chmricecube;
}

/* extern */

void func_8080000C_chmricecube(u8 *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800FFAB0(u8 *);
    s32 func_80102424(u8 *, s32);
    s32 func_8010A5B0(u8 *, s32);
    func_800EE7F8(arg0 + 0x18, arg0 + 4);
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = (f32) (*(f32 *)((s8 *)(arg0) + (0x48)));
    func_8010A5B0(arg0, func_800DA298(0x1C9));
    if (_glcutDll_entrypoint_20() != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x48))) - 180.0f);
        func_80102424(arg0, 6);
        return;
    }
    if (func_800DA298(0x31B) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_808000AC_chmricecube(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_17(void);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddieaudioquick_entrypoint_2(Actor *, f32 *, u32 *);
    s32 _subaddiefade_entrypoint_1(Actor *, s32);
    void func_800C4AF0(f32 *, void *);
    f32 func_800D8FF8(void);
    u8 func_800D9078(f32 *);
    s32 func_800DA544(s32);
    s32 func_800EF1B8(f32 *, f32, f32);
    f32 func_800EFC7C(f32 *, f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80101DDC(Actor *);
    s32 func_80102424(u8 *, s32);
    void func_80102FDC(Actor *, f32);
    void func_80800778_chmricecube(s32);
    void func_808007B0_chmricecube(Actor *);
    void func_80800850_chmricecube(Actor *);
    extern u32 D_80800970_chmricecube;
    extern u32 D_80800980_chmricecube;
    extern u32 D_80800990_chmricecube;
    f32 sp3C;
    f32 sp38;
    s32 sp34;
    f32 sp30;

    switch (arg0->unk70_10) {
    case 1:
        func_80800778_chmricecube((s32)arg0);
        return;
    case 2:
        arg0->unk64_19 = 1;
        func_80800850_chmricecube(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80102424((u8 *)arg0, 3);
            return;
        }
    default:
        return;
    case 4:
        if (func_80101DDC(arg0) != 0) {
            arg0->unk64_19 = 0;
            func_80102424((u8 *)arg0, 1);
            return;
        }
        break;
    case 5:
        sp3C = func_800D8FF8();
        *(f32 *)&arg0->actorData[3] = func_800F15F8(*(f32 *)&arg0->actorData[3], 200.0f, sp3C * 150.0f);
        func_800EF1B8(arg0->position, arg0->unk54, -(*(f32 *)&arg0->actorData[3] * sp3C));
        arg0->unk64_19 = 1;
        *(f32 *)&arg0->actorData[6] = func_800F15F8(*(f32 *)&arg0->actorData[6], 100.0f, sp3C * 120.0f);
        arg0->rotation[1] += *(f32 *)&arg0->actorData[6] * sp3C;
        if (func_800EFC7C(arg0->position, (f32 *)arg0->actorData) > 160000.0f) {
            if (!arg0->unk64_20) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800970_chmricecube);
                arg0->unk64_20 = 1;
            }
            *(f32 *)&arg0->actorData[5] += sp3C * 800.0f;
            arg0->position[1] -= sp3C * *(f32 *)&arg0->actorData[5];
            if (arg0->position[1] < (*(f32 *)&arg0->actorData[1] - 8000.0f)) {
                _capod_entrypoint_14();
                _glcutDll_entrypoint_6(0x127, 0x49);
                return;
            }
        } else {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80800980_chmricecube);
            return;
        }
        break;
    case 8:
        sp38 = func_800D8FF8();
        *(f32 *)&arg0->actorData[6] = func_800F15F8(*(f32 *)&arg0->actorData[6], 100.0f, sp38 * 120.0f);
        *(f32 *)&arg0->actorData[5] += sp38 * 800.0f;
        arg0->position[1] -= sp38 * *(f32 *)&arg0->actorData[5];
        arg0->rotation[1] += *(f32 *)&arg0->actorData[6] * sp38;
        if (arg0->position[1] < 600.0f) {
            arg0->position[1] = 600.0f;
            func_800C4AF0(arg0->position, &D_80800990_chmricecube);
            func_80102424((u8 *)arg0, 9);
            arg0->unk58 = 4.0f;
            func_80101180(0x439, 0xA, 0x3E7);
            return;
        }
        break;
    case 9:
        sp34 = func_800D9078(&arg0->unk58);
        sp30 = func_800D8FF8();
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 4.0f, 400.0f, 600.0f);
        func_80102FDC(arg0, func_800F12D4(arg0->unk58, 0.0f, 4.0f, 0.5f, 1.0f));
        _subaddiefade_entrypoint_1(arg0, (s32)func_800F12D4(arg0->unk58, 0.0f, 4.0f, 0, 255.0f));
        if (arg0->unk58 > 1.0f) {
            *(f32 *)&arg0->actorData[6] = func_800F15F8(*(f32 *)&arg0->actorData[6], 0.0f, sp30 * 40.0f);
            func_808007B0_chmricecube(arg0);
        }
        arg0->rotation[1] += *(f32 *)&arg0->actorData[6] * sp30;
        if (sp34 != 0) {
            func_800DA544(0x31B);
            _glcutDll_entrypoint_17();
            return;
        }
        break;
    case 6:
        func_80800850_chmricecube(arg0);
        arg0->unk64_19 = 1;
        if (func_80101DDC(arg0) != 0) {
            func_80102424((u8 *)arg0, 7);
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mricecube/func_8080050C_chmricecube.s")

/* extern */

void func_80800734_chmricecube(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void *, s32);
    func_800DF744(3, (u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) << 0xC) >> 0x1F);
    func_80101870(arg0, arg1);
}

void func_80800778_chmricecube(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808008B0_chmricecube;
    extern s32 D_808009B8_chmricecube;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_808009B8_chmricecube, &D_808008B0_chmricecube, 5);
}

void func_808007B0_chmricecube(Actor *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808009C8_chmricecube;
    f32 sp34[3];
    f32 sp28[3];

    if (func_800D90A4((f32 *)arg0->actorData + 4) != 0) {
        func_800EE7F8(sp34, arg0->position);
        sp34[1] = 200.0f;
        func_800EE7F8(sp28, arg0->position);
        sp28[1] = 600.0f;
        func_800BBCB8(sp28, sp34, arg0->scale, 5, &D_808009C8_chmricecube);
        ((f32 *)arg0->actorData)[4] = func_800DC178(0.1f, 0.15f);
    }
}

void func_80800850_chmricecube(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800A00_chmricecube;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800A00_chmricecube, 0.1f);
}
