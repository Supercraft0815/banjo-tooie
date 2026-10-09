#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_80800000_sccustom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_80800264_sccustom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_808004C8_sccustom.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_8080050C_sccustom.s")

/* extern */

void sccustom_entrypoint_0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom(s32, s32, s32, s32, s32);
    s32 func_808004C8_sccustom(s32);
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_808004C8_sccustom(arg1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_808006C4_sccustom.s")

/* extern */

void sccustom_entrypoint_3(s32 arg0) {
    s32 func_808004C8_sccustom();
    s32 func_808006C4_sccustom(s32, s32);
    func_808006C4_sccustom(arg0, func_808004C8_sccustom());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/sccustom_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/func_8080084C_sccustom.s")

/* extern */

void sccustom_entrypoint_6(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_80800000_sccustom(s32, s32, s32, s32, s32);
    s32 func_8080084C_sccustom(s32);
    func_80800000_sccustom(arg0, arg1, arg2, arg3, func_8080084C_sccustom(arg1));
}

/* extern */

void sccustom_entrypoint_7(s32 arg0) {
    s32 func_8080084C_sccustom();
    s32 func_808006C4_sccustom(s32, s32);
    func_808006C4_sccustom(arg0, func_8080084C_sccustom());
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/custom/R_80800910_sccustom.s")
