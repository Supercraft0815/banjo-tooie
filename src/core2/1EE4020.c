#include "common.h"

void func_8010A730(s32 arg0, s32 arg1) {
}
/* extern */

void func_8010A73C(s32 *arg0, s32 arg1) {
    s32 func_801039E4(s32);
    func_801039E4(*arg0);
}

/* extern */

void func_8010A764(s32 arg0, s32 arg1) {
    void *func_80100368();
    (*(s32 (**)(s32, s32))((s8 *)(func_80100368()) + (0x14)))(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4020/func_8010A79C.s")

void func_8010A800(void **arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x2A];
        u16 high : 7;
        u16 value : 8;
        u16 low : 1;
    };
    struct Fields *fields = *arg0;

    fields->value = 1 << arg1;
}

void func_8010A828(void **arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x2A];
        u16 high : 7;
        u16 value : 8;
        u16 low : 1;
    };
    struct Fields *fields = *arg0;

    fields->value = arg1;
}

u32 func_8010A848(void **arg0) {
    return (u32) ((*(s32 *)((s8 *)(*arg0) + (0x28))) << 0x17) >> 0x18;
}

void func_8010A85C(u8 *arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x77];
        u8 high : 4;
        u8 low : 4;
    };
    ((struct Fields *)arg0)->low = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE4020/func_8010A874.s")
