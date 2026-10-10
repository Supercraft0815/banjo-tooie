#include "common.h"

void bamovehover_entrypoint_0(s32 arg0) 
{
}
/* extern */

void bamovehover_entrypoint_1(void *arg0) {
    s32 func_800EFA4C(s32, s32, s32, s32);
    s32 func_800EFD24(s32);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xAC);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xB8);
    func_800EFA4C((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10, 0x41855556, 0x42055556, 0x42480000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/hover/bamovehover_entrypoint_2.s")

/* extern */

void bamovehover_entrypoint_3(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 172);
}

void bamovehover_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 func_800EE7F8(s32);
    s32 func_800EFD24(s32);
    if (arg1 == 0) {
        func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xB8);
        return;
    }
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xB8);
}
