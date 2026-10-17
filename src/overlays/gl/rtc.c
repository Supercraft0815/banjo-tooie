#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/glrtc_entrypoint_0.s")

void func_80800170_glrtc(u8 **arg0, u16 *arg1, s32 arg2) {
    void func_808002C8_glrtc(u16 *arg0, u16 arg1);
    u16 endpoints[2];
    u32 bits;
    u16 colors[4];
    s32 i;
    s32 j;
    u8 *src;

    src = *arg0;
    bcopy(src, endpoints, 4);
    src += 4;
    colors[0] = endpoints[0];
    colors[1] = 1;
    colors[2] = 1;
    colors[3] = endpoints[1];
    func_808002C8_glrtc(colors, 0xF800);
    func_808002C8_glrtc(colors, 0x7C0);
    func_808002C8_glrtc(colors, 0x3E);
    bcopy(src, &bits, 4);
    src += 4;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg1[j] = colors[bits & 3];
            bits >>= 2;
        }
        arg1 += arg2;
    }
    *arg0 = src;
}

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
