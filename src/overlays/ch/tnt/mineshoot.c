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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808004BC_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808005AC_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_808006D0_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800830_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800A1C_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800AD0_chtntmineshoot.s")

void func_80800BCC_chtntmineshoot(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s8 *)((s8 *)(temp_v0) + (1))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (4))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800BF4_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80800C90_chtntmineshoot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801318_chtntmineshoot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801974_chtntmineshoot.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801D6C_chtntmineshoot.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801DEC_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_2(void)
{
    extern u8 D_80802774_chtntmineshoot[];

    return (OSThread *) D_80802774_chtntmineshoot;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80801F90_chtntmineshoot.s")

void func_80802140_chtntmineshoot(s32 arg0) 
{
}
/* extern */

void func_80802148_chtntmineshoot(void *arg0, s32 arg1) {
    s32 func_800DF5D8(u8, u8, u8, u8);
    s32 func_80101870(void *, s32);
    s32 func_80802320_chtntmineshoot(void *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/mineshoot/func_80802320_chtntmineshoot.s")

OSThread *chtntmineshoot_entrypoint_3(void)
{
    extern u8 D_808028E4_chtntmineshoot[];

    return (OSThread *) D_808028E4_chtntmineshoot;
}
