#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80800000_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80800180_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80800200_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080041C_chdiggerboss.s")

OSThread *chdiggerboss_entrypoint_0(void)
{
    extern u8 D_80809E44_chdiggerboss[];

    return (OSThread *) D_80809E44_chdiggerboss;
}

OSThread *chdiggerboss_entrypoint_1(void)
{
    extern u8 D_80809E8C_chdiggerboss[];

    return (OSThread *) D_80809E8C_chdiggerboss;
}

void func_80800508_chdiggerboss(Actor *arg0, u32 arg1) {
    void _gcnewoption_entrypoint_1();
    s32 func_800EB854(void);
    void *func_80100094(Actor *, u32);
    void func_801017D0(Actor *);
    void func_80101808();
    s32 temp_v0;

    temp_v0 = func_800EB854();
    if (temp_v0 != 0) {
        if (temp_v0 == 3) {
            _gcnewoption_entrypoint_1((u8 *)func_80100094(arg0, 0) + 0x10C, arg1);
        }
    } else {
        func_80101808(arg0, func_801017D0);
    }
}

void func_80800568_chdiggerboss(Actor *arg0, volatile s32 arg1)
{
  void func_800DF744(s32, s32);
  void *func_80100094(Actor *, u32);
  s32 func_801015D0(Actor *);
  extern s16 D_80809EE0_chdiggerboss;
  extern s16 D_80809EE2_chdiggerboss;
  s16 *var_s0;
  u8 *new_var;
  u8 *var_s1;
  void *temp_s2;
  temp_s2 = func_80100094(arg0, 0);
  func_801015D0(arg0);
  var_s1 = temp_s2;
 var_s0 = &D_80809EE0_chdiggerboss; do {
    new_var = var_s1;
    func_800DF744(*var_s0, new_var[0xFC]);
    var_s0 += 1;
    var_s1 += 1;
  }
  while (var_s0 != (&D_80809EE2_chdiggerboss));
}

/* extern */

void func_808005DC_chdiggerboss(s32 arg0, s32 arg1) {
    s32 func_800AE6BC(s32);
    s32 func_801040A8();
    s32 func_80806528_chdiggerboss(s32, s32, s32);
    func_80806528_chdiggerboss(arg0, func_800AE6BC(func_801040A8()), arg1);
}

void func_80800618_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)((((u8 *)func_80100094(arg0, 0)) + arg1)) + (0xFC))) = (s8) arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80800650_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808006F8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808007E0_chdiggerboss.s")

void func_808008C0_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)((((u8 *)func_80100094(arg0, 0)) + arg1)) + (0xE4))) = (s8) arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808008F8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80800A4C_chdiggerboss.s")

/* extern */

void func_808019A8_chdiggerboss(s32 arg0) {
    void func_80802EF8_chdiggerboss(s32);
    void func_808059CC_chdiggerboss(s32);
    void func_8080666C_chdiggerboss(s32);
    void func_8080843C_chdiggerboss(s32);
    void func_80807B4C_chdiggerboss(s32);
    s32 func_808027F4_chdiggerboss(s32);
    func_808027F4_chdiggerboss(arg0);
    func_80802EF8_chdiggerboss(arg0);
    func_80807B4C_chdiggerboss(arg0);
    func_8080666C_chdiggerboss(arg0);
    func_808059CC_chdiggerboss(arg0);
    func_8080843C_chdiggerboss(arg0);
    _suexpression_entrypoint_8((Actor *) arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80801A04_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80801DE0_chdiggerboss.s")

u16 func_80802158_chdiggerboss(s32 arg0, s32 arg1) {
    extern s32 D_80809EE4_chdiggerboss;
    return *(u16 *)((u8 *)&D_80809EE4_chdiggerboss + (arg1 * 2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802170_chdiggerboss.s")

s32 func_808021E8_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    if (*(u8 *)(((u8 *)func_80100094(arg0, 0)) + arg1 + 0xFD) == 0) {
        return 0;
    } else {
        return 1;
    }
}

/* extern */

Actor *func_80802228_chdiggerboss(Actor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790(arg0->unk3C);
}

s32 func_80802248_chdiggerboss(s32 arg0) {
    s32 func_800F54E4(void);
    s32 func_8010D290(s32);
    s32 temp_v0;
    s32 var_v1;
    temp_v0 = func_8010D290(0x10000);
    var_v1 = temp_v0;
    if (temp_v0 == -1) {
        var_v1 = func_800F54E4();
    }
    return var_v1;
}

s32 func_80802288_chdiggerboss(void *arg0) {
    return (*(u16 *)((s8 *)(arg0) + (0x64))) & 1;
}

void func_80802298_chdiggerboss(u8 *arg0, u8 *arg1)
{
  void func_800EE7F8(f32 *, f32 *);
  s32 func_800EF1B8(u8 *, s32, f32);
  func_800EE7F8(arg1, arg0 + 4);
  func_800EF1B8(arg1, *((s32 *) (((s8 *) arg0) + 0x48)), (*((f32 *) (((s8 *) arg0) + 0x38))) * 600.0f);
  *((f32 *) (((s8 *) arg1) + 4)) = (f32) (((*((f32 *) (((s8 *) arg0) + 0x38))) * 2500.0f) + (*((f32 *) (((s8 *) arg1) + 4))));
}

/* extern */

s32 func_80802314_chdiggerboss(void) {
    s32 func_800DA980(s32, s32);
    return 2 - func_800DA980(0xA4F, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080233C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808023D8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802550_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808025D4_chdiggerboss.s")

/* extern */

void func_808026F8_chdiggerboss(void *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    func_80106790((*(s32 *)((s8 *)(arg0) + (0x3C))));
}

/* extern */

s32 func_80802718_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80802878_chdiggerboss(s32, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (8))) != 2) {
            func_80802878_chdiggerboss(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802778_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808027F4_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802878_chdiggerboss.s")

void func_8080290C_chdiggerboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802938_chdiggerboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802938_chdiggerboss(arg0, arg0->unk0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802938_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808029C8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802AB8_chdiggerboss.s")

void func_80802BE0_chdiggerboss(s32 arg0, f32 arg1) {
    void *func_80100094(Actor *, u32);
    (*(f32 *)((s8 *)(func_80100094(arg0, 0)) + (0xC))) = arg1;
}

void func_80802C0C_chdiggerboss(s32 arg0) {
    s32 func_800F4AF4(u32, s32);
    void func_80802C40_chdiggerboss(s32);
    func_800F4AF4(func_80802248_chdiggerboss(arg0), 0x14);
    func_80802C40_chdiggerboss(arg0);
}

void func_80802C40_chdiggerboss(s32 arg0) {
    void _plcamera_entrypoint_9(s32, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F5EF8(s32);
    s32 func_80110014(s32 *);
    void func_80116088(u8 *, s32);
    f32 sp2C[3];
    s32 sp28;
    s32 sp24;

    sp24 = func_80802248_chdiggerboss(arg0);
    func_800EE7F8(sp2C, arg0 + 4);
    sp2C[1] += 500.0f;
    _plcamera_entrypoint_9(sp24, sp2C, 0.0f);
    func_80116088(func_80110014(func_800F5EF8(sp24)), sp2C);
}

void func_80802CB4_chdiggerboss()
{
    s32 func_80802248_chdiggerboss();
    func_800F4B20(func_80802248_chdiggerboss());
}

void func_80802CDC_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x42))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802D00_chdiggerboss.s")

void func_80802EF8_chdiggerboss(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802F00_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80802FEC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803078_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803224_chdiggerboss.s")

/* extern */

void func_80803338_chdiggerboss(s32 arg0) {
    s32 _gcnewoption_entrypoint_12(s32, s32, s16);
    s32 _gcnewoption_entrypoint_21(s32, s32);
    s32 var_s0;

    var_s0 = 0;
    do {
        _gcnewoption_entrypoint_12(arg0, var_s0, (s16) (var_s0 + 0xA));
        _gcnewoption_entrypoint_21(arg0, var_s0);
        var_s0 += 1;
    } while (var_s0 != 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808033A0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803424_chdiggerboss.s")

int func_80803524_chdiggerboss(u8 *array, s32 index) {
    return ((array + (index >> 3))[0] & (1 << (index & 7))) ? 1 : 0;
}

void func_80803558_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (arg1 >> 3) + arg0;
        *temp_v0 |= 1 << (arg1 & 7);
        return;
    }
    temp_v0_2 = (arg1 >> 3) + arg0;
    *temp_v0_2 &= ~(1 << (arg1 & 7));
}

/* extern */

void chdiggerboss_entrypoint_2(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_37(s32, s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 sp1C;
    u8 *sp18;
    s32 temp_a0;
    s32 temp_v0;

    temp_v0 = func_80106790(arg1);
    sp1C = temp_v0;
    sp18 = func_80100094(temp_v0, 0);
    temp_a0 = ((u8 *)func_80100094(sp1C, 0)) + 0x10C;
    if ((*(u8 *)((s8 *)(sp18) + (0x40))) == 2) {
        _gcnewoption_entrypoint_37(temp_a0, 1);
    }
}

/* extern */

void func_80803610_chdiggerboss(s32 arg0) {
    s32 func_800CE88C(s32, s32);
    s32 func_800CE928(s32, s32, s32);
    s32 func_800CEAA8(s32);
    s32 func_800CEBD8(s32, s32);
    if (func_800CEAA8(8) != 0) {
        func_800CE928(8, 0, 0);
        func_800CE88C(8, 0);
        func_800CEBD8(8, 0);
    }
}

s32 func_80803660_chdiggerboss(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    return _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x22);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803694_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808039C0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803BE8_chdiggerboss.s")

/* extern */

void func_80803DC8_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_8080041C_chdiggerboss(s32, s32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (4))) = (s8) arg1;
    if (arg2 != -1) {
        func_8080041C_chdiggerboss(arg0, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803E10_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80803E84_chdiggerboss.s")

void func_808040D8_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800E8C08(u8 a0);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(u8 *)((s8 *)(temp_v0) + (0xA))) != 0) {
        func_800E8C08((*(u8 *)((s8 *)(temp_v0) + (0xA))));
        (*(u8 *)((s8 *)(temp_v0) + (0xA))) = 0U;
    }
    (*(u8 *)((s8 *)(temp_v0) + (0xB))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xB))));
    (*(u8 *)((s8 *)(temp_v0) + (0xC))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xC))));
    (*(u8 *)((s8 *)(temp_v0) + (0xD))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xD))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804140_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808041E4_chdiggerboss.s")

u8 func_808042D8_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    return (*(u8 *)((s8 *)(func_80100094(arg0, 0)) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808042FC_chdiggerboss.s")

void func_808043D8_chdiggerboss(Actor *arg0, f32 arg1, f32 *arg2) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_800B53A4(s32);
    void func_800BAB80(s32, f32 *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80809FE0_chdiggerboss;
    f32 sp24[3];
    s32 sp20;

    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 7, sp24) != 0) {
        sp20 = func_800B53A4(1);
        func_800BAB80(sp20, arg2);
        func_800BABB8(sp20, sp24, arg0->position, arg1, &D_80809FE0_chdiggerboss);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804450_chdiggerboss.s")

s32 func_80804644_chdiggerboss(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg2 < arg0) && (arg1 <= arg2)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804680_chdiggerboss.s")

void func_80804784_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x1A))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808047A8_chdiggerboss.s")

void func_808049A8_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x1A))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x1A))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808049DC_chdiggerboss.s")

void func_80804A50_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = (s16) arg1;
}

/* extern */

void func_80804A7C_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_800E0AFC(s32, s32, f32, f32, f32, f32);
    func_800E0AFC(arg1, 0x2A, 1.0f, 0.0f, 0.0f, (*(f32 *)((s8 *)(func_80100094(arg0, 0)) + (0x1C))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804AC8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804C28_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804D44_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80804EFC_chdiggerboss.s")

void func_80804FE4_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    struct DiggerPart { s16 pad; s16 appendage; u8 gap[4]; f32 position[3]; u8 camera; u8 alpha; u8 visible; u8 tail[5]; };
    struct DiggerData { u8 prefix[0x34]; struct DiggerPart parts[0]; };
    void *func_80100094(Actor *, u32);
    s32 func_800A89F8();
    s32 func_800E8918(u8, s32, s32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800E3A58(f32 *);
    void func_800DF830(s32);
    void func_800DF744(s32, s32);
    void func_800DF410(s32);
    s32 func_800D674C(s32);
    void func_800DE498(s32, u8 *, f32 *, s32, s32, s32);
    struct DiggerData *data;
    f32 screen[2];
    s32 alpha;
    u8 camera;
    s32 visible;
    f32 xfade;
    f32 yfade;
    f32 rotation[3];

    data = (struct DiggerData *) func_80100094(arg0, 0);
    camera = data->parts[arg1].camera;
    alpha = 0;
    visible = func_800E8918(camera, func_800A89F8(), 0, screen);
    switch (visible) {
        case -1:
            if (data->parts[arg1].visible != 0) {
                xfade = 1.0f;
                yfade = 1.0f;
                if (screen[0] < -30.0f || screen[0] > 334.0f) {
                    xfade = -1.0f;
                } else if (screen[0] <= 0.0f && screen[0] >= -30.0f) {
                    xfade = func_800F10B4(screen[0], 0.0f, -30.0f, 1.0f, 0.0f);
                } else if (screen[0] >= 304.0f && screen[0] <= 334.0f) {
                    xfade = func_800F10B4(screen[0], 304.0f, 334.0f, 1.0f, 0.0f);
                }
                if (screen[1] < -30.0f || screen[1] > 258.0f) {
                    yfade = -1.0f;
                } else if (screen[1] <= 0.0f && screen[1] >= -30.0f) {
                    yfade = func_800F10B4(screen[1], 0.0f, -30.0f, 1.0f, 0.0f);
                } else if (screen[1] >= 228.0f && screen[1] <= 258.0f) {
                    yfade = func_800F10B4(screen[1], 228.0f, 258.0f, 1.0f, 0.0f);
                }
                if (yfade != -1.0f && yfade != -1.0f) {
                    alpha = (xfade + yfade) * 0.5f * 255.0f;
                    visible = 1;
                    break;
                }
            }
        case 0:
            alpha = data->parts[arg1].alpha * 0.25f;
            if (alpha != 0) {
                visible = 1;
            }
            break;
        case 1:
            alpha = 255;
            break;
        default:
            break;
    }
    data->parts[arg1].alpha = (data->parts[arg1].alpha + alpha) >> 1;
    if (visible == 1) {
        func_800E3A58(rotation);
        func_800DF830(0);
        func_800DF744(1, data->parts[arg1].appendage);
        func_800DF410(data->parts[arg1].alpha);
        func_800DE498(arg2, (u8 *) data->parts[arg1].position, rotation, *(s32 *)(arg0 + 0x38), 0, func_800D674C(0x954));
        data->parts[arg1].visible = 1;
    } else {
        data->parts[arg1].visible = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808053BC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805448_chdiggerboss.s")

void func_808056B8_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor*);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_8010A570((Actor *) arg0);
    (*(f32 *)((s8 *)(sp1C) + (0x2C))) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808056F8_chdiggerboss.s")

s16 func_80805798_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    return (*(s16 *)((s8 *)((((u8 *)func_80100094(arg0, 0)) + (arg1 * 0x1C))) + (0x34)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808057D0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808058B0_chdiggerboss.s")

void func_80805960_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s16 *)((s8 *)((((u8 *)func_80100094(arg0, 0)) + (arg1 * 0x1C))) + (0x36))) = (s16) arg2;
}

void func_808059A4_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    (*(s8 *)((s8 *)(temp_v0) + (0x24))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0x25))) = 0;
}

void func_808059CC_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x24))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x24))));
}

/* extern */

void func_80805A00_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_808027F4_chdiggerboss(s32);
    void func_80802C0C_chdiggerboss(s32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    func_808027F4_chdiggerboss(arg0);
    func_80803BE8_chdiggerboss(arg0, arg1, 1);
    func_80802C0C_chdiggerboss(arg0);
    (*(s8 *)((s8 *)(sp1C) + (0x25))) = 1;
    (*(f32 *)((s8 *)(sp1C) + (0x18))) = 1.5f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805A64_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805B8C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805C1C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805D64_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80805DF4_chdiggerboss.s")

void func_808062B8_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct DiggerState { f32 prefix[5]; f32 value; };
    struct DiggerActorState { f32 prefix[3]; f32 value; };
    struct DiggerState *sp1C;
    Actor *actor;

    sp1C = func_80100094(arg0, 0);
    actor = func_80802228_chdiggerboss(arg0);
    sp1C->value = 2.0f;
    ((struct DiggerActorState *)actor->actorData)->value = 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806300_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808063C8_chdiggerboss.s")

void func_808064CC_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s8 _subaddieaudioloop_entrypoint_7(u8, s32, s32, s32 *, s32);
    extern s32 D_8080A0EC_chdiggerboss;
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp24 = temp_v0;
    (*(s8 *)((s8 *)(sp24) + (0x24))) = _subaddieaudioloop_entrypoint_7((*(u8 *)((s8 *)(temp_v0) + (0x24))), arg0 + 4, arg1, &D_8080A0EC_chdiggerboss, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806528_chdiggerboss.s")

void func_80806648_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x78))) = 0;
}

void func_8080666C_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x78))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x78))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808066A0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806A78_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806B38_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806C08_chdiggerboss.s")

void func_80806CA4_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    switch (temp_v0->pad5C) {
    case 1:
        temp_v0->pad5C = 2;
        return;
    case 9:
        temp_v0->pad5C = 10;
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806CF8_chdiggerboss.s")

s32 func_80806D84_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(s32 *)((s8 *)(temp_v0) + (0x64))) != 0) {
        return func_80106790((*(s32 *)((s8 *)(temp_v0) + (0x64))));
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806DC4_chdiggerboss.s")

void func_80806EE4_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x5F))) = (s8) arg1;
}

u8 func_80806F10_chdiggerboss(Actor *arg0, u8 arg1) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    u8 func_800C4350(s32, f32[3], s32 *);
    void func_800C4B7C(s32);
    s32 func_800DC128(s32, s32);
    extern s32 D_8080A104_chdiggerboss;
    extern s16 D_8080A11C_chdiggerboss[];
    f32 *sp18[2];

    u8 *handle = &arg1;

    if (*handle == 0) {
        *handle = _subaddieaudioquick_entrypoint_1(arg0, arg0->position);
    }
    sp18[0] = arg0->position;
    func_800C4B7C(D_8080A11C_chdiggerboss[func_800DC128(0, 2)]);
    func_800C4350(*handle, sp18[0], &D_8080A104_chdiggerboss);
    return *handle;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80806F8C_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808070B0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807280_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807304_chdiggerboss.s")

s16 func_8080761C_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    return (*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (0x80)));
}

void func_80807640_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0xA0))) = 0;
}

void func_80807664_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0xA0))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xA0))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807698_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807754_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_8080783C_chdiggerboss.s")

void func_80807B18_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    (*(s8 *)((s8 *)(temp_v0) + (0xA4))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0xC8))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0xA6))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0xA7))) = 4;
}

void func_80807B4C_chdiggerboss(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807B54_chdiggerboss.s")

void func_80807DC0_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    (*(s8 *)((s8 *)(temp_v0) + (0xA5))) = 1;
    (*(s8 *)((s8 *)(temp_v0) + (0xA6))) = (s8) arg1;
}

void func_80807DF4_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;
    u8 temp_v1;

    temp_v0 = func_80100094(arg0, 0);
    temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (0xA4)));
    (*(s8 *)((s8 *)(temp_v0) + (0xA5))) = 0;
    if ((temp_v1 != 1) && (temp_v1 != 2) && (temp_v1 != 3)) {
        (*(u8 *)((s8 *)(temp_v0) + (0xA4))) = 4U;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80807E3C_chdiggerboss.s")

void func_80807FD8_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    (*(s32 *)((s8 *)(temp_v0) + (0xA8))) = 0;
    (*(s8 *)((s8 *)(temp_v0) + (0xA6))) = 0;
}

void func_80808000_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0xA6))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0xA6))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808034_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808080C0_chdiggerboss.s")

void func_8080815C_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor* func_801084B0(s32, Actor**);
    u8 *sp1C;
    sp1C = func_80100094(arg0, 0);
    if (arg1 == 3) {
        (*(s32 *)((s8 *)(sp1C) + (0xA8))) = (s32) func_801084B0(0x178, (Actor **) &arg0)->unk0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808081AC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808258_chdiggerboss.s")

void func_8080843C_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x78))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x78))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808470_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808560_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808085E0_chdiggerboss.s")

s32 func_808086A8_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(s32 *)((s8 *)(temp_v0) + (0xD4))) != 0) {
        return func_80106790((*(s32 *)((s8 *)(temp_v0) + (0xD4))));
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808086E8_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808087F0_chdiggerboss.s")

void func_808088AC_chdiggerboss(s32 arg0)
{
    func_80808B40_chdiggerboss(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808088CC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808948_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808089BC_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808B40_chdiggerboss.s")

void func_80808BE4_chdiggerboss(u8 *arg0, u8 *arg1, s32 arg2) {
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_80103014(u8 *);
    extern f32 D_8080A1AC_chdiggerboss[];
    extern f32 D_8080A1BC_chdiggerboss[];
    extern f32 D_8080A1CC_chdiggerboss[];

    func_800EEC30((f32 *)(arg1 + 4), D_8080A1BC_chdiggerboss[arg2], *(f32 *)(arg0 + 0x48) + D_8080A1AC_chdiggerboss[arg2], D_8080A1CC_chdiggerboss[arg2]);
    func_800EF04C((f32 *)(arg1 + 4), (f32 *)(arg0 + 4));
    func_80103014(arg1);
}

void func_80808C64_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    u8 *data;
    s32 i;

    data = func_80100094(arg0, 0);
    for (i = 0; i < 2; i++) {
        ((f32 *)(data + 0xC0))[i] = 0.0f;
    }
    func_800EE7F8((f32 *)(data + 0xD4), (f32 *)((u8 *)arg0 + 4));
    *(f32 *)(data + 0xE0) = *(f32 *)((u8 *)arg0 + 0x48);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808CD0_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80808D54_chdiggerboss.s")

void func_80808F44_chdiggerboss(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_801065A4();
    s32 _chdiggerboss_entrypoint_3();
    s32 sp1C;
    sp1C = func_801065A4();
    if (sp1C != 0) {
        _glid_entrypoint_0(sp1C, 1, (s32 *)_chdiggerboss_entrypoint_3, *arg0);
        _glid_entrypoint_0(sp1C, 2, (s32 *)_chdiggerboss_entrypoint_3, *arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/chdiggerboss_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809078_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809150_chdiggerboss.s")

/* extern */

s32 func_808091E4_chdiggerboss(s32 arg0) {
    u8 func_800D9078(f32*);
    void *func_80100094(Actor *, u32);
    s32 func_80809234_chdiggerboss(s32);
    if ((func_800D9078(((u8 *)func_80100094(arg0, 0)) + 0xE0) != 0) && (func_80809234_chdiggerboss(arg0) == 0)) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809234_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80809310_chdiggerboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808093F8_chdiggerboss.s")
