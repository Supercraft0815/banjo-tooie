#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizexitdoor/func_80800000_chquizexitdoor.s")

void func_80800124_chquizexitdoor(s32 arg0) 
{
}
s32 func_8080012C_chquizexitdoor(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor*, u32);
    void func_80103110(Actor*, u32);
    if (arg1 == 7) {
        arg0->unk58 = 2.0f;
        func_80101FDC(arg0, 2U);
        func_80103110(arg0, 1U);
        return 1;
    }
    return 0;
}

OSThread *chquizexitdoor_entrypoint_0(void)
{
    extern u8 D_80800190_chquizexitdoor[];

    return (OSThread *) D_80800190_chquizexitdoor;
}
