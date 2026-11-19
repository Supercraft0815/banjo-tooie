#include "common.h"

extern ALSynth *D_800411F4;

void func_800263C0(ALEventQueue *arg0, ALEventListItem *arg1, s32 arg2) {
    void func_80020E40(ALLink *, ALLink *);
    s32 i;

    arg0->eventCount = 0;
    arg0->allocList.next = NULL;
    arg0->allocList.prev = NULL;
    arg0->freeList.next = NULL;
    arg0->freeList.prev = NULL;
    for (i = 0; i < arg2; i++) {
        func_80020E40((ALLink *)&arg1[i], &arg0->freeList);
    }
}

s32 func_8002645C(ALEventQueue *arg0, ALEvent *arg1) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    ALEventListItem *item;
    s32 delta;
    u32 mask;

    mask = osSetIntMask(1U);
    item = (ALEventListItem *)arg0->allocList.next;
    if (item != NULL) {
        func_80020E74(&item->node);
        bcopy(&item->evt, arg1, 0x10);
        func_80020E40(&item->node, &arg0->freeList);
        delta = item->delta;
    } else {
        arg1->type = -1;
        delta = 0;
    }
    osSetIntMask(mask);
    return delta;
}

void func_80026500(ALEventQueue *arg0, void *arg1, s32 arg2, s32 arg3) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    ALEventListItem *sp2C;
    ALEventListItem *sp28;
    ALLink *sp24;
    s32 sp20;
    u32 sp1C;

    sp20 = 0;
    sp1C = osSetIntMask(1U);
    sp2C = (ALEventListItem *)arg0->freeList.next;
    if (sp2C == NULL) {
        osSetIntMask(sp1C);
        return;
    }
    if (sp2C->node.next == NULL && arg3 == 0) {
        osSetIntMask(sp1C);
        return;
    }
    func_80020E74(&sp2C->node);
    bcopy(arg1, &sp2C->evt, 0x10);
    if (arg2 == 0x7FFFFFFF) {
        sp20 = -1;
    }
    for (sp24 = &arg0->allocList; sp24 != NULL; sp24 = sp24->next) {
        if (sp24->next == NULL) {
            if (sp20 != 0) {
                sp2C->delta = 0;
            } else {
                sp2C->delta = arg2;
            }
            func_80020E40(&sp2C->node, sp24);
            break;
        } else {
            sp28 = (ALEventListItem *)sp24->next;
            if (arg2 < sp28->delta) {
                sp2C->delta = arg2;
                sp28->delta -= arg2;
                func_80020E40(&sp2C->node, sp24);
                break;
            }
            arg2 -= sp28->delta;
        }
    }
    osSetIntMask(sp1C);
}

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

void func_80026780(ALPlayer *arg0) {
    u32 mask;
    mask = osSetIntMask(1U);
    arg0->samplesLeft = D_800411F4->curSamples;
    arg0->next = D_800411F4->head;
    D_800411F4->head = arg0;
    osSetIntMask(mask);
}

void func_800267F0(ALPlayer *arg0) {
    u32 mask;
    mask = osSetIntMask(1U);
    arg0->samplesLeft = D_800411F4->curSamples;
    arg0->next = D_800411F4->head;
    D_800411F4->head = arg0;
    osSetIntMask(mask);
}

void func_80026860(ALPlayer *arg0) {
    u32 mask;
    mask = osSetIntMask(1U);
    arg0->samplesLeft = D_800411F4->curSamples;
    arg0->next = D_800411F4->head;
    D_800411F4->head = arg0;
    osSetIntMask(mask);
}

s32 func_800268D0(ALVoice *arg0, ALVoiceConfig *arg1) {
    s32 *func_80021794(void);
    s32 func_80026AA4(ALLink **, s16);
    s32 func_8002B684(void *, s32, void *);
    struct PhysicalVoice {
        ALLink node;
        ALVoice *voice;
        u8 padC[0x7C];
        s32 offset;
    };
    ALLink *sp24;
    s32 *sp20;
    s32 sp1C;

    sp24 = NULL;
    arg0->priority = arg1->priority;
    arg0->unityPitch = arg1->unityPitch;
    arg0->table = NULL;
    arg0->fxBus = arg1->fxBus;
    arg0->state = 0;
    arg0->pvoice = NULL;
    sp1C = func_80026AA4(&sp24, arg1->priority);
    if (sp24 != NULL) {
        if (sp1C != 0) {
            ((struct PhysicalVoice *)sp24)->offset = 0x228;
            ((struct PhysicalVoice *)sp24)->voice->pvoice = NULL;
            ((struct PhysicalVoice *)sp24)->voice = arg0;
            arg0->pvoice = (struct PVoice_s *)sp24;
            sp20 = func_80021794();
            if (sp20 != NULL) {
                sp20[1] = D_800411F4->paramSamples;
                ((s16 *)sp20)[4] = 0xB;
                sp20[3] = 0;
                sp20[4] = 0x170;
                func_8002B684(arg0->pvoice, 3, sp20);
            } else {
            }
            sp20 = func_80021794();
            if (sp20 != NULL) {
                sp20[1] = D_800411F4->paramSamples + ((struct PhysicalVoice *)sp24)->offset;
                ((s16 *)sp20)[4] = 0xF;
                sp20[0] = 0;
                func_8002B684(arg0->pvoice, 3, sp20);
            } else {
            }
        } else {
            ((struct PhysicalVoice *)sp24)->offset = 0;
            ((struct PhysicalVoice *)sp24)->voice = arg0;
            arg0->pvoice = (struct PVoice_s *)sp24;
        }
    }
    return sp24 != NULL;
}

s32 func_80026AA4(ALLink **arg0, s16 arg1) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    struct PhysicalVoice {
        ALLink node;
        ALVoice *voice;
        u8 padC[0x7C];
        s32 offset;
    };
    ALLink *sp24;
    struct PhysicalVoice *sp20;
    s32 sp1C;

    sp1C = 0;
    if ((sp24 = D_800411F4->pLameList.next) != NULL) {
        *arg0 = sp24;
        func_80020E74(sp24);
        func_80020E40(sp24, &D_800411F4->pAllocList);
    } else {
        if ((sp24 = D_800411F4->pFreeList.next) != NULL) {
            *arg0 = sp24;
            func_80020E74(sp24);
            func_80020E40(sp24, &D_800411F4->pAllocList);
        } else {
            if ((sp24 = D_800411F4->pAllocList.next) != NULL) {
                do {
                    sp20 = (struct PhysicalVoice *)sp24;
                    if (sp20->voice->priority <= arg1 && sp20->offset == 0) {
                        *arg0 = &sp20->node;
                        arg1 = sp20->voice->priority;
                        sp1C = 1;
                    }
                } while ((sp24 = sp24->next) != NULL);
            }
        }
    }
    return sp1C;
}
