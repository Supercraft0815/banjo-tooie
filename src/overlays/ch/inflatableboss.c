#include "common.h"

OSThread *chinflatableboss_entrypoint_0(void)
{
    extern u8 D_80802E50_chinflatableboss[];

    return (OSThread *) D_80802E50_chinflatableboss;
}

void func_8080000C_chinflatableboss(Actor *arg0) {
    typedef struct {
        f32 position[3];
        s32 id;
        s32 unk10;
        s32 unk14;
    } BossMarker;
    typedef struct {
        u8 unk0[8];
        u8 unk8[0x14];
        f32 position1[3];
        f32 position2[3];
        f32 position3[3];
        u8 unk40[8];
        f32 positions[3][3];
        s32 count6C;
        BossMarker markers70[20];
        s32 count250;
        BossMarker markers254[20];
        u8 unk434[0x60];
        u8 unk494;
        u8 unk495;
        u8 unk496;
        u8 unk497;
        u8 unk498;
        u8 unk499[3];
        u8 unk49C;
    } BossData;
    s32 _chcredits_entrypoint_1(void);
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_20(void);
    void _plcamera_entrypoint_8(s32);
    void _subaddieDll_entrypoint_10(s32, void *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, BossMarker *, s32);
    s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, BossMarker *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F497C(s32);
    void func_800F49D4(s32, void *, Unk80132ED0 *);
    void func_800F4A58(s32, f32 *, f32);
    u32 func_800F54E4(void);
    void func_800F608C(s32, s32);
    s32 func_800F64A4(s32, s32);
    void func_800F8294(s32, f32 *);
    void func_800F8300(s32, s32, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    void func_80109FE8(Actor *, s32);
    void func_8010A85C(Actor *, s32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    void func_8080183C_chinflatableboss(Actor *);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    void func_80802AD8_chinflatableboss(Actor *, s32, s32);
    extern s16 D_80802D8C_chinflatableboss;
    extern s32 func_8010D5DC;
    BossData *data;
    s32 i;
    BossMarker markers[3];
    s32 j;
    s32 k;
    s32 count;
    BossMarker *marker;
    s32 player;
    s32 pad;
    f32 *volatile position;

    data = func_80100094(arg0, 0);
    func_800DA524(1);
    func_800DA524(2);
    func_800DA524(4);
    func_800DA524(3);
    func_800DA524(5);
    if (func_800DA298(0x9C) && !_glcutDll_entrypoint_20()) {
        func_800DA544(3);
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(arg0);
        return;
    }
    func_80102FDC(arg0, 1.4f);
    data->unk494 = 1;
    data->unk495 = D_80802D8C_chinflatableboss;
    ((f32 *)arg0->actorData)[4] = 0.35f;
    func_80109FE8(arg0, 0);
    func_800EE7F8(data->position1, position = arg0->position);
    func_800EE7F8(data->position2, position);
    func_800EE7F8(data->position3, position);
    for (i = 0; i != 12; i++) {
        func_80802AD8_chinflatableboss(arg0, i, 1);
    }
    _subaddieDll_entrypoint_10(0x154, data->unk0);
    _subaddieDll_entrypoint_10(0x320, data->unk8);
    func_8080183C_chinflatableboss(arg0);
    func_8010A85C(arg0, 2);
    _suexpression_entrypoint_7(arg0, 1, 0x3A);
    data->count6C = _subaddiemarker_entrypoint_1(arg0, 0x437, 0x32, data->markers70, 20);
    data->count250 = _subaddiemarker_entrypoint_1(arg0, 0x437, 0x35, data->markers254, 20);
    count = _subaddiemarker_entrypoint_0(arg0, 0x3DA, markers, 20);
    j = 0;
    if (count > 0) {
        do {
            k = 0;
            if (count > 0) {
                marker = markers;
                do {
                    if (j + 0x32 == marker->id) {
                        break;
                    }
                    k++;
                    marker++;
                } while (k != count);
            }
            func_800EE7F8(data->positions[j], markers[k].position);
            j++;
        } while (j < count);
    }
    if (func_800DA298(0x17F)) {
        data->unk498 = 5;
    } else {
        data->unk498 = 1;
    }
    if (!func_800F64A4(func_800F54E4(), 1)) {
        data->unk498 = 0;
    }
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C(arg0, 1);
        func_80800F84_chinflatableboss(arg0, _chcredits_entrypoint_1() == 0x36 ? 0x12 : 0x13);
        return;
    }
    if (data->unk498 == 5) {
        player = func_800F54E4();
        data->unk49C = 1;
        data->unk496 = 1;
        func_800F608C(player, 1);
        func_800F8294(player, data->positions[1]);
        func_800F8300(player, 2, position);
        func_800F497C(player);
        _plcamera_entrypoint_8(player);
        func_800DA544(2);
        func_80802A00_chinflatableboss(arg0, 0x22, 0x20);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1087, 0x107, position, 0x3A);
        func_80800F84_chinflatableboss(arg0, 3);
        func_8010A85C(arg0, 1);
        return;
    }
    if (func_800D395C()) {
        arg0->unk64_16 = 1;
        data->unk498 = 2;
        func_800F497C(func_800F54E4());
        func_800F49D4(func_800F54E4(), &func_8010D5DC, arg0->unk0);
        func_800F4A58(func_800F54E4(), data->positions[0], 300.0f);
        func_80802A00_chinflatableboss(arg0, 0x2F, 0x20);
    } else {
        arg0->unk64_16 = 0;
        _chintrotext_entrypoint_2(1);
    }
}

void func_80800408_chinflatableboss(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor *, u32);
    s32 func_800BA2C4(void *);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    void *temp_a0;
    void *temp_a0_2;
    s32 var_s1;
    u8 *var_s0;

    sp2C = func_80100094(arg0, 0);
    _suexpression_entrypoint_8(arg0, 1);
    var_s1 = 0;
    var_s0 = sp2C;
    do {
        temp_a0 = *(void **)(var_s0 + 0x43C);
        if (temp_a0 != NULL) {
            *(s32 *)(var_s0 + 0x43C) = func_800BA2C4(temp_a0);
        }
        var_s1 += 4;
        var_s0 += 4;
    } while (var_s1 != 0x30);
    temp_a0_2 = *(void **)(sp2C + 0x434);
    if (temp_a0_2 != NULL) {
        *(s32 *)(sp2C + 0x434) = func_800BA2C4(temp_a0_2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_808004A0_chinflatableboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80800A98_chinflatableboss.s")

struct anctrl_s;
void func_80800F84_chinflatableboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    s32 func_80801C7C_chinflatableboss(Actor *);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_8010A570(Actor *);
    extern s16 D_80802D8C_chinflatableboss;
    u8 *sp2C;

    sp2C = func_80100094(arg0, 0);
    func_80102424(arg0, arg1);
    switch (arg1) {
        case 11:
            func_8008B1C8(func_80104248(arg0), 0.8f);
            sp2C[0x495] = (&D_80802D8C_chinflatableboss)[func_80801C7C_chinflatableboss(arg0)];
            break;
        case 13:
            func_8008B1C8(func_80104248(arg0), 0.8f);
            *(f32 *)(sp2C + 0x44) = arg0->scale;
            break;
        case 14:
            func_80802A00_chinflatableboss(arg0, 0x2B, 0x30);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1084, 0x10C, arg0->position, 0x3A);
            func_8010A570(arg0);
            func_8008B1C8(func_80104248(arg0), 0.8f);
            break;
        case 16:
            arg0->unk64_16 = 0;
            break;
    }
}

void func_808010BC_chinflatableboss(Actor *arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    u32 state;
    s32 index;
    Unk80132ED0 *marker;

    sp2C = func_80100094(arg0, 0);
    if (func_800DA298(5) == 0) {
        marker = arg0->unk0;
        state = (marker->unk18 << 11) >> 28;
        index = state;
        if ((s32)state >= 3 && (s32)state < 15) {
            index -= 3;
            if ((sp2C + index)[0x487] != 2) {
            _subaddiedialog_entrypoint_11(marker, 0x1086, 0x10E, arg0->position, 0x3A);
            func_800DA544(5);
            arg0->unk74_30 = 1;
            }
        }
    }
}

void func_80801164_chinflatableboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 unk0[0x43C];
        s32 effects[12];
        u8 unk46C[0x1B];
        u8 states[12];
        u8 unk493;
    } BossData;
    void *func_80100094(Actor *, u32);
    s32 func_80802590_chinflatableboss(Actor *, f32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_808012EC_chinflatableboss(Actor *, f32[3], s32);
    void func_80801904_chinflatableboss(Actor *, s32, f32 *);
    s32 func_80801FC0_chinflatableboss(u8 *, f32 *, f32 *);
    void func_80802AD8_chinflatableboss(Actor *, s32, s32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    s32 func_80801CB4_chinflatableboss(Actor *);
    void func_800DA544(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    extern u8 D_80802F08_chinflatableboss[];
    BossData *sp54;
    s32 sp50;
    f32 sp44[3];
    f32 sp38[3];
    s32 sp34;
    u32 state;
    s32 count;

    sp54 = func_80100094(arg0, 0);
    state = (arg0->unk0->unk18 << 11) >> 28;
    sp50 = state;
    if ((s32)state >= 3 && (s32)state < 15) {
        sp50 -= 3;
        if (sp54->states[sp50] != 2) {
            sp34 = func_80802590_chinflatableboss(arg0, sp44, state);
            _subaddieaudioquick_entrypoint_2(arg0, sp44, D_80802F08_chinflatableboss);
            func_808012EC_chinflatableboss(arg0, sp44, sp34);
            func_80801904_chinflatableboss(arg0, sp50, sp38);
            sp54->effects[sp50] = func_80801FC0_chinflatableboss((u8 *)arg0, sp44, sp38);
            func_80802AD8_chinflatableboss(arg0, sp50, 2);
            func_80800F84_chinflatableboss(arg0, 12);
            func_8008B1C8(func_80104248(arg0), 0.8f);
            sp54->unk493 = 1;
            count = func_80801CB4_chinflatableboss(arg0);
            if (count != 0) {
                if (count == 11) {
                    func_800DA544(5);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1085, 0x10E, arg0->position, 0x3A);
                    func_80802A00_chinflatableboss(arg0, 0x2D, 0x20);
                    arg0->unk74_30 = 1;
                }
            } else {
                func_800DA544(0);
                func_80802A00_chinflatableboss(arg0, 0x29, 0x30);
            }
        }
    }
}

void func_808012EC_chinflatableboss(Actor *arg0, f32 arg1[3], s32 arg2) {
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    void func_800BA714(void *, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_80801904_chinflatableboss(Actor *, s32, f32 *);
    extern s16 D_80802F0E_chinflatableboss[];
    extern s32 D_80802F2C_chinflatableboss[];
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;

    func_80801904_chinflatableboss(arg0, ((arg0->unk0->unk18 << 11) >> 28) - 3, sp28);
    func_800EFB24(sp34, arg1, sp28);
    func_800EF368(sp34, arg2 * 0.5f);
    func_800EF04C(sp34, arg1);
    sp24 = func_800BABB8(0, arg1, sp34, arg0->scale, D_80802F2C_chinflatableboss);
    func_800BA714(sp24, arg2 * 0.4f, arg2 * 0.6f);
    func_800BA670(sp24, D_80802F0E_chinflatableboss[(arg0->unk0->unk18 << 11) >> 28]);
    func_800BA22C(sp24, 8);
}

void func_80801418_chinflatableboss(Actor *arg0, u8 *arg1) {
    typedef struct {
        u8 pad[0x478];
        u8 visibility[15];
    } BossRenderData;
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _suexpression_entrypoint_19(void *, Actor *);
    void func_800DF660(s32, s32, s32, s32);
    void func_800DF720(s32);
    void func_800DF72C(s32);
    void func_800DF738(s32);
    void func_800DF744(s32, s32);
    void func_800DF818(s32);
    void func_800DF830(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80100AC4(s16);
    void func_80101934(Actor *);
    s32 func_80103CDC(u8 *, u8 *);
    void func_80103D48(void **);
    void func_80103D70(void **);
    void *func_801040A8(Actor *);
    OSThread *func_80104130(void);
    void func_8080267C_chinflatableboss(Actor *);
    s32 i;
    BossRenderData *data;

    data = func_80100094(arg0, 0);
    func_80103D48(arg0);
    _suexpression_entrypoint_19(func_80100094(arg0, 1), arg0);
    if (!arg0->unk64_20) {
        func_8080267C_chinflatableboss(arg0);
    }
    func_800DF72C(func_801040A8(arg0));
    func_800DF830(1);
    func_800DF738(func_80104130());
    func_800DF818(func_80103CDC(arg0, arg1));
    func_800DF660(2, arg0->pad7A_7, 0, _subaddiefade_entrypoint_0(arg0));
    func_800DF720(func_80100AC4(*(s16 *)&arg0->pad60));
    func_80101934(arg0);
    func_80103D70(arg0);
    for (i = 0; i != 15; i++) {
        func_800DF744(i + 3, data->visibility[i]);
    }
    arg0->unk7C_12 = 1;
    arg0->unk64_20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801554_chinflatableboss.s")

void func_8080183C_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 points[2][8];
        f32 position[3];
        u8 unk1C[0x478];
        u8 unk494;
        u8 unk495[2];
        u8 unk497;
    } BossData;
    typedef struct {
        f32 position[3];
    } BossActorData;
    void *func_80100094(Actor *, u32);
    void _subaddieDll_entrypoint_12(void *, s16 *);
    f32 func_800DC178(f32, f32);
    BossData *data;
    s16 point[2];
    void *source;

    data = func_80100094(arg0, 0);
    data->unk494 ^= 1;
    if (data->unk494) {
        source = data->points[0];
    } else {
        source = data->points[1];
    }
    _subaddieDll_entrypoint_12(source, point);
    data->position[0] = point[0];
    data->position[1] = arg0->position[1];
    data->position[2] = point[1];
    ((BossActorData *)arg0->actorData)->position[0] = func_800DC178(0.0f, 1000.0f);
    ((BossActorData *)arg0->actorData)->position[1] = arg0->position[1];
    ((BossActorData *)arg0->actorData)->position[2] = func_800DC178(0.0f, 1000.0f);
    data->unk497 = 1;
}

void func_80801904_chinflatableboss(Actor *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    f32 *var_a1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((arg1 >= 3) && (arg1 < 6)) {
        var_a1 = temp_v0 + 0x34;
    } else {
        var_a1 = temp_v0 + 0x28;
    }
    func_800EE7F8(arg2, var_a1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80801958_chinflatableboss.s")

void func_80801AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor*, u32);
    if (arg1 == 0x1085) {
        func_80108B04(arg0, 0U);
    }
}

void func_80801B04_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 unk0[0x10];
        f32 position[3];
        u8 unk1C[0x24];
        f32 unk40;
        u8 unk44[0x44F];
        u8 unk493;
        u8 unk494[3];
        u8 unk497;
    } BossData;
    typedef struct {
        f32 position[3];
        f32 unkC;
    } BossActorData;
    void *func_80100094(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800F15F8(f32, f32, f32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80101F24(Actor *);
    f32 func_800F3780(f32, u8 *, s16);
    s32 func_8010C3A8(Actor *, u32, f32);
    int func_800F0064(f32 *, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    extern u8 D_80802F68_chinflatableboss[];
    BossData *data;

    data = func_80100094(arg0, 0);
    arg0->unk54 = func_80102D78(arg0, ((BossActorData *)arg0->actorData)->position);
    ((BossActorData *)arg0->actorData)->unkC = func_800F15F8(((BossActorData *)arg0->actorData)->unkC, data->unk40, func_800D8FF8() * 200.0f);
    func_80102BF8(arg0, 0.1f, 3.0f, 60.0f);
    func_8010C3A8(arg0, 5, func_800F3780(func_80101F24(arg0), D_80802F68_chinflatableboss, 5));
    if (func_800F0064(((BossActorData *)arg0->actorData)->position, 400.0f, arg0->position)) {
        if (data->unk497) {
            func_80800F84_chinflatableboss(arg0, 7);
            func_800EE7F8(((BossActorData *)arg0->actorData)->position, data->position);
            data->unk497 = 0;
            arg0->unk58 = func_800DC178(4.0f, 6.0f);
        } else if (data->unk493 == 0) {
            func_80800F84_chinflatableboss(arg0, 9);
            arg0->unk58 = func_800DC178(6.0f, 8.0f);
        } else {
            func_80800F84_chinflatableboss(arg0, 10);
        }
        func_8008B1C8(func_80104248(arg0), 0.8f);
    }
}

/* extern */

s32 func_80801C7C_chinflatableboss(Actor *arg0) {
    s32 func_80801CB4_chinflatableboss(Actor *);
    return (s32) (0xC - func_80801CB4_chinflatableboss(arg0)) / 2;
}

s32 func_80801CB4_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 remaining;
    s32 i;
    u8 *data;

    data = func_80100094(arg0, 0U);
    remaining = 12;
    for (i = 0; i < 12; i++) {
        if (data[0x487 + i] == 2) {
            remaining--;
        }
    }
    return remaining;
}

void func_80801D38_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    extern f32 D_80802D98_chinflatableboss[];
    u8 *sp24;
    Actor *sp20;
    s32 sp1C;

    sp24 = func_80100094(arg0, 0);
    sp1C = func_80801C7C_chinflatableboss(arg0);
    sp20 = func_80108528(0x13D, (f32 *)(sp24 + 0x1C), 0, &arg0);
    func_80102FDC(sp20, arg0->scale);
    sp20->unk3C = arg0->unk0;
    sp20->unk6C_0 = func_80801CB4_chinflatableboss(arg0);
    sp20->unk58 = D_80802D98_chinflatableboss[sp1C];
}

void func_80801DE0_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    void func_80802A9C_chinflatableboss(Actor *);
    void func_80801EA0_chinflatableboss(Actor *);
    u8 *data;

    data = func_80100094(arg0, 0);
    _chappearfx_entrypoint_1(func_80108528(0x13E, (f32 *)(data + 0x254), (s32)*(f32 *)(data + 0x264), &arg0), 0x22, 0, 1.0f);
    func_80108528(0x36E, (f32 *)(data + 0x254), (s32)*(f32 *)(data + 0x264), &arg0);
    if (func_800DA298(0x6AC) == 0) {
        func_800DA544(0x6AC);
        func_80802A00_chinflatableboss(arg0, 8, 0x30);
    } else {
        func_80802A9C_chinflatableboss(arg0);
        func_80801EA0_chinflatableboss(arg0);
    }
}

void func_80801EA0_chinflatableboss(Actor *arg0) {
    typedef struct {
        f32 position[3];
        f32 unkC;
        f32 rotation;
        f32 unk14;
    } BossSpawn;
    typedef struct {
        u8 pad0[0x6C];
        s32 count;
        BossSpawn spawns[20];
    } BossSpawns;
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
    s32 i;
    BossSpawns *data;

    data = func_80100094(arg0, 0);
    for (i = 0; i < data->count; i++) {
        _chappearfx_entrypoint_2(func_80108474(0x234, data->spawns[i].position, (s32)data->spawns[i].rotation), 0x20, 2, 1.0f);
    }
}

/* extern */

void func_80801F4C_chinflatableboss(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor* func_80106790(Unk80132ED0 *);
    s32 func_800D10D4(s32, s32, f32 *, s32, s32);
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);
    f32 sp2C[3];
    s32 sp28;
    Unk80132ED0 *sp24;

    sp24 = arg0->unk0;
    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] = 5000.0f;
    sp28 = func_800D10D4(0x17, 1, sp2C, 0, 0);
    func_80802A2C_chinflatableboss(func_80106790(sp24), (Unk80132ED0 *)sp28, 0x14, 0x438);
}

s32 func_80801FC0_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802F90_chinflatableboss;
    func_800BABB8(0, arg1, arg2, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f, &D_80802F90_chinflatableboss);
}

void func_8080200C_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802FC4_chinflatableboss;
    func_800BABB8(0, arg1, arg2, (*(f32 *)((s8 *)(arg0) + (0x38))) * 0.75f, &D_80802FC4_chinflatableboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_80802058_chinflatableboss.s")

void func_80802264_chinflatableboss(Actor *arg0, f32 arg1, f32 arg2, f32 *arg3, s16 arg4) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3868(u8, f32, f32, f32, f32);
    u8 func_800C4350(u8, f32[3], s32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    extern s32 D_80803008_chinflatableboss;
    f32 temp_f20;
    f32 *var_s1;
    f32 *temp_s0;
    u8 temp_v0;
    int var_s2;
    var_s2 = 0;
    if (arg4 > 0) {
    var_s1 = arg3; do { if (func_80101E14(arg0, *var_s1) != 0) {
    temp_s0 = arg0->position;
    temp_f20 = func_800F10B4((f32) var_s2, 0.0f, (f32) arg4, arg1, arg2);
    temp_v0 = _subaddieaudioquick_entrypoint_1(arg0, temp_s0);
    func_800C3868(temp_v0, 0.15f, 0.25f, temp_f20, temp_f20 + 0.12f);
    func_800C4350(temp_v0, temp_s0, &D_80803008_chinflatableboss);
    }
    var_s2++;
    var_s1++;
    }
    while (var_s2 < arg4);
    }
    }

f32 func_808023B0_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 result;
    s32 i;
    u8 *data;

    data = func_80100094(arg0, 0);
    result = 1.4f;
    for (i = 0; i < 12; i++) {
        if (data[0x487 + i] == 2) {
            result *= 0.85f;
        }
    }
    return result;
}

/* extern */

void func_80802450_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    void func_80102FDC(Actor *, f32);
    f32 func_808023B0_chinflatableboss(Actor *);
    Actor *sp1C;
    f32 sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = sp1C->rotation[0] - func_808023B0_chinflatableboss(arg0);
    func_80102FDC(arg0, sp1C->rotation[0] - (func_80101F24(arg0) * sp18));
}

void func_808024BC_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 unk0[0x40];
        f32 duration;
        u8 unk44[0x453];
        u8 unk497;
    } BossData;
    void *func_80100094(Actor *, u32);
    void func_80101CDC(Actor *, f32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    extern s16 D_80802D80_chinflatableboss[];
    BossData *sp24;
    f32 duration;

    sp24 = func_80100094(arg0, 0);
    sp24->duration = D_80802D80_chinflatableboss[func_80801C7C_chinflatableboss(arg0)];
    *(f32 *)&arg0->actorData[3] = 0.0f;
    func_80800F84_chinflatableboss(arg0, sp24->unk497 != 0 ? 6 : 8);
    duration = ((f32)D_80802D80_chinflatableboss[0] / sp24->duration) * 5.0f;
    func_80101CDC(arg0, duration);
    func_8008B1C8(func_80104248(arg0), 0.8f);
}

s32 func_80802590_chinflatableboss(Actor *arg0, f32 *arg1, s32 arg2) {
    s32 func_800AE0B8(s32 *);
    s32 func_800B0D80(u8 *, s32, f32 *, f32 *, f32, s32, void *, f32 *, f32 *);
    u8 *func_800B2824(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u8 *func_801039E4(Unk80132ED0 *);
    void *func_801040A8(Actor *);
    f32 sp4C[3];
    f32 sp48;
    u8 *sp44;

    if (func_800AE0B8(func_801040A8(arg0)) == 0) {
        func_800EE7F8(arg1, arg0->position);
        return 0;
    }
    sp44 = func_801039E4(arg0->unk0);
    func_800EFA4C(sp4C, 0.0f, arg0->rotation[1], 0.0f);
    if (func_800B0D80(func_800B2824(sp44), arg2, arg0->position, sp4C, arg0->scale, 0, func_801040A8(arg0), arg1, &sp48) == 0) {
        func_800EE7F8(arg1, arg0->position);
        return 0;
    }
    return (s32)sp48;
}

/* extern */

void func_8080267C_chinflatableboss(Actor *arg0) {
    struct Marker { u8 pad0[0x10]; s16 animIndex; };
    void *func_8008AEDC(void *);
    void func_8008B304(s32);
    void func_8008C200(s16, s32, s32);
    s32 *func_8008C27C(void *);
    u8 *func_800B27E0(u8 *);
    void func_800DFBE0(s32 *, s32, f32 *);
    u8 *func_801039E4(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    f64 pad;
    struct anctrl_s *sp34;
    f32 sp28[3];
    u8 *sp24;

    sp34 = func_80104248(arg0);
    if (arg0->unk64_16) {
        sp24 = func_801039E4(arg0->unk0);
        sp24 = func_800B27E0(sp24);
        func_8008B304(sp34);
        func_8008C200(((struct Marker *)arg0->unk0)->animIndex, sp24, func_8008AEDC(sp34));
        sp24 = func_8008AEDC(sp34);
        func_800DFBE0(func_8008C27C(sp24), 3, sp28);
        ((f32 *)arg0->actorData)[4] = sp28[0] * arg0->scale;
        arg0->unk64_20 = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/inflatableboss/func_8080272C_chinflatableboss.s")

void func_80802910_chinflatableboss(Actor *arg0) {
    s32 _gcfrontend_entrypoint_9(s32);
    void func_800A51C0(void);
    void func_800DA544(s32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80109FE8(Actor *, s32);
    void func_8010A590(Actor *);
    void func_808024BC_chinflatableboss(Actor *);
    void func_80802A9C_chinflatableboss(Actor *);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_800FDC28(4);
    func_80802A9C_chinflatableboss(arg0);
    func_800A51C0();
    func_808024BC_chinflatableboss(arg0);
    func_800DA544(1);
    func_800DA544(0x17F);
    _gcfrontend_entrypoint_9(0x25);
    func_800F82D4(func_800F54E4(), 0);
    sp24[0x498] = 6;
    func_8010A590(arg0);
    func_80109FE8(arg0, 1);
}

/* extern */

void func_808029AC_chinflatableboss(Actor *arg0) {
    s32 func_800D2498(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80801CB4_chinflatableboss(Actor *);
    if ((func_800DA298(1) != 0) && (func_800DA298(3) == 0)) {
        func_800D2498(0xEC, func_80801CB4_chinflatableboss(arg0), 0);
    }
}

void func_80802A00_chinflatableboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802A2C_chinflatableboss(arg0, arg0->unk0, arg1, arg2);
}

void func_80802A2C_chinflatableboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    void _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x49D))) != 0) {
        arg3 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg1, arg0->unk0, arg2, arg3);
    (*(s8 *)((s8 *)(sp1C) + (0x49D))) = 1;
}

void func_80802A9C_chinflatableboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x49D))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x49D))) = 0;
    }
}

void func_80802AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_v1_2;

    temp_v0 = func_80100094(arg0, 0U);
    temp_v1 = temp_v0 + arg1;
    (*(s8 *)((s8 *)(temp_v1) + (0x487))) = (s8) arg2;
    if (arg1 >= 9) {
        arg1 = arg1 + arg1;
        arg1 -= 9;
        temp_v1_2 = temp_v0 + arg1;
        (*(s8 *)((s8 *)(temp_v1_2) + (0x478))) = (s8) arg2;
        (*(s8 *)((s8 *)(temp_v1_2) + (0x479))) = (s8) arg2;
    } else {
        (*(s8 *)((s8 *)(temp_v1) + (0x478))) = (s8) arg2;
    }
}
