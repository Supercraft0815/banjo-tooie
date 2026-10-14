#include "common.h"

s32 ncbadolly_entrypoint_0() 
{
    return 0x2C;
}

void ncbadolly_entrypoint_1(u8 *arg0) {
    s32 func_801124D0(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x21))) = 1;
    func_801124D0((s32) arg0, 1);
}

void ncbadolly_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/dolly/ncbadolly_entrypoint_3.s")

/* extern */

void ncbadolly_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_18(u8 *);
    s32 _cadbfunc_entrypoint_20(u8 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    s32 _cadbfunc_entrypoint_4(u8 *);
    s32 _cadbfunc_entrypoint_6(f32 *, f32 *);
    s32 _cadbfunc_entrypoint_8(f32 *, f32 *);
    s32 func_800A5800(s32);
    void func_80111B8C(s32 *, f32, f32);
    void func_80112570(u8 *, s32, f32);
    f32 sp2C;
    f32 sp28;
    s32 sp24;

    func_800A5800(arg1);
    _cadbfunc_entrypoint_29(1, &sp24);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x20))) = (s8) sp24;
    _cadbfunc_entrypoint_4((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0xC);
    _cadbfunc_entrypoint_0((*(u8 **)((s8 *)(arg0) + (0x1C))));
    _cadbfunc_entrypoint_6(&sp2C, &sp28);
    func_80111B8C((s32 *) arg0, sp2C, sp28);
    _cadbfunc_entrypoint_8(&sp2C, &sp28);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x24))) = sp2C;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x28))) = sp28;
    _cadbfunc_entrypoint_18((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0x1C);
    _cadbfunc_entrypoint_20((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0x18);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x1C)))) + (0x21))) = 0;
    func_80112570(arg0, (s32) ((*(u8 **)((s8 *)(arg0) + (0x1C))) + 0xC), 150.0f);
}
