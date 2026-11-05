#include "common.h"

#ifdef BT_NATIVE
#include "native_actor.h"
#include "native_actor_model.h"
#include "native_spline.h"
#include "memory.h"
FreeList *D_80136EC0, *D_80136ED0;
Vector *D_80136ED4;
Unk80132ED0 *D_80136ED8;
#define ACTOR_ITEM_FLAG(a, native, original) (native)
#define ITEM_FIELD(i, field, original) (((NativeActorItem *)(i))->field)
#define ITEM_SIZE ((s32)sizeof(NativeActorItem))
#define ITEM_MODEL(i) ((i)->model)
#define ITEM_ID(i) ((i)->id)
#define ITEM_UPDATE(t) ((t).update)
#define ITEM_DEFRAG(t) ((t).defrag)
#define ITEM_ENTRY_SIZE ((s32)sizeof(NativeActorItems))
#define OWNER_INDEX(a, original) (((s16 *)&((Actor *)(a))->pad90)[0])
#define ITEM_ENTRY(e, field, original) (((NativeActorItems *)(e))->field)
#define CREATE_ITEM(a, b, c, d) func_80106320(a, b, c, d)
#else
#define SPLINE_ACTOR(a, field, original) (original)
#define ACTOR_ITEM_FLAG(a, native, original) (original)
#define ITEM_FIELD(i, field, original) (original)
#define ITEM_SIZE 0xA8
#define ITEM_MODEL(i) ((i)->unk0)
#define ITEM_ID(i) ((i)->unk6)
#define ITEM_UPDATE(t) ((t).unk4)
#define ITEM_DEFRAG(t) ((t).unkC)
#define ITEM_ENTRY_SIZE 8
#define OWNER_INDEX(a, original) (original)
#define ITEM_ENTRY(e, field, original) (original)
#define CREATE_ITEM(a, b, c, d) func_80106320(a, b, c, d, 0)
typedef struct {
    s16 next_free;
    u8 data[];
} FreeListElement;
typedef struct {
    s16 element_size;
    s16 capacity;
    FreeListElement data[];
} FreeList;

extern s32 D_80136ED8;

typedef struct {
    void (*create)(void *, s32, s32, s32, s32);
    void (*unk4)(void *, s32, s32);
    void (*destroy)(void *);
    s32 unkC;
} ItemType;
extern ItemType D_80124440[];

#endif

void func_80105410(void) {
    FreeList *freelist_new(s32, s32);
    extern FreeList *D_80136EC0;
    D_80136EC0 = freelist_new(0x48, 8);
}

void func_80105438(void) {
    void freelist_free(FreeList *);
    extern FreeList *D_80136EC0;
    freelist_free(D_80136EC0);
#ifdef BT_NATIVE
    D_80136EC0 = NULL;
#endif
}

void func_8010545C(void) {
    FreeList *freelist_defrag(FreeList *);
    extern FreeList *D_80136EC0;
    if (D_80136EC0 != 0) {
        D_80136EC0 = freelist_defrag(D_80136EC0);
    }
}

void *func_80105494(Actor *arg0) {
    extern FreeList *D_80136EC0;
    void *freelist_at(FreeList *, s32);
    if (arg0->unk7C_0 == 0) {
        return NULL;
    }
    return freelist_at(D_80136EC0, arg0->unk7C_0);
}

s32 func_801054D4(Actor *arg0) {
    s32 func_800D7DE8(Actor *);
    s32 func_800D8588(Actor *, s32, s32, s32);
    s32 func_8010B990(Actor *, s32);
    s32 func_80105A5C(Actor *);
    void func_800FFAB0(Actor *);
    struct {
        u8 pad0[0x18];

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 pad18:31; u32 unk18_31:1;
#else
u32 unk18_31 : 1;
        u32 pad18 : 31;
#endif
u8 pad1C[8];

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 pad24_0:5; u32 unk24_5:1; u32 pad24:26;
#else
u32 pad24 : 26;
        u32 unk24_5 : 1;
        u32 pad24_0 : 5;
#endif
} *sp24;
    s32 sp20;
#ifdef BT_NATIVE
    Unk80132ED0 *marker = arg0->unk0;
#endif

    sp24 = func_80105494(arg0);
    sp20 = func_800D8588(arg0, func_800D7DE8(arg0), 0x19, 0x19);
#ifdef BT_NATIVE
    /* Spawning can move both the actor and its path-state pool. */
    if (marker) {
        arg0 = func_80106790(marker);
        if (!arg0) return sp20;
    }
    sp24 = func_80105494(arg0);
    if (!sp24) return sp20;
#endif
    if (sp24->unk18_31) {
        func_8010B990(arg0, 0x6000);
    }
    if (sp24->unk24_5 && func_80105A5C(arg0)) {
        func_800FFAB0(arg0);
    }
    return sp20;
}

void *func_8010556C(Actor *arg0) {
    typedef struct {
        s16 unk0;
        s16 pad2_11 : 5;
        s16 unk2_1 : 10;
        s16 pad2_0 : 1;
        u8 pad4[0x10];
        f32 unk14;
        u8 unk18_7 : 1;
        u8 unk18_6 : 1;
        u8 unk18_0 : 6;
        u8 pad19[0xE];
        u8 pad27_6 : 2;
        u8 unk27_5 : 1;
        u8 pad27_0 : 5;
        u8 unk28_5 : 3;
        u8 pad28_0 : 5;
    } Entry;
    void *freelist_next(FreeList **, s32 *);
    void rare_memset(void *, u8, int);
    u32 func_800E6A00(void);
    extern FreeList *D_80136EC0;
    s32 sp1C;
    Entry *sp18;

    sp1C = 0;
    sp18 = freelist_next(&D_80136EC0, &sp1C);
    arg0->unk7C_0 = sp1C;
    rare_memset(sp18, 0, 0x48);
#ifdef BT_NATIVE
    ((NativeActorPathState *)sp18)->first = 0x3FF << 1;
    ((NativeActorPathState *)sp18)->flags28 = 7u << 29;
    ((NativeActorPathState *)sp18)->speed = 100.0f;
    ((NativeActorPathState *)sp18)->flags18 = (func_800E6A00() & 1u) << 30;
#else
    sp18->unk2_1 = -1;
    sp18->unk28_5 = 7;
    sp18->unk18_7 = 0;
    sp18->unk14 = 100.0f;
    sp18->unk18_6 = func_800E6A00();
    sp18->unk27_5 = 0;
#endif
    return sp18;
}

void func_80105634(Actor *arg0) {
    void freelist_erase(FreeList *, s32);
    extern FreeList *D_80136EC0;
    if (arg0->unk7C_0 != 0) {
        freelist_erase(D_80136EC0, arg0->unk7C_0);
#ifdef BT_NATIVE
        arg0->unk7C_0 = 0;
        arg0->pad74_0 &= ~16u;
#else
        (*(u16 *)((s8 *)(arg0) + (0x7E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7E))) & 0xF000);
        (*(u8 *)((s8 *)(arg0) + (0x77))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x77))) & 0xFFEF);
#endif
    }
}

void func_800FFAB0(Actor *);

int func_8010568C(Actor *arg0, s32 arg1) {
    struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        s32 pad2_0:1; s32 unk2_1:10; s32 pad0:21;
#else
s32 pad0 : 21;
        s32 unk2_1 : 10;
        s32 pad2_0 : 1;
#endif
} *temp_v0;

    temp_v0 = func_80105494(arg0);
    if ((temp_v0 == NULL) || (temp_v0->unk2_1 == -1)) {
        if (arg1 != 0) {
            func_800FFAB0(arg0);
        }
        return 0;
    }
    return 1;
}

/* extern */

void func_801056EC(Actor *arg0, f32 arg1) {
    void func_800D86F0(s32, f32, f32 *);
    void *temp_v0;

    temp_v0 = func_80105494(arg0);
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = arg1;
    func_800D86F0((s32) ((*(u32 *)((s8 *)(temp_v0) + (0))) << 0x15) >> 0x16, arg1, SPLINE_ACTOR(arg0, position, (s8 *)arg0 + 4));
}

void func_8010573C(Actor *arg0, f32 arg1) {
    void func_800C810C(u8 *, f32, f32 *, f32 *);
    void *func_800D7520(s32);
    s32 func_800D7DE8(Actor *);
    void func_800D86F0(s32, f32, f32 *);
    f32 position[3];
    f32 rotation[3];
    struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 lower:1; s32 path_index:10; s32 upper:21;
#else
s32 upper : 21;
        s32 path_index : 10;
        u32 lower : 1;
#endif
f32 unk4;
        f32 unk8;
        f32 progress;
        f32 previous;
    } *state;
    s32 flags;

    state = func_80105494(arg0);
    flags = func_800D7DE8(arg0);
    state->previous = state->progress;
    state->progress = arg1;
    func_800D86F0(state->path_index, arg1, arg0->position);
    func_800C810C(func_800D7520(state->path_index), state->progress, position, rotation);
    if (flags & 0x100) {
        if (rotation[1] >= 180.0f) {
            arg0->unk54 = rotation[1] - 180.0f;
        } else {
            arg0->unk54 = rotation[1] + 180.0f;
        }
    }
    if (flags & 0x200) {
        arg0->unk50 = 360.0f - rotation[0];
    }
    arg0->rotation[1] = arg0->unk54;
    arg0->rotation[0] = arg0->unk50;
}

void func_80105834(Actor *arg0)
{
    func_801054D4(arg0);
}

void func_80105854(Actor *arg0) {
    s32 func_80105A5C(Actor *);
#ifdef BT_NATIVE
    Unk80132ED0 *marker = arg0->unk0;
#endif
    func_801054D4(arg0);
#ifdef BT_NATIVE
    if (marker) {
        arg0 = func_80106790(marker);
        if (!arg0) return;
    }
#endif
    if (func_80105A5C(arg0) != 0) { func_800FFAB0(arg0); }
}

void func_8010588C(Actor *arg0) { void func_8010A570(Actor *); struct { u32 words[10];
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 lower:10; u32 flag:1; u32 upper:21;
#else
u32 upper : 21; u32 flag : 1; u32 lower : 10;
#endif
} *flags; func_8010A570(arg0); flags = (void *)arg0->unk0;
#ifdef BT_NATIVE
    arg0->unk0->unk28 |= 1 << 10;
#else
    flags->flag = 1;
#endif
    func_801054D4(arg0); }

/* extern */

void func_801058C4(Actor *arg0, s32 arg1, f32 arg2, u32 arg3) {
    void func_800D8648(s32, f32 *);
    struct State {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 active:1; s32 id:10; u32 upper:21;
#else
u32 upper : 21;
        s32 id : 10;
        u32 active : 1;
#endif
s32 unk4;
        s32 unk8;
        f32 current;
        f32 previous;
        f32 speed;
        s32 unk18[4];

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 lower28:29; u32 mode:3;
#else
u32 mode : 3;
        u32 lower28 : 29;
#endif
} *var_v1, *var_v0;
    struct { u32 words[29];
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 lower:4; u32 flag:1; u32 upper:27;
#else
u32 upper : 27; u32 flag : 1; u32 lower : 4;
#endif
} *actorFlags;

    var_v0 = func_80105494(arg0);
    var_v1 = var_v0;
    if (var_v0 == NULL) {
        var_v0 = func_8010556C(arg0);
        var_v1 = var_v0;
    }
    if (arg1 != -1) {
        var_v0->id = arg1;
    }
    if (arg3 != 0) {
        func_800D8648(var_v1->id, arg0->position);
    }
    var_v1->current = 0.0f;
    var_v1->previous = 0.0f;
    var_v1->speed = arg2;
    actorFlags = (void *)arg0;
#ifdef BT_NATIVE
    arg0->pad74_0 |= 16;
#else
    actorFlags->flag = 1;
#endif
    var_v1->active = 1;
    var_v1->mode = 0;
}

s32 func_80105998(Actor *arg0, f32 arg1) {
    void *state;
    f32 current;
    f32 previous;

    state = func_80105494(arg0);
    current = *(f32 *)((s8 *)state + 0xC);
    previous = *(f32 *)((s8 *)state + 0x10);
    if (previous == current) {
        return 0;
    }
    return previous < current
        ? (previous <= arg1 && arg1 < current)
        : (previous <= arg1 || arg1 < current);
}

/* extern */

s32 func_80105A5C(Actor *arg0) {
    void *func_80105494(Actor *);

    return (*(f32 *)((s8 *)func_80105494(arg0) + 0xC)) == 1.0f;
}

void func_80105A9C(Actor *arg0, f32 arg1) {
    void *func_80105494(Actor *);
    (*(f32 *)((s8 *)(func_80105494(arg0)) + 0x14)) = arg1;
}

/* extern */

f32 func_80105AC4(Actor *arg0) {
    void *func_80105494(Actor *);
    return (*(f32 *)((s8 *)(func_80105494(arg0)) + (0x14)));
}

/* extern */

f32 func_80105AE8(Actor *arg0) {
    void *func_80105494(Actor *);
    return (*(f32 *)((s8 *)(func_80105494(arg0)) + (0xC)));
}

f32 func_80105B0C(Actor *arg0, s32 arg1) {
    void func_800C810C(u8 *, f32, f32 *, f32 *);
    void *func_800D7520(s32);
    s32 func_800D7DE8(Actor *);
    f32 position[3];
    f32 rotation[3];
    struct {

#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 lower:1; s32 path_index:10; s32 upper:21;
#else
s32 upper : 21;
        s32 path_index : 10;
        u32 lower : 1;
#endif
f32 unk4;
        f32 unk8;
        f32 progress;
    } *state;
    s32 flags;
    f32 result;

    state = func_80105494(arg0);
    flags = func_800D7DE8(arg0);
    func_800C810C(func_800D7520(state->path_index), state->progress, position, rotation);
    if (flags & 0x100) {
        if (rotation[1] >= 180.0f) {
            result = rotation[1] - 180.0f;
        } else {
            result = rotation[1] + 180.0f;
        }
        return result;
    }
    return rotation[1];
}

void func_80105BAC(Actor *arg0) {
    void *func_80105494(Actor *);
    struct {
        u8 pad[0x18];
        u8 flag : 1;
        u8 rest : 7;
    } *temp_v0;

    temp_v0 = func_80105494(arg0);
    if (temp_v0 != NULL) {
#ifdef BT_NATIVE
        ((NativeActorPathState *)temp_v0)->flags18 |= 1u << 31;
#else
        temp_v0->flag = 1;
#endif
    }
}

/* extern */

void func_80105BE0(Actor *arg0, s32 arg1) {
    void *func_80105494(Actor *);
    struct {
        u8 pad[0x27];
        u8 high : 2;
        u8 flag : 1;
        u8 low : 5;
    } *temp_v0;
    temp_v0 = func_80105494(arg0);
    if (temp_v0 != NULL) {
#ifdef BT_NATIVE
        ((NativeActorPathState *)temp_v0)->flags24 = (((NativeActorPathState *)temp_v0)->flags24 & ~32u) | ((arg1 & 1u) << 5);
#else
        temp_v0->flag = arg1;
#endif
    }
}

void func_80105C20(void) {
    FreeList *freelist_new(s32, s32);
    extern FreeList *D_80136ED0;
    D_80136ED0 = freelist_new(ITEM_ENTRY_SIZE, 0);
}

void func_80105C48(void) {
    s16 freelist_capacity(FreeList *);
    void freelist_free(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    void func_801060E4(s16);
    extern FreeList *D_80136ED0;
    s32 var_s0;
    s32 temp_v0;

    temp_v0 = freelist_capacity(D_80136ED0);
    var_s0 = 1;
    if (temp_v0 >= 2) {
        do {
            if (freelist_is_element_alive(D_80136ED0, var_s0) != 0) {
                func_801060E4(var_s0);
            }
            var_s0 += 1;
        } while (var_s0 < temp_v0);
    }
    freelist_free(D_80136ED0);
    D_80136ED0 = 0;
}

void func_80105CD0(void) {
#ifndef BT_NATIVE
    s32 defrag(s32);
#endif
    void *freelist_at(FreeList *, s32);
    s16 freelist_capacity(FreeList *);
    FreeList *freelist_defrag(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
#ifndef BT_NATIVE
    void func_801063EC(s16, s32);
#endif
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_defrag(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
    extern FreeList *D_80136ED0;
#ifdef BT_NATIVE
    typedef NativeActorItem Item;
#else
    typedef struct {
        s32 unk0;
        s16 type;
        s16 unk6;
        u8 data[0xA0];
    } Item;
#endif
    s32 index;
    s32 capacity;
#ifdef BT_NATIVE
    NativeActorItems *entry;
#else
    s32 *entry;
#endif
    Item *item;
    Item *end;
#ifdef BT_NATIVE
    void (*callback)(void *);
#else
    s32 callback;
#endif

    if (D_80136ED0 != 0) {
        capacity = freelist_capacity(D_80136ED0);
        for (index = 1; index < capacity; index++) {
            if (freelist_is_element_alive(D_80136ED0, index)) {
                entry = freelist_at(D_80136ED0, index);
                func_801063EC(index, defrag(ITEM_ENTRY(entry, model, entry[0])));
                ITEM_ENTRY(entry, items, entry[1]) = vector_defrag(ITEM_ENTRY(entry, items, entry[1]));
                end = (Item *)vector_end(ITEM_ENTRY(entry, items, entry[1]));
                item = (Item *)vector_begin(ITEM_ENTRY(entry, items, entry[1]));
                for (; item < end; item++) {
                    callback = ITEM_DEFRAG(D_80124440[item->type]);
                    if (callback) {
                        ((void (*)(void *))callback)(item->data);
                    }
                }
            }
        }
        D_80136ED0 = freelist_defrag(D_80136ED0);
#ifdef BT_NATIVE
        D_80136ED4 = NULL;
#else
        (&D_80136ED0)[1] = 0;
#endif
    }
}

void func_80105DFC(Actor *arg0) {
    s16 *_glidmake_entrypoint_1();
#ifdef BT_NATIVE
    void *_glidmake_entrypoint_5(u16, void *);
#else
    s32 _glidmake_entrypoint_5(u16, s32);
#endif
    void freelist_erase(FreeList *, s32);
    void *freelist_next(FreeList **, s32 *);
#ifndef BT_NATIVE
    s32 vector_new(s32, s32);
#endif
#ifndef BT_NATIVE
    void *func_80106320();
#endif
    extern FreeList *D_80136ED0;
    typedef struct {
        u8 pad[0x90];
        s16 index;
    } Owner;
    s16 *sp44;
    s16 *var_s1;
    s16 temp_a1;
    s32 sp38;
    s32 var_s2;
#ifdef BT_NATIVE
    NativeActorItems *entry;
#else
    s32 *entry;
#endif

    sp38 = 0;
    if (OWNER_INDEX(arg0, ((Owner *)arg0)->index) == 0) {
        entry = freelist_next(&D_80136ED0, &sp38);
        OWNER_INDEX(arg0, ((Owner *)arg0)->index) = sp38;
        ITEM_ENTRY(entry, model, entry[0]) = _glidmake_entrypoint_5(arg0->unk0->unk14, 0);
        if (ITEM_ENTRY(entry, model, entry[0]) == 0) {
            freelist_erase(D_80136ED0, sp38);
            OWNER_INDEX(arg0, ((Owner *)arg0)->index) = 0;
            return;
        }
        ITEM_ENTRY(entry, items, entry[1]) = vector_new(ITEM_SIZE, 0);
        sp44 = _glidmake_entrypoint_1(ITEM_ENTRY(entry, model, entry[0]));
        var_s1 = sp44 + 1;
        var_s2 = 0;
        if (*sp44 > 0) {
            do {
                temp_a1 = var_s1[0];
                if ((temp_a1 >= 0x65) && (temp_a1 < 0xC8)) {
                    CREATE_ITEM(arg0, temp_a1, 1, temp_a1 - 0x64);
                } else if ((temp_a1 >= 0xC8) && (temp_a1 < 0x12C)) {
                    CREATE_ITEM(arg0, temp_a1, 0, temp_a1 - 0xC8);
                } else if ((temp_a1 >= 0x12C) && (temp_a1 < 0x190)) {
                    CREATE_ITEM(arg0, temp_a1, 3, temp_a1 - 0x12C);
                } else if ((temp_a1 >= 0x190) && (temp_a1 < 0x1F4)) {
                    CREATE_ITEM(arg0, temp_a1, 2, temp_a1 - 0x190);
                } else if ((temp_a1 >= 0x1F4) && (temp_a1 < 0x258)) {
                    CREATE_ITEM(arg0, temp_a1, 4, temp_a1 - 0x1F4);
                } else if ((temp_a1 >= 0x258) && (temp_a1 < 0x2BC)) {
                    CREATE_ITEM(arg0, temp_a1, 2, temp_a1 - 0x258);
                } else if ((temp_a1 >= 0x2BC) && (temp_a1 < 0x320)) {
                    CREATE_ITEM(arg0, temp_a1, 5, temp_a1 - 0x2BC);
                } else if ((temp_a1 >= 0x320) && (temp_a1 < 0x384)) {
                    CREATE_ITEM(arg0, temp_a1, 6, temp_a1 - 0x320);
                } else if ((temp_a1 >= 0x384) && (temp_a1 < 0x3E8)) {
                    CREATE_ITEM(arg0, temp_a1, 7, temp_a1 - 0x384);
                } else if ((temp_a1 >= 0x4B0) && (temp_a1 < 0x6A4)) {
                    CREATE_ITEM(arg0, temp_a1, 8, temp_a1 - 0x4B0);
                } else if ((temp_a1 >= 0x6A4) && (temp_a1 < 0x708)) {
                    CREATE_ITEM(arg0, temp_a1, 10, temp_a1 - 0x6A4);
                } else if ((temp_a1 >= 0x76C) && (temp_a1 < 0x7D0)) {
                    CREATE_ITEM(arg0, temp_a1, 9, temp_a1 - 0x76C);
                }
                var_s2++;
                var_s1 += var_s1[1];
                var_s1 += 2;
            } while (var_s2 < *sp44);
        }
    }
}

void func_801060E4(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    void freelist_erase(FreeList *, s32);
#ifndef BT_NATIVE
    s32 vector_free(s32);
#endif
#ifdef BT_NATIVE
    void _glidmake_entrypoint_4(void *);
#else
    s32 _glidmake_entrypoint_4(s32);
#endif
    extern FreeList *D_80136ED0;
#ifdef BT_NATIVE
    NativeActorItems *entry;
#else
    s32 *entry;
#endif

    entry = freelist_at(D_80136ED0, arg0);
    vector_free(ITEM_ENTRY(entry, items, entry[1]));
    _glidmake_entrypoint_4(ITEM_ENTRY(entry, model, entry[0]));
    freelist_erase(D_80136ED0, arg0);
}

void func_80106138(void *arg0) {
    void *func_801063C0(void *);
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
#ifdef BT_NATIVE
    typedef NativeActorItem Item;
#else
    typedef struct {
        s32 unk0;
        s16 type;
        s16 unk6;
        u8 data[0xA0];
    } Item;
#endif
    typedef struct {
        u8 pad[0x90];
        s16 index;
    } Owner;
#ifdef BT_NATIVE
    NativeActorItems *entry;
#else
    s32 *entry;
#endif
    Item *end;
    Item *item;

    entry = func_801063C0(arg0);
    end = (Item *)vector_end(ITEM_ENTRY(entry, items, entry[1]));
    item = (Item *)vector_begin(ITEM_ENTRY(entry, items, entry[1]));
    if (item < end) {
        do {
            D_80124440[item->type].destroy(item->data);
            item++;
        } while (item < end);
    }
    func_801060E4(OWNER_INDEX(arg0, ((Owner *)arg0)->index));
    OWNER_INDEX(arg0, ((Owner *)arg0)->index) = 0;
}

void func_801061D8(Actor *arg0) {
    typedef struct {
        u8 pad[0x70];
        u32 pad70_25 : 7;
        u32 flag70_24 : 1;
        u32 pad70_4 : 20;
        u32 flag70_3 : 1;
        u32 pad70_0 : 3;
        u32 pad74_23 : 9;
        u32 flag74_22 : 1;
        u32 pad74_0 : 22;
    } ActorFlags;
    void *func_801063C0(void *);
    void func_800D62E4(s32);
#ifdef BT_NATIVE
    void _glid_entrypoint_5(void *,void *),_glid_entrypoint_6(void *,void *);
#else
    u8 *func_80103AA0(u8 *);
    void func_800D62E4(s32);
    s32 func_80103CDC(u8 *, u8 *);
    s32 func_80103D00(void *, u8 *);
#ifdef BT_NATIVE
    void _glid_entrypoint_5(void *, s32);
#else
    s32 _glid_entrypoint_5(s32, s32);
#endif
#ifdef BT_NATIVE
    void _glid_entrypoint_6(void *, s32);
#else
    s32 _glid_entrypoint_6(s32, s32);
#endif
#endif
    void func_8010381C(Actor *);
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136ED4;
#endif
#ifdef BT_NATIVE
    typedef NativeActorItem Item;
#else
    typedef struct {
        s32 unk0;
        s16 type;
        s16 unk6;
        u8 data[0xA0];
    } Item;
#endif
#ifdef BT_NATIVE
    NativeActorItems *entry;
#else
    s32 *entry;
#endif
    u8 *model;
    Item *end;
    Item *item;

    entry = func_801063C0(arg0);
#ifdef BT_NATIVE
    model = func_80103AA0(arg0->unk0);
#else
    model = func_80103AA0((u8 *)arg0->unk0);
#endif
    if (model != NULL) {
        func_800D62E4(arg0->unk0->unk14);
        _glid_entrypoint_5(ITEM_ENTRY(entry, model, entry[0]), func_80103CDC(ACTOR_ITEM_FLAG(arg0, arg0, (u8 *)arg0), model));
        if (ACTOR_ITEM_FLAG(arg0, (arg0->pad70_16 & 0x100), ((ActorFlags *)arg0)->flag70_24)) {
            _glid_entrypoint_6(ITEM_ENTRY(entry, model, entry[0]), func_80103D00(arg0, model));
        }
        if (arg0->unk7C_12 && !ACTOR_ITEM_FLAG(arg0, (arg0->pad74_18 & 16), ((ActorFlags *)arg0)->flag74_22)) {
            end = (Item *)vector_end(ITEM_ENTRY(entry, items, entry[1]));
            D_80136ED4 = ITEM_ENTRY(entry, items, entry[1]);
            item = (Item *)vector_begin(ITEM_ENTRY(entry, items, entry[1]));
            if (item < end) {
                do {
                    ITEM_UPDATE(D_80124440[item->type])(item->data, ITEM_MODEL(item), ITEM_ID(item));
                    item++;
                } while (item < end);
            }
        }
    } else if (ACTOR_ITEM_FLAG(arg0, (arg0->pad70_1 & 4), ((ActorFlags *)arg0)->flag70_3)) {
        func_8010381C(arg0);
    }
}

#ifdef BT_NATIVE
Unk80132ED0 *func_80106314(void)
#else
s32 func_80106314()
#endif
{
    return D_80136ED8;
}

#ifdef BT_NATIVE
void *func_80106320(Actor *arg0, s32 arg1, s32 arg2, s32 arg3)
#else
void *func_80106320(s32 *arg0, s32 arg1, s32 arg2, s32 arg3)
#endif
{
    void *func_801063C0(void *);
#ifndef BT_NATIVE
    void *vector_push_back(void **);
#endif
#ifdef BT_NATIVE
    typedef NativeActorItems Entry;
#else
    typedef struct {
        s32 unk0;
        void *items;
    } Entry;
#endif
#ifdef BT_NATIVE
    typedef NativeActorItem Item;
#else
    typedef struct {
        s32 unk0;
        s16 type;
        s16 unk6;
        u8 data[0xA0];
    } Item;
#endif
    Entry *entry;
    Item *item;

    entry = func_801063C0(arg0);
    item = vector_push_back(&entry->items);
    item->type = arg2;
    ITEM_MODEL(item) = ITEM_ENTRY(entry, model, entry->unk0);
    ITEM_ID(item) = arg1;
#ifdef BT_NATIVE
    D_80136ED8 = arg0->unk0;
#else
    D_80136ED8 = *arg0;
#endif
    D_80124440[item->type].create(item->data, arg3, ITEM_MODEL(item), ITEM_ID(item), 4);
    return item;
}

void *func_801063C0(void *arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80136ED0;
    return freelist_at(D_80136ED0, OWNER_INDEX(arg0, (*(s16 *)((s8 *)(arg0) + (0x90)))));
}

#ifdef BT_NATIVE
void func_801063EC(s16 arg0, void *arg1)
#else
void func_801063EC(s16 arg0, s32 arg1)
#endif
{
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80136ED0;
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
#ifdef BT_NATIVE
    NativeActorItems *entry;
#else
    s32 *entry;
#endif
    s32 pad;
    uintptr_t end;
    uintptr_t begin;
    uintptr_t item;

    entry = freelist_at(D_80136ED0, arg0);
    if (arg1 != ITEM_ENTRY(entry, model, entry[0])) {
        end = (uintptr_t)vector_end(ITEM_ENTRY(entry, items, entry[1]));
        begin = (uintptr_t)vector_begin(ITEM_ENTRY(entry, items, entry[1]));
        item = begin;
        if (begin < end) {
            do {
                item += ITEM_SIZE;
#ifdef BT_NATIVE
                ((NativeActorItem *)(item - ITEM_SIZE))->model = arg1;
#else
                *(s32 *)(item - 0xA8) = arg1;
#endif
            } while (item < end);
        }
        ITEM_ENTRY(entry, model, entry[0]) = arg1;
    }
}

/* extern */

#ifdef BT_NATIVE
void func_8010647C(void *arg0, void *arg1)
#else
void func_8010647C(void *arg0, s32 arg1)
#endif
{
    func_801063EC(OWNER_INDEX(arg0, (*(s16 *)((s8 *)(arg0) + (0x90)))), arg1);
}

/* extern */

void *func_8010649C(void *arg0, s32 arg1) {
    s32 pad;
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
    uintptr_t sp20;
    void *sp1C;
    uintptr_t temp_v0_2;
    uintptr_t var_v1;
    void *temp_v0;

    temp_v0 = func_801063C0(arg0);
    sp1C = temp_v0;
    sp20 = (uintptr_t)vector_end(ITEM_ENTRY(temp_v0, items, (*(s32 *)((s8 *)(temp_v0) + (4)))));
    temp_v0_2 = (uintptr_t)vector_begin(ITEM_ENTRY(sp1C, items, (*(s32 *)((s8 *)(sp1C) + (4)))));
    var_v1 = temp_v0_2;
    if (temp_v0_2 < sp20) {
loop_2:
        if ((ITEM_FIELD(var_v1, type, (*(s16 *)((s8 *)(var_v1) + (4)))) == 2) && (arg1 == ITEM_FIELD(var_v1, id, (*(s16 *)((s8 *)(var_v1) + (6)))))) {
            return (void *)ITEM_FIELD(var_v1, data, var_v1 + 8);
        }
        var_v1 += ITEM_SIZE;
        if (var_v1 >= sp20) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return NULL;
}

void *func_80106520(s32 arg0) {
#ifndef BT_NATIVE
    u32 vector_begin(s32);
#endif
#ifndef BT_NATIVE
    u32 vector_end(s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136ED4;
#endif
    s32 pad;
    uintptr_t sp18;
    uintptr_t temp_v0;
    uintptr_t var_v1;

    sp18 = (uintptr_t)vector_end(D_80136ED4);
    temp_v0 = (uintptr_t)vector_begin(D_80136ED4);
    var_v1 = temp_v0;
    if (temp_v0 < sp18) {
loop_2:
        if ((ITEM_FIELD(var_v1, type, (*(s16 *)((s8 *)(var_v1) + (4)))) == 7) && (arg0 == ITEM_FIELD(var_v1, id, (*(s16 *)((s8 *)(var_v1) + (6)))))) {
            return (void *)ITEM_FIELD(var_v1, data, var_v1 + 8);
        }
        var_v1 += ITEM_SIZE;
        if (var_v1 >= sp18) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return NULL;
}

#ifdef BT_NATIVE
void *func_801065A4(void *arg0)
#else
s32 func_801065A4(void *arg0)
#endif
{
#ifdef BT_NATIVE
    void *result = NULL;
#else
    s32 result = 0;
#endif
    if (OWNER_INDEX(arg0, *(s16 *)((s8 *)arg0 + 0x90)) != 0) {
        return ITEM_ENTRY(func_801063C0(arg0), model, *(s32 *)func_801063C0(arg0));
    }
    return result;
}
