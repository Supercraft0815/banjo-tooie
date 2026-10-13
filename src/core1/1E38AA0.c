#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80020F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021574.s")

typedef struct { u8 pad[4]; ALLink list; u8 padC[8]; ALLink *head; u8 pad18[0x14]; ALLink *free; u8 pad30[0x10]; s32 unk40; } PoolFreeList;

s32 *func_80021794(void) {
    extern PoolFreeList *D_800411F4;
    ALLink *sp4;

    sp4 = NULL;
    if (D_800411F4->free != NULL) {
        sp4 = D_800411F4->free;
        D_800411F4->free = D_800411F4->free->next;
        sp4->next = NULL;
    }
    return (s32 *)sp4;
}

void func_800217F4(ALLink *arg0) {
    extern PoolFreeList *D_800411F4;

    arg0->next = D_800411F4->free;
    D_800411F4->free = arg0;
}

void func_80021820(void) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    extern PoolFreeList *D_800411F4;
    ALLink *sp1C;

    if ((sp1C = D_800411F4->head) != NULL) {
        do {
            func_80020E74(sp1C);
            func_80020E40(sp1C, &D_800411F4->list);
        } while ((sp1C = D_800411F4->head) != NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021884.s")

s32 func_800218C4(s32 arg0) {
    extern PoolFreeList *D_800411F4;
    extern f32 D_80041980;
    volatile f32 sp4;

    sp4 = ((f32) arg0 * (f32) D_800411F4->unk40 / D_80041980) + 0.5f;
    return (s32) sp4;
}

/* extern */

s32 func_80021928(s32 arg0) {
    s32 func_800218C4(s32);
    return func_800218C4(arg0) & ~0xF;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021960.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021A00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021AD0.s")
