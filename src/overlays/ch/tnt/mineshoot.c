#include "common.h"

void func_80800000_chtntmineshoot(Actor *arg0) { extern s32 D_80802590_chtntmineshoot; extern s32 D_8080259C_chtntmineshoot; f32 *sp1C[2]; sp1C[1] = arg0->position; func_800C4AF0(sp1C[1], &D_80802590_chtntmineshoot);
    func_800C4AF0(sp1C[1], &D_8080259C_chtntmineshoot);
}

void func_8080003C_chtntmineshoot(s32 arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808025A8_chtntmineshoot;
    func_800BBCB8((f32 *)(arg0 + 4), 0, 1.0f, 4, &D_808025A8_chtntmineshoot);
}

void func_80800078_chtntmineshoot(f32 *arg0, f32 arg1) {
    void func_800187B4(s32, f32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    extern s32 D_808025CC_chtntmineshoot;
    f32 sp1C[3];

    if (arg0 != NULL) {
        func_800C4AF0(arg0, &D_808025CC_chtntmineshoot);
        if (arg1 != 0.0f) {
            func_800E1610(0, 50.0f, arg1, arg0);
        }
    } else {
        func_800F5A00(func_800F54E4(), sp1C);
        func_800C4AF0(sp1C, &D_808025CC_chtntmineshoot);
        if (arg1 != 0.0f) {
            func_800E1610(0, 50.0f, arg1, sp1C);
        }
    }
    func_800187B4(0, 0.5f, 2.0f, 0.5f);
}

void func_80800150_chtntmineshoot(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808025DC_chtntmineshoot;
    _subaddieaudioloop_entrypoint_4(arg0, (f32 *) ((u8 *) arg0 + 4), 1U, &D_808025DC_chtntmineshoot);
    arg0->unk5F = 0;
}

void func_80800188_chtntmineshoot(f32 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    f32 func_800F5F24(u32);
    extern s32 D_808025F8_chtntmineshoot;
    extern s32 D_80802644_chtntmineshoot;
    f32 sp2C[3];
    u32 sp28;

    if (arg0 != NULL) {
        func_800EE7F8(sp2C, arg0);
    } else {
        sp28 = func_800F54E4();
        func_800F5A00(sp28, sp2C);
        func_800EF1B8(sp2C, func_800F5F24(sp28), 200.0f);
    }
    func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_808025F8_chtntmineshoot);
    func_800BBCB8(sp2C, NULL, 1.0f, 1, &D_80802644_chtntmineshoot);
}

void func_80800228_chtntmineshoot(Actor *arg0) { void *func_80100094(Actor *, u32); void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *); void func_80800440_chtntmineshoot(Actor *, s32); void func_80800BCC_chtntmineshoot(Actor *); u8 *sp24; sp24 = func_80100094(arg0, 0U); func_80800BCC_chtntmineshoot(arg0); func_80800440_chtntmineshoot(arg0, 0); _subaddierouteDll_entrypoint_3(arg0, sp24 + 0x18, (f32 *)((u8 *)arg0 + 4)); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800280_chtntmineshoot.s")

void func_80800440_chtntmineshoot(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if (*temp_v0 != 2) {
        if (arg1 != 0) {
            if ((arg1 == 1) || (arg1 == 2)) {
                _subaddieDll_entrypoint_4(arg0, 1);
            }
        } else {
            _subaddieDll_entrypoint_4(arg0, 0);
        }
        *sp1C = arg1;
    }
}

s32 func_808004BC_chtntmineshoot(Actor *arg0, s32 arg1) {
    void func_80800830_chtntmineshoot(Actor *, s32);
    void func_800187B4(s32, f32, f32, f32);
    switch (arg1) {
        case 2:
            func_80102424(arg0, arg1);
            func_80800830_chtntmineshoot(arg0, 1);
            break;
        case 4:
            func_80102424(arg0, 4);
            func_80800830_chtntmineshoot(arg0, 2);
            func_8010A570(arg0);
            func_80800440_chtntmineshoot(arg0, 2);
            break;
        case 5:
            func_80102424(arg0, 5);
            func_80800830_chtntmineshoot(arg0, 2);
            func_8010A570(arg0);
            func_80800440_chtntmineshoot(arg0, 2);
            func_800187B4(0, 0.5f, 2.0f, 0.75f);
        default:
            func_80102424(arg0, arg1);
            break;
    }
    return 1;
}

s32 func_808005AC_chtntmineshoot(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddierouteDll_entrypoint_1(Actor *);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, s32);
    void func_80800BF4_chtntmineshoot(Actor *, s32);
    void func_80801F90_chtntmineshoot(Actor **, s32);

    switch (arg1) {
        case 0x95:
            _subaddierouteDll_entrypoint_1(arg0);
            break;
        case 0xA:
            func_80800BF4_chtntmineshoot(arg0, 1);
            break;
        case 5:
            func_808004BC_chtntmineshoot(arg0, 5);
            break;
        case 0x40:
            func_80101180(0x2BC, 5, 0);
            func_808004BC_chtntmineshoot(arg0, 5);
            func_80800078_chtntmineshoot(arg0->position, 0.95f);
            break;
        case 0x3F:
            func_80101180(0x2BC, 0x4F, 0);
            func_808004BC_chtntmineshoot(arg0, 4);
            func_80800BF4_chtntmineshoot(arg0, 2);
            break;
        case 0x3D:
            if (arg0->unk7C_12) {
                func_80801F90_chtntmineshoot(&arg0, arg2);
            }
            func_800FFAB0(arg0);
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808006D0_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800830_chtntmineshoot.s")

s32 func_80800A1C_chtntmineshoot(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_8010CD28(Actor *);
    f32 func_800136E4(f32);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_8010B990(Actor *, s32);
    s32 sp2C;
    u8 *sp28;
    f32 angle;

    sp28 = func_80100094(arg0, 0U);
    angle = func_800136E4(func_8010CD28(arg0) + 180.0f);
    arg0->unk54 = angle;
    _subaddierouteDll_entrypoint_7(arg0, sp28 + 0x18, arg0->rotation[1], angle, 200.0f, 0x4000);
    func_80102BF8(arg0, 0.1f, 4.0f, 100.0f);
    sp2C = func_8010B990(arg0, 0x325);
    sp2C |= func_8010B990(arg0, 0x4004);
    return sp2C;
}

s32 func_80800AD0_chtntmineshoot(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_80800830_chtntmineshoot(Actor *, s32);
    struct { u8 pad0[0x14]; u8 state; } *data;
    s32 result;

    data = func_80100094(arg0, 0U);
    result = 0;
    switch (data->state) {
        case 4:
            break;
        case 1:
            result = func_80800A1C_chtntmineshoot(arg0);
            if (result & 8) {
                func_80800830_chtntmineshoot(arg0, 3);
            }
            break;
        case 2:
            *(f32 *)&arg0->actorData[3] *= 0.5f;
            result = func_80800A1C_chtntmineshoot(arg0);
            if (result & 8) {
                func_80800830_chtntmineshoot(arg0, 4);
            }
            break;
        case 3:
            *(f32 *)&arg0->actorData[3] *= 0.5f;
            result = func_80800A1C_chtntmineshoot(arg0);
            if (func_80101DDC(arg0)) {
                func_80800830_chtntmineshoot(arg0, 4);
            }
            break;
    }
    return result;
}

void func_80800BCC_chtntmineshoot(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (1))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (4))) = 0;
}

void func_80800BF4_chtntmineshoot(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800DC090(void);
    f32 func_800DC0C0(void);
    struct { u8 unk0; s8 state; u8 pad2[2]; s8 mode; u8 pad5[3]; f32 timer; } *data;

    data = func_80100094(arg0, 0U);
    data->state = arg1;
    switch (arg1) {
        case 0:
            data->mode = 0;
            break;
        case 1:
            if (func_800DC090() & 1) {
                data->mode = 1;
            } else {
                data->mode = 2;
            }
            data->timer = func_800DC0C0();
            break;
        case 2:
            data->mode = 3;
            break;
    }
}

void func_80800C90_chtntmineshoot(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    struct { u8 unk0; s8 state; u8 pad2[2]; u8 mode; u8 pad5[3]; f32 timer; } *data;
    f32 delta;
    f32 color;
    s32 channel;

    data = func_80100094(arg0, 0U);
    delta = func_800D8FF8();
    switch (data->mode) {
        case 2:
            data->timer -= delta * 4.0f;
            if (data->timer < 0.0f) {
                data->timer = 0.0f;
                data->mode = 1;
            }
            break;
        case 1:
            data->timer += delta * 4.0f;
            if (data->timer > 1.0f) {
                data->timer = 1.0f;
                data->mode = 2;
            }
            break;
        case 3:
            data->timer += delta * 4.0f;
            if (data->timer > 1.0f) {
                data->timer = 1.0f;
                data->mode = 0;
            }
            break;
    }
    color = data->timer * 224.0f;
    arg0->pad98 = 255 - (s32) (color * 0.5f);
    channel = (s32) color + 31;
    arg0->pad99 = channel;
    arg0->pad9A = channel;
    arg0->alpha = 255;
}

OSThread *chtntmineshoot_entrypoint_0(void)
{
    extern u8 D_80802690_chtntmineshoot[];

    return (OSThread *) D_80802690_chtntmineshoot;
}

/* extern */

void func_80800E10_chtntmineshoot(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 func_800C2E04(void);
    void func_800C330C(u8 id, s32);
    void* func_80100094(Actor*, u32);
    void func_800C431C(u8, s32);
    struct { u8 pad[12]; u8 id; } *sp1C;

    sp1C = func_80100094(arg0, 0U);
    sp1C->id = func_800C2E04();
    func_800C330C(sp1C->id, 3);
    func_800C431C(sp1C->id, 0);
    _susubgame_entrypoint_11(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800E64_chtntmineshoot.s")

/* extern */

void func_80801128_chtntmineshoot(Actor *arg0) {
    f32 func_800CEA60(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FE820(f32);
    f32 temp_f0;
    f32 var_f0;

    temp_f0 = func_800CEA60(0);
    if (temp_f0 > 10.0f) {
        var_f0 = func_800F10B4(temp_f0, arg0->unk74_7, 0.0f, 1.0f, 1.4f);
    } else {
        var_f0 = func_800F10B4(temp_f0, 10.0f, 0.0f, 1.4f, 1.55f);
    }
    func_800FE820(var_f0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808011D4_chtntmineshoot.s")

void func_80801318_chtntmineshoot(Actor *arg0) {
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C35E8(u8, f32 *);
    void func_800C3BDC(u8);
    void func_800C3CE8(u8);
    s32 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80801974_chtntmineshoot(Actor *, s32);
    f32 sp28[4];
    struct { u8 pad[12]; u8 id; s32 state; } *data;

    data = func_80100094(arg0, 0);
    func_800F5A00(func_800F54E4(), sp28);
    switch (data->state) {
        case 0:
            func_800C35E8(data->id, arg0->position);
            func_800C301C(data->id, 0x414);
            func_800C3058(data->id, 0x7FFF);
            func_800C3BDC(data->id);
            arg0->unk58 = 1.0f;
            data->state = 1;
            break;
        case 1:
            if (func_800D9078(&arg0->unk58)) {
                func_800C3CE8(data->id);
                func_80101180(0x2BE, 5, 0);
                func_80801974_chtntmineshoot(arg0, 0xFA3);
                data->state = 2;
            }
            break;
        case 2:
            func_80800078_chtntmineshoot(NULL, 0.95f);
            func_80800188_chtntmineshoot(NULL);
            arg0->unk58 = func_800DC178(0.67f, 1.0f);
            data->state = 3;
            break;
        case 3:
            if (func_800D9078(&arg0->unk58)) {
                data->state = 2;
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_8080146C_chtntmineshoot.s")

void func_80801604_chtntmineshoot(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    void func_800C2FDC(u8 id);
    void func_800D284C(u32 a0);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 temp_a0;

    sp1C = func_80100094(arg0, 0U);
    _susubgame_entrypoint_11(0);
    func_800D284C(0x102U);
    temp_a0 = (*(u8 *)((s8 *)(sp1C) + (0xC)));
    if (temp_a0 != 0) {
        func_800C2FDC(temp_a0);
        (*(u8 *)((s8 *)(sp1C) + (0xC))) = 0U;
    }
}

/* extern */

s32 func_80801658_chtntmineshoot(Actor **arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800D395C(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_801085CC(s32, s16 *, u32);
    Actor *temp_v0;
    Unk80132ED0 *sp88;
    Prop *sp38[20];
    s32 var_s0;
    s32 var_s2;
    Prop **var_s1;
    Prop *temp_a1;

    temp_v0 = *arg0;
    sp88 = temp_v0->unk0;
    if ((func_800D0A9C(0xF, 1) == 0) || (func_800D395C() != 0)) {
        var_s2 = _gccubesearch_entrypoint_9(0x2BA, sp38, 0x14);
    } else {
        var_s2 = 0;
    }
    var_s0 = 0;
    if (var_s2 > 0) {
        var_s1 = sp38;
        do {
            temp_a1 = *var_s1;
            func_801085CC(0x2BE, temp_a1->position, temp_a1->FlagOrRotation);
            var_s0 += 1;
            var_s1++;
        } while (var_s0 != var_s2);
    }
    *arg0 = func_80106790(sp88);
    return var_s2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801714_chtntmineshoot.s")

s32 func_80801974_chtntmineshoot(Actor *arg0, s32 arg1) {
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 dialog;

    dialog = 7;
    switch (arg1) {
        case 0xFA4:
            break;
        default:
        case 0xFA2:
        case 0xFA3:
            func_800F7F98(func_800F54E4(), 1);
            break;
        case 0xCEC:
        case 0xFB3:
            dialog = 0x23;
            break;
        case 0xCEB:
            dialog = 0x144;
            break;
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, dialog, NULL, 0x3F);
    return 1;
}

/* extern */

s32 func_80801A18_chtntmineshoot(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800D211C(s32);
    if (arg1 == 0xFB3) {
        return func_800D211C(0x95);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801A54_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_1(void)
{
    extern u8 D_808026D8_chtntmineshoot[];

    return (OSThread *) D_808026D8_chtntmineshoot;
}

void func_80801BA0_chtntmineshoot(void) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    struct Vec { f32 v[3]; };
    extern struct Vec D_80802720_chtntmineshoot;
    extern s32 D_8080272C_chtntmineshoot;
    struct Vec sp24;

    sp24 = D_80802720_chtntmineshoot;
    func_800BBCB8(sp24.v, 0, 1.0f, 2, &D_8080272C_chtntmineshoot);
    func_800E1610(0, 20.0f, 0.9f, sp24.v);
}

void func_80801C10_chtntmineshoot(s32 arg0) 
{
}
void func_80801C18_chtntmineshoot(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801C20_chtntmineshoot.s")

void func_80801D6C_chtntmineshoot(Actor *arg0) {
    void func_80801C20_chtntmineshoot(void);
    s32 func_800D9078(f32 *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    void func_80101FDC(Actor *, u32);

    func_80801C20_chtntmineshoot();
    switch (arg0->unk70_10) {
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800D1000(0xF, 1, NULL, 1, 0);
            func_80101FDC(arg0, 1);
        }
    case 2:
    case 4:
        return;
    }
}

s32 func_80801DEC_chtntmineshoot(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _capod_entrypoint_14(void);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800EA090(void);
    u32 func_800F54E4(void);
    s32 func_800F7B9C(s32, s32);
    s32 func_800F7F98(s32, u32);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
    case 0xB:
        if (arg0->unk70_10 == 4) {
            func_800F7F98(func_800F54E4(), 0);
            func_800F7B9C(func_800F54E4(), 0x73);
            func_80101FDC(arg0, 1);
            if (func_800D0A9C(0xF, 1) == 0) {
                if (func_800EA090() == 2) {
                    func_80801974_chtntmineshoot(arg0, 0xFAB);
                } else {
                    func_80801974_chtntmineshoot(arg0, 0xFA4);
                }
            }
        }
        return 3;
    case 0x49:
        if (_glcutDll_entrypoint_19(0x18) != 0) {
            _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x900);
            func_80101FDC(arg0, 3);
            arg0->unk58 = 0.15f;
            return 1;
        }
        break;
    case 0x2E:
        func_800F7F98(func_800F54E4(), 0);
        return 1;
    case 0x77:
        if (arg0->unk70_10 == 2) {
            func_800F7B9C(arg2, 0x73);
            func_80101FDC(arg0, 1);
            _capod_entrypoint_14();
            func_800F7B9C(func_800F54E4(), 0x99);
            return 1;
        }
        break;
    }
    return 0;
}

OSThread *chtntmineshoot_entrypoint_2(void)
{
    extern u8 D_80802774_chtntmineshoot[];

    return (OSThread *) D_80802774_chtntmineshoot;
}

void func_80801F90_chtntmineshoot(Actor **arg0, s32 arg1)
{
  typedef struct 
  {
    u32 state;
    u16 pad4;
    u16 anim;
    f32 size;
    f32 unkC;
    f32 distance;
    f32 height;
    f32 speedMin;
    f32 speedMax;
    f32 yMin;
    f32 yMax;
    f32 lifeMin;
    f32 lifeMax;
  } DebrisSettings;
  typedef struct 
  {
    f32 pad18[4];
    f32 velocity[3];
    f32 size;
  } DebrisData;
  typedef struct 
  {
    u32 rgba;
  } DebrisColor;
  f32 func_800DC178(f32, f32);
  void func_800EEB9C(f32 *, f32, f32);
  void func_800EF04C(f32 *, f32 *);
  void func_800EFA98(f32 *, f32 *, f32);
  void func_80101FDC(Actor *, u32);
  s32 func_80103140(Actor *, u32, u16);
  Actor *func_801084B0(s32, Actor **);
  extern DebrisSettings D_808027BC_chtntmineshoot[][2];
  Actor *actor;
  u32 *color;
  f32 min;
  f32 vec[3];
  f32 angle;
  s32 i;
  DebrisSettings *settings;
  DebrisSettings *next;
  DebrisSettings *base;
  base = D_808027BC_chtntmineshoot[0];
  base += ((arg1 == 4) ? (0) : (1)) * 2;
  settings = base;
  next = settings + 1;
  i = 0;
  angle = (*arg0)->rotation[1];
  do
  {
    actor = func_801084B0(0x2C3, arg0);
    color = (u32 *) (&(*arg0)->pad98);
    base = settings;
    *((u32 *) (&actor->pad98)) = *color;
    func_80101FDC(actor, base->state);
    func_80103140(actor, settings->anim, actor->unk0->unk16);
    ((DebrisData *) actor->actorData)->size = settings->size;
    actor->unk54 = settings->unkC;
    actor->rotation[1] = func_800DC178(-30.0f, 30.0f) + angle;
    angle += 72.0f;
    func_800EEB9C(vec, actor->rotation[1], settings->distance);
    vec[1] = settings->height;
    func_800EF04C(actor->position, vec);
    vec[1] = 0.0f;
    func_800EFA98(((DebrisData *) actor->actorData)->velocity, vec, func_800DC178(settings->speedMin, settings->speedMax));
    ((DebrisData *) actor->actorData)->velocity[1] = func_800DC178(settings->yMin, settings->yMax);
    actor->unk50 = func_800DC178(settings->lifeMin, settings->lifeMax);
    settings = next;
    i++;
  }
  while (i != 5);
}

void func_80802140_chtntmineshoot(s32 arg0) 
{
}
/* extern */

void func_80802148_chtntmineshoot(void *arg0, s32 arg1) {
    s32 func_800DF5D8(u8, u8, u8, u8);
    s32 func_80101870(void *, s32);
    void func_80802320_chtntmineshoot(Actor *);
    func_800DF5D8((*(u8 *)((s8 *)(arg0) + (0x98))), (*(u8 *)((s8 *)(arg0) + (0x99))), (*(u8 *)((s8 *)(arg0) + (0x9A))), (*(u8 *)((s8 *)(arg0) + (0x9B))));
    func_80101870(arg0, arg1);
    func_80802320_chtntmineshoot(arg0);
}

/* extern */

void func_80802198_chtntmineshoot(Actor *arg0) {
    s32 func_808021C4_chtntmineshoot(Actor *);
    void func_808022A8_chtntmineshoot(Actor *, s32);
    func_808022A8_chtntmineshoot(arg0, func_808021C4_chtntmineshoot(arg0));
}

/* extern */

s32 func_808021C4_chtntmineshoot(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800F059C(f32 *, f32 *, f32 *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *sp54;
    f32 sp48[3];
    f32 dt;
    f32 sp38[3];
    f32 sp2C[3];

    dt = func_800D8FF8();
    ((f32 *)arg0->actorData)[5] += ((f32 *)arg0->actorData)[7] * dt;
    if (((f32 *)arg0->actorData)[5] < arg0->unk54) {
        ((f32 *)arg0->actorData)[5] = arg0->unk54;
    }
    func_800EFA20(sp38, &((f32 *)arg0->actorData)[4], dt);
    func_800EE780(sp48, arg0->position, sp38);
    sp54 = func_800FAB50(arg0->position, sp48, sp2C, 0x024200A1, 15.0f);
    if (sp54 != NULL) {
        func_800F059C(&((f32 *)arg0->actorData)[4], &((f32 *)arg0->actorData)[4], sp2C);
    }
    func_800EE7F8(arg0->position, sp48);
    return sp54 ? 1 : 0;
}

void func_808022A8_chtntmineshoot(Actor *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_3(Actor *);
    f32 func_800D8FF8(void);
    void func_800EF334(f32 *, f32);
    int func_800F1EA4(f32 *, f32 *);
    f32 sp2C;

    if (arg1 != 0) {
        if (func_800F1EA4(&((f32 *)arg0->actorData)[4], &sp2C) != 0) {
            arg0->rotation[1] = sp2C;
        }
        func_800EF334(&((f32 *)arg0->actorData)[4], 0.8f);
        _subaddiefade_entrypoint_3(arg0);
    }
    arg0->rotation[0] += arg0->unk50 * func_800D8FF8();
}

void func_80802320_chtntmineshoot(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_8001211C(void);
    void func_800BA22C(s32, s32);
    void func_800BA3FC(s32, s32);
    void func_800BA4B0(s8 *, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DC090(void);
    extern s32 D_8080287C_chtntmineshoot[];
    extern s32 D_808028C4_chtntmineshoot[];
    f32 sp2C[3];
    s32 sp28;
    s32 sp24;
    switch (arg0->unk70_10) {
    case 5:
        if (!(func_800DC090() & 3) &&
            _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp2C)) {
            sp28 = func_800BABB8(0, sp2C, NULL, 1.0f, D_8080287C_chtntmineshoot);
            func_800BA3FC(sp28, (func_8001211C() & 1) ? 0x9E3 : 0x9E2);
            func_800BA22C(sp28, 1);
        }
        break;
    case 3:
        if ((u32)(func_800DC090() & 0xF) < 3U &&
               _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp2C)) {
        sp24 = func_800BABB8(0, sp2C, NULL, 1.0f, D_808028C4_chtntmineshoot);
        func_800BA4B0(sp24, arg0->alpha);
        func_800BA22C(sp24, 1);
        }
        break;
    }
}

OSThread *chtntmineshoot_entrypoint_3(void)
{
    extern u8 D_808028E4_chtntmineshoot[];

    return (OSThread *) D_808028E4_chtntmineshoot;
}
