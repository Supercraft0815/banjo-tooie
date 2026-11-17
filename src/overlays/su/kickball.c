#include "common.h"
#ifdef BT_NATIVE // complete the enum forward declarations below
#include "overlays/ba/assets.h"
#endif
struct kickball_vector { f32 v[3]; };
void func_80800000_sukickball(BtIntPtr arg0, BtIntPtr arg1, f32 *arg2, f32 arg3) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF830(s32);
    BtIntPtr func_801039E4(BtIntPtr);

    extern struct kickball_vector D_80801200_sukickball;
    struct kickball_vector sp24 = D_80801200_sukickball;

    func_800DF830(3);
    func_800DE448(arg2, sp24.v, arg3, NULL, func_801039E4(arg0));
}

void sukickball_entrypoint_0(Actor *arg0, s32 arg1) {
    f32 func_800138D0(f32);
    void func_800DBEFC(s32 *, s32, f32 *);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    s32 func_800DF350(void);
    void func_800DF410(s32);
    void func_800DF47C(s32, BtIntPtr);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    OSThread *func_80104130(void);

    struct kickball_render_data { f32 unused[2]; f32 position[3]; f32 angle; };
    extern struct kickball_vector D_8080120C_sukickball;
    struct kickball_render_data *sp54;
    struct kickball_vector sp48;
    s32 value;
    f32 sp38[3];
    f32 wave;
if (!arg0) {}

    sp54 = func_80100094(arg0, 0);
    sp48 = D_8080120C_sukickball;
    sp48.v[0] = arg0->rotation[0];
    sp48.v[1] = 0.0f;
    sp48.v[2] = arg0->rotation[2];
    func_800DF47C((BtIntPtr)func_801015D0, (BtIntPtr)arg0);
    wave = func_800138D0(sp54->angle);
    value = (s32)((u32)arg0->alpha * wave);
    if (value < 0) {
        value = -value;
    }
    if (value >= 0x61) {
        func_800DF744(3, 1);
        func_800DF410(value);
        func_800DE448(arg0->position, sp48.v, arg0->scale, NULL, func_8010347C(arg0->unk0));
        if (func_800DF350()) {
            func_800DBEFC((s32 *)func_80104130(), 4, sp54->position);
        }
    }
    if (value < 0xA0) {
        func_800DF744(3, 2);
        func_800DF410(arg0->alpha - value);
        func_800DE448(arg0->position, sp48.v, arg0->scale, NULL, func_8010347C(arg0->unk0));
        if (func_800DF350()) {
            func_800DBEFC((s32 *)func_80104130(), 5, sp54->position);
        }
    }
    if (func_800DF350()) {
        sp38[0] = arg0->position[0];
        sp38[1] = arg0->position[1] - 30.0f;
        sp38[2] = arg0->position[2];
        func_80800000_sukickball((BtIntPtr)arg0->unk3C, arg1, sp38, 0.4f);
    }
}

void sukickball_entrypoint_1(Actor *arg0, void *arg1) {
    extern s32 D_80801218_sukickball[];
    func_800DF744(1, D_80801218_sukickball[arg0->unk6C_0]);
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_80800000_sukickball((BtIntPtr)arg0->unk3C, (BtIntPtr)arg1, (f32 *)arg0->position, 0.5f);
    }
}

void sukickball_entrypoint_2(Actor *arg0, f32 arg1, f32 arg2) {
    struct anctrl_s;
#ifndef BT_NATIVE // would hide the complete enum from overlays/ba/assets.h
    enum asset_e;
#endif
    void anctrl_setIndex(struct anctrl_s *, enum asset_e);
    void anctrl_start(struct anctrl_s *);
    void func_800C4140(u32, f32 *, u32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101CDC(Actor *, f32);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    struct anctrl_s *func_80104248(void *);
    struct kickball_motion {
        f32 unused[3];
        f32 speed;
    };
    struct kickball_sound {
        f32 unused;
        f32 timer;
    } *sp2C;

    sp2C = func_80100094(arg0, 0);
    if (((struct kickball_motion *)arg0->actorData)->speed > 0.5f) {
        if (func_801022E4(arg0) == 0x63) {
            anctrl_setIndex(func_80104248(arg0), 0x1D7);
            anctrl_start(func_80104248(arg0));
        }
        func_80101CDC(arg0, func_800F10B4(((struct kickball_motion *)arg0->actorData)->speed, arg1, arg2, 1.0f, 0.5f));
    } else if (func_801022E4(arg0) != 0x63) {
        anctrl_setIndex(func_80104248(arg0), 0x63);
        func_80101CDC(arg0, 8.0f);
        anctrl_start(func_80104248(arg0));
    }
    if (sp2C->timer <= 0.0f && (func_80101E14(arg0, 0.5f) || func_80101E14(arg0, 0.0f))) {
        func_800C4140(0xE627D4AE, arg0->position, 0x3E800640);
        sp2C->timer = 1.0f;
    }
}

s32 sukickball_entrypoint_3(void) {
    s32 func_800EA05C();

    switch (func_800EA05C()) {
        case 0xC6:
        case 0x12E:
            return 0;
        case 0xC8:
        case 0x12F:
            return 1;
        case 0xC9:
        case 0x130:
            return 2;
        case 0x17F:
        case 0x180:
            return 4;
        case 0xBB:
            return 3;
    }
    return 0;
}

void sukickball_entrypoint_4(s32 arg0, f32 *arg1) {
    f32 func_800DC178(f32, f32);

    arg1[1] = 0.0f;
    switch (arg0) {
        case 0:
            arg1[0] = 846.0f;
            if (arg1[2] < -108.0f || arg1[2] > 108.0f) {
                arg1[2] = func_800DC178(-108.0f, 108.0f);
            }
            break;
        case 2:
            if (arg1[0] < -108.0f || arg1[0] > 108.0f) {
                arg1[0] = func_800DC178(-108.0f, 108.0f);
            }
            arg1[2] = 846.0f;
            break;
        case 1:
            arg1[0] = -846.0f;
            if (arg1[2] < -108.0f || arg1[2] > 108.0f) {
                arg1[2] = func_800DC178(-108.0f, 108.0f);
            }
            break;
        case 3:
            if (arg1[0] < -108.0f || arg1[0] > 108.0f) {
                arg1[0] = func_800DC178(-108.0f, 108.0f);
            }
            arg1[2] = -846.0f;
            break;
    }
}

s32 sukickball_entrypoint_5(Actor *arg0, f32 *arg1) {
    s32 *func_800BF340(f32 *, f32 *, f32 *, s32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA98(f32 *, f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFDE8(f32 *, u8 *, f32 *);
    f32 sp64[3];
    u8 sp58[12];
    f32 sp4C[3];
    s32 changed = 0;
    s32 pad;
    f32 sp38[3];

    func_800EFB24(sp58, arg0->position, arg1);
    func_800EE7F8(sp4C, arg0->position);
    if (func_800BF340(arg1, sp4C, sp64, 0x20020, 30.0f)) {
        func_800EFDE8(sp38, sp58, sp64);
        sp38[1] = 0.0f;
        func_800EFA98(sp38, sp38, 5.0f);
        func_800EE780(arg0->position, sp4C, sp38);
        func_800EE7F8(arg1, arg0->position);
        return 1;
    }
    if (arg0->position[2] > 690.0f) {
        if (arg0->position[0] > -159.0f && arg0->position[0] < 159.0f) {
            if (arg0->position[2] > 822.0f) {
                changed = 1;
                arg0->position[2] = 816.0f;
            }
        } else {
            arg0->position[2] = 690.0f;
            changed = 1;
        }
    }
    if (arg0->position[2] < -696.0f) {
        if (arg0->position[0] > -159.0f && arg0->position[0] < 159.0f) {
            if (arg0->position[2] < -822.0f) {
                changed = 1;
                arg0->position[2] = -816.0f;
            }
        } else {
            changed = 1;
            arg0->position[2] = -690.0f;
        }
    }
    if (arg0->position[0] < -696.0f) {
        if (arg0->position[2] < 159.0f && arg0->position[2] > -159.0f) {
            if (arg0->position[0] < -822.0f) {
                changed = 1;
                arg0->position[0] = -816.0f;
            }
        } else {
            changed = 1;
            arg0->position[0] = -690.0f;
        }
    }
    if (arg0->position[0] > 696.0f) {
        if (arg0->position[2] > -159.0f && arg0->position[2] < 159.0f) {
            if (arg0->position[0] > 822.0f) {
                changed = 1;
                arg0->position[0] = 816.0f;
            }
        } else {
            arg0->position[0] = 690.0f;
            changed = 1;
        }
    }
    if (changed) {
        func_800EE7F8(arg0->position, arg1);
    }
    return changed;
}

/* extern */

s32 sukickball_entrypoint_6(Actor *arg0, BtIntPtr arg1) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)((BtIntPtr)func_80100094(arg0, 0U) + arg1 + 0xA))) == 2;
}

/* extern */

s32 sukickball_entrypoint_7(Actor *arg0, BtIntPtr arg1) {
    void* func_80100094(Actor*, u32);
    return (*(u8 *)((s8 *)((BtIntPtr)func_80100094(arg0, 0U) + arg1 + 0xA))) == 1;
}

/* extern */

BtIntPtr sukickball_entrypoint_8(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return ((s32 *)func_80100094(arg0, 0U))[arg1 + 4];
}

void sukickball_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    int func_800DC298(f32);
    void func_800C4140(u32, f32 *, u32);
    struct KickballData {
        f32 timers[2];
        u8 pad8[0x18];
        s32 scores[4];
        u8 pad30[9];
        u8 mode;
    } *data;
    s32 sound;

    data = func_80100094(arg0, 0);
    sound = 0;
    if ((s32)arg0->unk70_10 == 4) {
        switch (arg2) {
            case 1:
                data->scores[arg1] += 2;
                if ((arg1 == 0 && data->mode != 4) ||
                    (data->mode == 4 && func_800DC298(0.5f))) {
                    sound = 2;
                } else {
                    sound = 1;
                }
                break;
            case 5:
                data->scores[arg1] += 4;
                if ((arg1 == 0 && data->mode != 4) ||
                    (data->mode == 4 && func_800DC298(0.5f))) {
                    sound = 2;
                } else {
                    sound = 1;
                }
                break;
            case 2:
                data->scores[arg1] -= 1;
                if (data->scores[arg1] < 0) {
                    data->scores[arg1] = 0;
                }
                if ((arg1 == 0 && data->mode != 4) ||
                    (data->mode == 4 && func_800DC298(0.5f))) {
                    sound = 1;
                } else {
                    sound = 2;
                }
                break;
            case 4:
                data->scores[arg1] -= 2;
                if (data->scores[arg1] < 0) {
                    data->scores[arg1] = 0;
                }
                if ((arg1 == 0 && data->mode != 4) ||
                    (data->mode == 4 && func_800DC298(0.5f))) {
                    sound = 1;
                } else {
                    sound = 2;
                }
                break;
        }
        switch (sound) {
            case 1:
                if (data->timers[0] <= 0.0f) {
                    func_800C4140(0x7FFF453A, arg0->position, 0x3E800640);
                    data->timers[0] = 1.0f;
                }
                break;
            case 2:
                if (data->timers[1] <= 0.0f) {
                    func_800C4140(0x7FFF453B, arg0->position, 0x3E800640);
                    data->timers[1] = 1.0f;
                }
                break;
        }
    }
}

/* extern */
void sukickball_entrypoint_10(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + arg1 + 0x34)) = (s8)arg2;
}

/* extern */

void sukickball_entrypoint_11(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)func_80100094(arg0, 0U) + arg1 + 0x34)) = 0;
}

/* extern */

u8 sukickball_entrypoint_12(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    return ((u8 *)func_80100094(arg0, 0))[arg1 + 0x34];
}

s32 sukickball_entrypoint_13(f32 *arg0, f32 *arg1, f32 arg2) {
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    int func_800F0064(f32 *, f32, f32 *);

    extern struct kickball_vector D_80801228_sukickball;
    struct kickball_vector sp4C;
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;

    if (func_800F0064(arg0, arg2, arg1) != 0) {
        sp4C = D_80801228_sukickball;
        sp30 = arg1[1];
        sp2C = arg0[1];
        func_800EE7F8(sp40, arg0);
        func_800EE7F8(sp34, arg1);
        if (arg1[0] == arg0[0] && arg1[2] == arg0[2]) {
            arg1[0] = func_800DC178(-5.0f, 5.0f) + arg1[0];
            arg1[2] = func_800DC178(-5.0f, 5.0f) + arg1[2];
        }
        sp4C.v[0] = arg0[0] - arg1[0];
        sp4C.v[1] = arg0[1] - arg1[1];
        sp4C.v[2] = arg0[2] - arg1[2];
        func_800EF368(sp4C.v, arg2 * 1.1f);
        func_800EFB24(arg1, sp40, sp4C.v);
        func_800EE780(arg0, sp34, sp4C.v);
        arg1[1] = sp30;
        arg0[1] = sp2C;
        return 1;
    }
    return 0;
}

void sukickball_entrypoint_14(Actor *arg0) {
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78(Actor *, void *);
    f32 sukickball_entrypoint_15(s32);

    arg0->unk54 = func_80102D78(arg0, arg0->actorData);
    if (arg0->unk70_10 == 3) {
        arg0->unk54 = sukickball_entrypoint_15(arg0->unk6C_0);
    }
    if (func_80102CF4(arg0, 0x41000000) == 0) {
        func_80102B2C(arg0, 8.0f);
    }
}

f32 sukickball_entrypoint_15(s32 arg0) {
    extern f32 D_80801234_sukickball[];
    return ((f32 *)&D_80801234_sukickball)[arg0];
}

void sukickball_entrypoint_16(s32 arg0, f32 *arg1) {
    switch (arg0) {
    case 0:
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        arg1[0] = 720.0f;
        return;
    case 2:
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = 720.0f;
        return;
    case 1:
        arg1[1] = 0.0f;
        arg1[2] = 0.0f;
        arg1[0] = -720.0f;
        return;
    case 3:
        arg1[0] = 0.0f;
        arg1[1] = 0.0f;
        arg1[2] = -720.0f;
        return;
    }
}

/* extern */

void sukickball_entrypoint_17(Actor *arg0) {
    void func_800F8294(BtIntPtr, f32 *);
    void *func_80100094(Actor *, u32);
    void sukickball_entrypoint_16(s32, f32 *);
    f64 pad;
    f32 sp2C[3];
    s32 var_s0;

    if (((u8 *)func_80100094(arg0, 0U))[0x39] != 3) {
        for (var_s0 = 0; var_s0 != 4; var_s0++) {
            if (sukickball_entrypoint_6(arg0, var_s0) != 0) {
                sukickball_entrypoint_16(var_s0, sp2C);
                func_800F8294(var_s0, sp2C);
            }
        }
    }
}

void sukickball_entrypoint_18(Actor *arg0) {
    void func_800D2748(s32, s32);
    void *func_80100094(Actor *, u32);

    switch (((u8 *)func_80100094(arg0, 0U))[0x39]) {
    case 0:
    case 1:
    case 2:
        func_800D2748(0xC3, 0x2D);
        break;
    case 4:
        func_800D2748(0xC3, 0x1F);
        break;
    }
    func_800D2748(0xC4, 0x20);
    func_800D2748(0xC5, 0x21);
    func_800D2748(0xC6, 0x22);
}    typedef struct { u8 pad0[0x38]; u8 unk38; } Objkickball_sukickball_entrypoint_19_temp_s2; /* offsets.py genstruct: fields from raw offsets on temp_s2; rename once understood */

/* extern */

void sukickball_entrypoint_19(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800D24E8(s32, s32, s32);
    void func_800D2770(s32, s32);
    s32 func_800D28A0(s32);
    void *func_80100094(Actor *, u32);
    s32 var_s0;
    s32 var_s1;
    u8 *temp_s2;

    temp_s2 = func_80100094(arg0, 0U);
    var_s0 = 0;
    if (arg2 > 0) {
        do {
            var_s1 = var_s0 + 0xC3;
            if ((((Objkickball_sukickball_entrypoint_19_temp_s2 *)temp_s2)->unk38) == 0) {
                var_s1 = var_s0 + 0xC3;
                func_800D2770(var_s1, 0);
            } else {
                func_800D24E8(var_s1, ((s32 *)temp_s2)[var_s0 + 8], 0);
            }
            if ((arg1 != 0) && ((*(u8 *)((s8 *)((temp_s2 + var_s0)) + (0x30))) != 0)) {
                func_800D28A0(var_s1);
            }
            var_s0 += 1;
        } while (var_s0 != arg2);
    }
    (((Objkickball_sukickball_entrypoint_19_temp_s2 *)temp_s2)->unk38) = 1U;
}
/* data_to_c.py: from asm/data/overlays/su/kickball.data.s */
struct kickball_vector D_80801200_sukickball BT_DATA(4, overlays_su_kickball, 0x0) = { { 0.0f, 0.0f, 0.0f } };
struct kickball_vector D_8080120C_sukickball BT_DATA(4, overlays_su_kickball, 0xC) = { { 0.0f, 0.0f, 0.0f } };
s32 D_80801218_sukickball [4] BT_DATA(4, overlays_su_kickball, 0x18) = { 4, 2, 1, 3 };
struct kickball_vector D_80801228_sukickball BT_DATA(4, overlays_su_kickball, 0x28) = { { 0.0f, 0.0f, 0.0f } };
f32 D_80801234_sukickball [7] BT_DATA(4, overlays_su_kickball, 0x34) = { 270.0f, 90.0f, 180.0f, 0.0f, 0.0f, 0.0f, 0.0f };
