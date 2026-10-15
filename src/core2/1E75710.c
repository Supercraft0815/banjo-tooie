#include "core2/1E75710.h"

s32 func_8009BE20() 
{
    return 0x10;
}

/* extern */

void func_8009BE28(void *arg0, f32 arg1, f32 arg2) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    f32 func_800D8FF8();
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F212C(f32, f32);
    s32 pad[2];
    f32 sp2C;
    f32 sp28;
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f20;
    void *temp_s0;

    sp28 = func_800D8FF8();
    temp_s0 = (*(void **)((s8 *)(arg0) + (0xDC)));
    temp_f0 = func_80013728((*(f32 *)((s8 *)(temp_s0) + (4))) - (*(f32 *)((s8 *)(temp_s0) + (0))));
    sp2C = temp_f0;
    temp_f2 = temp_f0 * arg2;
    var_f20 = temp_f2;
    if (var_f20 != 0.0f) {
        if (var_f20 < 0.0f) { var_f20 = func_800F0D50(var_f20, -arg1, -3.0f); } else { var_f20 = func_800F0D50(var_f20, 3.0f, arg1); }
    }
    (*(f32 *)((s8 *)(temp_s0) + (0))) += func_800F212C(var_f20 * sp28, sp2C);
    (*(f32 *)((s8 *)(temp_s0) + (0))) = func_800136E4((*(f32 *)((s8 *)(temp_s0) + (0))));
}

void func_8009BF04(PlayerState *arg0) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xDC)))) + (0))) = 0.0f;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xDC)))) + (4))) = 0.0f;
    func_8009C000(arg0);
}

/* extern */

void func_8009BF34(PlayerState *arg0) {
    void func_8009BE28(void *, f32, f32);
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xDC)));
    func_8009BE28(arg0, (*(f32 *)((s8 *)(temp_v0) + (8))), (*(f32 *)((s8 *)(temp_v0) + (0xC))));
}

/* extern */

void func_8009BF5C(PlayerState *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xDC)))) + (4))) = func_800136E4(arg1);
}

void func_8009BF8C(u8 *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    *(*(f32 **)((s8 *)(arg0) + (0xDC))) = func_800136E4(arg1);
}

void func_8009BFBC(void *arg0) {
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xDC)));
    (*(f32 *)((s8 *)(temp_v0) + (0))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (4)));
}

f32 func_8009BFCC(PlayerState *arg0) {
    return **(f32 **)((u8 *)arg0 + 0xDC);
}

f32 func_8009BFD8(PlayerState *arg0) {
    return (*(f32 **)((u8 *)arg0 + 0xDC))[1];
}

void func_8009BFE4(PlayerState *arg0, f32 arg1, f32 arg2) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xDC)))) + (8))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xDC)))) + (0xC))) = arg2;
}

void func_8009C000(PlayerState *arg0) {
    func_8009BFE4(arg0, 500.0f, 0.8f);
}
