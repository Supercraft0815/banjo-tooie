#include "common.h"

OSThread *chscorepoints_entrypoint_0(void)
{
    extern u8 D_808003C0_chscorepoints[];

    return (OSThread *) D_808003C0_chscorepoints;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_8080000C_chscorepoints.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_808000BC_chscorepoints.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_8080019C_chscorepoints.s")

/* extern */

void chscorepoints_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_800D3DA4(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    Actor *func_80108474(u32, f32 *, s32);
    f32 sp1C[3];
    Actor *sp18;

    func_800EFA4C(sp1C, (f32) arg2, (f32) arg3, (f32) arg4);
    sp18 = func_80108474(0x14E, sp1C, 0);
    sp18->actorData[4] = arg0;
    sp18->actorData[5] = arg5;
    *(s32 *)&sp18->unk54 = arg1;
    *(s32 *)&sp18->unk50 = func_800D3DA4(arg1) + 0xC29;
}

void chscorepoints_entrypoint_2(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    extern s32 _chscorepoints_entrypoint_1;
    _chbaddiesetup_entrypoint_6(&_chscorepoints_entrypoint_1, arg0, arg1, (s32) (*(f32 *)((s8 *)(arg2) + (0))), (s32) (*(f32 *)((s8 *)(arg2) + (4))), (s32) (*(f32 *)((s8 *)(arg2) + (8))), arg3);
}
