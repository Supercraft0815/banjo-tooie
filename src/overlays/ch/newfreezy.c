#include "common.h"

void func_80800000_chnewfreezy()
{
    _sufreezy_entrypoint_1();
}

/* extern */

void func_80800020_chnewfreezy(void **arg0) {
    s32 func_800ADFE0(s16);
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(*arg0) + (0x10)));
    if (temp_a1 != 0) {
        func_800ADFE0(temp_a1);
        (*(s16 *)((s8 *)(*arg0) + (0x10))) = 0;
    }
}

/* extern */

void func_80800068_chnewfreezy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u32 func_8010A828(Actor*, u32);
    Actor *_subaddielink_entrypoint_4(u8 *);
    func_8010A828(_subaddielink_entrypoint_4(func_80100094(arg0, 1U)), (u32) (*(u8 *)((s8 *)(arg0) + (0x79))) >> 4);
}

void func_808000AC_chnewfreezy(s32 arg0)
{
    _sufreezy_entrypoint_2();
    func_8010A570(arg0);
}
void func_808000D4_chnewfreezy(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010D254(f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void _sufreezy_entrypoint_4(Unk80132ED0 *, s32);
    struct FreezyPart {
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 pad24[3];
        f32 spin[3];
        f32 pad3C[4];
        f32 size;
        f32 pad50[3];
        s8 state;
        u8 pad5D[3];
    } *part;
    volatile s32 pad;
    f32 position[3];
    volatile s32 pad2;
    f32 angle;
    f32 pitch;
    f32 yaw;
    f32 speed;
    f32 pitchRange = 20.0f;
    f32 yawRange = 65.0f;
    u32 i;

    part = func_80100094(arg0, 0);
    if (!arg0->unk64_20) {
        arg0->unk64_20 = 1;
        arg0->unk54 = 0.0f;
        func_8010D254(position);
        for (i = 0; i < arg0->unk6C_0; i++) {
            if (part->state == 3) {
                part++;
            } else {
                angle = func_800F1DF4(part->position, position);
                pitch = func_800DC178(-pitchRange, pitchRange);
                yaw = func_800DC178(-yawRange, yawRange);
                speed = func_800DC178(800.0f, 1000.0f);
                func_800EEC30(part->velocity, pitch + 130.0f, yaw + angle, speed);
                part->spin[0] = func_800DC178(-25.0f, 25.0f);
                part->spin[1] = func_800DC178(-25.0f, 25.0f);
                part->spin[2] = func_800DC178(-25.0f, 25.0f);
                part->state = 4;
                part->size *= 0.6f;
                part++;
            }
        }
        _sufreezy_entrypoint_4(arg0->unk0, 8);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newfreezy/func_808002C0_chnewfreezy.s")

void func_80800824_chnewfreezy(Actor *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct FreezyPart {
        f32 position[3];
        u8 pad0C[0x18];
        f32 unk24[3];
        u8 pad30[0x24];
        f32 unk54;
        f32 unk58;
        u8 pad5C[4];
    } *parts;
    struct FreezyPart *temp_s1;
    struct FreezyPart *temp_s0;
    struct FreezyLink {
        u8 pad00[0xE];
        s16 parent;
    } *sp48;
    struct FreezyLink *temp_fp;
    struct FreezyLink *temp_v0;
    s32 var_s2;
    parts = func_80100094(arg0, 0);
    var_s2 = 0;
    if (arg2 > 0) {
        sp48 = (void *) (arg1 + 8);
        for (;;) {
            temp_v0 = &sp48[var_s2];
            temp_fp = &sp48[arg3];
            if (temp_v0 == temp_fp) {
                goto next;
            }
            temp_s1 = &parts[var_s2];
            if (temp_s1->unk58 != (-1.0f)) {
                goto next;
            }
            if ((arg3 != temp_v0->parent) && (var_s2 != temp_fp->parent)) {
                goto next;
            }
            temp_s0 = &parts[arg3];
            temp_s1->unk54 = temp_s0->unk58;
            temp_s1->unk58 = func_800EEAD4(temp_s1->position, temp_s0->position) + temp_s0->unk58;
            func_800EE7F8(temp_s1->unk24, temp_s0->position);
            /* This redundant condition preserves IDO's parent/child register allocation. */
            if (temp_s0 || temp_s0) {}
            func_80800824_chnewfreezy(arg0, arg1, arg2, var_s2);
            next:
            if ((++var_s2) == arg2) {
                break;
            }

        }

    }
}

/* extern */

void func_80800974_chnewfreezy(Actor *arg0, u8 *arg1) {
    typedef struct { f32 m[4][4]; } MtxF;
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    u32 func_800ADE50(u8 *, u8 *, s32);
    void *func_800AE080(s16);
    s32 func_800AE290(s16, s32, s32);
    s32 func_800DF324(void);
    void func_800F2C1C(MtxF *, f32 *);
    void mlMtxGet(void *);
    void mlMtxSet(void *);
    void mlMtxRotatePYR(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    f32 temp_f8;
    s32 temp_s5;
    u32 var_s1;
    struct FreezyPartTransform {
        f32 position[3];
        f32 rotation[3];
        u8 pad18[0x48];
    } *var_s0;
    MtxF sp48;

    var_s0 = func_80100094(arg0, 0);
    func_800AE290(*(s16 *)&arg0->unk0->unk10, arg1, func_800DF324());
    temp_s5 = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    var_s1 = 0;
    if (arg0->unk6C_0) {
        do {
            mlMtxSet(func_800ADE50(temp_s5, arg1, _dbskeleton_entrypoint_4(arg1, var_s1)));
            mlMtxRotatePYR(arg0->rotation[0], arg0->rotation[1], arg0->rotation[2]);
            mlMtxGet(&sp48);
            func_800F2C1C(&sp48, var_s0->rotation);
            var_s0->rotation[1] -= 90.0f;
            var_s0->rotation[2] = -var_s0->rotation[0];
            var_s0->rotation[0] = 0.0f;
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
}

void func_80800AA4_chnewfreezy(Actor *arg0, u8 *arg1) {
    typedef struct { f32 m[4][4]; } MtxF;
    typedef struct { f32 v[3]; } FreezyVector;
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    u32 func_800ADE50(u8 *, u8 *, s32);
    void *func_800AE080(s16);
    void func_800AE40C(s16, u8 *, s32);
    s32 func_800DF324(void);
    void func_800F23D0(MtxF *, f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void mlMtxGet(void *);
    void mlMtxSet(void *);
    f32 sqrtf(f32);
    extern FreezyVector D_80801950_chnewfreezy;
    u8 *temp_s5;
    s32 temp_v0;
    u32 var_s0;
    struct FreezyPartScale {
        u8 pad00[0x48];
        f32 scale;
        u8 pad4C[0x14];
    } *var_s1;
    MtxF sp60;
    FreezyVector sp54;
    f32 sp48[3];

    var_s1 = func_80100094(arg0, 0);
    func_800AE40C(*(s16 *)&arg0->unk0->unk10, arg1, func_800DF324());
    temp_s5 = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    for (var_s0 = 0; var_s0 < arg0->unk6C_0; var_s0++) {
            temp_v0 = _dbskeleton_entrypoint_4(arg1, var_s0);
            sp54 = D_80801950_chnewfreezy;
            mlMtxSet(func_800ADE50(temp_s5, arg1, temp_v0));
            mlMtxGet(&sp60);
            func_800F23D0(&sp60, sp48, sp54.v);
            var_s1->scale = sqrtf((sp48[0] * sp48[0] + sp48[1] * sp48[1]) + sp48[2] * sp48[2]);
            var_s1++;
    }
}

/* extern */

void func_80800BFC_chnewfreezy(Actor *arg0, u8 *arg1) {
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    void *func_800AE080(s16);
    s32 func_800AE1E8(s16, s32, s32);
    s32 func_800AE630(u8 *, u8 *, s32, s32);
    s32 func_800DF324(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 temp_s4;
    u32 var_s1;
    struct FreezyPartPosition {
        f32 position[3];
        u8 pad0C[0x18];
        f32 previousPosition[3];
        u8 pad30[0x1C];
        f32 unk4C;
        u8 pad50[0x10];
    } *var_s0;

    var_s0 = func_80100094(arg0, 0);
    func_800AE1E8(*(s16 *)&arg0->unk0->unk10, arg1, func_800DF324());
    temp_s4 = func_800AE080(*(s16 *)&arg0->unk0->unk10);
    var_s1 = 0;
    if (arg0->unk6C_0) {
        do {
            func_800AE630(temp_s4, arg1, _dbskeleton_entrypoint_4(arg1, var_s1), var_s0);
            func_800EF334(var_s0->position, *(f32 *)&arg0->actorData[7]);
            func_800EF5A0(var_s0->position, arg0->rotation, var_s0->position[0], var_s0->position[1], var_s0->position[2]);
            func_800EF04C(var_s0->position, arg0->position);
            var_s0->unk4C = 0.0f;
            func_800EE7F8(var_s0->previousPosition, var_s0->position);
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
}

void func_80800D28_chnewfreezy(Actor *arg0, s32 arg1) {
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80800824_chnewfreezy(Actor *, u8 *, s32, s32);
    struct FreezyPart {
        f32 position[3];
        u8 pad0C[0x48];
        f32 unk54;
        f32 unk58;
        u8 pad5C[4];
    } *part, *nearest;
    f32 distance;
    f32 maximum;
    f32 minimum;
    u32 i;
    u32 nearestIndex;

    part = func_80100094(arg0, 0);
    maximum = 0.0f;
    minimum = 0.0f;
    nearestIndex = -1U;
    i = 0;
    if (arg0->unk6C_0) {
        do {
            distance = func_800EEAD4((f32 *)arg0->actorData, part->position);
            if (i == 0 || maximum < distance) {
                maximum = distance;
            }
            if (i == 0 || distance < minimum) {
                minimum = distance;
                nearestIndex = i;
            }
            part->unk58 = -1.0f;
            i++;
            part++;
        } while (i < arg0->unk6C_0);
    }
    if (nearestIndex != -1U) {
        nearest = func_80100094(arg0, 0);
        nearest += nearestIndex;
        nearest->unk58 = 100.0f;
        nearest->unk54 = 0.0f;
        func_80800824_chnewfreezy(arg0, (u8 *)arg1, arg0->unk6C_0, nearestIndex);
    }
}

void func_80800E74_chnewfreezy(Actor *arg0, u8 *arg1, void *volatile arg2, s32 arg3) {
    void *func_80100094(Actor *, u32);
    s32 _dbskeleton_entrypoint_4(u8 *, u32);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    struct FreezyPart {
        f32 position[3];
        f32 rotation[3];
        f32 pad18[12];
        f32 size;
        f32 pad4C[3];
        f32 unk58;
        s8 state;
        s8 unk5D;
        s8 unk5E;
        s8 pad5F;
    } *part;
    struct FreezyConfig {
        s32 bone;
        f32 scale;
        s8 unk8;
        s8 unk9;
        s8 padA[2];
    } *config;
    u32 i;
    u32 j;
    s32 k;
    s32 bone;
    f32 angle;

    part = func_80100094(arg0, 0);
    if (arg0->unk6C_0) {
        i = 0;
        do {
            bone = _dbskeleton_entrypoint_4(arg1, i);
            part->state = 3;
            if (part->unk58 == -1.0f) {
                part->unk58 = 100.0f;
            }
            k = 0;
            config = arg2;
            if (arg3 > 0) {
                do {
                    if (bone == config->bone) {
                        part->size *= config->scale;
                        part->state = 1;
                        part->unk5D = config->unk8;
                        part->unk5E = config->unk9;
                        if (part->unk5E >= 0) {
                            j = 0;
                            if (arg0->unk6C_0) {
                                do {
                                    if (_dbskeleton_entrypoint_4(arg1, j) == part->unk5E) {
                                        func_800F18FC(part->position, ((struct FreezyPart *)func_80100094(arg0, 0))[j].position, part->rotation);
                                        part->rotation[2] = part->rotation[0];
                                        part->rotation[0] = 0.0f;
                                        part->rotation[1] -= 90.0f;
                                    }
                                    j++;
                                } while (j < arg0->unk6C_0);
                            }
                        } else {
                            switch (part->unk5E) {
                                case -4:
                                    func_800EF214(part->position, part->rotation[0] + 45.0f, arg0->rotation[1], part->size * 25.0f);
                                    break;
                                case -5:
                                    func_800EF214(part->position, part->rotation[0] + 45.0f, part->rotation[1] + 90.0f, part->size * 25.0f);
                                    break;
                                case -3:
                                    func_800EF214(part->position, part->rotation[0] + 90.0f, part->rotation[1] + 90.0f, part->size * 25.0f);
                                    break;
                                case -2:
                                    func_800EF214(part->position, part->rotation[0] - 90.0f, part->rotation[1] + 90.0f, part->size * 25.0f);
                                    break;
                            }
                        }
                    }
                    k++;
                    config++;
                } while (k != arg3);
            }
            part->size *= *(f32 *)&arg0->actorData[7];
            part++;
            i++;
        } while (i < arg0->unk6C_0);
    }
}

void func_808011A8_chnewfreezy(f32 arg0, f32 arg1) {
    void func_800D93A0(f32[4], f32[3]);
    void func_800D9470(f32[4], f32[4], f32[4]);
    s32 func_800DF324(void);
    void func_800DFB40(s32 *, s32, u8 *);
    void func_800DFF2C(u8 **, s32, f32[4]);
    struct Quaternion { f32 v[4]; };
    struct Vector { f32 v[3]; };
    extern struct Quaternion D_8080195C_chnewfreezy;
    extern struct Vector D_8080196C_chnewfreezy;
    struct Quaternion sp58;
    struct Vector sp4C;
    f32 sp3C[4];
    f32 sp2C[4];
    s32 sp28;


    sp58 = D_8080195C_chnewfreezy;
    sp4C = D_8080196C_chnewfreezy;
    sp28 = func_800DF324();
    func_800DFB40(sp28, 0x12, sp3C);
    sp4C.v[1] = arg0 * 0.75f;
    sp4C.v[0] = -arg1 * 0.9f;
    func_800D93A0(sp58.v, sp4C.v);
    func_800D9470(sp58.v, sp58.v, sp3C);
    func_800DFF2C(sp28, 0x12, sp58.v);
    func_800DFB40(sp28, 1, sp2C);
    sp4C.v[1] = arg0 * 0.25f;
    sp4C.v[0] = -arg1 * 0.1f;
    func_800D93A0(sp58.v, sp4C.v);
    func_800D9470(sp58.v, sp58.v, sp2C);
    func_800DFF2C(sp28, 1, sp58.v);
}

/* extern */

f32 func_808012F8_chnewfreezy(Actor *arg0) {
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct FreezyPart {
        f32 position[3];
        u8 pad0C[0x3C];
        f32 scale;
        u8 pad4C[0x10];
        s8 state;
        u8 pad5D[3];
    } *var_s0;
    f32 temp_f2;
    f32 var_f20;
    u32 var_s1;

    var_s0 = func_80100094(arg0, 0);
    var_f20 = 0.0f;
    var_s1 = 0;
    if (arg0->unk6C_0) {
        do {
            if (var_s0->state != 3) {
                temp_f2 = func_800EEAD4((f32 *)&arg0->actorData[4], var_s0->position) + (25.0f * var_s0->scale);
                if (var_f20 < temp_f2) {
                    var_f20 = temp_f2;
                }
            }
            var_s1 += 1;
            var_s0++;
        } while (var_s1 < arg0->unk6C_0);
    }
    return var_f20;
}

Actor *chnewfreezy_entrypoint_0(Unk80132ED0 *marker, s32 x, s32 y, s32 z) {
    s32 _dbskeleton_entrypoint_0(u8 *);
    void _sufreezy_entrypoint_3(Actor *);
    s16 func_800AE020(void);
    f32 func_800EC708(Unk80132ED0 *);
    void func_80101038(f32 *);
    s32 func_8010108C(Actor *, s32, s32);
    u8 *func_801039E4(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *arg0);
    Actor *sp54;
    Actor *actor;
    u8 *sp4C;
    void *sp48;
    s32 sp44;
    s32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 sp2C[3];

    sp40 = 0;
    sp54 = func_80106790(marker);
    sp44 = func_8010108C(sp54, 0x38, 0);
    if (sp44 <= 0) {
        return NULL;
    }
    sp48 = func_80101080();
    actor = func_801084B0(0x2FF, &sp54);
    ((f32 *)actor->actorData)[0] = x;
    ((f32 *)actor->actorData)[1] = y;
    ((f32 *)actor->actorData)[2] = z;
    actor->rotation[0] = sp54->rotation[0];
    actor->rotation[1] = sp54->rotation[1];
    actor->rotation[2] = sp54->rotation[2];
    ((f32 *)actor->actorData)[7] = sp54->scale;
    actor->unk50 = 0.0f;
    func_80103DFC(sp54, (f32 *)&actor->actorData[4]);
    sp4C = func_800B27E0(func_801039E4(sp54->unk0));
    actor->unk6C_0 = _dbskeleton_entrypoint_0(sp4C);
    func_80100074(actor, 0, actor->unk6C_0 * 0x60);
    if (*(s16 *)&actor->unk0->unk10 == 0) {
        *(s16 *)&actor->unk0->unk10 = func_800AE020();
    }
    func_800DF41C(func_8008B4D4(func_80104248(sp54)));
    if (func_8010108C(sp54, 0x94, 0) > 0) {
        func_80101038(sp2C);
        sp40 = 1;
        sp3C = sp2C[0];
        sp38 = sp2C[1];
    }
    if (sp40 != 0) {
        func_808011A8_chnewfreezy(sp38, sp3C);
    }
    func_80800974_chnewfreezy(actor, sp4C);
    func_80800AA4_chnewfreezy(actor, sp4C);
    func_80800BFC_chnewfreezy(actor, sp4C);
    func_80800D28_chnewfreezy(actor, (s32)sp4C);
    func_80800E74_chnewfreezy(actor, sp4C, sp48, sp44);
    actor->unk74_7 = func_808012F8_chnewfreezy(actor);
    actor->scale = actor->unk74_7 / func_800EC708(actor->unk0);
    _sufreezy_entrypoint_3(actor);
    return actor;
}

/* extern */

void func_808016B4_chnewfreezy(Actor *arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF830(s32);
    s32 func_800E3E8C(f32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 models[4];
    u32 i;
    struct FreezyRenderPart {
        u8 pad00[0xC];
        f32 rotation[3];
        u8 pad18[0x24];
        f32 position[3];
        f32 pad48;
        f32 scale;
        u8 pad50[0xC];
        s8 state;
        s8 model;
        u8 pad5E[2];
    } *part;

    if (func_800E3E8C((f32 *)&arg0->actorData[4], arg0->unk74_7)) {
        part = func_80100094(arg0, 0);
        models[0] = func_800D674C(0x74C);
        models[1] = func_800D674C(0x74D);
        models[2] = func_800D674C(0x74E);
        i = 0;
        if (arg0->unk6C_0) {
            do {
                if (part->state != 3) {
                    if (_subaddiefade_entrypoint_0(arg0) < 0xFF) {
                        func_800DF410(_subaddiefade_entrypoint_0(arg0));
                    }
                    func_800DF830(2);
                    func_800DE448(part->position, part->rotation, part->scale, 0, models[part->model]);
                }
                i++;
                part++;
            } while (i < arg0->unk6C_0);
        }
    }
}

s32 func_808017FC_chnewfreezy(Actor *arg0, s32 arg1, volatile s32 arg2) {
    s32 _subaddielink_entrypoint_3(u8 *);
    void _sufreezy_entrypoint_5(Unk80132ED0 *, s32);
    void _sufreezy_entrypoint_6(Unk80132ED0 *, s32);
    void _sufreezy_entrypoint_7(Unk80132ED0 *, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);

    switch (arg1) {
        case 0x3E:
            if (arg0->unk50 > 0.75f) {
                func_80800068_chnewfreezy(arg0);
                _sufreezy_entrypoint_5(arg0->unk0, arg2);
                func_808000D4_chnewfreezy(arg0);
                func_808000AC_chnewfreezy((s32)arg0);
            }
            break;
        case 0x3F:
            _sufreezy_entrypoint_6(arg0->unk0, arg2);
            break;
        case 0x40:
            func_80800068_chnewfreezy(arg0);
            _sufreezy_entrypoint_7(arg0->unk0, arg2);
            func_808000D4_chnewfreezy(arg0);
            func_808000AC_chnewfreezy((s32)arg0);
            break;
        case 0x95:
            if (_subaddielink_entrypoint_3(func_80100094(arg0, 1)) == 0) {
                func_800FFAB0(arg0);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chnewfreezy_entrypoint_1(void)
{
    extern u8 D_80801978_chnewfreezy[];

    return (OSThread *) D_80801978_chnewfreezy;
}
