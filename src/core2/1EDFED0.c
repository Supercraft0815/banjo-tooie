#include "common.h"
#ifdef BT_NATIVE
#include "native_actor.h"
#include "memory.h"
Vector *D_80136EE0;
#define ACTOR_SIZE ((s32)sizeof(Actor))
#else
#define ACTOR_SIZE 0x9C
#endif

void func_801065E0(void) {
#ifndef BT_NATIVE
    s32 vector_new(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    D_80136EE0 = vector_new(ACTOR_SIZE, 30);
}

void func_80106608(void) {
#ifndef BT_NATIVE
    s32 vector_free(s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    vector_free(D_80136EE0);
    D_80136EE0 = 0;
}

void func_80106630(void) {
#ifndef BT_NATIVE
    s32 vector_defrag(s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    if (D_80136EE0 != 0) {
        D_80136EE0 = vector_defrag(D_80136EE0);
    }
}

void *func_80106668(s32 *arg0) {
#ifndef BT_NATIVE
    s32 vector_index_of(s32, void *);
#endif
#ifndef BT_NATIVE
    void *vector_push_back(s32 *);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    void *sp1C;

    *arg0 = 0;
#ifdef BT_NATIVE
    if (!D_80136EE0 || vector_size(D_80136EE0) >= 0x800) { *arg0 = -1; return NULL; }
#endif
    sp1C = vector_push_back(&D_80136EE0);
    *arg0 = vector_index_of(D_80136EE0, sp1C);
    bzero(sp1C, ACTOR_SIZE);
    return sp1C;
}

void func_801066C0(s32 arg0) {
#ifndef BT_NATIVE
    s32 vector_erase_unordered(s32, s32);
#endif
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    struct Entry {
        u8 pad[0x1A];
        u16 index : 11;
        u16 flags : 5;
    } *entry;

#ifdef BT_NATIVE
    if (!D_80136EE0 || arg0 < 0 || arg0 >= vector_size(D_80136EE0)) return;
#endif
    vector_erase_unordered(D_80136EE0, arg0);
    if (arg0 < vector_size(D_80136EE0)) {
#ifdef BT_NATIVE
        Unk80132ED0 *marker = ((Actor *)vector_at(D_80136EE0, arg0))->unk0;
        if (marker) marker->unk18 = (marker->unk18 & ~0xFFE0u) | ((u32)arg0 << 5);
#else
        entry = *(struct Entry **)(u32)vector_at(D_80136EE0, arg0);
        entry->index = arg0;
#endif
    }
}

s32 func_80106730(void) {
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    if (D_80136EE0 == 0) {
        return 0;
    }
    return vector_size(D_80136EE0);
}

#ifdef BT_NATIVE
Actor *func_80106768(s32 arg0)
#else
void func_80106768(s32 arg0)
#endif
{
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
#ifdef BT_NATIVE
    if (!D_80136EE0 || arg0 < 0 || arg0 >= vector_size(D_80136EE0)) return NULL;
    return vector_at(D_80136EE0, arg0);
#else
    vector_at(D_80136EE0, arg0);
#endif
}

Actor *func_80106790(Unk80132ED0 *arg0) {
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifdef BT_NATIVE
    if (!func_801069A4(arg0)) return NULL;
    return vector_at(D_80136EE0, (arg0->unk18 >> 5) & 0x7FF);
#else
    return vector_at(D_80136EE0, (u32) (*(u16 *)((s8 *)(arg0) + 0x1A)) >> 5);
#endif
}

#ifdef BT_NATIVE
Actor *func_801067C4(s32 *arg0)
#else
s32 func_801067C4(s32 *arg0)
#endif
{
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif

    if (D_80136EE0 == 0) {
        return 0;
    }
    *arg0 = vector_size(D_80136EE0) - 1;
    if (*arg0 >= 0) {
        return vector_at(D_80136EE0, *arg0);
    }
    return 0;
}

#ifdef BT_NATIVE
Actor *func_8010682C(s32 *arg0)
#else
s32 func_8010682C(s32 *arg0)
#endif
{
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    s32 size;
    s32 index;

    if (D_80136EE0 == 0) {
        return 0;
    }
    size = vector_size(D_80136EE0);
    index = *arg0;
    if (index >= size) {
        *arg0 = size;
        index = size;
    }
    if (index > 0) {
        *arg0 = index - 1;
        return vector_at(D_80136EE0, *arg0);
    }
    return 0;
}

Actor *func_801068A8(s32 *arg0) {
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    s32 size;
    s32 index;

    if (D_80136EE0 == 0) {
        return NULL;
    }
    size = vector_size(D_80136EE0);
    if (size > 0) {
        index = *arg0;
        if (index < 0 || index >= size) {
            *arg0 = 0;
            index = 0;
        }
        return vector_at(D_80136EE0, index);
    }
    return NULL;
}

Actor *func_80106920(s32 *arg0) {
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    s32 vector_at(s32, s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    s32 size;
    s32 index;

    if (D_80136EE0 == 0) {
        return NULL;
    }
    size = vector_size(D_80136EE0);
    index = --*arg0;
    if (index < 0 || index >= size) {
        index = size - 1;
        *arg0 = index;
    }
    if (index >= 0) {
        return vector_at(D_80136EE0, index);
    }
    return NULL;
}

s32 func_801069A4(Unk80132ED0 *arg0) {
#ifndef BT_NATIVE
    s32 vector_size(s32);
#endif
#ifndef BT_NATIVE
    extern s32 D_80136EE0;
#endif
    s32 result;

    if (D_80136EE0 == 0) {
        return 0;
    }
#ifdef BT_NATIVE
    if (arg0 == NULL || !(arg0->unk18 & 0x10000)) {
#else
    if (arg0 == NULL || !(((u16 *)&arg0->unk18)[0] & 1)) {
#endif
        return 0;
    }
#ifdef BT_NATIVE
    result = (arg0->unk18 >> 5) & 0x7FF;
    return result < vector_size(D_80136EE0) && ((Actor *)vector_at(D_80136EE0, result))->unk0 == arg0;
#else
    result = (s32)((u32)((u16 *)&arg0->unk18)[1] >> 5) < vector_size(D_80136EE0);
#endif
    return result;
}
