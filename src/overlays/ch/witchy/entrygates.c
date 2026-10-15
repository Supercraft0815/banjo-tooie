#include "ch/witchyentrygates.h"

extern u32 D_808001F0_chwitchyentrygates;

void func_80800000_chwitchyentrygates(Actor* arg0)
{
    f32 var_f0;
    s32 var_a3;
    if (_sujiggy_entrypoint_20(2U) != 0)
    {
        func_800DA544(FLAG_394_PROGRESS_OPENED_WORLD_WW);
    }
    if ((func_800D3E40(0xB) != 0) && (_glcutDll_entrypoint_19(0x7CU) == 0))
    {
        var_a3 = -1;
        func_80101FDC(arg0, 4);
    }
    else
    {
        var_a3 = 0x394;
    }
    if (arg0->unk74_7 == 0x33)
    {
        var_f0 = 75.0f;
    }
    else
    {
        var_f0 = -75.0f;
    }
    _chdoormake_entrypoint_0(arg0, var_f0, 0, var_a3);
    _chdoormake_entrypoint_5(arg0, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/witchy/entrygates/func_808000B8_chwitchyentrygates.s")

/* extern */

void func_80800168_chwitchyentrygates(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 var_v0;

    if (arg1 == 0x95) {
        var_v0 = (arg0->unk74_7 == 0x33) ? 0x96C : 0x96D;
        func_80103140(arg0, var_v0 & 0xFFFF, arg0->unk0->unk16);
    }
    _chdoor_entrypoint_1((s32)arg0, arg1, arg2);
}

void* chwitchyentrygates_entrypoint_0(void) {
    return &D_808001F0_chwitchyentrygates;
}
