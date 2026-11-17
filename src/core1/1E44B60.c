#include "common.h"

Acmd *func_8002D030(u8 *arg0, s16 *arg1, s32 arg2, Acmd *arg3) {
    struct FilterState { u8 pad[0x8C]; u8 count; u8 pad8D[0x2B]; s32 flags; };
    void func_80028C04(void *, f32);
    Acmd *func_8002D450(u8 *, s16 *, Acmd *);
    f32 sqrtf(f32);
    extern f32 D_80041DA0;
    extern f32 D_80041DA4;
    extern f32 D_80041DA8;
    Acmd *sp2C;
    f32 sp28;
    Acmd *sp24;
    Acmd *sp20;
    Acmd *sp1C;

    sp2C = arg3;
    sp2C = func_8002D450(arg0, arg1, arg3);
    if (((struct FilterState *)arg0)->count != 0 && ((struct FilterState *)arg0)->count < 0x40) {
        if (((struct FilterState *)arg0)->count >= 6) {
            sp28 = D_80041DA0 / sqrtf((f32)((struct FilterState *)arg0)->count + 1.0f);
        } else {
            sp28 = 65536.0f / ((f32)((struct FilterState *)arg0)->count + 1.0f);
        }
        if (sp28 < D_80041DA4) {
            sp28 = D_80041DA8;
        }
        sp24 = sp2C++;
        sp24->words.w0 = *arg1 & 0xFFFF;
        sp24->words.w1 = (((u32)sp28 & 0xFFFF) << 16) | ((((struct FilterState *)arg0)->count + 1) & 0xFFFF);
    }
    if (*(s16 *)(arg0 + 0x92) > 0) {
        if (((struct FilterState *)arg0)->flags != 0) {
            func_80028C04(arg0 + 0x90, 22050.0f);
        }
        sp20 = sp2C++;
        sp20->words.w0 = 0x0B000020;
        sp20->words.w1 = osVirtualToPhysical(arg0 + 0x98);
        if (((struct FilterState *)arg0)->flags == 2) {
            ((struct FilterState *)arg0)->flags = 0;
        }
        sp1C = sp2C++;
        sp1C->words.w0 = (*arg1 & 0xFFFF) | (((((struct FilterState *)arg0)->flags & 0xFF) << 16) | 0x0E000000);
        sp1C->words.w1 = osVirtualToPhysical(*(u8 **)(arg0 + 0xBC)) & 0xFFFFFF & 0xFFFFFF;
        ((struct FilterState *)arg0)->flags = 0;
    }
    return sp2C;
}

s32 func_8002D328(u8 *arg0, s32 arg1, BtIntPtr arg2) {
    s32 func_8002CC9C(void *, s32, BtIntPtr);
    f32 *value;

    value = (f32 *)&arg2;
    switch (arg1) {
        case 4:
            *(s16 *)(arg0 + 0x92) = 0;
            func_8002CC9C(arg0, 4, arg2);
            break;
        case 18:
            *(s16 *)(arg0 + 0x92) = arg2;
            *(s32 *)(arg0 + 0xB8) |= 2;
            break;
        case 19:
            *(s16 *)(arg0 + 0x90) = (s32)*value;
            *(s32 *)(arg0 + 0xB8) |= 2;
            break;
        case 17:
            *(s8 *)(arg0 + 0x8C) = arg2;
            break;
        default:
            func_8002CC9C(arg0, arg1, arg2);
            break;
    }
    return 0;
}
