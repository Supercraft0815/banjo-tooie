#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_80800000_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808000B8_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808001E0_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_80800350_chtorpedo.s")

/* extern */

void func_80800394_chtorpedo(s32 *arg0) {
    void *func_80100094(s32 *, s32);
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(s32 (**)(s32, s32, s32))((s8 *)(temp_v0) + (0x2C))) != NULL) {
        (*(s32 (**)(s32, s32, s32))((s8 *)(temp_v0) + (0x2C)))(*arg0, 5, (*(s32 *)((s8 *)(temp_v0) + (0x30))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808003DC_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/chtorpedo_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_80800720_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/chtorpedo_entrypoint_1.s")
