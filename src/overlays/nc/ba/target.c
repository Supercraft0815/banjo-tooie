#include "nc/ba/target.h"

s32 ncbatarget_entrypoint_0() 
{
    return 0x10;
}

/* extern */

void func_80800008_ncbatarget(PlayerState *arg0, f32 *arg1) {
    s32 func_800EF174(f32 *, s32 *, s32);
    s32 func_800EFB24(s32 *, void *, f32 *);
    s32 sp1C[3];

    func_80112524(arg0, arg1);
    func_800EFB24(sp1C, (*(void **)((s8 *)(arg0) + (0x58))), arg1);
    func_800EF174(arg1, sp1C, (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x58)))) + (0xC))));
}

void func_80800058_ncbatarget(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/target/ncbatarget_entrypoint_1.s")

void ncbatarget_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/target/ncbatarget_entrypoint_3.s")

void ncbatarget_entrypoint_4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 88) + 12) = arg1;
}

/* extern */

void ncbatarget_entrypoint_5(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0x58))));
}
