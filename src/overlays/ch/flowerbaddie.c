#include "common.h"

OSThread *chflowerbaddie_entrypoint_0(void)
{
    extern u8 D_80800C14_chflowerbaddie[];

    return (OSThread *) D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 600.0f;
    arg0->unk64_20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_8080005C_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800380_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800610_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808006A0_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808007F0_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808008D4_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800980_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808009F0_chflowerbaddie.s")
