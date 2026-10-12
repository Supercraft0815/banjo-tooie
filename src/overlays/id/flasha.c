#include "common.h"

void idflasha_entrypoint_0(s16 arg0, u32 arg1, u8 *arg2, s32 arg3, s16 *arg4) {
    s32 value = *arg4;
    u32 end = (arg3 << 4) + arg1;

    if (arg1 < end) {
        do {
            arg1 += 0x10;
            arg2 += 0x10;
            arg2[-1] = value;
        } while (arg1 < end);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flasha/func_80800038_idflasha.s")

s32 idflasha_entrypoint_1(s16 *arg0) {
    return arg0[0];
}

void idflasha_entrypoint_2(s32 arg0) 
{
}
/* extern */

void idflasha_entrypoint_3(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800038_idflasha(s32, s32);
    (*(s16 *)((s8 *)(arg0) + (0))) = 0;
    (*(s32 *)((s8 *)(arg0) + (4))) = 0;
    (*(s32 *)((s8 *)(arg0) + (8))) = 2;
    (*(s32 *)((s8 *)(arg0) + (0xC))) = 0;
    func_80800038_idflasha((s32)arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/flasha/idflasha_entrypoint_4.s")
