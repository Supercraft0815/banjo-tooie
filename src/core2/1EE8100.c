#include "common.h"

OSThread *func_8010E810(void)
{
    extern u8 D_80137080[];

    return (OSThread *) D_80137080;
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8100/func_8010EACC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8100/func_8010EBE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE8100/func_8010EECC.s")
