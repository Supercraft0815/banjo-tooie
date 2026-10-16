#include "core2/1ED8C80.h"

void func_800FF390(void) {
    s32 func_80104170();
    s32 func_80104350();
    s32 func_80105410();
    s32 func_80105C20();
    s32 func_801065E0();
    s32 func_80106A20();
    s32 func_80106DF0();
    s32 func_80107BB0();
    extern s32 D_80135A50;
    D_80135A50 = 0;
    func_801065E0();
    func_80104170();
    func_80104350();
    func_80105410();
    func_80105C20();
    func_80106A20();
    func_80106DF0();
    func_80107BB0();
}

void func_800FF3EC(Actor *arg0) {
    typedef struct {
        u32 pad0[10];
        s32 (*unk28)(Actor *);
    } ActorCallbacks;
    void *func_80100368(void *);
    ActorCallbacks *callbacks;

    if (!arg0->unk64_26) {
        callbacks = func_80100368(arg0);
        if (callbacks->unk28 != NULL) {
            callbacks->unk28(arg0);
        }
        arg0->unk64_26 = 1;
    }
}

/* extern */

void func_800FF44C(void) {
    void func_800FF3EC(Actor *);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 sp24;
    s32 var_a0;

    func_80101238(0x93, 0);
    if ((var_a0 = func_801067C4(&sp24)) != 0) {
        do {
            func_800FF3EC((Actor *)var_a0);
        } while ((var_a0 = func_8010682C(&sp24)) != 0);
    }
}

/* extern */

void func_800FF4A4(Actor *arg0) {
    typedef struct {
        u32 pad0[9];
        u32 pad24_14 : 18;
        u32 player : 1;
        u32 pad24_9 : 4;
        u32 target : 3;
        u32 pad24_0 : 6;
    } PathState;
    void _subaddieaudioloop_entrypoint_2(Actor *);
    void func_800D8808(s32);
    void func_8010381C(Actor *);
    void func_80103938(void *);
    void func_80104328(s32);
    void func_80104504(void *);
    void *func_80105494(Actor *);
    void func_80105634(Actor *);
    void func_80106EE0(void *);
    Unk80132ED0 *temp_s0;
    u32 var_s0;

    temp_s0 = arg0->unk0;
    func_8010381C(arg0);
    func_80103938(arg0);
    if (arg0->unk7C_0) {
        PathState *state = func_80105494(arg0);
        func_800D8808(state->target);
        func_80105634(arg0);
    }
    *(u16 *)&temp_s0->unk24 &= 0x3F;
    func_80104328((s32)arg0);
    _subaddieaudioloop_entrypoint_2(arg0);
    func_80104504(arg0);
    func_80106EE0(arg0);
    var_s0 = 0;
    do {
        func_80100074(arg0, var_s0, 0U);
        var_s0 += 1;
    } while (var_s0 != 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF564.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FF62C.s")

/* extern */

void func_800FFA3C(Actor *arg0) {
    void func_800EBFF4(void *arg0);
    void func_800FF3EC(Actor *);
    void func_800FF4A4(Actor *);
    s32 func_801066C0(u32);
    Unk80132ED0 *sp1C = arg0->unk0;
    func_800FF3EC(arg0);
    func_800FF4A4(arg0);
    func_801066C0((u32) (*(u16 *)((s8 *)(sp1C) + (0x1A))) >> 5);
    func_800EBFF4(sp1C);
}

void func_800FFA88(Unk80132ED0* a0)
{
    func_800FFAB0(func_80106790(a0));
}

void func_800FFAB0(Actor *arg0) {
    extern s32 D_80135A50;
    Actor *temp_v0;
    s32 temp_a2;
    struct ActorFlags {
        u8 prefix[0x74];
        u32 pad74_25 : 7;
        u32 flag74_24 : 1;
        u32 pad74_0 : 24;
        u32 pad78_3 : 29;
        u32 flag78_2 : 1;
        u32 pad78_0 : 2;
    } *flags = (void *)arg0;

    arg0->unk64_17 = 1;
    D_80135A50 += 1;
    temp_a2 = arg0->pad40;
    if ((temp_a2 != 0) && (arg0->unk6C_9 != 0x243)) {
        temp_v0 = func_80106790((Unk80132ED0 *) temp_a2);
        temp_v0->unk64_17 = 1;
        arg0->pad40 = 0;
        temp_v0->pad40 = 0;
        D_80135A50 += 1;
    }
    flags->flag78_2 = 0;
    flags->flag74_24 = flags->flag78_2;
}

void func_800FFB74(void) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    extern s32 D_80135A50;
    Actor *actor;
    s32 sp20;

    if (D_80135A50 > 0) {
        if ((actor = (Actor *)func_801067C4(&sp20)) != NULL) {
            do {
                if (actor->unk64_17) {
                    func_800FFA3C(actor);
                }
            } while ((actor = (Actor *)func_8010682C(&sp20)) != NULL);
        }
        D_80135A50 = 0;
    }
}

void func_800FFBE4(void) {
}

void func_800FFC3C(void);

void func_800FFBEC()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC14()
{
    func_800FFC3C();
    func_8010DEFC();
}

void func_800FFC3C(void) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 var_s0;
    s32 sp20[1];

    if ((var_s0 = func_801067C4(sp20)) != 0) {
        do {
            *(u8 *)((s8 *)var_s0 + 0x7E) &= 0xFFEF;
        } while ((var_s0 = func_8010682C(sp20)) != 0);
    }
}

/* extern */

void func_800FFC90(void) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    struct ActorFlags {
        u8 pad0[0x70];
        u8 pad70 : 7;
        u8 active : 1;
        u8 toggle : 1;
        u8 pad71 : 7;
        u8 pad72[10];
        u32 pad7C : 19;
        u32 unk7C_12 : 1;
        u32 pad7C_0 : 12;
    } *var_v0;
    s32 sp20;

    var_v0 = (struct ActorFlags *)func_801067C4(&sp20);
    if (var_v0 != NULL) {
        do {
            if (var_v0->unk7C_12 && var_v0->active) {
                var_v0->toggle ^= 1;
            }
            var_v0 = (struct ActorFlags *)func_8010682C(&sp20);
        } while (var_v0 != NULL);
    }
}

void func_800FFD10(s32 arg0) {
    void func_8010381C(Actor *);
    s32 func_80103AC0(Actor *);
    s32 func_80106730(void);
    Actor *func_801068A8(s32 *);
    Actor *func_80106920(s32 *);
    extern s32 D_80124390;
    struct ActorFlags {
        u8 pad0[0x70];
        u32 pad70 : 28;
        u32 active : 1;
        u32 pad70_0 : 3;
    };
    s32 var_s1;
    Actor *var_s0;
    Actor *var_v0;

    if (arg0 == 1) {
        var_s1 = 0xA;
    } else {
        var_s1 = func_80106730();
    }
    var_v0 = func_801068A8(&D_80124390);
    var_s0 = var_v0;
    if ((var_v0 != NULL) && (var_s1 > 0)) {
loop_5:
        if (((struct ActorFlags *)var_v0)->active && (func_80103AC0(var_s0) == 0)) {
            func_8010381C(var_s0);
        }
        var_v0 = func_80106920(&D_80124390);
        var_s0 = var_v0;
        var_s1 -= 1;
        if ((var_v0 != NULL) && (var_s1 > 0)) {
            goto loop_5;
        }
    }
}

/* extern */

void func_800FFDBC(void) {
    void func_8010381C(Actor *);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    Actor *var_a0;
    s32 sp20;

    if ((var_a0 = func_801067C4(&sp20)) != 0) {
        do {
            func_8010381C(var_a0);
        } while ((var_a0 = func_8010682C(&sp20)) != 0);
    }
}

void func_800FFE08(void) {
    s32 func_800DC060(s32);
    void func_801041C8(void);
    void func_801043A0(void);
    void func_8010545C(void);
    void func_80105CD0(void);
    void func_80106630(void);
    Actor *func_801068A8(s32 *);
    Actor *func_80106920(s32 *);
    void func_80106A60(void);
    void func_80106E50(void);
    void func_80107C10(void);
    extern s32 D_80124394;
    s32 temp_a0;
    s32 var_s1;
    Actor *var_v0;
    Unk80132ED0 *temp_s0;

    var_s1 = 0;
    var_v0 = func_801068A8(&D_80124394);
    if (var_v0 != NULL) {
loop_1:
        temp_s0 = var_v0->unk0;
        temp_a0 = (s32)temp_s0->unk4;
        if (temp_a0 != 0) {
            temp_s0->unk4 = (u32 *)func_800DC060(temp_a0);
        }
        var_v0 = func_80106920(&D_80124394);
        var_s1 += 1;
        if ((var_v0 != NULL) && (var_s1 != 8)) {
            goto loop_1;
        }
    }
    func_80106630();
    func_801041C8();
    func_801043A0();
    func_8010545C();
    func_80105CD0();
    func_80106A60();
    func_80106E50();
    func_80107C10();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED8C80/func_800FFECC.s")

u32* func_80100074(Actor* a0, u32 a1, u32 a2)
{
    return func_800FFECC(a0,a1,a2);
}

void *func_80100094(Actor *arg0, u32 arg1) {
    s32 func_8001B798(s16);
    s16 temp;
    s32 result;
    temp = *(s16 *)((u8 *)arg0 + 0x82 + arg1 * 2);
    result = 0;
    if (temp != 0) {
        return (void *) func_8001B798(temp);
    }
    return (void *) result;
}

s32 func_801000D8(Actor *arg0, s32 arg1, s32 arg2) {
    if (func_80100094(arg0, (u32) arg1) == NULL) {
        func_80100074(arg0, (u32) arg1, (u32) arg2);
    }
    return func_80100094(arg0, (u32) arg1);
}

void func_80100120(Actor *arg0) {
    typedef struct {
        u32 padding[13];
        void (*update)(Actor *);
    } ActorCallbacks;
    typedef struct {
        u8 padding[0x70];
        u32 pad70 : 28;
        u32 flag70 : 1;
        u32 pad70_0 : 3;
        u32 pad74 : 10;
        u32 flag74 : 1;
        u32 pad74_0 : 21;
        u32 pad78;
        u32 pad7C : 16;
        u32 initialized : 1;
        u32 enabled : 1;
        u32 pad7C_0 : 14;
    } ActorFlags;
    void *func_80100368(void *);
    s32 func_80102F74(Unk80132ED0 *, s32);
    void func_8010381C(Actor *);
    register void (*update)(Actor *);

    if (!((ActorFlags *)arg0)->flag74) {
        update = ((ActorCallbacks *)func_80100368(arg0))->update;
        if (update != NULL) {
            if (((ActorFlags *)arg0)->flag70) {
                if (func_80102F74(arg0, 0x80080000) != 0) {
                    func_8010381C(arg0);
                }
            }
            update(arg0);
            if (arg0->unk64_17) {
                ((ActorFlags *)arg0)->initialized = 1;
                ((ActorFlags *)arg0)->enabled = 0;
            }
        }
        ((ActorFlags *)arg0)->flag74 = 1;
    }
}

/* extern */

void func_801001D8(void) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 func_8010D1E8(void);
    s32 sp24;
    Actor *var_a0;

    func_8010D1E8();
    if ((var_a0 = func_801067C4(&sp24)) != NULL) {
        do {
            func_80100120(var_a0);
        } while ((var_a0 = func_8010682C(&sp24)) != NULL);
    }
    func_800FFB74();
}

int func_80100230(Actor *arg0, f32 *arg1) {
    f32 func_800EEB40(f32 *, f32 *);
    struct {
        u8 padding[0x7C];
        u32 radius : 16;
        u32 pad7E_15 : 1;
        u32 enabled : 1;
        u32 pad7E_0 : 14;
    } *range;
    void *data;
    f32 distance;

    data = arg0;
    range = data;
    if (!range->enabled) {
        return 0;
    }
    if (range->radius == 0) {
        return 1;
    }
    distance = func_800EEB40(arg1, arg0->position);
    return (f32)(s32)(range->radius * range->radius) < distance;
}

/* extern */

void func_801002C0(void) {
    s32 _suautobaddies_entrypoint_1();
    void func_800819B4(void *);
    s32 func_80081D34(s32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    s32 sp3C;
    Actor *var_s0;
    f32 sp2C[3];

    func_801001D8();
    _suautobaddies_entrypoint_1();
    func_800FFB74();
    func_800F5A00(func_800F54E4(), sp2C);
    if ((var_s0 = func_801067C4(&sp3C)) != NULL) {
        do {
            if ((func_80100230(var_s0, sp2C) != 0) && (func_80081D34(var_s0->pointerToSyscallEntry) != 0)) {
                func_800819B4(var_s0->pointerToSyscallEntry);
            }
        } while ((var_s0 = func_8010682C(&sp3C)) != NULL);
    }
}

void *func_80100368(void *arg0) {
    return (*(void *(**)())((s8 *)(arg0) + (0x10)))();
}

s32 func_8010038C(Actor *arg0, f32 *arg1) {
    s32 func_80081D34(s32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    s32 func_8010108C();
    struct {
        u8 padding[0x7C];
        u32 radius : 16;
        u32 initialized : 1;
        u32 enabled : 1;
        u32 flag13 : 1;
        u32 flag12 : 1;
        u32 padding0 : 12;
    } *range;
    void *data;

    data = arg0;
    range = data;
    if (!range->initialized) {
        range->initialized = 1;
        func_8010108C(arg0, 0x95, 0);
        if (arg0->unk64_17) {
            return 0;
        }
        if (arg0->unk7A_5) {
            func_80081D34(arg0->pointerToSyscallEntry);
        }
    }
    if (!range->enabled) {
        return 0;
    }
    if (range->radius == 0) {
        return 1;
    }
    if (range->flag13 && range->flag12) {
        return 1;
    }
    return func_800EFFB4(arg0->position, (f32)(s32)range->radius, arg1);
}
