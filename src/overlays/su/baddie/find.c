#include "common.h"

Actor *subaddiefind_entrypoint_0(f32 *arg0, s32 arg1, s32 arg2, f32 *arg3) {
    f32 func_800EEB40(f32 *, f32 *);
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    f32 sqrtf(f32);
    f32 temp_f0;
    f32 var_f20;
    s32 var_s1;
    Actor *var_s0;
    s32 sp54;
    Actor *var_s3;

    var_f20 = 0.0f;
    var_s3 = NULL;
    var_s1 = 0;
    var_s0 = (Actor *)func_801067C4(&sp54);
    if (var_s0 != NULL) {
        do {
            if (((arg1 == var_s0->unk6C_9) || (arg1 < 0)) && (arg2 != var_s0->unk70_10) && (var_s0->unk6C_9 != 0x215) && (var_s0->unk6C_9 != 0x243) && !var_s0->unk64_17) {
                temp_f0 = func_800EEB40(arg0, var_s0->position);
                if ((temp_f0 < var_f20) || (var_s1 == 0)) {
                    var_f20 = temp_f0;
                    var_s3 = var_s0;
                    var_s1 = 1;
                }
            }
            var_s0 = (Actor *)func_8010682C(&sp54);
        } while (var_s0 != NULL);
    }
    if (arg3 != NULL) {
        *arg3 = sqrtf(var_f20);
    }
    return var_s3;
}

/* extern */

Actor *subaddiefind_entrypoint_1(Actor *arg0, s32 arg1, s32 arg2, f32 *arg3) {
    f32 func_800EEAD4(f32 *, f32 *);
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    f32 temp_f0;
    f32 var_f20;
    Actor *var_s0;
    s32 sp48;
    Actor *var_s5;

    var_s5 = NULL;
    var_f20 = 1e10f;
    var_s0 = (Actor *)func_801067C4(&sp48);
    if (var_s0 != NULL) {
        do {
            if (((arg1 == var_s0->unk6C_9) || (arg1 < 0)) && (arg2 != var_s0->unk70_10) && (0x215 != var_s0->unk6C_9) && (0x243 != var_s0->unk6C_9) && !var_s0->unk64_17 && (var_s0->unk0 != arg0->unk0)) {
                temp_f0 = func_800EEAD4(arg0->position, var_s0->position);
                if (temp_f0 < var_f20) {
                    var_f20 = temp_f0;
                    var_s5 = var_s0;
                }
            }
            var_s0 = (Actor *)func_8010682C(&sp48);
                } while (var_s0 != NULL);
    }
    if (arg3 != NULL) {
        *arg3 = var_f20;
    }
    return var_s5;
}

/* extern */

Actor *subaddiefind_entrypoint_2(s32 arg0, s32 *arg1) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    Actor *actor;
    s32 sp20;

    actor = (Actor *)func_801067C4(&sp20);
    while (actor != NULL) {
        if (arg0 == actor->unk6C_9 && !actor->unk64_17) {
            if (arg1 != NULL) {
                *arg1 = sp20;
            }
            return actor;
        }
        actor = (Actor *)func_8010682C(&sp20);
    }
    return NULL;
}

/* extern */

Actor *subaddiefind_entrypoint_3(s32 arg0, s32 *arg1) {
    BtIntPtr func_8010682C(s32 *);
    Actor *actor;

    actor = (Actor *)func_8010682C(arg1);
    while (actor != NULL) {
        if (arg0 == actor->unk6C_9 && !actor->unk64_17) {
            return actor;
        }
        actor = (Actor *)func_8010682C(arg1);
    }
    return NULL;
}

/* extern */

s32 subaddiefind_entrypoint_4(s32 arg0, Actor **arg1, s32 arg2) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    s32 var_s1;
    s32 sp38;
    s32 id = arg0;
    Actor *var_v0;

    var_s1 = 0;
    var_v0 = (Actor *)func_801067C4(&sp38);
    if (var_v0 != NULL) {
        do {
            if (id == var_v0->unk6C_9 && !var_v0->unk64_17) {
                var_s1 += 1;
                *arg1++ = var_v0;
                if (var_s1 == arg2) {
                    return var_s1;
                }
            }
            var_v0 = (Actor *)func_8010682C(&sp38);
        } while (var_v0 != NULL);
    }
    return var_s1;
}

/* extern */

s32 subaddiefind_entrypoint_5(s32 arg0, Actor **arg1, s32 arg2, f32 *arg3, f32 arg4, f32 (*arg5)(f32 *, f32 *)) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    s32 sp48[2];
    s32 var_s1;
    Actor *var_v0;

    arg4 *= arg4;
    var_s1 = 0;
    var_v0 = (Actor *)func_801067C4(sp48);
    if (var_v0 != NULL) {
        do {
            if (arg0 == var_v0->unk6C_9 && !var_v0->unk64_17 && arg5(arg3, var_v0->position) < arg4) {
                var_s1++;
                *arg1++ = var_v0;
                if (var_s1 == arg2) {
                    return var_s1;
                }
            }
            var_v0 = (Actor *)func_8010682C(sp48);
        } while (var_v0 != NULL);
    }
    return var_s1;
}

/* extern */

s32 subaddiefind_entrypoint_6(s16 *arg0, Actor **arg1, s32 arg2) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    s16 *var_v1;
    s32 var_s1;
    s32 sp3C;
    Actor *var_v0;

    var_s1 = 0;
    var_v0 = (Actor *)func_801067C4(&sp3C);
    if (var_v0 != NULL) {
        do {
            if (!var_v0->unk64_17) {
                for (var_v1 = arg0; *var_v1 != -1; var_v1++) {
                    if (var_v0->unk6C_9 == *var_v1) {
                        var_s1++;
                        *arg1++ = var_v0;
                        if (var_s1 == arg2) {
                            return var_s1;
                        }
                    }
                }
            }
            var_v0 = (Actor *)func_8010682C(&sp3C);
        } while (var_v0 != NULL);
    }
    return var_s1;
}

/* extern */

s32 subaddiefind_entrypoint_7(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *subaddiefind_entrypoint_0(f32 *, s32, s32, f32 *);
    f32 sp24;
    f32 var_f0;
    Actor *temp_v0;

    temp_v0 = subaddiefind_entrypoint_0(arg0->position, arg1, -1, &sp24);
    if ((temp_v0 != NULL) && (sp24 < (f32) arg2)) {
        arg0->unk3C = temp_v0->unk0;
    } else {
        arg0->unk3C = NULL;
    }
    if (arg0->unk3C != NULL) {
        var_f0 = sp24;
    } else {
        var_f0 = -1.0f;
    }
    return (s32) var_f0;
}

/* extern */

Actor *subaddiefind_entrypoint_8(s32 arg0) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    Actor *actor;
    s32 sp20;

    actor = (Actor *)func_801067C4(&sp20);
    while (actor != NULL) {
        if (arg0 == ((u32)(u16)actor->unk0->unk10 >> 1) && !actor->unk64_17) {
            return actor;
        }
        actor = (Actor *)func_8010682C(&sp20);
    }
    return NULL;
}

/* extern */

s32 subaddiefind_entrypoint_9(s32 arg0) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    s32 var_s0;
    Actor *var_v0;
    s32 sp2C;

    var_s0 = 0;
    var_v0 = (Actor *)func_801067C4(&sp2C);
    if (var_v0 != NULL) {
        do {
            if (arg0 == var_v0->unk6C_9 && !var_v0->unk64_17) {
                var_s0 += 1;
            }
            var_v0 = (Actor *)func_8010682C(&sp2C);
        } while (var_v0 != NULL);
    }
    return var_s0;
}

/* extern */

s32 subaddiefind_entrypoint_10(Actor *arg0, s32 arg1, u32 arg2) {
    Actor *subaddiefind_entrypoint_11(s32, u32);
    Actor *temp_v0;

    temp_v0 = subaddiefind_entrypoint_11(arg1, arg2);
    if (temp_v0 != NULL) {
        arg0->unk3C = temp_v0->unk0;
    } else {
        arg0->unk3C = NULL;
    }
    return arg0->unk3C ? 1 : 0;
}

/* extern */

Actor *subaddiefind_entrypoint_11(s32 arg0, u32 arg1) {
    s32 subaddiefind_entrypoint_4(s32, Actor **, s32);
    Actor *sp28[20];
    s32 temp_v0;
    s32 var_v1;
    Actor *temp_a0;

    temp_v0 = subaddiefind_entrypoint_4(arg0, sp28, 0x14);
    for (var_v1 = 0; var_v1 < temp_v0; var_v1++) {
        temp_a0 = sp28[var_v1];
        if (arg1 == temp_a0->unk74_7) {
            return temp_a0;
        }
    }
    return NULL;
}

/* extern */

Actor *subaddiefind_entrypoint_12(s32 arg0) {
    BtIntPtr func_801067C4(s32 *);
    BtIntPtr func_8010682C(s32 *);
    Actor *actor;
    s32 sp20;

    actor = (Actor *)func_801067C4(&sp20);
    while (actor != NULL) {
        if (!actor->unk64_17 && arg0 == actor->pad6C_21) {
            return actor;
        }
        actor = (Actor *)func_8010682C(&sp20);
    }
    return NULL;
}

Actor **subaddiefind_entrypoint_13(u8 *arg0) {
    typedef struct {
        Unk80132ED0 *marker;
        s32 unk4;
        BT_BITFIELD_ORDER(u32 unk8:31, u32 isMarker : 1);
        BT_BITFIELD_ORDER(u32 isMarker:1, u32 unk8 : 31);
    } HitProp;
    typedef struct {
        u8 pad0[0x18];
        u16 flags;
    } MarkerFlags;
    s32 *func_800BE3F8(u8 *);
    BtIntPtr func_800E9E88(BtIntPtr);
    BtUIntPtr func_800E9EB4(s16 *);
    OSThread *func_8010413C(void);
    Actor *func_80106790(Unk80132ED0 *);
    Actor **actors;
    s32 count;
    s32 *cell;
    HitProp *prop;
    HitProp *end;
    Unk80132ED0 *marker;
    Actor *actor;

    actors = (Actor **)func_8010413C();
    count = 0;
    cell = func_800BE3F8(arg0);
    while (*cell != 0) {
            prop = (HitProp *)func_800E9E88(*cell);
            end = (HitProp *)func_800E9EB4((s16 *)*cell);
            if (prop < end) {
                do {
                    if (prop->isMarker) {
                        marker = prop->marker;
                        if (((MarkerFlags *)marker)->flags & 1) {
                            actor = func_80106790(marker);
                            if (!actor->unk64_17) {
                                actors[count] = actor;
                                count++;
                            }
                        }
                    }
                    prop++;
                } while (prop < end);
            }
            cell++;
    }
    actors[count] = NULL;
    return actors;
}
