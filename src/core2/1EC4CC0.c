#include "common.h"
#ifdef BT_NATIVE
#include "native_world_grid.h"
#include "native_actor.h"
#include "native_model.h"
#include "vector.h"
#include "memory.h"
#include "core2/1EAF950.h"
#include "core2/1EC8070.h"

typedef struct { NativeMarkerProp *prop; s32 distance; } MarkerGroupElement;
static struct {
    s32 position[3], distance, type;
    void *cube, *prop;
    s32 kind;
    s32 (*filter)(s16 *, uintptr_t);
    uintptr_t userdata;
} marker_search;
static Unk80132ED0 marker_pool[200];
static u8 marker_used[25];
static s32 marker_generation;

/* World cells retain ownership of their movable prop arrays. */
s32 func_800DC214(s32, s32);
void func_800E3A30(s16 *);
void _gspropprop_entrypoint_2(void *);
void _gspropprop_entrypoint_3(void *, s32);
void func_800CDFD0(void *);
f32 func_800136E4(f32);
s32 func_800B0CFC(void *);
void *func_801039E4(void *);
s32 func_8010A79C(Actor *, s32);
#endif

typedef struct {
#ifdef BT_NATIVE
    Vector *entries[7];
#else
    s32 entries[7];
#endif
    s16 selected;
} EntryGroup;

EntryGroup D_80132E80;

#ifdef BT_NATIVE
void func_800EB3D0(void *data, s32 group, s16 *origin) {
    NativeMarkerProp *prop = data;
    MarkerGroupElement *begin, *end, *current;
    Vector **vec;
    s32 dx, dy, dz, distance;
    if (group < 0 || group >= 7) return;
    vec = &D_80132E80.entries[group];
    if (!*vec) *vec = vector_new(sizeof(MarkerGroupElement), 5);
    vector_push_back(vec);
    dx = prop->position[0] - origin[0];
    dy = prop->position[1] - origin[1];
    dz = prop->position[2] - origin[2];
    distance = dx*dx + dy*dy + dz*dz;
    begin = vector_begin(*vec);
    end = (MarkerGroupElement *)vector_end(*vec) - 1;
    current = end;
    while (current > begin && distance >= current[-1].distance) --current;
    if (current < end) aligned4_memmove(current + 1, current, (end-current)*sizeof(*current));
    current->distance = distance;
    current->prop = prop;
}
#else
void func_800EB3D0(void *arg0, s32 arg1, s16 *arg2) {
    typedef struct { void *prop; s32 distance; } Element;
    void aligned4_memmove(void *, void *, int);
    void *vector_begin(s32);
    void *vector_end(s32);
    s32 vector_new(s32, s32);
    void *vector_push_back(void **);
    s32 dx, dy, dz;
    Element *current;
    Element *begin;
    Element *end;
    s32 vector;
    s32 *vec;

    vec = &D_80132E80.entries[arg1];
    if (*vec == 0) {
        *vec = vector_new(8, 5);
    }
    vector_push_back((void **)vec);
    vector = *vec;
    dx = ((s16 *)arg0)[2] - arg2[0];
    dy = ((s16 *)arg0)[3] - arg2[1];
    dz = ((s16 *)arg0)[4] - arg2[2];
    dx = dx * dx + dy * dy + dz * dz;
    begin = vector_begin(vector);
    end = (Element *)vector_end(vector) - 1;
    current = end - 1;
    while (current >= begin) {
        if (dx < current->distance) {
            break;
        }
        current--;
    }
    current++;
    if (current < end) {
        aligned4_memmove(current + 1, current, (end - current) * sizeof(Element));
    }
    current->distance = dx;
    current->prop = arg0;
}
#endif

#ifdef BT_NATIVE
void func_800EB51C(s32 group, s32 mode) {
    Vector *vec;
    MarkerGroupElement *current, *end;
    if (group < 0 || group >= 7 || !(vec = D_80132E80.entries[group])) return;
    current = vector_begin(vec); end = vector_end(vec);
    if (current != end) D_80132E80.selected = group;
    for (; current < end; ++current) {
        NativeMarkerProp *prop = current->prop;
        if (prop->flags & 1) func_800EC7D4(prop->marker, mode);
        else _gspropprop_entrypoint_3(prop, mode);
    }
}
#else
void func_800EB51C(s32 arg0, s32 arg1) {
    typedef struct {
        Unk80132ED0 *actor;
        s32 unknown;
        u32 flags;
    } Prop;
    typedef struct { Prop *prop; s32 unknown; } Element;
    void *vector_begin(s32);
    void *vector_end(s32);
    void func_800EC7D4(Unk80132ED0 *, s32);
    void _gspropprop_entrypoint_3(void *, s32);
    s32 vector;
    Element *end;
    Element *start;
    Element *current;
    Prop *prop;

    vector = D_80132E80.entries[arg0];
    if (vector != 0) {
        start = vector_begin(vector);
        end = vector_end(vector);
        if (end != start) {
            D_80132E80.selected = arg0;
            for (current = start; current < end; current++) {
                prop = current->prop;
                if (prop->flags & 1) {
                    func_800EC7D4(prop->actor, arg1);
                } else {
                    _gspropprop_entrypoint_3(prop, arg1);
                }
            }
        }
    }
}
#endif

#ifdef BT_NATIVE
void func_800EB5E0(void *cube, s32 unused) {
    s16 origin[3];
    NativeMarkerProp *prop, *end;
    (void)unused;
    func_800E3A30(origin);
    prop = func_800E9E88(cube); end = func_800E9EB4(cube);
    for (; prop && prop < end; ++prop) {
        if (!(prop->flags & 0x10)) continue;
        if (!(prop->flags & 2)) _gspropprop_entrypoint_2(prop);
        if (prop->flags & 1) {
            if (func_800EC800(prop->marker)) {
                for (s32 i=0; i<7; ++i)
                    if ((prop->marker->unk28 >> 1) & (1u << i)) func_800EB3D0(prop, i, origin);
            }
        } else func_800EB3D0(prop, (prop->flags & 8) ? 1 : 0, origin);
    }
}
#else
void func_800EB5E0(s32 arg0, s32 arg1) {
    typedef struct {
        Unk80132ED0 *actor;
        s32 unknown;
        unsigned int unused : 27;
        unsigned int active : 1;
        unsigned int group : 1;
        unsigned int unknown2 : 1;
        unsigned int ready : 1;
        unsigned int is_actor : 1;
    } Prop;
    void _gspropprop_entrypoint_2(void *);
    void func_800E3A30(s32);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    int func_800EC800(void *);
    s32 group;
    s32 i;
    s16 sp40[3];
    u32 end;
    u32 prop;
    Unk80132ED0 *actor;

    func_800E3A30((s32)sp40);
    prop = func_800E9E88(arg0);
    end = func_800E9EB4((s16 *)arg0);
    if (prop < end) {
        do {
            if (((Prop *)prop)->active) {
                if (!((Prop *)prop)->ready) {
                    _gspropprop_entrypoint_2((void *)prop);
                }
                if (((Prop *)prop)->is_actor) {
                    actor = ((Prop *)prop)->actor;
                    if (func_800EC800(actor) != 0) {
                        i = 0;
                        do {
                            if (((actor->unk28 << 23) >> 24) & (1 << i)) {
                                func_800EB3D0((void *)prop, i, sp40);
                            }
                            i++;
                        } while (i != 7);
                    }
                } else {
                    if (((Prop *)prop)->group) {
                        group = 1;
                    } else {
                        group = 0;
                    }
                    func_800EB3D0((void *)prop, group, sp40);
                }
            }
            prop += 12;
        } while (prop < end);
    }
}
#endif

void func_800EB70C(void) {
    s32 i;

    D_80132E80.selected = -1;
    for (i = 0; i < 7; i++) {
        D_80132E80.entries[i] = 0;
    }
}

#ifdef BT_NATIVE
void func_800EB750(void) {
    for (Vector **vec=D_80132E80.entries; vec<D_80132E80.entries+7; ++vec) {
        if (*vec) { vector_free(*vec); *vec = NULL; }
    }
}
#else
void func_800EB750(void)
{
  s32 vector_free(s32);
  s32 (*var_s0)[1];


  s32 temp_a0;
 var_s0 = (s32 (*)[1]) (D_80132E80.entries); do {
    temp_a0 = var_s0[0][0];
    if (temp_a0 != 0)
    {
      vector_free(temp_a0);
      var_s0[0][0] = 0;
    }
    var_s0++;
  }
  while (((s16 *) var_s0) != (((s16 *)(D_80132E80.entries + 7))));
}
#endif

#ifdef BT_NATIVE
void func_800EB7A8(void) {
    for (Vector **vec=D_80132E80.entries; vec<D_80132E80.entries+7; ++vec) {
        if (*vec) { *vec = vector_defrag(*vec); }
    }
}
#else
void func_800EB7A8(void) {
    s32 vector_defrag(s32);
    s32 *current;
    s32 *end;
    s32 value;

    current = (end = D_80132E80.entries + 7, D_80132E80.entries);
    do {
        value = *current;
        if (value != 0) {
            *current = vector_defrag(value);
        }
        current++;
    } while (current != end);
}
#endif

#ifdef BT_NATIVE
void func_800EB800(void) {
    for (Vector **vec=D_80132E80.entries; vec<D_80132E80.entries+7; ++vec) {
        if (*vec) { vector_clear(*vec); }
    }
}
#else
void func_800EB800(void) {
    s32 vector_clear(s32);
    s32 *current;
    s32 *end;
    s32 value;

    current = (end = D_80132E80.entries + 7, D_80132E80.entries);
    do {
        value = *current;
        if (value != 0) {
            vector_clear(value);
        }
        current++;
    } while (current != end);
}
#endif

s32 func_800EB854(void) {


    return D_80132E80.selected;
}

#ifdef BT_NATIVE
void func_800EB860(s32 (*filter)(s16 *, uintptr_t), uintptr_t data) {
    marker_search.filter = filter;
    marker_search.userdata = data;
}
#else
void func_800EB860(s32 arg0, s32 arg1) {
    extern s32 D_80132EA0;
    (*(s32 *)((s8 *)(&D_80132EA0) + (0x20))) = arg0;
    (*(s32 *)((s8 *)(&D_80132EA0) + (0x24))) = arg1;
}
#endif

#ifdef BT_NATIVE
void func_800EB874(void) { marker_search.filter = NULL; }
#else
void func_800EB874(void)
{
    extern s32 D_80132EC0;

    D_80132EC0 = 0;
}
#endif

#ifdef BT_NATIVE
void func_800EB880(s32 *position, s32 type, s32 radius) {
    func_800EE830(marker_search.position, position);
    marker_search.type = type;
    marker_search.distance = radius * radius;
    marker_search.cube = marker_search.prop = NULL;
    marker_search.kind = 0;
}
#else
void func_800EB880(s32 *arg0, s32 arg1, s32 arg2) {
    extern s32 D_80132EA0;
    s32 *dst = &D_80132EA0;
    dst[0] = arg0[0];
    dst[1] = arg0[1];
    dst[2] = arg0[2];
    dst[4] = arg1;
    dst[5] = 0;
    dst[3] = arg2 * arg2;
    dst[6] = 0;
    dst[7] = 0;
}
#endif

#ifdef BT_NATIVE
void func_800EB8C0(void *cube) {
    s32 x, y, z, distance, group;
    if (func_800E9DCC(cube) && (marker_search.type==1 || marker_search.type==2)) {
        NativeMarkerProp *prop=func_800E9E88(cube), *end=func_800E9EB4(cube);
        for (; prop<end; ++prop) {
            if (prop->flags & 1) continue;
            x=prop->position[0]-marker_search.position[0];
            y=prop->position[1]-marker_search.position[1];
            z=prop->position[2]-marker_search.position[2];
            distance=x*x+y*y+z*z;
            group=(prop->flags & 2) ? 2 : 1;
            if (distance<marker_search.distance && group==marker_search.type) {
                marker_search.distance=distance; marker_search.cube=cube;
                marker_search.prop=prop; marker_search.kind=group;
            }
        }
    }
    if (func_800E9DC4(cube) && marker_search.type==3) {
        Prop *prop=func_800E9D68(cube), *end=func_800E9D90(cube);
        for (; prop<end; ++prop) {
            x=prop->position[0]-marker_search.position[0];
            y=prop->position[1]-marker_search.position[1];
            z=prop->position[2]-marker_search.position[2];
            distance=x*x+y*y+z*z;
            if (distance>=marker_search.distance) continue;
            if (marker_search.filter) {
                if (!marker_search.filter(prop->position, marker_search.userdata)) continue;
                x=prop->position[0]-marker_search.position[0];
                y=prop->position[1]-marker_search.position[1];
                z=prop->position[2]-marker_search.position[2];
                distance=x*x+y*y+z*z;
            }
            marker_search.distance=distance; marker_search.cube=cube;
            marker_search.prop=prop; marker_search.kind=3;
        }
    }
}
#else
void func_800EB8C0(s32 arg0) {
    typedef struct {
        s32 unk0;
        s16 x, y;
        signed int z : 16;
        unsigned int unused : 14;
        unsigned int type : 1;
        unsigned int disabled : 1;
    } Entry;
    Prop *func_800E9D68(s16 *);
    u32 func_800E9D90(s16 *);
    s32 func_800E9DC4(s16 *);
    s32 func_800E9DCC(s16 *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    extern s32 D_80132EA0;
    Entry *entry;
    s16 *prop;
    u32 end;
    u32 prop_end;
    s32 distance;
    s32 x1, y1, z1, distance1;
    s32 x, y, z;
    s32 type;
    s32 group;

    if (func_800E9DCC((s16 *)arg0) && ((type = (*(s32 *)((s8 *)&D_80132EA0 + 0x10))) == 1 || type == 2)) {
        entry = (Entry *)func_800E9E88((s32)arg0);
        end = func_800E9EB4((s16 *)arg0);
        for (; (u32)entry < end; entry++) {
            if (!entry->disabled) {
                z1 = entry->z - (*(s32 *)((s8 *)&D_80132EA0 + 0x8));
                x1 = entry->x - (*(s32 *)((s8 *)&D_80132EA0 + 0x0));
                y1 = entry->y - (*(s32 *)((s8 *)&D_80132EA0 + 0x4));
                distance1 = z1*z1 + x1*x1 + y1*y1;
                if (distance1 < (*(s32 *)((s8 *)&D_80132EA0 + 0xC))) {
                    group = entry->type ? 2 : 1;
                    type = (*(s32 *)((s8 *)&D_80132EA0 + 0x10));
                    if (group == type) {
                    (*(s32 *)((s32)&D_80132EA0 + 0xC)) = distance1;
                    (*(s32 *)((s8 *)&D_80132EA0 + 0x14)) = (s32)arg0;
                    (*(s32 *)((s8 *)&D_80132EA0 + 0x18)) = (s32)entry;
                    (*(s32 *)((s8 *)&D_80132EA0 + 0x1C)) = type;
                    }
                }
            }
        }
    }
    if (func_800E9DC4((s16 *)arg0) && (*(s32 *)((s8 *)&D_80132EA0 + 0x10)) == 3) {
        prop = (s16 *)func_800E9D68((s16 *)arg0);
        prop_end = func_800E9D90((s16 *)arg0);
        for (; (u32)prop < prop_end; prop += 10) {
            z = prop[2] - (*(s32 *)((s8 *)&D_80132EA0 + 0x8));
            x = prop[0] - (*(s32 *)((s8 *)&D_80132EA0 + 0x0));
            y = prop[1] - (*(s32 *)((s8 *)&D_80132EA0 + 0x4));
            distance = z*z + x*x + y*y;
            if (distance < (*(s32 *)((s8 *)&D_80132EA0 + 0xC))) {
                if ((*(s32 (**)(s16 *, s32))((s8 *)&D_80132EA0 + 0x20))) {
                    if (!((*(s32 (**)(s16 *, s32))((s8 *)&D_80132EA0 + 0x20)))(prop, (*(s32 *)((s8 *)&D_80132EA0 + 0x24)))) {
                        continue;
                    }
                    z = prop[2] - (*(s32 *)((s8 *)&D_80132EA0 + 0x8));
                    x = prop[0] - (*(s32 *)((s8 *)&D_80132EA0 + 0x0));
                    y = prop[1] - (*(s32 *)((s8 *)&D_80132EA0 + 0x4));
                    distance = z*z + x*x + y*y;
                }
                (*(s32 *)((s32)&D_80132EA0 + 0xC)) = distance;
                (*(s32 *)((s8 *)&D_80132EA0 + 0x14)) = (s32)arg0;
                (*(s32 *)((s8 *)&D_80132EA0 + 0x18)) = (s32)prop;
                (*(s32 *)((s8 *)&D_80132EA0 + 0x1C)) = (*(s32 *)((s8 *)&D_80132EA0 + 0x10));
            }
        }
    }
}
#endif

#ifdef BT_NATIVE
s32 func_800EBB30(void **cube, void **prop) {
    *cube=marker_search.cube; *prop=marker_search.prop; return marker_search.kind;
}
#else
s32 func_800EBB30(s32 *arg0, s32 *arg1) {
    extern s32 D_80132EA0;
    *arg0 = (*(s32 *)((s8 *)(&D_80132EA0) + (0x14)));
    *arg1 = (*(s32 *)((s8 *)(&D_80132EA0) + (0x18)));
    return (*(s32 *)((s8 *)(&D_80132EA0) + (0x1C)));
}
#endif

#ifdef BT_NATIVE
OSThread *func_800EBB50(void) {
    static uintptr_t callbacks[5];
    return (OSThread *)callbacks;
}
#else
OSThread *func_800EBB50(void)
{
    extern u8 D_80123540[];

    return (OSThread *) D_80123540;
}
#endif

#ifdef BT_NATIVE
void func_800EBB5C(void) { marker_generation=0x6B7; }
#else
void func_800EBB5C(void) {
    extern s32 D_8013546C;
    D_8013546C = 0x6B7;
}
#endif

void func_800EBB6C(void) {
}

#ifdef BT_NATIVE
s32 func_800EBB74(void) { return 1; }
#else
s32 func_800EBB74(void) {
    extern s32 D_80132ED0;
    return (s32)&D_80132ED0 ? 1 : 0;
}
#endif

#ifdef BT_NATIVE
void func_800EBB94(void) {
    for (s32 i=0; i<25; ++i) marker_used[i]=0;
    for (s32 i=0; i<200; ++i) marker_pool[i].unk10 &= 0xFFFF0001u;
}
#else
void func_800EBB94(void) {
    extern s32 D_80132ED0;
    struct {
        u16 records[200][24];
        s8 flags[25];
    } *state = (void *)&D_80132ED0;
    s32 i;

    for (i = 0; i < 25; i++) {
        state->flags[i] = 0;
    }
    for (i = 0; i < 200; i++) {
        state->records[i][9] &= 1;
    }
}
#endif

void func_800EBC04(void) {
}

#ifdef BT_NATIVE
void func_800EBC0C(void *cube, s32 *position, void *data, s32 model) {
    Unk80132ED0 *marker=data;
    NativeMarkerProp *prop=func_800E99E0(cube);
    if (!prop) return;
    for (s32 i=0; i<3; ++i) prop->position[i]=position[i];
    prop->marker=marker;
    prop->flags=(prop->flags & 0x1D) | ((model & 1)<<1) | ((func_800DC214(0,0x20) & 31)<<6);
    marker->unk0=(u32 *)prop;
    marker->cube_index=func_800BD948(cube);
}
#else
void func_800EBC0C(s32 arg0, s32 *arg1, void *arg2, s32 arg3) {
    typedef struct {
        void *owner;
        s16 position[3];
        u16 frame : 5;
        u16 random : 5;
        u16 flag20 : 1;
        u16 flag10 : 1;
        u16 flag8 : 1;
        u16 flag4 : 1;
        u16 isModelProp : 1;
        u16 isActorProp : 1;
    } Prop;
    s32 func_800BD948(s32);
    s32 func_800DC214(s32, s32);
    void *func_800E99E0(void);
    Prop *prop;

    prop = func_800E99E0();
    prop->position[0] = arg1[0];
    prop->position[1] = arg1[1];
    prop->position[2] = arg1[2];
    prop->owner = arg2;
    prop->isModelProp = arg3;
    prop->frame = 0;
    prop->flag20 = 0;
    prop->random = func_800DC214(0, 0x20);
    *(Prop **)arg2 = prop;
    *(s16 *)((u8 *)arg2 + 0x1C) = func_800BD948(arg0);
}
#endif

#ifdef BT_NATIVE
void func_800EBCD0(void *data, s32 *position, void *old_cube, void *new_cube) {
    Unk80132ED0 *marker=data;
    /* Reserve before removal so a failed allocation preserves the old position. */
    NativeMarkerProp *prop=func_800E99E0(new_cube), *old_prop;
    if (!prop) return;
    old_prop=(void *)marker->unk0;
    prop->marker=marker;
    prop->flags=old_prop->flags;
    for (s32 i=0; i<3; ++i) prop->position[i]=position[i];
    func_800DC214(0,0x20); /* The original reattachment consumes one random value. */
    marker->unk0=(u32 *)prop;
    marker->cube_index=func_800BD948(new_cube);
    func_800E9AC0(old_cube, old_prop);
}
#else
void func_800EBCD0(u8 **arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800E9AC0(s32, s32);
    void func_800EBC0C(s32, s32 *, void *, s32);
    volatile struct {
        u16 pad[3];
        u16 saved;
        u32 tail[2];
    } local;
    u8 *temp_a1;
    s32 result;

    temp_a1 = *arg0;
    local.saved = (*(u16 *)((s8 *)(temp_a1) + (0xA)));
    result = func_800E9AC0(arg2, (s32) temp_a1);
    func_800EBC0C(arg3, arg1, arg0, result);
    (*(u16 *)((s8 *)(*arg0) + (0xA))) = local.saved;
}
#endif

/* extern */

#ifdef BT_NATIVE
void func_800EBD2C(void *data, s32 *position, s32 index) {
    Unk80132ED0 *marker=data;
    func_800EBCD0(marker, position, func_800BDB9C(marker->cube_index), func_800BDB9C(index));
}
#else
void func_800EBD2C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800BDB9C(s32);
    void func_800EBCD0(u8 **, s32, s32, s32);
    s32 pad;
    s32 sp18;

    sp18 = func_800BDB9C(*(s16 *)((s8 *) arg0 + 0x1C));
    pad = 0;
    func_800EBCD0(arg0, arg1, sp18, func_800BDB9C(arg2));
}
#endif

#ifdef BT_NATIVE
void *func_800EBD78(void) {
    for (s32 bucket=0; bucket<25; ++bucket) {
        if (marker_used[bucket]==0xFF) continue;
        for (s32 slot=0; slot<8; ++slot) {
            u8 bit=0x80 >> slot;
            if (!(marker_used[bucket] & bit)) {
                marker_used[bucket] |= bit;
                return &marker_pool[bucket*8+slot];
            }
        }
    }
    return NULL;
}
#else
void *func_800EBD78(void) {
    extern s32 D_80132ED0;
    extern u8 D_80135450;
    s32 temp_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_v1;
    void *temp_a0;

    var_v1 = 0;
    if (D_80135450 == 0xFF) {
loop_2:
        var_v1 += 1;
        if (var_v1 < 0x19) {
            if (*((u8 *)&D_80132ED0 + var_v1 + 0x2580) == 0xFF) {
                goto loop_2;
            }
        }
    }
    if (var_v1 == 0x19) {
        return NULL;
    }
    temp_a0 = (u8 *)&D_80132ED0 + var_v1;
    temp_a1 = (*(u8 *)((s8 *)(temp_a0) + (0x2580)));
    var_a2 = 0x80;
    var_a3 = 0;
    while (temp_a1 & var_a2) {
        var_a2 >>= 1;
        var_a3 += 1;
    }
    (*(u8 *)((s8 *)(temp_a0) + (0x2580))) = (u8) (temp_a1 | var_a2);
    return (u8 *)&D_80132ED0 + (var_v1 * 0x180) + (var_a3 * 0x30);
}
#endif

#ifdef BT_NATIVE
void func_800EBE24(void *data) {
    uintptr_t offset=(uintptr_t)data-(uintptr_t)marker_pool;
    size_t index;
    if (offset>=sizeof(marker_pool) || offset%sizeof(marker_pool[0])) return;
    index=offset/sizeof(marker_pool[0]);
    marker_pool[index].unk10 &= 0xFFFF0001u;
    marker_used[index>>3] &= ~(0x80u >> (index & 7));
}
#else
void func_800EBE24(void *arg0) {
    extern s32 D_80123554;
    extern s32 D_80132ED0;
    u8 *base;
    s32 temp_v0;
    u8 *temp_v1;

    base = (u8 *) &D_80132ED0;
    temp_v0 = (s32) arg0 - (s32) base;
    *(u16 *) ((s8 *) arg0 + 0x12) &= 1;
    temp_v1 = base;
    temp_v1 += temp_v0 / 48 >> 3;
    *(temp_v1 + 0x2580) = *(temp_v1 + 0x2580) & *((s32 *) &D_80123554 + (temp_v0 / 48 & 7));
}
#endif

/* extern */

#ifdef BT_NATIVE
void func_800EBE74(s32 *position, void *data, s32 model) {
    Unk80132ED0 *marker=data;
    void *cube=(marker->unk10 & 1) ? func_800BDC44() : func_800BDBC4(position);
    func_800EBC0C(cube, position, marker, model);
}
#else
void func_800EBE74(s32 arg0, void *arg1, s32 arg2) {
    s32 func_800BDBC4(s32);
    s32 func_800BDC44();
    void func_800EBC0C(s32, s32 *, void *, s32);
    s32 var_v0;

    if ((*(s32 *)((s8 *)(arg1) + (0x10))) & 1) {
        var_v0 = func_800BDC44();
    } else {
        var_v0 = func_800BDBC4(arg0);
    }
    func_800EBC0C(var_v0, arg0, arg1, arg2);
}
#endif

/* extern */

#ifdef BT_NATIVE
void *func_800EBED4(s32 *position, s32 model, s32 type, s32 flags) {
    Unk80132ED0 *marker=func_800EBD78();
    if (!marker) return NULL;
    bzero(marker, sizeof(*marker));
    marker->unk10=((u32)func_800EC854()<<1) | (flags & 1);
    marker->unk24=((u32)type & 0x3FF)<<22;
    marker->callback=func_800EBB50;
    marker->unk28=1u<<9;
    func_800EBE74(position, marker, model);
    if (!marker->unk0) { func_800EBE24(marker); return NULL; }
    return marker;
}
#else
void *func_800EBED4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct Entry {
        u8 pad0[8];
        OSThread *(*callback)(void);
        u8 padC[6];
        u16 id : 15;
        u16 flag : 1;
        u8 pad14[16];
        u16 type : 10;
        u16 low24 : 6;
        u8 pad26[4];
        u8 high2A : 6;
        u8 active : 1;
        u8 low2A : 1;
        u8 pad2B[5];
    };
    s32 func_800EC854(void);
    struct Entry *entry;

    entry = func_800EBD78();
    bzero(entry, 0x30);
    entry->id = func_800EC854();
    entry->type = arg2;
    entry->flag = arg3;
    entry->callback = func_800EBB50;
    entry->active = 1;
    func_800EBE74(arg0, entry, arg1);
    return entry;
}
#endif

#ifdef BT_NATIVE
void *func_800EBF8C(f32 *position, s32 model, u32 type, s32 flags) {
    s32 vec[3];
    func_800EE904(vec, position);
    return func_800EBED4(vec, model, type, flags);
}
#else
void *func_800EBF8C(f32 *arg0, s32 arg1, u32 arg2, Prop *arg3) {
    void func_800EE904(s32 *, f32 *);
    s32 vec[3];
    func_800EE904(vec, arg0);
    return func_800EBED4(vec, arg1, arg2, (s32)arg3);
}
#endif

#ifdef BT_NATIVE
void *func_800EBFD4(f32 *position, s32 model, u32 type) {
    return func_800EBF8C(position, model, type, 0);
}
#else
void *func_800EBFD4(f32 *arg0, s32 arg1, u32 arg2) {
    void *func_800EBF8C(f32 *, s32, u32, Prop *);
    return func_800EBF8C(arg0, arg1, arg2, NULL);
}
#endif

/* extern */

#ifdef BT_NATIVE
void func_800EBFF4(void *data) {
    Unk80132ED0 *marker=data;
    if (marker->unk0) func_800E9AC0(func_800BDB9C(marker->cube_index), (void *)marker->unk0);
    marker->unk0=NULL;
    func_800EBE24(marker);
}
#else
void func_800EBFF4(void *arg0) {
    s32 func_800BDB9C(s32);
    s32 func_800E9AC0(s32, s32);
    void func_800EBE24(void *);
    func_800E9AC0(func_800BDB9C((*(s16 *)((s8 *)(arg0) + (0x1C)))), (*(s32 *)((s8 *)(arg0) + (0))));
    func_800EBE24(arg0);
}
#endif

#ifdef BT_NATIVE
void func_800EC030(void *data, s32 *position) {
    NativeMarkerProp *prop=(void *)((Unk80132ED0 *)data)->unk0;
    if (prop) for (s32 i=0; i<3; ++i) prop->position[i]=position[i];
}
#else
void func_800EC030(void **arg0, void *arg1) {
    (*(s16 *)((s8 *)(*arg0) + (4))) = (s16) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s16 *)((s8 *)(*arg0) + (6))) = (s16) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s16 *)((s8 *)(*arg0) + (8))) = (s16) (*(s32 *)((s8 *)(arg1) + (8)));
}
#endif

#ifdef BT_NATIVE
void func_800EC058(s32 *position, void *data) {
    Unk80132ED0 *marker=data;
    s32 index=(marker->unk10 & 1) ? -1 : func_800BD97C(position);
    if (index==marker->cube_index) func_800EC030(marker, position);
    else func_800EBD2C(marker, position, index);
    if (marker->unk28 & (1u<<10)) func_800CDFD0(marker);
}
#else
void func_800EC058(s32 *arg0, void **arg1) {
    struct Flags {
        u8 pad[0x28];
        u32 upper : 21;
        u32 update : 1;
        u32 lower : 10;
    };
    s32 func_800BD97C(s32 *);
    void func_800CDFD0(void **);
    s32 result;

    if (*(s32 *)((u8 *)arg1 + 0x10) & 1) {
        result = -1;
    } else {
        result = func_800BD97C(arg0);
    }
    if (result == *(s16 *)((u8 *)arg1 + 0x1C)) {
        func_800EC030(arg1, arg0);
    } else {
        func_800EBD2C((u8 *)arg1, (s32)arg0, result);
    }
    if (((struct Flags *)arg1)->update) {
        func_800CDFD0(arg1);
    }
}
#endif

/* extern */

#ifdef BT_NATIVE
void func_800EC0EC(f32 *position, void *marker) {
    s32 vec[3];
    func_800EE904(vec, position);
    func_800EC058(vec, marker);
}
#else
void func_800EC0EC(f32 *arg0, void **arg1) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    void func_800EC058(s32 *, void **);
    s32 sp1C[3];

    func_800EE904(sp1C, arg0);
    func_800EC058(sp1C, arg1);
}
#endif

#ifdef BT_NATIVE
void func_800EC124(f32 *position, void *data, f32 *angles) {
    Unk80132ED0 *marker=data;
    marker->unk24=(marker->unk24 & ~(0x1FFu<<7)) | (((u32)func_800136E4(angles[0]) & 0x1FF)<<7);
    marker->unk28=(marker->unk28 & ~0xFFFFC000u) | (((u32)func_800136E4(angles[1]) & 0x1FF)<<23)
        | (((u32)func_800136E4(angles[2]) & 0x1FF)<<14);
    func_800EC0EC(position, marker);
}
#else
void func_800EC124(f32 *arg0, void *arg1, f32 *arg2) {
    struct Angles {
        u8 pad[0x24];
        u32 unused24 : 16;
        u32 x : 9;
        u32 unused27 : 7;
        u32 y : 9;
        u32 z : 9;
        u32 unused2A : 14;
    };
    f32 func_800136E4(f32);
    struct Angles *data = arg1;
    data->x = (u32)func_800136E4(arg2[0]);
    data->y = (u32)func_800136E4(arg2[1]);
    data->z = (u32)func_800136E4(arg2[2]);
    func_800EC0EC(arg0, arg1);
}
#endif

#ifdef BT_NATIVE
void func_800EC340(void *data, s32 index) {
    Unk80132ED0 *marker=data;
    marker->unk18=(marker->unk18 & ~0xFFE0u) | (((u32)index & 0x7FF)<<5);
}
#else
void func_800EC340(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad[26];
        u16 upper : 11;
        u16 lower : 5;
    };
    ((struct Fields *)arg0)->upper = arg1;
}
#endif

#ifdef BT_NATIVE
void func_800EC358(void *marker, struct NativeMarkerCollision *(*value)(void)) { ((Unk80132ED0 *)marker)->collision=value; }
#else
void func_800EC358(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}
#endif

#ifdef BT_NATIVE
void func_800EC360(void *marker, s32 value) { ((Unk80132ED0 *)marker)->unk14=value; }
#else
void func_800EC360(s16 *arg0, s32 arg1) {
    arg0[10] = arg1;
}
#endif

#ifdef BT_NATIVE
void func_800EC368(void *marker, s32 value) { ((Unk80132ED0 *)marker)->unk16=value; }
#else
void func_800EC368(s16 *arg0, s32 arg1) {
    arg0[11] = arg1;
}
#endif

#ifdef BT_NATIVE
void func_800EC370(void *data, s16 *position) {
    NativeMarkerProp *prop=(void *)((Unk80132ED0 *)data)->unk0;
    func_800EE814(position, prop->position);
}
#else
void func_800EC370(void **arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (0))) = (s16) (*(s16 *)((s8 *)(*arg0) + (4)));
    (*(s16 *)((s8 *)(arg1) + (2))) = (s16) (*(s16 *)((s8 *)(*arg0) + (6)));
    (*(s16 *)((s8 *)(arg1) + (4))) = (s16) (*(s16 *)((s8 *)(*arg0) + (8)));
}
#endif

#ifdef BT_NATIVE
void func_800EC398(Unk80132ED0 *marker, f32 *position) {
    NativeMarkerProp *prop=(void *)marker->unk0;
    func_800EE88C(position, prop->position);
}
#else
void func_800EC398(Unk80132ED0 *arg0, f32 *arg1) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    func_800EE88C(arg1, (s16 *)(arg0->unk0 + 1));
}
#endif

#ifdef BT_NATIVE
void *func_800EC3C4(void *data) { return ((Unk80132ED0 *)data)->callback(); }
#else
void *func_800EC3C4(void *arg0) {
    return (*(void *(**)())((s8 *)(arg0) + (8)))();
}
#endif

/* extern */

#ifdef BT_NATIVE
void *func_800EC3E8(void *data) {
    u16 model=((Unk80132ED0 *)data)->unk14;
    return model==0 || model==0xFFFF ? NULL : func_800D674C(model);
}
#else
void *func_800EC3E8(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return func_800D674C(temp_a1);
}
#endif

/* extern */

#ifdef BT_NATIVE
void *func_800EC428(void *data) {
    Unk80132ED0 *marker=data;
    if (marker->unk18 & 0x10000) return func_801039E4(marker);
    return func_800EC3E8(marker);
}
#else
s32 func_800EC428(void *arg0) {
    void *func_800D674C(s32);
    s32 func_801039E4(void *);
    s32 temp_a0;

    if ((*(u16 *)((s8 *)(arg0) + (0x18))) & 1) {
        return func_801039E4(arg0);
    }
    temp_a0 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a0 == 0) || (temp_a0 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a0);
}
#endif

/* extern */

#ifdef BT_NATIVE
f32 func_800EC48C(void *data) {
    Unk80132ED0 *marker=data;
    f32 radius;
    if (marker->unk14==0 || marker->unk14==0xFFFF) return 0.0f;
    radius=func_800B0CFC(func_800EC3E8(marker))*0.5f;
    marker->model_center[1]=(s16)(s32)radius;
    return radius;
}
#else
f32 func_800EC48C(void *arg0) {
    s32 func_800B0CFC(void *);
    typedef struct { u8 pad0[0x14]; u16 model; u8 pad16[0xA]; s16 radius; } PropView;
    PropView *prop = arg0;
    f32 temp_f2;
    u16 temp_v0;

    temp_v0 = prop->model;
    if ((temp_v0 == 0) || (temp_v0 == 0xFFFF)) {
        return 0.0f;
    }
    temp_f2 = (f32) func_800B0CFC(func_800EC3E8(arg0)) * 0.5f;
    prop->radius = (s16) (s32) temp_f2;
    return temp_f2;
}
#endif

typedef struct { u8 pad0[0x14]; u16 model; u8 pad16[8]; s16 center[3]; } PropCenterView;
#ifdef BT_NATIVE
f32 func_800EC504(void *data) {
    Unk80132ED0 *marker=data;
    s32 model=marker->unk14, cached;
    f32 norm, center[3];
    void *asset;
    if (model==0 || model==0xFFFF) return 1.0f;
    cached=func_800D73CC(model);
    asset=func_800D674C(model);
    if (!asset) return 1.0f;
    func_800D62E4(model);
    func_800B237C(func_800B2840(asset), center, &norm);
    func_800EE940(marker->model_center, center);
    if (!cached) func_800D6CEC(model);
    return norm;
}
#else
f32 func_800EC504(PropCenterView *prop) {
    void func_800B237C(void *, f32[3], f32 *);
    s32 func_800B2840(s32);
    void func_800D62E4(s32);
    void *func_800D674C(s32);
    s32 func_800D6CEC(s32);
    s32 func_800D73CC(s32);
    void func_800EE940(s16[3], f32[3]);
    f32 norm;
    f32 center[3];
    void *asset;
    s32 cached;
    s32 model;

    model = prop->model;
    if (model == 0 || model == 0xFFFF) {
        return 1.0f;
    }
    cached = func_800D73CC(model);
    asset = func_800D674C(prop->model);
    if (asset == NULL) {
        return 1.0f;
    }
    func_800D62E4(prop->model);
    func_800B237C(func_800B2840(asset), center, &norm);
    func_800EE940(prop->center, center);
    if (cached == 0) {
        func_800D6CEC(prop->model);
    }
    return norm;
}
#endif

#ifdef BT_NATIVE
f32 func_800EC5C0(void *data, f32 (*callback)(void *)) {
    Unk80132ED0 *marker=((NativeMarkerProp *)data)->marker;
    f32 value=marker->unk18>>21;
    if (value==0.0f) {
        u32 cached=(u32)callback(marker) & 0x7FF;
        marker->unk18=(marker->unk18 & 0x1FFFFF) | (cached<<21);
        value=cached;
    }
    if (marker->unk18 & 0x10000) {
        Actor *actor=func_80106790(marker);
        if (actor) value *= actor->scale;
    }
    return value;
}
#else
f32 func_800EC5C0(void *arg0, void *arg1) {
    Actor *func_80106790(Unk80132ED0 *);
    typedef struct { Unk80132ED0 *marker; } PropView;
    typedef struct {
        u8 pad0[0x18];
        u32 cached : 11;
        u32 flags : 4;
        u32 scaled : 1;
        u32 rest : 16;
    } MarkerView;
    Unk80132ED0 *marker;
    f32 value;
    f32 (*callback)(Unk80132ED0 *) = arg1;

    marker = ((PropView *)arg0)->marker;
    value = (f32)((MarkerView *)marker)->cached;
    if (value == 0.0f) {
        value = ((MarkerView *)marker)->cached = callback(marker);
    }
    if (((MarkerView *)marker)->scaled) {
        value *= func_80106790(marker)->scale;
    }
    return value;
}
#endif

#ifdef BT_NATIVE
f32 func_800EC708(Unk80132ED0 *marker) {
    NativeMarkerProp *prop=(void *)marker->unk0;
    return func_800EC5C0(prop, (prop->flags & 2) ? func_800EC504 : func_800EC48C);
}
#else
f32 func_800EC708(Unk80132ED0 *marker) {
    f32 func_800EC5C0(void *, void *);
    f32 func_800EC48C(void *);
    typedef struct { u8 pad0[8]; u32 reserved : 30; u32 isModel : 1; u32 flag : 1; } PropView;
    PropView *prop = marker->unk0;
    if (prop->isModel) return func_800EC5C0(prop, func_800EC504);
    else return func_800EC5C0(prop, func_800EC48C);
}
#endif

#ifdef BT_NATIVE
f32 func_800EC75C(void *data, f32 *center) {
    Unk80132ED0 *marker=data;
    NativeMarkerProp *prop=(void *)marker->unk0;
    f32 radius=func_800EC708(marker), scale=1.0f;
    if (marker->unk18 & 0x10000) {
        Actor *actor=func_80106790(marker);
        if (actor) scale=actor->scale;
    }
    for (s32 i=0; i<3; ++i) center[i]=marker->model_center[i]*scale+prop->position[i];
    return radius;
}
#else
f32 func_800EC75C(void *marker, f32 *arg1) {
    void func_800EE88C(f32 *, s16 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    typedef struct {
        u8 pad0[0x18];
        u16 flags;
        u8 pad1A[4];
        s16 rotation[3];
    } MarkerView;
    f32 sp34;
    f32 sp28[3];
    MarkerView *prop = marker;

    sp34 = func_800EC708(marker);
    func_800EE88C(arg1, prop->rotation);
    if (prop->flags & 1) {
        func_800EF334(arg1, func_80106790(marker)->scale);
    }
    func_800EC398(marker, sp28);
    func_800EF04C(arg1, sp28);
    return sp34;
}
#endif

/* extern */

void func_800EC7D4(Unk80132ED0 *arg0, s32 arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    s32 func_8010A79C(Actor *, s32);
    func_8010A79C(func_80106790(arg0), arg1);
}

#ifdef BT_NATIVE
int func_800EC800(void *data) {
    Unk80132ED0 *marker=data;
    return (marker->unk18 & 0x10000)!=0 && marker->unk14!=0;
}
#else
int func_800EC800(void *arg0) {
    return ((*(u16 *)((u8 *)arg0 + 0x18) & 1) != 0)
        && (*(u16 *)((u8 *)arg0 + 0x14) != 0);
}
#endif

#ifdef BT_NATIVE
void func_800EC828(void) { if (--marker_generation<0x6B7) marker_generation=0x7FFF; }
#else
void func_800EC828(void) {
    extern s32 D_80132ED0;
    (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C)))--;
    if ((*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) < 0x6B7) {
        (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) = 0x7FFF;
    }
}
#endif

#ifdef BT_NATIVE
s32 func_800EC854(void) {
    s32 result=marker_generation;
    if (++marker_generation>=0x8000) marker_generation=0x6B7;
    return result;
}
#else
s32 func_800EC854(void) {
    extern s32 D_80132ED0;
    s32 temp_t6;
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C)));
    (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C)))++;
    if ((*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) >= 0x8000) {
        (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) = 0x6B7;
    }
    return temp_v1;
}
#endif
