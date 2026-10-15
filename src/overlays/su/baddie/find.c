#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_1.s")

/* extern */

Actor *subaddiefind_entrypoint_2(s32 arg0, s32 *arg1) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
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
    s32 func_8010682C(s32 *);
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
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_5.s")

/* extern */

s32 subaddiefind_entrypoint_6(s16 *arg0, Actor **arg1, s32 arg2) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
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
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
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
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
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
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/find/subaddiefind_entrypoint_13.s")
