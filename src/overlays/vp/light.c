#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_0.s")

void vplight_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
void func_80800134_vplight(s16 *arg0, f32 *arg1, f32 arg2, s32 *arg3, s32 *arg4) {
    s32 lo;
    s32 hi;
    s32 i;
    f32 low;
    f32 high;
    s16 min;
    s16 max;

    for (i = 0; i < 3; i++) {
        low = arg1[i] - arg2;
        high = arg1[i] + arg2;
        lo = (s32)(*(f32 *)((u8 *)arg0 + 0x18) * low);
        hi = (s32)(*(f32 *)((u8 *)arg0 + 0x18) * high);
        if (low < 0.0f) {
            lo--;
        }
        if (high < 0.0f) {
            hi--;
        }
        min = arg0[i];
        max = arg0[i + 3];
        if (lo < min) {
            lo = min;
        }
        if (max < lo) {
            lo = max;
        }
        if (hi < min) {
            hi = min;
        }
        if (max < hi) {
            hi = max;
        }
        arg3[i] = lo - min;
        arg4[i] = hi - min;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_2.s")

void func_808004B0_vplight(void *arg0, s32 position[3]) {
    void func_800C8800(void *, f32 *);
    f32 pos[3];
    func_800C8800(arg0, pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/func_80800518_vplight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/vp/light/vplight_entrypoint_4.s")
