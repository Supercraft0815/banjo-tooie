#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/glrtc_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/func_80800170_glrtc.s")

void func_808002C8_glrtc(u16 *arg0, u16 arg1) {
    u16 start;
    u16 end;
    u16 step;

    start = arg0[0] & arg1;
    end = arg0[3] & arg1;
    step = ((end - start) / 3) & arg1;
    arg0[1] = arg0[1] | (start + step);
    arg0[2] = arg0[2] | (end - step);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/func_8080031C_glrtc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/func_80800474_glrtc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/func_808005B0_glrtc.s")
