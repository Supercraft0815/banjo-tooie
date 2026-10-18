#include "common.h"

struct SfxState;

void func_800205D0(void *arg0) {
    void func_80020E74(ALLink *);
    void func_800E90A4(s32, s32);
    extern struct SfxState *D_800411D0;
    extern struct SfxState *D_800411D4;
    extern struct SfxState *D_800411D8;
    extern s16 D_800411E0;
    u32 mask;

    mask = osSetIntMask(1U);
    if (D_800411D0 == arg0) {
        D_800411D0 = *(void **)arg0;
    }
    if (D_800411D4 == arg0) {
        D_800411D4 = *(void **)((u8 *)arg0 + 4);
    }
    func_80020E74(arg0);
    if (D_800411D8 != NULL) {
        *(void **)arg0 = D_800411D8;
        *(void **)((u8 *)arg0 + 4) = NULL;
        *(void **)((u8 *)D_800411D8 + 4) = arg0;
        D_800411D8 = arg0;
    } else {
        *(void **)((u8 *)arg0 + 4) = NULL;
        *(void **)arg0 = *(void **)((u8 *)arg0 + 4);
        D_800411D8 = arg0;
    }
    if (*(u8 *)((u8 *)arg0 + 0x44) & 4) {
        D_800411E0 -= 1;
    }
    *(u8 *)((u8 *)arg0 + 0x45) = 0;
    if (*(void ***)((u8 *)arg0 + 0x30) != NULL) {
        if (**(void ***)((u8 *)arg0 + 0x30) == arg0) {
            **(void ***)((u8 *)arg0 + 0x30) = NULL;
        }
        *(void ***)((u8 *)arg0 + 0x30) = NULL;
    }
    func_800E90A4(*(s32 *)((u8 *)arg0 + 8), 0);
    osSetIntMask(mask);
}

void func_80020738(void *arg0, u8 arg1) {
    if (arg0 != NULL) {
        *(u8 *)((u8 *)arg0 + 0x40) = (s16)arg1;
    }
}

s32 func_80020760(void *arg0) {
    if (arg0 != NULL) {
        return *(u8 *)((u8 *)arg0 + 0x45);
    } else {
        return 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38100/func_80020790.s")

void func_80020A60(void *arg0) {
    struct { s16 type; void *state; s32 pad[2]; } evt;
    extern u8 *D_800411DC;
    void func_80026500(void *, void *, s32, s32);

    evt.type = 0x400;
    evt.state = arg0;
    if (arg0 != NULL) {
        *(u8 *)((u8 *)evt.state + 0x44) &= ~0x10;
        func_80026500(D_800411DC + 0x14, &evt, 0, 0);
    }
}

void func_80020AD0(u8 arg0) {
    extern struct SfxState *D_800411D0;
    extern u8 *D_800411DC;
    void func_80026500(void *, void *, s32, s32);
    u32 mask;
    struct { s16 type; void *state; s32 pad[2]; } evt;
    void *state;

    mask = osSetIntMask(1U);
    state = D_800411D0;
    if (state != NULL) {
        do {
            evt.type = 0x400;
            evt.state = state;
            if ((*(u8 *)((u8 *)state + 0x44) & arg0) == arg0) {
                *(u8 *)((u8 *)evt.state + 0x44) &= ~0x10;
                func_80026500(D_800411DC + 0x14, &evt, 0, 0);
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

void func_80020C08(volatile s32 arg0, volatile s16 arg1, volatile s32 arg2) {
    extern u8 *D_800411DC;
    void func_80026500(void *, void *, s32, s32);
    struct {
        s16 type;
        s32 value;
        s32 data;
        s32 extra;
    } event;

    event.type = arg1;
    event.value = arg0;
    event.data = arg2;
    if (arg0 != 0) {
        func_80026500(D_800411DC + 0x14, &event, 0, 0);
    }
}

s32 func_80020C74(u8 arg0) {
    extern u16 *D_8007EA24;

    return D_8007EA24[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E38100/func_80020CA0.s")

void func_80020D80(s32 arg0, s32 arg1) {
    s32 func_80020F70(s32);
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

void func_80020DEC(s32 arg0) {
    s32 func_80027200();
    extern s32 D_800411F0;
    extern s32 D_800411F4;
    if (D_800411F0 != 0) {
        func_80027200();
        D_800411F0 = 0;
        D_800411F4 = 0;
    }
}
