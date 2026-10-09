#include "ch/minegrilldoor.h"

extern u32 D_80800190_chminegrilldoor;

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800000_chminegrilldoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mine/grilldoor/func_80800068_chminegrilldoor.s")

/* extern */

void func_80800144_chminegrilldoor(void *arg0) {
    s32 _chdoor_entrypoint_0();
    if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) == 3) {
        _chdoor_entrypoint_0();
    }
}

void* chminegrilldoor_entrypoint_0(void) {
    return &D_80800190_chminegrilldoor;
}

