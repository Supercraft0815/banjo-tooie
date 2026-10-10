#include "common.h"

OSThread *choctopus_entrypoint_0(void)
{
    extern u8 D_808008F4_choctopus[];

    return (OSThread *) D_808008F4_choctopus;
}

void func_8080000C_choctopus(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor*);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.8f);
    arg0->actorData[6] = _subaddiesect_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800054_choctopus.s")

void func_80800210_choctopus()
{
    func_808007E4_choctopus();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800230_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800348_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800428_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800540_choctopus.s")

OSThread *choctopus_entrypoint_1(void)
{
    extern u8 D_80800998_choctopus[];

    return (OSThread *) D_80800998_choctopus;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_80800790_choctopus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/octopus/func_808007E4_choctopus.s")
