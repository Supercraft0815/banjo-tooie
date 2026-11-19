#include "ch/transparentfish.h"

void func_80800348_chtransparentfish(Actor *actor);
void func_80105834(Actor *);
void func_80800690_chtransparentfish(Actor *arg0, void *arg1);
void func_80800B30_chtransparentfish(s32 arg0);
OSThread *func_80108ED0(void);
void func_808002B8_chtransparentfish(Actor *arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_8080078C_chtransparentfish(Actor *arg0, s32 arg1, s32 arg2);
u32 D_80800F80_chtransparentfish[] = {
    0x00010000, 0x00020000, 0x00020000, 0x00000000,
    0x00030000
};

u32 D_80800F94_chtransparentfish[] = {
    0x00000000, 0x00000000, 0x40200000, 0x01580001,
    0x40200000, 0x01580001, 0x40200000, 0x01580001
};

s32 D_80800FB4_chtransparentfish[][3] = {
    { 0, 0, 100 },
    { 543, -30, 100 },
    { 310, -50, 100 },
    { 456, -50, 100 },
    { 457, -50, 100 },
    { 458, -50, 100 },
    { 459, -50, 100 },
    { 460, -70, 90 },
    { 462, -70, 100 },
    { 463, -70, 100 },
    { 471, -50, 100 },
    { 472, -70, 70 },
    { 544, -50, 90 }
};

s32 D_80801050_chtransparentfish[] = {
    0x001D09D9, 0x00161004, 0x001B0096, 0x00960007,
    0x0001000E, 0x000A000A, 0x00150000, 0x00CC002B,
    0x03000300, 0x0020FFFF, 0xFEFF0022, 0x000C0017,
    0x000C0017, 0x002F0040, 0x00400000, 0x00000019,
    0x00000033, 0x00000000
};

BtFnWord D_80801098_chtransparentfish[] = {
    0x012D0295, 0x06D90001, (BtFnWord)D_80800F94_chtransparentfish, (BtFnWord)func_80800348_chtransparentfish,
    (BtFnWord)func_80105834, (BtFnWord)func_80800690_chtransparentfish, 0x13880000, 0x00000000,
    0x00000000, 0x00220123, (BtFnWord)func_80800B30_chtransparentfish, (BtFnWord)func_80108ED0,
    0x00080000, (BtFnWord)func_808002B8_chtransparentfish, (BtFnWord)func_80107C2C, 0x8040500F,
    (BtFnWord)func_8080078C_chtransparentfish, (BtFnWord)D_80800F80_chtransparentfish
};

void func_80800000_chtransparentfish(Actor *arg0) {
    struct FishNodeIndices {
        u8 prefix[0x70];
        BT_BITFIELD_ORDER(u32 sector : 7, u32 flags : 4);
        BT_BITFIELD_ORDER(u32 unused : 15, u32 node : 6);
        BT_BITFIELD_ORDER(u32 node : 6, u32 unused : 15);
        BT_BITFIELD_ORDER(u32 flags : 4, u32 sector : 7);
    };
    struct FishData {
        f32 unused[3];
        f32 speed;
        f32 unused2[3];
        f32 turnSpeed;
    };
    s32 _subaddieDll_entrypoint_11(void *, s32, s32);
    void *func_800CC63C(s32, s32);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    void func_80102924(void *, f32);
    void func_80102950(void *, f32);
    s32 func_80102CCC(Actor *);
    f32 func_80102D78(Actor *, f32 *);
    f32 sp2C;
    s32 sp28;
    f32 *sp24;
    f32 y;
    f32 height;
    f32 radius;

    sp24 = func_800CC63C(((struct FishNodeIndices *)arg0)->sector - 1,
                        ((struct FishNodeIndices *)arg0)->node - 1);
    y = arg0->position[1];
    height = sp24[1];
    radius = ((s16 *)sp24)[7];
    if (height + radius <= y) {
        sp28 = 1;
        func_80102950(arg0, 355.0f);
    } else if (y <= height - radius) {
        sp28 = 1;
        func_80102950(arg0, 5.0f);
    } else {
        sp28 = 0;
    }
    if (_subaddieDll_entrypoint_11(arg0, (s32)arg0->unk54,
            (s32)(arg0->scale * 3.0f * ((struct FishData *)arg0->actorData)->speed)) == 0) {
        func_80102924(arg0, func_80102D78(arg0, sp24));
        arg0->unk58 = func_800DC178(1.0f, 3.0f);
        return;
    }
    arg0->unk58 -= func_800D8FF8();
    if (0.0f >= arg0->unk58) {
        arg0->unk58 = func_800DC178(1.0f, 3.0f);
        ((struct FishData *)arg0->actorData)->turnSpeed = func_800DC178(105.0f, 150.0f);
        if (sp28 == 0) {
            func_80102950(arg0, func_800DC178(-8.333333f, 8.333333f));
        }
        sp2C = func_800DC178(-35.0f, 35.0f);
        if (func_80102CCC(arg0) != 0) {
            func_80102924(arg0, arg0->rotation[1] + sp2C);
        }
    }
}

void func_80800204_chtransparentfish(Actor *arg0) {
    f32 _subaddiejoy_entrypoint_3();
    void func_80102BAC(Actor *, f32, f32, f32);
    s32 func_8010BA80(Actor *, s32, s32);
    f32 speed;

    speed = _subaddiejoy_entrypoint_3() * 300.0f;
    func_80102BAC(arg0, 0.5f, 0.5, 5.0f);
    if (((f32 *)arg0->actorData)[3] <= speed) {
        ((f32 *)arg0->actorData)[3] = speed;
    } else {
        ((f32 *)arg0->actorData)[3] -= ((f32 *)arg0->actorData)[3] * 0.02f;
        if (((f32 *)arg0->actorData)[3] < 30.0f) {
            ((f32 *)arg0->actorData)[3] = 0.0f;
        }
    }
    func_8010BA80(arg0, 0x200006, 0x20);
}

/* extern */

void func_808002B8_chtransparentfish(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    s32 func_80800B60_chtransparentfish();
    s32 func_80800EE0_chtransparentfish(s32);
    if (func_800DA298(FLAG3_9F4_UNK) == 0) {
        func_800DA544(FLAG3_9F4_UNK);
        func_80800B60_chtransparentfish();
    }
    arg0->unk6C_0 = func_80800EE0_chtransparentfish(arg0->pad6C_21);
    ((f32 *)arg0->actorData)[3] = 150.0f;
    ((f32 *)arg0->actorData)[7] = 150.0f;
    ((f32 *)arg0->actorData)[5] = (f32) _subaddiesect_entrypoint_1(arg0);
}

void func_80800348_chtransparentfish(Actor *actor)
{
    s32 _subaddiesect_entrypoint_0(Actor *arg0, s32 arg1, s32 arg2);
    void func_80800AC4_chtransparentfish(Actor *, f32 *, s32);
    u32 func_800F54E4(void);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
    s32 func_800F690C(BtIntPtr);
    f32 func_80103EAC(Actor *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 _sudeflect_entrypoint_0(f32 *, f32, f32, s32);
    s32 func_80101E14(Actor *, f32);
    s32 func_80102CCC(Actor *);
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, u32 *, BtIntPtr, f32, s32 *);
    void func_800BA994(void *emitter, s16 yaw_min, s16 pitch_min, s16 speed_min, s16 yaw_max, s16 pitch_max, s16 speed_max);
    void func_800BA22C(BtIntPtr, s32);
    void func_80800204_chtransparentfish(Actor *);
    void func_80800000_chtransparentfish(Actor *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101CDC(Actor *, f32);
    void func_80102BAC(Actor *, f32, f32, f32);
    void func_80102C58(void *, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_8010BA80(Actor *, s32, s32);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F0DC0(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    struct TransparentFishFlags {
        BT_BITFIELD_ORDER(u32 unused : 2, u32 : 29);
        BT_BITFIELD_ORDER(u32 active : 1, u32 active : 1; u32 unused : 2);
    };
    s32 flag;
    f32 position[3];
    f32 height;
    f32 factor;
    BtIntPtr emitter;

    _subaddiesect_entrypoint_0(actor, (s32)((f32 *)actor->actorData)[5], 11);
    func_80800AC4_chtransparentfish(actor, 0, actor->unk7C_12);
    if (func_800F52B8(func_800F54E4(), actor->unk0) != 20) {
        flag = func_800F690C(func_800F54E4());
        height = func_80103EAC(actor);
        factor = flag ? 0.5f : 0.25f;
        func_800EFA4C(position, actor->position[0], actor->position[1] + factor * height, actor->position[2]);
        factor = flag ? 0.75f : 0.5f;
        _sudeflect_entrypoint_0(position, 0.0f, factor * height, 30);
    }
    if (func_80101E14(actor, 0.01f) && func_80102CCC(actor)) {
        emitter = func_800B53A4(10);
        func_800BABB8(emitter, actor->actorData, 0, actor->scale, D_80801050_chtransparentfish);
        func_800BA994(emitter, (s16)actor->rotation[0], (s16)(actor->rotation[1] - 35.0f),
            (s16)(((f32 *)actor->actorData)[3] * 1.1f), (s16)actor->rotation[0],
            (s32)(actor->rotation[1] + 35.0f), (s32)(((f32 *)actor->actorData)[3] * 2.0f));
        func_800BA22C(emitter, 10);
    }
    if (actor->unk70_10 == 1) {
        if (((struct TransparentFishFlags *)((u8 *)actor + 0x64))->active) {
            func_80800204_chtransparentfish(actor);
            func_80101CDC(actor, func_800F10B4(((f32 *)actor->actorData)[3], 0.0f, 300.0f, 3.0f, 1.5f));
        } else {
            func_80800000_chtransparentfish(actor);
            func_80102BAC(actor, 0.05f, 0.05f, 4.0f);
            func_80102C58(actor, 0.05f, 0.01f, 0.5f);
            ((f32 *)actor->actorData)[3] = func_800F15F8(((f32 *)actor->actorData)[3], ((f32 *)actor->actorData)[7], 2.0f);
            if (func_8010BA80(actor, 38, 16)) {
                actor->unk54 += 10.0f;
            }
        }
        ((f32 *)actor->actorData)[4] = func_800F0DC0(func_800F1DCC(actor->rotation[1], actor->unk54) * 0.5f, 15.0f);
        actor->rotation[2] = func_800F1FF0(actor->rotation[2], ((f32 *)actor->actorData)[4], 0.01f, 0.005f, 0.1f);
    }
}

void func_80800690_chtransparentfish(Actor *arg0, void *arg1) {
    void func_800DBEFC(void *, s32, f32 *);
    void func_80101870(Actor *, void *);
    OSThread *func_80104130(void);
    void func_80800AC4_chtransparentfish(Actor *, f32 *, s32);
    f32 position[3];
    s32 value;
    u32 index;

    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC(func_80104130(), 5, (f32 *)arg0->actorData);
        index = arg0->unk6C_0;
        value = (index != 0 && index < 13U) ? D_80800FB4_chtransparentfish[index][0] : 0;
        if (value != 0) {
            func_800DBEFC(func_80104130(), 4, position);
            index = arg0->unk6C_0;
            value = (index != 0 && index < 13U) ? D_80800FB4_chtransparentfish[index][1] : 0;
            position[1] += (f32)value;
            func_80800AC4_chtransparentfish(arg0, position, 1);
        }
    }
}

s32 func_8080078C_chtransparentfish(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddielink_entrypoint_1(u8 *arg0, u8 *arg1);
    s32 _subaddielink_entrypoint_3(s32 *arg0);
    s32 func_800D0B68(u32 arg0, u32 arg1);
    BtIntPtr func_800D10D4(u32 arg0, u32 arg1, f32 *arg2, s32 arg3, BtIntPtr arg4);
    void * func_80100094(Actor *arg0, u32 arg1);
    void func_80102424(Actor *arg0, s32 arg1);
    Actor * func_80106790(Unk80132ED0 *arg0);
    s32 func_80107070(Actor *arg0, u32 arg1);
    Actor * func_80108474(u32 arg0, f32 *arg1, s32 arg2);
    void func_80108B04(s32 *arg0, s32 arg1);
    void func_80800AC4_chtransparentfish(Actor *arg0, f32 *arg1, s32 arg2);
    struct FishFlags {
        u8 prefix[0x64];
        BT_BITFIELD_ORDER(u32 visible : 1, u32 rest64 : 31);
        BT_BITFIELD_ORDER(u32 rest64 : 31, u32 visible : 1);
        u32 word68;
        u32 word6C;
        BT_BITFIELD_ORDER(u32 upper70 : 15, u32 lower70 : 16);
        u32 flag70_16 : 1;
        BT_BITFIELD_ORDER(u32 lower70 : 16, u32 upper70 : 15);
        BT_BITFIELD_ORDER(u32 upper74 : 11, char : 0);
        BT_BITFIELD_ORDER(u32 flag74_20 : 1, u32 lower74 : 5);
        BT_BITFIELD_ORDER(u32 middle74 : 14, u32 flag74_5 : 1);
        BT_BITFIELD_ORDER(u32 flag74_5 : 1, u32 middle74 : 14);
        BT_BITFIELD_ORDER(u32 lower74 : 5, u32 flag74_20 : 1; u32 upper74 : 11);
    };
    Actor *spawned;
    Unk80132ED0 *marker;
    u32 index;
    s32 value;
    f32 *position;
    switch ((int)arg1) {
    case 0x3D:
        marker = arg0->unk0;
        index = arg0->unk6C_0;
        value = (index != 0 && index < 13U) ? D_80800FB4_chtransparentfish[index][0] : 0;
        if (value == 0x21F) {
            if (func_800D0B68(0x26, 1) == 0) {
                spawned = func_80106790((Unk80132ED0 *)func_800D10D4(0x26, 1, arg0->position, 3, (BtIntPtr)arg0->unk0));
            }
            else {
                return 0;
            }
        }
        else {
            value = (index != 0 && index < 13U) ? D_80800FB4_chtransparentfish[index][0] : 0;
            if (value == 0x136) {
                if (func_800D0B68(0xB, 4) == 0) {
                    spawned = func_80106790((Unk80132ED0 *)func_800D10D4(0xB, 4, arg0->position, 3, (BtIntPtr)arg0->unk0));
                }
                else {
                    return 0;
                }
            }
            else {
                value = (index != 0 && index < 13U) ? D_80800FB4_chtransparentfish[index][0] : 0;
                position = arg0->position;
                if (value == 0x220) {
                    if (func_800D0B68(0xA, 2) == 0) {
                        spawned = func_80106790((Unk80132ED0 *)func_800D10D4(0xA, 2, arg0->position, 3, (BtIntPtr)arg0->unk0));
                    }
                    else {
                        return 0;
                    }
                }
                else {
                    value = (index != 0 && index < 13U) ? D_80800FB4_chtransparentfish[index][0] : 0;
                    spawned = func_80108474(value, position, 0);
                }
            }
        }
        ((struct FishFlags *)spawned)->flag74_5 = 0;
        ((struct FishFlags *)spawned)->flag74_20 = 0;
        ((struct FishFlags *)spawned)->flag70_16 = 0;
        ((struct FishFlags *)spawned)->visible = 0;
        arg0 = func_80106790(marker);
        _subaddielink_entrypoint_1(func_80100094(arg0, 0), (u8 *)spawned->unk0);
        func_80800AC4_chtransparentfish(arg0, arg0->position, 0);
        index = arg0->unk6C_0;
        if (index != 0 && index < 13U) {
            spawned->scale = ((f32)D_80800FB4_chtransparentfish[index][2] / 100.0f) * arg0->scale;
        }
        else {
            spawned->scale = 0.0f;
        }
        return 1;
    case 1:
        func_80102424(arg0, 1);
        return 1;
    case 2:
        func_80107070(arg0, 1);
        return 1;
    case 0x95:
        if (_subaddielink_entrypoint_3(func_80100094(arg0, 0)) == 0) {
            func_80108B04((s32 *)arg0, 0);
        }
        return 1;
    default:
        return 0;
    }
}

void func_80800AC4_chtransparentfish(Actor *arg0, f32 *arg1, s32 arg2) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *temp_v0;
    Actor *var_v1;
    s32 pad;

    temp_v0 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
    var_v1 = temp_v0;
    if (temp_v0 != NULL) {
        if (arg1 != 0) {
            func_800EE7F8(temp_v0->position, arg1);
            var_v1 = temp_v0;
        }
        var_v1->unk64_16 = arg2;
    }
}

void func_80800B30_chtransparentfish(s32 arg0)
{
    func_800DA524(FLAG3_9F4_UNK);
}

OSThread *chtransparentfish_entrypoint_0(void)
{
    return (OSThread *) D_80801098_chtransparentfish;
}

typedef struct {
    s32 id;
    s32 value;
    s32 assigned;
} FishEntry;

extern FishEntry B_808010E0_chtransparentfish[20];

s32 func_80800B60_chtransparentfish(void) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _gspropctrl_entrypoint_8(Prop *);
    s32 func_800DC090(void);
    s32 func_800DC128(s32, s32);
    void func_800DC324(s32);
    s32 func_80800E10_chtransparentfish(s32);
    typedef struct {
        s32 header[4];
        BT_BITFIELD_ORDER(u32 id : 11, u32 flags : 21);
        BT_BITFIELD_ORDER(u32 flags : 21, u32 id : 11);
    } FishProp;
    s32 count;
    s32 i;
    s32 j;
    s32 rnd;
    s32 seed;
    Prop *props[20];
    s32 temp;
    s32 k;
    s32 n; BT_NATIVE_ONLY(s32 result;)

    for (k = 0; k < 20; k++) {
        B_808010E0_chtransparentfish[k].id = 0;
        B_808010E0_chtransparentfish[k].value = -1;
        B_808010E0_chtransparentfish[k].assigned = -1;
        k++; k--;
    }
    count = _gccubesearch_entrypoint_9(0x295, props, 20);
    for (i = 0; i < count; i++) {
        B_808010E0_chtransparentfish[i].id = ((FishProp *)props[i])->id;
        B_808010E0_chtransparentfish[i].value = _gspropctrl_entrypoint_8(props[i]) - 50;
    }
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            if (B_808010E0_chtransparentfish[i].id < B_808010E0_chtransparentfish[j].id) {
                temp = B_808010E0_chtransparentfish[j].id;
                B_808010E0_chtransparentfish[j].id = B_808010E0_chtransparentfish[i].id;
                B_808010E0_chtransparentfish[i].id = temp;
            }
        }
    }
    if (func_800DA298(FLAG2_6C0_UNK)) {
        rnd = func_800DA564(FLAG2_6C1_UNK, 8);
    } else {
        rnd = func_800DC128(0, 256);
        func_800DA7A8(FLAG2_6C1_UNK, rnd, 8);
        func_800DA544(FLAG2_6C0_UNK);
    }
    n = 0;
    seed = func_800DC090();
    func_800DC324(rnd);
    BT_IDO_ONLY(while (!func_80800E10_chtransparentfish(count))) BT_NATIVE_ONLY(while (!(result = func_80800E10_chtransparentfish(count)))) {
        k = func_800DC128(0, count);
        if (B_808010E0_chtransparentfish[k].assigned == -1) {
            B_808010E0_chtransparentfish[k].assigned = B_808010E0_chtransparentfish[n].value;
            n++;
        }
    }
    func_800DC324(seed); BT_NATIVE_ONLY(return result;)
}

s32 func_80800E10_chtransparentfish(s32 arg0) {
    s32 result = 1;
    s32 i;

    for (i = 0; i < arg0; i++) {
        result &= B_808010E0_chtransparentfish[i].assigned != -1;
    }
    return result;
}

s32 func_80800EE0_chtransparentfish(s32 arg0) {
    s32 i;

    for (i = 0; i < 20; i++) {
        if (arg0 == B_808010E0_chtransparentfish[i].id) {
            return B_808010E0_chtransparentfish[i].assigned;
        }
    }
    return 0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
FishEntry B_808010E0_chtransparentfish [ 20 ] BT_DATA(16, bss_ch_transparentfish, 0x0);
#endif
