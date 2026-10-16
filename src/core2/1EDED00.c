#include "common.h"

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
    s32 unk4;
    void (*destroy)(void *);
    s32 unkC;
} ItemType;
extern ItemType D_80124440[];

void func_80105410(void) {
    FreeList *freelist_new(s32, s32);
    extern FreeList *D_80136EC0;
    D_80136EC0 = freelist_new(0x48, 8);
}

void func_80105438(void) {
    void freelist_free(FreeList *);
    extern FreeList *D_80136EC0;
    freelist_free(D_80136EC0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801054D4.s")

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
    sp18->unk2_1 = -1;
    sp18->unk28_5 = 7;
    sp18->unk18_7 = 0;
    sp18->unk14 = 100.0f;
    sp18->unk18_6 = func_800E6A00();
    sp18->unk27_5 = 0;
    return sp18;
}

void func_80105634(Actor *arg0) {
    void freelist_erase(FreeList *, s32);
    extern FreeList *D_80136EC0;
    if (arg0->unk7C_0 != 0) {
        freelist_erase(D_80136EC0, arg0->unk7C_0);
        (*(u16 *)((s8 *)(arg0) + (0x7E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x7E))) & 0xF000);
        (*(u8 *)((s8 *)(arg0) + (0x77))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x77))) & 0xFFEF);
    }
}

void func_800FFAB0(Actor *);

int func_8010568C(Actor *arg0, s32 arg1) {
    struct {
        s32 pad0 : 21;
        s32 unk2_1 : 10;
        s32 pad2_0 : 1;
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
    s32 func_800D86F0(s32, f32, void *);
    void *temp_v0;

    temp_v0 = func_80105494(arg0);
    (*(f32 *)((s8 *)(temp_v0) + (0x10))) = (*(f32 *)((s8 *)(temp_v0) + (0xC)));
    (*(f32 *)((s8 *)(temp_v0) + (0xC))) = arg1;
    func_800D86F0((s32) ((*(s32 *)((s8 *)(temp_v0) + (0))) << 0x15) >> 0x16, arg1, (s8 *)arg0 + 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010573C.s")

void func_80105834()
{
    func_801054D4();
}

void func_80105854(Actor *arg0) { s32 func_80105A5C(Actor *); func_801054D4(); if (func_80105A5C(arg0) != 0) { func_800FFAB0(arg0); } }

void func_8010588C(Actor *arg0) { void func_8010A570(Actor *); struct { u32 words[10]; u32 upper : 21; u32 flag : 1; u32 lower : 10; } *flags; func_8010A570(arg0); flags = (void *)arg0->unk0; flags->flag = 1; func_801054D4(arg0); }

/* extern */

void func_801058C4(Actor *arg0, s32 arg1, f32 arg2, u32 arg3) {
    void func_800D8648(s32, f32 *);
    struct State {
        u32 upper : 21;
        s32 id : 10;
        u32 active : 1;
        s32 unk4;
        s32 unk8;
        f32 current;
        f32 previous;
        f32 speed;
        s32 unk18[4];
        u32 mode : 3;
        u32 lower28 : 29;
    } *var_v1, *var_v0;
    struct { u32 words[29]; u32 upper : 27; u32 flag : 1; u32 lower : 4; } *actorFlags;

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
    actorFlags->flag = 1;
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
        s32 upper : 21;
        s32 path_index : 10;
        u32 lower : 1;
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
        temp_v0->flag = 1;
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
        temp_v0->flag = arg1;
    }
}

void func_80105C20(void) {
    FreeList *freelist_new(s32, s32);
    extern FreeList *D_80136ED0;
    D_80136ED0 = freelist_new(0x8, 0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105DFC.s")

void func_801060E4(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    void freelist_erase(FreeList *, s32);
    s32 vector_free(s32);
    s32 _glidmake_entrypoint_4(s32);
    extern FreeList *D_80136ED0;
    s32 *entry;

    entry = freelist_at(D_80136ED0, arg0);
    vector_free(entry[1]);
    _glidmake_entrypoint_4(entry[0]);
    freelist_erase(D_80136ED0, arg0);
}

void func_80106138(void *arg0) {
    void *func_801063C0(void *);
    u32 vector_begin(s32);
    u32 vector_end(s32);
    typedef struct {
        s32 unk0;
        s16 type;
        s16 unk6;
        u8 data[0xA0];
    } Item;
    typedef struct {
        u8 pad[0x90];
        s16 index;
    } Owner;
    s32 *entry;
    Item *end;
    Item *item;

    entry = func_801063C0(arg0);
    end = (Item *)vector_end(entry[1]);
    item = (Item *)vector_begin(entry[1]);
    if (item < end) {
        do {
            D_80124440[item->type].destroy(item->data);
            item++;
        } while (item < end);
    }
    func_801060E4(((Owner *)arg0)->index);
    ((Owner *)arg0)->index = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801061D8.s")

s32 func_80106314()
{
    return D_80136ED8;
}

void *func_80106320(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_801063C0(void *);
    void *vector_push_back(void **);
    typedef struct {
        s32 unk0;
        void *items;
    } Entry;
    typedef struct {
        s32 unk0;
        s16 type;
        s16 unk6;
        u8 data[0xA0];
    } Item;
    Entry *entry;
    Item *item;

    entry = func_801063C0(arg0);
    item = vector_push_back(&entry->items);
    item->type = arg2;
    item->unk0 = entry->unk0;
    item->unk6 = arg1;
    D_80136ED8 = *arg0;
    D_80124440[item->type].create(item->data, arg3, item->unk0, item->unk6, 4);
    return item;
}

void *func_801063C0(void *arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80136ED0;
    return freelist_at(D_80136ED0, (*(s16 *)((s8 *)(arg0) + (0x90))));
}

void func_801063EC(s16 arg0, s32 arg1) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80136ED0;
    u32 vector_begin(s32);
    u32 vector_end(s32);
    s32 *entry;
    s32 pad;
    u32 end;
    u32 begin;
    u32 item;

    entry = freelist_at(D_80136ED0, arg0);
    if (arg1 != entry[0]) {
        end = vector_end(entry[1]);
        begin = vector_begin(entry[1]);
        item = begin;
        if (begin < end) {
            do {
                item += 0xA8;
                *(s32 *)(item - 0xA8) = arg1;
            } while (item < end);
        }
        entry[0] = arg1;
    }
}

/* extern */

void func_8010647C(void *arg0, s32 arg1) {
    func_801063EC((*(s16 *)((s8 *)(arg0) + (0x90))), arg1);
}

/* extern */

void *func_8010649C(void *arg0, s32 arg1) {
    s32 pad;
    u32 vector_begin(s32);
    u32 vector_end(s32);
    u32 sp20;
    void *sp1C;
    u32 temp_v0_2;
    u32 var_v1;
    void *temp_v0;

    temp_v0 = func_801063C0(arg0);
    sp1C = temp_v0;
    sp20 = vector_end((*(s32 *)((s8 *)(temp_v0) + (4))));
    temp_v0_2 = vector_begin((*(s32 *)((s8 *)(sp1C) + (4))));
    var_v1 = temp_v0_2;
    if (temp_v0_2 < sp20) {
loop_2:
        if (((*(s16 *)((s8 *)(var_v1) + (4))) == 2) && (arg1 == (*(s16 *)((s8 *)(var_v1) + (6))))) {
            return var_v1 + 8;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp20) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return NULL;
}

void *func_80106520(s32 arg0) {
    u32 vector_begin(s32);
    u32 vector_end(s32);
    extern s32 D_80136ED4;
    s32 pad;
    u32 sp18;
    u32 temp_v0;
    u32 var_v1;

    sp18 = vector_end(D_80136ED4);
    temp_v0 = vector_begin(D_80136ED4);
    var_v1 = temp_v0;
    if (temp_v0 < sp18) {
loop_2:
        if (((*(s16 *)((s8 *)(var_v1) + (4))) == 7) && (arg0 == (*(s16 *)((s8 *)(var_v1) + (6))))) {
            return var_v1 + 8;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp18) {
            goto block_6;
        }
        goto loop_2;
    }
block_6:
    return NULL;
}

s32 func_801065A4(void *arg0) {
    s32 result = 0;
    if (*(s16 *)((s8 *)arg0 + 0x90) != 0) {
        return *(s32 *)func_801063C0(arg0);
    }
    return result;
}
