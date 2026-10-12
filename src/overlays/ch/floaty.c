#include "common.h"

OSThread *chfloaty_entrypoint_0(void)
{
    extern u8 D_80800E00_chfloaty[];

    return (OSThread *) D_80800E00_chfloaty;
}

s32 func_8080000C_chfloaty(s32 arg0, s32 arg1, s32 arg2) {
    return 1;
}

void func_80800020_chfloaty(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, *((s32 *) (((s8 *) arg1) + 0)), *((s32 *) (((s8 *) arg1) + 4)), *((s32 *) (((s8 *) arg1) + 8)), arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_8080007C_chfloaty.s")

void func_80800118_chfloaty(Actor *arg0)
{
    s32 _plsu_entrypoint_3(Unk80132ED0 *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddietaxi_entrypoint_5(Actor *, s32);
    f32 func_80013970(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    f32 func_8010CD28(Actor *);
    s32 func_80102BAC(Actor *, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    void func_800C4140(s32, f32 *, s32);
    void func_800E0B8C(void *, u8, f32, f32, f32, f32);
    void *func_8010262C(Unk80132ED0 *, s32);
    void func_8010C964(Actor *);
    void func_808006AC_chfloaty(Actor *, s32);
    void func_80800BD8_chfloaty(s32, s32);
    s32 index;
    f32 scale;
    f32 first;
    f32 second;
    void *model;
    f32 t;

    switch (arg0->unk70_10) {
        case 1:
            index = _plsu_entrypoint_3(arg0->unk0);
            if (index != -1) {
                func_800F7BC8(index, 0x53, arg0->unk0);
            }
            break;
        case 2:
            if (func_80101E14(arg0, 0.47f)) {
                func_80108B04(arg0, 0);
                func_800C4140(0x7FFB5D61, arg0->position, 0x04B000FA);
            }
            if (func_80101DDC(arg0)) {
                func_800FFA88(arg0->unk0);
            }
            break;
        case 3:
            if (func_800D90A4(&arg0->unk50)) {
                if (!func_800DA298(0x340)) {
                    func_800DA544(0x340);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1431, 0xE, arg0->position, 0x6F);
                }
                func_808006AC_chfloaty(arg0, 4);
            } else {
                scale = func_800F10B4(arg0->unk50, 1.5f, 0.0f, 0.01f, 1.0f);
                first = func_800F10B4(arg0->unk50, 1.5f, 0.75f, 0.0f, 1.0f);
                second = func_800F10B4(arg0->unk50, 0.75f, 0.0f, 0.0f, 1.0f);
                scale = mlAbsF(func_80013970(scale * 720.0f) * 0.25f) + scale;
                first = mlAbsF(func_80013970(first * 180.0f) * 2.0f) + first;
                second = mlAbsF(func_80013970(second * 180.0f) * 2.0f) + second;
                model = func_8010262C(arg0->unk0, 8);
                if (model != NULL) {
                    func_800E0B8C(model, 0x2A, -1.0f, first, first, first);
                    func_800E0B8C(model, 0x2D, -1.0f, second, second, second);
                    func_800E0B8C(model, 0x30, -1.0f, first, first, first);
                    func_800E0B8C(model, 0x33, -1.0f, second, second, second);
                    func_800E0B8C(model, 0x39, -1.0f, first, first, first);
                    func_800E0B8C(model, 0x3C, -1.0f, second, second, second);
                    func_800E0B8C(model, 0x3F, -1.0f, first, first, first);
                    func_800E0B8C(model, 0x36, -1.0f, second, second, second);
                }
                arg0->scale = scale;
            }
            func_80800BD8_chfloaty((s32)arg0, 1);
            func_8010C964(arg0);
            break;
        case 4:
            if (func_800F64A4(func_800F54E4(), 0xA)) {
                if (!func_800DA298(0x6DD) && _subaddiedialog_entrypoint_4(arg0->position, 500, 0)) {
                    func_800DA544(0x6DD);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1432, 0xE, arg0->position, 0x6F);
                }
            } else {
                if (!func_800DA298(0x6DE) && _subaddiedialog_entrypoint_4(arg0->position, 500, 0)) {
                    func_800DA544(0x6DE);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1433, 0xE, arg0->position, 0x6F);
                }
            }
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BAC(arg0, 0.1f, 0.5f, 8.0f);
            func_8010C964(arg0);
            func_80800BD8_chfloaty((s32)arg0, 1);
            break;
        case 6:
            if (func_800D90A4((f32 *)&arg0->actorData[3])) {
                _subaddieDll_entrypoint_4(arg0, 0);
                _subaddietaxi_entrypoint_5(arg0, arg0->unk74_7 - 0x25);
                func_808006AC_chfloaty(arg0, 4);
            } else if (*(f32 *)&arg0->actorData[3] >= 7.0f) {
                t = func_800F12D4(*(f32 *)&arg0->actorData[3], 8.0f, 7.0f, 0.0f, 1.0f);
                arg0->scale = t / 2.0f + 0.5f;
                func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4], (f32 *)&arg0->actorData[0], t);
                arg0->position[1] += func_80013970(t * 180.0f) * 100.0f;
            }
            if (*(f32 *)&arg0->actorData[3] < 1.0f) {
                arg0->alpha = (s32)func_800F12D4(*(f32 *)&arg0->actorData[3], 1.0f, 0.0f, 255.0f, 0.0f);
            }
            func_8010C964(arg0);
            func_80800BD8_chfloaty((s32)arg0, 1);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_808006AC_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_8080090C_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800B68_chfloaty.s")

void func_80800BD8_chfloaty(s32 arg0, s32 arg1) {
    s32 func_8001210C(s32);
    s32 func_800B5BE4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    s32 func_80800CA0_chfloaty(s32);
    extern s32 D_80800EA8_chfloaty;
    s32 sp24;
    s32 temp_a1;
    s32 temp_v0;

    if (func_8001210C(1) != 0) {
        temp_v0 = func_800B5BE4(0x1C);
        temp_a1 = arg0 + 4;
        sp24 = temp_v0;
        func_800BABB8(temp_v0, temp_a1, temp_a1, 0x3F800000, &D_80800EA8_chfloaty);
        func_800BA22C(sp24, arg1);
    }
    func_80800CA0_chfloaty(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800C4C_chfloaty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/floaty/func_80800CA0_chfloaty.s")

OSThread *chfloaty_entrypoint_1(void)
{
    extern u8 D_80800EF0_chfloaty[];

    return (OSThread *) D_80800EF0_chfloaty;
}
