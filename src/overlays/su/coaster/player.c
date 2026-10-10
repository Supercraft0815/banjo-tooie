#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/player/sucoasterplayer_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/player/sucoasterplayer_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/player/sucoasterplayer_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/player/sucoasterplayer_entrypoint_3.s")

/* extern */

s32 func_8080076C_sucoasterplayer(void *arg0, void *arg1) {
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    void *_sucoasterdata_entrypoint_1(u32);
    s32 func_80016B30(u32, s32);
    if (((*(u16 *)((s8 *)(_sucoasterdata_entrypoint_1((u32) (*(u32 *)((s8 *)(arg1) + (0x18))) >> 0x1C)) + (0x4A))) != 0) && (func_80016B30((u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) * 8) >> 0x1E, 1) == 1)) {
        return _sucoaster_entrypoint_9(arg0, 9, 6);
    }
    return 0;
}
