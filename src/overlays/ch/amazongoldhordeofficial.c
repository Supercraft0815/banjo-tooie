#include "common.h"

OSThread *chamazongoldhordeofficial_entrypoint_0(void)
{
    extern u8 D_80801240_chamazongoldhordeofficial[];

    return (OSThread *) D_80801240_chamazongoldhordeofficial;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_8080000C_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800150_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800630_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800690_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_808006F8_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800A84_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800C18_chamazongoldhordeofficial.s")

s32 func_80800C60_chamazongoldhordeofficial(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800DA298(s32);
    s32 func_800F54E4();
    s32 func_800F56AC(s32);
    extern s32 D_80801324_chamazongoldhordeofficial;
    extern s32 D_80801340_chamazongoldhordeofficial;
    if (func_800F56AC(func_800F54E4()) == 0x12) {
        return 0;
    }
    if (func_800DA298(0x5A) != 0) {
        return _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80801340_chamazongoldhordeofficial);
    }
    return _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_80801324_chamazongoldhordeofficial);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800CD8_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800DB4_chamazongoldhordeofficial.s")

/* extern */

void func_80800E18_chamazongoldhordeofficial(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_80102424(Actor*, s32);
    s32 func_80800DB4_chamazongoldhordeofficial(Actor *, u8);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_80800DB4_chamazongoldhordeofficial(arg0, (*(u8 *)((s8 *)(temp_v0) + (0x67))));
    func_80102424(arg0, 2);
    (*(s16 *)((s8 *)(sp1C) + (8))) = -0x3E7;
}

void func_80800E64_chamazongoldhordeofficial(Actor *arg0) {
    extern u32 D_808011D0_chamazongoldhordeofficial;
    extern u32 D_8080135C_chamazongoldhordeofficial;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_808011D0_chamazongoldhordeofficial, &D_8080135C_chamazongoldhordeofficial);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800E94_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80800F40_chamazongoldhordeofficial.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/amazongoldhordeofficial/func_80801060_chamazongoldhordeofficial.s")
