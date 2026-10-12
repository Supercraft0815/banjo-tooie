#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_80800000_cheggclockwork.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_80800048_cheggclockwork.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_80800124_cheggclockwork.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_80800270_cheggclockwork.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_808002DC_cheggclockwork.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_808003B4_cheggclockwork.s")

OSThread *cheggclockwork_entrypoint_0(void)
{
    extern u8 D_808008C0_cheggclockwork[];

    return (OSThread *) D_808008C0_cheggclockwork;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/cheggclockwork_entrypoint_1.s")

/* extern */

void cheggclockwork_entrypoint_2(s32 arg0, s32 arg1, s32 arg2, volatile f32 arg3, s32 arg4, s32 arg5) {
    s32 _cheggsplode_entrypoint_2(s32 *, f32, s32, s32, s32);
    f32 sp24[3];
    f32 scale = arg3;
    sp24[0] = *(f32 *)&arg0;
    sp24[1] = *(f32 *)&arg1;
    sp24[2] = *(f32 *)&arg2;
    _cheggsplode_entrypoint_2((s32 *)sp24, scale, arg4, 5, arg5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/cheggclockwork_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_808006E8_cheggclockwork.s")

void func_808007B4_cheggclockwork(Actor *arg0) {
    s32 func_8001B754(s16);
    void* func_80100094(Actor*, u32);
    func_8001B754((*(s16 *)((s8 *)(func_80100094(arg0, 0U)) + (0x2C))));
}

/* extern */

void func_808007DC_cheggclockwork(Actor *arg0, f32 *arg1) {
    s32 func_8001B798(s16);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    s16 func_8001B668(s32, s32);
    u8 *sp1C;
    s32 sp18;
    s32 temp_v0;

    sp1C = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(sp1C) + (0x2C))) = func_8001B668(0, 0x24);
    temp_v0 = func_8001B798((*(s16 *)((s8 *)(sp1C) + (0x2C))));
    sp18 = temp_v0;
    func_800EE7F8((f32 *) temp_v0, arg1);
    func_800EE7F8(sp18 + 0xC, arg1);
    func_800EE7F8(sp18 + 0x18, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/egg/clockwork/func_80800850_cheggclockwork.s")
