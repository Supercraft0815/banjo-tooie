#include "common.h"

void *gspropmarker_entrypoint_0(s16 *arg0, s32 arg1) { Prop *func_800E9D68(s16 *); u32 func_800E9D90(s16 *); s32 func_800E9DC4(s16 *);
    Prop *start;
    Prop *prop;
    u32 end;

    if ((arg0 != NULL) && (func_800E9DC4(arg0) != 0)) {
        start = func_800E9D68(arg0);
        end = func_800E9D90(arg0);
        for (prop = start; (u32)prop < end; prop++) {
            if (((prop->unk6_0 == 1) || ((prop->unk6_0 == 0) && ((*(u8 *)((s8 *)prop + 0x12) & 1) == 1U))) && (prop->unk6_1 == 6) && (arg1 == prop->ItemID)) {
                return prop;
            }
        }
    }
    return NULL;
}

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
