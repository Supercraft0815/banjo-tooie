#include "common.h"

s32 glsplinefuncs_entrypoint_0(s32 arg0, s32 *arg1, f32 *arg2, f32 *arg3, s32 arg4, f32 *arg5, f32 *arg6) {
    void *func_8001B798(s16);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void *func_800D7400(void);
    void *func_800D7520(s32);
    u8 *state;
    s16 *ids;
    u8 *data;
    u8 *first;
    u8 *entry;
    u8 *end;
    s32 i;

    state = func_800D7400();
    ids = func_8001B798(*(s16 *)(state + 0x186));
    *arg5 = -9999.0f;
    *arg6 = -9999.0f;
    if (arg4 != -1) {
        data = func_8001B798(ids[arg4]);
        first = data + 4;
        entry = first;
        end = data + *(s32 *)data * 20 + 4;
        while (arg0 != (*(u32 *)(entry + 16) >> 21) && entry < end) {
            entry += 20;
        }
        if (entry < end) {
            if ((*(u32 *)(entry + 4) & 1) == 1) {
                if (!(*(u32 *)(entry + 12) & 1) && ((*(u32 *)(entry + 4) << 25) >> 29) == 7) {
                    *arg5 = (f32)(*(u32 *)(entry + 12) >> 23);
                    *arg6 = (f32)((u32)*(u16 *)(entry + 6) >> 7);
                }
            }
            *arg1 = arg4;
            *arg2 = *(f32 *)entry;
            func_800C7A68(func_800D7520(arg4), *(f32 *)entry, arg3);
            return 1;
        }
    }
    for (i = 0; i < *(s32 *)(state + 0x188); i++) {
        if (i != arg4) {
            data = func_8001B798(ids[i]);
            first = data + 4;
        entry = first;
            end = data + *(s32 *)data * 20 + 4;
            while (arg0 != (*(u32 *)(entry + 16) >> 21) && entry < end) {
                entry += 20;
            }
            if (entry < end) {
                if ((*(u32 *)(entry + 4) & 1) == 1) {
                    if (!(*(u32 *)(entry + 12) & 1) && ((*(u32 *)(entry + 4) << 25) >> 29) == 7) {
                        *arg5 = (f32)(*(u32 *)(entry + 12) >> 23);
                        *arg6 = (f32)((u32)*(u16 *)(entry + 6) >> 7);
                    }
                }
                *arg1 = i;
                *arg2 = *(f32 *)entry;
                func_800C7A68(func_800D7520(i), *(f32 *)entry, arg3);
                return 1;
            }
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/spline/funcs/glsplinefuncs_entrypoint_1.s")
