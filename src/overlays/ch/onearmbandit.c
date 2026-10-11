#include "common.h"

OSThread *chonearmbandit_entrypoint_0(void)
{
    extern u8 D_808012BC_chonearmbandit[];

    return (OSThread *) D_808012BC_chonearmbandit;
}

OSThread *chonearmbandit_entrypoint_1(void)
{
    extern u8 D_80801304_chonearmbandit[];

    return (OSThread *) D_80801304_chonearmbandit;
}

/* extern */

void func_80800018_chonearmbandit(void *arg0) {
    s32 func_80800040_chonearmbandit();
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 400.0f;
    func_80800040_chonearmbandit();
}

s32 func_80800040_chonearmbandit(Actor *arg0) {
    void _subaddierouteDll_entrypoint_1(Actor*);
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 1U), arg0->position);
    _subaddierouteDll_entrypoint_1(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_8080007C_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800520_chonearmbandit.s")

/* extern */

void func_8080063C_chonearmbandit(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800680_chonearmbandit.s")

/* extern */

void func_808006F8_chonearmbandit(u8 *arg0, s32 arg1) {
    struct Flags {
        unsigned int : 29;
        unsigned int active : 1;
        unsigned int : 2;
    };
    void func_80800680_chonearmbandit(u8 *, s32);
    if (!((struct Flags *)(arg0 + 0x78))->active &&
        (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 7)) {
        func_80800680_chonearmbandit(arg0, 7);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800740_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_808008E0_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800A14_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800AB8_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800D00_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800E78_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800EBC_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80800F80_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80801008_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80801040_chonearmbandit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_808010AC_chonearmbandit.s")

void func_80801114_chonearmbandit(u8 *arg0) {
    s32 func_800BBCB8(u8 *, s32, s32, s32, s32 *);
    extern s32 D_808013E8_chonearmbandit;
    func_800BBCB8(arg0 + 4, 0, (*(s32 *)((s8 *)(arg0) + (0x38))), 1, &D_808013E8_chonearmbandit);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/onearmbandit/func_80801154_chonearmbandit.s")
