#include "common.h"

extern u32 D_808017DC_chtoothyfish[];
void func_80101870(Actor *, void *);
void func_801018A4(Actor *, BtIntPtr);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_80800000_chtoothyfish(Actor *arg0);
void func_80800470_chtoothyfish(Actor *arg0, s32 arg1, s32 arg2, u8 *arg3);
void func_808004A4_chtoothyfish(Actor *arg0);
s32 func_80800B68_chtoothyfish();
void func_80800E04_chtoothyfish(Actor *arg0);
void func_80800EDC_chtoothyfish(s32 arg0);
void func_8080106C_chtoothyfish(Actor *self);

u32 D_80801760_chtoothyfish[] = {
    0x00130544, 0x000D00CC, 0x01330016, 0x7FFF0001,
    0x0FA01D4C, 0x00000000,
};

u32 D_80801778_chtoothyfish[] = {
    0x001305CE, 0x000A0066, 0x00167FFF, 0x00010FA0,
    0x1D4C0000,
};

u32 D_8080178C_chtoothyfish[] = {
    0x001303ED, 0x000D0040, 0x004C0016, 0x46500000,
};

u32 D_8080179C_chtoothyfish[] = {
    0x001303ED, 0x000D004C, 0x00590016, 0x46500000,
};

u32 D_808017AC_chtoothyfish[] = {
    0x00130546, 0x000D00CC, 0x00E60016, 0x7D000001,
    0x0FA01D4C, 0x00000000,
};

u32 D_808017C4_chtoothyfish[] = {
    0x00130547, 0x000D00CC, 0x00E60016, 0x7D000001,
    0x0FA01D4C, 0x00000000,
};

u32 D_808017DC_chtoothyfish[] = {
    0x00000000, 0x00000000, 0x40000000, 0x01190001,
    0x3F99999A, 0x00FA0042, 0x3FC00000, 0x00FA0042,
    0x40000000, 0x011A0001, 0x40000000, 0x011A0001,
    0x40000000, 0x011A0001,
};

u32 D_80801814_chtoothyfish[] = {
    0x001D09D9, 0x00161004, 0x00010000, 0x00230000,
    0x00000032, 0x0000001B, 0x009600C8, 0x00070001,
    0x00150000, 0x00CC002B, 0x01800480, 0x0020FFFF,
    0xFEFF002F, 0x00400040, 0x00000000, 0x00190000,
    0x00330000,
};

u32 D_80801858_chtoothyfish[] = {
    0x3E2E147B, 0x3F2E147B, 0xBF800000,
};

u32 D_80801864_chtoothyfish[] = {
    0x3EDC28F6, 0x3F68F5C3, 0xBF800000,
};

BtFnWord D_80801870_chtoothyfish[] = {
    0x02D4030F, 0x06C50001, (BtFnWord)D_808017DC_chtoothyfish, (BtFnWord)func_808004A4_chtoothyfish,
    (BtFnWord)func_808004A4_chtoothyfish, (BtFnWord)func_801018A4, 0x2EE02AF8, 0x00000000,
    0x00000000, 0x00000C68, (BtFnWord)func_80800470_chtoothyfish, (BtFnWord)func_80108ED0,
    0x00400000, (BtFnWord)func_80800000_chtoothyfish, (BtFnWord)func_80107C2C, 0x00000000,
    (BtFnWord)func_80800B68_chtoothyfish, 0x00000000,
};

u32 D_808018B8_chtoothyfish[] = {
    0x001D09D9, 0x00161004, 0x002C0000, 0x00640000,
    0x000000C8, 0x0000000B, 0x000F001E, 0x000F0000,
    0x00010000, 0x00230000, 0x00000032, 0x0000001B,
    0x009600C8, 0x00070001, 0x00150000, 0x00CC002B,
    0x01800280, 0x0020FFFF, 0xFEFF002F, 0x00400040,
    0x00000000, 0x00190000, 0x00330000,
};

BtFnWord D_80801914_chtoothyfish[] = {
    0x02D50310, 0x073A0001, 0x00000000, (BtFnWord)func_8080106C_chtoothyfish,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000800, (BtFnWord)func_80800EDC_chtoothyfish, 0x00000000,
    0x00000000, (BtFnWord)func_80800E04_chtoothyfish, (BtFnWord)func_80107C2C, 0x80000002,
    0x00000000, 0x00000000, 0x00000000,
};

void func_80800000_chtoothyfish(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_808000E8_chtoothyfish(Actor *, s32);
    struct ToothyfishData {
        f32 unk0[6];
        f32 timers[5];
        s32 unk2C;
        f32 unk30;
        u8 flags[5];
        u8 other[5];
    } *data;
    s32 i;
    s32 count;

    data = func_80100094(arg0, 0);
    count = 0;
    for (i = 0; i < 5; i++) {
        data->flags[i] = func_800DA298(i + 0x4F6);
        if (data->flags[i] == 0) {
            count++;
        }
        data->other[i] = 0;
        data->timers[i] = 0.0f;
    }
    if (count == 0) {
        func_808000E8_chtoothyfish(arg0, 4);
    }
    data->unk2C = 0;
    data->unk30 = 1.0f;
    arg0->unk6C_0 = _subaddiesect_entrypoint_1(arg0);
}

void func_808000E8_chtoothyfish(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800FC660(u32);
    void func_80102424(Actor *, s32);
    if (arg1 != arg0->unk70_10) {
        func_80102424(arg0, arg1);
        switch (arg1) {
        case 1:
            break;
        case 2:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &(*(u32 *)D_80801760_chtoothyfish));
            func_800FC660(0xE);
            break;
        case 3:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &(*(u32 *)D_80801778_chtoothyfish));
            func_800FC660(0x10);
            break;
        case 4:
            break;
        }
    }
}

void func_80800188_chtoothyfish(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA568(s16 *, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    s32 sp34;
    s32 temp_v0;
    BtIntPtr temp_v0_2;

    temp_v0 = func_800DC128(0, 5);
    sp34 = temp_v0;
    temp_v0_2 = func_800B53A4(temp_v0);
    func_800BABB8(temp_v0_2, arg0, 0, 1.0f, &(*(s32 *)D_80801814_chtoothyfish));
    func_800BA568(temp_v0_2, (s16) (s32) (arg0[1] + arg1));
    func_800BA7C4(temp_v0_2, 0.16f * arg2, 0.3f * arg2);
    func_800BA7FC(temp_v0_2, 0.45f * arg2, 0.6f * arg2);
    func_800BA994(temp_v0_2, -75, (s16) (s32) (arg3 - 75.0f), 1200, -15, (s32) (arg3 + 75.0f), 1500);
    func_800BA22C(temp_v0_2, sp34);
}

void func_808002DC_chtoothyfish(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 *arg2);
    f32 sp1C[3];

    if (arg0->unk7C_12) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 0xA, sp1C);
        _subaddieaudioquick_entrypoint_4(arg0, sp1C, &(*(u32 *)D_8080178C_chtoothyfish), &(*(u32 *)D_80801858_chtoothyfish));
        _subaddieaudioquick_entrypoint_4(arg0, sp1C, &(*(u32 *)D_8080179C_chtoothyfish), &(*(u32 *)D_80801864_chtoothyfish));
    }
}

void func_80800350_chtoothyfish(Actor *arg0, u8 *arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80108B04(Actor *, u32);
    if ((arg1 + arg2)[0x39] >= 0x1E) {
        func_80108B04(arg0, arg2);
        arg0->unk74_29 = 1;
        return;
    }
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &(*(s32 *)D_808017AC_chtoothyfish));
    ((f32 *)(arg1 + 0x18))[arg2] = 1.0f;
}    typedef struct { u8 pad0[0x34]; u8 unk34; } Objtoothyfish_func_808003D4_chtoothyfish_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

void func_808003D4_chtoothyfish(Actor *arg0, u8 *arg1)
{
  void func_808000E8_chtoothyfish();
  s32 sp18;
  s32 var_a2;
  s32 var_v0;
  u8 *var_v1;
  var_a2 = 0;
 do { var_v0 = 0; var_v1 = arg1; do { var_v0 += 1; if ((((Objtoothyfish_func_808003D4_chtoothyfish_var_v1 *)var_v1)->unk34) == 0) { var_a2 += 1; } var_v1 += 1; } while (var_v0 != 5); } while (0);
  if (var_a2 != (*((u8 *) (((s8 *) arg1) + 0x3E))))
  {
    if (var_a2 != 0)
    {
      sp18 = var_a2;
#ifdef BT_NATIVE
      ((void (*)())func_808000E8_chtoothyfish)(arg0, 2, var_a2);
#else
      func_808000E8_chtoothyfish(arg0, 2, var_a2);
#endif
    }
    else
    {
      sp18 = var_a2;
#ifdef BT_NATIVE
      ((void (*)())func_808000E8_chtoothyfish)(arg0, 3, var_a2);
#else
      func_808000E8_chtoothyfish(arg0, 3, var_a2);
#endif
    }
    *((u8 *) (((s8 *) arg1) + 0x3E)) = ((u8) var_a2) & 0xFFFF;
  }
}

/* extern */

void func_80800470_chtoothyfish(Actor *arg0, s32 arg1, s32 arg2, u8 *arg3) {
    void func_808000E8_chtoothyfish();
    if (arg0->unk70_10 == 6) {
        if (arg1) {
            arg1 = 5;
        } else {
            arg1 = 5;
        }
#ifdef BT_NATIVE
        ((void (*)())func_808000E8_chtoothyfish)(arg0, arg1, arg2, arg3);
#else
        func_808000E8_chtoothyfish(arg0, arg1, arg2, arg3);
#endif
    }
}

void func_808004A4_chtoothyfish(Actor *arg0) {
    void _gcgoto_entrypoint_5(s32 arg0, s32 arg1, f32 arg2);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 *arg2);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void func_80090358(f32 *, f32, void *, BtIntPtr);
    f32 func_800D8FF8(void);
    s32 func_800DC298(f32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    void func_800E39A8(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    u8 func_800F8B88(void);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    BtIntPtr func_8010262C(Unk80132ED0 *, u32);
    void func_80105834(Actor *);
    void func_80105A9C(Actor *, f32);
    void func_8010A624(Actor *);
    void func_8010A63C(Actor *);
    s32 func_8010CAC0(f32 *, u32);
    struct ToothyfishData {
        f32 unk0[6];
        f32 timers[5];
        s32 unk2C;
        f32 unk30;
        u8 flags[5];
        u8 other[5];
    } *data;
    s32 i;
    BtIntPtr skeleton;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];

    data = func_80100094(arg0, 0);
    if (arg0->unk64_19) {
        func_8010A624(arg0);
    } else {
        func_8010A63C(arg0);
        if (data->unk30 < 1.0f) {
            data->unk30 += 0.3f * func_800D8FF8();
        }
    }
    ((f32 *)arg0->actorData)[3] = data->unk30 * 200.0f;
    func_80105A9C(arg0, ((f32 *)arg0->actorData)[3]);
    func_80105834(arg0);
    arg0->rotation[0] = 0.0f;
    arg0->rotation[1] += func_800F1DCC(arg0->unk54, arg0->rotation[1]) * 0.1f;
    skeleton = func_8010262C(arg0->unk0, 5);
    if (skeleton) {
        for (i = 0; i < 5; i++) {
            if (data->timers[i] > 0.005f || data->timers[i] < -0.005f) {
                data->timers[i] *= -0.9f;
            }
            func_800E0AFC((void *)skeleton, 0x5A - i, 1.0f,
                         data->timers[i] * 15.0f, data->timers[i] * 15.0f,
                         data->timers[i] * 0);
        }
    }
    if (arg0->unk74_29) {
        func_808003D4_chtoothyfish(arg0, (u8 *)data);
    }
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2:
        if (func_80101E14(arg0, 0.999f)) {
            func_808000E8_chtoothyfish(arg0, 1);
        }
        break;
    case 3:
        if (func_80101E14(arg0, 0.25f)) {
            func_808000E8_chtoothyfish(arg0, 4);
        }
        break;
    case 4:
        func_800EEC30(sp50, -arg0->rotation[0] - 30.0f, arg0->rotation[1], arg0->scale * 80.0f);
        func_800EF04C(sp50, arg0->position);
        _sudeflect_entrypoint_0(sp50, arg0->scale * 70.0f, arg0->scale * 80.0f, 4);
        if (func_8010CAC0(sp50, (s32)(arg0->scale * 70.0f)) && func_800F8B88() != 3) {
            func_800E39A8(data->unk0, &data->unk0[3]);
            _gcgoto_entrypoint_5(0xF8, 1, arg0->rotation[1] + 180.0f);
            arg0->unk64_20 = 1;
            func_80090358(arg0->position, 4.0f, NULL, 0);
            func_808000E8_chtoothyfish(arg0, 5);
        }
        break;
    case 6:
        data->unk30 = 0.0f;
        break;
    case 5:
        func_800EEC30(sp44, -arg0->rotation[0] - 20.0f, arg0->rotation[1], arg0->scale * 80.0f);
        func_800EF04C(sp44, arg0->position);
        if (!func_8010CAC0(sp44, (s32)(arg0->scale * 150.0f))) {
            func_808000E8_chtoothyfish(arg0, 4);
        }
        break;
    }
    func_808002DC_chtoothyfish(arg0);
    if (arg0->unk7C_12 && (func_800DC298(0.03f) ||
        (arg0->unk70_10 == 2 && func_800DC298(0.1f)))) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 6, sp38);
        func_80800188_chtoothyfish(sp38, 1000.0f, arg0->scale, arg0->rotation[1]);
    }
}

s32 func_80800908_chtoothyfish(s32 arg0) {
    switch (arg0 &= 0x78000000) {
    case 0x28000000:
        return 0;
    case 0x08000000:
        return 1;
    case 0x10000000:
        return 2;
    case 0x18000000:
        return 3;
    case 0x20000000:
        return 4;
    default:
        arg0 = -1;
        break;
    }
    return arg0;
}

void func_8080096C_chtoothyfish(Actor *arg0, Unk80132ED0 *arg1) {
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    Unk80132ED0 *_sueggmove_entrypoint_1(Unk80132ED0 *);
    s32 _sueggmove_entrypoint_2(Unk80132ED0 *);
    struct ToothyfishData {
        f32 unk0[6];
        f32 timers[5];
        s32 unk2C;
        f32 unk30;
        u8 flags[5];
        u8 other[5];
    } *data;
    s32 valid;
    s32 damage;
    s32 index;
    u32 adjacent;

    data = func_80100094(arg0, 0);
    valid = 1;
    damage = 0;
    if (arg0->unk7C_12 && arg1 != NULL) {
        switch (arg1->unk24 >> 22) {
        case 0x26C:
            damage = 10;
            break;
        case 0x26D:
            damage = 20;
            break;
        case 0x26F:
            damage = 30;
            break;
        case 0x26E:
            damage = 20;
            break;
        default:
            valid = 0;
            break;
        }
        if (damage && valid) {
            if (_sueggmove_entrypoint_1(arg1) == arg0->unk0) {
                index = func_80800908_chtoothyfish(_sueggmove_entrypoint_2(arg1));
                if (index >= 0) {
                    data->other[index] += damage;
                    if (damage == 30) {
                        if (index > 0) {
                            adjacent = index - 1;
                            if (data->flags[index - 1] == 0) {
                            data->other[adjacent] += 10;
                            data->timers[adjacent] = 0.5f;
                            if (data->other[adjacent] >= 30) {
                                func_80108B04(arg0, adjacent);
                            }
                        }
                        }
                        if (index < 4) {
                            adjacent = index + 1;
                            if (data->flags[adjacent] == 0) {
                            data->other[adjacent] += 10;
                            data->timers[adjacent] = 0.5f;
                            if (data->other[adjacent] >= 30) {
                                func_80108B04(arg0, adjacent);
                            }
                        }
                    }
                    }
                    if (data->flags[index] == 0) {
                        func_80800350_chtoothyfish(arg0, (u8 *)data, index);
                    }
                }
            }
        }
    }
}

s32 func_80800B68_chtoothyfish(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_800DF744(s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A00(BtIntPtr, s32);
    void func_800F4A2C(BtIntPtr, f32 *);
    void func_800F4A8C(BtIntPtr, f32 *, f32);
    u32 func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800F832C(BtIntPtr arg0,f32* a1);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    void func_80103014(u8 *);
    void func_8010573C(Actor *, f32);
    void func_80801588_chtoothyfish(Actor *, BtIntPtr);
    extern s32 func_8010D5DC;
    struct ToothyfishData {
        f32 unk0[6];
        f32 timers[5];
        s32 unk2C;
        f32 unk30;
        u8 flags[5];
        u8 other[5];
    } *data;
    f32 position[3];
    f32 rotation[3];
    BtIntPtr player;
    s32 i;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x49:
        if (arg0->unk64_20) {
            player = func_800F54E4();
            func_8010573C(arg0, 0.73f);
            func_80103014((u8 *)arg0);
            func_800EEC30(position, -arg0->rotation[0], arg0->rotation[1], arg0->scale * 150.0f);
            func_800EF04C(position, arg0->position);
            func_800EFA4C(rotation, 0.0f, arg0->rotation[1], 0.0f);
            func_800F8294(player, position);
            func_800F832C(player, rotation);
            func_800F608C(player, 5);
            func_800F497C(player);
            func_800F4A2C(player, position);
            func_800F49A8(player, 1);
            func_800F4A00(player, 1);
            func_800F49D4(player, &func_8010D5DC, (BtIntPtr)arg0->unk0);
            func_800EEC30(position, -arg0->rotation[0], arg0->rotation[1], arg0->scale * 350.0f);
            func_800EF04C(position, arg0->position);
            func_800F4A8C(player, position, 2.0f);
            data->unk30 = 0.0f;
            arg0->unk79_4 = 15;
            arg0->unk64_20 = 0;
            arg0->unk64_19 = 1;
            arg0->unk58 = 5.0f;
            _capod_entrypoint_13(arg0->unk0, NULL, 0x2E, 0xA4C);
        }
        break;
    case 0x32:
        arg0->unk64_19 = 0;
        break;
    case 0x3E:
        func_8080096C_chtoothyfish(arg0, arg2);
        break;
    case 0x3D:
        func_80801588_chtoothyfish(arg0, (BtIntPtr)arg2);
        break;
    case 0x1F:
        func_801015D0(arg0);
        for (i = 0; i < 5; i++) {
            if (data->flags[i]) {
                func_800DF744(i + 3, 0);
            } else {
                func_800DF744(i + 3, 1);
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chtoothyfish_entrypoint_0(void)
{
    return (OSThread *) ((u8 *)D_80801870_chtoothyfish);
}

void func_80800E04_chtoothyfish(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 *arg2);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp2C;

    sp2C = func_80106790(arg0->unk3C);
    _subaddieskeleton_entrypoint_2(arg0->unk3C, arg0->unk6C_0 + 4, arg0->position);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &(*(s32 *)D_808017C4_chtoothyfish));
    arg0->scale = sp2C->scale;
    arg0->rotation[2] = sp2C->rotation[2];
    arg0->rotation[0] = sp2C->rotation[0];
    func_800EFCD8((f32 *)&arg0->actorData[4], func_800F1DF4(sp2C->position, arg0->position), 3000.0f);
    *(f32 *)&arg0->actorData[5] = 200.0f;
    *(f32 *)&arg0->actorData[7] = -1000.0f;
    func_80103140(arg0, (arg0->unk6C_0 + 0x73A) & 0xFFFF, arg0->unk0->unk16);
}

void func_80800EDC_chtoothyfish(s32 arg0) 
{
}
void func_80800EE4_chtoothyfish(Actor *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);

    func_80101FDC(arg0, arg1);
    switch (arg1) {
        case 2:
            arg0->unk50 = func_800DC178(165.0f, 195.0f);
            break;
        case 4:
            arg0->unk50 = func_800DC178(45.0f, 135.0f);
            break;
    }
}

void func_80800F6C_chtoothyfish(f32 *arg0, f32 arg1, f32 arg2) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA568(s16 *, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    s32 sp2C;
    s32 temp_v0;
    BtIntPtr temp_v0_2;

    temp_v0 = func_800DC128(0, 5);
    sp2C = temp_v0;
    temp_v0_2 = func_800B53A4(temp_v0);
    func_800BABB8(temp_v0_2, arg0, 0, 1.0f, &(*(s32 *)D_808018B8_chtoothyfish));
    func_800BA568(temp_v0_2, (s16) (s32) (arg0[1] + arg1));
    func_800BA7C4(temp_v0_2, 0.08f * arg2, 0.15f * arg2);
    func_800BA7FC(temp_v0_2, 0.09f * arg2, 0.18f * arg2);
    func_800BA22C(temp_v0_2, sp2C);
}

void func_8080106C_chtoothyfish(Actor *self)
{
  f32 func_800D8FF8(void);
  void func_800EFA20(void *, void *, f32);
  void func_800EF04C(f32 *, f32 *);
  s32 func_800DC298(f32);
  f32 func_800DC178(f32, f32);
  s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
  s32 func_80102D4C(Actor *, f32);
  s32 func_80102CF4(Actor *, f32);
  void func_80102B6C(u8 *, f32);
  void func_80102B2C(Actor *, f32);
  void func_80800EE4_chtoothyfish(Actor *, s32);
  void func_80800F6C_chtoothyfish(f32 *, f32, f32);
  f32 delta[3];
  f32 dt;
  dt = func_800D8FF8();
  func_800EFA20(delta, &self->actorData[4], dt);
  switch (self->unk70_10)
  {
    case 1:
      func_800EF04C(self->position, delta);
      ((f32 *) self->actorData)[4] *= 0.7f;
      ((f32 *) self->actorData)[6] *= 0.7f;
      ((f32 *) self->actorData)[5] += ((f32 *) self->actorData)[7] * dt;
      if (((f32 *) self->actorData)[5] < (-50.0f))
    {
      func_80800EE4_chtoothyfish(self, 2);
    }
      self->rotation[0] += 400.0f * dt;
      self->rotation[1] += 200.0f * dt;
      if (func_800DC298(0.2f))
    {
      func_80800F6C_chtoothyfish(self->position, 200.0f, self->scale);
    }
      break;

    case 2:
      func_800EF04C(self->position, delta);
      ((f32 *) self->actorData)[4] *= 0.7f;
      ((f32 *) self->actorData)[6] *= 0.7f;
      ((f32 *) self->actorData)[5] += ((f32 *) self->actorData)[7] * dt;
      if (_subaddie3d_entrypoint_0(self->position, 0.0f, self->scale * (-200.0f), &((f32 *) self->actorData)[1]))
    {
      if ((((f32 *) self->actorData)[1] + (20.0f * self->scale)) < (delta[1] + self->position[1]))
      {
        self->position[1] += delta[1];
      }
      else
      {
        func_80800EE4_chtoothyfish(self, 4);
      }
    }
    else
      if (func_80102D4C(self, 4.0f))
    {
      func_80800EE4_chtoothyfish(self, 3);
    }
    else
    {
      func_80102B6C((u8 *) self, 4.0f);
    }
      if (func_800DC298(0.2f))
    {
      func_80800F6C_chtoothyfish(self->position, 200.0f, self->scale);
    }
      break;

    case 3:
      ((f32 *) self->actorData)[4] *= 0.7f;
      ((f32 *) self->actorData)[6] *= 0.7f;
      ((f32 *) self->actorData)[5] += ((f32 *) self->actorData)[7] * dt;
      self->position[0] += ((f32 *) self->actorData)[4];
      self->position[2] += ((f32 *) self->actorData)[6];
      if (_subaddie3d_entrypoint_0(self->position, 0.0f, self->scale * (-200.0f), &((f32 *) self->actorData)[1]))
    {
      if ((((f32 *) self->actorData)[1] + (50.0f * self->scale)) < (delta[1] + self->position[1]))
      {
        self->position[1] += delta[1];
      }
      else
      {
        func_80800EE4_chtoothyfish(self, 4);
      }
    }
    else
    {
      self->position[1] += delta[1];
    }
      if (!func_80102D4C(self, 3.0f))
    {
      func_80102B6C((u8 *) self, 3.0f);
    }
      if (!func_80102CF4(self, 3.0f))
    {
      func_80102B2C(self, 3.0f);
    }
      if (func_800DC298(0.1f))
    {
      self->unk50 = func_800DC178(140.0f, 220.0f);
    }
      if (func_800DC298(0.1f))
    {
      self->unk54 = self->rotation[1] + func_800DC178(-90.0f, 90.0f);
    }
      if (func_800DC298(0.2f))
    {
      func_80800F6C_chtoothyfish(self->position, 200.0f, self->scale);
    }
      break;

    case 4:
      if ((((f32 *) self->actorData)[1] + (10.0f * self->scale)) < self->position[1])
    {
      self->position[1] += ((f32 *) self->actorData)[5] * dt;
    }
    else
      if (self->position[1] < ((f32 *) self->actorData)[1])
    {
      self->position[1] += 4.0f;
    }
      if (!func_80102D4C(self, 8.0f))
    {
      func_80102B6C((u8 *) self, 8.0f);
    }
    else
    {
      func_80800EE4_chtoothyfish(self, 5);
    }
      break;

    case 5:
      if ((((f32 *) self->actorData)[1] + (10.0f * self->scale)) < self->position[1])
    {
      self->position[1] += ((f32 *) self->actorData)[5] * dt;
    }
    else
      if (self->position[1] < (((f32 *) self->actorData)[1] + (5.0f * self->scale)))
    {
      self->position[1] += 4.0f;
    }
    else
    {
      ((u8 *) self)[0x7E] &= ~0x40;
    }
      break;

  }

}

/* extern */

void func_80801588_chtoothyfish(Actor *arg0, BtIntPtr arg1) {
    void* func_80100094(Actor*, u32);
    Actor* func_801084B0(BtIntPtr, Actor**);
    void func_800DA544(s32 index);
    Actor *sp1C;
    u8 *sp18;

    sp18 = func_80100094(arg0, 0U);
    sp1C = func_801084B0(0x310, &arg0);
    func_800DA544(arg1 + 0x4F6);
    (*(s8 *)((s8 *)((sp18 + arg1)) + (0x34))) = 1;
    sp1C->unk3C = arg0->unk0;
    sp1C->unk6C_0 = arg1;
}

OSThread *chtoothyfish_entrypoint_1(void)
{
    return (OSThread *) ((u8 *)D_80801914_chtoothyfish);
}
