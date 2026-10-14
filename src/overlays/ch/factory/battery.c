#include "common.h"

OSThread *chfactorybattery_entrypoint_0(void)
{
    extern u8 D_80801B34_chfactorybattery[];

    return (OSThread *) D_80801B34_chfactorybattery;
}

/* extern */

s32 func_8080000C_chfactorybattery(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 _gccubesearch_entrypoint_12(s32 *, s32, u8 *);
    f32 sp24[3];
    s32 sp20;
    sp20 = _gccubesearch_entrypoint_12((s32 *)sp24, 0x28C, (u8 *)arg0->position);
    func_800EE7F8(arg0->position, sp24);
    return sp20;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800050_chfactorybattery.s")

void func_8080019C_chfactorybattery(volatile unsigned int arg0, void *arg1, s32 arg2, s32 arg3)
{
  s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
  extern s32 _subaddietaxi_entrypoint_16;
  _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, *((s32 *) (((s8 *) arg1) + 0)), *((s32 *) (((s8 *) arg1) + 4)), *((s32 *) (((s8 *) arg1) + 8)), arg2, arg3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808001F8_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808003C0_chfactorybattery.s")

/* extern */

s32 func_80800444_chfactorybattery(void) {
    s32 func_800DA298(s32);
    s32 func_80800480_chfactorybattery();
    s32 temp_v0;

    temp_v0 = func_80800480_chfactorybattery();
    if (temp_v0 != 0) {
        return func_800DA298(temp_v0);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800480_chfactorybattery.s")

/* extern */

int func_808004E8_chfactorybattery(void) {
    s32 func_800EA05C();
    return func_800EA05C() == 0x101 ||
           func_800EA05C() == 0x106 ||
           func_800EA05C() == 0x109 ||
           func_800EA05C() == 0x10B;
}

/* extern */

void func_80800558_chfactorybattery(void) {
    s32 func_800DA298(s32);
    s32 func_80800678_chfactorybattery();
    func_800DA298(func_80800678_chfactorybattery() + 0x1B1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800580_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800678_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808006E4_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800760_chfactorybattery.s")

/* extern */

void func_808008C8_chfactorybattery(Actor *arg0) {
    s32 func_800DC128(s32, s32);

    switch (arg0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 9:
        arg0->unk79_4 = 0;
        return;
    case 5:
    case 7:
    case 10:
    case 13:
        arg0->unk79_4 = func_800DC128(1, 4);
        /* fallthrough */
    default:
        return;
    }
}

void func_80800948_chfactorybattery(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80801B60_chfactorybattery;
    extern u32 D_80801B78_chfactorybattery;

    switch (arg0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 9:
        break;
    case 6:
    case 8:
    case 10:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801B60_chfactorybattery, 0.5f);
        break;
    }
    if (arg0->unk79_4 != 0) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80801B78_chfactorybattery);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_808009C8_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80800AB8_chfactorybattery.s")

s32 func_80801040_chfactorybattery(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_1();
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 _subaddietaxi_entrypoint_2(Actor *, s32);
    void func_800DF744(s32, s32);
    s32 func_800F54E4();
    void func_800F7A2C(s32, s32, f32 *);
    s32 func_801015D0(Actor *);
    s32 func_80107070(Actor *, s32);
    f32 func_8010A40C(void *);
    s32 func_8080000C_chfactorybattery(Actor *);
    void func_80800050_chfactorybattery(Actor *, s32);
    void func_808001F8_chfactorybattery(Actor *);
    s32 func_80800678_chfactorybattery();
    void func_8080130C_chfactorybattery(Actor *, s32);

    switch (arg1) {
        case 0x3E:
            switch (arg0->unk70_10) {
                case 1:
                case 4:
                case 9:
                    if (_subaddietaxi_entrypoint_2(arg0, func_80800678_chfactorybattery(arg0))) {
                        func_8080130C_chfactorybattery(arg0, 2);
                    }
                    return 1;
                case 6:
                case 7:
                    func_8080130C_chfactorybattery(arg0, 7);
                    return 1;
                case 8:
                case 10:
                    if (arg0->unk79_4) {
                        func_8080130C_chfactorybattery(arg0, 10);
                    }
                    return 1;
                case 5:
                case 13:
                    func_800F7A2C(func_800F54E4(), 5, arg0->position);
                    return 1;
                default:
                    return 1;
            }
        case 0x40:
            switch (arg0->unk70_10) {
                case 1:
                case 6:
                    func_8080130C_chfactorybattery(arg0, 1);
                    return 1;
                case 8:
                case 9:
                case 10:
                    func_8080130C_chfactorybattery(arg0, 9);
                    return 1;
                default:
                    return 1;
            }
        case 1:
            switch ((s32)arg0->unk70_10) {
                case 1:
                case 6:
                case 7:
                    func_8080130C_chfactorybattery(arg0, 8);
                    return 1;
            }
            return 1;
        case 2:
            func_80107070(arg0, 1);
            return 1;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF744(3, arg0->unk79_4);
            return 1;
        case 0x44:
            func_80800050_chfactorybattery(arg0, arg2);
            return 1;
        case 0x29:
            ((s16 *)arg0->unk0)[0x10] = (s32)(func_8010A40C(arg0) * 120.0f);
            return 1;
        case 0x95:
            func_808001F8_chfactorybattery(arg0);
            return 1;
        case 0x4D:
            func_8080000C_chfactorybattery(arg0);
            if (arg0->unk70_10 != 3 && arg0->unk70_10 != 4 && arg0->unk70_10 != 5 && arg0->unk70_10 != 13) {
                _subaddieDll_entrypoint_1(arg0);
                _subaddierouteDll_entrypoint_1(arg0);
            }
            return 1;
        default:
            return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_8080130C_chfactorybattery.s")

/* extern */

void func_808014C0_chfactorybattery(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
    if (func_80100094(arg0, 0U) != NULL) {
        _subaddiefx_entrypoint_1(arg0, func_80100094(arg0, 0U));
    }
}

OSThread *chfactorybattery_entrypoint_1(void)
{
    extern u8 D_80801BA8_chfactorybattery[];

    return (OSThread *) D_80801BA8_chfactorybattery;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_8080150C_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80801728_chfactorybattery.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/battery/func_80801804_chfactorybattery.s")

OSThread *chfactorybattery_entrypoint_2(void)
{
    extern u8 D_80801BF0_chfactorybattery[];

    return (OSThread *) D_80801BF0_chfactorybattery;
}
