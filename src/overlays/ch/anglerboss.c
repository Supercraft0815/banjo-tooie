#include "common.h"

OSThread *changlerboss_entrypoint_0(void)
{
    extern u8 D_80802EB4_changlerboss[];

    return (OSThread *) D_80802EB4_changlerboss;
}

OSThread *changlerboss_entrypoint_1(void)
{
    extern u8 D_80802EFC_changlerboss[];

    return (OSThread *) D_80802EFC_changlerboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800018_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808002E0_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800B7C_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80800F14_changlerboss.s")

/* extern */

void func_80800FEC_changlerboss(Actor *arg0, s32 arg1) {
    void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101870(Actor *, void *);
    void func_801018A4(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    struct AnglerBossData {
        u8 pad0[0x9C];
        Unk80132ED0 *unk9C;
        Unk80132ED0 *unkA0;
    } *sp1C, *temp_v0;
    Unk80132ED0 *temp_a0;
    Actor *child;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if (sp1C->unkA0 != NULL) {
        child = func_80106790(sp1C->unkA0);
        func_80101870(child, arg1);
    }
    func_801018A4(arg0, arg1);
    temp_a0 = sp1C->unk9C;
    if (temp_a0 != NULL) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, func_80106790(temp_a0)->position);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801070_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808012E0_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_808015F4_changlerboss.s")

/* extern */

void func_808016A8_changlerboss(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_808015F4_changlerboss(Actor *, s32, s32);
    u8 *temp_s0;
    s32 temp_v0;

    temp_s0 = func_80100094(arg0, 0U);
    do {
        temp_v0 = func_800DC128(0, 6);
    } while (*(u8 *)((s32)temp_s0 + temp_v0 + 0x1B) != 1);
    func_808015F4_changlerboss(arg0, temp_v0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_8080170C_changlerboss.s")

/* extern */

void func_808018E8_changlerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[0x98];
        f32 unk98;
        u8 pad9C[0x93];
        u8 unk12F;
    } *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    *(f32 *)&arg0->actorData[3] = 10.0f;
    if (temp_v0->unk12F != 0) {
        temp_v0->unk98 = 900.0f;
        return;
    }
    temp_v0->unk98 = 400.0f;
}

/* extern */

int func_80801948_changlerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800EEB40(f32 *, f32 *);
    f32 func_800F15F8(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010B990(Actor *, s32);
    struct {
        u8 pad0[0x90];
        s16 index;
        u8 pad92[6];
        f32 speed;
        u8 pad9C[8];
        struct {
            f32 position[3];
            f32 padC[3];
        } points[5];
        u8 pad11C[0x13];
        u8 active;
    } *temp_s1;

    temp_s1 = func_80100094(arg0, 0);
    *(f32 *)&arg0->actorData[3] = func_800F15F8(*(f32 *)&arg0->actorData[3], temp_s1->speed, func_800D8FF8() * 600.0f);
    func_8010B990(arg0, 6);
    if (func_800EEB40(arg0->position, temp_s1->points[temp_s1->index].position) < 160000.0f) {
        if (temp_s1->active != 0) {
            temp_s1->active = 0;
            temp_s1->speed = 400.0f;
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801A10_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801AF0_changlerboss.s")

/* extern */

void func_80801BC8_changlerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    void *temp_v0;
    f32 temp_f2;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(f32 *)((s8 *)(arg0) + (8))) < (*(f32 *)((s8 *)(temp_v0) + (0xF0)))) {
        (*(f32 *)((s8 *)(arg0) + (8))) += func_800D8FF8() * 120.0f;
        temp_f2 = (*(f32 *)((s8 *)(temp_v0) + (0xF0)));
        if (temp_f2 < (*(f32 *)((s8 *)(arg0) + (8)))) {
            (*(f32 *)((s8 *)(arg0) + (8))) = temp_f2;
        }
    }
}

/* extern */

s32 func_80801C50_changlerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 var_v1;
    s32 i;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_v1 = 0;
    for (i = 0; i < 6; i++) {
        if ((temp_v0 + i)[0x1B] != 2) {
            var_v1 += 1;
        }
    }
    return var_v1;
}

/* extern */

void func_80801CD8_changlerboss(s32 arg0) {
    s32 func_8001210C(s32);
    s32 func_80108B04(s32, s32);
    if (func_8001210C(3) == 0) {
        func_80108B04(arg0, 2);
    }
}

/* extern */

void func_80801D0C_changlerboss(Actor *arg0) {
    s32 _subaddieDll_entrypoint_0(Actor *);
    void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(s32, Actor **);
    void func_8010A570(Actor *);
    void func_8010A800(Actor *, s32);
    struct AnglerBossData {
        u8 pad0[0x9C];
        Unk80132ED0 *unk9C;
        Unk80132ED0 *unkA0;
    } *sp24;
    Actor *temp_v0;

    sp24 = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x298, &arg0);
    temp_v0->unk3C = arg0->unk0;
    sp24->unkA0 = temp_v0->unk0;
    _subaddieDll_entrypoint_0(temp_v0);
    func_8010A800(temp_v0, 2);
    func_8010A570(temp_v0);
    temp_v0->unk64_16 = 0;
    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xB, temp_v0->position);
}

/* extern */

Actor *func_80801DA0_changlerboss(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    Actor *func_801084B0(s32, Actor **);
    struct AnglerBossData {
        u8 pad0[0x9C];
        Unk80132ED0 *unk9C;
    } *sp24;
    Actor *temp_v0;

    sp24 = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x45E, &arg0);
    func_80102FDC(temp_v0, arg0->scale);
    temp_v0->unk3C = arg0->unk0;
    sp24->unk9C = temp_v0->unk0;
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(temp_v0, 2);
    } else if (func_800DA298(0x1AF) != 0) {
        func_80102424(temp_v0, 3);
    }
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801E3C_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80801F54_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802108_changlerboss.s")

void func_808021E4_changlerboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802210_changlerboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802210_changlerboss(arg0, arg0->unk0, arg1, arg2);
}

void func_80802210_changlerboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3)
{
  void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
  void _capod_entrypoint_14(void);
  void *func_80100094(Actor *, u32);
  u8 *sp1C;
  u8 *temp_v0;
  temp_v0 = func_80100094(arg0, 0U);
  sp1C = temp_v0;
  arg3 = arg3;
  if ((*((u8 *) (((s8 *) temp_v0) + 0x12B))) != 0)
  {
    _capod_entrypoint_14();
    arg3 = arg3 | 0x2000;
  }
  _capod_entrypoint_13(arg1, arg0->unk0, arg2, arg3);
  *((s8 *) (((s8 *) sp1C) + 0x12B)) = 1;
}

void func_80802288_changlerboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x12B))) != 0) {
        _capod_entrypoint_14();
        (*(s8 *)((s8 *)(temp_v0) + (0x12B))) = 0;
    }
}

/* extern */

void func_808022C4_changlerboss(Actor *arg0) {
    void func_800D2498(u32, s32, u32);
    void *func_80100094(Actor *, u32);
    s32 var_a1;
    s32 temp_t6;
    void *temp_v0;

    temp_t6 = arg0->unk70_10;
    if ((temp_t6 != 0xB) && (temp_t6 != 0xC) && (temp_t6 >= 5) && (temp_t6 < 0x19)) {
        temp_v0 = func_80100094(arg0, 0U);
        if ((*(s16 *)((s8 *)(temp_v0) + (0x92))) == 0) {
            var_a1 = func_80801C50_changlerboss(arg0);
        } else {
            var_a1 = (*(s16 *)((s8 *)(temp_v0) + (0x96)));
        }
        func_800D2498(0xFE, var_a1, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802340_changlerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802430_changlerboss.s")

/* extern */

s32 func_808025AC_changlerboss(s32 arg0) {
    s32 func_800F54E4();
    s32 func_8010D290(s32);
    s32 temp_v0;
    s32 var_v1;

    temp_v0 = func_8010D290(0x400);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800F54E4();
    }
    return var_v1;
}

void func_808025EC_changlerboss(Actor *arg0) {
    void _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    extern s16 D_80803054_changlerboss;
    s32 i;
    struct {
        f32 pad0[15];
        f32 unk3C[6][3];
        f32 unk84[3];
    } *sp30;

    sp30 = func_80100094(arg0, 0);
    for (i = 0; i < 6; i++) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, (&D_80803054_changlerboss)[i], sp30->unk3C[i]);
    }
    _subaddieskeleton_entrypoint_2(arg0->unk0, 0xC, sp30->unk84);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802680_changlerboss.s")

/* extern */

void func_808027F8_changlerboss(void *arg0) {
    void func_800EFD24(f32 *);
    f32 func_80102D78(void *, s32 *);
    s32 sp1C[3];
    f32 temp_f0;

    func_800EFD24((f32 *)sp1C);
    temp_f0 = func_80102D78(arg0, sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x48))) = temp_f0;
    (*(f32 *)((s8 *)(arg0) + (0x50))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x44))) = 0.0f;
}

/* extern */

void func_80802844_changlerboss(void *arg0) {
    s32 func_800C8A98();
    struct {
        u8 pad0[0x54];
        s32 unk54;
        f32 unk58;
        u8 pad5C[0x1E];
        u8 unk7A_7 : 2;
        u8 pad7A_5 : 6;
    } *self = arg0;
    self->unk58 = 0.4f;
    self->unk7A_7 = 2;
    self->unk54 = func_800C8A98();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/func_80802888_changlerboss.s")

/* extern */

s32 func_80802A90_changlerboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void _subaddiefade_entrypoint_3(Actor *);
    void func_80101FDC(Actor *, u32);
    struct {
        u8 pad0[0x54];
        s32 unk54;
    } *self = (void *)arg0;
    s32 temp_a0;
    s32 result;

    if (arg1 == 0x2C) {
        temp_a0 = self->unk54;
        if (temp_a0 != 0) {
            self->unk54 = _chlightfader_entrypoint_1(temp_a0, 1.0f, 3);
        }
        _subaddiefade_entrypoint_3(arg0);
        func_80101FDC(arg0, 4);
        result = 1;
    } else {
        return 0;
    }
    return result;
}
