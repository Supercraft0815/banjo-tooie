#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbDll/func_80800000_gldbDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbDll/func_808000E8_gldbDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbDll/gldbDll_entrypoint_0.s")

void gldbDll_entrypoint_1(void) {
    s32 _gleeprom_entrypoint_0(void);
    s32 _glreflight_entrypoint_0();
    void func_800DA544(GameFlag);
    s32 i;

    for (i = 0; i < 32; i += 8) {
        func_800DA544(((_gleeprom_entrypoint_0() & (0xFF << i)) >> i) + 0x9C4);
    }
    for (i = 0; i != 32; i += 8) {
        func_800DA544(((_glreflight_entrypoint_0() & (0xFF << i)) >> i) + 0x9C4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbDll/gldbDll_entrypoint_2.s")
