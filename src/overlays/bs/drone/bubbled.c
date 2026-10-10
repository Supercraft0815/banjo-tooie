#include "common.h"

s32 func_80800000_bsdronebubbled(u8 *arg0) {
    s32 func_8010114C(s32, s32, s32);
    s32 temp_v0;

    temp_v0 = func_8010114C((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x48))), 0x2C, (*(s32 *)((s8 *)(arg0) + (0x184))));
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x54)))) + (0x48))) = 0;
    return temp_v0;
}

/* extern */

void bsdronebubbled_entrypoint_0(void *arg0) {
    s32 func_80800000_bsdronebubbled();
    if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x54)))) + (0x48))) != 0) {
        func_80800000_bsdronebubbled();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bubbled/bsdronebubbled_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bubbled/bsdronebubbled_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bubbled/bsdronebubbled_entrypoint_3.s")

void bsdronebubbled_entrypoint_4(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bubbled/bsdronebubbled_entrypoint_5.s")

void bsdronebubbled_entrypoint_6()
{
    func_80099B94();
}

void bsdronebubbled_entrypoint_7(void *arg0)
{
}
