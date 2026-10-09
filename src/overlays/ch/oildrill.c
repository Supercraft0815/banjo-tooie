#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800000_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800104_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_808007DC_choildrill.s")

void choildrill_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808013DC_choildrill;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_808013DC_choildrill);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_808008AC_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_8080097C_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_808009F8_choildrill.s")

/* extern */

void func_80800B90_choildrill(void **arg0) {
    s32 func_80103140(void **, s32, u16);
    s32 func_8010A590(void **);
    s32 func_8010A624();
    func_8010A624();
    func_8010A590(arg0);
    func_80103140(arg0, 0x610, (*(u16 *)((s8 *)(*arg0) + (0x16))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800BCC_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800CF0_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80800F08_choildrill.s")

OSThread *choildrill_entrypoint_1(void)
{
    extern u8 D_808014A8_choildrill[];

    return (OSThread *) D_808014A8_choildrill;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_808010C0_choildrill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/oildrill/func_80801110_choildrill.s")

OSThread *choildrill_entrypoint_2(void)
{
    extern u8 D_808014F0_choildrill[];

    return (OSThread *) D_808014F0_choildrill;
}
