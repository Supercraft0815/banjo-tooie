#include "common.h"

void func_801065E0(void) {
    s32 vector_new(s32, s32);
    extern s32 D_80136EE0;
    D_80136EE0 = vector_new(0x9C, 30);
}

void func_80106608(void) {
    s32 vector_free(s32);
    extern s32 D_80136EE0;
    vector_free(D_80136EE0);
    D_80136EE0 = 0;
}

void func_80106630(void) {
    s32 vector_defrag(s32);
    extern s32 D_80136EE0;
    if (D_80136EE0 != 0) {
        D_80136EE0 = vector_defrag(D_80136EE0);
    }
}

void *func_80106668(s32 *arg0) {
    s32 vector_index_of(s32, void *);
    void *vector_push_back(s32 *);
    extern s32 D_80136EE0;
    void *sp1C;

    *arg0 = 0;
    sp1C = vector_push_back(&D_80136EE0);
    *arg0 = vector_index_of(D_80136EE0, sp1C);
    bzero(sp1C, 0x9C);
    return sp1C;
}

void func_801066C0(s32 arg0) {
    s32 vector_erase_unordered(s32, s32);
    s32 vector_size(s32);
    s32 vector_at(s32, s32);
    extern s32 D_80136EE0;
    struct Entry {
        u8 pad[0x1A];
        u16 index : 11;
        u16 flags : 5;
    } *entry;

    vector_erase_unordered(D_80136EE0, arg0);
    if (arg0 < vector_size(D_80136EE0)) {
        entry = *(struct Entry **)(u32)vector_at(D_80136EE0, arg0);
        entry->index = arg0;
    }
}

s32 func_80106730(void) {
    s32 vector_size(s32);
    extern s32 D_80136EE0;
    if (D_80136EE0 == 0) {
        return 0;
    }
    return vector_size(D_80136EE0);
}

void func_80106768(s32 arg0) {
    s32 vector_at(s32, s32);
    extern s32 D_80136EE0;
    vector_at(D_80136EE0, arg0);
}

Actor *func_80106790(Unk80132ED0 *arg0) {
    extern s32 D_80136EE0;
    s32 vector_at(s32, s32);
    return vector_at(D_80136EE0, (u32) (*(u16 *)((s8 *)(arg0) + 0x1A)) >> 5);
}

s32 func_801067C4(s32 *arg0) {
    s32 vector_size(s32);
    s32 vector_at(s32, s32);
    extern s32 D_80136EE0;

    if (D_80136EE0 == 0) {
        return 0;
    }
    *arg0 = vector_size(D_80136EE0) - 1;
    if (*arg0 >= 0) {
        return vector_at(D_80136EE0, *arg0);
    }
    return 0;
}

s32 func_8010682C(s32 *arg0) {
    s32 vector_size(s32);
    s32 vector_at(s32, s32);
    extern s32 D_80136EE0;
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
    s32 vector_size(s32);
    s32 vector_at(s32, s32);
    extern s32 D_80136EE0;
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDFED0/func_80106920.s")

s32 func_801069A4(Unk80132ED0 *arg0) {
    s32 vector_size(s32);
    extern s32 D_80136EE0;
    s32 result;

    if (D_80136EE0 == 0) {
        return 0;
    }
    if (arg0 == NULL || !(((u16 *)&arg0->unk18)[0] & 1)) {
        return 0;
    }
    result = (s32)((u32)((u16 *)&arg0->unk18)[1] >> 5) < vector_size(D_80136EE0);
    return result;
}
