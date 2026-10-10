#include "common.h"

s32 ncbaswim_entrypoint_0() 
{
    return 0x4;
}

void ncbaswim_entrypoint_1(s32 arg0) 
{
}
void ncbaswim_entrypoint_2(s32 arg0) {
    s32 func_801124D0(s32, s32);
    void func_80115858(void *arg0, s32 arg1);
    void func_80115870(void *arg0, f32 arg1);
    func_801124D0(arg0, 1);
    func_80115858((u8 *) arg0, 2);
    func_80115870((u8 *) arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/swim/ncbaswim_entrypoint_3.s")
