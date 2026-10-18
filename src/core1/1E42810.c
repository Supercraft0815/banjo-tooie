#include "common.h"

/* extern */

void func_8002ACE0(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    void func_80026500(void *, void *, s32, s32);
    struct { s16 type; s32 value; u8 b0; u8 b1; u8 b2; u8 b3; s32 tail; } event;
    s32 delay;
    event.type = 2;
    event.value = 0;
    event.b0 = arg2;
    event.b1 = arg3;
    event.b2 = arg4;
    event.b3 = arg5;
    event.tail = 0;
    delay = arg1;
    func_80026500((void *)(arg0 + 0x48), (void *)&event, delay, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002AD60.s")

s32 func_8002B684(void *arg0, s32 arg1, void *arg2) {
    void func_8002D328(void *, s32, void *);
    void *sp24;

    sp24 = arg0;
    switch (arg1) {
        case 3:
            if (*(void **)((s8 *)sp24 + 0x80) != NULL) {
                **(void ***)((s8 *)sp24 + 0x80) = arg2;
            } else {
                *(void **)((s8 *)sp24 + 0x7C) = arg2;
            }
            *(void **)((s8 *)sp24 + 0x80) = arg2;
            break;
        case 4:
            *(s32 *)((s8 *)sp24 + 0x78) = 1;
            *(s32 *)((s8 *)sp24 + 0x84) = 0;
            *(s16 *)((s8 *)sp24 + 0x5A) = 1;
            *(s32 *)((s8 *)sp24 + 0x74) = 0;
            *(f32 *)((s8 *)sp24 + 0x4C) = 0.0f;
            *(s32 *)((s8 *)sp24 + 0x50) = 1;
            *(s32 *)((s8 *)sp24 + 0x48) = 0;
            func_8002D328(sp24, 4, arg2);
            break;
        case 9:
            *(s32 *)((s8 *)sp24 + 0x84) = 1;
            break;
        default:
            func_8002D328(sp24, arg1, arg2);
            break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002B7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BD40.s")
