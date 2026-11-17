#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "1EC3810_collision_native.inc"
#else
void func_800EA600(s32 arg0, s32 arg1) {
    extern s32 D_80132DD0;
    (*(s32 *)((s8 *)(&D_80132DD0) + (0))) = arg0;
    (*(s32 *)((s8 *)(&D_80132DD0) + (4))) = arg1;
}

void func_800EA614(void) {
    extern s32 D_80132DD0;
    (*(s32 *)((s8 *)(&D_80132DD0) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_80132DD0) + (4))) = 0;
}

s32 func_800EA628(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    typedef struct {
        union {
            u8 *marker;
            struct { u16 id; u8 yaw; u8 roll; } model;
        } data;
        s16 x;
        s16 y;
        s32 z : 16;
        u32 scale : 8;
        u32 unused : 3;
        u32 active : 1;
        u32 collidable : 1;
        u32 flag2 : 1;
        u32 isModel : 1;
        u32 isActor : 1;
    } Prop;
    typedef s32 (*CollisionCallback)(u8 *, s32, s32, s32, s32);
    typedef struct { CollisionCallback collide; } CollisionTable;
    typedef CollisionTable *(*GetCollisionTable)(void);
    typedef struct { u32 upper : 14; u32 excluded : 1; u32 lower : 17; } ActorFlags;
    s32 _gsproplookup_entrypoint_0();
    s32 func_800AAEF4(f32 *, f32, f32 *, f32 *);
    s32 func_800AB868(u8 *, s32, f32 *, f32 *, f32, s32, s32, s32, s32);
    f32 func_800B2354(void *);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    u8 *func_800BFC34(s32);
    u8 *func_800BFC54(s32);
    void func_800BFC74(s32);
    s16 func_800CB854(s32 *);
    void func_800D62E4(u16);
    void *func_800E9E88(s32);
    void *func_800E9EB4(s32);
    void func_800EA400(s32, u8 *, BtIntPtr, s32);
    s32 func_800EB350(Actor *, f32 *, f32 *);
    void func_80103508(u8 *);
    s32 func_801039E4(s32);
    u8 *func_80103AA0(u8 *);
    s32 func_80103CDC(u8 *, u8 *);
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80132DD0;
    extern s32 D_80132DD4;
    extern f32 D_80125E50;
    s32 result;
    Prop *prop;
    s32 modelId;
    Prop *end;
    u8 *model;
    f32 scale;
    CollisionTable *table;
    f32 position[3];
    f32 rotation[3];
    u8 *collision;
    u8 *marker;
    u8 *actor;
    s32 hit;
    s32 customHit;
    s32 context;
    s32 modelHit;

    result = 0;
    prop = func_800E9E88(arg0);
    end = func_800E9EB4(arg0);
    for (; prop < end; prop++) {
        if (prop->active) {
            if (!prop->isActor) {
                if (prop->isModel) {
                    modelId = _gsproplookup_entrypoint_0(prop);
                    model = func_800BFC54(modelId);
                    if (model != NULL || (func_800CB854(NULL) == 1 && (model = func_800BFC34(modelId)) != NULL)) {
                        collision = func_800B2720(model);
                        if (collision != NULL) {
                            prop->collidable = 1;
                            position[0] = prop->x;
                            position[1] = prop->y;
                            position[2] = prop->z;
                            rotation[0] = 0.0f;
                            rotation[1] = (f32)(u32)prop->data.model.yaw * 2.0f;
                            rotation[2] = (f32)(u32)prop->data.model.roll * 2.0f;
                            scale = (f32)prop->scale * D_80125E50;
                            if (func_800AAEF4(position, func_800B2354((void *)func_800B2840((s32)model)) * scale, arg1, arg2)) {
                                modelHit = func_800AB868(collision, func_800B2840((s32)model), position, rotation, scale, arg1, arg2, arg3, arg4);
                                if (modelHit != 0) {
                                    result = modelHit;
                                }
                            }
                        }
                        if (model != NULL) {
                            func_800BFC74(modelId);
                        }
                    }
                }
            } else {
                marker = prop->data.marker;
                if (prop->collidable && (*(u16 *)(marker + 0x18) & 1)) {
                    if (*(GetCollisionTable *)(marker + 0xC) != NULL && (table = (*(GetCollisionTable *)(marker + 0xC))())->collide != NULL) {
                        customHit = table->collide(marker, arg1, arg2, arg3, arg4);
                        if (customHit != 0) {
                            result = customHit;
                        }
                    } else {
                        actor = func_80106790(marker);
                        if (!((ActorFlags *)(actor + 0x64))->excluded && !func_800EB350(actor, arg1, arg2)) {
                            if (func_800CB854(NULL) == 1) {
                                func_80103508(actor);
                            }
                            model = func_80103AA0(marker);
                            if (model != NULL) {
                                collision = func_800B2720(model);
                                if (collision != NULL) {
                                    hit = func_800AB868(collision, func_80103CDC(actor, model), (f32 *)(actor + 4), (f32 *)(actor + 0x44), *(f32 *)(actor + 0x38), arg1, arg2, arg3, arg4);
                                    if (hit != 0 && D_80132DD0 != 0) {
                                        ((void (*)(u8 *, s32))D_80132DD0)(marker, D_80132DD4);
                                    }
                                    if (hit != 0 && func_800CB854(&context) == 1) {
                                        func_801039E4((s32)marker);
                                        if (*(u16 *)(actor + 0x80) != 0) {
                                            func_800EA400(context, marker, arg2, hit);
                                        }
                                    }
                                    if (hit != 0) {
                                        result = hit;
                                    }
                                }
                                if (model != NULL) {
                                    func_800D62E4(*(u16 *)(marker + 0x14));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

s32 func_800EAA2C(s32 arg0, volatile s32 arg1, s32 arg2, f32 arg3, f32 *arg4, volatile s32 arg5, volatile u32 arg6) {
    s32 _gsproplookup_entrypoint_0();
    u8 *func_800AC848(u8 *, s32, f32 *, f32 *, f32, s32, s32, f32, f32 *, s32, u32);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    u8 *func_800BFC54(s32);
    void func_800BFC74(s32);
    s16 func_800CB854(s32 *);
    void func_800D62E4(u16);
    void *func_800E9E88(s32);
    void *func_800E9EB4(s32);
    f32 func_800EEAD4(s32, f32 *);
    void func_80103328(Actor *);
    void func_80103508(u8 *);
    u8 *func_80103AA0(u8 *);
    s32 func_80103CDC(u8 *, u8 *);
    Actor *func_80106790(Unk80132ED0 *);
    extern f32 D_80125E54;
    extern s32 D_80132DD0;
    extern s32 D_80132DD4;
    typedef u8 *(*CollisionFunc)(u8 *, s32, s32, f32, f32 *, s32, u32);
    typedef struct {
        s32 unused;
        CollisionFunc collide;
    } CollisionMethods;
    typedef struct {
        u32 unused:27;
        u32 collide:1;
        u32 enabled:1;
        u32 unused2:1;
        u32 model:1;
        u32 actor:1;
    } PropFlags;
    typedef struct {
        u32 unused:14;
        u32 skip:1;
        u32 unused2:17;
    } ActorFlags;
    u8 *actor;
    s32 propId;
    u8 *hit;
    u8 *end;
    u8 *model;
    u8 *collision;
    s32 marker;
    f32 position[3];
    f32 rotation[3];
    s32 result;
    u8 *prop;
    CollisionMethods *methods;
    u8 *actorHit;
    f32 distance;

    result = 0;
    prop = func_800E9E88(arg0);
    end = func_800E9EB4(arg0);
    for (; prop < end; prop += 12) {
        if (((PropFlags *)(prop + 8))->collide) {
            if (!((PropFlags *)(prop + 8))->actor) {
                if (((PropFlags *)(prop + 8))->model) {
                    propId = _gsproplookup_entrypoint_0(prop);
                    model = func_800BFC54(propId);
                    collision = func_800B2720(model);
                    if (collision != NULL) {
                        position[0] = (f32)*(s16 *)(prop + 4);
                        position[1] = (f32)*(s16 *)(prop + 6);
                        position[2] = (f32)*(s16 *)(prop + 8);
                        rotation[0] = 0.0f;
                        rotation[1] = (f32)prop[2] + (f32)prop[2];
                        rotation[2] = (f32)prop[3] + (f32)prop[3];
                        hit = func_800AC848(collision, func_800B2840((s32)model), position, rotation,
                            (f32)prop[10] * D_80125E54, arg1, arg2, arg3, arg4, arg5, arg6);
                        if (hit != 0 && D_80132DD0 != 0) {
                            ((void (*)(s32, s32))D_80132DD0)(*(s32 *)prop, D_80132DD4);
                        }
                        if (hit != 0) {
                            result = (s32)hit;
                        }
                    }
                    if (model != NULL) {
                        func_800BFC74(propId);
                    }
                }
            } else {
                if (1) { } if (1) { } if (1) { }
                marker = *(s32 *)prop;
                if (((PropFlags *)(prop + 8))->enabled && (*(u16 *)(marker + 0x18) & 1)) {
                    actor = (u8 *)func_80106790((Unk80132ED0 *)marker);
                    if (!((ActorFlags *)(actor + 0x64))->skip) {
                        if (*(CollisionMethods *(**)(void))(marker + 0xC) != NULL &&
                            (methods = (*(CollisionMethods *(**)(void))(marker + 0xC))(), methods->collide != NULL)) {
                            actorHit = methods->collide((u8 *)marker, *(s32 *)&arg1, arg2, arg3, arg4, *(s32 *)&arg5, *(u32 *)&arg6);
                            if (actorHit != 0) {
                                result = (s32)actorHit;
                            }
                        } else {
                            func_80103328(actor);
                            distance = func_800EEAD4((f32 *)arg2, (f32 *)(actor + 4)) - arg3;
                            if (!(distance >=
                                *(f32 *)(actor + 0x38) * (f32)*(u16 *)(actor + 0x6A))) {
                                if (func_800CB854(NULL) == 1) {
                                    func_80103508(actor);
                                }
                                model = func_80103AA0((u8 *)marker);
                                collision = func_800B2720(model);
                                if (collision != NULL) {
                                    actorHit = func_800AC848(collision, func_80103CDC(actor, model), (f32 *)(actor + 4),
                                        (f32 *)(actor + 0x44), *(f32 *)(actor + 0x38), arg1, arg2, arg3, arg4, arg5, arg6);
                                    if (actorHit != 0) {
                                        result = (s32)actorHit;
                                    }
                                }
                                if (model != NULL) {
                                    func_800D62E4(*(u16 *)(marker + 0x14));
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}

s32 func_800EADFC(s32 arg0, s32 arg1, f32 arg2, f32 *arg3, u32 arg4) {
    typedef struct {
        u8 data[8];
        u32 unused:27;
        u32 enabled:1;
        u32 active:1;
        u32 unused2:1;
        u32 model:1;
        u32 actor:1;
    } Prop;
    typedef struct {
        s32 data[2];
        s32 (*collide)(u8 *, s32, f32, f32 *, u32);
    } Callbacks;
    typedef struct {
        u8 data[0xC];
        s32 (*get_callbacks)();
        u32 unknown10;
        u16 model_id;
        u16 unknown16;
        u16 flags;
    } Marker;
    typedef struct {
        u8 data[0x64];
        u32 unused:14;
        u32 disabled:1;
        u32 unused2:17;
    } ActorFlags;
    s32 _gsproplookup_entrypoint_0(u8 *);
    s32 func_800AD1AC(s32, s32, f32 *, f32 *, f32, s32, f32, f32 *, u32);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    u8 *func_800BFC54(s32);
    s16 func_800CB854(s32 *);
    void func_800D62E4(u16);
    void *func_800E9E88(s32);
    void *func_800E9EB4(s32);
    f32 func_800EEAD4(s32, f32 *);
    void func_80103328(Actor *);
    void func_80103508(u8 *);
    u8 *func_80103AA0(u8 *);
    s32 func_80103CDC(u8 *, u8 *);
    Actor *func_80106790(Unk80132ED0 *);
    extern f32 D_80125E58;
    s32 result;
    s32 hit;
    Prop *prop;
    Prop *end;
    s32 collision;
    Prop *model_prop;
    s32 model;
    f32 position[3];
    f32 rotation[3];
    u8 *actor;
    u8 *marker;
    f32 *actor_position;
    f32 **output = &arg3;

    result = 0;
    prop = func_800E9E88(arg0);
    end = func_800E9EB4(arg0);
    if (prop < end) do {
        if (!prop->enabled) {
            continue;
        }
        {
            if (!((Prop *)prop)->actor) {
                if (((Prop *)prop)->model) {
                    model_prop = prop;
                    model = func_800BFC54(_gsproplookup_entrypoint_0((u8 *)model_prop));
                    collision = func_800B2720(model);
                    if (collision != 0) {
                        position[0] = (f32)*(s16 *)((u8 *)model_prop + 4);
                        position[1] = (f32)*(s16 *)((u8 *)model_prop + 6);
                        position[2] = (f32)*(s16 *)((u8 *)model_prop + 8);
                        rotation[0] = 0.0f;
                        rotation[1] = (f32)(u32)*((u8 *)model_prop + 2) + (f32)(u32)*((u8 *)model_prop + 2);
                        rotation[2] = (f32)(u32)*((u8 *)model_prop + 3) + (f32)(u32)*((u8 *)model_prop + 3);
                        hit = func_800AD1AC(collision, func_800B2840(model), position, rotation,
                            (f32)(u32)*((u8 *)model_prop + 0xA) * D_80125E58, arg1, arg2, *output, arg4);
                        if (hit != 0) {
                            result = hit;
                        }
                    }
                }
            } else {
                marker = *(u8 **)prop;
                if (!prop->active || !(((Marker *)marker)->flags & 1)) {
                    continue;
                }
                {
                    actor = (u8 *)func_80106790((Unk80132ED0 *)marker);
                    if (((ActorFlags *)actor)->disabled) {
                        continue;
                    }
                    {
                        if (((Marker *)marker)->get_callbacks != NULL) {
                            hit = ((Marker *)marker)->get_callbacks();
                            if (((Callbacks *)hit)->collide != NULL) {
                                hit = ((Callbacks *)hit)->collide(marker, arg1, arg2, *output, arg4);
                                if (hit != 0) {
                                    result = hit;
                                }
                                continue;
                            }
                        }
                        {
                            func_80103328(actor);
                            actor_position = (f32 *)(actor + 4);
                            if (!(func_800EEAD4(arg1, actor_position) - arg2 >=
                                *(f32 *)(actor + 0x38) * (f32)(u32)*(u16 *)(actor + 0x6A))) {
                                if (func_800CB854(0) == 1) {
                                    func_80103508(actor);
                                }
                                model = func_80103AA0(marker);
                                collision = func_800B2720(model);
                                if (collision != 0) {
                                    hit = func_800AD1AC(collision, func_80103CDC(actor, model), actor_position,
                                        (f32 *)(actor + 0x44), *(f32 *)(actor + 0x38), arg1, arg2, *output, arg4);
                                    if (hit != 0) {
                                        result = hit;
                                    }
                                }
                                if (model != 0) {
                                    func_800D62E4(((Marker *)marker)->model_id);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while (++prop < end);
    return result;
}

#endif
