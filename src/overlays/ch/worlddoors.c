#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800000_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800068_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800214_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800388_chworlddoors.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_808006A8_chworlddoors.s")

void func_80800750_chworlddoors(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_2(Actor*);
    s32 func_800E1720(s32);
    u32 temp_v0;

    temp_v0 = arg0->actorData[3];
    if (temp_v0 != 0) {
        func_800E1720(temp_v0 - 1);
    }
    if (arg0->unk5F != 0) {
        _subaddieaudioloop_entrypoint_2(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/worlddoors/func_80800798_chworlddoors.s")

OSThread *chworlddoors_entrypoint_0(void)
{
    extern u8 D_80800A04_chworlddoors[];

    return (OSThread *) D_80800A04_chworlddoors;
}
