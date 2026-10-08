#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/func_80800000_glintrosyncDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/func_808000BC_glintrosyncDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/glintrosyncDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/glintrosyncDll_entrypoint_1.s")

void glintrosyncDll_entrypoint_2(f32 arg0) {
    extern f32 D_80127194;
    *(f32 *)((u8 *)&D_80127194 + 1092) = arg0;
}

f32 glintrosyncDll_entrypoint_3(void) {
    extern f32 D_80127194;
    return *(f32 *)((u8 *)&D_80127194 + 1092);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/glintrosyncDll_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/glintrosyncDll_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/glintrosyncDll_entrypoint_6.s")
