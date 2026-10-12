#include "common.h"

OSThread *chcheatopage_entrypoint_0(void)
{
    extern u8 D_80800330_chcheatopage[];

    return (OSThread *) D_80800330_chcheatopage;
}

/* extern */
void func_8080000C_chcheatopage(Actor *arg0) { s32 func_80103110(void *, s32); func_80103110(arg0, 0); func_8010A5B0(arg0, func_800DA298(0x666) == 0); if (arg0->unk64_20) { func_800FC660(0x77); arg0->unk64_20 = 0; } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatopage/func_80800070_chcheatopage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatopage/func_80800124_chcheatopage.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatopage/func_80800194_chcheatopage.s")

/* extern */

void func_808002A0_chcheatopage(void *arg0) {
    s32 func_80101870();
    s32 func_80103110(void *, s32);
    func_80101870();
    if ((((struct { unsigned int : 19; unsigned int active : 1; unsigned int : 12; } *)((s8 *)arg0 + 0x7C))->active) && (((u32) (*(u16 *)((s8 *)(arg0) + (0x72))) >> 0xA) == 1)) {
        func_80103110(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatopage/func_808002F0_chcheatopage.s")
