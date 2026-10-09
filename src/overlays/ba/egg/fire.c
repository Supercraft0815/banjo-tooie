#include "common.h"

s32 baeggfire_entrypoint_0() 
{
    return 0x14;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/func_80800008_baeggfire.s")

void func_80800040_baeggfire(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x12))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x11))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/baeggfire_entrypoint_1.s")

/* extern */

void baeggfire_entrypoint_2(void) {
    void *func_800F53D0();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(func_800F53D0()) + (0x6C)))) + (0x13))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/func_808000B8_baeggfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/func_80800180_baeggfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/func_80800250_baeggfire.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/baeggfire_entrypoint_3.s")

void baeggfire_entrypoint_4(s32 arg0)
{
    func_8009E0AC(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/baeggfire_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/egg/fire/baeggfire_entrypoint_6.s")

void baeggfire_entrypoint_7(void *arg0) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0xC))) = 1;
}

s32 baeggfire_entrypoint_8(void *arg0) {
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (8))) >= 2;
}
