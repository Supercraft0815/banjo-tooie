#include "common.h"

Acmd *func_8002D450(u8 *arg0, s16 *arg1, Acmd *arg2) {
    Acmd *func_8002C5F8(u8 *, s16 *, s32, Acmd *);


    Acmd *sp34;
    s16 sp32;
    s32 sp2C;
    s32 sp28;
    f32 sp24;

    sp34 = arg2;
    sp32 = 0x170;
    if ((*(s32 *)((s8 *)(arg0) + (0x48))) != 0) {
        sp34 = func_8002C5F8(arg0, &sp32, 0xB8, arg2);
        {
        Acmd *sp20;
        sp20 = sp34++;
        (*(s32 *)((s8 *)(sp20) + (0))) = (s32) ((sp32 & 0xFFFFFF) | 0x0A000000);
        (*(s32 *)((s8 *)(sp20) + (4))) = (s32) (((*arg1 & 0xFFFF) << 0x10) | 0x170);
        }
    } else {
        if ((f64) (*(f32 *)((s8 *)(arg0) + (0x44))) > 1.99996) {
            (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) 1.99996f;
        }
        (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) (s32) ((*(f32 *)((s8 *)(arg0) + (0x44))) * 32768.0f);
        (*(f32 *)((s8 *)(arg0) + (0x44))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x44))) / 32768.0f);
        sp24 = ((*(f32 *)((s8 *)(arg0) + (0x44))) * 184.0f) + (*(f32 *)((s8 *)(arg0) + (0x4C)));
        sp2C = (s32) sp24;
        (*(f32 *)((s8 *)(arg0) + (0x4C))) = (f32) (sp24 - (f32) sp2C);
        sp34 = func_8002C5F8(arg0, &sp32, sp2C, arg2);
        sp28 = (s32) ((*(f32 *)((s8 *)(arg0) + (0x44))) * 32768.0f);
        {
        Acmd *sp1C;
        sp1C = sp34++;
        (*(s32 *)((s8 *)(sp1C) + (0))) = (s32) ((osVirtualToPhysical((*(u8 **)((s8 *)(arg0) + (0x40)))) & 0xFFFFFF) | 0x05000000);
        (*(s32 *)((s8 *)(sp1C) + (4))) = (s32) ((((*(s32 *)((s8 *)(arg0) + (0x50))) & 3) << 0x1E) | ((sp28 & 0xFFFF) << 0xE) | ((sp32 & 0xFFF) * 4));
        }
        (*(s32 *)((s8 *)(arg0) + (0x50))) = 0;
    }
    return sp34;
}

/* extern */

s32 func_8002D694(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8002CC9C(BtIntPtr, s32, BtIntPtr);
    func_8002CC9C(arg0, arg1, arg2);
    return 0;
}
