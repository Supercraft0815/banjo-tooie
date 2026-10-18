#include "common.h"

void *func_8010E810(void)
{
    extern u8 D_80137080[];

    return D_80137080;
}

void *func_8010E81C(f32 arg0) {
    struct entry { s32 data[9]; f32 value; };
    struct list { s32 data[5]; struct entry *start; struct entry *end; };
    extern u8 D_80137080[];
    extern s32 D_8013709C;
    s32 *dst;
    s32 *src;
    u32 cursor;
    s32 bytes;

    for (cursor = (u32)&D_8013709C; (struct entry *)cursor < ((struct list *)D_80137080)->start; cursor += sizeof(struct entry)) {
        if (arg0 < ((struct entry *)cursor)->value) {
            break;
        }
    }
    if ((struct entry *)cursor == ((struct list *)D_80137080)->start) {
        if (((struct list *)D_80137080)->start < ((struct list *)D_80137080)->end) {
            ((struct list *)D_80137080)->start++;
            return (void *)cursor;
        }
        return NULL;
    }
    if (((struct list *)D_80137080)->start == ((struct list *)D_80137080)->end) {
        ((struct list *)D_80137080)->start--;
    }
    dst = (s32 *)(((struct list *)D_80137080)->start + 1);
    bytes = (((struct list *)D_80137080)->start - (struct entry *)cursor) * sizeof(struct entry);
    dst--;
    src = (s32 *)((struct list *)D_80137080)->start - 1;
    while (bytes > 0) {
        *dst-- = *src--;
        bytes -= 4;
    }
    ((struct list *)D_80137080)->start++;
    return (void *)cursor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8100/func_8010E924.s")

void func_8010EACC(void *arg0, s32 arg1, f32 arg2) {
    struct entry { s32 data[9]; f32 value; };
    struct list { u8 data[0x11]; s8 count; u8 pad[2]; struct entry *start; struct entry *end; };
    extern u8 D_80137080[];
    void func_80019224(f32 *, f32 *);
    void func_800B237C(void *, f32[3], f32 *);
    s32 func_800C8760(s32, s32);
    s32 func_800C878C(s32, s32, s32);
    s32 func_800DF8B4(s32 *);
    f32 func_800DF8C4(f32 *);
    void func_800DF900(u8 *);
    void func_8010E924(s32, f32 *, f32, f32);
    void mlMtxPop(void);
    s32 current;
    f32 center[3];
    f32 norm;
    s32 amount;
    s32 list;
    s32 pad;

    if (arg1 < 0) {
        amount = -arg1;
    } else {
        amount = arg1;
    }
    ((struct list *)D_80137080)->end = amount + ((struct list *)D_80137080)->start;
    list = func_800DF8B4(arg0);
    func_800B237C((void *)list, center, &norm);
    arg2 = func_800DF8C4(arg0);
    func_80019224(center, center);
    norm *= arg2;
    func_800DF900(arg0);
    current = func_800C8760(0, 1);
    if (current != 0) {
        do {
            func_8010E924(current, center, norm, arg2);
            current = func_800C878C(current, 0, 1);
        } while (current != 0);
    }
    ((struct list *)D_80137080)->count = (s32)((u8 *)((struct list *)D_80137080)->start - D_80137080 - 0x1C) / 40;
    mlMtxPop();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8100/func_8010EBE4.s")

void func_8010EECC(s32 *arg0, s32 arg1, s32 arg2, f32 arg3) {
    struct state { s32 *actor; s32 data[3]; s8 value; u8 pad[3]; s32 *start; };
    extern u8 D_80137080[];
    extern s32 D_80137084;
    extern s32 D_8013709C;
    void func_800C87B8(s32 *);
    s32 func_800DF8B4(s32 *);
    s32 func_800DF8BC(s32 *);
    s32 func_800DF8CC(s32 *);
    int func_800DF8D4(s32 *);
    void func_8010EBE4(s32, s32, s32);
    s32 pad;
    s32 sp28;
    s32 sp24;

    ((struct state *)D_80137080)->actor = arg0;
    ((struct state *)D_80137080)->value = func_800DF8D4(arg0);
    ((struct state *)D_80137080)->start = &D_8013709C;
    func_8010EACC(arg0, arg1, arg3);
    func_800C87B8(&D_80137084);
    sp24 = func_800DF8B4(arg0);
    sp28 = func_800DF8CC(arg0);
    func_8010EBE4(sp24, sp28, func_800DF8BC(arg0));
}
