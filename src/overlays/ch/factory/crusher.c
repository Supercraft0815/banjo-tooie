#include "common.h"

OSThread *chfactorycrusher_entrypoint_0(void)
{
    extern u8 D_80800A50_chfactorycrusher[];

    return (OSThread *) D_80800A50_chfactorycrusher;
}

OSThread *chfactorycrusher_entrypoint_1(void)
{
    extern u8 D_80800A98_chfactorycrusher[];

    return (OSThread *) D_80800A98_chfactorycrusher;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800018_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800150_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800580_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_8080067C_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_808006CC_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800738_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800800_chfactorycrusher.s")

/* extern */

void func_80800898_chfactorycrusher(void *arg0) {
    s32 func_80106790(s32);
    func_80106790((*(s32 *)((s8 *)(arg0) + (0x3C))));
}

void func_808008B8_chfactorycrusher(s32 arg0, f32 arg1) {
    void func_800EFE50(f32*, void*, void*, f32);
    func_800EFE50(arg0 + 4, arg0 + 0x18, arg0 + 0x28, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_808008F0_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800984_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_808009BC_chfactorycrusher.s")
