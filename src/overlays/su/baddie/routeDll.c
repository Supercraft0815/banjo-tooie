#include "common.h"

/* extern */

void func_80800000_subaddierouteDll(void) {
    s16 func_8001B668(s32, s32);
    void func_8001B7F0(s16, u8, int);
    s32 func_800CC5E8(void);
    OSThread *func_801015B0(void);
    void func_801015BC(void);
    s32 sp1C;
    s16 *sp18;

    sp18 = (s16 *)func_801015B0();
    sp18[1] = func_800CC5E8();
    sp1C = sp18[1] * 4;
    if (sp1C != 0) {
        sp18[0] = func_8001B668(0, sp1C);
        func_8001B7F0(sp18[0], 0, sp1C);
        func_801015BC();
        return;
    }
    sp18[0] = 0;
}

void subaddierouteDll_entrypoint_0(void) {
    void func_8001B754(s16);
    void *func_8001B798(s16);
    OSThread *func_801015B0(void);
    s16 *state;
    s16 *entries;
    s32 offset;
    s32 i;

    state = (s16 *)func_801015B0();
    if (state[0] != 0) {
        i = 0;
        offset = 0;
        if (state[1] > 0) {
            do {
                entries = func_8001B798(state[0]);
                if (*(s16 *)((u8 *)entries + offset) != 0) {
                    func_8001B754(*(s16 *)((u8 *)entries + offset));
                }
                i++;
                offset += 4;
            } while (i < state[1]);
        }
        func_8001B754(state[0]);
        state[0] = 0;
    }
    state[1] = 0;
}

/* extern */

s32 func_8080011C_subaddierouteDll(s32 arg0, s16 *arg1) {
    u32 func_800CC5F4(s32);
    void *func_800CC63C(s32, s32);
    f32 func_800EFC7C(void *, void *);
    s16 *var_s7;
    s32 var_fp;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 var_s0;
    s32 var_s3;
    s32 var_s4;
    void *temp_s2;
    void *temp_v0_2;
    f32 distance;

    temp_v0 = func_800CC5F4(arg0);
    var_fp = ((temp_v0 * 2) + 3) & ~3;
    var_s4 = 0;
    if (temp_v0 > 0) {
        var_s7 = arg1;
        do {
            *var_s7 = var_fp;
            temp_s2 = func_800CC63C(arg0, var_s4);
            var_s3 = 1;
            var_s0 = 0;
            if (temp_v0 > 0) {
                do {
                    if (var_s4 != var_s0) {
                        temp_v0_2 = func_800CC63C(arg0, var_s0);
                        distance = func_800EFC7C(temp_s2, temp_v0_2);
                        temp_v0_3 = (*(s16 *)((s8 *)(temp_v0_2) + (0xC))) + (*(s16 *)((s8 *)(temp_s2) + (0xC)));
                        if (distance < (f32) (temp_v0_3 * temp_v0_3)) {
                            var_s3 += 1;
                        }
                    }
                    var_s0 += 1;
                } while (var_s0 != temp_v0);
            }
            var_s4 += 1;
            var_s7 += 1;
            var_fp += (var_s3 + 3) & ~3;
        } while (var_s4 < temp_v0);
    }
    return var_fp;
}

/* extern */

void func_8080024C_subaddierouteDll(s8 *arg0, s32 arg1, s32 arg2) {
    u32 func_800CC5F4(s32);
    void *func_800CC63C(s32, s32);
    f32 func_800EFC7C(void *, void *);
    s32 temp_s4;
    s32 temp_v0_2;
    s8 *var_s2;
    s32 var_s0;
    void *temp_s3;
    void *temp_v0;
    f32 distance;

    var_s2 = arg0 + 1;
    temp_s4 = func_800CC5F4(arg1);
    temp_s3 = func_800CC63C(arg1, arg2);
    var_s0 = 0;
    if (temp_s4 > 0) {
        do {
            if (arg2 != var_s0) {
                temp_v0 = func_800CC63C(arg1, var_s0);
                distance = func_800EFC7C(temp_s3, temp_v0);
                temp_v0_2 = (*(s16 *)((s8 *)(temp_v0) + (0xC))) + (*(s16 *)((s8 *)(temp_s3) + (0xC)));
                if (distance < (f32) (temp_v0_2 * temp_v0_2)) {
                    *var_s2 = var_s0;
                    var_s2 += 1;
                }
            }
            var_s0 += 1;
        } while (var_s0 != temp_s4);
    }
    *arg0 = (var_s2 - arg0) - 1;
}

void subaddierouteDll_entrypoint_1(Actor *arg0) {
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    u32 func_800CC5F4(s32);
    OSThread *func_801015B0(void);
    void *func_80106F30(void *);
    s16 offsets[128];
    s16 *handle;
    s16 *table;
    s16 *data;
    s8 *base;
    s16 *dest;
    s16 *src;
    s32 tableOffset;
    s32 count;
    s32 offset;
    s32 i;
    s32 route;
    struct {
        u8 pad[12];
        u32 route : 12;
        u32 rest : 20;
    } *entry;
    s16 *slot;

    route = arg0->unk70_25 - 1;
    handle = (s16 *)func_801015B0();
    if (*handle == 0) {
        func_80800000_subaddierouteDll();
    }
    if (route < 0) {
        entry = func_80106F30(arg0);
        if (entry != NULL) {
            if (entry->route != 0) {
                route = entry->route - 1;
            }
        }
    }
    count = func_800CC5F4(route);
    table = func_8001B798(*handle);
    tableOffset = route * 4;
    slot = (s16 *)((s8 *)table + tableOffset);
    if (slot[0] != 0) {
        slot[1]++;
        return;
    }
    slot = (s16 *)((s8 *)table + tableOffset);
    slot[0] = func_8001B668(0, func_8080011C_subaddierouteDll(route, offsets));
    slot[1] = 1;
    data = func_8001B798(slot[0]);
    i = 0;
    if (count > 0) {
        offset = 0;
        dest = data;
        src = offsets;
        do {
            *dest = *src;
            base = func_8001B798(*(s16 *)((s8 *)func_8001B798(*handle) + tableOffset));
            func_8080024C_subaddierouteDll(base + *(s16 *)(base + offset), route, i);
            i++;
            offset += 2;
            dest++;
            src++;
        } while (i != count);
    }
}

/* extern */

void subaddierouteDll_entrypoint_2(void *arg0) {
    void func_8001B754(s16);
    void *func_8001B798(s16);
    OSThread *func_801015B0(void);
    register s32 sp2C;
    s16 *temp_v0;

    sp2C = ((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) - 1;
    temp_v0 = func_8001B798(*(s16 *)func_801015B0());
    (*(s16 *)((u8 *)temp_v0 + sp2C * 4 + 2)) = (s16)(*(s16 *)((u8 *)temp_v0 + sp2C * 4 + 2) - 1);
    if ((*(s16 *)((u8 *)temp_v0 + sp2C * 4 + 2)) == 0) {
        arg0 = (s16 *)((s32)temp_v0 + sp2C * 4);
        func_8001B754(*(s16 *)arg0);
        *(s16 *)arg0 = 0;
    }
}

void subaddierouteDll_entrypoint_3(s32 arg0, void *arg1, f32 *arg2) {
    void func_80800564_subaddierouteDll(s32, void *);
    rare_memset(arg1, 0, 0xC);
    func_80800564_subaddierouteDll(arg0, arg1);
}

void func_80800564_subaddierouteDll(s32 arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (6))) = 0;
    (*(s32 *)((s8 *)(arg1) + (8))) = 0;
}

/* extern */

s32 subaddierouteDll_entrypoint_4(void **arg0) {
    s32 func_8001210C(s32);
    u32 sp1C;

    sp1C = (u32)(*(u16 *)((s8 *)(*arg0) + 0x12)) >> 1 & 3;
    return func_8001210C(3) == sp1C;
}
/* extern */

void func_808005B0_subaddierouteDll(Actor *arg0, s16 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800136E4(f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 sp1C[3];

    func_800EE88C(sp1C, arg1);
    arg0->unk54 = func_800136E4(func_800F1DF4(arg0->position, sp1C) + 180.0f);
    if (func_80102CF4(arg0, 0x42200000) == 0) {
        func_80102BF8(arg0, arg2, arg3, arg4);
    }
}

/* extern */

void subaddierouteDll_entrypoint_5(Actor *arg0, void *arg1, s32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    void func_80102BF8(void *, f32, f32, f32);
    if (arg2 & 4) {
        func_808005B0_subaddierouteDll(arg0, arg1, arg3, arg4, arg5);
        return;
    }
    func_80102BF8(arg0, arg3, arg4, arg5);
}

/* extern */

s32 subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    s32 func_80102D98(Actor *, s32, s32, f32, f32, f32);
    if (arg2 & 0x1C) {
        return 0;
    }
    return func_80102D98(arg0, arg3, 0, arg4, (f32) arg5, (f32) arg6);
}

s32 func_808006D0_subaddierouteDll(Actor *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    u8 func_800CC61C(s32);
    void *func_800CC684(s32, s32);
    void func_800EEB9C(f32[3], f32, f32);
    s32 func_800F05F8(f32 *, f32 *, f32 *, f32, f32 *);
    f32 func_800F13F0(f32, f32);
    f32 direction[3];
    f32 roots[2];
    s32 route;
    s32 count;
    s32 i;
    struct { f32 position[3]; s16 radius; } *sphere;

    route = arg0->unk70_25 - 1;
    count = func_800CC61C(route);
    if (count == 0) {
        return 1;
    }
    func_800EEB9C(direction, arg2, arg3);
    for (i = count - 1; i >= 0; i--) {
        sphere = func_800CC684(route, i);
        if (func_800F05F8(arg0->position, direction, sphere->position, sphere->radius, roots) == 2
            && roots[0] >= 0.0f && roots[1] >= 0.0f
            && func_800F13F0(roots[0], roots[1]) < 1.0f) {
            ((u16 *)arg1)[3] |= 2;
            return 0;
        }
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/routeDll/func_80800828_subaddierouteDll.s")

s32 func_80800A74_subaddierouteDll(void *arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    s32 func_800CC6CC(s32, s32);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DCC(f32, f32);
    int func_800F1EA4(f32 *, f32 *);
    struct RouteHit { s16 position[3]; u16 flags; Unk80132ED0 *actor; };
    struct RouteActor {
        Unk80132ED0 *unk0;
        f32 position[3];
        f32 unk10;
        u32 unk14;
        u8 pad18[0x58];
        u32 route_start : 7;
        u32 pad70 : 15;
        u32 route_end : 6;
        u32 pad73 : 4;
    };
    f32 end[3];
    f32 start[3];
    f32 normal[3];
    f32 yaw;
    f32 *position;

    (void)&arg0;
    if (!(arg4 & 0x2000)) {
        if (!func_800CC6CC(((struct RouteActor *)arg0)->route_start - 1,
                          ((struct RouteActor *)arg0)->route_end - 1)) {
            return 1;
        }
    }
    func_800EE7F8(start, ((Actor *)arg0)->position);
    func_800EE7F8(end, ((Actor *)arg0)->position);
    func_800EF1B8(end, arg2, *(f32 *)&arg3);
    start[1] += 0.6f * func_800EC708(((Actor *)arg0)->unk0);
    end[1] = start[1];
    if (func_800BEF00(start, end, normal, ((Actor *)arg0)->unk14)) {
        if (func_800F1EA4(normal, &yaw)) {
            ((struct RouteHit *)arg1)->flags |= func_800F1DCC(arg2 + 180.0f, yaw) > 0.0f ? 0x10 : 8;
        }
        return 0;
    }
    return 1;
}

typedef struct {
    s16 position[3];
    u16 flags;
    Unk80132ED0 *actor;
} RouteResult;

s32 subaddierouteDll_entrypoint_7(Actor *arg0, RouteResult *arg1, f32 arg2, f32 arg3, f32 arg4, s32 arg5) {
    f32 func_800136E4(f32);
    s32 *func_800BE444(f32 *arg0);
    f32 func_800F1DCC(f32 arg0, f32 arg1);
    s32 func_80800D88_subaddierouteDll(Actor *, RouteResult *, f32, s32, s32 *);
    s32 func_8080160C_subaddierouteDll(Actor *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 *arg5);
    f32 func_8080183C_subaddierouteDll(u8 *arg0, f32 arg1);
    f32 temp;
    f32 leftAngle;
    f32 right;
    f32 leftStep;
    f32 rightStep;
    s32 *cell;
    s32 count;

    func_80800564_subaddierouteDll((s32)arg0, arg1);
    if (arg5 & 0x1000) {
        arg4 = func_8080183C_subaddierouteDll((u8 *)arg0, arg4);
    }
    cell = func_800BE444(arg0->position);
    if (arg5 & 0x800) {
        func_80800D88_subaddierouteDll(arg0, arg1, arg2, arg5, cell);
    }
    temp = arg2;
    if (arg5 & 0x4000) {
        arg2 = arg3;
        arg3 = temp;
    }
    leftAngle = func_800F1DCC(arg3, arg2);
    if (func_8080160C_subaddierouteDll(arg0, (s32)arg1, arg2, arg4, arg5, cell)) {
        return 1;
    }
    if (leftAngle < 0.0f) {
        leftStep = -30.0f;
        rightStep = 30.0f;
    } else {
        leftStep = 30.0f;
        rightStep = -30.0f;
    }
    leftAngle = right = arg2;
    count = 4;
    do {
        leftAngle = func_800136E4(leftAngle + leftStep);
        if (func_8080160C_subaddierouteDll(arg0, (s32)arg1, leftAngle, arg4, arg5, cell)) {
            return 1;
        }
        right = func_800136E4(right + rightStep);
        if (func_8080160C_subaddierouteDll(arg0, (s32)arg1, right, arg4, arg5, cell)) {
            return 1;
        }
    } while (--count);
    return 0;
}

typedef struct {
        Unk80132ED0 *actor;
        s32 unknown;
        u32 unused : 31;
        u32 is_actor : 1;
    } RouteEntry;

s32 func_80800D88_subaddierouteDll(Actor *arg0, RouteResult *arg1, f32 arg2, s32 arg3, s32 *arg4) {
    s32 *func_800BE444(f32 *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE940(s16 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF11C(f32 *, s16 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_80801784_subaddierouteDll(Actor *, Unk80132ED0 *, s32, f32 *);
    f32 position[3];
    RouteEntry *entry;
    RouteEntry *end;
    struct {
        f32 position[3];
        f32 radius;
    } sphere;
    Unk80132ED0 *actor;
    f32 radius;

    radius = func_800EC708(arg0->unk0) * 0.7f;
    func_800EE7F8(position, arg0->position);
    func_800EF11C(position, (s16 *)&arg0->unk0->unk1C + 1);
    func_800EF1B8(position, arg2, 0.6f * radius);
    if (arg4 == NULL) {
        arg4 = func_800BE444(arg0->position);
    }
    for (; *arg4 != 0; arg4++) {
        entry = (RouteEntry *)func_800E9E88(*arg4);
        end = (RouteEntry *)func_800E9EB4((s16 *)*arg4);
        for (; entry < end; entry++) {
            if (entry->is_actor) {
                actor = entry->actor;
                if (func_80801784_subaddierouteDll(arg0, actor, arg3, sphere.position)) {
                    if (func_800EEB40(position, sphere.position) < (radius + sphere.radius) * (radius + sphere.radius)) {
                        func_800EE940(arg1->position, sphere.position);
                        arg1->actor = actor;
                        arg1->flags |= 4;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

s32 func_80800F34_subaddierouteDll(f32 *arg0, s32 arg1, s32 arg2, s16 *arg3) {
    void *func_8001B798(s16);
    void *func_800CC63C(s32, s32);
    int func_800F0064(f32 *, f32, f32 *);
    OSThread *func_801015B0(void);
    s16 *entries;
    u8 *data;
    u8 *point;
    s32 count;
    s32 i;
    s32 length;
    s32 found;
    s16 *end;
    void *region;

    entries = func_8001B798(*(s16 *)func_801015B0());
    data = func_8001B798(*(s16 *)((u8 *)entries + arg1 * 4));
    i = 0;
    point = data + ((s16 *)data)[arg2];
    count = *point;
    point++;
    if (count > 0) {
        do {
            found = 0;
            length = 0;
            /* Byte offsets preserve IDO's induction-variable allocation. */
            while (*(s16 *)((u8 *)arg3 + length * 2) != -1) {
                if (found == 0 && *(s16 *)((u8 *)arg3 + length * 2) == *point) {
                    found = 1;
                }
                length++;
            }
            if (found == 0) {
                region = func_800CC63C(arg1, *point);
                if (func_800F0064(region, (f32)((s16 *)region)[6], arg0) != 0) {
                    end = (s16 *)((u8 *)arg3 + length * 2);
                    end[0] = *point;
                    end[1] = -1;
                    return i;
                }
            }
            i++;
            point++;
        } while (i != count);
    }
    return -1;
}

s32 subaddierouteDll_entrypoint_8(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void *func_8001B798(s16);
    u8 func_800CC61C(s32);
    void *func_800CC63C(s32, s32);
    void *func_800CC684(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    OSThread *func_801015B0(void);
    struct RouteActor {
        u8 pad[0x70];
        u32 route_start : 7;
        u32 pad70 : 15;
        u32 route_end : 6;
        u32 pad73 : 4;
    };
    struct Region {
        f32 position[3];
        s16 radius;
        s16 height;
    } *region;
    struct RouteHandle { s16 handle; s16 references; } *handles;
    struct { s32 end; s32 pad[2]; } index;
    s32 route;
    s16 *state;
    s16 *table;
    u8 *neighbors;
    s32 count;
    s32 i;
    f32 y, height, actorY;
    f32 *position;

    route = arg0->unk70_25 - 1;
    index.end = ((struct RouteActor *)arg0)->route_end - 1;
    state = (s16 *)func_801015B0();
    count = func_800CC61C(route);
    for (i = 0; i < count; i++) {
        region = func_800CC684(route, i);
        y = region->position[1];
        height = region->height;
        actorY = arg0->position[1];
        if (y - height < actorY && actorY < y + height) {
            position = arg0->position;
            if (func_800F0064(region->position, region->radius, position)) {
                func_800EE7F8(position, arg1);
                return 1;
            }
        }
    }
    position = arg0->position;
    region = func_800CC63C(route, index.end);
    y = region->position[1];
    height = region->height;
    actorY = arg0->position[1];
    if (y - height < actorY && actorY < y + height &&
        func_800F0064(region->position, region->radius, position)) {
        return 0;
    }
    handles = func_8001B798(*state);
    table = func_8001B798(handles[route].handle);
    neighbors = (u8 *)table + table[index.end];
    count = *neighbors++;
    i = 0;
    if (count > 0) {
        do {
            region = func_800CC63C(route, *neighbors);
            y = region->position[1];
            height = region->height;
            actorY = arg0->position[1];
            if (y - height < actorY && actorY < y + height &&
                func_800F0064(region->position, region->radius, position)) {
                ((struct RouteActor *)arg0)->route_end = *neighbors + 1;
                return 0;
            }
            i++;
            neighbors++;
        } while (i != count);
    }
    func_800EE7F8(position, arg1);
    return 1;
}

s32 subaddierouteDll_entrypoint_9(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void *func_8001B798(s16);
    u8 func_800CC61C(s32);
    void *func_800CC63C(s32, s32);
    void *func_800CC684(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    int func_800F0064(f32 *, f32, f32 *);
    int func_800F00A4(f32 *, f32, f32, f32, f32 *);
    OSThread *func_801015B0(void);
    s32 func_8010BFA4(f32 *, f32 *, f32 *, f32);
    struct RouteActor {
        u8 pad[0x70];
        u32 route_start : 7;
        u32 pad70 : 15;
        u32 route_end : 6;
        u32 pad73 : 4;
    };
    struct Region {
        f32 position[3];
        s16 radius;
        s16 height;
    } *region;
    struct RouteHandle { s16 handle; s16 references; } *handles;
    struct { s32 pad[2]; s32 end; } index;
    s32 route;
    s16 *table;
    s16 *state;
    u8 *neighbors;
    s32 count;
    s32 i, j;
    f32 *position;

    route = ((struct RouteActor *)arg0)->route_start - 1;
    index.end = ((struct RouteActor *)arg0)->route_end - 1;
    state = (s16 *)func_801015B0();
    count = func_800CC61C(route);
    for (i = 0; i < count; i++) {
        position = arg0->position;
        region = func_800CC684(route, i);
        if (func_800F00A4(region->position, region->radius, region->height,
                         -region->height, position)) {
            if (arg3 & 2) {
                func_800EE7F8(position, arg1);
                return 1;
            }
            if (!func_8010BFA4(position, arg1, region->position, region->radius)) {
                return 1;
            }
            j = 0;
            if (count > 0) {
                do {
                    region = func_800CC684(route, j);
                    if (j != i && func_800F0064(region->position, region->radius, position)) {
                        func_800EE7F8(position, arg1);
                        return 1;
                    }
                    j++;
                } while (j != count);
            }
            break;
        }
    }
    position = arg0->position;
    region = func_800CC63C(route, index.end);
    if (func_800F00A4(region->position, region->radius, region->height,
                     -region->height, position)) {
        return 0;
    }
    handles = func_8001B798(*state);
    table = func_8001B798(handles[route].handle);
    neighbors = (u8 *)table + table[index.end];
    count = *neighbors++;
    i = 0;
    if (count > 0) {
        do {
            region = func_800CC63C(route, *neighbors);
            if (func_800F00A4(region->position, region->radius, region->height,
                             -region->height, position)) {
                ((struct RouteActor *)arg0)->route_end = *neighbors + 1;
                return 0;
            }
            i++;
            neighbors++;
        } while (i != count);
    }
    func_800EE7F8(position, arg1);
    return 1;
}

/* extern */

s32 func_8080160C_subaddierouteDll(Actor *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 *arg5) {
    s32 func_800DC128(s32, s32);
    s32 func_808006D0_subaddierouteDll(Actor *, s32, f32, f32, s32);
    s32 func_80800828_subaddierouteDll(void *, s32, f32, s32, s32);
    s32 func_80800A74_subaddierouteDll(void *, s32, f32, s32, s32);
    if (!(arg4 & 0x200) && (func_808006D0_subaddierouteDll(arg0, arg1, arg2, arg3, arg4) == 0)) {
        return 0;
    }
    if (!(arg4 & 0x100) && (func_80800828_subaddierouteDll(arg0, arg1, arg2, *(s32 *)&arg3, arg4) == 0)) {
        return 0;
    }
    if (!(arg4 & 0x400) && (func_80800A74_subaddierouteDll(arg0, arg1, (f32) func_800DC128(-0x14, 0x14) + arg2, *(s32 *)&arg3, arg4) == 0)) {
        return 0;
    }
    arg0->unk54 = arg2;
    return 1;
}

s32 func_808016F0_subaddierouteDll(Actor *arg0, Unk80132ED0 *arg1, s32 arg2) {
    Actor *func_80106790(Unk80132ED0 *);

    if (arg1 == arg0->unk0) {
        return 2;
    }
    if ((arg2 & 2) && (*(u16 *)&arg1->unk18 & 1)) {
        return (*(u32 *)((u8 *)func_80106790(arg1) + 0x64) >> 31) ? 0 : 4;
    }
    if ((arg2 & 1) && ((arg1->unk24 >> 22) == 0)) {
        return 1;
    }
    return 3;
}

s32 func_80801784_subaddierouteDll(Actor *arg0, Unk80132ED0 *arg1, s32 arg2, f32 *arg3) {
    s32 func_808016F0_subaddierouteDll();
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF11C(f32 *, s16 *);
    f32 func_8008FE3C(f32 *);
    Actor *sp20[2];
    s32 temp_v0;

    temp_v0 = func_808016F0_subaddierouteDll(arg0, arg1, arg2, arg3);
    switch (temp_v0) {
    case 0:
        sp20[0] = func_80106790(arg1);
        arg3[3] = func_800EC708(arg0->unk0) * 0.7f;
        func_800EE7F8(arg3, sp20[0]->position);
        func_800EF11C(arg3, (s16 *)&arg1->unk1C + 1);
        return 1;
    case 1:
        arg3[3] = func_8008FE3C(arg3) * 4.0f;
        return 1;
    default:
        return 0;
    }
}

/* extern */

f32 func_8080183C_subaddierouteDll(u8 *arg0, f32 arg1) {
    f32 func_800EFBFC(void *, void *);
    f32 func_800F0E00(f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 temp_f12;
    temp_f12 = func_800F13F0(arg1, func_800EFBFC(arg0 + 4, arg0 + 0x18));
    return func_800F0E00(temp_f12, (f32)(u32)*(u16 *)(arg0 + 0x62) * (*(f32 *)(arg0 + 0x38) * 1.2f));
}
