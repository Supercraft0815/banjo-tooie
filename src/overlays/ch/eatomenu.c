#include "common.h"

OSThread *chcheatomenu_entrypoint_0(void)
{
    extern u8 D_8080089C_chcheatomenu[];

    return (OSThread *) D_8080089C_chcheatomenu;
}

void func_8080000C_chcheatomenu(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800014_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_808000D4_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800150_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800194_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800364_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800428_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_8080052C_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_8080058C_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800668_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800720_chcheatomenu.s")

/* extern */

void func_808007B8_chcheatomenu(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800800_chcheatomenu.s")
