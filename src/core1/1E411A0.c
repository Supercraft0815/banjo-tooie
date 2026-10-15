#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002976C.s")

/* extern */

u8 func_800298E4(u8 *arg0, s32 arg1, s32 arg2) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    ALLink *sp2C;
    ALLink *sp28;
    ALLink *volatile sp24;
    s32 sp20;
    u8 sp1F;

    sp20 = 0;
    sp1F = 1;
    sp2C = (*(ALLink **)((s8 *)(arg0) + (0x50)));
    while (sp2C != NULL) {
        sp28 = sp2C->next;
        sp24 = sp2C;
        sp20 += (*(s32 *)((s8 *)(sp24) + (8)));
        if (((*(s16 *)((s8 *)(sp24) + (0xC))) == 5) &&
            ((*(s32 *)((s8 *)(sp24) + (0x10))) == arg1)) {
            if (sp20 > arg2) {
                if (sp28 != NULL) {
                    (*(s32 *)((s8 *)(sp28) + (8))) += (*(s32 *)((s8 *)(sp24) + (8)));
                }
                func_80020E74(sp2C);
                func_80020E40(sp2C, (ALLink *)(arg0 + 0x48));
            } else {
                sp1F = 0;
            }
            break;
        }
        sp2C = sp28;
    }
    return sp1F;
}

/* extern */

s32 *func_80029A04(void *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    void func_800E9070(s32, s32);
    s32 *sp1C;

    sp1C = (*(s32 **)((s8 *)(arg0) + (0x6C)));
    if ((s32) (*(u8 *)((s8 *)(arg0) + (0x89))) > (s32) (*(u8 *)((s8 *)(arg0) + (0x88)))) {
        return NULL;
    }
    if (sp1C != NULL) {
        (*(s32 **)((s8 *)(arg0) + (0x6C))) = (s32 *) (*(s32 **)((s8 *)(sp1C) + (0)));
        (*(s32 **)((s8 *)(sp1C) + (0))) = NULL;
        if ((*(s32 **)((s8 *)(arg0) + (0x64))) == NULL) {
            (*(s32 **)((s8 *)(arg0) + (0x64))) = sp1C;
        } else {
            *(*(s32 **)((s8 *)(arg0) + (0x68))) = sp1C;
        }
        (*(s32 **)((s8 *)(arg0) + (0x68))) = sp1C;
        (*(u8 *)((s8 *)(sp1C) + (0x35))) = arg3;
        (*(u8 *)((s8 *)(sp1C) + (0x36))) = arg1;
        (*(u8 *)((s8 *)(sp1C) + (0x37))) = arg2;
        (*(s32 **)((s8 *)(sp1C) + (0x14))) = sp1C;
        (*(s32 *)((s8 *)(sp1C) + (0x28))) = 0;
        (*(u8 *)((s8 *)(arg0) + (0x89))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x89))) + 1);
        func_800E9070(arg4, 1);
    }
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029B18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029BA0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029D54.s")

u8 func_80029E64(void *arg0, void *arg1) {
    s32 sp14;
    s32 sp10;

    sp14 = (*(u8 (**)[0x38])((u8 *)arg1 + 0x60))[*(u8 *)((u8 *)arg0 + 0x35)][6] & 0x80;
    sp10 = (s32)(*(f32 *)((u8 *)arg1 + 0x80) * (f32)((s32)(*(f32 *)((u8 *)arg1 + 0x7C) * 127.0f) + ((*(u8 (**)[0x38])((u8 *)arg1 + 0x60))[*(u8 *)((u8 *)arg0 + 0x35)][6] & 0x7F)));
    return ((sp10 >= 0x80 ? 0x7F : sp10) < 0 ? 0 : (sp10 >= 0x80 ? 0x7F : sp10)) | sp14;
}

s32 func_80029F5C(void *arg0, s32 arg1) {
    s32 sp4;

    sp4 = (*(s32 *)((s8 *)(arg0) + (0x28))) - arg1;
    if (sp4 >= 0) {
        return sp4;
    } else {
        return 0x3E8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029FA0.s")

/* extern */

void func_8002A024(void *arg0, s32 arg1) {
    void func_8002A150(void *, s32);
    s32 func_8002A318(void *, s32, s32);
    s16 func_800E9054(s32);
    s32 sp1C;
    s32 sp18;

    sp18 = 0;
    if (func_800E9054(0) == 0) {
        do {
        } while (func_800E9054(++sp18) == 0);
    }
    for (sp1C = 0; sp1C < (s32) (*(u8 *)((s8 *)(arg0) + (0x36))); sp1C++) {
        func_8002A150(arg0, sp1C);
        func_8002A318(arg0, sp18, sp1C);
    }
}

/* extern */

void func_8002A0CC(void *arg0) {
    void func_8002A150(void *, s32);
    s32 sp1C;

    for (sp1C = 0; sp1C < (s32) (*(u8 *)((s8 *)(arg0) + (0x36))); sp1C++) {
        (*(s8 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x60))) + (sp1C * 0x38))) + (0x33))) = 0;
        func_8002A150(arg0, sp1C);
    }
}

void func_8002A150(register void *arg0, register s32 arg1) {
    typedef struct {
        s16 unk0;
        u8 unk2, unk3, unk4, unk5, unk6, unk7, unk8, unk9, unkA, unkB;
        u8 padC[4];
        u8 unk10, unk11, unk12, unk13;
        f32 unk14;
        u8 pad18[26];
        u8 unk32;
        u8 pad33[5];
    } Channel;
    typedef struct { u8 pad[0x60]; Channel *channels; } AudioState;
    ((AudioState *)arg0)->channels[arg1].unk2 = 0;
    ((AudioState *)arg0)->channels[arg1].unk6 = 0;
    ((AudioState *)arg0)->channels[arg1].unk3 = 0x40;
    ((AudioState *)arg0)->channels[arg1].unk5 = 0x7F;
    ((AudioState *)arg0)->channels[arg1].unk4 = 5;
    ((AudioState *)arg0)->channels[arg1].unk8 = 0;
    ((AudioState *)arg0)->channels[arg1].unk0 = 200;
    ((AudioState *)arg0)->channels[arg1].unk14 = 1.0f;
    ((AudioState *)arg0)->channels[arg1].unk10 = 0;
    ((AudioState *)arg0)->channels[arg1].unk9 = 0xFF;
    ((AudioState *)arg0)->channels[arg1].unkA = 0xFF;
    ((AudioState *)arg0)->channels[arg1].unkB = 0;
    ((AudioState *)arg0)->channels[arg1].unk7 = 0;
    ((AudioState *)arg0)->channels[arg1].unk13 = 0;
    ((AudioState *)arg0)->channels[arg1].unk12 = 0;
    ((AudioState *)arg0)->channels[arg1].unk11 = 0;
    ((AudioState *)arg0)->channels[arg1].unk32 = 0;
}


#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A318.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A6A4.s")

typedef struct { ALPlayer *players; ALLink list; u8 padC[8]; ALLink *head; u8 pad18[8]; s32 curSamples; u8 pad24[8]; ALLink *free; u8 pad30[0x10]; s32 unk40; } PoolFreeList;
void func_8002A7E0(void *arg0, f32 arg1) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern PoolFreeList *D_800411F4;
    void *sp1C;

    if ((*(void **)((s8 *)(arg0) + (8))) != NULL) {
        sp1C = func_80021794();
        if (sp1C == NULL) {
            return;
        }
        (*(s32 *)((s8 *)(sp1C) + (4))) = (s32) ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (8)))) + (0x88))) + (*(s32 *)((s8 *)(D_800411F4) + (0x1C))));
        (*(s16 *)((s8 *)(sp1C) + (8))) = 0x13;
        (*(f32 *)((s8 *)(sp1C) + (0xC))) = arg1;
        (*(s32 *)((s8 *)(sp1C) + (0))) = 0;
        func_8002B684((*(void **)((s8 *)(arg0) + (8))), 3, sp1C);
    }
}

void func_8002A890(void *arg0, u8 arg1) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern PoolFreeList *D_800411F4;
    void *sp1C;

    if ((*(void **)((s8 *)(arg0) + (8))) != NULL) {
        sp1C = func_80021794();
        if (sp1C == NULL) {
            return;
        }
        (*(s32 *)((s8 *)(sp1C) + (4))) = (s32) ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (8)))) + (0x88))) + (*(s32 *)((s8 *)(D_800411F4) + (0x1C))));
        (*(s16 *)((s8 *)(sp1C) + (8))) = 0x12;
        (*(s32 *)((s8 *)(sp1C) + (0xC))) = (s32) arg1;
        (*(s32 *)((s8 *)(sp1C) + (0))) = 0;
        func_8002B684((*(void **)((s8 *)(arg0) + (8))), 3, sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A9B8.s")

void func_8002AA30(void *arg0, s16 arg1, s32 arg2) {
    void func_80027AF0(void *, s16, s32);
    void *saved;
    saved = arg0;
    func_80027AF0(saved, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002AA74.s")
