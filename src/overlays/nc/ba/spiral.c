#include "nc/ba/spiral.h"

s32 ncbaspiral_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spiral/ncbaspiral_entrypoint_1.s")

void ncbaspiral_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spiral/ncbaspiral_entrypoint_3.s")

/* extern */

void ncbaspiral_entrypoint_4(void *arg0) {
    s32 func_800EE7F8(s32 *);
    func_800EE7F8(*(s32 **)((s8 *)arg0 + 0x48) + 1);
    *(*(s32 **)((s8 *)(arg0) + (0x48))) = -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/spiral/ncbaspiral_entrypoint_5.s")
