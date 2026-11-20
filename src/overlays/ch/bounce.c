#include "common.h"

void *func_80100094(Actor *, u32);

struct BounceConfig {
    u16 flags;
    s16 actorId;
    s16 count;
    s16 field6;
    f32 field8;
    s16 fieldC;
    s16 xBase;
    s16 xRange;
    s16 speed;
    s16 speedRange;
    s16 zBase;
    s16 zRange;
    u8 pad1A[2];
    f32 restitution;
    f32 unk20;
};

void chbounce_entrypoint_0(void) {
    extern f32 D_8012716C;
    f32 *temp_v0 = (f32 *)(BtUIntPtr)((u8 *)&D_8012716C + 28);
    temp_v0[0] = 0.0f;
    temp_v0[1] = 1.0f;
    temp_v0[2] = 0.0;
}

void chbounce_entrypoint_1(void) {
}    typedef struct { u8 pad0[0x1C]; f32 unk1C; u8 pad20[0x4]; f32 unk24; } Objbounce_D_8012716C; /* offsets.py genstruct: fields from raw offsets on &D_8012716C; rename once understood */

void chbounce_entrypoint_2(f32 arg0) {
    extern f32 D_8012716C;
    ((Objbounce_D_8012716C *)&D_8012716C)->unk1C = arg0;
}

void chbounce_entrypoint_3(f32 arg0) {
    extern f32 D_8012716C;
    ((Objbounce_D_8012716C *)&D_8012716C)->unk24 = arg0;
}

void chbounce_entrypoint_4(Actor *arg0, s32 *arg1) {
    void func_800EE84C(f32 dst[3], s32 src[3]);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(u32 *) chbounce_entrypoint_6(Actor *arg0, BtUIntPtr arg1);
    f32 position[3];

    func_800EE84C(position, arg1);
    chbounce_entrypoint_6(arg0, (BtUIntPtr) position);
}

/* extern */

s32 func_80800078_chbounce(void) {
    u32 _gclevel_entrypoint_3(u32);
    s32 func_800D3E40(s32);
    s32 func_800DA9E4(s32, s32);
    f32 func_800DC0C0(void);
    s32 func_800EA068(s32);
    f32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800DC0C0();
    sp20 = _gclevel_entrypoint_3(0x10);
    sp1C = _gclevel_entrypoint_3(0x12);
    if (func_800D3E40(9) != 0) {
        return 0x229;
    }
    if (func_800EA068(0x8000) != 0) {
        return 0x229;
    }
    if ((sp20 == 0) && (sp1C == 0)) {
        return 0x229;
    }
    if (sp20 != 0) {
        if (func_800DA9E4(0x31, 1) == 0) {
            return 0x197;
        }
        if (sp24 < 0.049987793f) {
            return 0x197;
        }
        goto block_12;
    }
block_12:
    if (sp1C != 0) {
        if (func_800DA9E4(0x30, 1) == 0) {
            return 0x196;
        }
        if (sp24 < 0.049987793f) {
            return 0x196;
        }
        goto block_17;
    }
block_17:
    return 0x229;
}

u32 *func_80800190_chbounce(Actor *arg0, BtUIntPtr arg1, BtUIntPtr arg2) {
    struct BounceGlobals {
        f32 angle;
        f32 scale;
        f32 yaw;
    };
    struct BounceBits {
        u8 pad[0x24];
        BT_BITFIELD_ORDER(u8 flag24 : 1, u8 type : 7);
        BT_BITFIELD_ORDER(u8 type : 7, u8 flag24 : 1);
        BT_BITFIELD_ORDER(u8 flag25 : 1, char : 0);
        u8 state : 7;
        BT_BITFIELD_ORDER(u8 mode : 3, u8 flag25 : 1);
        BT_BITFIELD_ORDER(u8 rest26 : 5, char : 0; u8 rest26 : 5; u8 mode : 3);
    };
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(void *, f32, f32);
    void func_800EF934(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80105494(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_80108474(s32, f32 *, s32);
    extern f32 D_8012716C;
    extern struct BounceConfig D_80800FE0_chbounce[];
    extern f32 D_808014A8_chbounce;
    struct BounceConfig *loopConfig;
    f32 yRandom;
    f32 xRandom;
    f32 zRandom;
    f32 radialSpeed;
    s32 actorId;
    u8 type;
    s32 i;
    Unk80132ED0 *marker;
    struct BounceGlobals *globals;
    register u8 *data;
    register u8 *vector;
    u8 *position;
    struct BounceConfig *config;
    Actor *actor;
    u8 *extra;
    f32 *base;

    config = &D_80800FE0_chbounce[(BtIntPtr) arg0];
    loopConfig = config;
    actor = 0;
    if (arg2 != 0) {
        marker = *(Unk80132ED0 **) arg2;
    } else {
        marker = 0;
    }
    base = &D_8012716C;
    i = 0;
    if (loopConfig->count > 0) {
        globals = (void *) (base + 7);
        do {
            config = loopConfig;
            (&D_8012716C)[7] = globals->angle + (360.0f / config->count);
            if (arg1) {
            }
            while (globals->angle >= 360.0f) {
                globals->angle -= 360.0f;
            }

            if ((i == 0) && (marker != 0)) {
                actor = func_80106790(marker);
            } else {
                actorId = config->actorId;
                if (actorId != 0x229) {
                    actor = func_80108474(actorId, (f32 *) arg1, 0);
                } else {
                    actorId = func_80800078_chbounce();
                    actor = func_80108474(actorId, (f32 *) arg1, 0);
                }
            }
            if (actor == 0) {
                goto next_actor;
            }
            {
                type = (BtIntPtr) arg0;
                func_80100074(actor, 2, 0x34);
                data = func_80100094(actor, 2);
                position = (u8 *) actor + 4;
                ((struct { u8 pad[0x7B]; BT_BITFIELD_ORDER(u8 a : 4, u8 b : 3); u8 f : 1; BT_BITFIELD_ORDER(u8 b : 3, u8 a : 4); } *) actor)->f = 1;
                ((struct BounceBits *) data)->type = type;
                ((struct BounceBits *) data)->mode = 1;
                ((struct BounceBits *) data)->state = 1;
                *(s16 *) (data + 0x28) = config->field6;
                *(f32 *) (data + 0x2C) = config->field8;
                *(s16 *) (data + 0x2A) = config->fieldC;
                func_800EE7F8((f32 *) data, (f32 *) position);
                func_800EE7F8((f32 *) position, (f32 *) data);
                if (1.0f != globals->scale) {
                    vector = data + 0xC;
                    func_800EFA4C((f32 *) vector, config->xBase * globals->scale, func_800DC178(0.0f, config->speedRange) + config->speed, config->zBase * globals->scale);
                    globals->scale = 1.0f;
                } else {
                    xRandom = func_800DC178(0.0f, config->xRange);
                    yRandom = func_800DC178(0.0f, config->speedRange);
                    vector = data + 0xC;
                    func_800EFA4C((f32 *) vector, (xRandom * 1.0f) + config->xBase, (yRandom * 1.0f) + config->speed, func_800DC178(0.0f, config->zRange) + config->zBase);
                }
                if (config->flags & 0x400) {
                    radialSpeed = func_800DC178(0.0f, config->xRange) + config->xBase;
                    func_800EEB9C(vector, globals->yaw, radialSpeed);
                    *(f32 *) (data + 0x10) = func_800DC178(0.0f, config->speedRange) + config->speed;
                } else {
                    zRandom = D_808014A8_chbounce;
                    zRandom *= -1.0f;
                    *(f32 *) (data + 0x1C) = zRandom;
                    D_808014A8_chbounce = zRandom;
                    if (config->flags & 0x20) {
                        yRandom = config->unk20;
                    } else {
                        yRandom = func_800DC178(0.0f, 360.0f);
                        if (!marker) {
                        }
                    }
                    *(f32 *) (data + 0x18) = yRandom;
                    actor->rotation[1] = yRandom;
                    func_800EF934(vector, vector, actor->rotation[1] + globals->angle);
                }
                *(f32 *) (data + 0x20) = 0.0f;
                ((struct BounceBits *) data)->flag24 = 0;
                ((struct BounceBits *) data)->flag25 = 1;
                *(u16 *) (data + 0x32) = config->flags;
                if (config->flags & 0x200) {
                    extra = func_80105494(actor);
                    if (extra != 0) {
                        *(f32 *) (extra + 0x1C) = *(f32 *) (data + 4);
                    }
                }
            }
        next_actor:
            i++;
        } while (i < loopConfig->count);
    }
    return (u32 *) actor;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(u32 *) chbounce_entrypoint_5(BtIntPtr arg0, u8 *arg1) {
    extern struct BounceConfig D_80800FE0_chbounce[];
    u32* func_80800190_chbounce(Actor*, BtUIntPtr, BtUIntPtr);
    D_80800FE0_chbounce[arg0].unk20 = *(f32 *)(arg1 + 0x48);
    BT_NATIVE_ONLY(return) func_80800190_chbounce((Actor *)arg0, (BtUIntPtr)(arg1 + 4), (BtUIntPtr)arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(u32 *) chbounce_entrypoint_6(Actor *arg0, BtUIntPtr arg1) {
    u32* func_80800190_chbounce(Actor*, BtUIntPtr, BtUIntPtr);
    BT_NATIVE_ONLY(return) func_80800190_chbounce(arg0, arg1, 0U);
}

BtIntPtr chbounce_entrypoint_7(BtIntPtr arg0, f32 *arg1, s32 arg2) {
    extern struct BounceConfig D_80800FE0_chbounce[];
    u32 *func_80800190_chbounce(Actor *, BtUIntPtr, BtUIntPtr);
    Actor *actor;
    struct {
        u8 pad[0x28];
        s16 sound;
        s16 volume;
        f32 pitch;
    } *data;

    D_80800FE0_chbounce[arg0].actorId = arg2;
    actor = (Actor *)func_80800190_chbounce((Actor *)arg0, (BtUIntPtr)arg1, 0U);
    data = func_80100094(actor, 2U);
    switch (arg2) {
        case 0x1C9:
        case 0x1CA:
        case 0x1CB:
        case 0x1CC:
        case 0x1F4:
            data->sound = 0x404;
            data->pitch = 1.8f;
            data->volume = 0x4E20;
            break;
        case 0x136:
        case 0x3C6:
            data->sound = 0x404;
            data->pitch = 1.8f;
            data->volume = 0x4E20;
            break;
        case 0x21F:
            break;
        case 0x513:
            data->sound = 0x3E9;
            data->pitch = 1.0f;
            data->volume = 0x3E80;
            break;
        case 0x517:
            data->sound = 0x53D;
            data->pitch = 1.6f;
            data->volume = 0x3E80;
            break;
    }
    return (BtIntPtr)actor;
}

BtIntPtr func_808007B8_chbounce(Actor *arg0, f32 *arg1, f32 *arg2, f32 *arg3, s32 arg4) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    void *func_800BF0E0(f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,u32 mode);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void *func_800C6B78(f32 *, f32 *, f32, f32 *, s32, u32);
    s32 func_800CC338(f32 *, s32, s32);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    u32 func_8010A654(void ***, s32);
    u32 func_8010A698(void ***);
    BtIntPtr result;
    f32 radius;
    s32 pad[2];
    s32 saved;
    s32 index;
    struct { u8 pad[0x32]; u16 flags; } *data;
    struct {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u32 sector : 7, u32 flags : 4);
        BT_BITFIELD_ORDER(u32 reserved : 15, u32 triangle : 6);
        BT_BITFIELD_ORDER(u32 triangle : 6, u32 reserved : 15);
        BT_BITFIELD_ORDER(u32 flags : 4, u32 sector : 7);
    } *collision = (void *)arg0;

    data = func_80100094(arg0, 2);
    if (data->flags & 0x80) {
        if (arg0->unk70_25 != 0) {
            index = func_800CC338(arg2, arg0->unk70_25 - 1, collision->triangle - 1);
            if (index == -1) {
                func_800EFB24(arg3, arg2, arg1);
                func_800EF2A0(arg3);
                func_800EE7F8(arg2, arg1);
                return 1;
            }
            collision->triangle = index + 1;
        }
    }
    radius = func_800EC708(arg0->unk0) * 0.6666667f;
    arg1[1] += radius;
    arg2[1] += radius;
    if (arg4) {
        result = func_800BF0E0(arg1, arg2, radius, arg3, 3, arg0->unk14);
        if (result == 0) {
            result = (BtIntPtr)func_800BEF00(arg1, arg2, arg3, arg0->unk14);
            if (result != 0) {
                func_800EF04C(arg2, arg3);
            }
        }
    } else {
        saved = func_8010A698(arg0);
        func_8010A654(arg0, 0);
        result = (BtIntPtr)func_800C6B78(arg1, arg2, radius, arg3, 3, arg0->unk14);
        func_8010A654(arg0, saved);
        if (result == 0) {
            result = (BtIntPtr)func_800C6A7C(arg1, arg2, arg3, arg0->unk14);
            if (result != 0) {
                func_800EF04C(arg2, arg3);
            }
        }
    }
    arg1[1] -= radius;
    arg2[1] -= radius;
    return result;
}

void chbounce_entrypoint_8(Actor *arg0) {
    f32 func_800BECCC(void);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    void func_80104580(BT_NATIVE_ONLY(Actor *) BT_IDO_ONLY(void));
    void *func_80105494(Actor *);
    void func_8010A63C(Actor *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    f32 mlAbsF(f32);
    void func_80800F74_chbounce(Actor *);
    struct BounceData {
        f32 position[3];
        f32 velocity[3];
        f32 angle;
        f32 angularVelocity;
        f32 time;
        BT_BITFIELD_ORDER(u32 settled : 1, u32 reserved2 : 13);
        BT_BITFIELD_ORDER(u32 type : 7, u32 state : 3);
        u32 reserved : 8;
        BT_BITFIELD_ORDER(u32 state : 3, u32 type : 7);
        BT_BITFIELD_ORDER(u32 reserved2 : 13, u32 settled : 1);
        s16 sound;
        s16 volume;
        f32 pitch;
        s16 bounces;
        u16 flags;
    };
    extern struct BounceConfig D_80800FE0_chbounce[];
    extern s32 D_808014AC_chbounce[];
    f32 dt;
    struct BounceData *data;
    struct BounceConfig *config;
    f32 previous[3];
    f32 displacement[3];
    f32 normal[3];
    struct { u8 pad[0x1C]; f32 height; } *floor;
    f32 speed;
    f32 factor;

    func_80104580(BT_NATIVE_ONLY(arg0));
    dt = func_800D8FF8();
    data = func_80100094(arg0, 2);
    config = &D_80800FE0_chbounce[data->type];
    switch (data->state) {
        case 1:
            data->time += dt;
            func_800EE7F8(previous, data->position);
            func_800EFA20(displacement, data->velocity, dt);
            func_800EF04C(data->position, displacement);
            if (data->time > 1.2f) {
                data->settled = 1;
            }
            if ((!(config->flags & 0x40) || !(data->time < 1.2f)) &&
                (func_808007B8_chbounce(arg0, previous, data->position, normal, config->flags & 8) ||
                 ((config->flags & 0x200) && data->velocity[1] < -(config->speedRange / 2 + config->speed)))) {
                if (config->flags & 0x204) {
                    func_800EFA4C(normal, 0.0f, 1.0f, 0.0f);
                }
                func_800EF334(data->velocity, -1.0f);
                func_800EF334(normal, 2.0f * func_800EEAA4(data->velocity, normal));
                func_800EFB24(data->velocity, normal, data->velocity);
                data->bounces++;
                if (data->sound != 0) {
                    factor = (data->flags & 0x2000)
                        ? func_800F10B4((f32)data->bounces,
                                       1.0f,
                                       4.0f,
                                       1.0f,
                                       0.65f)
                        : 1;
                    func_800C4B64(data->pitch * factor);
                    func_800C4B70(data->volume * factor);
                    func_800C4B7C(data->sound);
                    func_8010D930(3, arg0->unk70_0, data->position, D_808014AC_chbounce);
                }
                func_800EF334(data->velocity, config->restitution);
                speed = func_800EEF94(data->velocity);
                if (speed > 800.0f) {
                    speed = 800.0f;
                    func_800EF368(data->velocity, speed);
                }
                if ((speed < 200.0f && normal[1] > 0.75f) || speed < 10.0f) {
                    data->state = 2;
                    data->settled = 1;
                    if (config->flags & 0x10) {
                        func_8010A63C(arg0);
                    }
                }
                if (config->flags & 0x200) {
                    floor = func_80105494(arg0);
                    if (floor != NULL) {
                        data->position[1] = floor->height;
                    }
                }
            } else {
                if (config->flags & 0x100) {
                    data->velocity[1] -= 4000.0f * dt;
                } else if (config->flags & 0x800) {
                    data->velocity[1] -= 750.0f * dt;
                } else {
                    data->velocity[1] -= 1500.0f * dt;
                }
            }
            func_800EE7F8(arg0->position, data->position);
            break;
        case 2:
            if (config->flags & 2) {
                data->angle += data->angularVelocity * dt;
                while (data->angle >= 360.0f) {
                    data->angle -= 360.0f;
                }
                while (data->angle < 0.0f) {
                    data->angle += 360.0f;
                }
                arg0->rotation[1] = data->angle;
            }
            if (mlAbsF(data->angularVelocity) < 0.1f || !(config->flags & 2)) {
                func_80800F74_chbounce(arg0);
            }
            break;
    }
    if (arg0->position[1] < func_800BECCC() - 1000.0f) {
        if (func_8010108C(arg0, 0x4D, 0) > 0) {
            func_80800F74_chbounce(arg0);
        } else {
            func_800FFAB0(arg0);
        }
    }
}

/* extern */

BtIntPtr chbounce_entrypoint_9(Actor *arg0) {
    return (BtIntPtr) ((s8 *) func_80100094(arg0, 2U) + 0xC);
}

s32 chbounce_entrypoint_10(Actor *arg0) {
    return ((u32) (*(u32 *)((s8 *)(func_80100094(arg0, 2U)) + (0x24))) >> 0x1F) == 0;
}

void func_80800F74_chbounce(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    (*(u8 *)((s8 *)(arg0) + (0x7B))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x7B))) & 0xFFF7);
    func_80100074(arg0, 2U, 0U);
}
/* data_to_c.py: from asm/data/overlays/ch/bounce.data.s */
struct BounceConfig D_80800FE0_chbounce [34] BT_DATA(4, overlays_ch_bounce, 0x0) = { { 0x21, 500, 1, 1028, 1.8f, 20000, 100, 50, 500, 250, 100, 50, { 0, 0 }, 0.6f, 0.0f }, { 0x2D, 528, 1, 0, 1.25f, 16000, 0, 0, 200, 0, 0, 0, { 0, 0 }, 0.2f, 315.0f }, { 1, 553, 1, 1001, 1.25f, 18000, 50, 150, 500, 250, 50, 150, { 0, 0 }, 0.6f, 0.0f }, { 0x21, 553, 1, 1001, 1.25f, 18000, 0, 0, 750, 250, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x21, 553, 2, 1001, 1.25f, 18000, 50, 150, 500, 250, 50, 150, { 0, 0 }, 0.6f, 0.0f }, { 0x21, 553, 3, 1001, 1.25f, 18000, 50, 150, 500, 250, 50, 150, { 0, 0 }, 0.6f, 0.0f }, { 0x481, 553, 1, 1028, 1.2f, 20000, 250, 0, 200, 0, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x481, 553, 1, 1028, 1.2f, 20000, 350, 0, 350, 0, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x481, 553, 1, 1028, 1.2f, 20000, 450, 0, 400, 0, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x481, 553, 1, 1028, 1.2f, 20000, 550, 0, 450, 0, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x481, 553, 1, 1028, 1.2f, 20000, 650, 0, 500, 0, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x681, 553, 1, 1028, 1.2f, 20000, 250, 0, 200, 0, 0, 0, { 0, 0 }, 0.0f, 0.0f }, { 0x681, 553, 1, 1028, 1.2f, 20000, 350, 0, 350, 0, 0, 0, { 0, 0 }, 0.0f, 0.0f }, { 0x681, 553, 1, 1028, 1.2f, 20000, 450, 0, 400, 0, 0, 0, { 0, 0 }, 0.0f, 0.0f }, { 0x681, 553, 1, 1028, 1.2f, 20000, 550, 0, 450, 0, 0, 0, { 0, 0 }, 0.0f, 0.0f }, { 0x681, 553, 1, 1028, 1.2f, 20000, 650, 0, 500, 0, 0, 0, { 0, 0 }, 0.0f, 0.0f }, { 0x480, 553, 1, 1028, 1.2f, 20000, 250, 0, 200, 0, 0, 0, { 0, 0 }, 0.5f, 0.0f }, { 0x480, 553, 1, 1028, 1.2f, 20000, 300, 0, 250, 0, 0, 0, { 0, 0 }, 0.5f, 0.0f }, { 0x480, 553, 1, 1028, 1.2f, 20000, 400, 0, 325, 0, 0, 0, { 0, 0 }, 0.5f, 0.0f }, { 0x480, 553, 1, 1028, 1.2f, 20000, 650, 0, 450, 0, 0, 0, { 0, 0 }, 0.5f, 0.0f }, { 0x480, 553, 1, 1028, 1.2f, 20000, 950, 0, 500, 0, 0, 0, { 0, 0 }, 0.5f, 0.0f }, { 0, 457, 1, 1048, 1.25f, 16000, 20, 30, 500, 500, 20, 30, { 0, 0 }, 0.6f, 0.0f }, { 0, 459, 1, 1048, 1.25f, 16000, 20, 30, 500, 500, 20, 30, { 0, 0 }, 0.6f, 0.0f }, { 0, 460, 1, 1048, 1.25f, 16000, 20, 30, 500, 500, 20, 30, { 0, 0 }, 0.6f, 0.0f }, { 0x21, 407, 1, 1001, 1.25f, 18000, 0, 0, 750, 250, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x21, 406, 1, 1001, 1.25f, 18000, 0, 0, 750, 250, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0xC80, 0, 1, 1028, 1.2f, 20000, 250, 0, 1000, 0, 0, 0, { 0, 0 }, 0.5f, 0.0f }, { 0x2400, 0, 1, 1577, 1.0f, 14000, 50, 30, 1000, 50, 50, 30, { 0, 0 }, 0.5f, 0.0f }, { 0x1021, 543, 1, 1001, 1.25f, 16000, 0, 0, 500, 250, 100, 50, { 0, 0 }, 0.6f, 0.0f }, { 0x1024, 543, 1, 1001, 1.25f, 16000, 0, 0, 500, 250, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x1024, 543, 1, 1001, 1.25f, 16000, 0, 0, 0, 0, 0, 0, { 0, 0 }, 0.6f, 0.0f }, { 0x29, 543, 1, 1001, 1.25f, 16000, 300, 0, 500, 250, -300, -100, { 0, 0 }, 0.6f, 180.0f }, { 0x29, 543, 1, 1001, 1.25f, 16000, -100, -100, 750, 250, -300, -100, { 0, 0 }, 0.6f, 0.0f }, { 0x401, 553, 1, 1001, 1.25f, 18000, 300, 100, 600, 250, 300, 100, { 0, 0 }, 0.6f, 0.0f } };
f32 D_808014A8_chbounce BT_DATA(4, overlays_ch_bounce, 0x4C8) = 400.0f;
s32 D_808014AC_chbounce [5] BT_DATA(4, overlays_ch_bounce, 0x4CC) = { 2162717, 1966081, 13110200, 0, 0 };
