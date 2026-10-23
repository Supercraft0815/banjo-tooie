#include "common.h"

typedef struct SynthVoice {
    ALLink link;
    s32 unk8;
    u8 padC[0xB4];
} SynthVoice;

typedef struct SynthUpdate {
    ALLink link;
    u8 pad8[0x1C];
} SynthUpdate;

typedef struct SynthAux {
    s16 unk0;
    s16 unk2;
    u8 pad4[0x28];
    void *unk2C;
    void *unk30;
    s32 unk34;
} SynthAux;

typedef struct SynthBus {
    u8 pad0[0x14];
    s32 count;
    s32 capacity;
    SynthVoice **voices;
    s32 effect;
    u8 pad24[0x20];
    SynthAux *aux;
} SynthBus;

typedef struct {
    ALPlayer *players;
    ALLink list;
    ALLink unkC;
    ALLink *head;
    ALLink *unk18;
    s32 paramSamples;
    s32 curSamples;
    s32 unk24;
    void *heap;
    ALLink *free;
    u8 *unk30;
    SynthBus *busses;
    s32 maxVoices;
    s32 numBusses;
    s32 unk40;
    s32 maxSamples;
    s16 *outBuf;
    s32 unk4C;
} PoolFreeList;

s32 func_80020F70(s32 arg0) {
    extern PoolFreeList *D_800411F4;
    void func_800272B0(void);
    void func_80020E40(ALLink *, ALLink *);
    s32 func_80020EE4(s32, s32, void *, s32, s32);
    s32 func_80027220(s16, s32, s32);
    void func_800293B4(void *, s32, void *);
    s32 i;
    s32 j;
    SynthVoice *voice;
    SynthVoice *voices;
    void *heap;
    SynthUpdate *items;
    SynthUpdate *item;

    heap = (void *)((s32 *)arg0)[5];
    D_800411F4->players = NULL;
    D_800411F4->maxVoices = ((s32 *)arg0)[1];
    D_800411F4->curSamples = 0;
    D_800411F4->paramSamples = 0;
    D_800411F4->unk40 = ((s32 *)arg0)[6];
    D_800411F4->maxSamples = 0xB8;
    D_800411F4->unk24 = ((s32 *)arg0)[4];
    D_800411F4->outBuf = 0;
    D_800411F4->unk4C = 1;
    if (((s32 *)arg0)[3] >= 2) {
        D_800411F4->numBusses = 1;
    } else if (((s32 *)arg0)[3] <= 0) {
        D_800411F4->numBusses = 1;
    } else {
        D_800411F4->numBusses = ((s32 *)arg0)[3];
    }
    D_800411F4->busses = (SynthBus *)func_80020EE4(0, 0, heap, D_800411F4->numBusses, sizeof(SynthBus));
    for (i = 0; i < D_800411F4->numBusses; i++) {
        D_800411F4->busses[i].count = 0;
        D_800411F4->busses[i].capacity = ((s32 *)arg0)[1];
        D_800411F4->busses[i].voices = (SynthVoice **)func_80020EE4(0, 0, heap, ((s32 *)arg0)[1], sizeof(SynthVoice *));
        if (((u8 *)arg0)[0x1C + i] != 0) {
            D_800411F4->busses[i].effect = func_80027220(i, arg0, (s32)heap);
        } else {
            D_800411F4->busses[i].effect = 0;
        }
        D_800411F4->busses[i].aux = (SynthAux *)func_80020EE4(0, 0, heap, 1, sizeof(SynthAux));
        D_800411F4->busses[i].aux->unk2 = 0;
        D_800411F4->busses[i].aux->unk2C = (void *)func_80020EE4(0, 0, heap, 1, 8);
        D_800411F4->busses[i].aux->unk30 = (void *)func_80020EE4(0, 0, heap, 1, 8);
    }
    D_800411F4->unk30 = (u8 *)func_80020EE4(0, 0, heap, 1, 0x14);
    *(void (**)(void))(D_800411F4->unk30 + 4) = func_800272B0;
    D_800411F4->list.next = NULL;
    D_800411F4->list.prev = NULL;
    D_800411F4->head = NULL;
    D_800411F4->unk18 = NULL;
    D_800411F4->unkC.next = NULL;
    D_800411F4->unkC.prev = NULL;
    voices = (SynthVoice *)func_80020EE4(0, 0, heap, ((s32 *)arg0)[1], sizeof(SynthVoice));
    for (i = 0; i < ((s32 *)arg0)[1]; i++) {
        voice = &voices[i];
        func_80020E40(&voice->link, &D_800411F4->list);
        voice->unk8 = 0;
        func_800293B4(voice, D_800411F4->unk24, heap);
        for (j = 0; j < D_800411F4->numBusses; j++) {
            D_800411F4->busses[j].voices[D_800411F4->busses[j].count++] = voice;
        }
    }
    items = (SynthUpdate *)func_80020EE4(0, 0, heap, ((s32 *)arg0)[2], sizeof(SynthUpdate));
    D_800411F4->free = NULL;
    for (i = 0; i < ((s32 *)arg0)[2]; i++) {
        item = &items[i];
        item->link.next = D_800411F4->free;
        D_800411F4->free = &item->link;
    }
    D_800411F4->heap = heap;
}

Acmd *func_80021574(Acmd *arg0, s32 *arg1, s16 *arg2, s32 arg3) {
    void func_80021820(void);
    s32 func_800218C4(s32);
    s32 func_80021960(ALPlayer **);
    Acmd *func_800295D0(s32, Acmd *);
    extern PoolFreeList *D_800411F4;
    ALPlayer *sp3C;
    Acmd *sp38;
    Acmd *sp34;
    s32 sp30;
    s16 *sp2C;

    sp38 = arg0;
    sp2C = arg2;
    if (D_800411F4->players == NULL) {
        *arg1 = 0;
        return arg0;
    }
    while ((D_800411F4->paramSamples = func_80021960(&sp3C),
        D_800411F4->paramSamples - D_800411F4->curSamples < arg3)) {
            D_800411F4->paramSamples &= ~0xF;
            sp3C->samplesLeft += func_800218C4(sp3C->handler(sp3C));
    }
        D_800411F4->paramSamples &= ~0xF;
        while (arg3 > 0) {
            sp30 = D_800411F4->maxSamples < arg3 ? D_800411F4->maxSamples : arg3;
            sp34 = sp38;
            D_800411F4->outBuf = sp2C;
            sp38 = func_800295D0(D_800411F4->curSamples, sp34);
            arg3 -= sp30;
            sp2C += sp30 * 2;
            D_800411F4->curSamples += sp30;
        }
        *arg1 = sp38 - arg0;
        func_80021820();
        return sp38;
}

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

void func_80021884(ALLink *arg0) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    extern PoolFreeList *D_800411F4;
    func_80020E74(arg0);
    func_80020E40(arg0, (ALLink *)((u8 *)D_800411F4 + 0x14));
}

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

s32 func_80021960(ALPlayer **arg0) {
    extern PoolFreeList *D_800411F4;
    s32 sp4;
    ALPlayer *sp0;

    sp4 = 0x7FFFFFFF;
    *arg0 = NULL;
    if ((sp0 = D_800411F4->players) != NULL) {
        do {
            if (sp0->samplesLeft - D_800411F4->curSamples < sp4) {
                *arg0 = sp0;
                sp4 = sp0->samplesLeft - D_800411F4->curSamples;
            }
        } while ((sp0 = sp0->next) != NULL);
    }
    return (*arg0)->samplesLeft;
}

void func_80021A00(u8 arg0) {
    extern u8 D_8007EA30;
    extern u8 D_8007EA31;
    extern u8 D_8007EA32;
    s32 func_80021AD0();
    s32 i;

    D_8007EA30 = 0;
    D_8007EA31 = 0;
    D_8007EA32 = 0;
    switch (arg0) {
        case 1:
            D_8007EA31 = 1;
            break;
        case 3:
            D_8007EA32 = 1;
            break;
        case 4:
            D_8007EA30 = 1;
            break;
    }
    i = 0;
    do {
        func_80021AD0(i, 0);
    } while (++i <= 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38AA0/func_80021AD0.s")
