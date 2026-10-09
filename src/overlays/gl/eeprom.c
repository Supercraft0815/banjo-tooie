#include "common.h"

s32 gleeprom_entrypoint_0(void) {
    extern s32 D_8007DA60;
    return (*(s32 *)((s8 *)(&D_8007DA60) + (0xF0))) ^ 0xBD1F0416;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/eeprom/gleeprom_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/eeprom/gleeprom_entrypoint_2.s")
