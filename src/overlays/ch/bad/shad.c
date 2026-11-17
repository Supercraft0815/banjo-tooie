#include "common.h"

OSThread *chbadshad_entrypoint_0(void)
{
    extern ActorData D_80800A10_chbadshad[];

    return (OSThread *) D_80800A10_chbadshad;
}

typedef union {
    Actor actor;
    struct {
        u8 reserved[0x7A];
        u8 shadowState : 2;
        u8 otherFlags : 6;
    } shadow;
} ShadActor;

void func_8080000C_chbadshad(ShadActor *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80102F74(Unk80132ED0 *, s32);
    void func_8010A800(Actor *, s32);
    Unk80132ED0 *marker;
    void *parent;

    func_8010A800(&arg0->actor, 5);
    marker = arg0->actor.pad40;
    if (marker != NULL) {
        parent = func_80106790(marker);
    } else {
        parent = NULL;
    }
    if (parent != NULL) {
        if (func_80102F74(parent, 0x82000000)) {
            arg0->shadow.shadowState = 3;
        } else {
            arg0->shadow.shadowState = 2;
        }
    }
}

void func_8080082C_chbadshad(Actor *arg0);
s32 func_8001211C(void);

void func_80800090_chbadshad(Actor *arg0) { if (!arg0->unk64_17 && (s32) arg0->actorData[0] < func_8001211C() - 1) func_8080082C_chbadshad(arg0); }

void func_808000E0_chbadshad(Actor *arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF410(s32);
    f32 func_800DF428(f32);
    void func_800DF470(s32);
    void func_800DF830(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 *func_80101918(f32);
    u8 *func_801039E4(Unk80132ED0 *);
    Actor *func_80106790(Unk80132ED0 *);
    typedef union {
        Actor actor;
        struct {
            u8 reserved74[0x74];
            u32 flags74 : 5;
            u32 halfScale : 1;
            u32 other74 : 26;
            u16 reserved78;
            u16 state : 2;
            u16 other7A : 14;
        } shadow;
    } ShadowRenderActor;
    f32 scale[1];
    Actor *parent;
    Unk80132ED0 *marker;
    s32 pad30;
    f32 *transform;
    s32 pad28;

    parent = NULL;
    if (!arg0->unk64_17) {
        scale[0] = arg0->scale;
        marker = arg0->pad40;
        if (marker != NULL) {
            parent = func_80106790(marker);
        }
        if (parent != NULL) {
            func_800DF410(_subaddiefade_entrypoint_0(parent));
        }
        if (parent == NULL || !((ShadowRenderActor *)parent)->shadow.halfScale) {
            scale[0] *= func_800F10B4(*(f32 *)&arg0->actorData[3], 0.0f, 800.0f, 0.53f, 0.18f);
        } else {
            scale[0] *= 0.5f;
        }
        func_800DF470(1);
        func_800DF428(4000.0f);
        func_800DF830(((ShadowRenderActor *)arg0)->shadow.state);
        if (((ShadowRenderActor *)arg0)->shadow.state == 3) {
            if (func_800DE448(arg0->position, arg0->rotation, scale[0], NULL, func_801039E4(arg0->unk0))) {
                arg0->unk7C_12 = 1;
            } else {
                arg0->unk7C_12 = 0;
            }
        } else {
            transform = func_80101918(scale[0]);
            if (func_800DE448(arg0->position, arg0->rotation, scale[0], transform, func_801039E4(arg0->unk0))) {
                arg0->unk7C_12 = 1;
            } else {
                arg0->unk7C_12 = 0;
            }
        }
    }
}

f32 func_8080028C_chbadshad(Actor *arg0, Actor *arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    void func_8010279C(void *, void *);
    s32 func_80104668(BtIntPtr, f32 *, f32 *, f32 *, f32 *);
    s32 func_8010518C(BtIntPtr);
    void *func_80105494(Actor *);
    s32 func_8080086C_chbadshad();
    struct MovementFlags {
    u8 reserved[0x70];
    u32 upper : 12;
    u32 direct : 1;
    u32 lower : 19;
    u32 reserved74;
    u32 upper78 : 28;
    u32 changed : 1;
    u32 lower78 : 3;
    };
    struct PositionFlags {
    u32 upper : 28;
    u32 changed : 1;
    u32 lower : 3;
    s16 reserved7C;
    s16 floor : 1;
    u16 rest : 15;
    };
    struct SurfaceFlags {
    u32 hidden : 1;
    u32 other : 31;
    };
    f32 sp34[3];
    f32 sp30;
    f32 temp_f0;
    sp30 = 0.0f;
    if (!((struct PositionFlags *)&arg0->unk78)->changed && !(arg1->actorData[1] & 0x80008000) && ((struct PositionFlags *)&arg1->unk78)->floor != 0 && (s32)arg1->position[0] == (s32)arg2[0] && (s32)arg1->position[2] == (s32)arg2[2]) {
    arg1->position[0] = arg2[0];
    arg1->position[2] = arg2[2];
    goto done;
    }
    if (((struct MovementFlags *)arg0)->direct) {
    func_800EE7F8(arg1->position, arg2);
    return 0.0f;
    }
    if (((s16 *)&arg0->pad8C)[1] != 0 && func_80105494(arg0) == NULL && func_80104668(arg0, arg2, arg1->position, sp34, &sp30) != 0) {
    arg1->actorData[1] = func_8010518C(arg0);
    func_8010279C(arg1, sp34);
    if ((arg1->actorData[1] & 0x80000000)) {
    arg1->unk64_16 = 0;
    }
    else {
    arg1->unk64_16 = 1;
    }
    return sp30;
    }
    else if (func_8080086C_chbadshad(arg1, arg0, &sp30, arg2) == 0) {
    arg1->unk64_16 = 0;
    }
    else if ((arg1->actorData[1] & 0x80000000)) {
    arg1->unk64_16 = 0;
    }
    else {
    arg1->unk64_16 = 1;
    }
    done: return sp30;
    }



/* extern */

void chbadshad_entrypoint_1(void *arg0, void *arg1, f32 arg2) {
    Actor *func_80800664_chbadshad(void *, void *, f32);
    Actor *temp_v0;

    temp_v0 = func_80800664_chbadshad(arg0, arg1, arg2);
    if (temp_v0 != NULL) {
        temp_v0->scale = arg2;
    }
}

s32 chbadshad_entrypoint_2(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3) { s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *); void func_800EE7F8(f32 *, f32 *); Actor *func_80106790(Unk80132ED0 *); f32 sp2C[3]; f32 *var_s0; Unk80132ED0 *marker;  var_s0 = arg3; if (arg3 == NULL) { var_s0 = sp2C; } if (_subaddieskeleton_entrypoint_0(arg0, arg1, var_s0) != 0) { chbadshad_entrypoint_1(arg0, var_s0, arg2); marker = arg0->pad40; if (marker != NULL) { func_800EE7F8(var_s0, func_80106790(marker)->position); } return 1; } return 0; }

/* extern */

void chbadshad_entrypoint_3(Actor *arg0, void *arg1, s32 arg2, f32 arg3, s16 *arg4) {
    s32 chbadshad_entrypoint_2(Actor *, s32, f32, f32 *);

    while (*arg4 != -1) {
        if (arg0->unk70_10 == *arg4) {
            chbadshad_entrypoint_2(arg0, arg2, arg3, 0);
            return;
        }
        arg4++;
    }
    chbadshad_entrypoint_1(arg0, arg1, arg3);
}

struct ShadowSource { Unk80132ED0 *marker; };
void chbadshad_entrypoint_4(struct ShadowSource arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_801084B0(BtIntPtr, Actor **);
    f32 func_8080028C_chbadshad(Actor *, Actor *, f32 *);
    struct ShadowData {
        s32 frame;
        f32 reserved[2];
        f32 height;
    };
    f32 sp2C[3];
    Unk80132ED0 *volatile sp28;
    Actor *sp24;
    volatile f32 sp20;
    Actor *sp1C;

    sp28 = arg0.marker;
    sp24 = func_80106790(arg0.marker);
    sp2C[0] = arg2;
    sp2C[1] = arg3;
    sp2C[2] = arg4;
    if (!sp24->unk64_17) {
        sp20 = arg1;
        sp1C = func_801084B0(0x243, &sp24);
        if (sp1C != NULL) {
            sp1C->unk14 = sp24->unk14;
            ((struct ShadowData *)sp1C->actorData)->height = func_8080028C_chbadshad(sp24, sp1C, sp2C);
            if (!sp1C->unk64_17) {
                sp24->pad40 = (BtIntPtr)sp1C->unk0;
                sp1C->scale = sp20;
                sp1C->pad40 = (BtIntPtr)sp28;
                sp1C->actorData[0] = func_8001211C();
            }
        }
    }
}

Actor *func_80800664_chbadshad(void *arg0, void *arg1, f32 arg2) {
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
#ifndef BT_NATIVE
    extern s32 _chbadshad_entrypoint_4;
#endif
    Actor *func_80106790(Unk80132ED0 *);
    int func_8080078C_chbadshad(Actor *, BtIntPtr);
    void func_8080082C_chbadshad(Actor *);
    s32 func_8001211C(void);
    struct ShadowData {
        s32 frame;
        f32 reserved[2];
        f32 height;
    };
    Actor *shadow;

    if (((Actor *)arg0)->unk64_17) {
        Unk80132ED0 *marker = (Unk80132ED0 *)((Actor *)arg0)->pad40;
        if (marker != NULL) {
            func_8080082C_chbadshad(func_80106790(marker));

        }
        return NULL;
    }
    else if ((Unk80132ED0 *)((Actor *)arg0)->pad40 == NULL) {
        _chbaddiesetup_entrypoint_5(&_chbadshad_entrypoint_4,
            (BtIntPtr)((Actor *)arg0)->unk0, *(s32 *)&arg2, ((s32 *)arg1)[0],
            ((s32 *)arg1)[1], ((s32 *)arg1)[2]);
    }
    else {
    shadow = func_80106790((Unk80132ED0 *)((Actor *)arg0)->pad40);
    if (shadow->unk64_17) {
        return NULL;
    } else {
    if (func_8080078C_chbadshad(shadow, (BtIntPtr)arg0)) {
        ((struct ShadowData *)shadow->actorData)->height =
            func_8080028C_chbadshad(arg0, shadow, arg1);
    } else {
        shadow->position[0] = ((f32 *)arg1)[0];
        shadow->position[2] = ((f32 *)arg1)[2];
    }
    shadow->actorData[0] = func_8001211C();
    shadow->scale = arg2;
    return shadow;
    }
    }
    return NULL;
}

/* extern */

int func_8080078C_chbadshad(Actor *arg0, BtIntPtr arg1) {
    struct ShadowFlags {
        u8 unk78;
        u8 unk79;
        u16 unk7A_14 : 2;
        u16 unk7A_0 : 14;
        u16 unk7C;
        u16 unk7E_15 : 1;
        u16 unk7E_0 : 15;
    };
    struct ShadowMarkerBits {
        u16 unk18;
        u16 unk1A_5 : 11;
        u16 unk1A_0 : 5;
    };
    int func_800DB9B0();
    int func_80104544();
    if (!((struct ShadowFlags *)&arg0->unk78)->unk7E_15) {
        return 1;
    }
    if (func_80104544(arg1) != 0) {
        return 1;
    }
    if (func_800DB9B0() != 0) {
        return 1;
    }
    if (((struct ShadowFlags *)&arg0->unk78)->unk7A_14 == 3) {
        return 1;
    }
    return ((func_8001211C() ^ ((struct ShadowMarkerBits *)&arg0->unk0->unk18)->unk1A_5) & 3) == 0;
}

void func_8080082C_chbadshad(Actor *arg0) {
    void func_800FFAB0(Actor*);
    Actor* func_80106790(Unk80132ED0 *);
    Unk80132ED0 *temp_a1;

    temp_a1 = arg0->pad40;
    if (temp_a1 != NULL) {
        func_80106790(temp_a1)->pad40 = 0;
    }
    func_800FFAB0(arg0);
}

s32 func_8080086C_chbadshad(Actor *arg0, Actor *arg1, f32 *arg2, f32 *arg3) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F0E00(f32, f32);
    int func_800F1988(f32 *arg0, f32 *arg1, f32 *arg2);
    void func_8010279C(void *, void *);
    void func_801045AC(Actor *, f32 *, f32 *, s32);
    u32 func_8010A654(void ***, s32);
    typedef struct {
        s16 vertices[3];
        s16 unk6;
        s32 flags;
    } ShadowTriangle;
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    u32 sp2C;
    ShadowTriangle *sp28;

    sp2C = func_8010A654((void *)arg1, 0);
    func_800EE7F8(sp54, arg3);
    func_800EE7F8(sp48, arg3);
    sp54[1] += 80.0f;
    sp48[1] -= 100.0f;
    sp28 = func_800C6A7C(sp54, sp48, sp3C, arg0->unk14);
    if (sp28 == NULL) {
        sp48[1] = arg3[1] - 2000.0f;
        sp28 = func_800C6A7C(sp54, sp48, sp3C, arg0->unk14);
        if (sp28 == NULL) {
            *arg2 = 0.0f;
            func_8010A654((void *)arg1, sp2C);
            arg0->actorData[1] = 0;
            return 0;
        }
    }
    arg0->actorData[1] = sp28->flags;
    func_8010A654((void *)arg1, sp2C);
    func_800EE7F8(arg0->position, sp48);
    *arg2 = func_800F0E00(0.0f, arg3[1] - arg0->position[1]);
    func_800F1988(sp3C, &sp30[0], &sp30[1]);
    sp30[2] = 0.0f;
    func_8010279C(arg0, sp30);
    if (((s16 *)&arg1->pad8C)[1] != 0) {
        func_801045AC(arg1, sp3C, arg0->position, sp28->flags);
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/bad/shad.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800A10_chbadshad [1] BT_DATA(4, overlays_ch_bad_shad, 0x0) = { { 155, 579, 1591, 1, 0, (void (*)(struct Actor *))func_80800090_chbadshad, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808000E0_chbadshad, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chbadshad, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
