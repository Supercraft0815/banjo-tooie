#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1ED9D70_native.inc"
#else
#include "common.h"

typedef struct { u8 pad0[0x2]; s16 unk2; s32 unk4; } Obj1ED9D70_func_80100480_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */ void *func_80100480(s32 arg0, s32 arg1) {
    s32 func_8001211C(void);
    void *heap_alloc(s32);
    void *heap_realloc(void *, s32);
    extern s32 D_801243A0;
    void *temp_a2;
    s8 *temp_s0;

    temp_s0 = (s8 *)&D_801243A0 + arg0 * 0xC;
    temp_a2 = *(void **)(temp_s0 + 8);
    if (temp_a2 == 0) {
        (((Obj1ED9D70_func_80100480_temp_s0 *)temp_s0)->unk2) = arg1;
        *(void **)(temp_s0 + 8) = heap_alloc(*(s16 *)(temp_s0 + 2) * *(s16 *)(temp_s0 + 0));
    } else if ((((Obj1ED9D70_func_80100480_temp_s0 *)temp_s0)->unk2) < arg1) {
        (((Obj1ED9D70_func_80100480_temp_s0 *)temp_s0)->unk2) = arg1;
        *(void **)(temp_s0 + 8) = heap_realloc(temp_a2, *(s16 *)(temp_s0 + 2) * *(s16 *)(temp_s0 + 0));
    }
    (((Obj1ED9D70_func_80100480_temp_s0 *)temp_s0)->unk4) = func_8001211C();
    return *(void **)(temp_s0 + 8);
}

void func_8010052C(void) {
}    typedef struct { u8 pad0[0x2]; s16 unk2; s32 unk4; s32 unk8; } Obj1ED9D70_func_80100534_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

void func_80100534(void) {
    s32 func_8001211C(void);
    void heap_free(void *);
    extern s32 D_801243A0;
    extern s32 D_801243DC;
    s8 *var_s0;
    void *temp_a0;
    s32 temp_s2;

    temp_s2 = func_8001211C();
    var_s0 = (s8 *)&D_801243A0; do {
        temp_a0 = *(void **)(var_s0 + 8);
        if ((temp_a0 != 0) && ((temp_s2 - (((Obj1ED9D70_func_80100534_var_s0 *)var_s0)->unk4)) >= 0x1F)) {
            heap_free(temp_a0);
            (((Obj1ED9D70_func_80100534_var_s0 *)var_s0)->unk8) = 0;
            (((Obj1ED9D70_func_80100534_var_s0 *)var_s0)->unk2) = 0;
            (((Obj1ED9D70_func_80100534_var_s0 *)var_s0)->unk4) = 0;
        }
        var_s0 += 0xC;
    } while (var_s0 != (s8 *)&D_801243DC);
}

void func_801005B8(void)
{
  void *defrag(void *);
  extern s32 D_801243A0;
  extern s32 D_801243DC;
  s32 (*var_s0)[3];
  s32 temp_a0;
 var_s0 = &D_801243A0; do {
    temp_a0 = var_s0[0][2];
    if (temp_a0 != 0)
    {
      var_s0[0][2] = defrag(temp_a0);
    }
    var_s0++;
  }
  while (var_s0 != ((s32 (*)[3]) (&D_801243DC)));
}

void func_80100610(void)
{
    void heap_free(void *);
    extern s32 D_801243A0;
    extern s32 D_801243DC;
    s32 (*var_s0)[3];
    void *temp_a0;
    var_s0 = &D_801243A0; do {
        temp_a0 = *(void **)&var_s0[0][2];
        if (temp_a0 != 0) {
            heap_free(temp_a0);
            var_s0[0][2] = 0;
            ((s16 *)var_s0)[1] = 0;
            var_s0[0][1] = 0;
        }
        var_s0++;
    } while (var_s0 != ((s32 (*)[3]) (&D_801243DC)));
}

void func_80100670()
{
    func_80100610();
}

typedef struct {
    s16 next_free;
    u8 data[];
} FreeListElement;

typedef struct {
    s16 element_size;
    s16 capacity;
    FreeListElement data[];
} FreeList;

FreeList *freelist_new(s32, s32);
void *freelist_next(FreeList **, s32 *);

void *func_80100690(s32 *arg0) {
    FreeList *freelist_new(s32, s32);
    void *freelist_next(FreeList **, s32 *);
    extern FreeList *D_80135A60[2];
    if (D_80135A60[0] == 0) {
        D_80135A60[0] = freelist_new(0xC, 2);
    }
    return freelist_next(&D_80135A60[0], arg0);
}

extern FreeList *D_80135A64;

void *func_801006E0(s32 *arg0) {
    FreeList *volatile *list = &D_80135A64;
    if (D_80135A64 == 0) {
        *list = freelist_new(0xC, 2);
    }
    return freelist_next(&D_80135A64, arg0);
}

int func_8010072C(s32 *arg0, u8 *arg1) {
    if (arg0 != NULL) {
        return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2];
    } else {
        return arg1[0] == 0xFF && arg1[1] == 0xFF && arg1[2] == 0xFF;
    }
}

s32 func_801007B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800D674C(s32);
    s32 _glpackvtx_entrypoint_0(s32, s32, s32);
    void *freelist_at(FreeList *, s32);
    s16 freelist_capacity(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    s32 func_800B2840(s32);
    void func_800F2F20(void *, void *);
    void func_800F31EC(u8 *, s32, s32, s32);
    extern FreeList *D_80135A60[2];
    struct Entry { s32 data; s16 value; s16 image; u8 count; u8 color[3]; };
    s32 image;
    struct Entry *entry;
    s32 index;

    if (D_80135A60[1] != NULL) {
        for (index = 1; index < freelist_capacity(D_80135A60[1]); index++) {
            if (freelist_is_element_alive(D_80135A60[1], index)) {
                entry = freelist_at(D_80135A60[1], index);
                if (arg1 == entry->value && arg2 == entry->image && func_8010072C((s32 *)arg3, entry->color)) {
                    entry->count++;
                    return index;
                }
            }
        }
    }
    entry = func_801006E0(&index);
    image = arg2 ? func_800D674C(arg2) : 0;
    entry->data = _glpackvtx_entrypoint_0(func_800B2840(arg0), image, arg3);
    entry->value = arg1;
    entry->image = arg2;
    entry->count = 1;
    if (arg3 != NULL) {
        func_800F2F20(entry->color, (void *)arg3);
    } else {
        func_800F31EC(entry->color, 0xFF, 0xFF, 0xFF);
    }
    return index;
}

void func_80100938(s32 arg0) {
    s32 _glpackvtx_entrypoint_1(s32);
    void *freelist_at(FreeList *, s32);
    void freelist_erase(FreeList *, s32);
    void freelist_free(FreeList *);
    s32 freelist_used_count(FreeList *);
    struct Entry { s32 data; s16 value; u8 padding[2]; u32 count : 8; u32 unused : 24; };
    struct Entry *entry;

    entry = freelist_at(D_80135A64, arg0);
    entry->count--;
    if (entry->count == 0) {
        _glpackvtx_entrypoint_1(entry->data);
        entry->data = 0;
        entry->value = 0;
        freelist_erase(D_80135A64, arg0);
        if (freelist_used_count(D_80135A64) == 0) {
            freelist_free(D_80135A64);
            D_80135A64 = NULL;
        }
    }
}    typedef struct { u8 pad0[0x9]; s8 unk9; } Obj1ED9D70_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_801009C4(void **arg0, s32 arg1) {
    void freelist_erase(FreeList *, s32);
    void freelist_free(FreeList *);
    s32 freelist_used_count(FreeList *);
    void func_800B23E0(void *);
    void func_80100938(s32);
    extern FreeList *D_80135A60[2];
    void **var_s1;
    void *temp_a0;
    s32 var_s0;
    struct EntryBits { void *lists[2]; u32 index : 8; u32 used : 8; u32 padding : 16; };

    var_s0 = 0;
    var_s1 = arg0;
    do {
        temp_a0 = *var_s1;
        if (temp_a0 != 0) {
            func_800B23E0(temp_a0);
        }
        var_s0 += 4;
        var_s1++;
    } while (var_s0 != 8);
    if (((struct EntryBits *)arg0)->index != 0) {
        func_80100938(((struct EntryBits *)arg0)->index);
    }
    (((Obj1ED9D70_arg0 *)arg0)->unk9) = 0;
    freelist_erase(D_80135A60[0], arg1);
    if (freelist_used_count(D_80135A60[0]) == 0) {
        freelist_free(D_80135A60[0]);
        D_80135A60[0] = 0;
    }
}

s32 func_80100A74(s16 arg0, s32 arg1) { extern FreeList *D_80135A60[2]; void *freelist_at(FreeList *, s32); s32 var_v1; u8 *temp_v0;
    temp_v0 = freelist_at(D_80135A60[0], arg0); if (temp_v0[9] != 0) { var_v1 = ((s32 *)temp_v0)[arg1]; } else { var_v1 = 0; } return var_v1; }    typedef struct { s32 unk0; u8 pad4[0x4]; u8 unk8; } Obj1ED9D70_func_80100AC4_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */ typedef struct { u8 pad0[0x8]; u8 unk8; } Obj1ED9D70_func_80100AC4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_80100AC4(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80135A60[2];
    extern FreeList *D_80135A64;
    s32 var_v1;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = freelist_at(D_80135A60[0], arg0);
    if ((((Obj1ED9D70_func_80100AC4_temp_v0 *)temp_v0)->unk8) == 0) {
        return 0;
    }
    temp_v0_2 = freelist_at(D_80135A64, (s16) (((Obj1ED9D70_func_80100AC4_temp_v0 *)temp_v0)->unk8));
    if ((((Obj1ED9D70_func_80100AC4_temp_v0_2 *)temp_v0_2)->unk8) != 0) {
        var_v1 = (((Obj1ED9D70_func_80100AC4_temp_v0_2 *)temp_v0_2)->unk0);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_80100B3C(void) {
    extern s32 D_80135A68;
    D_80135A68 = 0x3667;
}

void func_80100B4C(void) {
    void *freelist_at(FreeList *, s32);
    s16 freelist_capacity(FreeList *);
    void freelist_free(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    s32 _glpackvtx_entrypoint_1(s32);
    void func_80100C74(void);
    extern FreeList *D_80135A60[2];
    s32 i;
    s32 *entry;

    func_80100C74();
    func_80100C74();
    for (i = 1; D_80135A60[0] != 0 && i < freelist_capacity(D_80135A60[0]); i++) {
        if (freelist_is_element_alive(D_80135A60[0], i)) {
            func_801009C4(freelist_at(D_80135A60[0], i), i);
        }
    }
    if (D_80135A60[0] != 0) {
        freelist_free(D_80135A60[0]);
        D_80135A60[0] = 0;
    }
    if (D_80135A60[1] != 0) {
        for (i = 1; i < freelist_capacity(D_80135A60[1]); i++) {
            if (freelist_is_element_alive(D_80135A60[1], i)) {
                entry = freelist_at(D_80135A60[1], i);
                _glpackvtx_entrypoint_1(*entry);
            }
        }
        freelist_free(D_80135A60[1]);
        D_80135A60[1] = 0;
    }
}    typedef struct { u8 pad0[0xA]; u8 unkA; } Obj1ED9D70_func_80100C74_entry; /* offsets.py genstruct: fields from raw offsets on entry; rename once understood */

void func_80100C74(void) {
    void *freelist_at(FreeList *, s32);
    s16 freelist_capacity(FreeList *);
    s32 freelist_is_element_alive(FreeList *, s32);
    extern FreeList *D_80135A60[2];
    s32 i;
    void **entry;
    u8 age;
    u8 next_age;

    for (i = 1; D_80135A60[0] != 0 && i < freelist_capacity(D_80135A60[0]); i++) {
        if (freelist_is_element_alive(D_80135A60[0], i)) {
            entry = freelist_at(D_80135A60[0], i);
            if (((Obj1ED9D70_func_80100C74_entry *)entry)->unkA != 0 &&
                --((Obj1ED9D70_func_80100C74_entry *)entry)->unkA == 0) {
                func_801009C4(entry, i);
            }
        }
    }
}

s16 func_80100D24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    typedef struct VertexListView {
        u8 pad0[0x16];
        u16 count : 15;
        u16 flags : 1;
        Vtx vertices[1];
    } VertexListView;
    void *func_800B2400(VertexListView *, s32);
    s32 func_800B2840(s32);
    s32 func_801007B8(s32, s32, s32, s32);
    struct Entry { VertexListView *vertices[2]; s8 index; s8 active; s8 age; };
    s32 index[2];
    struct Entry *entry;
    VertexListView *list;
    s32 i;
    entry = func_80100690(index);
    list = (VertexListView *)func_800B2840(arg0);
    for (i = 0; i < 2; i++) {
        if (i < arg2) {
            entry->vertices[i] = func_800B2400(list, 0);
            entry->vertices[i]->flags = 1;
        } else {
            entry->vertices[i] = NULL;
        }
    }
    if (arg3 != 0) {
        entry->index = func_801007B8(arg0, arg1, arg4, arg5);
    } else {
        entry->index = 0;
    }
    entry->active = 1;
    entry->age = 0;
    return index[0];
}

void func_80100E18(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80135A60[2];
    (*(s8 *)((s8 *)(freelist_at(D_80135A60[0], arg0)) + (0xA))) = 2;
}

void func_80100E54(void) { void *defrag(void *); void *freelist_at(FreeList *, s32); s16 freelist_capacity(FreeList *); s32 freelist_is_element_alive(FreeList *, s32); FreeList *freelist_defrag(FreeList *); extern FreeList *D_80135A60[2]; s32 i; void **entry; if (D_80135A60[0] != NULL) { D_80135A60[0] = freelist_defrag(D_80135A60[0]); } if (D_80135A60[1] != NULL) { for (i = 1; i < freelist_capacity(D_80135A60[1]); i++) { if (freelist_is_element_alive(D_80135A60[1], i)) { entry = freelist_at(D_80135A60[1], i); *entry = defrag(*entry); } } D_80135A60[1] = freelist_defrag(D_80135A60[1]); } }    typedef struct { u8 pad0[0x8]; s32 unk8; } Obj1ED9D70_D_80135A60; /* offsets.py genstruct: fields from raw offsets on &D_80135A60; rename once understood */

void func_80100F0C(s16 arg0, s32 arg1) {
    void *freelist_at(FreeList *, s32);
    s32 _glpackvtx_entrypoint_0(s32, s32, s32);
    s32 _glpackvtx_entrypoint_1(s32);
    s32 func_800B2840(s32);
    s32 func_800D674C(s32);
    void func_80100938(s32);
    extern FreeList *D_80135A60[2];
    struct Entry { s32 value; s16 asset; s16 age; u32 index : 8; u32 rest : 24; };
    struct Entry *sp34;
    struct Entry *var_s0;
    s32 temp_value;
    struct { s32 index; s32 asset; } sp24;

    sp34 = freelist_at(D_80135A60[0], arg0);
    if (sp34->index != 0) {
        var_s0 = freelist_at(D_80135A64, sp34->index);
        if (var_s0->index != 0) {
            sp24.asset = var_s0->asset;
            if (var_s0->age < 0x3666) {
                func_80100938(sp34->index);
                var_s0 = func_801006E0(&sp24.index);
                sp34->index = sp24.index;
            } else {
                _glpackvtx_entrypoint_1(var_s0->value);
            }
            temp_value = func_800D674C(sp24.asset);
            temp_value = func_800B2840(temp_value);
            var_s0->value = _glpackvtx_entrypoint_0(temp_value, arg1, 0);
            var_s0->asset = sp24.asset;
            var_s0->age = ((Obj1ED9D70_D_80135A60 *)&D_80135A60)->unk8;
            ((Obj1ED9D70_D_80135A60 *)&D_80135A60)->unk8 += 1;
            var_s0->index = 1;
        }
    }
}

#endif
