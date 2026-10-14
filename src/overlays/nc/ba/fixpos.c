#include "common.h"

s32 ncbafixpos_entrypoint_0() 
{
    return 0x1C;
}

void ncbafixpos_entrypoint_1(u8 *arg0) {
    s32 func_801124D0(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x1A))) = 1;
    func_801124D0((s32) arg0, 1);
}

void ncbafixpos_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fixpos/func_8080003C_ncbafixpos.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fixpos/ncbafixpos_entrypoint_3.s")

/* extern */

void ncbafixpos_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    s32 _cadbfunc_entrypoint_4(u8 *);
    s32 _cadbfunc_entrypoint_6(s32 *, s32 *);
    s32 _cadbfunc_entrypoint_8(s32 *, s32 *);
    s32 func_800A5800(s32);
    s32 func_80111B8C(u8 *, s32, s32);
    s32 func_80112570(u8 *, u8 *, s32);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    func_800A5800(arg1);
    _cadbfunc_entrypoint_29(2, &sp24);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x18))) = (s8) sp24;
    _cadbfunc_entrypoint_29(1, &sp24);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x19))) = (s8) sp24;
    _cadbfunc_entrypoint_4((*(u8 **)((s8 *)(arg0) + (0x20))) + 0xC);
    _cadbfunc_entrypoint_0((*(u8 **)((s8 *)(arg0) + (0x20))));
    _cadbfunc_entrypoint_6(&sp2C, &sp28);
    func_80111B8C(arg0, sp2C, sp28);
    _cadbfunc_entrypoint_8(&sp2C, &sp28);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x1A))) = 0;
    func_80112570(arg0, (*(u8 **)((s8 *)(arg0) + (0x20))) + 0xC, 0x42C80000);
}
