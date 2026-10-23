#include "common.h"

void func_80800000_chdiggerboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    void func_80800180_chdiggerboss(Actor *, s32);
    Actor *func_80802228_chdiggerboss(Actor *);
    extern u32 D_80809DB8_chdiggerboss;
    extern u32 D_80809DCC_chdiggerboss;
    extern u32 D_80809DE4_chdiggerboss;
    extern u32 D_80809DFC_chdiggerboss;
    extern u32 D_80809E10_chdiggerboss;
    struct DiggerBossData {
        u8 unk0[7];
        s8 unk7;
    };
    s32 pad[2];
    f32 *volatile position;
    f32 *nextPosition;

    switch (func_801022E4(arg0)) {
    case 0x435:
        _subaddieaudioquick_entrypoint_3(arg0, position = arg0->position, &D_80809DB8_chdiggerboss, 0.3f);
        nextPosition = position;
        _subaddieaudioquick_entrypoint_3(arg0, nextPosition, &D_80809DCC_chdiggerboss, 0.8f);
        break;
    case 0x43B:
        _subaddieaudioquick_entrypoint_3(arg0, position = arg0->position, &D_80809DB8_chdiggerboss, 0.5f);
        nextPosition = position;
        _subaddieaudioquick_entrypoint_3(arg0, nextPosition, &D_80809DCC_chdiggerboss, 0.85f);
        break;
    case 0x436:
        if (func_80101DDC(arg0)) {
            func_80800180_chdiggerboss(arg0, 5);
        }
        break;
    case 0x437:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80809DE4_chdiggerboss, 0.6f);
        break;
    case 0x440:
        _subaddieaudioquick_entrypoint_3(arg0, position = arg0->position, &D_80809DFC_chdiggerboss, 0.6f);
        nextPosition = position;
        _subaddieaudioquick_entrypoint_3(arg0, nextPosition, &D_80809E10_chdiggerboss, 0.85f);
        if (func_80101E14(arg0, 0.5f)) {
            ((struct DiggerBossData *)func_80100094(func_80802228_chdiggerboss(arg0), 0))->unk7 = 1;
        }
        break;
    }
}

void func_80800180_chdiggerboss(Actor *arg0, s32 arg1) {
    s32 func_801022E4(Actor *);
    void func_80102424(Actor *, s32);
    void func_808008C0_chdiggerboss(s32, s32, s32);
    Actor *func_80802228_chdiggerboss(Actor *);

    func_80102424(arg0, arg1);
    if (func_801022E4(arg0) != 0) {
        arg0->unk64_16 = 1;
    } else {
        arg0->unk64_16 = 0;
    }
    if (arg0->unk3C != NULL) {
        func_808008C0_chdiggerboss(func_80802228_chdiggerboss(arg0), 5, !arg0->unk64_16);
    }
}

void func_80800200_chdiggerboss(Actor *arg0) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, f32, f32);
    void func_8080041C_chdiggerboss(Actor *, s32);
    void func_808008C0_chdiggerboss(s32, s32, s32);
    Actor *func_808026F8_chdiggerboss(void *);
    void func_808041E4_chdiggerboss(Actor *, s32);
    void func_80807DC0_chdiggerboss(s32, s32);
    extern u32 D_80809DB8_chdiggerboss;
    extern u32 D_80809DCC_chdiggerboss;
    extern s32 D_80809E24_chdiggerboss;
    extern u32 D_80809E38_chdiggerboss;
    struct {
        u8 pad0[5];
        s8 unk5;
        s8 unk6;
        u8 pad7[0x99];
        u8 unkA0;
    } *data;
    f32 *position;
    s32 active;

    data = func_80100094(arg0, 0);
    switch (func_801022E4(arg0)) {
    case 0x42D:
        active = func_80102320(arg0, 0.2f, 0.9f);
        data->unkA0 = _subaddieaudioloop_entrypoint_7(data->unkA0, position = arg0->position, active, &D_80809E24_chdiggerboss, arg0->unk70_0);
        _subaddieaudioquick_entrypoint_3(arg0, position, &D_80809E38_chdiggerboss, 0.85f);
        if (func_80101DDC(arg0)) {
            func_808008C0_chdiggerboss(arg0, 1, 0);
            func_808008C0_chdiggerboss(arg0, 2, 0);
            func_8080041C_chdiggerboss(arg0, 0x13);
        }
        break;
    case 0x42E:
        if (func_80101DDC(arg0)) {
            data->unk6 = 1;
            func_8080041C_chdiggerboss(arg0, 1);
            func_808041E4_chdiggerboss(arg0, 1);
        }
        break;
    case 0x429:
    case 0x42B:
        active = func_80102320(arg0, 0.0f, 0.6f);
        data->unkA0 = _subaddieaudioloop_entrypoint_7(data->unkA0, position = arg0->position, active, &D_80809E24_chdiggerboss, arg0->unk70_0);
        _subaddieaudioquick_entrypoint_3(arg0, position, &D_80809E38_chdiggerboss, 0.65f);
        break;
    case 0x42F:
        _subaddieaudioquick_entrypoint_3(arg0, position = arg0->position, &D_80809DB8_chdiggerboss, 0.3f);
        _subaddieaudioquick_entrypoint_3(arg0, position, &D_80809DCC_chdiggerboss, 0.8f);
        if (func_80101DDC(arg0)) {
            data->unk5 = 1;
            func_8080041C_chdiggerboss(arg0, 1);
            func_80807DC0_chdiggerboss(func_808026F8_chdiggerboss(arg0), 1);
        }
        break;
    }
}

void func_8080041C_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_801022E4(Actor *);
    void func_80102424(Actor *, s32);
    void func_808008C0_chdiggerboss(s32, s32, s32);
    Actor *func_808026F8_chdiggerboss(void *);
    struct {
        u8 pad0[0x80];
        s16 unk80;
    } *sp20[2];
    s32 temp_v0;

    sp20[0] = func_80100094(func_808026F8_chdiggerboss(arg0), 0);
    func_80102424(arg0, arg1);
    temp_v0 = func_801022E4(arg0);
    switch (temp_v0) {
        case 0x429:
            func_808008C0_chdiggerboss(arg0, 3, 1);
            func_808008C0_chdiggerboss(arg0, 1, 1);
            break;
        case 0x42B:
            sp20[0]->unk80 = 1;
            func_808008C0_chdiggerboss(arg0, 4, 1);
            func_808008C0_chdiggerboss(arg0, 2, 1);
            break;
        case 0x42D:
            sp20[0]->unk80 = 0;
            break;
    }
}

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
    s32 func_80101808(Actor *, void (*)(Actor *));
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
    void *func_801040A8();
    s32 func_80806528_chdiggerboss(s32, s32, s32);
    func_80806528_chdiggerboss(arg0, func_800AE6BC(func_801040A8()), arg1);
}

void func_80800618_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)((((u8 *)func_80100094(arg0, 0)) + arg1)) + (0xFC))) = (s8) arg2;
}

void func_80800650_chdiggerboss(Actor *arg0, void *arg1) {
    s32 func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF830(s32);
    s32 func_800EB854(void);
    void func_801017D0(Actor *);
    s32 func_80101808(Actor *, void (*)(Actor *));
    void func_80804EFC_chdiggerboss(Actor *, void *);

    switch (func_800EB854()) {
        case 1:
            func_800DF830(0);
            func_800DF410(0xC0);
            func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, func_800D674C(0x959));
            break;
        case 0:
            func_80101808(arg0, func_801017D0);
            break;
        case 2:
            func_80804EFC_chdiggerboss(arg0, arg1);
            break;
    }
}

void func_808006F8_chdiggerboss(Actor *arg0, u8 *arg1) {
    void func_800AE1E8(s16, u8 *, s32);
    u8 *func_800B27E0(u8 *);
    void func_800DF72C(s32);
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    s32 func_801022E4(Actor *);
    void *func_801040A8(Actor *);
    s32 func_801040D0(void);
    extern s16 D_80809ED4_chdiggerboss;
    extern s16 D_80809EE0_chdiggerboss;
    s16 *var_s0;
    u8 *temp_s1;
    u8 *temp_s2;
    u8 *var_s1;

    temp_s2 = func_80100094(arg0, 0);
    func_801015D0(arg0);
    if (func_801022E4(arg0) == 0) {
        temp_s1 = func_800B27E0(arg1);
        func_800AE1E8(*(s16 *)&arg0->unk0->unk10, temp_s1, func_801040D0());
        func_800DF72C(func_801040A8(arg0));
    }
    var_s1 = temp_s2;
    var_s0 = &D_80809ED4_chdiggerboss; do {
        func_800DF744(*var_s0, var_s1[0xE4]);
        var_s0++;
        var_s1++;
    } while (var_s0 != &D_80809EE0_chdiggerboss);
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 0);
    func_800DF744(4, 0);
}

typedef struct {
    f32 unk0;
    f32 unk4[3];
    u8 unk10;
    u8 unk11;
    u8 pad12[2];
} Unkfunc_800E0960_2;

typedef struct {
    Unkfunc_800E0960_2 *unk0;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 padB;
    f32 unkC;
    s32 unk10[4];
} Unkfunc_800E0960_1;

void func_808007E0_chdiggerboss(Actor *arg0, u8 *arg1) {
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010262C(Unk80132ED0 *, u32);
    void func_800E0C20(Unkfunc_800E0960_1 *, u8, f32, f32, f32, f32);
    void func_808042FC_chdiggerboss(Actor *, Unkfunc_800E0960_1 *, u8 *);
    void func_80804A7C_chdiggerboss(s32, s32, s32);
    void func_80809078_chdiggerboss(Actor *, void *, s32);
    u8 *sp2C;
    Unkfunc_800E0960_1 *temp_v0;

    sp2C = func_80100094(arg0, 0);
    temp_v0 = func_8010262C(arg0->unk0, 0xC);
    func_808042FC_chdiggerboss(arg0, temp_v0, arg1);
    func_80804A7C_chdiggerboss((s32)arg0, (s32)temp_v0, (s32)arg1);
    func_80809078_chdiggerboss(arg0, temp_v0, (s32)arg1);
    if (sp2C[5] != 0) {
        func_800E0AFC(temp_v0, 0x52, 1.0f, -129.0f, 0.0f, 0.0f);
    }
    if (sp2C[6] != 0) {
        func_800E0C20(temp_v0, 0x50, 1.0f, 0.0f, 0.5f, 0.0f);
    }
}

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

s32 func_80801A04_chdiggerboss(Actor *arg0, s32 arg1, s32 arg2) {
    typedef union {
        s32 word;
        s16 half[2];
    } MessageData;
    Actor *func_801084B0(s32, Actor **);
    void *func_80100094(Actor *, u32);
    void *func_80101080(void);
    void func_80101010(s32);
    void func_80101074(s32);
    Actor *func_80802228_chdiggerboss(Actor *);
    s32 func_80802288_chdiggerboss(void *);
    s32 func_80802718_chdiggerboss(s32, s32, s32);
    s32 func_80802AB8_chdiggerboss(Actor *, s32);
    s32 func_80803660_chdiggerboss(Actor *, s32, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);

    void func_80800568_chdiggerboss(Actor *arg0, volatile s32 arg1);
    void func_80801DE0_chdiggerboss(Actor *);
    void func_80802298_chdiggerboss(u8 *, u8 *);
    void func_808029C8_chdiggerboss(Actor *);
    void func_80803078_chdiggerboss(Actor *, s32, s32, u32);
    void func_80803694_chdiggerboss(Actor *, s16, s16);
    void func_808039C0_chdiggerboss(Actor *, s16, s16);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    void func_80805448_chdiggerboss(Actor *, s32, s32);
    void func_80806CA4_chdiggerboss(Actor *, s32);
    void func_80806CF8_chdiggerboss(Actor *, s32);
    void func_80806DC4_chdiggerboss(Actor *, Unk80132ED0 *);
    void func_80807304_chdiggerboss(Actor *, s32);
    void func_80807E3C_chdiggerboss(Actor *, s32);
    void func_808085E0_chdiggerboss(Actor *, s32);
    void func_808086E8_chdiggerboss(Actor *, Unk80132ED0 *);
    void func_80809310_chdiggerboss(Actor *);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800FDC28(u32);
    s32 func_800D395C(void);
    extern u8 B_8080A300_chdiggerboss;
    Actor *other;
    s32 pad;
    s32 data;
    s32 i;
    f32 position[3];

    switch (arg1) {
        case 0x49:
            other = func_801084B0(0x203, &arg0);
            *(s32 *)((u8 *)arg0 + 0x3C) = *(s32 *)other;
            *(s32 *)((u8 *)other + 0x3C) = *(s32 *)arg0;
            break;
        case 0x57:
            return func_80802718_chdiggerboss((s32)arg0, arg2 & 0xFFFF,
                (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x20:
            func_80803078_chdiggerboss(arg0, func_80101080(),
                ((MessageData *)&arg2)->half[0], ((MessageData *)&arg2)->half[1]);
            break;
        case 0x95:
            func_80801DE0_chdiggerboss(arg0);
            break;
        case 0x0B:
            return func_80802AB8_chdiggerboss(arg0, arg2);
        case 0x2E:
            func_80803694_chdiggerboss(arg0,
                ((MessageData *)&arg2)->half[0], ((MessageData *)&arg2)->half[1]);
            break;
        case 0x2F:
            func_808039C0_chdiggerboss(arg0,
                ((MessageData *)&arg2)->half[0], ((MessageData *)&arg2)->half[1]);
            break;
        case 0x52:
            func_808029C8_chdiggerboss(arg0);
            break;
        case 0x1F:
            func_80800568_chdiggerboss(arg0, ((MessageData *)&arg2)->word);
            break;
        case 0x9C:
            func_808005DC_chdiggerboss((s32)arg0, ((MessageData *)&arg2)->word);
            break;
        case 0x40:
            if (((u8 *)func_80100094(arg0, 0))[3]) {
                func_808086E8_chdiggerboss(arg0, ((MessageData *)&arg2)->word);
            } else {
                func_80806DC4_chdiggerboss(arg0, ((MessageData *)&arg2)->word);
            }
            break;
        case 0x3D:
            switch (arg2) {
                case 0:
                    func_80806CF8_chdiggerboss(arg0, arg2);
                    break;
                case 1:
                case 2:
                    func_80807304_chdiggerboss(arg0, arg2);
                    break;
                case 4:
                    func_80807E3C_chdiggerboss(arg0, arg2);
                    break;
                case 5:
                    func_808085E0_chdiggerboss(arg0, arg2);
                    break;
            }
            break;
        case 0x96:
            if (func_800D395C() == 0) {
                return 0;
            }
            func_80803660_chdiggerboss(arg0, 0xCEB, 0x46);
            break;
        case 0x9F:
            data = (s32)func_80802228_chdiggerboss(arg0);
            i = 0;
            do {
                func_80805448_chdiggerboss(data, i, 0);
            } while (++i != 4);
            func_800FDC28(0);
            func_80800618_chdiggerboss((s32)arg0, 0, 0);
            if (func_80802288_chdiggerboss(arg0)) {
                func_800D395C();
                func_80803BE8_chdiggerboss(arg0, 0x48, 8);
            } else {
                func_80803BE8_chdiggerboss(arg0, 0x47, 2);
            }
            break;
        case 0x29:
            _suexpression_entrypoint_7(arg0, 1, 0x22);
            break;
        case 0x2A:
            _suexpression_entrypoint_8(arg0, 1);
            break;
        case 0xA2:
            if (!arg0->unk7C_12 ||
                !func_80802288_chdiggerboss(arg0)) {
                return 0;
            }
            func_80802298_chdiggerboss((u8 *)arg0, &B_8080A300_chdiggerboss);
            func_80101074((s32)&B_8080A300_chdiggerboss);
            break;
        case 0x90:
            func_80809310_chdiggerboss(arg0);
            break;
        case 0x8D:
            func_800EE7F8((u8 *)position, (s32)((u8 *)arg0 + 4));
            position[1] += 250.0f;
            func_80101010((s32)position);
            break;
        case 0xB5:
            func_80806CA4_chdiggerboss(arg0, arg2);
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_80801DE0_chdiggerboss.s")

u16 func_80802158_chdiggerboss(s32 arg0, s32 arg1) {
    extern s32 D_80809EE4_chdiggerboss;
    return *(u16 *)((u8 *)&D_80809EE4_chdiggerboss + (arg1 * 2));
}

int func_80802170_chdiggerboss(Actor *arg0, s32 arg1) {
    s32 func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    u8 *data;
    s32 flag;

    data = func_80100094(arg0, 0);
    if (*(data + arg1 + 0xFD) == 0) {
        flag = func_80802158_chdiggerboss(arg0, arg1);
        if (flag != 0) {
            func_800DA544(flag);
        }
        *(data + arg1 + 0xFD) = 1;
        return 0;
    }
    return 1;
}

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
    u32 func_800F54E4(void);
    s32 func_8010D290(s32);
    s32 temp_v0;
    int var_v1;
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
  void func_800EF1B8(f32 *, f32, f32);
  func_800EE7F8(arg1, arg0 + 4);
  func_800EF1B8(arg1, *((f32 *) (((s8 *) arg0) + 0x48)), (*((f32 *) (((s8 *) arg0) + 0x38))) * 600.0f);
  *((f32 *) (((s8 *) arg1) + 4)) = (f32) (((*((f32 *) (((s8 *) arg0) + 0x38))) * 2500.0f) + (*((f32 *) (((s8 *) arg1) + 4))));
}

/* extern */

s32 func_80802314_chdiggerboss(void) {
    s32 func_800DA980(s32, s32);
    return 2 - func_800DA980(0xA4F, 2);
}

void func_8080233C_chdiggerboss(Actor *arg0) {
    void func_80102FDC(void *, f32);
    void func_80108B04(Actor *, u32);
    void func_8010A828(void **, s32);
    void func_80803DC8_chdiggerboss(s32, s32, s32);
    void func_80803E10_chdiggerboss(Actor *);
    void func_80804784_chdiggerboss(s32);
    void func_80804C28_chdiggerboss(s32);
    void func_80807640_chdiggerboss(s32);
    void func_80807FD8_chdiggerboss(s32);
    void func_808088AC_chdiggerboss(s32);
    void func_80808C64_chdiggerboss(Actor *);
    func_80102FDC(arg0, 0.25f);
    func_8010A828(arg0, 3);
    func_80803DC8_chdiggerboss(arg0, 1, 1);
    func_808008C0_chdiggerboss(arg0, 5, 1);
    func_80803E10_chdiggerboss(arg0);
    func_80804784_chdiggerboss(arg0);
    func_80804C28_chdiggerboss(arg0);
    func_80807640_chdiggerboss(arg0);
    func_80807FD8_chdiggerboss(arg0);
    func_808088AC_chdiggerboss(arg0);
    func_80808C64_chdiggerboss(arg0);
    func_80108B04(arg0, 7);
}

void func_808023D8_chdiggerboss(Actor *arg0) {
    void _subaddieDll_entrypoint_7(Actor *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F4E5C(s32, s32, s32, s32, s32);
    s32 func_800F6438(u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_808026F8_chdiggerboss(void *);
    void func_80803E84_chdiggerboss(Actor *);
    void func_808047A8_chdiggerboss(Actor *);
    void func_80804D44_chdiggerboss(s32);
    void func_80808034_chdiggerboss(Actor *);
    void func_808088CC_chdiggerboss(Actor *);
    void func_80808CD0_chdiggerboss(Actor *);
    extern u32 D_80809F04_chdiggerboss;
    extern s32 D_80809F10_chdiggerboss;
    extern s32 D_80809F1C_chdiggerboss;
    struct DiggerBossUpdateData {
        Unk80132ED0 *unk0;
        u8 unk4[3];
        u8 unk7;
    } *data;
    Actor *actor;
    f32 *position;
    s32 i;

    data = func_80100094(arg0, 0);
    func_80800200_chdiggerboss(arg0);
    func_80803E84_chdiggerboss(arg0);
    func_808047A8_chdiggerboss(arg0);
    func_80804D44_chdiggerboss(arg0);
    func_80808034_chdiggerboss(arg0);
    func_808088CC_chdiggerboss(arg0);
    func_80808CD0_chdiggerboss(arg0);
    position = arg0->position;
    _subaddieaudioloop_entrypoint_4(arg0, position, data->unk7, &D_80809F04_chdiggerboss);
    if (data->unk7 != 0) {
        _subaddieDll_entrypoint_7(arg0, 8);
    }
    for (i = 0; i != 8; i++) {
        if (func_800F6438(i) != 0) {
            func_800F4E5C(i, position, arg0->rotation, &D_80809F10_chdiggerboss, &D_80809F1C_chdiggerboss);
        }
    }
    if (arg0->unk3C != NULL) {
        actor = func_808026F8_chdiggerboss(arg0);
        func_800EE7F8(actor->position, position);
        actor->rotation[1] = arg0->rotation[1];
    }
    if (data->unk0 != NULL) {
        actor = func_80106790(data->unk0);
        func_800EE7F8(actor->position, position);
        actor->position[1] += 300.0f;
    }
}

void func_80802550_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800FFA88(Unk80132ED0 *);
    s32 func_801069A4(Unk80132ED0 *);
    void func_808040D8_chdiggerboss(s32);
    void func_808049A8_chdiggerboss(s32);
    void func_808053BC_chdiggerboss(Actor *);
    void func_80807664_chdiggerboss(s32);
    void func_80808000_chdiggerboss(s32);
    void func_80808948_chdiggerboss(Actor *);
    Actor *sp24;

    sp24 = func_80100094(arg0, 0);
    func_808040D8_chdiggerboss(arg0);
    func_808049A8_chdiggerboss(arg0);
    func_808053BC_chdiggerboss(arg0);
    func_80807664_chdiggerboss(arg0);
    func_80808000_chdiggerboss(arg0);
    func_80808948_chdiggerboss(arg0);
    if (func_801069A4(sp24->unk0) != 0) {
        func_800FFA88(sp24->unk0);
        sp24->unk0 = NULL;
    }
}

s32 func_808025D4_chdiggerboss(Actor *arg0, s32 arg1, u8 *arg2) {
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(s32, Actor **);
    void func_808058B0_chdiggerboss(Actor *, void *);
    void func_8080815C_chdiggerboss(s32, s32);
    void func_808089BC_chdiggerboss(Actor *, s32);
    Actor *sp1C;

    switch (arg1) {
        case 0x1F:
            func_808006F8_chdiggerboss(arg0, arg2);
            break;
        case 0x9C:
            func_808007E0_chdiggerboss(arg0, arg2);
            break;
        case 0x3D:
            switch (*(s32 *)&arg2) {
                case 3:
                    func_8080815C_chdiggerboss((s32)arg0, (s32)arg2);
                    break;
                case 6:
                    func_808089BC_chdiggerboss(arg0, (s32)arg2);
                    break;
                case 7:
                    sp1C = func_80100094(arg0, 0);
                    sp1C->unk0 = func_801084B0(0x4FF, &arg0)->unk0;
                    break;
            }
            break;
        case 0x3F:
            func_808058B0_chdiggerboss(arg0, arg2);
            break;
        case 0x95:
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

Actor *func_808026F8_chdiggerboss(void *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    return func_80106790((*(s32 *)((s8 *)(arg0) + (0x3C))));
}

/* extern */

s32 func_80802718_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80802878_chdiggerboss(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (8))) != 2) {
            func_80802878_chdiggerboss(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

void func_80802778_chdiggerboss(Actor *arg0, s32 arg1) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    s32 func_800F7F98(s32, u32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    _capod_entrypoint_2(arg0->unk0, 0x22, arg1 | 0x80000);
    if (*(s16 *)(sp1C + 0xA) == 0) {
        func_800F7F98(func_80802248_chdiggerboss(arg0), 1);
        *(s16 *)(sp1C + 0xA) = 1;
    }
}

s32 func_808027F4_chdiggerboss(s32 arg0) {
    void _capod_entrypoint_3(u32);
    void _plcamera_entrypoint_8(s32);
    s32 func_800F7F98(s32, u32);
    void *func_80100094(Actor *, u32);
    int result;
    s32 sp20;
    u8 *data;

    data = func_80100094(arg0, 0);
    sp20 = func_80802248_chdiggerboss(arg0);
    if (*(s16 *)(data + 0xA) != 0) {
        func_800F7F98(sp20, 0);
        *(s16 *)(data + 0xA) = 0;
    }
    if (*(s16 *)(data + 8) != 0) {
        _capod_entrypoint_3(0);
        _plcamera_entrypoint_8(sp20);
        *(s16 *)(data + 8) = 0;
        return 1;
    }
    return 0;
}

void func_80802878_chdiggerboss(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_808029C8_chdiggerboss(Actor *);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_8(void);
    s16 *data;

    data = func_80100094(arg0, 0U);
    switch (data[4]) {
        case 0:
            func_80802778_chdiggerboss(arg0, 0);
        case 1:
            _capod_entrypoint_8(1);
            data[4] = 2;
        case 2:
            func_808029C8_chdiggerboss(arg0);
            _gcdialogcamera_entrypoint_8();
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_8080290C_chdiggerboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802938_chdiggerboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802938_chdiggerboss(arg0, arg0->unk0, arg1, arg2);
}

void func_80802938_chdiggerboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    s16 *data;

    data = func_80100094(arg0, 0U);
    switch (data[4]) {
        case 0:
            func_80802778_chdiggerboss(arg0, arg3);
        case 2:
            data[4] = 1;
        case 1:
            _capod_entrypoint_6(arg1, arg2, arg3 | 0x80000);
            break;
    }
}

void func_808029C8_chdiggerboss(Actor *arg0) {
    s32 _gcdialogcamera_entrypoint_3(f32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp30[4];
    s32 pad2C;
    f32 *sp28;
    f32 temp_f0;
    f32 temp_f2;

    sp28 = func_80100094(arg0, 0);
    func_800EE7F8(sp4C, arg0->rotation);
    sp4C[1] += sp28[4];
    func_800EE7F8(sp40, arg0->position);
    func_800EF1B8(sp40, arg0->rotation[1], arg0->scale * 400.0f);
    temp_f0 = arg0->scale;
    temp_f2 = temp_f0;
    temp_f2 *= sp28[3];
    sp30[0] = temp_f0 * 2700.0f;
    sp30[1] = 800.0f * temp_f2;
    sp30[2] = 500.0f * temp_f2;
    sp30[3] = arg0->scale * 2100.0f;
    _gcdialogcamera_entrypoint_3(sp30, 1.0f);
    _gcdialogcamera_entrypoint_4(sp40);
    _gcdialogcamera_entrypoint_5(sp4C);
}

s32 func_80802AB8_chdiggerboss(Actor *arg0, s32 arg1) {
    s32 func_800DA544(s32);
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _gcgoto_entrypoint_2(s32, s32, s32);
    void func_800A7AD4(s32, s32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    s32 func_80803660_chdiggerboss(Actor *, s32, s32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    void func_80805D64_chdiggerboss(Actor *, s32);

    switch (arg1) {
        case 0x1C:
            func_8080290C_chdiggerboss(arg0, 0x1F, 0x20);
            return 4;
        case 0x1F:
            func_800F82D4(func_800F54E4(), 0);
            _gcgoto_entrypoint_2(0x19A, 1, 0);
            func_800A7AD4(1, 0x15);
            break;
        case 0xD:
            func_800F82D4(func_800F54E4(), 0);
            func_80803660_chdiggerboss(arg0, 0x171D, 0x14C);
            func_8080290C_chdiggerboss(arg0, 0x18, 0x20);
            return 4;
        case 0x18:
            func_800DA544(0x44);
            _gcfrontend_entrypoint_9(0x2C);
            func_80802878_chdiggerboss(arg0, 3, 1);
            func_80803BE8_chdiggerboss((s32)arg0, 2, 2);
            return 4;
        case 0x3B:
            func_80805D64_chdiggerboss(arg0, 0x27);
            return 4;
    }
    return 3;
}

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

s32 func_80802D00_chdiggerboss(Actor *arg0) {
    s32 _gcnewoption_entrypoint_0(s32);
    s32 _gcnewoption_entrypoint_37(s32, s32);
    s32 _gcnewoption_entrypoint_7(u8 *);
    u8 func_800D9078(f32 *);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_8010A828(void **, s32);
    void func_80803224_chdiggerboss(Actor *);
    s32 func_80803660_chdiggerboss(Actor *, s32, s32);
    struct DiggerBossData {
        u8 pad0[0x40];
        u8 state;
        u8 flag;
        s8 unk42;
        u8 pad43[3];
        s16 unk46;
        u8 pad48[4];
        f32 unk4C;
        u8 pad50[0xBC];
        u8 option[1];
    } *data;
    u8 *option;

    data = func_80100094(arg0, 0);
    option = ((struct DiggerBossData *)func_80100094(arg0, 0))->option;
    switch (data->state) {
    case 0:
        break;
    case 1:
        func_80803224_chdiggerboss(arg0);
        break;
    case 2:
        _gcnewoption_entrypoint_0((s32)option);
        break;
    case 3:
        _gcnewoption_entrypoint_0((s32)option);
        if (func_800D9078(&data->unk4C)) {
            _gcnewoption_entrypoint_37((s32)option, 1);
        }
        break;
    case 4:
        _gcnewoption_entrypoint_7(option);
        data->unk42 = 0;
        func_8010A828(arg0, 1);
        if (data->flag && !func_80802170_chdiggerboss(arg0, 3)) {
            func_80802878_chdiggerboss(arg0, 5, 1);
            func_80803660_chdiggerboss(arg0, 0x172F, 0x106);
            data->state = 6;
            data->unk46 = 1;
        } else if (!data->flag && !func_80802170_chdiggerboss(arg0, 4)) {
            func_80802878_chdiggerboss(arg0, 5, 1);
            func_80803660_chdiggerboss(arg0, 0x1730, 0x106);
            data->state = 6;
            data->unk46 = 1;
        } else {
            func_80800180_chdiggerboss(arg0, 6);
            data->state = 5;
        }
        break;
    case 5:
        if (func_80101DDC(arg0)) {
            func_800F82D4(func_800F54E4(), 0);
            func_80800618_chdiggerboss((s32)arg0, 0, 0);
            func_80800180_chdiggerboss(arg0, 8);
            data->state = 0;
            return 1;
        }
        break;
    case 6:
        if (data->unk46 == 0) {
            func_80800180_chdiggerboss(arg0, 6);
            data->state = 5;
        }
        break;
    }
    return 0;
}

void func_80802EF8_chdiggerboss(s32 arg0) 
{
}
void func_80802F00_chdiggerboss(s32 arg0, s32 arg1) {
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F7F98(s32, u32);
    s32 func_800F8418(s32, f32 *);
    void func_80802878_chdiggerboss(Actor *, s32, s32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    void func_808056B8_chdiggerboss(s32);
    s32 sp44;
    f32 sp38[3];
    f32 sp2C[3];

    func_80803BE8_chdiggerboss(arg0, arg1, 2);
    func_80802878_chdiggerboss(arg0, 3, 1);
    func_80800618_chdiggerboss(arg0, 0, 1);
    func_808056B8_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0));
    sp44 = func_800F54E4();
    func_800F5A00(sp44, sp38);
    if (func_800EFB8C(sp38, (f32 *)(arg0 + 4)) < 550.0f) {
        func_800EEB9C(sp2C, func_800F1DF4((f32 *)(arg0 + 4), sp38), 550.0f);
        func_800EF04C(sp2C, (f32 *)(arg0 + 4));
        sp2C[1] = sp38[1];
        func_800F8418(sp44, sp2C);
    }
    func_800F7F98(sp44, 1);
}

void func_80802FEC_chdiggerboss(Actor *arg0, s32 arg1, s32 arg2) {
    u32 func_800F54E4(void);
    s32 func_800F7F98(s32, u32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    s32 func_80803424_chdiggerboss(Actor *, s32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    typedef struct {
        u8 pad0[0x40];
        s8 unk40;
        u8 pad41[2];
        s8 unk43;
        u16 unk44;
    } DiggerBossData;
    DiggerBossData *sp1C;

    sp1C = func_80100094(arg0, 0);
    sp1C->unk40 = 1;
    sp1C->unk43 = arg2;
    sp1C->unk44 = func_80803424_chdiggerboss(arg0, arg2);
    func_800F7F98(func_800F54E4(), 0);
    func_800F8300(func_800F54E4(), 2, arg0->position);
    func_80803BE8_chdiggerboss(arg0, arg1, 4);
}

void func_80803078_chdiggerboss(Actor *arg0, s32 arg1, s32 arg2, u32 arg3) {
    void *func_80100094(Actor *, u32);
    void func_80803338_chdiggerboss(s32);
    void func_80803610_chdiggerboss(s32);
    s32 _gcnewoption_entrypoint_3(s32);
    s32 _gcnewoption_entrypoint_37(s32, s32);
    s32 _gcnewoption_entrypoint_38(s32, s32);
    s32 func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800CE928(s32, s32, s32);
    void func_800CEA38(s32, s32);
    void func_800FC660(u32);
    extern s32 _chdiggerboss_entrypoint_2;
    typedef struct {
        u8 pad0[0x40];
        s8 unk40;
        s8 unk41;
        u8 pad42[6];
        u8 unk48;
        u8 pad49[3];
        f32 unk4C;
    } DiggerBossData;
    DiggerBossData *data;
    s32 pad20;
    s32 success;
    s32 pad18;

    data = func_80100094(arg0, 0);
    switch (arg3) {
    case 0:
        func_80803338_chdiggerboss(arg1);
        break;
    case 2:
        func_80803610_chdiggerboss(arg0);
        data->unk40 = 4;
        break;
    case 4:
        success = _gcnewoption_entrypoint_3(arg1) == arg2;
        data->unk48 = 0;
        data->unk41 = success;
        func_80803610_chdiggerboss(arg0);
        if (success) {
            _gcnewoption_entrypoint_38(arg1, 1);
            func_800FC660(0xE);
        } else {
            _gcnewoption_entrypoint_37(arg1, 1);
            func_800FC660(0xF);
        }
        break;
    case 5:
        data->unk41 = 0;
        data->unk48 = 0;
        func_80803610_chdiggerboss(arg0);
        _gcnewoption_entrypoint_37(arg1, 1);
        func_800FC660(0xF);
        break;
    case 3:
        func_80803610_chdiggerboss(arg0);
        data->unk40 = 4;
        break;
    case 9:
        func_800CE8D8(8, 5.0f, 5);
        func_800CE928(8, &_chdiggerboss_entrypoint_2, arg0->unk0);
        func_800CEA38(8, 1);
        func_800CE88C(8, 1);
        break;
    case 10:
        if (!data->unk48) {
            data->unk40 = 3;
            data->unk4C = 0.4f;
        }
        break;
    }
}

void func_80803224_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A828(void **, s32);
    s32 _gcnewoption_entrypoint_2(void);
    void _gcnewoption_entrypoint_5(s32, void *, u8, u16, s32);
    s32 _gcnewoption_entrypoint_8(s32, s32);
    s32 _gcnewoption_entrypoint_9(s32, s32);
    s32 _gcnewoption_entrypoint_10(s32, s32);
    void _gcnewoption_entrypoint_11(s32);
    s32 _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    void _gcnewoption_entrypoint_28(s32);
    void _gcnewoption_entrypoint_29(s32, s32);
    void _gcnewoption_entrypoint_30(s32, s32 *);
    s32 _gcnewoption_entrypoint_32(s32, s32);
    void bzero(void *, int);
    extern s32 _gcnewoption_entrypoint_35;
    extern s32 D_80809F34_chdiggerboss;
    typedef struct {
        u8 pad0[0x40];
        s8 unk40;
        u8 pad41;
        s8 unk42;
        u8 pad43;
        u16 unk44;
        u8 pad46[2];
        s8 unk48;
        u8 pad49[0xC3];
        u8 options[0x260];
    } DiggerBossData;
    s32 options;
    DiggerBossData *data;

    data = func_80100094(arg0, 0);
    options = ((DiggerBossData *)func_80100094(arg0, 0))->options;
    bzero(options, _gcnewoption_entrypoint_2());
    _gcnewoption_entrypoint_5(options, &_gcnewoption_entrypoint_35, 0, data->unk44, arg0->unk0);
    _gcnewoption_entrypoint_8(options, 3);
    _gcnewoption_entrypoint_9(options, 3);
    _gcnewoption_entrypoint_10(options, 2);
    _gcnewoption_entrypoint_14(options, 0, 0, 0, 4.0f);
    _gcnewoption_entrypoint_32(options, 0x22);
    _gcnewoption_entrypoint_30(options, &D_80809F34_chdiggerboss);
    _gcnewoption_entrypoint_28(options);
    _gcnewoption_entrypoint_29(options, 1);
    _gcnewoption_entrypoint_11(options);
    data->unk40 = 2;
    data->unk42 = 1;
    data->unk48 = 1;
    func_8010A828(arg0, 9);
}

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

void *func_808033A0_chdiggerboss(Actor *arg0, s32 arg1, s32 *arg2) {
    void *func_80100094(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0:
            *arg2 = 0x14;
            return data + 0x50;
        case 1:
            *arg2 = 0x14;
            return data + 0x53;
        case 2:
            *arg2 = 0x14;
            return data + 0x56;
        default:
            return NULL;
    }
}

s32 func_80803424_chdiggerboss(Actor *arg0, s32 arg1) {
    s32 func_800DC128(s32, s32);
    int func_80803524_chdiggerboss(u8 *, s32);
    void func_80803558_chdiggerboss(s32, s32, s32);
    void bzero(void *, int);
    extern u16 D_80809F28_chdiggerboss[][2];
    s32 count;
    s32 index;
    s32 i;
    u8 *array;

    array = func_808033A0_chdiggerboss(arg0, arg1, &count);
    index = func_800DC128(0, count);
    for (i = 0; i < count; i++) {
        if (func_80803524_chdiggerboss(array, index) == 0) {
            func_80803558_chdiggerboss((s32)array, index, 1);
            return D_80809F28_chdiggerboss[arg1][0] + index;
        }
        index++;
        if (index == count) {
            index = 0;
        }
    }
    bzero(array, (count + 7) >> 3);
    index = func_800DC128(0, count);
    func_80803558_chdiggerboss((s32)array, index, 1);
    return D_80809F28_chdiggerboss[arg1][0] + index;
}

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

s32 func_80803BE8_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80800180_chdiggerboss(Actor *, s32);
    Actor *func_80802228_chdiggerboss(Actor *);
    void func_80805448_chdiggerboss(Actor *, s32, s32);
    s32 i;
    struct {
        s16 unk0;
        u8 pad2[0x1A];
        f32 unk1C;
        f32 unk20;
        u8 pad24[0xC];
        f32 unk30;
        f32 unk34;
        f32 unk38;
        f32 unk3C;
    } *data;

    data = func_80100094((Actor *)arg0, 0);
    data->unk0 = arg1;
    if (arg2 != -1) {
        func_80800180_chdiggerboss((Actor *)arg0, arg2);
    }
    switch (arg1) {
        case 6:
            func_80805448_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0), 0, 1);
            func_80805448_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0), 2, 1);
            data->unk20 = 40.0f;
            data->unk1C = 10.0f;
            break;
        case 14:
            for (i = 0; i != 4; i++) {
                func_80805448_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0), i, 1);
            }
            data->unk1C = 10.0f;
            data->unk20 = -60.0f;
            break;
        case 39:
            func_80805448_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0), 0, 1);
            func_80805448_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0), 3, 1);
            data->unk30 = 5.0f;
            data->unk34 = 5.0f;
            data->unk3C = 40.0f;
            data->unk20 = 40.0f;
            data->unk38 = 250.0f;
            break;
        case 49:
            for (i = 0; i != 4; i++) {
                func_80805448_chdiggerboss(func_80802228_chdiggerboss((Actor *)arg0), i, 1);
            }
            data->unk30 = 5.0f;
            data->unk34 = 5.0f;
            data->unk3C = 60.0f;
            data->unk38 = 350.0f;
            data->unk20 = -60.0f;
            break;
    }
}

/* extern */

void func_80803DC8_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_8080041C_chdiggerboss(Actor *, s32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (4))) = (s8) arg1;
    if (arg2 != -1) {
        func_8080041C_chdiggerboss(arg0, arg2);
    }
}

void func_80803E10_chdiggerboss(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    u8 func_800E8B74(u32);
    void func_800E8D5C(u8, void *, s16);
    void *func_80100094(Actor *, u32);
    extern u8 D_80809F98_chdiggerboss[];
    struct {
        u8 pad0[0xA];
        u8 unkA;
        u8 unkB;
        u8 unkC;
        u8 unkD;
        u8 padE[6];
        f32 unk14;
    } *data, *temp;

    temp = func_80100094(arg0, 0);
    data = temp;
    temp->unkB = 0;
    temp->unkC = 0;
    temp->unkD = 0;
    data->unk14 = func_800DC178(0.85f, 2.5f);
    data->unkA = func_800E8B74(0);
    func_800E8D5C(data->unkA, D_80809F98_chdiggerboss, 3);
}

void func_80803E84_chdiggerboss(Actor *arg0) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_8001210C(s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    u8 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80804140_chdiggerboss(Actor *);
    void func_808041E4_chdiggerboss(Actor *, s32);
    void func_808043D8_chdiggerboss(Actor *, f32, f32 *);
    void func_80804450_chdiggerboss(Actor *);
    void func_80804680_chdiggerboss(Actor *);
    extern f32 D_80809F3C_chdiggerboss;
    extern f32 D_80809F40_chdiggerboss;
    extern u32 D_80809F44_chdiggerboss;
    extern s32 D_80809FB0_chdiggerboss;
    extern s32 D_80809FC0_chdiggerboss;
    extern s32 D_80809FD0_chdiggerboss;
    struct {
        u8 pad0[8];
        u8 state;
        u8 count;
        u8 loopA;
        u8 loopB;
        u8 loopC;
        u8 loopD;
        u8 padE[2];
        f32 timer;
        f32 timer14;
    } *data;
    f32 volume;
    s32 rate;

    data = func_80100094(arg0, 0);
    switch (data->state) {
        case 0:
            break;
        case 1:
            data->loopD = _subaddieaudioloop_entrypoint_7(data->loopD, arg0->position, 1, &D_80809FB0_chdiggerboss, arg0->unk70_0);
            if (func_800D9078(&data->timer)) {
                func_808041E4_chdiggerboss(arg0, 2);
            }
            break;
        case 2:
            volume = func_800F10B4(*(f32 *)&arg0->actorData[3], 0.0f, 350.0f, 0.85f, 1.1f);
            rate = (s32)func_800F10B4(*(f32 *)&arg0->actorData[3], 0.0f, 350.0f, 25000.0f, 32000.0f);
            if (data->loopB == 0) {
                func_800C4B64(volume);
                func_800C4B70(rate);
            }
            data->loopB = _subaddieaudioloop_entrypoint_7(data->loopB, arg0->position, 1, &D_80809FC0_chdiggerboss, arg0->unk70_0);
            if (data->loopB != 0) {
                func_800C31DC(data->loopB, volume);
                func_800C3058(data->loopB, rate);
            }
            if (func_80802314_chdiggerboss() < 2 && func_800D90A4(&data->timer14)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
                data->timer14 = func_800DC178(0.85f, 2.5f);
                data->count = 4;
            }
            func_80804680_chdiggerboss(arg0);
            if (func_8001210C(1)) {
                if (data->count != 0) {
                    func_808043D8_chdiggerboss(arg0, 1.25f, &D_80809F3C_chdiggerboss);
                    data->count--;
                } else {
                    func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F40_chdiggerboss);
                }
            }
            break;
        case 3:
            data->loopC = _subaddieaudioloop_entrypoint_7(data->loopC, arg0->position, 1, &D_80809FD0_chdiggerboss, arg0->unk70_0);
            break;
        case 4:
            func_80804450_chdiggerboss(arg0);
            break;
    }
    func_80804140_chdiggerboss(arg0);
}

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

void func_80804140_chdiggerboss(Actor *arg0) {
    void func_800E8D28(u8, f32);
    void func_800E8DB0(u8, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    s32 sp28;
    f32 sp24;

    sp2C = func_80100094(arg0, 0);
    sp28 = (s32)func_800F10B4(*(f32 *)((u8 *)arg0 + 0x24), 0.0f, 350.0f, 15.0f, 25.0f);
    sp24 = func_800F10B4(*(f32 *)((u8 *)arg0 + 0x24), 0.0f, 350.0f, 0.35f, 0.2f);
    func_800E8DB0(sp2C[0xA], sp28);
    func_800E8D28(sp2C[0xA], sp24);
}

void func_808041E4_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    struct {
        u8 unk0[8];
        u8 state;
        u8 unk9[2];
        u8 loopB;
        u8 loopC;
        u8 loopD;
        u8 unkE[2];
        f32 timer;
    } *data;

    data = func_80100094(arg0, 0);
    data->state = arg1;
    switch (arg1) {
    case 0:
        data->loopB = _subaddieaudioloop_entrypoint_3(data->loopB);
        data->loopC = _subaddieaudioloop_entrypoint_3(data->loopC);
        data->loopD = _subaddieaudioloop_entrypoint_3(data->loopD);
        break;
    case 1:
        data->timer = 1.4f;
        break;
    case 2:
        data->loopC = _subaddieaudioloop_entrypoint_3(data->loopC);
        data->loopD = _subaddieaudioloop_entrypoint_3(data->loopD);
        break;
    case 3:
        data->loopB = _subaddieaudioloop_entrypoint_3(data->loopB);
        data->loopD = _subaddieaudioloop_entrypoint_3(data->loopD);
        break;
    case 4:
        data->loopB = _subaddieaudioloop_entrypoint_3(data->loopB);
        data->loopC = _subaddieaudioloop_entrypoint_3(data->loopC);
        data->loopD = _subaddieaudioloop_entrypoint_3(data->loopD);
        data->timer = 0.0f;
        break;
    }
}

u8 func_808042D8_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    return (*(u8 *)((s8 *)(func_80100094(arg0, 0)) + (8)));
}

void func_808042FC_chdiggerboss(Actor *arg0, Unkfunc_800E0960_1 *arg1, u8 *arg2) {
    f32 _dbskeleton_entrypoint_1(void *);
    u8 *func_800B27E0(u8 *);
    void func_800E0C20(Unkfunc_800E0960_1 *, u8, f32, f32, f32, f32);
    s32 func_800E8C58(u8);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;
    f32 sp30;
    f32 sp2C;
    f32 rotation[3];

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0[8] != 0) {
        sp30 = (f32)func_800E8C58(temp_v0[0xA]);
        sp2C = 1.0f / _dbskeleton_entrypoint_1(func_800B27E0(arg2));
        func_800E0C20(arg1, 3, sp2C, 0.0f, sp30, 0.0f);
        rotation[1] = -sp30;
        func_800E0C20(arg1, 0xA, sp2C, 0.0f, rotation[1], 0.0f);
        func_800E0C20(arg1, 0x18, sp2C, 0.0f, rotation[1], 0.0f);
    }
}

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

void func_80804450_chdiggerboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    int func_800D91EC(f32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80804644_chdiggerboss(f32, f32, f32);
    extern f32 D_80809F3C_chdiggerboss;
    extern f32 D_80809F40_chdiggerboss;
    extern u32 D_80809F44_chdiggerboss;
    extern u32 D_80809F5C_chdiggerboss;
    extern u32 D_80809F74_chdiggerboss;
    extern u32 D_80809F88_chdiggerboss;
    struct DiggerBossTimerData {
        u8 unk0[0x10];
        f32 timer;
    } *sp2C;
    f32 sp28;
    s32 sp24;

    sp2C = func_80100094(arg0, 0);
    sp28 = sp2C->timer;
    sp24 = func_800D91EC(&sp2C->timer, 4.0f);
    if (func_80804644_chdiggerboss(sp2C->timer, sp28, 0.1f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
        func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(sp2C->timer, sp28, 0.4f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
        func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(sp2C->timer, sp28, 1.2f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F74_chdiggerboss);
        func_808043D8_chdiggerboss(arg0, 1.25f, &D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(sp2C->timer, sp28, 2.0f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F44_chdiggerboss);
        func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F3C_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(sp2C->timer, sp28, 2.4f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F5C_chdiggerboss);
        func_808043D8_chdiggerboss(arg0, 1.0f, &D_80809F40_chdiggerboss);
    }
    if (func_80804644_chdiggerboss(sp2C->timer, sp28, 3.4f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80809F88_chdiggerboss);
        func_808043D8_chdiggerboss(arg0, 1.5f, &D_80809F3C_chdiggerboss);
    }
    if (sp24 != 0) {
        func_808041E4_chdiggerboss(arg0, 0);
    }
}

s32 func_80804644_chdiggerboss(f32 arg0, f32 arg1, f32 arg2) {
    if ((arg2 < arg0) && (arg1 <= arg2)) {
        return 1;
    }
    return 0;
}

void func_80804680_chdiggerboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800EFB8C(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F48BC(s32, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_8010D490(f32 *, f32 *, f32, f32, s32);
    s32 temp_v0;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp24[4];

    if (_subaddieskeleton_entrypoint_2(arg0->unk0, 7, sp44) != 0) {
        func_800EF1B8(sp44, arg0->rotation[1], 150.0f);
        func_800EEB9C(sp38, arg0->rotation[1] - 180.0f, 1000.0f);
        temp_v0 = func_8010D490(sp44, sp38, 650.0f, 325.0f, -1);
        if (temp_v0 != -1) {
            func_800F5A00(temp_v0, sp50);
            sp34 = func_800F10B4(func_800EFB8C(sp44, sp50), 0.0f, 650.0f, 1400.0f, 100.0f);
            func_800EEB9C(sp24, func_800F1DF4(sp44, sp50), sp34);
            func_800F48BC(temp_v0, sp24);
        }
    }
}

void func_80804784_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x1A))) = 0;
}

void func_808047A8_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80804AC8_chdiggerboss(Actor *, s32);
    void func_808049DC_chdiggerboss(Actor *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C31DC(u8, f32);
    void func_800C3058(u8, s32);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    extern s32 D_8080A028_chdiggerboss[];
    typedef struct {
        u8 pad0[0x18];
        s16 state;
        u8 sound;
        u8 pad1B;
        f32 angle;
        f32 speed;
    } DiggerBossData;
    DiggerBossData *data;
    s32 active;
    f32 volume;
    s32 rate;

    data = func_80100094(arg0, 0);
    switch (data->state) {
        case 0:
            data->speed = func_800F15F8(data->speed, 0.0f, func_800D8FF8() * 0.4f);
            func_80804AC8_chdiggerboss(arg0, 0);
            break;
        case 1:
            data->speed = func_800F15F8(data->speed, 0.2f, func_800D8FF8() * 0.4f);
            func_80804AC8_chdiggerboss(arg0, 1);
            break;
        case 2:
            data->speed = func_800F15F8(data->speed, 1.0f, func_800D8FF8() * 0.4f);
            func_80804AC8_chdiggerboss(arg0, 1);
            break;
    }
    active = data->speed > 0.0f;
    func_808049DC_chdiggerboss(arg0);
    volume = func_800F10B4(data->speed, 0.0f, 1.0f, 0.7f, 1.1f);
    rate = func_800F10B4(data->speed, 0.0f, 1.0f, 22000.0f, 32000.0f);
    if (data->sound == 0) {
        func_800C4B64(volume);
        func_800C4B70(rate);
    }
    data->sound = _subaddieaudioloop_entrypoint_7(data->sound, arg0->position, active, D_8080A028_chdiggerboss, arg0->unk70_0);
    if (data->sound != 0) {
        func_800C31DC(data->sound, volume);
        func_800C3058(data->sound, rate);
    }
}

void func_808049A8_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x1A))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x1A))));
}

void func_808049DC_chdiggerboss(Actor *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    u8 *data;
    f32 sp28;

    data = func_80100094(arg0, 0);
    sp28 = func_800F10B4(*(f32 *)(data + 0x20), 0.0f, 1.0f, 0.0f, 300.0f);
    *(f32 *)(data + 0x1C) += sp28 * func_800D8FF8();
    *(f32 *)(data + 0x1C) = func_800136E4(*(f32 *)(data + 0x1C));
}

void func_80804A50_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    (*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = (s16) arg1;
}

/* extern */

void func_80804A7C_chdiggerboss(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    func_800E0AFC(arg1, 0x2A, 1.0f, 0.0f, 0.0f, (*(f32 *)((s8 *)(func_80100094(arg0, 0)) + (0x1C))));
}

void func_80804AC8_chdiggerboss(Actor *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800F018C(f32 *, f32 *, f32 *, f32 *);
    s32 func_800F581C(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    s32 func_800F6478(s32);
    int func_800F7A2C(s32, s32, f32 *);
    void func_808062B8_chdiggerboss(Actor *);
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    int i;
    f32 sp5C[3];
    f32 *position;

    if (arg1 != 0) {
        for (i = 0; i < 8; i++) {
            if (!func_800F6438(i)) continue;
            if (!func_800F6478(i)) continue;
            if (func_800F581C(i) & 0x10000000) {
                func_800EE7F8(sp5C, arg0->position);
                func_800EF1B8(sp5C, arg0->rotation[1], 1300.0f);
                sp5C[1] += 275.0f;
                func_800F5A00(i, sp6C);
                func_800EE7F8(sp84, arg0->position);
                sp84[1] += 275.0f;
                func_800F018C(sp78, sp84, sp5C, sp6C);
                func_800F7A2C(i, 6, sp78);
                func_808062B8_chdiggerboss(func_808026F8_chdiggerboss(arg0));
            }
        }
    }
}

void func_80804C28_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800C8A98(void);
    void func_800C8D4C(s32, f32 *);
    void func_800C8F64(s32, s32);
    u8 func_800E8714(s32);
    void func_800E8830(u8, f32 *);
    void func_800E8870(u8, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80805448_chdiggerboss(Actor *, s32, s32);
    void func_808057D0_chdiggerboss(Actor *);
    void func_808056B8_chdiggerboss(s32);
    extern f32 D_8080A038_chdiggerboss;
    struct DiggerPart { s32 handle; u8 pad[8]; f32 position[3]; u8 effect; u8 tail[3]; };
    struct DiggerData { u8 prefix[0x24]; u8 active; u8 pad[0xB]; struct DiggerPart parts[4]; };
    s32 handle;
    s32 i;
    u8 effect;
    struct DiggerData *data;

    data = func_80100094((Actor *)arg0, 0);
    data->active = 0;
    for (i = 0; i < 4; i++) {
        func_80805448_chdiggerboss((Actor *)arg0, i, 0);
        handle = func_800C8A98();
        data->parts[i].handle = handle;
        func_800C8F64(handle, 9);
        func_800C8D4C(handle, &D_8080A038_chdiggerboss);
        func_800EE7F8(data->parts[i].position, (f32 *)(arg0 + 4));
        effect = func_800E8714(1);
        data->parts[i].effect = effect;
        func_800E8830(effect, (f32 *)(arg0 + 4));
        func_800E8870(effect, 20.0f);
    }
    func_808057D0_chdiggerboss((Actor *)arg0);
    func_808056B8_chdiggerboss(arg0);
}

void func_80804D44_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    u8 func_800D9078(f32 *);
    s32 func_800DC128(s32, s32);
    int func_800DC298(f32);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void func_800E8830(u8, f32 *);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    void func_80805960_chdiggerboss(s32, s32, s32);
    void func_80805448_chdiggerboss(Actor *, s32, s32);
    void func_808056F8_chdiggerboss(Actor *);
    void func_808057D0_chdiggerboss(Actor *);
    extern s32 D_8080A040_chdiggerboss;
    extern s16 D_8080A058_chdiggerboss[];
    struct DiggerPart { s32 handle; s16 state; s16 appendage; f32 timer; f32 position[3]; u8 effect; u8 pad[3]; };
    struct DiggerData { u8 prefix[0x24]; u8 active; u8 pad[3]; f32 timer; s32 unk2C; struct DiggerPart parts[4]; };
    struct DiggerData *data;
    s32 active;
    s32 i;
    s16 state;
    s32 choice;
    data = func_80100094((Actor *)arg0, 0);
    active = 0;
    func_800D9078(&data->timer);
    for (i = 0; i != 4; i++) {
        state = data->parts[i].state;
        switch (state) {
        case 0:
            break;
        case 1:
            active = 1;
            func_80805960_chdiggerboss(arg0, i, func_800DC128(1, 5));
            break;
        case 2:
            choice = func_800DC298(0.5f);
            active = 1;
            if (choice) {
                choice = 0;
            } else {
                choice = func_800DC128(1, 5);
            }
            func_80805960_chdiggerboss(arg0, i, choice);
            if (func_800D9078(&data->parts[i].timer)) {
                func_80805448_chdiggerboss((Actor *)arg0, i, 0);
            }
            break;
        }
        if (data->parts[i].effect) {
            _subaddieskeleton_entrypoint_2(((Actor *)arg0)->unk0, D_8080A058_chdiggerboss[i], data->parts[i].position);
            func_800E8830(data->parts[i].effect, data->parts[i].position);
        }
    }
    func_808056F8_chdiggerboss((Actor *)arg0);
    func_808057D0_chdiggerboss((Actor *)arg0);
    data->active = _subaddieaudioloop_entrypoint_7(data->active, ((Actor *)arg0)->position, active, &D_8080A040_chdiggerboss, ((Actor *)arg0)->unk70_0);
}

void func_80804EFC_chdiggerboss(Actor *arg0, void *arg1) {
    struct DiggerPart { s16 active; s16 appendage; u8 rest[0x18]; };
    struct DiggerData { u8 prefix[0x34]; struct DiggerPart parts[4]; };
    void *func_80100094(Actor *, u32);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    s32 func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
    void func_80804FE4_chdiggerboss(Actor *, s32, void *);
    extern s16 D_8080A060_chdiggerboss;
    struct DiggerData *data;
    s16 *appendage;
    s32 i;

    data = func_80100094(arg0, 0);
    appendage = &D_8080A060_chdiggerboss;
    i = 0;
    do {
        func_800DF744(*appendage, data->parts[i].appendage);
        appendage++;
        i++;
    } while (i < 4);
    func_800DF830(1);
    func_800DE498(arg1, arg0->position, arg0->rotation, arg0->scale, NULL, func_800D674C(0x955));
    i = 0;
    do {
        if (data->parts[i].active != 0) {
            func_80804FE4_chdiggerboss(arg0, i, arg1);
        }
        i++;
    } while (i != 4);
}

void func_80804FE4_chdiggerboss(Actor *arg0, s32 arg1, void *arg2) {
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
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
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
        func_800DE498(arg2, data->parts[arg1].position, rotation, arg0->scale, 0, func_800D674C(0x954));
        data->parts[arg1].visible = 1;
    } else {
        data->parts[arg1].visible = 0;
    }
}

void func_808053BC_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800C8B84(volatile s32);
    void func_800E87E0(u8);
    s32 temp_a0;
    s32 var_s1;
    u8 temp_a0_2;
    u8 *temp_v0;
    u8 *var_s0;

    temp_v0 = func_80100094(arg0, 0);
    temp_v0[0x24] = _subaddieaudioloop_entrypoint_3(temp_v0[0x24]);
    for (var_s1 = 0, var_s0 = temp_v0; var_s1 != 0x70; var_s1 += 0x1C, var_s0 += 0x1C) {
        temp_a0 = *(s32 *)(var_s0 + 0x30);
        if (temp_a0 != 0) {
            func_800C8B84(temp_a0);
            *(s32 *)(var_s0 + 0x30) = 0;
        }
        temp_a0_2 = var_s0[0x48];
        if (temp_a0_2 != 0) {
            func_800E87E0(temp_a0_2);
            var_s0[0x48] = 0;
        }
    }
}

void func_80805448_chdiggerboss(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_80805960_chdiggerboss(s32, s32, s32);
    void func_808056F8_chdiggerboss(Actor *);
    extern u8 D_8080A068_chdiggerboss[];
    struct MarkerFlags {
        u8 pad0[0x18];
        unsigned int pad18:27; u8 flags18:4; unsigned int end18:1;
        u8 pad1C[0xC];
        unsigned int pad28:23; u16 flags28:8; unsigned int end28:1;
    };
    u8 *data;
    s32 i;
    s32 count;

    data = func_80100094(arg0, 0);
    count = 0;
    *(s16 *)(data + arg1 * 0x1C + 0x34) = arg2;
    switch (arg2) {
    case 0:
        func_80805960_chdiggerboss(arg0, arg1, 0);
        ((struct MarkerFlags *)arg0->unk0)->flags18 |= D_8080A068_chdiggerboss[arg1];
        data[arg1 * 0x1C + 0x4A] = 0;
        data[arg1 * 0x1C + 0x49] = 0;
        break;
    case 1:
        func_80805960_chdiggerboss(arg0, arg1, func_800DC128(1, 5));
        ((struct MarkerFlags *)arg0->unk0)->flags18 &= ~D_8080A068_chdiggerboss[arg1];
        break;
    case 2:
        func_80805960_chdiggerboss(arg0, arg1, func_800DC128(1, 5));
        ((struct MarkerFlags *)arg0->unk0)->flags18 |= D_8080A068_chdiggerboss[arg1];
        *(f32 *)(data + arg1 * 0x1C + 0x38) = func_800DC178(0.8f, 1.2f);
        break;
    }
    for (i = 0; i != 0x70; i += 0x1C) {
        if (*(s16 *)(data + i + 0x34) == 1) {
            count++;
        }
    }
    i = count > 0;
    data[0x25] = i;
    func_808056F8_chdiggerboss(arg0);
    if (i) {
        ((struct MarkerFlags *)arg0->unk0)->flags28 |= 4;
    } else {
        ((struct MarkerFlags *)arg0->unk0)->flags28 &= ~4;
    }
}

void func_808056B8_chdiggerboss(s32 arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor*);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_8010A570((Actor *) arg0);
    (*(f32 *)((s8 *)(sp1C) + (0x2C))) = 1.0f;
}

void func_808056F8_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800F6478(s32);
    int func_800F8004(s32);
    s32 func_800D90A4(f32 *);
    u32 func_8010A5B0(Actor *, s32);
    u8 *sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_80100094(arg0, 0);
    sp20 = 0;
    if (sp24[0x25] != 0) {
        sp1C = func_80802248_chdiggerboss(func_808026F8_chdiggerboss(arg0));
        if (func_800F6478(sp1C) != 0 && func_800F8004(sp1C) == 0) {
            if (func_800D90A4((f32 *)(sp24 + 0x2C)) != 0) {
                sp20 = 1;
            }
        } else {
            *(f32 *)(sp24 + 0x2C) = 1.0f;
        }
    }
    func_8010A5B0(arg0, sp20);
}

s16 func_80805798_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    return (*(s16 *)((s8 *)((((u8 *)func_80100094(arg0, 0)) + (arg1 * 0x1C))) + (0x34)));
}

void func_808057D0_chdiggerboss(Actor *arg0) {
    s32 func_8001210C(s32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    extern u32 D_8080A06C_chdiggerboss[][3];
    s32 temp_s1;
    s32 var_s0;
    s32 var_s3;
    struct DiggerPart { s32 handle; s16 active; u8 pad[6]; f32 pos[3]; u8 tail[4]; };
    struct DiggerParts { u8 prefix[0x30]; struct DiggerPart part[4]; } *var_s2;

    var_s2 = func_80100094(arg0, 0);
    for (var_s3 = 0; var_s3 < 4; var_s3++) {
        if (var_s2->part[var_s3].active == 1) {
            var_s0 = 1;
        } else {
            var_s0 = 0;
        }
        temp_s1 = var_s2->part[var_s3].handle;
        if (temp_s1 == 0) {
            continue;
        }
        func_800C8FE0(temp_s1, var_s0);
        if (var_s0 == 0) {
            continue;
        }
        func_800C8CB8(temp_s1, var_s2->part[var_s3].pos);
        func_800C8E84(temp_s1, D_8080A06C_chdiggerboss[func_8001210C(1)]);
    }
}

void func_808058B0_chdiggerboss(Actor *arg0, void *arg1) {
    struct DiggerHit { u8 prefix[0x1A]; u16 id : 11; u16 flags : 5; };
    struct DiggerHitData { u8 prefix[0x28]; f32 cooldown; };
    void *func_80100094(Actor *, u32);
    s32 func_800F79DC(s32, s32, s32);
    f32 func_800F5BF0(s32, f32 *);
    s32 _subaddiecustomhits_entrypoint_4(Actor *, f32 *, s32);
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    struct DiggerHitData *sp24;
    f32 sp18[3];

    sp24 = func_80100094(arg0, 0);
    func_800F79DC(((struct DiggerHit *)arg1)->id, 6, (s32)arg0->unk0);
    if (sp24->cooldown == 0.0f) {
        if (_subaddiecustomhits_entrypoint_4(arg0, sp18, 0) == 0) {
            func_800F5BF0(((struct DiggerHit *)arg1)->id, sp18);
        }
        _chelectricfence_entrypoint_1(arg0, sp18);
        sp24->cooldown = 0.6f;
    }
}

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

s32 func_80805A64_chdiggerboss(Actor *arg0) {
    f32 func_800D8FF8(void);
    u8 func_800D9078(f32 *);
    u32 func_800F54E4(void);
    s32 func_800F6D24(s32);
    void *func_80100094(Actor *, u32);
    void func_80805B8C_chdiggerboss(Actor *, f32);
    void func_808064CC_chdiggerboss(s32, s32);
    s32 pad[2];
    s32 result;
    Actor *other;
    s32 i;
    u8 state;
    u8 *data;

    data = func_80100094(arg0, 0);
    other = func_80802228_chdiggerboss(arg0);
    result = 0;
    func_80802C40_chdiggerboss((s32)arg0);
    if (func_800F6D24(func_800F54E4()) != 0) {
        return 0;
    }
    state = data[0x25];
    switch (state) {
        case 1:
            if (func_800D9078((f32 *)(data + 0x18)) != 0) {
                data[0x25] = 2;
            }
            break;
        case 2:
            result = func_800D9078((f32 *)(data + 0x1C));
            other->rotation[1] += *(f32 *)(data + 0x20) * func_800D8FF8();
            func_808064CC_chdiggerboss((s32)arg0, result == 0);
            func_80805B8C_chdiggerboss(arg0, *(f32 *)(data + 0x20));
            i = 0;
            if (result != 0) {
                do {
                    func_80805448_chdiggerboss(other, i, 0);
                    i++;
                } while (i != 4);
                func_80802CB4_chdiggerboss(arg0);
            }
            break;
    }
    return result;
}

void func_80805B8C_chdiggerboss(Actor *arg0, f32 arg1) {
    void func_80805C1C_chdiggerboss(Actor *, s32, f32 *, f32);
    extern f32 D_8080A084_chdiggerboss[];
    extern f32 D_8080A090_chdiggerboss[];
    extern f32 D_8080A09C_chdiggerboss[];
    extern f32 D_8080A0A8_chdiggerboss[];

    if (arg1 > 0.0f) {
        func_80805C1C_chdiggerboss(arg0, 0, D_8080A084_chdiggerboss, -90.0f);
        func_80805C1C_chdiggerboss(arg0, 2, D_8080A0A8_chdiggerboss, 90.0f);
    } else {
        func_80805C1C_chdiggerboss(arg0, 0, D_8080A090_chdiggerboss, -90.0f);
        func_80805C1C_chdiggerboss(arg0, 2, D_8080A09C_chdiggerboss, 90.0f);
    }
}

void func_80805C1C_chdiggerboss(Actor *arg0, s32 arg1, f32 *arg2, f32 arg3) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32[3], f32[3], f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_8080A0B4_chdiggerboss[];
    f32 sp44[3];
    f32 sp38[3];
    s32 sp34;
    Actor *sp30;

    if (func_800DC298(0.2f) != 0) {
        sp30 = func_80802228_chdiggerboss(arg0);
        func_800EFA4C(sp44, func_800DC178(10.0f, 15.0f), sp30->rotation[1] + arg3, 0.0f);
        sp44[1] += func_800DC178(-25.0f, 25.0f);
        func_800EF934(sp38, arg2, sp30->rotation[1]);
        func_800EF04C(sp38, sp30->position);
        sp34 = func_800B53A4(1);
        func_800BABB8(sp34, sp38, 0, 1.0f, D_8080A0B4_chdiggerboss);
        func_800BA994(sp34, (s16)sp44[0], (s16)sp44[1], 250, (s16)sp44[0], (s16)sp44[1], 400);
        func_800BA22C(sp34, 1);
    }
}

void func_80805D64_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    struct DiggerState {
        f32 prefix[5];
        f32 value;
        f32 speed;
        u8 padding[12];
        s16 state;
    };
    struct DiggerActorState { f32 prefix[3]; f32 value; };
    struct DiggerState *sp24;
    Actor *sp20;
    Actor *temp_v0;

    sp24 = func_80100094(arg0, 0);
    temp_v0 = func_80802228_chdiggerboss(arg0);
    sp20 = temp_v0;
    sp24->value = 0.0f;
    sp24->speed = 1.5f;
    ((struct DiggerActorState *)temp_v0->actorData)->value = 0.0f;
    sp24->state = 1;
    func_808027F4_chdiggerboss((s32)arg0);
    func_80802C0C_chdiggerboss((s32)arg0);
    func_80803BE8_chdiggerboss((s32)arg0, arg1, 1);
    func_80804A50_chdiggerboss((s32)sp20, 2);
}

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

s32 func_80806300_chdiggerboss(Actor *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    int func_800F20BC(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 func_8010CD50(Actor *, u32);
    struct DiggerTurnState {
        s32 prefix[2];
        s16 state;
        u8 padding[6];
        f32 value;
    };
    struct DiggerTurnState *sp2C;
    f32 sp28;
    f32 sp24;
    f32 temp_f0;

    sp2C = func_80100094(arg0, 0);
    sp24 = func_800D8FF8();
    if (sp2C->state == 2) {
        return -1;
    }
    sp28 = func_800136E4(func_8010CD50(arg0, func_80802248_chdiggerboss(arg0)) - arg0->rotation[1]);
    temp_f0 = func_800F1FF0(sp2C->value, sp28, 0.1f, sp24 * 4.0f, sp24 * 100.0f);
    sp2C->value = temp_f0;
    return func_800F20BC(temp_f0, sp28, 10.0f);
}

s32 func_808063C8_chdiggerboss(Actor *arg0, s32 arg1, f32 arg2) {
    f32 func_800D8FF8(void);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1F38(f32, f32, f32);
    int func_800F20BC(f32, f32, f32);
    f32 func_8010CD50(Actor *, u32);
    void func_808064CC_chdiggerboss(s32, s32);
    f32 mlAbsF(f32);
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    Actor *sp24;
    s32 sp20;

    sp28 = func_800D8FF8();
    sp24 = func_80802228_chdiggerboss(arg0);
    sp34 = func_8010CD50(arg0, func_80802248_chdiggerboss((s32) arg0));
    sp30 = sp24->rotation[1];
    sp24->rotation[1] = func_800F1F38(sp30, sp34, sp28 * arg2);
    sp2C = func_800F1DCC(sp24->rotation[1], sp30);
    if (mlAbsF(func_800F1DCC(sp30, sp34)) > 20.0f) {
        func_80805B8C_chdiggerboss(arg0, sp2C);
    }
    sp20 = func_800F20BC(sp24->rotation[1], sp34, 10.0f);
    if (arg1 != 0) {
        func_808064CC_chdiggerboss((s32) arg0, sp20 == 0);
    }
    return sp20;
}

void func_808064CC_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
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

void func_80806A78_chdiggerboss(Actor *arg0, s32 arg1, u8 *arg2) {
    void *func_80100094(Actor *, u32);
    void rare_memcpy(void *, void *, int);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    s32 func_800F7B9C(s32, s32);
    void func_80806B38_chdiggerboss(Actor *);
    struct DiggerBossInitData {
        u8 pad0[0x5C];
        u8 state;
        u8 parameter;
        u8 mode;
        u8 active;
        f32 timer;
        s32 child;
        u8 copy[0x10];
    } *data;

    data = func_80100094(arg0, 0);
    rare_memcpy(data->copy, arg2, 0x10);
    data->mode = 3;
    data->timer = 1.75f;
    data->parameter = *arg2;
    func_80803BE8_chdiggerboss((s32)arg0, arg1, 8);
    func_808027F4_chdiggerboss((s32)arg0);
    if (func_800F5410(func_800F54E4()) == 0x11) {
        data->state = 1;
        func_800F7B9C(func_800F54E4(), 0x8E);
    } else {
        func_80806B38_chdiggerboss(arg0);
    }
}

void func_80806B38_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    int func_800F7C58(s32, s32, s32);
    void func_800F8444(s32, f32 *);
    struct DiggerBossData {
        u8 pad0[4];
        u8 flag;
        u8 pad5[0x57];
        u8 state;
        u8 pad5D[2];
        u8 active;
        f32 timer;
    } *data;
    f32 position[3];
    f32 rotation[3];
    s32 child;

    data = func_80100094(arg0, 0);
    if (data->active != 0 || data->flag != 0) {
        data->state = 3;
        data->timer = 0.15f;
        return;
    }
    child = func_80802248_chdiggerboss(arg0);
    data->state = 3;
    data->timer = 1.75f;
    func_800F5A00(child, position);
    func_800EFA4C(rotation, 0.0f, func_800F1DF4(position, arg0->position), 0.0f);
    func_800F8444(child, rotation);
    func_800F7C58(child, 0x61, 1);
}

void func_80806C08_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800F7B9C(s32, s32);
    int func_800F7C58(s32, s32, s32);
    struct DiggerBossData {
        u8 pad0[4];
        u8 flag;
        u8 pad5[0x57];
        u8 state;
        u8 pad5D[3];
        f32 timer;
    } *data;
    s32 child;

    data = func_80100094(arg0, 0);
    child = func_80802248_chdiggerboss(arg0);
    if (data->flag != 0) {
        data->state = 0xB;
        data->timer = 0.15f;
        return;
    }
    func_800F7B9C(child, 0x63);
    func_800F7C58(child, 0x61, 2);
    func_80802878_chdiggerboss(arg0, 5, 1);
    data->state = 0xB;
    data->timer = 1.0f;
}

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

void func_80806CF8_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor *func_801084B0(s32, Actor **);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    struct DiggerBossData {
        u8 pad0[0x5C];
        u8 state;
        u8 pad5D;
        u8 count;
        u8 pad5F;
        s32 pad60;
        Unk80132ED0 *child;
    } *sp1C;
    Actor *sp18;
    u8 temp_a0;

    sp1C = func_80100094(arg0, 0);
    if (arg1 == 0) {
        sp18 = func_801084B0(0x4F2, &arg0);
        _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp18->position);
        temp_a0 = sp1C->count;
        sp1C->child = sp18->unk0;
        sp1C->state = 5;
        if ((s32) temp_a0 > 0) {
            sp1C->count = temp_a0 - 1;
        }
        func_80800180_chdiggerboss(arg0, 7);
    }
}

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

void func_80806DC4_chdiggerboss(Actor *arg0, Unk80132ED0 *arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800F0E28(s32, s32);
    void func_8010963C(void *, f32 *, void *);
    void func_80109FE8(void **, s32);
    u8 func_80806F10_chdiggerboss(Actor *, u8);
    s32 damage;
    struct {
        u8 pad0[2];
        u8 health;
        u8 pad3[0x59];
        u8 state;
        u8 pad5D[7];
        Unk80132ED0 *child;
        u8 pad68;
        u8 minimum;
        u8 pad6A[0xE];
        u8 sound;
    } *data;
    f32 position[3];

    data = func_80100094(arg0, 0);
    switch (arg1->unk24 >> 22) {
    case 0x26C:
        damage = 1;
        break;
    case 0x26D:
    case 0x26E:
        damage = 2;
        break;
    case 0x26F:
        damage = 3;
        break;
    default:
        return;
    }
    data->health = func_800F0E28(data->health - damage, data->minimum);
    data->sound = func_80806F10_chdiggerboss(arg0, data->sound);
    if (data->health == data->minimum) {
        func_80109FE8((void *)arg0, 0);
    }
    func_80802298_chdiggerboss((u8 *)arg0, (u8 *)position);
    func_8010963C(arg0, position, arg1);
    switch (data->state) {
    case 4:
    case 7:
        break;
    case 5:
        if (data->child != NULL) {
            break;
        }
    default:
        func_80800180_chdiggerboss(arg0, 9);
        data->state = 7;
        break;
    }
}

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

void func_80806F8C_chdiggerboss(Actor *arg0) {
    void _chbaddiesetup_entrypoint_10(void);
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    void _chbounce_entrypoint_3(f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800DC178(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    f32 func_800F2094(f32, f32);
    extern f32 D_8080A134_chdiggerboss[];
    extern s32 D_8080A120_chdiggerboss;
    f32 position[3];
    f32 zero = 0.0f;
    f32 yaw;
    f32 target_yaw;
    Actor *child;

    child = func_80802228_chdiggerboss(arg0);
    func_80802298_chdiggerboss((u8 *)arg0, (u8 *)position);
    if (!func_800F1E6C(position, D_8080A134_chdiggerboss, &target_yaw)) {
        target_yaw = 0.0f;
    }
    if (func_800F2094(child->rotation[1] + 90.0f, target_yaw) < func_800F2094(child->rotation[1] - 90.0f, target_yaw)) {
        yaw = child->rotation[1] + 90.0f;
    } else {
        yaw = child->rotation[1] - 90.0f;
    }
    _chbounce_entrypoint_3(func_800DC178(-30.0f, 30.0f) + yaw);
    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 0x21,
        *(s32 *)&position[0], *(s32 *)&position[1], *(s32 *)&position[2], *(s32 *)&zero);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080A120_chdiggerboss);
}

s32 func_808070B0_chdiggerboss(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    u8 func_800D9078(f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    void func_80108B04(Actor *, u32);
    s16 func_8080761C_chdiggerboss(s32);
    typedef struct {
        u8 pad0[0x7C];
        s16 unk7C;
        s16 unk7E;
        u8 pad80[4];
        f32 unk84;
    } BossData;
    BossData *data;
    Actor *child2;
    Actor *child3;

    data = func_80100094(arg0, 0);
    func_80802C40_chdiggerboss((s32)arg0);
    switch (data->unk7C) {
    case 1:
        if (func_800D9078(&data->unk84)) {
            data->unk7C = 2;
        }
        break;
    case 2:
        if (func_808063C8_chdiggerboss(arg0, 1, 80.0f)) {
            child2 = func_80802228_chdiggerboss(arg0);
            if (func_8080761C_chdiggerboss((s32)arg0)) {
                func_808008C0_chdiggerboss((s32)child2, 3, 1);
                func_808008C0_chdiggerboss((s32)child2, 4, 1);
                func_8080041C_chdiggerboss(child2, 0x11);
            } else {
                func_808008C0_chdiggerboss((s32)child2, 3, 1);
                func_8080041C_chdiggerboss(child2, 0xF);
            }
            data->unk7C = 3;
        }
        break;
    case 3:
        child3 = func_80802228_chdiggerboss(arg0);
        func_808063C8_chdiggerboss(arg0, 1, 80.0f);
        if (func_80101E14(child3, 0.14f)) {
            func_80108B04(arg0, 1);
        }
        if (func_8080761C_chdiggerboss((s32)arg0) && func_80101E14(child3, 0.28f)) {
            func_80108B04(arg0, 2);
        }
        break;
    case 4:
        if (func_800D9078(&data->unk84)) {
            data->unk7C = 2;
        }
        break;
    case 5:
        if (!_subaddiefind_entrypoint_2(0x4F3, 0) && !_subaddiefind_entrypoint_2(0x4F4, 0)) {
            data->unk7C = 0;
            func_80802CB4_chdiggerboss((s32)arg0);
            return 1;
        }
        break;
    }
    return 0;
}

void *func_80807280_chdiggerboss(s32 arg0, s32 arg1, s16 *arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    void rare_memcpy(void *, void *, int);
    typedef struct {
        u8 pad0[0x7C];
        s16 unk7C;
        s16 unk7E;
        u8 pad80[4];
        f32 unk84;
        s16 unk88[8];
    } BossData;
    void *volatile data;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    data = temp_v0;
    rare_memcpy(((BossData *)temp_v0)->unk88, arg2, 0x10);
    func_808027F4_chdiggerboss(arg0);
    func_80802C0C_chdiggerboss(arg0);
    func_80803BE8_chdiggerboss(arg0, arg1, 1);
    temp_v0 = data;
    ((BossData *)temp_v0)->unk7C = 1;
    ((BossData *)temp_v0)->unk84 = 1.5f;
    ((BossData *)temp_v0)->unk7E = *arg2;
    return temp_v0;
}

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

void func_80807698_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80805448_chdiggerboss(Actor *, s32, s32);
    Actor *child;
    s32 enabled;
    s32 value;
    s32 i;
    u8 *data;

    data = func_80100094(arg0, 0);
    child = func_80802228_chdiggerboss(arg0);
    if (arg1 != 0) {
        enabled = 1;
    } else {
        value = data[0xA3] ? 1 : 0;
        enabled = value;
    }
    i = 0;
    do {
        if (data[0xA2] & (1 << i)) {
            func_80805448_chdiggerboss(child, i, enabled);
        }
        i++;
    } while (i != 4);
}

void func_80807754_chdiggerboss(Actor *arg0, s32 arg1, f32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    void func_808041E4_chdiggerboss(Actor *, s32);
    Actor *child;
    s32 i;
    u8 *data;

    data = func_80100094(arg0, 0);
    child = func_80802228_chdiggerboss(arg0);
    *(f32 *)(data + 0x98) = arg2;
    *(f32 *)(data + 0x9C) = 2.0f;
    data[0xA3] = 1;
    data[0xA2] = 0;
    i = 0;
    do {
        if (func_80805798_chdiggerboss((s32)child, i) != 0) {
            data[0xA2] |= 1 << i;
        }
        i++;
    } while (i != 4);
    func_808027F4_chdiggerboss((s32)arg0);
    func_80803BE8_chdiggerboss((s32)arg0, arg1, 1);
    func_808041E4_chdiggerboss(func_80802228_chdiggerboss(arg0), 3);
}

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
void func_80807B54_chdiggerboss(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    s32 _subaddiefind_entrypoint_9(s32);
    void _sucoaster_entrypoint_4(Actor *);
    f32 func_8001395C(f32);
    void func_800B4470(f32 *, f32 *, f32 *, s32, f32, f32, s32, s32, s32);
    void func_800C4104(s32, f32, s32, s32, f32, f32);
    u8 func_800D9078(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800F4F34(u32, f32 *, f32, f32);
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80108B04(Actor *, u32);
    extern f32 D_8080A150_chdiggerboss[];
    struct BossData {
        u8 pad[0xA4];
        u8 state, active, count, delay;
        f32 end[3];
        f32 start[3];
        f32 unkC0;
        f32 progress;
        Unk80132ED0 *marker;
    } *data;
    s32 finished;
    Actor *child;
    f32 t;
    s32 iterator[2];
    Actor *actor;

    data = func_80100094(arg0, 0);
    switch (data->state) {
    case 1:
        break;
    case 0:
        if (data->active && _subaddiefind_entrypoint_9(0x131) < data->count) {
            data->state = 1;
            func_80108B04(arg0, 4);
        }
        break;
    case 2:
        finished = func_800D9078(&data->progress);
        child = func_80106790(data->marker);
        t = func_800F10B4(data->progress, 0.0f, 1.0f, 1.0f, 0.0f);
        func_800EFE50(child->position, data->start, data->end, t);
        child->position[1] += func_8001395C(t * 3.1415927f) * 500.0f;
        func_800F4F34(func_800F54E4(), child->position, child->scale * 90.0f, child->scale * 100.0f);
        if (finished) {
            func_800B4470(child->position, NULL, D_8080A150_chdiggerboss, 1, 0.8f, 0.0f, 100, 150, 0);
            func_800C4104(0x419, 1.0f, 0x6D60, child->position, 1200.0f, 8000.0f);
            child->unk64_20 = 1;
            data->state = 3;
        }
        break;
    case 3:
        _sucoaster_entrypoint_4(func_80106790(data->marker));
        if (data->active) {
            data->state = 0;
        } else {
            data->state = 4;
        }
        data->marker = NULL;
        break;
    case 4:
        if (data->delay) {
            data->delay--;
        } else {
            actor = _subaddiefind_entrypoint_2(0x131, iterator);
            while (actor) {
                func_8010108C(actor, 0x9A, 0);
                actor = _subaddiefind_entrypoint_3(0x131, iterator);
            }
            data->state = 0;
        }
        break;
    }
}

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

void func_80807E3C_chdiggerboss(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFD24(f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(void *, f32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    f32 func_8010CD50(Actor *, u32);
    extern s32 D_8080A154_chdiggerboss;
    struct DiggerBossData {
        u8 pad0[0xA4];
        s8 state;
        u8 padA5[3];
        f32 destination[3];
        f32 position[3];
        f32 yaw;
        f32 timer;
        Unk80132ED0 *marker;
    };
    struct DiggerBossData *data;
    f32 sp38[3];
    Actor *sp34;
    s32 sp30;

    data = func_80100094(arg0, 0);
    if (arg1 == 4) {
        sp30 = func_80802248_chdiggerboss(arg0);
        func_800EFD24(sp38);
        if (func_800F1E6C(arg0->position, sp38, &data->yaw) == 0) {
            data->yaw = func_8010CD50(arg0, sp30) + (func_800DC298(0.5f) ? 1.0f : -1.0f) * 45.0f;
        }
        func_800EE7F8(data->position, arg0->position);
        data->position[1] += 500.0f;
        func_800EE7F8(data->destination, arg0->position);
        func_800EF1B8(data->destination, data->yaw, 600.0f);
        sp34 = func_80108528(0x131, data->position, (s32)data->yaw, &arg0);
        sp34->unk74_17 = 0;
        sp34->rotation[1] = data->yaw;
        func_80102FDC(sp34, func_800DC178(1.2f, 1.6f));
        data->marker = sp34->unk0;
        data->state = 2;
        data->timer = 1.0f;
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_8080A154_chdiggerboss);
    }
}

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

void func_80808034_chdiggerboss(Actor *arg0) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    s32 func_8001210C(s32);
    void *func_80100094(Actor *, u32);
    void func_808081AC_chdiggerboss(u8 *volatile);
    extern s32 D_8080A160_chdiggerboss;
    u8 *sp24;
    s32 sp20;
    u8 *temp_v0;
    u32 flags;
    u8 sound;

    temp_v0 = func_80100094(arg0, 0);
    sp24 = temp_v0;
    sp20 = 0;
    if (*(s16 *)(temp_v0 + 0xA4) == 1) {
        sp20 = 1;
        if (func_8001210C(1) != 0) {
            func_808081AC_chdiggerboss((u8 *)arg0);
        }
    }
    sound = sp24[0xA6];
    flags = arg0->unk70_0;
    flags &= 1;
    sp24[0xA6] = _subaddieaudioloop_entrypoint_7(sound, arg0->position, sp20, &D_8080A160_chdiggerboss, flags);
}

void func_808080C0_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    void func_80108B04(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    *(s16 *)(data + 0xA4) = arg1;
    switch (arg1) {
        case 0:
            if (*(s32 *)(data + 0xA8) != 0) {
                func_8010114C(*(s32 *)(data + 0xA8), 0x4F, 0);
                *(s32 *)(data + 0xA8) = 0;
            }
            break;
        case 1:
            break;
        case 2:
            if (*(s32 *)(data + 0xA8) == 0) {
                func_80108B04(arg0, 3);
            }
            break;
    }
}

void func_8080815C_chdiggerboss(s32 arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    Actor* func_801084B0(s32, Actor**);
    u8 *sp1C;
    sp1C = func_80100094(arg0, 0);
    if (arg1 == 3) {
        (*(s32 *)((s8 *)(sp1C) + (0xA8))) = (s32) func_801084B0(0x178, (Actor **) &arg0)->unk0;
    }
}

void func_808081AC_chdiggerboss(u8 *volatile arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_8080A16C_chdiggerboss;
    f32 sp34[3];
    f32 sp28[3];
    f32 *volatile sp24;

    func_800EE7F8(sp28, sp24 = (f32 *)(arg0 + 4));
    func_800EF1B8(sp28, *(f32 *)(arg0 + 0x48), -80.0f);
    sp28[1] += 80.0f;
    func_800EE7F8(sp34, sp28);
    func_800EF1B8(sp34, *(f32 *)(arg0 + 0x48) + 90.0f, 200.0f);
    func_800BBCB8(sp34, sp24, 1.0f, 1, &D_8080A16C_chdiggerboss);
}

void func_80808258_chdiggerboss(Actor *arg0) {
    void func_80808560_chdiggerboss(Actor *);
    s32 func_808086A8_chdiggerboss(s32);
    void func_808087F0_chdiggerboss(Actor *);
    s32 func_800D2498(u32, s32, u32);
    u8 func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_8010105C(f32);
    s32 func_8010108C(Actor *, s32, s32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102FDC(void *, f32);
    void func_80108B04(Actor *, u32);
    struct {
        u8 pad0[2];
        u8 value;
        u8 pad3[0xC9];
        u8 state;
        u8 active;
        u8 padCE[2];
        f32 timer;
        s32 unkD4;
    } *sp3C;
    s32 sp38;
    f32 sp34;
    s32 sp30;
    s16 sp2C[2];

    sp3C = func_80100094(arg0, 0);
    func_800D2498(0x10A, sp3C->value, 0);
    func_808087F0_chdiggerboss(arg0);
    switch (sp3C->state) {
        case 0:
            break;
        case 1:
            func_80108B04(arg0, 5);
            break;
        case 2:
            sp38 = func_808086A8_chdiggerboss((s32)arg0);
            if (sp38 != 0) {
                func_80102FDC((Actor *)sp38, func_800F10B4(func_80101F24(arg0), 0.0f, 1.0f, 0.1f, 0.8f));
            }
            if (func_80101DDC(arg0)) {
                if (sp3C->active) {
                    func_80808560_chdiggerboss(arg0);
                } else {
                    func_80800180_chdiggerboss(arg0, 0xB);
                    sp3C->state = 3;
                }
            }
            break;
        case 3:
            if (sp3C->active) {
                func_80808560_chdiggerboss(arg0);
            }
            break;
        case 4:
            if (func_800D9078(&sp3C->timer)) {
                func_80800180_chdiggerboss(arg0, 0xC);
                sp3C->state = 5;
            }
            break;
        case 5:
            sp30 = func_808086A8_chdiggerboss((s32)arg0);
            if (func_80101E14(arg0, 0.33f)) {
                sp2C[0] = func_80802248_chdiggerboss((s32)arg0);
                func_8010105C(800.0f);
                func_8010108C((Actor *)sp30, 0xA, (sp2C[0] << 16) | 0xDAC);
                sp3C->unkD4 = 0;
            }
            if (func_80101DDC(arg0)) {
                func_80800180_chdiggerboss(arg0, 8);
                sp3C->state = 1;
                sp3C->timer = 0.5f;
            }
            break;
    }
}

void func_8080843C_chdiggerboss(s32 arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    sp1C = temp_v0;
    (*(u8 *)((s8 *)(sp1C) + (0x78))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(temp_v0) + (0x78))));
}

void func_80808470_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800F8444(s32, f32 *);
    void func_80109FE8(void **, s32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    s32 pad;
    s32 child;
    f32 position[3];
    f32 rotation[3];
    struct {
        u8 pad0[3];
        u8 active;
        u8 pad4[0xC8];
        u8 state;
        u8 padCD[0xB];
        u8 flag;
    } *data;

    data = func_80100094(arg0, 0);
    child = func_80802248_chdiggerboss(arg0);
    data->active = 1;
    data->flag = 0;
    func_80803BE8_chdiggerboss(arg0, arg1, 8);
    func_800F5A00(child, position);
    func_800EFA4C(rotation, 0.0f, func_800F1DF4(position, arg0->position), 0.0f);
    func_800F8444(child, rotation);
    if (func_808021E8_chdiggerboss(arg0, 0xB) == 0) {
        func_80802878_chdiggerboss(arg0, 3, 1);
        func_80803660_chdiggerboss(arg0, 0x172D, 0x10E);
        data->state = 1;
        return;
    }
    func_80109FE8(arg0, 1);
    data->state = 1;
}

void func_80808560_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80102FDC(void *, f32);
    void func_80109FE8(void **, s32);
    s32 func_808086A8_chdiggerboss(s32);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_80102FDC(func_808086A8_chdiggerboss(arg0), 0.8f);
    func_80800180_chdiggerboss(arg0, 0xB);
    func_808027F4_chdiggerboss(arg0);
    func_80109FE8(arg0, 1);
    sp24[0xCC] = 4;
    *(f32 *)(sp24 + 0xD0) = 0.5f;
}

void func_808085E0_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102FDC(void *, f32);
    Actor *func_801084B0(s32, Actor **);
    void func_808087F0_chdiggerboss(Actor *);
    u8 *data;
    Actor *sp20;
    Actor *temp_v0;

    data = func_80100094(arg0, 0);
    if (arg1 == 5) {
        temp_v0 = func_801084B0(0x4F6, &arg0);
        sp20 = temp_v0;
        *(Unk80132ED0 **)(data + 0xD4) = temp_v0->unk0;
        func_808087F0_chdiggerboss(arg0);
        if (func_80802170_chdiggerboss(arg0, 0xB) == 0) {
            func_80102FDC(sp20, 0.1f);
            func_80800180_chdiggerboss(arg0, 0xA);
            data[0xCC] = 2;
            return;
        }
        func_80102FDC(sp20, 0.8f);
        func_80800180_chdiggerboss(arg0, 0xB);
        data[0xCC] = 4;
        *(f32 *)(data + 0xD0) = 0.5f;
    }
}

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

void func_808086E8_chdiggerboss(Actor *arg0, Unk80132ED0 *arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    void func_80109FE8(void **, s32);
    s32 func_800F7B9C(s32, s32);
    s32 func_8010114C(s32, s32, s32);
    u8 *data;
    u32 id;

    data = func_80100094(arg0, 0);
    data[0xD8] = func_80806F10_chdiggerboss(arg0, data[0xD8]);
    if ((*(s32 *)(data + 0xD4) != 0) &&
        ((id = arg1->unk24 >> 22, id == 0x26C) ||
         id == 0x26D || id == 0x26E || id == 0x26F)) {
        func_80109FE8(arg0, 0);
        func_80803BE8_chdiggerboss(arg0, 0x41, 0xD);
        func_80802878_chdiggerboss(arg0, 3, 1);
        func_80803660_chdiggerboss(arg0, 0x1735, 0x14C);
        func_800F7B9C(func_80802248_chdiggerboss(arg0), 0x63);
        func_8010114C(*(s32 *)(data + 0xD4), 0x9B, (s32)(arg0->position[1] + 200.0f));
        *(s32 *)(data + 0xD4) = 0;
        data[0xCC] = 0;
        data[2] = 0;
    }
}

void func_808087F0_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    void func_800EF1B8(f32 *, f32, f32);
    f32 *sp44;
    Actor *sp40;
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    sp44 = func_80100094(arg0, 0);
    sp40 = func_808086A8_chdiggerboss(arg0);
    if ((sp40 != NULL) && (_subaddieskeleton_entrypoint_0(arg0, 0x10, sp34) != 0)) {
        sp24 = sp44[4] + arg0->rotation[1];
        _subaddieskeleton_entrypoint_0(arg0, 0x1E, sp28);
        func_800EFE50(sp40->position, sp34, sp28, 0.5f);
        func_800EF1B8(sp40->position, sp24, 80.0f);
        sp40->position[1] += 80.0f;
    }
}

void func_80808B40_chdiggerboss(Actor *, s32);

void func_808088AC_chdiggerboss(s32 arg0)
{
    func_80808B40_chdiggerboss(arg0,1);
}

void func_808088CC_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80808BE4_chdiggerboss(u8 *, u8 *, s32);
    Unk80132ED0 *temp_a0;
    s32 var_s0;
    u8 *var_s1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        temp_a0 = *(Unk80132ED0 **)(var_s1 + 0xB0);
        if (temp_a0 != NULL) {
            func_80808BE4_chdiggerboss(arg0, func_80106790(temp_a0), var_s0);
        }
        var_s0 += 1;
        var_s1 += 4;
    } while (var_s0 != 4);
}

void func_80808948_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_801069A4(Unk80132ED0 *);
    void func_800FFA88(Unk80132ED0 *);
    Unk80132ED0 *temp_a0;
    s32 var_s1;
    u8 *var_s0;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    var_s1 = 0;
    var_s0 = temp_v0;
    do {
        temp_a0 = *(Unk80132ED0 **)(var_s0 + 0xB0);
        if (temp_a0 != NULL) {
            if (func_801069A4(temp_a0) != 0) {
                func_800FFA88(*(Unk80132ED0 **)(var_s0 + 0xB0));
            }
            *(Unk80132ED0 **)(var_s0 + 0xB0) = NULL;
        }
        var_s1 += 4;
        var_s0 += 4;
    } while (var_s1 != 0x10);
}

void func_808089BC_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80103110(void *, s32);
    void func_80102FDC(void *, f32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    s32 _subaddiefade_entrypoint_12(s32, s32, s32, s32);
    void func_80808BE4_chdiggerboss(u8 *, u8 *, s32);
    struct BossItems {
        u8 pad[0xAC];
        s32 active;
        Unk80132ED0 *items[4];
    } *data, *cursor;
    Actor *child;
    Actor *child2;
    Actor **parent;
    s32 i;

    parent = &arg0;
    data = func_80100094(arg0, 0);
    i = 0;
    if (arg1 == 6) {
        for (i = 0, cursor = data; i < 2; i++) {
            child = func_80108528(0x50A, arg0->position, 0xA, parent);
            func_80103110(child, 1);
            func_80102FDC(child, 1.5f);
            child->unk74_17 = 0;
            child->unk74_7 = 0x43;
            func_80808BE4_chdiggerboss(arg0, child, i);
            cursor->items[0] = child->unk0;
            cursor = (void *)((u8 *)cursor + 4);
        }
        if (i < 4) {
          do {
            child2 = func_80108528(0x50A, arg0->position, 0xA, parent);
            func_80103110(child2, 1);
            func_80102FDC(child2, 0.8f);
            _subaddiefade_entrypoint_12(child2, 0xFF, 0, 0);
            child2->unk74_17 = 0;
            child2->unk74_7 = 0x3E;
            func_80808BE4_chdiggerboss(arg0, child2, i);
            cursor->items[0] = child2->unk0;
            i++;
            cursor = (void *)((u8 *)cursor + 4);
          } while (i < 4);
        }
    }
}

void func_80808B40_chdiggerboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_800FFA88(Unk80132ED0 *);
    Unk80132ED0 *temp_a0;
    s32 var_s1;
    struct {
        u8 pad[0xAC];
        s32 active;
        Unk80132ED0 *items[4];
    } *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if (arg1 == temp_v0->active) {
        return;
    }
    temp_v0->active = arg1;
    if (arg1 != 0) {
        if (temp_v0->items[0] == NULL) {
            func_80108B04(arg0, 6);
        }
        return;
    }
    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        temp_a0 = temp_v0->items[var_s1];
        if (temp_a0 != NULL) {
            func_800FFA88(temp_a0);
            temp_v0->items[var_s1] = NULL;
        }
    }
}

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

void func_80808CD0_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80808D54_chdiggerboss(Actor *, s32, f32, f32 *);
    void func_80808F44_chdiggerboss(s32 *);
    extern f32 D_8080A1DC_chdiggerboss[];
    extern f32 D_8080A1E8_chdiggerboss[];
    u8 *data;

    data = func_80100094(arg0, 0);
    func_80808D54_chdiggerboss(arg0, 0, -1.0f, D_8080A1E8_chdiggerboss);
    func_80808D54_chdiggerboss(arg0, 1, 1.0f, D_8080A1DC_chdiggerboss);
    func_80808F44_chdiggerboss((s32 *)arg0);
    func_800EE7F8((f32 *)(data + 0xD4), (f32 *)((u8 *)arg0 + 4));
    *(f32 *)(data + 0xE0) = *(f32 *)((u8 *)arg0 + 0x48);
}

void func_80808D54_chdiggerboss(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3) {
    f32 func_800D8FF8(void);
    f32 func_800EEAD4(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    s32 pad;
    f32 sp60;
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 var_f2;
    s32 var_v1;
    u8 *data;
    u8 *element;

    data = func_80100094(arg0, 0);
    sp60 = func_800D8FF8();
    func_800EF934(sp54, arg3, *(f32 *)((u8 *)arg0 + 0x48));
    func_800EF04C(sp54, (f32 *)((u8 *)arg0 + 4));
    func_800EF934(sp48, arg3, *(f32 *)(data + 0xE0));
    func_800EF04C(sp48, (f32 *)(data + 0xD4));
    sp44 = func_800EEAD4(sp54, sp48);
    if (func_800EECE0((f32 *)((u8 *)arg0 + 4), (f32 *)(data + 0xD4))) {
        var_f2 = (func_800F1DCC(*(f32 *)(data + 0xE0), *(f32 *)((u8 *)arg0 + 0x48)) <= 0.0f ? 1.0f : -1.0f) * arg2;
    } else {
        var_f2 = 1.0f;
    }
    element = (u8 *)((u32)data + arg1 * 4);
    *(f32 *)(element + 0xC8) += sp44 * 12.0f * var_f2 * 64.0f * sp60;
    var_v1 = (s32)*(f32 *)(element + 0xC8);
    if ((s32)*(f32 *)(element + 0xC8) >= 0x2000) {
        *(f32 *)(element + 0xC8) -= 8192.0f;
    } else if (var_v1 < 0) {
        *(f32 *)(element + 0xC8) += 8192.0f;
    }
    *(s16 *)(data + arg1 * 2 + 0xD0) = (s32)*(f32 *)(element + 0xC8);
    *(f32 *)(element + 0xC0) += sp44 * 0.013333334f * var_f2 * 57.29578f;
}

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

void chdiggerboss_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s16 *data;
    s32 offset;
    Vtx *end;

    data = func_80100094(func_80106790(arg4), 0);
    switch (arg0) {
    case 1:
        offset = data[0x68];
        end = arg1 + arg3;
        while (arg1 < end) {
            arg2++;
            arg2[-1].v.tc[1] = (arg1++)->v.tc[1] + offset;
        }
        break;
    case 2:
        offset = data[0x69];
        end = arg1 + arg3;
        while (arg1 < end) {
            arg2++;
            arg2[-1].v.tc[1] = (arg1++)->v.tc[1] + offset;
        }
        break;
    }
}

void func_80809078_chdiggerboss(Actor *arg0, void *arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    extern u16 D_8080A1F4_chdiggerboss[];
    extern u16 D_8080A1FA_chdiggerboss[];
    extern u16 D_8080A1FC_chdiggerboss[];
    extern u16 D_8080A202_chdiggerboss[];
    s32 i;
    f32 *data;

    data = func_80100094(arg0, 0);
    for (i = 0; i < 3; i++) {
        func_800E0AFC(arg1, D_8080A1F4_chdiggerboss[i], 1.0f, data[0x30], 0.0f, 0.0f);
    }
    for (i = 0; i < 3; i++) {
        func_800E0AFC(arg1, D_8080A1FC_chdiggerboss[i], 1.0f, data[0x31], 0.0f, 0.0f);
    }
}

void func_80809150_chdiggerboss(Actor *arg0) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 func_800DA544(s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80803BE8_chdiggerboss(s32, s32, s32);
    s32 func_80809234_chdiggerboss(Actor *);
    Actor *child;
    struct {
        u8 pad[0xDC];
        s32 phase;
        f32 timer;
        s32 state;
        s32 unkE8;
        s32 unkEC;
        s32 unkF0;
        s32 unkF4;
    } *data;

    child = func_80802228_chdiggerboss(arg0);
    data = func_80100094(arg0, 0);
    func_80808B40_chdiggerboss(child, 0);
    func_80803BE8_chdiggerboss(arg0, 0x43, 1);
    func_800DA544(0x43);
    _gcfrontend_entrypoint_9(0x83);
    func_800FDC28(0x16);
    data->phase = -1;
    data->state = 0;
    data->unkE8 = 0;
    data->unkEC = 0;
    data->unkF0 = 0;
    data->unkF4 = 0;
    func_80809234_chdiggerboss(arg0);
}

/* extern */

s32 func_808091E4_chdiggerboss(s32 arg0) {
    u8 func_800D9078(f32*);
    void *func_80100094(Actor *, u32);
    s32 func_80809234_chdiggerboss(Actor *);
    if ((func_800D9078(((u8 *)func_80100094(arg0, 0)) + 0xE0) != 0) && (func_80809234_chdiggerboss(arg0) == 0)) {
        return 0;
    }
    return 1;
}

s32 func_80809234_chdiggerboss(Actor *arg0) {
    void _chexploder_entrypoint_5(Actor *, s32, f32 *, s32, f32, s32);
    void func_800FC6B0(u32);
    void func_800FC74C(u32);
    void *func_80100094(Actor *, u32);
    extern s16 D_8080A1FE_chdiggerboss[][4];
    extern s16 D_8080A206_chdiggerboss[][4];
    extern f32 D_8080A208_chdiggerboss[][2];
    struct {
        u8 pad[0xDC];
        u32 phase;
        f32 timer;
        s32 state;
    } *data;
    data = func_80100094(arg0, 0);
    if (++data->phase >= 5U) {
        func_800FC74C(D_8080A1FE_chdiggerboss[data->phase][0]);
        data->state = 0;
        return 0;
    }
    data->timer = D_8080A208_chdiggerboss[data->phase][0];
    _chexploder_entrypoint_5(arg0, 0x91C, arg0->position,
        *(s32 *)((u8 *)arg0 + 0x48), 1.0f, 7);
    if (data->phase != 0) {
        func_800FC74C(D_8080A1FE_chdiggerboss[data->phase][0]);
    }
    func_800FC6B0(D_8080A206_chdiggerboss[data->phase][0]);
    return 1;
}

void func_80809310_chdiggerboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _chexploder_entrypoint_6(s32, s32, s32);
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 _chexploder_entrypoint_11(Actor *, f32 *);
    void func_808093F8_chdiggerboss(Actor *);
    extern s16 D_8080A204_chdiggerboss[][4];
    extern f32 D_8080A240_chdiggerboss[3];
    struct {
        u8 pad[0xDC];
        u32 phase;
        f32 timer;
        Unk80132ED0 *marker;
    } *temp, *data;
    Actor *exploder;
    Actor *child;

    exploder = func_80106790(func_80101080());
    temp = func_80100094(arg0, 0);
    data = temp;
    func_80802938_chdiggerboss(arg0, exploder->unk0,
        D_8080A204_chdiggerboss[data->phase][0], 0x28);
    _chexploder_entrypoint_6(exploder, 0x447A0000, 0x44960000);
    _chexploder_entrypoint_12(exploder, 0xFA);
    _chexploder_entrypoint_11(exploder, D_8080A240_chdiggerboss);
    func_808093F8_chdiggerboss(arg0);
    if (data->marker != NULL) {
        func_800FFA88(data->marker);
    }
    data->marker = exploder->unk0;
    if (arg0->unk3C != NULL) {
        child = func_80802228_chdiggerboss(arg0);
        child->unk3C = NULL;
        arg0->unk3C = NULL;
        func_800FFAB0(child);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/boss/func_808093F8_chdiggerboss.s")
