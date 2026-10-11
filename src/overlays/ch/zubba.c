#include "common.h"

OSThread *chzubba_entrypoint_0(void)
{
    extern u8 D_80800178_chzubba[];

    return (OSThread *) D_80800178_chzubba;
}

/* extern */

void func_8080000C_chzubba(s32 arg0) {
    s32 _sucoasterfly_entrypoint_1(s32, s32);
    s32 func_8010A3E8(s32, s32);
    _sucoasterfly_entrypoint_1(arg0, 0);
    func_8010A3E8(arg0, 0x3F266666);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/zubba/func_80800040_chzubba.s")
