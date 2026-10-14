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

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002B684.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002B7C8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BAAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BCBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E42810/func_8002BD40.s")
