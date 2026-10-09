#include "nc/ba/dive.h"

s32 ncbadive_entrypoint_0() 
{
    return 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/dive/ncbadive_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/dive/ncbadive_entrypoint_2.s")

void func_80800080_ncbadive(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/dive/ncbadive_entrypoint_3.s")

/* extern */

void ncbadive_entrypoint_4(void *arg0) {
    s32 func_800EF410(s32);
    func_800EF410((*(s32 *)((s8 *)(arg0) + (0x18))));
}
