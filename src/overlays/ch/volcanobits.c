#include "common.h"

OSThread *chvolcanobits_entrypoint_0(void)
{
    extern u8 D_80801154_chvolcanobits[];

    return (OSThread *) D_80801154_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_1(void)
{
    extern u8 D_8080119C_chvolcanobits[];

    return (OSThread *) D_8080119C_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_2(void)
{
    extern u8 D_808011E4_chvolcanobits[];

    return (OSThread *) D_808011E4_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_3(void)
{
    extern u8 D_8080122C_chvolcanobits[];

    return (OSThread *) D_8080122C_chvolcanobits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800030_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800170_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_8080027C_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_8080061C_chvolcanobits.s")

void func_8080065C_chvolcanobits(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800664_chvolcanobits.s")

void func_8080086C_chvolcanobits(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_808008A4_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800914_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_808009A8_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800A04_chvolcanobits.s")

void func_80800AEC_chvolcanobits(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    func_800EE7F8(func_80100094(arg0, 0U), arg0->position);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800B20_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800C5C_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800D6C_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/chvolcanobits_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800EF0_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80801040_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_8080108C_chvolcanobits.s")
