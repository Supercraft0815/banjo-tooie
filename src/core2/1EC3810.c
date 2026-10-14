#include "core2/1EC3810.h"

extern u16 D_80132DC2;
extern s32 D_80132DC0;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800E9F20.s")

// Get World Section
MapId func_800EA05C(void) 
{
	return D_80132DC2;
}

s32 func_800EA068(s32 arg0) {
    s32 _gcsectionDll_entrypoint_3(s32, s32);
    extern s32 D_80132DC4;
    return _gcsectionDll_entrypoint_3(D_80132DC4, arg0);
}

s32 func_800EA090(void) {
    extern s16 D_80132DC8;

    return D_80132DC8;
}

s32 func_800EA09C(void) {
    return *(s16 *)((u8 *)&D_80132DC0 + 0);
}

void func_800EA0A8()
{
    _gsworldDll_entrypoint_1(&D_80132DC0);
}

/* extern */

void func_800EA0CC(s32 arg0, s32 arg1, s32 arg2) {
    s32 _cothemedll_entrypoint_0();
    s32 _gsworldDll_entrypoint_2(s32 *, s32, s32, s32);
    s32 func_800BF8BC(s32);
    s32 func_800C0064(s32);
    s32 func_800DBB5C();
    _cothemedll_entrypoint_0();
    func_800DBB5C();
    func_800BF8BC(arg0);
    func_800C0064(arg0);
    _gsworldDll_entrypoint_2(&D_80132DC0, arg0, arg1, arg2);
}

void func_800EA124()
{
    _gsworldDll_entrypoint_4(&D_80132DC0);
}

/* extern */

void func_800EA148(s32 arg0) {
    s32 _gsworldDll_entrypoint_3(s32 *, s32);
    _gsworldDll_entrypoint_3(&D_80132DC0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA170.s")

void func_800EA334(s32 arg0) {
    extern s16 D_80132DCA;
    *(s16 *)((u8 *)&D_80132DCA + 0) = arg0;
}

s32 func_800EA340(void) {
    extern s16 D_80132DCA;

    return D_80132DCA;
}

void func_800EA34C(s32 arg0) {
    extern s16 D_80132DCC;
    *(s16 *)((u8 *)&D_80132DCC + 0) = arg0;
}

s32 func_800EA358(void) {
    extern s16 D_80132DCC;

    return D_80132DCC;
}

u32 func_800EA364(void) {
    extern u16 D_80132DCE;
    return *(u16 *)((u8 *)&D_80132DCE + 0);
}

void func_800EA370()
{
    func_800EA3A0();
}

void func_800EA390(void) {
}

void func_800EA398(void) {
}

int func_800EA3A0(void) {
    extern s32 D_80132DD0;
    extern f32 D_80132DD8;
    extern f32 D_80132E78;
    void func_800EFD24(f32 *);
    f32 *var_s1;
    s32 *var_s0;
    f32 *end;

    end = &D_80132E78; var_s0 = &D_80132DD0; var_s1 = &D_80132DD8;
    do {
        func_800EFD24(var_s1);
        var_s1 += 5;
        var_s0 += 5;
        var_s0[0] = 0;
        var_s0[1] = 0;
    } while (var_s1 != end);
}

void func_800EA400(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    extern s32 D_80132DD0;
    func_800EE7F8((f32 *)((u8 *)&D_80132DD0 + arg0 * 0x14 + 8), (f32 *)arg2);
    *(u8 **)((u8 *)&D_80132DD0 + arg0 * 0x14 + 0x14) = arg1;
    *(s32 *)((u8 *)&D_80132DD0 + arg0 * 0x14 + 0x18) = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA45C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EA51C.s")

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
    s32 func_800AAEF4(f32 *, f32, s32, s32);
    s32 func_800AB868(u8 *, s32, f32 *, f32 *, f32, s32, s32, s32, s32);
    f32 func_800B2354(void *);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    u8 *func_800BFC34(s32);
    u8 *func_800BFC54(s32);
    void func_800BFC74(s32);
    s16 func_800CB854(s32 *);
    void func_800D62E4(u16);
    Prop *func_800E9E88(s32);
    Prop *func_800E9EB4(s32);
    void func_800EA400(s32, u8 *, s32, s32);
    s32 func_800EB350(u8 *, s32, s32);
    void func_80103508(u8 *);
    s32 func_801039E4(s32);
    u8 *func_80103AA0(u8 *);
    s32 func_80103CDC(u8 *, u8 *);
    u8 *func_80106790(u8 *);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EAA2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EADFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB15C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB210.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB2DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC3810/func_800EB350.s")
