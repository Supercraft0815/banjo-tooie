#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800000_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800088_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808000F4_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808002B0_chclinker.s")

void func_80800304_chclinker(Actor *arg0, u32 arg1) {
    void _subaddieDll_entrypoint_4(Actor*, u32);
    void* func_80100094(Actor*, u32);
    void func_80101FDC(Actor*, u32);
    void func_8010A570(Actor*);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (arg1 == 2) {
        func_8010A570(arg0);
        _subaddieDll_entrypoint_4(arg0, 1U);
        (*(s32 *)((s8 *)(sp1C) + (8))) = 0;
    }
    func_80101FDC(arg0, arg1);
}

void func_80800368_chclinker(Actor *arg0, u8 *arg1) {
    void func_800DF744(s32, s32);
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))));
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808003A8_chclinker.s")

OSThread *chclinker_entrypoint_0(void)
{
    extern u8 D_808014D4_chclinker[];

    return (OSThread *) D_808014D4_chclinker;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_8080045C_chclinker.s")

/* extern */

void func_80800574_chclinker(s32 arg0) {
    s32 _susubgame_entrypoint_11(s32);
    _susubgame_entrypoint_11(0);
}

void func_80800598_chclinker(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (0x18))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808005BC_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808006A4_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808007BC_chclinker.s")

void func_808008C0_chclinker(s32 arg0)
{
    func_808008E0_chclinker(arg0,0x5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808008E0_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800BDC_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800C9C_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800D24_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_80800E1C_chclinker.s")

OSThread *chclinker_entrypoint_1(void)
{
    extern u8 D_80801550_chclinker[];

    return (OSThread *) D_80801550_chclinker;
}

void func_80800FFC_chclinker(s32 arg0) 
{
}
void func_80801004_chclinker(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_8080100C_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_8080112C_chclinker.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/clinker/func_808011A8_chclinker.s")

OSThread *chclinker_entrypoint_2(void)
{
    extern u8 D_80801598_chclinker[];

    return (OSThread *) D_80801598_chclinker;
}
