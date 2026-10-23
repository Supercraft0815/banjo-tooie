#include "common.h"

OSThread *chterryegg_entrypoint_0(void)
{
    extern u8 D_80801260_chterryegg[];

    return (OSThread *) D_80801260_chterryegg;
}

OSThread *chterryegg_entrypoint_1(void)
{
    extern u8 D_80801328_chterryegg[];

    return (OSThread *) D_80801328_chterryegg;
}

OSThread *chterryegg_entrypoint_2(void)
{
    extern u8 D_80801370_chterryegg[];

    return (OSThread *) D_80801370_chterryegg;
}

OSThread *chterryegg_entrypoint_3(void)
{
    extern u8 D_808013B8_chterryegg[];

    return (OSThread *) D_808013B8_chterryegg;
}

void func_80800030_chterryegg(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32 *);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80103014(u8 *);
    s32 func_80800CF4_chterryegg(Actor *, f32);
    s32 func_80801138_chterryegg(void *);

    if (func_800DA298(arg0->unk74_7 + 0x143) || func_80801138_chterryegg(arg0)) {
        func_800FFAB0(arg0);
        return;
    }
    _glsplinefind_entrypoint_0(0x357, arg0->position);
    func_80103014(arg0);
    func_80800CF4_chterryegg(arg0, 4.0f);
}

void func_808000A8_chterryegg(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _plsu_entrypoint_3(Unk80132ED0 *);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiepalette_entrypoint_1(Actor *, void *);
    s32 _subaddiepalette_entrypoint_2(Actor *, void *, s32, f32);
    s32 func_800D9078();
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F7BC8(s32, s32, Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_808010B0_chterryegg(Actor *);
    s32 player;

    switch (arg0->unk70_10) {
        case 1:
            player = _plsu_entrypoint_3(arg0->unk0);
            if (player != -1) {
                func_800F7BC8(player, 0x53, arg0->unk0);
            }
            break;
        case 3:
            if (arg0->unk7C_12 && func_800D9078(&arg0->unk58)) {
                _subaddiepalette_entrypoint_2(arg0, func_80100094(arg0, 1), 0x7BE, 2.5f);
                func_80102424(arg0, 4);
                arg0->unk58 = 2.5f;
            }
            break;
        case 4:
            if (func_800D9078(&arg0->unk58)) {
                func_80102424(arg0, 5);
                _subaddieDll_entrypoint_4(arg0, 0);
            }
            ((f32 *)arg0->actorData)[4] = func_800F10B4(arg0->unk58, 0.0f, 2.5f, 0, 255.0f);
            break;
        case 5:
            player = _plsu_entrypoint_3(arg0->unk0);
            if (player != -1) {
                func_800F7BC8(player, 0x53, arg0->unk0);
            }
            break;
        case 6:
            func_808010B0_chterryegg(arg0);
            if (func_80101E14(arg0, 0.3f)) {
                _chexploder_entrypoint_3(arg0, arg0->position, 8);
                func_80102424(arg0, 7);
            }
            break;
    }
    _subaddiepalette_entrypoint_1(arg0, func_80100094(arg0, 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/terryegg/func_8080023C_chterryegg.s")

/* extern */

void func_8080057C_chterryegg(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    s32 func_801088A8(Actor *, s32, s32, s32);
    f32 func_80801188_chterryegg(Actor *, s32);
    func_80102FDC(arg0, func_80801188_chterryegg(arg0, 0));
    func_801088A8(arg0, 0x10002000, 0, 0);
}

void func_808005C4_chterryegg(Actor *arg0) {
    typedef struct {
        u8 pad0[0x74];
        u32 pad74_31 : 11;
        u32 unk74_20 : 1;
        u32 pad74_0 : 20;
    } TerryEggFlags;
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddietaxi_entrypoint_1(Actor *, s32);
    s32 _subaddietaxi_entrypoint_5(Actor *, s32);
    void _subaddietaxi_entrypoint_9(Actor *, s32);
    s32 _subaddietaxi_entrypoint_11(Actor *, s32);
    s32 _subaddietaxi_entrypoint_12(Actor *, s32);
    void _subaddietaxi_entrypoint_14(Actor *, s32);
    s32 _subaddietaxi_entrypoint_15(Actor *, s32);
    s32 func_800CB698(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DA7A8(s32, s32, s32);
    void func_800EFD24(f32 *);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_801058C4(Actor *, s32, f32, u32);
    void func_8010A590(Actor *);
    void func_80800FE0_chterryegg(u8 *);
    void func_80801050_chterryegg(Actor *);
    int func_80801080_chterryegg(s32);
    s32 func_808010DC_chterryegg(void);
    extern u8 D_80801260_chterryegg[];
    s32 active = 1;
    s32 *data;
    f32 position[3];
    f32 *actorPosition;

    switch (arg0->unk70_10) {
        case 1:
            active = 0;
            arg0->unk64_16 = 0; ((TerryEggFlags *)arg0)->unk74_20 = 0;
            if (func_800DA298(0xE5)) {
                func_80800FE0_chterryegg(arg0);
            }
            break;
        case 2:
            arg0->unk64_16 = 1;
            ((TerryEggFlags *)arg0)->unk74_20 = arg0->unk64_16;
            active = 0;
            if (func_80101DDC(arg0)) {
                func_800F82D4(func_800F54E4(), 0);
                if (func_808010DC_chterryegg() == 1) {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x17FE, 0xF, arg0->position, 0);
                    func_800DA7A8(0x361, arg0->unk74_7 - 0x31, 3);
                    func_80102424(arg0, 4);
                    func_8010A590(arg0);
                } else {
                    data = func_80100094(arg0, 0);
                    func_800DA544(arg0->unk74_7 + 0x143);
                    func_800CB698(arg0->unk74_7 - 0x2B, 6);
                    func_80102424(arg0, 5);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x17E1, 0x44, arg0->position, 0);
                    _subaddieDll_entrypoint_4(arg0, 1);
                    if (*data != -1) {
                        _capod_entrypoint_13(arg0->unk0, NULL, D_80801260_chterryegg[arg0->unk74_7 - 0x2A], 0x31);
                        func_801058C4(arg0, *data, 200.0f, 1);
                    }
                }
            }
            break;
        case 3:
            func_80801080_chterryegg(arg0);
            break;
        case 4:
            func_80801050_chterryegg(arg0);
            break;
        case 5:
            func_800FFAB0(arg0);
            break;
        case 6:
            func_80801050_chterryegg(arg0);
            break;
        case 7:
            func_80801050_chterryegg(arg0);
            break;
        case 8:
            active = 0;
            break;
        case 9:
            active = 0;
            func_80801080_chterryegg(arg0);
            if (_subaddietaxi_entrypoint_1(arg0, arg0->unk74_7 - 0x2B)) {
                func_80102424(arg0, 0xB);
                func_800DA544(arg0->unk74_7 + 0x143);
                func_80101180(0x36F, 0x31, arg0->unk74_7 - 0x32);
            }
            break;
        case 10:
            func_80801050_chterryegg(arg0);
            if (_subaddietaxi_entrypoint_11(arg0, arg0->unk74_7 - 0x2B) &&
                _subaddietaxi_entrypoint_5(arg0, arg0->unk74_7 - 0x2B)) {
                _subaddietaxi_entrypoint_14(arg0, arg0->unk74_7 - 0x2B);
                func_80102424(arg0, 0xC);
            }
            active = _subaddietaxi_entrypoint_12(arg0, arg0->unk74_7 - 0x2B);
            break;
        case 11:
            func_800EFD24(position);
            arg0->unk54 = func_80102D78(arg0, position);
            func_80102BF8(arg0, 0.1f, 4.0f, 80.0f);
            func_80801080_chterryegg(arg0);
            break;
        case 12:
            if (_subaddietaxi_entrypoint_15(arg0, arg0->unk74_7 - 0x2B)) {
                func_80102424(arg0, 6);
                func_8010A590(arg0);
            }
            break;
    }
    _subaddietaxi_entrypoint_9(arg0, arg0->unk74_7 - 0x2B);
    if (active) {
        actorPosition = arg0->position;
        func_800F4F34(func_800F54E4(), actorPosition, arg0->scale * 20.0f, arg0->scale * 20.0f);
    }
}

void func_808009B4_chterryegg(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_800FFAB0(Actor *);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    extern u32 D_80801400_chterryegg;

    if (arg0->unk70_10 == 5) {
        func_80105834(arg0);
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801400_chterryegg, 0.25f);
        if (func_80105A5C(arg0) != 0) {
            _capod_entrypoint_14();
            func_800FFAB0(arg0);
        }
    }
}

s32 func_80800A2C_chterryegg(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddietaxi_entrypoint_13(Actor *, s32, void *, s32);
    s32 _subaddietaxi_entrypoint_2(Actor *, s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_80800BD0_chterryegg(Actor *, s32, s32);
    void func_80800C08_chterryegg(Actor *);
    void func_80800E88_chterryegg(Actor *, s32);
    s32 func_80801138_chterryegg(void *);
    extern OSThread *_chterryegg_entrypoint_0(void);
    struct TerryEggFlags {
        u8 pad[0x74];
        u32 pad74_21 : 11;
        u32 active : 1;
        u32 pad74_0 : 20;
    };
    switch (arg1) {
    case 0x3E:
        if (_subaddietaxi_entrypoint_2(arg0, arg0->unk74_7 - 0x2B)) {
            func_80102424(arg0, 8);
        }
        break;
    case 0x2E:
        func_80800BD0_chterryegg(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x44:
        func_80800E88_chterryegg(arg0, arg2);
        break;
    case 0x95:
        if (_glcutDll_entrypoint_19(0x33)) {
            _subaddieDll_entrypoint_4(arg0, 1);
        }
        if (_subaddietaxi_entrypoint_13(arg0, arg0->unk74_7 - 0x2B, _chterryegg_entrypoint_0, 3)) {
            func_80800C08_chterryegg(arg0);
            if (func_80801138_chterryegg(arg0)) {
                arg0->unk64_16 = 1;
                ((struct TerryEggFlags *)arg0)->active = arg0->unk64_16;
                func_80102424(arg0, 6);
            } else {
                func_8010A570(arg0);
                arg0->unk64_16 = 0;
                ((struct TerryEggFlags *)arg0)->active = arg0->unk64_16;
            }
        } else if (arg0->unk7A_5) {
            func_800FFAB0(arg0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800BD0_chterryegg(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if ((arg1 != 0x17E1) && (arg1 == 0x17FE)) {
        func_80102424(arg0, 6);
    }
}

void func_80800C08_chterryegg(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32*);
    void* func_80100094(Actor*, u32);
    s32 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    *sp1C = _glsplinefind_entrypoint_0(0x357U, arg0->position);
}

void func_80800C48_chterryegg(s32 arg0)
{
    func_8010C964();
    func_80801080_chterryegg(arg0);
}
s32 func_80800C70_chterryegg(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);
    f32 func_800DC0C0(void);
    void func_800FFAB0(Actor *);
    void func_80101EE4(Actor *, f32);
    s32 func_80800CF4_chterryegg(Actor *, f32);
    f32 func_80801188_chterryegg(Actor *, s32);
    if (arg1 == 0x95) {
        func_80800CF4_chterryegg(arg0, func_80801188_chterryegg(arg0, 0));
        func_80101EE4(arg0, func_800DC0C0());
        if (func_800DA298(arg0->unk74_7 + 0x143) == 0) {
            func_800FFAB0(arg0);
        }
        return 1;
    }
    return 0;
}

s32 func_80800CF4_chterryegg(Actor *arg0, f32 arg1) {
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg1);
    return 1;
}

void func_80800D20_chterryegg(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    extern s32 _subaddietaxi_entrypoint_16;
    if (func_800DA298(arg0 + 0x16E) == 0) {
        _chbaddiesetup_entrypoint_6(&_subaddietaxi_entrypoint_16, arg0, (*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (4))), (*(s32 *)((s8 *)(arg1) + (8))), arg2, arg3);
    }
}

void func_80800D88_chterryegg(s32 arg0, f32 *arg1) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void func_800EE88C(f32 *, s16 *);
    extern Prop *B_80801460_chterryegg[4];
    s32 count;
    s32 i;
    s32 id;
    Prop **cursor;
    Prop *prop;

    count = _gccubesearch_entrypoint_9(0x3D7, B_80801460_chterryegg, 4);
    i = 0;
    if (count > 0) {
        cursor = B_80801460_chterryegg;
        id = arg0 + 0x2B;
        do {
            prop = *cursor;
            i++;
            if (id == prop->unk6_7) {
                func_800EE88C(arg1, prop->position);
                return;
            }
            cursor++;
        } while (i < count);
    }
}

/* extern */

s32 func_80800E0C_chterryegg(s32 arg0, s32 arg1, f32 *arg2) {
    s32 func_800C05B8(s32, s32, s32, s32, s32, s32, s32);
    s32 func_800CBD84(s32);
    s32 func_800EA05C();
    void func_80800D88_chterryegg(s32, f32 *);
    if ((func_800EA05C() == 0x113) && (func_800CBD84(arg1) != -1)) {
        func_80800D88_chterryegg(arg0, arg2);
        return 2;
    }
    func_800C05B8(0x17E0, 1, 0, 0, 0, 0, 0);
    return 1;
}

void func_80800E88_chterryegg(Actor *arg0, s32 arg1) {
    void func_80100120(Actor *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void _subaddietaxi_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddietaxi_entrypoint_10(Actor *, s32, s32);
    s32 func_800CB3E0(s32);
    s32 func_800DA298(s32);
    s32 func_80801138_chterryegg(void *);
    f32 func_80801188_chterryegg(Actor *, s32);
    struct TerryEggFlags {
        u8 pad[0x74];
        u32 pad74_21 : 11;
        u32 active : 1;
        u32 pad74_0 : 20;
    };
    f32 position[3];

    func_80100120(arg0);
    func_80800CF4_chterryegg(arg0, func_80801188_chterryegg(arg0, 0));
    switch (func_800CB3E0(arg1)) {
        case 1:
            if (func_800DA298(arg0->unk74_7 + 0x143) || func_80801138_chterryegg(arg0)) {
                func_80102424(arg0, 6);
                func_8010A590(arg0);
            } else {
                func_80800C08_chterryegg(arg0);
                func_80102424(arg0, 1);
                func_8010A570(arg0);
                arg0->unk64_16 = 0;
                ((struct TerryEggFlags *)arg0)->active = arg0->unk64_16;
            }
            break;
        case 3:
            _subaddietaxi_entrypoint_10(arg0, arg1, 10);
            break;
        case 4:
            func_80800D88_chterryegg(arg1, position);
            func_8010A570(arg0);
            _subaddietaxi_entrypoint_0(arg0, arg1, position, 9);
            break;
        case 6:
            func_80102424(arg0, 11);
            func_8010A570(arg0);
            break;
    }
}

void func_80800FE0_chterryegg(u8 *arg0) {
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 func_800D9078(s32);
    f32 func_800DC178(f32, f32);
    extern s32 D_80801410_chterryegg;
    func_800D9078(arg0 + 0x58);
    if ((*(f32 *)((s8 *)(arg0) + (0x58))) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80801410_chterryegg);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = func_800DC178(1.5f, 2.5f);
    }
}

void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);

void func_80801050_chterryegg(Actor *arg0) {
    extern u32 D_80801424_chterryegg;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801424_chterryegg, 0.81f);
}

int func_80801080_chterryegg(s32 arg0) {
    extern u32 D_8080126C_chterryegg;
    extern u32 D_80801438_chterryegg;
    _subaddieaudioquick_entrypoint_4(arg0, (f32 *) (arg0 + 4), &D_8080126C_chterryegg, &D_80801438_chterryegg);
}

void func_808010B0_chterryegg(Actor *arg0) {
    extern u32 D_80801450_chterryegg;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80801450_chterryegg, 0.0f);
}

/* extern */

s32 func_808010DC_chterryegg(void) {
    s32 func_800DA564(s32, s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_800DA564(0x175, 4);
    var_v1 = 0;
    if (temp_v0 & 1) {
        var_v1 = 1;
    }
    if (temp_v0 & 2) {
        var_v1 += 1;
    }
    if (temp_v0 & 4) {
        var_v1 += 1;
    }
    if (temp_v0 & 8) {
        var_v1 += 1;
    }
    return 4 - var_v1;
}

s32 func_80801138_chterryegg(void *arg0)
{
  s32 func_800DA564(s32, s32);
  s32 temp_v0;
  temp_v0 = func_800DA564(0x361, 3);
  if (temp_v0 == 0)
  {
    return 0;
  }
  return (temp_v0 + 0x31) == (((unsigned long) ((u16) (*((u16 *) (((s8 *) arg0) + 0x76))))) >> 7);
}

f32 func_80801188_chterryegg(Actor *arg0, s32 arg1) {
    f32 var_f2;

    if (arg1 != 0) {
        if (func_808010DC_chterryegg() == 1) {
            var_f2 = 4.0f;
        } else {
            var_f2 = 2.0f;
        }
        return var_f2;
    } else if (func_80801138_chterryegg(arg0) != 0) {
        var_f2 = 4.0f;
    } else {
        var_f2 = 2.0f;
    }
    return var_f2;
}
