#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propmarker/gspropmarker_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propmarker/gspropmarker_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propmarker/gspropmarker_entrypoint_2.s")

f32 gspropmarker_entrypoint_3(void *arg0) {
    f32 result;
    u32 value;

    value = *(u32 *)((s8 *)arg0 + 0xC) & 0x7FFFFF;
    if (value != 0) {
        result = (f32)value * 0.01f;
    } else {
        result = 1.0f;
    }
    return result;
}
