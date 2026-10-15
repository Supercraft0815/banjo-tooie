#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029670.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002976C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_800298E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_80029A04.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A024.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A7E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A890.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A940.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002A9B8.s")

void func_8002AA30(void *arg0, s16 arg1, s32 arg2) {
    void func_80027AF0(void *, s16, s32);
    void *saved;
    saved = arg0;
    func_80027AF0(saved, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E411A0/func_8002AA74.s")
