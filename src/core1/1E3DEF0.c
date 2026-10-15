#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3DEF0/func_800263C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3DEF0/func_8002645C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3DEF0/func_80026500.s")

/* extern */

void func_800266B0(ALEventQueue *arg0, s16 arg1) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    ALLink *sp2C;
    ALLink *sp28;
    ALEventListItem *sp24;
    ALEventListItem *sp20;
    u32 sp1C;

    sp1C = osSetIntMask(1U);
    sp2C = arg0->allocList.next;
    if (sp2C != NULL) {
        do {
            sp28 = sp2C->next;
            sp24 = (ALEventListItem *)sp2C;
            sp20 = (ALEventListItem *)sp28;
            if (sp24->evt.type == arg1) {
                if (sp20 != NULL) {
                    sp20->delta = sp20->delta + sp24->delta;
                }
                func_80020E74(sp2C);
                func_80020E40(sp2C, &arg0->freeList);
            }
            sp2C = sp28;
        } while (sp2C != NULL);
    }
    osSetIntMask(sp1C);
}

void func_80026780(s32 *arg0) {
    extern s32 *D_800411F4;
    u32 mask;
    mask = osSetIntMask(1U);
    arg0[4] = D_800411F4[8];
    arg0[0] = D_800411F4[0];
    D_800411F4[0] = (s32)arg0;
    osSetIntMask(mask);
}

void func_800267F0(s32 *arg0) {
    extern s32 *D_800411F4;
    u32 mask;
    mask = osSetIntMask(1U);
    arg0[4] = D_800411F4[8];
    arg0[0] = D_800411F4[0];
    D_800411F4[0] = (s32)arg0;
    osSetIntMask(mask);
}

void func_80026860(s32 *arg0) {
    extern s32 *D_800411F4;
    u32 mask;
    mask = osSetIntMask(1U);
    arg0[4] = D_800411F4[8];
    arg0[0] = D_800411F4[0];
    D_800411F4[0] = (s32)arg0;
    osSetIntMask(mask);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3DEF0/func_800268D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E3DEF0/func_80026AA4.s")
