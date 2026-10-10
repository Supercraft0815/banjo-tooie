#include "nc/ba/dive.h"

s32 ncbadive_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void ncbadive_entrypoint_1(void *arg0) {
    s32 func_800EFD24(void *);
    s32 func_801120CC(void *, s32, s32, s32);
    func_800EFD24((*(void **)((s8 *)(arg0) + (0x18))));
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x18)))) + (0xC))) = 0.0f;
    func_801120CC(arg0, 0x45834000, 0x46034000, 0xC6034000);
}

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
