#include "common.h"

OSThread *chdinoswitches_entrypoint_0(void)
{
    extern u8 D_80800C30_chdinoswitches[];

    return (OSThread *) D_80800C30_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_1(void)
{
    extern u8 D_80800C78_chdinoswitches[];

    return (OSThread *) D_80800C78_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_2(void)
{
    extern u8 D_80800CC0_chdinoswitches[];

    return (OSThread *) D_80800CC0_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_3(void)
{
    extern u8 D_80800D08_chdinoswitches[];

    return (OSThread *) D_80800D08_chdinoswitches;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800030_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800108_chdinoswitches.s")

void func_80800270_chdinoswitches(void *arg0) {
    void func_801032B0(void *, u16, u16);
    extern u8 D_80800B28_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_801032B0(arg0, *(u16 *)(D_80800B28_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808002B0_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808003E8_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/chdinoswitches_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800714_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808007A0_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800848_chdinoswitches.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_808008F0_chdinoswitches.s")

void func_80800A48_chdinoswitches(void *arg0) {
    void func_80103140(void *, u16, u16);
    extern u8 D_80800B2C_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_80103140(arg0, *(u16 *)(D_80800B2C_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/switches/func_80800A88_chdinoswitches.s")
