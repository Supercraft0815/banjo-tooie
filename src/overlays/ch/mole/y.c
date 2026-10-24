#include "common.h"

void func_80800274_chmoley(Actor *);
void func_80105834(Actor *);
void func_808000AC_chmoley(Actor *, void *);
void func_8080088C_chmoley(Actor *);
void func_808008C0_chmoley(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80800000_chmoley(Actor *, s32, s32);
extern u32 D_80800B60_chmoley[];

u32 D_80800C10_chmoley[] = {
    0x00B7018F, 0x07D60001, (u32)D_80800B60_chmoley, (u32)func_80800274_chmoley,
    (u32)func_80105834, (u32)func_808000AC_chmoley, 0x09C40000, 0x00000000,
    0x00000000, 0x0000014C, (u32)func_8080088C_chmoley, 0x00000000,
    0x00000000, (u32)func_808008C0_chmoley, (u32)func_80107C2C, 0x80002002,
    (u32)func_80800000_chmoley, 0x00000000, 0x00000000, 0x00000000,
};

struct anctrl_s;

s32 func_80800000_chmoley(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 _chmolehill_entrypoint_5(Actor *);
    s32 func_8010114C(s32, s32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    extern s32 D_80800BD0_chmoley;
    int result;

    if (arg0->unk64_17) {
        return 0;
    }
    switch (arg1) {
    case 0x2E:
    case 0x2F:
    case 0x30:
        return func_8010114C(_chmolehill_entrypoint_5(func_80106790(arg0->unk3C)), arg1, arg2);
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800BD0_chmoley, 1.0f);
        result = 1;
        break;
    default:
        return 0;
    }
    return result;
}

/* extern */

void func_808000AC_chmoley(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    if (arg0->unk64_20) {
        func_800DF744(3, 1);
        func_800DF744(5, 0);
    } else {
        func_800DF744(3, 0);
        func_800DF744(5, 1);
    }
    if (arg0->unk64_19) {
        func_800DF744(4, 1);
        func_800DF744(6, 0);
        func_800DF744(7, 1);
    } else {
        func_800DF744(4, 0);
        func_800DF744(6, 1);
        func_800DF744(7, 0);
    }
    func_800DF744(8, 0);
    func_80101870(arg0, arg1);
}

/* extern */

s32 func_80800190_chmoley(Actor *arg0) {
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    struct anctrl_s *func_80104248(void *);

    if (func_80104248(arg0) == 0) {
        return 1;
    }
    switch (func_801022E4(arg0)) {
    case 0x2BC:
    case 0x2C8:
        return 1;
    case 0x2BF:
        if (func_80101E14(arg0, 0.0909f) != 0) {
            arg0->unk64_19 = 1;
        } else if (func_80101E14(arg0, 0.8295f) != 0) {
            arg0->unk64_19 = 0;
        }
        if (func_80101DDC(arg0)) {
            return 1;
        }
        break;
    default:
        if (func_80101E14(arg0, 0.999f)) {
            return 1;
        }
        break;
    }
    return 0;
}

void func_80800274_chmoley(Actor *arg0) {
    struct Fields {
        Unk80132ED0 *marker;
        f32 position[3];
        u8 pad10[0x2C];
        Unk80132ED0 *hill;
        u8 pad40[0x25];
        u8 pad65 : 3;
        u8 flag10 : 1;
        u8 flag8 : 1;
        u8 rest65 : 3;
        u8 pad66[0xC];
        u16 state : 6;
        u16 rest72 : 10;
        u8 pad74[5];
        u8 upper : 4;
        u8 lower : 4;
    };
    struct Times { f32 values[4]; };
    void _chmolehill_entrypoint_1(Actor *, s32);
    void _chmolehill_entrypoint_2(Actor *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddieaudioquick_entrypoint_2(Actor *, f32 *, u32 *);
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _suexpression_entrypoint_10(s32, s32, s32);
    s32 func_800DC298(f32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    struct anctrl_s *func_80104248(void *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800190_chmoley(Actor *);
    extern u32 D_80800A90_chmoley[], D_80800AA8_chmoley[];
    extern u32 D_80800AC0_chmoley[], D_80800AD8_chmoley[];
    extern u32 D_80800AF0_chmoley[], D_80800B08_chmoley[];
    extern u32 D_80800B20_chmoley[], D_80800B38_chmoley[];
    extern u32 D_80800B4C_chmoley[];
    extern struct Times D_80800BE0_chmoley, D_80800BF0_chmoley, D_80800C00_chmoley;

    _suexpression_entrypoint_10((s32)func_80100094(arg0, 1), (s32)((struct Fields *)arg0)->marker, 0);
    switch (((struct Fields *)arg0)->upper) {
        case 0:
        case 1:
        case 3:
        case 4:
            break;
        case 2:
            if (func_80800190_chmoley(arg0)) {
                _chmolehill_entrypoint_1((Actor *)&((struct Fields *)arg0)->marker, 0);
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 6);
            }
            break;
        case 5:
            if (func_80800190_chmoley(arg0)) {
                _chmolehill_entrypoint_1((Actor *)&((struct Fields *)arg0)->marker, 0);
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 5);
            }
            break;
        case 6:
            if (func_80800190_chmoley(arg0)) {
                _chmolehill_entrypoint_1((Actor *)&((struct Fields *)arg0)->marker, 0);
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 10);
            }
            break;
    }
    switch (((struct Fields *)arg0)->state) {
        case 2:
            if (func_80101E14(arg0, 0.583f)) {
                ((struct Fields *)arg0)->flag10 = 1;
            } else if (func_80101E14(arg0, 0.931f)) {
                ((struct Fields *)arg0)->flag10 = 0;
            }
            if (func_80101DDC(arg0)) {
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 10);
            }
            break;
        case 7:
            if (func_80101DDC(arg0)) {
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 9);
            }
            break;
        case 8:
            if (func_80101DDC(arg0)) {
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 1);
            }
            break;
        case 6:
            if (func_80101E14(arg0, 0.0f)) {
                _subaddiedialog_entrypoint_11(((struct Fields *)arg0)->marker, 0xDBD, 4, ((struct Fields *)arg0)->position, 0x6F);
            } else if (func_80101DDC(arg0)) {
                if (func_800DC298(0.09999084473f)) {
                    _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 11);
                } else {
                    _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 3);
                }
            }
            break;
        case 3:
            if (func_80101DDC(arg0)) {
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 1);
            }
            break;
        case 11:
            if (func_80101E14(arg0, 0.0921f)) {
                ((struct Fields *)arg0)->flag10 = 1;
            } else if (func_80101DDC(arg0)) {
                ((struct Fields *)arg0)->flag10 = 0;
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 1);
            }
            break;
        case 10:
            if (func_80101E14(arg0, 0.999f) && func_800DC298(0.25f)) {
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 4);
            }
            break;
        case 4:
            if (func_80101E14(arg0, 0.0909f)) {
                ((struct Fields *)arg0)->flag8 = 1;
            } else if (func_80101E14(arg0, 0.8295f)) {
                ((struct Fields *)arg0)->flag8 = 0;
            } else if (func_80101E14(arg0, 0.999f)) {
                _chmolehill_entrypoint_2(func_80106790(((struct Fields *)arg0)->hill), 10);
            }
            break;
    }
    if (func_80104248(arg0)) {
        switch ((u32)func_801022E4(arg0) - 0x2BB) {
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
                break;
            case 14: {
                register f32 time = func_80101F24(arg0);
                if (time >= 0.6f && time <= 0.7f) {
                    _subaddieaudioloop_entrypoint_4(arg0, ((struct Fields *)arg0)->position, 1, D_80800B4C_chmoley);
                }
                _subaddieaudioquick_entrypoint_3(arg0, ((struct Fields *)arg0)->position, D_80800A90_chmoley, 0.16f);
                _subaddieaudioquick_entrypoint_3(arg0, ((struct Fields *)arg0)->position, D_80800AA8_chmoley, 0.3f);
                break;
            }
            case 13: {
                struct Times sp54 = D_80800BE0_chmoley;
                struct Times sp44 = D_80800BF0_chmoley;
                struct Times sp34 = D_80800C00_chmoley;
                if (func_80101E4C(arg0, sp54.values)) {
                    _subaddieaudioquick_entrypoint_2(arg0, ((struct Fields *)arg0)->position, D_80800AC0_chmoley);
                } else if (func_80101E4C(arg0, sp44.values)) {
                    _subaddieaudioquick_entrypoint_2(arg0, ((struct Fields *)arg0)->position, D_80800AD8_chmoley);
                } else if (func_80101E4C(arg0, sp34.values)) {
                    _subaddieaudioquick_entrypoint_2(arg0, ((struct Fields *)arg0)->position, D_80800AF0_chmoley);
                }
                break;
            }
            case 1:
                if (func_80101E14(arg0, 0.24f)) {
                    _subaddieaudioquick_entrypoint_2(arg0, ((struct Fields *)arg0)->position, D_80800B08_chmoley);
                }
                if (func_80101E14(arg0, 0.74f)) {
                    _subaddieaudioquick_entrypoint_2(arg0, ((struct Fields *)arg0)->position, D_80800B20_chmoley);
                }
                break;
            case 0:
                if (func_80101E14(arg0, 0.26f)) {
                    _subaddieaudioquick_entrypoint_2(arg0, ((struct Fields *)arg0)->position, D_80800B38_chmoley);
                }
                break;
        }
    }
}

void func_8080088C_chmoley(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808008C0_chmoley(Actor *arg0) { void _suexpression_entrypoint_12(void *, f32, f32); f32 zero = 0.0f; arg0->scale = 0.5f; _suexpression_entrypoint_7(arg0, 1, 0x6F); _suexpression_entrypoint_12(func_80100094(arg0, 1), zero, zero); }

void chmoley_entrypoint_0(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad[0x79];
        u8 upper : 4;
        u8 lower : 4;
    };
    ((struct Fields *)arg0)->upper = arg1;
}

/* extern */

void chmoley_entrypoint_1(Actor *arg0, s32 arg1) {
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_80102424(Actor *, s32);

    if (arg1 != arg0->unk70_10) {
        if (arg0->unk70_10 == 5) {
            func_800FCAE0(0x3A, 0, 0x7D0);
            func_800FCA90(0x3A);
        }
        func_80102424(arg0, arg1);
        if (arg0->unk70_10 != 1) {
            if (arg0->unk70_10 != 5) {
                arg0->unk64_16 = 1;
                return;
            }
            func_800FCAE0(0x3A, -1, 0x7D0);
            return;
        }
        arg0->unk64_16 = 0;
    }
}

OSThread *chmoley_entrypoint_2(void)
{


    return (OSThread *) D_80800C10_chmoley;
}
