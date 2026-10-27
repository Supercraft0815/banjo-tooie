#include "common.h"

void glrtc_entrypoint_0(void *arg0, void *arg1) {
    void func_80800170_glrtc(u8 **arg0, u16 *arg1, s32 arg2);
    void func_8080031C_glrtc(u8 **arg0, u8 *arg1, s32 arg2);
    void func_80800474_glrtc(u8 **arg0, u8 *arg1, s32 arg2);
    s32 pad0;
    u8 *src;
    s32 pad[3];
    s32 stride;
    s32 x;
    s32 y;
    struct {
        u8 format;
        u8 width;
        u8 height;
    } *header;

    header = arg0;
    src = (u8 *)arg0 + 3;
    stride = header->width;
    stride *= 4;
    for (y = 0; y < header->height; y++) {
        for (x = 0; x < header->width; x++) {
            switch (((u8 *)arg0)[0]) {
                case 0:
                    func_80800170_glrtc(&src, (u16 *)arg1 + y * 4 * stride + x * 4, stride);
                    break;
                case 1:
                    func_8080031C_glrtc(&src, (u8 *)((u32 *)arg1 + y * 4 * stride + x * 4), stride);
                    break;
                case 2:
                    func_80800474_glrtc(&src, (u8 *)((u32 *)arg1 + y * 4 * stride + x * 4), stride);
                    break;
            }
        }
    }
}

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

void func_8080031C_glrtc(u8 **arg0, u8 *arg1, s32 arg2) {
    void func_808005B0_glrtc(u8 *, u8, s32, u8 *, u32);
    u16 endpoints[2];
    u8 colors[4][4];
    s32 i;
    s32 bits;
    u8 *channel;
    u8 *src;

    src = *arg0;
    bcopy(src, endpoints, 4);
    colors[0][0] = (endpoints[0] & 0xF800) >> 8;
    colors[1][0] = (endpoints[0] & 0x7C0) >> 3;
    src += 4;
    colors[2][0] = (endpoints[0] & 0x3E) * 4;
    colors[3][0] = 0xFF;
    colors[0][3] = (endpoints[1] & 0xF800) >> 8;
    colors[1][3] = (endpoints[1] & 0x7C0) >> 3;
    colors[2][3] = (endpoints[1] & 0x3E) * 4;
    colors[3][3] = 0xFF;
    i = 0;
    channel = colors[0];
    for (; i < 3; i++) {
        if (channel[0] == channel[3]) {
            bits = 0;
        } else {
            bcopy(src, &bits, 4);
            src += 4;
        }
        func_808005B0_glrtc(arg1, i, arg2, channel, bits);
        channel += 4;
    }
    bits = 0;
    func_808005B0_glrtc(arg1, i, arg2, colors[0], 0);
    *arg0 = src;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/func_80800474_glrtc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/rtc/func_808005B0_glrtc.s")
