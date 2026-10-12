#include "common.h"

OSThread *chfactorytoxicpools_entrypoint_0(void)
{
    extern u8 D_80800940_chfactorytoxicpools[];

    return (OSThread *) D_80800940_chfactorytoxicpools;
}

OSThread *chfactorytoxicpools_entrypoint_1(void)
{
    extern u8 D_80800988_chfactorytoxicpools[];

    return (OSThread *) D_80800988_chfactorytoxicpools;
}

OSThread *chfactorytoxicpools_entrypoint_2(void)
{
    extern u8 D_808009D0_chfactorytoxicpools[];

    return (OSThread *) D_808009D0_chfactorytoxicpools;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_80800024_chfactorytoxicpools.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_808000D0_chfactorytoxicpools.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_80800190_chfactorytoxicpools.s")

void func_80800270_chfactorytoxicpools(Actor *arg0) {
    s32 _idwibble_entrypoint_5(s32, s16);
    s32 _idworld_entrypoint_4(s32, s32);
    s32 func_800BEA88(s32);
    void* func_80100094(Actor*, u32);
    s16 *sp1C;

    sp1C = func_80100094(arg0, 1U);
    _idwibble_entrypoint_5(_idworld_entrypoint_4(func_800BEA88(1), 1), *sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_808002B8_chfactorytoxicpools.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_80800338_chfactorytoxicpools.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_808003DC_chfactorytoxicpools.s")

void func_808004A4_chfactorytoxicpools(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 func_800BEA88(s32);
    extern s32 _chfactorytoxicpools_entrypoint_3;
    s32 temp_v0;
    s32 sp1C;

    temp_v0 = func_800BEA88(1);
    if (temp_v0 != 0) {
        sp1C = temp_v0;
        _idworldmake_entrypoint_1(temp_v0, 0x7D, 2, 1);
        _glid_entrypoint_0(sp1C, 2, &_chfactorytoxicpools_entrypoint_3, *arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/chfactorytoxicpools_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_8080057C_chfactorytoxicpools.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_80800670_chfactorytoxicpools.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/toxicpools/func_80800898_chfactorytoxicpools.s")
