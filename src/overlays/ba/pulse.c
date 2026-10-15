#include "common.h"

s32 bapulse_entrypoint_0() 
{
    return 0xC;
}

void bapulse_entrypoint_1(u8 *arg0) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xE8)));
    func_800F10B4((*(f32 *)((s8 *)(temp_v0) + (8))), 0.0f, (*(f32 *)((s8 *)(temp_v0) + (4))), 0.0f, 1.0f);
}

void bapulse_entrypoint_2(s32 arg0) 
{
}
void bapulse_entrypoint_3(void *arg0, f32 arg1, f32 arg2) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (0))) = 0;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (8))) = arg1;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (4))) = arg2;
}

/* extern */

void bapulse_entrypoint_4(void *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F13C4(f32, f32);
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f20;
    void *temp_v0;

    temp_f0 = func_800D8FF8();
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xE8)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0))) == 0) {
        (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (8))) + temp_f0);
        temp_v0 = (*(void **)((s8 *)(arg0) + (0xE8)));
        temp_f20 = (*(f32 *)((s8 *)(temp_v0) + (8)));
        temp_f14 = (*(f32 *)((s8 *)(temp_v0) + (4)));
        if (temp_f14 <= temp_f20) {
            temp_f0 = func_800F13C4(temp_f20, temp_f14);
            temp_v0 = (*(void **)((s8 *)(arg0) + (0xE8)));
            (*(f32 *)((s8 *)(temp_v0) + (8))) = (*(f32 *)((s8 *)(temp_v0) + (4))) - temp_f0;
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (0))) = 1;
        }
    } else {
        (*(f32 *)((s8 *)(temp_v0) + (8))) = (f32) ((*(f32 *)((s8 *)(temp_v0) + (8))) - temp_f0);
        temp_v0 = (*(void **)((s8 *)(arg0) + (0xE8)));
        temp_f20 = (*(f32 *)((s8 *)(temp_v0) + (8)));
        if (temp_f20 < 0.0f) {
            (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (8))) = func_800F13C4(-temp_f20, (*(f32 *)((s8 *)(temp_v0) + (4))));
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xE8)))) + (0))) = 0;
        }
    }
}
