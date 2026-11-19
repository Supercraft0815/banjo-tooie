#include "core2/1EEC090.h"
BT_LP64_ONLY(void *defrag(void *);)
s32 func_80113FF0(void *arg0) {
    typedef struct {
        s32 unk;
        f32 value;
        u8 active;
        u8 pad[3];
    } Entry;
    typedef struct {
        u8 pad[0x48];
        Entry entries[7];
    } Data;
    Data *data = arg0;
    s32 i;
    s32 best = -1;
    f32 value = -1.0f;
    f32 current;

    for (i = 0; i < 7; i++) {
        if (data->entries[i].active != 0) {
            current = data->entries[i].value;
            if (best == -1 || current < value) {
                value = current;
                best = i;
            }
        }
    }
    return best;
}

void func_8011413C(BtIntPtr camera, f32 rotation[3], f32 scale, s32 index) {
    void func_800CA740(BtIntPtr, f32 *);
    void func_800CB0E8(BtIntPtr, f32 *, s32);
    void func_800EF334(f32 *, f32);
    if (index != 0) {
        func_800CB0E8(camera, rotation, index - 1);
    } else {
        func_800CA740(camera, rotation);
    }
    func_800EF334(rotation, scale);
}

    typedef struct {
        s32 flags;
        f32 value;
        u8 active;
        u8 pad[3];
    } CameraCollisionEntry;
    typedef struct {
        s16 index;
        u8 hit;
        u8 active;
        u8 pad4[0x10];
        f32 position[3];
        u8 pad20[0x18];
        s32 flags;
        f32 normal[3];
        CameraCollisionEntry entries[7];
    } CameraCollisionData;     
s32 func_80114184(CameraCollisionData *data, BtIntPtr camera, f32 scale, s32 enabled, u32 flags) {
    void func_800CA8F4(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 rotation[3];
    f32 position[3];
    f32 normal[3];
    f32 distance;
    f32 collisionNormal[3];
    s32 *triangle;
    s32 i;
    f32 delta[3];

    if (!enabled) {
        func_80113FF0(data);
        BT_IDO_ONLY(return;) BT_NATIVE_ONLY(return 0;)
    }
    func_800CA8F4((f32 *)camera, position, normal);
    if (data->active && func_800EEAA4(normal, data->normal) < 0.1f) {
        func_800EFB24(delta, position, data->position);
        distance = func_800EEAA4(delta, data->normal);
        data->entries[6].active = 1;
        data->entries[6].value = distance;
        data->entries[6].flags = data->flags;
    } else {
        data->entries[6].flags = 0;
        data->entries[6].active = 0;
        data->entries[6].value = -1.0f;
    }
    func_8011413C(camera, rotation, scale, data->index);
    func_800EF04C(rotation, position);
    triangle = func_800C6A7C(position, rotation, collisionNormal, flags);
    if (triangle != NULL) {
        distance = func_800EEAD4(position, rotation);
        func_800EF3DC(rotation, position);
        data->entries[data->index].flags = triangle[2];
        data->entries[data->index].active = 1;
    } else {
        distance = -1.0f;
        data->entries[data->index].flags = 0;
        data->entries[data->index].active = 0;
    }
    data->entries[data->index].value = distance;
    data->index++;
    if (data->index >= 6) {
        data->index = 0;
    }
    data->hit = 0;
    for (i = 0; i < 7; i++) {
        if (data->entries[i].flags != 0) {
            if (data->entries[i].flags & 0x20020) {
                data->hit = 1;
            } else {
                data->hit = 0;
                break;
            }
        }
    }
    func_80113FF0(data); BT_NATIVE_ONLY(return 0;)
}

/* extern */

s32 func_801143A4(f32 *arg0, f32 *arg1, f32 arg2, f32 *arg3) {
    void func_800CA8F4(f32 *, f32 *, f32 *);
    s32 func_800CACEC(f32 *, f32 *, f32);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];
    f32 temp_f12;

    func_800CA8F4(arg0, sp34, sp28);
    func_800EFB24(sp1C, arg1, sp34);
    temp_f12 = func_800EEAA4(sp1C, sp28) - arg2;
    if (temp_f12 < *arg3) {
        if (func_800CACEC(arg0, arg1, arg2) != 0) {
            *arg3 = temp_f12;
            return 1;
        }
    }
    return 0;
}

f32 func_80114444(s32 arg0) {
    s32 func_800F5410(BtIntPtr);
    if (func_800F5410(arg0) == 0xD) {
        return 1.1f;
    }
    return 0.8f;
}

/* extern */

s32 func_8011447C(f32 *arg0, f32 *arg1) {
    s32 func_800F5898();
    s32 func_800F5EF8(BtIntPtr);
    s32 func_800F6438(BtUIntPtr);
    int func_800F6640(s32);
    s32 func_800F6690(s32);
    s32 func_800F6BE4(BtIntPtr);
    PlayerState *func_80110014(s32);
    f32 temp_f20;
    s32 var_s0;
    f32 sp4C[3];
    s32 var_s2;

    var_s2 = 0;
    var_s0 = 0;
    if (func_800F5898() > 0) {
        do {
            if ((func_800F6BE4(var_s0) != 0) && (func_800F6BE4(var_s0) != 0) && (func_800F6438(var_s0) != 0) && (func_800F6640(var_s0) != 0) && (func_800F6690(var_s0) != 0)) {
                temp_f20 = func_80112550(func_80110014(func_800F5EF8(var_s0)), sp4C);
                var_s2 |= func_801143A4(arg0, sp4C, func_80114444(var_s0) * temp_f20, arg1);
            }
            var_s0 += 1;
        } while (var_s0 < func_800F5898());
    }
    return var_s2;
}

s32 func_8011458C(f32 *arg0, f32 *arg1, f32 *arg2) {
    typedef struct {
        Unk80132ED0 *actor;
        s32 unknown;
        BT_BITFIELD_ORDER(unsigned int unused : 27, unsigned int is_actor : 1);
        BT_BITFIELD_ORDER(unsigned int active : 1, unsigned int ready : 1);
        BT_BITFIELD_ORDER(unsigned int group : 1, unsigned int unknown2 : 1);
        BT_BITFIELD_ORDER(unsigned int unknown2 : 1, unsigned int group : 1);
        BT_BITFIELD_ORDER(unsigned int ready : 1, unsigned int active : 1);
        BT_BITFIELD_ORDER(unsigned int is_actor : 1, unsigned int unused : 27);
    } Prop;
    s32 *func_800BE444(f32 *);
    BtIntPtr func_800E9E88(BtIntPtr);
    BtUIntPtr func_800E9EB4(s16 *);
    f32 func_800EC75C(void *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_801072A8(void *);
    f32 scale;
    s32 *list;
    BtUIntPtr prop;
    BtUIntPtr end;
    Unk80132ED0 *marker;
    f32 sp60[3];
    Actor *actor;
    s32 hit;
    typedef struct { BT_BITFIELD_ORDER(unsigned int unused : 17, unsigned int rest : 14); unsigned int enabled : 1; BT_BITFIELD_ORDER(unsigned int rest : 14, unsigned int unused : 17); } Flags;

    list = func_800BE444(arg1);
    hit = 0;
    if (*list != 0) { scale = 0.8f; do { prop = func_800E9E88(*list);
        end = func_800E9EB4((s16 *)*list);
        for (; prop < end; prop += 12) {
            if (((Prop *)prop)->active && ((Prop *)prop)->is_actor && !((Prop *)prop)->group) {
                marker = ((Prop *)prop)->actor;
                if ((((u16 *)&marker->unk18)[0] & 1) && marker->unk14 != 0 && marker->unk14 != 0xFFFF) {
                    actor = func_80106790(marker);
                    if (((Flags *)&actor->pad94)->enabled && !actor->unk64_17 && !func_801072A8(actor)) {
                        if (func_801143A4(arg0, sp60, func_800EC75C(marker, sp60) * scale, arg2)) {
                            hit = 1;
                            if (*arg2 < 0.0f) {
                                *arg2 = 0.0f;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (prop < end) {
            break;
        }
        list++;
    } while (*list != 0);
    }
    if (hit && *arg2 < 25.0f) {
        *arg2 = 25.0f;
    }
    return hit;
}

f32 func_80114774(CameraCollisionData *arg0, BtIntPtr arg1, BtIntPtr arg2, BtIntPtr arg3) {
    s32 func_800C954C(void);
    f32 func_800C9588(void);
    f32 func_800F0E00(f32, f32);
    f32 func_800F13F0(f32, f32);
    s32 func_8011458C(f32 *, f32 *, f32 *);
    f32 sp44[3];
    f32 value;
    f32 minimum;
    s32 index;

    index = func_80114184(arg0, arg1, func_800F0E00(350.0f, *(f32 *)((u8 *)arg0 + 0xC)), 1, 0x820020);
    value = *(f32 *)((u8 *)arg0 + 0xC);
    if (index != -1) {
        value = func_800F13F0(value, arg0->entries[index].value * 0.8f - 15.0f);
    }
    sp44[2] = value;
    if (func_8011447C((f32 *)arg1, &sp44[2])) {
        if (sp44[2] < 0.0f) {
            sp44[2] = 0.0f;
        }
        value = func_800F13F0(value, sp44[2]);
    }
    sp44[2] = value;
    if (value > 25.0f && func_8011458C(arg1, arg3, &sp44[2])) {
        value = func_800F13F0(value, sp44[2]);
    }
    if (func_800C954C()) {
        value = func_800F13F0(value, func_800C9588() * 0.8f);
    }
    if (arg0->hit) {
        minimum = 25.0f;
    } else {
        minimum = 10.0f;
    }
    if (value < minimum) {
        value = minimum;
    }
    return value;
}

void func_8011490C(CameraCollisionData *arg0, s32 *arg1, s32 arg2) {
    s32 func_800A940C(s32);
    void func_800BCC28(BtIntPtr, BtIntPtr);
    int func_800BCC58(void);
    void func_800BED18(s32 *, s32 *);
    f32 func_800C5190(s32);
    void func_800CA8F4(f32 *, f32 *, f32 *);
    s32 func_800E36D0(s32 *, s32 *, f32 *, f32 *);
    void func_800EE84C(f32 *, s32 *);
    f32 func_800F13F0(f32, f32);
    BtIntPtr func_8010FF80(s32 *);
    f32 position[3];
    f32 direction[3];
    s32 minimum[3];
    s32 maximum[3];
    BtIntPtr camera;
    s32 i;
    f32 transformedMin[3];
    f32 transformedMax[3];
    f32 scale;

    camera = func_8010FF80(arg1);
    func_800BED18(minimum, maximum);
    func_800CA8F4((f32 *)camera, position, direction);
    if (func_800BCC58()) {
        func_800EE84C(transformedMin, minimum);
        func_800EE84C(transformedMax, maximum);
        func_800BCC28((BtIntPtr)transformedMin, (BtIntPtr)transformedMin);
        func_800BCC28((BtIntPtr)transformedMax, (BtIntPtr)transformedMax);
        for (i = 0; i < 3; i++) {
            if (transformedMin[i] < minimum[i]) {
                minimum[i] = transformedMin[i];
            }
            if (maximum[i] < transformedMax[i]) {
                maximum[i] = transformedMax[i];
            }
            if (maximum[i] < transformedMin[i]) {
                maximum[i] = transformedMin[i];
            }
            if (transformedMax[i] < minimum[i]) {
                minimum[i] = transformedMax[i];
            }
        }
    }
    *(f32 *)((u8 *)arg0 + 0x10) = func_800E36D0(minimum, maximum, position, direction) + 100.0f;
    if (*(f32 *)((u8 *)arg0 + 0x10) < 1000.0f) {
        *(f32 *)((u8 *)arg0 + 0x10) = 1000.0f;
    } else if (*(f32 *)((u8 *)arg0 + 0x10) > 32000.0f) {
        *(f32 *)((u8 *)arg0 + 0x10) = 32000.0f;
    }
    *(f32 *)((u8 *)arg0 + 0xC) = *(f32 *)((u8 *)arg0 + 0x10) * 0.0078125f;
    if (*(f32 *)((u8 *)arg0 + 8) > 0.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) = *(f32 *)((u8 *)arg0 + 8);
    } else if (*(f32 *)((u8 *)arg0 + 0xC) < 10.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) = 10.0f;
    } else {
        *(f32 *)((u8 *)arg0 + 0xC) = func_800F13F0(*(f32 *)((u8 *)arg0 + 0xC), func_80114774(arg0, camera, (BtIntPtr)arg1, (BtIntPtr)position));
    }
    scale = 1.0f / func_800C5190(func_800A940C(arg2));
    if (scale != 1.0f) {
        *(f32 *)((u8 *)arg0 + 0xC) *= scale;
        *(f32 *)((u8 *)arg0 + 0x10) *= scale;
    }
    if (*(f32 *)((u8 *)arg0 + 8) > 0.0f && arg0->pad4[0]) {
        arg0->pad4[0] = 0;
        *(f32 *)((u8 *)arg0 + 8) = 0.0f;
    }
    arg0->active = 0;
}

void *func_80114BD4(void) {
    void *heap_alloc(s32);
    u8 *ptr;
    s32 i;

    ptr = heap_alloc(0x9C);
    *(s8 *)(ptr + 2) = 0;
    *(s16 *)(ptr + 0) = 0;
    *(s8 *)(ptr + 3) = 0;
    *(s8 *)(ptr + 4) = 0;
    *(f32 *)(ptr + 8) = 0.0f;
    for (i = 0; i < 7; i++) {
        *(s32 *)(ptr + 0x48 + i * 0xC) = 0;
        *(f32 *)(ptr + 0x4C + i * 0xC) = -1.0f;
        *(s8 *)(ptr + 0x50 + i * 0xC) = 0;
    }
    return ptr;
}

void func_80114C7C(void* arg0)
{
    heap_free(arg0);
}               typedef struct { u8 pad0[0x3]; s8 unk3; s8 unk4; u8 pad5[0x3]; f32 unk8; f32 unkC; f32 unk10; u8 pad14[0x24]; s32 unk38; } Obj1EED8E0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void func_80114C9C(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (((Obj1EED8E0_arg0 *)arg0)->unkC);
    *arg2 = (((Obj1EED8E0_arg0 *)arg0)->unk10);
}

void func_80114CB0(void *arg0, f32 arg1) {
    (((Obj1EED8E0_arg0 *)arg0)->unk4) = 0;
    (((Obj1EED8E0_arg0 *)arg0)->unk8) = arg1;
}

void func_80114CC0(void *arg0, f32 arg1) {
    (((Obj1EED8E0_arg0 *)arg0)->unk4) = 1;
    (((Obj1EED8E0_arg0 *)arg0)->unk8) = arg1;
}

void* func_80114CD4(void* arg0)
{
    return defrag(arg0);
}
/* extern */

void func_80114CF4(u8 *arg0, f32 *arg1, s32 arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    s32 var_s0;
    f32 *var_s1;
    f32 *var_s2;

    if (!(arg2 & 0x40000)) {
        var_s0 = 0;
        var_s1 = (f32 *)(arg0 + 0x14);
        var_s2 = arg1;
        do {
            func_800EE7F8(var_s1, var_s2);
            var_s0 += 0xC;
            var_s1 += 3;
            var_s2 += 3;
        } while (var_s0 != 0x24);
        func_800EE7F8((f32 *)(arg0 + 0x3C), arg3);
        (((Obj1EED8E0_arg0 *)arg0)->unk38) = arg2;
        (((Obj1EED8E0_arg0 *)arg0)->unk3) = 1;
    }
}
