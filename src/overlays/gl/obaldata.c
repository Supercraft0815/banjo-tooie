#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obaldata/glglobaldata_entrypoint_0.s")

s32 glglobaldata_entrypoint_1(u8 *arg0) {
    return *arg0 == 8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obaldata/glglobaldata_entrypoint_2.s")

void func_80800124_glglobaldata(u8 *arg0, s32 *arg1) { arg0[*arg1] = 8; *arg1 += 1; }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/obaldata/glglobaldata_entrypoint_3.s")

void glglobaldata_entrypoint_4(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x80; i++) {
        arg0[i] = 0;
    }
}
