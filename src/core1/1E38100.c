#include "common.h"
#include "core1/sfx_player.h"

void func_800205D0(SfxState *arg0) {
    void func_80020E74(ALLink *);
    void func_800E90A4(BtIntPtr, s32);
    extern struct SfxState *D_800411D0;
    extern struct SfxState *D_800411D4;
    extern struct SfxState *D_800411D8;
    BT_IDO_ONLY(extern s16 D_800411E0;)
    u32 mask;

    mask = osSetIntMask(1U);
    if (D_800411D0 == arg0) {
        D_800411D0 = arg0->next;
    }
    if (D_800411D4 == arg0) {
        D_800411D4 = arg0->prev;
    }
    func_80020E74((ALLink *)arg0);
    if (D_800411D8 != NULL) {
        arg0->next = D_800411D8;
        arg0->prev = NULL;
        D_800411D8->prev = arg0;
        D_800411D8 = arg0;
    } else {
        arg0->prev = NULL;
        arg0->next = arg0->prev;
        D_800411D8 = arg0;
    }
    if (arg0->flags & 4) {
        BT_DATA_FIELD(sfx_voice_count.active, D_800411E0) -= 1;
    }
    arg0->phase = 0;
    if (arg0->handle != NULL) {
        if (*arg0->handle == arg0) {
            *arg0->handle = NULL;
        }
        arg0->handle = NULL;
    }
    func_800E90A4((BtIntPtr)arg0->sound, 0);
    osSetIntMask(mask);
}

void func_80020738(void *arg0, u8 arg1) {
    if (arg0 != NULL) {
        ((SfxState *)arg0)->priority = (s16)arg1;
    }
}

s32 func_80020760(void *arg0) {
    if (arg0 != NULL) {
        return ((SfxState *)arg0)->phase;
    } else {
        return 0;
    }
}

struct SfxState *func_80020790(s16 arg0, u16 arg1, u8 arg2, f32 arg3, u8 arg4, u8 arg5, BtIntPtr arg6) {
    struct SfxState *func_8002039C(struct SfxSound *);
    void func_80026500(void *, void *, s32, s32);
    u8 *func_800E9320(s32, s32);
    extern SfxPlayer *D_800411DC;
    struct SfxState *sp5C;
    struct SfxState *sp58;
    SfxKeyMap *sp54;
    SfxSound *sp50;
    s16 sp4E;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    SfxEvent evt1;
    SfxEvent evt2;

    sp58 = NULL;
    sp4E = 0;
    sp40 = 0;
    if (arg0 != 0) {
        do {
            sp50 = (SfxSound *)func_800E9320(0, arg0 - 1);
            sp5C = func_8002039C(sp50);
            if (sp5C != NULL) {
                D_800411DC->lastStarted = sp5C;
                evt1.type = 1;
                evt1.state = sp5C;
                sp3C = arg2 + sp5C->pan - 0x40;
                if (sp3C >= 0x80) {
                    sp3C = 0x7F;
                } else if (sp3C < 0) {
                    sp3C = 0;
                }
                sp5C->pan = sp3C;
                sp5C->volume = (u32)(arg1 * sp5C->volume) >> 15;
                sp5C->pitchRatio *= arg3;
                sp5C->fxMix = arg4;
                sp5C->fxBus = arg5;
                sp44 = sp50->key.velocityMax * 33333;
                if (sp5C->flags & 0x10) {
                    sp5C->flags &= ~0x10;
                    func_80026500(&D_800411DC->queue, &evt1, sp40 + 1, 0);
                    sp48 = sp44 + 1;
                    sp4E = arg0;
                } else {
                    func_80026500(&D_800411DC->queue, &evt1, sp44 + 1, 0);
                }
                sp58 = sp5C;
            }
            BT_NATIVE_ONLY(if (sp5C != NULL)) sp40 += sp44;
            sp54 = &sp50->key;
            arg0 = sp54->velocityMin + ((sp54->keyMin & 0xC0) * 4);
        } while (arg0 != 0 && sp5C != NULL);
        if (sp58 != NULL) {
            sp58->flags |= 1;
            sp58->handle = (SfxState **)arg6;
            if (sp4E != 0) {
                sp58->flags |= 0x10;
                evt2.type = 0x200;
                evt2.state = sp58;
                evt2.value.data = sp4E;
                func_80026500(&D_800411DC->queue, &evt2, sp48, 0);
            }
        }
    }
    if (arg6 != 0) {
        *(struct SfxState **)arg6 = sp58;
    }
    return sp58;
}

void func_80020A60(void *arg0) {
    SfxEvent evt;
    extern SfxPlayer *D_800411DC;
    void func_80026500(void *, void *, s32, s32);

    evt.type = 0x400;
    evt.state = arg0;
    if (arg0 != NULL) {
        evt.state->flags &= ~0x10;
        func_80026500(&D_800411DC->queue, &evt, 0, 0);
    }
}

void func_80020AD0(u8 arg0) {
    extern struct SfxState *D_800411D0;
    extern SfxPlayer *D_800411DC;
    void func_80026500(void *, void *, s32, s32);
    u32 mask;
    SfxEvent evt;
    void *state;

    mask = osSetIntMask(1U);
    state = D_800411D0;
    if (state != NULL) {
        do {
            evt.type = 0x400;
            evt.state = state;
            if ((((SfxState *)state)->flags & arg0) == arg0) {
                evt.state->flags &= ~0x10;
                func_80026500(&D_800411DC->queue, &evt, 0, 0);
            }
            state = *(void **)state;
        } while (state != NULL);
    }
    osSetIntMask(mask);
}

void func_80020B90(void) {
    void func_80020AD0(u8);

    func_80020AD0(1);
}

void func_80020BB8(void) {
    void func_80020AD0(u8);

    func_80020AD0(0x11);
}

void func_80020BE0(void) {
    void func_80020AD0(u8);

    func_80020AD0(3);
}

void func_80020C08(SfxVoiceRef volatile arg0, volatile s16 arg1, volatile s32 arg2) {
    extern SfxPlayer *D_800411DC;
    void func_80026500(void *, void *, s32, s32);
    SfxEvent event;

    event.type = arg1;
    event.state = (SfxState *)arg0;
    event.value.data = arg2;
    if (arg0 != 0) {
        func_80026500(&D_800411DC->queue, &event, 0, 0);
    }
}

s32 func_80020C74(u8 arg0) {
    extern u16 *D_8007EA24;

    return D_8007EA24[arg0];
}

void func_80020CA0(u8 arg0, u16 arg1) {
    extern struct SfxState *D_800411D0;
    extern SfxPlayer *D_800411DC;
    extern u16 *D_8007EA24;
    void func_80026500(void *, void *, s32, s32);
    u32 mask;
    void *volatile state;
    s32 count;
    SfxEvent event;

    mask = osSetIntMask(1U);
    state = D_800411D0;
    D_8007EA24[arg0] = arg1;
    for (count = 0; state != NULL; count++, state = *(void **)state) {
            if ((((SfxState *)state)->sound->key.keyMin & 0x1F) == arg0) {
                event.type = 0x800;
                event.state = state;
                func_80026500(&D_800411DC->queue, &event, 0, 0);
            }
    }
    osSetIntMask(mask);
}

#ifdef BT_NATIVE
void func_80020D80(BtIntPtr arg0, BtIntPtr arg1) {
    s32 func_80020F70(BtIntPtr);
    extern void *D_800411F0;
    extern void *D_800411F4;
    if (D_800411F0 == NULL) {
        D_800411F0 = (void *)arg0;
        if (D_800411F4 == NULL) {
            D_800411F4 = D_800411F0;
            func_80020F70(arg1);
        }
    }
}
#else
void func_80020D80(s32 arg0, s32 arg1) {
    s32 func_80020F70(BtIntPtr);
    extern s32 D_800411F0;
    extern s32 D_800411F4;
    if (D_800411F0 == 0) {
        D_800411F0 = arg0;
        if (D_800411F4 == 0) {
            D_800411F4 = D_800411F0;
            func_80020F70(arg1);
        }
    }
}
#endif

#ifdef BT_NATIVE
void func_80020DEC(s32 arg0) {
    void func_80027200(void);
    extern void *D_800411F0;
    extern void *D_800411F4;
    if (D_800411F0 != NULL) {
        func_80027200();
        D_800411F0 = NULL;
        D_800411F4 = NULL;
    }
}
#else
void func_80020DEC(s32 arg0) {
    void func_80027200(void);
    extern s32 D_800411F0;
    extern s32 D_800411F4;
    if (D_800411F0 != 0) {
        func_80027200();
        D_800411F0 = 0;
        D_800411F4 = 0;
    }
}
#endif

