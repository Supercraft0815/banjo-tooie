#include "common.h"

void *func_80100480(s32 arg0, s32 arg1) {
    s32 func_8001211C(void);
    void *heap_alloc(s32);
    void *heap_realloc(void *, s32);
    extern s32 D_801243A0;
    void *temp_a2;
    s8 *temp_s0;

    temp_s0 = (s8 *)&D_801243A0 + arg0 * 0xC;
    temp_a2 = *(void **)(temp_s0 + 8);
    if (temp_a2 == 0) {
        (*(s16 *)((s8 *)(temp_s0) + (2))) = arg1;
        *(void **)(temp_s0 + 8) = heap_alloc(*(s16 *)(temp_s0 + 2) * *(s16 *)(temp_s0 + 0));
    } else if ((*(s16 *)((s8 *)(temp_s0) + (2))) < arg1) {
        (*(s16 *)((s8 *)(temp_s0) + (2))) = arg1;
        *(void **)(temp_s0 + 8) = heap_realloc(temp_a2, *(s16 *)(temp_s0 + 2) * *(s16 *)(temp_s0 + 0));
    }
    (*(s32 *)((s8 *)(temp_s0) + (4))) = func_8001211C();
    return *(void **)(temp_s0 + 8);
}

void func_8010052C(void) {
}

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
        if ((temp_a0 != 0) && ((temp_s2 - (*(s32 *)((s8 *)(var_s0) + (4)))) >= 0x1F)) {
            heap_free(temp_a0);
            (*(s32 *)((s8 *)(var_s0) + (8))) = 0;
            (*(s16 *)((s8 *)(var_s0) + (2))) = 0;
            (*(s32 *)((s8 *)(var_s0) + (4))) = 0;
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

void func_80100690(s32 *arg0) {
    FreeList *freelist_new(s32, s32);
    void *freelist_next(FreeList **, s32 *);
    extern FreeList *D_80135A60[2];
    if (D_80135A60[0] == 0) {
        D_80135A60[0] = freelist_new(0xC, 2);
    }
    freelist_next(&D_80135A60[0], arg0);
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_801007B8.s")

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
}

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
    (*(s8 *)((s8 *)(arg0) + (9))) = 0;
    freelist_erase(D_80135A60[0], arg1);
    if (freelist_used_count(D_80135A60[0]) == 0) {
        freelist_free(D_80135A60[0]);
        D_80135A60[0] = 0;
    }
}

s32 func_80100A74(s16 arg0, s32 arg1) { extern FreeList *D_80135A60[2]; void *freelist_at(FreeList *, s32); s32 var_v1; u8 *temp_v0;
    temp_v0 = freelist_at(D_80135A60[0], arg0); if (temp_v0[9] != 0) { var_v1 = ((s32 *)temp_v0)[arg1]; } else { var_v1 = 0; } return var_v1; }

s32 func_80100AC4(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80135A60[2];
    extern FreeList *D_80135A64;
    s32 var_v1;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = freelist_at(D_80135A60[0], arg0);
    if ((*(u8 *)((s8 *)(temp_v0) + (8))) == 0) {
        return 0;
    }
    temp_v0_2 = freelist_at(D_80135A64, (s16) (*(u8 *)((s8 *)(temp_v0) + (8))));
    if ((*(u8 *)((s8 *)(temp_v0_2) + (8))) != 0) {
        var_v1 = (*(s32 *)((s8 *)(temp_v0_2) + (0)));
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_80100B3C(void) {
    extern s32 D_80135A68;
    D_80135A68 = 0x3667;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100B4C.s")

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
            if (*(u8 *)((s8 *)entry + 0xA) != 0 &&
                --*(u8 *)((s8 *)entry + 0xA) == 0) {
                func_801009C4(entry, i);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100D24.s")

void func_80100E18(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80135A60[2];
    (*(s8 *)((s8 *)(freelist_at(D_80135A60[0], arg0)) + (0xA))) = 2;
}

void func_80100E54(void) { void *defrag(void *); void *freelist_at(FreeList *, s32); s16 freelist_capacity(FreeList *); s32 freelist_is_element_alive(FreeList *, s32); FreeList *freelist_defrag(FreeList *); extern FreeList *D_80135A60[2]; s32 i; void **entry; if (D_80135A60[0] != NULL) { D_80135A60[0] = freelist_defrag(D_80135A60[0]); } if (D_80135A60[1] != NULL) { for (i = 1; i < freelist_capacity(D_80135A60[1]); i++) { if (freelist_is_element_alive(D_80135A60[1], i)) { entry = freelist_at(D_80135A60[1], i); *entry = defrag(*entry); } } D_80135A60[1] = freelist_defrag(D_80135A60[1]); } }

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
            var_s0->age = *(s32 *)((u8 *)&D_80135A60 + 8);
            *(s32 *)((u8 *)&D_80135A60 + 8) += 1;
            var_s0->index = 1;
        }
    }
}
